// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vsystolic_array__pch.h"
#include "Vsystolic_array.h"
#include "Vsystolic_array___024root.h"

// FUNCTIONS
Vsystolic_array__Syms::~Vsystolic_array__Syms()
{
}

Vsystolic_array__Syms::Vsystolic_array__Syms(VerilatedContext* contextp, const char* namep, Vsystolic_array* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
        // Check resources
        Verilated::stackCheck(18);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
}
