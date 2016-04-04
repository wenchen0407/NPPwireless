/* Include files */

#include <stddef.h>
#include "blas.h"
#include "SmAHTR_r1_PITTRTNUKE_sfun.h"
#include "c9_SmAHTR_r1_PITTRTNUKE.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "SmAHTR_r1_PITTRTNUKE_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c9_debug_family_names[24] = { "eta_C", "eta_T", "r",
  "cpCO2Turbine", "cpCO2Compressor", "tau_t", "Pt", "Pc", "u", "A", "B", "C",
  "D", "nargin", "nargout", "Tc_i", "Tt_i", "mdot", "constants", "x", "y",
  "Tt_o", "Tc_o", "xdot" };

/* Function Declarations */
static void initialize_c9_SmAHTR_r1_PITTRTNUKE
  (SFc9_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance);
static void initialize_params_c9_SmAHTR_r1_PITTRTNUKE
  (SFc9_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance);
static void enable_c9_SmAHTR_r1_PITTRTNUKE
  (SFc9_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance);
static void disable_c9_SmAHTR_r1_PITTRTNUKE
  (SFc9_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance);
static void c9_update_debugger_state_c9_SmAHTR_r1_PITTRTNUKE
  (SFc9_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c9_SmAHTR_r1_PITTRTNUKE
  (SFc9_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance);
static void set_sim_state_c9_SmAHTR_r1_PITTRTNUKE
  (SFc9_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance, const mxArray *c9_st);
static void finalize_c9_SmAHTR_r1_PITTRTNUKE
  (SFc9_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance);
static void sf_gateway_c9_SmAHTR_r1_PITTRTNUKE
  (SFc9_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance);
static void initSimStructsc9_SmAHTR_r1_PITTRTNUKE
  (SFc9_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c9_machineNumber, uint32_T
  c9_chartNumber, uint32_T c9_instanceNumber);
static const mxArray *c9_sf_marshallOut(void *chartInstanceVoid, void *c9_inData);
static real_T c9_emlrt_marshallIn(SFc9_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c9_xdot, const char_T *c9_identifier);
static real_T c9_b_emlrt_marshallIn(SFc9_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_b_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static void c9_info_helper(const mxArray **c9_info);
static const mxArray *c9_emlrt_marshallOut(const char * c9_u);
static const mxArray *c9_b_emlrt_marshallOut(const uint32_T c9_u);
static const mxArray *c9_c_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static int32_T c9_c_emlrt_marshallIn(SFc9_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static uint8_T c9_d_emlrt_marshallIn(SFc9_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c9_b_is_active_c9_SmAHTR_r1_PITTRTNUKE, const
  char_T *c9_identifier);
static uint8_T c9_e_emlrt_marshallIn(SFc9_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void init_dsm_address_info(SFc9_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c9_SmAHTR_r1_PITTRTNUKE
  (SFc9_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance)
{
  chartInstance->c9_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c9_is_active_c9_SmAHTR_r1_PITTRTNUKE = 0U;
}

static void initialize_params_c9_SmAHTR_r1_PITTRTNUKE
  (SFc9_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c9_SmAHTR_r1_PITTRTNUKE
  (SFc9_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c9_SmAHTR_r1_PITTRTNUKE
  (SFc9_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c9_update_debugger_state_c9_SmAHTR_r1_PITTRTNUKE
  (SFc9_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c9_SmAHTR_r1_PITTRTNUKE
  (SFc9_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance)
{
  const mxArray *c9_st;
  const mxArray *c9_y = NULL;
  real_T c9_hoistedGlobal;
  real_T c9_u;
  const mxArray *c9_b_y = NULL;
  real_T c9_b_hoistedGlobal;
  real_T c9_b_u;
  const mxArray *c9_c_y = NULL;
  real_T c9_c_hoistedGlobal;
  real_T c9_c_u;
  const mxArray *c9_d_y = NULL;
  real_T c9_d_hoistedGlobal;
  real_T c9_d_u;
  const mxArray *c9_e_y = NULL;
  uint8_T c9_e_hoistedGlobal;
  uint8_T c9_e_u;
  const mxArray *c9_f_y = NULL;
  real_T *c9_Tc_o;
  real_T *c9_Tt_o;
  real_T *c9_xdot;
  real_T *c9_g_y;
  c9_xdot = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c9_Tc_o = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c9_Tt_o = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c9_g_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c9_st = NULL;
  c9_st = NULL;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_createcellmatrix(5, 1), false);
  c9_hoistedGlobal = *c9_Tc_o;
  c9_u = c9_hoistedGlobal;
  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", &c9_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 0, c9_b_y);
  c9_b_hoistedGlobal = *c9_Tt_o;
  c9_b_u = c9_b_hoistedGlobal;
  c9_c_y = NULL;
  sf_mex_assign(&c9_c_y, sf_mex_create("y", &c9_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 1, c9_c_y);
  c9_c_hoistedGlobal = *c9_xdot;
  c9_c_u = c9_c_hoistedGlobal;
  c9_d_y = NULL;
  sf_mex_assign(&c9_d_y, sf_mex_create("y", &c9_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 2, c9_d_y);
  c9_d_hoistedGlobal = *c9_g_y;
  c9_d_u = c9_d_hoistedGlobal;
  c9_e_y = NULL;
  sf_mex_assign(&c9_e_y, sf_mex_create("y", &c9_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 3, c9_e_y);
  c9_e_hoistedGlobal = chartInstance->c9_is_active_c9_SmAHTR_r1_PITTRTNUKE;
  c9_e_u = c9_e_hoistedGlobal;
  c9_f_y = NULL;
  sf_mex_assign(&c9_f_y, sf_mex_create("y", &c9_e_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 4, c9_f_y);
  sf_mex_assign(&c9_st, c9_y, false);
  return c9_st;
}

static void set_sim_state_c9_SmAHTR_r1_PITTRTNUKE
  (SFc9_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance, const mxArray *c9_st)
{
  const mxArray *c9_u;
  real_T *c9_Tc_o;
  real_T *c9_Tt_o;
  real_T *c9_xdot;
  real_T *c9_y;
  c9_xdot = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c9_Tc_o = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c9_Tt_o = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c9_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c9_doneDoubleBufferReInit = true;
  c9_u = sf_mex_dup(c9_st);
  *c9_Tc_o = c9_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_u,
    0)), "Tc_o");
  *c9_Tt_o = c9_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_u,
    1)), "Tt_o");
  *c9_xdot = c9_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_u,
    2)), "xdot");
  *c9_y = c9_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 3)),
    "y");
  chartInstance->c9_is_active_c9_SmAHTR_r1_PITTRTNUKE = c9_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 4)),
     "is_active_c9_SmAHTR_r1_PITTRTNUKE");
  sf_mex_destroy(&c9_u);
  c9_update_debugger_state_c9_SmAHTR_r1_PITTRTNUKE(chartInstance);
  sf_mex_destroy(&c9_st);
}

