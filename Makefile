mac_test_ic:
	@echo "Compiling mac_test..."
	iverilog -o mac_test tb_icarus/tb_mac.sv rtl/mac.sv
	@echo "vvp..."
	vvp mac_test
	vcd2fst test.vcd test.fst
	rm -rf test.vcd

pe_test_ic:
	@echo "Compiling Systolic Array test..."
	iverilog -o pe_test tb_icarus/tb_pe.sv rtl/process_element.sv rtl/ mac.sv
	@ "Generating VVP..."
	vvp pe_test
	@ "Generating FST..."
	vcd2fst pe_test.vcd pe_test.fst
	rm -rf test.vcd
	
mac_test_ver:
	@echo "Compiling mac_test..."	
	verilator --cc ../rtl/mac.sv -I../rtl

clean:
	@echo "Cleaning up..."
	rm *.fst *_test

help: 
	@echo "Run targets: make <test_name>"
	@echo "test_name: mac_test pe_test"
