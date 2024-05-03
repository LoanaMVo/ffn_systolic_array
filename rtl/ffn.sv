/* Feed forward Neural Network
 * Parameters:
 * DATA_WIDTH - length of an n x n matrix
 * ACC_WIDTH  - accumulator size, depends on matrix size and how many iterations
 *		  	  - general rule should be n * datawidth * 
 * PE_NUM     - number of processing elements
 * NEURON_NUM - number of max neurons
 * Author: Loana Vo
 */
/* verilator lint_off UNUSEDSIGNAL */
/* verilator lint_off UNDRIVEN*/
module ffn #( 
	parameter DATA_WIDTH = 16,
	parameter ACC_WIDTH = 64,
	parameter PE_NUM = 16,
	parameter NEURON_NUM = 4
) (
	input  logic clk,
	input  logic rstn,
	input  logic signed [DATA_WIDTH*NEURON_NUM-1:0]     data_i,
	input  logic signed [DATA_WIDTH*PE_NUM-1:0]         weight_i,
    input  logic signed [4-1:0]                         layer_i,
	output logic        [ACC_WIDTH-1:0]                 acc_o,
    output logic                                        done_o
);
    logic [6:0] state;

    // FSM States
	typedef enum logic [6:0] {
		RESET,
		INIT,
        WEIGHT_UPDATE,
		WEIGHT_LOAD, // load in weights in
		FORWARD, // forward pass computation
        FIRST_LAYER, // compute first layer
        FINAL_LAYER, // compute final layer
		BACKWARD, // backward pass computation
		DONE // done
	} State;
    
    // amount of cycles for full systolic array computation
    localparam COUNTER = NEURON_NUM*2-1;
    // internal resets
	logic rstn_acc;
    // enables
	logic acc_en_r;
	logic load_en_r;	
    // counter for systolic array passes
    logic [3:0] cnt_r;
    logic [3:0] layer_cnt_r;
    // parameters
    logic [DATA_WIDTH*NEURON_NUM-1:0] data_r; 
	logic [DATA_WIDTH*PE_NUM-1:0] weight_r;
	logic [ACC_WIDTH*NEURON_NUM-1:0] acc_r;
    logic [1:0] activ_type_r; 
    // input data buffer signals
    logic id_wr_en_r;
    logic id_rd_en_r;
    logic [4-1:0] id_wr_addr_r;
    logic [4-1:0] id_wr_pntr_r;
    logic [4-1:0] id_rd_addr_r;
    logic [4-1:0] id_rd_pntr_r;
    logic [DATA_WIDTH*PE_NUM-1:0] id_wr_data_r;
    logic [DATA_WIDTH*PE_NUM-1:0] id_rd_data_r;
    // weight buffer signals
    logic wt_wr_en_r;
    logic wt_rd_en_r;
    logic [4-1:0] wt_wr_addr_r;
    logic [4-1:0] wt_wr_pntr_r;
    logic [4-1:0] wt_rd_addr_r;
    logic [4-1:0] wt_rd_pntr_r;
    logic [DATA_WIDTH*PE_NUM-1:0] wt_wr_data_r;
    logic [DATA_WIDTH*PE_NUM-1:0] wt_rd_data_r;

	always_ff @(posedge clk, negedge rstn) begin
		if (~rstn) begin
            rstn_acc     <= 1b'0;
			done_o       <= 1'b0;
			acc_en_r     <= 1'b0;
            load_en_r    <= 1'b0;
			weight_r     <= '0;
            wt_wr_addr_r <= '0;
            wt_rd_addr_r <= '0;
            layer_cnt_r  <= layer_i;
			cnt_r        <= COUNTER;
            state        <= RESET;
		end else begin
			case (state)
                // inital write to buffer
                RESET: begin
                    rstn_acc <= 1'b0;
                    // rst counter for this
                    //acc_rstn <= 1'b1;
                    state    <= INIT;
                end
                // initial state, load initial weights into buffer
                INIT: begin
                    if(~layer_cnt_r) begin
                        state        <= WEIGHT_LOAD;
                        wt_wr_en_r   <= 1'b0;
                        acc_rstn <= 1'b1;
                    end else begin
                        layer_cnt_r  <= layer_cnt_r - 3'b1;
                        wt_wr_en_r   <= 1'b1;
                        wt_wr_data_r <= weight_i;
                        wt_wr_pntr_r <= layer_cnt_i - layer_cnt_r;
                        wt_wr_addr_r <= wt_wr_pntr_r;
                    end
                end
                // load systolic array weights
				WEIGHT_LOAD: begin
                    load_en_r    <= 1'b1;
                    wt_rd_en_r   <= 1'b1;
                    wt_rd_addr_r <= wt_rd_pntr_r;
                    weight_r     <= wt_rd_data_r;
                    state        <= FIRST_LAYER;
				end
                // load weights into buffer
                WEIGHT_UPDATE: begin
                    wt_wr_en_r   <= 1'b1;
                    wt_wr_data_r <= weight_r;
                    wt_wr_addr_r <= wt_wr_pntr_r;
                    wt_wr_pntr_r <= wt_wr_pntr_r + 3'b1 ;
                    state        <= INIT;
                end
                // begin forward propagation
				FIRST_LAYER: begin
                    load_en_r <= 1'b0;
					acc_en_r  <= 1'b1;
					data_r    <= data_i;
					cnt_r 	  <= cnt_r - 4'b1;
                    // load into systolic array
					if (~cnt_r) begin
							data_r[DATA_WIDTH*4-1 -: DATA_WIDTH] <=  data_i[DATA_WIDTH*4-1 -: DATA_WIDTH];
							data_r[DATA_WIDTH*3-1 -: DATA_WIDTH] <=  data_i[DATA_WIDTH*3-1 -: DATA_WIDTH];
							data_r[DATA_WIDTH*2-1 -: DATA_WIDTH] <=  data_i[DATA_WIDTH*2-1 -: DATA_WIDTH];
							data_r[DATA_WIDTH*1-1 -: DATA_WIDTH] <=  data_i[DATA_WIDTH*1-1 -: DATA_WIDTH];
					end else begin
                            state <= DONE;
                    end
				end
                // done neural network
				DONE: begin
					acc_en_r <= 1'b0;
                    done_o   <= 1'b1;
				end
                default: state<=INIT;
			endcase
		end
	end

	systolic_array_ws systolic_array_0 (
		.clk(clk),
		.rstn(rstn),
        // enables
		.acc_en(acc_en_r),
		.load_en(load_en_r),
        // data
		.data_0_i(data_r[DATA_WIDTH*1-1 -: DATA_WIDTH]),
		.data_1_i(data_r[DATA_WIDTH*2-1 -: DATA_WIDTH]),
		.data_2_i(data_r[DATA_WIDTH*3-1 -: DATA_WIDTH]),
		.data_3_i(data_r[DATA_WIDTH*4-1 -: DATA_WIDTH]),
        // weight
        .weight_i(weight_r),
		.acc_o(acc_r)
	);

    // weight register file
    reg_file weight_buffer (
        .clk(clk),
        .rstn(rstn),
        .wr_en(wt_wr_en_r),
        .rd_en(wt_rd_en_r),
        .wr_addr(wt_wr_addr_r),
        .rd_addr(wt_rd_addr_r),
        .wr_data_i(wt_wr_data_r),
        .rd_data_o(wt_rd_data_r)
    );

    // input data register file
    reg_file input_data_buffer (
        .clk(clk),
        .rstn(rstn),
        .wr_en(id_wr_en_r),
        .rd_en(id_rd_en_r),
        .wr_addr(id_wr_addr_r),
        .rd_addr(id_rd_addr_r),
        .wr_data_i(id_wr_data_r),
        .rd_data_o(id_rd_data_r)
    );

    logic [ACC_WIDTH-1:0] z_int_r;

    bias_activation bias_activation_0 (
        .activ_type_i(activ_type_r),
        .z_i(acc_r[DATA_WIDTH*1-1   -: DATA_WIDTH]),
        .y_o(z_int_r[DATA_WIDTH*i-1 -: DATA_WIDTH])
    );

    bias_activation bias_activation_1 (
        .activ_type_i(activ_type_r),
        .z_i(acc_r[DATA_WIDTH*2-1   -: DATA_WIDTH]),
        .y_o(z_int_r[DATA_WIDTH*i-1 -: DATA_WIDTH])
    );

    bias_activation bias_activation_2 (
        .activ_type_i(activ_type_r),
        .z_i(acc_r[DATA_WIDTH*3-1   -: DATA_WIDTH]),
        .y_o(z_int_r[DATA_WIDTH*i-1 -: DATA_WIDTH])
    );

    bias_activation bias_activation_3 (
        .activ_type_i(activ_type_r),
        .z_i(acc_r[DATA_WIDTH*4-1   -: DATA_WIDTH]),
        .y_o(z_int_r[DATA_WIDTH*i-1 -: DATA_WIDTH])
    );

endmodule //ffn_top
/* verilator lint_on UNUSEDSIGNAL */
/* verilator lint_on UNDRIVEN */
