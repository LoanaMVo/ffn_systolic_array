module pe #(
	parameter DATA_WIDTH = 16,
	parameter ACC_WIDTH = 64
	) (    
	input logic clk,
    input logic rstn,
	// enable for accumulator
	input logic acc_en,
	// data a and b inputs
    input logic signed  [DATA_WIDTH - 1:0] data_a_i,
	input logic signed  [DATA_WIDTH - 1:0] data_b_i,
	input logic signed  [DATA_WDITH - 1:0] weight_i,
	// data a and b outputs
	output logic signed [DATA_WIDTH - 1:0] data_a_o,
    output logic signed [DATA_WIDTH - 1:0] data_b_o,
	// output accumulator
	output signed [ACC_WIDTH  - 1:0] acc_o
    );

	mac #(.DATA_WIDTH(DATA_WIDTH), .ACC_WIDTH(ACC_WIDTH)) mac_inst (
		.clk(clk),
		.rstn(rstn),
		.acc_en(acc_en),
		.data_a_i(data_a_i),
		.data_b_i(data_b_i),
		.weight_i(weight_i),
		.data_a_o(data_a_o),
		.data_b_o(data_b_o),
		.acc_o(acc_o)
	);

endmodule
