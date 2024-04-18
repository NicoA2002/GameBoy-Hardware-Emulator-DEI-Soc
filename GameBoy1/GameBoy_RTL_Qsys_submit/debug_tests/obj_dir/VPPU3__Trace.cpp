// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VPPU3__Syms.h"


//======================

void VPPU3::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    VPPU3* t = (VPPU3*)userthis;
    VPPU3__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
        t->traceChgThis(vlSymsp, vcdp, code);
    }
}

//======================


void VPPU3::traceChgThis(VPPU3__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VPPU3* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY((1U & vlTOPp->__Vm_traceActivity))) {
            vlTOPp->traceChgThis__2(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((2U & vlTOPp->__Vm_traceActivity))) {
            vlTOPp->traceChgThis__3(vlSymsp, vcdp, code);
        }
        vlTOPp->traceChgThis__4(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void VPPU3::traceChgThis__2(VPPU3__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VPPU3* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+1,(vlTOPp->PPU3__DOT____Vcellinp__sprite_fifo__data[0]),8);
        vcdp->chgBus(c+2,(vlTOPp->PPU3__DOT____Vcellinp__sprite_fifo__data[1]),8);
        vcdp->chgBus(c+17,(vlTOPp->PPU3__DOT____Vcellinp__bg_fifo__data[0]),8);
        vcdp->chgBus(c+18,(vlTOPp->PPU3__DOT____Vcellinp__bg_fifo__data[1]),8);
    }
}

void VPPU3::traceChgThis__3(VPPU3__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VPPU3* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+33,(vlTOPp->PPU3__DOT__LY),8);
        vcdp->chgBus(c+41,(vlTOPp->PPU3__DOT__x_pos),8);
        vcdp->chgBus(c+49,(vlTOPp->PPU3__DOT__sprites_loaded),4);
        vcdp->chgBit(c+57,(vlTOPp->PPU3__DOT__sprite_found));
        vcdp->chgBus(c+65,(vlTOPp->PPU3__DOT__cycles),9);
        vcdp->chgBus(c+73,(vlTOPp->PPU3__DOT__sprite_y_buff[0]),8);
        vcdp->chgBus(c+74,(vlTOPp->PPU3__DOT__sprite_y_buff[1]),8);
        vcdp->chgBus(c+75,(vlTOPp->PPU3__DOT__sprite_y_buff[2]),8);
        vcdp->chgBus(c+76,(vlTOPp->PPU3__DOT__sprite_y_buff[3]),8);
        vcdp->chgBus(c+77,(vlTOPp->PPU3__DOT__sprite_y_buff[4]),8);
        vcdp->chgBus(c+78,(vlTOPp->PPU3__DOT__sprite_y_buff[5]),8);
        vcdp->chgBus(c+79,(vlTOPp->PPU3__DOT__sprite_y_buff[6]),8);
        vcdp->chgBus(c+80,(vlTOPp->PPU3__DOT__sprite_y_buff[7]),8);
        vcdp->chgBus(c+81,(vlTOPp->PPU3__DOT__sprite_y_buff[8]),8);
        vcdp->chgBus(c+82,(vlTOPp->PPU3__DOT__sprite_y_buff[9]),8);
        vcdp->chgBus(c+153,(vlTOPp->PPU3__DOT__sprite_x_buff[0]),8);
        vcdp->chgBus(c+154,(vlTOPp->PPU3__DOT__sprite_x_buff[1]),8);
        vcdp->chgBus(c+155,(vlTOPp->PPU3__DOT__sprite_x_buff[2]),8);
        vcdp->chgBus(c+156,(vlTOPp->PPU3__DOT__sprite_x_buff[3]),8);
        vcdp->chgBus(c+157,(vlTOPp->PPU3__DOT__sprite_x_buff[4]),8);
        vcdp->chgBus(c+158,(vlTOPp->PPU3__DOT__sprite_x_buff[5]),8);
        vcdp->chgBus(c+159,(vlTOPp->PPU3__DOT__sprite_x_buff[6]),8);
        vcdp->chgBus(c+160,(vlTOPp->PPU3__DOT__sprite_x_buff[7]),8);
        vcdp->chgBus(c+161,(vlTOPp->PPU3__DOT__sprite_x_buff[8]),8);
        vcdp->chgBus(c+162,(vlTOPp->PPU3__DOT__sprite_x_buff[9]),8);
        vcdp->chgBus(c+233,(vlTOPp->PPU3__DOT__sprite_offset_buff[0]),8);
        vcdp->chgBus(c+234,(vlTOPp->PPU3__DOT__sprite_offset_buff[1]),8);
        vcdp->chgBus(c+235,(vlTOPp->PPU3__DOT__sprite_offset_buff[2]),8);
        vcdp->chgBus(c+236,(vlTOPp->PPU3__DOT__sprite_offset_buff[3]),8);
        vcdp->chgBus(c+237,(vlTOPp->PPU3__DOT__sprite_offset_buff[4]),8);
        vcdp->chgBus(c+238,(vlTOPp->PPU3__DOT__sprite_offset_buff[5]),8);
        vcdp->chgBus(c+239,(vlTOPp->PPU3__DOT__sprite_offset_buff[6]),8);
        vcdp->chgBus(c+240,(vlTOPp->PPU3__DOT__sprite_offset_buff[7]),8);
        vcdp->chgBus(c+241,(vlTOPp->PPU3__DOT__sprite_offset_buff[8]),8);
        vcdp->chgBus(c+242,(vlTOPp->PPU3__DOT__sprite_offset_buff[9]),8);
        vcdp->chgBus(c+313,(((2U & (vlTOPp->PPU3__DOT__sprite_fifo__DOT__shift_reg
                                    [1U] >> 6U)) | 
                             (1U & (vlTOPp->PPU3__DOT__sprite_fifo__DOT__shift_reg
                                    [0U] >> 7U)))),2);
        vcdp->chgBus(c+321,(((2U & (vlTOPp->PPU3__DOT__bg_fifo__DOT__shift_reg
                                    [1U] >> 6U)) | 
                             (1U & (vlTOPp->PPU3__DOT__bg_fifo__DOT__shift_reg
                                    [0U] >> 7U)))),2);
        vcdp->chgBus(c+329,(vlTOPp->PPU3__DOT__FF40),8);
        vcdp->chgBus(c+337,(vlTOPp->PPU3__DOT__FF41),8);
        vcdp->chgBus(c+345,(vlTOPp->PPU3__DOT__FF43),8);
        vcdp->chgBus(c+353,(vlTOPp->PPU3__DOT__FF42),8);
        vcdp->chgBus(c+361,(vlTOPp->PPU3__DOT__FF45),8);
        vcdp->chgBus(c+369,(vlTOPp->PPU3__DOT__FF46),8);
        vcdp->chgBus(c+377,(vlTOPp->PPU3__DOT__FF47),8);
        vcdp->chgBus(c+385,((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF48))),8);
        vcdp->chgBus(c+393,((0xfcU & (IData)(vlTOPp->PPU3__DOT__FF49))),8);
        vcdp->chgBus(c+401,(vlTOPp->PPU3__DOT__FF4B),8);
        vcdp->chgBus(c+409,(vlTOPp->PPU3__DOT__FF4A),8);
        vcdp->chgBus(c+417,(vlTOPp->PPU3__DOT__FF48),8);
        vcdp->chgBus(c+425,(vlTOPp->PPU3__DOT__FF49),8);
        vcdp->chgBus(c+433,(vlTOPp->PPU3__DOT__sprite_fifo__DOT__shift_reg[0]),8);
        vcdp->chgBus(c+434,(vlTOPp->PPU3__DOT__sprite_fifo__DOT__shift_reg[1]),8);
        vcdp->chgBus(c+449,(vlTOPp->PPU3__DOT__bg_fifo__DOT__shift_reg[0]),8);
        vcdp->chgBus(c+450,(vlTOPp->PPU3__DOT__bg_fifo__DOT__shift_reg[1]),8);
    }
}

