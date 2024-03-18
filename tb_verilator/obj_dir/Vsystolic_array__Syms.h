// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VSYSTOLIC_ARRAY__SYMS_H_
#define VERILATED_VSYSTOLIC_ARRAY__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vsystolic_array.h"

// INCLUDE MODULE CLASSES
#include "Vsystolic_array___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vsystolic_array__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vsystolic_array* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vsystolic_array___024root      TOP;

    // CONSTRUCTORS
    Vsystolic_array__Syms(VerilatedContext* contextp, const char* namep, Vsystolic_array* modelp);
    ~Vsystolic_array__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
