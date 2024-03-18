// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vsystolic_array__pch.h"

//============================================================
// Constructors

Vsystolic_array::Vsystolic_array(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vsystolic_array__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rstn{vlSymsp->TOP.rstn}
    , acc_en{vlSymsp->TOP.acc_en}
    , data_a_0_i{vlSymsp->TOP.data_a_0_i}
    , data_a_1_i{vlSymsp->TOP.data_a_1_i}
    , data_a_2_i{vlSymsp->TOP.data_a_2_i}
    , data_a_3_i{vlSymsp->TOP.data_a_3_i}
    , data_b_0_i{vlSymsp->TOP.data_b_0_i}
    , data_b_1_i{vlSymsp->TOP.data_b_1_i}
    , data_b_2_i{vlSymsp->TOP.data_b_2_i}
    , data_b_3_i{vlSymsp->TOP.data_b_3_i}
    , data_a_o{vlSymsp->TOP.data_a_o}
    , data_b_o{vlSymsp->TOP.data_b_o}
    , acc_0_o{vlSymsp->TOP.acc_0_o}
    , acc_1_o{vlSymsp->TOP.acc_1_o}
    , acc_2_o{vlSymsp->TOP.acc_2_o}
    , acc_3_o{vlSymsp->TOP.acc_3_o}
    , acc_4_o{vlSymsp->TOP.acc_4_o}
    , acc_5_o{vlSymsp->TOP.acc_5_o}
    , acc_6_o{vlSymsp->TOP.acc_6_o}
    , acc_7_o{vlSymsp->TOP.acc_7_o}
    , acc_8_o{vlSymsp->TOP.acc_8_o}
    , acc_9_o{vlSymsp->TOP.acc_9_o}
    , acc_10_o{vlSymsp->TOP.acc_10_o}
    , acc_11_o{vlSymsp->TOP.acc_11_o}
    , acc_12_o{vlSymsp->TOP.acc_12_o}
    , acc_13_o{vlSymsp->TOP.acc_13_o}
    , acc_14_o{vlSymsp->TOP.acc_14_o}
    , acc_15_o{vlSymsp->TOP.acc_15_o}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vsystolic_array::Vsystolic_array(const char* _vcname__)
    : Vsystolic_array(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vsystolic_array::~Vsystolic_array() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vsystolic_array___024root___eval_debug_assertions(Vsystolic_array___024root* vlSelf);
#endif  // VL_DEBUG
void Vsystolic_array___024root___eval_static(Vsystolic_array___024root* vlSelf);
void Vsystolic_array___024root___eval_initial(Vsystolic_array___024root* vlSelf);
void Vsystolic_array___024root___eval_settle(Vsystolic_array___024root* vlSelf);
void Vsystolic_array___024root___eval(Vsystolic_array___024root* vlSelf);

void Vsystolic_array::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vsystolic_array::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vsystolic_array___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vsystolic_array___024root___eval_static(&(vlSymsp->TOP));
        Vsystolic_array___024root___eval_initial(&(vlSymsp->TOP));
        Vsystolic_array___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vsystolic_array___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vsystolic_array::eventsPending() { return false; }

uint64_t Vsystolic_array::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vsystolic_array::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vsystolic_array___024root___eval_final(Vsystolic_array___024root* vlSelf);

VL_ATTR_COLD void Vsystolic_array::final() {
    Vsystolic_array___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vsystolic_array::hierName() const { return vlSymsp->name(); }
const char* Vsystolic_array::modelName() const { return "Vsystolic_array"; }
unsigned Vsystolic_array::threads() const { return 1; }
void Vsystolic_array::prepareClone() const { contextp()->prepareClone(); }
void Vsystolic_array::atClone() const {
    contextp()->threadPoolpOnClone();
}

//============================================================
// Trace configuration

VL_ATTR_COLD void Vsystolic_array::trace(VerilatedVcdC* tfp, int levels, int options) {
    vl_fatal(__FILE__, __LINE__, __FILE__,"'Vsystolic_array::trace()' called on model that was Verilated without --trace option");
}
