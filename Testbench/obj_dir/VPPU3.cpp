// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VPPU3.h for the primary calling header

#include "VPPU3.h"
#include "VPPU3__Syms.h"

//==========

VL_CTOR_IMP(VPPU3) {
    VPPU3__Syms* __restrict vlSymsp = __VlSymsp = new VPPU3__Syms(this, name());
    VPPU3* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VPPU3::__Vconfigure(VPPU3__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

VPPU3::~VPPU3() {
    delete __VlSymsp; __VlSymsp=NULL;
}

void VPPU3::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VPPU3::eval\n"); );
    VPPU3__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    VPPU3* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("../PPU3.sv", 6, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VPPU3::_eval_initial_loop(VPPU3__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("../PPU3.sv", 6, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void VPPU3::_sequent__TOP__1(VPPU3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPPU3::_sequent__TOP__1\n"); );
    VPPU3* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*0:0*/ __Vdlyvset__PPU3__DOT__SP_PRIPN__v0;
    CData/*1:0*/ __Vdlyvval__PPU3__DOT__SP_PRIPN__v10;
    CData/*0:0*/ __Vdlyvset__PPU3__DOT__SP_PRIPN__v10;
    CData/*1:0*/ __Vdlyvval__PPU3__DOT__SP_PRIPN__v11;
    CData/*0:0*/ __Vdlyvset__PPU3__DOT__SP_PRIPN__v11;
    CData/*1:0*/ __Vdlyvval__PPU3__DOT__SP_PRIPN__v12;
    CData/*0:0*/ __Vdlyvset__PPU3__DOT__SP_PRIPN__v12;
    CData/*1:0*/ __Vdlyvval__PPU3__DOT__SP_PRIPN__v13;
    CData/*0:0*/ __Vdlyvset__PPU3__DOT__SP_PRIPN__v13;
    CData/*1:0*/ __Vdlyvval__PPU3__DOT__SP_PRIPN__v14;
    CData/*0:0*/ __Vdlyvset__PPU3__DOT__SP_PRIPN__v14;
    CData/*1:0*/ __Vdlyvval__PPU3__DOT__SP_PRIPN__v15;
    CData/*0:0*/ __Vdlyvset__PPU3__DOT__SP_PRIPN__v15;
    CData/*1:0*/ __Vdlyvval__PPU3__DOT__SP_PRIPN__v16;
    CData/*0:0*/ __Vdlyvset__PPU3__DOT__SP_PRIPN__v16;
    CData/*1:0*/ __Vdlyvval__PPU3__DOT__SP_PRIPN__v17;
    CData/*0:0*/ __Vdlyvset__PPU3__DOT__SP_PRIPN__v17;
    CData/*1:0*/ __Vdlyvval__PPU3__DOT__SP_PRIPN__v18;
    CData/*0:0*/ __Vdlyvset__PPU3__DOT__SP_PRIPN__v18;
    CData/*1:0*/ __Vdlyvval__PPU3__DOT__SP_PRIPN__v19;
    CData/*0:0*/ __Vdlyvset__PPU3__DOT__SP_PRIPN__v19;
    CData/*3:0*/ __Vdly__PPU3__DOT__sp_table_cnt;
    CData/*0:0*/ __Vdly__PPU3__DOT__sp_found;
    CData/*0:0*/ __Vdlyvset__PPU3__DOT__sp_y_table__v0;
    CData/*3:0*/ __Vdlyvdim0__PPU3__DOT__sp_x_table__v10;
    CData/*7:0*/ __Vdlyvval__PPU3__DOT__sp_x_table__v10;
    CData/*0:0*/ __Vdlyvset__PPU3__DOT__sp_x_table__v10;
    CData/*3:0*/ __Vdlyvdim0__PPU3__DOT__sp_name_table__v0;
    CData/*5:0*/ __Vdlyvval__PPU3__DOT__sp_name_table__v0;
    CData/*0:0*/ __Vdlyvset__PPU3__DOT__sp_name_table__v0;
    CData/*3:0*/ __Vdlyvdim0__PPU3__DOT__sp_y_table__v10;
    CData/*7:0*/ __Vdlyvval__PPU3__DOT__sp_y_table__v10;
    CData/*0:0*/ __Vdlyvset__PPU3__DOT__sp_y_table__v10;
    CData/*2:0*/ __Vdly__PPU3__DOT__BGWD_CNT;
    CData/*2:0*/ __Vdly__PPU3__DOT__SP_CNT;
    CData/*7:0*/ __Vdly__PPU3__DOT__SP_FLAG;
    CData/*0:0*/ __Vdlyvset__PPU3__DOT__SP_SHIFT_REG9__DOT__shift_reg__v0;
    CData/*7:0*/ __Vdlyvval__PPU3__DOT__SP_SHIFT_REG9__DOT__shift_reg__v2;
    CData/*0:0*/ __Vdlyvset__PPU3__DOT__SP_SHIFT_REG9__DOT__shift_reg__v2;
    CData/*7:0*/ __Vdlyvval__PPU3__DOT__SP_SHIFT_REG9__DOT__shift_reg__v3;
    CData/*2:0*/ __Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG9__DOT__shift_reg__v4;
    CData/*6:0*/ __Vdlyvval__PPU3__DOT__SP_SHIFT_REG9__DOT__shift_reg__v4;
    CData/*0:0*/ __Vdlyvset__PPU3__DOT__SP_SHIFT_REG9__DOT__shift_reg__v4;
    CData/*2:0*/ __Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG9__DOT__shift_reg__v5;
    CData/*2:0*/ __Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG9__DOT__shift_reg__v6;
    CData/*6:0*/ __Vdlyvval__PPU3__DOT__SP_SHIFT_REG9__DOT__shift_reg__v6;
    CData/*2:0*/ __Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG9__DOT__shift_reg__v7;
    CData/*0:0*/ __Vdlyvset__PPU3__DOT__SP_SHIFT_REG8__DOT__shift_reg__v0;
    CData/*7:0*/ __Vdlyvval__PPU3__DOT__SP_SHIFT_REG8__DOT__shift_reg__v2;
    CData/*0:0*/ __Vdlyvset__PPU3__DOT__SP_SHIFT_REG8__DOT__shift_reg__v2;
    CData/*7:0*/ __Vdlyvval__PPU3__DOT__SP_SHIFT_REG8__DOT__shift_reg__v3;
    CData/*2:0*/ __Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG8__DOT__shift_reg__v4;
    CData/*6:0*/ __Vdlyvval__PPU3__DOT__SP_SHIFT_REG8__DOT__shift_reg__v4;
    CData/*0:0*/ __Vdlyvset__PPU3__DOT__SP_SHIFT_REG8__DOT__shift_reg__v4;
    CData/*2:0*/ __Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG8__DOT__shift_reg__v5;
    CData/*2:0*/ __Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG8__DOT__shift_reg__v6;
    CData/*6:0*/ __Vdlyvval__PPU3__DOT__SP_SHIFT_REG8__DOT__shift_reg__v6;
    CData/*2:0*/ __Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG8__DOT__shift_reg__v7;
    CData/*0:0*/ __Vdlyvset__PPU3__DOT__SP_SHIFT_REG7__DOT__shift_reg__v0;
    CData/*7:0*/ __Vdlyvval__PPU3__DOT__SP_SHIFT_REG7__DOT__shift_reg__v2;
    CData/*0:0*/ __Vdlyvset__PPU3__DOT__SP_SHIFT_REG7__DOT__shift_reg__v2;
    CData/*7:0*/ __Vdlyvval__PPU3__DOT__SP_SHIFT_REG7__DOT__shift_reg__v3;
    CData/*2:0*/ __Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG7__DOT__shift_reg__v4;
    CData/*6:0*/ __Vdlyvval__PPU3__DOT__SP_SHIFT_REG7__DOT__shift_reg__v4;
    CData/*0:0*/ __Vdlyvset__PPU3__DOT__SP_SHIFT_REG7__DOT__shift_reg__v4;
    CData/*2:0*/ __Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG7__DOT__shift_reg__v5;
    CData/*2:0*/ __Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG7__DOT__shift_reg__v6;
    CData/*6:0*/ __Vdlyvval__PPU3__DOT__SP_SHIFT_REG7__DOT__shift_reg__v6;
    CData/*2:0*/ __Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG7__DOT__shift_reg__v7;
    CData/*0:0*/ __Vdlyvset__PPU3__DOT__SP_SHIFT_REG6__DOT__shift_reg__v0;
    CData/*7:0*/ __Vdlyvval__PPU3__DOT__SP_SHIFT_REG6__DOT__shift_reg__v2;
    CData/*0:0*/ __Vdlyvset__PPU3__DOT__SP_SHIFT_REG6__DOT__shift_reg__v2;
    CData/*7:0*/ __Vdlyvval__PPU3__DOT__SP_SHIFT_REG6__DOT__shift_reg__v3;
    CData/*2:0*/ __Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG6__DOT__shift_reg__v4;
    CData/*6:0*/ __Vdlyvval__PPU3__DOT__SP_SHIFT_REG6__DOT__shift_reg__v4;
    CData/*0:0*/ __Vdlyvset__PPU3__DOT__SP_SHIFT_REG6__DOT__shift_reg__v4;
    CData/*2:0*/ __Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG6__DOT__shift_reg__v5;
    CData/*2:0*/ __Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG6__DOT__shift_reg__v6;
    CData/*6:0*/ __Vdlyvval__PPU3__DOT__SP_SHIFT_REG6__DOT__shift_reg__v6;
    CData/*2:0*/ __Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG6__DOT__shift_reg__v7;
    CData/*0:0*/ __Vdlyvset__PPU3__DOT__SP_SHIFT_REG5__DOT__shift_reg__v0;
    CData/*7:0*/ __Vdlyvval__PPU3__DOT__SP_SHIFT_REG5__DOT__shift_reg__v2;
    CData/*0:0*/ __Vdlyvset__PPU3__DOT__SP_SHIFT_REG5__DOT__shift_reg__v2;
    CData/*7:0*/ __Vdlyvval__PPU3__DOT__SP_SHIFT_REG5__DOT__shift_reg__v3;
    CData/*2:0*/ __Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG5__DOT__shift_reg__v4;
    CData/*6:0*/ __Vdlyvval__PPU3__DOT__SP_SHIFT_REG5__DOT__shift_reg__v4;
    CData/*0:0*/ __Vdlyvset__PPU3__DOT__SP_SHIFT_REG5__DOT__shift_reg__v4;
    CData/*2:0*/ __Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG5__DOT__shift_reg__v5;
    CData/*2:0*/ __Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG5__DOT__shift_reg__v6;
    CData/*6:0*/ __Vdlyvval__PPU3__DOT__SP_SHIFT_REG5__DOT__shift_reg__v6;
    CData/*2:0*/ __Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG5__DOT__shift_reg__v7;
    CData/*0:0*/ __Vdlyvset__PPU3__DOT__SP_SHIFT_REG4__DOT__shift_reg__v0;
    CData/*7:0*/ __Vdlyvval__PPU3__DOT__SP_SHIFT_REG4__DOT__shift_reg__v2;
    CData/*0:0*/ __Vdlyvset__PPU3__DOT__SP_SHIFT_REG4__DOT__shift_reg__v2;
    CData/*7:0*/ __Vdlyvval__PPU3__DOT__SP_SHIFT_REG4__DOT__shift_reg__v3;
    CData/*2:0*/ __Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG4__DOT__shift_reg__v4;
    CData/*6:0*/ __Vdlyvval__PPU3__DOT__SP_SHIFT_REG4__DOT__shift_reg__v4;
    CData/*0:0*/ __Vdlyvset__PPU3__DOT__SP_SHIFT_REG4__DOT__shift_reg__v4;
    CData/*2:0*/ __Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG4__DOT__shift_reg__v5;
    CData/*2:0*/ __Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG4__DOT__shift_reg__v6;
    CData/*6:0*/ __Vdlyvval__PPU3__DOT__SP_SHIFT_REG4__DOT__shift_reg__v6;
    CData/*2:0*/ __Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG4__DOT__shift_reg__v7;
    CData/*0:0*/ __Vdlyvset__PPU3__DOT__SP_SHIFT_REG3__DOT__shift_reg__v0;
    CData/*7:0*/ __Vdlyvval__PPU3__DOT__SP_SHIFT_REG3__DOT__shift_reg__v2;
    CData/*0:0*/ __Vdlyvset__PPU3__DOT__SP_SHIFT_REG3__DOT__shift_reg__v2;
    CData/*7:0*/ __Vdlyvval__PPU3__DOT__SP_SHIFT_REG3__DOT__shift_reg__v3;
    CData/*2:0*/ __Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG3__DOT__shift_reg__v4;
    CData/*6:0*/ __Vdlyvval__PPU3__DOT__SP_SHIFT_REG3__DOT__shift_reg__v4;
    CData/*0:0*/ __Vdlyvset__PPU3__DOT__SP_SHIFT_REG3__DOT__shift_reg__v4;
    CData/*2:0*/ __Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG3__DOT__shift_reg__v5;
    CData/*2:0*/ __Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG3__DOT__shift_reg__v6;
    CData/*6:0*/ __Vdlyvval__PPU3__DOT__SP_SHIFT_REG3__DOT__shift_reg__v6;
    CData/*2:0*/ __Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG3__DOT__shift_reg__v7;
    CData/*0:0*/ __Vdlyvset__PPU3__DOT__SP_SHIFT_REG2__DOT__shift_reg__v0;
    CData/*7:0*/ __Vdlyvval__PPU3__DOT__SP_SHIFT_REG2__DOT__shift_reg__v2;
    CData/*0:0*/ __Vdlyvset__PPU3__DOT__SP_SHIFT_REG2__DOT__shift_reg__v2;
    CData/*7:0*/ __Vdlyvval__PPU3__DOT__SP_SHIFT_REG2__DOT__shift_reg__v3;
    CData/*2:0*/ __Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG2__DOT__shift_reg__v4;
    CData/*6:0*/ __Vdlyvval__PPU3__DOT__SP_SHIFT_REG2__DOT__shift_reg__v4;
    CData/*0:0*/ __Vdlyvset__PPU3__DOT__SP_SHIFT_REG2__DOT__shift_reg__v4;
    CData/*2:0*/ __Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG2__DOT__shift_reg__v5;
    CData/*2:0*/ __Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG2__DOT__shift_reg__v6;
    CData/*6:0*/ __Vdlyvval__PPU3__DOT__SP_SHIFT_REG2__DOT__shift_reg__v6;
    CData/*2:0*/ __Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG2__DOT__shift_reg__v7;
    CData/*0:0*/ __Vdlyvset__PPU3__DOT__SP_SHIFT_REG1__DOT__shift_reg__v0;
    CData/*7:0*/ __Vdlyvval__PPU3__DOT__SP_SHIFT_REG1__DOT__shift_reg__v2;
    CData/*0:0*/ __Vdlyvset__PPU3__DOT__SP_SHIFT_REG1__DOT__shift_reg__v2;
    CData/*7:0*/ __Vdlyvval__PPU3__DOT__SP_SHIFT_REG1__DOT__shift_reg__v3;
    CData/*2:0*/ __Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG1__DOT__shift_reg__v4;
    CData/*6:0*/ __Vdlyvval__PPU3__DOT__SP_SHIFT_REG1__DOT__shift_reg__v4;
    CData/*0:0*/ __Vdlyvset__PPU3__DOT__SP_SHIFT_REG1__DOT__shift_reg__v4;
    CData/*2:0*/ __Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG1__DOT__shift_reg__v5;
    CData/*2:0*/ __Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG1__DOT__shift_reg__v6;
    CData/*6:0*/ __Vdlyvval__PPU3__DOT__SP_SHIFT_REG1__DOT__shift_reg__v6;
    CData/*2:0*/ __Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG1__DOT__shift_reg__v7;
    CData/*0:0*/ __Vdlyvset__PPU3__DOT__SP_SHIFT_REG0__DOT__shift_reg__v0;
    CData/*7:0*/ __Vdlyvval__PPU3__DOT__SP_SHIFT_REG0__DOT__shift_reg__v2;
    CData/*0:0*/ __Vdlyvset__PPU3__DOT__SP_SHIFT_REG0__DOT__shift_reg__v2;
    CData/*7:0*/ __Vdlyvval__PPU3__DOT__SP_SHIFT_REG0__DOT__shift_reg__v3;
    CData/*2:0*/ __Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG0__DOT__shift_reg__v4;
    CData/*6:0*/ __Vdlyvval__PPU3__DOT__SP_SHIFT_REG0__DOT__shift_reg__v4;
    CData/*0:0*/ __Vdlyvset__PPU3__DOT__SP_SHIFT_REG0__DOT__shift_reg__v4;
    CData/*2:0*/ __Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG0__DOT__shift_reg__v5;
    CData/*2:0*/ __Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG0__DOT__shift_reg__v6;
    CData/*6:0*/ __Vdlyvval__PPU3__DOT__SP_SHIFT_REG0__DOT__shift_reg__v6;
    CData/*2:0*/ __Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG0__DOT__shift_reg__v7;
    CData/*0:0*/ __Vdlyvset__PPU3__DOT__BGWD_SHIFT_REG_A__DOT__shift_reg__v0;
    CData/*7:0*/ __Vdlyvval__PPU3__DOT__BGWD_SHIFT_REG_A__DOT__shift_reg__v2;
    CData/*0:0*/ __Vdlyvset__PPU3__DOT__BGWD_SHIFT_REG_A__DOT__shift_reg__v2;
    CData/*7:0*/ __Vdlyvval__PPU3__DOT__BGWD_SHIFT_REG_A__DOT__shift_reg__v3;
    CData/*2:0*/ __Vdlyvlsb__PPU3__DOT__BGWD_SHIFT_REG_A__DOT__shift_reg__v4;
    CData/*6:0*/ __Vdlyvval__PPU3__DOT__BGWD_SHIFT_REG_A__DOT__shift_reg__v4;
    CData/*0:0*/ __Vdlyvset__PPU3__DOT__BGWD_SHIFT_REG_A__DOT__shift_reg__v4;
    CData/*2:0*/ __Vdlyvlsb__PPU3__DOT__BGWD_SHIFT_REG_A__DOT__shift_reg__v5;
    CData/*2:0*/ __Vdlyvlsb__PPU3__DOT__BGWD_SHIFT_REG_A__DOT__shift_reg__v6;
    CData/*6:0*/ __Vdlyvval__PPU3__DOT__BGWD_SHIFT_REG_A__DOT__shift_reg__v6;
    CData/*2:0*/ __Vdlyvlsb__PPU3__DOT__BGWD_SHIFT_REG_A__DOT__shift_reg__v7;
    CData/*0:0*/ __Vdlyvset__PPU3__DOT__BGWD_SHIFT_REG_B__DOT__shift_reg__v0;
    CData/*7:0*/ __Vdlyvval__PPU3__DOT__BGWD_SHIFT_REG_B__DOT__shift_reg__v2;
    CData/*0:0*/ __Vdlyvset__PPU3__DOT__BGWD_SHIFT_REG_B__DOT__shift_reg__v2;
    CData/*7:0*/ __Vdlyvval__PPU3__DOT__BGWD_SHIFT_REG_B__DOT__shift_reg__v3;
    CData/*2:0*/ __Vdlyvlsb__PPU3__DOT__BGWD_SHIFT_REG_B__DOT__shift_reg__v4;
    CData/*6:0*/ __Vdlyvval__PPU3__DOT__BGWD_SHIFT_REG_B__DOT__shift_reg__v4;
    CData/*0:0*/ __Vdlyvset__PPU3__DOT__BGWD_SHIFT_REG_B__DOT__shift_reg__v4;
    CData/*2:0*/ __Vdlyvlsb__PPU3__DOT__BGWD_SHIFT_REG_B__DOT__shift_reg__v5;
    CData/*2:0*/ __Vdlyvlsb__PPU3__DOT__BGWD_SHIFT_REG_B__DOT__shift_reg__v6;
    CData/*6:0*/ __Vdlyvval__PPU3__DOT__BGWD_SHIFT_REG_B__DOT__shift_reg__v6;
    CData/*2:0*/ __Vdlyvlsb__PPU3__DOT__BGWD_SHIFT_REG_B__DOT__shift_reg__v7;
    // Body
    __Vdly__PPU3__DOT__BGWD_CNT = vlTOPp->PPU3__DOT__BGWD_CNT;
    __Vdly__PPU3__DOT__SP_FLAG = vlTOPp->PPU3__DOT__SP_FLAG;
    __Vdly__PPU3__DOT__SP_CNT = vlTOPp->PPU3__DOT__SP_CNT;
    __Vdlyvset__PPU3__DOT__SP_SHIFT_REG0__DOT__shift_reg__v0 = 0U;
    __Vdlyvset__PPU3__DOT__SP_SHIFT_REG0__DOT__shift_reg__v2 = 0U;
    __Vdlyvset__PPU3__DOT__SP_SHIFT_REG0__DOT__shift_reg__v4 = 0U;
    __Vdlyvset__PPU3__DOT__SP_SHIFT_REG1__DOT__shift_reg__v0 = 0U;
    __Vdlyvset__PPU3__DOT__SP_SHIFT_REG1__DOT__shift_reg__v2 = 0U;
    __Vdlyvset__PPU3__DOT__SP_SHIFT_REG1__DOT__shift_reg__v4 = 0U;
    __Vdlyvset__PPU3__DOT__SP_SHIFT_REG2__DOT__shift_reg__v0 = 0U;
    __Vdlyvset__PPU3__DOT__SP_SHIFT_REG2__DOT__shift_reg__v2 = 0U;
    __Vdlyvset__PPU3__DOT__SP_SHIFT_REG2__DOT__shift_reg__v4 = 0U;
    __Vdlyvset__PPU3__DOT__SP_SHIFT_REG3__DOT__shift_reg__v0 = 0U;
    __Vdlyvset__PPU3__DOT__SP_SHIFT_REG3__DOT__shift_reg__v2 = 0U;
    __Vdlyvset__PPU3__DOT__SP_SHIFT_REG3__DOT__shift_reg__v4 = 0U;
    __Vdlyvset__PPU3__DOT__SP_SHIFT_REG4__DOT__shift_reg__v0 = 0U;
    __Vdlyvset__PPU3__DOT__SP_SHIFT_REG4__DOT__shift_reg__v2 = 0U;
    __Vdlyvset__PPU3__DOT__SP_SHIFT_REG4__DOT__shift_reg__v4 = 0U;
    __Vdlyvset__PPU3__DOT__SP_SHIFT_REG5__DOT__shift_reg__v0 = 0U;
    __Vdlyvset__PPU3__DOT__SP_SHIFT_REG5__DOT__shift_reg__v2 = 0U;
    __Vdlyvset__PPU3__DOT__SP_SHIFT_REG5__DOT__shift_reg__v4 = 0U;
    __Vdlyvset__PPU3__DOT__SP_SHIFT_REG6__DOT__shift_reg__v0 = 0U;
    __Vdlyvset__PPU3__DOT__SP_SHIFT_REG6__DOT__shift_reg__v2 = 0U;
    __Vdlyvset__PPU3__DOT__SP_SHIFT_REG6__DOT__shift_reg__v4 = 0U;
    __Vdlyvset__PPU3__DOT__SP_SHIFT_REG7__DOT__shift_reg__v0 = 0U;
    __Vdlyvset__PPU3__DOT__SP_SHIFT_REG7__DOT__shift_reg__v2 = 0U;
    __Vdlyvset__PPU3__DOT__SP_SHIFT_REG7__DOT__shift_reg__v4 = 0U;
    __Vdlyvset__PPU3__DOT__SP_SHIFT_REG8__DOT__shift_reg__v0 = 0U;
    __Vdlyvset__PPU3__DOT__SP_SHIFT_REG8__DOT__shift_reg__v2 = 0U;
    __Vdlyvset__PPU3__DOT__SP_SHIFT_REG8__DOT__shift_reg__v4 = 0U;
    __Vdlyvset__PPU3__DOT__SP_SHIFT_REG9__DOT__shift_reg__v0 = 0U;
    __Vdlyvset__PPU3__DOT__SP_SHIFT_REG9__DOT__shift_reg__v2 = 0U;
    __Vdlyvset__PPU3__DOT__SP_SHIFT_REG9__DOT__shift_reg__v4 = 0U;
    __Vdlyvset__PPU3__DOT__BGWD_SHIFT_REG_B__DOT__shift_reg__v0 = 0U;
    __Vdlyvset__PPU3__DOT__BGWD_SHIFT_REG_B__DOT__shift_reg__v2 = 0U;
    __Vdlyvset__PPU3__DOT__BGWD_SHIFT_REG_B__DOT__shift_reg__v4 = 0U;
    __Vdlyvset__PPU3__DOT__BGWD_SHIFT_REG_A__DOT__shift_reg__v0 = 0U;
    __Vdlyvset__PPU3__DOT__BGWD_SHIFT_REG_A__DOT__shift_reg__v2 = 0U;
    __Vdlyvset__PPU3__DOT__BGWD_SHIFT_REG_A__DOT__shift_reg__v4 = 0U;
    __Vdly__PPU3__DOT__sp_found = vlTOPp->PPU3__DOT__sp_found;
    __Vdly__PPU3__DOT__sp_table_cnt = vlTOPp->PPU3__DOT__sp_table_cnt;
    __Vdlyvset__PPU3__DOT__sp_x_table__v10 = 0U;
    __Vdlyvset__PPU3__DOT__sp_name_table__v0 = 0U;
    __Vdlyvset__PPU3__DOT__sp_y_table__v10 = 0U;
    __Vdlyvset__PPU3__DOT__sp_y_table__v0 = 0U;
    __Vdlyvset__PPU3__DOT__SP_PRIPN__v0 = 0U;
    __Vdlyvset__PPU3__DOT__SP_PRIPN__v10 = 0U;
    __Vdlyvset__PPU3__DOT__SP_PRIPN__v11 = 0U;
    __Vdlyvset__PPU3__DOT__SP_PRIPN__v12 = 0U;
    __Vdlyvset__PPU3__DOT__SP_PRIPN__v13 = 0U;
    __Vdlyvset__PPU3__DOT__SP_PRIPN__v14 = 0U;
    __Vdlyvset__PPU3__DOT__SP_PRIPN__v15 = 0U;
    __Vdlyvset__PPU3__DOT__SP_PRIPN__v16 = 0U;
    __Vdlyvset__PPU3__DOT__SP_PRIPN__v17 = 0U;
    __Vdlyvset__PPU3__DOT__SP_PRIPN__v18 = 0U;
    __Vdlyvset__PPU3__DOT__SP_PRIPN__v19 = 0U;
    vlTOPp->PPU3__DOT__IRQ_STAT = ((~ (IData)(vlTOPp->rst)) 
                                   & (IData)(vlTOPp->PPU3__DOT__IRQ_STAT_NEXT));
    vlTOPp->PPU3__DOT__FF46 = ((IData)(vlTOPp->rst)
                                ? 0U : (IData)(vlTOPp->PPU3__DOT__FF46_NEXT));
    vlTOPp->PPU3__DOT__FF49 = ((IData)(vlTOPp->rst)
                                ? 0U : (IData)(vlTOPp->PPU3__DOT__FF49_NEXT));
    vlTOPp->PPU3__DOT__FF48 = ((IData)(vlTOPp->rst)
                                ? 0U : (IData)(vlTOPp->PPU3__DOT__FF48_NEXT));
    vlTOPp->PPU3__DOT__FF47 = ((IData)(vlTOPp->rst)
                                ? 0U : (IData)(vlTOPp->PPU3__DOT__FF47_NEXT));
    vlTOPp->PPU3__DOT__FF41 = ((IData)(vlTOPp->rst)
                                ? 0U : (IData)(vlTOPp->PPU3__DOT__FF41_NEXT));
    vlTOPp->PPU3__DOT__FF45 = ((IData)(vlTOPp->rst)
                                ? 0U : (IData)(vlTOPp->PPU3__DOT__FF45_NEXT));
    vlTOPp->PPU3__DOT__FF4B = ((IData)(vlTOPp->rst)
                                ? 0U : (IData)(vlTOPp->PPU3__DOT__FF4B_NEXT));
    vlTOPp->PPU3__DOT__FF4A = ((IData)(vlTOPp->rst)
                                ? 0U : (IData)(vlTOPp->PPU3__DOT__FF4A_NEXT));
    vlTOPp->PPU3__DOT__FF42 = ((IData)(vlTOPp->rst)
                                ? 0U : (IData)(vlTOPp->PPU3__DOT__FF42_NEXT));
    vlTOPp->PPU3__DOT__FF43 = ((IData)(vlTOPp->rst)
                                ? 0U : (IData)(vlTOPp->PPU3__DOT__FF43_NEXT));
    vlTOPp->PPU3__DOT__SCX_CNT = ((IData)(vlTOPp->rst)
                                   ? 0U : (IData)(vlTOPp->PPU3__DOT__SCX_CNT_NEXT));
    vlTOPp->PPU3__DOT__isFetchWD = ((~ (IData)(vlTOPp->rst)) 
                                    & (IData)(vlTOPp->PPU3__DOT__isFetchWD_NEXT));
    vlTOPp->PPU3__DOT__FIRST_FETCH_WD_DONE = ((~ (IData)(vlTOPp->rst)) 
                                              & (IData)(vlTOPp->PPU3__DOT__FIRST_FETCH_WD_DONE_NEXT));
    vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_A_VALID = ((~ (IData)(vlTOPp->rst)) 
                                                 & (IData)(vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_A_VALID_NEXT));
    vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_B_VALID = ((~ (IData)(vlTOPp->rst)) 
                                                 & (IData)(vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_B_VALID_NEXT));
    vlTOPp->PPU3__DOT__RENDER_CNT = ((IData)(vlTOPp->rst)
                                      ? 0U : (IData)(vlTOPp->PPU3__DOT__RENDER_CNT_NEXT));
    vlTOPp->PPU3__DOT__SP_NEXT_SLOT = ((IData)(vlTOPp->rst)
                                        ? 0U : (IData)(vlTOPp->PPU3__DOT__SP_NEXT_SLOT_NEXT));
    if ((1U & ((IData)(vlTOPp->rst) | (~ (IData)(vlTOPp->PPU3__DOT__BGWD_RENDER_GO))))) {
        __Vdly__PPU3__DOT__BGWD_CNT = 0U;
        vlTOPp->PPU3__DOT__BGWD_TILE_DATA0 = 0U;
        vlTOPp->PPU3__DOT__BGWD_TILE_DATA1 = 0U;
        vlTOPp->PPU3__DOT__BGWD_MAP = 0U;
    } else {
        __Vdly__PPU3__DOT__BGWD_CNT = ((5U == (IData)(vlTOPp->PPU3__DOT__BGWD_CNT))
                                        ? 0U : (7U 
                                                & ((IData)(1U) 
                                                   + (IData)(vlTOPp->PPU3__DOT__BGWD_CNT))));
        if ((0U == (IData)(vlTOPp->PPU3__DOT__BGWD_CNT))) {
            vlTOPp->PPU3__DOT__BGWD_MAP = vlTOPp->PPU_DATA_in;
        } else {
            if ((1U == (IData)(vlTOPp->PPU3__DOT__BGWD_CNT))) {
                vlTOPp->PPU3__DOT__BGWD_TILE_DATA0 
                    = vlTOPp->PPU_DATA_in;
            } else {
                if ((2U == (IData)(vlTOPp->PPU3__DOT__BGWD_CNT))) {
                    vlTOPp->PPU3__DOT__BGWD_TILE_DATA1 
                        = vlTOPp->PPU_DATA_in;
                }
            }
        }
    }
    vlTOPp->PPU3__DOT__LX = ((IData)(vlTOPp->rst) ? 0U
                              : (IData)(vlTOPp->PPU3__DOT__LX_NEXT));
    vlTOPp->PPU3__DOT__sp_not_used = ((IData)(vlTOPp->rst)
                                       ? 0x3ffU : (IData)(vlTOPp->PPU3__DOT__sp_not_used_next));
    if (((IData)(vlTOPp->rst) | (2U == vlTOPp->PPU3__DOT__PPU_STATE))) {
        __Vdly__PPU3__DOT__SP_CNT = 0U;
        vlTOPp->PPU3__DOT__SP_TILE_DATA0 = 0U;
        vlTOPp->PPU3__DOT__SP_TILE_DATA1 = 0U;
        vlTOPp->PPU3__DOT__SP_MAP = 0U;
        __Vdly__PPU3__DOT__SP_FLAG = 0U;
    } else {
        if (vlTOPp->PPU3__DOT__SP_RENDER_GO) {
            __Vdly__PPU3__DOT__SP_CNT = ((5U == (IData)(vlTOPp->PPU3__DOT__SP_CNT))
                                          ? 0U : (7U 
                                                  & ((IData)(1U) 
                                                     + (IData)(vlTOPp->PPU3__DOT__SP_CNT))));
            if ((0U == (IData)(vlTOPp->PPU3__DOT__SP_CNT))) {
                vlTOPp->PPU3__DOT__SP_MAP = vlTOPp->PPU_DATA_in;
            } else {
                if ((1U == (IData)(vlTOPp->PPU3__DOT__SP_CNT))) {
                    __Vdly__PPU3__DOT__SP_FLAG = vlTOPp->PPU_DATA_in;
                } else {
                    if ((2U == (IData)(vlTOPp->PPU3__DOT__SP_CNT))) {
                        vlTOPp->PPU3__DOT__SP_TILE_DATA0 
                            = ((0x20U & (IData)(vlTOPp->PPU3__DOT__SP_FLAG))
                                ? ((0x80U & ((IData)(vlTOPp->PPU_DATA_in) 
                                             << 7U)) 
                                   | ((0x40U & ((IData)(vlTOPp->PPU_DATA_in) 
                                                << 5U)) 
                                      | ((0x20U & ((IData)(vlTOPp->PPU_DATA_in) 
                                                   << 3U)) 
                                         | ((0x10U 
                                             & ((IData)(vlTOPp->PPU_DATA_in) 
                                                << 1U)) 
                                            | ((8U 
                                                & ((IData)(vlTOPp->PPU_DATA_in) 
                                                   >> 1U)) 
                                               | ((4U 
                                                   & ((IData)(vlTOPp->PPU_DATA_in) 
                                                      >> 3U)) 
                                                  | ((2U 
                                                      & ((IData)(vlTOPp->PPU_DATA_in) 
                                                         >> 5U)) 
                                                     | (1U 
                                                        & ((IData)(vlTOPp->PPU_DATA_in) 
                                                           >> 7U)))))))))
                                : (IData)(vlTOPp->PPU_DATA_in));
                    } else {
                        if ((4U == (IData)(vlTOPp->PPU3__DOT__SP_CNT))) {
                            vlTOPp->PPU3__DOT__SP_TILE_DATA1 
                                = ((0x20U & (IData)(vlTOPp->PPU3__DOT__SP_FLAG))
                                    ? ((0x80U & ((IData)(vlTOPp->PPU_DATA_in) 
                                                 << 7U)) 
                                       | ((0x40U & 
                                           ((IData)(vlTOPp->PPU_DATA_in) 
                                            << 5U)) 
                                          | ((0x20U 
                                              & ((IData)(vlTOPp->PPU_DATA_in) 
                                                 << 3U)) 
                                             | ((0x10U 
                                                 & ((IData)(vlTOPp->PPU_DATA_in) 
                                                    << 1U)) 
                                                | ((8U 
                                                    & ((IData)(vlTOPp->PPU_DATA_in) 
                                                       >> 1U)) 
                                                   | ((4U 
                                                       & ((IData)(vlTOPp->PPU_DATA_in) 
                                                          >> 3U)) 
                                                      | ((2U 
                                                          & ((IData)(vlTOPp->PPU_DATA_in) 
                                                             >> 5U)) 
                                                         | (1U 
                                                            & ((IData)(vlTOPp->PPU_DATA_in) 
                                                               >> 7U)))))))))
                                    : (IData)(vlTOPp->PPU_DATA_in));
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->rst) {
        __Vdlyvset__PPU3__DOT__SP_SHIFT_REG0__DOT__shift_reg__v0 = 1U;
    } else {
        if ((1U & (IData)(vlTOPp->PPU3__DOT__SP_SHIFT_REG_LOAD))) {
            __Vdlyvval__PPU3__DOT__SP_SHIFT_REG0__DOT__shift_reg__v2 
                = vlTOPp->PPU3__DOT____Vcellinp__SP_SHIFT_REG0__data
                [0U];
            __Vdlyvset__PPU3__DOT__SP_SHIFT_REG0__DOT__shift_reg__v2 = 1U;
            __Vdlyvval__PPU3__DOT__SP_SHIFT_REG0__DOT__shift_reg__v3 
                = vlTOPp->PPU3__DOT____Vcellinp__SP_SHIFT_REG0__data
                [1U];
        } else {
            if (vlTOPp->PPU3__DOT__SHIFT_REG_GO) {
                __Vdlyvval__PPU3__DOT__SP_SHIFT_REG0__DOT__shift_reg__v4 
                    = (0x7fU & vlTOPp->PPU3__DOT__SP_SHIFT_REG0__DOT__shift_reg
                       [0U]);
                __Vdlyvset__PPU3__DOT__SP_SHIFT_REG0__DOT__shift_reg__v4 = 1U;
                __Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG0__DOT__shift_reg__v4 = 1U;
                __Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG0__DOT__shift_reg__v5 = 0U;
                __Vdlyvval__PPU3__DOT__SP_SHIFT_REG0__DOT__shift_reg__v6 
                    = (0x7fU & vlTOPp->PPU3__DOT__SP_SHIFT_REG0__DOT__shift_reg
                       [1U]);
                __Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG0__DOT__shift_reg__v6 = 1U;
                __Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG0__DOT__shift_reg__v7 = 0U;
            }
        }
    }
    if (vlTOPp->rst) {
        __Vdlyvset__PPU3__DOT__SP_SHIFT_REG1__DOT__shift_reg__v0 = 1U;
    } else {
        if ((2U & (IData)(vlTOPp->PPU3__DOT__SP_SHIFT_REG_LOAD))) {
            __Vdlyvval__PPU3__DOT__SP_SHIFT_REG1__DOT__shift_reg__v2 
                = vlTOPp->PPU3__DOT____Vcellinp__SP_SHIFT_REG1__data
                [0U];
            __Vdlyvset__PPU3__DOT__SP_SHIFT_REG1__DOT__shift_reg__v2 = 1U;
            __Vdlyvval__PPU3__DOT__SP_SHIFT_REG1__DOT__shift_reg__v3 
                = vlTOPp->PPU3__DOT____Vcellinp__SP_SHIFT_REG1__data
                [1U];
        } else {
            if (vlTOPp->PPU3__DOT__SHIFT_REG_GO) {
                __Vdlyvval__PPU3__DOT__SP_SHIFT_REG1__DOT__shift_reg__v4 
                    = (0x7fU & vlTOPp->PPU3__DOT__SP_SHIFT_REG1__DOT__shift_reg
                       [0U]);
                __Vdlyvset__PPU3__DOT__SP_SHIFT_REG1__DOT__shift_reg__v4 = 1U;
                __Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG1__DOT__shift_reg__v4 = 1U;
                __Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG1__DOT__shift_reg__v5 = 0U;
                __Vdlyvval__PPU3__DOT__SP_SHIFT_REG1__DOT__shift_reg__v6 
                    = (0x7fU & vlTOPp->PPU3__DOT__SP_SHIFT_REG1__DOT__shift_reg
                       [1U]);
                __Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG1__DOT__shift_reg__v6 = 1U;
                __Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG1__DOT__shift_reg__v7 = 0U;
            }
        }
    }
    if (vlTOPp->rst) {
        __Vdlyvset__PPU3__DOT__SP_SHIFT_REG2__DOT__shift_reg__v0 = 1U;
    } else {
        if ((4U & (IData)(vlTOPp->PPU3__DOT__SP_SHIFT_REG_LOAD))) {
            __Vdlyvval__PPU3__DOT__SP_SHIFT_REG2__DOT__shift_reg__v2 
                = vlTOPp->PPU3__DOT____Vcellinp__SP_SHIFT_REG2__data
                [0U];
            __Vdlyvset__PPU3__DOT__SP_SHIFT_REG2__DOT__shift_reg__v2 = 1U;
            __Vdlyvval__PPU3__DOT__SP_SHIFT_REG2__DOT__shift_reg__v3 
                = vlTOPp->PPU3__DOT____Vcellinp__SP_SHIFT_REG2__data
                [1U];
        } else {
            if (vlTOPp->PPU3__DOT__SHIFT_REG_GO) {
                __Vdlyvval__PPU3__DOT__SP_SHIFT_REG2__DOT__shift_reg__v4 
                    = (0x7fU & vlTOPp->PPU3__DOT__SP_SHIFT_REG2__DOT__shift_reg
                       [0U]);
                __Vdlyvset__PPU3__DOT__SP_SHIFT_REG2__DOT__shift_reg__v4 = 1U;
                __Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG2__DOT__shift_reg__v4 = 1U;
                __Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG2__DOT__shift_reg__v5 = 0U;
                __Vdlyvval__PPU3__DOT__SP_SHIFT_REG2__DOT__shift_reg__v6 
                    = (0x7fU & vlTOPp->PPU3__DOT__SP_SHIFT_REG2__DOT__shift_reg
                       [1U]);
                __Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG2__DOT__shift_reg__v6 = 1U;
                __Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG2__DOT__shift_reg__v7 = 0U;
            }
        }
    }
    if (vlTOPp->rst) {
        __Vdlyvset__PPU3__DOT__SP_SHIFT_REG3__DOT__shift_reg__v0 = 1U;
    } else {
        if ((8U & (IData)(vlTOPp->PPU3__DOT__SP_SHIFT_REG_LOAD))) {
            __Vdlyvval__PPU3__DOT__SP_SHIFT_REG3__DOT__shift_reg__v2 
                = vlTOPp->PPU3__DOT____Vcellinp__SP_SHIFT_REG3__data
                [0U];
            __Vdlyvset__PPU3__DOT__SP_SHIFT_REG3__DOT__shift_reg__v2 = 1U;
            __Vdlyvval__PPU3__DOT__SP_SHIFT_REG3__DOT__shift_reg__v3 
                = vlTOPp->PPU3__DOT____Vcellinp__SP_SHIFT_REG3__data
                [1U];
        } else {
            if (vlTOPp->PPU3__DOT__SHIFT_REG_GO) {
                __Vdlyvval__PPU3__DOT__SP_SHIFT_REG3__DOT__shift_reg__v4 
                    = (0x7fU & vlTOPp->PPU3__DOT__SP_SHIFT_REG3__DOT__shift_reg
                       [0U]);
                __Vdlyvset__PPU3__DOT__SP_SHIFT_REG3__DOT__shift_reg__v4 = 1U;
                __Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG3__DOT__shift_reg__v4 = 1U;
                __Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG3__DOT__shift_reg__v5 = 0U;
                __Vdlyvval__PPU3__DOT__SP_SHIFT_REG3__DOT__shift_reg__v6 
                    = (0x7fU & vlTOPp->PPU3__DOT__SP_SHIFT_REG3__DOT__shift_reg
                       [1U]);
                __Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG3__DOT__shift_reg__v6 = 1U;
                __Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG3__DOT__shift_reg__v7 = 0U;
            }
        }
    }
    if (vlTOPp->rst) {
        __Vdlyvset__PPU3__DOT__SP_SHIFT_REG4__DOT__shift_reg__v0 = 1U;
    } else {
        if ((0x10U & (IData)(vlTOPp->PPU3__DOT__SP_SHIFT_REG_LOAD))) {
            __Vdlyvval__PPU3__DOT__SP_SHIFT_REG4__DOT__shift_reg__v2 
                = vlTOPp->PPU3__DOT____Vcellinp__SP_SHIFT_REG4__data
                [0U];
            __Vdlyvset__PPU3__DOT__SP_SHIFT_REG4__DOT__shift_reg__v2 = 1U;
            __Vdlyvval__PPU3__DOT__SP_SHIFT_REG4__DOT__shift_reg__v3 
                = vlTOPp->PPU3__DOT____Vcellinp__SP_SHIFT_REG4__data
                [1U];
        } else {
            if (vlTOPp->PPU3__DOT__SHIFT_REG_GO) {
                __Vdlyvval__PPU3__DOT__SP_SHIFT_REG4__DOT__shift_reg__v4 
                    = (0x7fU & vlTOPp->PPU3__DOT__SP_SHIFT_REG4__DOT__shift_reg
                       [0U]);
                __Vdlyvset__PPU3__DOT__SP_SHIFT_REG4__DOT__shift_reg__v4 = 1U;
                __Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG4__DOT__shift_reg__v4 = 1U;
                __Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG4__DOT__shift_reg__v5 = 0U;
                __Vdlyvval__PPU3__DOT__SP_SHIFT_REG4__DOT__shift_reg__v6 
                    = (0x7fU & vlTOPp->PPU3__DOT__SP_SHIFT_REG4__DOT__shift_reg
                       [1U]);
                __Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG4__DOT__shift_reg__v6 = 1U;
                __Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG4__DOT__shift_reg__v7 = 0U;
            }
        }
    }
    if (vlTOPp->rst) {
        __Vdlyvset__PPU3__DOT__SP_SHIFT_REG5__DOT__shift_reg__v0 = 1U;
    } else {
        if ((0x20U & (IData)(vlTOPp->PPU3__DOT__SP_SHIFT_REG_LOAD))) {
            __Vdlyvval__PPU3__DOT__SP_SHIFT_REG5__DOT__shift_reg__v2 
                = vlTOPp->PPU3__DOT____Vcellinp__SP_SHIFT_REG5__data
                [0U];
            __Vdlyvset__PPU3__DOT__SP_SHIFT_REG5__DOT__shift_reg__v2 = 1U;
            __Vdlyvval__PPU3__DOT__SP_SHIFT_REG5__DOT__shift_reg__v3 
                = vlTOPp->PPU3__DOT____Vcellinp__SP_SHIFT_REG5__data
                [1U];
        } else {
            if (vlTOPp->PPU3__DOT__SHIFT_REG_GO) {
                __Vdlyvval__PPU3__DOT__SP_SHIFT_REG5__DOT__shift_reg__v4 
                    = (0x7fU & vlTOPp->PPU3__DOT__SP_SHIFT_REG5__DOT__shift_reg
                       [0U]);
                __Vdlyvset__PPU3__DOT__SP_SHIFT_REG5__DOT__shift_reg__v4 = 1U;
                __Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG5__DOT__shift_reg__v4 = 1U;
                __Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG5__DOT__shift_reg__v5 = 0U;
                __Vdlyvval__PPU3__DOT__SP_SHIFT_REG5__DOT__shift_reg__v6 
                    = (0x7fU & vlTOPp->PPU3__DOT__SP_SHIFT_REG5__DOT__shift_reg
                       [1U]);
                __Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG5__DOT__shift_reg__v6 = 1U;
                __Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG5__DOT__shift_reg__v7 = 0U;
            }
        }
    }
    if (vlTOPp->rst) {
        __Vdlyvset__PPU3__DOT__SP_SHIFT_REG6__DOT__shift_reg__v0 = 1U;
    } else {
        if ((0x40U & (IData)(vlTOPp->PPU3__DOT__SP_SHIFT_REG_LOAD))) {
            __Vdlyvval__PPU3__DOT__SP_SHIFT_REG6__DOT__shift_reg__v2 
                = vlTOPp->PPU3__DOT____Vcellinp__SP_SHIFT_REG6__data
                [0U];
            __Vdlyvset__PPU3__DOT__SP_SHIFT_REG6__DOT__shift_reg__v2 = 1U;
            __Vdlyvval__PPU3__DOT__SP_SHIFT_REG6__DOT__shift_reg__v3 
                = vlTOPp->PPU3__DOT____Vcellinp__SP_SHIFT_REG6__data
                [1U];
        } else {
            if (vlTOPp->PPU3__DOT__SHIFT_REG_GO) {
                __Vdlyvval__PPU3__DOT__SP_SHIFT_REG6__DOT__shift_reg__v4 
                    = (0x7fU & vlTOPp->PPU3__DOT__SP_SHIFT_REG6__DOT__shift_reg
                       [0U]);
                __Vdlyvset__PPU3__DOT__SP_SHIFT_REG6__DOT__shift_reg__v4 = 1U;
                __Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG6__DOT__shift_reg__v4 = 1U;
                __Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG6__DOT__shift_reg__v5 = 0U;
                __Vdlyvval__PPU3__DOT__SP_SHIFT_REG6__DOT__shift_reg__v6 
                    = (0x7fU & vlTOPp->PPU3__DOT__SP_SHIFT_REG6__DOT__shift_reg
                       [1U]);
                __Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG6__DOT__shift_reg__v6 = 1U;
                __Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG6__DOT__shift_reg__v7 = 0U;
            }
        }
    }
    if (vlTOPp->rst) {
        __Vdlyvset__PPU3__DOT__SP_SHIFT_REG7__DOT__shift_reg__v0 = 1U;
    } else {
        if ((0x80U & (IData)(vlTOPp->PPU3__DOT__SP_SHIFT_REG_LOAD))) {
            __Vdlyvval__PPU3__DOT__SP_SHIFT_REG7__DOT__shift_reg__v2 
                = vlTOPp->PPU3__DOT____Vcellinp__SP_SHIFT_REG7__data
                [0U];
            __Vdlyvset__PPU3__DOT__SP_SHIFT_REG7__DOT__shift_reg__v2 = 1U;
            __Vdlyvval__PPU3__DOT__SP_SHIFT_REG7__DOT__shift_reg__v3 
                = vlTOPp->PPU3__DOT____Vcellinp__SP_SHIFT_REG7__data
                [1U];
        } else {
            if (vlTOPp->PPU3__DOT__SHIFT_REG_GO) {
                __Vdlyvval__PPU3__DOT__SP_SHIFT_REG7__DOT__shift_reg__v4 
                    = (0x7fU & vlTOPp->PPU3__DOT__SP_SHIFT_REG7__DOT__shift_reg
                       [0U]);
                __Vdlyvset__PPU3__DOT__SP_SHIFT_REG7__DOT__shift_reg__v4 = 1U;
                __Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG7__DOT__shift_reg__v4 = 1U;
                __Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG7__DOT__shift_reg__v5 = 0U;
                __Vdlyvval__PPU3__DOT__SP_SHIFT_REG7__DOT__shift_reg__v6 
                    = (0x7fU & vlTOPp->PPU3__DOT__SP_SHIFT_REG7__DOT__shift_reg
                       [1U]);
                __Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG7__DOT__shift_reg__v6 = 1U;
                __Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG7__DOT__shift_reg__v7 = 0U;
            }
        }
    }
    if (vlTOPp->rst) {
        __Vdlyvset__PPU3__DOT__SP_SHIFT_REG8__DOT__shift_reg__v0 = 1U;
    } else {
        if ((0x100U & (IData)(vlTOPp->PPU3__DOT__SP_SHIFT_REG_LOAD))) {
            __Vdlyvval__PPU3__DOT__SP_SHIFT_REG8__DOT__shift_reg__v2 
                = vlTOPp->PPU3__DOT____Vcellinp__SP_SHIFT_REG8__data
                [0U];
            __Vdlyvset__PPU3__DOT__SP_SHIFT_REG8__DOT__shift_reg__v2 = 1U;
            __Vdlyvval__PPU3__DOT__SP_SHIFT_REG8__DOT__shift_reg__v3 
                = vlTOPp->PPU3__DOT____Vcellinp__SP_SHIFT_REG8__data
                [1U];
        } else {
            if (vlTOPp->PPU3__DOT__SHIFT_REG_GO) {
                __Vdlyvval__PPU3__DOT__SP_SHIFT_REG8__DOT__shift_reg__v4 
                    = (0x7fU & vlTOPp->PPU3__DOT__SP_SHIFT_REG8__DOT__shift_reg
                       [0U]);
                __Vdlyvset__PPU3__DOT__SP_SHIFT_REG8__DOT__shift_reg__v4 = 1U;
                __Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG8__DOT__shift_reg__v4 = 1U;
                __Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG8__DOT__shift_reg__v5 = 0U;
                __Vdlyvval__PPU3__DOT__SP_SHIFT_REG8__DOT__shift_reg__v6 
                    = (0x7fU & vlTOPp->PPU3__DOT__SP_SHIFT_REG8__DOT__shift_reg
                       [1U]);
                __Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG8__DOT__shift_reg__v6 = 1U;
                __Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG8__DOT__shift_reg__v7 = 0U;
            }
        }
    }
    if (vlTOPp->rst) {
        __Vdlyvset__PPU3__DOT__SP_SHIFT_REG9__DOT__shift_reg__v0 = 1U;
    } else {
        if ((0x200U & (IData)(vlTOPp->PPU3__DOT__SP_SHIFT_REG_LOAD))) {
            __Vdlyvval__PPU3__DOT__SP_SHIFT_REG9__DOT__shift_reg__v2 
                = vlTOPp->PPU3__DOT____Vcellinp__SP_SHIFT_REG9__data
                [0U];
            __Vdlyvset__PPU3__DOT__SP_SHIFT_REG9__DOT__shift_reg__v2 = 1U;
            __Vdlyvval__PPU3__DOT__SP_SHIFT_REG9__DOT__shift_reg__v3 
                = vlTOPp->PPU3__DOT____Vcellinp__SP_SHIFT_REG9__data
                [1U];
        } else {
            if (vlTOPp->PPU3__DOT__SHIFT_REG_GO) {
                __Vdlyvval__PPU3__DOT__SP_SHIFT_REG9__DOT__shift_reg__v4 
                    = (0x7fU & vlTOPp->PPU3__DOT__SP_SHIFT_REG9__DOT__shift_reg
                       [0U]);
                __Vdlyvset__PPU3__DOT__SP_SHIFT_REG9__DOT__shift_reg__v4 = 1U;
                __Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG9__DOT__shift_reg__v4 = 1U;
                __Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG9__DOT__shift_reg__v5 = 0U;
                __Vdlyvval__PPU3__DOT__SP_SHIFT_REG9__DOT__shift_reg__v6 
                    = (0x7fU & vlTOPp->PPU3__DOT__SP_SHIFT_REG9__DOT__shift_reg
                       [1U]);
                __Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG9__DOT__shift_reg__v6 = 1U;
                __Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG9__DOT__shift_reg__v7 = 0U;
            }
        }
    }
    if (vlTOPp->rst) {
        __Vdlyvset__PPU3__DOT__BGWD_SHIFT_REG_B__DOT__shift_reg__v0 = 1U;
    } else {
        if ((2U & (IData)(vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_LOAD))) {
            __Vdlyvval__PPU3__DOT__BGWD_SHIFT_REG_B__DOT__shift_reg__v2 
                = vlTOPp->PPU3__DOT____Vcellinp__BGWD_SHIFT_REG_B__data
                [0U];
            __Vdlyvset__PPU3__DOT__BGWD_SHIFT_REG_B__DOT__shift_reg__v2 = 1U;
            __Vdlyvval__PPU3__DOT__BGWD_SHIFT_REG_B__DOT__shift_reg__v3 
                = vlTOPp->PPU3__DOT____Vcellinp__BGWD_SHIFT_REG_B__data
                [1U];
        } else {
            if (((IData)(vlTOPp->PPU3__DOT__SHIFT_REG_GO) 
                 & (IData)(vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_SEL))) {
                __Vdlyvval__PPU3__DOT__BGWD_SHIFT_REG_B__DOT__shift_reg__v4 
                    = (0x7fU & vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_B__DOT__shift_reg
                       [0U]);
                __Vdlyvset__PPU3__DOT__BGWD_SHIFT_REG_B__DOT__shift_reg__v4 = 1U;
                __Vdlyvlsb__PPU3__DOT__BGWD_SHIFT_REG_B__DOT__shift_reg__v4 = 1U;
                __Vdlyvlsb__PPU3__DOT__BGWD_SHIFT_REG_B__DOT__shift_reg__v5 = 0U;
                __Vdlyvval__PPU3__DOT__BGWD_SHIFT_REG_B__DOT__shift_reg__v6 
                    = (0x7fU & vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_B__DOT__shift_reg
                       [1U]);
                __Vdlyvlsb__PPU3__DOT__BGWD_SHIFT_REG_B__DOT__shift_reg__v6 = 1U;
                __Vdlyvlsb__PPU3__DOT__BGWD_SHIFT_REG_B__DOT__shift_reg__v7 = 0U;
            }
        }
    }
    if (vlTOPp->rst) {
        __Vdlyvset__PPU3__DOT__BGWD_SHIFT_REG_A__DOT__shift_reg__v0 = 1U;
    } else {
        if ((1U & (IData)(vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_LOAD))) {
            __Vdlyvval__PPU3__DOT__BGWD_SHIFT_REG_A__DOT__shift_reg__v2 
                = vlTOPp->PPU3__DOT____Vcellinp__BGWD_SHIFT_REG_A__data
                [0U];
            __Vdlyvset__PPU3__DOT__BGWD_SHIFT_REG_A__DOT__shift_reg__v2 = 1U;
            __Vdlyvval__PPU3__DOT__BGWD_SHIFT_REG_A__DOT__shift_reg__v3 
                = vlTOPp->PPU3__DOT____Vcellinp__BGWD_SHIFT_REG_A__data
                [1U];
        } else {
            if (((IData)(vlTOPp->PPU3__DOT__SHIFT_REG_GO) 
                 & (~ (IData)(vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_SEL)))) {
                __Vdlyvval__PPU3__DOT__BGWD_SHIFT_REG_A__DOT__shift_reg__v4 
                    = (0x7fU & vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_A__DOT__shift_reg
                       [0U]);
                __Vdlyvset__PPU3__DOT__BGWD_SHIFT_REG_A__DOT__shift_reg__v4 = 1U;
                __Vdlyvlsb__PPU3__DOT__BGWD_SHIFT_REG_A__DOT__shift_reg__v4 = 1U;
                __Vdlyvlsb__PPU3__DOT__BGWD_SHIFT_REG_A__DOT__shift_reg__v5 = 0U;
                __Vdlyvval__PPU3__DOT__BGWD_SHIFT_REG_A__DOT__shift_reg__v6 
                    = (0x7fU & vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_A__DOT__shift_reg
                       [1U]);
                __Vdlyvlsb__PPU3__DOT__BGWD_SHIFT_REG_A__DOT__shift_reg__v6 = 1U;
                __Vdlyvlsb__PPU3__DOT__BGWD_SHIFT_REG_A__DOT__shift_reg__v7 = 0U;
            }
        }
    }
    if (((IData)(vlTOPp->rst) | (2U == vlTOPp->PPU3__DOT__PPU_STATE))) {
        __Vdly__PPU3__DOT__sp_table_cnt = 0U;
        __Vdly__PPU3__DOT__sp_found = 0U;
        __Vdlyvset__PPU3__DOT__sp_y_table__v0 = 1U;
    } else {
        if (vlTOPp->PPU3__DOT__OAM_SEARCH_GO) {
            if ((1U & (IData)(vlTOPp->PPU3__DOT__PPU_CNT))) {
                if (vlTOPp->PPU3__DOT__sp_found) {
                    vlTOPp->PPU3__DOT____Vlvbound9 
                        = vlTOPp->PPU_DATA_in;
                    if ((9U >= (0xfU & ((IData)(vlTOPp->PPU3__DOT__sp_table_cnt) 
                                        - (IData)(1U))))) {
                        __Vdlyvval__PPU3__DOT__sp_x_table__v10 
                            = vlTOPp->PPU3__DOT____Vlvbound9;
                        __Vdlyvset__PPU3__DOT__sp_x_table__v10 = 1U;
                        __Vdlyvdim0__PPU3__DOT__sp_x_table__v10 
                            = (0xfU & ((IData)(vlTOPp->PPU3__DOT__sp_table_cnt) 
                                       - (IData)(1U)));
                    }
                }
                __Vdly__PPU3__DOT__sp_found = 0U;
            } else {
                if ((((((IData)(vlTOPp->PPU_DATA_in) 
                        + (8U & ((IData)(vlTOPp->PPU3__DOT__FF40) 
                                 << 1U))) > ((IData)(8U) 
                                             + (IData)(vlTOPp->PPU3__DOT__LY))) 
                      & ((IData)(vlTOPp->PPU_DATA_in) 
                         <= ((IData)(0x10U) + (IData)(vlTOPp->PPU3__DOT__LY)))) 
                     & (0xaU > (IData)(vlTOPp->PPU3__DOT__sp_table_cnt)))) {
                    __Vdly__PPU3__DOT__sp_table_cnt 
                        = (0xfU & ((IData)(1U) + (IData)(vlTOPp->PPU3__DOT__sp_table_cnt)));
                    vlTOPp->PPU3__DOT____Vlvbound10 
                        = (0x3fU & ((IData)(vlTOPp->PPU3__DOT__PPU_CNT) 
                                    >> 1U));
                    if ((9U >= (IData)(vlTOPp->PPU3__DOT__sp_table_cnt))) {
                        __Vdlyvval__PPU3__DOT__sp_name_table__v0 
                            = vlTOPp->PPU3__DOT____Vlvbound10;
                        __Vdlyvset__PPU3__DOT__sp_name_table__v0 = 1U;
                        __Vdlyvdim0__PPU3__DOT__sp_name_table__v0 
                            = vlTOPp->PPU3__DOT__sp_table_cnt;
                    }
                    __Vdly__PPU3__DOT__sp_found = 1U;
                    vlTOPp->PPU3__DOT____Vlvbound11 
                        = vlTOPp->PPU_DATA_in;
                    if ((9U >= (IData)(vlTOPp->PPU3__DOT__sp_table_cnt))) {
                        __Vdlyvval__PPU3__DOT__sp_y_table__v10 
                            = vlTOPp->PPU3__DOT____Vlvbound11;
                        __Vdlyvset__PPU3__DOT__sp_y_table__v10 = 1U;
                        __Vdlyvdim0__PPU3__DOT__sp_y_table__v10 
                            = vlTOPp->PPU3__DOT__sp_table_cnt;
                    }
                }
            }
        }
    }
    if (vlTOPp->rst) {
        __Vdlyvset__PPU3__DOT__SP_PRIPN__v0 = 1U;
    } else {
        vlTOPp->PPU3__DOT____Vlvbound2 = vlTOPp->PPU3__DOT__SP_PRIPN_NEXT
            [0U];
        __Vdlyvval__PPU3__DOT__SP_PRIPN__v10 = vlTOPp->PPU3__DOT____Vlvbound2;
        __Vdlyvset__PPU3__DOT__SP_PRIPN__v10 = 1U;
        vlTOPp->PPU3__DOT____Vlvbound2 = vlTOPp->PPU3__DOT__SP_PRIPN_NEXT
            [1U];
        __Vdlyvval__PPU3__DOT__SP_PRIPN__v11 = vlTOPp->PPU3__DOT____Vlvbound2;
        __Vdlyvset__PPU3__DOT__SP_PRIPN__v11 = 1U;
        vlTOPp->PPU3__DOT____Vlvbound2 = vlTOPp->PPU3__DOT__SP_PRIPN_NEXT
            [2U];
        __Vdlyvval__PPU3__DOT__SP_PRIPN__v12 = vlTOPp->PPU3__DOT____Vlvbound2;
        __Vdlyvset__PPU3__DOT__SP_PRIPN__v12 = 1U;
        vlTOPp->PPU3__DOT____Vlvbound2 = vlTOPp->PPU3__DOT__SP_PRIPN_NEXT
            [3U];
        __Vdlyvval__PPU3__DOT__SP_PRIPN__v13 = vlTOPp->PPU3__DOT____Vlvbound2;
        __Vdlyvset__PPU3__DOT__SP_PRIPN__v13 = 1U;
        vlTOPp->PPU3__DOT____Vlvbound2 = vlTOPp->PPU3__DOT__SP_PRIPN_NEXT
            [4U];
        __Vdlyvval__PPU3__DOT__SP_PRIPN__v14 = vlTOPp->PPU3__DOT____Vlvbound2;
        __Vdlyvset__PPU3__DOT__SP_PRIPN__v14 = 1U;
        vlTOPp->PPU3__DOT____Vlvbound2 = vlTOPp->PPU3__DOT__SP_PRIPN_NEXT
            [5U];
        __Vdlyvval__PPU3__DOT__SP_PRIPN__v15 = vlTOPp->PPU3__DOT____Vlvbound2;
        __Vdlyvset__PPU3__DOT__SP_PRIPN__v15 = 1U;
        vlTOPp->PPU3__DOT____Vlvbound2 = vlTOPp->PPU3__DOT__SP_PRIPN_NEXT
            [6U];
        __Vdlyvval__PPU3__DOT__SP_PRIPN__v16 = vlTOPp->PPU3__DOT____Vlvbound2;
        __Vdlyvset__PPU3__DOT__SP_PRIPN__v16 = 1U;
        vlTOPp->PPU3__DOT____Vlvbound2 = vlTOPp->PPU3__DOT__SP_PRIPN_NEXT
            [7U];
        __Vdlyvval__PPU3__DOT__SP_PRIPN__v17 = vlTOPp->PPU3__DOT____Vlvbound2;
        __Vdlyvset__PPU3__DOT__SP_PRIPN__v17 = 1U;
        vlTOPp->PPU3__DOT____Vlvbound2 = vlTOPp->PPU3__DOT__SP_PRIPN_NEXT
            [8U];
        __Vdlyvval__PPU3__DOT__SP_PRIPN__v18 = vlTOPp->PPU3__DOT____Vlvbound2;
        __Vdlyvset__PPU3__DOT__SP_PRIPN__v18 = 1U;
        vlTOPp->PPU3__DOT____Vlvbound2 = vlTOPp->PPU3__DOT__SP_PRIPN_NEXT
            [9U];
        __Vdlyvval__PPU3__DOT__SP_PRIPN__v19 = vlTOPp->PPU3__DOT____Vlvbound2;
        __Vdlyvset__PPU3__DOT__SP_PRIPN__v19 = 1U;
    }
    vlTOPp->PPU3__DOT__BGWD_CNT = __Vdly__PPU3__DOT__BGWD_CNT;
    vlTOPp->PPU3__DOT__SP_CNT = __Vdly__PPU3__DOT__SP_CNT;
    vlTOPp->PPU3__DOT__SP_FLAG = __Vdly__PPU3__DOT__SP_FLAG;
    if (__Vdlyvset__PPU3__DOT__SP_SHIFT_REG0__DOT__shift_reg__v0) {
        vlTOPp->PPU3__DOT__SP_SHIFT_REG0__DOT__shift_reg[0U] = 0U;
        vlTOPp->PPU3__DOT__SP_SHIFT_REG0__DOT__shift_reg[1U] = 0U;
    }
    if (__Vdlyvset__PPU3__DOT__SP_SHIFT_REG0__DOT__shift_reg__v2) {
        vlTOPp->PPU3__DOT__SP_SHIFT_REG0__DOT__shift_reg[0U] 
            = __Vdlyvval__PPU3__DOT__SP_SHIFT_REG0__DOT__shift_reg__v2;
        vlTOPp->PPU3__DOT__SP_SHIFT_REG0__DOT__shift_reg[1U] 
            = __Vdlyvval__PPU3__DOT__SP_SHIFT_REG0__DOT__shift_reg__v3;
    }
    if (__Vdlyvset__PPU3__DOT__SP_SHIFT_REG0__DOT__shift_reg__v4) {
        vlTOPp->PPU3__DOT__SP_SHIFT_REG0__DOT__shift_reg[0U] 
            = (((~ ((IData)(0x7fU) << (IData)(__Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG0__DOT__shift_reg__v4))) 
                & vlTOPp->PPU3__DOT__SP_SHIFT_REG0__DOT__shift_reg
                [0U]) | ((IData)(__Vdlyvval__PPU3__DOT__SP_SHIFT_REG0__DOT__shift_reg__v4) 
                         << (IData)(__Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG0__DOT__shift_reg__v4)));
        vlTOPp->PPU3__DOT__SP_SHIFT_REG0__DOT__shift_reg[0U] 
            = ((~ ((IData)(1U) << (IData)(__Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG0__DOT__shift_reg__v5))) 
               & vlTOPp->PPU3__DOT__SP_SHIFT_REG0__DOT__shift_reg
               [0U]);
        vlTOPp->PPU3__DOT__SP_SHIFT_REG0__DOT__shift_reg[1U] 
            = (((~ ((IData)(0x7fU) << (IData)(__Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG0__DOT__shift_reg__v6))) 
                & vlTOPp->PPU3__DOT__SP_SHIFT_REG0__DOT__shift_reg
                [1U]) | ((IData)(__Vdlyvval__PPU3__DOT__SP_SHIFT_REG0__DOT__shift_reg__v6) 
                         << (IData)(__Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG0__DOT__shift_reg__v6)));
        vlTOPp->PPU3__DOT__SP_SHIFT_REG0__DOT__shift_reg[1U] 
            = ((~ ((IData)(1U) << (IData)(__Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG0__DOT__shift_reg__v7))) 
               & vlTOPp->PPU3__DOT__SP_SHIFT_REG0__DOT__shift_reg
               [1U]);
    }
    if (__Vdlyvset__PPU3__DOT__SP_SHIFT_REG1__DOT__shift_reg__v0) {
        vlTOPp->PPU3__DOT__SP_SHIFT_REG1__DOT__shift_reg[0U] = 0U;
        vlTOPp->PPU3__DOT__SP_SHIFT_REG1__DOT__shift_reg[1U] = 0U;
    }
    if (__Vdlyvset__PPU3__DOT__SP_SHIFT_REG1__DOT__shift_reg__v2) {
        vlTOPp->PPU3__DOT__SP_SHIFT_REG1__DOT__shift_reg[0U] 
            = __Vdlyvval__PPU3__DOT__SP_SHIFT_REG1__DOT__shift_reg__v2;
        vlTOPp->PPU3__DOT__SP_SHIFT_REG1__DOT__shift_reg[1U] 
            = __Vdlyvval__PPU3__DOT__SP_SHIFT_REG1__DOT__shift_reg__v3;
    }
    if (__Vdlyvset__PPU3__DOT__SP_SHIFT_REG1__DOT__shift_reg__v4) {
        vlTOPp->PPU3__DOT__SP_SHIFT_REG1__DOT__shift_reg[0U] 
            = (((~ ((IData)(0x7fU) << (IData)(__Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG1__DOT__shift_reg__v4))) 
                & vlTOPp->PPU3__DOT__SP_SHIFT_REG1__DOT__shift_reg
                [0U]) | ((IData)(__Vdlyvval__PPU3__DOT__SP_SHIFT_REG1__DOT__shift_reg__v4) 
                         << (IData)(__Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG1__DOT__shift_reg__v4)));
        vlTOPp->PPU3__DOT__SP_SHIFT_REG1__DOT__shift_reg[0U] 
            = ((~ ((IData)(1U) << (IData)(__Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG1__DOT__shift_reg__v5))) 
               & vlTOPp->PPU3__DOT__SP_SHIFT_REG1__DOT__shift_reg
               [0U]);
        vlTOPp->PPU3__DOT__SP_SHIFT_REG1__DOT__shift_reg[1U] 
            = (((~ ((IData)(0x7fU) << (IData)(__Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG1__DOT__shift_reg__v6))) 
                & vlTOPp->PPU3__DOT__SP_SHIFT_REG1__DOT__shift_reg
                [1U]) | ((IData)(__Vdlyvval__PPU3__DOT__SP_SHIFT_REG1__DOT__shift_reg__v6) 
                         << (IData)(__Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG1__DOT__shift_reg__v6)));
        vlTOPp->PPU3__DOT__SP_SHIFT_REG1__DOT__shift_reg[1U] 
            = ((~ ((IData)(1U) << (IData)(__Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG1__DOT__shift_reg__v7))) 
               & vlTOPp->PPU3__DOT__SP_SHIFT_REG1__DOT__shift_reg
               [1U]);
    }
    if (__Vdlyvset__PPU3__DOT__SP_SHIFT_REG2__DOT__shift_reg__v0) {
        vlTOPp->PPU3__DOT__SP_SHIFT_REG2__DOT__shift_reg[0U] = 0U;
        vlTOPp->PPU3__DOT__SP_SHIFT_REG2__DOT__shift_reg[1U] = 0U;
    }
    if (__Vdlyvset__PPU3__DOT__SP_SHIFT_REG2__DOT__shift_reg__v2) {
        vlTOPp->PPU3__DOT__SP_SHIFT_REG2__DOT__shift_reg[0U] 
            = __Vdlyvval__PPU3__DOT__SP_SHIFT_REG2__DOT__shift_reg__v2;
        vlTOPp->PPU3__DOT__SP_SHIFT_REG2__DOT__shift_reg[1U] 
            = __Vdlyvval__PPU3__DOT__SP_SHIFT_REG2__DOT__shift_reg__v3;
    }
    if (__Vdlyvset__PPU3__DOT__SP_SHIFT_REG2__DOT__shift_reg__v4) {
        vlTOPp->PPU3__DOT__SP_SHIFT_REG2__DOT__shift_reg[0U] 
            = (((~ ((IData)(0x7fU) << (IData)(__Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG2__DOT__shift_reg__v4))) 
                & vlTOPp->PPU3__DOT__SP_SHIFT_REG2__DOT__shift_reg
                [0U]) | ((IData)(__Vdlyvval__PPU3__DOT__SP_SHIFT_REG2__DOT__shift_reg__v4) 
                         << (IData)(__Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG2__DOT__shift_reg__v4)));
        vlTOPp->PPU3__DOT__SP_SHIFT_REG2__DOT__shift_reg[0U] 
            = ((~ ((IData)(1U) << (IData)(__Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG2__DOT__shift_reg__v5))) 
               & vlTOPp->PPU3__DOT__SP_SHIFT_REG2__DOT__shift_reg
               [0U]);
        vlTOPp->PPU3__DOT__SP_SHIFT_REG2__DOT__shift_reg[1U] 
            = (((~ ((IData)(0x7fU) << (IData)(__Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG2__DOT__shift_reg__v6))) 
                & vlTOPp->PPU3__DOT__SP_SHIFT_REG2__DOT__shift_reg
                [1U]) | ((IData)(__Vdlyvval__PPU3__DOT__SP_SHIFT_REG2__DOT__shift_reg__v6) 
                         << (IData)(__Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG2__DOT__shift_reg__v6)));
        vlTOPp->PPU3__DOT__SP_SHIFT_REG2__DOT__shift_reg[1U] 
            = ((~ ((IData)(1U) << (IData)(__Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG2__DOT__shift_reg__v7))) 
               & vlTOPp->PPU3__DOT__SP_SHIFT_REG2__DOT__shift_reg
               [1U]);
    }
    if (__Vdlyvset__PPU3__DOT__SP_SHIFT_REG3__DOT__shift_reg__v0) {
        vlTOPp->PPU3__DOT__SP_SHIFT_REG3__DOT__shift_reg[0U] = 0U;
        vlTOPp->PPU3__DOT__SP_SHIFT_REG3__DOT__shift_reg[1U] = 0U;
    }
    if (__Vdlyvset__PPU3__DOT__SP_SHIFT_REG3__DOT__shift_reg__v2) {
        vlTOPp->PPU3__DOT__SP_SHIFT_REG3__DOT__shift_reg[0U] 
            = __Vdlyvval__PPU3__DOT__SP_SHIFT_REG3__DOT__shift_reg__v2;
        vlTOPp->PPU3__DOT__SP_SHIFT_REG3__DOT__shift_reg[1U] 
            = __Vdlyvval__PPU3__DOT__SP_SHIFT_REG3__DOT__shift_reg__v3;
    }
    if (__Vdlyvset__PPU3__DOT__SP_SHIFT_REG3__DOT__shift_reg__v4) {
        vlTOPp->PPU3__DOT__SP_SHIFT_REG3__DOT__shift_reg[0U] 
            = (((~ ((IData)(0x7fU) << (IData)(__Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG3__DOT__shift_reg__v4))) 
                & vlTOPp->PPU3__DOT__SP_SHIFT_REG3__DOT__shift_reg
                [0U]) | ((IData)(__Vdlyvval__PPU3__DOT__SP_SHIFT_REG3__DOT__shift_reg__v4) 
                         << (IData)(__Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG3__DOT__shift_reg__v4)));
        vlTOPp->PPU3__DOT__SP_SHIFT_REG3__DOT__shift_reg[0U] 
            = ((~ ((IData)(1U) << (IData)(__Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG3__DOT__shift_reg__v5))) 
               & vlTOPp->PPU3__DOT__SP_SHIFT_REG3__DOT__shift_reg
               [0U]);
        vlTOPp->PPU3__DOT__SP_SHIFT_REG3__DOT__shift_reg[1U] 
            = (((~ ((IData)(0x7fU) << (IData)(__Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG3__DOT__shift_reg__v6))) 
                & vlTOPp->PPU3__DOT__SP_SHIFT_REG3__DOT__shift_reg
                [1U]) | ((IData)(__Vdlyvval__PPU3__DOT__SP_SHIFT_REG3__DOT__shift_reg__v6) 
                         << (IData)(__Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG3__DOT__shift_reg__v6)));
        vlTOPp->PPU3__DOT__SP_SHIFT_REG3__DOT__shift_reg[1U] 
            = ((~ ((IData)(1U) << (IData)(__Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG3__DOT__shift_reg__v7))) 
               & vlTOPp->PPU3__DOT__SP_SHIFT_REG3__DOT__shift_reg
               [1U]);
    }
    if (__Vdlyvset__PPU3__DOT__SP_SHIFT_REG4__DOT__shift_reg__v0) {
        vlTOPp->PPU3__DOT__SP_SHIFT_REG4__DOT__shift_reg[0U] = 0U;
        vlTOPp->PPU3__DOT__SP_SHIFT_REG4__DOT__shift_reg[1U] = 0U;
    }
    if (__Vdlyvset__PPU3__DOT__SP_SHIFT_REG4__DOT__shift_reg__v2) {
        vlTOPp->PPU3__DOT__SP_SHIFT_REG4__DOT__shift_reg[0U] 
            = __Vdlyvval__PPU3__DOT__SP_SHIFT_REG4__DOT__shift_reg__v2;
        vlTOPp->PPU3__DOT__SP_SHIFT_REG4__DOT__shift_reg[1U] 
            = __Vdlyvval__PPU3__DOT__SP_SHIFT_REG4__DOT__shift_reg__v3;
    }
    if (__Vdlyvset__PPU3__DOT__SP_SHIFT_REG4__DOT__shift_reg__v4) {
        vlTOPp->PPU3__DOT__SP_SHIFT_REG4__DOT__shift_reg[0U] 
            = (((~ ((IData)(0x7fU) << (IData)(__Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG4__DOT__shift_reg__v4))) 
                & vlTOPp->PPU3__DOT__SP_SHIFT_REG4__DOT__shift_reg
                [0U]) | ((IData)(__Vdlyvval__PPU3__DOT__SP_SHIFT_REG4__DOT__shift_reg__v4) 
                         << (IData)(__Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG4__DOT__shift_reg__v4)));
        vlTOPp->PPU3__DOT__SP_SHIFT_REG4__DOT__shift_reg[0U] 
            = ((~ ((IData)(1U) << (IData)(__Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG4__DOT__shift_reg__v5))) 
               & vlTOPp->PPU3__DOT__SP_SHIFT_REG4__DOT__shift_reg
               [0U]);
        vlTOPp->PPU3__DOT__SP_SHIFT_REG4__DOT__shift_reg[1U] 
            = (((~ ((IData)(0x7fU) << (IData)(__Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG4__DOT__shift_reg__v6))) 
                & vlTOPp->PPU3__DOT__SP_SHIFT_REG4__DOT__shift_reg
                [1U]) | ((IData)(__Vdlyvval__PPU3__DOT__SP_SHIFT_REG4__DOT__shift_reg__v6) 
                         << (IData)(__Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG4__DOT__shift_reg__v6)));
        vlTOPp->PPU3__DOT__SP_SHIFT_REG4__DOT__shift_reg[1U] 
            = ((~ ((IData)(1U) << (IData)(__Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG4__DOT__shift_reg__v7))) 
               & vlTOPp->PPU3__DOT__SP_SHIFT_REG4__DOT__shift_reg
               [1U]);
    }
    if (__Vdlyvset__PPU3__DOT__SP_SHIFT_REG5__DOT__shift_reg__v0) {
        vlTOPp->PPU3__DOT__SP_SHIFT_REG5__DOT__shift_reg[0U] = 0U;
        vlTOPp->PPU3__DOT__SP_SHIFT_REG5__DOT__shift_reg[1U] = 0U;
    }
    if (__Vdlyvset__PPU3__DOT__SP_SHIFT_REG5__DOT__shift_reg__v2) {
        vlTOPp->PPU3__DOT__SP_SHIFT_REG5__DOT__shift_reg[0U] 
            = __Vdlyvval__PPU3__DOT__SP_SHIFT_REG5__DOT__shift_reg__v2;
        vlTOPp->PPU3__DOT__SP_SHIFT_REG5__DOT__shift_reg[1U] 
            = __Vdlyvval__PPU3__DOT__SP_SHIFT_REG5__DOT__shift_reg__v3;
    }
    if (__Vdlyvset__PPU3__DOT__SP_SHIFT_REG5__DOT__shift_reg__v4) {
        vlTOPp->PPU3__DOT__SP_SHIFT_REG5__DOT__shift_reg[0U] 
            = (((~ ((IData)(0x7fU) << (IData)(__Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG5__DOT__shift_reg__v4))) 
                & vlTOPp->PPU3__DOT__SP_SHIFT_REG5__DOT__shift_reg
                [0U]) | ((IData)(__Vdlyvval__PPU3__DOT__SP_SHIFT_REG5__DOT__shift_reg__v4) 
                         << (IData)(__Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG5__DOT__shift_reg__v4)));
        vlTOPp->PPU3__DOT__SP_SHIFT_REG5__DOT__shift_reg[0U] 
            = ((~ ((IData)(1U) << (IData)(__Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG5__DOT__shift_reg__v5))) 
               & vlTOPp->PPU3__DOT__SP_SHIFT_REG5__DOT__shift_reg
               [0U]);
        vlTOPp->PPU3__DOT__SP_SHIFT_REG5__DOT__shift_reg[1U] 
            = (((~ ((IData)(0x7fU) << (IData)(__Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG5__DOT__shift_reg__v6))) 
                & vlTOPp->PPU3__DOT__SP_SHIFT_REG5__DOT__shift_reg
                [1U]) | ((IData)(__Vdlyvval__PPU3__DOT__SP_SHIFT_REG5__DOT__shift_reg__v6) 
                         << (IData)(__Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG5__DOT__shift_reg__v6)));
        vlTOPp->PPU3__DOT__SP_SHIFT_REG5__DOT__shift_reg[1U] 
            = ((~ ((IData)(1U) << (IData)(__Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG5__DOT__shift_reg__v7))) 
               & vlTOPp->PPU3__DOT__SP_SHIFT_REG5__DOT__shift_reg
               [1U]);
    }
    if (__Vdlyvset__PPU3__DOT__SP_SHIFT_REG6__DOT__shift_reg__v0) {
        vlTOPp->PPU3__DOT__SP_SHIFT_REG6__DOT__shift_reg[0U] = 0U;
        vlTOPp->PPU3__DOT__SP_SHIFT_REG6__DOT__shift_reg[1U] = 0U;
    }
    if (__Vdlyvset__PPU3__DOT__SP_SHIFT_REG6__DOT__shift_reg__v2) {
        vlTOPp->PPU3__DOT__SP_SHIFT_REG6__DOT__shift_reg[0U] 
            = __Vdlyvval__PPU3__DOT__SP_SHIFT_REG6__DOT__shift_reg__v2;
        vlTOPp->PPU3__DOT__SP_SHIFT_REG6__DOT__shift_reg[1U] 
            = __Vdlyvval__PPU3__DOT__SP_SHIFT_REG6__DOT__shift_reg__v3;
    }
    if (__Vdlyvset__PPU3__DOT__SP_SHIFT_REG6__DOT__shift_reg__v4) {
        vlTOPp->PPU3__DOT__SP_SHIFT_REG6__DOT__shift_reg[0U] 
            = (((~ ((IData)(0x7fU) << (IData)(__Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG6__DOT__shift_reg__v4))) 
                & vlTOPp->PPU3__DOT__SP_SHIFT_REG6__DOT__shift_reg
                [0U]) | ((IData)(__Vdlyvval__PPU3__DOT__SP_SHIFT_REG6__DOT__shift_reg__v4) 
                         << (IData)(__Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG6__DOT__shift_reg__v4)));
        vlTOPp->PPU3__DOT__SP_SHIFT_REG6__DOT__shift_reg[0U] 
            = ((~ ((IData)(1U) << (IData)(__Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG6__DOT__shift_reg__v5))) 
               & vlTOPp->PPU3__DOT__SP_SHIFT_REG6__DOT__shift_reg
               [0U]);
        vlTOPp->PPU3__DOT__SP_SHIFT_REG6__DOT__shift_reg[1U] 
            = (((~ ((IData)(0x7fU) << (IData)(__Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG6__DOT__shift_reg__v6))) 
                & vlTOPp->PPU3__DOT__SP_SHIFT_REG6__DOT__shift_reg
                [1U]) | ((IData)(__Vdlyvval__PPU3__DOT__SP_SHIFT_REG6__DOT__shift_reg__v6) 
                         << (IData)(__Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG6__DOT__shift_reg__v6)));
        vlTOPp->PPU3__DOT__SP_SHIFT_REG6__DOT__shift_reg[1U] 
            = ((~ ((IData)(1U) << (IData)(__Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG6__DOT__shift_reg__v7))) 
               & vlTOPp->PPU3__DOT__SP_SHIFT_REG6__DOT__shift_reg
               [1U]);
    }
    if (__Vdlyvset__PPU3__DOT__SP_SHIFT_REG7__DOT__shift_reg__v0) {
        vlTOPp->PPU3__DOT__SP_SHIFT_REG7__DOT__shift_reg[0U] = 0U;
        vlTOPp->PPU3__DOT__SP_SHIFT_REG7__DOT__shift_reg[1U] = 0U;
    }
    if (__Vdlyvset__PPU3__DOT__SP_SHIFT_REG7__DOT__shift_reg__v2) {
        vlTOPp->PPU3__DOT__SP_SHIFT_REG7__DOT__shift_reg[0U] 
            = __Vdlyvval__PPU3__DOT__SP_SHIFT_REG7__DOT__shift_reg__v2;
        vlTOPp->PPU3__DOT__SP_SHIFT_REG7__DOT__shift_reg[1U] 
            = __Vdlyvval__PPU3__DOT__SP_SHIFT_REG7__DOT__shift_reg__v3;
    }
    if (__Vdlyvset__PPU3__DOT__SP_SHIFT_REG7__DOT__shift_reg__v4) {
        vlTOPp->PPU3__DOT__SP_SHIFT_REG7__DOT__shift_reg[0U] 
            = (((~ ((IData)(0x7fU) << (IData)(__Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG7__DOT__shift_reg__v4))) 
                & vlTOPp->PPU3__DOT__SP_SHIFT_REG7__DOT__shift_reg
                [0U]) | ((IData)(__Vdlyvval__PPU3__DOT__SP_SHIFT_REG7__DOT__shift_reg__v4) 
                         << (IData)(__Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG7__DOT__shift_reg__v4)));
        vlTOPp->PPU3__DOT__SP_SHIFT_REG7__DOT__shift_reg[0U] 
            = ((~ ((IData)(1U) << (IData)(__Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG7__DOT__shift_reg__v5))) 
               & vlTOPp->PPU3__DOT__SP_SHIFT_REG7__DOT__shift_reg
               [0U]);
        vlTOPp->PPU3__DOT__SP_SHIFT_REG7__DOT__shift_reg[1U] 
            = (((~ ((IData)(0x7fU) << (IData)(__Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG7__DOT__shift_reg__v6))) 
                & vlTOPp->PPU3__DOT__SP_SHIFT_REG7__DOT__shift_reg
                [1U]) | ((IData)(__Vdlyvval__PPU3__DOT__SP_SHIFT_REG7__DOT__shift_reg__v6) 
                         << (IData)(__Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG7__DOT__shift_reg__v6)));
        vlTOPp->PPU3__DOT__SP_SHIFT_REG7__DOT__shift_reg[1U] 
            = ((~ ((IData)(1U) << (IData)(__Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG7__DOT__shift_reg__v7))) 
               & vlTOPp->PPU3__DOT__SP_SHIFT_REG7__DOT__shift_reg
               [1U]);
    }
    if (__Vdlyvset__PPU3__DOT__SP_SHIFT_REG8__DOT__shift_reg__v0) {
        vlTOPp->PPU3__DOT__SP_SHIFT_REG8__DOT__shift_reg[0U] = 0U;
        vlTOPp->PPU3__DOT__SP_SHIFT_REG8__DOT__shift_reg[1U] = 0U;
    }
    if (__Vdlyvset__PPU3__DOT__SP_SHIFT_REG8__DOT__shift_reg__v2) {
        vlTOPp->PPU3__DOT__SP_SHIFT_REG8__DOT__shift_reg[0U] 
            = __Vdlyvval__PPU3__DOT__SP_SHIFT_REG8__DOT__shift_reg__v2;
        vlTOPp->PPU3__DOT__SP_SHIFT_REG8__DOT__shift_reg[1U] 
            = __Vdlyvval__PPU3__DOT__SP_SHIFT_REG8__DOT__shift_reg__v3;
    }
    if (__Vdlyvset__PPU3__DOT__SP_SHIFT_REG8__DOT__shift_reg__v4) {
        vlTOPp->PPU3__DOT__SP_SHIFT_REG8__DOT__shift_reg[0U] 
            = (((~ ((IData)(0x7fU) << (IData)(__Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG8__DOT__shift_reg__v4))) 
                & vlTOPp->PPU3__DOT__SP_SHIFT_REG8__DOT__shift_reg
                [0U]) | ((IData)(__Vdlyvval__PPU3__DOT__SP_SHIFT_REG8__DOT__shift_reg__v4) 
                         << (IData)(__Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG8__DOT__shift_reg__v4)));
        vlTOPp->PPU3__DOT__SP_SHIFT_REG8__DOT__shift_reg[0U] 
            = ((~ ((IData)(1U) << (IData)(__Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG8__DOT__shift_reg__v5))) 
               & vlTOPp->PPU3__DOT__SP_SHIFT_REG8__DOT__shift_reg
               [0U]);
        vlTOPp->PPU3__DOT__SP_SHIFT_REG8__DOT__shift_reg[1U] 
            = (((~ ((IData)(0x7fU) << (IData)(__Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG8__DOT__shift_reg__v6))) 
                & vlTOPp->PPU3__DOT__SP_SHIFT_REG8__DOT__shift_reg
                [1U]) | ((IData)(__Vdlyvval__PPU3__DOT__SP_SHIFT_REG8__DOT__shift_reg__v6) 
                         << (IData)(__Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG8__DOT__shift_reg__v6)));
        vlTOPp->PPU3__DOT__SP_SHIFT_REG8__DOT__shift_reg[1U] 
            = ((~ ((IData)(1U) << (IData)(__Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG8__DOT__shift_reg__v7))) 
               & vlTOPp->PPU3__DOT__SP_SHIFT_REG8__DOT__shift_reg
               [1U]);
    }
    if (__Vdlyvset__PPU3__DOT__SP_SHIFT_REG9__DOT__shift_reg__v0) {
        vlTOPp->PPU3__DOT__SP_SHIFT_REG9__DOT__shift_reg[0U] = 0U;
        vlTOPp->PPU3__DOT__SP_SHIFT_REG9__DOT__shift_reg[1U] = 0U;
    }
    if (__Vdlyvset__PPU3__DOT__SP_SHIFT_REG9__DOT__shift_reg__v2) {
        vlTOPp->PPU3__DOT__SP_SHIFT_REG9__DOT__shift_reg[0U] 
            = __Vdlyvval__PPU3__DOT__SP_SHIFT_REG9__DOT__shift_reg__v2;
        vlTOPp->PPU3__DOT__SP_SHIFT_REG9__DOT__shift_reg[1U] 
            = __Vdlyvval__PPU3__DOT__SP_SHIFT_REG9__DOT__shift_reg__v3;
    }
    if (__Vdlyvset__PPU3__DOT__SP_SHIFT_REG9__DOT__shift_reg__v4) {
        vlTOPp->PPU3__DOT__SP_SHIFT_REG9__DOT__shift_reg[0U] 
            = (((~ ((IData)(0x7fU) << (IData)(__Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG9__DOT__shift_reg__v4))) 
                & vlTOPp->PPU3__DOT__SP_SHIFT_REG9__DOT__shift_reg
                [0U]) | ((IData)(__Vdlyvval__PPU3__DOT__SP_SHIFT_REG9__DOT__shift_reg__v4) 
                         << (IData)(__Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG9__DOT__shift_reg__v4)));
        vlTOPp->PPU3__DOT__SP_SHIFT_REG9__DOT__shift_reg[0U] 
            = ((~ ((IData)(1U) << (IData)(__Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG9__DOT__shift_reg__v5))) 
               & vlTOPp->PPU3__DOT__SP_SHIFT_REG9__DOT__shift_reg
               [0U]);
        vlTOPp->PPU3__DOT__SP_SHIFT_REG9__DOT__shift_reg[1U] 
            = (((~ ((IData)(0x7fU) << (IData)(__Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG9__DOT__shift_reg__v6))) 
                & vlTOPp->PPU3__DOT__SP_SHIFT_REG9__DOT__shift_reg
                [1U]) | ((IData)(__Vdlyvval__PPU3__DOT__SP_SHIFT_REG9__DOT__shift_reg__v6) 
                         << (IData)(__Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG9__DOT__shift_reg__v6)));
        vlTOPp->PPU3__DOT__SP_SHIFT_REG9__DOT__shift_reg[1U] 
            = ((~ ((IData)(1U) << (IData)(__Vdlyvlsb__PPU3__DOT__SP_SHIFT_REG9__DOT__shift_reg__v7))) 
               & vlTOPp->PPU3__DOT__SP_SHIFT_REG9__DOT__shift_reg
               [1U]);
    }
    if (__Vdlyvset__PPU3__DOT__BGWD_SHIFT_REG_B__DOT__shift_reg__v0) {
        vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_B__DOT__shift_reg[0U] = 0U;
        vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_B__DOT__shift_reg[1U] = 0U;
    }
    if (__Vdlyvset__PPU3__DOT__BGWD_SHIFT_REG_B__DOT__shift_reg__v2) {
        vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_B__DOT__shift_reg[0U] 
            = __Vdlyvval__PPU3__DOT__BGWD_SHIFT_REG_B__DOT__shift_reg__v2;
        vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_B__DOT__shift_reg[1U] 
            = __Vdlyvval__PPU3__DOT__BGWD_SHIFT_REG_B__DOT__shift_reg__v3;
    }
    if (__Vdlyvset__PPU3__DOT__BGWD_SHIFT_REG_B__DOT__shift_reg__v4) {
        vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_B__DOT__shift_reg[0U] 
            = (((~ ((IData)(0x7fU) << (IData)(__Vdlyvlsb__PPU3__DOT__BGWD_SHIFT_REG_B__DOT__shift_reg__v4))) 
                & vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_B__DOT__shift_reg
                [0U]) | ((IData)(__Vdlyvval__PPU3__DOT__BGWD_SHIFT_REG_B__DOT__shift_reg__v4) 
                         << (IData)(__Vdlyvlsb__PPU3__DOT__BGWD_SHIFT_REG_B__DOT__shift_reg__v4)));
        vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_B__DOT__shift_reg[0U] 
            = ((~ ((IData)(1U) << (IData)(__Vdlyvlsb__PPU3__DOT__BGWD_SHIFT_REG_B__DOT__shift_reg__v5))) 
               & vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_B__DOT__shift_reg
               [0U]);
        vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_B__DOT__shift_reg[1U] 
            = (((~ ((IData)(0x7fU) << (IData)(__Vdlyvlsb__PPU3__DOT__BGWD_SHIFT_REG_B__DOT__shift_reg__v6))) 
                & vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_B__DOT__shift_reg
                [1U]) | ((IData)(__Vdlyvval__PPU3__DOT__BGWD_SHIFT_REG_B__DOT__shift_reg__v6) 
                         << (IData)(__Vdlyvlsb__PPU3__DOT__BGWD_SHIFT_REG_B__DOT__shift_reg__v6)));
        vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_B__DOT__shift_reg[1U] 
            = ((~ ((IData)(1U) << (IData)(__Vdlyvlsb__PPU3__DOT__BGWD_SHIFT_REG_B__DOT__shift_reg__v7))) 
               & vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_B__DOT__shift_reg
               [1U]);
    }
    if (__Vdlyvset__PPU3__DOT__BGWD_SHIFT_REG_A__DOT__shift_reg__v0) {
        vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_A__DOT__shift_reg[0U] = 0U;
        vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_A__DOT__shift_reg[1U] = 0U;
    }
    if (__Vdlyvset__PPU3__DOT__BGWD_SHIFT_REG_A__DOT__shift_reg__v2) {
        vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_A__DOT__shift_reg[0U] 
            = __Vdlyvval__PPU3__DOT__BGWD_SHIFT_REG_A__DOT__shift_reg__v2;
        vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_A__DOT__shift_reg[1U] 
            = __Vdlyvval__PPU3__DOT__BGWD_SHIFT_REG_A__DOT__shift_reg__v3;
    }
    if (__Vdlyvset__PPU3__DOT__BGWD_SHIFT_REG_A__DOT__shift_reg__v4) {
        vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_A__DOT__shift_reg[0U] 
            = (((~ ((IData)(0x7fU) << (IData)(__Vdlyvlsb__PPU3__DOT__BGWD_SHIFT_REG_A__DOT__shift_reg__v4))) 
                & vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_A__DOT__shift_reg
                [0U]) | ((IData)(__Vdlyvval__PPU3__DOT__BGWD_SHIFT_REG_A__DOT__shift_reg__v4) 
                         << (IData)(__Vdlyvlsb__PPU3__DOT__BGWD_SHIFT_REG_A__DOT__shift_reg__v4)));
        vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_A__DOT__shift_reg[0U] 
            = ((~ ((IData)(1U) << (IData)(__Vdlyvlsb__PPU3__DOT__BGWD_SHIFT_REG_A__DOT__shift_reg__v5))) 
               & vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_A__DOT__shift_reg
               [0U]);
        vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_A__DOT__shift_reg[1U] 
            = (((~ ((IData)(0x7fU) << (IData)(__Vdlyvlsb__PPU3__DOT__BGWD_SHIFT_REG_A__DOT__shift_reg__v6))) 
                & vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_A__DOT__shift_reg
                [1U]) | ((IData)(__Vdlyvval__PPU3__DOT__BGWD_SHIFT_REG_A__DOT__shift_reg__v6) 
                         << (IData)(__Vdlyvlsb__PPU3__DOT__BGWD_SHIFT_REG_A__DOT__shift_reg__v6)));
        vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_A__DOT__shift_reg[1U] 
            = ((~ ((IData)(1U) << (IData)(__Vdlyvlsb__PPU3__DOT__BGWD_SHIFT_REG_A__DOT__shift_reg__v7))) 
               & vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_A__DOT__shift_reg
               [1U]);
    }
    vlTOPp->PPU3__DOT__sp_table_cnt = __Vdly__PPU3__DOT__sp_table_cnt;
    vlTOPp->PPU3__DOT__sp_found = __Vdly__PPU3__DOT__sp_found;
    if (__Vdlyvset__PPU3__DOT__sp_y_table__v0) {
        vlTOPp->PPU3__DOT__sp_y_table[0U] = 0xffU;
        vlTOPp->PPU3__DOT__sp_y_table[1U] = 0xffU;
        vlTOPp->PPU3__DOT__sp_y_table[2U] = 0xffU;
        vlTOPp->PPU3__DOT__sp_y_table[3U] = 0xffU;
        vlTOPp->PPU3__DOT__sp_y_table[4U] = 0xffU;
        vlTOPp->PPU3__DOT__sp_y_table[5U] = 0xffU;
        vlTOPp->PPU3__DOT__sp_y_table[6U] = 0xffU;
        vlTOPp->PPU3__DOT__sp_y_table[7U] = 0xffU;
        vlTOPp->PPU3__DOT__sp_y_table[8U] = 0xffU;
        vlTOPp->PPU3__DOT__sp_y_table[9U] = 0xffU;
    }
    if (__Vdlyvset__PPU3__DOT__sp_y_table__v10) {
        vlTOPp->PPU3__DOT__sp_y_table[__Vdlyvdim0__PPU3__DOT__sp_y_table__v10] 
            = __Vdlyvval__PPU3__DOT__sp_y_table__v10;
    }
    if (__Vdlyvset__PPU3__DOT__sp_y_table__v0) {
        vlTOPp->PPU3__DOT__sp_x_table[0U] = 0xffU;
        vlTOPp->PPU3__DOT__sp_x_table[1U] = 0xffU;
        vlTOPp->PPU3__DOT__sp_x_table[2U] = 0xffU;
        vlTOPp->PPU3__DOT__sp_x_table[3U] = 0xffU;
        vlTOPp->PPU3__DOT__sp_x_table[4U] = 0xffU;
        vlTOPp->PPU3__DOT__sp_x_table[5U] = 0xffU;
        vlTOPp->PPU3__DOT__sp_x_table[6U] = 0xffU;
        vlTOPp->PPU3__DOT__sp_x_table[7U] = 0xffU;
        vlTOPp->PPU3__DOT__sp_x_table[8U] = 0xffU;
        vlTOPp->PPU3__DOT__sp_x_table[9U] = 0xffU;
    }
    if (__Vdlyvset__PPU3__DOT__sp_x_table__v10) {
        vlTOPp->PPU3__DOT__sp_x_table[__Vdlyvdim0__PPU3__DOT__sp_x_table__v10] 
            = __Vdlyvval__PPU3__DOT__sp_x_table__v10;
    }
    if (__Vdlyvset__PPU3__DOT__sp_name_table__v0) {
        vlTOPp->PPU3__DOT__sp_name_table[__Vdlyvdim0__PPU3__DOT__sp_name_table__v0] 
            = __Vdlyvval__PPU3__DOT__sp_name_table__v0;
    }
    if (__Vdlyvset__PPU3__DOT__SP_PRIPN__v0) {
        vlTOPp->PPU3__DOT__SP_PRIPN[0U] = 0U;
        vlTOPp->PPU3__DOT__SP_PRIPN[1U] = 0U;
        vlTOPp->PPU3__DOT__SP_PRIPN[2U] = 0U;
        vlTOPp->PPU3__DOT__SP_PRIPN[3U] = 0U;
        vlTOPp->PPU3__DOT__SP_PRIPN[4U] = 0U;
        vlTOPp->PPU3__DOT__SP_PRIPN[5U] = 0U;
        vlTOPp->PPU3__DOT__SP_PRIPN[6U] = 0U;
        vlTOPp->PPU3__DOT__SP_PRIPN[7U] = 0U;
        vlTOPp->PPU3__DOT__SP_PRIPN[8U] = 0U;
        vlTOPp->PPU3__DOT__SP_PRIPN[9U] = 0U;
    }
    if (__Vdlyvset__PPU3__DOT__SP_PRIPN__v10) {
        vlTOPp->PPU3__DOT__SP_PRIPN[0U] = __Vdlyvval__PPU3__DOT__SP_PRIPN__v10;
    }
    if (__Vdlyvset__PPU3__DOT__SP_PRIPN__v11) {
        vlTOPp->PPU3__DOT__SP_PRIPN[1U] = __Vdlyvval__PPU3__DOT__SP_PRIPN__v11;
    }
    if (__Vdlyvset__PPU3__DOT__SP_PRIPN__v12) {
        vlTOPp->PPU3__DOT__SP_PRIPN[2U] = __Vdlyvval__PPU3__DOT__SP_PRIPN__v12;
    }
    if (__Vdlyvset__PPU3__DOT__SP_PRIPN__v13) {
        vlTOPp->PPU3__DOT__SP_PRIPN[3U] = __Vdlyvval__PPU3__DOT__SP_PRIPN__v13;
    }
    if (__Vdlyvset__PPU3__DOT__SP_PRIPN__v14) {
        vlTOPp->PPU3__DOT__SP_PRIPN[4U] = __Vdlyvval__PPU3__DOT__SP_PRIPN__v14;
    }
    if (__Vdlyvset__PPU3__DOT__SP_PRIPN__v15) {
        vlTOPp->PPU3__DOT__SP_PRIPN[5U] = __Vdlyvval__PPU3__DOT__SP_PRIPN__v15;
    }
    if (__Vdlyvset__PPU3__DOT__SP_PRIPN__v16) {
        vlTOPp->PPU3__DOT__SP_PRIPN[6U] = __Vdlyvval__PPU3__DOT__SP_PRIPN__v16;
    }
    if (__Vdlyvset__PPU3__DOT__SP_PRIPN__v17) {
        vlTOPp->PPU3__DOT__SP_PRIPN[7U] = __Vdlyvval__PPU3__DOT__SP_PRIPN__v17;
    }
    if (__Vdlyvset__PPU3__DOT__SP_PRIPN__v18) {
        vlTOPp->PPU3__DOT__SP_PRIPN[8U] = __Vdlyvval__PPU3__DOT__SP_PRIPN__v18;
    }
    if (__Vdlyvset__PPU3__DOT__SP_PRIPN__v19) {
        vlTOPp->PPU3__DOT__SP_PRIPN[9U] = __Vdlyvval__PPU3__DOT__SP_PRIPN__v19;
    }
    vlTOPp->PPU3__DOT____Vcellinp__BGWD_SHIFT_REG_A__data[0U] 
        = vlTOPp->PPU3__DOT__BGWD_TILE_DATA0;
    vlTOPp->PPU3__DOT____Vcellinp__BGWD_SHIFT_REG_B__data[0U] 
        = vlTOPp->PPU3__DOT__BGWD_TILE_DATA0;
    vlTOPp->PPU3__DOT____Vcellinp__BGWD_SHIFT_REG_A__data[1U] 
        = vlTOPp->PPU3__DOT__BGWD_TILE_DATA1;
    vlTOPp->PPU3__DOT____Vcellinp__BGWD_SHIFT_REG_B__data[1U] 
        = vlTOPp->PPU3__DOT__BGWD_TILE_DATA1;
    vlTOPp->PPU3__DOT____Vcellinp__SP_SHIFT_REG9__data[0U] 
        = (0xffU & (IData)(vlTOPp->PPU3__DOT__SP_TILE_DATA0));
    vlTOPp->PPU3__DOT____Vcellinp__SP_SHIFT_REG8__data[0U] 
        = (0xffU & (IData)(vlTOPp->PPU3__DOT__SP_TILE_DATA0));
    vlTOPp->PPU3__DOT____Vcellinp__SP_SHIFT_REG7__data[0U] 
        = (0xffU & (IData)(vlTOPp->PPU3__DOT__SP_TILE_DATA0));
    vlTOPp->PPU3__DOT____Vcellinp__SP_SHIFT_REG6__data[0U] 
        = (0xffU & (IData)(vlTOPp->PPU3__DOT__SP_TILE_DATA0));
    vlTOPp->PPU3__DOT____Vcellinp__SP_SHIFT_REG5__data[0U] 
        = (0xffU & (IData)(vlTOPp->PPU3__DOT__SP_TILE_DATA0));
    vlTOPp->PPU3__DOT____Vcellinp__SP_SHIFT_REG4__data[0U] 
        = (0xffU & (IData)(vlTOPp->PPU3__DOT__SP_TILE_DATA0));
    vlTOPp->PPU3__DOT____Vcellinp__SP_SHIFT_REG3__data[0U] 
        = (0xffU & (IData)(vlTOPp->PPU3__DOT__SP_TILE_DATA0));
    vlTOPp->PPU3__DOT____Vcellinp__SP_SHIFT_REG2__data[0U] 
        = (0xffU & (IData)(vlTOPp->PPU3__DOT__SP_TILE_DATA0));
    vlTOPp->PPU3__DOT____Vcellinp__SP_SHIFT_REG1__data[0U] 
        = (0xffU & (IData)(vlTOPp->PPU3__DOT__SP_TILE_DATA0));
    vlTOPp->PPU3__DOT____Vcellinp__SP_SHIFT_REG0__data[0U] 
        = (0xffU & (IData)(vlTOPp->PPU3__DOT__SP_TILE_DATA0));
    vlTOPp->PPU3__DOT____Vcellinp__SP_SHIFT_REG9__data[1U] 
        = (0xffU & (IData)(vlTOPp->PPU3__DOT__SP_TILE_DATA1));
    vlTOPp->PPU3__DOT____Vcellinp__SP_SHIFT_REG8__data[1U] 
        = (0xffU & (IData)(vlTOPp->PPU3__DOT__SP_TILE_DATA1));
    vlTOPp->PPU3__DOT____Vcellinp__SP_SHIFT_REG7__data[1U] 
        = (0xffU & (IData)(vlTOPp->PPU3__DOT__SP_TILE_DATA1));
    vlTOPp->PPU3__DOT____Vcellinp__SP_SHIFT_REG6__data[1U] 
        = (0xffU & (IData)(vlTOPp->PPU3__DOT__SP_TILE_DATA1));
    vlTOPp->PPU3__DOT____Vcellinp__SP_SHIFT_REG5__data[1U] 
        = (0xffU & (IData)(vlTOPp->PPU3__DOT__SP_TILE_DATA1));
    vlTOPp->PPU3__DOT____Vcellinp__SP_SHIFT_REG4__data[1U] 
        = (0xffU & (IData)(vlTOPp->PPU3__DOT__SP_TILE_DATA1));
    vlTOPp->PPU3__DOT____Vcellinp__SP_SHIFT_REG3__data[1U] 
        = (0xffU & (IData)(vlTOPp->PPU3__DOT__SP_TILE_DATA1));
    vlTOPp->PPU3__DOT____Vcellinp__SP_SHIFT_REG2__data[1U] 
        = (0xffU & (IData)(vlTOPp->PPU3__DOT__SP_TILE_DATA1));
    vlTOPp->PPU3__DOT____Vcellinp__SP_SHIFT_REG1__data[1U] 
        = (0xffU & (IData)(vlTOPp->PPU3__DOT__SP_TILE_DATA1));
    vlTOPp->PPU3__DOT____Vcellinp__SP_SHIFT_REG0__data[1U] 
        = (0xffU & (IData)(vlTOPp->PPU3__DOT__SP_TILE_DATA1));
    vlTOPp->PPU3__DOT__SP_PX_MAP[0U] = ((2U & (vlTOPp->PPU3__DOT__SP_SHIFT_REG0__DOT__shift_reg
                                               [1U] 
                                               >> 6U)) 
                                        | (1U & (vlTOPp->PPU3__DOT__SP_SHIFT_REG0__DOT__shift_reg
                                                 [0U] 
                                                 >> 7U)));
    vlTOPp->PPU3__DOT__SP_PX_MAP[1U] = ((2U & (vlTOPp->PPU3__DOT__SP_SHIFT_REG1__DOT__shift_reg
                                               [1U] 
                                               >> 6U)) 
                                        | (1U & (vlTOPp->PPU3__DOT__SP_SHIFT_REG1__DOT__shift_reg
                                                 [0U] 
                                                 >> 7U)));
    vlTOPp->PPU3__DOT__SP_PX_MAP[2U] = ((2U & (vlTOPp->PPU3__DOT__SP_SHIFT_REG2__DOT__shift_reg
                                               [1U] 
                                               >> 6U)) 
                                        | (1U & (vlTOPp->PPU3__DOT__SP_SHIFT_REG2__DOT__shift_reg
                                                 [0U] 
                                                 >> 7U)));
    vlTOPp->PPU3__DOT__SP_PX_MAP[3U] = ((2U & (vlTOPp->PPU3__DOT__SP_SHIFT_REG3__DOT__shift_reg
                                               [1U] 
                                               >> 6U)) 
                                        | (1U & (vlTOPp->PPU3__DOT__SP_SHIFT_REG3__DOT__shift_reg
                                                 [0U] 
                                                 >> 7U)));
    vlTOPp->PPU3__DOT__SP_PX_MAP[4U] = ((2U & (vlTOPp->PPU3__DOT__SP_SHIFT_REG4__DOT__shift_reg
                                               [1U] 
                                               >> 6U)) 
                                        | (1U & (vlTOPp->PPU3__DOT__SP_SHIFT_REG4__DOT__shift_reg
                                                 [0U] 
                                                 >> 7U)));
    vlTOPp->PPU3__DOT__SP_PX_MAP[5U] = ((2U & (vlTOPp->PPU3__DOT__SP_SHIFT_REG5__DOT__shift_reg
                                               [1U] 
                                               >> 6U)) 
                                        | (1U & (vlTOPp->PPU3__DOT__SP_SHIFT_REG5__DOT__shift_reg
                                                 [0U] 
                                                 >> 7U)));
    vlTOPp->PPU3__DOT__SP_PX_MAP[6U] = ((2U & (vlTOPp->PPU3__DOT__SP_SHIFT_REG6__DOT__shift_reg
                                               [1U] 
                                               >> 6U)) 
                                        | (1U & (vlTOPp->PPU3__DOT__SP_SHIFT_REG6__DOT__shift_reg
                                                 [0U] 
                                                 >> 7U)));
    vlTOPp->PPU3__DOT__SP_PX_MAP[7U] = ((2U & (vlTOPp->PPU3__DOT__SP_SHIFT_REG7__DOT__shift_reg
                                               [1U] 
                                               >> 6U)) 
                                        | (1U & (vlTOPp->PPU3__DOT__SP_SHIFT_REG7__DOT__shift_reg
                                                 [0U] 
                                                 >> 7U)));
    vlTOPp->PPU3__DOT__SP_PX_MAP[8U] = ((2U & (vlTOPp->PPU3__DOT__SP_SHIFT_REG8__DOT__shift_reg
                                               [1U] 
                                               >> 6U)) 
                                        | (1U & (vlTOPp->PPU3__DOT__SP_SHIFT_REG8__DOT__shift_reg
                                                 [0U] 
                                                 >> 7U)));
    vlTOPp->PPU3__DOT__SP_PX_MAP[9U] = ((2U & (vlTOPp->PPU3__DOT__SP_SHIFT_REG9__DOT__shift_reg
                                               [1U] 
                                               >> 6U)) 
                                        | (1U & (vlTOPp->PPU3__DOT__SP_SHIFT_REG9__DOT__shift_reg
                                                 [0U] 
                                                 >> 7U)));
    vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_SEL = ((~ (IData)(vlTOPp->rst)) 
                                             & (IData)(vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_SEL_NEXT));
    vlTOPp->PPU3__DOT__PPU_CNT = ((IData)(vlTOPp->rst)
                                   ? 0U : (IData)(vlTOPp->PPU3__DOT__PPU_CNT_NEXT));
    vlTOPp->PPU3__DOT__LY = ((IData)(vlTOPp->rst) ? 0x91U
                              : (IData)(vlTOPp->PPU3__DOT__LY_NEXT));
    vlTOPp->PPU3__DOT__PPU_STATE = ((IData)(vlTOPp->rst)
                                     ? 3U : vlTOPp->PPU3__DOT__PPU_STATE_NEXT);
    vlTOPp->PPU3__DOT__FF40 = ((IData)(vlTOPp->rst)
                                ? 0U : (IData)(vlTOPp->PPU3__DOT__FF40_NEXT));
    vlTOPp->PPU3__DOT__sp_name_table_x[0U] = (vlTOPp->PPU3__DOT__sp_name_table
                                              [0U] 
                                              << 2U);
    vlTOPp->PPU3__DOT__sp_name_table_x[1U] = (vlTOPp->PPU3__DOT__sp_name_table
                                              [1U] 
                                              << 2U);
    vlTOPp->PPU3__DOT__sp_name_table_x[2U] = (vlTOPp->PPU3__DOT__sp_name_table
                                              [2U] 
                                              << 2U);
    vlTOPp->PPU3__DOT__sp_name_table_x[3U] = (vlTOPp->PPU3__DOT__sp_name_table
                                              [3U] 
                                              << 2U);
    vlTOPp->PPU3__DOT__sp_name_table_x[4U] = (vlTOPp->PPU3__DOT__sp_name_table
                                              [4U] 
                                              << 2U);
    vlTOPp->PPU3__DOT__sp_name_table_x[5U] = (vlTOPp->PPU3__DOT__sp_name_table
                                              [5U] 
                                              << 2U);
    vlTOPp->PPU3__DOT__sp_name_table_x[6U] = (vlTOPp->PPU3__DOT__sp_name_table
                                              [6U] 
                                              << 2U);
    vlTOPp->PPU3__DOT__sp_name_table_x[7U] = (vlTOPp->PPU3__DOT__sp_name_table
                                              [7U] 
                                              << 2U);
    vlTOPp->PPU3__DOT__sp_name_table_x[8U] = (vlTOPp->PPU3__DOT__sp_name_table
                                              [8U] 
                                              << 2U);
    vlTOPp->PPU3__DOT__sp_name_table_x[9U] = (vlTOPp->PPU3__DOT__sp_name_table
                                              [9U] 
                                              << 2U);
    vlTOPp->PPU3__DOT__BGWD_PX_MAP = ((IData)(vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_SEL)
                                       ? ((2U & (vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_B__DOT__shift_reg
                                                 [1U] 
                                                 >> 6U)) 
                                          | (1U & (
                                                   vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_B__DOT__shift_reg
                                                   [0U] 
                                                   >> 7U)))
                                       : ((2U & (vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_A__DOT__shift_reg
                                                 [1U] 
                                                 >> 6U)) 
                                          | (1U & (
                                                   vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_A__DOT__shift_reg
                                                   [0U] 
                                                   >> 7U))));
    vlTOPp->PPU3__DOT__OAM_SEARCH_GO = 0U;
    if ((0x80U & (IData)(vlTOPp->PPU3__DOT__FF40))) {
        if ((0U == vlTOPp->PPU3__DOT__PPU_STATE)) {
            vlTOPp->PPU3__DOT__OAM_SEARCH_GO = 1U;
        }
    }
    vlTOPp->PPU_RD = 0U;
    if ((0x80U & (IData)(vlTOPp->PPU3__DOT__FF40))) {
        if ((0U == vlTOPp->PPU3__DOT__PPU_STATE)) {
            vlTOPp->PPU_RD = 1U;
        } else {
            if ((1U == vlTOPp->PPU3__DOT__PPU_STATE)) {
                vlTOPp->PPU_RD = 1U;
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->PPU3__DOT__FF40))) {
        vlTOPp->PPU3__DOT__PPU_CNT_NEXT = (0xffffU 
                                           & ((IData)(1U) 
                                              + (IData)(vlTOPp->PPU3__DOT__PPU_CNT)));
        if ((0U != vlTOPp->PPU3__DOT__PPU_STATE)) {
            if ((1U != vlTOPp->PPU3__DOT__PPU_STATE)) {
                if ((2U == vlTOPp->PPU3__DOT__PPU_STATE)) {
                    if ((0x1c7U == (IData)(vlTOPp->PPU3__DOT__PPU_CNT))) {
                        vlTOPp->PPU3__DOT__PPU_CNT_NEXT = 0U;
                    }
                } else {
                    if ((3U == vlTOPp->PPU3__DOT__PPU_STATE)) {
                        if (((0x1c7U == (IData)(vlTOPp->PPU3__DOT__PPU_CNT)) 
                             & (0U != (IData)(vlTOPp->PPU3__DOT__LY)))) {
                            vlTOPp->PPU3__DOT__PPU_CNT_NEXT = 0U;
                        }
                        if (((0x1c7U == (IData)(vlTOPp->PPU3__DOT__PPU_CNT)) 
                             & (0U == (IData)(vlTOPp->PPU3__DOT__LY)))) {
                            vlTOPp->PPU3__DOT__PPU_CNT_NEXT = 0U;
                        }
                    }
                }
            }
        }
    } else {
        vlTOPp->PPU3__DOT__PPU_CNT_NEXT = 0U;
    }
    vlTOPp->PPU_MODE = 1U;
    if ((0x80U & (IData)(vlTOPp->PPU3__DOT__FF40))) {
        if ((0U == vlTOPp->PPU3__DOT__PPU_STATE)) {
            vlTOPp->PPU_MODE = 2U;
        } else {
            if ((1U == vlTOPp->PPU3__DOT__PPU_STATE)) {
                vlTOPp->PPU_MODE = 3U;
            } else {
                if ((2U == vlTOPp->PPU3__DOT__PPU_STATE)) {
                    vlTOPp->PPU_MODE = 0U;
                } else {
                    if ((3U == vlTOPp->PPU3__DOT__PPU_STATE)) {
                        vlTOPp->PPU_MODE = 1U;
                    }
                }
            }
        }
    } else {
        vlTOPp->PPU_MODE = 0U;
    }
    vlTOPp->PPU3__DOT__isHitSP = 0U;
    if ((2U & (IData)(vlTOPp->PPU3__DOT__FF40))) {
        if (((vlTOPp->PPU3__DOT__sp_x_table[9U] == (IData)(vlTOPp->PPU3__DOT__LX)) 
             & ((IData)(vlTOPp->PPU3__DOT__sp_not_used) 
                >> 9U))) {
            vlTOPp->PPU3__DOT__isHitSP = 1U;
        }
        if (((vlTOPp->PPU3__DOT__sp_x_table[8U] == (IData)(vlTOPp->PPU3__DOT__LX)) 
             & ((IData)(vlTOPp->PPU3__DOT__sp_not_used) 
                >> 8U))) {
            vlTOPp->PPU3__DOT__isHitSP = 1U;
        }
        if (((vlTOPp->PPU3__DOT__sp_x_table[7U] == (IData)(vlTOPp->PPU3__DOT__LX)) 
             & ((IData)(vlTOPp->PPU3__DOT__sp_not_used) 
                >> 7U))) {
            vlTOPp->PPU3__DOT__isHitSP = 1U;
        }
        if (((vlTOPp->PPU3__DOT__sp_x_table[6U] == (IData)(vlTOPp->PPU3__DOT__LX)) 
             & ((IData)(vlTOPp->PPU3__DOT__sp_not_used) 
                >> 6U))) {
            vlTOPp->PPU3__DOT__isHitSP = 1U;
        }
        if (((vlTOPp->PPU3__DOT__sp_x_table[5U] == (IData)(vlTOPp->PPU3__DOT__LX)) 
             & ((IData)(vlTOPp->PPU3__DOT__sp_not_used) 
                >> 5U))) {
            vlTOPp->PPU3__DOT__isHitSP = 1U;
        }
        if (((vlTOPp->PPU3__DOT__sp_x_table[4U] == (IData)(vlTOPp->PPU3__DOT__LX)) 
             & ((IData)(vlTOPp->PPU3__DOT__sp_not_used) 
                >> 4U))) {
            vlTOPp->PPU3__DOT__isHitSP = 1U;
        }
        if (((vlTOPp->PPU3__DOT__sp_x_table[3U] == (IData)(vlTOPp->PPU3__DOT__LX)) 
             & ((IData)(vlTOPp->PPU3__DOT__sp_not_used) 
                >> 3U))) {
            vlTOPp->PPU3__DOT__isHitSP = 1U;
        }
        if (((vlTOPp->PPU3__DOT__sp_x_table[2U] == (IData)(vlTOPp->PPU3__DOT__LX)) 
             & ((IData)(vlTOPp->PPU3__DOT__sp_not_used) 
                >> 2U))) {
            vlTOPp->PPU3__DOT__isHitSP = 1U;
        }
        if (((vlTOPp->PPU3__DOT__sp_x_table[1U] == (IData)(vlTOPp->PPU3__DOT__LX)) 
             & ((IData)(vlTOPp->PPU3__DOT__sp_not_used) 
                >> 1U))) {
            vlTOPp->PPU3__DOT__isHitSP = 1U;
        }
        if (((vlTOPp->PPU3__DOT__sp_x_table[0U] == (IData)(vlTOPp->PPU3__DOT__LX)) 
             & (IData)(vlTOPp->PPU3__DOT__sp_not_used))) {
            vlTOPp->PPU3__DOT__isHitSP = 1U;
        }
    }
    vlTOPp->PPU3__DOT__sp_to_fetch = 0U;
    if ((2U & (IData)(vlTOPp->PPU3__DOT__FF40))) {
        if (((vlTOPp->PPU3__DOT__sp_x_table[9U] == (IData)(vlTOPp->PPU3__DOT__LX)) 
             & ((IData)(vlTOPp->PPU3__DOT__sp_not_used) 
                >> 9U))) {
            vlTOPp->PPU3__DOT__sp_to_fetch = 9U;
        }
        if (((vlTOPp->PPU3__DOT__sp_x_table[8U] == (IData)(vlTOPp->PPU3__DOT__LX)) 
             & ((IData)(vlTOPp->PPU3__DOT__sp_not_used) 
                >> 8U))) {
            vlTOPp->PPU3__DOT__sp_to_fetch = 8U;
        }
        if (((vlTOPp->PPU3__DOT__sp_x_table[7U] == (IData)(vlTOPp->PPU3__DOT__LX)) 
             & ((IData)(vlTOPp->PPU3__DOT__sp_not_used) 
                >> 7U))) {
            vlTOPp->PPU3__DOT__sp_to_fetch = 7U;
        }
        if (((vlTOPp->PPU3__DOT__sp_x_table[6U] == (IData)(vlTOPp->PPU3__DOT__LX)) 
             & ((IData)(vlTOPp->PPU3__DOT__sp_not_used) 
                >> 6U))) {
            vlTOPp->PPU3__DOT__sp_to_fetch = 6U;
        }
        if (((vlTOPp->PPU3__DOT__sp_x_table[5U] == (IData)(vlTOPp->PPU3__DOT__LX)) 
             & ((IData)(vlTOPp->PPU3__DOT__sp_not_used) 
                >> 5U))) {
            vlTOPp->PPU3__DOT__sp_to_fetch = 5U;
        }
        if (((vlTOPp->PPU3__DOT__sp_x_table[4U] == (IData)(vlTOPp->PPU3__DOT__LX)) 
             & ((IData)(vlTOPp->PPU3__DOT__sp_not_used) 
                >> 4U))) {
            vlTOPp->PPU3__DOT__sp_to_fetch = 4U;
        }
        if (((vlTOPp->PPU3__DOT__sp_x_table[3U] == (IData)(vlTOPp->PPU3__DOT__LX)) 
             & ((IData)(vlTOPp->PPU3__DOT__sp_not_used) 
                >> 3U))) {
            vlTOPp->PPU3__DOT__sp_to_fetch = 3U;
        }
        if (((vlTOPp->PPU3__DOT__sp_x_table[2U] == (IData)(vlTOPp->PPU3__DOT__LX)) 
             & ((IData)(vlTOPp->PPU3__DOT__sp_not_used) 
                >> 2U))) {
            vlTOPp->PPU3__DOT__sp_to_fetch = 2U;
        }
        if (((vlTOPp->PPU3__DOT__sp_x_table[1U] == (IData)(vlTOPp->PPU3__DOT__LX)) 
             & ((IData)(vlTOPp->PPU3__DOT__sp_not_used) 
                >> 1U))) {
            vlTOPp->PPU3__DOT__sp_to_fetch = 1U;
        }
        if (((vlTOPp->PPU3__DOT__sp_x_table[0U] == (IData)(vlTOPp->PPU3__DOT__LX)) 
             & (IData)(vlTOPp->PPU3__DOT__sp_not_used))) {
            vlTOPp->PPU3__DOT__sp_to_fetch = 0U;
        }
    }
    vlTOPp->PPU3__DOT__BGWD_PX_DATA = ((2U & (((IData)(vlTOPp->PPU3__DOT__FF47) 
                                               >> (1U 
                                                   | ((IData)(vlTOPp->PPU3__DOT__BGWD_PX_MAP) 
                                                      << 1U))) 
                                              << 1U)) 
                                       | (1U & ((IData)(vlTOPp->PPU3__DOT__FF47) 
                                                >> 
                                                ((IData)(vlTOPp->PPU3__DOT__BGWD_PX_MAP) 
                                                 << 1U))));
    vlTOPp->PPU3__DOT__PPU_STATE_NEXT = vlTOPp->PPU3__DOT__PPU_STATE;
    vlTOPp->PPU3__DOT__LX_NEXT = vlTOPp->PPU3__DOT__LX;
    vlTOPp->PPU3__DOT__LY_NEXT = vlTOPp->PPU3__DOT__LY;
    vlTOPp->PPU3__DOT__SCX_CNT_NEXT = vlTOPp->PPU3__DOT__SCX_CNT;
    vlTOPp->PPU3__DOT__sp_not_used_next = vlTOPp->PPU3__DOT__sp_not_used;
    vlTOPp->PPU3__DOT__isFetchWD_NEXT = vlTOPp->PPU3__DOT__isFetchWD;
    vlTOPp->PPU3__DOT__FIRST_FETCH_WD_DONE_NEXT = vlTOPp->PPU3__DOT__FIRST_FETCH_WD_DONE;
    vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_SEL_NEXT = vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_SEL;
    vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_A_VALID_NEXT 
        = vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_A_VALID;
    vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_B_VALID_NEXT 
        = vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_B_VALID;
    vlTOPp->PPU3__DOT__RENDER_CNT_NEXT = vlTOPp->PPU3__DOT__RENDER_CNT;
    vlTOPp->PPU3__DOT__SP_NEXT_SLOT_NEXT = vlTOPp->PPU3__DOT__SP_NEXT_SLOT;
    vlTOPp->PPU3__DOT____Vlvbound3 = vlTOPp->PPU3__DOT__SP_PRIPN
        [0U];
    vlTOPp->PPU3__DOT__SP_PRIPN_NEXT[0U] = vlTOPp->PPU3__DOT____Vlvbound3;
    vlTOPp->PPU3__DOT____Vlvbound3 = vlTOPp->PPU3__DOT__SP_PRIPN
        [1U];
    vlTOPp->PPU3__DOT__SP_PRIPN_NEXT[1U] = vlTOPp->PPU3__DOT____Vlvbound3;
    vlTOPp->PPU3__DOT____Vlvbound3 = vlTOPp->PPU3__DOT__SP_PRIPN
        [2U];
    vlTOPp->PPU3__DOT__SP_PRIPN_NEXT[2U] = vlTOPp->PPU3__DOT____Vlvbound3;
    vlTOPp->PPU3__DOT____Vlvbound3 = vlTOPp->PPU3__DOT__SP_PRIPN
        [3U];
    vlTOPp->PPU3__DOT__SP_PRIPN_NEXT[3U] = vlTOPp->PPU3__DOT____Vlvbound3;
    vlTOPp->PPU3__DOT____Vlvbound3 = vlTOPp->PPU3__DOT__SP_PRIPN
        [4U];
    vlTOPp->PPU3__DOT__SP_PRIPN_NEXT[4U] = vlTOPp->PPU3__DOT____Vlvbound3;
    vlTOPp->PPU3__DOT____Vlvbound3 = vlTOPp->PPU3__DOT__SP_PRIPN
        [5U];
    vlTOPp->PPU3__DOT__SP_PRIPN_NEXT[5U] = vlTOPp->PPU3__DOT____Vlvbound3;
    vlTOPp->PPU3__DOT____Vlvbound3 = vlTOPp->PPU3__DOT__SP_PRIPN
        [6U];
    vlTOPp->PPU3__DOT__SP_PRIPN_NEXT[6U] = vlTOPp->PPU3__DOT____Vlvbound3;
    vlTOPp->PPU3__DOT____Vlvbound3 = vlTOPp->PPU3__DOT__SP_PRIPN
        [7U];
    vlTOPp->PPU3__DOT__SP_PRIPN_NEXT[7U] = vlTOPp->PPU3__DOT____Vlvbound3;
    vlTOPp->PPU3__DOT____Vlvbound3 = vlTOPp->PPU3__DOT__SP_PRIPN
        [8U];
    vlTOPp->PPU3__DOT__SP_PRIPN_NEXT[8U] = vlTOPp->PPU3__DOT____Vlvbound3;
    vlTOPp->PPU3__DOT____Vlvbound3 = vlTOPp->PPU3__DOT__SP_PRIPN
        [9U];
    vlTOPp->PPU3__DOT__SP_PRIPN_NEXT[9U] = vlTOPp->PPU3__DOT____Vlvbound3;
    vlTOPp->PPU_ADDR = 0U;
    vlTOPp->PPU3__DOT__BGWD_RENDER_GO = 0U;
    vlTOPp->PPU3__DOT__isHitWD = ((((IData)(vlTOPp->PPU3__DOT__FF4A) 
                                    <= (IData)(vlTOPp->PPU3__DOT__LY)) 
                                   & ((IData)(vlTOPp->PPU3__DOT__LX) 
                                      == ((IData)(1U) 
                                          + (IData)(vlTOPp->PPU3__DOT__FF4B)))) 
                                  & ((IData)(vlTOPp->PPU3__DOT__FF40) 
                                     >> 5U));
    vlTOPp->PPU3__DOT__SP_RENDER_GO = 0U;
    vlTOPp->PPU3__DOT__SP_SHIFT_REG_LOAD = 0U;
    vlTOPp->PPU3__DOT__SHIFT_REG_GO = 0U;
    vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_LOAD = 0U;
    vlTOPp->PX_valid = 0U;
    vlTOPp->IRQ_V_BLANK = 0U;
    if ((0x80U & (IData)(vlTOPp->PPU3__DOT__FF40))) {
        if ((0U == vlTOPp->PPU3__DOT__PPU_STATE)) {
            vlTOPp->PPU_ADDR = (0xffffU & ((1U & (IData)(vlTOPp->PPU3__DOT__PPU_CNT))
                                            ? ((IData)(0xfdffU) 
                                               + ((IData)(vlTOPp->PPU3__DOT__PPU_CNT) 
                                                  << 1U))
                                            : ((IData)(0xfe00U) 
                                               + ((IData)(vlTOPp->PPU3__DOT__PPU_CNT) 
                                                  << 1U))));
            vlTOPp->PPU3__DOT__sp_not_used_next = 0x3ffU;
            if ((0x4fU == (IData)(vlTOPp->PPU3__DOT__PPU_CNT))) {
                vlTOPp->PPU3__DOT__PPU_STATE_NEXT = 1U;
            }
        } else {
            if ((1U == vlTOPp->PPU3__DOT__PPU_STATE)) {
                if (((IData)(vlTOPp->PPU3__DOT__isHitWD) 
                     & (~ (IData)(vlTOPp->PPU3__DOT__isFetchWD)))) {
                    vlTOPp->PPU3__DOT__RENDER_CNT_NEXT = 0U;
                    vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_A_VALID_NEXT = 0U;
                    vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_B_VALID_NEXT = 0U;
                    vlTOPp->PPU3__DOT__isFetchWD_NEXT = 1U;
                } else {
                    if ((((~ (IData)(vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_A_VALID)) 
                          | (~ (IData)(vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_B_VALID))) 
                         & (6U >= (IData)(vlTOPp->PPU3__DOT__RENDER_CNT)))) {
                        vlTOPp->PPU3__DOT__BGWD_RENDER_GO = 1U;
                        if (vlTOPp->PPU3__DOT__isFetchWD) {
                            if ((0U == (IData)(vlTOPp->PPU3__DOT__BGWD_CNT))) {
                                vlTOPp->PPU_ADDR = 
                                    (0xffffU & (0x9800U 
                                                | (((0x400U 
                                                     & ((IData)(vlTOPp->PPU3__DOT__FF40) 
                                                        << 4U)) 
                                                    | (0x3e0U 
                                                       & (((IData)(vlTOPp->PPU3__DOT__LY) 
                                                           - (IData)(vlTOPp->PPU3__DOT__FF4A)) 
                                                          << 2U))) 
                                                   | (0x1fU 
                                                      & (((((IData)(vlTOPp->PPU3__DOT__LX) 
                                                            + 
                                                            ((IData)(vlTOPp->PPU3__DOT__FIRST_FETCH_WD_DONE) 
                                                             << 3U)) 
                                                           - (IData)(vlTOPp->PPU3__DOT__FF4B)) 
                                                          - (IData)(1U)) 
                                                         >> 3U)))));
                            } else {
                                if ((1U == (IData)(vlTOPp->PPU3__DOT__BGWD_CNT))) {
                                    vlTOPp->PPU_ADDR 
                                        = (0xffffU 
                                           & (IData)(
                                                     (VL_ULL(0x1ffffffff) 
                                                      & ((0x10U 
                                                          & (IData)(vlTOPp->PPU3__DOT__FF40))
                                                          ? 
                                                         (((QData)((IData)(
                                                                           ((0x10U 
                                                                             & (IData)(vlTOPp->PPU3__DOT__FF40))
                                                                             ? 0x8000U
                                                                             : 0x9000U))) 
                                                           + (QData)((IData)(
                                                                             ((IData)(vlTOPp->PPU3__DOT__BGWD_MAP) 
                                                                              << 4U)))) 
                                                          | ((QData)((IData)(
                                                                             (7U 
                                                                              & ((IData)(vlTOPp->PPU3__DOT__LY) 
                                                                                - (IData)(vlTOPp->PPU3__DOT__FF4A))))) 
                                                             << 1U))
                                                          : 
                                                         ((((QData)((IData)(
                                                                            ((0x10U 
                                                                              & (IData)(vlTOPp->PPU3__DOT__FF40))
                                                                              ? 0x8000U
                                                                              : 0x9000U))) 
                                                            - (QData)((IData)(
                                                                              (0x800U 
                                                                               & ((IData)(vlTOPp->PPU3__DOT__BGWD_MAP) 
                                                                                << 4U))))) 
                                                           + (QData)((IData)(
                                                                             (0x7f0U 
                                                                              & ((IData)(vlTOPp->PPU3__DOT__BGWD_MAP) 
                                                                                << 4U))))) 
                                                          | (QData)((IData)(
                                                                            (0xeU 
                                                                             & (((IData)(vlTOPp->PPU3__DOT__LY) 
                                                                                - (IData)(vlTOPp->PPU3__DOT__FF4A)) 
                                                                                << 1U)))))))));
                                } else {
                                    if ((2U == (IData)(vlTOPp->PPU3__DOT__BGWD_CNT))) {
                                        vlTOPp->PPU_ADDR 
                                            = (0xffffU 
                                               & (IData)(
                                                         (VL_ULL(0x1ffffffff) 
                                                          & ((0x10U 
                                                              & (IData)(vlTOPp->PPU3__DOT__FF40))
                                                              ? 
                                                             (VL_ULL(1) 
                                                              | (((QData)((IData)(
                                                                                ((0x10U 
                                                                                & (IData)(vlTOPp->PPU3__DOT__FF40))
                                                                                 ? 0x8000U
                                                                                 : 0x9000U))) 
                                                                  + (QData)((IData)(
                                                                                ((IData)(vlTOPp->PPU3__DOT__BGWD_MAP) 
                                                                                << 4U)))) 
                                                                 | ((QData)((IData)(
                                                                                (7U 
                                                                                & ((IData)(vlTOPp->PPU3__DOT__LY) 
                                                                                - (IData)(vlTOPp->PPU3__DOT__FF4A))))) 
                                                                    << 1U)))
                                                              : 
                                                             ((((QData)((IData)(
                                                                                ((0x10U 
                                                                                & (IData)(vlTOPp->PPU3__DOT__FF40))
                                                                                 ? 0x8000U
                                                                                 : 0x9000U))) 
                                                                - (QData)((IData)(
                                                                                (0x800U 
                                                                                & ((IData)(vlTOPp->PPU3__DOT__BGWD_MAP) 
                                                                                << 4U))))) 
                                                               + (QData)((IData)(
                                                                                (0x7f0U 
                                                                                & ((IData)(vlTOPp->PPU3__DOT__BGWD_MAP) 
                                                                                << 4U))))) 
                                                              | (QData)((IData)(
                                                                                (1U 
                                                                                | (0xeU 
                                                                                & (((IData)(vlTOPp->PPU3__DOT__LY) 
                                                                                - (IData)(vlTOPp->PPU3__DOT__FF4A)) 
                                                                                << 1U))))))))));
                                    }
                                }
                            }
                        } else {
                            if ((0U == (IData)(vlTOPp->PPU3__DOT__BGWD_CNT))) {
                                vlTOPp->PPU_ADDR = 
                                    (0x9800U | (((0x400U 
                                                  & ((IData)(vlTOPp->PPU3__DOT__FF40) 
                                                     << 7U)) 
                                                 | (0x3e0U 
                                                    & (((IData)(vlTOPp->PPU3__DOT__LY) 
                                                        + (IData)(vlTOPp->PPU3__DOT__FF42)) 
                                                       << 2U))) 
                                                | (0x1fU 
                                                   & (((IData)(vlTOPp->PPU3__DOT__LX) 
                                                       + (IData)(vlTOPp->PPU3__DOT__FF43)) 
                                                      >> 3U))));
                            } else {
                                if ((1U == (IData)(vlTOPp->PPU3__DOT__BGWD_CNT))) {
                                    vlTOPp->PPU_ADDR 
                                        = (0xffffU 
                                           & (IData)(
                                                     (VL_ULL(0x1ffffffff) 
                                                      & ((0x10U 
                                                          & (IData)(vlTOPp->PPU3__DOT__FF40))
                                                          ? 
                                                         (((QData)((IData)(
                                                                           ((0x10U 
                                                                             & (IData)(vlTOPp->PPU3__DOT__FF40))
                                                                             ? 0x8000U
                                                                             : 0x9000U))) 
                                                           + (QData)((IData)(
                                                                             ((IData)(vlTOPp->PPU3__DOT__BGWD_MAP) 
                                                                              << 4U)))) 
                                                          | ((QData)((IData)(
                                                                             (7U 
                                                                              & ((IData)(vlTOPp->PPU3__DOT__LY) 
                                                                                + (IData)(vlTOPp->PPU3__DOT__FF42))))) 
                                                             << 1U))
                                                          : 
                                                         ((((QData)((IData)(
                                                                            ((0x10U 
                                                                              & (IData)(vlTOPp->PPU3__DOT__FF40))
                                                                              ? 0x8000U
                                                                              : 0x9000U))) 
                                                            - (QData)((IData)(
                                                                              (0x800U 
                                                                               & ((IData)(vlTOPp->PPU3__DOT__BGWD_MAP) 
                                                                                << 4U))))) 
                                                           + (QData)((IData)(
                                                                             (0x7f0U 
                                                                              & ((IData)(vlTOPp->PPU3__DOT__BGWD_MAP) 
                                                                                << 4U))))) 
                                                          | (QData)((IData)(
                                                                            (0xeU 
                                                                             & (((IData)(vlTOPp->PPU3__DOT__LY) 
                                                                                + (IData)(vlTOPp->PPU3__DOT__FF42)) 
                                                                                << 1U)))))))));
                                } else {
                                    if ((2U == (IData)(vlTOPp->PPU3__DOT__BGWD_CNT))) {
                                        vlTOPp->PPU_ADDR 
                                            = (0xffffU 
                                               & (IData)(
                                                         (VL_ULL(0x1ffffffff) 
                                                          & ((0x10U 
                                                              & (IData)(vlTOPp->PPU3__DOT__FF40))
                                                              ? 
                                                             (VL_ULL(1) 
                                                              | (((QData)((IData)(
                                                                                ((0x10U 
                                                                                & (IData)(vlTOPp->PPU3__DOT__FF40))
                                                                                 ? 0x8000U
                                                                                 : 0x9000U))) 
                                                                  + (QData)((IData)(
                                                                                ((IData)(vlTOPp->PPU3__DOT__BGWD_MAP) 
                                                                                << 4U)))) 
                                                                 | ((QData)((IData)(
                                                                                (7U 
                                                                                & ((IData)(vlTOPp->PPU3__DOT__LY) 
                                                                                + (IData)(vlTOPp->PPU3__DOT__FF42))))) 
                                                                    << 1U)))
                                                              : 
                                                             ((((QData)((IData)(
                                                                                ((0x10U 
                                                                                & (IData)(vlTOPp->PPU3__DOT__FF40))
                                                                                 ? 0x8000U
                                                                                 : 0x9000U))) 
                                                                - (QData)((IData)(
                                                                                (0x800U 
                                                                                & ((IData)(vlTOPp->PPU3__DOT__BGWD_MAP) 
                                                                                << 4U))))) 
                                                               + (QData)((IData)(
                                                                                (0x7f0U 
                                                                                & ((IData)(vlTOPp->PPU3__DOT__BGWD_MAP) 
                                                                                << 4U))))) 
                                                              | (QData)((IData)(
                                                                                (1U 
                                                                                | (0xeU 
                                                                                & (((IData)(vlTOPp->PPU3__DOT__LY) 
                                                                                + (IData)(vlTOPp->PPU3__DOT__FF42)) 
                                                                                << 1U))))))))));
                                    }
                                }
                            }
                        }
                        if (((IData)(vlTOPp->PPU3__DOT__BGWD_CNT) 
                             == (5U & (6U | (1U & (~ (IData)(vlTOPp->PPU3__DOT__isHitSP))))))) {
                            if (vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_SEL) {
                                vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_A_VALID_NEXT = 1U;
                                vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_LOAD 
                                    = (1U | (IData)(vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_LOAD));
                            } else {
                                vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_B_VALID_NEXT = 1U;
                                vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_LOAD 
                                    = (2U | (IData)(vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_LOAD));
                            }
                            if ((1U & ((~ (IData)(vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_A_VALID)) 
                                       & (~ (IData)(vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_B_VALID))))) {
                                vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_SEL_NEXT 
                                    = (1U & (~ (IData)(vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_SEL)));
                            }
                            if (vlTOPp->PPU3__DOT__isFetchWD) {
                                vlTOPp->PPU3__DOT__FIRST_FETCH_WD_DONE_NEXT = 1U;
                            }
                        }
                    } else {
                        if (vlTOPp->PPU3__DOT__isHitSP) {
                            vlTOPp->PPU3__DOT__SP_RENDER_GO = 1U;
                            if ((0U == (IData)(vlTOPp->PPU3__DOT__SP_CNT))) {
                                vlTOPp->PPU_ADDR = 
                                    (0xffffU & ((IData)(0xfe02U) 
                                                + (
                                                   (9U 
                                                    >= (IData)(vlTOPp->PPU3__DOT__sp_to_fetch))
                                                    ? 
                                                   vlTOPp->PPU3__DOT__sp_name_table_x
                                                   [vlTOPp->PPU3__DOT__sp_to_fetch]
                                                    : 0U)));
                            } else {
                                if ((1U == (IData)(vlTOPp->PPU3__DOT__SP_CNT))) {
                                    vlTOPp->PPU_ADDR 
                                        = (0xffffU 
                                           & ((IData)(0xfe03U) 
                                              + ((9U 
                                                  >= (IData)(vlTOPp->PPU3__DOT__sp_to_fetch))
                                                  ? 
                                                 vlTOPp->PPU3__DOT__sp_name_table_x
                                                 [vlTOPp->PPU3__DOT__sp_to_fetch]
                                                  : 0U)));
                                } else {
                                    if (((2U == (IData)(vlTOPp->PPU3__DOT__SP_CNT)) 
                                         | (3U == (IData)(vlTOPp->PPU3__DOT__SP_CNT)))) {
                                        vlTOPp->PPU_ADDR 
                                            = (0xffffU 
                                               & ((0x40U 
                                                   & (IData)(vlTOPp->PPU3__DOT__SP_FLAG))
                                                   ? 
                                                  ((IData)(0x8000U) 
                                                   + 
                                                   ((((4U 
                                                       & (IData)(vlTOPp->PPU3__DOT__FF40))
                                                       ? 
                                                      (0xfeU 
                                                       & (IData)(vlTOPp->PPU3__DOT__SP_MAP))
                                                       : (IData)(vlTOPp->PPU3__DOT__SP_MAP)) 
                                                     << 4U) 
                                                    | (0x1eU 
                                                       & ((((((IData)(8U) 
                                                              + 
                                                              ((8U 
                                                                & ((IData)(vlTOPp->PPU3__DOT__FF40) 
                                                                   << 1U)) 
                                                               + 
                                                               ((9U 
                                                                 >= (IData)(vlTOPp->PPU3__DOT__sp_to_fetch))
                                                                 ? 
                                                                vlTOPp->PPU3__DOT__sp_y_table
                                                                [vlTOPp->PPU3__DOT__sp_to_fetch]
                                                                 : 0U))) 
                                                             - (IData)(vlTOPp->PPU3__DOT__LY)) 
                                                            - (IData)(0x10U)) 
                                                           - (IData)(1U)) 
                                                          << 1U))))
                                                   : 
                                                  ((IData)(0x8000U) 
                                                   + 
                                                   ((((4U 
                                                       & (IData)(vlTOPp->PPU3__DOT__FF40))
                                                       ? 
                                                      (0xfeU 
                                                       & (IData)(vlTOPp->PPU3__DOT__SP_MAP))
                                                       : (IData)(vlTOPp->PPU3__DOT__SP_MAP)) 
                                                     << 4U) 
                                                    | (0x1eU 
                                                       & ((((IData)(0x10U) 
                                                            + (IData)(vlTOPp->PPU3__DOT__LY)) 
                                                           - 
                                                           ((9U 
                                                             >= (IData)(vlTOPp->PPU3__DOT__sp_to_fetch))
                                                             ? 
                                                            vlTOPp->PPU3__DOT__sp_y_table
                                                            [vlTOPp->PPU3__DOT__sp_to_fetch]
                                                             : 0U)) 
                                                          << 1U))))));
                                    } else {
                                        if (((4U == (IData)(vlTOPp->PPU3__DOT__SP_CNT)) 
                                             | (5U 
                                                == (IData)(vlTOPp->PPU3__DOT__SP_CNT)))) {
                                            vlTOPp->PPU_ADDR 
                                                = (0xffffU 
                                                   & ((0x40U 
                                                       & (IData)(vlTOPp->PPU3__DOT__SP_FLAG))
                                                       ? 
                                                      ((IData)(0x8001U) 
                                                       + 
                                                       ((((4U 
                                                           & (IData)(vlTOPp->PPU3__DOT__FF40))
                                                           ? 
                                                          (0xfeU 
                                                           & (IData)(vlTOPp->PPU3__DOT__SP_MAP))
                                                           : (IData)(vlTOPp->PPU3__DOT__SP_MAP)) 
                                                         << 4U) 
                                                        | (0x1eU 
                                                           & ((((((IData)(8U) 
                                                                  + 
                                                                  ((8U 
                                                                    & ((IData)(vlTOPp->PPU3__DOT__FF40) 
                                                                       << 1U)) 
                                                                   + 
                                                                   ((9U 
                                                                     >= (IData)(vlTOPp->PPU3__DOT__sp_to_fetch))
                                                                     ? 
                                                                    vlTOPp->PPU3__DOT__sp_y_table
                                                                    [vlTOPp->PPU3__DOT__sp_to_fetch]
                                                                     : 0U))) 
                                                                 - (IData)(vlTOPp->PPU3__DOT__LY)) 
                                                                - (IData)(0x10U)) 
                                                               - (IData)(1U)) 
                                                              << 1U))))
                                                       : 
                                                      ((IData)(0x8001U) 
                                                       + 
                                                       ((((4U 
                                                           & (IData)(vlTOPp->PPU3__DOT__FF40))
                                                           ? 
                                                          (0xfeU 
                                                           & (IData)(vlTOPp->PPU3__DOT__SP_MAP))
                                                           : (IData)(vlTOPp->PPU3__DOT__SP_MAP)) 
                                                         << 4U) 
                                                        | (0x1eU 
                                                           & ((((IData)(0x10U) 
                                                                + (IData)(vlTOPp->PPU3__DOT__LY)) 
                                                               - 
                                                               ((9U 
                                                                 >= (IData)(vlTOPp->PPU3__DOT__sp_to_fetch))
                                                                 ? 
                                                                vlTOPp->PPU3__DOT__sp_y_table
                                                                [vlTOPp->PPU3__DOT__sp_to_fetch]
                                                                 : 0U)) 
                                                              << 1U))))));
                                        }
                                    }
                                }
                            }
                            if ((5U == (IData)(vlTOPp->PPU3__DOT__SP_CNT))) {
                                vlTOPp->PPU3__DOT____Vlvbound4 = 0U;
                                vlTOPp->PPU3__DOT____Vlvbound5 = 1U;
                                vlTOPp->PPU3__DOT____Vlvbound6 
                                    = ((2U & ((IData)(vlTOPp->PPU3__DOT__SP_FLAG) 
                                              >> 6U)) 
                                       | (1U & ((IData)(vlTOPp->PPU3__DOT__SP_FLAG) 
                                                >> 4U)));
                                if ((9U >= (IData)(vlTOPp->PPU3__DOT__sp_to_fetch))) {
                                    vlTOPp->PPU3__DOT__sp_not_used_next 
                                        = (((~ ((IData)(1U) 
                                                << (IData)(vlTOPp->PPU3__DOT__sp_to_fetch))) 
                                            & (IData)(vlTOPp->PPU3__DOT__sp_not_used_next)) 
                                           | ((IData)(vlTOPp->PPU3__DOT____Vlvbound4) 
                                              << (IData)(vlTOPp->PPU3__DOT__sp_to_fetch)));
                                }
                                if ((9U >= (IData)(vlTOPp->PPU3__DOT__SP_NEXT_SLOT))) {
                                    vlTOPp->PPU3__DOT__SP_SHIFT_REG_LOAD 
                                        = (((~ ((IData)(1U) 
                                                << (IData)(vlTOPp->PPU3__DOT__SP_NEXT_SLOT))) 
                                            & (IData)(vlTOPp->PPU3__DOT__SP_SHIFT_REG_LOAD)) 
                                           | ((IData)(vlTOPp->PPU3__DOT____Vlvbound5) 
                                              << (IData)(vlTOPp->PPU3__DOT__SP_NEXT_SLOT)));
                                }
                                if ((9U >= (IData)(vlTOPp->PPU3__DOT__SP_NEXT_SLOT))) {
                                    vlTOPp->PPU3__DOT__SP_PRIPN_NEXT[vlTOPp->PPU3__DOT__SP_NEXT_SLOT] 
                                        = vlTOPp->PPU3__DOT____Vlvbound6;
                                }
                                vlTOPp->PPU3__DOT__SP_NEXT_SLOT_NEXT 
                                    = (0xfU & ((IData)(1U) 
                                               + (IData)(vlTOPp->PPU3__DOT__SP_NEXT_SLOT)));
                            }
                        }
                    }
                }
                if (((((IData)(vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_A_VALID) 
                       | (IData)(vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_B_VALID)) 
                      & (~ (IData)(vlTOPp->PPU3__DOT__isHitSP))) 
                     & (~ ((IData)(vlTOPp->PPU3__DOT__isHitWD) 
                           & (~ (IData)(vlTOPp->PPU3__DOT__isFetchWD)))))) {
                    vlTOPp->PPU3__DOT__RENDER_CNT_NEXT 
                        = (7U & ((IData)(1U) + (IData)(vlTOPp->PPU3__DOT__RENDER_CNT)));
                    vlTOPp->PPU3__DOT__SHIFT_REG_GO = 1U;
                    if (((IData)(vlTOPp->PPU3__DOT__SCX_CNT) 
                         != (7U & (IData)(vlTOPp->PPU3__DOT__FF43)))) {
                        vlTOPp->PPU3__DOT__SCX_CNT_NEXT 
                            = (7U & ((IData)(1U) + (IData)(vlTOPp->PPU3__DOT__SCX_CNT)));
                    } else {
                        vlTOPp->PPU3__DOT__LX_NEXT 
                            = (0xffU & ((IData)(1U) 
                                        + (IData)(vlTOPp->PPU3__DOT__LX)));
                        if ((8U <= (IData)(vlTOPp->PPU3__DOT__LX))) {
                            vlTOPp->PX_valid = 1U;
                        }
                    }
                    if ((7U == (IData)(vlTOPp->PPU3__DOT__RENDER_CNT))) {
                        vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_SEL_NEXT 
                            = (1U & (~ (IData)(vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_SEL)));
                        if (vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_SEL) {
                            vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_B_VALID_NEXT = 0U;
                        } else {
                            vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_A_VALID_NEXT = 0U;
                        }
                    }
                }
                if ((0xa8U == (IData)(vlTOPp->PPU3__DOT__LX_NEXT))) {
                    vlTOPp->PPU3__DOT__PPU_STATE_NEXT = 2U;
                    vlTOPp->PPU3__DOT__isFetchWD_NEXT = 0U;
                    vlTOPp->PPU3__DOT__FIRST_FETCH_WD_DONE_NEXT = 0U;
                    vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_A_VALID_NEXT = 0U;
                    vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_B_VALID_NEXT = 0U;
                    vlTOPp->PPU3__DOT__RENDER_CNT_NEXT = 0U;
                    vlTOPp->PPU3__DOT__sp_not_used_next = 0x3ffU;
                    vlTOPp->PPU3__DOT__SP_NEXT_SLOT_NEXT = 0U;
                    vlTOPp->PPU3__DOT__SCX_CNT_NEXT = 0U;
                }
            } else {
                if ((2U == vlTOPp->PPU3__DOT__PPU_STATE)) {
                    if ((0x1c7U == (IData)(vlTOPp->PPU3__DOT__PPU_CNT))) {
                        vlTOPp->PPU3__DOT__LY_NEXT 
                            = (0xffU & ((IData)(1U) 
                                        + (IData)(vlTOPp->PPU3__DOT__LY)));
                        vlTOPp->PPU3__DOT__LX_NEXT = 0U;
                        vlTOPp->PPU3__DOT__PPU_STATE_NEXT = 0U;
                        if ((0x90U == (IData)(vlTOPp->PPU3__DOT__LY_NEXT))) {
                            vlTOPp->PPU3__DOT__PPU_STATE_NEXT = 3U;
                            vlTOPp->IRQ_V_BLANK = 1U;
                        }
                    }
                } else {
                    if ((3U == vlTOPp->PPU3__DOT__PPU_STATE)) {
                        if ((0x99U == (IData)(vlTOPp->PPU3__DOT__LY))) {
                            vlTOPp->PPU3__DOT__LY_NEXT = 0U;
                            vlTOPp->PPU3__DOT__LX_NEXT = 0U;
                        }
                        if (((0x1c7U == (IData)(vlTOPp->PPU3__DOT__PPU_CNT)) 
                             & (0U == (IData)(vlTOPp->PPU3__DOT__LY)))) {
                            vlTOPp->PPU3__DOT__PPU_STATE_NEXT = 0U;
                        }
                        if (((0x1c7U == (IData)(vlTOPp->PPU3__DOT__PPU_CNT)) 
                             & (0U != (IData)(vlTOPp->PPU3__DOT__LY)))) {
                            vlTOPp->PPU3__DOT__LY_NEXT 
                                = (0xffU & ((IData)(1U) 
                                            + (IData)(vlTOPp->PPU3__DOT__LY)));
                        }
                    }
                }
            }
        }
    } else {
        vlTOPp->PPU3__DOT__LY_NEXT = 0U;
        vlTOPp->PPU3__DOT__LX_NEXT = 0U;
        vlTOPp->PPU3__DOT__PPU_STATE_NEXT = 0U;
    }
    vlTOPp->PX_OUT = vlTOPp->PPU3__DOT__BGWD_PX_DATA;
    if ((2U & (IData)(vlTOPp->PPU3__DOT__FF40))) {
        if (((vlTOPp->PPU3__DOT__SP_PRIPN[9U] >> 1U) 
             & (0U != vlTOPp->PPU3__DOT__SP_PX_MAP[9U]))) {
            vlTOPp->PX_OUT = ((1U & vlTOPp->PPU3__DOT__SP_PRIPN
                               [9U]) ? ((2U & (((0xfcU 
                                                 & (IData)(vlTOPp->PPU3__DOT__FF49)) 
                                                >> 
                                                (1U 
                                                 | (vlTOPp->PPU3__DOT__SP_PX_MAP
                                                    [9U] 
                                                    << 1U))) 
                                               << 1U)) 
                                        | (1U & ((0xfcU 
                                                  & (IData)(vlTOPp->PPU3__DOT__FF49)) 
                                                 >> 
                                                 (vlTOPp->PPU3__DOT__SP_PX_MAP
                                                  [9U] 
                                                  << 1U))))
                               : ((2U & (((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF48)) 
                                          >> (1U | 
                                              (vlTOPp->PPU3__DOT__SP_PX_MAP
                                               [9U] 
                                               << 1U))) 
                                         << 1U)) | 
                                  (1U & ((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF48)) 
                                         >> (vlTOPp->PPU3__DOT__SP_PX_MAP
                                             [9U] << 1U)))));
        }
        if (((vlTOPp->PPU3__DOT__SP_PRIPN[8U] >> 1U) 
             & (0U != vlTOPp->PPU3__DOT__SP_PX_MAP[8U]))) {
            vlTOPp->PX_OUT = ((1U & vlTOPp->PPU3__DOT__SP_PRIPN
                               [8U]) ? ((2U & (((0xfcU 
                                                 & (IData)(vlTOPp->PPU3__DOT__FF49)) 
                                                >> 
                                                (1U 
                                                 | (vlTOPp->PPU3__DOT__SP_PX_MAP
                                                    [8U] 
                                                    << 1U))) 
                                               << 1U)) 
                                        | (1U & ((0xfcU 
                                                  & (IData)(vlTOPp->PPU3__DOT__FF49)) 
                                                 >> 
                                                 (vlTOPp->PPU3__DOT__SP_PX_MAP
                                                  [8U] 
                                                  << 1U))))
                               : ((2U & (((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF48)) 
                                          >> (1U | 
                                              (vlTOPp->PPU3__DOT__SP_PX_MAP
                                               [8U] 
                                               << 1U))) 
                                         << 1U)) | 
                                  (1U & ((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF48)) 
                                         >> (vlTOPp->PPU3__DOT__SP_PX_MAP
                                             [8U] << 1U)))));
        }
        if (((vlTOPp->PPU3__DOT__SP_PRIPN[7U] >> 1U) 
             & (0U != vlTOPp->PPU3__DOT__SP_PX_MAP[7U]))) {
            vlTOPp->PX_OUT = ((1U & vlTOPp->PPU3__DOT__SP_PRIPN
                               [7U]) ? ((2U & (((0xfcU 
                                                 & (IData)(vlTOPp->PPU3__DOT__FF49)) 
                                                >> 
                                                (1U 
                                                 | (vlTOPp->PPU3__DOT__SP_PX_MAP
                                                    [7U] 
                                                    << 1U))) 
                                               << 1U)) 
                                        | (1U & ((0xfcU 
                                                  & (IData)(vlTOPp->PPU3__DOT__FF49)) 
                                                 >> 
                                                 (vlTOPp->PPU3__DOT__SP_PX_MAP
                                                  [7U] 
                                                  << 1U))))
                               : ((2U & (((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF48)) 
                                          >> (1U | 
                                              (vlTOPp->PPU3__DOT__SP_PX_MAP
                                               [7U] 
                                               << 1U))) 
                                         << 1U)) | 
                                  (1U & ((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF48)) 
                                         >> (vlTOPp->PPU3__DOT__SP_PX_MAP
                                             [7U] << 1U)))));
        }
        if (((vlTOPp->PPU3__DOT__SP_PRIPN[6U] >> 1U) 
             & (0U != vlTOPp->PPU3__DOT__SP_PX_MAP[6U]))) {
            vlTOPp->PX_OUT = ((1U & vlTOPp->PPU3__DOT__SP_PRIPN
                               [6U]) ? ((2U & (((0xfcU 
                                                 & (IData)(vlTOPp->PPU3__DOT__FF49)) 
                                                >> 
                                                (1U 
                                                 | (vlTOPp->PPU3__DOT__SP_PX_MAP
                                                    [6U] 
                                                    << 1U))) 
                                               << 1U)) 
                                        | (1U & ((0xfcU 
                                                  & (IData)(vlTOPp->PPU3__DOT__FF49)) 
                                                 >> 
                                                 (vlTOPp->PPU3__DOT__SP_PX_MAP
                                                  [6U] 
                                                  << 1U))))
                               : ((2U & (((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF48)) 
                                          >> (1U | 
                                              (vlTOPp->PPU3__DOT__SP_PX_MAP
                                               [6U] 
                                               << 1U))) 
                                         << 1U)) | 
                                  (1U & ((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF48)) 
                                         >> (vlTOPp->PPU3__DOT__SP_PX_MAP
                                             [6U] << 1U)))));
        }
        if (((vlTOPp->PPU3__DOT__SP_PRIPN[5U] >> 1U) 
             & (0U != vlTOPp->PPU3__DOT__SP_PX_MAP[5U]))) {
            vlTOPp->PX_OUT = ((1U & vlTOPp->PPU3__DOT__SP_PRIPN
                               [5U]) ? ((2U & (((0xfcU 
                                                 & (IData)(vlTOPp->PPU3__DOT__FF49)) 
                                                >> 
                                                (1U 
                                                 | (vlTOPp->PPU3__DOT__SP_PX_MAP
                                                    [5U] 
                                                    << 1U))) 
                                               << 1U)) 
                                        | (1U & ((0xfcU 
                                                  & (IData)(vlTOPp->PPU3__DOT__FF49)) 
                                                 >> 
                                                 (vlTOPp->PPU3__DOT__SP_PX_MAP
                                                  [5U] 
                                                  << 1U))))
                               : ((2U & (((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF48)) 
                                          >> (1U | 
                                              (vlTOPp->PPU3__DOT__SP_PX_MAP
                                               [5U] 
                                               << 1U))) 
                                         << 1U)) | 
                                  (1U & ((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF48)) 
                                         >> (vlTOPp->PPU3__DOT__SP_PX_MAP
                                             [5U] << 1U)))));
        }
        if (((vlTOPp->PPU3__DOT__SP_PRIPN[4U] >> 1U) 
             & (0U != vlTOPp->PPU3__DOT__SP_PX_MAP[4U]))) {
            vlTOPp->PX_OUT = ((1U & vlTOPp->PPU3__DOT__SP_PRIPN
                               [4U]) ? ((2U & (((0xfcU 
                                                 & (IData)(vlTOPp->PPU3__DOT__FF49)) 
                                                >> 
                                                (1U 
                                                 | (vlTOPp->PPU3__DOT__SP_PX_MAP
                                                    [4U] 
                                                    << 1U))) 
                                               << 1U)) 
                                        | (1U & ((0xfcU 
                                                  & (IData)(vlTOPp->PPU3__DOT__FF49)) 
                                                 >> 
                                                 (vlTOPp->PPU3__DOT__SP_PX_MAP
                                                  [4U] 
                                                  << 1U))))
                               : ((2U & (((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF48)) 
                                          >> (1U | 
                                              (vlTOPp->PPU3__DOT__SP_PX_MAP
                                               [4U] 
                                               << 1U))) 
                                         << 1U)) | 
                                  (1U & ((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF48)) 
                                         >> (vlTOPp->PPU3__DOT__SP_PX_MAP
                                             [4U] << 1U)))));
        }
        if (((vlTOPp->PPU3__DOT__SP_PRIPN[3U] >> 1U) 
             & (0U != vlTOPp->PPU3__DOT__SP_PX_MAP[3U]))) {
            vlTOPp->PX_OUT = ((1U & vlTOPp->PPU3__DOT__SP_PRIPN
                               [3U]) ? ((2U & (((0xfcU 
                                                 & (IData)(vlTOPp->PPU3__DOT__FF49)) 
                                                >> 
                                                (1U 
                                                 | (vlTOPp->PPU3__DOT__SP_PX_MAP
                                                    [3U] 
                                                    << 1U))) 
                                               << 1U)) 
                                        | (1U & ((0xfcU 
                                                  & (IData)(vlTOPp->PPU3__DOT__FF49)) 
                                                 >> 
                                                 (vlTOPp->PPU3__DOT__SP_PX_MAP
                                                  [3U] 
                                                  << 1U))))
                               : ((2U & (((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF48)) 
                                          >> (1U | 
                                              (vlTOPp->PPU3__DOT__SP_PX_MAP
                                               [3U] 
                                               << 1U))) 
                                         << 1U)) | 
                                  (1U & ((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF48)) 
                                         >> (vlTOPp->PPU3__DOT__SP_PX_MAP
                                             [3U] << 1U)))));
        }
        if (((vlTOPp->PPU3__DOT__SP_PRIPN[2U] >> 1U) 
             & (0U != vlTOPp->PPU3__DOT__SP_PX_MAP[2U]))) {
            vlTOPp->PX_OUT = ((1U & vlTOPp->PPU3__DOT__SP_PRIPN
                               [2U]) ? ((2U & (((0xfcU 
                                                 & (IData)(vlTOPp->PPU3__DOT__FF49)) 
                                                >> 
                                                (1U 
                                                 | (vlTOPp->PPU3__DOT__SP_PX_MAP
                                                    [2U] 
                                                    << 1U))) 
                                               << 1U)) 
                                        | (1U & ((0xfcU 
                                                  & (IData)(vlTOPp->PPU3__DOT__FF49)) 
                                                 >> 
                                                 (vlTOPp->PPU3__DOT__SP_PX_MAP
                                                  [2U] 
                                                  << 1U))))
                               : ((2U & (((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF48)) 
                                          >> (1U | 
                                              (vlTOPp->PPU3__DOT__SP_PX_MAP
                                               [2U] 
                                               << 1U))) 
                                         << 1U)) | 
                                  (1U & ((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF48)) 
                                         >> (vlTOPp->PPU3__DOT__SP_PX_MAP
                                             [2U] << 1U)))));
        }
        if (((vlTOPp->PPU3__DOT__SP_PRIPN[1U] >> 1U) 
             & (0U != vlTOPp->PPU3__DOT__SP_PX_MAP[1U]))) {
            vlTOPp->PX_OUT = ((1U & vlTOPp->PPU3__DOT__SP_PRIPN
                               [1U]) ? ((2U & (((0xfcU 
                                                 & (IData)(vlTOPp->PPU3__DOT__FF49)) 
                                                >> 
                                                (1U 
                                                 | (vlTOPp->PPU3__DOT__SP_PX_MAP
                                                    [1U] 
                                                    << 1U))) 
                                               << 1U)) 
                                        | (1U & ((0xfcU 
                                                  & (IData)(vlTOPp->PPU3__DOT__FF49)) 
                                                 >> 
                                                 (vlTOPp->PPU3__DOT__SP_PX_MAP
                                                  [1U] 
                                                  << 1U))))
                               : ((2U & (((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF48)) 
                                          >> (1U | 
                                              (vlTOPp->PPU3__DOT__SP_PX_MAP
                                               [1U] 
                                               << 1U))) 
                                         << 1U)) | 
                                  (1U & ((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF48)) 
                                         >> (vlTOPp->PPU3__DOT__SP_PX_MAP
                                             [1U] << 1U)))));
        }
        if (((vlTOPp->PPU3__DOT__SP_PRIPN[0U] >> 1U) 
             & (0U != vlTOPp->PPU3__DOT__SP_PX_MAP[0U]))) {
            vlTOPp->PX_OUT = ((1U & vlTOPp->PPU3__DOT__SP_PRIPN
                               [0U]) ? ((2U & (((0xfcU 
                                                 & (IData)(vlTOPp->PPU3__DOT__FF49)) 
                                                >> 
                                                (1U 
                                                 | (vlTOPp->PPU3__DOT__SP_PX_MAP
                                                    [0U] 
                                                    << 1U))) 
                                               << 1U)) 
                                        | (1U & ((0xfcU 
                                                  & (IData)(vlTOPp->PPU3__DOT__FF49)) 
                                                 >> 
                                                 (vlTOPp->PPU3__DOT__SP_PX_MAP
                                                  [0U] 
                                                  << 1U))))
                               : ((2U & (((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF48)) 
                                          >> (1U | 
                                              (vlTOPp->PPU3__DOT__SP_PX_MAP
                                               [0U] 
                                               << 1U))) 
                                         << 1U)) | 
                                  (1U & ((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF48)) 
                                         >> (vlTOPp->PPU3__DOT__SP_PX_MAP
                                             [0U] << 1U)))));
        }
    }
    if ((1U & (IData)(vlTOPp->PPU3__DOT__FF40))) {
        vlTOPp->PX_OUT = ((0U == (IData)(vlTOPp->PPU3__DOT__BGWD_PX_MAP))
                           ? (IData)(vlTOPp->PX_OUT)
                           : (IData)(vlTOPp->PPU3__DOT__BGWD_PX_DATA));
    }
    if ((2U & (IData)(vlTOPp->PPU3__DOT__FF40))) {
        if (((~ (vlTOPp->PPU3__DOT__SP_PRIPN[9U] >> 1U)) 
             & (0U != vlTOPp->PPU3__DOT__SP_PX_MAP[9U]))) {
            vlTOPp->PX_OUT = ((1U & vlTOPp->PPU3__DOT__SP_PRIPN
                               [9U]) ? ((2U & (((0xfcU 
                                                 & (IData)(vlTOPp->PPU3__DOT__FF49)) 
                                                >> 
                                                (1U 
                                                 | (vlTOPp->PPU3__DOT__SP_PX_MAP
                                                    [9U] 
                                                    << 1U))) 
                                               << 1U)) 
                                        | (1U & ((0xfcU 
                                                  & (IData)(vlTOPp->PPU3__DOT__FF49)) 
                                                 >> 
                                                 (vlTOPp->PPU3__DOT__SP_PX_MAP
                                                  [9U] 
                                                  << 1U))))
                               : ((2U & (((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF48)) 
                                          >> (1U | 
                                              (vlTOPp->PPU3__DOT__SP_PX_MAP
                                               [9U] 
                                               << 1U))) 
                                         << 1U)) | 
                                  (1U & ((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF48)) 
                                         >> (vlTOPp->PPU3__DOT__SP_PX_MAP
                                             [9U] << 1U)))));
        }
        if (((~ (vlTOPp->PPU3__DOT__SP_PRIPN[8U] >> 1U)) 
             & (0U != vlTOPp->PPU3__DOT__SP_PX_MAP[8U]))) {
            vlTOPp->PX_OUT = ((1U & vlTOPp->PPU3__DOT__SP_PRIPN
                               [8U]) ? ((2U & (((0xfcU 
                                                 & (IData)(vlTOPp->PPU3__DOT__FF49)) 
                                                >> 
                                                (1U 
                                                 | (vlTOPp->PPU3__DOT__SP_PX_MAP
                                                    [8U] 
                                                    << 1U))) 
                                               << 1U)) 
                                        | (1U & ((0xfcU 
                                                  & (IData)(vlTOPp->PPU3__DOT__FF49)) 
                                                 >> 
                                                 (vlTOPp->PPU3__DOT__SP_PX_MAP
                                                  [8U] 
                                                  << 1U))))
                               : ((2U & (((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF48)) 
                                          >> (1U | 
                                              (vlTOPp->PPU3__DOT__SP_PX_MAP
                                               [8U] 
                                               << 1U))) 
                                         << 1U)) | 
                                  (1U & ((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF48)) 
                                         >> (vlTOPp->PPU3__DOT__SP_PX_MAP
                                             [8U] << 1U)))));
        }
        if (((~ (vlTOPp->PPU3__DOT__SP_PRIPN[7U] >> 1U)) 
             & (0U != vlTOPp->PPU3__DOT__SP_PX_MAP[7U]))) {
            vlTOPp->PX_OUT = ((1U & vlTOPp->PPU3__DOT__SP_PRIPN
                               [7U]) ? ((2U & (((0xfcU 
                                                 & (IData)(vlTOPp->PPU3__DOT__FF49)) 
                                                >> 
                                                (1U 
                                                 | (vlTOPp->PPU3__DOT__SP_PX_MAP
                                                    [7U] 
                                                    << 1U))) 
                                               << 1U)) 
                                        | (1U & ((0xfcU 
                                                  & (IData)(vlTOPp->PPU3__DOT__FF49)) 
                                                 >> 
                                                 (vlTOPp->PPU3__DOT__SP_PX_MAP
                                                  [7U] 
                                                  << 1U))))
                               : ((2U & (((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF48)) 
                                          >> (1U | 
                                              (vlTOPp->PPU3__DOT__SP_PX_MAP
                                               [7U] 
                                               << 1U))) 
                                         << 1U)) | 
                                  (1U & ((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF48)) 
                                         >> (vlTOPp->PPU3__DOT__SP_PX_MAP
                                             [7U] << 1U)))));
        }
        if (((~ (vlTOPp->PPU3__DOT__SP_PRIPN[6U] >> 1U)) 
             & (0U != vlTOPp->PPU3__DOT__SP_PX_MAP[6U]))) {
            vlTOPp->PX_OUT = ((1U & vlTOPp->PPU3__DOT__SP_PRIPN
                               [6U]) ? ((2U & (((0xfcU 
                                                 & (IData)(vlTOPp->PPU3__DOT__FF49)) 
                                                >> 
                                                (1U 
                                                 | (vlTOPp->PPU3__DOT__SP_PX_MAP
                                                    [6U] 
                                                    << 1U))) 
                                               << 1U)) 
                                        | (1U & ((0xfcU 
                                                  & (IData)(vlTOPp->PPU3__DOT__FF49)) 
                                                 >> 
                                                 (vlTOPp->PPU3__DOT__SP_PX_MAP
                                                  [6U] 
                                                  << 1U))))
                               : ((2U & (((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF48)) 
                                          >> (1U | 
                                              (vlTOPp->PPU3__DOT__SP_PX_MAP
                                               [6U] 
                                               << 1U))) 
                                         << 1U)) | 
                                  (1U & ((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF48)) 
                                         >> (vlTOPp->PPU3__DOT__SP_PX_MAP
                                             [6U] << 1U)))));
        }
        if (((~ (vlTOPp->PPU3__DOT__SP_PRIPN[5U] >> 1U)) 
             & (0U != vlTOPp->PPU3__DOT__SP_PX_MAP[5U]))) {
            vlTOPp->PX_OUT = ((1U & vlTOPp->PPU3__DOT__SP_PRIPN
                               [5U]) ? ((2U & (((0xfcU 
                                                 & (IData)(vlTOPp->PPU3__DOT__FF49)) 
                                                >> 
                                                (1U 
                                                 | (vlTOPp->PPU3__DOT__SP_PX_MAP
                                                    [5U] 
                                                    << 1U))) 
                                               << 1U)) 
                                        | (1U & ((0xfcU 
                                                  & (IData)(vlTOPp->PPU3__DOT__FF49)) 
                                                 >> 
                                                 (vlTOPp->PPU3__DOT__SP_PX_MAP
                                                  [5U] 
                                                  << 1U))))
                               : ((2U & (((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF48)) 
                                          >> (1U | 
                                              (vlTOPp->PPU3__DOT__SP_PX_MAP
                                               [5U] 
                                               << 1U))) 
                                         << 1U)) | 
                                  (1U & ((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF48)) 
                                         >> (vlTOPp->PPU3__DOT__SP_PX_MAP
                                             [5U] << 1U)))));
        }
        if (((~ (vlTOPp->PPU3__DOT__SP_PRIPN[4U] >> 1U)) 
             & (0U != vlTOPp->PPU3__DOT__SP_PX_MAP[4U]))) {
            vlTOPp->PX_OUT = ((1U & vlTOPp->PPU3__DOT__SP_PRIPN
                               [4U]) ? ((2U & (((0xfcU 
                                                 & (IData)(vlTOPp->PPU3__DOT__FF49)) 
                                                >> 
                                                (1U 
                                                 | (vlTOPp->PPU3__DOT__SP_PX_MAP
                                                    [4U] 
                                                    << 1U))) 
                                               << 1U)) 
                                        | (1U & ((0xfcU 
                                                  & (IData)(vlTOPp->PPU3__DOT__FF49)) 
                                                 >> 
                                                 (vlTOPp->PPU3__DOT__SP_PX_MAP
                                                  [4U] 
                                                  << 1U))))
                               : ((2U & (((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF48)) 
                                          >> (1U | 
                                              (vlTOPp->PPU3__DOT__SP_PX_MAP
                                               [4U] 
                                               << 1U))) 
                                         << 1U)) | 
                                  (1U & ((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF48)) 
                                         >> (vlTOPp->PPU3__DOT__SP_PX_MAP
                                             [4U] << 1U)))));
        }
        if (((~ (vlTOPp->PPU3__DOT__SP_PRIPN[3U] >> 1U)) 
             & (0U != vlTOPp->PPU3__DOT__SP_PX_MAP[3U]))) {
            vlTOPp->PX_OUT = ((1U & vlTOPp->PPU3__DOT__SP_PRIPN
                               [3U]) ? ((2U & (((0xfcU 
                                                 & (IData)(vlTOPp->PPU3__DOT__FF49)) 
                                                >> 
                                                (1U 
                                                 | (vlTOPp->PPU3__DOT__SP_PX_MAP
                                                    [3U] 
                                                    << 1U))) 
                                               << 1U)) 
                                        | (1U & ((0xfcU 
                                                  & (IData)(vlTOPp->PPU3__DOT__FF49)) 
                                                 >> 
                                                 (vlTOPp->PPU3__DOT__SP_PX_MAP
                                                  [3U] 
                                                  << 1U))))
                               : ((2U & (((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF48)) 
                                          >> (1U | 
                                              (vlTOPp->PPU3__DOT__SP_PX_MAP
                                               [3U] 
                                               << 1U))) 
                                         << 1U)) | 
                                  (1U & ((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF48)) 
                                         >> (vlTOPp->PPU3__DOT__SP_PX_MAP
                                             [3U] << 1U)))));
        }
        if (((~ (vlTOPp->PPU3__DOT__SP_PRIPN[2U] >> 1U)) 
             & (0U != vlTOPp->PPU3__DOT__SP_PX_MAP[2U]))) {
            vlTOPp->PX_OUT = ((1U & vlTOPp->PPU3__DOT__SP_PRIPN
                               [2U]) ? ((2U & (((0xfcU 
                                                 & (IData)(vlTOPp->PPU3__DOT__FF49)) 
                                                >> 
                                                (1U 
                                                 | (vlTOPp->PPU3__DOT__SP_PX_MAP
                                                    [2U] 
                                                    << 1U))) 
                                               << 1U)) 
                                        | (1U & ((0xfcU 
                                                  & (IData)(vlTOPp->PPU3__DOT__FF49)) 
                                                 >> 
                                                 (vlTOPp->PPU3__DOT__SP_PX_MAP
                                                  [2U] 
                                                  << 1U))))
                               : ((2U & (((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF48)) 
                                          >> (1U | 
                                              (vlTOPp->PPU3__DOT__SP_PX_MAP
                                               [2U] 
                                               << 1U))) 
                                         << 1U)) | 
                                  (1U & ((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF48)) 
                                         >> (vlTOPp->PPU3__DOT__SP_PX_MAP
                                             [2U] << 1U)))));
        }
        if (((~ (vlTOPp->PPU3__DOT__SP_PRIPN[1U] >> 1U)) 
             & (0U != vlTOPp->PPU3__DOT__SP_PX_MAP[1U]))) {
            vlTOPp->PX_OUT = ((1U & vlTOPp->PPU3__DOT__SP_PRIPN
                               [1U]) ? ((2U & (((0xfcU 
                                                 & (IData)(vlTOPp->PPU3__DOT__FF49)) 
                                                >> 
                                                (1U 
                                                 | (vlTOPp->PPU3__DOT__SP_PX_MAP
                                                    [1U] 
                                                    << 1U))) 
                                               << 1U)) 
                                        | (1U & ((0xfcU 
                                                  & (IData)(vlTOPp->PPU3__DOT__FF49)) 
                                                 >> 
                                                 (vlTOPp->PPU3__DOT__SP_PX_MAP
                                                  [1U] 
                                                  << 1U))))
                               : ((2U & (((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF48)) 
                                          >> (1U | 
                                              (vlTOPp->PPU3__DOT__SP_PX_MAP
                                               [1U] 
                                               << 1U))) 
                                         << 1U)) | 
                                  (1U & ((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF48)) 
                                         >> (vlTOPp->PPU3__DOT__SP_PX_MAP
                                             [1U] << 1U)))));
        }
        if (((~ (vlTOPp->PPU3__DOT__SP_PRIPN[0U] >> 1U)) 
             & (0U != vlTOPp->PPU3__DOT__SP_PX_MAP[0U]))) {
            vlTOPp->PX_OUT = ((1U & vlTOPp->PPU3__DOT__SP_PRIPN
                               [0U]) ? ((2U & (((0xfcU 
                                                 & (IData)(vlTOPp->PPU3__DOT__FF49)) 
                                                >> 
                                                (1U 
                                                 | (vlTOPp->PPU3__DOT__SP_PX_MAP
                                                    [0U] 
                                                    << 1U))) 
                                               << 1U)) 
                                        | (1U & ((0xfcU 
                                                  & (IData)(vlTOPp->PPU3__DOT__FF49)) 
                                                 >> 
                                                 (vlTOPp->PPU3__DOT__SP_PX_MAP
                                                  [0U] 
                                                  << 1U))))
                               : ((2U & (((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF48)) 
                                          >> (1U | 
                                              (vlTOPp->PPU3__DOT__SP_PX_MAP
                                               [0U] 
                                               << 1U))) 
                                         << 1U)) | 
                                  (1U & ((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF48)) 
                                         >> (vlTOPp->PPU3__DOT__SP_PX_MAP
                                             [0U] << 1U)))));
        }
    }
}

