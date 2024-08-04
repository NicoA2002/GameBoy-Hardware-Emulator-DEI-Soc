// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VPPU3__Syms.h"


void VPPU3___024root__trace_chg_sub_0(VPPU3___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void VPPU3___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPPU3___024root__trace_chg_top_0\n"); );
    // Init
    VPPU3___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VPPU3___024root*>(voidSelf);
    VPPU3__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    VPPU3___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void VPPU3___024root__trace_chg_sub_0(VPPU3___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    VPPU3__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPPU3___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0U])) {
        bufp->chgCData(oldp+0,(vlSelf->PPU3__DOT____Vcellinp__bg_fifo__data[0]),8);
        bufp->chgCData(oldp+1,(vlSelf->PPU3__DOT____Vcellinp__bg_fifo__data[1]),8);
        bufp->chgCData(oldp+2,(vlSelf->PPU3__DOT____Vcellinp__sprite_fifo__data[0]),8);
        bufp->chgCData(oldp+3,(vlSelf->PPU3__DOT____Vcellinp__sprite_fifo__data[1]),8);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgCData(oldp+4,(vlSelf->PPU3__DOT__LY),8);
        bufp->chgCData(oldp+5,(vlSelf->PPU3__DOT__x_pos),8);
        bufp->chgCData(oldp+6,(vlSelf->PPU3__DOT__sprites_loaded),4);
        bufp->chgBit(oldp+7,(vlSelf->PPU3__DOT__sprite_found));
        bufp->chgSData(oldp+8,(vlSelf->PPU3__DOT__cycles),9);
        bufp->chgCData(oldp+9,(vlSelf->PPU3__DOT__sprite_y_buff[0]),8);
        bufp->chgCData(oldp+10,(vlSelf->PPU3__DOT__sprite_y_buff[1]),8);
        bufp->chgCData(oldp+11,(vlSelf->PPU3__DOT__sprite_y_buff[2]),8);
        bufp->chgCData(oldp+12,(vlSelf->PPU3__DOT__sprite_y_buff[3]),8);
        bufp->chgCData(oldp+13,(vlSelf->PPU3__DOT__sprite_y_buff[4]),8);
        bufp->chgCData(oldp+14,(vlSelf->PPU3__DOT__sprite_y_buff[5]),8);
        bufp->chgCData(oldp+15,(vlSelf->PPU3__DOT__sprite_y_buff[6]),8);
        bufp->chgCData(oldp+16,(vlSelf->PPU3__DOT__sprite_y_buff[7]),8);
        bufp->chgCData(oldp+17,(vlSelf->PPU3__DOT__sprite_y_buff[8]),8);
        bufp->chgCData(oldp+18,(vlSelf->PPU3__DOT__sprite_y_buff[9]),8);
        bufp->chgCData(oldp+19,(vlSelf->PPU3__DOT__sprite_x_buff[0]),8);
        bufp->chgCData(oldp+20,(vlSelf->PPU3__DOT__sprite_x_buff[1]),8);
        bufp->chgCData(oldp+21,(vlSelf->PPU3__DOT__sprite_x_buff[2]),8);
        bufp->chgCData(oldp+22,(vlSelf->PPU3__DOT__sprite_x_buff[3]),8);
        bufp->chgCData(oldp+23,(vlSelf->PPU3__DOT__sprite_x_buff[4]),8);
        bufp->chgCData(oldp+24,(vlSelf->PPU3__DOT__sprite_x_buff[5]),8);
        bufp->chgCData(oldp+25,(vlSelf->PPU3__DOT__sprite_x_buff[6]),8);
        bufp->chgCData(oldp+26,(vlSelf->PPU3__DOT__sprite_x_buff[7]),8);
        bufp->chgCData(oldp+27,(vlSelf->PPU3__DOT__sprite_x_buff[8]),8);
        bufp->chgCData(oldp+28,(vlSelf->PPU3__DOT__sprite_x_buff[9]),8);
        bufp->chgCData(oldp+29,(vlSelf->PPU3__DOT__sprite_offset_buff[0]),8);
        bufp->chgCData(oldp+30,(vlSelf->PPU3__DOT__sprite_offset_buff[1]),8);
        bufp->chgCData(oldp+31,(vlSelf->PPU3__DOT__sprite_offset_buff[2]),8);
        bufp->chgCData(oldp+32,(vlSelf->PPU3__DOT__sprite_offset_buff[3]),8);
        bufp->chgCData(oldp+33,(vlSelf->PPU3__DOT__sprite_offset_buff[4]),8);
        bufp->chgCData(oldp+34,(vlSelf->PPU3__DOT__sprite_offset_buff[5]),8);
        bufp->chgCData(oldp+35,(vlSelf->PPU3__DOT__sprite_offset_buff[6]),8);
        bufp->chgCData(oldp+36,(vlSelf->PPU3__DOT__sprite_offset_buff[7]),8);
        bufp->chgCData(oldp+37,(vlSelf->PPU3__DOT__sprite_offset_buff[8]),8);
        bufp->chgCData(oldp+38,(vlSelf->PPU3__DOT__sprite_offset_buff[9]),8);
        bufp->chgCData(oldp+39,(((2U & (vlSelf->PPU3__DOT__sprite_fifo__DOT__shift_reg
                                        [1U] >> 6U)) 
                                 | (1U & (vlSelf->PPU3__DOT__sprite_fifo__DOT__shift_reg
                                          [0U] >> 7U)))),2);
        bufp->chgCData(oldp+40,(((2U & (vlSelf->PPU3__DOT__bg_fifo__DOT__shift_reg
                                        [1U] >> 6U)) 
                                 | (1U & (vlSelf->PPU3__DOT__bg_fifo__DOT__shift_reg
                                          [0U] >> 7U)))),2);
        bufp->chgCData(oldp+41,(vlSelf->PPU3__DOT__FF40),8);
        bufp->chgCData(oldp+42,(vlSelf->PPU3__DOT__FF41),8);
        bufp->chgCData(oldp+43,(vlSelf->PPU3__DOT__FF43),8);
        bufp->chgCData(oldp+44,(vlSelf->PPU3__DOT__FF42),8);
        bufp->chgCData(oldp+45,(vlSelf->PPU3__DOT__FF45),8);
        bufp->chgCData(oldp+46,(vlSelf->PPU3__DOT__FF46),8);
        bufp->chgCData(oldp+47,(vlSelf->PPU3__DOT__FF47),8);
        bufp->chgCData(oldp+48,((0xfcU & (IData)(vlSelf->PPU3__DOT__FF48))),8);
        bufp->chgCData(oldp+49,((0xfcU & (IData)(vlSelf->PPU3__DOT__FF49))),8);
        bufp->chgCData(oldp+50,(vlSelf->PPU3__DOT__FF4B),8);
        bufp->chgCData(oldp+51,(vlSelf->PPU3__DOT__FF4A),8);
        bufp->chgCData(oldp+52,(vlSelf->PPU3__DOT__FF48),8);
        bufp->chgCData(oldp+53,(vlSelf->PPU3__DOT__FF49),8);
        bufp->chgCData(oldp+54,(vlSelf->PPU3__DOT__bg_fifo__DOT__shift_reg[0]),8);
        bufp->chgCData(oldp+55,(vlSelf->PPU3__DOT__bg_fifo__DOT__shift_reg[1]),8);
        bufp->chgCData(oldp+56,(vlSelf->PPU3__DOT__sprite_fifo__DOT__shift_reg[0]),8);
        bufp->chgCData(oldp+57,(vlSelf->PPU3__DOT__sprite_fifo__DOT__shift_reg[1]),8);
    }
    bufp->chgBit(oldp+58,(vlSelf->clk));
    bufp->chgBit(oldp+59,(vlSelf->rst));
    bufp->chgSData(oldp+60,(vlSelf->ADDR),16);
    bufp->chgBit(oldp+61,(vlSelf->WR));
    bufp->chgBit(oldp+62,(vlSelf->RD));
    bufp->chgCData(oldp+63,(vlSelf->MMIO_DATA_out),8);
    bufp->chgCData(oldp+64,(vlSelf->MMIO_DATA_in),8);
    bufp->chgBit(oldp+65,(vlSelf->IRQ_V_BLANK));
    bufp->chgBit(oldp+66,(vlSelf->IRQ_LCDC));
    bufp->chgCData(oldp+67,(vlSelf->PPU_MODE),2);
    bufp->chgBit(oldp+68,(vlSelf->PPU_RD));
    bufp->chgSData(oldp+69,(vlSelf->PPU_ADDR),16);
    bufp->chgCData(oldp+70,(vlSelf->PPU_DATA_in),8);
    bufp->chgCData(oldp+71,(vlSelf->PX_OUT),2);
    bufp->chgBit(oldp+72,(vlSelf->PX_valid));
    bufp->chgBit(oldp+73,(((((IData)(0x10U) + (IData)(vlSelf->PPU3__DOT__LY)) 
                            >= (IData)(vlSelf->PPU_DATA_in)) 
                           & (((IData)(0x10U) + (IData)(vlSelf->PPU3__DOT__LY)) 
                              < ((IData)(vlSelf->PPU_DATA_in) 
                                 + ((IData)(8U) << 
                                    (1U & ((IData)(vlSelf->PPU3__DOT__FF40) 
                                           >> 2U))))))));
    bufp->chgSData(oldp+74,((0xffffU & ((IData)(vlSelf->PPU_ADDR) 
                                        - (IData)(0xfe00U)))),16);
}

void VPPU3___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPPU3___024root__trace_cleanup\n"); );
    // Init
    VPPU3___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VPPU3___024root*>(voidSelf);
    VPPU3__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
