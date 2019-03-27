// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VVortex.h for the primary calling header

#include "VVortex.h"
#include "VVortex__Syms.h"


//--------------------
// STATIC VARIABLES

// Begin mtask footprint  all: 
VL_ST_SIG8(VVortex::__Vtable1_Vortex__DOT__vx_decode__DOT__mul_alu[8],4,0);

//--------------------

VL_CTOR_IMP(VVortex) {
    VVortex__Syms* __restrict vlSymsp = __VlSymsp = new VVortex__Syms(this, name());
    VVortex* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VVortex::__Vconfigure(VVortex__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

VVortex::~VVortex() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void VVortex::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VVortex::eval\n"); );
    VVortex__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    VVortex* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif // VL_DEBUG
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
	    VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Verilated model didn't converge");
	} else {
	    __Vchange = _change_request(vlSymsp);
	}
    } while (VL_UNLIKELY(__Vchange));
}

void VVortex::_eval_initial_loop(VVortex__Syms* __restrict vlSymsp) {
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
	    VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Verilated model didn't DC converge");
	} else {
	    __Vchange = _change_request(vlSymsp);
	}
    } while (VL_UNLIKELY(__Vchange));
}

//--------------------
// Internal Methods

VL_INLINE_OPT void VVortex::_sequent__TOP__1(VVortex__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VVortex::_sequent__TOP__1\n"); );
    VVortex* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    // Begin mtask footprint  all: 
    VL_SIG8(__Vdlyvset__Vortex__DOT__vx_f_d_reg__DOT__valid__v0,0,0);
    VL_SIG8(__Vdlyvval__Vortex__DOT__vx_f_d_reg__DOT__valid__v2,0,0);
    VL_SIG8(__Vdlyvset__Vortex__DOT__vx_f_d_reg__DOT__valid__v2,0,0);
    VL_SIG8(__Vdlyvval__Vortex__DOT__vx_f_d_reg__DOT__valid__v3,0,0);
    // Body
    __Vdlyvset__Vortex__DOT__vx_f_d_reg__DOT__valid__v0 = 0U;
    __Vdlyvset__Vortex__DOT__vx_f_d_reg__DOT__valid__v2 = 0U;
    // ALWAYS at VX_fetch.v:144
    vlTOPp->Vortex__DOT__vx_fetch__DOT__old = ((IData)(vlTOPp->reset)
					        ? 0U
					        : vlTOPp->Vortex__DOT__vx_fetch__DOT__temp_PC);
    // ALWAYS at VX_fetch.v:144
    vlTOPp->Vortex__DOT__vx_fetch__DOT__BR_reg = ((IData)(vlTOPp->reset)
						   ? 0U
						   : 
						  ((IData)(4U) 
						   + vlTOPp->Vortex__DOT__memory_branch_dest));
    // ALWAYS at VX_fetch.v:144
    vlTOPp->Vortex__DOT__vx_fetch__DOT__delay_reg = 0U;
    // ALWAYS at VX_fetch.v:144
    vlTOPp->Vortex__DOT__vx_fetch__DOT__real_PC = ((IData)(vlTOPp->reset)
						    ? 0U
						    : 
						   ((IData)(4U) 
						    + vlTOPp->Vortex__DOT__vx_fetch__DOT__PC_to_use));
    // ALWAYS at VX_fetch.v:144
    vlTOPp->Vortex__DOT__vx_fetch__DOT__stall_reg = 
	((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->Vortex__DOT__vx_fetch__DOT__stall));
    // ALWAYS at VX_f_d_reg.v:29
    if (vlTOPp->reset) {
	__Vdlyvset__Vortex__DOT__vx_f_d_reg__DOT__valid__v0 = 1U;
    } else {
	if ((1U & (~ (IData)(vlTOPp->Vortex__DOT__forwarding_fwd_stall)))) {
	    __Vdlyvval__Vortex__DOT__vx_f_d_reg__DOT__valid__v2 
		= vlTOPp->Vortex__DOT____Vcellinp__vx_f_d_reg__in_valid
		[1U];
	    __Vdlyvset__Vortex__DOT__vx_f_d_reg__DOT__valid__v2 = 1U;
	    __Vdlyvval__Vortex__DOT__vx_f_d_reg__DOT__valid__v3 
		= vlTOPp->Vortex__DOT____Vcellinp__vx_f_d_reg__in_valid
		[0U];
	}
    }
    // ALWAYS at VX_fetch.v:144
    vlTOPp->Vortex__DOT__vx_fetch__DOT__state = ((IData)(vlTOPp->reset)
						  ? 0U
						  : 
						 ((IData)(vlTOPp->Vortex__DOT__vx_fetch__DOT__prev_debug)
						   ? 4U
						   : 
						  ((IData)(vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__jal)
						    ? 1U
						    : 
						   ((IData)(vlTOPp->Vortex__DOT__memory_branch_dir)
						     ? 2U
						     : 0U))));
    // ALWAYS at VX_fetch.v:144
    vlTOPp->Vortex__DOT__vx_fetch__DOT__JAL_reg = ((IData)(vlTOPp->reset)
						    ? 0U
						    : 
						   ((IData)(4U) 
						    + vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__jal_dest));
    // ALWAYSPOST at VX_f_d_reg.v:34
    if (__Vdlyvset__Vortex__DOT__vx_f_d_reg__DOT__valid__v0) {
	vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__valid[0U] = 0U;
	vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__valid[1U] = 0U;
    }
    if (__Vdlyvset__Vortex__DOT__vx_f_d_reg__DOT__valid__v2) {
	vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__valid[1U] 
	    = __Vdlyvval__Vortex__DOT__vx_f_d_reg__DOT__valid__v2;
	vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__valid[0U] 
	    = __Vdlyvval__Vortex__DOT__vx_f_d_reg__DOT__valid__v3;
    }
    vlTOPp->Vortex__DOT____Vcellout__vx_f_d_reg__out_valid[1U] 
	= vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__valid
	[1U];
    vlTOPp->Vortex__DOT____Vcellout__vx_f_d_reg__out_valid[0U] 
	= vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__valid
	[0U];
    // ALWAYS at VX_fetch.v:144
    vlTOPp->Vortex__DOT__vx_fetch__DOT__prev_debug = 0U;
    // ALWAYS at VX_fetch.v:82
    vlTOPp->Vortex__DOT__vx_fetch__DOT__PC_to_use = 
	((IData)(vlTOPp->Vortex__DOT__vx_fetch__DOT__delay_reg)
	  ? vlTOPp->Vortex__DOT__vx_fetch__DOT__old
	  : ((IData)(vlTOPp->Vortex__DOT__vx_fetch__DOT__stall_reg)
	      ? vlTOPp->Vortex__DOT__vx_fetch__DOT__old
	      : ((0x10U & (IData)(vlTOPp->Vortex__DOT__vx_fetch__DOT__state))
		  ? 0U : ((8U & (IData)(vlTOPp->Vortex__DOT__vx_fetch__DOT__state))
			   ? 0U : ((4U & (IData)(vlTOPp->Vortex__DOT__vx_fetch__DOT__state))
				    ? ((2U & (IData)(vlTOPp->Vortex__DOT__vx_fetch__DOT__state))
				        ? 0U : ((1U 
						 & (IData)(vlTOPp->Vortex__DOT__vx_fetch__DOT__state))
						 ? 0U
						 : vlTOPp->Vortex__DOT__vx_fetch__DOT__old))
				    : ((2U & (IData)(vlTOPp->Vortex__DOT__vx_fetch__DOT__state))
				        ? ((1U & (IData)(vlTOPp->Vortex__DOT__vx_fetch__DOT__state))
					    ? vlTOPp->Vortex__DOT__vx_fetch__DOT__real_PC
					    : vlTOPp->Vortex__DOT__vx_fetch__DOT__BR_reg)
				        : ((1U & (IData)(vlTOPp->Vortex__DOT__vx_fetch__DOT__state))
					    ? vlTOPp->Vortex__DOT__vx_fetch__DOT__JAL_reg
					    : vlTOPp->Vortex__DOT__vx_fetch__DOT__real_PC)))))));
    vlTOPp->Vortex__DOT__f_d_valid[1U] = vlTOPp->Vortex__DOT____Vcellout__vx_f_d_reg__out_valid
	[1U];
    vlTOPp->Vortex__DOT__f_d_valid[0U] = vlTOPp->Vortex__DOT____Vcellout__vx_f_d_reg__out_valid
	[0U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_decode__in_valid[1U] 
	= vlTOPp->Vortex__DOT__f_d_valid[1U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_decode__in_valid[0U] 
	= vlTOPp->Vortex__DOT__f_d_valid[0U];
    vlTOPp->Vortex__DOT____Vcellout__vx_decode__out_valid[1U] 
	= vlTOPp->Vortex__DOT____Vcellinp__vx_decode__in_valid
	[1U];
    vlTOPp->Vortex__DOT____Vcellout__vx_decode__out_valid[0U] 
	= vlTOPp->Vortex__DOT____Vcellinp__vx_decode__in_valid
	[0U];
    vlTOPp->Vortex__DOT__decode_valid[1U] = vlTOPp->Vortex__DOT____Vcellout__vx_decode__out_valid
	[1U];
    vlTOPp->Vortex__DOT__decode_valid[0U] = vlTOPp->Vortex__DOT____Vcellout__vx_decode__out_valid
	[0U];
}

VL_INLINE_OPT void VVortex::_sequent__TOP__2(VVortex__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VVortex::_sequent__TOP__2\n"); );
    VVortex* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    // Begin mtask footprint  all: 
    VL_SIG8(__Vdlyvdim0__Vortex__DOT__vx_decode__DOT__gen_code_label__BRA__0__KET____DOT__vx_register_file__DOT__registers__v0,4,0);
    VL_SIG8(__Vdlyvset__Vortex__DOT__vx_decode__DOT__gen_code_label__BRA__0__KET____DOT__vx_register_file__DOT__registers__v0,0,0);
    VL_SIG8(__Vdlyvdim0__Vortex__DOT__vx_decode__DOT__gen_code_label__BRA__1__KET____DOT__vx_register_file__DOT__registers__v0,4,0);
    VL_SIG8(__Vdlyvset__Vortex__DOT__vx_decode__DOT__gen_code_label__BRA__1__KET____DOT__vx_register_file__DOT__registers__v0,0,0);
    VL_SIG8(__Vdlyvval__Vortex__DOT__vx_d_e_reg__DOT__valid__v0,0,0);
    VL_SIG8(__Vdlyvval__Vortex__DOT__vx_d_e_reg__DOT__valid__v1,0,0);
    VL_SIG8(__Vdlyvval__Vortex__DOT__vx_e_m_reg__DOT__valid__v0,0,0);
    VL_SIG8(__Vdlyvval__Vortex__DOT__vx_e_m_reg__DOT__valid__v1,0,0);
    VL_SIG8(__Vdlyvval__Vortex__DOT__vx_m_w_reg__DOT__valid__v0,0,0);
    VL_SIG8(__Vdlyvval__Vortex__DOT__vx_m_w_reg__DOT__valid__v1,0,0);
    VL_SIG8(__Vdlyvset__Vortex__DOT__vx_csr_handler__DOT__csr__v0,0,0);
    VL_SIG16(__Vdlyvdim0__Vortex__DOT__vx_csr_handler__DOT__csr__v0,11,0);
    VL_SIG16(__Vdlyvval__Vortex__DOT__vx_csr_handler__DOT__csr__v0,11,0);
    VL_SIG(__Vdlyvval__Vortex__DOT__vx_decode__DOT__gen_code_label__BRA__0__KET____DOT__vx_register_file__DOT__registers__v0,31,0);
    VL_SIG(__Vdlyvval__Vortex__DOT__vx_decode__DOT__gen_code_label__BRA__1__KET____DOT__vx_register_file__DOT__registers__v0,31,0);
    VL_SIG(__Vdlyvval__Vortex__DOT__vx_d_e_reg__DOT__reg_data__v0,31,0);
    VL_SIG(__Vdlyvval__Vortex__DOT__vx_d_e_reg__DOT__reg_data__v1,31,0);
    VL_SIG(__Vdlyvval__Vortex__DOT__vx_d_e_reg__DOT__reg_data__v2,31,0);
    VL_SIG(__Vdlyvval__Vortex__DOT__vx_d_e_reg__DOT__reg_data__v3,31,0);
    VL_SIG(__Vdlyvval__Vortex__DOT__vx_e_m_reg__DOT__alu_result__v0,31,0);
    VL_SIG(__Vdlyvval__Vortex__DOT__vx_e_m_reg__DOT__alu_result__v1,31,0);
    VL_SIG(__Vdlyvval__Vortex__DOT__vx_e_m_reg__DOT__reg_data__v0,31,0);
    VL_SIG(__Vdlyvval__Vortex__DOT__vx_e_m_reg__DOT__reg_data__v1,31,0);
    VL_SIG(__Vdlyvval__Vortex__DOT__vx_e_m_reg__DOT__reg_data__v2,31,0);
    VL_SIG(__Vdlyvval__Vortex__DOT__vx_e_m_reg__DOT__reg_data__v3,31,0);
    VL_SIG(__Vdlyvval__Vortex__DOT__vx_m_w_reg__DOT__mem_result__v0,31,0);
    VL_SIG(__Vdlyvval__Vortex__DOT__vx_m_w_reg__DOT__mem_result__v1,31,0);
    VL_SIG(__Vdlyvval__Vortex__DOT__vx_m_w_reg__DOT__alu_result__v0,31,0);
    VL_SIG(__Vdlyvval__Vortex__DOT__vx_m_w_reg__DOT__alu_result__v1,31,0);
    // Body
    __Vdlyvset__Vortex__DOT__vx_decode__DOT__gen_code_label__BRA__1__KET____DOT__vx_register_file__DOT__registers__v0 = 0U;
    __Vdlyvset__Vortex__DOT__vx_decode__DOT__gen_code_label__BRA__0__KET____DOT__vx_register_file__DOT__registers__v0 = 0U;
    __Vdlyvset__Vortex__DOT__vx_csr_handler__DOT__csr__v0 = 0U;
    // ALWAYS at VX_m_w_reg.v:60
    __Vdlyvval__Vortex__DOT__vx_m_w_reg__DOT__valid__v0 
	= vlTOPp->Vortex__DOT____Vcellinp__vx_m_w_reg__in_valid
	[1U];
    __Vdlyvval__Vortex__DOT__vx_m_w_reg__DOT__valid__v1 
	= vlTOPp->Vortex__DOT____Vcellinp__vx_m_w_reg__in_valid
	[0U];
    // ALWAYS at VX_e_m_reg.v:123
    __Vdlyvval__Vortex__DOT__vx_e_m_reg__DOT__valid__v0 
	= vlTOPp->Vortex__DOT____Vcellinp__vx_e_m_reg__in_valid
	[1U];
    __Vdlyvval__Vortex__DOT__vx_e_m_reg__DOT__valid__v1 
	= vlTOPp->Vortex__DOT____Vcellinp__vx_e_m_reg__in_valid
	[0U];
    // ALWAYS at VX_e_m_reg.v:123
    __Vdlyvval__Vortex__DOT__vx_e_m_reg__DOT__reg_data__v0 
	= vlTOPp->Vortex__DOT____Vcellinp__vx_e_m_reg__in_reg_data
	[3U];
    __Vdlyvval__Vortex__DOT__vx_e_m_reg__DOT__reg_data__v1 
	= vlTOPp->Vortex__DOT____Vcellinp__vx_e_m_reg__in_reg_data
	[2U];
    __Vdlyvval__Vortex__DOT__vx_e_m_reg__DOT__reg_data__v2 
	= vlTOPp->Vortex__DOT____Vcellinp__vx_e_m_reg__in_reg_data
	[1U];
    __Vdlyvval__Vortex__DOT__vx_e_m_reg__DOT__reg_data__v3 
	= vlTOPp->Vortex__DOT____Vcellinp__vx_e_m_reg__in_reg_data
	[0U];
    // ALWAYS at VX_m_w_reg.v:60
    __Vdlyvval__Vortex__DOT__vx_m_w_reg__DOT__alu_result__v0 
	= vlTOPp->Vortex__DOT____Vcellinp__vx_m_w_reg__in_alu_result
	[1U];
    __Vdlyvval__Vortex__DOT__vx_m_w_reg__DOT__alu_result__v1 
	= vlTOPp->Vortex__DOT____Vcellinp__vx_m_w_reg__in_alu_result
	[0U];
    // ALWAYS at VX_m_w_reg.v:60
    __Vdlyvval__Vortex__DOT__vx_m_w_reg__DOT__mem_result__v0 
	= vlTOPp->Vortex__DOT____Vcellinp__vx_m_w_reg__in_mem_result
	[1U];
    __Vdlyvval__Vortex__DOT__vx_m_w_reg__DOT__mem_result__v1 
	= vlTOPp->Vortex__DOT____Vcellinp__vx_m_w_reg__in_mem_result
	[0U];
    // ALWAYS at VX_d_e_reg.v:133
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__upper_immed 
	= (0xfffffU & ((IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__stalling)
		        ? 0U : ((0x37U == (0x7fU & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction))
				 ? (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
				    >> 0xcU) : ((0x17U 
						 == 
						 (0x7fU 
						  & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction))
						 ? 
						(vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
						 >> 0xcU)
						 : 0U))));
    // ALWAYS at VX_csr_handler.v:34
    vlTOPp->Vortex__DOT__vx_csr_handler__DOT__decode_csr_address 
	= vlTOPp->Vortex__DOT__decode_csr_address;
    // ALWAYS at VX_csr_handler.v:34
    vlTOPp->Vortex__DOT__vx_csr_handler__DOT__cycle 
	= (VL_ULL(1) + vlTOPp->Vortex__DOT__vx_csr_handler__DOT__cycle);
    // ALWAYS at VX_csr_handler.v:34
    if (vlTOPp->Vortex__DOT__m_w_valid[0U]) {
	vlTOPp->Vortex__DOT__vx_csr_handler__DOT__instret 
	    = (VL_ULL(1) + vlTOPp->Vortex__DOT__vx_csr_handler__DOT__instret);
    }
    // ALWAYS at VX_d_e_reg.v:133
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__rs2_src = 
	(1U & ((IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__stalling)
	        ? 0U : (1U & (((IData)(vlTOPp->Vortex__DOT__vx_decode__DOT__is_itype) 
			       | (0x23U == (0x7fU & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)))
			       ? 1U : 0U))));
    // ALWAYS at VX_e_m_reg.v:123
    __Vdlyvval__Vortex__DOT__vx_e_m_reg__DOT__alu_result__v0 
	= vlTOPp->Vortex__DOT____Vcellinp__vx_e_m_reg__in_alu_result
	[1U];
    __Vdlyvval__Vortex__DOT__vx_e_m_reg__DOT__alu_result__v1 
	= vlTOPp->Vortex__DOT____Vcellinp__vx_e_m_reg__in_alu_result
	[0U];
    // ALWAYS at VX_e_m_reg.v:123
    vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__branch_type 
	= vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__branch_type;
    // ALWAYS at VX_d_e_reg.v:133
    __Vdlyvval__Vortex__DOT__vx_d_e_reg__DOT__valid__v0 
	= ((IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__stalling)
	    ? vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__valid_z
	   [1U] : vlTOPp->Vortex__DOT____Vcellinp__vx_d_e_reg__in_valid
	   [1U]);
    __Vdlyvval__Vortex__DOT__vx_d_e_reg__DOT__valid__v1 
	= ((IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__stalling)
	    ? vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__valid_z
	   [0U] : vlTOPp->Vortex__DOT____Vcellinp__vx_d_e_reg__in_valid
	   [0U]);
    // ALWAYS at VX_e_m_reg.v:123
    vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__mem_read 
	= vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__mem_read;
    // ALWAYS at VX_e_m_reg.v:123
    vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__mem_write 
	= vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__mem_write;
    // ALWAYS at VX_e_m_reg.v:123
    vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__jal = vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__jal;
    // ALWAYS at VX_e_m_reg.v:123
    vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__curr_PC = vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__curr_PC;
    // ALWAYS at VX_e_m_reg.v:123
    vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__branch_offset 
	= vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__itype_immed;
    // ALWAYS at VX_m_w_reg.v:60
    vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__PC_next = vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__PC_next;
    // ALWAYS at VX_e_m_reg.v:123
    vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__jal_dest 
	= (vlTOPp->Vortex__DOT____Vcellinp__vx_execute__in_reg_data
	   [0U] + vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__jal_offset);
    // ALWAYS at VX_register_file.v:36
    if ((((0U != (IData)(vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__wb)) 
	  & (0U != (IData)(vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__rd))) 
	 & vlTOPp->Vortex__DOT____Vcellinp__vx_decode__in_wb_valid
	 [1U])) {
	__Vdlyvval__Vortex__DOT__vx_decode__DOT__gen_code_label__BRA__1__KET____DOT__vx_register_file__DOT__registers__v0 
	    = vlTOPp->Vortex__DOT____Vcellinp__vx_decode__in_write_data
	    [1U];
	__Vdlyvset__Vortex__DOT__vx_decode__DOT__gen_code_label__BRA__1__KET____DOT__vx_register_file__DOT__registers__v0 = 1U;
	__Vdlyvdim0__Vortex__DOT__vx_decode__DOT__gen_code_label__BRA__1__KET____DOT__vx_register_file__DOT__registers__v0 
	    = vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__rd;
    }
    // ALWAYS at VX_register_file.v:36
    if ((((0U != (IData)(vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__wb)) 
	  & (0U != (IData)(vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__rd))) 
	 & vlTOPp->Vortex__DOT____Vcellinp__vx_decode__in_wb_valid
	 [0U])) {
	__Vdlyvval__Vortex__DOT__vx_decode__DOT__gen_code_label__BRA__0__KET____DOT__vx_register_file__DOT__registers__v0 
	    = vlTOPp->Vortex__DOT____Vcellinp__vx_decode__in_write_data
	    [0U];
	__Vdlyvset__Vortex__DOT__vx_decode__DOT__gen_code_label__BRA__0__KET____DOT__vx_register_file__DOT__registers__v0 = 1U;
	__Vdlyvdim0__Vortex__DOT__vx_decode__DOT__gen_code_label__BRA__0__KET____DOT__vx_register_file__DOT__registers__v0 
	    = vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__rd;
    }
    // ALWAYS at VX_csr_handler.v:43
    if (vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__is_csr) {
	__Vdlyvval__Vortex__DOT__vx_csr_handler__DOT__csr__v0 
	    = (0xfffU & vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__csr_result);
	__Vdlyvset__Vortex__DOT__vx_csr_handler__DOT__csr__v0 = 1U;
	__Vdlyvdim0__Vortex__DOT__vx_csr_handler__DOT__csr__v0 
	    = vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__csr_address;
    }
    // ALWAYS at VX_d_e_reg.v:133
    __Vdlyvval__Vortex__DOT__vx_d_e_reg__DOT__reg_data__v0 
	= ((IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__stalling)
	    ? vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__reg_data_z
	   [3U] : vlTOPp->Vortex__DOT____Vcellinp__vx_d_e_reg__in_reg_data
	   [3U]);
    __Vdlyvval__Vortex__DOT__vx_d_e_reg__DOT__reg_data__v1 
	= ((IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__stalling)
	    ? vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__reg_data_z
	   [2U] : vlTOPp->Vortex__DOT____Vcellinp__vx_d_e_reg__in_reg_data
	   [2U]);
    __Vdlyvval__Vortex__DOT__vx_d_e_reg__DOT__reg_data__v2 
	= ((IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__stalling)
	    ? vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__reg_data_z
	   [1U] : vlTOPp->Vortex__DOT____Vcellinp__vx_d_e_reg__in_reg_data
	   [1U]);
    __Vdlyvval__Vortex__DOT__vx_d_e_reg__DOT__reg_data__v3 
	= ((IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__stalling)
	    ? vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__reg_data_z
	   [0U] : vlTOPp->Vortex__DOT____Vcellinp__vx_d_e_reg__in_reg_data
	   [0U]);
    // ALWAYSPOST at VX_m_w_reg.v:69
    vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__valid[1U] 
	= __Vdlyvval__Vortex__DOT__vx_m_w_reg__DOT__valid__v0;
    vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__valid[0U] 
	= __Vdlyvval__Vortex__DOT__vx_m_w_reg__DOT__valid__v1;
    // ALWAYSPOST at VX_e_m_reg.v:142
    vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__valid[1U] 
	= __Vdlyvval__Vortex__DOT__vx_e_m_reg__DOT__valid__v0;
    vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__valid[0U] 
	= __Vdlyvval__Vortex__DOT__vx_e_m_reg__DOT__valid__v1;
    // ALWAYSPOST at VX_e_m_reg.v:133
    vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__reg_data[3U] 
	= __Vdlyvval__Vortex__DOT__vx_e_m_reg__DOT__reg_data__v0;
    vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__reg_data[2U] 
	= __Vdlyvval__Vortex__DOT__vx_e_m_reg__DOT__reg_data__v1;
    vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__reg_data[1U] 
	= __Vdlyvval__Vortex__DOT__vx_e_m_reg__DOT__reg_data__v2;
    vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__reg_data[0U] 
	= __Vdlyvval__Vortex__DOT__vx_e_m_reg__DOT__reg_data__v3;
    // ALWAYSPOST at VX_m_w_reg.v:62
    vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__alu_result[1U] 
	= __Vdlyvval__Vortex__DOT__vx_m_w_reg__DOT__alu_result__v0;
    vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__alu_result[0U] 
	= __Vdlyvval__Vortex__DOT__vx_m_w_reg__DOT__alu_result__v1;
    // ALWAYSPOST at VX_m_w_reg.v:63
    vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__mem_result[1U] 
	= __Vdlyvval__Vortex__DOT__vx_m_w_reg__DOT__mem_result__v0;
    vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__mem_result[0U] 
	= __Vdlyvval__Vortex__DOT__vx_m_w_reg__DOT__mem_result__v1;
    // ALWAYSPOST at VX_e_m_reg.v:125
    vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__alu_result[1U] 
	= __Vdlyvval__Vortex__DOT__vx_e_m_reg__DOT__alu_result__v0;
    vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__alu_result[0U] 
	= __Vdlyvval__Vortex__DOT__vx_e_m_reg__DOT__alu_result__v1;
    // ALWAYSPOST at VX_d_e_reg.v:154
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__valid[1U] 
	= __Vdlyvval__Vortex__DOT__vx_d_e_reg__DOT__valid__v0;
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__valid[0U] 
	= __Vdlyvval__Vortex__DOT__vx_d_e_reg__DOT__valid__v1;
    // ALWAYSPOST at VX_register_file.v:39
    if (__Vdlyvset__Vortex__DOT__vx_decode__DOT__gen_code_label__BRA__1__KET____DOT__vx_register_file__DOT__registers__v0) {
	vlTOPp->Vortex__DOT__vx_decode__DOT__gen_code_label__BRA__1__KET____DOT__vx_register_file__DOT__registers[__Vdlyvdim0__Vortex__DOT__vx_decode__DOT__gen_code_label__BRA__1__KET____DOT__vx_register_file__DOT__registers__v0] 
	    = __Vdlyvval__Vortex__DOT__vx_decode__DOT__gen_code_label__BRA__1__KET____DOT__vx_register_file__DOT__registers__v0;
    }
    // ALWAYSPOST at VX_register_file.v:39
    if (__Vdlyvset__Vortex__DOT__vx_decode__DOT__gen_code_label__BRA__0__KET____DOT__vx_register_file__DOT__registers__v0) {
	vlTOPp->Vortex__DOT__vx_decode__DOT__gen_code_label__BRA__0__KET____DOT__vx_register_file__DOT__registers[__Vdlyvdim0__Vortex__DOT__vx_decode__DOT__gen_code_label__BRA__0__KET____DOT__vx_register_file__DOT__registers__v0] 
	    = __Vdlyvval__Vortex__DOT__vx_decode__DOT__gen_code_label__BRA__0__KET____DOT__vx_register_file__DOT__registers__v0;
    }
    // ALWAYSPOST at VX_csr_handler.v:45
    if (__Vdlyvset__Vortex__DOT__vx_csr_handler__DOT__csr__v0) {
	vlTOPp->Vortex__DOT__vx_csr_handler__DOT__csr[__Vdlyvdim0__Vortex__DOT__vx_csr_handler__DOT__csr__v0] 
	    = __Vdlyvval__Vortex__DOT__vx_csr_handler__DOT__csr__v0;
    }
    // ALWAYSPOST at VX_d_e_reg.v:138
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__reg_data[3U] 
	= __Vdlyvval__Vortex__DOT__vx_d_e_reg__DOT__reg_data__v0;
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__reg_data[2U] 
	= __Vdlyvval__Vortex__DOT__vx_d_e_reg__DOT__reg_data__v1;
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__reg_data[1U] 
	= __Vdlyvval__Vortex__DOT__vx_d_e_reg__DOT__reg_data__v2;
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__reg_data[0U] 
	= __Vdlyvval__Vortex__DOT__vx_d_e_reg__DOT__reg_data__v3;
    vlTOPp->Vortex__DOT____Vcellout__vx_m_w_reg__out_valid[1U] 
	= vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__valid
	[1U];
    vlTOPp->Vortex__DOT____Vcellout__vx_m_w_reg__out_valid[0U] 
	= vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__valid
	[0U];
    vlTOPp->Vortex__DOT____Vcellout__vx_e_m_reg__out_valid[1U] 
	= vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__valid
	[1U];
    vlTOPp->Vortex__DOT____Vcellout__vx_e_m_reg__out_valid[0U] 
	= vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__valid
	[0U];
    vlTOPp->Vortex__DOT____Vcellout__vx_e_m_reg__out_reg_data[3U] 
	= vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__reg_data
	[3U];
    vlTOPp->Vortex__DOT____Vcellout__vx_e_m_reg__out_reg_data[2U] 
	= vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__reg_data
	[2U];
    vlTOPp->Vortex__DOT____Vcellout__vx_e_m_reg__out_reg_data[1U] 
	= vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__reg_data
	[1U];
    vlTOPp->Vortex__DOT____Vcellout__vx_e_m_reg__out_reg_data[0U] 
	= vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__reg_data
	[0U];
    vlTOPp->Vortex__DOT____Vcellout__vx_m_w_reg__out_alu_result[1U] 
	= vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__alu_result
	[1U];
    vlTOPp->Vortex__DOT____Vcellout__vx_m_w_reg__out_alu_result[0U] 
	= vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__alu_result
	[0U];
    vlTOPp->Vortex__DOT____Vcellout__vx_m_w_reg__out_mem_result[1U] 
	= vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__mem_result
	[1U];
    vlTOPp->Vortex__DOT____Vcellout__vx_m_w_reg__out_mem_result[0U] 
	= vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__mem_result
	[0U];
    vlTOPp->Vortex__DOT____Vcellout__vx_e_m_reg__out_alu_result[1U] 
	= vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__alu_result
	[1U];
    vlTOPp->Vortex__DOT____Vcellout__vx_e_m_reg__out_alu_result[0U] 
	= vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__alu_result
	[0U];
    // ALWAYS at VX_d_e_reg.v:133
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__branch_type 
	= ((IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__stalling)
	    ? 0U : (IData)(vlTOPp->Vortex__DOT__decode_branch_type));
    vlTOPp->Vortex__DOT____Vcellout__vx_d_e_reg__out_valid[1U] 
	= vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__valid
	[1U];
    vlTOPp->Vortex__DOT____Vcellout__vx_d_e_reg__out_valid[0U] 
	= vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__valid
	[0U];
    vlTOPp->out_cache_driver_in_mem_read = vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__mem_read;
    // ALWAYS at VX_d_e_reg.v:133
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__mem_read 
	= (7U & ((IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__stalling)
		  ? 7U : ((3U == (0x7fU & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction))
			   ? (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
			      >> 0xcU) : 7U)));
    vlTOPp->out_cache_driver_in_mem_write = vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__mem_write;
    // ALWAYS at VX_d_e_reg.v:133
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__mem_write 
	= (7U & ((IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__stalling)
		  ? 7U : ((0x23U == (0x7fU & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction))
			   ? (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
			      >> 0xcU) : 7U)));
    // ALWAYS at VX_d_e_reg.v:133
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__jal = ((~ (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__stalling)) 
						 & ((0x6fU 
						     == 
						     (0x7fU 
						      & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)) 
						    | ((0x67U 
							== 
							(0x7fU 
							 & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)) 
						       | ((0x73U 
							   == 
							   (0x7fU 
							    & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)) 
							  & ((0U 
							      == 
							      (7U 
							       & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
								  >> 0xcU))) 
							     & (2U 
								> 
								(0xfffU 
								 & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
								    >> 0x14U))))))));
    // ALWAYS at VX_d_e_reg.v:133
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__curr_PC = 
	((IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__stalling)
	  ? 0U : vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__curr_PC);
    vlTOPp->Vortex__DOT__memory_branch_dest = (vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__curr_PC 
					       + (vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__branch_offset 
						  << 1U));
    // ALWAYS at VX_d_e_reg.v:133
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__itype_immed 
	= ((IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__stalling)
	    ? 0xdeadbeefU : vlTOPp->Vortex__DOT__decode_itype_immed);
    vlTOPp->Vortex__DOT__vx_writeback__DOT__out_pc_data[0U] 
	= vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__PC_next;
    vlTOPp->Vortex__DOT__vx_writeback__DOT__out_pc_data[1U] 
	= vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__PC_next;
    vlTOPp->Vortex__DOT__vx_forwarding__DOT__use_writeback_PC_next[0U] 
	= vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__PC_next;
    vlTOPp->Vortex__DOT__vx_forwarding__DOT__use_writeback_PC_next[1U] 
	= vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__PC_next;
    // ALWAYS at VX_e_m_reg.v:123
    vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__PC_next = vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__PC_next_out;
    // ALWAYS at VX_d_e_reg.v:133
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__jal_offset 
	= ((IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__stalling)
	    ? 0U : ((0x6fU == (0x7fU & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction))
		     ? ((0xffe00000U & (VL_NEGATE_I((IData)(
							    (1U 
							     & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
								>> 0x1fU)))) 
					<< 0x15U)) 
			| ((0x100000U & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
					 >> 0xbU)) 
			   | ((0xff000U & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction) 
			      | ((0x800U & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
					    >> 9U)) 
				 | (0x7feU & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
					      >> 0x14U))))))
		     : ((0x67U == (0x7fU & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction))
			 ? ((0xfffff000U & (VL_NEGATE_I((IData)(
								(1U 
								 & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
								    >> 0x1fU)))) 
					    << 0xcU)) 
			    | (0xfffU & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
					 >> 0x14U)))
			 : ((0x73U == (0x7fU & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction))
			     ? (((0U == (7U & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
					       >> 0xcU))) 
				 & (2U > (0xfffU & 
					  (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
					   >> 0x14U))))
				 ? 0xb0000000U : 0xdeadbeefU)
			     : 0xdeadbeefU))));
    // ALWAYS at VX_m_w_reg.v:60
    vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__rd = vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__rd;
    // ALWAYS at VX_m_w_reg.v:60
    vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__wb = vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__wb;
    // ALWAYS at VX_e_m_reg.v:123
    vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__csr_address 
	= vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__csr_address;
    // ALWAYS at VX_e_m_reg.v:123
    vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__is_csr = vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__is_csr;
    // ALWAYS at VX_e_m_reg.v:123
    vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__csr_result 
	= ((0xdU == (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
	    ? vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__csr_mask
	    : ((0xeU == (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
	        ? (vlTOPp->Vortex__DOT__csr_decode_csr_data 
		   | vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__csr_mask)
	        : ((0xfU == (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
		    ? (vlTOPp->Vortex__DOT__csr_decode_csr_data 
		       & ((IData)(0xffffffffU) - vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__csr_mask))
		    : 0xdeadbeefU)));
    vlTOPp->Vortex__DOT____Vcellout__vx_d_e_reg__out_reg_data[3U] 
	= vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__reg_data
	[3U];
    vlTOPp->Vortex__DOT____Vcellout__vx_d_e_reg__out_reg_data[2U] 
	= vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__reg_data
	[2U];
    vlTOPp->Vortex__DOT____Vcellout__vx_d_e_reg__out_reg_data[1U] 
	= vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__reg_data
	[1U];
    vlTOPp->Vortex__DOT____Vcellout__vx_d_e_reg__out_reg_data[0U] 
	= vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__reg_data
	[0U];
    vlTOPp->Vortex__DOT__m_w_valid[1U] = vlTOPp->Vortex__DOT____Vcellout__vx_m_w_reg__out_valid
	[1U];
    vlTOPp->Vortex__DOT__m_w_valid[0U] = vlTOPp->Vortex__DOT____Vcellout__vx_m_w_reg__out_valid
	[0U];
    vlTOPp->Vortex__DOT__e_m_valid[1U] = vlTOPp->Vortex__DOT____Vcellout__vx_e_m_reg__out_valid
	[1U];
    vlTOPp->Vortex__DOT__e_m_valid[0U] = vlTOPp->Vortex__DOT____Vcellout__vx_e_m_reg__out_valid
	[0U];
    vlTOPp->Vortex__DOT__e_m_reg_data[3U] = vlTOPp->Vortex__DOT____Vcellout__vx_e_m_reg__out_reg_data
	[3U];
    vlTOPp->Vortex__DOT__e_m_reg_data[2U] = vlTOPp->Vortex__DOT____Vcellout__vx_e_m_reg__out_reg_data
	[2U];
    vlTOPp->Vortex__DOT__e_m_reg_data[1U] = vlTOPp->Vortex__DOT____Vcellout__vx_e_m_reg__out_reg_data
	[1U];
    vlTOPp->Vortex__DOT__e_m_reg_data[0U] = vlTOPp->Vortex__DOT____Vcellout__vx_e_m_reg__out_reg_data
	[0U];
    vlTOPp->Vortex__DOT__m_w_alu_result[1U] = vlTOPp->Vortex__DOT____Vcellout__vx_m_w_reg__out_alu_result
	[1U];
    vlTOPp->Vortex__DOT__m_w_alu_result[0U] = vlTOPp->Vortex__DOT____Vcellout__vx_m_w_reg__out_alu_result
	[0U];
    vlTOPp->Vortex__DOT__m_w_mem_result[1U] = vlTOPp->Vortex__DOT____Vcellout__vx_m_w_reg__out_mem_result
	[1U];
    vlTOPp->Vortex__DOT__m_w_mem_result[0U] = vlTOPp->Vortex__DOT____Vcellout__vx_m_w_reg__out_mem_result
	[0U];
    vlTOPp->Vortex__DOT__e_m_alu_result[1U] = vlTOPp->Vortex__DOT____Vcellout__vx_e_m_reg__out_alu_result
	[1U];
    vlTOPp->Vortex__DOT__e_m_alu_result[0U] = vlTOPp->Vortex__DOT____Vcellout__vx_e_m_reg__out_alu_result
	[0U];
    vlTOPp->Vortex__DOT__d_e_valid[1U] = vlTOPp->Vortex__DOT____Vcellout__vx_d_e_reg__out_valid
	[1U];
    vlTOPp->Vortex__DOT__d_e_valid[0U] = vlTOPp->Vortex__DOT____Vcellout__vx_d_e_reg__out_valid
	[0U];
    vlTOPp->Vortex__DOT__csr_decode_csr_data = ((0xc00U 
						 == (IData)(vlTOPp->Vortex__DOT__vx_csr_handler__DOT__decode_csr_address))
						 ? (IData)(vlTOPp->Vortex__DOT__vx_csr_handler__DOT__cycle)
						 : 
						((0xc80U 
						  == (IData)(vlTOPp->Vortex__DOT__vx_csr_handler__DOT__decode_csr_address))
						  ? (IData)(
							    (vlTOPp->Vortex__DOT__vx_csr_handler__DOT__cycle 
							     >> 0x20U))
						  : 
						 ((0xc02U 
						   == (IData)(vlTOPp->Vortex__DOT__vx_csr_handler__DOT__decode_csr_address))
						   ? (IData)(vlTOPp->Vortex__DOT__vx_csr_handler__DOT__instret)
						   : 
						  ((0xc82U 
						    == (IData)(vlTOPp->Vortex__DOT__vx_csr_handler__DOT__decode_csr_address))
						    ? (IData)(
							      (vlTOPp->Vortex__DOT__vx_csr_handler__DOT__instret 
							       >> 0x20U))
						    : 
						   vlTOPp->Vortex__DOT__vx_csr_handler__DOT__csr
						   [vlTOPp->Vortex__DOT__vx_csr_handler__DOT__decode_csr_address]))));
    vlTOPp->Vortex__DOT__d_e_reg_data[3U] = vlTOPp->Vortex__DOT____Vcellout__vx_d_e_reg__out_reg_data
	[3U];
    vlTOPp->Vortex__DOT__d_e_reg_data[2U] = vlTOPp->Vortex__DOT____Vcellout__vx_d_e_reg__out_reg_data
	[2U];
    vlTOPp->Vortex__DOT__d_e_reg_data[1U] = vlTOPp->Vortex__DOT____Vcellout__vx_d_e_reg__out_reg_data
	[1U];
    vlTOPp->Vortex__DOT__d_e_reg_data[0U] = vlTOPp->Vortex__DOT____Vcellout__vx_d_e_reg__out_reg_data
	[0U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_decode__in_wb_valid[1U] 
	= vlTOPp->Vortex__DOT__m_w_valid[1U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_decode__in_wb_valid[0U] 
	= vlTOPp->Vortex__DOT__m_w_valid[0U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_memory__in_valid[1U] 
	= vlTOPp->Vortex__DOT__e_m_valid[1U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_memory__in_valid[0U] 
	= vlTOPp->Vortex__DOT__e_m_valid[0U];
    vlTOPp->Vortex__DOT__use_rd2[0U] = vlTOPp->Vortex__DOT__e_m_reg_data
	[1U];
    vlTOPp->Vortex__DOT__use_rd2[1U] = vlTOPp->Vortex__DOT__e_m_reg_data
	[3U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_writeback__in_alu_result[1U] 
	= vlTOPp->Vortex__DOT__m_w_alu_result[1U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_writeback__in_alu_result[0U] 
	= vlTOPp->Vortex__DOT__m_w_alu_result[0U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_forwarding__in_writeback_alu_result[1U] 
	= vlTOPp->Vortex__DOT__m_w_alu_result[1U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_forwarding__in_writeback_alu_result[0U] 
	= vlTOPp->Vortex__DOT__m_w_alu_result[0U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_writeback__in_mem_result[1U] 
	= vlTOPp->Vortex__DOT__m_w_mem_result[1U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_writeback__in_mem_result[0U] 
	= vlTOPp->Vortex__DOT__m_w_mem_result[0U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_forwarding__in_writeback_mem_data[1U] 
	= vlTOPp->Vortex__DOT__m_w_mem_result[1U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_forwarding__in_writeback_mem_data[0U] 
	= vlTOPp->Vortex__DOT__m_w_mem_result[0U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_memory__in_alu_result[1U] 
	= vlTOPp->Vortex__DOT__e_m_alu_result[1U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_memory__in_alu_result[0U] 
	= vlTOPp->Vortex__DOT__e_m_alu_result[0U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_execute__in_valid[1U] 
	= vlTOPp->Vortex__DOT__d_e_valid[1U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_execute__in_valid[0U] 
	= vlTOPp->Vortex__DOT__d_e_valid[0U];
    vlTOPp->Vortex__DOT__execute_branch_stall = ((0U 
						  != (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__branch_type)) 
						 | (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__jal));
    vlTOPp->Vortex__DOT__vx_forwarding__DOT__use_memory_PC_next[0U] 
	= vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__PC_next;
    vlTOPp->Vortex__DOT__vx_forwarding__DOT__use_memory_PC_next[1U] 
	= vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__PC_next;
    // ALWAYS at VX_d_e_reg.v:133
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__PC_next_out 
	= ((IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__stalling)
	    ? 0U : ((IData)(4U) + vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__curr_PC));
    // ALWAYS at VX_e_m_reg.v:123
    vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__rd = vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__rd;
    // ALWAYS at VX_e_m_reg.v:123
    vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__wb = vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__wb;
    // ALWAYS at VX_d_e_reg.v:133
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__csr_address 
	= ((IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__stalling)
	    ? 0U : (IData)(vlTOPp->Vortex__DOT__decode_csr_address));
    // ALWAYS at VX_d_e_reg.v:133
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__is_csr = 
	((~ (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__stalling)) 
	 & (IData)(vlTOPp->Vortex__DOT__vx_decode__DOT__is_csr));
    // ALWAYS at VX_d_e_reg.v:133
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__csr_mask 
	= ((IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__stalling)
	    ? 0U : (((IData)(vlTOPp->Vortex__DOT__vx_decode__DOT__is_csr) 
		     & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
			>> 0xeU)) ? (0x1fU & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
					      >> 0xfU))
		     : vlTOPp->Vortex__DOT____Vcellout__vx_decode__out_reg_data
		    [0U]));
    // ALWAYS at VX_d_e_reg.v:133
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op = 
	((IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__stalling)
	  ? 0xfU : (((vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
		      >> 0x19U) & (0x33U == (0x7fU 
					     & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)))
		     ? (IData)(vlTOPp->Vortex__DOT__vx_decode__DOT__mul_alu)
		     : (IData)(vlTOPp->Vortex__DOT__vx_decode__DOT__temp_final_alu)));
    vlTOPp->Vortex__DOT____Vcellinp__vx_execute__in_reg_data[3U] 
	= vlTOPp->Vortex__DOT__d_e_reg_data[3U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_execute__in_reg_data[2U] 
	= vlTOPp->Vortex__DOT__d_e_reg_data[2U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_execute__in_reg_data[1U] 
	= vlTOPp->Vortex__DOT__d_e_reg_data[1U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_execute__in_reg_data[0U] 
	= vlTOPp->Vortex__DOT__d_e_reg_data[0U];
    vlTOPp->Vortex__DOT____Vcellout__vx_memory__out_cache_driver_in_valid[1U] 
	= vlTOPp->Vortex__DOT____Vcellinp__vx_memory__in_valid
	[1U];
    vlTOPp->Vortex__DOT____Vcellout__vx_memory__out_cache_driver_in_valid[0U] 
	= vlTOPp->Vortex__DOT____Vcellinp__vx_memory__in_valid
	[0U];
    vlTOPp->Vortex__DOT____Vcellout__vx_memory__out_valid[1U] 
	= vlTOPp->Vortex__DOT____Vcellinp__vx_memory__in_valid
	[1U];
    vlTOPp->Vortex__DOT____Vcellout__vx_memory__out_valid[0U] 
	= vlTOPp->Vortex__DOT____Vcellinp__vx_memory__in_valid
	[0U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_memory__in_rd2[1U] 
	= vlTOPp->Vortex__DOT__use_rd2[1U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_memory__in_rd2[0U] 
	= vlTOPp->Vortex__DOT__use_rd2[0U];
    vlTOPp->Vortex__DOT____Vcellout__vx_writeback__out_write_data[1U] 
	= ((3U == (IData)(vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__wb))
	    ? vlTOPp->Vortex__DOT__vx_writeback__DOT__out_pc_data
	   [1U] : ((1U == (IData)(vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__wb))
		    ? vlTOPp->Vortex__DOT____Vcellinp__vx_writeback__in_alu_result
		   [1U] : vlTOPp->Vortex__DOT____Vcellinp__vx_writeback__in_mem_result
		   [1U]));
    vlTOPp->Vortex__DOT____Vcellout__vx_writeback__out_write_data[0U] 
	= ((3U == (IData)(vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__wb))
	    ? vlTOPp->Vortex__DOT__vx_writeback__DOT__out_pc_data
	   [0U] : ((1U == (IData)(vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__wb))
		    ? vlTOPp->Vortex__DOT____Vcellinp__vx_writeback__in_alu_result
		   [0U] : vlTOPp->Vortex__DOT____Vcellinp__vx_writeback__in_mem_result
		   [0U]));
    vlTOPp->Vortex__DOT____Vcellout__vx_memory__out_cache_driver_in_address[1U] 
	= vlTOPp->Vortex__DOT____Vcellinp__vx_memory__in_alu_result
	[1U];
    vlTOPp->Vortex__DOT____Vcellout__vx_memory__out_cache_driver_in_address[0U] 
	= vlTOPp->Vortex__DOT____Vcellinp__vx_memory__in_alu_result
	[0U];
    // ALWAYS at VX_memory.v:65
    vlTOPp->Vortex__DOT__memory_branch_dir = (1U & 
					      ((4U 
						& (IData)(vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__branch_type))
					        ? (
						   (2U 
						    & (IData)(vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__branch_type))
						    ? 
						   ((~ (IData)(vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__branch_type)) 
						    & (~ 
						       (vlTOPp->Vortex__DOT____Vcellinp__vx_memory__in_alu_result
							[0U] 
							>> 0x1fU)))
						    : 
						   ((1U 
						     & (IData)(vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__branch_type))
						     ? 
						    (vlTOPp->Vortex__DOT____Vcellinp__vx_memory__in_alu_result
						     [0U] 
						     >> 0x1fU)
						     : 
						    (~ 
						     (vlTOPp->Vortex__DOT____Vcellinp__vx_memory__in_alu_result
						      [0U] 
						      >> 0x1fU))))
					        : (
						   (2U 
						    & (IData)(vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__branch_type))
						    ? 
						   ((1U 
						     & (IData)(vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__branch_type))
						     ? 
						    (vlTOPp->Vortex__DOT____Vcellinp__vx_memory__in_alu_result
						     [0U] 
						     >> 0x1fU)
						     : 
						    (0U 
						     != 
						     vlTOPp->Vortex__DOT____Vcellinp__vx_memory__in_alu_result
						     [0U]))
						    : 
						   ((IData)(vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__branch_type) 
						    & (0U 
						       == 
						       vlTOPp->Vortex__DOT____Vcellinp__vx_memory__in_alu_result
						       [0U])))));
    vlTOPp->Vortex__DOT____Vcellout__vx_memory__out_alu_result[1U] 
	= vlTOPp->Vortex__DOT____Vcellinp__vx_memory__in_alu_result
	[1U];
    vlTOPp->Vortex__DOT____Vcellout__vx_memory__out_alu_result[0U] 
	= vlTOPp->Vortex__DOT____Vcellinp__vx_memory__in_alu_result
	[0U];
    vlTOPp->Vortex__DOT____Vcellout__vx_execute__out_valid[1U] 
	= vlTOPp->Vortex__DOT____Vcellinp__vx_execute__in_valid
	[1U];
    vlTOPp->Vortex__DOT____Vcellout__vx_execute__out_valid[0U] 
	= vlTOPp->Vortex__DOT____Vcellinp__vx_execute__in_valid
	[0U];
    vlTOPp->Vortex__DOT____Vcellout__vx_execute__out_reg_data[3U] 
	= vlTOPp->Vortex__DOT____Vcellinp__vx_execute__in_reg_data
	[3U];
    vlTOPp->Vortex__DOT____Vcellout__vx_execute__out_reg_data[2U] 
	= vlTOPp->Vortex__DOT____Vcellinp__vx_execute__in_reg_data
	[2U];
    vlTOPp->Vortex__DOT____Vcellout__vx_execute__out_reg_data[1U] 
	= vlTOPp->Vortex__DOT____Vcellinp__vx_execute__in_reg_data
	[1U];
    vlTOPp->Vortex__DOT____Vcellout__vx_execute__out_reg_data[0U] 
	= vlTOPp->Vortex__DOT____Vcellinp__vx_execute__in_reg_data
	[0U];
    vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__0__KET____DOT__vx_alu__in_reg_data[1U] 
	= vlTOPp->Vortex__DOT____Vcellinp__vx_execute__in_reg_data
	[1U];
    vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__0__KET____DOT__vx_alu__in_reg_data[0U] 
	= vlTOPp->Vortex__DOT____Vcellinp__vx_execute__in_reg_data
	[0U];
    vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__2__KET____DOT__vx_alu__in_reg_data[1U] 
	= vlTOPp->Vortex__DOT____Vcellinp__vx_execute__in_reg_data
	[3U];
    vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__2__KET____DOT__vx_alu__in_reg_data[0U] 
	= vlTOPp->Vortex__DOT____Vcellinp__vx_execute__in_reg_data
	[2U];
    vlTOPp->out_cache_driver_in_valid[1U] = vlTOPp->Vortex__DOT____Vcellout__vx_memory__out_cache_driver_in_valid
	[1U];
    vlTOPp->out_cache_driver_in_valid[0U] = vlTOPp->Vortex__DOT____Vcellout__vx_memory__out_cache_driver_in_valid
	[0U];
    vlTOPp->Vortex__DOT__memory_valid[1U] = vlTOPp->Vortex__DOT____Vcellout__vx_memory__out_valid
	[1U];
    vlTOPp->Vortex__DOT__memory_valid[0U] = vlTOPp->Vortex__DOT____Vcellout__vx_memory__out_valid
	[0U];
    vlTOPp->Vortex__DOT____Vcellout__vx_memory__out_cache_driver_in_data[1U] 
	= vlTOPp->Vortex__DOT____Vcellinp__vx_memory__in_rd2
	[1U];
    vlTOPp->Vortex__DOT____Vcellout__vx_memory__out_cache_driver_in_data[0U] 
	= vlTOPp->Vortex__DOT____Vcellinp__vx_memory__in_rd2
	[0U];
    vlTOPp->Vortex__DOT__writeback_write_data[1U] = 
	vlTOPp->Vortex__DOT____Vcellout__vx_writeback__out_write_data
	[1U];
    vlTOPp->Vortex__DOT__writeback_write_data[0U] = 
	vlTOPp->Vortex__DOT____Vcellout__vx_writeback__out_write_data
	[0U];
    vlTOPp->out_cache_driver_in_address[1U] = vlTOPp->Vortex__DOT____Vcellout__vx_memory__out_cache_driver_in_address
	[1U];
    vlTOPp->out_cache_driver_in_address[0U] = vlTOPp->Vortex__DOT____Vcellout__vx_memory__out_cache_driver_in_address
	[0U];
    vlTOPp->Vortex__DOT__memory_alu_result[1U] = vlTOPp->Vortex__DOT____Vcellout__vx_memory__out_alu_result
	[1U];
    vlTOPp->Vortex__DOT__memory_alu_result[0U] = vlTOPp->Vortex__DOT____Vcellout__vx_memory__out_alu_result
	[0U];
    vlTOPp->Vortex__DOT__execute_valid[1U] = vlTOPp->Vortex__DOT____Vcellout__vx_execute__out_valid
	[1U];
    vlTOPp->Vortex__DOT__execute_valid[0U] = vlTOPp->Vortex__DOT____Vcellout__vx_execute__out_valid
	[0U];
    vlTOPp->Vortex__DOT__vx_forwarding__DOT__use_execute_PC_next[0U] 
	= vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__PC_next_out;
    vlTOPp->Vortex__DOT__vx_forwarding__DOT__use_execute_PC_next[1U] 
	= vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__PC_next_out;
    // ALWAYS at VX_d_e_reg.v:133
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__rd = (0x1fU 
						& ((IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__stalling)
						    ? 0U
						    : 
						   (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
						    >> 7U)));
    // ALWAYS at VX_d_e_reg.v:133
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__wb = ((IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__stalling)
						 ? 0U
						 : 
						((((0x6fU 
						    == 
						    (0x7fU 
						     & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)) 
						   | (0x67U 
						      == 
						      (0x7fU 
						       & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction))) 
						  | ((0x73U 
						      == 
						      (0x7fU 
						       & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)) 
						     & (0U 
							== 
							(7U 
							 & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
							    >> 0xcU)))))
						  ? 3U
						  : 
						 ((3U 
						   == 
						   (0x7fU 
						    & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction))
						   ? 2U
						   : 
						  ((((((IData)(vlTOPp->Vortex__DOT__vx_decode__DOT__is_itype) 
						       | (0x33U 
							  == 
							  (0x7fU 
							   & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction))) 
						      | (0x37U 
							 == 
							 (0x7fU 
							  & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction))) 
						     | (0x17U 
							== 
							(0x7fU 
							 & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction))) 
						    | (IData)(vlTOPp->Vortex__DOT__vx_decode__DOT__is_csr))
						    ? 1U
						    : 0U))));
    vlTOPp->Vortex__DOT__execute_reg_data[3U] = vlTOPp->Vortex__DOT____Vcellout__vx_execute__out_reg_data
	[3U];
    vlTOPp->Vortex__DOT__execute_reg_data[2U] = vlTOPp->Vortex__DOT____Vcellout__vx_execute__out_reg_data
	[2U];
    vlTOPp->Vortex__DOT__execute_reg_data[1U] = vlTOPp->Vortex__DOT____Vcellout__vx_execute__out_reg_data
	[1U];
    vlTOPp->Vortex__DOT__execute_reg_data[0U] = vlTOPp->Vortex__DOT____Vcellout__vx_execute__out_reg_data
	[0U];
    vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__0__KET____DOT__vx_alu__DOT__ALU_in2 
	= ((IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__rs2_src)
	    ? vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__itype_immed
	    : vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__0__KET____DOT__vx_alu__in_reg_data
	   [1U]);
    vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__2__KET____DOT__vx_alu__DOT__ALU_in2 
	= ((IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__rs2_src)
	    ? vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__itype_immed
	    : vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__2__KET____DOT__vx_alu__in_reg_data
	   [1U]);
    vlTOPp->Vortex__DOT____Vcellinp__vx_m_w_reg__in_valid[1U] 
	= vlTOPp->Vortex__DOT__memory_valid[1U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_m_w_reg__in_valid[0U] 
	= vlTOPp->Vortex__DOT__memory_valid[0U];
    vlTOPp->out_cache_driver_in_data[1U] = vlTOPp->Vortex__DOT____Vcellout__vx_memory__out_cache_driver_in_data
	[1U];
    vlTOPp->out_cache_driver_in_data[0U] = vlTOPp->Vortex__DOT____Vcellout__vx_memory__out_cache_driver_in_data
	[0U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_decode__in_write_data[1U] 
	= vlTOPp->Vortex__DOT__writeback_write_data
	[1U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_decode__in_write_data[0U] 
	= vlTOPp->Vortex__DOT__writeback_write_data
	[0U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_m_w_reg__in_alu_result[1U] 
	= vlTOPp->Vortex__DOT__memory_alu_result[1U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_m_w_reg__in_alu_result[0U] 
	= vlTOPp->Vortex__DOT__memory_alu_result[0U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_forwarding__in_memory_alu_result[1U] 
	= vlTOPp->Vortex__DOT__memory_alu_result[1U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_forwarding__in_memory_alu_result[0U] 
	= vlTOPp->Vortex__DOT__memory_alu_result[0U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_e_m_reg__in_valid[1U] 
	= vlTOPp->Vortex__DOT__execute_valid[1U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_e_m_reg__in_valid[0U] 
	= vlTOPp->Vortex__DOT__execute_valid[0U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_e_m_reg__in_reg_data[3U] 
	= vlTOPp->Vortex__DOT__execute_reg_data[3U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_e_m_reg__in_reg_data[2U] 
	= vlTOPp->Vortex__DOT__execute_reg_data[2U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_e_m_reg__in_reg_data[1U] 
	= vlTOPp->Vortex__DOT__execute_reg_data[1U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_e_m_reg__in_reg_data[0U] 
	= vlTOPp->Vortex__DOT__execute_reg_data[0U];
    vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__0__KET____DOT__vx_alu__DOT__mult_signed_result 
	= VL_MULS_QQQ(64,64,64, VL_EXTENDS_QI(64,32, 
					      vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__0__KET____DOT__vx_alu__in_reg_data
					      [0U]), 
		      VL_EXTENDS_QI(64,32, vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__0__KET____DOT__vx_alu__DOT__ALU_in2));
    vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__2__KET____DOT__vx_alu__DOT__mult_signed_result 
	= VL_MULS_QQQ(64,64,64, VL_EXTENDS_QI(64,32, 
					      vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__2__KET____DOT__vx_alu__in_reg_data
					      [0U]), 
		      VL_EXTENDS_QI(64,32, vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__2__KET____DOT__vx_alu__DOT__ALU_in2));
    // ALWAYS at VX_alu.v:47
    vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellout__gen_code_label__BRA__0__KET____DOT__vx_alu__out_alu_result 
	= ((0x10U & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
	    ? ((8U & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
	        ? 0U : ((4U & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
			 ? ((2U & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
			     ? ((1U & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
				 ? ((0U == vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__0__KET____DOT__vx_alu__DOT__ALU_in2)
				     ? vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__0__KET____DOT__vx_alu__in_reg_data
				    [0U] : VL_MODDIV_III(32, 
							 vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__0__KET____DOT__vx_alu__in_reg_data
							 [0U], vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__0__KET____DOT__vx_alu__DOT__ALU_in2))
				 : ((0U == vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__0__KET____DOT__vx_alu__DOT__ALU_in2)
				     ? vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__0__KET____DOT__vx_alu__in_reg_data
				    [0U] : VL_MODDIVS_III(32, 
							  vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__0__KET____DOT__vx_alu__in_reg_data
							  [0U], vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__0__KET____DOT__vx_alu__DOT__ALU_in2)))
			     : ((1U & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
				 ? ((0U == vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__0__KET____DOT__vx_alu__DOT__ALU_in2)
				     ? 0xffffffffU : 
				    VL_DIV_III(32, 
					       vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__0__KET____DOT__vx_alu__in_reg_data
					       [0U], vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__0__KET____DOT__vx_alu__DOT__ALU_in2))
				 : ((0U == vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__0__KET____DOT__vx_alu__DOT__ALU_in2)
				     ? 0xffffffffU : 
				    VL_DIVS_III(32, 
						vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__0__KET____DOT__vx_alu__in_reg_data
						[0U], vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__0__KET____DOT__vx_alu__DOT__ALU_in2))))
			 : ((2U & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
			     ? ((1U & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
				 ? (IData)((((QData)((IData)(
							     vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__0__KET____DOT__vx_alu__in_reg_data
							     [0U])) 
					     * (QData)((IData)(vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__0__KET____DOT__vx_alu__DOT__ALU_in2))) 
					    >> 0x20U))
				 : (IData)((((((QData)((IData)(
							       VL_NEGATE_I((IData)(
										(1U 
										& (vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__0__KET____DOT__vx_alu__in_reg_data
										[0U] 
										>> 0x1fU)))))) 
					       << 0x20U) 
					      | (QData)((IData)(
								vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__0__KET____DOT__vx_alu__in_reg_data
								[0U]))) 
					     * (QData)((IData)(vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__0__KET____DOT__vx_alu__DOT__ALU_in2))) 
					    >> 0x20U)))
			     : ((1U & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
				 ? (IData)((vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__0__KET____DOT__vx_alu__DOT__mult_signed_result 
					    >> 0x20U))
				 : (IData)(vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__0__KET____DOT__vx_alu__DOT__mult_signed_result)))))
	    : ((8U & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
	        ? ((4U & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
		    ? ((2U & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
		        ? vlTOPp->Vortex__DOT__csr_decode_csr_data
		        : ((1U & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
			    ? vlTOPp->Vortex__DOT__csr_decode_csr_data
			    : (vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__curr_PC 
			       + (vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__upper_immed 
				  << 0xcU)))) : ((2U 
						  & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
						  ? 
						 ((1U 
						   & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
						   ? 
						  (vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__upper_immed 
						   << 0xcU)
						   : 
						  ((vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__0__KET____DOT__vx_alu__in_reg_data
						    [0U] 
						    >= vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__0__KET____DOT__vx_alu__DOT__ALU_in2)
						    ? 0U
						    : 0xffffffffU))
						  : 
						 ((1U 
						   & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
						   ? 
						  (vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__0__KET____DOT__vx_alu__DOT__ALU_in2 
						   & vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__0__KET____DOT__vx_alu__in_reg_data
						   [0U])
						   : 
						  (vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__0__KET____DOT__vx_alu__in_reg_data
						   [0U] 
						   | vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__0__KET____DOT__vx_alu__DOT__ALU_in2))))
	        : ((4U & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
		    ? ((2U & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
		        ? ((1U & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
			    ? VL_SHIFTRS_III(32,32,5, 
					     vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__0__KET____DOT__vx_alu__in_reg_data
					     [0U], 
					     (0x1fU 
					      & vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__0__KET____DOT__vx_alu__DOT__ALU_in2))
			    : (vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__0__KET____DOT__vx_alu__in_reg_data
			       [0U] >> (0x1fU & vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__0__KET____DOT__vx_alu__DOT__ALU_in2)))
		        : ((1U & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
			    ? (vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__0__KET____DOT__vx_alu__in_reg_data
			       [0U] ^ vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__0__KET____DOT__vx_alu__DOT__ALU_in2)
			    : ((vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__0__KET____DOT__vx_alu__in_reg_data
				[0U] < vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__0__KET____DOT__vx_alu__DOT__ALU_in2)
			        ? 1U : 0U))) : ((2U 
						 & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
						 ? 
						((1U 
						  & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
						  ? 
						 (VL_LTS_III(1,32,32, 
							     vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__0__KET____DOT__vx_alu__in_reg_data
							     [0U], vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__0__KET____DOT__vx_alu__DOT__ALU_in2)
						   ? 1U
						   : 0U)
						  : 
						 (vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__0__KET____DOT__vx_alu__in_reg_data
						  [0U] 
						  << 
						  (0x1fU 
						   & vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__0__KET____DOT__vx_alu__DOT__ALU_in2)))
						 : 
						((1U 
						  & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
						  ? 
						 (vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__0__KET____DOT__vx_alu__in_reg_data
						  [0U] 
						  - vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__0__KET____DOT__vx_alu__DOT__ALU_in2)
						  : 
						 (vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__0__KET____DOT__vx_alu__in_reg_data
						  [0U] 
						  + vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__0__KET____DOT__vx_alu__DOT__ALU_in2))))));
    // ALWAYS at VX_alu.v:47
    vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellout__gen_code_label__BRA__2__KET____DOT__vx_alu__out_alu_result 
	= ((0x10U & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
	    ? ((8U & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
	        ? 0U : ((4U & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
			 ? ((2U & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
			     ? ((1U & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
				 ? ((0U == vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__2__KET____DOT__vx_alu__DOT__ALU_in2)
				     ? vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__2__KET____DOT__vx_alu__in_reg_data
				    [0U] : VL_MODDIV_III(32, 
							 vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__2__KET____DOT__vx_alu__in_reg_data
							 [0U], vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__2__KET____DOT__vx_alu__DOT__ALU_in2))
				 : ((0U == vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__2__KET____DOT__vx_alu__DOT__ALU_in2)
				     ? vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__2__KET____DOT__vx_alu__in_reg_data
				    [0U] : VL_MODDIVS_III(32, 
							  vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__2__KET____DOT__vx_alu__in_reg_data
							  [0U], vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__2__KET____DOT__vx_alu__DOT__ALU_in2)))
			     : ((1U & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
				 ? ((0U == vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__2__KET____DOT__vx_alu__DOT__ALU_in2)
				     ? 0xffffffffU : 
				    VL_DIV_III(32, 
					       vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__2__KET____DOT__vx_alu__in_reg_data
					       [0U], vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__2__KET____DOT__vx_alu__DOT__ALU_in2))
				 : ((0U == vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__2__KET____DOT__vx_alu__DOT__ALU_in2)
				     ? 0xffffffffU : 
				    VL_DIVS_III(32, 
						vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__2__KET____DOT__vx_alu__in_reg_data
						[0U], vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__2__KET____DOT__vx_alu__DOT__ALU_in2))))
			 : ((2U & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
			     ? ((1U & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
				 ? (IData)((((QData)((IData)(
							     vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__2__KET____DOT__vx_alu__in_reg_data
							     [0U])) 
					     * (QData)((IData)(vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__2__KET____DOT__vx_alu__DOT__ALU_in2))) 
					    >> 0x20U))
				 : (IData)((((((QData)((IData)(
							       VL_NEGATE_I((IData)(
										(1U 
										& (vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__2__KET____DOT__vx_alu__in_reg_data
										[0U] 
										>> 0x1fU)))))) 
					       << 0x20U) 
					      | (QData)((IData)(
								vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__2__KET____DOT__vx_alu__in_reg_data
								[0U]))) 
					     * (QData)((IData)(vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__2__KET____DOT__vx_alu__DOT__ALU_in2))) 
					    >> 0x20U)))
			     : ((1U & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
				 ? (IData)((vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__2__KET____DOT__vx_alu__DOT__mult_signed_result 
					    >> 0x20U))
				 : (IData)(vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__2__KET____DOT__vx_alu__DOT__mult_signed_result)))))
	    : ((8U & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
	        ? ((4U & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
		    ? ((2U & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
		        ? vlTOPp->Vortex__DOT__csr_decode_csr_data
		        : ((1U & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
			    ? vlTOPp->Vortex__DOT__csr_decode_csr_data
			    : (vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__curr_PC 
			       + (vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__upper_immed 
				  << 0xcU)))) : ((2U 
						  & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
						  ? 
						 ((1U 
						   & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
						   ? 
						  (vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__upper_immed 
						   << 0xcU)
						   : 
						  ((vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__2__KET____DOT__vx_alu__in_reg_data
						    [0U] 
						    >= vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__2__KET____DOT__vx_alu__DOT__ALU_in2)
						    ? 0U
						    : 0xffffffffU))
						  : 
						 ((1U 
						   & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
						   ? 
						  (vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__2__KET____DOT__vx_alu__DOT__ALU_in2 
						   & vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__2__KET____DOT__vx_alu__in_reg_data
						   [0U])
						   : 
						  (vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__2__KET____DOT__vx_alu__in_reg_data
						   [0U] 
						   | vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__2__KET____DOT__vx_alu__DOT__ALU_in2))))
	        : ((4U & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
		    ? ((2U & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
		        ? ((1U & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
			    ? VL_SHIFTRS_III(32,32,5, 
					     vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__2__KET____DOT__vx_alu__in_reg_data
					     [0U], 
					     (0x1fU 
					      & vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__2__KET____DOT__vx_alu__DOT__ALU_in2))
			    : (vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__2__KET____DOT__vx_alu__in_reg_data
			       [0U] >> (0x1fU & vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__2__KET____DOT__vx_alu__DOT__ALU_in2)))
		        : ((1U & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
			    ? (vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__2__KET____DOT__vx_alu__in_reg_data
			       [0U] ^ vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__2__KET____DOT__vx_alu__DOT__ALU_in2)
			    : ((vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__2__KET____DOT__vx_alu__in_reg_data
				[0U] < vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__2__KET____DOT__vx_alu__DOT__ALU_in2)
			        ? 1U : 0U))) : ((2U 
						 & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
						 ? 
						((1U 
						  & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
						  ? 
						 (VL_LTS_III(1,32,32, 
							     vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__2__KET____DOT__vx_alu__in_reg_data
							     [0U], vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__2__KET____DOT__vx_alu__DOT__ALU_in2)
						   ? 1U
						   : 0U)
						  : 
						 (vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__2__KET____DOT__vx_alu__in_reg_data
						  [0U] 
						  << 
						  (0x1fU 
						   & vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__2__KET____DOT__vx_alu__DOT__ALU_in2)))
						 : 
						((1U 
						  & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
						  ? 
						 (vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__2__KET____DOT__vx_alu__in_reg_data
						  [0U] 
						  - vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__2__KET____DOT__vx_alu__DOT__ALU_in2)
						  : 
						 (vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__2__KET____DOT__vx_alu__in_reg_data
						  [0U] 
						  + vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__2__KET____DOT__vx_alu__DOT__ALU_in2))))));
    vlTOPp->Vortex__DOT____Vcellout__vx_execute__out_alu_result[0U] 
	= vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellout__gen_code_label__BRA__0__KET____DOT__vx_alu__out_alu_result;
    vlTOPp->Vortex__DOT____Vcellout__vx_execute__out_alu_result[0U] 
	= vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellout__gen_code_label__BRA__2__KET____DOT__vx_alu__out_alu_result;
    vlTOPp->Vortex__DOT__execute_alu_result[1U] = vlTOPp->Vortex__DOT____Vcellout__vx_execute__out_alu_result
	[1U];
    vlTOPp->Vortex__DOT__execute_alu_result[0U] = vlTOPp->Vortex__DOT____Vcellout__vx_execute__out_alu_result
	[0U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_e_m_reg__in_alu_result[1U] 
	= vlTOPp->Vortex__DOT__execute_alu_result[1U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_e_m_reg__in_alu_result[0U] 
	= vlTOPp->Vortex__DOT__execute_alu_result[0U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_forwarding__in_execute_alu_result[1U] 
	= vlTOPp->Vortex__DOT__execute_alu_result[1U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_forwarding__in_execute_alu_result[0U] 
	= vlTOPp->Vortex__DOT__execute_alu_result[0U];
}

VL_INLINE_OPT void VVortex::_combo__TOP__3(VVortex__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VVortex::_combo__TOP__3\n"); );
    VVortex* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->Vortex__DOT____Vcellinp__vx_memory__in_cache_driver_out_data[1U] 
	= vlTOPp->in_cache_driver_out_data[1U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_memory__in_cache_driver_out_data[0U] 
	= vlTOPp->in_cache_driver_out_data[0U];
    vlTOPp->Vortex__DOT____Vcellout__vx_memory__out_mem_result[1U] 
	= vlTOPp->Vortex__DOT____Vcellinp__vx_memory__in_cache_driver_out_data
	[1U];
    vlTOPp->Vortex__DOT____Vcellout__vx_memory__out_mem_result[0U] 
	= vlTOPp->Vortex__DOT____Vcellinp__vx_memory__in_cache_driver_out_data
	[0U];
    vlTOPp->Vortex__DOT__memory_mem_result[1U] = vlTOPp->Vortex__DOT____Vcellout__vx_memory__out_mem_result
	[1U];
    vlTOPp->Vortex__DOT__memory_mem_result[0U] = vlTOPp->Vortex__DOT____Vcellout__vx_memory__out_mem_result
	[0U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_m_w_reg__in_mem_result[1U] 
	= vlTOPp->Vortex__DOT__memory_mem_result[1U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_m_w_reg__in_mem_result[0U] 
	= vlTOPp->Vortex__DOT__memory_mem_result[0U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_forwarding__in_memory_mem_data[1U] 
	= vlTOPp->Vortex__DOT__memory_mem_result[1U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_forwarding__in_memory_mem_data[0U] 
	= vlTOPp->Vortex__DOT__memory_mem_result[0U];
}

void VVortex::_settle__TOP__4(VVortex__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VVortex::_settle__TOP__4\n"); );
    VVortex* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->Vortex__DOT____Vcellinp__vx_memory__in_cache_driver_out_data[1U] 
	= vlTOPp->in_cache_driver_out_data[1U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_memory__in_cache_driver_out_data[0U] 
	= vlTOPp->in_cache_driver_out_data[0U];
    vlTOPp->Vortex__DOT____Vcellout__vx_m_w_reg__out_valid[1U] 
	= vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__valid
	[1U];
    vlTOPp->Vortex__DOT____Vcellout__vx_m_w_reg__out_valid[0U] 
	= vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__valid
	[0U];
    vlTOPp->Vortex__DOT__vx_decode__DOT__rd2_register[0U] 
	= vlTOPp->Vortex__DOT__vx_decode__DOT____Vcellout__gen_code_label__BRA__0__KET____DOT__vx_register_file__out_src2_data;
    vlTOPp->Vortex__DOT__vx_decode__DOT__rd2_register[1U] 
	= vlTOPp->Vortex__DOT__vx_decode__DOT____Vcellout__gen_code_label__BRA__1__KET____DOT__vx_register_file__out_src2_data;
    vlTOPp->Vortex__DOT__vx_decode__DOT__rd1_register[0U] 
	= vlTOPp->Vortex__DOT__vx_decode__DOT____Vcellout__gen_code_label__BRA__0__KET____DOT__vx_register_file__out_src1_data;
    vlTOPp->Vortex__DOT__vx_decode__DOT__rd1_register[1U] 
	= vlTOPp->Vortex__DOT__vx_decode__DOT____Vcellout__gen_code_label__BRA__1__KET____DOT__vx_register_file__out_src1_data;
    vlTOPp->Vortex__DOT____Vcellout__vx_f_d_reg__out_valid[1U] 
	= vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__valid
	[1U];
    vlTOPp->Vortex__DOT____Vcellout__vx_f_d_reg__out_valid[0U] 
	= vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__valid
	[0U];
    vlTOPp->Vortex__DOT____Vcellout__vx_m_w_reg__out_alu_result[1U] 
	= vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__alu_result
	[1U];
    vlTOPp->Vortex__DOT____Vcellout__vx_m_w_reg__out_alu_result[0U] 
	= vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__alu_result
	[0U];
    vlTOPp->Vortex__DOT____Vcellout__vx_m_w_reg__out_mem_result[1U] 
	= vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__mem_result
	[1U];
    vlTOPp->Vortex__DOT____Vcellout__vx_m_w_reg__out_mem_result[0U] 
	= vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__mem_result
	[0U];
    vlTOPp->Vortex__DOT__vx_decode__DOT__is_itype = 
	((0x13U == (0x7fU & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)) 
	 | (3U == (0x7fU & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)));
    vlTOPp->Vortex__DOT__decode_csr_address = (0xfffU 
					       & (((0U 
						    != 
						    (7U 
						     & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
							>> 0xcU))) 
						   & (2U 
						      <= 
						      (0xfffU 
						       & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
							  >> 0x14U))))
						   ? 
						  (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
						   >> 0x14U)
						   : 0x55U));
    // ALWAYS at VX_decode.v:357
    vlTOPp->__Vtableidx1 = (7U & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
				  >> 0xcU));
    vlTOPp->Vortex__DOT__vx_decode__DOT__mul_alu = 
	vlTOPp->__Vtable1_Vortex__DOT__vx_decode__DOT__mul_alu
	[vlTOPp->__Vtableidx1];
    vlTOPp->Vortex__DOT__vx_decode__DOT__alu_tempp 
	= (0xfffU & (((1U == (7U & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
				    >> 0xcU))) | (5U 
						  == 
						  (7U 
						   & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
						      >> 0xcU))))
		      ? (0x1fU & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
				  >> 0x14U)) : (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
						>> 0x14U)));
    vlTOPp->Vortex__DOT__vx_decode__DOT__is_csr = (
						   (0x73U 
						    == 
						    (0x7fU 
						     & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)) 
						   & (0U 
						      != 
						      (7U 
						       & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
							  >> 0xcU))));
    // ALWAYS at VX_decode.v:307
    vlTOPp->Vortex__DOT__decode_branch_type = ((0x63U 
						== 
						(0x7fU 
						 & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction))
					        ? (
						   (0x4000U 
						    & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						    ? 
						   ((0x2000U 
						     & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						     ? 
						    ((0x1000U 
						      & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						      ? 6U
						      : 5U)
						     : 
						    ((0x1000U 
						      & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						      ? 4U
						      : 3U))
						    : 
						   ((0x2000U 
						     & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						     ? 0U
						     : 
						    ((0x1000U 
						      & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						      ? 2U
						      : 1U)))
					        : 0U);
    vlTOPp->Vortex__DOT____Vcellout__vx_memory__out_mem_result[1U] 
	= vlTOPp->Vortex__DOT____Vcellinp__vx_memory__in_cache_driver_out_data
	[1U];
    vlTOPp->Vortex__DOT____Vcellout__vx_memory__out_mem_result[0U] 
	= vlTOPp->Vortex__DOT____Vcellinp__vx_memory__in_cache_driver_out_data
	[0U];
    vlTOPp->Vortex__DOT__m_w_valid[1U] = vlTOPp->Vortex__DOT____Vcellout__vx_m_w_reg__out_valid
	[1U];
    vlTOPp->Vortex__DOT__m_w_valid[0U] = vlTOPp->Vortex__DOT____Vcellout__vx_m_w_reg__out_valid
	[0U];
    vlTOPp->Vortex__DOT__f_d_valid[1U] = vlTOPp->Vortex__DOT____Vcellout__vx_f_d_reg__out_valid
	[1U];
    vlTOPp->Vortex__DOT__f_d_valid[0U] = vlTOPp->Vortex__DOT____Vcellout__vx_f_d_reg__out_valid
	[0U];
    vlTOPp->Vortex__DOT__m_w_alu_result[1U] = vlTOPp->Vortex__DOT____Vcellout__vx_m_w_reg__out_alu_result
	[1U];
    vlTOPp->Vortex__DOT__m_w_alu_result[0U] = vlTOPp->Vortex__DOT____Vcellout__vx_m_w_reg__out_alu_result
	[0U];
    vlTOPp->Vortex__DOT__m_w_mem_result[1U] = vlTOPp->Vortex__DOT____Vcellout__vx_m_w_reg__out_mem_result
	[1U];
    vlTOPp->Vortex__DOT__m_w_mem_result[0U] = vlTOPp->Vortex__DOT____Vcellout__vx_m_w_reg__out_mem_result
	[0U];
    // ALWAYS at VX_decode.v:296
    vlTOPp->Vortex__DOT__decode_itype_immed = ((0x40U 
						& vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
					        ? (
						   (0x20U 
						    & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						    ? 
						   ((0x10U 
						     & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						     ? 0xdeadbeefU
						     : 
						    ((8U 
						      & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						      ? 0xdeadbeefU
						      : 
						     ((4U 
						       & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						       ? 0xdeadbeefU
						       : 
						      ((2U 
							& vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						        ? 
						       ((1U 
							 & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
							 ? 
							((0xfffff000U 
							  & (VL_NEGATE_I((IData)(
										(1U 
										& (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
										>> 0x1fU)))) 
							     << 0xcU)) 
							 | ((0x800U 
							     & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
								>> 0x14U)) 
							    | ((0x400U 
								& (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
								   << 3U)) 
							       | ((0x3f0U 
								   & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
								      >> 0x15U)) 
								  | (0xfU 
								     & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
									>> 8U))))))
							 : 0xdeadbeefU)
						        : 0xdeadbeefU))))
						    : 0xdeadbeefU)
					        : (
						   (0x20U 
						    & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						    ? 
						   ((0x10U 
						     & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						     ? 0xdeadbeefU
						     : 
						    ((8U 
						      & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						      ? 0xdeadbeefU
						      : 
						     ((4U 
						       & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						       ? 0xdeadbeefU
						       : 
						      ((2U 
							& vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						        ? 
						       ((1U 
							 & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
							 ? 
							((0xfffff000U 
							  & (VL_NEGATE_I((IData)(
										(1U 
										& (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
										>> 0x1fU)))) 
							     << 0xcU)) 
							 | ((0xfe0U 
							     & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
								>> 0x14U)) 
							    | (0x1fU 
							       & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
								  >> 7U))))
							 : 0xdeadbeefU)
						        : 0xdeadbeefU))))
						    : 
						   ((0x10U 
						     & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						     ? 
						    ((8U 
						      & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						      ? 0xdeadbeefU
						      : 
						     ((4U 
						       & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						       ? 0xdeadbeefU
						       : 
						      ((2U 
							& vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						        ? 
						       ((1U 
							 & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
							 ? 
							((0xfffff000U 
							  & (VL_NEGATE_I((IData)(
										(1U 
										& ((IData)(vlTOPp->Vortex__DOT__vx_decode__DOT__alu_tempp) 
										>> 0xbU)))) 
							     << 0xcU)) 
							 | (IData)(vlTOPp->Vortex__DOT__vx_decode__DOT__alu_tempp))
							 : 0xdeadbeefU)
						        : 0xdeadbeefU)))
						     : 
						    ((8U 
						      & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						      ? 0xdeadbeefU
						      : 
						     ((4U 
						       & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						       ? 0xdeadbeefU
						       : 
						      ((2U 
							& vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						        ? 
						       ((1U 
							 & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
							 ? 
							((0xfffff000U 
							  & (VL_NEGATE_I((IData)(
										(1U 
										& (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
										>> 0x1fU)))) 
							     << 0xcU)) 
							 | (0xfffU 
							    & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
							       >> 0x14U)))
							 : 0xdeadbeefU)
						        : 0xdeadbeefU))))));
    vlTOPp->Vortex__DOT__vx_decode__DOT__temp_final_alu 
	= ((0x63U == (0x7fU & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction))
	    ? ((5U > (IData)(vlTOPp->Vortex__DOT__decode_branch_type))
	        ? 1U : 0xaU) : ((0x37U == (0x7fU & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction))
				 ? 0xbU : ((0x17U == 
					    (0x7fU 
					     & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction))
					    ? 0xcU : 
					   ((IData)(vlTOPp->Vortex__DOT__vx_decode__DOT__is_csr)
					     ? ((1U 
						 == 
						 (3U 
						  & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
						     >> 0xcU)))
						 ? 0xdU
						 : 
						((2U 
						  == 
						  (3U 
						   & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
						      >> 0xcU)))
						  ? 0xeU
						  : 0xfU))
					     : (((0x23U 
						  == 
						  (0x7fU 
						   & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)) 
						 | (3U 
						    == 
						    (0x7fU 
						     & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)))
						 ? 0U
						 : 
						((0x4000U 
						  & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						  ? 
						 ((0x2000U 
						   & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						   ? 
						  ((0x1000U 
						    & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						    ? 9U
						    : 8U)
						   : 
						  ((0x1000U 
						    & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						    ? 
						   ((0U 
						     == 
						     (0x7fU 
						      & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
							 >> 0x19U)))
						     ? 6U
						     : 7U)
						    : 5U))
						  : 
						 ((0x2000U 
						   & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						   ? 
						  ((0x1000U 
						    & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						    ? 4U
						    : 3U)
						   : 
						  ((0x1000U 
						    & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						    ? 2U
						    : 
						   ((0x13U 
						     == 
						     (0x7fU 
						      & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction))
						     ? 0U
						     : 
						    ((0U 
						      == 
						      (0x7fU 
						       & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
							  >> 0x19U)))
						      ? 0U
						      : 1U))))))))));
    vlTOPp->Vortex__DOT__memory_mem_result[1U] = vlTOPp->Vortex__DOT____Vcellout__vx_memory__out_mem_result
	[1U];
    vlTOPp->Vortex__DOT__memory_mem_result[0U] = vlTOPp->Vortex__DOT____Vcellout__vx_memory__out_mem_result
	[0U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_decode__in_wb_valid[1U] 
	= vlTOPp->Vortex__DOT__m_w_valid[1U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_decode__in_wb_valid[0U] 
	= vlTOPp->Vortex__DOT__m_w_valid[0U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_decode__in_valid[1U] 
	= vlTOPp->Vortex__DOT__f_d_valid[1U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_decode__in_valid[0U] 
	= vlTOPp->Vortex__DOT__f_d_valid[0U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_writeback__in_alu_result[1U] 
	= vlTOPp->Vortex__DOT__m_w_alu_result[1U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_writeback__in_alu_result[0U] 
	= vlTOPp->Vortex__DOT__m_w_alu_result[0U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_forwarding__in_writeback_alu_result[1U] 
	= vlTOPp->Vortex__DOT__m_w_alu_result[1U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_forwarding__in_writeback_alu_result[0U] 
	= vlTOPp->Vortex__DOT__m_w_alu_result[0U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_writeback__in_mem_result[1U] 
	= vlTOPp->Vortex__DOT__m_w_mem_result[1U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_writeback__in_mem_result[0U] 
	= vlTOPp->Vortex__DOT__m_w_mem_result[0U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_forwarding__in_writeback_mem_data[1U] 
	= vlTOPp->Vortex__DOT__m_w_mem_result[1U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_forwarding__in_writeback_mem_data[0U] 
	= vlTOPp->Vortex__DOT__m_w_mem_result[0U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_m_w_reg__in_mem_result[1U] 
	= vlTOPp->Vortex__DOT__memory_mem_result[1U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_m_w_reg__in_mem_result[0U] 
	= vlTOPp->Vortex__DOT__memory_mem_result[0U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_forwarding__in_memory_mem_data[1U] 
	= vlTOPp->Vortex__DOT__memory_mem_result[1U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_forwarding__in_memory_mem_data[0U] 
	= vlTOPp->Vortex__DOT__memory_mem_result[0U];
    vlTOPp->Vortex__DOT____Vcellout__vx_decode__out_valid[1U] 
	= vlTOPp->Vortex__DOT____Vcellinp__vx_decode__in_valid
	[1U];
    vlTOPp->Vortex__DOT____Vcellout__vx_decode__out_valid[0U] 
	= vlTOPp->Vortex__DOT____Vcellinp__vx_decode__in_valid
	[0U];
    vlTOPp->Vortex__DOT__decode_valid[1U] = vlTOPp->Vortex__DOT____Vcellout__vx_decode__out_valid
	[1U];
    vlTOPp->Vortex__DOT__decode_valid[0U] = vlTOPp->Vortex__DOT____Vcellout__vx_decode__out_valid
	[0U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_d_e_reg__in_valid[1U] 
	= vlTOPp->Vortex__DOT__decode_valid[1U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_d_e_reg__in_valid[0U] 
	= vlTOPp->Vortex__DOT__decode_valid[0U];
}

VL_INLINE_OPT void VVortex::_sequent__TOP__5(VVortex__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VVortex::_sequent__TOP__5\n"); );
    VVortex* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at VX_register_file.v:43
    vlTOPp->Vortex__DOT__vx_decode__DOT____Vcellout__gen_code_label__BRA__1__KET____DOT__vx_register_file__out_src2_data 
	= vlTOPp->Vortex__DOT__vx_decode__DOT__gen_code_label__BRA__1__KET____DOT__vx_register_file__DOT__registers
	[(0x1fU & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
		   >> 0x14U))];
    // ALWAYS at VX_register_file.v:43
    vlTOPp->Vortex__DOT__vx_decode__DOT____Vcellout__gen_code_label__BRA__0__KET____DOT__vx_register_file__out_src2_data 
	= vlTOPp->Vortex__DOT__vx_decode__DOT__gen_code_label__BRA__0__KET____DOT__vx_register_file__DOT__registers
	[(0x1fU & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
		   >> 0x14U))];
    // ALWAYS at VX_register_file.v:43
    vlTOPp->Vortex__DOT__vx_decode__DOT____Vcellout__gen_code_label__BRA__1__KET____DOT__vx_register_file__out_src1_data 
	= vlTOPp->Vortex__DOT__vx_decode__DOT__gen_code_label__BRA__1__KET____DOT__vx_register_file__DOT__registers
	[(0x1fU & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
		   >> 0xfU))];
    // ALWAYS at VX_register_file.v:43
    vlTOPp->Vortex__DOT__vx_decode__DOT____Vcellout__gen_code_label__BRA__0__KET____DOT__vx_register_file__out_src1_data 
	= vlTOPp->Vortex__DOT__vx_decode__DOT__gen_code_label__BRA__0__KET____DOT__vx_register_file__DOT__registers
	[(0x1fU & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
		   >> 0xfU))];
    vlTOPp->Vortex__DOT__vx_decode__DOT__rd2_register[1U] 
	= vlTOPp->Vortex__DOT__vx_decode__DOT____Vcellout__gen_code_label__BRA__1__KET____DOT__vx_register_file__out_src2_data;
    vlTOPp->Vortex__DOT__vx_decode__DOT__rd2_register[0U] 
	= vlTOPp->Vortex__DOT__vx_decode__DOT____Vcellout__gen_code_label__BRA__0__KET____DOT__vx_register_file__out_src2_data;
    vlTOPp->Vortex__DOT__vx_decode__DOT__rd1_register[1U] 
	= vlTOPp->Vortex__DOT__vx_decode__DOT____Vcellout__gen_code_label__BRA__1__KET____DOT__vx_register_file__out_src1_data;
    vlTOPp->Vortex__DOT__vx_decode__DOT__rd1_register[0U] 
	= vlTOPp->Vortex__DOT__vx_decode__DOT____Vcellout__gen_code_label__BRA__0__KET____DOT__vx_register_file__out_src1_data;
}

void VVortex::_initial__TOP__6(VVortex__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VVortex::_initial__TOP__6\n"); );
    VVortex* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // INITIAL at VX_fetch.v:51
    vlTOPp->Vortex__DOT__vx_fetch__DOT__valid = (1U 
						 | (IData)(vlTOPp->Vortex__DOT__vx_fetch__DOT__valid));
    vlTOPp->Vortex__DOT__vx_fetch__DOT__valid = (1U 
						 & (IData)(vlTOPp->Vortex__DOT__vx_fetch__DOT__valid));
    vlTOPp->Vortex__DOT__vx_fetch__DOT__stall_reg = 0U;
    vlTOPp->Vortex__DOT__vx_fetch__DOT__delay_reg = 0U;
    vlTOPp->Vortex__DOT__vx_fetch__DOT__old = 0U;
    vlTOPp->Vortex__DOT__vx_fetch__DOT__state = 0U;
    vlTOPp->Vortex__DOT__vx_fetch__DOT__real_PC = 0U;
    vlTOPp->Vortex__DOT__vx_fetch__DOT__JAL_reg = 0U;
    vlTOPp->Vortex__DOT__vx_fetch__DOT__BR_reg = 0U;
    vlTOPp->Vortex__DOT__vx_fetch__DOT__prev_debug = 0U;
    // INITIAL at VX_m_w_reg.v:39
    vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__rd = 0U;
    vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__wb = 0U;
    vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__PC_next = 0U;
    // INITIAL at VX_csr_handler.v:27
    vlTOPp->Vortex__DOT__vx_csr_handler__DOT__cycle = VL_ULL(0);
    vlTOPp->Vortex__DOT__vx_csr_handler__DOT__instret = VL_ULL(0);
    vlTOPp->Vortex__DOT__vx_csr_handler__DOT__decode_csr_address = 0U;
    // INITIAL at VX_e_m_reg.v:74
    vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__rd = 0U;
    vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__wb = 0U;
    vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__PC_next = 0U;
    vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__mem_read = 7U;
    vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__mem_write = 7U;
    vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__csr_address = 0U;
    vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__is_csr = 0U;
    vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__csr_result = 0U;
    vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__curr_PC = 0U;
    vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__branch_offset = 0U;
    vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__branch_type = 0U;
    vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__jal = 0U;
    vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__jal_dest = 0U;
    vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__reg_data[0U] = 0U;
    vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__valid[0U] = 0U;
    vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__alu_result[0U] = 0U;
    vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__reg_data[1U] = 0U;
    vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__valid[1U] = 0U;
    vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__alu_result[1U] = 0U;
    // INITIAL at VX_d_e_reg.v:79
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__rd = 0U;
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__reg_data[0U] = 0U;
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__reg_data_z[0U] = 0U;
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__valid[0U] = 0U;
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__valid_z[0U] = 0U;
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__reg_data[1U] = 0U;
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__reg_data_z[1U] = 0U;
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__valid[1U] = 0U;
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__valid_z[1U] = 0U;
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op = 0U;
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__wb = 0U;
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__PC_next_out = 0U;
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__rs2_src = 0U;
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__itype_immed = 0U;
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__mem_read = 7U;
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__mem_write = 7U;
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__branch_type = 0U;
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__upper_immed = 0U;
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__csr_address = 0U;
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__is_csr = 0U;
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__csr_mask = 0U;
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__curr_PC = 0U;
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__jal = 0U;
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__jal_offset = 0U;
}

VL_INLINE_OPT void VVortex::_sequent__TOP__7(VVortex__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VVortex::_sequent__TOP__7\n"); );
    VVortex* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->Vortex__DOT____Vcellinp__vx_d_e_reg__in_valid[1U] 
	= vlTOPp->Vortex__DOT__decode_valid[1U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_d_e_reg__in_valid[0U] 
	= vlTOPp->Vortex__DOT__decode_valid[0U];
    // ALWAYS at VX_f_d_reg.v:29
    if (vlTOPp->reset) {
	vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__curr_PC = 0U;
    } else {
	if ((1U & (~ (IData)(vlTOPp->Vortex__DOT__forwarding_fwd_stall)))) {
	    vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__curr_PC 
		= vlTOPp->Vortex__DOT__vx_fetch__DOT__temp_PC;
	}
    }
    // ALWAYS at VX_f_d_reg.v:29
    if (vlTOPp->reset) {
	vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction = 0U;
    } else {
	if ((1U & (~ (IData)(vlTOPp->Vortex__DOT__forwarding_fwd_stall)))) {
	    vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
		= ((IData)(vlTOPp->Vortex__DOT__vx_fetch__DOT__stall)
		    ? 0U : vlTOPp->fe_instruction);
	}
    }
    // ALWAYS at VX_fetch.v:110
    vlTOPp->Vortex__DOT__vx_fetch__DOT__temp_PC = (
						   ((IData)(vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__jal) 
						    & (~ (IData)(vlTOPp->Vortex__DOT__vx_fetch__DOT__delay_reg)))
						    ? vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__jal_dest
						    : 
						   (((IData)(vlTOPp->Vortex__DOT__memory_branch_dir) 
						     & (~ (IData)(vlTOPp->Vortex__DOT__vx_fetch__DOT__delay_reg)))
						     ? vlTOPp->Vortex__DOT__memory_branch_dest
						     : vlTOPp->Vortex__DOT__vx_fetch__DOT__PC_to_use));
    vlTOPp->curr_PC = vlTOPp->Vortex__DOT__vx_fetch__DOT__temp_PC;
    vlTOPp->Vortex__DOT__vx_decode__DOT__is_itype = 
	((0x13U == (0x7fU & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)) 
	 | (3U == (0x7fU & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)));
    vlTOPp->Vortex__DOT__decode_csr_address = (0xfffU 
					       & (((0U 
						    != 
						    (7U 
						     & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
							>> 0xcU))) 
						   & (2U 
						      <= 
						      (0xfffU 
						       & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
							  >> 0x14U))))
						   ? 
						  (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
						   >> 0x14U)
						   : 0x55U));
    // ALWAYS at VX_decode.v:357
    vlTOPp->__Vtableidx1 = (7U & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
				  >> 0xcU));
    vlTOPp->Vortex__DOT__vx_decode__DOT__mul_alu = 
	vlTOPp->__Vtable1_Vortex__DOT__vx_decode__DOT__mul_alu
	[vlTOPp->__Vtableidx1];
    vlTOPp->Vortex__DOT__vx_decode__DOT__alu_tempp 
	= (0xfffU & (((1U == (7U & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
				    >> 0xcU))) | (5U 
						  == 
						  (7U 
						   & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
						      >> 0xcU))))
		      ? (0x1fU & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
				  >> 0x14U)) : (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
						>> 0x14U)));
    vlTOPp->Vortex__DOT__vx_decode__DOT__is_csr = (
						   (0x73U 
						    == 
						    (0x7fU 
						     & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)) 
						   & (0U 
						      != 
						      (7U 
						       & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
							  >> 0xcU))));
    // ALWAYS at VX_decode.v:307
    vlTOPp->Vortex__DOT__decode_branch_type = ((0x63U 
						== 
						(0x7fU 
						 & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction))
					        ? (
						   (0x4000U 
						    & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						    ? 
						   ((0x2000U 
						     & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						     ? 
						    ((0x1000U 
						      & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						      ? 6U
						      : 5U)
						     : 
						    ((0x1000U 
						      & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						      ? 4U
						      : 3U))
						    : 
						   ((0x2000U 
						     & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						     ? 0U
						     : 
						    ((0x1000U 
						      & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						      ? 2U
						      : 1U)))
					        : 0U);
    vlTOPp->Vortex__DOT__vx_forwarding__DOT__src2_exe_fwd 
	= ((((0x1fU & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
		       >> 0x14U)) == (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__rd)) 
	    & (0U != (0x1fU & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
			       >> 0x14U)))) & (0U != (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__wb)));
    vlTOPp->Vortex__DOT__vx_forwarding__DOT__src1_exe_fwd 
	= ((((0x1fU & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
		       >> 0xfU)) == (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__rd)) 
	    & (0U != (0x1fU & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
			       >> 0xfU)))) & (0U != (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__wb)));
    // ALWAYS at VX_decode.v:296
    vlTOPp->Vortex__DOT__decode_itype_immed = ((0x40U 
						& vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
					        ? (
						   (0x20U 
						    & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						    ? 
						   ((0x10U 
						     & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						     ? 0xdeadbeefU
						     : 
						    ((8U 
						      & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						      ? 0xdeadbeefU
						      : 
						     ((4U 
						       & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						       ? 0xdeadbeefU
						       : 
						      ((2U 
							& vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						        ? 
						       ((1U 
							 & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
							 ? 
							((0xfffff000U 
							  & (VL_NEGATE_I((IData)(
										(1U 
										& (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
										>> 0x1fU)))) 
							     << 0xcU)) 
							 | ((0x800U 
							     & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
								>> 0x14U)) 
							    | ((0x400U 
								& (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
								   << 3U)) 
							       | ((0x3f0U 
								   & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
								      >> 0x15U)) 
								  | (0xfU 
								     & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
									>> 8U))))))
							 : 0xdeadbeefU)
						        : 0xdeadbeefU))))
						    : 0xdeadbeefU)
					        : (
						   (0x20U 
						    & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						    ? 
						   ((0x10U 
						     & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						     ? 0xdeadbeefU
						     : 
						    ((8U 
						      & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						      ? 0xdeadbeefU
						      : 
						     ((4U 
						       & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						       ? 0xdeadbeefU
						       : 
						      ((2U 
							& vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						        ? 
						       ((1U 
							 & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
							 ? 
							((0xfffff000U 
							  & (VL_NEGATE_I((IData)(
										(1U 
										& (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
										>> 0x1fU)))) 
							     << 0xcU)) 
							 | ((0xfe0U 
							     & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
								>> 0x14U)) 
							    | (0x1fU 
							       & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
								  >> 7U))))
							 : 0xdeadbeefU)
						        : 0xdeadbeefU))))
						    : 
						   ((0x10U 
						     & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						     ? 
						    ((8U 
						      & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						      ? 0xdeadbeefU
						      : 
						     ((4U 
						       & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						       ? 0xdeadbeefU
						       : 
						      ((2U 
							& vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						        ? 
						       ((1U 
							 & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
							 ? 
							((0xfffff000U 
							  & (VL_NEGATE_I((IData)(
										(1U 
										& ((IData)(vlTOPp->Vortex__DOT__vx_decode__DOT__alu_tempp) 
										>> 0xbU)))) 
							     << 0xcU)) 
							 | (IData)(vlTOPp->Vortex__DOT__vx_decode__DOT__alu_tempp))
							 : 0xdeadbeefU)
						        : 0xdeadbeefU)))
						     : 
						    ((8U 
						      & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						      ? 0xdeadbeefU
						      : 
						     ((4U 
						       & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						       ? 0xdeadbeefU
						       : 
						      ((2U 
							& vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						        ? 
						       ((1U 
							 & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
							 ? 
							((0xfffff000U 
							  & (VL_NEGATE_I((IData)(
										(1U 
										& (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
										>> 0x1fU)))) 
							     << 0xcU)) 
							 | (0xfffU 
							    & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
							       >> 0x14U)))
							 : 0xdeadbeefU)
						        : 0xdeadbeefU))))));
    vlTOPp->Vortex__DOT__vx_decode__DOT__temp_final_alu 
	= ((0x63U == (0x7fU & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction))
	    ? ((5U > (IData)(vlTOPp->Vortex__DOT__decode_branch_type))
	        ? 1U : 0xaU) : ((0x37U == (0x7fU & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction))
				 ? 0xbU : ((0x17U == 
					    (0x7fU 
					     & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction))
					    ? 0xcU : 
					   ((IData)(vlTOPp->Vortex__DOT__vx_decode__DOT__is_csr)
					     ? ((1U 
						 == 
						 (3U 
						  & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
						     >> 0xcU)))
						 ? 0xdU
						 : 
						((2U 
						  == 
						  (3U 
						   & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
						      >> 0xcU)))
						  ? 0xeU
						  : 0xfU))
					     : (((0x23U 
						  == 
						  (0x7fU 
						   & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)) 
						 | (3U 
						    == 
						    (0x7fU 
						     & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)))
						 ? 0U
						 : 
						((0x4000U 
						  & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						  ? 
						 ((0x2000U 
						   & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						   ? 
						  ((0x1000U 
						    & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						    ? 9U
						    : 8U)
						   : 
						  ((0x1000U 
						    & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						    ? 
						   ((0U 
						     == 
						     (0x7fU 
						      & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
							 >> 0x19U)))
						     ? 6U
						     : 7U)
						    : 5U))
						  : 
						 ((0x2000U 
						   & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						   ? 
						  ((0x1000U 
						    & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						    ? 4U
						    : 3U)
						   : 
						  ((0x1000U 
						    & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						    ? 2U
						    : 
						   ((0x13U 
						     == 
						     (0x7fU 
						      & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction))
						     ? 0U
						     : 
						    ((0U 
						      == 
						      (0x7fU 
						       & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
							  >> 0x19U)))
						      ? 0U
						      : 1U))))))))));
    vlTOPp->Vortex__DOT__vx_forwarding__DOT__src2_mem_fwd 
	= (((((0x1fU & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
			>> 0x14U)) == (IData)(vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__rd)) 
	     & (0U != (0x1fU & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
				>> 0x14U)))) & (0U 
						!= (IData)(vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__wb))) 
	   & (~ (IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src2_exe_fwd)));
    vlTOPp->Vortex__DOT__vx_forwarding__DOT__src1_mem_fwd 
	= (((((0x1fU & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
			>> 0xfU)) == (IData)(vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__rd)) 
	     & (0U != (0x1fU & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
				>> 0xfU)))) & (0U != (IData)(vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__wb))) 
	   & (~ (IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src1_exe_fwd)));
    vlTOPp->Vortex__DOT__vx_forwarding__DOT__src2_wb_fwd 
	= ((((((0x1fU & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
			 >> 0x14U)) == (IData)(vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__rd)) 
	      & (0U != (0x1fU & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
				 >> 0x14U)))) & (0U 
						 != (IData)(vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__wb))) 
	    & (~ (IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src2_exe_fwd))) 
	   & (~ (IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src2_mem_fwd)));
    vlTOPp->Vortex__DOT__forwarding_fwd_stall = ((((IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src1_exe_fwd) 
						   | (IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src2_exe_fwd)) 
						  & (2U 
						     == (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__wb))) 
						 | (((IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src1_mem_fwd) 
						     | (IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src2_mem_fwd)) 
						    & (2U 
						       == (IData)(vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__wb))));
    vlTOPp->Vortex__DOT__vx_forwarding__DOT__src1_wb_fwd 
	= ((((((0x1fU & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
			 >> 0xfU)) == (IData)(vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__rd)) 
	      & (0U != (0x1fU & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
				 >> 0xfU)))) & (0U 
						!= (IData)(vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__wb))) 
	    & (~ (IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src1_exe_fwd))) 
	   & (~ (IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src1_mem_fwd)));
    vlTOPp->Vortex__DOT__forwarding_src2_fwd = (((IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src2_exe_fwd) 
						 | (IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src2_mem_fwd)) 
						| (IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src2_wb_fwd));
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__stalling 
	= ((IData)(vlTOPp->Vortex__DOT__forwarding_fwd_stall) 
	   | (IData)(vlTOPp->Vortex__DOT__execute_branch_stall));
    vlTOPp->Vortex__DOT__vx_fetch__DOT__stall = (((
						   (0x63U 
						    == 
						    (0x7fU 
						     & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)) 
						   | ((0x6fU 
						       == 
						       (0x7fU 
							& vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)) 
						      | (0x67U 
							 == 
							 (0x7fU 
							  & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)))) 
						  | (IData)(vlTOPp->Vortex__DOT__forwarding_fwd_stall)) 
						 | (IData)(vlTOPp->Vortex__DOT__execute_branch_stall));
    vlTOPp->Vortex__DOT__forwarding_src1_fwd = (((IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src1_exe_fwd) 
						 | (IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src1_mem_fwd)) 
						| (IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src1_wb_fwd));
    vlTOPp->Vortex__DOT____Vcellout__vx_fetch__out_valid[0U] 
	= (1U & ((~ (IData)(vlTOPp->Vortex__DOT__vx_fetch__DOT__stall)) 
		 & (IData)(vlTOPp->Vortex__DOT__vx_fetch__DOT__valid)));
    vlTOPp->Vortex__DOT____Vcellout__vx_fetch__out_valid[1U] 
	= (1U & ((~ (IData)(vlTOPp->Vortex__DOT__vx_fetch__DOT__stall)) 
		 & ((IData)(vlTOPp->Vortex__DOT__vx_fetch__DOT__valid) 
		    >> 1U)));
    vlTOPp->Vortex__DOT__fetch_valid[1U] = vlTOPp->Vortex__DOT____Vcellout__vx_fetch__out_valid
	[1U];
    vlTOPp->Vortex__DOT__fetch_valid[0U] = vlTOPp->Vortex__DOT____Vcellout__vx_fetch__out_valid
	[0U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_f_d_reg__in_valid[1U] 
	= vlTOPp->Vortex__DOT__fetch_valid[1U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_f_d_reg__in_valid[0U] 
	= vlTOPp->Vortex__DOT__fetch_valid[0U];
}

void VVortex::_settle__TOP__8(VVortex__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VVortex::_settle__TOP__8\n"); );
    VVortex* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at VX_fetch.v:82
    vlTOPp->Vortex__DOT__vx_fetch__DOT__PC_to_use = 
	((IData)(vlTOPp->Vortex__DOT__vx_fetch__DOT__delay_reg)
	  ? vlTOPp->Vortex__DOT__vx_fetch__DOT__old
	  : ((IData)(vlTOPp->Vortex__DOT__vx_fetch__DOT__stall_reg)
	      ? vlTOPp->Vortex__DOT__vx_fetch__DOT__old
	      : ((0x10U & (IData)(vlTOPp->Vortex__DOT__vx_fetch__DOT__state))
		  ? 0U : ((8U & (IData)(vlTOPp->Vortex__DOT__vx_fetch__DOT__state))
			   ? 0U : ((4U & (IData)(vlTOPp->Vortex__DOT__vx_fetch__DOT__state))
				    ? ((2U & (IData)(vlTOPp->Vortex__DOT__vx_fetch__DOT__state))
				        ? 0U : ((1U 
						 & (IData)(vlTOPp->Vortex__DOT__vx_fetch__DOT__state))
						 ? 0U
						 : vlTOPp->Vortex__DOT__vx_fetch__DOT__old))
				    : ((2U & (IData)(vlTOPp->Vortex__DOT__vx_fetch__DOT__state))
				        ? ((1U & (IData)(vlTOPp->Vortex__DOT__vx_fetch__DOT__state))
					    ? vlTOPp->Vortex__DOT__vx_fetch__DOT__real_PC
					    : vlTOPp->Vortex__DOT__vx_fetch__DOT__BR_reg)
				        : ((1U & (IData)(vlTOPp->Vortex__DOT__vx_fetch__DOT__state))
					    ? vlTOPp->Vortex__DOT__vx_fetch__DOT__JAL_reg
					    : vlTOPp->Vortex__DOT__vx_fetch__DOT__real_PC)))))));
    vlTOPp->Vortex__DOT__vx_writeback__DOT__out_pc_data[0U] 
	= vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__PC_next;
    vlTOPp->Vortex__DOT__vx_writeback__DOT__out_pc_data[1U] 
	= vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__PC_next;
    vlTOPp->Vortex__DOT__vx_forwarding__DOT__use_writeback_PC_next[0U] 
	= vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__PC_next;
    vlTOPp->Vortex__DOT__vx_forwarding__DOT__use_writeback_PC_next[1U] 
	= vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__PC_next;
    vlTOPp->Vortex__DOT__csr_decode_csr_data = ((0xc00U 
						 == (IData)(vlTOPp->Vortex__DOT__vx_csr_handler__DOT__decode_csr_address))
						 ? (IData)(vlTOPp->Vortex__DOT__vx_csr_handler__DOT__cycle)
						 : 
						((0xc80U 
						  == (IData)(vlTOPp->Vortex__DOT__vx_csr_handler__DOT__decode_csr_address))
						  ? (IData)(
							    (vlTOPp->Vortex__DOT__vx_csr_handler__DOT__cycle 
							     >> 0x20U))
						  : 
						 ((0xc02U 
						   == (IData)(vlTOPp->Vortex__DOT__vx_csr_handler__DOT__decode_csr_address))
						   ? (IData)(vlTOPp->Vortex__DOT__vx_csr_handler__DOT__instret)
						   : 
						  ((0xc82U 
						    == (IData)(vlTOPp->Vortex__DOT__vx_csr_handler__DOT__decode_csr_address))
						    ? (IData)(
							      (vlTOPp->Vortex__DOT__vx_csr_handler__DOT__instret 
							       >> 0x20U))
						    : 
						   vlTOPp->Vortex__DOT__vx_csr_handler__DOT__csr
						   [vlTOPp->Vortex__DOT__vx_csr_handler__DOT__decode_csr_address]))));
    vlTOPp->out_cache_driver_in_mem_read = vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__mem_read;
    vlTOPp->out_cache_driver_in_mem_write = vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__mem_write;
    vlTOPp->Vortex__DOT__memory_branch_dest = (vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__curr_PC 
					       + (vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__branch_offset 
						  << 1U));
    vlTOPp->Vortex__DOT____Vcellout__vx_e_m_reg__out_valid[1U] 
	= vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__valid
	[1U];
    vlTOPp->Vortex__DOT____Vcellout__vx_e_m_reg__out_valid[0U] 
	= vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__valid
	[0U];
    vlTOPp->Vortex__DOT____Vcellout__vx_e_m_reg__out_reg_data[3U] 
	= vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__reg_data
	[3U];
    vlTOPp->Vortex__DOT____Vcellout__vx_e_m_reg__out_reg_data[2U] 
	= vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__reg_data
	[2U];
    vlTOPp->Vortex__DOT____Vcellout__vx_e_m_reg__out_reg_data[1U] 
	= vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__reg_data
	[1U];
    vlTOPp->Vortex__DOT____Vcellout__vx_e_m_reg__out_reg_data[0U] 
	= vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__reg_data
	[0U];
    vlTOPp->Vortex__DOT__vx_forwarding__DOT__use_memory_PC_next[0U] 
	= vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__PC_next;
    vlTOPp->Vortex__DOT__vx_forwarding__DOT__use_memory_PC_next[1U] 
	= vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__PC_next;
    vlTOPp->Vortex__DOT____Vcellout__vx_e_m_reg__out_alu_result[1U] 
	= vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__alu_result
	[1U];
    vlTOPp->Vortex__DOT____Vcellout__vx_e_m_reg__out_alu_result[0U] 
	= vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__alu_result
	[0U];
    vlTOPp->Vortex__DOT__execute_branch_stall = ((0U 
						  != (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__branch_type)) 
						 | (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__jal));
    vlTOPp->Vortex__DOT____Vcellout__vx_d_e_reg__out_valid[1U] 
	= vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__valid
	[1U];
    vlTOPp->Vortex__DOT____Vcellout__vx_d_e_reg__out_valid[0U] 
	= vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__valid
	[0U];
    vlTOPp->Vortex__DOT__vx_forwarding__DOT__use_execute_PC_next[0U] 
	= vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__PC_next_out;
    vlTOPp->Vortex__DOT__vx_forwarding__DOT__use_execute_PC_next[1U] 
	= vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__PC_next_out;
    vlTOPp->Vortex__DOT____Vcellout__vx_d_e_reg__out_reg_data[3U] 
	= vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__reg_data
	[3U];
    vlTOPp->Vortex__DOT____Vcellout__vx_d_e_reg__out_reg_data[2U] 
	= vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__reg_data
	[2U];
    vlTOPp->Vortex__DOT____Vcellout__vx_d_e_reg__out_reg_data[1U] 
	= vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__reg_data
	[1U];
    vlTOPp->Vortex__DOT____Vcellout__vx_d_e_reg__out_reg_data[0U] 
	= vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__reg_data
	[0U];
    vlTOPp->Vortex__DOT__vx_forwarding__DOT__src2_exe_fwd 
	= ((((0x1fU & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
		       >> 0x14U)) == (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__rd)) 
	    & (0U != (0x1fU & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
			       >> 0x14U)))) & (0U != (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__wb)));
    vlTOPp->Vortex__DOT__vx_forwarding__DOT__src1_exe_fwd 
	= ((((0x1fU & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
		       >> 0xfU)) == (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__rd)) 
	    & (0U != (0x1fU & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
			       >> 0xfU)))) & (0U != (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__wb)));
    vlTOPp->Vortex__DOT____Vcellout__vx_writeback__out_write_data[1U] 
	= ((3U == (IData)(vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__wb))
	    ? vlTOPp->Vortex__DOT__vx_writeback__DOT__out_pc_data
	   [1U] : ((1U == (IData)(vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__wb))
		    ? vlTOPp->Vortex__DOT____Vcellinp__vx_writeback__in_alu_result
		   [1U] : vlTOPp->Vortex__DOT____Vcellinp__vx_writeback__in_mem_result
		   [1U]));
    vlTOPp->Vortex__DOT____Vcellout__vx_writeback__out_write_data[0U] 
	= ((3U == (IData)(vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__wb))
	    ? vlTOPp->Vortex__DOT__vx_writeback__DOT__out_pc_data
	   [0U] : ((1U == (IData)(vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__wb))
		    ? vlTOPp->Vortex__DOT____Vcellinp__vx_writeback__in_alu_result
		   [0U] : vlTOPp->Vortex__DOT____Vcellinp__vx_writeback__in_mem_result
		   [0U]));
    vlTOPp->Vortex__DOT__e_m_valid[1U] = vlTOPp->Vortex__DOT____Vcellout__vx_e_m_reg__out_valid
	[1U];
    vlTOPp->Vortex__DOT__e_m_valid[0U] = vlTOPp->Vortex__DOT____Vcellout__vx_e_m_reg__out_valid
	[0U];
    vlTOPp->Vortex__DOT__e_m_reg_data[3U] = vlTOPp->Vortex__DOT____Vcellout__vx_e_m_reg__out_reg_data
	[3U];
    vlTOPp->Vortex__DOT__e_m_reg_data[2U] = vlTOPp->Vortex__DOT____Vcellout__vx_e_m_reg__out_reg_data
	[2U];
    vlTOPp->Vortex__DOT__e_m_reg_data[1U] = vlTOPp->Vortex__DOT____Vcellout__vx_e_m_reg__out_reg_data
	[1U];
    vlTOPp->Vortex__DOT__e_m_reg_data[0U] = vlTOPp->Vortex__DOT____Vcellout__vx_e_m_reg__out_reg_data
	[0U];
    vlTOPp->Vortex__DOT__e_m_alu_result[1U] = vlTOPp->Vortex__DOT____Vcellout__vx_e_m_reg__out_alu_result
	[1U];
    vlTOPp->Vortex__DOT__e_m_alu_result[0U] = vlTOPp->Vortex__DOT____Vcellout__vx_e_m_reg__out_alu_result
	[0U];
    vlTOPp->Vortex__DOT__d_e_valid[1U] = vlTOPp->Vortex__DOT____Vcellout__vx_d_e_reg__out_valid
	[1U];
    vlTOPp->Vortex__DOT__d_e_valid[0U] = vlTOPp->Vortex__DOT____Vcellout__vx_d_e_reg__out_valid
	[0U];
    vlTOPp->Vortex__DOT__d_e_reg_data[3U] = vlTOPp->Vortex__DOT____Vcellout__vx_d_e_reg__out_reg_data
	[3U];
    vlTOPp->Vortex__DOT__d_e_reg_data[2U] = vlTOPp->Vortex__DOT____Vcellout__vx_d_e_reg__out_reg_data
	[2U];
    vlTOPp->Vortex__DOT__d_e_reg_data[1U] = vlTOPp->Vortex__DOT____Vcellout__vx_d_e_reg__out_reg_data
	[1U];
    vlTOPp->Vortex__DOT__d_e_reg_data[0U] = vlTOPp->Vortex__DOT____Vcellout__vx_d_e_reg__out_reg_data
	[0U];
    vlTOPp->Vortex__DOT__vx_forwarding__DOT__src2_mem_fwd 
	= (((((0x1fU & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
			>> 0x14U)) == (IData)(vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__rd)) 
	     & (0U != (0x1fU & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
				>> 0x14U)))) & (0U 
						!= (IData)(vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__wb))) 
	   & (~ (IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src2_exe_fwd)));
    vlTOPp->Vortex__DOT__vx_forwarding__DOT__src1_mem_fwd 
	= (((((0x1fU & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
			>> 0xfU)) == (IData)(vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__rd)) 
	     & (0U != (0x1fU & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
				>> 0xfU)))) & (0U != (IData)(vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__wb))) 
	   & (~ (IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src1_exe_fwd)));
    vlTOPp->Vortex__DOT__writeback_write_data[1U] = 
	vlTOPp->Vortex__DOT____Vcellout__vx_writeback__out_write_data
	[1U];
    vlTOPp->Vortex__DOT__writeback_write_data[0U] = 
	vlTOPp->Vortex__DOT____Vcellout__vx_writeback__out_write_data
	[0U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_memory__in_valid[1U] 
	= vlTOPp->Vortex__DOT__e_m_valid[1U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_memory__in_valid[0U] 
	= vlTOPp->Vortex__DOT__e_m_valid[0U];
    vlTOPp->Vortex__DOT__use_rd2[0U] = vlTOPp->Vortex__DOT__e_m_reg_data
	[1U];
    vlTOPp->Vortex__DOT__use_rd2[1U] = vlTOPp->Vortex__DOT__e_m_reg_data
	[3U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_memory__in_alu_result[1U] 
	= vlTOPp->Vortex__DOT__e_m_alu_result[1U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_memory__in_alu_result[0U] 
	= vlTOPp->Vortex__DOT__e_m_alu_result[0U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_execute__in_valid[1U] 
	= vlTOPp->Vortex__DOT__d_e_valid[1U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_execute__in_valid[0U] 
	= vlTOPp->Vortex__DOT__d_e_valid[0U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_execute__in_reg_data[3U] 
	= vlTOPp->Vortex__DOT__d_e_reg_data[3U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_execute__in_reg_data[2U] 
	= vlTOPp->Vortex__DOT__d_e_reg_data[2U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_execute__in_reg_data[1U] 
	= vlTOPp->Vortex__DOT__d_e_reg_data[1U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_execute__in_reg_data[0U] 
	= vlTOPp->Vortex__DOT__d_e_reg_data[0U];
    vlTOPp->Vortex__DOT__vx_forwarding__DOT__src2_wb_fwd 
	= ((((((0x1fU & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
			 >> 0x14U)) == (IData)(vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__rd)) 
	      & (0U != (0x1fU & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
				 >> 0x14U)))) & (0U 
						 != (IData)(vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__wb))) 
	    & (~ (IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src2_exe_fwd))) 
	   & (~ (IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src2_mem_fwd)));
    vlTOPp->Vortex__DOT__forwarding_fwd_stall = ((((IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src1_exe_fwd) 
						   | (IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src2_exe_fwd)) 
						  & (2U 
						     == (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__wb))) 
						 | (((IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src1_mem_fwd) 
						     | (IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src2_mem_fwd)) 
						    & (2U 
						       == (IData)(vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__wb))));
    vlTOPp->Vortex__DOT__vx_forwarding__DOT__src1_wb_fwd 
	= ((((((0x1fU & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
			 >> 0xfU)) == (IData)(vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__rd)) 
	      & (0U != (0x1fU & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
				 >> 0xfU)))) & (0U 
						!= (IData)(vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__wb))) 
	    & (~ (IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src1_exe_fwd))) 
	   & (~ (IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src1_mem_fwd)));
    vlTOPp->Vortex__DOT____Vcellinp__vx_decode__in_write_data[1U] 
	= vlTOPp->Vortex__DOT__writeback_write_data
	[1U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_decode__in_write_data[0U] 
	= vlTOPp->Vortex__DOT__writeback_write_data
	[0U];
    vlTOPp->Vortex__DOT____Vcellout__vx_memory__out_cache_driver_in_valid[1U] 
	= vlTOPp->Vortex__DOT____Vcellinp__vx_memory__in_valid
	[1U];
    vlTOPp->Vortex__DOT____Vcellout__vx_memory__out_cache_driver_in_valid[0U] 
	= vlTOPp->Vortex__DOT____Vcellinp__vx_memory__in_valid
	[0U];
    vlTOPp->Vortex__DOT____Vcellout__vx_memory__out_valid[1U] 
	= vlTOPp->Vortex__DOT____Vcellinp__vx_memory__in_valid
	[1U];
    vlTOPp->Vortex__DOT____Vcellout__vx_memory__out_valid[0U] 
	= vlTOPp->Vortex__DOT____Vcellinp__vx_memory__in_valid
	[0U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_memory__in_rd2[1U] 
	= vlTOPp->Vortex__DOT__use_rd2[1U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_memory__in_rd2[0U] 
	= vlTOPp->Vortex__DOT__use_rd2[0U];
    vlTOPp->Vortex__DOT____Vcellout__vx_memory__out_cache_driver_in_address[1U] 
	= vlTOPp->Vortex__DOT____Vcellinp__vx_memory__in_alu_result
	[1U];
    vlTOPp->Vortex__DOT____Vcellout__vx_memory__out_cache_driver_in_address[0U] 
	= vlTOPp->Vortex__DOT____Vcellinp__vx_memory__in_alu_result
	[0U];
    // ALWAYS at VX_memory.v:65
    vlTOPp->Vortex__DOT__memory_branch_dir = (1U & 
					      ((4U 
						& (IData)(vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__branch_type))
					        ? (
						   (2U 
						    & (IData)(vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__branch_type))
						    ? 
						   ((~ (IData)(vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__branch_type)) 
						    & (~ 
						       (vlTOPp->Vortex__DOT____Vcellinp__vx_memory__in_alu_result
							[0U] 
							>> 0x1fU)))
						    : 
						   ((1U 
						     & (IData)(vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__branch_type))
						     ? 
						    (vlTOPp->Vortex__DOT____Vcellinp__vx_memory__in_alu_result
						     [0U] 
						     >> 0x1fU)
						     : 
						    (~ 
						     (vlTOPp->Vortex__DOT____Vcellinp__vx_memory__in_alu_result
						      [0U] 
						      >> 0x1fU))))
					        : (
						   (2U 
						    & (IData)(vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__branch_type))
						    ? 
						   ((1U 
						     & (IData)(vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__branch_type))
						     ? 
						    (vlTOPp->Vortex__DOT____Vcellinp__vx_memory__in_alu_result
						     [0U] 
						     >> 0x1fU)
						     : 
						    (0U 
						     != 
						     vlTOPp->Vortex__DOT____Vcellinp__vx_memory__in_alu_result
						     [0U]))
						    : 
						   ((IData)(vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__branch_type) 
						    & (0U 
						       == 
						       vlTOPp->Vortex__DOT____Vcellinp__vx_memory__in_alu_result
						       [0U])))));
    vlTOPp->Vortex__DOT____Vcellout__vx_memory__out_alu_result[1U] 
	= vlTOPp->Vortex__DOT____Vcellinp__vx_memory__in_alu_result
	[1U];
    vlTOPp->Vortex__DOT____Vcellout__vx_memory__out_alu_result[0U] 
	= vlTOPp->Vortex__DOT____Vcellinp__vx_memory__in_alu_result
	[0U];
    vlTOPp->Vortex__DOT____Vcellout__vx_execute__out_valid[1U] 
	= vlTOPp->Vortex__DOT____Vcellinp__vx_execute__in_valid
	[1U];
    vlTOPp->Vortex__DOT____Vcellout__vx_execute__out_valid[0U] 
	= vlTOPp->Vortex__DOT____Vcellinp__vx_execute__in_valid
	[0U];
    vlTOPp->Vortex__DOT____Vcellout__vx_execute__out_reg_data[3U] 
	= vlTOPp->Vortex__DOT____Vcellinp__vx_execute__in_reg_data
	[3U];
    vlTOPp->Vortex__DOT____Vcellout__vx_execute__out_reg_data[2U] 
	= vlTOPp->Vortex__DOT____Vcellinp__vx_execute__in_reg_data
	[2U];
    vlTOPp->Vortex__DOT____Vcellout__vx_execute__out_reg_data[1U] 
	= vlTOPp->Vortex__DOT____Vcellinp__vx_execute__in_reg_data
	[1U];
    vlTOPp->Vortex__DOT____Vcellout__vx_execute__out_reg_data[0U] 
	= vlTOPp->Vortex__DOT____Vcellinp__vx_execute__in_reg_data
	[0U];
    vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__0__KET____DOT__vx_alu__in_reg_data[1U] 
	= vlTOPp->Vortex__DOT____Vcellinp__vx_execute__in_reg_data
	[1U];
    vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__0__KET____DOT__vx_alu__in_reg_data[0U] 
	= vlTOPp->Vortex__DOT____Vcellinp__vx_execute__in_reg_data
	[0U];
    vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__2__KET____DOT__vx_alu__in_reg_data[1U] 
	= vlTOPp->Vortex__DOT____Vcellinp__vx_execute__in_reg_data
	[3U];
    vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__2__KET____DOT__vx_alu__in_reg_data[0U] 
	= vlTOPp->Vortex__DOT____Vcellinp__vx_execute__in_reg_data
	[2U];
    vlTOPp->Vortex__DOT__forwarding_src2_fwd = (((IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src2_exe_fwd) 
						 | (IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src2_mem_fwd)) 
						| (IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src2_wb_fwd));
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__stalling 
	= ((IData)(vlTOPp->Vortex__DOT__forwarding_fwd_stall) 
	   | (IData)(vlTOPp->Vortex__DOT__execute_branch_stall));
    vlTOPp->Vortex__DOT__vx_fetch__DOT__stall = (((
						   (0x63U 
						    == 
						    (0x7fU 
						     & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)) 
						   | ((0x6fU 
						       == 
						       (0x7fU 
							& vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)) 
						      | (0x67U 
							 == 
							 (0x7fU 
							  & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)))) 
						  | (IData)(vlTOPp->Vortex__DOT__forwarding_fwd_stall)) 
						 | (IData)(vlTOPp->Vortex__DOT__execute_branch_stall));
    vlTOPp->Vortex__DOT__forwarding_src1_fwd = (((IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src1_exe_fwd) 
						 | (IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src1_mem_fwd)) 
						| (IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src1_wb_fwd));
    vlTOPp->out_cache_driver_in_valid[1U] = vlTOPp->Vortex__DOT____Vcellout__vx_memory__out_cache_driver_in_valid
	[1U];
    vlTOPp->out_cache_driver_in_valid[0U] = vlTOPp->Vortex__DOT____Vcellout__vx_memory__out_cache_driver_in_valid
	[0U];
    vlTOPp->Vortex__DOT__memory_valid[1U] = vlTOPp->Vortex__DOT____Vcellout__vx_memory__out_valid
	[1U];
    vlTOPp->Vortex__DOT__memory_valid[0U] = vlTOPp->Vortex__DOT____Vcellout__vx_memory__out_valid
	[0U];
    vlTOPp->Vortex__DOT____Vcellout__vx_memory__out_cache_driver_in_data[1U] 
	= vlTOPp->Vortex__DOT____Vcellinp__vx_memory__in_rd2
	[1U];
    vlTOPp->Vortex__DOT____Vcellout__vx_memory__out_cache_driver_in_data[0U] 
	= vlTOPp->Vortex__DOT____Vcellinp__vx_memory__in_rd2
	[0U];
    vlTOPp->out_cache_driver_in_address[1U] = vlTOPp->Vortex__DOT____Vcellout__vx_memory__out_cache_driver_in_address
	[1U];
    vlTOPp->out_cache_driver_in_address[0U] = vlTOPp->Vortex__DOT____Vcellout__vx_memory__out_cache_driver_in_address
	[0U];
    // ALWAYS at VX_fetch.v:110
    vlTOPp->Vortex__DOT__vx_fetch__DOT__temp_PC = (
						   ((IData)(vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__jal) 
						    & (~ (IData)(vlTOPp->Vortex__DOT__vx_fetch__DOT__delay_reg)))
						    ? vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__jal_dest
						    : 
						   (((IData)(vlTOPp->Vortex__DOT__memory_branch_dir) 
						     & (~ (IData)(vlTOPp->Vortex__DOT__vx_fetch__DOT__delay_reg)))
						     ? vlTOPp->Vortex__DOT__memory_branch_dest
						     : vlTOPp->Vortex__DOT__vx_fetch__DOT__PC_to_use));
    vlTOPp->Vortex__DOT__memory_alu_result[1U] = vlTOPp->Vortex__DOT____Vcellout__vx_memory__out_alu_result
	[1U];
    vlTOPp->Vortex__DOT__memory_alu_result[0U] = vlTOPp->Vortex__DOT____Vcellout__vx_memory__out_alu_result
	[0U];
    vlTOPp->Vortex__DOT__execute_valid[1U] = vlTOPp->Vortex__DOT____Vcellout__vx_execute__out_valid
	[1U];
    vlTOPp->Vortex__DOT__execute_valid[0U] = vlTOPp->Vortex__DOT____Vcellout__vx_execute__out_valid
	[0U];
    vlTOPp->Vortex__DOT__execute_reg_data[3U] = vlTOPp->Vortex__DOT____Vcellout__vx_execute__out_reg_data
	[3U];
    vlTOPp->Vortex__DOT__execute_reg_data[2U] = vlTOPp->Vortex__DOT____Vcellout__vx_execute__out_reg_data
	[2U];
    vlTOPp->Vortex__DOT__execute_reg_data[1U] = vlTOPp->Vortex__DOT____Vcellout__vx_execute__out_reg_data
	[1U];
    vlTOPp->Vortex__DOT__execute_reg_data[0U] = vlTOPp->Vortex__DOT____Vcellout__vx_execute__out_reg_data
	[0U];
    vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__0__KET____DOT__vx_alu__DOT__ALU_in2 
	= ((IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__rs2_src)
	    ? vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__itype_immed
	    : vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__0__KET____DOT__vx_alu__in_reg_data
	   [1U]);
    vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__2__KET____DOT__vx_alu__DOT__ALU_in2 
	= ((IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__rs2_src)
	    ? vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__itype_immed
	    : vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__2__KET____DOT__vx_alu__in_reg_data
	   [1U]);
    vlTOPp->Vortex__DOT____Vcellout__vx_fetch__out_valid[0U] 
	= (1U & ((~ (IData)(vlTOPp->Vortex__DOT__vx_fetch__DOT__stall)) 
		 & (IData)(vlTOPp->Vortex__DOT__vx_fetch__DOT__valid)));
    vlTOPp->Vortex__DOT____Vcellout__vx_fetch__out_valid[1U] 
	= (1U & ((~ (IData)(vlTOPp->Vortex__DOT__vx_fetch__DOT__stall)) 
		 & ((IData)(vlTOPp->Vortex__DOT__vx_fetch__DOT__valid) 
		    >> 1U)));
    vlTOPp->Vortex__DOT____Vcellinp__vx_m_w_reg__in_valid[1U] 
	= vlTOPp->Vortex__DOT__memory_valid[1U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_m_w_reg__in_valid[0U] 
	= vlTOPp->Vortex__DOT__memory_valid[0U];
    vlTOPp->out_cache_driver_in_data[1U] = vlTOPp->Vortex__DOT____Vcellout__vx_memory__out_cache_driver_in_data
	[1U];
    vlTOPp->out_cache_driver_in_data[0U] = vlTOPp->Vortex__DOT____Vcellout__vx_memory__out_cache_driver_in_data
	[0U];
    vlTOPp->curr_PC = vlTOPp->Vortex__DOT__vx_fetch__DOT__temp_PC;
    vlTOPp->Vortex__DOT____Vcellinp__vx_m_w_reg__in_alu_result[1U] 
	= vlTOPp->Vortex__DOT__memory_alu_result[1U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_m_w_reg__in_alu_result[0U] 
	= vlTOPp->Vortex__DOT__memory_alu_result[0U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_forwarding__in_memory_alu_result[1U] 
	= vlTOPp->Vortex__DOT__memory_alu_result[1U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_forwarding__in_memory_alu_result[0U] 
	= vlTOPp->Vortex__DOT__memory_alu_result[0U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_e_m_reg__in_valid[1U] 
	= vlTOPp->Vortex__DOT__execute_valid[1U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_e_m_reg__in_valid[0U] 
	= vlTOPp->Vortex__DOT__execute_valid[0U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_e_m_reg__in_reg_data[3U] 
	= vlTOPp->Vortex__DOT__execute_reg_data[3U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_e_m_reg__in_reg_data[2U] 
	= vlTOPp->Vortex__DOT__execute_reg_data[2U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_e_m_reg__in_reg_data[1U] 
	= vlTOPp->Vortex__DOT__execute_reg_data[1U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_e_m_reg__in_reg_data[0U] 
	= vlTOPp->Vortex__DOT__execute_reg_data[0U];
    vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__0__KET____DOT__vx_alu__DOT__mult_signed_result 
	= VL_MULS_QQQ(64,64,64, VL_EXTENDS_QI(64,32, 
					      vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__0__KET____DOT__vx_alu__in_reg_data
					      [0U]), 
		      VL_EXTENDS_QI(64,32, vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__0__KET____DOT__vx_alu__DOT__ALU_in2));
    vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__2__KET____DOT__vx_alu__DOT__mult_signed_result 
	= VL_MULS_QQQ(64,64,64, VL_EXTENDS_QI(64,32, 
					      vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__2__KET____DOT__vx_alu__in_reg_data
					      [0U]), 
		      VL_EXTENDS_QI(64,32, vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__2__KET____DOT__vx_alu__DOT__ALU_in2));
    vlTOPp->Vortex__DOT__fetch_valid[1U] = vlTOPp->Vortex__DOT____Vcellout__vx_fetch__out_valid
	[1U];
    vlTOPp->Vortex__DOT__fetch_valid[0U] = vlTOPp->Vortex__DOT____Vcellout__vx_fetch__out_valid
	[0U];
    // ALWAYS at VX_alu.v:47
    vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellout__gen_code_label__BRA__0__KET____DOT__vx_alu__out_alu_result 
	= ((0x10U & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
	    ? ((8U & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
	        ? 0U : ((4U & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
			 ? ((2U & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
			     ? ((1U & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
				 ? ((0U == vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__0__KET____DOT__vx_alu__DOT__ALU_in2)
				     ? vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__0__KET____DOT__vx_alu__in_reg_data
				    [0U] : VL_MODDIV_III(32, 
							 vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__0__KET____DOT__vx_alu__in_reg_data
							 [0U], vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__0__KET____DOT__vx_alu__DOT__ALU_in2))
				 : ((0U == vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__0__KET____DOT__vx_alu__DOT__ALU_in2)
				     ? vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__0__KET____DOT__vx_alu__in_reg_data
				    [0U] : VL_MODDIVS_III(32, 
							  vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__0__KET____DOT__vx_alu__in_reg_data
							  [0U], vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__0__KET____DOT__vx_alu__DOT__ALU_in2)))
			     : ((1U & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
				 ? ((0U == vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__0__KET____DOT__vx_alu__DOT__ALU_in2)
				     ? 0xffffffffU : 
				    VL_DIV_III(32, 
					       vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__0__KET____DOT__vx_alu__in_reg_data
					       [0U], vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__0__KET____DOT__vx_alu__DOT__ALU_in2))
				 : ((0U == vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__0__KET____DOT__vx_alu__DOT__ALU_in2)
				     ? 0xffffffffU : 
				    VL_DIVS_III(32, 
						vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__0__KET____DOT__vx_alu__in_reg_data
						[0U], vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__0__KET____DOT__vx_alu__DOT__ALU_in2))))
			 : ((2U & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
			     ? ((1U & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
				 ? (IData)((((QData)((IData)(
							     vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__0__KET____DOT__vx_alu__in_reg_data
							     [0U])) 
					     * (QData)((IData)(vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__0__KET____DOT__vx_alu__DOT__ALU_in2))) 
					    >> 0x20U))
				 : (IData)((((((QData)((IData)(
							       VL_NEGATE_I((IData)(
										(1U 
										& (vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__0__KET____DOT__vx_alu__in_reg_data
										[0U] 
										>> 0x1fU)))))) 
					       << 0x20U) 
					      | (QData)((IData)(
								vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__0__KET____DOT__vx_alu__in_reg_data
								[0U]))) 
					     * (QData)((IData)(vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__0__KET____DOT__vx_alu__DOT__ALU_in2))) 
					    >> 0x20U)))
			     : ((1U & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
				 ? (IData)((vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__0__KET____DOT__vx_alu__DOT__mult_signed_result 
					    >> 0x20U))
				 : (IData)(vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__0__KET____DOT__vx_alu__DOT__mult_signed_result)))))
	    : ((8U & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
	        ? ((4U & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
		    ? ((2U & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
		        ? vlTOPp->Vortex__DOT__csr_decode_csr_data
		        : ((1U & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
			    ? vlTOPp->Vortex__DOT__csr_decode_csr_data
			    : (vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__curr_PC 
			       + (vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__upper_immed 
				  << 0xcU)))) : ((2U 
						  & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
						  ? 
						 ((1U 
						   & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
						   ? 
						  (vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__upper_immed 
						   << 0xcU)
						   : 
						  ((vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__0__KET____DOT__vx_alu__in_reg_data
						    [0U] 
						    >= vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__0__KET____DOT__vx_alu__DOT__ALU_in2)
						    ? 0U
						    : 0xffffffffU))
						  : 
						 ((1U 
						   & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
						   ? 
						  (vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__0__KET____DOT__vx_alu__DOT__ALU_in2 
						   & vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__0__KET____DOT__vx_alu__in_reg_data
						   [0U])
						   : 
						  (vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__0__KET____DOT__vx_alu__in_reg_data
						   [0U] 
						   | vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__0__KET____DOT__vx_alu__DOT__ALU_in2))))
	        : ((4U & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
		    ? ((2U & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
		        ? ((1U & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
			    ? VL_SHIFTRS_III(32,32,5, 
					     vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__0__KET____DOT__vx_alu__in_reg_data
					     [0U], 
					     (0x1fU 
					      & vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__0__KET____DOT__vx_alu__DOT__ALU_in2))
			    : (vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__0__KET____DOT__vx_alu__in_reg_data
			       [0U] >> (0x1fU & vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__0__KET____DOT__vx_alu__DOT__ALU_in2)))
		        : ((1U & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
			    ? (vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__0__KET____DOT__vx_alu__in_reg_data
			       [0U] ^ vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__0__KET____DOT__vx_alu__DOT__ALU_in2)
			    : ((vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__0__KET____DOT__vx_alu__in_reg_data
				[0U] < vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__0__KET____DOT__vx_alu__DOT__ALU_in2)
			        ? 1U : 0U))) : ((2U 
						 & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
						 ? 
						((1U 
						  & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
						  ? 
						 (VL_LTS_III(1,32,32, 
							     vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__0__KET____DOT__vx_alu__in_reg_data
							     [0U], vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__0__KET____DOT__vx_alu__DOT__ALU_in2)
						   ? 1U
						   : 0U)
						  : 
						 (vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__0__KET____DOT__vx_alu__in_reg_data
						  [0U] 
						  << 
						  (0x1fU 
						   & vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__0__KET____DOT__vx_alu__DOT__ALU_in2)))
						 : 
						((1U 
						  & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
						  ? 
						 (vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__0__KET____DOT__vx_alu__in_reg_data
						  [0U] 
						  - vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__0__KET____DOT__vx_alu__DOT__ALU_in2)
						  : 
						 (vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__0__KET____DOT__vx_alu__in_reg_data
						  [0U] 
						  + vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__0__KET____DOT__vx_alu__DOT__ALU_in2))))));
    // ALWAYS at VX_alu.v:47
    vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellout__gen_code_label__BRA__2__KET____DOT__vx_alu__out_alu_result 
	= ((0x10U & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
	    ? ((8U & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
	        ? 0U : ((4U & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
			 ? ((2U & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
			     ? ((1U & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
				 ? ((0U == vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__2__KET____DOT__vx_alu__DOT__ALU_in2)
				     ? vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__2__KET____DOT__vx_alu__in_reg_data
				    [0U] : VL_MODDIV_III(32, 
							 vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__2__KET____DOT__vx_alu__in_reg_data
							 [0U], vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__2__KET____DOT__vx_alu__DOT__ALU_in2))
				 : ((0U == vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__2__KET____DOT__vx_alu__DOT__ALU_in2)
				     ? vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__2__KET____DOT__vx_alu__in_reg_data
				    [0U] : VL_MODDIVS_III(32, 
							  vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__2__KET____DOT__vx_alu__in_reg_data
							  [0U], vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__2__KET____DOT__vx_alu__DOT__ALU_in2)))
			     : ((1U & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
				 ? ((0U == vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__2__KET____DOT__vx_alu__DOT__ALU_in2)
				     ? 0xffffffffU : 
				    VL_DIV_III(32, 
					       vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__2__KET____DOT__vx_alu__in_reg_data
					       [0U], vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__2__KET____DOT__vx_alu__DOT__ALU_in2))
				 : ((0U == vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__2__KET____DOT__vx_alu__DOT__ALU_in2)
				     ? 0xffffffffU : 
				    VL_DIVS_III(32, 
						vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__2__KET____DOT__vx_alu__in_reg_data
						[0U], vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__2__KET____DOT__vx_alu__DOT__ALU_in2))))
			 : ((2U & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
			     ? ((1U & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
				 ? (IData)((((QData)((IData)(
							     vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__2__KET____DOT__vx_alu__in_reg_data
							     [0U])) 
					     * (QData)((IData)(vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__2__KET____DOT__vx_alu__DOT__ALU_in2))) 
					    >> 0x20U))
				 : (IData)((((((QData)((IData)(
							       VL_NEGATE_I((IData)(
										(1U 
										& (vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__2__KET____DOT__vx_alu__in_reg_data
										[0U] 
										>> 0x1fU)))))) 
					       << 0x20U) 
					      | (QData)((IData)(
								vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__2__KET____DOT__vx_alu__in_reg_data
								[0U]))) 
					     * (QData)((IData)(vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__2__KET____DOT__vx_alu__DOT__ALU_in2))) 
					    >> 0x20U)))
			     : ((1U & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
				 ? (IData)((vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__2__KET____DOT__vx_alu__DOT__mult_signed_result 
					    >> 0x20U))
				 : (IData)(vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__2__KET____DOT__vx_alu__DOT__mult_signed_result)))))
	    : ((8U & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
	        ? ((4U & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
		    ? ((2U & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
		        ? vlTOPp->Vortex__DOT__csr_decode_csr_data
		        : ((1U & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
			    ? vlTOPp->Vortex__DOT__csr_decode_csr_data
			    : (vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__curr_PC 
			       + (vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__upper_immed 
				  << 0xcU)))) : ((2U 
						  & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
						  ? 
						 ((1U 
						   & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
						   ? 
						  (vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__upper_immed 
						   << 0xcU)
						   : 
						  ((vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__2__KET____DOT__vx_alu__in_reg_data
						    [0U] 
						    >= vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__2__KET____DOT__vx_alu__DOT__ALU_in2)
						    ? 0U
						    : 0xffffffffU))
						  : 
						 ((1U 
						   & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
						   ? 
						  (vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__2__KET____DOT__vx_alu__DOT__ALU_in2 
						   & vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__2__KET____DOT__vx_alu__in_reg_data
						   [0U])
						   : 
						  (vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__2__KET____DOT__vx_alu__in_reg_data
						   [0U] 
						   | vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__2__KET____DOT__vx_alu__DOT__ALU_in2))))
	        : ((4U & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
		    ? ((2U & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
		        ? ((1U & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
			    ? VL_SHIFTRS_III(32,32,5, 
					     vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__2__KET____DOT__vx_alu__in_reg_data
					     [0U], 
					     (0x1fU 
					      & vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__2__KET____DOT__vx_alu__DOT__ALU_in2))
			    : (vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__2__KET____DOT__vx_alu__in_reg_data
			       [0U] >> (0x1fU & vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__2__KET____DOT__vx_alu__DOT__ALU_in2)))
		        : ((1U & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
			    ? (vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__2__KET____DOT__vx_alu__in_reg_data
			       [0U] ^ vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__2__KET____DOT__vx_alu__DOT__ALU_in2)
			    : ((vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__2__KET____DOT__vx_alu__in_reg_data
				[0U] < vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__2__KET____DOT__vx_alu__DOT__ALU_in2)
			        ? 1U : 0U))) : ((2U 
						 & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
						 ? 
						((1U 
						  & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
						  ? 
						 (VL_LTS_III(1,32,32, 
							     vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__2__KET____DOT__vx_alu__in_reg_data
							     [0U], vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__2__KET____DOT__vx_alu__DOT__ALU_in2)
						   ? 1U
						   : 0U)
						  : 
						 (vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__2__KET____DOT__vx_alu__in_reg_data
						  [0U] 
						  << 
						  (0x1fU 
						   & vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__2__KET____DOT__vx_alu__DOT__ALU_in2)))
						 : 
						((1U 
						  & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
						  ? 
						 (vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__2__KET____DOT__vx_alu__in_reg_data
						  [0U] 
						  - vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__2__KET____DOT__vx_alu__DOT__ALU_in2)
						  : 
						 (vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__2__KET____DOT__vx_alu__in_reg_data
						  [0U] 
						  + vlTOPp->Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__2__KET____DOT__vx_alu__DOT__ALU_in2))))));
    vlTOPp->Vortex__DOT____Vcellinp__vx_f_d_reg__in_valid[1U] 
	= vlTOPp->Vortex__DOT__fetch_valid[1U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_f_d_reg__in_valid[0U] 
	= vlTOPp->Vortex__DOT__fetch_valid[0U];
    vlTOPp->Vortex__DOT____Vcellout__vx_execute__out_alu_result[0U] 
	= vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellout__gen_code_label__BRA__0__KET____DOT__vx_alu__out_alu_result;
    vlTOPp->Vortex__DOT____Vcellout__vx_execute__out_alu_result[0U] 
	= vlTOPp->Vortex__DOT__vx_execute__DOT____Vcellout__gen_code_label__BRA__2__KET____DOT__vx_alu__out_alu_result;
    vlTOPp->Vortex__DOT__execute_alu_result[1U] = vlTOPp->Vortex__DOT____Vcellout__vx_execute__out_alu_result
	[1U];
    vlTOPp->Vortex__DOT__execute_alu_result[0U] = vlTOPp->Vortex__DOT____Vcellout__vx_execute__out_alu_result
	[0U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_e_m_reg__in_alu_result[1U] 
	= vlTOPp->Vortex__DOT__execute_alu_result[1U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_e_m_reg__in_alu_result[0U] 
	= vlTOPp->Vortex__DOT__execute_alu_result[0U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_forwarding__in_execute_alu_result[1U] 
	= vlTOPp->Vortex__DOT__execute_alu_result[1U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_forwarding__in_execute_alu_result[0U] 
	= vlTOPp->Vortex__DOT__execute_alu_result[0U];
    vlTOPp->Vortex__DOT____Vcellout__vx_forwarding__out_src2_fwd_data[1U] 
	= ((IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src2_exe_fwd)
	    ? ((3U == (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__wb))
	        ? vlTOPp->Vortex__DOT__vx_forwarding__DOT__use_execute_PC_next
	       [1U] : vlTOPp->Vortex__DOT____Vcellinp__vx_forwarding__in_execute_alu_result
	       [1U]) : ((IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src2_mem_fwd)
			 ? ((3U == (IData)(vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__wb))
			     ? vlTOPp->Vortex__DOT__vx_forwarding__DOT__use_memory_PC_next
			    [1U] : ((2U == (IData)(vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__wb))
				     ? vlTOPp->Vortex__DOT____Vcellinp__vx_forwarding__in_memory_mem_data
				    [1U] : vlTOPp->Vortex__DOT____Vcellinp__vx_forwarding__in_memory_alu_result
				    [1U])) : ((IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src2_wb_fwd)
					       ? ((3U 
						   == (IData)(vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__wb))
						   ? 
						  vlTOPp->Vortex__DOT__vx_forwarding__DOT__use_writeback_PC_next
						  [1U]
						   : 
						  ((2U 
						    == (IData)(vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__wb))
						    ? 
						   vlTOPp->Vortex__DOT____Vcellinp__vx_forwarding__in_writeback_mem_data
						   [1U]
						    : 
						   vlTOPp->Vortex__DOT____Vcellinp__vx_forwarding__in_writeback_alu_result
						   [1U]))
					       : vlTOPp->Vortex__DOT____Vcellinp__vx_forwarding__in_execute_alu_result
					      [1U])));
    vlTOPp->Vortex__DOT____Vcellout__vx_forwarding__out_src2_fwd_data[0U] 
	= ((IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src2_exe_fwd)
	    ? ((3U == (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__wb))
	        ? vlTOPp->Vortex__DOT__vx_forwarding__DOT__use_execute_PC_next
	       [0U] : vlTOPp->Vortex__DOT____Vcellinp__vx_forwarding__in_execute_alu_result
	       [0U]) : ((IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src2_mem_fwd)
			 ? ((3U == (IData)(vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__wb))
			     ? vlTOPp->Vortex__DOT__vx_forwarding__DOT__use_memory_PC_next
			    [0U] : ((2U == (IData)(vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__wb))
				     ? vlTOPp->Vortex__DOT____Vcellinp__vx_forwarding__in_memory_mem_data
				    [0U] : vlTOPp->Vortex__DOT____Vcellinp__vx_forwarding__in_memory_alu_result
				    [0U])) : ((IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src2_wb_fwd)
					       ? ((3U 
						   == (IData)(vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__wb))
						   ? 
						  vlTOPp->Vortex__DOT__vx_forwarding__DOT__use_writeback_PC_next
						  [0U]
						   : 
						  ((2U 
						    == (IData)(vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__wb))
						    ? 
						   vlTOPp->Vortex__DOT____Vcellinp__vx_forwarding__in_writeback_mem_data
						   [0U]
						    : 
						   vlTOPp->Vortex__DOT____Vcellinp__vx_forwarding__in_writeback_alu_result
						   [0U]))
					       : vlTOPp->Vortex__DOT____Vcellinp__vx_forwarding__in_execute_alu_result
					      [0U])));
    vlTOPp->Vortex__DOT____Vcellout__vx_forwarding__out_src1_fwd_data[1U] 
	= ((IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src1_exe_fwd)
	    ? ((3U == (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__wb))
	        ? vlTOPp->Vortex__DOT__vx_forwarding__DOT__use_execute_PC_next
	       [1U] : vlTOPp->Vortex__DOT____Vcellinp__vx_forwarding__in_execute_alu_result
	       [1U]) : ((IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src1_mem_fwd)
			 ? ((3U == (IData)(vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__wb))
			     ? vlTOPp->Vortex__DOT__vx_forwarding__DOT__use_memory_PC_next
			    [1U] : ((2U == (IData)(vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__wb))
				     ? vlTOPp->Vortex__DOT____Vcellinp__vx_forwarding__in_memory_mem_data
				    [1U] : vlTOPp->Vortex__DOT____Vcellinp__vx_forwarding__in_memory_alu_result
				    [1U])) : ((IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src1_wb_fwd)
					       ? ((3U 
						   == (IData)(vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__wb))
						   ? 
						  vlTOPp->Vortex__DOT__vx_forwarding__DOT__use_writeback_PC_next
						  [1U]
						   : 
						  ((2U 
						    == (IData)(vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__wb))
						    ? 
						   vlTOPp->Vortex__DOT____Vcellinp__vx_forwarding__in_writeback_mem_data
						   [1U]
						    : 
						   vlTOPp->Vortex__DOT____Vcellinp__vx_forwarding__in_writeback_alu_result
						   [1U]))
					       : vlTOPp->Vortex__DOT____Vcellinp__vx_forwarding__in_execute_alu_result
					      [1U])));
    vlTOPp->Vortex__DOT____Vcellout__vx_forwarding__out_src1_fwd_data[0U] 
	= ((IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src1_exe_fwd)
	    ? ((3U == (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__wb))
	        ? vlTOPp->Vortex__DOT__vx_forwarding__DOT__use_execute_PC_next
	       [0U] : vlTOPp->Vortex__DOT____Vcellinp__vx_forwarding__in_execute_alu_result
	       [0U]) : ((IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src1_mem_fwd)
			 ? ((3U == (IData)(vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__wb))
			     ? vlTOPp->Vortex__DOT__vx_forwarding__DOT__use_memory_PC_next
			    [0U] : ((2U == (IData)(vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__wb))
				     ? vlTOPp->Vortex__DOT____Vcellinp__vx_forwarding__in_memory_mem_data
				    [0U] : vlTOPp->Vortex__DOT____Vcellinp__vx_forwarding__in_memory_alu_result
				    [0U])) : ((IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src1_wb_fwd)
					       ? ((3U 
						   == (IData)(vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__wb))
						   ? 
						  vlTOPp->Vortex__DOT__vx_forwarding__DOT__use_writeback_PC_next
						  [0U]
						   : 
						  ((2U 
						    == (IData)(vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__wb))
						    ? 
						   vlTOPp->Vortex__DOT____Vcellinp__vx_forwarding__in_writeback_mem_data
						   [0U]
						    : 
						   vlTOPp->Vortex__DOT____Vcellinp__vx_forwarding__in_writeback_alu_result
						   [0U]))
					       : vlTOPp->Vortex__DOT____Vcellinp__vx_forwarding__in_execute_alu_result
					      [0U])));
    vlTOPp->Vortex__DOT__forwarding_src2_fwd_data[1U] 
	= vlTOPp->Vortex__DOT____Vcellout__vx_forwarding__out_src2_fwd_data
	[1U];
    vlTOPp->Vortex__DOT__forwarding_src2_fwd_data[0U] 
	= vlTOPp->Vortex__DOT____Vcellout__vx_forwarding__out_src2_fwd_data
	[0U];
    vlTOPp->Vortex__DOT__forwarding_src1_fwd_data[1U] 
	= vlTOPp->Vortex__DOT____Vcellout__vx_forwarding__out_src1_fwd_data
	[1U];
    vlTOPp->Vortex__DOT__forwarding_src1_fwd_data[0U] 
	= vlTOPp->Vortex__DOT____Vcellout__vx_forwarding__out_src1_fwd_data
	[0U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_decode__in_src2_fwd_data[1U] 
	= vlTOPp->Vortex__DOT__forwarding_src2_fwd_data
	[1U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_decode__in_src2_fwd_data[0U] 
	= vlTOPp->Vortex__DOT__forwarding_src2_fwd_data
	[0U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_decode__in_src1_fwd_data[1U] 
	= vlTOPp->Vortex__DOT__forwarding_src1_fwd_data
	[1U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_decode__in_src1_fwd_data[0U] 
	= vlTOPp->Vortex__DOT__forwarding_src1_fwd_data
	[0U];
    vlTOPp->Vortex__DOT____Vcellout__vx_decode__out_reg_data[1U] 
	= ((IData)(vlTOPp->Vortex__DOT__forwarding_src2_fwd)
	    ? vlTOPp->Vortex__DOT____Vcellinp__vx_decode__in_src2_fwd_data
	   [0U] : vlTOPp->Vortex__DOT__vx_decode__DOT__rd2_register
	   [0U]);
    vlTOPp->Vortex__DOT____Vcellout__vx_decode__out_reg_data[2U] 
	= ((IData)(vlTOPp->Vortex__DOT__forwarding_src2_fwd)
	    ? vlTOPp->Vortex__DOT____Vcellinp__vx_decode__in_src2_fwd_data
	   [1U] : vlTOPp->Vortex__DOT__vx_decode__DOT__rd2_register
	   [1U]);
    vlTOPp->Vortex__DOT____Vcellout__vx_decode__out_reg_data[0U] 
	= ((0x6fU == (0x7fU & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction))
	    ? vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__curr_PC
	    : ((IData)(vlTOPp->Vortex__DOT__forwarding_src1_fwd)
	        ? vlTOPp->Vortex__DOT____Vcellinp__vx_decode__in_src1_fwd_data
	       [0U] : vlTOPp->Vortex__DOT__vx_decode__DOT__rd1_register
	       [0U]));
    vlTOPp->Vortex__DOT____Vcellout__vx_decode__out_reg_data[1U] 
	= ((0x6fU == (0x7fU & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction))
	    ? vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__curr_PC
	    : ((IData)(vlTOPp->Vortex__DOT__forwarding_src1_fwd)
	        ? vlTOPp->Vortex__DOT____Vcellinp__vx_decode__in_src1_fwd_data
	       [1U] : vlTOPp->Vortex__DOT__vx_decode__DOT__rd1_register
	       [1U]));
    vlTOPp->Vortex__DOT__decode_reg_data[3U] = vlTOPp->Vortex__DOT____Vcellout__vx_decode__out_reg_data
	[3U];
    vlTOPp->Vortex__DOT__decode_reg_data[2U] = vlTOPp->Vortex__DOT____Vcellout__vx_decode__out_reg_data
	[2U];
    vlTOPp->Vortex__DOT__decode_reg_data[1U] = vlTOPp->Vortex__DOT____Vcellout__vx_decode__out_reg_data
	[1U];
    vlTOPp->Vortex__DOT__decode_reg_data[0U] = vlTOPp->Vortex__DOT____Vcellout__vx_decode__out_reg_data
	[0U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_d_e_reg__in_reg_data[3U] 
	= vlTOPp->Vortex__DOT__decode_reg_data[3U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_d_e_reg__in_reg_data[2U] 
	= vlTOPp->Vortex__DOT__decode_reg_data[2U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_d_e_reg__in_reg_data[1U] 
	= vlTOPp->Vortex__DOT__decode_reg_data[1U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_d_e_reg__in_reg_data[0U] 
	= vlTOPp->Vortex__DOT__decode_reg_data[0U];
}

VL_INLINE_OPT void VVortex::_combo__TOP__9(VVortex__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VVortex::_combo__TOP__9\n"); );
    VVortex* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->Vortex__DOT____Vcellout__vx_forwarding__out_src2_fwd_data[1U] 
	= ((IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src2_exe_fwd)
	    ? ((3U == (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__wb))
	        ? vlTOPp->Vortex__DOT__vx_forwarding__DOT__use_execute_PC_next
	       [1U] : vlTOPp->Vortex__DOT____Vcellinp__vx_forwarding__in_execute_alu_result
	       [1U]) : ((IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src2_mem_fwd)
			 ? ((3U == (IData)(vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__wb))
			     ? vlTOPp->Vortex__DOT__vx_forwarding__DOT__use_memory_PC_next
			    [1U] : ((2U == (IData)(vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__wb))
				     ? vlTOPp->Vortex__DOT____Vcellinp__vx_forwarding__in_memory_mem_data
				    [1U] : vlTOPp->Vortex__DOT____Vcellinp__vx_forwarding__in_memory_alu_result
				    [1U])) : ((IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src2_wb_fwd)
					       ? ((3U 
						   == (IData)(vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__wb))
						   ? 
						  vlTOPp->Vortex__DOT__vx_forwarding__DOT__use_writeback_PC_next
						  [1U]
						   : 
						  ((2U 
						    == (IData)(vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__wb))
						    ? 
						   vlTOPp->Vortex__DOT____Vcellinp__vx_forwarding__in_writeback_mem_data
						   [1U]
						    : 
						   vlTOPp->Vortex__DOT____Vcellinp__vx_forwarding__in_writeback_alu_result
						   [1U]))
					       : vlTOPp->Vortex__DOT____Vcellinp__vx_forwarding__in_execute_alu_result
					      [1U])));
    vlTOPp->Vortex__DOT____Vcellout__vx_forwarding__out_src2_fwd_data[0U] 
	= ((IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src2_exe_fwd)
	    ? ((3U == (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__wb))
	        ? vlTOPp->Vortex__DOT__vx_forwarding__DOT__use_execute_PC_next
	       [0U] : vlTOPp->Vortex__DOT____Vcellinp__vx_forwarding__in_execute_alu_result
	       [0U]) : ((IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src2_mem_fwd)
			 ? ((3U == (IData)(vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__wb))
			     ? vlTOPp->Vortex__DOT__vx_forwarding__DOT__use_memory_PC_next
			    [0U] : ((2U == (IData)(vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__wb))
				     ? vlTOPp->Vortex__DOT____Vcellinp__vx_forwarding__in_memory_mem_data
				    [0U] : vlTOPp->Vortex__DOT____Vcellinp__vx_forwarding__in_memory_alu_result
				    [0U])) : ((IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src2_wb_fwd)
					       ? ((3U 
						   == (IData)(vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__wb))
						   ? 
						  vlTOPp->Vortex__DOT__vx_forwarding__DOT__use_writeback_PC_next
						  [0U]
						   : 
						  ((2U 
						    == (IData)(vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__wb))
						    ? 
						   vlTOPp->Vortex__DOT____Vcellinp__vx_forwarding__in_writeback_mem_data
						   [0U]
						    : 
						   vlTOPp->Vortex__DOT____Vcellinp__vx_forwarding__in_writeback_alu_result
						   [0U]))
					       : vlTOPp->Vortex__DOT____Vcellinp__vx_forwarding__in_execute_alu_result
					      [0U])));
    vlTOPp->Vortex__DOT____Vcellout__vx_forwarding__out_src1_fwd_data[1U] 
	= ((IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src1_exe_fwd)
	    ? ((3U == (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__wb))
	        ? vlTOPp->Vortex__DOT__vx_forwarding__DOT__use_execute_PC_next
	       [1U] : vlTOPp->Vortex__DOT____Vcellinp__vx_forwarding__in_execute_alu_result
	       [1U]) : ((IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src1_mem_fwd)
			 ? ((3U == (IData)(vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__wb))
			     ? vlTOPp->Vortex__DOT__vx_forwarding__DOT__use_memory_PC_next
			    [1U] : ((2U == (IData)(vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__wb))
				     ? vlTOPp->Vortex__DOT____Vcellinp__vx_forwarding__in_memory_mem_data
				    [1U] : vlTOPp->Vortex__DOT____Vcellinp__vx_forwarding__in_memory_alu_result
				    [1U])) : ((IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src1_wb_fwd)
					       ? ((3U 
						   == (IData)(vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__wb))
						   ? 
						  vlTOPp->Vortex__DOT__vx_forwarding__DOT__use_writeback_PC_next
						  [1U]
						   : 
						  ((2U 
						    == (IData)(vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__wb))
						    ? 
						   vlTOPp->Vortex__DOT____Vcellinp__vx_forwarding__in_writeback_mem_data
						   [1U]
						    : 
						   vlTOPp->Vortex__DOT____Vcellinp__vx_forwarding__in_writeback_alu_result
						   [1U]))
					       : vlTOPp->Vortex__DOT____Vcellinp__vx_forwarding__in_execute_alu_result
					      [1U])));
    vlTOPp->Vortex__DOT____Vcellout__vx_forwarding__out_src1_fwd_data[0U] 
	= ((IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src1_exe_fwd)
	    ? ((3U == (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__wb))
	        ? vlTOPp->Vortex__DOT__vx_forwarding__DOT__use_execute_PC_next
	       [0U] : vlTOPp->Vortex__DOT____Vcellinp__vx_forwarding__in_execute_alu_result
	       [0U]) : ((IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src1_mem_fwd)
			 ? ((3U == (IData)(vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__wb))
			     ? vlTOPp->Vortex__DOT__vx_forwarding__DOT__use_memory_PC_next
			    [0U] : ((2U == (IData)(vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__wb))
				     ? vlTOPp->Vortex__DOT____Vcellinp__vx_forwarding__in_memory_mem_data
				    [0U] : vlTOPp->Vortex__DOT____Vcellinp__vx_forwarding__in_memory_alu_result
				    [0U])) : ((IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src1_wb_fwd)
					       ? ((3U 
						   == (IData)(vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__wb))
						   ? 
						  vlTOPp->Vortex__DOT__vx_forwarding__DOT__use_writeback_PC_next
						  [0U]
						   : 
						  ((2U 
						    == (IData)(vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__wb))
						    ? 
						   vlTOPp->Vortex__DOT____Vcellinp__vx_forwarding__in_writeback_mem_data
						   [0U]
						    : 
						   vlTOPp->Vortex__DOT____Vcellinp__vx_forwarding__in_writeback_alu_result
						   [0U]))
					       : vlTOPp->Vortex__DOT____Vcellinp__vx_forwarding__in_execute_alu_result
					      [0U])));
    vlTOPp->Vortex__DOT__forwarding_src2_fwd_data[1U] 
	= vlTOPp->Vortex__DOT____Vcellout__vx_forwarding__out_src2_fwd_data
	[1U];
    vlTOPp->Vortex__DOT__forwarding_src2_fwd_data[0U] 
	= vlTOPp->Vortex__DOT____Vcellout__vx_forwarding__out_src2_fwd_data
	[0U];
    vlTOPp->Vortex__DOT__forwarding_src1_fwd_data[1U] 
	= vlTOPp->Vortex__DOT____Vcellout__vx_forwarding__out_src1_fwd_data
	[1U];
    vlTOPp->Vortex__DOT__forwarding_src1_fwd_data[0U] 
	= vlTOPp->Vortex__DOT____Vcellout__vx_forwarding__out_src1_fwd_data
	[0U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_decode__in_src2_fwd_data[1U] 
	= vlTOPp->Vortex__DOT__forwarding_src2_fwd_data
	[1U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_decode__in_src2_fwd_data[0U] 
	= vlTOPp->Vortex__DOT__forwarding_src2_fwd_data
	[0U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_decode__in_src1_fwd_data[1U] 
	= vlTOPp->Vortex__DOT__forwarding_src1_fwd_data
	[1U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_decode__in_src1_fwd_data[0U] 
	= vlTOPp->Vortex__DOT__forwarding_src1_fwd_data
	[0U];
    vlTOPp->Vortex__DOT____Vcellout__vx_decode__out_reg_data[1U] 
	= ((IData)(vlTOPp->Vortex__DOT__forwarding_src2_fwd)
	    ? vlTOPp->Vortex__DOT____Vcellinp__vx_decode__in_src2_fwd_data
	   [0U] : vlTOPp->Vortex__DOT__vx_decode__DOT__rd2_register
	   [0U]);
    vlTOPp->Vortex__DOT____Vcellout__vx_decode__out_reg_data[2U] 
	= ((IData)(vlTOPp->Vortex__DOT__forwarding_src2_fwd)
	    ? vlTOPp->Vortex__DOT____Vcellinp__vx_decode__in_src2_fwd_data
	   [1U] : vlTOPp->Vortex__DOT__vx_decode__DOT__rd2_register
	   [1U]);
    vlTOPp->Vortex__DOT____Vcellout__vx_decode__out_reg_data[0U] 
	= ((0x6fU == (0x7fU & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction))
	    ? vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__curr_PC
	    : ((IData)(vlTOPp->Vortex__DOT__forwarding_src1_fwd)
	        ? vlTOPp->Vortex__DOT____Vcellinp__vx_decode__in_src1_fwd_data
	       [0U] : vlTOPp->Vortex__DOT__vx_decode__DOT__rd1_register
	       [0U]));
    vlTOPp->Vortex__DOT____Vcellout__vx_decode__out_reg_data[1U] 
	= ((0x6fU == (0x7fU & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction))
	    ? vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__curr_PC
	    : ((IData)(vlTOPp->Vortex__DOT__forwarding_src1_fwd)
	        ? vlTOPp->Vortex__DOT____Vcellinp__vx_decode__in_src1_fwd_data
	       [1U] : vlTOPp->Vortex__DOT__vx_decode__DOT__rd1_register
	       [1U]));
    vlTOPp->Vortex__DOT__decode_reg_data[3U] = vlTOPp->Vortex__DOT____Vcellout__vx_decode__out_reg_data
	[3U];
    vlTOPp->Vortex__DOT__decode_reg_data[2U] = vlTOPp->Vortex__DOT____Vcellout__vx_decode__out_reg_data
	[2U];
    vlTOPp->Vortex__DOT__decode_reg_data[1U] = vlTOPp->Vortex__DOT____Vcellout__vx_decode__out_reg_data
	[1U];
    vlTOPp->Vortex__DOT__decode_reg_data[0U] = vlTOPp->Vortex__DOT____Vcellout__vx_decode__out_reg_data
	[0U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_d_e_reg__in_reg_data[3U] 
	= vlTOPp->Vortex__DOT__decode_reg_data[3U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_d_e_reg__in_reg_data[2U] 
	= vlTOPp->Vortex__DOT__decode_reg_data[2U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_d_e_reg__in_reg_data[1U] 
	= vlTOPp->Vortex__DOT__decode_reg_data[1U];
    vlTOPp->Vortex__DOT____Vcellinp__vx_d_e_reg__in_reg_data[0U] 
	= vlTOPp->Vortex__DOT__decode_reg_data[0U];
}

void VVortex::_eval(VVortex__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VVortex::_eval\n"); );
    VVortex* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
	 | ((IData)(vlTOPp->reset) & (~ (IData)(vlTOPp->__Vclklast__TOP__reset))))) {
	vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
	vlTOPp->_sequent__TOP__2(vlSymsp);
    }
    vlTOPp->_combo__TOP__3(vlSymsp);
    if (((~ (IData)(vlTOPp->clk)) & (IData)(vlTOPp->__Vclklast__TOP__clk))) {
	vlTOPp->_sequent__TOP__5(vlSymsp);
    }
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
	 | ((IData)(vlTOPp->reset) & (~ (IData)(vlTOPp->__Vclklast__TOP__reset))))) {
	vlTOPp->_sequent__TOP__7(vlSymsp);
    }
    vlTOPp->_combo__TOP__9(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__reset = vlTOPp->reset;
}

void VVortex::_eval_initial(VVortex__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VVortex::_eval_initial\n"); );
    VVortex* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__reset = vlTOPp->reset;
    vlTOPp->_initial__TOP__6(vlSymsp);
}

void VVortex::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VVortex::final\n"); );
    // Variables
    VVortex__Syms* __restrict vlSymsp = this->__VlSymsp;
    VVortex* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VVortex::_eval_settle(VVortex__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VVortex::_eval_settle\n"); );
    VVortex* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__4(vlSymsp);
    vlTOPp->_settle__TOP__8(vlSymsp);
}

VL_INLINE_OPT QData VVortex::_change_request(VVortex__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VVortex::_change_request\n"); );
    VVortex* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VVortex::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VVortex::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
	Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
	Verilated::overWidthError("reset");}
}
#endif // VL_DEBUG

void VVortex::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VVortex::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    fe_instruction = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    in_cache_driver_out_data[__Vi0] = VL_RAND_RESET_I(32);
    }}
    curr_PC = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    out_cache_driver_in_address[__Vi0] = VL_RAND_RESET_I(32);
    }}
    out_cache_driver_in_mem_read = VL_RAND_RESET_I(3);
    out_cache_driver_in_mem_write = VL_RAND_RESET_I(3);
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    out_cache_driver_in_valid[__Vi0] = VL_RAND_RESET_I(1);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    out_cache_driver_in_data[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    Vortex__DOT__fetch_valid[__Vi0] = VL_RAND_RESET_I(1);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    Vortex__DOT__f_d_valid[__Vi0] = VL_RAND_RESET_I(1);
    }}
    Vortex__DOT__decode_csr_address = VL_RAND_RESET_I(12);
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
	    Vortex__DOT__decode_reg_data[__Vi0] = VL_RAND_RESET_I(32);
    }}
    Vortex__DOT__decode_itype_immed = VL_RAND_RESET_I(32);
    Vortex__DOT__decode_branch_type = VL_RAND_RESET_I(3);
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    Vortex__DOT__decode_valid[__Vi0] = VL_RAND_RESET_I(1);
    }}
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
	    Vortex__DOT__d_e_reg_data[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    Vortex__DOT__d_e_valid[__Vi0] = VL_RAND_RESET_I(1);
    }}
    Vortex__DOT__execute_branch_stall = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    Vortex__DOT__execute_alu_result[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
	    Vortex__DOT__execute_reg_data[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    Vortex__DOT__execute_valid[__Vi0] = VL_RAND_RESET_I(1);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    Vortex__DOT__e_m_alu_result[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
	    Vortex__DOT__e_m_reg_data[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    Vortex__DOT__e_m_valid[__Vi0] = VL_RAND_RESET_I(1);
    }}
    Vortex__DOT__memory_branch_dir = VL_RAND_RESET_I(1);
    Vortex__DOT__memory_branch_dest = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    Vortex__DOT__memory_alu_result[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    Vortex__DOT__memory_mem_result[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    Vortex__DOT__memory_valid[__Vi0] = VL_RAND_RESET_I(1);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    Vortex__DOT__m_w_alu_result[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    Vortex__DOT__m_w_mem_result[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    Vortex__DOT__m_w_valid[__Vi0] = VL_RAND_RESET_I(1);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    Vortex__DOT__writeback_write_data[__Vi0] = VL_RAND_RESET_I(32);
    }}
    Vortex__DOT__csr_decode_csr_data = VL_RAND_RESET_I(32);
    Vortex__DOT__forwarding_fwd_stall = VL_RAND_RESET_I(1);
    Vortex__DOT__forwarding_src1_fwd = VL_RAND_RESET_I(1);
    Vortex__DOT__forwarding_src2_fwd = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    Vortex__DOT__forwarding_src1_fwd_data[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    Vortex__DOT__forwarding_src2_fwd_data[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    Vortex__DOT____Vcellout__vx_fetch__out_valid[__Vi0] = VL_RAND_RESET_I(1);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    Vortex__DOT____Vcellout__vx_f_d_reg__out_valid[__Vi0] = VL_RAND_RESET_I(1);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    Vortex__DOT____Vcellinp__vx_f_d_reg__in_valid[__Vi0] = VL_RAND_RESET_I(1);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    Vortex__DOT____Vcellout__vx_decode__out_valid[__Vi0] = VL_RAND_RESET_I(1);
    }}
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
	    Vortex__DOT____Vcellout__vx_decode__out_reg_data[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    Vortex__DOT____Vcellinp__vx_decode__in_src2_fwd_data[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    Vortex__DOT____Vcellinp__vx_decode__in_src1_fwd_data[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    Vortex__DOT____Vcellinp__vx_decode__in_wb_valid[__Vi0] = VL_RAND_RESET_I(1);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    Vortex__DOT____Vcellinp__vx_decode__in_write_data[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    Vortex__DOT____Vcellinp__vx_decode__in_valid[__Vi0] = VL_RAND_RESET_I(1);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    Vortex__DOT____Vcellout__vx_d_e_reg__out_valid[__Vi0] = VL_RAND_RESET_I(1);
    }}
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
	    Vortex__DOT____Vcellout__vx_d_e_reg__out_reg_data[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    Vortex__DOT____Vcellinp__vx_d_e_reg__in_valid[__Vi0] = VL_RAND_RESET_I(1);
    }}
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
	    Vortex__DOT____Vcellinp__vx_d_e_reg__in_reg_data[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    Vortex__DOT____Vcellout__vx_execute__out_valid[__Vi0] = VL_RAND_RESET_I(1);
    }}
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
	    Vortex__DOT____Vcellout__vx_execute__out_reg_data[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    Vortex__DOT____Vcellout__vx_execute__out_alu_result[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    Vortex__DOT____Vcellinp__vx_execute__in_valid[__Vi0] = VL_RAND_RESET_I(1);
    }}
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
	    Vortex__DOT____Vcellinp__vx_execute__in_reg_data[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    Vortex__DOT____Vcellout__vx_e_m_reg__out_valid[__Vi0] = VL_RAND_RESET_I(1);
    }}
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
	    Vortex__DOT____Vcellout__vx_e_m_reg__out_reg_data[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    Vortex__DOT____Vcellout__vx_e_m_reg__out_alu_result[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    Vortex__DOT____Vcellinp__vx_e_m_reg__in_valid[__Vi0] = VL_RAND_RESET_I(1);
    }}
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
	    Vortex__DOT____Vcellinp__vx_e_m_reg__in_reg_data[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    Vortex__DOT____Vcellinp__vx_e_m_reg__in_alu_result[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    Vortex__DOT__use_rd2[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    Vortex__DOT____Vcellout__vx_memory__out_cache_driver_in_valid[__Vi0] = VL_RAND_RESET_I(1);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    Vortex__DOT____Vcellout__vx_memory__out_cache_driver_in_data[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    Vortex__DOT____Vcellout__vx_memory__out_cache_driver_in_address[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    Vortex__DOT____Vcellout__vx_memory__out_valid[__Vi0] = VL_RAND_RESET_I(1);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    Vortex__DOT____Vcellout__vx_memory__out_mem_result[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    Vortex__DOT____Vcellout__vx_memory__out_alu_result[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    Vortex__DOT____Vcellinp__vx_memory__in_cache_driver_out_data[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    Vortex__DOT____Vcellinp__vx_memory__in_valid[__Vi0] = VL_RAND_RESET_I(1);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    Vortex__DOT____Vcellinp__vx_memory__in_rd2[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    Vortex__DOT____Vcellinp__vx_memory__in_alu_result[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    Vortex__DOT____Vcellout__vx_m_w_reg__out_valid[__Vi0] = VL_RAND_RESET_I(1);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    Vortex__DOT____Vcellout__vx_m_w_reg__out_mem_result[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    Vortex__DOT____Vcellout__vx_m_w_reg__out_alu_result[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    Vortex__DOT____Vcellinp__vx_m_w_reg__in_valid[__Vi0] = VL_RAND_RESET_I(1);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    Vortex__DOT____Vcellinp__vx_m_w_reg__in_mem_result[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    Vortex__DOT____Vcellinp__vx_m_w_reg__in_alu_result[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    Vortex__DOT____Vcellout__vx_writeback__out_write_data[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    Vortex__DOT____Vcellinp__vx_writeback__in_mem_result[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    Vortex__DOT____Vcellinp__vx_writeback__in_alu_result[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    Vortex__DOT____Vcellout__vx_forwarding__out_src2_fwd_data[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    Vortex__DOT____Vcellout__vx_forwarding__out_src1_fwd_data[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    Vortex__DOT____Vcellinp__vx_forwarding__in_writeback_mem_data[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    Vortex__DOT____Vcellinp__vx_forwarding__in_writeback_alu_result[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    Vortex__DOT____Vcellinp__vx_forwarding__in_memory_mem_data[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    Vortex__DOT____Vcellinp__vx_forwarding__in_memory_alu_result[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    Vortex__DOT____Vcellinp__vx_forwarding__in_execute_alu_result[__Vi0] = VL_RAND_RESET_I(32);
    }}
    Vortex__DOT__vx_fetch__DOT__stall_reg = VL_RAND_RESET_I(1);
    Vortex__DOT__vx_fetch__DOT__delay_reg = VL_RAND_RESET_I(1);
    Vortex__DOT__vx_fetch__DOT__old = VL_RAND_RESET_I(32);
    Vortex__DOT__vx_fetch__DOT__state = VL_RAND_RESET_I(5);
    Vortex__DOT__vx_fetch__DOT__real_PC = VL_RAND_RESET_I(32);
    Vortex__DOT__vx_fetch__DOT__JAL_reg = VL_RAND_RESET_I(32);
    Vortex__DOT__vx_fetch__DOT__BR_reg = VL_RAND_RESET_I(32);
    Vortex__DOT__vx_fetch__DOT__prev_debug = VL_RAND_RESET_I(1);
    Vortex__DOT__vx_fetch__DOT__PC_to_use = VL_RAND_RESET_I(32);
    Vortex__DOT__vx_fetch__DOT__stall = VL_RAND_RESET_I(1);
    Vortex__DOT__vx_fetch__DOT__temp_PC = VL_RAND_RESET_I(32);
    Vortex__DOT__vx_fetch__DOT__valid = VL_RAND_RESET_I(2);
    Vortex__DOT__vx_f_d_reg__DOT__instruction = VL_RAND_RESET_I(32);
    Vortex__DOT__vx_f_d_reg__DOT__curr_PC = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    Vortex__DOT__vx_f_d_reg__DOT__valid[__Vi0] = VL_RAND_RESET_I(1);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    Vortex__DOT__vx_decode__DOT__rd1_register[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    Vortex__DOT__vx_decode__DOT__rd2_register[__Vi0] = VL_RAND_RESET_I(32);
    }}
    Vortex__DOT__vx_decode__DOT__is_itype = VL_RAND_RESET_I(1);
    Vortex__DOT__vx_decode__DOT__is_csr = VL_RAND_RESET_I(1);
    Vortex__DOT__vx_decode__DOT__alu_tempp = VL_RAND_RESET_I(12);
    Vortex__DOT__vx_decode__DOT__mul_alu = VL_RAND_RESET_I(5);
    Vortex__DOT__vx_decode__DOT__temp_final_alu = VL_RAND_RESET_I(5);
    Vortex__DOT__vx_decode__DOT____Vcellout__gen_code_label__BRA__0__KET____DOT__vx_register_file__out_src2_data = VL_RAND_RESET_I(32);
    Vortex__DOT__vx_decode__DOT____Vcellout__gen_code_label__BRA__0__KET____DOT__vx_register_file__out_src1_data = VL_RAND_RESET_I(32);
    Vortex__DOT__vx_decode__DOT____Vcellout__gen_code_label__BRA__1__KET____DOT__vx_register_file__out_src2_data = VL_RAND_RESET_I(32);
    Vortex__DOT__vx_decode__DOT____Vcellout__gen_code_label__BRA__1__KET____DOT__vx_register_file__out_src1_data = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<32; ++__Vi0) {
	    Vortex__DOT__vx_decode__DOT__gen_code_label__BRA__0__KET____DOT__vx_register_file__DOT__registers[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<32; ++__Vi0) {
	    Vortex__DOT__vx_decode__DOT__gen_code_label__BRA__1__KET____DOT__vx_register_file__DOT__registers[__Vi0] = VL_RAND_RESET_I(32);
    }}
    Vortex__DOT__vx_d_e_reg__DOT__rd = VL_RAND_RESET_I(5);
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
	    Vortex__DOT__vx_d_e_reg__DOT__reg_data[__Vi0] = VL_RAND_RESET_I(32);
    }}
    Vortex__DOT__vx_d_e_reg__DOT__alu_op = VL_RAND_RESET_I(5);
    Vortex__DOT__vx_d_e_reg__DOT__wb = VL_RAND_RESET_I(2);
    Vortex__DOT__vx_d_e_reg__DOT__PC_next_out = VL_RAND_RESET_I(32);
    Vortex__DOT__vx_d_e_reg__DOT__rs2_src = VL_RAND_RESET_I(1);
    Vortex__DOT__vx_d_e_reg__DOT__itype_immed = VL_RAND_RESET_I(32);
    Vortex__DOT__vx_d_e_reg__DOT__mem_read = VL_RAND_RESET_I(3);
    Vortex__DOT__vx_d_e_reg__DOT__mem_write = VL_RAND_RESET_I(3);
    Vortex__DOT__vx_d_e_reg__DOT__branch_type = VL_RAND_RESET_I(3);
    Vortex__DOT__vx_d_e_reg__DOT__upper_immed = VL_RAND_RESET_I(20);
    Vortex__DOT__vx_d_e_reg__DOT__csr_address = VL_RAND_RESET_I(12);
    Vortex__DOT__vx_d_e_reg__DOT__is_csr = VL_RAND_RESET_I(1);
    Vortex__DOT__vx_d_e_reg__DOT__csr_mask = VL_RAND_RESET_I(32);
    Vortex__DOT__vx_d_e_reg__DOT__curr_PC = VL_RAND_RESET_I(32);
    Vortex__DOT__vx_d_e_reg__DOT__jal = VL_RAND_RESET_I(1);
    Vortex__DOT__vx_d_e_reg__DOT__jal_offset = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    Vortex__DOT__vx_d_e_reg__DOT__valid[__Vi0] = VL_RAND_RESET_I(1);
    }}
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
	    Vortex__DOT__vx_d_e_reg__DOT__reg_data_z[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    Vortex__DOT__vx_d_e_reg__DOT__valid_z[__Vi0] = VL_RAND_RESET_I(1);
    }}
    Vortex__DOT__vx_d_e_reg__DOT__stalling = VL_RAND_RESET_I(1);
    Vortex__DOT__vx_execute__DOT____Vcellout__gen_code_label__BRA__0__KET____DOT__vx_alu__out_alu_result = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__0__KET____DOT__vx_alu__in_reg_data[__Vi0] = VL_RAND_RESET_I(32);
    }}
    Vortex__DOT__vx_execute__DOT____Vcellout__gen_code_label__BRA__2__KET____DOT__vx_alu__out_alu_result = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    Vortex__DOT__vx_execute__DOT____Vcellinp__gen_code_label__BRA__2__KET____DOT__vx_alu__in_reg_data[__Vi0] = VL_RAND_RESET_I(32);
    }}
    Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__0__KET____DOT__vx_alu__DOT__ALU_in2 = VL_RAND_RESET_I(32);
    Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__0__KET____DOT__vx_alu__DOT__mult_signed_result = VL_RAND_RESET_Q(64);
    Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__2__KET____DOT__vx_alu__DOT__ALU_in2 = VL_RAND_RESET_I(32);
    Vortex__DOT__vx_execute__DOT__gen_code_label__BRA__2__KET____DOT__vx_alu__DOT__mult_signed_result = VL_RAND_RESET_Q(64);
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    Vortex__DOT__vx_e_m_reg__DOT__alu_result[__Vi0] = VL_RAND_RESET_I(32);
    }}
    Vortex__DOT__vx_e_m_reg__DOT__rd = VL_RAND_RESET_I(5);
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
	    Vortex__DOT__vx_e_m_reg__DOT__reg_data[__Vi0] = VL_RAND_RESET_I(32);
    }}
    Vortex__DOT__vx_e_m_reg__DOT__wb = VL_RAND_RESET_I(2);
    Vortex__DOT__vx_e_m_reg__DOT__PC_next = VL_RAND_RESET_I(32);
    Vortex__DOT__vx_e_m_reg__DOT__mem_read = VL_RAND_RESET_I(3);
    Vortex__DOT__vx_e_m_reg__DOT__mem_write = VL_RAND_RESET_I(3);
    Vortex__DOT__vx_e_m_reg__DOT__csr_address = VL_RAND_RESET_I(12);
    Vortex__DOT__vx_e_m_reg__DOT__is_csr = VL_RAND_RESET_I(1);
    Vortex__DOT__vx_e_m_reg__DOT__csr_result = VL_RAND_RESET_I(32);
    Vortex__DOT__vx_e_m_reg__DOT__curr_PC = VL_RAND_RESET_I(32);
    Vortex__DOT__vx_e_m_reg__DOT__branch_offset = VL_RAND_RESET_I(32);
    Vortex__DOT__vx_e_m_reg__DOT__branch_type = VL_RAND_RESET_I(3);
    Vortex__DOT__vx_e_m_reg__DOT__jal = VL_RAND_RESET_I(1);
    Vortex__DOT__vx_e_m_reg__DOT__jal_dest = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    Vortex__DOT__vx_e_m_reg__DOT__valid[__Vi0] = VL_RAND_RESET_I(1);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    Vortex__DOT__vx_m_w_reg__DOT__alu_result[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    Vortex__DOT__vx_m_w_reg__DOT__mem_result[__Vi0] = VL_RAND_RESET_I(32);
    }}
    Vortex__DOT__vx_m_w_reg__DOT__rd = VL_RAND_RESET_I(5);
    Vortex__DOT__vx_m_w_reg__DOT__wb = VL_RAND_RESET_I(2);
    Vortex__DOT__vx_m_w_reg__DOT__PC_next = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    Vortex__DOT__vx_m_w_reg__DOT__valid[__Vi0] = VL_RAND_RESET_I(1);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    Vortex__DOT__vx_writeback__DOT__out_pc_data[__Vi0] = VL_RAND_RESET_I(32);
    }}
    Vortex__DOT__vx_forwarding__DOT__src1_exe_fwd = VL_RAND_RESET_I(1);
    Vortex__DOT__vx_forwarding__DOT__src1_mem_fwd = VL_RAND_RESET_I(1);
    Vortex__DOT__vx_forwarding__DOT__src1_wb_fwd = VL_RAND_RESET_I(1);
    Vortex__DOT__vx_forwarding__DOT__src2_exe_fwd = VL_RAND_RESET_I(1);
    Vortex__DOT__vx_forwarding__DOT__src2_mem_fwd = VL_RAND_RESET_I(1);
    Vortex__DOT__vx_forwarding__DOT__src2_wb_fwd = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    Vortex__DOT__vx_forwarding__DOT__use_execute_PC_next[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    Vortex__DOT__vx_forwarding__DOT__use_memory_PC_next[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    Vortex__DOT__vx_forwarding__DOT__use_writeback_PC_next[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<4096; ++__Vi0) {
	    Vortex__DOT__vx_csr_handler__DOT__csr[__Vi0] = VL_RAND_RESET_I(12);
    }}
    Vortex__DOT__vx_csr_handler__DOT__cycle = VL_RAND_RESET_Q(64);
    Vortex__DOT__vx_csr_handler__DOT__instret = VL_RAND_RESET_Q(64);
    Vortex__DOT__vx_csr_handler__DOT__decode_csr_address = VL_RAND_RESET_I(12);
    __Vtableidx1 = VL_RAND_RESET_I(3);
    __Vtable1_Vortex__DOT__vx_decode__DOT__mul_alu[0] = 0x10U;
    __Vtable1_Vortex__DOT__vx_decode__DOT__mul_alu[1] = 0x11U;
    __Vtable1_Vortex__DOT__vx_decode__DOT__mul_alu[2] = 0x12U;
    __Vtable1_Vortex__DOT__vx_decode__DOT__mul_alu[3] = 0x13U;
    __Vtable1_Vortex__DOT__vx_decode__DOT__mul_alu[4] = 0x14U;
    __Vtable1_Vortex__DOT__vx_decode__DOT__mul_alu[5] = 0x15U;
    __Vtable1_Vortex__DOT__vx_decode__DOT__mul_alu[6] = 0x16U;
    __Vtable1_Vortex__DOT__vx_decode__DOT__mul_alu[7] = 0x17U;
}