static void finalize_c9_SmAHTR_r1_PITTRTNUKE
  (SFc9_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c9_SmAHTR_r1_PITTRTNUKE
  (SFc9_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance)
{
  real_T c9_hoistedGlobal;
  real_T c9_b_hoistedGlobal;
  real_T c9_c_hoistedGlobal;
  real_T c9_d_hoistedGlobal;
  real_T c9_Tc_i;
  real_T c9_Tt_i;
  real_T c9_mdot;
  int32_T c9_i0;
  real_T c9_constants[7];
  real_T c9_x;
  uint32_T c9_debug_family_var_map[24];
  real_T c9_eta_C;
  real_T c9_eta_T;
  real_T c9_r;
  real_T c9_cpCO2Turbine;
  real_T c9_cpCO2Compressor;
  real_T c9_tau_t;
  real_T c9_Pt;
  real_T c9_Pc;
  real_T c9_u;
  real_T c9_A;
  real_T c9_B;
  real_T c9_C;
  real_T c9_D;
  real_T c9_nargin = 5.0;
  real_T c9_nargout = 4.0;
  real_T c9_y;
  real_T c9_Tt_o;
  real_T c9_Tc_o;
  real_T c9_xdot;
  real_T c9_b_A;
  real_T c9_b_B;
  real_T c9_b_x;
  real_T c9_b_y;
  real_T c9_c_x;
  real_T c9_c_y;
  real_T c9_d_x;
  real_T c9_d_y;
  real_T c9_e_y;
  real_T c9_c_B;
  real_T c9_f_y;
  real_T c9_g_y;
  real_T c9_h_y;
  real_T c9_i_y;
  real_T c9_d_B;
  real_T c9_j_y;
  real_T c9_k_y;
  real_T c9_l_y;
  real_T c9_e_B;
  real_T c9_m_y;
  real_T c9_n_y;
  real_T c9_o_y;
  int32_T c9_i1;
  real_T *c9_b_xdot;
  real_T *c9_b_Tc_o;
  real_T *c9_b_Tt_o;
  real_T *c9_p_y;
  real_T *c9_e_x;
  real_T *c9_b_mdot;
  real_T *c9_b_Tt_i;
  real_T *c9_b_Tc_i;
  real_T (*c9_b_constants)[7];
  c9_e_x = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c9_b_constants = (real_T (*)[7])ssGetInputPortSignal(chartInstance->S, 3);
  c9_b_mdot = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c9_b_Tt_i = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c9_b_Tc_i = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c9_b_xdot = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c9_b_Tc_o = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c9_b_Tt_o = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c9_p_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 7U, chartInstance->c9_sfEvent);
  chartInstance->c9_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 7U, chartInstance->c9_sfEvent);
  c9_hoistedGlobal = *c9_b_Tc_i;
  c9_b_hoistedGlobal = *c9_b_Tt_i;
  c9_c_hoistedGlobal = *c9_b_mdot;
  c9_d_hoistedGlobal = *c9_e_x;
  c9_Tc_i = c9_hoistedGlobal;
  c9_Tt_i = c9_b_hoistedGlobal;
  c9_mdot = c9_c_hoistedGlobal;
  for (c9_i0 = 0; c9_i0 < 7; c9_i0++) {
    c9_constants[c9_i0] = (*c9_b_constants)[c9_i0];
  }

  c9_x = c9_d_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 24U, 24U, c9_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_eta_C, 0U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_eta_T, 1U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_r, 2U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_cpCO2Turbine, 3U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_cpCO2Compressor, 4U,
    c9_sf_marshallOut, c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_tau_t, 5U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_Pt, 6U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_Pc, 7U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_u, 8U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_A, 9U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_B, 10U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_C, 11U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_D, 12U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 13U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 14U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_Tc_i, 15U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_Tt_i, 16U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_mdot, 17U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_constants, 18U, c9_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_x, 19U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_y, 20U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_Tt_o, 21U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_Tc_o, 22U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_xdot, 23U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_eta_C = c9_constants[0];
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 9);
  c9_eta_T = c9_constants[1];
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 10);
  c9_r = c9_constants[2];
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 11);
  c9_cpCO2Turbine = c9_constants[3];
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 12);
  c9_cpCO2Compressor = c9_constants[4];
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 14);
  c9_tau_t = c9_constants[6];
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 16);
  c9_b_A = c9_r - 1.0;
  c9_b_B = c9_eta_C;
  c9_b_x = c9_b_A;
  c9_b_y = c9_b_B;
  c9_c_x = c9_b_x;
  c9_c_y = c9_b_y;
  c9_d_x = c9_c_x;
  c9_d_y = c9_c_y;
  c9_e_y = c9_d_x / c9_d_y;
  c9_Tc_o = (c9_Tc_i + 273.0) * (c9_e_y + 1.0) - 273.0;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 17);
  c9_c_B = c9_r;
  c9_f_y = c9_c_B;
  c9_g_y = c9_f_y;
  c9_h_y = c9_g_y;
  c9_i_y = 1.0 / c9_h_y;
  c9_Tt_o = (c9_Tt_i + 273.0) * (1.0 - c9_eta_T * (1.0 - c9_i_y)) - 273.0;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 19);
  c9_Pt = c9_mdot * c9_cpCO2Turbine * (c9_Tt_i - c9_Tt_o);
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 20);
  c9_Pc = c9_mdot * c9_cpCO2Compressor * (c9_Tc_o - c9_Tc_i);
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 22);
  c9_u = c9_Pt - c9_Pc;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 26);
  c9_d_B = c9_tau_t;
  c9_j_y = c9_d_B;
  c9_k_y = c9_j_y;
  c9_l_y = c9_k_y;
  c9_A = -1.0 / c9_l_y;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 27);
  c9_e_B = c9_tau_t;
  c9_m_y = c9_e_B;
  c9_n_y = c9_m_y;
  c9_o_y = c9_n_y;
  c9_B = 1.0 / c9_o_y;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 28);
  c9_C = 1.0;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 29);
  c9_D = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 32);
  c9_xdot = c9_A * c9_x + c9_B * c9_u;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 33);
  c9_y = c9_x + 0.0 * c9_u;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 36);
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, -36);
  _SFD_SYMBOL_SCOPE_POP();
  *c9_p_y = c9_y;
  *c9_b_Tt_o = c9_Tt_o;
  *c9_b_Tc_o = c9_Tc_o;
  *c9_b_xdot = c9_xdot;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c9_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_SmAHTR_r1_PITTRTNUKEMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*c9_p_y, 0U);
  _SFD_DATA_RANGE_CHECK(*c9_b_Tt_o, 1U);
  _SFD_DATA_RANGE_CHECK(*c9_b_Tc_o, 2U);
  _SFD_DATA_RANGE_CHECK(*c9_b_xdot, 3U);
  _SFD_DATA_RANGE_CHECK(*c9_b_Tc_i, 4U);
  _SFD_DATA_RANGE_CHECK(*c9_b_Tt_i, 5U);
  _SFD_DATA_RANGE_CHECK(*c9_b_mdot, 6U);
  for (c9_i1 = 0; c9_i1 < 7; c9_i1++) {
    _SFD_DATA_RANGE_CHECK((*c9_b_constants)[c9_i1], 7U);
  }

  _SFD_DATA_RANGE_CHECK(*c9_e_x, 8U);
}

