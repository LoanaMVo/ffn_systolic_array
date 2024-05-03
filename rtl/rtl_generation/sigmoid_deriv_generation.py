# Sigmoid Derivative RTL Generation
# Supports fixed point represenation 
# Qn.m format
# n - int_bits 
# m - frac_bits

# Example: For Q
#import matplotlib.pyplot as plt
import numpy as np

def sigmoid(x):
    y = 1 / (1 + np.exp(-x))
    return y

def sigmoid_deriv(x):
    y = sigmoid(x)*(1-sigmoid(x))
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

def sigmoid_deriv_to_fixed_point(x, data_width, frac_bits):
    float_number = sigmoid_deriv(x)
    y_fixed_point = float_to_fixed_point_binary(data_width, float_number, frac_bits)
    return y_fixed_point

def lut_generation(max_int_range, frac_bits):
    #parameters
    # SQ1.7.8
    error = []
    x_point = []
    y_point = []

    real_y_point = []

    sigmoid_input = []
    sigmoid_output = []
    lut_width = frac_bits + max_int_range

    lut_range = 2**(lut_width)

    for i in range(lut_range):
        input_bin = bin(i)[2:].zfill(lut_width)
        input_float = fixed_point_binary_to_float(input_bin, max_int_range, frac_bits)
        output_fix = sigmoid_deriv_to_fixed_point(input_float,lut_width,frac_bits)
        output_float = fixed_point_binary_to_float(output_fix, max_int_range, frac_bits)

        real_y = sigmoid_deriv(input_float)

        real_y_point.append(real_y)
        x_point.append(input_float)
        y_point.append(output_float)

        sigmoid_input.append(input_bin)
        sigmoid_output.append(output_fix)
        #error.append(abs(output_float - real_y))
        #error.append(abs((output_float - real_y)/real_y)*100) # relative error
        #print(input_float)
        #print(int(input_bin,2)/256)
        #print("Input: int[{}] frac[{}] Dec({}) -> Output: int[{}] frac[{}] Dec[{}]".format(input_bin[7:10], input_bin[0:10],input_float,output_fix[7:10],output_fix[0:10],output_float))
    #print(max(error))

    #plt.plot(x_point, real_y_point)
    #plt.plot(x_point, y_point)
    #plt.plot(x_point, error)
    #plt.show()
    return sigmoid_input, sigmoid_output, lut_range, lut_width

def write_sigmoid(data_width, max_int_range, frac_bits):
    align = ""
    tab4 = "    "
    tab8 = tab4*2
    tab12 = tab4*3
    length = 2**(frac_bits) + 2**(3) 

    # LUT
    sigmoid_input, sigmoid_output, lut_range, lut_width = lut_generation(max_int_range,frac_bits)

    sigmoid_list = []

    # HEADER GENERATION
    sigmoid_list.append("// Sigmoid Derivative LUT\n" + "// McMaster Universiry, 4OJ4 Individual Research Course\n" +"// Author: Loana Vo\n" + "// Date: 2024\n")
    sigmoid_list.append("module sigmoid_deriv_lut #(\n")
    sigmoid_list.append(tab4 + "parameter DATA_WIDTH = " + str(data_width) + "," + "\n")
    sigmoid_list.append(tab4 + "parameter FRAC_BITS = " + str(frac_bits) + "\n")
    sigmoid_list.append(")(\n")
    sigmoid_list.append(tab4 + "input logic signed  [DATA_WIDTH-1:0] case_i,\n")
    sigmoid_list.append(tab4 + "output logic signed [DATA_WIDTH-1:0] y_int\n" + ");\n")
    sigmoid_list.append("\n")

    sigmoid_list.append (tab4 + "always_comb begin\n")
    sigmoid_list.append( tab8 + "case(case_i)\n")
    # generating LUT
    for i in range(lut_range):
        sigmoid_list.append(tab12 + str(lut_width) + "'b" + str(sigmoid_input[i]) + ": y_int = " + str(lut_width) + "'b" + str(sigmoid_output[i]) + ";\n")
    sigmoid_list.append(tab12 + "default: y_int = 11'b0;\n")
    sigmoid_list.append(tab8 + "endcase\n")
    sigmoid_list.append(tab4 + "end\n")

    sigmoid_list.append("endmodule // sigmoid_deriv_lut\n")

    return sigmoid_list

# Either use sigmoid LUT and paste into module or directly generate the sigmoid file

##############################
# Parameters
##############################
data_width = 16
max_int_range = 3 # 2^3 = 8 <- range of -8, 8 for sigmoid lut
frac_bits = 8 # 8 frac bits

# testing
#lut_generation(max_int_range,frac_bits)
##############################
# HOW TO CREATE SIGMOID.SV
##############################
# 16 -> DATA WIDTH, 8 -> FRACTIONAL BITS
write_array = write_sigmoid(data_width, max_int_range, frac_bits)
root_dir = "/home/debian/LoanaVo/ffn_systolic_array/rtl/"
filename = "sigmoid_deriv_lut.sv"
f = open(root_dir + filename, "w")
f.writelines(write_array)
f.close()