void VPPU3::_settle__TOP__2(VPPU3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPPU3::_settle__TOP__2\n"); );
    VPPU3* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->PPU3__DOT____Vcellinp__SP_SHIFT_REG9__data[1U] 
        = (0xffU & (IData)(vlTOPp->PPU3__DOT__SP_TILE_DATA1));
    vlTOPp->PPU3__DOT____Vcellinp__SP_SHIFT_REG9__data[0U] 
        = (0xffU & (IData)(vlTOPp->PPU3__DOT__SP_TILE_DATA0));
    vlTOPp->PPU3__DOT____Vcellinp__SP_SHIFT_REG8__data[1U] 
        = (0xffU & (IData)(vlTOPp->PPU3__DOT__SP_TILE_DATA1));
    vlTOPp->PPU3__DOT____Vcellinp__SP_SHIFT_REG8__data[0U] 
        = (0xffU & (IData)(vlTOPp->PPU3__DOT__SP_TILE_DATA0));
    vlTOPp->PPU3__DOT____Vcellinp__SP_SHIFT_REG7__data[1U] 
        = (0xffU & (IData)(vlTOPp->PPU3__DOT__SP_TILE_DATA1));
    vlTOPp->PPU3__DOT____Vcellinp__SP_SHIFT_REG7__data[0U] 
        = (0xffU & (IData)(vlTOPp->PPU3__DOT__SP_TILE_DATA0));
    vlTOPp->PPU3__DOT____Vcellinp__SP_SHIFT_REG6__data[1U] 
        = (0xffU & (IData)(vlTOPp->PPU3__DOT__SP_TILE_DATA1));
    vlTOPp->PPU3__DOT____Vcellinp__SP_SHIFT_REG6__data[0U] 
        = (0xffU & (IData)(vlTOPp->PPU3__DOT__SP_TILE_DATA0));
    vlTOPp->PPU3__DOT____Vcellinp__SP_SHIFT_REG5__data[1U] 
        = (0xffU & (IData)(vlTOPp->PPU3__DOT__SP_TILE_DATA1));
    vlTOPp->PPU3__DOT____Vcellinp__SP_SHIFT_REG5__data[0U] 
        = (0xffU & (IData)(vlTOPp->PPU3__DOT__SP_TILE_DATA0));
    vlTOPp->PPU3__DOT____Vcellinp__SP_SHIFT_REG4__data[1U] 
        = (0xffU & (IData)(vlTOPp->PPU3__DOT__SP_TILE_DATA1));
    vlTOPp->PPU3__DOT____Vcellinp__SP_SHIFT_REG4__data[0U] 
        = (0xffU & (IData)(vlTOPp->PPU3__DOT__SP_TILE_DATA0));
    vlTOPp->PPU3__DOT____Vcellinp__SP_SHIFT_REG3__data[1U] 
        = (0xffU & (IData)(vlTOPp->PPU3__DOT__SP_TILE_DATA1));
    vlTOPp->PPU3__DOT____Vcellinp__SP_SHIFT_REG3__data[0U] 
        = (0xffU & (IData)(vlTOPp->PPU3__DOT__SP_TILE_DATA0));
    vlTOPp->PPU3__DOT____Vcellinp__SP_SHIFT_REG2__data[1U] 
        = (0xffU & (IData)(vlTOPp->PPU3__DOT__SP_TILE_DATA1));
    vlTOPp->PPU3__DOT____Vcellinp__SP_SHIFT_REG2__data[0U] 
        = (0xffU & (IData)(vlTOPp->PPU3__DOT__SP_TILE_DATA0));
    vlTOPp->PPU3__DOT____Vcellinp__SP_SHIFT_REG1__data[1U] 
        = (0xffU & (IData)(vlTOPp->PPU3__DOT__SP_TILE_DATA1));
    vlTOPp->PPU3__DOT____Vcellinp__SP_SHIFT_REG1__data[0U] 
        = (0xffU & (IData)(vlTOPp->PPU3__DOT__SP_TILE_DATA0));
    vlTOPp->PPU3__DOT____Vcellinp__SP_SHIFT_REG0__data[1U] 
        = (0xffU & (IData)(vlTOPp->PPU3__DOT__SP_TILE_DATA1));
    vlTOPp->PPU3__DOT____Vcellinp__SP_SHIFT_REG0__data[0U] 
        = (0xffU & (IData)(vlTOPp->PPU3__DOT__SP_TILE_DATA0));
    vlTOPp->PPU3__DOT____Vcellinp__BGWD_SHIFT_REG_A__data[1U] 
        = vlTOPp->PPU3__DOT__BGWD_TILE_DATA1;
    vlTOPp->PPU3__DOT____Vcellinp__BGWD_SHIFT_REG_A__data[0U] 
        = vlTOPp->PPU3__DOT__BGWD_TILE_DATA0;
    vlTOPp->PPU3__DOT____Vcellinp__BGWD_SHIFT_REG_B__data[1U] 
        = vlTOPp->PPU3__DOT__BGWD_TILE_DATA1;
    vlTOPp->PPU3__DOT____Vcellinp__BGWD_SHIFT_REG_B__data[0U] 
        = vlTOPp->PPU3__DOT__BGWD_TILE_DATA0;
    vlTOPp->PPU3__DOT__FF45_NEXT = (((IData)(vlTOPp->WR) 
                                     & (0xff45U == (IData)(vlTOPp->ADDR)))
                                     ? (IData)(vlTOPp->MMIO_DATA_out)
                                     : (IData)(vlTOPp->PPU3__DOT__FF45));
    vlTOPp->PPU3__DOT__FF43_NEXT = (((IData)(vlTOPp->WR) 
                                     & (0xff43U == (IData)(vlTOPp->ADDR)))
                                     ? (IData)(vlTOPp->MMIO_DATA_out)
                                     : (IData)(vlTOPp->PPU3__DOT__FF43));
    vlTOPp->PPU3__DOT__FF42_NEXT = (((IData)(vlTOPp->WR) 
                                     & (0xff42U == (IData)(vlTOPp->ADDR)))
                                     ? (IData)(vlTOPp->MMIO_DATA_out)
                                     : (IData)(vlTOPp->PPU3__DOT__FF42));
    vlTOPp->PPU3__DOT__FF46_NEXT = (((IData)(vlTOPp->WR) 
                                     & (0xff46U == (IData)(vlTOPp->ADDR)))
                                     ? (IData)(vlTOPp->MMIO_DATA_out)
                                     : (IData)(vlTOPp->PPU3__DOT__FF46));
    vlTOPp->PPU3__DOT__FF47_NEXT = (((IData)(vlTOPp->WR) 
                                     & (0xff47U == (IData)(vlTOPp->ADDR)))
                                     ? (IData)(vlTOPp->MMIO_DATA_out)
                                     : (IData)(vlTOPp->PPU3__DOT__FF47));
    vlTOPp->PPU3__DOT__FF48_NEXT = (((IData)(vlTOPp->WR) 
                                     & (0xff48U == (IData)(vlTOPp->ADDR)))
                                     ? (IData)(vlTOPp->MMIO_DATA_out)
                                     : (IData)(vlTOPp->PPU3__DOT__FF48));
    vlTOPp->PPU3__DOT__FF49_NEXT = (((IData)(vlTOPp->WR) 
                                     & (0xff49U == (IData)(vlTOPp->ADDR)))
                                     ? (IData)(vlTOPp->MMIO_DATA_out)
                                     : (IData)(vlTOPp->PPU3__DOT__FF49));
    vlTOPp->PPU3__DOT__FF4A_NEXT = (((IData)(vlTOPp->WR) 
                                     & (0xff4aU == (IData)(vlTOPp->ADDR)))
                                     ? (IData)(vlTOPp->MMIO_DATA_out)
                                     : (IData)(vlTOPp->PPU3__DOT__FF4A));
    vlTOPp->PPU3__DOT__FF4B_NEXT = (((IData)(vlTOPp->WR) 
                                     & (0xff4bU == (IData)(vlTOPp->ADDR)))
                                     ? (IData)(vlTOPp->MMIO_DATA_out)
                                     : (IData)(vlTOPp->PPU3__DOT__FF4B));
    vlTOPp->PPU3__DOT__SP_PX_MAP[9U] = ((2U & (vlTOPp->PPU3__DOT__SP_SHIFT_REG9__DOT__shift_reg
                                               [1U] 
                                               >> 6U)) 
                                        | (1U & (vlTOPp->PPU3__DOT__SP_SHIFT_REG9__DOT__shift_reg
                                                 [0U] 
                                                 >> 7U)));
    vlTOPp->PPU3__DOT__SP_PX_MAP[8U] = ((2U & (vlTOPp->PPU3__DOT__SP_SHIFT_REG8__DOT__shift_reg
                                               [1U] 
                                               >> 6U)) 
                                        | (1U & (vlTOPp->PPU3__DOT__SP_SHIFT_REG8__DOT__shift_reg
                                                 [0U] 
                                                 >> 7U)));
    vlTOPp->PPU3__DOT__SP_PX_MAP[7U] = ((2U & (vlTOPp->PPU3__DOT__SP_SHIFT_REG7__DOT__shift_reg
                                               [1U] 
                                               >> 6U)) 
                                        | (1U & (vlTOPp->PPU3__DOT__SP_SHIFT_REG7__DOT__shift_reg
                                                 [0U] 
                                                 >> 7U)));
    vlTOPp->PPU3__DOT__SP_PX_MAP[6U] = ((2U & (vlTOPp->PPU3__DOT__SP_SHIFT_REG6__DOT__shift_reg
                                               [1U] 
                                               >> 6U)) 
                                        | (1U & (vlTOPp->PPU3__DOT__SP_SHIFT_REG6__DOT__shift_reg
                                                 [0U] 
                                                 >> 7U)));
    vlTOPp->PPU3__DOT__SP_PX_MAP[5U] = ((2U & (vlTOPp->PPU3__DOT__SP_SHIFT_REG5__DOT__shift_reg
                                               [1U] 
                                               >> 6U)) 
                                        | (1U & (vlTOPp->PPU3__DOT__SP_SHIFT_REG5__DOT__shift_reg
                                                 [0U] 
                                                 >> 7U)));
    vlTOPp->PPU3__DOT__SP_PX_MAP[4U] = ((2U & (vlTOPp->PPU3__DOT__SP_SHIFT_REG4__DOT__shift_reg
                                               [1U] 
                                               >> 6U)) 
                                        | (1U & (vlTOPp->PPU3__DOT__SP_SHIFT_REG4__DOT__shift_reg
                                                 [0U] 
                                                 >> 7U)));
    vlTOPp->PPU3__DOT__SP_PX_MAP[3U] = ((2U & (vlTOPp->PPU3__DOT__SP_SHIFT_REG3__DOT__shift_reg
                                               [1U] 
                                               >> 6U)) 
                                        | (1U & (vlTOPp->PPU3__DOT__SP_SHIFT_REG3__DOT__shift_reg
                                                 [0U] 
                                                 >> 7U)));
    vlTOPp->PPU3__DOT__SP_PX_MAP[2U] = ((2U & (vlTOPp->PPU3__DOT__SP_SHIFT_REG2__DOT__shift_reg
                                               [1U] 
                                               >> 6U)) 
                                        | (1U & (vlTOPp->PPU3__DOT__SP_SHIFT_REG2__DOT__shift_reg
                                                 [0U] 
                                                 >> 7U)));
    vlTOPp->PPU3__DOT__SP_PX_MAP[1U] = ((2U & (vlTOPp->PPU3__DOT__SP_SHIFT_REG1__DOT__shift_reg
                                               [1U] 
                                               >> 6U)) 
                                        | (1U & (vlTOPp->PPU3__DOT__SP_SHIFT_REG1__DOT__shift_reg
                                                 [0U] 
                                                 >> 7U)));
    vlTOPp->PPU3__DOT__SP_PX_MAP[0U] = ((2U & (vlTOPp->PPU3__DOT__SP_SHIFT_REG0__DOT__shift_reg
                                               [1U] 
                                               >> 6U)) 
                                        | (1U & (vlTOPp->PPU3__DOT__SP_SHIFT_REG0__DOT__shift_reg
                                                 [0U] 
                                                 >> 7U)));
    vlTOPp->PPU3__DOT__sp_name_table_x[0U] = (vlTOPp->PPU3__DOT__sp_name_table
                                              [0U] 
                                              << 2U);
    vlTOPp->PPU3__DOT__sp_name_table_x[1U] = (vlTOPp->PPU3__DOT__sp_name_table
                                              [1U] 
                                              << 2U);
    vlTOPp->PPU3__DOT__sp_name_table_x[2U] = (vlTOPp->PPU3__DOT__sp_name_table
                                              [2U] 
                                              << 2U);
    vlTOPp->PPU3__DOT__sp_name_table_x[3U] = (vlTOPp->PPU3__DOT__sp_name_table
                                              [3U] 
                                              << 2U);
    vlTOPp->PPU3__DOT__sp_name_table_x[4U] = (vlTOPp->PPU3__DOT__sp_name_table
                                              [4U] 
                                              << 2U);
    vlTOPp->PPU3__DOT__sp_name_table_x[5U] = (vlTOPp->PPU3__DOT__sp_name_table
                                              [5U] 
                                              << 2U);
    vlTOPp->PPU3__DOT__sp_name_table_x[6U] = (vlTOPp->PPU3__DOT__sp_name_table
                                              [6U] 
                                              << 2U);
    vlTOPp->PPU3__DOT__sp_name_table_x[7U] = (vlTOPp->PPU3__DOT__sp_name_table
                                              [7U] 
                                              << 2U);
    vlTOPp->PPU3__DOT__sp_name_table_x[8U] = (vlTOPp->PPU3__DOT__sp_name_table
                                              [8U] 
                                              << 2U);
    vlTOPp->PPU3__DOT__sp_name_table_x[9U] = (vlTOPp->PPU3__DOT__sp_name_table
                                              [9U] 
                                              << 2U);
    vlTOPp->PPU3__DOT__OAM_SEARCH_GO = 0U;
    if ((0x80U & (IData)(vlTOPp->PPU3__DOT__FF40))) {
        if ((0U == vlTOPp->PPU3__DOT__PPU_STATE)) {
            vlTOPp->PPU3__DOT__OAM_SEARCH_GO = 1U;
        }
    }
    vlTOPp->PPU_RD = 0U;
    if ((0x80U & (IData)(vlTOPp->PPU3__DOT__FF40))) {
        if ((0U == vlTOPp->PPU3__DOT__PPU_STATE)) {
            vlTOPp->PPU_RD = 1U;
        } else {
            if ((1U == vlTOPp->PPU3__DOT__PPU_STATE)) {
                vlTOPp->PPU_RD = 1U;
            }
        }
    }
    vlTOPp->PPU3__DOT__FF40_NEXT = (((IData)(vlTOPp->WR) 
                                     & (0xff40U == (IData)(vlTOPp->ADDR)))
                                     ? (IData)(vlTOPp->MMIO_DATA_out)
                                     : (IData)(vlTOPp->PPU3__DOT__FF40));
    if ((0x80U & (IData)(vlTOPp->PPU3__DOT__FF40))) {
        vlTOPp->PPU3__DOT__PPU_CNT_NEXT = (0xffffU 
                                           & ((IData)(1U) 
                                              + (IData)(vlTOPp->PPU3__DOT__PPU_CNT)));
        if ((0U != vlTOPp->PPU3__DOT__PPU_STATE)) {
            if ((1U != vlTOPp->PPU3__DOT__PPU_STATE)) {
                if ((2U == vlTOPp->PPU3__DOT__PPU_STATE)) {
                    if ((0x1c7U == (IData)(vlTOPp->PPU3__DOT__PPU_CNT))) {
                        vlTOPp->PPU3__DOT__PPU_CNT_NEXT = 0U;
                    }
                } else {
                    if ((3U == vlTOPp->PPU3__DOT__PPU_STATE)) {
                        if (((0x1c7U == (IData)(vlTOPp->PPU3__DOT__PPU_CNT)) 
                             & (0U != (IData)(vlTOPp->PPU3__DOT__LY)))) {
                            vlTOPp->PPU3__DOT__PPU_CNT_NEXT = 0U;
                        }
                        if (((0x1c7U == (IData)(vlTOPp->PPU3__DOT__PPU_CNT)) 
                             & (0U == (IData)(vlTOPp->PPU3__DOT__LY)))) {
                            vlTOPp->PPU3__DOT__PPU_CNT_NEXT = 0U;
                        }
                    }
                }
            }
        }
    } else {
        vlTOPp->PPU3__DOT__PPU_CNT_NEXT = 0U;
    }
    vlTOPp->MMIO_DATA_in = (((((((((0xff40U == (IData)(vlTOPp->ADDR)) 
                                   | (0xff41U == (IData)(vlTOPp->ADDR))) 
                                  | (0xff42U == (IData)(vlTOPp->ADDR))) 
                                 | (0xff43U == (IData)(vlTOPp->ADDR))) 
                                | (0xff44U == (IData)(vlTOPp->ADDR))) 
                               | (0xff45U == (IData)(vlTOPp->ADDR))) 
                              | (0xff46U == (IData)(vlTOPp->ADDR))) 
                             | (0xff47U == (IData)(vlTOPp->ADDR)))
                             ? ((0xff40U == (IData)(vlTOPp->ADDR))
                                 ? (IData)(vlTOPp->PPU3__DOT__FF40)
                                 : ((0xff41U == (IData)(vlTOPp->ADDR))
                                     ? (0x80U | (0x7fU 
                                                 & (IData)(vlTOPp->PPU3__DOT__FF41)))
                                     : ((0xff42U == (IData)(vlTOPp->ADDR))
                                         ? (IData)(vlTOPp->PPU3__DOT__FF42)
                                         : ((0xff43U 
                                             == (IData)(vlTOPp->ADDR))
                                             ? (IData)(vlTOPp->PPU3__DOT__FF43)
                                             : ((0xff44U 
                                                 == (IData)(vlTOPp->ADDR))
                                                 ? (IData)(vlTOPp->PPU3__DOT__LY)
                                                 : 
                                                ((0xff45U 
                                                  == (IData)(vlTOPp->ADDR))
                                                  ? (IData)(vlTOPp->PPU3__DOT__FF45)
                                                  : 
                                                 ((0xff46U 
                                                   == (IData)(vlTOPp->ADDR))
                                                   ? (IData)(vlTOPp->PPU3__DOT__FF46)
                                                   : (IData)(vlTOPp->PPU3__DOT__FF47))))))))
                             : ((0xff48U == (IData)(vlTOPp->ADDR))
                                 ? (IData)(vlTOPp->PPU3__DOT__FF48)
                                 : ((0xff49U == (IData)(vlTOPp->ADDR))
                                     ? (IData)(vlTOPp->PPU3__DOT__FF49)
                                     : ((0xff4aU == (IData)(vlTOPp->ADDR))
                                         ? (IData)(vlTOPp->PPU3__DOT__FF4A)
                                         : ((0xff4bU 
                                             == (IData)(vlTOPp->ADDR))
                                             ? (IData)(vlTOPp->PPU3__DOT__FF4B)
                                             : 0xffU)))));
    vlTOPp->PPU3__DOT__BGWD_PX_MAP = ((IData)(vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_SEL)
                                       ? ((2U & (vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_B__DOT__shift_reg
                                                 [1U] 
                                                 >> 6U)) 
                                          | (1U & (
                                                   vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_B__DOT__shift_reg
                                                   [0U] 
                                                   >> 7U)))
                                       : ((2U & (vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_A__DOT__shift_reg
                                                 [1U] 
                                                 >> 6U)) 
                                          | (1U & (
                                                   vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_A__DOT__shift_reg
                                                   [0U] 
                                                   >> 7U))));
    vlTOPp->PPU_MODE = 1U;
    if ((0x80U & (IData)(vlTOPp->PPU3__DOT__FF40))) {
        if ((0U == vlTOPp->PPU3__DOT__PPU_STATE)) {
            vlTOPp->PPU_MODE = 2U;
        } else {
            if ((1U == vlTOPp->PPU3__DOT__PPU_STATE)) {
                vlTOPp->PPU_MODE = 3U;
            } else {
                if ((2U == vlTOPp->PPU3__DOT__PPU_STATE)) {
                    vlTOPp->PPU_MODE = 0U;
                } else {
                    if ((3U == vlTOPp->PPU3__DOT__PPU_STATE)) {
                        vlTOPp->PPU_MODE = 1U;
                    }
                }
            }
        }
    } else {
        vlTOPp->PPU_MODE = 0U;
    }
    vlTOPp->PPU3__DOT__isHitSP = 0U;
    if ((2U & (IData)(vlTOPp->PPU3__DOT__FF40))) {
        if (((vlTOPp->PPU3__DOT__sp_x_table[9U] == (IData)(vlTOPp->PPU3__DOT__LX)) 
             & ((IData)(vlTOPp->PPU3__DOT__sp_not_used) 
                >> 9U))) {
            vlTOPp->PPU3__DOT__isHitSP = 1U;
        }
        if (((vlTOPp->PPU3__DOT__sp_x_table[8U] == (IData)(vlTOPp->PPU3__DOT__LX)) 
             & ((IData)(vlTOPp->PPU3__DOT__sp_not_used) 
                >> 8U))) {
            vlTOPp->PPU3__DOT__isHitSP = 1U;
        }
        if (((vlTOPp->PPU3__DOT__sp_x_table[7U] == (IData)(vlTOPp->PPU3__DOT__LX)) 
             & ((IData)(vlTOPp->PPU3__DOT__sp_not_used) 
                >> 7U))) {
            vlTOPp->PPU3__DOT__isHitSP = 1U;
        }
        if (((vlTOPp->PPU3__DOT__sp_x_table[6U] == (IData)(vlTOPp->PPU3__DOT__LX)) 
             & ((IData)(vlTOPp->PPU3__DOT__sp_not_used) 
                >> 6U))) {
            vlTOPp->PPU3__DOT__isHitSP = 1U;
        }
        if (((vlTOPp->PPU3__DOT__sp_x_table[5U] == (IData)(vlTOPp->PPU3__DOT__LX)) 
             & ((IData)(vlTOPp->PPU3__DOT__sp_not_used) 
                >> 5U))) {
            vlTOPp->PPU3__DOT__isHitSP = 1U;
        }
        if (((vlTOPp->PPU3__DOT__sp_x_table[4U] == (IData)(vlTOPp->PPU3__DOT__LX)) 
             & ((IData)(vlTOPp->PPU3__DOT__sp_not_used) 
                >> 4U))) {
            vlTOPp->PPU3__DOT__isHitSP = 1U;
        }
        if (((vlTOPp->PPU3__DOT__sp_x_table[3U] == (IData)(vlTOPp->PPU3__DOT__LX)) 
             & ((IData)(vlTOPp->PPU3__DOT__sp_not_used) 
                >> 3U))) {
            vlTOPp->PPU3__DOT__isHitSP = 1U;
        }
        if (((vlTOPp->PPU3__DOT__sp_x_table[2U] == (IData)(vlTOPp->PPU3__DOT__LX)) 
             & ((IData)(vlTOPp->PPU3__DOT__sp_not_used) 
                >> 2U))) {
            vlTOPp->PPU3__DOT__isHitSP = 1U;
        }
        if (((vlTOPp->PPU3__DOT__sp_x_table[1U] == (IData)(vlTOPp->PPU3__DOT__LX)) 
             & ((IData)(vlTOPp->PPU3__DOT__sp_not_used) 
                >> 1U))) {
            vlTOPp->PPU3__DOT__isHitSP = 1U;
        }
        if (((vlTOPp->PPU3__DOT__sp_x_table[0U] == (IData)(vlTOPp->PPU3__DOT__LX)) 
             & (IData)(vlTOPp->PPU3__DOT__sp_not_used))) {
            vlTOPp->PPU3__DOT__isHitSP = 1U;
        }
    }
    vlTOPp->PPU3__DOT__sp_to_fetch = 0U;
    if ((2U & (IData)(vlTOPp->PPU3__DOT__FF40))) {
        if (((vlTOPp->PPU3__DOT__sp_x_table[9U] == (IData)(vlTOPp->PPU3__DOT__LX)) 
             & ((IData)(vlTOPp->PPU3__DOT__sp_not_used) 
                >> 9U))) {
            vlTOPp->PPU3__DOT__sp_to_fetch = 9U;
        }
        if (((vlTOPp->PPU3__DOT__sp_x_table[8U] == (IData)(vlTOPp->PPU3__DOT__LX)) 
             & ((IData)(vlTOPp->PPU3__DOT__sp_not_used) 
                >> 8U))) {
            vlTOPp->PPU3__DOT__sp_to_fetch = 8U;
        }
        if (((vlTOPp->PPU3__DOT__sp_x_table[7U] == (IData)(vlTOPp->PPU3__DOT__LX)) 
             & ((IData)(vlTOPp->PPU3__DOT__sp_not_used) 
                >> 7U))) {
            vlTOPp->PPU3__DOT__sp_to_fetch = 7U;
        }
        if (((vlTOPp->PPU3__DOT__sp_x_table[6U] == (IData)(vlTOPp->PPU3__DOT__LX)) 
             & ((IData)(vlTOPp->PPU3__DOT__sp_not_used) 
                >> 6U))) {
            vlTOPp->PPU3__DOT__sp_to_fetch = 6U;
        }
        if (((vlTOPp->PPU3__DOT__sp_x_table[5U] == (IData)(vlTOPp->PPU3__DOT__LX)) 
             & ((IData)(vlTOPp->PPU3__DOT__sp_not_used) 
                >> 5U))) {
            vlTOPp->PPU3__DOT__sp_to_fetch = 5U;
        }
        if (((vlTOPp->PPU3__DOT__sp_x_table[4U] == (IData)(vlTOPp->PPU3__DOT__LX)) 
             & ((IData)(vlTOPp->PPU3__DOT__sp_not_used) 
                >> 4U))) {
            vlTOPp->PPU3__DOT__sp_to_fetch = 4U;
        }
        if (((vlTOPp->PPU3__DOT__sp_x_table[3U] == (IData)(vlTOPp->PPU3__DOT__LX)) 
             & ((IData)(vlTOPp->PPU3__DOT__sp_not_used) 
                >> 3U))) {
            vlTOPp->PPU3__DOT__sp_to_fetch = 3U;
        }
        if (((vlTOPp->PPU3__DOT__sp_x_table[2U] == (IData)(vlTOPp->PPU3__DOT__LX)) 
             & ((IData)(vlTOPp->PPU3__DOT__sp_not_used) 
                >> 2U))) {
            vlTOPp->PPU3__DOT__sp_to_fetch = 2U;
        }
        if (((vlTOPp->PPU3__DOT__sp_x_table[1U] == (IData)(vlTOPp->PPU3__DOT__LX)) 
             & ((IData)(vlTOPp->PPU3__DOT__sp_not_used) 
                >> 1U))) {
            vlTOPp->PPU3__DOT__sp_to_fetch = 1U;
        }
        if (((vlTOPp->PPU3__DOT__sp_x_table[0U] == (IData)(vlTOPp->PPU3__DOT__LX)) 
             & (IData)(vlTOPp->PPU3__DOT__sp_not_used))) {
            vlTOPp->PPU3__DOT__sp_to_fetch = 0U;
        }
    }
    vlTOPp->PPU3__DOT__BGWD_PX_DATA = ((2U & (((IData)(vlTOPp->PPU3__DOT__FF47) 
                                               >> (1U 
                                                   | ((IData)(vlTOPp->PPU3__DOT__BGWD_PX_MAP) 
                                                      << 1U))) 
                                              << 1U)) 
                                       | (1U & ((IData)(vlTOPp->PPU3__DOT__FF47) 
                                                >> 
                                                ((IData)(vlTOPp->PPU3__DOT__BGWD_PX_MAP) 
                                                 << 1U))));
    vlTOPp->PPU3__DOT__FF41_NEXT = (((IData)(vlTOPp->WR) 
                                     & (0xff41U == (IData)(vlTOPp->ADDR)))
                                     ? ((0xf8U & (IData)(vlTOPp->MMIO_DATA_out)) 
                                        | (7U & (IData)(vlTOPp->PPU3__DOT__FF41)))
                                     : ((0xf8U & (IData)(vlTOPp->PPU3__DOT__FF41)) 
                                        | ((((IData)(vlTOPp->PPU3__DOT__FF45) 
                                             == (IData)(vlTOPp->PPU3__DOT__LY)) 
                                            << 2U) 
                                           | (IData)(vlTOPp->PPU_MODE))));
    vlTOPp->PPU3__DOT__PPU_STATE_NEXT = vlTOPp->PPU3__DOT__PPU_STATE;
    vlTOPp->PPU3__DOT__LX_NEXT = vlTOPp->PPU3__DOT__LX;
    vlTOPp->PPU3__DOT__LY_NEXT = vlTOPp->PPU3__DOT__LY;
    vlTOPp->PPU3__DOT__SCX_CNT_NEXT = vlTOPp->PPU3__DOT__SCX_CNT;
    vlTOPp->PPU3__DOT__sp_not_used_next = vlTOPp->PPU3__DOT__sp_not_used;
    vlTOPp->PPU3__DOT__isFetchWD_NEXT = vlTOPp->PPU3__DOT__isFetchWD;
    vlTOPp->PPU3__DOT__FIRST_FETCH_WD_DONE_NEXT = vlTOPp->PPU3__DOT__FIRST_FETCH_WD_DONE;
    vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_SEL_NEXT = vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_SEL;
    vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_A_VALID_NEXT 
        = vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_A_VALID;
    vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_B_VALID_NEXT 
        = vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_B_VALID;
    vlTOPp->PPU3__DOT__RENDER_CNT_NEXT = vlTOPp->PPU3__DOT__RENDER_CNT;
    vlTOPp->PPU3__DOT__SP_NEXT_SLOT_NEXT = vlTOPp->PPU3__DOT__SP_NEXT_SLOT;
    vlTOPp->PPU3__DOT____Vlvbound3 = vlTOPp->PPU3__DOT__SP_PRIPN
        [0U];
    vlTOPp->PPU3__DOT__SP_PRIPN_NEXT[0U] = vlTOPp->PPU3__DOT____Vlvbound3;
    vlTOPp->PPU3__DOT____Vlvbound3 = vlTOPp->PPU3__DOT__SP_PRIPN
        [1U];
    vlTOPp->PPU3__DOT__SP_PRIPN_NEXT[1U] = vlTOPp->PPU3__DOT____Vlvbound3;
    vlTOPp->PPU3__DOT____Vlvbound3 = vlTOPp->PPU3__DOT__SP_PRIPN
        [2U];
    vlTOPp->PPU3__DOT__SP_PRIPN_NEXT[2U] = vlTOPp->PPU3__DOT____Vlvbound3;
    vlTOPp->PPU3__DOT____Vlvbound3 = vlTOPp->PPU3__DOT__SP_PRIPN
        [3U];
    vlTOPp->PPU3__DOT__SP_PRIPN_NEXT[3U] = vlTOPp->PPU3__DOT____Vlvbound3;
    vlTOPp->PPU3__DOT____Vlvbound3 = vlTOPp->PPU3__DOT__SP_PRIPN
        [4U];
    vlTOPp->PPU3__DOT__SP_PRIPN_NEXT[4U] = vlTOPp->PPU3__DOT____Vlvbound3;
    vlTOPp->PPU3__DOT____Vlvbound3 = vlTOPp->PPU3__DOT__SP_PRIPN
        [5U];
    vlTOPp->PPU3__DOT__SP_PRIPN_NEXT[5U] = vlTOPp->PPU3__DOT____Vlvbound3;
    vlTOPp->PPU3__DOT____Vlvbound3 = vlTOPp->PPU3__DOT__SP_PRIPN
        [6U];
    vlTOPp->PPU3__DOT__SP_PRIPN_NEXT[6U] = vlTOPp->PPU3__DOT____Vlvbound3;
    vlTOPp->PPU3__DOT____Vlvbound3 = vlTOPp->PPU3__DOT__SP_PRIPN
        [7U];
    vlTOPp->PPU3__DOT__SP_PRIPN_NEXT[7U] = vlTOPp->PPU3__DOT____Vlvbound3;
    vlTOPp->PPU3__DOT____Vlvbound3 = vlTOPp->PPU3__DOT__SP_PRIPN
        [8U];
    vlTOPp->PPU3__DOT__SP_PRIPN_NEXT[8U] = vlTOPp->PPU3__DOT____Vlvbound3;
    vlTOPp->PPU3__DOT____Vlvbound3 = vlTOPp->PPU3__DOT__SP_PRIPN
        [9U];
    vlTOPp->PPU3__DOT__SP_PRIPN_NEXT[9U] = vlTOPp->PPU3__DOT____Vlvbound3;
    vlTOPp->PPU_ADDR = 0U;
    vlTOPp->PPU3__DOT__BGWD_RENDER_GO = 0U;
    vlTOPp->PPU3__DOT__isHitWD = ((((IData)(vlTOPp->PPU3__DOT__FF4A) 
                                    <= (IData)(vlTOPp->PPU3__DOT__LY)) 
                                   & ((IData)(vlTOPp->PPU3__DOT__LX) 
                                      == ((IData)(1U) 
                                          + (IData)(vlTOPp->PPU3__DOT__FF4B)))) 
                                  & ((IData)(vlTOPp->PPU3__DOT__FF40) 
                                     >> 5U));
    vlTOPp->PPU3__DOT__SP_RENDER_GO = 0U;
    vlTOPp->PPU3__DOT__SP_SHIFT_REG_LOAD = 0U;
    vlTOPp->PPU3__DOT__SHIFT_REG_GO = 0U;
    vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_LOAD = 0U;
    vlTOPp->PX_valid = 0U;
    vlTOPp->IRQ_V_BLANK = 0U;
    if ((0x80U & (IData)(vlTOPp->PPU3__DOT__FF40))) {
        if ((0U == vlTOPp->PPU3__DOT__PPU_STATE)) {
            vlTOPp->PPU_ADDR = (0xffffU & ((1U & (IData)(vlTOPp->PPU3__DOT__PPU_CNT))
                                            ? ((IData)(0xfdffU) 
                                               + ((IData)(vlTOPp->PPU3__DOT__PPU_CNT) 
                                                  << 1U))
                                            : ((IData)(0xfe00U) 
                                               + ((IData)(vlTOPp->PPU3__DOT__PPU_CNT) 
                                                  << 1U))));
            vlTOPp->PPU3__DOT__sp_not_used_next = 0x3ffU;
            if ((0x4fU == (IData)(vlTOPp->PPU3__DOT__PPU_CNT))) {
                vlTOPp->PPU3__DOT__PPU_STATE_NEXT = 1U;
            }
        } else {
            if ((1U == vlTOPp->PPU3__DOT__PPU_STATE)) {
                if (((IData)(vlTOPp->PPU3__DOT__isHitWD) 
                     & (~ (IData)(vlTOPp->PPU3__DOT__isFetchWD)))) {
                    vlTOPp->PPU3__DOT__RENDER_CNT_NEXT = 0U;
                    vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_A_VALID_NEXT = 0U;
                    vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_B_VALID_NEXT = 0U;
                    vlTOPp->PPU3__DOT__isFetchWD_NEXT = 1U;
                } else {
                    if ((((~ (IData)(vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_A_VALID)) 
                          | (~ (IData)(vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_B_VALID))) 
                         & (6U >= (IData)(vlTOPp->PPU3__DOT__RENDER_CNT)))) {
                        vlTOPp->PPU3__DOT__BGWD_RENDER_GO = 1U;
                        if (vlTOPp->PPU3__DOT__isFetchWD) {
                            if ((0U == (IData)(vlTOPp->PPU3__DOT__BGWD_CNT))) {
                                vlTOPp->PPU_ADDR = 
                                    (0xffffU & (0x9800U 
                                                | (((0x400U 
                                                     & ((IData)(vlTOPp->PPU3__DOT__FF40) 
                                                        << 4U)) 
                                                    | (0x3e0U 
                                                       & (((IData)(vlTOPp->PPU3__DOT__LY) 
                                                           - (IData)(vlTOPp->PPU3__DOT__FF4A)) 
                                                          << 2U))) 
                                                   | (0x1fU 
                                                      & (((((IData)(vlTOPp->PPU3__DOT__LX) 
                                                            + 
                                                            ((IData)(vlTOPp->PPU3__DOT__FIRST_FETCH_WD_DONE) 
                                                             << 3U)) 
                                                           - (IData)(vlTOPp->PPU3__DOT__FF4B)) 
                                                          - (IData)(1U)) 
                                                         >> 3U)))));
                            } else {
                                if ((1U == (IData)(vlTOPp->PPU3__DOT__BGWD_CNT))) {
                                    vlTOPp->PPU_ADDR 
                                        = (0xffffU 
                                           & (IData)(
                                                     (VL_ULL(0x1ffffffff) 
                                                      & ((0x10U 
                                                          & (IData)(vlTOPp->PPU3__DOT__FF40))
                                                          ? 
                                                         (((QData)((IData)(
                                                                           ((0x10U 
                                                                             & (IData)(vlTOPp->PPU3__DOT__FF40))
                                                                             ? 0x8000U
                                                                             : 0x9000U))) 
                                                           + (QData)((IData)(
                                                                             ((IData)(vlTOPp->PPU3__DOT__BGWD_MAP) 
                                                                              << 4U)))) 
                                                          | ((QData)((IData)(
                                                                             (7U 
                                                                              & ((IData)(vlTOPp->PPU3__DOT__LY) 
                                                                                - (IData)(vlTOPp->PPU3__DOT__FF4A))))) 
                                                             << 1U))
                                                          : 
                                                         ((((QData)((IData)(
                                                                            ((0x10U 
                                                                              & (IData)(vlTOPp->PPU3__DOT__FF40))
                                                                              ? 0x8000U
                                                                              : 0x9000U))) 
                                                            - (QData)((IData)(
                                                                              (0x800U 
                                                                               & ((IData)(vlTOPp->PPU3__DOT__BGWD_MAP) 
                                                                                << 4U))))) 
                                                           + (QData)((IData)(
                                                                             (0x7f0U 
                                                                              & ((IData)(vlTOPp->PPU3__DOT__BGWD_MAP) 
                                                                                << 4U))))) 
                                                          | (QData)((IData)(
                                                                            (0xeU 
                                                                             & (((IData)(vlTOPp->PPU3__DOT__LY) 
                                                                                - (IData)(vlTOPp->PPU3__DOT__FF4A)) 
                                                                                << 1U)))))))));
                                } else {
                                    if ((2U == (IData)(vlTOPp->PPU3__DOT__BGWD_CNT))) {
                                        vlTOPp->PPU_ADDR 
                                            = (0xffffU 
                                               & (IData)(
                                                         (VL_ULL(0x1ffffffff) 
                                                          & ((0x10U 
                                                              & (IData)(vlTOPp->PPU3__DOT__FF40))
                                                              ? 
                                                             (VL_ULL(1) 
                                                              | (((QData)((IData)(
                                                                                ((0x10U 
                                                                                & (IData)(vlTOPp->PPU3__DOT__FF40))
                                                                                 ? 0x8000U
                                                                                 : 0x9000U))) 
                                                                  + (QData)((IData)(
                                                                                ((IData)(vlTOPp->PPU3__DOT__BGWD_MAP) 
                                                                                << 4U)))) 
                                                                 | ((QData)((IData)(
                                                                                (7U 
                                                                                & ((IData)(vlTOPp->PPU3__DOT__LY) 
                                                                                - (IData)(vlTOPp->PPU3__DOT__FF4A))))) 
                                                                    << 1U)))
                                                              : 
                                                             ((((QData)((IData)(
                                                                                ((0x10U 
                                                                                & (IData)(vlTOPp->PPU3__DOT__FF40))
                                                                                 ? 0x8000U
                                                                                 : 0x9000U))) 
                                                                - (QData)((IData)(
                                                                                (0x800U 
                                                                                & ((IData)(vlTOPp->PPU3__DOT__BGWD_MAP) 
                                                                                << 4U))))) 
                                                               + (QData)((IData)(
                                                                                (0x7f0U 
                                                                                & ((IData)(vlTOPp->PPU3__DOT__BGWD_MAP) 
                                                                                << 4U))))) 
                                                              | (QData)((IData)(
                                                                                (1U 
                                                                                | (0xeU 
                                                                                & (((IData)(vlTOPp->PPU3__DOT__LY) 
                                                                                - (IData)(vlTOPp->PPU3__DOT__FF4A)) 
                                                                                << 1U))))))))));
                                    }
                                }
                            }
                        } else {
                            if ((0U == (IData)(vlTOPp->PPU3__DOT__BGWD_CNT))) {
                                vlTOPp->PPU_ADDR = 
                                    (0x9800U | (((0x400U 
                                                  & ((IData)(vlTOPp->PPU3__DOT__FF40) 
                                                     << 7U)) 
                                                 | (0x3e0U 
                                                    & (((IData)(vlTOPp->PPU3__DOT__LY) 
                                                        + (IData)(vlTOPp->PPU3__DOT__FF42)) 
                                                       << 2U))) 
                                                | (0x1fU 
                                                   & (((IData)(vlTOPp->PPU3__DOT__LX) 
                                                       + (IData)(vlTOPp->PPU3__DOT__FF43)) 
                                                      >> 3U))));
                            } else {
                                if ((1U == (IData)(vlTOPp->PPU3__DOT__BGWD_CNT))) {
                                    vlTOPp->PPU_ADDR 
                                        = (0xffffU 
                                           & (IData)(
                                                     (VL_ULL(0x1ffffffff) 
                                                      & ((0x10U 
                                                          & (IData)(vlTOPp->PPU3__DOT__FF40))
                                                          ? 
                                                         (((QData)((IData)(
                                                                           ((0x10U 
                                                                             & (IData)(vlTOPp->PPU3__DOT__FF40))
                                                                             ? 0x8000U
                                                                             : 0x9000U))) 
                                                           + (QData)((IData)(
                                                                             ((IData)(vlTOPp->PPU3__DOT__BGWD_MAP) 
                                                                              << 4U)))) 
                                                          | ((QData)((IData)(
                                                                             (7U 
                                                                              & ((IData)(vlTOPp->PPU3__DOT__LY) 
                                                                                + (IData)(vlTOPp->PPU3__DOT__FF42))))) 
                                                             << 1U))
                                                          : 
                                                         ((((QData)((IData)(
                                                                            ((0x10U 
                                                                              & (IData)(vlTOPp->PPU3__DOT__FF40))
                                                                              ? 0x8000U
                                                                              : 0x9000U))) 
                                                            - (QData)((IData)(
                                                                              (0x800U 
                                                                               & ((IData)(vlTOPp->PPU3__DOT__BGWD_MAP) 
                                                                                << 4U))))) 
                                                           + (QData)((IData)(
                                                                             (0x7f0U 
                                                                              & ((IData)(vlTOPp->PPU3__DOT__BGWD_MAP) 
                                                                                << 4U))))) 
                                                          | (QData)((IData)(
                                                                            (0xeU 
                                                                             & (((IData)(vlTOPp->PPU3__DOT__LY) 
                                                                                + (IData)(vlTOPp->PPU3__DOT__FF42)) 
                                                                                << 1U)))))))));
                                } else {
                                    if ((2U == (IData)(vlTOPp->PPU3__DOT__BGWD_CNT))) {
                                        vlTOPp->PPU_ADDR 
                                            = (0xffffU 
                                               & (IData)(
                                                         (VL_ULL(0x1ffffffff) 
                                                          & ((0x10U 
                                                              & (IData)(vlTOPp->PPU3__DOT__FF40))
                                                              ? 
                                                             (VL_ULL(1) 
                                                              | (((QData)((IData)(
                                                                                ((0x10U 
                                                                                & (IData)(vlTOPp->PPU3__DOT__FF40))
                                                                                 ? 0x8000U
                                                                                 : 0x9000U))) 
                                                                  + (QData)((IData)(
                                                                                ((IData)(vlTOPp->PPU3__DOT__BGWD_MAP) 
                                                                                << 4U)))) 
                                                                 | ((QData)((IData)(
                                                                                (7U 
                                                                                & ((IData)(vlTOPp->PPU3__DOT__LY) 
                                                                                + (IData)(vlTOPp->PPU3__DOT__FF42))))) 
                                                                    << 1U)))
                                                              : 
                                                             ((((QData)((IData)(
                                                                                ((0x10U 
                                                                                & (IData)(vlTOPp->PPU3__DOT__FF40))
                                                                                 ? 0x8000U
                                                                                 : 0x9000U))) 
                                                                - (QData)((IData)(
                                                                                (0x800U 
                                                                                & ((IData)(vlTOPp->PPU3__DOT__BGWD_MAP) 
                                                                                << 4U))))) 
                                                               + (QData)((IData)(
                                                                                (0x7f0U 
                                                                                & ((IData)(vlTOPp->PPU3__DOT__BGWD_MAP) 
                                                                                << 4U))))) 
                                                              | (QData)((IData)(
                                                                                (1U 
                                                                                | (0xeU 
                                                                                & (((IData)(vlTOPp->PPU3__DOT__LY) 
                                                                                + (IData)(vlTOPp->PPU3__DOT__FF42)) 
                                                                                << 1U))))))))));
                                    }
                                }
                            }
                        }
                        if (((IData)(vlTOPp->PPU3__DOT__BGWD_CNT) 
                             == (5U & (6U | (1U & (~ (IData)(vlTOPp->PPU3__DOT__isHitSP))))))) {
                            if (vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_SEL) {
                                vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_A_VALID_NEXT = 1U;
                                vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_LOAD 
                                    = (1U | (IData)(vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_LOAD));
                            } else {
                                vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_B_VALID_NEXT = 1U;
                                vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_LOAD 
                                    = (2U | (IData)(vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_LOAD));
                            }
                            if ((1U & ((~ (IData)(vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_A_VALID)) 
                                       & (~ (IData)(vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_B_VALID))))) {
                                vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_SEL_NEXT 
                                    = (1U & (~ (IData)(vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_SEL)));
                            }
                            if (vlTOPp->PPU3__DOT__isFetchWD) {
                                vlTOPp->PPU3__DOT__FIRST_FETCH_WD_DONE_NEXT = 1U;
                            }
                        }
                    } else {
                        if (vlTOPp->PPU3__DOT__isHitSP) {
                            vlTOPp->PPU3__DOT__SP_RENDER_GO = 1U;
                            if ((0U == (IData)(vlTOPp->PPU3__DOT__SP_CNT))) {
                                vlTOPp->PPU_ADDR = 
                                    (0xffffU & ((IData)(0xfe02U) 
                                                + (
                                                   (9U 
                                                    >= (IData)(vlTOPp->PPU3__DOT__sp_to_fetch))
                                                    ? 
                                                   vlTOPp->PPU3__DOT__sp_name_table_x
                                                   [vlTOPp->PPU3__DOT__sp_to_fetch]
                                                    : 0U)));
                            } else {
                                if ((1U == (IData)(vlTOPp->PPU3__DOT__SP_CNT))) {
                                    vlTOPp->PPU_ADDR 
                                        = (0xffffU 
                                           & ((IData)(0xfe03U) 
                                              + ((9U 
                                                  >= (IData)(vlTOPp->PPU3__DOT__sp_to_fetch))
                                                  ? 
                                                 vlTOPp->PPU3__DOT__sp_name_table_x
                                                 [vlTOPp->PPU3__DOT__sp_to_fetch]
                                                  : 0U)));
                                } else {
                                    if (((2U == (IData)(vlTOPp->PPU3__DOT__SP_CNT)) 
                                         | (3U == (IData)(vlTOPp->PPU3__DOT__SP_CNT)))) {
                                        vlTOPp->PPU_ADDR 
                                            = (0xffffU 
                                               & ((0x40U 
                                                   & (IData)(vlTOPp->PPU3__DOT__SP_FLAG))
                                                   ? 
                                                  ((IData)(0x8000U) 
                                                   + 
                                                   ((((4U 
                                                       & (IData)(vlTOPp->PPU3__DOT__FF40))
                                                       ? 
                                                      (0xfeU 
                                                       & (IData)(vlTOPp->PPU3__DOT__SP_MAP))
                                                       : (IData)(vlTOPp->PPU3__DOT__SP_MAP)) 
                                                     << 4U) 
                                                    | (0x1eU 
                                                       & ((((((IData)(8U) 
                                                              + 
                                                              ((8U 
                                                                & ((IData)(vlTOPp->PPU3__DOT__FF40) 
                                                                   << 1U)) 
                                                               + 
                                                               ((9U 
                                                                 >= (IData)(vlTOPp->PPU3__DOT__sp_to_fetch))
                                                                 ? 
                                                                vlTOPp->PPU3__DOT__sp_y_table
                                                                [vlTOPp->PPU3__DOT__sp_to_fetch]
                                                                 : 0U))) 
                                                             - (IData)(vlTOPp->PPU3__DOT__LY)) 
                                                            - (IData)(0x10U)) 
                                                           - (IData)(1U)) 
                                                          << 1U))))
                                                   : 
                                                  ((IData)(0x8000U) 
                                                   + 
                                                   ((((4U 
                                                       & (IData)(vlTOPp->PPU3__DOT__FF40))
                                                       ? 
                                                      (0xfeU 
                                                       & (IData)(vlTOPp->PPU3__DOT__SP_MAP))
                                                       : (IData)(vlTOPp->PPU3__DOT__SP_MAP)) 
                                                     << 4U) 
                                                    | (0x1eU 
                                                       & ((((IData)(0x10U) 
                                                            + (IData)(vlTOPp->PPU3__DOT__LY)) 
                                                           - 
                                                           ((9U 
                                                             >= (IData)(vlTOPp->PPU3__DOT__sp_to_fetch))
                                                             ? 
                                                            vlTOPp->PPU3__DOT__sp_y_table
                                                            [vlTOPp->PPU3__DOT__sp_to_fetch]
                                                             : 0U)) 
                                                          << 1U))))));
                                    } else {
                                        if (((4U == (IData)(vlTOPp->PPU3__DOT__SP_CNT)) 
                                             | (5U 
                                                == (IData)(vlTOPp->PPU3__DOT__SP_CNT)))) {
                                            vlTOPp->PPU_ADDR 
                                                = (0xffffU 
                                                   & ((0x40U 
                                                       & (IData)(vlTOPp->PPU3__DOT__SP_FLAG))
                                                       ? 
                                                      ((IData)(0x8001U) 
                                                       + 
                                                       ((((4U 
                                                           & (IData)(vlTOPp->PPU3__DOT__FF40))
                                                           ? 
                                                          (0xfeU 
                                                           & (IData)(vlTOPp->PPU3__DOT__SP_MAP))
                                                           : (IData)(vlTOPp->PPU3__DOT__SP_MAP)) 
                                                         << 4U) 
                                                        | (0x1eU 
                                                           & ((((((IData)(8U) 
                                                                  + 
                                                                  ((8U 
                                                                    & ((IData)(vlTOPp->PPU3__DOT__FF40) 
                                                                       << 1U)) 
                                                                   + 
                                                                   ((9U 
                                                                     >= (IData)(vlTOPp->PPU3__DOT__sp_to_fetch))
                                                                     ? 
                                                                    vlTOPp->PPU3__DOT__sp_y_table
                                                                    [vlTOPp->PPU3__DOT__sp_to_fetch]
                                                                     : 0U))) 
                                                                 - (IData)(vlTOPp->PPU3__DOT__LY)) 
                                                                - (IData)(0x10U)) 
                                                               - (IData)(1U)) 
                                                              << 1U))))
                                                       : 
                                                      ((IData)(0x8001U) 
                                                       + 
                                                       ((((4U 
                                                           & (IData)(vlTOPp->PPU3__DOT__FF40))
                                                           ? 
                                                          (0xfeU 
                                                           & (IData)(vlTOPp->PPU3__DOT__SP_MAP))
                                                           : (IData)(vlTOPp->PPU3__DOT__SP_MAP)) 
                                                         << 4U) 
                                                        | (0x1eU 
                                                           & ((((IData)(0x10U) 
                                                                + (IData)(vlTOPp->PPU3__DOT__LY)) 
                                                               - 
                                                               ((9U 
                                                                 >= (IData)(vlTOPp->PPU3__DOT__sp_to_fetch))
                                                                 ? 
                                                                vlTOPp->PPU3__DOT__sp_y_table
                                                                [vlTOPp->PPU3__DOT__sp_to_fetch]
                                                                 : 0U)) 
                                                              << 1U))))));
                                        }
                                    }
                                }
                            }
                            if ((5U == (IData)(vlTOPp->PPU3__DOT__SP_CNT))) {
                                vlTOPp->PPU3__DOT____Vlvbound4 = 0U;
                                vlTOPp->PPU3__DOT____Vlvbound5 = 1U;
                                vlTOPp->PPU3__DOT____Vlvbound6 
                                    = ((2U & ((IData)(vlTOPp->PPU3__DOT__SP_FLAG) 
                                              >> 6U)) 
                                       | (1U & ((IData)(vlTOPp->PPU3__DOT__SP_FLAG) 
                                                >> 4U)));
                                if ((9U >= (IData)(vlTOPp->PPU3__DOT__sp_to_fetch))) {
                                    vlTOPp->PPU3__DOT__sp_not_used_next 
                                        = (((~ ((IData)(1U) 
                                                << (IData)(vlTOPp->PPU3__DOT__sp_to_fetch))) 
                                            & (IData)(vlTOPp->PPU3__DOT__sp_not_used_next)) 
                                           | ((IData)(vlTOPp->PPU3__DOT____Vlvbound4) 
                                              << (IData)(vlTOPp->PPU3__DOT__sp_to_fetch)));
                                }
                                if ((9U >= (IData)(vlTOPp->PPU3__DOT__SP_NEXT_SLOT))) {
                                    vlTOPp->PPU3__DOT__SP_SHIFT_REG_LOAD 
                                        = (((~ ((IData)(1U) 
                                                << (IData)(vlTOPp->PPU3__DOT__SP_NEXT_SLOT))) 
                                            & (IData)(vlTOPp->PPU3__DOT__SP_SHIFT_REG_LOAD)) 
                                           | ((IData)(vlTOPp->PPU3__DOT____Vlvbound5) 
                                              << (IData)(vlTOPp->PPU3__DOT__SP_NEXT_SLOT)));
                                }
                                if ((9U >= (IData)(vlTOPp->PPU3__DOT__SP_NEXT_SLOT))) {
                                    vlTOPp->PPU3__DOT__SP_PRIPN_NEXT[vlTOPp->PPU3__DOT__SP_NEXT_SLOT] 
                                        = vlTOPp->PPU3__DOT____Vlvbound6;
                                }
                                vlTOPp->PPU3__DOT__SP_NEXT_SLOT_NEXT 
                                    = (0xfU & ((IData)(1U) 
                                               + (IData)(vlTOPp->PPU3__DOT__SP_NEXT_SLOT)));
                            }
                        }
                    }
                }
                if (((((IData)(vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_A_VALID) 
                       | (IData)(vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_B_VALID)) 
                      & (~ (IData)(vlTOPp->PPU3__DOT__isHitSP))) 
                     & (~ ((IData)(vlTOPp->PPU3__DOT__isHitWD) 
                           & (~ (IData)(vlTOPp->PPU3__DOT__isFetchWD)))))) {
                    vlTOPp->PPU3__DOT__RENDER_CNT_NEXT 
                        = (7U & ((IData)(1U) + (IData)(vlTOPp->PPU3__DOT__RENDER_CNT)));
                    vlTOPp->PPU3__DOT__SHIFT_REG_GO = 1U;
                    if (((IData)(vlTOPp->PPU3__DOT__SCX_CNT) 
                         != (7U & (IData)(vlTOPp->PPU3__DOT__FF43)))) {
                        vlTOPp->PPU3__DOT__SCX_CNT_NEXT 
                            = (7U & ((IData)(1U) + (IData)(vlTOPp->PPU3__DOT__SCX_CNT)));
                    } else {
                        vlTOPp->PPU3__DOT__LX_NEXT 
                            = (0xffU & ((IData)(1U) 
                                        + (IData)(vlTOPp->PPU3__DOT__LX)));
                        if ((8U <= (IData)(vlTOPp->PPU3__DOT__LX))) {
                            vlTOPp->PX_valid = 1U;
                        }
                    }
                    if ((7U == (IData)(vlTOPp->PPU3__DOT__RENDER_CNT))) {
                        vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_SEL_NEXT 
                            = (1U & (~ (IData)(vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_SEL)));
                        if (vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_SEL) {
                            vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_B_VALID_NEXT = 0U;
                        } else {
                            vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_A_VALID_NEXT = 0U;
                        }
                    }
                }
                if ((0xa8U == (IData)(vlTOPp->PPU3__DOT__LX_NEXT))) {
                    vlTOPp->PPU3__DOT__PPU_STATE_NEXT = 2U;
                    vlTOPp->PPU3__DOT__isFetchWD_NEXT = 0U;
                    vlTOPp->PPU3__DOT__FIRST_FETCH_WD_DONE_NEXT = 0U;
                    vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_A_VALID_NEXT = 0U;
                    vlTOPp->PPU3__DOT__BGWD_SHIFT_REG_B_VALID_NEXT = 0U;
                    vlTOPp->PPU3__DOT__RENDER_CNT_NEXT = 0U;
                    vlTOPp->PPU3__DOT__sp_not_used_next = 0x3ffU;
                    vlTOPp->PPU3__DOT__SP_NEXT_SLOT_NEXT = 0U;
                    vlTOPp->PPU3__DOT__SCX_CNT_NEXT = 0U;
                }
            } else {
                if ((2U == vlTOPp->PPU3__DOT__PPU_STATE)) {
                    if ((0x1c7U == (IData)(vlTOPp->PPU3__DOT__PPU_CNT))) {
                        vlTOPp->PPU3__DOT__LY_NEXT 
                            = (0xffU & ((IData)(1U) 
                                        + (IData)(vlTOPp->PPU3__DOT__LY)));
                        vlTOPp->PPU3__DOT__LX_NEXT = 0U;
                        vlTOPp->PPU3__DOT__PPU_STATE_NEXT = 0U;
                        if ((0x90U == (IData)(vlTOPp->PPU3__DOT__LY_NEXT))) {
                            vlTOPp->PPU3__DOT__PPU_STATE_NEXT = 3U;
                            vlTOPp->IRQ_V_BLANK = 1U;
                        }
                    }
                } else {
                    if ((3U == vlTOPp->PPU3__DOT__PPU_STATE)) {
                        if ((0x99U == (IData)(vlTOPp->PPU3__DOT__LY))) {
                            vlTOPp->PPU3__DOT__LY_NEXT = 0U;
                            vlTOPp->PPU3__DOT__LX_NEXT = 0U;
                        }
                        if (((0x1c7U == (IData)(vlTOPp->PPU3__DOT__PPU_CNT)) 
                             & (0U == (IData)(vlTOPp->PPU3__DOT__LY)))) {
                            vlTOPp->PPU3__DOT__PPU_STATE_NEXT = 0U;
                        }
                        if (((0x1c7U == (IData)(vlTOPp->PPU3__DOT__PPU_CNT)) 
                             & (0U != (IData)(vlTOPp->PPU3__DOT__LY)))) {
                            vlTOPp->PPU3__DOT__LY_NEXT 
                                = (0xffU & ((IData)(1U) 
                                            + (IData)(vlTOPp->PPU3__DOT__LY)));
                        }
                    }
                }
            }
        }
    } else {
        vlTOPp->PPU3__DOT__LY_NEXT = 0U;
        vlTOPp->PPU3__DOT__LX_NEXT = 0U;
        vlTOPp->PPU3__DOT__PPU_STATE_NEXT = 0U;
    }
    vlTOPp->PX_OUT = vlTOPp->PPU3__DOT__BGWD_PX_DATA;
    if ((2U & (IData)(vlTOPp->PPU3__DOT__FF40))) {
        if (((vlTOPp->PPU3__DOT__SP_PRIPN[9U] >> 1U) 
             & (0U != vlTOPp->PPU3__DOT__SP_PX_MAP[9U]))) {
            vlTOPp->PX_OUT = ((1U & vlTOPp->PPU3__DOT__SP_PRIPN
                               [9U]) ? ((2U & (((0xfcU 
                                                 & (IData)(vlTOPp->PPU3__DOT__FF49)) 
                                                >> 
                                                (1U 
                                                 | (vlTOPp->PPU3__DOT__SP_PX_MAP
                                                    [9U] 
                                                    << 1U))) 
                                               << 1U)) 
                                        | (1U & ((0xfcU 
                                                  & (IData)(vlTOPp->PPU3__DOT__FF49)) 
                                                 >> 
                                                 (vlTOPp->PPU3__DOT__SP_PX_MAP
                                                  [9U] 
                                                  << 1U))))
                               : ((2U & (((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF48)) 
                                          >> (1U | 
                                              (vlTOPp->PPU3__DOT__SP_PX_MAP
                                               [9U] 
                                               << 1U))) 
                                         << 1U)) | 
                                  (1U & ((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF48)) 
                                         >> (vlTOPp->PPU3__DOT__SP_PX_MAP
                                             [9U] << 1U)))));
        }
        if (((vlTOPp->PPU3__DOT__SP_PRIPN[8U] >> 1U) 
             & (0U != vlTOPp->PPU3__DOT__SP_PX_MAP[8U]))) {
            vlTOPp->PX_OUT = ((1U & vlTOPp->PPU3__DOT__SP_PRIPN
                               [8U]) ? ((2U & (((0xfcU 
                                                 & (IData)(vlTOPp->PPU3__DOT__FF49)) 
                                                >> 
                                                (1U 
                                                 | (vlTOPp->PPU3__DOT__SP_PX_MAP
                                                    [8U] 
                                                    << 1U))) 
                                               << 1U)) 
                                        | (1U & ((0xfcU 
                                                  & (IData)(vlTOPp->PPU3__DOT__FF49)) 
                                                 >> 
                                                 (vlTOPp->PPU3__DOT__SP_PX_MAP
                                                  [8U] 
                                                  << 1U))))
                               : ((2U & (((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF48)) 
                                          >> (1U | 
                                              (vlTOPp->PPU3__DOT__SP_PX_MAP
                                               [8U] 
                                               << 1U))) 
                                         << 1U)) | 
                                  (1U & ((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF48)) 
                                         >> (vlTOPp->PPU3__DOT__SP_PX_MAP
                                             [8U] << 1U)))));
        }
        if (((vlTOPp->PPU3__DOT__SP_PRIPN[7U] >> 1U) 
             & (0U != vlTOPp->PPU3__DOT__SP_PX_MAP[7U]))) {
            vlTOPp->PX_OUT = ((1U & vlTOPp->PPU3__DOT__SP_PRIPN
                               [7U]) ? ((2U & (((0xfcU 
                                                 & (IData)(vlTOPp->PPU3__DOT__FF49)) 
                                                >> 
                                                (1U 
                                                 | (vlTOPp->PPU3__DOT__SP_PX_MAP
                                                    [7U] 
                                                    << 1U))) 
                                               << 1U)) 
                                        | (1U & ((0xfcU 
                                                  & (IData)(vlTOPp->PPU3__DOT__FF49)) 
                                                 >> 
                                                 (vlTOPp->PPU3__DOT__SP_PX_MAP
                                                  [7U] 
                                                  << 1U))))
                               : ((2U & (((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF48)) 
                                          >> (1U | 
                                              (vlTOPp->PPU3__DOT__SP_PX_MAP
                                               [7U] 
                                               << 1U))) 
                                         << 1U)) | 
                                  (1U & ((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF48)) 
                                         >> (vlTOPp->PPU3__DOT__SP_PX_MAP
                                             [7U] << 1U)))));
        }
        if (((vlTOPp->PPU3__DOT__SP_PRIPN[6U] >> 1U) 
             & (0U != vlTOPp->PPU3__DOT__SP_PX_MAP[6U]))) {
            vlTOPp->PX_OUT = ((1U & vlTOPp->PPU3__DOT__SP_PRIPN
                               [6U]) ? ((2U & (((0xfcU 
                                                 & (IData)(vlTOPp->PPU3__DOT__FF49)) 
                                                >> 
                                                (1U 
                                                 | (vlTOPp->PPU3__DOT__SP_PX_MAP
                                                    [6U] 
                                                    << 1U))) 
                                               << 1U)) 
                                        | (1U & ((0xfcU 
                                                  & (IData)(vlTOPp->PPU3__DOT__FF49)) 
                                                 >> 
                                                 (vlTOPp->PPU3__DOT__SP_PX_MAP
                                                  [6U] 
                                                  << 1U))))
                               : ((2U & (((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF48)) 
                                          >> (1U | 
                                              (vlTOPp->PPU3__DOT__SP_PX_MAP
                                               [6U] 
                                               << 1U))) 
                                         << 1U)) | 
                                  (1U & ((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF48)) 
                                         >> (vlTOPp->PPU3__DOT__SP_PX_MAP
                                             [6U] << 1U)))));
        }
        if (((vlTOPp->PPU3__DOT__SP_PRIPN[5U] >> 1U) 
             & (0U != vlTOPp->PPU3__DOT__SP_PX_MAP[5U]))) {
            vlTOPp->PX_OUT = ((1U & vlTOPp->PPU3__DOT__SP_PRIPN
                               [5U]) ? ((2U & (((0xfcU 
                                                 & (IData)(vlTOPp->PPU3__DOT__FF49)) 
                                                >> 
                                                (1U 
                                                 | (vlTOPp->PPU3__DOT__SP_PX_MAP
                                                    [5U] 
                                                    << 1U))) 
                                               << 1U)) 
                                        | (1U & ((0xfcU 
                                                  & (IData)(vlTOPp->PPU3__DOT__FF49)) 
                                                 >> 
                                                 (vlTOPp->PPU3__DOT__SP_PX_MAP
                                                  [5U] 
                                                  << 1U))))
                               : ((2U & (((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF48)) 
                                          >> (1U | 
                                              (vlTOPp->PPU3__DOT__SP_PX_MAP
                                               [5U] 
                                               << 1U))) 
                                         << 1U)) | 
                                  (1U & ((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF48)) 
                                         >> (vlTOPp->PPU3__DOT__SP_PX_MAP
                                             [5U] << 1U)))));
        }
        if (((vlTOPp->PPU3__DOT__SP_PRIPN[4U] >> 1U) 
             & (0U != vlTOPp->PPU3__DOT__SP_PX_MAP[4U]))) {
            vlTOPp->PX_OUT = ((1U & vlTOPp->PPU3__DOT__SP_PRIPN
                               [4U]) ? ((2U & (((0xfcU 
                                                 & (IData)(vlTOPp->PPU3__DOT__FF49)) 
                                                >> 
                                                (1U 
                                                 | (vlTOPp->PPU3__DOT__SP_PX_MAP
                                                    [4U] 
                                                    << 1U))) 
                                               << 1U)) 
                                        | (1U & ((0xfcU 
                                                  & (IData)(vlTOPp->PPU3__DOT__FF49)) 
                                                 >> 
                                                 (vlTOPp->PPU3__DOT__SP_PX_MAP
                                                  [4U] 
                                                  << 1U))))
                               : ((2U & (((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF48)) 
                                          >> (1U | 
                                              (vlTOPp->PPU3__DOT__SP_PX_MAP
                                               [4U] 
                                               << 1U))) 
                                         << 1U)) | 
                                  (1U & ((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF48)) 
                                         >> (vlTOPp->PPU3__DOT__SP_PX_MAP
                                             [4U] << 1U)))));
        }
        if (((vlTOPp->PPU3__DOT__SP_PRIPN[3U] >> 1U) 
             & (0U != vlTOPp->PPU3__DOT__SP_PX_MAP[3U]))) {
            vlTOPp->PX_OUT = ((1U & vlTOPp->PPU3__DOT__SP_PRIPN
                               [3U]) ? ((2U & (((0xfcU 
                                                 & (IData)(vlTOPp->PPU3__DOT__FF49)) 
                                                >> 
                                                (1U 
                                                 | (vlTOPp->PPU3__DOT__SP_PX_MAP
                                                    [3U] 
                                                    << 1U))) 
                                               << 1U)) 
                                        | (1U & ((0xfcU 
                                                  & (IData)(vlTOPp->PPU3__DOT__FF49)) 
                                                 >> 
                                                 (vlTOPp->PPU3__DOT__SP_PX_MAP
                                                  [3U] 
                                                  << 1U))))
                               : ((2U & (((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF48)) 
                                          >> (1U | 
                                              (vlTOPp->PPU3__DOT__SP_PX_MAP
                                               [3U] 
                                               << 1U))) 
                                         << 1U)) | 
                                  (1U & ((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF48)) 
                                         >> (vlTOPp->PPU3__DOT__SP_PX_MAP
                                             [3U] << 1U)))));
        }
        if (((vlTOPp->PPU3__DOT__SP_PRIPN[2U] >> 1U) 
             & (0U != vlTOPp->PPU3__DOT__SP_PX_MAP[2U]))) {
            vlTOPp->PX_OUT = ((1U & vlTOPp->PPU3__DOT__SP_PRIPN
                               [2U]) ? ((2U & (((0xfcU 
                                                 & (IData)(vlTOPp->PPU3__DOT__FF49)) 
                                                >> 
                                                (1U 
                                                 | (vlTOPp->PPU3__DOT__SP_PX_MAP
                                                    [2U] 
                                                    << 1U))) 
                                               << 1U)) 
                                        | (1U & ((0xfcU 
                                                  & (IData)(vlTOPp->PPU3__DOT__FF49)) 
                                                 >> 
                                                 (vlTOPp->PPU3__DOT__SP_PX_MAP
                                                  [2U] 
                                                  << 1U))))
                               : ((2U & (((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF48)) 
                                          >> (1U | 
                                              (vlTOPp->PPU3__DOT__SP_PX_MAP
                                               [2U] 
                                               << 1U))) 
                                         << 1U)) | 
                                  (1U & ((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF48)) 
                                         >> (vlTOPp->PPU3__DOT__SP_PX_MAP
                                             [2U] << 1U)))));
        }
        if (((vlTOPp->PPU3__DOT__SP_PRIPN[1U] >> 1U) 
             & (0U != vlTOPp->PPU3__DOT__SP_PX_MAP[1U]))) {
            vlTOPp->PX_OUT = ((1U & vlTOPp->PPU3__DOT__SP_PRIPN
                               [1U]) ? ((2U & (((0xfcU 
                                                 & (IData)(vlTOPp->PPU3__DOT__FF49)) 
                                                >> 
                                                (1U 
                                                 | (vlTOPp->PPU3__DOT__SP_PX_MAP
                                                    [1U] 
                                                    << 1U))) 
                                               << 1U)) 
                                        | (1U & ((0xfcU 
                                                  & (IData)(vlTOPp->PPU3__DOT__FF49)) 
                                                 >> 
                                                 (vlTOPp->PPU3__DOT__SP_PX_MAP
                                                  [1U] 
                                                  << 1U))))
                               : ((2U & (((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF48)) 
                                          >> (1U | 
                                              (vlTOPp->PPU3__DOT__SP_PX_MAP
                                               [1U] 
                                               << 1U))) 
                                         << 1U)) | 
                                  (1U & ((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF48)) 
                                         >> (vlTOPp->PPU3__DOT__SP_PX_MAP
                                             [1U] << 1U)))));
        }
        if (((vlTOPp->PPU3__DOT__SP_PRIPN[0U] >> 1U) 
             & (0U != vlTOPp->PPU3__DOT__SP_PX_MAP[0U]))) {
            vlTOPp->PX_OUT = ((1U & vlTOPp->PPU3__DOT__SP_PRIPN
                               [0U]) ? ((2U & (((0xfcU 
                                                 & (IData)(vlTOPp->PPU3__DOT__FF49)) 
                                                >> 
                                                (1U 
                                                 | (vlTOPp->PPU3__DOT__SP_PX_MAP
                                                    [0U] 
                                                    << 1U))) 
                                               << 1U)) 
                                        | (1U & ((0xfcU 
                                                  & (IData)(vlTOPp->PPU3__DOT__FF49)) 
                                                 >> 
                                                 (vlTOPp->PPU3__DOT__SP_PX_MAP
                                                  [0U] 
                                                  << 1U))))
                               : ((2U & (((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF48)) 
                                          >> (1U | 
                                              (vlTOPp->PPU3__DOT__SP_PX_MAP
                                               [0U] 
                                               << 1U))) 
                                         << 1U)) | 
                                  (1U & ((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF48)) 
                                         >> (vlTOPp->PPU3__DOT__SP_PX_MAP
                                             [0U] << 1U)))));
        }
    }
    if ((1U & (IData)(vlTOPp->PPU3__DOT__FF40))) {
        vlTOPp->PX_OUT = ((0U == (IData)(vlTOPp->PPU3__DOT__BGWD_PX_MAP))
                           ? (IData)(vlTOPp->PX_OUT)
                           : (IData)(vlTOPp->PPU3__DOT__BGWD_PX_DATA));
    }
    if ((2U & (IData)(vlTOPp->PPU3__DOT__FF40))) {
        if (((~ (vlTOPp->PPU3__DOT__SP_PRIPN[9U] >> 1U)) 
             & (0U != vlTOPp->PPU3__DOT__SP_PX_MAP[9U]))) {
            vlTOPp->PX_OUT = ((1U & vlTOPp->PPU3__DOT__SP_PRIPN
                               [9U]) ? ((2U & (((0xfcU 
                                                 & (IData)(vlTOPp->PPU3__DOT__FF49)) 
                                                >> 
                                                (1U 
                                                 | (vlTOPp->PPU3__DOT__SP_PX_MAP
                                                    [9U] 
                                                    << 1U))) 
                                               << 1U)) 
                                        | (1U & ((0xfcU 
                                                  & (IData)(vlTOPp->PPU3__DOT__FF49)) 
                                                 >> 
                                                 (vlTOPp->PPU3__DOT__SP_PX_MAP
                                                  [9U] 
                                                  << 1U))))
                               : ((2U & (((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF48)) 
                                          >> (1U | 
                                              (vlTOPp->PPU3__DOT__SP_PX_MAP
                                               [9U] 
                                               << 1U))) 
                                         << 1U)) | 
                                  (1U & ((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF48)) 
                                         >> (vlTOPp->PPU3__DOT__SP_PX_MAP
                                             [9U] << 1U)))));
        }
        if (((~ (vlTOPp->PPU3__DOT__SP_PRIPN[8U] >> 1U)) 
             & (0U != vlTOPp->PPU3__DOT__SP_PX_MAP[8U]))) {
            vlTOPp->PX_OUT = ((1U & vlTOPp->PPU3__DOT__SP_PRIPN
                               [8U]) ? ((2U & (((0xfcU 
                                                 & (IData)(vlTOPp->PPU3__DOT__FF49)) 
                                                >> 
                                                (1U 
                                                 | (vlTOPp->PPU3__DOT__SP_PX_MAP
                                                    [8U] 
                                                    << 1U))) 
                                               << 1U)) 
                                        | (1U & ((0xfcU 
                                                  & (IData)(vlTOPp->PPU3__DOT__FF49)) 
                                                 >> 
                                                 (vlTOPp->PPU3__DOT__SP_PX_MAP
                                                  [8U] 
                                                  << 1U))))
                               : ((2U & (((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF48)) 
                                          >> (1U | 
                                              (vlTOPp->PPU3__DOT__SP_PX_MAP
                                               [8U] 
                                               << 1U))) 
                                         << 1U)) | 
                                  (1U & ((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF48)) 
                                         >> (vlTOPp->PPU3__DOT__SP_PX_MAP
                                             [8U] << 1U)))));
        }
        if (((~ (vlTOPp->PPU3__DOT__SP_PRIPN[7U] >> 1U)) 
             & (0U != vlTOPp->PPU3__DOT__SP_PX_MAP[7U]))) {
            vlTOPp->PX_OUT = ((1U & vlTOPp->PPU3__DOT__SP_PRIPN
                               [7U]) ? ((2U & (((0xfcU 
                                                 & (IData)(vlTOPp->PPU3__DOT__FF49)) 
                                                >> 
                                                (1U 
                                                 | (vlTOPp->PPU3__DOT__SP_PX_MAP
                                                    [7U] 
                                                    << 1U))) 
                                               << 1U)) 
                                        | (1U & ((0xfcU 
                                                  & (IData)(vlTOPp->PPU3__DOT__FF49)) 
                                                 >> 
                                                 (vlTOPp->PPU3__DOT__SP_PX_MAP
                                                  [7U] 
                                                  << 1U))))
                               : ((2U & (((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF48)) 
                                          >> (1U | 
                                              (vlTOPp->PPU3__DOT__SP_PX_MAP
                                               [7U] 
                                               << 1U))) 
                                         << 1U)) | 
                                  (1U & ((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF48)) 
                                         >> (vlTOPp->PPU3__DOT__SP_PX_MAP
                                             [7U] << 1U)))));
        }
        if (((~ (vlTOPp->PPU3__DOT__SP_PRIPN[6U] >> 1U)) 
             & (0U != vlTOPp->PPU3__DOT__SP_PX_MAP[6U]))) {
            vlTOPp->PX_OUT = ((1U & vlTOPp->PPU3__DOT__SP_PRIPN
                               [6U]) ? ((2U & (((0xfcU 
                                                 & (IData)(vlTOPp->PPU3__DOT__FF49)) 
                                                >> 
                                                (1U 
                                                 | (vlTOPp->PPU3__DOT__SP_PX_MAP
                                                    [6U] 
                                                    << 1U))) 
                                               << 1U)) 
                                        | (1U & ((0xfcU 
                                                  & (IData)(vlTOPp->PPU3__DOT__FF49)) 
                                                 >> 
                                                 (vlTOPp->PPU3__DOT__SP_PX_MAP
                                                  [6U] 
                                                  << 1U))))
                               : ((2U & (((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF48)) 
                                          >> (1U | 
                                              (vlTOPp->PPU3__DOT__SP_PX_MAP
                                               [6U] 
                                               << 1U))) 
                                         << 1U)) | 
                                  (1U & ((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF48)) 
                                         >> (vlTOPp->PPU3__DOT__SP_PX_MAP
                                             [6U] << 1U)))));
        }
        if (((~ (vlTOPp->PPU3__DOT__SP_PRIPN[5U] >> 1U)) 
             & (0U != vlTOPp->PPU3__DOT__SP_PX_MAP[5U]))) {
            vlTOPp->PX_OUT = ((1U & vlTOPp->PPU3__DOT__SP_PRIPN
                               [5U]) ? ((2U & (((0xfcU 
                                                 & (IData)(vlTOPp->PPU3__DOT__FF49)) 
                                                >> 
                                                (1U 
                                                 | (vlTOPp->PPU3__DOT__SP_PX_MAP
                                                    [5U] 
                                                    << 1U))) 
                                               << 1U)) 
                                        | (1U & ((0xfcU 
                                                  & (IData)(vlTOPp->PPU3__DOT__FF49)) 
                                                 >> 
                                                 (vlTOPp->PPU3__DOT__SP_PX_MAP
                                                  [5U] 
                                                  << 1U))))
                               : ((2U & (((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF48)) 
                                          >> (1U | 
                                              (vlTOPp->PPU3__DOT__SP_PX_MAP
                                               [5U] 
                                               << 1U))) 
                                         << 1U)) | 
                                  (1U & ((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF48)) 
                                         >> (vlTOPp->PPU3__DOT__SP_PX_MAP
                                             [5U] << 1U)))));
        }
        if (((~ (vlTOPp->PPU3__DOT__SP_PRIPN[4U] >> 1U)) 
             & (0U != vlTOPp->PPU3__DOT__SP_PX_MAP[4U]))) {
            vlTOPp->PX_OUT = ((1U & vlTOPp->PPU3__DOT__SP_PRIPN
                               [4U]) ? ((2U & (((0xfcU 
                                                 & (IData)(vlTOPp->PPU3__DOT__FF49)) 
                                                >> 
                                                (1U 
                                                 | (vlTOPp->PPU3__DOT__SP_PX_MAP
                                                    [4U] 
                                                    << 1U))) 
                                               << 1U)) 
                                        | (1U & ((0xfcU 
                                                  & (IData)(vlTOPp->PPU3__DOT__FF49)) 
                                                 >> 
                                                 (vlTOPp->PPU3__DOT__SP_PX_MAP
                                                  [4U] 
                                                  << 1U))))
                               : ((2U & (((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF48)) 
                                          >> (1U | 
                                              (vlTOPp->PPU3__DOT__SP_PX_MAP
                                               [4U] 
                                               << 1U))) 
                                         << 1U)) | 
                                  (1U & ((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF48)) 
                                         >> (vlTOPp->PPU3__DOT__SP_PX_MAP
                                             [4U] << 1U)))));
        }
        if (((~ (vlTOPp->PPU3__DOT__SP_PRIPN[3U] >> 1U)) 
             & (0U != vlTOPp->PPU3__DOT__SP_PX_MAP[3U]))) {
            vlTOPp->PX_OUT = ((1U & vlTOPp->PPU3__DOT__SP_PRIPN
                               [3U]) ? ((2U & (((0xfcU 
                                                 & (IData)(vlTOPp->PPU3__DOT__FF49)) 
                                                >> 
                                                (1U 
                                                 | (vlTOPp->PPU3__DOT__SP_PX_MAP
                                                    [3U] 
                                                    << 1U))) 
                                               << 1U)) 
                                        | (1U & ((0xfcU 
                                                  & (IData)(vlTOPp->PPU3__DOT__FF49)) 
                                                 >> 
                                                 (vlTOPp->PPU3__DOT__SP_PX_MAP
                                                  [3U] 
                                                  << 1U))))
                               : ((2U & (((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF48)) 
                                          >> (1U | 
                                              (vlTOPp->PPU3__DOT__SP_PX_MAP
                                               [3U] 
                                               << 1U))) 
                                         << 1U)) | 
                                  (1U & ((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF48)) 
                                         >> (vlTOPp->PPU3__DOT__SP_PX_MAP
                                             [3U] << 1U)))));
        }
        if (((~ (vlTOPp->PPU3__DOT__SP_PRIPN[2U] >> 1U)) 
             & (0U != vlTOPp->PPU3__DOT__SP_PX_MAP[2U]))) {
            vlTOPp->PX_OUT = ((1U & vlTOPp->PPU3__DOT__SP_PRIPN
                               [2U]) ? ((2U & (((0xfcU 
                                                 & (IData)(vlTOPp->PPU3__DOT__FF49)) 
                                                >> 
                                                (1U 
                                                 | (vlTOPp->PPU3__DOT__SP_PX_MAP
                                                    [2U] 
                                                    << 1U))) 
                                               << 1U)) 
                                        | (1U & ((0xfcU 
                                                  & (IData)(vlTOPp->PPU3__DOT__FF49)) 
                                                 >> 
                                                 (vlTOPp->PPU3__DOT__SP_PX_MAP
                                                  [2U] 
                                                  << 1U))))
                               : ((2U & (((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF48)) 
                                          >> (1U | 
                                              (vlTOPp->PPU3__DOT__SP_PX_MAP
                                               [2U] 
                                               << 1U))) 
                                         << 1U)) | 
                                  (1U & ((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF48)) 
                                         >> (vlTOPp->PPU3__DOT__SP_PX_MAP
                                             [2U] << 1U)))));
        }
        if (((~ (vlTOPp->PPU3__DOT__SP_PRIPN[1U] >> 1U)) 
             & (0U != vlTOPp->PPU3__DOT__SP_PX_MAP[1U]))) {
            vlTOPp->PX_OUT = ((1U & vlTOPp->PPU3__DOT__SP_PRIPN
                               [1U]) ? ((2U & (((0xfcU 
                                                 & (IData)(vlTOPp->PPU3__DOT__FF49)) 
                                                >> 
                                                (1U 
                                                 | (vlTOPp->PPU3__DOT__SP_PX_MAP
                                                    [1U] 
                                                    << 1U))) 
                                               << 1U)) 
                                        | (1U & ((0xfcU 
                                                  & (IData)(vlTOPp->PPU3__DOT__FF49)) 
                                                 >> 
                                                 (vlTOPp->PPU3__DOT__SP_PX_MAP
                                                  [1U] 
                                                  << 1U))))
                               : ((2U & (((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF48)) 
                                          >> (1U | 
                                              (vlTOPp->PPU3__DOT__SP_PX_MAP
                                               [1U] 
                                               << 1U))) 
                                         << 1U)) | 
                                  (1U & ((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF48)) 
                                         >> (vlTOPp->PPU3__DOT__SP_PX_MAP
                                             [1U] << 1U)))));
        }
        if (((~ (vlTOPp->PPU3__DOT__SP_PRIPN[0U] >> 1U)) 
             & (0U != vlTOPp->PPU3__DOT__SP_PX_MAP[0U]))) {
            vlTOPp->PX_OUT = ((1U & vlTOPp->PPU3__DOT__SP_PRIPN
                               [0U]) ? ((2U & (((0xfcU 
                                                 & (IData)(vlTOPp->PPU3__DOT__FF49)) 
                                                >> 
                                                (1U 
                                                 | (vlTOPp->PPU3__DOT__SP_PX_MAP
                                                    [0U] 
                                                    << 1U))) 
                                               << 1U)) 
                                        | (1U & ((0xfcU 
                                                  & (IData)(vlTOPp->PPU3__DOT__FF49)) 
                                                 >> 
                                                 (vlTOPp->PPU3__DOT__SP_PX_MAP
                                                  [0U] 
                                                  << 1U))))
                               : ((2U & (((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF48)) 
                                          >> (1U | 
                                              (vlTOPp->PPU3__DOT__SP_PX_MAP
                                               [0U] 
                                               << 1U))) 
                                         << 1U)) | 
                                  (1U & ((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF48)) 
                                         >> (vlTOPp->PPU3__DOT__SP_PX_MAP
                                             [0U] << 1U)))));
        }
    }
    vlTOPp->PPU3__DOT__IRQ_STAT_NEXT = ((((((IData)(vlTOPp->PPU3__DOT__FF41_NEXT) 
                                            >> 6U) 
                                           & ((IData)(vlTOPp->PPU3__DOT__LY) 
                                              == (IData)(vlTOPp->PPU3__DOT__FF45))) 
                                          | (((IData)(vlTOPp->PPU3__DOT__FF41_NEXT) 
                                              >> 3U) 
                                             & (2U 
                                                == vlTOPp->PPU3__DOT__PPU_STATE))) 
                                         | (((IData)(vlTOPp->PPU3__DOT__FF41_NEXT) 
                                             >> 5U) 
                                            & (0U == vlTOPp->PPU3__DOT__PPU_STATE))) 
                                        | ((((IData)(vlTOPp->PPU3__DOT__FF41_NEXT) 
                                             >> 4U) 
                                            | ((IData)(vlTOPp->PPU3__DOT__FF41_NEXT) 
                                               >> 5U)) 
                                           & (3U == vlTOPp->PPU3__DOT__PPU_STATE)));
    vlTOPp->PPU3__DOT__IRQ_STAT_NEXT = ((IData)(vlTOPp->PPU3__DOT__IRQ_STAT_NEXT) 
                                        & ((IData)(vlTOPp->PPU3__DOT__FF40) 
                                           >> 7U));
    vlTOPp->IRQ_LCDC = ((IData)(vlTOPp->PPU3__DOT__IRQ_STAT_NEXT) 
                        & (~ (IData)(vlTOPp->PPU3__DOT__IRQ_STAT)));
}