static void initSimStructsc9_SmAHTR_r1_PITTRTNUKE
  (SFc9_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c9_machineNumber, uint32_T
  c9_chartNumber, uint32_T c9_instanceNumber)
{
  (void)c9_machineNumber;
  (void)c9_chartNumber;
  (void)c9_instanceNumber;
}

static const mxArray *c9_sf_marshallOut(void *chartInstanceVoid, void *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  real_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance;
  chartInstance = (SFc9_SmAHTR_r1_PITTRTNUKEInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(real_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static real_T c9_emlrt_marshallIn(SFc9_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c9_xdot, const char_T *c9_identifier)
{
  real_T c9_y;
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_xdot), &c9_thisId);
  sf_mex_destroy(&c9_xdot);
  return c9_y;
}

static real_T c9_b_emlrt_marshallIn(SFc9_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  real_T c9_y;
  real_T c9_d0;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_d0, 1, 0, 0U, 0, 0U, 0);
  c9_y = c9_d0;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_xdot;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y;
  SFc9_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance;
  chartInstance = (SFc9_SmAHTR_r1_PITTRTNUKEInstanceStruct *)chartInstanceVoid;
  c9_xdot = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_xdot), &c9_thisId);
  sf_mex_destroy(&c9_xdot);
  *(real_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_b_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i2;
  real_T c9_b_inData[7];
  int32_T c9_i3;
  real_T c9_u[7];
  const mxArray *c9_y = NULL;
  SFc9_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance;
  chartInstance = (SFc9_SmAHTR_r1_PITTRTNUKEInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i2 = 0; c9_i2 < 7; c9_i2++) {
    c9_b_inData[c9_i2] = (*(real_T (*)[7])c9_inData)[c9_i2];
  }

  for (c9_i3 = 0; c9_i3 < 7; c9_i3++) {
    c9_u[c9_i3] = c9_b_inData[c9_i3];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 7), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

const mxArray *sf_c9_SmAHTR_r1_PITTRTNUKE_get_eml_resolved_functions_info(void)
{
  const mxArray *c9_nameCaptureInfo = NULL;
  c9_nameCaptureInfo = NULL;
  sf_mex_assign(&c9_nameCaptureInfo, sf_mex_createstruct("structure", 2, 7, 1),
                false);
  c9_info_helper(&c9_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c9_nameCaptureInfo);
  return c9_nameCaptureInfo;
}

static void c9_info_helper(const mxArray **c9_info)
{
  const mxArray *c9_rhs0 = NULL;
  const mxArray *c9_lhs0 = NULL;
  const mxArray *c9_rhs1 = NULL;
  const mxArray *c9_lhs1 = NULL;
  const mxArray *c9_rhs2 = NULL;
  const mxArray *c9_lhs2 = NULL;
  const mxArray *c9_rhs3 = NULL;
  const mxArray *c9_lhs3 = NULL;
  const mxArray *c9_rhs4 = NULL;
  const mxArray *c9_lhs4 = NULL;
  const mxArray *c9_rhs5 = NULL;
  const mxArray *c9_lhs5 = NULL;
  const mxArray *c9_rhs6 = NULL;
  const mxArray *c9_lhs6 = NULL;
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("mrdivide"), "name", "name", 0);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1388481696U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1370031486U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c9_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 1);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 1);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1363732556U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c9_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 2);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("rdivide"), "name", "name", 2);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1363731880U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c9_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs2), "lhs", "lhs", 2);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 3);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1363732556U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c9_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs3), "rhs", "rhs", 3);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs3), "lhs", "lhs", 3);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 4);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1286840396U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c9_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs4), "rhs", "rhs", 4);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs4), "lhs", "lhs", 4);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_div"), "name", "name", 5);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c9_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs5), "rhs", "rhs", 5);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs5), "lhs", "lhs", 5);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 6);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1389329520U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c9_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs6), "rhs", "rhs", 6);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs6), "lhs", "lhs", 6);
  sf_mex_destroy(&c9_rhs0);
  sf_mex_destroy(&c9_lhs0);
  sf_mex_destroy(&c9_rhs1);
  sf_mex_destroy(&c9_lhs1);
  sf_mex_destroy(&c9_rhs2);
  sf_mex_destroy(&c9_lhs2);
  sf_mex_destroy(&c9_rhs3);
  sf_mex_destroy(&c9_lhs3);
  sf_mex_destroy(&c9_rhs4);
  sf_mex_destroy(&c9_lhs4);
  sf_mex_destroy(&c9_rhs5);
  sf_mex_destroy(&c9_lhs5);
  sf_mex_destroy(&c9_rhs6);
  sf_mex_destroy(&c9_lhs6);
}

