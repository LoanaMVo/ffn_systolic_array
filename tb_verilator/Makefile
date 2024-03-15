TEST := SYS_ARRAY
COMP := VERILATOR
TOP := systolic_array

make test_sim:
	verilator --cc ../rtl/$(TOP).sv -I../rtl
	verilator -Wall --trace -cc $(TOP).sv --exe tb_$(TOP).cpp -I../rtl/
	make -C obj_dir -f V$(TOP).mk V$(TOP)
	./obj_dir/V$(TOP)
	vcd2fst $(TOP)_test.vcd $(TOP)_test.fst
	rm -rf *.vcd

make clean:
	rm -rf *.fst
	rm -rf obj_dir/
	
