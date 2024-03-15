/*
 * Multiply Accumulator
 * Parameters:
 * DATA_WIDTH - length of an n x n matrix
 * ACC_WIDTH  - accumulator size, depends on matrix size and how many iterations
			  - general rule should be n * datawidth * 2	
 */

module mac #(
	parameter DATA_WIDTH = 9,
	parameter ACC_WIDTH = 17
	) (    
	input clk,
    input rstn,
	// enable for accumulator
	input acc_en,
	// data a and b inputs
    input signed  [DATA_WIDTH - 1:0] data_a_i,
	input signed  [DATA_WIDTH - 1:0] data_b_i,
	// data a and b outputs
	output signed [DATA_WIDTH - 1:0] data_a_o,
    output signed [DATA_WIDTH - 1:0] data_b_o,
	// output accumulator
	output signed [ACC_WIDTH  - 1:0] acc_o
    );

	reg  signed [2*DATA_WIDTH - 1:0] mult_r;
	reg  signed [ACC_WIDTH    - 1:0] acc_r;
	wire signed [ACC_WIDTH    - 1:0] acc_prev;

	assign acc_prev = acc_r; 

	always @(posedge clk, negedge rstn) begin
		if(!rstn) begin
			mult_r <= 0;
			acc_r  <= 0;
		end else begin
			mult_r <= data_a_i * data_b_i;
			if (acc_en) begin
				acc_r  <= acc_prev + data_a_i * data_b_i;
			end
		end
	end
	 
	assign data_a_o = data_a_i;
	assign data_b_o = data_b_i;
	assign acc_o = acc_r;

endmodule // mac
