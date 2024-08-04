// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VPPU3.h for the primary calling header

#include "verilated.h"

#include "VPPU3___024root.h"

VL_ATTR_COLD void VPPU3___024root___eval_static(VPPU3___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPPU3__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPPU3___024root___eval_static\n"); );
}

VL_ATTR_COLD void VPPU3___024root___eval_initial(VPPU3___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPPU3__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPPU3___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vtrigrprev__TOP__clk = vlSelf->clk;
}

VL_ATTR_COLD void VPPU3___024root___eval_final(VPPU3___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPPU3__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPPU3___024root___eval_final\n"); );
}

VL_ATTR_COLD void VPPU3___024root___eval_triggers__stl(VPPU3___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void VPPU3___024root___dump_triggers__stl(VPPU3___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void VPPU3___024root___eval_stl(VPPU3___024root* vlSelf);

VL_ATTR_COLD void VPPU3___024root___eval_settle(VPPU3___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPPU3__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPPU3___024root___eval_settle\n"); );
    // Init
    CData/*0:0*/ __VstlContinue;
    // Body
    vlSelf->__VstlIterCount = 0U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        __VstlContinue = 0U;
        VPPU3___024root___eval_triggers__stl(vlSelf);
        if (vlSelf->__VstlTriggered.any()) {
            __VstlContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VstlIterCount))) {
#ifdef VL_DEBUG
                VPPU3___024root___dump_triggers__stl(vlSelf);
#endif
                VL_FATAL_MT("PPU3.sv", 7, "", "Settle region did not converge.");
            }
            vlSelf->__VstlIterCount = ((IData)(1U) 
                                       + vlSelf->__VstlIterCount);
            VPPU3___024root___eval_stl(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VPPU3___024root___dump_triggers__stl(VPPU3___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPPU3__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPPU3___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VstlTriggered.at(0U)) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VPPU3___024root___stl_sequent__TOP__0(VPPU3___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPPU3__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPPU3___024root___stl_sequent__TOP__0\n"); );
    // Body
    vlSelf->PPU3__DOT__current_offset = (0xffffU & 
                                         ((IData)(vlSelf->PPU_ADDR) 
                                          - (IData)(0xfe00U)));
    vlSelf->PPU3__DOT____Vcellinp__sprite_fifo__data[1U] 
        = vlSelf->PPU3__DOT__sprite_tile_row[1U];
    vlSelf->PPU3__DOT____Vcellinp__sprite_fifo__data[0U] 
        = vlSelf->PPU3__DOT__sprite_tile_row[0U];
    vlSelf->PPU3__DOT____Vcellinp__bg_fifo__data[1U] 
        = vlSelf->PPU3__DOT__bg_tile_row[1U];
    vlSelf->PPU3__DOT____Vcellinp__bg_fifo__data[0U] 
        = vlSelf->PPU3__DOT__bg_tile_row[0U];
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

VL_ATTR_COLD void VPPU3___024root___eval_stl(VPPU3___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPPU3__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPPU3___024root___eval_stl\n"); );
    // Body
    if (vlSelf->__VstlTriggered.at(0U)) {
        VPPU3___024root___stl_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VPPU3___024root___dump_triggers__ico(VPPU3___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPPU3__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPPU3___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VicoTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VicoTriggered.at(0U)) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VPPU3___024root___dump_triggers__act(VPPU3___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPPU3__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPPU3___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VactTriggered.at(0U)) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VPPU3___024root___dump_triggers__nba(VPPU3___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPPU3__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPPU3___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VPPU3___024root___ctor_var_reset(VPPU3___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPPU3__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPPU3___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->ADDR = VL_RAND_RESET_I(16);
    vlSelf->WR = VL_RAND_RESET_I(1);
    vlSelf->RD = VL_RAND_RESET_I(1);
    vlSelf->MMIO_DATA_out = VL_RAND_RESET_I(8);
    vlSelf->MMIO_DATA_in = VL_RAND_RESET_I(8);
    vlSelf->IRQ_V_BLANK = VL_RAND_RESET_I(1);
    vlSelf->IRQ_LCDC = VL_RAND_RESET_I(1);
    vlSelf->PPU_MODE = VL_RAND_RESET_I(2);
    vlSelf->PPU_RD = VL_RAND_RESET_I(1);
    vlSelf->PPU_ADDR = VL_RAND_RESET_I(16);
    vlSelf->PPU_DATA_in = VL_RAND_RESET_I(8);
    vlSelf->PX_OUT = VL_RAND_RESET_I(2);
    vlSelf->PX_valid = VL_RAND_RESET_I(1);
    vlSelf->PPU3__DOT__LY = VL_RAND_RESET_I(8);
    vlSelf->PPU3__DOT__x_pos = VL_RAND_RESET_I(8);
    vlSelf->PPU3__DOT__current_offset = VL_RAND_RESET_I(16);
    vlSelf->PPU3__DOT__sprites_loaded = VL_RAND_RESET_I(4);
    vlSelf->PPU3__DOT__sprite_found = VL_RAND_RESET_I(1);
    vlSelf->PPU3__DOT__cycles = VL_RAND_RESET_I(9);
    for (int __Vi0 = 0; __Vi0 < 10; ++__Vi0) {
        vlSelf->PPU3__DOT__sprite_y_buff[__Vi0] = VL_RAND_RESET_I(8);
    }
    for (int __Vi0 = 0; __Vi0 < 10; ++__Vi0) {
        vlSelf->PPU3__DOT__sprite_x_buff[__Vi0] = VL_RAND_RESET_I(8);
    }
    for (int __Vi0 = 0; __Vi0 < 10; ++__Vi0) {
        vlSelf->PPU3__DOT__sprite_offset_buff[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->PPU3__DOT__sprite_shift_go = VL_RAND_RESET_I(1);
    vlSelf->PPU3__DOT__sprite_shift_load = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->PPU3__DOT__sprite_tile_row[__Vi0] = VL_RAND_RESET_I(8);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->PPU3__DOT____Vcellinp__sprite_fifo__data[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->PPU3__DOT__bg_shift_go = VL_RAND_RESET_I(1);
    vlSelf->PPU3__DOT__bg_shift_load = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->PPU3__DOT__bg_tile_row[__Vi0] = VL_RAND_RESET_I(8);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->PPU3__DOT____Vcellinp__bg_fifo__data[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->PPU3__DOT__FF40 = VL_RAND_RESET_I(8);
    vlSelf->PPU3__DOT__FF41 = VL_RAND_RESET_I(8);
    vlSelf->PPU3__DOT__FF42 = VL_RAND_RESET_I(8);
    vlSelf->PPU3__DOT__FF43 = VL_RAND_RESET_I(8);
    vlSelf->PPU3__DOT__FF44 = VL_RAND_RESET_I(8);
    vlSelf->PPU3__DOT__FF45 = VL_RAND_RESET_I(8);
    vlSelf->PPU3__DOT__FF46 = VL_RAND_RESET_I(8);
    vlSelf->PPU3__DOT__FF47 = VL_RAND_RESET_I(8);
    vlSelf->PPU3__DOT__FF48 = VL_RAND_RESET_I(8);
    vlSelf->PPU3__DOT__FF49 = VL_RAND_RESET_I(8);
    vlSelf->PPU3__DOT__FF4A = VL_RAND_RESET_I(8);
    vlSelf->PPU3__DOT__FF4B = VL_RAND_RESET_I(8);
    vlSelf->PPU3__DOT____Vlvbound_ha2b8a78f__0 = VL_RAND_RESET_I(8);
    vlSelf->PPU3__DOT____Vlvbound_he36bfb9b__0 = VL_RAND_RESET_I(8);
    vlSelf->PPU3__DOT____Vlvbound_hf25d2aed__0 = VL_RAND_RESET_I(8);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->PPU3__DOT__sprite_fifo__DOT__shift_reg[__Vi0] = VL_RAND_RESET_I(8);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->PPU3__DOT__bg_fifo__DOT__shift_reg[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->__Vtrigrprev__TOP__clk = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
