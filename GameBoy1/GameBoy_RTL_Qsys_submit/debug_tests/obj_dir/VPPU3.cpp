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
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("PPU3.sv", 7, "",
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
    vlSymsp->__Vm_activity = true;
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
            VL_FATAL_MT("PPU3.sv", 7, "",
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
    CData/*7:0*/ __Vdly__PPU3__DOT__FF45;
    CData/*7:0*/ __Vdly__PPU3__DOT__FF40;
    CData/*7:0*/ __Vdly__PPU3__DOT__LY;
    CData/*1:0*/ __Vdly__PPU_MODE;
    CData/*3:0*/ __Vdly__PPU3__DOT__sprites_loaded;
    CData/*0:0*/ __Vdly__PPU3__DOT__sprite_found;
    CData/*3:0*/ __Vdlyvdim0__PPU3__DOT__sprite_x_buff__v0;
    CData/*7:0*/ __Vdlyvval__PPU3__DOT__sprite_x_buff__v0;
    CData/*0:0*/ __Vdlyvset__PPU3__DOT__sprite_x_buff__v0;
    CData/*3:0*/ __Vdlyvdim0__PPU3__DOT__sprite_y_buff__v0;
    CData/*7:0*/ __Vdlyvval__PPU3__DOT__sprite_y_buff__v0;
    CData/*0:0*/ __Vdlyvset__PPU3__DOT__sprite_y_buff__v0;
    CData/*3:0*/ __Vdlyvdim0__PPU3__DOT__sprite_offset_buff__v0;
    CData/*7:0*/ __Vdlyvval__PPU3__DOT__sprite_offset_buff__v0;
    CData/*0:0*/ __Vdlyvset__PPU3__DOT__sprite_offset_buff__v0;
    CData/*0:0*/ __Vdlyvset__PPU3__DOT__sprite_fifo__DOT__shift_reg__v0;
    CData/*7:0*/ __Vdlyvval__PPU3__DOT__sprite_fifo__DOT__shift_reg__v2;
    CData/*0:0*/ __Vdlyvset__PPU3__DOT__sprite_fifo__DOT__shift_reg__v2;
    CData/*7:0*/ __Vdlyvval__PPU3__DOT__sprite_fifo__DOT__shift_reg__v3;
    CData/*2:0*/ __Vdlyvlsb__PPU3__DOT__sprite_fifo__DOT__shift_reg__v4;
    CData/*6:0*/ __Vdlyvval__PPU3__DOT__sprite_fifo__DOT__shift_reg__v4;
    CData/*0:0*/ __Vdlyvset__PPU3__DOT__sprite_fifo__DOT__shift_reg__v4;
    CData/*2:0*/ __Vdlyvlsb__PPU3__DOT__sprite_fifo__DOT__shift_reg__v5;
    CData/*2:0*/ __Vdlyvlsb__PPU3__DOT__sprite_fifo__DOT__shift_reg__v6;
    CData/*6:0*/ __Vdlyvval__PPU3__DOT__sprite_fifo__DOT__shift_reg__v6;
    CData/*2:0*/ __Vdlyvlsb__PPU3__DOT__sprite_fifo__DOT__shift_reg__v7;
    CData/*0:0*/ __Vdlyvset__PPU3__DOT__bg_fifo__DOT__shift_reg__v0;
    CData/*7:0*/ __Vdlyvval__PPU3__DOT__bg_fifo__DOT__shift_reg__v2;
    CData/*0:0*/ __Vdlyvset__PPU3__DOT__bg_fifo__DOT__shift_reg__v2;
    CData/*7:0*/ __Vdlyvval__PPU3__DOT__bg_fifo__DOT__shift_reg__v3;
    CData/*2:0*/ __Vdlyvlsb__PPU3__DOT__bg_fifo__DOT__shift_reg__v4;
    CData/*6:0*/ __Vdlyvval__PPU3__DOT__bg_fifo__DOT__shift_reg__v4;
    CData/*0:0*/ __Vdlyvset__PPU3__DOT__bg_fifo__DOT__shift_reg__v4;
    CData/*2:0*/ __Vdlyvlsb__PPU3__DOT__bg_fifo__DOT__shift_reg__v5;
    CData/*2:0*/ __Vdlyvlsb__PPU3__DOT__bg_fifo__DOT__shift_reg__v6;
    CData/*6:0*/ __Vdlyvval__PPU3__DOT__bg_fifo__DOT__shift_reg__v6;
    CData/*2:0*/ __Vdlyvlsb__PPU3__DOT__bg_fifo__DOT__shift_reg__v7;
    SData/*8:0*/ __Vdly__PPU3__DOT__cycles;
    SData/*15:0*/ __Vdly__PPU_ADDR;
    // Body
    __Vdly__PPU_MODE = vlTOPp->PPU_MODE;
    __Vdly__PPU3__DOT__LY = vlTOPp->PPU3__DOT__LY;
    __Vdly__PPU3__DOT__cycles = vlTOPp->PPU3__DOT__cycles;
    __Vdly__PPU3__DOT__FF45 = vlTOPp->PPU3__DOT__FF45;
    __Vdly__PPU3__DOT__FF40 = vlTOPp->PPU3__DOT__FF40;
    __Vdly__PPU3__DOT__sprite_found = vlTOPp->PPU3__DOT__sprite_found;
    __Vdly__PPU3__DOT__sprites_loaded = vlTOPp->PPU3__DOT__sprites_loaded;
    __Vdlyvset__PPU3__DOT__sprite_offset_buff__v0 = 0U;
    __Vdlyvset__PPU3__DOT__sprite_y_buff__v0 = 0U;
    __Vdlyvset__PPU3__DOT__sprite_x_buff__v0 = 0U;
    __Vdly__PPU_ADDR = vlTOPp->PPU_ADDR;
    __Vdlyvset__PPU3__DOT__bg_fifo__DOT__shift_reg__v0 = 0U;
    __Vdlyvset__PPU3__DOT__bg_fifo__DOT__shift_reg__v2 = 0U;
    __Vdlyvset__PPU3__DOT__bg_fifo__DOT__shift_reg__v4 = 0U;
    __Vdlyvset__PPU3__DOT__sprite_fifo__DOT__shift_reg__v0 = 0U;
    __Vdlyvset__PPU3__DOT__sprite_fifo__DOT__shift_reg__v2 = 0U;
    __Vdlyvset__PPU3__DOT__sprite_fifo__DOT__shift_reg__v4 = 0U;
    if (vlTOPp->rst) {
        vlTOPp->PPU3__DOT__x_pos = 0U;
        __Vdly__PPU3__DOT__cycles = 1U;
        __Vdly__PPU3__DOT__LY = 0U;
        __Vdly__PPU_MODE = 2U;
    } else {
        if ((0x80U & (IData)(vlTOPp->PPU3__DOT__FF40))) {
            __Vdly__PPU3__DOT__cycles = (0x1ffU & ((IData)(1U) 
                                                   + (IData)(vlTOPp->PPU3__DOT__cycles)));
            if ((2U & (IData)(vlTOPp->PPU_MODE))) {
                if ((1U & (IData)(vlTOPp->PPU_MODE))) {
                    __Vdly__PPU3__DOT__LY = vlTOPp->PPU3__DOT__LY;
                } else {
                    if ((0xfe9fU < (IData)(vlTOPp->PPU_ADDR))) {
                        __Vdly__PPU_MODE = 3U;
                    }
                    if ((0x90U <= (IData)(vlTOPp->PPU3__DOT__LY))) {
                        __Vdly__PPU_MODE = 1U;
                    }
                }
            } else {
                if ((1U & (IData)(vlTOPp->PPU_MODE))) {
                    __Vdly__PPU_MODE = 0U;
                } else {
                    if ((0x1c7U <= (IData)(vlTOPp->PPU3__DOT__cycles))) {
                        __Vdly__PPU3__DOT__LY = (0xffU 
                                                 & ((IData)(1U) 
                                                    + (IData)(vlTOPp->PPU3__DOT__LY)));
                        vlTOPp->PPU3__DOT__x_pos = 0U;
                        __Vdly__PPU_MODE = 2U;
                        __Vdly__PPU3__DOT__cycles = 0U;
                    }
                }
            }
        }
    }
    vlTOPp->PPU3__DOT__FF4B = ((IData)(vlTOPp->rst)
                                ? 0U : (((IData)(vlTOPp->WR) 
                                         & (0xff4bU 
                                            == (IData)(vlTOPp->ADDR)))
                                         ? (IData)(vlTOPp->MMIO_DATA_out)
                                         : (IData)(vlTOPp->PPU3__DOT__FF4B)));
    vlTOPp->PPU3__DOT__FF4A = ((IData)(vlTOPp->rst)
                                ? 0U : (((IData)(vlTOPp->WR) 
                                         & (0xff4aU 
                                            == (IData)(vlTOPp->ADDR)))
                                         ? (IData)(vlTOPp->MMIO_DATA_out)
                                         : (IData)(vlTOPp->PPU3__DOT__FF4A)));
    vlTOPp->PPU3__DOT__FF49 = ((IData)(vlTOPp->rst)
                                ? 0U : (((IData)(vlTOPp->WR) 
                                         & (0xff49U 
                                            == (IData)(vlTOPp->ADDR)))
                                         ? (IData)(vlTOPp->MMIO_DATA_out)
                                         : (IData)(vlTOPp->PPU3__DOT__FF49)));
    vlTOPp->PPU3__DOT__FF48 = ((IData)(vlTOPp->rst)
                                ? 0U : (((IData)(vlTOPp->WR) 
                                         & (0xff48U 
                                            == (IData)(vlTOPp->ADDR)))
                                         ? (IData)(vlTOPp->MMIO_DATA_out)
                                         : (IData)(vlTOPp->PPU3__DOT__FF48)));
    vlTOPp->PPU3__DOT__FF47 = ((IData)(vlTOPp->rst)
                                ? 0U : (((IData)(vlTOPp->WR) 
                                         & (0xff47U 
                                            == (IData)(vlTOPp->ADDR)))
                                         ? (IData)(vlTOPp->MMIO_DATA_out)
                                         : (IData)(vlTOPp->PPU3__DOT__FF47)));
    vlTOPp->PPU3__DOT__FF46 = ((IData)(vlTOPp->rst)
                                ? 0U : (((IData)(vlTOPp->WR) 
                                         & (0xff46U 
                                            == (IData)(vlTOPp->ADDR)))
                                         ? (IData)(vlTOPp->MMIO_DATA_out)
                                         : (IData)(vlTOPp->PPU3__DOT__FF46)));
    vlTOPp->PPU3__DOT__FF42 = ((IData)(vlTOPp->rst)
                                ? 0U : (((IData)(vlTOPp->WR) 
                                         & (0xff42U 
                                            == (IData)(vlTOPp->ADDR)))
                                         ? (IData)(vlTOPp->MMIO_DATA_out)
                                         : (IData)(vlTOPp->PPU3__DOT__FF42)));
    vlTOPp->PPU3__DOT__FF43 = ((IData)(vlTOPp->rst)
                                ? 0U : (((IData)(vlTOPp->WR) 
                                         & (0xff43U 
                                            == (IData)(vlTOPp->ADDR)))
                                         ? (IData)(vlTOPp->MMIO_DATA_out)
                                         : (IData)(vlTOPp->PPU3__DOT__FF43)));
    __Vdly__PPU3__DOT__FF45 = ((IData)(vlTOPp->rst)
                                ? 0U : (((IData)(vlTOPp->WR) 
                                         & (0xff45U 
                                            == (IData)(vlTOPp->ADDR)))
                                         ? (IData)(vlTOPp->MMIO_DATA_out)
                                         : (IData)(vlTOPp->PPU3__DOT__FF45)));
    __Vdly__PPU3__DOT__FF40 = ((IData)(vlTOPp->rst)
                                ? 0U : (((IData)(vlTOPp->WR) 
                                         & (0xff40U 
                                            == (IData)(vlTOPp->ADDR)))
                                         ? (IData)(vlTOPp->MMIO_DATA_out)
                                         : (IData)(vlTOPp->PPU3__DOT__FF40)));
    vlTOPp->PPU3__DOT__FF41 = ((IData)(vlTOPp->rst)
                                ? 0U : (((IData)(vlTOPp->WR) 
                                         & (0xff41U 
                                            == (IData)(vlTOPp->ADDR)))
                                         ? ((0xf8U 
                                             & (IData)(vlTOPp->MMIO_DATA_out)) 
                                            | (7U & (IData)(vlTOPp->PPU3__DOT__FF41)))
                                         : ((0xf8U 
                                             & (IData)(vlTOPp->PPU3__DOT__FF41)) 
                                            | ((((IData)(vlTOPp->PPU3__DOT__FF45) 
                                                 == (IData)(vlTOPp->PPU3__DOT__LY)) 
                                                << 2U) 
                                               | (IData)(vlTOPp->PPU_MODE)))));
    if (vlTOPp->rst) {
        __Vdly__PPU_ADDR = 0xfe00U;
    }
    if (((IData)(vlTOPp->rst) | (0U == (IData)(vlTOPp->PPU_MODE)))) {
        __Vdly__PPU3__DOT__sprites_loaded = 0U;
        __Vdly__PPU3__DOT__sprite_found = 0U;
    } else {
        if ((2U == (IData)(vlTOPp->PPU_MODE))) {
            if ((1U & (IData)(vlTOPp->PPU3__DOT__cycles))) {
                if (vlTOPp->PPU3__DOT__sprite_found) {
                    vlTOPp->PPU3__DOT____Vlvbound1 
                        = vlTOPp->PPU_DATA_in;
                    __Vdly__PPU_ADDR = (0xffffU & ((IData)(3U) 
                                                   + (IData)(vlTOPp->PPU_ADDR)));
                    if ((9U >= (0xfU & ((IData)(vlTOPp->PPU3__DOT__sprites_loaded) 
                                        - (IData)(1U))))) {
                        __Vdlyvval__PPU3__DOT__sprite_x_buff__v0 
                            = vlTOPp->PPU3__DOT____Vlvbound1;
                        __Vdlyvset__PPU3__DOT__sprite_x_buff__v0 = 1U;
                        __Vdlyvdim0__PPU3__DOT__sprite_x_buff__v0 
                            = (0xfU & ((IData)(vlTOPp->PPU3__DOT__sprites_loaded) 
                                       - (IData)(1U)));
                    }
                }
                __Vdly__PPU3__DOT__sprite_found = 0U;
            } else {
                if ((((((IData)(0x10U) + (IData)(vlTOPp->PPU3__DOT__LY)) 
                       >= (IData)(vlTOPp->PPU_DATA_in)) 
                      & (((IData)(0x10U) + (IData)(vlTOPp->PPU3__DOT__LY)) 
                         < ((IData)(vlTOPp->PPU_DATA_in) 
                            + ((IData)(8U) << (1U & 
                                               ((IData)(vlTOPp->PPU3__DOT__FF40) 
                                                >> 2U)))))) 
                     & (0xaU > (IData)(vlTOPp->PPU3__DOT__sprites_loaded)))) {
                    __Vdly__PPU3__DOT__sprites_loaded 
                        = (0xfU & ((IData)(1U) + (IData)(vlTOPp->PPU3__DOT__sprites_loaded)));
                    vlTOPp->PPU3__DOT____Vlvbound2 
                        = vlTOPp->PPU_DATA_in;
                    __Vdly__PPU_ADDR = (0xffffU & ((IData)(1U) 
                                                   + (IData)(vlTOPp->PPU_ADDR)));
                    if ((9U >= (IData)(vlTOPp->PPU3__DOT__sprites_loaded))) {
                        __Vdlyvval__PPU3__DOT__sprite_y_buff__v0 
                            = vlTOPp->PPU3__DOT____Vlvbound2;
                        __Vdlyvset__PPU3__DOT__sprite_y_buff__v0 = 1U;
                        __Vdlyvdim0__PPU3__DOT__sprite_y_buff__v0 
                            = vlTOPp->PPU3__DOT__sprites_loaded;
                    }
                    __Vdly__PPU3__DOT__sprite_found = 1U;
                    vlTOPp->PPU3__DOT____Vlvbound3 
                        = (0xffU & (IData)(vlTOPp->PPU3__DOT__current_offset));
                    if ((9U >= (IData)(vlTOPp->PPU3__DOT__sprites_loaded))) {
                        __Vdlyvval__PPU3__DOT__sprite_offset_buff__v0 
                            = vlTOPp->PPU3__DOT____Vlvbound3;
                        __Vdlyvset__PPU3__DOT__sprite_offset_buff__v0 = 1U;
                        __Vdlyvdim0__PPU3__DOT__sprite_offset_buff__v0 
                            = vlTOPp->PPU3__DOT__sprites_loaded;
                    }
                } else {
                    __Vdly__PPU_ADDR = (0xffffU & ((IData)(4U) 
                                                   + (IData)(vlTOPp->PPU_ADDR)));
                }
            }
        }
    }
    if (vlTOPp->rst) {
        __Vdlyvset__PPU3__DOT__bg_fifo__DOT__shift_reg__v0 = 1U;
    } else {
        if (vlTOPp->PPU3__DOT__bg_shift_load) {
            __Vdlyvval__PPU3__DOT__bg_fifo__DOT__shift_reg__v2 
                = vlTOPp->PPU3__DOT____Vcellinp__bg_fifo__data
                [0U];
            __Vdlyvset__PPU3__DOT__bg_fifo__DOT__shift_reg__v2 = 1U;
            __Vdlyvval__PPU3__DOT__bg_fifo__DOT__shift_reg__v3 
                = vlTOPp->PPU3__DOT____Vcellinp__bg_fifo__data
                [1U];
        } else {
            if (vlTOPp->PPU3__DOT__bg_shift_go) {
                __Vdlyvval__PPU3__DOT__bg_fifo__DOT__shift_reg__v4 
                    = (0x7fU & vlTOPp->PPU3__DOT__bg_fifo__DOT__shift_reg
                       [0U]);
                __Vdlyvset__PPU3__DOT__bg_fifo__DOT__shift_reg__v4 = 1U;
                __Vdlyvlsb__PPU3__DOT__bg_fifo__DOT__shift_reg__v4 = 1U;
                __Vdlyvlsb__PPU3__DOT__bg_fifo__DOT__shift_reg__v5 = 0U;
                __Vdlyvval__PPU3__DOT__bg_fifo__DOT__shift_reg__v6 
                    = (0x7fU & vlTOPp->PPU3__DOT__bg_fifo__DOT__shift_reg
                       [1U]);
                __Vdlyvlsb__PPU3__DOT__bg_fifo__DOT__shift_reg__v6 = 1U;
                __Vdlyvlsb__PPU3__DOT__bg_fifo__DOT__shift_reg__v7 = 0U;
            }
        }
    }
    if (vlTOPp->rst) {
        __Vdlyvset__PPU3__DOT__sprite_fifo__DOT__shift_reg__v0 = 1U;
    } else {
        if (vlTOPp->PPU3__DOT__sprite_shift_load) {
            __Vdlyvval__PPU3__DOT__sprite_fifo__DOT__shift_reg__v2 
                = vlTOPp->PPU3__DOT____Vcellinp__sprite_fifo__data
                [0U];
            __Vdlyvset__PPU3__DOT__sprite_fifo__DOT__shift_reg__v2 = 1U;
            __Vdlyvval__PPU3__DOT__sprite_fifo__DOT__shift_reg__v3 
                = vlTOPp->PPU3__DOT____Vcellinp__sprite_fifo__data
                [1U];
        } else {
            if (vlTOPp->PPU3__DOT__sprite_shift_go) {
                __Vdlyvval__PPU3__DOT__sprite_fifo__DOT__shift_reg__v4 
                    = (0x7fU & vlTOPp->PPU3__DOT__sprite_fifo__DOT__shift_reg
                       [0U]);
                __Vdlyvset__PPU3__DOT__sprite_fifo__DOT__shift_reg__v4 = 1U;
                __Vdlyvlsb__PPU3__DOT__sprite_fifo__DOT__shift_reg__v4 = 1U;
                __Vdlyvlsb__PPU3__DOT__sprite_fifo__DOT__shift_reg__v5 = 0U;
                __Vdlyvval__PPU3__DOT__sprite_fifo__DOT__shift_reg__v6 
                    = (0x7fU & vlTOPp->PPU3__DOT__sprite_fifo__DOT__shift_reg
                       [1U]);
                __Vdlyvlsb__PPU3__DOT__sprite_fifo__DOT__shift_reg__v6 = 1U;
                __Vdlyvlsb__PPU3__DOT__sprite_fifo__DOT__shift_reg__v7 = 0U;
            }
        }
    }
    vlTOPp->PPU3__DOT__FF45 = __Vdly__PPU3__DOT__FF45;
    vlTOPp->PPU3__DOT__sprites_loaded = __Vdly__PPU3__DOT__sprites_loaded;
    vlTOPp->PPU3__DOT__sprite_found = __Vdly__PPU3__DOT__sprite_found;
    vlTOPp->PPU3__DOT__cycles = __Vdly__PPU3__DOT__cycles;
    vlTOPp->PPU_MODE = __Vdly__PPU_MODE;
    vlTOPp->PPU3__DOT__LY = __Vdly__PPU3__DOT__LY;
    if (__Vdlyvset__PPU3__DOT__sprite_x_buff__v0) {
        vlTOPp->PPU3__DOT__sprite_x_buff[__Vdlyvdim0__PPU3__DOT__sprite_x_buff__v0] 
            = __Vdlyvval__PPU3__DOT__sprite_x_buff__v0;
    }
    if (__Vdlyvset__PPU3__DOT__sprite_y_buff__v0) {
        vlTOPp->PPU3__DOT__sprite_y_buff[__Vdlyvdim0__PPU3__DOT__sprite_y_buff__v0] 
            = __Vdlyvval__PPU3__DOT__sprite_y_buff__v0;
    }
    if (__Vdlyvset__PPU3__DOT__sprite_offset_buff__v0) {
        vlTOPp->PPU3__DOT__sprite_offset_buff[__Vdlyvdim0__PPU3__DOT__sprite_offset_buff__v0] 
            = __Vdlyvval__PPU3__DOT__sprite_offset_buff__v0;
    }
    vlTOPp->PPU_ADDR = __Vdly__PPU_ADDR;
    vlTOPp->PPU3__DOT__FF40 = __Vdly__PPU3__DOT__FF40;
    if (__Vdlyvset__PPU3__DOT__bg_fifo__DOT__shift_reg__v0) {
        vlTOPp->PPU3__DOT__bg_fifo__DOT__shift_reg[0U] = 0U;
        vlTOPp->PPU3__DOT__bg_fifo__DOT__shift_reg[1U] = 0U;
    }
    if (__Vdlyvset__PPU3__DOT__bg_fifo__DOT__shift_reg__v2) {
        vlTOPp->PPU3__DOT__bg_fifo__DOT__shift_reg[0U] 
            = __Vdlyvval__PPU3__DOT__bg_fifo__DOT__shift_reg__v2;
        vlTOPp->PPU3__DOT__bg_fifo__DOT__shift_reg[1U] 
            = __Vdlyvval__PPU3__DOT__bg_fifo__DOT__shift_reg__v3;
    }
    if (__Vdlyvset__PPU3__DOT__bg_fifo__DOT__shift_reg__v4) {
        vlTOPp->PPU3__DOT__bg_fifo__DOT__shift_reg[0U] 
            = (((~ ((IData)(0x7fU) << (IData)(__Vdlyvlsb__PPU3__DOT__bg_fifo__DOT__shift_reg__v4))) 
                & vlTOPp->PPU3__DOT__bg_fifo__DOT__shift_reg
                [0U]) | ((IData)(__Vdlyvval__PPU3__DOT__bg_fifo__DOT__shift_reg__v4) 
                         << (IData)(__Vdlyvlsb__PPU3__DOT__bg_fifo__DOT__shift_reg__v4)));
        vlTOPp->PPU3__DOT__bg_fifo__DOT__shift_reg[0U] 
            = ((~ ((IData)(1U) << (IData)(__Vdlyvlsb__PPU3__DOT__bg_fifo__DOT__shift_reg__v5))) 
               & vlTOPp->PPU3__DOT__bg_fifo__DOT__shift_reg
               [0U]);
        vlTOPp->PPU3__DOT__bg_fifo__DOT__shift_reg[1U] 
            = (((~ ((IData)(0x7fU) << (IData)(__Vdlyvlsb__PPU3__DOT__bg_fifo__DOT__shift_reg__v6))) 
                & vlTOPp->PPU3__DOT__bg_fifo__DOT__shift_reg
                [1U]) | ((IData)(__Vdlyvval__PPU3__DOT__bg_fifo__DOT__shift_reg__v6) 
                         << (IData)(__Vdlyvlsb__PPU3__DOT__bg_fifo__DOT__shift_reg__v6)));
        vlTOPp->PPU3__DOT__bg_fifo__DOT__shift_reg[1U] 
            = ((~ ((IData)(1U) << (IData)(__Vdlyvlsb__PPU3__DOT__bg_fifo__DOT__shift_reg__v7))) 
               & vlTOPp->PPU3__DOT__bg_fifo__DOT__shift_reg
               [1U]);
    }
    if (__Vdlyvset__PPU3__DOT__sprite_fifo__DOT__shift_reg__v0) {
        vlTOPp->PPU3__DOT__sprite_fifo__DOT__shift_reg[0U] = 0U;
        vlTOPp->PPU3__DOT__sprite_fifo__DOT__shift_reg[1U] = 0U;
    }
    if (__Vdlyvset__PPU3__DOT__sprite_fifo__DOT__shift_reg__v2) {
        vlTOPp->PPU3__DOT__sprite_fifo__DOT__shift_reg[0U] 
            = __Vdlyvval__PPU3__DOT__sprite_fifo__DOT__shift_reg__v2;
        vlTOPp->PPU3__DOT__sprite_fifo__DOT__shift_reg[1U] 
            = __Vdlyvval__PPU3__DOT__sprite_fifo__DOT__shift_reg__v3;
    }
    if (__Vdlyvset__PPU3__DOT__sprite_fifo__DOT__shift_reg__v4) {
        vlTOPp->PPU3__DOT__sprite_fifo__DOT__shift_reg[0U] 
            = (((~ ((IData)(0x7fU) << (IData)(__Vdlyvlsb__PPU3__DOT__sprite_fifo__DOT__shift_reg__v4))) 
                & vlTOPp->PPU3__DOT__sprite_fifo__DOT__shift_reg
                [0U]) | ((IData)(__Vdlyvval__PPU3__DOT__sprite_fifo__DOT__shift_reg__v4) 
                         << (IData)(__Vdlyvlsb__PPU3__DOT__sprite_fifo__DOT__shift_reg__v4)));
        vlTOPp->PPU3__DOT__sprite_fifo__DOT__shift_reg[0U] 
            = ((~ ((IData)(1U) << (IData)(__Vdlyvlsb__PPU3__DOT__sprite_fifo__DOT__shift_reg__v5))) 
               & vlTOPp->PPU3__DOT__sprite_fifo__DOT__shift_reg
               [0U]);
        vlTOPp->PPU3__DOT__sprite_fifo__DOT__shift_reg[1U] 
            = (((~ ((IData)(0x7fU) << (IData)(__Vdlyvlsb__PPU3__DOT__sprite_fifo__DOT__shift_reg__v6))) 
                & vlTOPp->PPU3__DOT__sprite_fifo__DOT__shift_reg
                [1U]) | ((IData)(__Vdlyvval__PPU3__DOT__sprite_fifo__DOT__shift_reg__v6) 
                         << (IData)(__Vdlyvlsb__PPU3__DOT__sprite_fifo__DOT__shift_reg__v6)));
        vlTOPp->PPU3__DOT__sprite_fifo__DOT__shift_reg[1U] 
            = ((~ ((IData)(1U) << (IData)(__Vdlyvlsb__PPU3__DOT__sprite_fifo__DOT__shift_reg__v7))) 
               & vlTOPp->PPU3__DOT__sprite_fifo__DOT__shift_reg
               [1U]);
    }
    vlTOPp->PPU3__DOT__current_offset = (0xffffU & 
                                         ((IData)(vlTOPp->PPU_ADDR) 
                                          - (IData)(0xfe00U)));
}

void VPPU3::_settle__TOP__2(VPPU3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPPU3::_settle__TOP__2\n"); );
    VPPU3* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->PPU3__DOT____Vcellinp__sprite_fifo__data[1U] 
        = vlTOPp->PPU3__DOT__sprite_tile_row[1U];
    vlTOPp->PPU3__DOT____Vcellinp__sprite_fifo__data[0U] 
        = vlTOPp->PPU3__DOT__sprite_tile_row[0U];
    vlTOPp->PPU3__DOT____Vcellinp__bg_fifo__data[1U] 
        = vlTOPp->PPU3__DOT__bg_tile_row[1U];
    vlTOPp->PPU3__DOT____Vcellinp__bg_fifo__data[0U] 
        = vlTOPp->PPU3__DOT__bg_tile_row[0U];
    vlTOPp->PPU3__DOT__current_offset = (0xffffU & 
                                         ((IData)(vlTOPp->PPU_ADDR) 
                                          - (IData)(0xfe00U)));
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
                                                 ? (IData)(vlTOPp->PPU3__DOT__FF44)
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
}

VL_INLINE_OPT void VPPU3::_combo__TOP__3(VPPU3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPPU3::_combo__TOP__3\n"); );
    VPPU3* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
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
                                                 ? (IData)(vlTOPp->PPU3__DOT__FF44)
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
}

void VPPU3::_eval(VPPU3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPPU3::_eval\n"); );
    VPPU3* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
        vlTOPp->__Vm_traceActivity = (2U | vlTOPp->__Vm_traceActivity);
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
    vlTOPp->__Vm_traceActivity = (1U | vlTOPp->__Vm_traceActivity);
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
    PPU3__DOT__LY = VL_RAND_RESET_I(8);
    PPU3__DOT__x_pos = VL_RAND_RESET_I(8);
    PPU3__DOT__current_offset = VL_RAND_RESET_I(16);
    PPU3__DOT__sprites_loaded = VL_RAND_RESET_I(4);
    PPU3__DOT__sprite_found = VL_RAND_RESET_I(1);
    PPU3__DOT__cycles = VL_RAND_RESET_I(9);
    { int __Vi0=0; for (; __Vi0<10; ++__Vi0) {
            PPU3__DOT__sprite_y_buff[__Vi0] = VL_RAND_RESET_I(8);
    }}
    { int __Vi0=0; for (; __Vi0<10; ++__Vi0) {
            PPU3__DOT__sprite_x_buff[__Vi0] = VL_RAND_RESET_I(8);
    }}
    { int __Vi0=0; for (; __Vi0<10; ++__Vi0) {
            PPU3__DOT__sprite_offset_buff[__Vi0] = VL_RAND_RESET_I(8);
    }}
    PPU3__DOT__sprite_shift_go = VL_RAND_RESET_I(1);
    PPU3__DOT__sprite_shift_load = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
            PPU3__DOT__sprite_tile_row[__Vi0] = VL_RAND_RESET_I(8);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
            PPU3__DOT____Vcellinp__sprite_fifo__data[__Vi0] = VL_RAND_RESET_I(8);
    }}
    PPU3__DOT__bg_shift_go = VL_RAND_RESET_I(1);
    PPU3__DOT__bg_shift_load = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
            PPU3__DOT__bg_tile_row[__Vi0] = VL_RAND_RESET_I(8);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
            PPU3__DOT____Vcellinp__bg_fifo__data[__Vi0] = VL_RAND_RESET_I(8);
    }}
    PPU3__DOT__FF40 = VL_RAND_RESET_I(8);
    PPU3__DOT__FF41 = VL_RAND_RESET_I(8);
    PPU3__DOT__FF42 = VL_RAND_RESET_I(8);
    PPU3__DOT__FF43 = VL_RAND_RESET_I(8);
    PPU3__DOT__FF44 = VL_RAND_RESET_I(8);
    PPU3__DOT__FF45 = VL_RAND_RESET_I(8);
    PPU3__DOT__FF46 = VL_RAND_RESET_I(8);
    PPU3__DOT__FF47 = VL_RAND_RESET_I(8);
    PPU3__DOT__FF48 = VL_RAND_RESET_I(8);
    PPU3__DOT__FF49 = VL_RAND_RESET_I(8);
    PPU3__DOT__FF4A = VL_RAND_RESET_I(8);
    PPU3__DOT__FF4B = VL_RAND_RESET_I(8);
    PPU3__DOT____Vlvbound1 = VL_RAND_RESET_I(8);
    PPU3__DOT____Vlvbound2 = VL_RAND_RESET_I(8);
    PPU3__DOT____Vlvbound3 = VL_RAND_RESET_I(8);
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
            PPU3__DOT__sprite_fifo__DOT__shift_reg[__Vi0] = VL_RAND_RESET_I(8);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
            PPU3__DOT__bg_fifo__DOT__shift_reg[__Vi0] = VL_RAND_RESET_I(8);
    }}
    __Vm_traceActivity = 0;
}
