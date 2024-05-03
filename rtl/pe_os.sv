/* PROCESS ELEMENT 
 * Parameters:
 * DATA_WIDTH - length of an n x n matrix
 * ACC_WIDTH  - accumulator size, depends on matrix size and how many iterations
 *		  	  - general rule should be n * datawidth * 2	
 * Author: Loana Vo
 */
module pe_os #(
	parameter DATA_WIDTH = 16,
	parameter ACC_WIDTH = 64
	) (    
	input logic clk,
    input logic rstn,
	// enable
	input logic acc_en,
	// data a and b inputs
    input logic signed  [DATA_WIDTH - 1:0] data_i,
	input logic signed  [DATA_WIDTH - 1:0] weight_i,
	// data a and b outputs
	output logic signed [DATA_WIDTH - 1:0] data_o,
	output logic signed [DATA_WIDTH - 1:0] weight_o,
	// output accumulator
	output logic signed [ACC_WIDTH  - 1:0] acc_o
    );
	
	mac_os #(
        .DATA_WIDTH(DATA_WIDTH),
        .ACC_WIDTH(ACC_WIDTH)
    ) mac_os_inst (
		.clk(clk),
		.rstn(rstn),
		.acc_en(acc_en),
		.data_i(data_i),
		.weight_i(weight_i),
		.data_o(data_o),
		.weight_o(weight_o),
		.acc_o(acc_o)
	);

endmodule
