/* MULTIPLY ACCUMULATOR 
 * Parameters:
 * DATA_WIDTH - length of an n x n matrix
 * ACC_WIDTH  - accumulator size, depends on matrix size and how many iterations
 *		  	  - general rule should be n * datawidth * 2	
 * Author: Loana Vo
 */

module mac #(
	parameter DATA_WIDTH = 8,
	parameter ACC_WIDTH = 32,
	parameter WEIGHT_WIDTH = 8
	) (    
	input logic clk,
    input logic rstn,
	// enable for accumulator
	input logic acc_en,
	// data a and accumulator result inputs
    input logic signed  [DATA_WIDTH - 1:0] data_a_i,
	input logic signed  [DATA_WIDTH - 1:0] acc_i,
	input logic signed  [DATA_WIDTH - 1:0] weight_i,
	// data a and b outputs
	output logic signed [DATA_WIDTH - 1:0] data_a_o,
	// output accumulator
	output signed [ACC_WIDTH  - 1:0] acc_o
    );

	logic signed [ACC_WIDTH - 1:0] acc_r;

	logic signed [DATA_WIDTH-1:0] data_a_r;
 

	always_ff @(posedge clk, negedge rstn) begin
		if(!rstn) begin
			acc_r    <=  0;
			data_a_r <= '0;
			data_b_r <= '0;
		end else begin
			if (acc_en) begin
				acc_r    <= acc_i + data_a_i * weight_i;
				data_a_r <= data_a_i;
				data_b_r <= data_b_i;
			end
		end
	end
	 
	assign acc_o    = acc_r;
	assign data_a_o = data_a_r;
	assign data_b_o = data_b_r;

endmodule // mac