VL_INLINE_OPT void VPPU3::_combo__TOP__3(VPPU3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPPU3::_combo__TOP__3\n"); );
    VPPU3* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->PPU3__DOT__FF46_NEXT = (((IData)(vlTOPp->WR) 
                                     & (0xff46U == (IData)(vlTOPp->ADDR)))
                                     ? (IData)(vlTOPp->MMIO_DATA_out)
                                     : (IData)(vlTOPp->PPU3__DOT__FF46));
    vlTOPp->PPU3__DOT__FF49_NEXT = (((IData)(vlTOPp->WR) 
                                     & (0xff49U == (IData)(vlTOPp->ADDR)))
                                     ? (IData)(vlTOPp->MMIO_DATA_out)
                                     : (IData)(vlTOPp->PPU3__DOT__FF49));
    vlTOPp->PPU3__DOT__FF48_NEXT = (((IData)(vlTOPp->WR) 
                                     & (0xff48U == (IData)(vlTOPp->ADDR)))
                                     ? (IData)(vlTOPp->MMIO_DATA_out)
                                     : (IData)(vlTOPp->PPU3__DOT__FF48));
    vlTOPp->PPU3__DOT__FF47_NEXT = (((IData)(vlTOPp->WR) 
                                     & (0xff47U == (IData)(vlTOPp->ADDR)))
                                     ? (IData)(vlTOPp->MMIO_DATA_out)
                                     : (IData)(vlTOPp->PPU3__DOT__FF47));
    vlTOPp->PPU3__DOT__FF45_NEXT = (((IData)(vlTOPp->WR) 
                                     & (0xff45U == (IData)(vlTOPp->ADDR)))
                                     ? (IData)(vlTOPp->MMIO_DATA_out)
                                     : (IData)(vlTOPp->PPU3__DOT__FF45));
    vlTOPp->PPU3__DOT__FF4B_NEXT = (((IData)(vlTOPp->WR) 
                                     & (0xff4bU == (IData)(vlTOPp->ADDR)))
                                     ? (IData)(vlTOPp->MMIO_DATA_out)
                                     : (IData)(vlTOPp->PPU3__DOT__FF4B));
    vlTOPp->PPU3__DOT__FF4A_NEXT = (((IData)(vlTOPp->WR) 
                                     & (0xff4aU == (IData)(vlTOPp->ADDR)))
                                     ? (IData)(vlTOPp->MMIO_DATA_out)
                                     : (IData)(vlTOPp->PPU3__DOT__FF4A));
    vlTOPp->PPU3__DOT__FF42_NEXT = (((IData)(vlTOPp->WR) 
                                     & (0xff42U == (IData)(vlTOPp->ADDR)))
                                     ? (IData)(vlTOPp->MMIO_DATA_out)
                                     : (IData)(vlTOPp->PPU3__DOT__FF42));
    vlTOPp->PPU3__DOT__FF43_NEXT = (((IData)(vlTOPp->WR) 
                                     & (0xff43U == (IData)(vlTOPp->ADDR)))
                                     ? (IData)(vlTOPp->MMIO_DATA_out)
                                     : (IData)(vlTOPp->PPU3__DOT__FF43));
    vlTOPp->PPU3__DOT__FF40_NEXT = (((IData)(vlTOPp->WR) 
                                     & (0xff40U == (IData)(vlTOPp->ADDR)))
                                     ? (IData)(vlTOPp->MMIO_DATA_out)
                                     : (IData)(vlTOPp->PPU3__DOT__FF40));
    vlTOPp->MMIO_DATA_in = (((((((((0xff40U == (IData)(vlTOPp->ADDR)) 
                                   | (0xff41U == (IData)(vlTOPp->ADDR))) 
                                  | (0xff42U == (IData)(vlTOPp->ADDR))) 
                                 | (0xff43U == (IData)(vlTOPp->ADDR))) 
                                | (0xff44U == (IData)(vlTOPp->ADDR))) 
                               | (0xff45U == (IData)(vlTOPp->ADDR))) 
                              | (0xff46U == (IData)(vlTOPp->ADDR))) 
                             | (0xff47U == (IData)(vlTOPp->ADDR)))
                             ? ((0xff40U == (IData)(vlTOPp->ADDR))
                                 ? (IData)(vlTOPp->PPU3__DOT__FF40)
                                 : ((0xff41U == (IData)(vlTOPp->ADDR))
                                     ? (0x80U | (0x7fU 
                                                 & (IData)(vlTOPp->PPU3__DOT__FF41)))
                                     : ((0xff42U == (IData)(vlTOPp->ADDR))
                                         ? (IData)(vlTOPp->PPU3__DOT__FF42)
                                         : ((0xff43U 
                                             == (IData)(vlTOPp->ADDR))
                                             ? (IData)(vlTOPp->PPU3__DOT__FF43)
                                             : ((0xff44U 
                                                 == (IData)(vlTOPp->ADDR))
                                                 ? (IData)(vlTOPp->PPU3__DOT__LY)
                                                 : 
                                                ((0xff45U 
                                                  == (IData)(vlTOPp->ADDR))
                                                  ? (IData)(vlTOPp->PPU3__DOT__FF45)
                                                  : 
                                                 ((0xff46U 
                                                   == (IData)(vlTOPp->ADDR))
                                                   ? (IData)(vlTOPp->PPU3__DOT__FF46)
                                                   : (IData)(vlTOPp->PPU3__DOT__FF47))))))))
                             : ((0xff48U == (IData)(vlTOPp->ADDR))
                                 ? (IData)(vlTOPp->PPU3__DOT__FF48)
                                 : ((0xff49U == (IData)(vlTOPp->ADDR))
                                     ? (IData)(vlTOPp->PPU3__DOT__FF49)
                                     : ((0xff4aU == (IData)(vlTOPp->ADDR))
                                         ? (IData)(vlTOPp->PPU3__DOT__FF4A)
                                         : ((0xff4bU 
                                             == (IData)(vlTOPp->ADDR))
                                             ? (IData)(vlTOPp->PPU3__DOT__FF4B)
                                             : 0xffU)))));
    vlTOPp->PPU3__DOT__FF41_NEXT = (((IData)(vlTOPp->WR) 
                                     & (0xff41U == (IData)(vlTOPp->ADDR)))
                                     ? ((0xf8U & (IData)(vlTOPp->MMIO_DATA_out)) 
                                        | (7U & (IData)(vlTOPp->PPU3__DOT__FF41)))
                                     : ((0xf8U & (IData)(vlTOPp->PPU3__DOT__FF41)) 
                                        | ((((IData)(vlTOPp->PPU3__DOT__FF45) 
                                             == (IData)(vlTOPp->PPU3__DOT__LY)) 
                                            << 2U) 
                                           | (IData)(vlTOPp->PPU_MODE))));
    vlTOPp->PPU3__DOT__IRQ_STAT_NEXT = ((((((IData)(vlTOPp->PPU3__DOT__FF41_NEXT) 
                                            >> 6U) 
                                           & ((IData)(vlTOPp->PPU3__DOT__LY) 
                                              == (IData)(vlTOPp->PPU3__DOT__FF45))) 
                                          | (((IData)(vlTOPp->PPU3__DOT__FF41_NEXT) 
                                              >> 3U) 
                                             & (2U 
                                                == vlTOPp->PPU3__DOT__PPU_STATE))) 
                                         | (((IData)(vlTOPp->PPU3__DOT__FF41_NEXT) 
                                             >> 5U) 
                                            & (0U == vlTOPp->PPU3__DOT__PPU_STATE))) 
                                        | ((((IData)(vlTOPp->PPU3__DOT__FF41_NEXT) 
                                             >> 4U) 
                                            | ((IData)(vlTOPp->PPU3__DOT__FF41_NEXT) 
                                               >> 5U)) 
                                           & (3U == vlTOPp->PPU3__DOT__PPU_STATE)));
    vlTOPp->PPU3__DOT__IRQ_STAT_NEXT = ((IData)(vlTOPp->PPU3__DOT__IRQ_STAT_NEXT) 
                                        & ((IData)(vlTOPp->PPU3__DOT__FF40) 
                                           >> 7U));
    vlTOPp->IRQ_LCDC = ((IData)(vlTOPp->PPU3__DOT__IRQ_STAT_NEXT) 
                        & (~ (IData)(vlTOPp->PPU3__DOT__IRQ_STAT)));
}

