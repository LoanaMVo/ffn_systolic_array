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
    VL_OUT8(done_o,0,0);
    CData/*0:0*/ systolic_array__DOT__done_r;
    CData/*0:0*/ systolic_array__DOT__cnt_r;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__rstn__0;
    CData/*0:0*/ __VactContinue;
    VL_IN(data_a_0_i,16,0);
    VL_IN(data_a_1_i,16,0);
    VL_IN(data_b_0_i,16,0);
    VL_IN(data_b_1_i,16,0);
    VL_OUTW(acc_0_o,68,0,3);
    VL_OUTW(acc_1_o,68,0,3);
    VL_OUTW(acc_2_o,68,0,3);
    VL_OUTW(acc_3_o,68,0,3);
    VlWide<3>/*68:0*/ systolic_array__DOT__pe_0__DOT__mac_inst__DOT__acc_r;
    VlWide<3>/*68:0*/ systolic_array__DOT__pe_1__DOT__mac_inst__DOT__acc_r;
    VlWide<3>/*68:0*/ systolic_array__DOT__pe_2__DOT__mac_inst__DOT__acc_r;
    VlWide<3>/*68:0*/ systolic_array__DOT__pe_3__DOT__mac_inst__DOT__acc_r;
    IData/*31:0*/ __VactIterCount;
    VL_OUT64(pe_a_o,33,0);
    VL_OUT64(pe_b_o,33,0);
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
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
