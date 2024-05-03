/* PROCESS ELEMENT 
 * Parameters:
 * DATA_WIDTH - length of an n x n matrix
 * ACC_WIDTH  - accumulator size, depends on matrix size and how many iterations
 *		  	  - general rule should be n * datawidth * 2	
 * Author: Loana Vo
 */
module pe_ws #(
	parameter DATA_WIDTH = 16,
	parameter ACC_WIDTH = 64
	) (    
	input logic clk,
    input logic rstn,
	// enable
	input logic acc_en,
    input logic load_en, 
	// data a and b inputs
    input logic signed  [DATA_WIDTH - 1:0] data_i,
    input logic signed  [ACC_WIDTH - 1:0] acc_i,
	input logic signed  [DATA_WIDTH - 1:0] weight_i,
	// data a and b outputs
	output logic signed [DATA_WIDTH - 1:0] data_o,
	// output accumulator
	output logic signed 		[ACC_WIDTH  - 1:0] acc_o
    );
	
	mac_ws #(
        .DATA_WIDTH(DATA_WIDTH),
        .ACC_WIDTH(ACC_WIDTH)
    ) mac_ws_inst (
		.clk(clk),
		.rstn(rstn),
		.acc_en(acc_en),
        .load_en(load_en),
		.data_i(data_i),
		.acc_i(acc_i),
		.weight_i(weight_i),
		.data_o(data_o),
		.acc_o(acc_o)
	);

endmodule
