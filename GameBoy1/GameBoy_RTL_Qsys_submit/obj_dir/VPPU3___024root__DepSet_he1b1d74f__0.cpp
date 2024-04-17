// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VPPU3.h for the primary calling header

#include "verilated.h"

#include "VPPU3___024root.h"

VL_INLINE_OPT void VPPU3___024root___ico_sequent__TOP__0(VPPU3___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPPU3__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPPU3___024root___ico_sequent__TOP__0\n"); );
    // Body
    vlSelf->MMIO_DATA_in = (((((((((0xff40U == (IData)(vlSelf->ADDR)) 
                                   | (0xff41U == (IData)(vlSelf->ADDR))) 
                                  | (0xff42U == (IData)(vlSelf->ADDR))) 
                                 | (0xff43U == (IData)(vlSelf->ADDR))) 
                                | (0xff44U == (IData)(vlSelf->ADDR))) 
                               | (0xff45U == (IData)(vlSelf->ADDR))) 
                              | (0xff46U == (IData)(vlSelf->ADDR))) 
                             | (0xff47U == (IData)(vlSelf->ADDR)))
                             ? ((0xff40U == (IData)(vlSelf->ADDR))
                                 ? (IData)(vlSelf->PPU3__DOT__FF40)
                                 : ((0xff41U == (IData)(vlSelf->ADDR))
                                     ? (0x80U | (0x7fU 
                                                 & (IData)(vlSelf->PPU3__DOT__FF41)))
                                     : ((0xff42U == (IData)(vlSelf->ADDR))
                                         ? (IData)(vlSelf->PPU3__DOT__FF42)
                                         : ((0xff43U 
                                             == (IData)(vlSelf->ADDR))
                                             ? (IData)(vlSelf->PPU3__DOT__FF43)
                                             : ((0xff44U 
                                                 == (IData)(vlSelf->ADDR))
                                                 ? (IData)(vlSelf->PPU3__DOT__FF44)
                                                 : 
                                                ((0xff45U 
                                                  == (IData)(vlSelf->ADDR))
                                                  ? (IData)(vlSelf->PPU3__DOT__FF45)
                                                  : 
                                                 ((0xff46U 
                                                   == (IData)(vlSelf->ADDR))
                                                   ? (IData)(vlSelf->PPU3__DOT__FF46)
                                                   : (IData)(vlSelf->PPU3__DOT__FF47))))))))
                             : ((0xff48U == (IData)(vlSelf->ADDR))
                                 ? (IData)(vlSelf->PPU3__DOT__FF48)
                                 : ((0xff49U == (IData)(vlSelf->ADDR))
                                     ? (IData)(vlSelf->PPU3__DOT__FF49)
                                     : ((0xff4aU == (IData)(vlSelf->ADDR))
                                         ? (IData)(vlSelf->PPU3__DOT__FF4A)
                                         : ((0xff4bU 
                                             == (IData)(vlSelf->ADDR))
                                             ? (IData)(vlSelf->PPU3__DOT__FF4B)
                                             : 0xffU)))));
}

