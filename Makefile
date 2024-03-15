mac_test:
	@echo "Compiling mac_test..."
	iverilog -o mac_test tb/tb_mac.sv rtl/mac.sv
	@echo "vvp..."
	vvp mac_test
	vcd2fst test.vcd test.fst
	rm -rf test.vcd

pe_test:
	@echo "Compiling Systolic Array test..."
	iverilog -o pe_test tb/tb_pe.sv rtl/process_element.sv rtl/ mac.sv
	@ "Generating VVP..."
	vvp pe_test
	@ "Generating FST..."
	vcd2fst pe_test.vcd pe_test.fst
	rm -rf test.vcd
	
	

clean:
	@echo "Cleaning up..."
	rm *.fst *_test

help: 
	@echo "Run targets: make <test_name>"
	@echo "test_name: mac_test pe_test"
