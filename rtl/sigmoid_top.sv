module sigmoid_top(
    input logic clk,
    input logic rstn,
    input  logic signed [16-1:0] z_i,
    output logic        [16-1:0] y_o
);
    logic signed [16-1:0] z_r;
    
    always_ff @(posedge clk, negedge rstn) begin
        if(~rstn) begin
            z_r <= '0;
        end else begin
            z_r <= z_i;
        end
    end

    sigmoid sigmoid_instn (
        .z_i(z_r),
        .y_o(y_o)
    );

endmodule // tb_sigmoid
