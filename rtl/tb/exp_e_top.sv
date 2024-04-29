module exp_e_top(
    input logic clk,
    input logic rstn,
    input logic signed [31:0] x_i,
    output logic signed [31:0] y_o
    );
    
    logic signed [31:0] x_r; 

    always_ff @(posedge clk, negedge rstn) begin
        if(~rstn) begin
            x_r <= '0;
        end
        x_r <= x_i;
    end

    exp_e exp_e_instn (
    .x_i(x_r),
    .y_o(y_o)
    );

endmodule
