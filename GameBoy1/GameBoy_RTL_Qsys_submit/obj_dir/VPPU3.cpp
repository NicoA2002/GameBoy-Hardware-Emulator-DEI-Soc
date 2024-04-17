// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VPPU3.h"
#include "VPPU3__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

VPPU3::VPPU3(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VPPU3__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst{vlSymsp->TOP.rst}
    , WR{vlSymsp->TOP.WR}
    , RD{vlSymsp->TOP.RD}
    , MMIO_DATA_out{vlSymsp->TOP.MMIO_DATA_out}
    , MMIO_DATA_in{vlSymsp->TOP.MMIO_DATA_in}
    , IRQ_V_BLANK{vlSymsp->TOP.IRQ_V_BLANK}
    , IRQ_LCDC{vlSymsp->TOP.IRQ_LCDC}
    , PPU_MODE{vlSymsp->TOP.PPU_MODE}
    , PPU_RD{vlSymsp->TOP.PPU_RD}
    , PPU_DATA_in{vlSymsp->TOP.PPU_DATA_in}
    , PX_OUT{vlSymsp->TOP.PX_OUT}
    , PX_valid{vlSymsp->TOP.PX_valid}
    , ADDR{vlSymsp->TOP.ADDR}
    , PPU_ADDR{vlSymsp->TOP.PPU_ADDR}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

VPPU3::VPPU3(const char* _vcname__)
    : VPPU3(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VPPU3::~VPPU3() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VPPU3___024root___eval_debug_assertions(VPPU3___024root* vlSelf);
#endif  // VL_DEBUG
void VPPU3___024root___eval_static(VPPU3___024root* vlSelf);
void VPPU3___024root___eval_initial(VPPU3___024root* vlSelf);
void VPPU3___024root___eval_settle(VPPU3___024root* vlSelf);
void VPPU3___024root___eval(VPPU3___024root* vlSelf);

void VPPU3::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VPPU3::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VPPU3___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        VPPU3___024root___eval_static(&(vlSymsp->TOP));
        VPPU3___024root___eval_initial(&(vlSymsp->TOP));
        VPPU3___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    VPPU3___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool VPPU3::eventsPending() { return false; }

uint64_t VPPU3::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* VPPU3::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void VPPU3___024root___eval_final(VPPU3___024root* vlSelf);

VL_ATTR_COLD void VPPU3::final() {
    VPPU3___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VPPU3::hierName() const { return vlSymsp->name(); }
const char* VPPU3::modelName() const { return "VPPU3"; }
unsigned VPPU3::threads() const { return 1; }
std::unique_ptr<VerilatedTraceConfig> VPPU3::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void VPPU3___024root__trace_init_top(VPPU3___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VPPU3___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VPPU3___024root*>(voidSelf);
    VPPU3__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    VPPU3___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void VPPU3___024root__trace_register(VPPU3___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void VPPU3::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'VPPU3::trace()' shall not be called after 'VerilatedVcdC::open()'.");
    }
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    VPPU3___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
