/* 
 * Processing element
 * contains mac unit
 * performs forward and backward propagation
 * linked to activation unit
 */

module process_element #(
	PE_SIZE = 4,
	MAC_WIDTH = 16+1,
	ACC_WIDTH = MAC_WIDTH*4+1
	)(
	input clk,
	input rstn,
	// data input
	input [MAC_WIDTH-1:0] data_a_0_i,
	input [MAC_WIDTH-1:0] data_a_1_i,
	input [MAC_WIDTH-1:0] data_b_0_i,
	input [MAC_WIDTH-1:0] data_b_1_i,
	// accumulator output
	input acc_en,
	output [ACC_WIDTH-1:0] acc_0_o,
	output [ACC_WIDTH-1:0] acc_1_o,
	output [ACC_WIDTH-1:0] acc_2_o,
	output [ACC_WIDTH-1:0] acc_3_o,
	output done_o
	);

	reg done_r; // asserts when computation is done
	reg cnt; // counter to measure how many clock cycles has passed

	// accumulator output	
	reg [ACC_WIDTH-1:0] acc_0_r;
	reg [ACC_WIDTH-1:0] acc_1_r; 
	reg [ACC_WIDTH-1:0] acc_2_r; 
	reg [ACC_WIDTH-1:0] acc_3_r; 

    /*
		mac0 -> mac1
	      |	     |
		mac2 -> mac_3 
	*/
	wire data_a_0_o;
	wire data_a_1_o;
	wire data_a_2_o;
	wire data_a_3_o;

	wire data_b_0_o;
	wire data_b_1_o;
	wire data_b_2_o;
	wire data_b_3_o;

	mac #(MAC_WIDTH, ACC_WIDTH) mac_0 (clk, rstn, acc_en, data_a_0_i, data_b_0_i, data_a_0_o, data_b_0_o, acc_0_r);
	
	mac #(MAC_WIDTH, ACC_WIDHT) mac_1 (clk, rstn, acc_en, data_a_0_o, data_b_1_i, data_a_1_o, data_b_0_o, acc_1_r);

	mac #(MAC_WIDTH, ACC_WIDHT) mac_2 (clk, rstn, acc_en, data_a_1_i, data_b_0_o, data_a_2_o, data_b_2_o, acc_2_r);
	
	mac #(MAC_WIDTH, ACC_WIDHT) mac_3 (clk, rstn, acc_en, data_a_2_o, data_b_1_o, data_a_3_o, data_b_3_o, acc_3_r); 

	always @(posedge clk, negedge rstn) begin
		if(!rstn) begin
			done_r <= 1'b0;	
			cnt  <= 1'b0;
		end else begin
			cnt = cnt + 1;
		end
	end

	assign acc_0_o = acc_0_r;
	assign acc_1_o = acc_1_r;
	assign acc_2_o = acc_2_r;
	assign acc_3_o = acc_3_r;
	//assign acc_o = {acc_0_r,acc_1_r,acc_2_r,acc_3_r};

	assign done_o = done_r;

endmodule // processing_element
