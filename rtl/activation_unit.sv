/*def sigmoid(val):
    return 1/(1+numpy.exp(-val))

# calculate derivative of sigmoid function
# sigmoid'(x) = (e^-x)/(1+e^-x)^2
# Inputs:
#   val: input to put to derivative function
# Returns: output of derivative function at val
def sigmoid_deriv(val):
    exp_val = numpy.exp(-val)
    res = exp_val/((1+exp_val)*(1+exp_val))
    return res
*/

module activation_unit #(
	DATA_WIDTH = 8 ) (
	input [1:0] activ_type_i,
	input logic signed  [DATA_WIDTH-1:0] z_i,
	output logic signed [DATA_WIDTH-1:0] y_o
);
	logic [DATA_WIDTH-1:0] y_sigmoid;
	logic [DATA_WIDTH-1:0] y_relu;
	logic [DATA_WIDTH-1:0] y_tanh;
	logic signed [DATA_WIDTH*2-1:0] z_int;

	// Quantize into activation type
	// ReLU, tanh, sigmoid
	always_comb begin
		case (activ_type_i):
			2'd0: // relu
				y_o = y_relu;
			2'd1: // sigmoid
				y_o = y_sigmoid;
			2'd2: // tanh
				y_o = y_tanh;
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

	tanh #(.DATA_WIDTH(DATA_WIDTH)) tanh_inst (
		.z_i(z_int),
		.y_o(y_tanh)
	);

endmodule

