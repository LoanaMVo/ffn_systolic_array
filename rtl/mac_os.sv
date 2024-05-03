/* MULTIPLY ACCUMULATOR 
 * Parameters:
 * DATA_WIDTH - length of an n x n matrix
 * ACC_WIDTH  - accumulator size, depends on matrix size and how many iterations
 *		  	  - general rule should be n * datawidth * 2	
 * Author: Loana Vo
 * Date: January 2024
 */

module mac_os #(
	parameter DATA_WIDTH = 16,
	parameter ACC_WIDTH = 64
	) (    
	input logic clk,
    input logic rstn,
	// enables
	input logic acc_en,
	// data a and accumulator result inputs
    input logic signed  [DATA_WIDTH - 1:0] data_i,
	input logic signed  [DATA_WIDTH - 1:0] weight_i,
	// data a and b outputs
	output logic signed [DATA_WIDTH - 1:0] data_o,
    output logic signed [DATA_WIDTH - 1:0] weight_o,
	// output accumulator
	output signed [ACC_WIDTH  - 1:0] acc_o
    );

	logic signed [ACC_WIDTH  - 1:0] acc_r;
	logic signed [ACC_WIDTH  - 1:0] acc_prev_r;
	logic signed [DATA_WIDTH - 1:0] data_r;
    logic signed [DATA_WIDTH - 1:0] weight_r;

	always_ff @(posedge clk, negedge rstn) begin
		if(!rstn) begin
			acc_r      <= '0;
			data_r     <= '0;
            weight_r   <= '0;
		end else begin
            if (acc_en) begin
				acc_r    <= acc_prev_r + data_i * weight_i;
				data_r   <= data_i;
                weight_r <= weight_i;
			end
		end
	end
	
    assign acc_prev_r = acc_r;

	assign acc_o      = acc_r;
	assign data_o     = data_r;
    assign weight_o   = weight_r;

endmodule // mac