void VPPU3::_eval(VPPU3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPPU3::_eval\n"); );
    VPPU3* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    vlTOPp->_combo__TOP__3(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

void VPPU3::_eval_initial(VPPU3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPPU3::_eval_initial\n"); );
    VPPU3* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

void VPPU3::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPPU3::final\n"); );
    // Variables
    VPPU3__Syms* __restrict vlSymsp = this->__VlSymsp;
    VPPU3* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VPPU3::_eval_settle(VPPU3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPPU3::_eval_settle\n"); );
    VPPU3* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
}

VL_INLINE_OPT QData VPPU3::_change_request(VPPU3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPPU3::_change_request\n"); );
    VPPU3* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VPPU3::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPPU3::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((WR & 0xfeU))) {
        Verilated::overWidthError("WR");}
    if (VL_UNLIKELY((RD & 0xfeU))) {
        Verilated::overWidthError("RD");}
}
#endif  // VL_DEBUG

void VPPU3::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPPU3::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    rst = VL_RAND_RESET_I(1);
    ADDR = VL_RAND_RESET_I(16);
    WR = VL_RAND_RESET_I(1);
    RD = VL_RAND_RESET_I(1);
    MMIO_DATA_out = VL_RAND_RESET_I(8);
    MMIO_DATA_in = VL_RAND_RESET_I(8);
    IRQ_V_BLANK = VL_RAND_RESET_I(1);
    IRQ_LCDC = VL_RAND_RESET_I(1);
    PPU_MODE = VL_RAND_RESET_I(2);
    PPU_RD = VL_RAND_RESET_I(1);
    PPU_ADDR = VL_RAND_RESET_I(16);
    PPU_DATA_in = VL_RAND_RESET_I(8);
    PX_OUT = VL_RAND_RESET_I(2);
    PX_valid = VL_RAND_RESET_I(1);
    PPU3__DOT__FF40 = VL_RAND_RESET_I(8);
    PPU3__DOT__FF40_NEXT = VL_RAND_RESET_I(8);
    PPU3__DOT__FF41 = VL_RAND_RESET_I(8);
    PPU3__DOT__FF41_NEXT = VL_RAND_RESET_I(8);
    PPU3__DOT__FF42 = VL_RAND_RESET_I(8);
    PPU3__DOT__FF42_NEXT = VL_RAND_RESET_I(8);
    PPU3__DOT__FF43 = VL_RAND_RESET_I(8);
    PPU3__DOT__FF43_NEXT = VL_RAND_RESET_I(8);
    PPU3__DOT__FF45 = VL_RAND_RESET_I(8);
    PPU3__DOT__FF45_NEXT = VL_RAND_RESET_I(8);
    PPU3__DOT__FF46 = VL_RAND_RESET_I(8);
    PPU3__DOT__FF46_NEXT = VL_RAND_RESET_I(8);
    PPU3__DOT__FF47 = VL_RAND_RESET_I(8);
    PPU3__DOT__FF47_NEXT = VL_RAND_RESET_I(8);
    PPU3__DOT__FF48 = VL_RAND_RESET_I(8);
    PPU3__DOT__FF48_NEXT = VL_RAND_RESET_I(8);
    PPU3__DOT__FF49 = VL_RAND_RESET_I(8);
    PPU3__DOT__FF49_NEXT = VL_RAND_RESET_I(8);
    PPU3__DOT__FF4A = VL_RAND_RESET_I(8);
    PPU3__DOT__FF4A_NEXT = VL_RAND_RESET_I(8);
    PPU3__DOT__FF4B = VL_RAND_RESET_I(8);
    PPU3__DOT__FF4B_NEXT = VL_RAND_RESET_I(8);
    PPU3__DOT__PPU_STATE = 0;
    PPU3__DOT__PPU_STATE_NEXT = 0;
    PPU3__DOT__LX = VL_RAND_RESET_I(8);
    PPU3__DOT__LX_NEXT = VL_RAND_RESET_I(8);
    PPU3__DOT__LY = VL_RAND_RESET_I(8);
    PPU3__DOT__LY_NEXT = VL_RAND_RESET_I(8);
    PPU3__DOT__OAM_SEARCH_GO = VL_RAND_RESET_I(1);
    PPU3__DOT__BGWD_RENDER_GO = VL_RAND_RESET_I(1);
    PPU3__DOT__SHIFT_REG_GO = VL_RAND_RESET_I(1);
    PPU3__DOT__SP_MAP = VL_RAND_RESET_I(8);
    PPU3__DOT__PPU_CNT = 0;
    PPU3__DOT__PPU_CNT_NEXT = 0;
    PPU3__DOT__SCX_CNT = VL_RAND_RESET_I(3);
    PPU3__DOT__SCX_CNT_NEXT = VL_RAND_RESET_I(3);
    PPU3__DOT__sp_table_cnt = VL_RAND_RESET_I(4);
    { int __Vi0=0; for (; __Vi0<10; ++__Vi0) {
            PPU3__DOT__sp_name_table[__Vi0] = VL_RAND_RESET_I(6);
    }}
    { int __Vi0=0; for (; __Vi0<10; ++__Vi0) {
            PPU3__DOT__sp_name_table_x[__Vi0] = VL_RAND_RESET_I(8);
    }}
    { int __Vi0=0; for (; __Vi0<10; ++__Vi0) {
            PPU3__DOT__sp_y_table[__Vi0] = VL_RAND_RESET_I(8);
    }}
    { int __Vi0=0; for (; __Vi0<10; ++__Vi0) {
            PPU3__DOT__sp_x_table[__Vi0] = VL_RAND_RESET_I(8);
    }}
    PPU3__DOT__sp_found = VL_RAND_RESET_I(1);
    PPU3__DOT__isHitSP = VL_RAND_RESET_I(1);
    PPU3__DOT__sp_to_fetch = VL_RAND_RESET_I(4);
    PPU3__DOT__sp_not_used = VL_RAND_RESET_I(10);
    PPU3__DOT__sp_not_used_next = VL_RAND_RESET_I(10);
    PPU3__DOT__SP_RENDER_GO = VL_RAND_RESET_I(1);
    PPU3__DOT__SP_SHIFT_REG_LOAD = VL_RAND_RESET_I(10);
    PPU3__DOT__SP_TILE_DATA0 = VL_RAND_RESET_I(9);
    PPU3__DOT__SP_TILE_DATA1 = VL_RAND_RESET_I(9);
    { int __Vi0=0; for (; __Vi0<10; ++__Vi0) {
            PPU3__DOT__SP_PX_MAP[__Vi0] = VL_RAND_RESET_I(2);
    }}
    PPU3__DOT__SP_NEXT_SLOT = VL_RAND_RESET_I(4);
    PPU3__DOT__SP_NEXT_SLOT_NEXT = VL_RAND_RESET_I(4);
    PPU3__DOT__SP_CNT = VL_RAND_RESET_I(3);
    PPU3__DOT__SP_FLAG = VL_RAND_RESET_I(8);
    { int __Vi0=0; for (; __Vi0<10; ++__Vi0) {
            PPU3__DOT__SP_PRIPN[__Vi0] = VL_RAND_RESET_I(2);
    }}
    { int __Vi0=0; for (; __Vi0<10; ++__Vi0) {
            PPU3__DOT__SP_PRIPN_NEXT[__Vi0] = VL_RAND_RESET_I(2);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
            PPU3__DOT____Vcellinp__SP_SHIFT_REG9__data[__Vi0] = VL_RAND_RESET_I(8);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
            PPU3__DOT____Vcellinp__SP_SHIFT_REG8__data[__Vi0] = VL_RAND_RESET_I(8);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
            PPU3__DOT____Vcellinp__SP_SHIFT_REG7__data[__Vi0] = VL_RAND_RESET_I(8);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
            PPU3__DOT____Vcellinp__SP_SHIFT_REG6__data[__Vi0] = VL_RAND_RESET_I(8);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
            PPU3__DOT____Vcellinp__SP_SHIFT_REG5__data[__Vi0] = VL_RAND_RESET_I(8);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
            PPU3__DOT____Vcellinp__SP_SHIFT_REG4__data[__Vi0] = VL_RAND_RESET_I(8);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
            PPU3__DOT____Vcellinp__SP_SHIFT_REG3__data[__Vi0] = VL_RAND_RESET_I(8);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
            PPU3__DOT____Vcellinp__SP_SHIFT_REG2__data[__Vi0] = VL_RAND_RESET_I(8);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
            PPU3__DOT____Vcellinp__SP_SHIFT_REG1__data[__Vi0] = VL_RAND_RESET_I(8);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
            PPU3__DOT____Vcellinp__SP_SHIFT_REG0__data[__Vi0] = VL_RAND_RESET_I(8);
    }}
    PPU3__DOT__isHitWD = VL_RAND_RESET_I(1);
    PPU3__DOT__BGWD_CNT = VL_RAND_RESET_I(3);
    PPU3__DOT__BGWD_MAP = VL_RAND_RESET_I(8);
    PPU3__DOT__BGWD_TILE_DATA0 = VL_RAND_RESET_I(8);
    PPU3__DOT__BGWD_TILE_DATA1 = VL_RAND_RESET_I(8);
    PPU3__DOT__isFetchWD = VL_RAND_RESET_I(1);
    PPU3__DOT__isFetchWD_NEXT = VL_RAND_RESET_I(1);
    PPU3__DOT__FIRST_FETCH_WD_DONE = VL_RAND_RESET_I(1);
    PPU3__DOT__FIRST_FETCH_WD_DONE_NEXT = VL_RAND_RESET_I(1);
    PPU3__DOT__BGWD_SHIFT_REG_SEL = VL_RAND_RESET_I(1);
    PPU3__DOT__BGWD_SHIFT_REG_SEL_NEXT = VL_RAND_RESET_I(1);
    PPU3__DOT__BGWD_SHIFT_REG_LOAD = VL_RAND_RESET_I(2);
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
            PPU3__DOT____Vcellinp__BGWD_SHIFT_REG_A__data[__Vi0] = VL_RAND_RESET_I(8);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
            PPU3__DOT____Vcellinp__BGWD_SHIFT_REG_B__data[__Vi0] = VL_RAND_RESET_I(8);
    }}
    PPU3__DOT__BGWD_PX_MAP = VL_RAND_RESET_I(2);
    PPU3__DOT__BGWD_PX_DATA = VL_RAND_RESET_I(2);
    PPU3__DOT__BGWD_SHIFT_REG_A_VALID = VL_RAND_RESET_I(1);
    PPU3__DOT__BGWD_SHIFT_REG_A_VALID_NEXT = VL_RAND_RESET_I(1);
    PPU3__DOT__BGWD_SHIFT_REG_B_VALID = VL_RAND_RESET_I(1);
    PPU3__DOT__BGWD_SHIFT_REG_B_VALID_NEXT = VL_RAND_RESET_I(1);
    PPU3__DOT__RENDER_CNT = VL_RAND_RESET_I(3);
    PPU3__DOT__RENDER_CNT_NEXT = VL_RAND_RESET_I(3);
    PPU3__DOT__IRQ_STAT = VL_RAND_RESET_I(1);
    PPU3__DOT__IRQ_STAT_NEXT = VL_RAND_RESET_I(1);
    PPU3__DOT____Vlvbound2 = VL_RAND_RESET_I(2);
    PPU3__DOT____Vlvbound3 = VL_RAND_RESET_I(2);
    PPU3__DOT____Vlvbound4 = VL_RAND_RESET_I(1);
    PPU3__DOT____Vlvbound5 = VL_RAND_RESET_I(1);
    PPU3__DOT____Vlvbound6 = VL_RAND_RESET_I(2);
    PPU3__DOT____Vlvbound9 = VL_RAND_RESET_I(8);
    PPU3__DOT____Vlvbound10 = VL_RAND_RESET_I(6);
    PPU3__DOT____Vlvbound11 = VL_RAND_RESET_I(8);
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
            PPU3__DOT__SP_SHIFT_REG9__DOT__shift_reg[__Vi0] = VL_RAND_RESET_I(8);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
            PPU3__DOT__SP_SHIFT_REG8__DOT__shift_reg[__Vi0] = VL_RAND_RESET_I(8);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
            PPU3__DOT__SP_SHIFT_REG7__DOT__shift_reg[__Vi0] = VL_RAND_RESET_I(8);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
            PPU3__DOT__SP_SHIFT_REG6__DOT__shift_reg[__Vi0] = VL_RAND_RESET_I(8);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
            PPU3__DOT__SP_SHIFT_REG5__DOT__shift_reg[__Vi0] = VL_RAND_RESET_I(8);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
            PPU3__DOT__SP_SHIFT_REG4__DOT__shift_reg[__Vi0] = VL_RAND_RESET_I(8);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
            PPU3__DOT__SP_SHIFT_REG3__DOT__shift_reg[__Vi0] = VL_RAND_RESET_I(8);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
            PPU3__DOT__SP_SHIFT_REG2__DOT__shift_reg[__Vi0] = VL_RAND_RESET_I(8);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
            PPU3__DOT__SP_SHIFT_REG1__DOT__shift_reg[__Vi0] = VL_RAND_RESET_I(8);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
            PPU3__DOT__SP_SHIFT_REG0__DOT__shift_reg[__Vi0] = VL_RAND_RESET_I(8);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
            PPU3__DOT__BGWD_SHIFT_REG_A__DOT__shift_reg[__Vi0] = VL_RAND_RESET_I(8);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
            PPU3__DOT__BGWD_SHIFT_REG_B__DOT__shift_reg[__Vi0] = VL_RAND_RESET_I(8);
    }}
}
