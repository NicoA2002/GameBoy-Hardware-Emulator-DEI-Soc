// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VPPU3.h for the primary calling header

#include "verilated.h"

#include "VPPU3__Syms.h"
#include "VPPU3___024root.h"

void VPPU3___024root___ctor_var_reset(VPPU3___024root* vlSelf);

VPPU3___024root::VPPU3___024root(VPPU3__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VPPU3___024root___ctor_var_reset(this);
}

void VPPU3___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

VPPU3___024root::~VPPU3___024root() {
}
