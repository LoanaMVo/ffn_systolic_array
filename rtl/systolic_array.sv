/* 
 * SYSTOLIC ARRAY
 * ---------------------------------------------
 * 
 * Author: Loana Vo
 */

module systolic_array #(
	//PE_SIZE = 4,
	DATA_WIDTH = 16+1,
	ACC_WIDTH = DATA_WIDTH*4+1
	)(
	input logic clk,
	input logic rstn,
	// data input
	input logic signed [DATA_WIDTH-1:0] data_a_0_i,
	input logic signed [DATA_WIDTH-1:0] data_a_1_i,
	input logic signed [DATA_WIDTH-1:0] data_b_0_i,
	input logic signed [DATA_WIDTH-1:0] data_b_1_i,
	// accumulator enable
	input  logic acc_en,
	// accumulator output
	output logic signed [ACC_WIDTH-1:0] acc_0_o,
	output logic signed [ACC_WIDTH-1:0] acc_1_o,
	output logic signed [ACC_WIDTH-1:0] acc_2_o,
	output logic signed [ACC_WIDTH-1:0] acc_3_o,
	output logic [DATA_WIDTH*2-1:0] pe_a_o,
	output logic [DATA_WIDTH*2-1:0] pe_b_o,
	// done
	output logic done_o
	);

	reg done_r; // asserts when computation is done
	reg cnt_r; // counter to measure how many clock cycles has passed

	// accumulator output	
	reg [ACC_WIDTH-1:0] acc_0_r;
	reg [ACC_WIDTH-1:0] acc_1_r; 
	reg [ACC_WIDTH-1:0] acc_2_r; 
	reg [ACC_WIDTH-1:0] acc_3_r; 

    /*
		pe0 -> pe1
	      |	     |
		pe2 -> pe_3 
	*/

	logic [DATA_WIDTH-1:0] pe0_a_o;
	logic [DATA_WIDTH-1:0] pe1_a_o;
	logic [DATA_WIDTH-1:0] pe2_a_o;
	logic [DATA_WIDTH-1:0] pe3_a_o;

	logic [DATA_WIDTH-1:0] pe0_b_o;
	logic [DATA_WIDTH-1:0] pe1_b_o;
	logic [DATA_WIDTH-1:0] pe2_b_o;
	logic [DATA_WIDTH-1:0] pe3_b_o;

	pe #(.DATA_WIDTH(DATA_WIDTH), .ACC_WIDTH(ACC_WIDTH)) pe_0 (
		.clk(clk),
		.rstn(rstn),
		.acc_en(acc_en),
		.data_a_i(data_a_0_i),
		.data_b_i(data_b_0_i),
		.data_a_o(pe0_a_o),
		.data_b_o(pe0_b_o),
		.acc_o(acc_0_r)
	);
	
	pe #(.DATA_WIDTH(DATA_WIDTH), .ACC_WIDTH(ACC_WIDTH)) pe_1 (
		.clk(clk),
		.rstn(rstn),
		.acc_en(acc_en),
		.data_a_i(pe0_a_o),
		.data_b_i(data_b_1_i),
		.data_a_o(pe1_a_o),
		.data_b_o(pe1_b_o),
		.acc_o(acc_1_r)
	);
	
	pe #(.DATA_WIDTH(DATA_WIDTH), .ACC_WIDTH(ACC_WIDTH)) pe_2 (
		.clk(clk),
		.rstn(rstn),
		.acc_en(acc_en),
		.data_a_i(data_a_1_i),
		.data_b_i(pe0_b_o),
		.data_a_o(pe2_a_o),
		.data_b_o(pe2_b_o),
		.acc_o(acc_2_r)
	);
	
	pe #(.DATA_WIDTH(DATA_WIDTH), .ACC_WIDTH(ACC_WIDTH)) pe_3 (
		.clk(clk),
		.rstn(rstn),
		.acc_en(acc_en),
		.data_a_i(pe2_a_o),
		.data_b_i(pe1_b_o),
		.data_a_o(pe3_a_o),
		.data_b_o(pe3_b_o),
		.acc_o(acc_3_r)
	);
	// done loop
	always @(posedge clk, negedge rstn) begin
		if(!rstn) begin
			done_r <= 1'b0;	
			cnt_r  <= 1'b0;
		end else begin
			cnt_r <= cnt_r + 1;
		end
	end

	assign acc_0_o = acc_0_r;
	assign acc_1_o = acc_1_r;
	assign acc_2_o = acc_2_r;
	assign acc_3_o = acc_3_r;
	// assign acc_o = {acc_0_r,acc_1_r,acc_2_r,acc_3_r};

	assign done_o = done_r;

	// data_o
	assign pe_a_o = {pe1_a_o,pe3_a_o};
	assign pe_b_o = {pe2_b_o,pe3_b_o};
endmodule // systolic_array
