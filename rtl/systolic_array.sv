/* 
 * SYSTOLIC ARRAY
 * Author: Loana Vo
 * Data: Febuary 2024
 * ---------------------------------------------
 *	pe0	pe2 
 *  pe2 pe3
 *  Notes:
 *  - systolic array takes in 32 bit signed input. 
 *  - fixed point prescision.
 *  - performs clocked matrix multiplication.
 */

module systolic_array #(
	//PE_SIZE = 4,
	DATA_WIDTH = 16,
	ACC_WIDTH = 64
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
	output logic signed [DATA_WIDTH*2-1:0] pe_a_o,
	output logic signed [DATA_WIDTH*2-1:0] pe_b_o
	);

	// accumulator output	
	logic signed [ACC_WIDTH-1:0] acc_0_r;
	logic signed [ACC_WIDTH-1:0] acc_1_r; 
	logic signed [ACC_WIDTH-1:0] acc_2_r; 
	logic signed [ACC_WIDTH-1:0] acc_3_r; 

	//process element outputs
	logic signed [DATA_WIDTH-1:0] data_a_pe0;
	logic signed [DATA_WIDTH-1:0] data_a_pe1;
	logic signed [DATA_WIDTH-1:0] data_a_pe2;
	logic signed [DATA_WIDTH-1:0] data_a_pe3;

	logic signed [DATA_WIDTH-1:0] data_b_pe0;
	logic signed [DATA_WIDTH-1:0] data_b_pe1;
	logic signed [DATA_WIDTH-1:0] data_b_pe2;
	logic signed [DATA_WIDTH-1:0] data_b_pe3;

	// process element arrangment
	pe #(.DATA_WIDTH(DATA_WIDTH), .ACC_WIDTH(ACC_WIDTH)) pe_0 (
		.clk(clk),
		.rstn(rstn),
		.acc_en(acc_en),
		.data_a_i(data_a_0_i),
		.data_b_i(data_b_0_i),
		.data_a_o(data_a_pe0),
		.data_b_o(data_b_pe0),
		.acc_o(acc_0_r)
	);
	
	pe #(.DATA_WIDTH(DATA_WIDTH), .ACC_WIDTH(ACC_WIDTH)) pe_1 (
		.clk(clk),
		.rstn(rstn),
		.acc_en(acc_en),
		.data_a_i(data_a_pe0),
		.data_b_i(data_b_1_i),
		.data_a_o(data_a_pe1),
		.data_b_o(data_b_pe1),
		.acc_o(acc_1_r)
	);
	
	pe #(.DATA_WIDTH(DATA_WIDTH), .ACC_WIDTH(ACC_WIDTH)) pe_2 (
		.clk(clk),
		.rstn(rstn),
		.acc_en(acc_en),
		.data_a_i(data_a_1_i),
		.data_b_i(data_b_pe0),
		.data_a_o(data_a_pe2),
		.data_b_o(data_b_pe2),
		.acc_o(acc_2_r)
	);
	
	pe #(.DATA_WIDTH(DATA_WIDTH), .ACC_WIDTH(ACC_WIDTH)) pe_3 (
		.clk(clk),
		.rstn(rstn),
		.acc_en(acc_en),
		.data_a_i(data_a_pe2),
		.data_b_i(data_b_pe1),
		.data_a_o(data_a_pe3),
		.data_b_o(data_b_pe3),
		.acc_o(acc_3_r)
	);
	
	always @(posedge clk, negedge rstn) begin
		if(!rstn) begin

		end
	end

	assign acc_0_o = acc_0_r;
	assign acc_1_o = acc_1_r;
	assign acc_2_o = acc_2_r;
	assign acc_3_o = acc_3_r;

	// data_o
	assign pe_a_o = {data_a_pe1,data_a_pe3};
	assign pe_b_o = {data_b_pe2,data_b_pe3};
endmodule // systolic_array
