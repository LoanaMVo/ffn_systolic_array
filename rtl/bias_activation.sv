module bias_activation #(
    parameter DATA_WIDTH = 16
)(
	input  logic            [1:0]            activ_type_i,
    input  logic signed     [DATA_WIDTH-1:0] z_i, 
    output logic signed     [DATA_WIDTH-1:0] y_o
);
	logic signed [DATA_WIDTH-1:0] y_sigmoid;
	logic signed [DATA_WIDTH-1:0] y_relu;
	logic signed [DATA_WIDTH-1:0] z_int;

	// Quantize into activation type
	// ReLU, tanh, sigmoid
	always_comb begin
		case (activ_type_i)
			2'd0: // relu
				y_o = y_relu;
			2'd1: // sigmoid
				y_o = y_sigmoid;
            default: y_o = '0;
		endcase
	end
	
	assign z_int = z_i;

	relu #(.DATA_WIDTH(DATA_WIDTH)) relu_inst (
		.z_i(z_int),
		.y_o(y_relu)
	);

	sigmoid #(.DATA_WIDTH(DATA_WIDTH)) sigmoid_inst (
		.z_i(z_int),
		.y_o(y_sigmoid)
	);

endmodule // bias activation
