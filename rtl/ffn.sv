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
	input  logic signed [DATA_WIDTH*PE_NUM-1:0]     weight_i,
    input  logic signed [4-1:0]                     layers_i,
	output logic        [ACC_WIDTH-1:0]             acc_o,
    output logic                                    done_o
);

    // FSM States
	typedef enum {
		INIT,
		RESET,
        WEIGHT_WRITE,
        WEIGHT_READ,
		WEIGHT_LOAD, // load in weights in
		FORWARD, // forward pass computation
        FIRST_LAYER, // compute first layer
        FINAL_LAYER, // compute final layer
		BACKWARD, // backward pass computation
		DONE // done
	} state;
    
    // amount of cycles for full systolic array computation
    localparam COUNTER = NEURON_NUM*2-1;
    // enables
	logic acc_en_r;
	logic load_en_r;	
    // counter for systolic array passes
    logic [3:0] cnt_r;
    logic [3:0] layer_cnt_r;
    // parameters
	logic signed [DATA_WIDTH*PE_NUM-1:0] weight_r;
	logic signed [ACC_WIDTH*PE_NUM-1:0] acc_r;
    logic [1:0] activ_type_r; 
    // buffer interface signals
    logic wr_en_r;
    logic rd_en_r;
    logic [4-1:0] wr_addr_r;
    logic [4-1:0] wr_pntr_r;
    logic [4-1:0] rd_addr_r;
    logic [4-1:0] rd_pntr_r;
    logic [DATA_WIDTH*PE_NUM-1:0] wr_data_r;
    logic [DATA_WIDTH*PE_NUM-1:0] rd_data_r;
    // TODO: for multiplication of large arrays
    //?????????

    assign layer_cnt_r = layers_i;

	always_ff @(posedge clk, negedge rstn) begin
		if (~rstn) begin
			done_o    <= 1'b0;
			acc_en_r  <= 1'b0;
            load_en_r <= 1'b0;
			weight_r  <= '0;
            wr_addr_r <= '0;
            rd_addr_r <= '0;
			cnt_r     <= COUNTER;
			//state     <= LOAD;
		end /*else begin
			case (state)
                INIT: begin// inital write to buffer
                    wr_en_r   <= 1'b1;
                    wr_data_r <= weight_i;
                    wr_addr_r <= 4'b0;
                    rd_addr_r <= 4'b0;
                    rd_pntr   <= 4'b0;
                    state     <= WEIGHT_LOAD;
                end
                // load weights into buffer
                WEIGHT_WRITE: begin
                    wr_en_r   <= 1'b1;
                    wr_data_r <= weight_r;
                    wr_addr_r <= wr_pntr;
                    state     <= INIT; // ?
                end
                // load systolic array weights
				WEIGHT_LOAD: begin
                    load_en_r <= 1'b1;
                    rd_en_r   <= 1'b1;
                    rd_addr_r <= rd_pntr;
                    weight_r  <= rd_data_r;
                    state     <= FIRST_LAYER;
				end
                // begin forward propagation
				FIRST_LAYER: begin
                    load_en_r <= 1'b0;
					acc_en_r  <= 1'b1;
					data_a_r  <= data_a_i;
					cnt_r 	  <= cnt_r - 1'b1;
                    // load into systolic array
					if (!cnt_r) begin
							data_0_r <=  data_i[DATA_WIDTH*NEURON_NUM*4-1 -: DATA_WIDTH];
							data_1_r <=  data_i[DATA_WIDTH*NEURON_NUM*3-1 -: DATA_WIDTH];
							data_2_r <=  data_i[DATA_WIDTH*NEURON_NUM*2-1 -: DATA_WIDTH];
							data_3_r <=  data_i[DATA_WIDTH*NEURON_NUM*1-1 -: DATA_WIDTH];
					end else begin
                            state <= DONE;
                    end
				end
                // done neural network
				DONE: begin
					acc_en_r <= 1'b0;
                    done_o   <= 1'b1;
				end
			endcase
		end*/
	end
/*
	systolic_array systolic_array_0 (
		.clk(clk),
		.rstn(rstn),
        // enables
		.acc_en(acc_en_r),
		.load_en(load_en_r),
        // data
		.data_0_i(data_0_r),
		.data_1_i(data_1_r),
		.data_2_i(data_2_r),
		.data_3_i(data_3_r),
        // weight
        .weight_0_i(weight_r[DATA_WIDTH*1-1-:DATA_WIDTH]),
		.weight_1_i(weight_r[DATA_WIDTH*2-1-:DATA_WIDTH]),
		.weight_2_i(weight_r[DATA_WIDTH*3-1-:DATA_WIDTH]),
		.weight_3_i(weight_r[DATA_WIDTH*4-1-:DATA_WIDTH]),
		.acc_o(acc_r)
	);*/

    weight_buffer weight_buffer_0 (
        .clk(clk),
        .rstn(rstn),
        .wr_en(wr_en_r),
        .rd_en(rd_en_r),
        .wr_addr(wr_addr_r),
        .rd_addr(rd_addr_r),
        .wr_data_i(wr_data_r),
        .rd_data_o(rd_data_r)
    );

    logic [ACC_WIDTH-1:0] z_int_r;

    // bias activation unit
    genvar i;
    generate
        for(i=1; i<NEURON_NUM; i=i+1) begin
            bias_activation bias_activation_0 (
   	            .activ_type_i(activ_type_r),
                .z_i(acc_r[DATA_WIDTH*i-1   -: DATA_WIDTH]),
                .y_o(z_int_r[DATA_WIDTH*i-1 -: DATA_WIDTH])
            );
        end
    endgenerate

endmodule //ffn_top
/* verilator lint_on UNUSEDSIGNAL */
/* verilator lint_on UNDRIVEN */
