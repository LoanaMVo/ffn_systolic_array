/* FFN TOP WRAPPER
 * Wrapper module serializes data.
 * Author: Loana Vo
 */

/* verilator lint_off UNUSEDSIGNAL */
/* verilator lint_off UNDRIVEN*/
module ffn_top #( 
	parameter DATA_WIDTH = 16,
	parameter ACC_WIDTH = 64,
    parameter PE_NUM = 16,
	parameter NEURON_NUM = 4
	) (
	input logic clk,
	input logic rstn,
    // layers
    input logic [4-1:0] layer_i,
    // data a input
	input logic signed [DATA_WIDTH-1:0] data_0_i,
	input logic signed [DATA_WIDTH-1:0] data_1_i,
	input logic signed [DATA_WIDTH-1:0] data_2_i,
	input logic signed [DATA_WIDTH-1:0] data_3_i,
    // weight input
	input logic signed [DATA_WIDTH-1:0] weight_00_i,
	input logic signed [DATA_WIDTH-1:0] weight_01_i,
	input logic signed [DATA_WIDTH-1:0] weight_02_i,
	input logic signed [DATA_WIDTH-1:0] weight_03_i,
	input logic signed [DATA_WIDTH-1:0] weight_10_i,
	input logic signed [DATA_WIDTH-1:0] weight_11_i,
	input logic signed [DATA_WIDTH-1:0] weight_12_i,
	input logic signed [DATA_WIDTH-1:0] weight_13_i,
	input logic signed [DATA_WIDTH-1:0] weight_20_i,
	input logic signed [DATA_WIDTH-1:0] weight_21_i,
	input logic signed [DATA_WIDTH-1:0] weight_22_i,
	input logic signed [DATA_WIDTH-1:0] weight_23_i,
	input logic signed [DATA_WIDTH-1:0] weight_30_i,
	input logic signed [DATA_WIDTH-1:0] weight_31_i,
	input logic signed [DATA_WIDTH-1:0] weight_32_i,
	input logic signed [DATA_WIDTH-1:0] weight_33_i,
    // accumulator output
	output logic [DATA_WIDTH*4-1:0] acc_o,
    output logic done_o
);
	
	logic [DATA_WIDTH*PE_NUM-1:0] weight_int;
	logic [DATA_WIDTH*NEURON_NUM-1:0] data_int;

	ffn #(
        .DATA_WIDTH(DATA_WIDTH),
        .ACC_WIDTH(ACC_WIDTH),
        .PE_NUM(PE_NUM),
        .NEURON_NUM(NEURON_NUM)
    ) fnn_inst (
		.clk(clk),
		.rstn(rstn),
		.data_i(data_int),
        .layer_i(layer_i),
		.weight_i(weight_int),
		.acc_o(acc_o),
        .done_o(done_o)
	);

    assign data_int = {data_3_i,data_2_i,data_1_i,data_0_i};

	assign weight_int = { weight_33_i, weight_32_i, weight_31_i, weight_30_i,
						  weight_23_i, weight_22_i, weight_21_i, weight_20_i,
						  weight_13_i, weight_12_i, weight_12_i, weight_10_i,
						  weight_03_i, weight_02_i, weight_02_i, weight_01_i };
endmodule // ffn_top
/* verilator lint_on UNUSEDSIGNAL */
/* verilator lint_on UNDRIVEN */