static const mxArray *c9_emlrt_marshallOut(const char * c9_u)
{
  const mxArray *c9_y = NULL;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c9_u)), false);
  return c9_y;
}

static const mxArray *c9_b_emlrt_marshallOut(const uint32_T c9_u)
{
  const mxArray *c9_y = NULL;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 7, 0U, 0U, 0U, 0), false);
  return c9_y;
}

static const mxArray *c9_c_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance;
  chartInstance = (SFc9_SmAHTR_r1_PITTRTNUKEInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(int32_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static int32_T c9_c_emlrt_marshallIn(SFc9_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  int32_T c9_y;
  int32_T c9_i4;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_i4, 1, 6, 0U, 0, 0U, 0);
  c9_y = c9_i4;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_b_sfEvent;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  int32_T c9_y;
  SFc9_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance;
  chartInstance = (SFc9_SmAHTR_r1_PITTRTNUKEInstanceStruct *)chartInstanceVoid;
  c9_b_sfEvent = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_sfEvent),
    &c9_thisId);
  sf_mex_destroy(&c9_b_sfEvent);
  *(int32_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

static uint8_T c9_d_emlrt_marshallIn(SFc9_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c9_b_is_active_c9_SmAHTR_r1_PITTRTNUKE, const
  char_T *c9_identifier)
{
  uint8_T c9_y;
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c9_b_is_active_c9_SmAHTR_r1_PITTRTNUKE), &c9_thisId);
  sf_mex_destroy(&c9_b_is_active_c9_SmAHTR_r1_PITTRTNUKE);
  return c9_y;
}

