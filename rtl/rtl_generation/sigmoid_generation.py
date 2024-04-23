# Sigmoid RTL Generation
# Supports fixed point represenation 
# Qn.m format
# n - int_bits 
# m - frac_bits

# Example: For Q
import matplotlib.pyplot as plt
import numpy as np

def sigmoid(x):
    y = 1 / (1 + np.exp(-x))
    return y

def float_to_fixed_point_binary(data_width, float_number, frac_bits):
    scale_factor = 2 ** frac_bits # scale factor to quantize float
    fixed_point_num = bin(round(float_number * scale_factor))[2:].zfill(data_width)
    return fixed_point_num

def fixed_point_binary_to_float(binary, int_bits, frac_bits):
    int_part = int(binary[:int_bits], 2)
    frac_part = int(binary[int_bits:], 2) / (2 ** frac_bits)
    float_num = int_part + frac_part
    return float_num

def sigmoid_to_fixed_point(x, data_width, frac_bits):
    float_number = sigmoid(x)
    y_fixed_point = float_to_fixed_point_binary(data_width, float_number, frac_bits)
    return y_fixed_point

def lut_generation(frac_bits):
    #parameters
    # SQ1.7.8
    x_point = []
    y_point = []

    real_y_point = []

    sigmoid_input = []
    sigmoid_output = []
    int_max = 3 # 2^3 = 8 <- range of -8, 8 for sigmoid lut
    lut_width = frac_bits + int_max

    lut_range = 2**(lut_width)

    for i in range(lut_range):
        input_bin = bin(i)[2:].zfill(lut_width)
        input_float = fixed_point_binary_to_float(input_bin, int_max, frac_bits)
        output_fix = sigmoid_to_fixed_point(input_float,lut_width,frac_bits)
        output_float = fixed_point_binary_to_float(output_fix, int_max, frac_bits)

        real_y_point.append(sigmoid(input_float))
        x_point.append(input_float)
        y_point.append(output_float)

        sigmoid_input.append(input_bin)
        sigmoid_output.append(output_fix)
        #print("Input: int[{}] frac[{}] Dec({}) -> Output: int[{}] frac[{}] Dec[{}]".format(input_bin[7:10], input_bin[0:10],input_float,output_fix[7:10],output_fix[0:10],output_float))
    #plt.plot(x_point, real_ypoint)
    #plt.plot(x_point, y_point)
    #plt.show()
    return sigmoid_input, sigmoid_output, lut_range, lut_width

def write_sigmoid(data_width, int_bits, frac_bits):
    align = ""
    tab4 = "    "
    tab8 = tab4*2
    tab12 = tab4*3
    length = 2**(frac_bits) + 2**(3) 

    # LUT

    sigmoid_input, sigmoid_output, lut_range, lut_width = lut_generation(frac_bits)

    myarray = []

    # HEADER GENERATION
    myarray.append("// Sigmoid Activation Function\n" + "// McMaster Universiry, 4OJ4 Individual Research Course\n" +"// Author: Loana Vo\n" + "// Date: 2024\n")
    myarray.append("module sigmoid #(\n")
    myarray.append(tab4 + "parameter DATA_WIDTH = " + str(data_width) + "," + "\n")
    myarray.append(tab4 + "parameter INT_BITS = " + str(int_bits) + "," + "\n")
    myarray.append(tab4 + "parameter FRAC_BITS = " + str(frac_bits) + "\n")
    myarray.append(")(\n")
    myarray.append(tab4 + "input logic signed  [DATA_WIDTH-1:0] z_i,\n")
    myarray.append(tab4 + "output logic signed [DATA_WIDTH-1:0] y_o\n" + ");\n")
    myarray.append("\n")
    myarray.append(tab4 + "logic [FRAC_BITS + 3 : 0] y_int;\n")
    myarray.append("\n")
    myarray.append ("always_comb begin\n")
    myarray.append(tab4 + "// values greater than 'd8 are approximated to either 0 or 1 depending on sign\n")
    myarray.append(tab4 + "if ( | z_i[DATA_WIDTH - 2 : FRAC_BITS + 4]) begin\n")
    myarray.append(tab8 + "y_o = z_i[DATA_WIDTH-1] ? 'd0 : 'd1;\n")
    myarray.append(tab4 + "end else begin\n")
    myarray.append(tab8 + "case(z_i[FRAC_BITS + 3 : 0]):\n")

    for i in range(lut_range):
        myarray.append(tab12 + str(lut_width) + "'b" + str(sigmoid_input[i]) + ": y_int = " + str(lut_width) + "'b" + str(sigmoid_output[i]) + ";\n")
    
    myarray.append(tab8 + "endcase\n")

    myarray.append(tab8 + "y_o = z_i[DATA_WIDTH-1] ? -{5'b0, y_int} : {5'b0, y_int};\n")


    myarray.append(tab4 + "end\n")
    myarray.append("end\n")

    myarray.append("endmodule // sigmoid\n")

    return myarray

write_array = write_sigmoid(16, 8, 8)
f = open("/Users/loanavo/Library/CloudStorage/OneDrive-Personal/McMaster/Level 4 elec eng/4OJ4/Code/sigmoid.sv", "w")
f.writelines(write_array)
f.close()