void VPPU3::traceChgThis__4(VPPU3__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VPPU3* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+465,(vlTOPp->clk));
        vcdp->chgBit(c+473,(vlTOPp->rst));
        vcdp->chgBus(c+481,(vlTOPp->ADDR),16);
        vcdp->chgBit(c+489,(vlTOPp->WR));
        vcdp->chgBit(c+497,(vlTOPp->RD));
        vcdp->chgBus(c+505,(vlTOPp->MMIO_DATA_out),8);
        vcdp->chgBus(c+513,(vlTOPp->MMIO_DATA_in),8);
        vcdp->chgBit(c+521,(vlTOPp->IRQ_V_BLANK));
        vcdp->chgBit(c+529,(vlTOPp->IRQ_LCDC));
        vcdp->chgBus(c+537,(vlTOPp->PPU_MODE),2);
        vcdp->chgBit(c+545,(vlTOPp->PPU_RD));
        vcdp->chgBus(c+553,(vlTOPp->PPU_ADDR),16);
        vcdp->chgBus(c+561,(vlTOPp->PPU_DATA_in),8);
        vcdp->chgBus(c+569,(vlTOPp->PX_OUT),2);
        vcdp->chgBit(c+577,(vlTOPp->PX_valid));
        vcdp->chgBit(c+585,(((((IData)(0x10U) + (IData)(vlTOPp->PPU3__DOT__LY)) 
                              >= (IData)(vlTOPp->PPU_DATA_in)) 
                             & (((IData)(0x10U) + (IData)(vlTOPp->PPU3__DOT__LY)) 
                                < ((IData)(vlTOPp->PPU_DATA_in) 
                                   + ((IData)(8U) << 
                                      (1U & ((IData)(vlTOPp->PPU3__DOT__FF40) 
                                             >> 2U))))))));
        vcdp->chgBus(c+593,((0xffffU & ((IData)(vlTOPp->PPU_ADDR) 
                                        - (IData)(0xfe00U)))),16);
    }
}