static uint8_T c9_e_emlrt_marshallIn(SFc9_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  uint8_T c9_y;
  uint8_T c9_u0;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_u0, 1, 3, 0U, 0, 0U, 0);
  c9_y = c9_u0;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void init_dsm_address_info(SFc9_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c9_SmAHTR_r1_PITTRTNUKE_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2566277105U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2562410118U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2996450078U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4283109355U);
}

mxArray *sf_c9_SmAHTR_r1_PITTRTNUKE_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("kNFURNIMqv06tgfv0cWXZC");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,5,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(7);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c9_SmAHTR_r1_PITTRTNUKE_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c9_SmAHTR_r1_PITTRTNUKE_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c9_SmAHTR_r1_PITTRTNUKE(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x5'type','srcId','name','auxInfo'{{M[1],M[11],T\"Tc_o\",},{M[1],M[10],T\"Tt_o\",},{M[1],M[9],T\"xdot\",},{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c9_SmAHTR_r1_PITTRTNUKE\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 5, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c9_SmAHTR_r1_PITTRTNUKE_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc9_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc9_SmAHTR_r1_PITTRTNUKEInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _SmAHTR_r1_PITTRTNUKEMachineNumber_,
           9,
           1,
           1,
           0,
           9,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_SmAHTR_r1_PITTRTNUKEMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_SmAHTR_r1_PITTRTNUKEMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _SmAHTR_r1_PITTRTNUKEMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,2,0,1,"y");
          _SFD_SET_DATA_PROPS(1,2,0,1,"Tt_o");
          _SFD_SET_DATA_PROPS(2,2,0,1,"Tc_o");
          _SFD_SET_DATA_PROPS(3,2,0,1,"xdot");
          _SFD_SET_DATA_PROPS(4,1,1,0,"Tc_i");
          _SFD_SET_DATA_PROPS(5,1,1,0,"Tt_i");
          _SFD_SET_DATA_PROPS(6,1,1,0,"mdot");
          _SFD_SET_DATA_PROPS(7,1,1,0,"constants");
          _SFD_SET_DATA_PROPS(8,1,1,0,"x");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",1,-1,879);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 7;
          _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c9_y;
          real_T *c9_Tt_o;
          real_T *c9_Tc_o;
          real_T *c9_xdot;
          real_T *c9_Tc_i;
          real_T *c9_Tt_i;
          real_T *c9_mdot;
          real_T *c9_x;
          real_T (*c9_constants)[7];
          c9_x = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c9_constants = (real_T (*)[7])ssGetInputPortSignal(chartInstance->S, 3);
          c9_mdot = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c9_Tt_i = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c9_Tc_i = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          c9_xdot = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
          c9_Tc_o = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c9_Tt_o = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c9_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c9_y);
          _SFD_SET_DATA_VALUE_PTR(1U, c9_Tt_o);
          _SFD_SET_DATA_VALUE_PTR(2U, c9_Tc_o);
          _SFD_SET_DATA_VALUE_PTR(3U, c9_xdot);
          _SFD_SET_DATA_VALUE_PTR(4U, c9_Tc_i);
          _SFD_SET_DATA_VALUE_PTR(5U, c9_Tt_i);
          _SFD_SET_DATA_VALUE_PTR(6U, c9_mdot);
          _SFD_SET_DATA_VALUE_PTR(7U, *c9_constants);
          _SFD_SET_DATA_VALUE_PTR(8U, c9_x);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _SmAHTR_r1_PITTRTNUKEMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "OV9lzu2c8FVpplEGyyLevE";
}

