/* PROCESS ELEMENT 
 * Parameters:
 * DATA_WIDTH - length of an n x n matrix
 * ACC_WIDTH  - accumulator size, depends on matrix size and how many iterations
 *		  	  - general rule should be n * datawidth * 2	
 * Author: Loana Vo
 */
module pe #(
	parameter DATA_WIDTH = 32,
	parameter ACC_WIDTH = 64,
    parameter WEIGHT_WIDTH = 8
	) (    
	input logic clk,
    input logic rstn,
	// enable for accumulator
	input logic acc_en,
	// data a and b inputs
    input logic signed  [DATA_WIDTH - 1:0] data_i,
    input logic signed  [DATA_WIDTH - 1:0] acc_i,
	input logic signed  [WEIGHT_WIDTH - 1:0] weight_i,
    input logic                              load_en, 
	// data a and b outputs
	output logic signed [DATA_WIDTH - 1:0] data_o,
	// output accumulator
	output signed 		[ACC_WIDTH  - 1:0] acc_o
    );
	
	mac #(
        .DATA_WIDTH(DATA_WIDTH),
        .ACC_WIDTH(ACC_WIDTH),
        .WEIGHT_WIDTH(WEIGHT_WIDTH)
    ) mac_inst (
		.clk(clk),
		.rstn(rstn),
		.acc_en(acc_en),
		.data_i(data_i),
		.acc_i(acc_i),
		.weight_i(weight_i),
		.data_o(data_o),
		.acc_o(acc_o)
	);

endmodule
