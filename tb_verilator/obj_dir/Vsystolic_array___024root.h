// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vsystolic_array.h for the primary calling header

#ifndef VERILATED_VSYSTOLIC_ARRAY___024ROOT_H_
#define VERILATED_VSYSTOLIC_ARRAY___024ROOT_H_  // guard

#include "verilated.h"


class Vsystolic_array__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vsystolic_array___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rstn,0,0);
    VL_IN8(acc_en,0,0);
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__rstn__0;
    CData/*0:0*/ __VactContinue;
    VL_IN16(data_a_0_i,15,0);
    VL_IN16(data_a_1_i,15,0);
    VL_IN16(data_b_0_i,15,0);
    VL_IN16(data_b_1_i,15,0);
    SData/*15:0*/ systolic_array__DOT__pe_0__DOT__mac_inst__DOT__data_a_r;
    SData/*15:0*/ systolic_array__DOT__pe_0__DOT__mac_inst__DOT__data_b_r;
    SData/*15:0*/ systolic_array__DOT__pe_1__DOT__mac_inst__DOT__data_a_r;
    SData/*15:0*/ systolic_array__DOT__pe_1__DOT__mac_inst__DOT__data_b_r;
    SData/*15:0*/ systolic_array__DOT__pe_2__DOT__mac_inst__DOT__data_a_r;
    SData/*15:0*/ systolic_array__DOT__pe_2__DOT__mac_inst__DOT__data_b_r;
    SData/*15:0*/ systolic_array__DOT__pe_3__DOT__mac_inst__DOT__data_a_r;
    SData/*15:0*/ systolic_array__DOT__pe_3__DOT__mac_inst__DOT__data_b_r;
    VL_OUT(pe_a_o,31,0);
    VL_OUT(pe_b_o,31,0);
    IData/*31:0*/ __VactIterCount;
    VL_OUT64(acc_0_o,63,0);
    VL_OUT64(acc_1_o,63,0);
    VL_OUT64(acc_2_o,63,0);
    VL_OUT64(acc_3_o,63,0);
    QData/*63:0*/ systolic_array__DOT__pe_0__DOT__mac_inst__DOT__acc_r;
    QData/*63:0*/ systolic_array__DOT__pe_1__DOT__mac_inst__DOT__acc_r;
    QData/*63:0*/ systolic_array__DOT__pe_2__DOT__mac_inst__DOT__acc_r;
    QData/*63:0*/ systolic_array__DOT__pe_3__DOT__mac_inst__DOT__acc_r;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vsystolic_array__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vsystolic_array___024root(Vsystolic_array__Syms* symsp, const char* v__name);
    ~Vsystolic_array___024root();
    VL_UNCOPYABLE(Vsystolic_array___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