static void sf_opaque_initialize_c9_SmAHTR_r1_PITTRTNUKE(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc9_SmAHTR_r1_PITTRTNUKEInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c9_SmAHTR_r1_PITTRTNUKE
    ((SFc9_SmAHTR_r1_PITTRTNUKEInstanceStruct*) chartInstanceVar);
  initialize_c9_SmAHTR_r1_PITTRTNUKE((SFc9_SmAHTR_r1_PITTRTNUKEInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c9_SmAHTR_r1_PITTRTNUKE(void *chartInstanceVar)
{
  enable_c9_SmAHTR_r1_PITTRTNUKE((SFc9_SmAHTR_r1_PITTRTNUKEInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c9_SmAHTR_r1_PITTRTNUKE(void *chartInstanceVar)
{
  disable_c9_SmAHTR_r1_PITTRTNUKE((SFc9_SmAHTR_r1_PITTRTNUKEInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c9_SmAHTR_r1_PITTRTNUKE(void *chartInstanceVar)
{
  sf_gateway_c9_SmAHTR_r1_PITTRTNUKE((SFc9_SmAHTR_r1_PITTRTNUKEInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c9_SmAHTR_r1_PITTRTNUKE
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c9_SmAHTR_r1_PITTRTNUKE
    ((SFc9_SmAHTR_r1_PITTRTNUKEInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c9_SmAHTR_r1_PITTRTNUKE();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c9_SmAHTR_r1_PITTRTNUKE(SimStruct* S,
  const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c9_SmAHTR_r1_PITTRTNUKE();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c9_SmAHTR_r1_PITTRTNUKE((SFc9_SmAHTR_r1_PITTRTNUKEInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c9_SmAHTR_r1_PITTRTNUKE(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c9_SmAHTR_r1_PITTRTNUKE(S);
}

static void sf_opaque_set_sim_state_c9_SmAHTR_r1_PITTRTNUKE(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c9_SmAHTR_r1_PITTRTNUKE(S, st);
}

static void sf_opaque_terminate_c9_SmAHTR_r1_PITTRTNUKE(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc9_SmAHTR_r1_PITTRTNUKEInstanceStruct*) chartInstanceVar
      )->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_SmAHTR_r1_PITTRTNUKE_optimization_info();
    }

    finalize_c9_SmAHTR_r1_PITTRTNUKE((SFc9_SmAHTR_r1_PITTRTNUKEInstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc9_SmAHTR_r1_PITTRTNUKE((SFc9_SmAHTR_r1_PITTRTNUKEInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c9_SmAHTR_r1_PITTRTNUKE(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    initialize_params_c9_SmAHTR_r1_PITTRTNUKE
      ((SFc9_SmAHTR_r1_PITTRTNUKEInstanceStruct*)(chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c9_SmAHTR_r1_PITTRTNUKE(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_SmAHTR_r1_PITTRTNUKE_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,9);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,9,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,9,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,9);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,9,5);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,9,4);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=4; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 5; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,9);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3954557796U));
  ssSetChecksum1(S,(1598644551U));
  ssSetChecksum2(S,(2933242711U));
  ssSetChecksum3(S,(2528299683U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c9_SmAHTR_r1_PITTRTNUKE(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c9_SmAHTR_r1_PITTRTNUKE(SimStruct *S)
{
  SFc9_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc9_SmAHTR_r1_PITTRTNUKEInstanceStruct *)utMalloc(sizeof
    (SFc9_SmAHTR_r1_PITTRTNUKEInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc9_SmAHTR_r1_PITTRTNUKEInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c9_SmAHTR_r1_PITTRTNUKE;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c9_SmAHTR_r1_PITTRTNUKE;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c9_SmAHTR_r1_PITTRTNUKE;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c9_SmAHTR_r1_PITTRTNUKE;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c9_SmAHTR_r1_PITTRTNUKE;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c9_SmAHTR_r1_PITTRTNUKE;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c9_SmAHTR_r1_PITTRTNUKE;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c9_SmAHTR_r1_PITTRTNUKE;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c9_SmAHTR_r1_PITTRTNUKE;
  chartInstance->chartInfo.mdlStart = mdlStart_c9_SmAHTR_r1_PITTRTNUKE;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c9_SmAHTR_r1_PITTRTNUKE;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  crtInfo->instanceInfo = (&(chartInstance->chartInfo));
  crtInfo->isJITEnabled = false;
  ssSetUserData(S,(void *)(crtInfo));  /* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c9_SmAHTR_r1_PITTRTNUKE_method_dispatcher(SimStruct *S, int_T method, void *
  data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c9_SmAHTR_r1_PITTRTNUKE(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c9_SmAHTR_r1_PITTRTNUKE(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c9_SmAHTR_r1_PITTRTNUKE(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c9_SmAHTR_r1_PITTRTNUKE_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
