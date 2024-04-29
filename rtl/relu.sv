// RELU
//McMaster Universiry, 4OJ4 Individual Research Course
// Author: Loana
// Date: Febuary 2024
module relu #(
    parameter DATA_WIDTH = 16
)(
    input logic signed  [DATA_WIDTH-1:0] z_i,
    output logic signed [DATA_WIDTH-1:0] y_o
);

    y_o = (| z_i[DATA_WIDTH-1]) ? 'd0 : z_i; // check MSB for negative

endmodule //relu
