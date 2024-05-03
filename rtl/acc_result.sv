module acc_result #(
        parameter DATA_WIDTH=64
    )(
        input logic clk,
        input logic rstn,
        input logic acc_en,
        input logic signed  [DATA_WIDTH-1:0] acc_i,
        output logic signed [DATA_WIDTH-1:0] acc_o       
    );

    logic signed [DATA_WIDTH-1:0] acc_r;

    always @(posedge clk, negedge rstn) begin
        if(!rstn) begin
            acc_r <= '0;
        end else begin
            if (acc_en)
                acc_r <= acc_r + acc_i;
        end
    end
    
    assign acc_o = acc_r;

endmodule 