void VPPU3___024root___eval_ico(VPPU3___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPPU3__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPPU3___024root___eval_ico\n"); );
    // Body
    if (vlSelf->__VicoTriggered.at(0U)) {
        VPPU3___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void VPPU3___024root___eval_act(VPPU3___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPPU3__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPPU3___024root___eval_act\n"); );
}

VL_INLINE_OPT void VPPU3___024root___nba_sequent__TOP__0(VPPU3___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPPU3__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPPU3___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*7:0*/ __Vdly__PPU3__DOT__FF40;
    __Vdly__PPU3__DOT__FF40 = 0;
    CData/*7:0*/ __Vdly__PPU3__DOT__FF45;
    __Vdly__PPU3__DOT__FF45 = 0;
    SData/*8:0*/ __Vdly__PPU3__DOT__cycles;
    __Vdly__PPU3__DOT__cycles = 0;
    CData/*7:0*/ __Vdly__PPU3__DOT__LY;
    __Vdly__PPU3__DOT__LY = 0;
    CData/*1:0*/ __Vdly__PPU_MODE;
    __Vdly__PPU_MODE = 0;
    SData/*15:0*/ __Vdly__PPU_ADDR;
    __Vdly__PPU_ADDR = 0;
    CData/*3:0*/ __Vdly__PPU3__DOT__sprites_loaded;
    __Vdly__PPU3__DOT__sprites_loaded = 0;
    CData/*0:0*/ __Vdly__PPU3__DOT__sprite_found;
    __Vdly__PPU3__DOT__sprite_found = 0;
    CData/*3:0*/ __Vdlyvdim0__PPU3__DOT__sprite_x_buff__v0;
    __Vdlyvdim0__PPU3__DOT__sprite_x_buff__v0 = 0;
    CData/*7:0*/ __Vdlyvval__PPU3__DOT__sprite_x_buff__v0;
    __Vdlyvval__PPU3__DOT__sprite_x_buff__v0 = 0;
    CData/*0:0*/ __Vdlyvset__PPU3__DOT__sprite_x_buff__v0;
    __Vdlyvset__PPU3__DOT__sprite_x_buff__v0 = 0;
    CData/*3:0*/ __Vdlyvdim0__PPU3__DOT__sprite_y_buff__v0;
    __Vdlyvdim0__PPU3__DOT__sprite_y_buff__v0 = 0;
    CData/*7:0*/ __Vdlyvval__PPU3__DOT__sprite_y_buff__v0;
    __Vdlyvval__PPU3__DOT__sprite_y_buff__v0 = 0;
    CData/*0:0*/ __Vdlyvset__PPU3__DOT__sprite_y_buff__v0;
    __Vdlyvset__PPU3__DOT__sprite_y_buff__v0 = 0;
    CData/*3:0*/ __Vdlyvdim0__PPU3__DOT__sprite_offset_buff__v0;
    __Vdlyvdim0__PPU3__DOT__sprite_offset_buff__v0 = 0;
    CData/*7:0*/ __Vdlyvval__PPU3__DOT__sprite_offset_buff__v0;
    __Vdlyvval__PPU3__DOT__sprite_offset_buff__v0 = 0;
    CData/*0:0*/ __Vdlyvset__PPU3__DOT__sprite_offset_buff__v0;
    __Vdlyvset__PPU3__DOT__sprite_offset_buff__v0 = 0;
    CData/*0:0*/ __Vdlyvset__PPU3__DOT__sprite_fifo__DOT__shift_reg__v0;
    __Vdlyvset__PPU3__DOT__sprite_fifo__DOT__shift_reg__v0 = 0;
    CData/*7:0*/ __Vdlyvval__PPU3__DOT__sprite_fifo__DOT__shift_reg__v2;
    __Vdlyvval__PPU3__DOT__sprite_fifo__DOT__shift_reg__v2 = 0;
    CData/*0:0*/ __Vdlyvset__PPU3__DOT__sprite_fifo__DOT__shift_reg__v2;
    __Vdlyvset__PPU3__DOT__sprite_fifo__DOT__shift_reg__v2 = 0;
    CData/*7:0*/ __Vdlyvval__PPU3__DOT__sprite_fifo__DOT__shift_reg__v3;
    __Vdlyvval__PPU3__DOT__sprite_fifo__DOT__shift_reg__v3 = 0;
    CData/*2:0*/ __Vdlyvlsb__PPU3__DOT__sprite_fifo__DOT__shift_reg__v4;
    __Vdlyvlsb__PPU3__DOT__sprite_fifo__DOT__shift_reg__v4 = 0;
    CData/*6:0*/ __Vdlyvval__PPU3__DOT__sprite_fifo__DOT__shift_reg__v4;
    __Vdlyvval__PPU3__DOT__sprite_fifo__DOT__shift_reg__v4 = 0;
    CData/*0:0*/ __Vdlyvset__PPU3__DOT__sprite_fifo__DOT__shift_reg__v4;
    __Vdlyvset__PPU3__DOT__sprite_fifo__DOT__shift_reg__v4 = 0;
    CData/*2:0*/ __Vdlyvlsb__PPU3__DOT__sprite_fifo__DOT__shift_reg__v5;
    __Vdlyvlsb__PPU3__DOT__sprite_fifo__DOT__shift_reg__v5 = 0;
    CData/*2:0*/ __Vdlyvlsb__PPU3__DOT__sprite_fifo__DOT__shift_reg__v6;
    __Vdlyvlsb__PPU3__DOT__sprite_fifo__DOT__shift_reg__v6 = 0;
    CData/*6:0*/ __Vdlyvval__PPU3__DOT__sprite_fifo__DOT__shift_reg__v6;
    __Vdlyvval__PPU3__DOT__sprite_fifo__DOT__shift_reg__v6 = 0;
    CData/*2:0*/ __Vdlyvlsb__PPU3__DOT__sprite_fifo__DOT__shift_reg__v7;
    __Vdlyvlsb__PPU3__DOT__sprite_fifo__DOT__shift_reg__v7 = 0;
    CData/*0:0*/ __Vdlyvset__PPU3__DOT__bg_fifo__DOT__shift_reg__v0;
    __Vdlyvset__PPU3__DOT__bg_fifo__DOT__shift_reg__v0 = 0;
    CData/*7:0*/ __Vdlyvval__PPU3__DOT__bg_fifo__DOT__shift_reg__v2;
    __Vdlyvval__PPU3__DOT__bg_fifo__DOT__shift_reg__v2 = 0;
    CData/*0:0*/ __Vdlyvset__PPU3__DOT__bg_fifo__DOT__shift_reg__v2;
    __Vdlyvset__PPU3__DOT__bg_fifo__DOT__shift_reg__v2 = 0;
    CData/*7:0*/ __Vdlyvval__PPU3__DOT__bg_fifo__DOT__shift_reg__v3;
    __Vdlyvval__PPU3__DOT__bg_fifo__DOT__shift_reg__v3 = 0;
    CData/*2:0*/ __Vdlyvlsb__PPU3__DOT__bg_fifo__DOT__shift_reg__v4;
    __Vdlyvlsb__PPU3__DOT__bg_fifo__DOT__shift_reg__v4 = 0;
    CData/*6:0*/ __Vdlyvval__PPU3__DOT__bg_fifo__DOT__shift_reg__v4;
    __Vdlyvval__PPU3__DOT__bg_fifo__DOT__shift_reg__v4 = 0;
    CData/*0:0*/ __Vdlyvset__PPU3__DOT__bg_fifo__DOT__shift_reg__v4;
    __Vdlyvset__PPU3__DOT__bg_fifo__DOT__shift_reg__v4 = 0;
    CData/*2:0*/ __Vdlyvlsb__PPU3__DOT__bg_fifo__DOT__shift_reg__v5;
    __Vdlyvlsb__PPU3__DOT__bg_fifo__DOT__shift_reg__v5 = 0;
    CData/*2:0*/ __Vdlyvlsb__PPU3__DOT__bg_fifo__DOT__shift_reg__v6;
    __Vdlyvlsb__PPU3__DOT__bg_fifo__DOT__shift_reg__v6 = 0;
    CData/*6:0*/ __Vdlyvval__PPU3__DOT__bg_fifo__DOT__shift_reg__v6;
    __Vdlyvval__PPU3__DOT__bg_fifo__DOT__shift_reg__v6 = 0;
    CData/*2:0*/ __Vdlyvlsb__PPU3__DOT__bg_fifo__DOT__shift_reg__v7;
    __Vdlyvlsb__PPU3__DOT__bg_fifo__DOT__shift_reg__v7 = 0;
    // Body
    __Vdly__PPU_MODE = vlSelf->PPU_MODE;
    __Vdly__PPU3__DOT__LY = vlSelf->PPU3__DOT__LY;
    __Vdly__PPU3__DOT__cycles = vlSelf->PPU3__DOT__cycles;
    __Vdly__PPU3__DOT__FF45 = vlSelf->PPU3__DOT__FF45;
    __Vdly__PPU3__DOT__FF40 = vlSelf->PPU3__DOT__FF40;
    __Vdly__PPU3__DOT__sprite_found = vlSelf->PPU3__DOT__sprite_found;
    __Vdly__PPU3__DOT__sprites_loaded = vlSelf->PPU3__DOT__sprites_loaded;
    __Vdlyvset__PPU3__DOT__sprite_offset_buff__v0 = 0U;
    __Vdlyvset__PPU3__DOT__sprite_y_buff__v0 = 0U;
    __Vdlyvset__PPU3__DOT__sprite_x_buff__v0 = 0U;
    __Vdlyvset__PPU3__DOT__bg_fifo__DOT__shift_reg__v0 = 0U;
    __Vdlyvset__PPU3__DOT__bg_fifo__DOT__shift_reg__v2 = 0U;
    __Vdlyvset__PPU3__DOT__bg_fifo__DOT__shift_reg__v4 = 0U;
    __Vdlyvset__PPU3__DOT__sprite_fifo__DOT__shift_reg__v0 = 0U;
    __Vdlyvset__PPU3__DOT__sprite_fifo__DOT__shift_reg__v2 = 0U;
    __Vdlyvset__PPU3__DOT__sprite_fifo__DOT__shift_reg__v4 = 0U;
    __Vdly__PPU_ADDR = vlSelf->PPU_ADDR;
    if (vlSelf->rst) {
        vlSelf->PPU3__DOT__FF4B = 0U;
        vlSelf->PPU3__DOT__FF4A = 0U;
        vlSelf->PPU3__DOT__FF48 = 0U;
        vlSelf->PPU3__DOT__FF47 = 0U;
        vlSelf->PPU3__DOT__FF46 = 0U;
        vlSelf->PPU3__DOT__FF43 = 0U;
        vlSelf->PPU3__DOT__FF42 = 0U;
        vlSelf->PPU3__DOT__FF49 = 0U;
        __Vdly__PPU3__DOT__FF45 = 0U;
        __Vdly__PPU3__DOT__FF40 = 0U;
        vlSelf->PPU3__DOT__FF41 = 0U;
        __Vdlyvset__PPU3__DOT__bg_fifo__DOT__shift_reg__v0 = 1U;
        __Vdlyvset__PPU3__DOT__sprite_fifo__DOT__shift_reg__v0 = 1U;
        __Vdly__PPU_ADDR = 0xfe00U;
        vlSelf->PPU3__DOT__x_pos = 0U;
        __Vdly__PPU3__DOT__cycles = 0U;
        __Vdly__PPU3__DOT__LY = 0U;
        __Vdly__PPU_MODE = 2U;
    } else {
        vlSelf->PPU3__DOT__FF4B = (((IData)(vlSelf->WR) 
                                    & (0xff4bU == (IData)(vlSelf->ADDR)))
                                    ? (IData)(vlSelf->MMIO_DATA_out)
                                    : (IData)(vlSelf->PPU3__DOT__FF4B));
        vlSelf->PPU3__DOT__FF4A = (((IData)(vlSelf->WR) 
                                    & (0xff4aU == (IData)(vlSelf->ADDR)))
                                    ? (IData)(vlSelf->MMIO_DATA_out)
                                    : (IData)(vlSelf->PPU3__DOT__FF4A));
        vlSelf->PPU3__DOT__FF48 = (((IData)(vlSelf->WR) 
                                    & (0xff48U == (IData)(vlSelf->ADDR)))
                                    ? (IData)(vlSelf->MMIO_DATA_out)
                                    : (IData)(vlSelf->PPU3__DOT__FF48));
        vlSelf->PPU3__DOT__FF47 = (((IData)(vlSelf->WR) 
                                    & (0xff47U == (IData)(vlSelf->ADDR)))
                                    ? (IData)(vlSelf->MMIO_DATA_out)
                                    : (IData)(vlSelf->PPU3__DOT__FF47));
        vlSelf->PPU3__DOT__FF46 = (((IData)(vlSelf->WR) 
                                    & (0xff46U == (IData)(vlSelf->ADDR)))
                                    ? (IData)(vlSelf->MMIO_DATA_out)
                                    : (IData)(vlSelf->PPU3__DOT__FF46));
        vlSelf->PPU3__DOT__FF43 = (((IData)(vlSelf->WR) 
                                    & (0xff43U == (IData)(vlSelf->ADDR)))
                                    ? (IData)(vlSelf->MMIO_DATA_out)
                                    : (IData)(vlSelf->PPU3__DOT__FF43));
        vlSelf->PPU3__DOT__FF42 = (((IData)(vlSelf->WR) 
                                    & (0xff42U == (IData)(vlSelf->ADDR)))
                                    ? (IData)(vlSelf->MMIO_DATA_out)
                                    : (IData)(vlSelf->PPU3__DOT__FF42));
        vlSelf->PPU3__DOT__FF49 = (((IData)(vlSelf->WR) 
                                    & (0xff49U == (IData)(vlSelf->ADDR)))
                                    ? (IData)(vlSelf->MMIO_DATA_out)
                                    : (IData)(vlSelf->PPU3__DOT__FF49));
        __Vdly__PPU3__DOT__FF45 = (((IData)(vlSelf->WR) 
                                    & (0xff45U == (IData)(vlSelf->ADDR)))
                                    ? (IData)(vlSelf->MMIO_DATA_out)
                                    : (IData)(vlSelf->PPU3__DOT__FF45));
        __Vdly__PPU3__DOT__FF40 = (((IData)(vlSelf->WR) 
                                    & (0xff40U == (IData)(vlSelf->ADDR)))
                                    ? (IData)(vlSelf->MMIO_DATA_out)
                                    : (IData)(vlSelf->PPU3__DOT__FF40));
        vlSelf->PPU3__DOT__FF41 = (((IData)(vlSelf->WR) 
                                    & (0xff41U == (IData)(vlSelf->ADDR)))
                                    ? ((0xf8U & (IData)(vlSelf->MMIO_DATA_out)) 
                                       | (7U & (IData)(vlSelf->PPU3__DOT__FF41)))
                                    : ((0xf8U & (IData)(vlSelf->PPU3__DOT__FF41)) 
                                       | ((((IData)(vlSelf->PPU3__DOT__FF45) 
                                            == (IData)(vlSelf->PPU3__DOT__LY)) 
                                           << 2U) | (IData)(vlSelf->PPU_MODE))));
        if (vlSelf->PPU3__DOT__bg_shift_load) {
            __Vdlyvval__PPU3__DOT__bg_fifo__DOT__shift_reg__v2 
                = vlSelf->PPU3__DOT____Vcellinp__bg_fifo__data
                [0U];
            __Vdlyvset__PPU3__DOT__bg_fifo__DOT__shift_reg__v2 = 1U;
            __Vdlyvval__PPU3__DOT__bg_fifo__DOT__shift_reg__v3 
                = vlSelf->PPU3__DOT____Vcellinp__bg_fifo__data
                [1U];
        } else if (vlSelf->PPU3__DOT__bg_shift_go) {
            __Vdlyvval__PPU3__DOT__bg_fifo__DOT__shift_reg__v4 
                = (0x7fU & vlSelf->PPU3__DOT__bg_fifo__DOT__shift_reg
                   [0U]);
            __Vdlyvset__PPU3__DOT__bg_fifo__DOT__shift_reg__v4 = 1U;
            __Vdlyvlsb__PPU3__DOT__bg_fifo__DOT__shift_reg__v4 = 1U;
            __Vdlyvlsb__PPU3__DOT__bg_fifo__DOT__shift_reg__v5 = 0U;
            __Vdlyvval__PPU3__DOT__bg_fifo__DOT__shift_reg__v6 
                = (0x7fU & vlSelf->PPU3__DOT__bg_fifo__DOT__shift_reg
                   [1U]);
            __Vdlyvlsb__PPU3__DOT__bg_fifo__DOT__shift_reg__v6 = 1U;
            __Vdlyvlsb__PPU3__DOT__bg_fifo__DOT__shift_reg__v7 = 0U;
        }
        if (vlSelf->PPU3__DOT__sprite_shift_load) {
            __Vdlyvval__PPU3__DOT__sprite_fifo__DOT__shift_reg__v2 
                = vlSelf->PPU3__DOT____Vcellinp__sprite_fifo__data
                [0U];
            __Vdlyvset__PPU3__DOT__sprite_fifo__DOT__shift_reg__v2 = 1U;
            __Vdlyvval__PPU3__DOT__sprite_fifo__DOT__shift_reg__v3 
                = vlSelf->PPU3__DOT____Vcellinp__sprite_fifo__data
                [1U];
        } else if (vlSelf->PPU3__DOT__sprite_shift_go) {
            __Vdlyvval__PPU3__DOT__sprite_fifo__DOT__shift_reg__v4 
                = (0x7fU & vlSelf->PPU3__DOT__sprite_fifo__DOT__shift_reg
                   [0U]);
            __Vdlyvset__PPU3__DOT__sprite_fifo__DOT__shift_reg__v4 = 1U;
            __Vdlyvlsb__PPU3__DOT__sprite_fifo__DOT__shift_reg__v4 = 1U;
            __Vdlyvlsb__PPU3__DOT__sprite_fifo__DOT__shift_reg__v5 = 0U;
            __Vdlyvval__PPU3__DOT__sprite_fifo__DOT__shift_reg__v6 
                = (0x7fU & vlSelf->PPU3__DOT__sprite_fifo__DOT__shift_reg
                   [1U]);
            __Vdlyvlsb__PPU3__DOT__sprite_fifo__DOT__shift_reg__v6 = 1U;
            __Vdlyvlsb__PPU3__DOT__sprite_fifo__DOT__shift_reg__v7 = 0U;
        }
        if ((0x80U & (IData)(vlSelf->PPU3__DOT__FF40))) {
            __Vdly__PPU3__DOT__cycles = (0x1ffU & ((IData)(1U) 
                                                   + (IData)(vlSelf->PPU3__DOT__cycles)));
            if ((2U & (IData)(vlSelf->PPU_MODE))) {
                if ((1U & (IData)(vlSelf->PPU_MODE))) {
                    __Vdly__PPU3__DOT__LY = vlSelf->PPU3__DOT__LY;
                } else {
                    if ((0xfe9fU < (IData)(vlSelf->PPU_ADDR))) {
                        __Vdly__PPU_MODE = 3U;
                    }
                    if ((0x90U <= (IData)(vlSelf->PPU3__DOT__LY))) {
                        __Vdly__PPU_MODE = 1U;
                    }
                }
            } else if ((1U & (IData)(vlSelf->PPU_MODE))) {
                __Vdly__PPU_MODE = 0U;
            } else if ((0x1c7U <= (IData)(vlSelf->PPU3__DOT__cycles))) {
                __Vdly__PPU3__DOT__LY = (0xffU & ((IData)(1U) 
                                                  + (IData)(vlSelf->PPU3__DOT__LY)));
                vlSelf->PPU3__DOT__x_pos = 0U;
                __Vdly__PPU_MODE = 2U;
                __Vdly__PPU3__DOT__cycles = 0U;
            }
        }
    }
    if (((IData)(vlSelf->rst) | (0U == (IData)(vlSelf->PPU_MODE)))) {
        __Vdly__PPU3__DOT__sprites_loaded = 0U;
        __Vdly__PPU3__DOT__sprite_found = 0U;
    } else if ((2U == (IData)(vlSelf->PPU_MODE))) {
        if ((1U & (IData)(vlSelf->PPU3__DOT__cycles))) {
            if (vlSelf->PPU3__DOT__sprite_found) {
                vlSelf->PPU3__DOT____Vlvbound_ha2b8a78f__0 
                    = vlSelf->PPU_DATA_in;
                __Vdly__PPU_ADDR = (0xffffU & ((IData)(3U) 
                                               + (IData)(vlSelf->PPU_ADDR)));
                if ((9U >= (0xfU & ((IData)(vlSelf->PPU3__DOT__sprites_loaded) 
                                    - (IData)(1U))))) {
                    __Vdlyvval__PPU3__DOT__sprite_x_buff__v0 
                        = vlSelf->PPU3__DOT____Vlvbound_ha2b8a78f__0;
                    __Vdlyvset__PPU3__DOT__sprite_x_buff__v0 = 1U;
                    __Vdlyvdim0__PPU3__DOT__sprite_x_buff__v0 
                        = (0xfU & ((IData)(vlSelf->PPU3__DOT__sprites_loaded) 
                                   - (IData)(1U)));
                }
            }
            __Vdly__PPU3__DOT__sprite_found = 0U;
        } else if ((((((IData)(0x10U) + (IData)(vlSelf->PPU3__DOT__LY)) 
                      >= (IData)(vlSelf->PPU_DATA_in)) 
                     & (((IData)(0x10U) + (IData)(vlSelf->PPU3__DOT__LY)) 
                        < ((IData)(vlSelf->PPU_DATA_in) 
                           + ((IData)(8U) << (1U & 
                                              ((IData)(vlSelf->PPU3__DOT__FF40) 
                                               >> 2U)))))) 
                    & (0xaU > (IData)(vlSelf->PPU3__DOT__sprites_loaded)))) {
            __Vdly__PPU3__DOT__sprites_loaded = (0xfU 
                                                 & ((IData)(1U) 
                                                    + (IData)(vlSelf->PPU3__DOT__sprites_loaded)));
            vlSelf->PPU3__DOT____Vlvbound_he36bfb9b__0 
                = vlSelf->PPU_DATA_in;
            __Vdly__PPU_ADDR = (0xffffU & ((IData)(1U) 
                                           + (IData)(vlSelf->PPU_ADDR)));
            __Vdly__PPU3__DOT__sprite_found = 1U;
            vlSelf->PPU3__DOT____Vlvbound_hf25d2aed__0 
                = (0xffU & (IData)(vlSelf->PPU3__DOT__current_offset));
            if ((9U >= (IData)(vlSelf->PPU3__DOT__sprites_loaded))) {
                __Vdlyvval__PPU3__DOT__sprite_y_buff__v0 
                    = vlSelf->PPU3__DOT____Vlvbound_he36bfb9b__0;
                __Vdlyvset__PPU3__DOT__sprite_y_buff__v0 = 1U;
                __Vdlyvdim0__PPU3__DOT__sprite_y_buff__v0 
                    = vlSelf->PPU3__DOT__sprites_loaded;
                __Vdlyvval__PPU3__DOT__sprite_offset_buff__v0 
                    = vlSelf->PPU3__DOT____Vlvbound_hf25d2aed__0;
                __Vdlyvset__PPU3__DOT__sprite_offset_buff__v0 = 1U;
                __Vdlyvdim0__PPU3__DOT__sprite_offset_buff__v0 
                    = vlSelf->PPU3__DOT__sprites_loaded;
            }
        } else {
            __Vdly__PPU_ADDR = (0xffffU & ((IData)(4U) 
                                           + (IData)(vlSelf->PPU_ADDR)));
        }
    }
    vlSelf->PPU3__DOT__FF45 = __Vdly__PPU3__DOT__FF45;
    if (__Vdlyvset__PPU3__DOT__bg_fifo__DOT__shift_reg__v0) {
        vlSelf->PPU3__DOT__bg_fifo__DOT__shift_reg[0U] = 0U;
        vlSelf->PPU3__DOT__bg_fifo__DOT__shift_reg[1U] = 0U;
    }
    if (__Vdlyvset__PPU3__DOT__bg_fifo__DOT__shift_reg__v2) {
        vlSelf->PPU3__DOT__bg_fifo__DOT__shift_reg[0U] 
            = __Vdlyvval__PPU3__DOT__bg_fifo__DOT__shift_reg__v2;
        vlSelf->PPU3__DOT__bg_fifo__DOT__shift_reg[1U] 
            = __Vdlyvval__PPU3__DOT__bg_fifo__DOT__shift_reg__v3;
    }
    if (__Vdlyvset__PPU3__DOT__bg_fifo__DOT__shift_reg__v4) {
        vlSelf->PPU3__DOT__bg_fifo__DOT__shift_reg[0U] 
            = (((~ ((IData)(0x7fU) << (IData)(__Vdlyvlsb__PPU3__DOT__bg_fifo__DOT__shift_reg__v4))) 
                & vlSelf->PPU3__DOT__bg_fifo__DOT__shift_reg
                [0U]) | (0xffU & ((IData)(__Vdlyvval__PPU3__DOT__bg_fifo__DOT__shift_reg__v4) 
                                  << (IData)(__Vdlyvlsb__PPU3__DOT__bg_fifo__DOT__shift_reg__v4))));
        vlSelf->PPU3__DOT__bg_fifo__DOT__shift_reg[0U] 
            = ((~ ((IData)(1U) << (IData)(__Vdlyvlsb__PPU3__DOT__bg_fifo__DOT__shift_reg__v5))) 
               & vlSelf->PPU3__DOT__bg_fifo__DOT__shift_reg
               [0U]);
        vlSelf->PPU3__DOT__bg_fifo__DOT__shift_reg[1U] 
            = (((~ ((IData)(0x7fU) << (IData)(__Vdlyvlsb__PPU3__DOT__bg_fifo__DOT__shift_reg__v6))) 
                & vlSelf->PPU3__DOT__bg_fifo__DOT__shift_reg
                [1U]) | (0xffU & ((IData)(__Vdlyvval__PPU3__DOT__bg_fifo__DOT__shift_reg__v6) 
                                  << (IData)(__Vdlyvlsb__PPU3__DOT__bg_fifo__DOT__shift_reg__v6))));
        vlSelf->PPU3__DOT__bg_fifo__DOT__shift_reg[1U] 
            = ((~ ((IData)(1U) << (IData)(__Vdlyvlsb__PPU3__DOT__bg_fifo__DOT__shift_reg__v7))) 
               & vlSelf->PPU3__DOT__bg_fifo__DOT__shift_reg
               [1U]);
    }
    if (__Vdlyvset__PPU3__DOT__sprite_fifo__DOT__shift_reg__v0) {
        vlSelf->PPU3__DOT__sprite_fifo__DOT__shift_reg[0U] = 0U;
        vlSelf->PPU3__DOT__sprite_fifo__DOT__shift_reg[1U] = 0U;
    }
    if (__Vdlyvset__PPU3__DOT__sprite_fifo__DOT__shift_reg__v2) {
        vlSelf->PPU3__DOT__sprite_fifo__DOT__shift_reg[0U] 
            = __Vdlyvval__PPU3__DOT__sprite_fifo__DOT__shift_reg__v2;
        vlSelf->PPU3__DOT__sprite_fifo__DOT__shift_reg[1U] 
            = __Vdlyvval__PPU3__DOT__sprite_fifo__DOT__shift_reg__v3;
    }
    if (__Vdlyvset__PPU3__DOT__sprite_fifo__DOT__shift_reg__v4) {
        vlSelf->PPU3__DOT__sprite_fifo__DOT__shift_reg[0U] 
            = (((~ ((IData)(0x7fU) << (IData)(__Vdlyvlsb__PPU3__DOT__sprite_fifo__DOT__shift_reg__v4))) 
                & vlSelf->PPU3__DOT__sprite_fifo__DOT__shift_reg
                [0U]) | (0xffU & ((IData)(__Vdlyvval__PPU3__DOT__sprite_fifo__DOT__shift_reg__v4) 
                                  << (IData)(__Vdlyvlsb__PPU3__DOT__sprite_fifo__DOT__shift_reg__v4))));
        vlSelf->PPU3__DOT__sprite_fifo__DOT__shift_reg[0U] 
            = ((~ ((IData)(1U) << (IData)(__Vdlyvlsb__PPU3__DOT__sprite_fifo__DOT__shift_reg__v5))) 
               & vlSelf->PPU3__DOT__sprite_fifo__DOT__shift_reg
               [0U]);
        vlSelf->PPU3__DOT__sprite_fifo__DOT__shift_reg[1U] 
            = (((~ ((IData)(0x7fU) << (IData)(__Vdlyvlsb__PPU3__DOT__sprite_fifo__DOT__shift_reg__v6))) 
                & vlSelf->PPU3__DOT__sprite_fifo__DOT__shift_reg
                [1U]) | (0xffU & ((IData)(__Vdlyvval__PPU3__DOT__sprite_fifo__DOT__shift_reg__v6) 
                                  << (IData)(__Vdlyvlsb__PPU3__DOT__sprite_fifo__DOT__shift_reg__v6))));
        vlSelf->PPU3__DOT__sprite_fifo__DOT__shift_reg[1U] 
            = ((~ ((IData)(1U) << (IData)(__Vdlyvlsb__PPU3__DOT__sprite_fifo__DOT__shift_reg__v7))) 
               & vlSelf->PPU3__DOT__sprite_fifo__DOT__shift_reg
               [1U]);
    }
    vlSelf->PPU3__DOT__sprites_loaded = __Vdly__PPU3__DOT__sprites_loaded;
    vlSelf->PPU3__DOT__sprite_found = __Vdly__PPU3__DOT__sprite_found;
    if (__Vdlyvset__PPU3__DOT__sprite_x_buff__v0) {
        vlSelf->PPU3__DOT__sprite_x_buff[__Vdlyvdim0__PPU3__DOT__sprite_x_buff__v0] 
            = __Vdlyvval__PPU3__DOT__sprite_x_buff__v0;
    }
    if (__Vdlyvset__PPU3__DOT__sprite_y_buff__v0) {
        vlSelf->PPU3__DOT__sprite_y_buff[__Vdlyvdim0__PPU3__DOT__sprite_y_buff__v0] 
            = __Vdlyvval__PPU3__DOT__sprite_y_buff__v0;
    }
    if (__Vdlyvset__PPU3__DOT__sprite_offset_buff__v0) {
        vlSelf->PPU3__DOT__sprite_offset_buff[__Vdlyvdim0__PPU3__DOT__sprite_offset_buff__v0] 
            = __Vdlyvval__PPU3__DOT__sprite_offset_buff__v0;
    }
    vlSelf->PPU3__DOT__cycles = __Vdly__PPU3__DOT__cycles;
    vlSelf->PPU_MODE = __Vdly__PPU_MODE;
    vlSelf->PPU3__DOT__LY = __Vdly__PPU3__DOT__LY;
    vlSelf->PPU_ADDR = __Vdly__PPU_ADDR;
    vlSelf->PPU3__DOT__FF40 = __Vdly__PPU3__DOT__FF40;
    vlSelf->PPU3__DOT__current_offset = (0xffffU & 
                                         ((IData)(vlSelf->PPU_ADDR) 
                                          - (IData)(0xfe00U)));
    vlSelf->MMIO_DATA_in = (((((((((0xff40U == (IData)(vlSelf->ADDR)) 
                                   | (0xff41U == (IData)(vlSelf->ADDR))) 
                                  | (0xff42U == (IData)(vlSelf->ADDR))) 
                                 | (0xff43U == (IData)(vlSelf->ADDR))) 
                                | (0xff44U == (IData)(vlSelf->ADDR))) 
                               | (0xff45U == (IData)(vlSelf->ADDR))) 
                              | (0xff46U == (IData)(vlSelf->ADDR))) 
                             | (0xff47U == (IData)(vlSelf->ADDR)))
                             ? ((0xff40U == (IData)(vlSelf->ADDR))
                                 ? (IData)(vlSelf->PPU3__DOT__FF40)
                                 : ((0xff41U == (IData)(vlSelf->ADDR))
                                     ? (0x80U | (0x7fU 
                                                 & (IData)(vlSelf->PPU3__DOT__FF41)))
                                     : ((0xff42U == (IData)(vlSelf->ADDR))
                                         ? (IData)(vlSelf->PPU3__DOT__FF42)
                                         : ((0xff43U 
                                             == (IData)(vlSelf->ADDR))
                                             ? (IData)(vlSelf->PPU3__DOT__FF43)
                                             : ((0xff44U 
                                                 == (IData)(vlSelf->ADDR))
                                                 ? (IData)(vlSelf->PPU3__DOT__FF44)
                                                 : 
                                                ((0xff45U 
                                                  == (IData)(vlSelf->ADDR))
                                                  ? (IData)(vlSelf->PPU3__DOT__FF45)
                                                  : 
                                                 ((0xff46U 
                                                   == (IData)(vlSelf->ADDR))
                                                   ? (IData)(vlSelf->PPU3__DOT__FF46)
                                                   : (IData)(vlSelf->PPU3__DOT__FF47))))))))
                             : ((0xff48U == (IData)(vlSelf->ADDR))
                                 ? (IData)(vlSelf->PPU3__DOT__FF48)
                                 : ((0xff49U == (IData)(vlSelf->ADDR))
                                     ? (IData)(vlSelf->PPU3__DOT__FF49)
                                     : ((0xff4aU == (IData)(vlSelf->ADDR))
                                         ? (IData)(vlSelf->PPU3__DOT__FF4A)
                                         : ((0xff4bU 
                                             == (IData)(vlSelf->ADDR))
                                             ? (IData)(vlSelf->PPU3__DOT__FF4B)
                                             : 0xffU)))));
}

void VPPU3___024root___eval_nba(VPPU3___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPPU3__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPPU3___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(0U)) {
        VPPU3___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
}

void VPPU3___024root___eval_triggers__ico(VPPU3___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void VPPU3___024root___dump_triggers__ico(VPPU3___024root* vlSelf);
#endif  // VL_DEBUG
void VPPU3___024root___eval_triggers__act(VPPU3___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void VPPU3___024root___dump_triggers__act(VPPU3___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VPPU3___024root___dump_triggers__nba(VPPU3___024root* vlSelf);
#endif  // VL_DEBUG

void VPPU3___024root___eval(VPPU3___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPPU3__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPPU3___024root___eval\n"); );
    // Init
    CData/*0:0*/ __VicoContinue;
    VlTriggerVec<1> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    vlSelf->__VicoIterCount = 0U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        __VicoContinue = 0U;
        VPPU3___024root___eval_triggers__ico(vlSelf);
        if (vlSelf->__VicoTriggered.any()) {
            __VicoContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VicoIterCount))) {
#ifdef VL_DEBUG
                VPPU3___024root___dump_triggers__ico(vlSelf);
#endif
                VL_FATAL_MT("PPU3.sv", 7, "", "Input combinational region did not converge.");
            }
            vlSelf->__VicoIterCount = ((IData)(1U) 
                                       + vlSelf->__VicoIterCount);
            VPPU3___024root___eval_ico(vlSelf);
        }
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        __VnbaContinue = 0U;
        vlSelf->__VnbaTriggered.clear();
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            vlSelf->__VactContinue = 0U;
            VPPU3___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    VPPU3___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("PPU3.sv", 7, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                VPPU3___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                VPPU3___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("PPU3.sv", 7, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            VPPU3___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void VPPU3___024root___eval_debug_assertions(VPPU3___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPPU3__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPPU3___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelf->WR & 0xfeU))) {
        Verilated::overWidthError("WR");}
    if (VL_UNLIKELY((vlSelf->RD & 0xfeU))) {
        Verilated::overWidthError("RD");}
}
#endif  // VL_DEBUG
