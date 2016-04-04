/* Include files */

#include <stddef.h>
#include "blas.h"
#include "SmAHTR_r1_PITTRTNUKE_sfun.h"
#include "c10_SmAHTR_r1_PITTRTNUKE.h"
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
static const char * c10_debug_family_names[30] = { "V_secondary",
  "rho_secondary", "cps", "rhoCO2", "m1", "c1", "m2", "c2", "h1", "h2", "ms",
  "cs", "Area", "UA_thresh", "u", "A", "b", "C", "D", "nargin", "nargout",
  "mdots", "mdott", "T_s1", "T_t1", "constants", "Tamb", "x", "y", "x_dot" };

/* Function Declarations */
static void initialize_c10_SmAHTR_r1_PITTRTNUKE
  (SFc10_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance);
static void initialize_params_c10_SmAHTR_r1_PITTRTNUKE
  (SFc10_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance);
static void enable_c10_SmAHTR_r1_PITTRTNUKE
  (SFc10_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance);
static void disable_c10_SmAHTR_r1_PITTRTNUKE
  (SFc10_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance);
static void c10_update_debugger_state_c10_SmAHTR_r1_PITTRTNUKE
  (SFc10_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c10_SmAHTR_r1_PITTRTNUKE
  (SFc10_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance);
static void set_sim_state_c10_SmAHTR_r1_PITTRTNUKE
  (SFc10_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance, const mxArray
   *c10_st);
static void finalize_c10_SmAHTR_r1_PITTRTNUKE
  (SFc10_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance);
static void sf_gateway_c10_SmAHTR_r1_PITTRTNUKE
  (SFc10_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance);
static void c10_chartstep_c10_SmAHTR_r1_PITTRTNUKE
  (SFc10_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance);
static void initSimStructsc10_SmAHTR_r1_PITTRTNUKE
  (SFc10_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c10_machineNumber, uint32_T
  c10_chartNumber, uint32_T c10_instanceNumber);
static const mxArray *c10_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static void c10_emlrt_marshallIn(SFc10_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c10_x_dot, const char_T *c10_identifier, real_T
  c10_y[3]);
static void c10_b_emlrt_marshallIn(SFc10_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId,
  real_T c10_y[3]);
static void c10_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static const mxArray *c10_b_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static const mxArray *c10_c_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static real_T c10_c_emlrt_marshallIn(SFc10_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId);
static void c10_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static const mxArray *c10_d_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static void c10_d_emlrt_marshallIn(SFc10_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId,
  real_T c10_y[9]);
static void c10_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static void c10_info_helper(const mxArray **c10_info);
static const mxArray *c10_emlrt_marshallOut(const char * c10_u);
static const mxArray *c10_b_emlrt_marshallOut(const uint32_T c10_u);
static void c10_eml_scalar_eg(SFc10_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance);
static void c10_eml_xgemm(SFc10_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, real_T c10_A[9], real_T c10_B[3], real_T c10_C[3], real_T
  c10_b_C[3]);
static const mxArray *c10_e_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static int32_T c10_e_emlrt_marshallIn(SFc10_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId);
static void c10_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static uint8_T c10_f_emlrt_marshallIn(SFc10_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c10_b_is_active_c10_SmAHTR_r1_PITTRTNUKE, const
  char_T *c10_identifier);
static uint8_T c10_g_emlrt_marshallIn(SFc10_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId);
static void c10_b_eml_xgemm(SFc10_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, real_T c10_A[9], real_T c10_B[3], real_T c10_C[3]);
static void init_dsm_address_info(SFc10_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c10_SmAHTR_r1_PITTRTNUKE
  (SFc10_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance)
{
  chartInstance->c10_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c10_is_active_c10_SmAHTR_r1_PITTRTNUKE = 0U;
}

static void initialize_params_c10_SmAHTR_r1_PITTRTNUKE
  (SFc10_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c10_SmAHTR_r1_PITTRTNUKE
  (SFc10_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c10_SmAHTR_r1_PITTRTNUKE
  (SFc10_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c10_update_debugger_state_c10_SmAHTR_r1_PITTRTNUKE
  (SFc10_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c10_SmAHTR_r1_PITTRTNUKE
  (SFc10_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance)
{
  const mxArray *c10_st;
  const mxArray *c10_y = NULL;
  int32_T c10_i0;
  real_T c10_u[3];
  const mxArray *c10_b_y = NULL;
  int32_T c10_i1;
  real_T c10_b_u[3];
  const mxArray *c10_c_y = NULL;
  uint8_T c10_hoistedGlobal;
  uint8_T c10_c_u;
  const mxArray *c10_d_y = NULL;
  real_T (*c10_e_y)[3];
  real_T (*c10_x_dot)[3];
  c10_x_dot = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c10_e_y = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c10_st = NULL;
  c10_st = NULL;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_createcellmatrix(3, 1), false);
  for (c10_i0 = 0; c10_i0 < 3; c10_i0++) {
    c10_u[c10_i0] = (*c10_x_dot)[c10_i0];
  }

  c10_b_y = NULL;
  sf_mex_assign(&c10_b_y, sf_mex_create("y", c10_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_setcell(c10_y, 0, c10_b_y);
  for (c10_i1 = 0; c10_i1 < 3; c10_i1++) {
    c10_b_u[c10_i1] = (*c10_e_y)[c10_i1];
  }

  c10_c_y = NULL;
  sf_mex_assign(&c10_c_y, sf_mex_create("y", c10_b_u, 0, 0U, 1U, 0U, 1, 3),
                false);
  sf_mex_setcell(c10_y, 1, c10_c_y);
  c10_hoistedGlobal = chartInstance->c10_is_active_c10_SmAHTR_r1_PITTRTNUKE;
  c10_c_u = c10_hoistedGlobal;
  c10_d_y = NULL;
  sf_mex_assign(&c10_d_y, sf_mex_create("y", &c10_c_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c10_y, 2, c10_d_y);
  sf_mex_assign(&c10_st, c10_y, false);
  return c10_st;
}

static void set_sim_state_c10_SmAHTR_r1_PITTRTNUKE
  (SFc10_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance, const mxArray
   *c10_st)
{
  const mxArray *c10_u;
  real_T c10_dv0[3];
  int32_T c10_i2;
  real_T c10_dv1[3];
  int32_T c10_i3;
  real_T (*c10_x_dot)[3];
  real_T (*c10_y)[3];
  c10_x_dot = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c10_y = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c10_doneDoubleBufferReInit = true;
  c10_u = sf_mex_dup(c10_st);
  c10_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c10_u, 0)),
                       "x_dot", c10_dv0);
  for (c10_i2 = 0; c10_i2 < 3; c10_i2++) {
    (*c10_x_dot)[c10_i2] = c10_dv0[c10_i2];
  }

  c10_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c10_u, 1)), "y",
                       c10_dv1);
  for (c10_i3 = 0; c10_i3 < 3; c10_i3++) {
    (*c10_y)[c10_i3] = c10_dv1[c10_i3];
  }

  chartInstance->c10_is_active_c10_SmAHTR_r1_PITTRTNUKE = c10_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c10_u, 2)),
     "is_active_c10_SmAHTR_r1_PITTRTNUKE");
  sf_mex_destroy(&c10_u);
  c10_update_debugger_state_c10_SmAHTR_r1_PITTRTNUKE(chartInstance);
  sf_mex_destroy(&c10_st);
}

static void finalize_c10_SmAHTR_r1_PITTRTNUKE
  (SFc10_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c10_SmAHTR_r1_PITTRTNUKE
  (SFc10_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance)
{
  int32_T c10_i4;
  int32_T c10_i5;
  int32_T c10_i6;
  int32_T c10_i7;
  real_T *c10_mdots;
  real_T *c10_mdott;
  real_T *c10_T_s1;
  real_T *c10_T_t1;
  real_T *c10_Tamb;
  real_T (*c10_x)[3];
  real_T (*c10_constants)[4];
  real_T (*c10_x_dot)[3];
  real_T (*c10_y)[3];
  c10_x = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 6);
  c10_Tamb = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c10_constants = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 4);
  c10_T_t1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c10_T_s1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c10_mdott = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c10_x_dot = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c10_mdots = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c10_y = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 8U, chartInstance->c10_sfEvent);
  chartInstance->c10_sfEvent = CALL_EVENT;
  c10_chartstep_c10_SmAHTR_r1_PITTRTNUKE(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_SmAHTR_r1_PITTRTNUKEMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c10_i4 = 0; c10_i4 < 3; c10_i4++) {
    _SFD_DATA_RANGE_CHECK((*c10_y)[c10_i4], 0U);
  }

  _SFD_DATA_RANGE_CHECK(*c10_mdots, 1U);
  for (c10_i5 = 0; c10_i5 < 3; c10_i5++) {
    _SFD_DATA_RANGE_CHECK((*c10_x_dot)[c10_i5], 2U);
  }

  _SFD_DATA_RANGE_CHECK(*c10_mdott, 3U);
  _SFD_DATA_RANGE_CHECK(*c10_T_s1, 4U);
  _SFD_DATA_RANGE_CHECK(*c10_T_t1, 5U);
  for (c10_i6 = 0; c10_i6 < 4; c10_i6++) {
    _SFD_DATA_RANGE_CHECK((*c10_constants)[c10_i6], 6U);
  }

  _SFD_DATA_RANGE_CHECK(*c10_Tamb, 7U);
  for (c10_i7 = 0; c10_i7 < 3; c10_i7++) {
    _SFD_DATA_RANGE_CHECK((*c10_x)[c10_i7], 8U);
  }
}

static void c10_chartstep_c10_SmAHTR_r1_PITTRTNUKE
  (SFc10_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance)
{
  real_T c10_hoistedGlobal;
  real_T c10_b_hoistedGlobal;
  real_T c10_c_hoistedGlobal;
  real_T c10_d_hoistedGlobal;
  real_T c10_e_hoistedGlobal;
  real_T c10_mdots;
  real_T c10_mdott;
  real_T c10_T_s1;
  real_T c10_T_t1;
  int32_T c10_i8;
  real_T c10_constants[4];
  real_T c10_Tamb;
  int32_T c10_i9;
  real_T c10_x[3];
  uint32_T c10_debug_family_var_map[30];
  real_T c10_V_secondary;
  real_T c10_rho_secondary;
  real_T c10_cps;
  real_T c10_rhoCO2;
  real_T c10_m1;
  real_T c10_c1;
  real_T c10_m2;
  real_T c10_c2;
  real_T c10_h1;
  real_T c10_h2;
  real_T c10_ms;
  real_T c10_cs;
  real_T c10_Area;
  real_T c10_UA_thresh;
  real_T c10_u[3];
  real_T c10_A[9];
  real_T c10_b[9];
  real_T c10_C[9];
  real_T c10_D[9];
  real_T c10_nargin = 7.0;
  real_T c10_nargout = 2.0;
  real_T c10_y[3];
  real_T c10_x_dot[3];
  real_T c10_b_A;
  real_T c10_B;
  real_T c10_b_x;
  real_T c10_b_y;
  real_T c10_c_x;
  real_T c10_c_y;
  real_T c10_d_x;
  real_T c10_d_y;
  real_T c10_e_y;
  real_T c10_b_B;
  real_T c10_f_y;
  real_T c10_g_y;
  real_T c10_h_y;
  real_T c10_i_y;
  real_T c10_c_B;
  real_T c10_j_y;
  real_T c10_k_y;
  real_T c10_l_y;
  real_T c10_m_y;
  real_T c10_d_B;
  real_T c10_n_y;
  real_T c10_o_y;
  real_T c10_p_y;
  real_T c10_q_y;
  real_T c10_e_B;
  real_T c10_r_y;
  real_T c10_s_y;
  real_T c10_t_y;
  real_T c10_u_y;
  real_T c10_f_B;
  real_T c10_v_y;
  real_T c10_w_y;
  real_T c10_x_y;
  real_T c10_y_y;
  real_T c10_g_B;
  real_T c10_ab_y;
  real_T c10_bb_y;
  real_T c10_cb_y;
  real_T c10_db_y;
  real_T c10_c_A;
  real_T c10_h_B;
  real_T c10_e_x;
  real_T c10_eb_y;
  real_T c10_f_x;
  real_T c10_fb_y;
  real_T c10_g_x;
  real_T c10_gb_y;
  real_T c10_hb_y;
  real_T c10_i_B;
  real_T c10_ib_y;
  real_T c10_jb_y;
  real_T c10_kb_y;
  real_T c10_lb_y;
  real_T c10_d_A;
  real_T c10_h_x;
  real_T c10_i_x;
  real_T c10_j_x;
  real_T c10_mb_y;
  real_T c10_e_A;
  real_T c10_j_B;
  real_T c10_k_x;
  real_T c10_nb_y;
  real_T c10_l_x;
  real_T c10_ob_y;
  real_T c10_m_x;
  real_T c10_pb_y;
  real_T c10_qb_y;
  real_T c10_k_B;
  real_T c10_rb_y;
  real_T c10_sb_y;
  real_T c10_tb_y;
  real_T c10_ub_y;
  real_T c10_f_A;
  real_T c10_l_B;
  real_T c10_n_x;
  real_T c10_vb_y;
  real_T c10_o_x;
  real_T c10_wb_y;
  real_T c10_p_x;
  real_T c10_xb_y;
  real_T c10_yb_y;
  real_T c10_g_A;
  real_T c10_q_x;
  real_T c10_r_x;
  real_T c10_s_x;
  real_T c10_ac_y;
  int32_T c10_i10;
  static real_T c10_a[9] = { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 };

  int32_T c10_i11;
  int32_T c10_i12;
  real_T c10_b_a[9];
  int32_T c10_i13;
  real_T c10_b_b[3];
  int32_T c10_i14;
  real_T c10_bc_y[3];
  int32_T c10_i15;
  real_T c10_c_a[9];
  int32_T c10_i16;
  real_T c10_c_b[3];
  int32_T c10_i17;
  int32_T c10_i18;
  int32_T c10_i19;
  real_T c10_cc_y[3];
  int32_T c10_i20;
  real_T c10_d_a[9];
  int32_T c10_i21;
  real_T c10_d_b[3];
  int32_T c10_i22;
  int32_T c10_i23;
  int32_T c10_i24;
  int32_T c10_i25;
  real_T c10_e_a[9];
  int32_T c10_i26;
  real_T c10_e_b[3];
  int32_T c10_i27;
  int32_T c10_i28;
  int32_T c10_i29;
  int32_T c10_i30;
  real_T c10_f_a[9];
  int32_T c10_i31;
  real_T c10_f_b[3];
  int32_T c10_i32;
  int32_T c10_i33;
  int32_T c10_i34;
  real_T *c10_b_Tamb;
  real_T *c10_b_T_t1;
  real_T *c10_b_T_s1;
  real_T *c10_b_mdott;
  real_T *c10_b_mdots;
  real_T (*c10_dc_y)[3];
  real_T (*c10_b_x_dot)[3];
  real_T (*c10_t_x)[3];
  real_T (*c10_b_constants)[4];
  c10_t_x = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 6);
  c10_b_Tamb = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c10_b_constants = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 4);
  c10_b_T_t1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c10_b_T_s1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c10_b_mdott = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c10_b_x_dot = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c10_b_mdots = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c10_dc_y = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 8U, chartInstance->c10_sfEvent);
  c10_hoistedGlobal = *c10_b_mdots;
  c10_b_hoistedGlobal = *c10_b_mdott;
  c10_c_hoistedGlobal = *c10_b_T_s1;
  c10_d_hoistedGlobal = *c10_b_T_t1;
  c10_e_hoistedGlobal = *c10_b_Tamb;
  c10_mdots = c10_hoistedGlobal;
  c10_mdott = c10_b_hoistedGlobal;
  c10_T_s1 = c10_c_hoistedGlobal;
  c10_T_t1 = c10_d_hoistedGlobal;
  for (c10_i8 = 0; c10_i8 < 4; c10_i8++) {
    c10_constants[c10_i8] = (*c10_b_constants)[c10_i8];
  }

  c10_Tamb = c10_e_hoistedGlobal;
  for (c10_i9 = 0; c10_i9 < 3; c10_i9++) {
    c10_x[c10_i9] = (*c10_t_x)[c10_i9];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 30U, 30U, c10_debug_family_names,
    c10_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_V_secondary, 0U,
    c10_b_sf_marshallOut, c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_rho_secondary, 1U,
    c10_b_sf_marshallOut, c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_cps, 2U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_rhoCO2, 3U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_m1, 4U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_c1, 5U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_m2, 6U, c10_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_c2, 7U, c10_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_h1, 8U, c10_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_h2, 9U, c10_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_ms, 10U, c10_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_cs, 11U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_Area, 12U, c10_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_UA_thresh, 13U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_u, 14U, c10_sf_marshallOut,
    c10_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_A, 15U, c10_d_sf_marshallOut,
    c10_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_b, 16U, c10_d_sf_marshallOut,
    c10_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c10_C, 17U, c10_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c10_D, 18U, c10_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargin, 19U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargout, 20U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_mdots, 21U, c10_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_mdott, 22U, c10_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_T_s1, 23U, c10_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_T_t1, 24U, c10_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c10_constants, 25U, c10_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_Tamb, 26U, c10_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c10_x, 27U, c10_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_y, 28U, c10_sf_marshallOut,
    c10_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_x_dot, 29U, c10_sf_marshallOut,
    c10_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 3);
  c10_V_secondary = c10_constants[0];
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 4);
  c10_rho_secondary = c10_constants[1];
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 5);
  c10_cps = c10_constants[2];
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 6);
  c10_rhoCO2 = c10_constants[3];
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 7);
  c10_m1 = c10_V_secondary * c10_rho_secondary;
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 8);
  c10_c1 = c10_cps;
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 9);
  c10_m2 = 708.0;
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 10);
  c10_c2 = 1121.0;
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 11);
  c10_h1 = 23800.0;
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 12);
  c10_h2 = 30000.0;
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 13);
  c10_ms = 600000.0;
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 14);
  c10_cs = c10_cps;
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 15);
  c10_Area = 292.0;
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 18);
  if (CV_EML_IF(0, 1, 0, c10_x[1] >= 540.0)) {
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 19);
    c10_UA_thresh = 5.0E+6;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 21);
    c10_UA_thresh = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 25);
  c10_u[0] = c10_T_s1;
  c10_u[1] = c10_Tamb;
  c10_u[2] = c10_T_t1;
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 27);
  c10_b_A = -c10_mdots;
  c10_B = c10_m1;
  c10_b_x = c10_b_A;
  c10_b_y = c10_B;
  c10_c_x = c10_b_x;
  c10_c_y = c10_b_y;
  c10_d_x = c10_c_x;
  c10_d_y = c10_c_y;
  c10_e_y = c10_d_x / c10_d_y;
  c10_b_B = c10_m1 * c10_c1;
  c10_f_y = c10_b_B;
  c10_g_y = c10_f_y;
  c10_h_y = c10_g_y;
  c10_i_y = 6.9496E+6 / c10_h_y;
  c10_c_B = c10_m1 * c10_c1;
  c10_j_y = c10_c_B;
  c10_k_y = c10_j_y;
  c10_l_y = c10_k_y;
  c10_m_y = 6.9496E+6 / c10_l_y;
  c10_d_B = 600000.0 * c10_cs;
  c10_n_y = c10_d_B;
  c10_o_y = c10_n_y;
  c10_p_y = c10_o_y;
  c10_q_y = 6.9496E+6 / c10_p_y;
  c10_e_B = 600000.0 * c10_cs;
  c10_r_y = c10_e_B;
  c10_s_y = c10_r_y;
  c10_t_y = c10_s_y;
  c10_u_y = -6.9496E+6 / c10_t_y;
  c10_f_B = 600000.0 * c10_cs;
  c10_v_y = c10_f_B;
  c10_w_y = c10_v_y;
  c10_x_y = c10_w_y;
  c10_y_y = 8.76E+6 / c10_x_y;
  c10_g_B = 600000.0 * c10_cs;
  c10_ab_y = c10_g_B;
  c10_bb_y = c10_ab_y;
  c10_cb_y = c10_bb_y;
  c10_db_y = 62831.853071795864 / c10_cb_y;
  c10_c_A = c10_UA_thresh;
  c10_h_B = 600000.0 * c10_cs;
  c10_e_x = c10_c_A;
  c10_eb_y = c10_h_B;
  c10_f_x = c10_e_x;
  c10_fb_y = c10_eb_y;
  c10_g_x = c10_f_x;
  c10_gb_y = c10_fb_y;
  c10_hb_y = c10_g_x / c10_gb_y;
  c10_i_B = 600000.0 * c10_cs;
  c10_ib_y = c10_i_B;
  c10_jb_y = c10_ib_y;
  c10_kb_y = c10_jb_y;
  c10_lb_y = 8.76E+6 / c10_kb_y;
  c10_d_A = -c10_mdott;
  c10_h_x = c10_d_A;
  c10_i_x = c10_h_x;
  c10_j_x = c10_i_x;
  c10_mb_y = c10_j_x / 708.0;
  c10_A[0] = c10_e_y - c10_i_y;
  c10_A[3] = c10_m_y;
  c10_A[6] = 0.0;
  c10_A[1] = c10_q_y;
  c10_A[4] = ((c10_u_y - c10_y_y) - c10_db_y) - c10_hb_y;
  c10_A[7] = c10_lb_y;
  c10_A[2] = 0.0;
  c10_A[5] = 11.037360710019806;
  c10_A[8] = c10_mb_y - 11.037360710019806;
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 31);
  c10_e_A = c10_mdots;
  c10_j_B = c10_m1;
  c10_k_x = c10_e_A;
  c10_nb_y = c10_j_B;
  c10_l_x = c10_k_x;
  c10_ob_y = c10_nb_y;
  c10_m_x = c10_l_x;
  c10_pb_y = c10_ob_y;
  c10_qb_y = c10_m_x / c10_pb_y;
  c10_k_B = 600000.0 * c10_cs;
  c10_rb_y = c10_k_B;
  c10_sb_y = c10_rb_y;
  c10_tb_y = c10_sb_y;
  c10_ub_y = 62831.853071795864 / c10_tb_y;
  c10_f_A = c10_UA_thresh;
  c10_l_B = 600000.0 * c10_cs;
  c10_n_x = c10_f_A;
  c10_vb_y = c10_l_B;
  c10_o_x = c10_n_x;
  c10_wb_y = c10_vb_y;
  c10_p_x = c10_o_x;
  c10_xb_y = c10_wb_y;
  c10_yb_y = c10_p_x / c10_xb_y;
  c10_g_A = c10_mdott;
  c10_q_x = c10_g_A;
  c10_r_x = c10_q_x;
  c10_s_x = c10_r_x;
  c10_ac_y = c10_s_x / 708.0;
  c10_b[0] = c10_qb_y;
  c10_b[3] = 0.0;
  c10_b[6] = 0.0;
  c10_b[1] = 0.0;
  c10_b[4] = c10_ub_y + c10_yb_y;
  c10_b[7] = 0.0;
  c10_b[2] = 0.0;
  c10_b[5] = 0.0;
  c10_b[8] = c10_ac_y;
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 33);
  for (c10_i10 = 0; c10_i10 < 9; c10_i10++) {
    c10_C[c10_i10] = c10_a[c10_i10];
  }

  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 35);
  for (c10_i11 = 0; c10_i11 < 9; c10_i11++) {
    c10_D[c10_i11] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 37);
  for (c10_i12 = 0; c10_i12 < 9; c10_i12++) {
    c10_b_a[c10_i12] = c10_A[c10_i12];
  }

  for (c10_i13 = 0; c10_i13 < 3; c10_i13++) {
    c10_b_b[c10_i13] = c10_x[c10_i13];
  }

  c10_eml_scalar_eg(chartInstance);
  c10_eml_scalar_eg(chartInstance);
  for (c10_i14 = 0; c10_i14 < 3; c10_i14++) {
    c10_bc_y[c10_i14] = 0.0;
  }

  for (c10_i15 = 0; c10_i15 < 9; c10_i15++) {
    c10_c_a[c10_i15] = c10_b_a[c10_i15];
  }

  for (c10_i16 = 0; c10_i16 < 3; c10_i16++) {
    c10_c_b[c10_i16] = c10_b_b[c10_i16];
  }

  c10_b_eml_xgemm(chartInstance, c10_c_a, c10_c_b, c10_bc_y);
  for (c10_i17 = 0; c10_i17 < 9; c10_i17++) {
    c10_b_a[c10_i17] = c10_b[c10_i17];
  }

  for (c10_i18 = 0; c10_i18 < 3; c10_i18++) {
    c10_b_b[c10_i18] = c10_u[c10_i18];
  }

  c10_eml_scalar_eg(chartInstance);
  c10_eml_scalar_eg(chartInstance);
  for (c10_i19 = 0; c10_i19 < 3; c10_i19++) {
    c10_cc_y[c10_i19] = 0.0;
  }

  for (c10_i20 = 0; c10_i20 < 9; c10_i20++) {
    c10_d_a[c10_i20] = c10_b_a[c10_i20];
  }

  for (c10_i21 = 0; c10_i21 < 3; c10_i21++) {
    c10_d_b[c10_i21] = c10_b_b[c10_i21];
  }

  c10_b_eml_xgemm(chartInstance, c10_d_a, c10_d_b, c10_cc_y);
  for (c10_i22 = 0; c10_i22 < 3; c10_i22++) {
    c10_x_dot[c10_i22] = c10_bc_y[c10_i22] + c10_cc_y[c10_i22];
  }

  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 39);
  for (c10_i23 = 0; c10_i23 < 3; c10_i23++) {
    c10_b_b[c10_i23] = c10_x[c10_i23];
  }

  c10_eml_scalar_eg(chartInstance);
  c10_eml_scalar_eg(chartInstance);
  for (c10_i24 = 0; c10_i24 < 3; c10_i24++) {
    c10_bc_y[c10_i24] = 0.0;
  }

  for (c10_i25 = 0; c10_i25 < 9; c10_i25++) {
    c10_e_a[c10_i25] = c10_a[c10_i25];
  }

  for (c10_i26 = 0; c10_i26 < 3; c10_i26++) {
    c10_e_b[c10_i26] = c10_b_b[c10_i26];
  }

  c10_b_eml_xgemm(chartInstance, c10_e_a, c10_e_b, c10_bc_y);
  for (c10_i27 = 0; c10_i27 < 3; c10_i27++) {
    c10_b_b[c10_i27] = c10_u[c10_i27];
  }

  c10_eml_scalar_eg(chartInstance);
  c10_eml_scalar_eg(chartInstance);
  for (c10_i28 = 0; c10_i28 < 9; c10_i28++) {
    c10_b_a[c10_i28] = 0.0;
  }

  for (c10_i29 = 0; c10_i29 < 3; c10_i29++) {
    c10_cc_y[c10_i29] = 0.0;
  }

  for (c10_i30 = 0; c10_i30 < 9; c10_i30++) {
    c10_f_a[c10_i30] = c10_b_a[c10_i30];
  }

  for (c10_i31 = 0; c10_i31 < 3; c10_i31++) {
    c10_f_b[c10_i31] = c10_b_b[c10_i31];
  }

  c10_b_eml_xgemm(chartInstance, c10_f_a, c10_f_b, c10_cc_y);
  for (c10_i32 = 0; c10_i32 < 3; c10_i32++) {
    c10_y[c10_i32] = c10_bc_y[c10_i32] + c10_cc_y[c10_i32];
  }

  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 41);
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, -41);
  _SFD_SYMBOL_SCOPE_POP();
  for (c10_i33 = 0; c10_i33 < 3; c10_i33++) {
    (*c10_dc_y)[c10_i33] = c10_y[c10_i33];
  }

  for (c10_i34 = 0; c10_i34 < 3; c10_i34++) {
    (*c10_b_x_dot)[c10_i34] = c10_x_dot[c10_i34];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c10_sfEvent);
}

static void initSimStructsc10_SmAHTR_r1_PITTRTNUKE
  (SFc10_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c10_machineNumber, uint32_T
  c10_chartNumber, uint32_T c10_instanceNumber)
{
  (void)c10_machineNumber;
  (void)c10_chartNumber;
  (void)c10_instanceNumber;
}

static const mxArray *c10_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i35;
  real_T c10_b_inData[3];
  int32_T c10_i36;
  real_T c10_u[3];
  const mxArray *c10_y = NULL;
  SFc10_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance;
  chartInstance = (SFc10_SmAHTR_r1_PITTRTNUKEInstanceStruct *)chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i35 = 0; c10_i35 < 3; c10_i35++) {
    c10_b_inData[c10_i35] = (*(real_T (*)[3])c10_inData)[c10_i35];
  }

  for (c10_i36 = 0; c10_i36 < 3; c10_i36++) {
    c10_u[c10_i36] = c10_b_inData[c10_i36];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static void c10_emlrt_marshallIn(SFc10_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c10_x_dot, const char_T *c10_identifier, real_T
  c10_y[3])
{
  emlrtMsgIdentifier c10_thisId;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_x_dot), &c10_thisId,
    c10_y);
  sf_mex_destroy(&c10_x_dot);
}

static void c10_b_emlrt_marshallIn(SFc10_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId,
  real_T c10_y[3])
{
  real_T c10_dv2[3];
  int32_T c10_i37;
  (void)chartInstance;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), c10_dv2, 1, 0, 0U, 1, 0U, 1, 3);
  for (c10_i37 = 0; c10_i37 < 3; c10_i37++) {
    c10_y[c10_i37] = c10_dv2[c10_i37];
  }

  sf_mex_destroy(&c10_u);
}

static void c10_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_x_dot;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  real_T c10_y[3];
  int32_T c10_i38;
  SFc10_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance;
  chartInstance = (SFc10_SmAHTR_r1_PITTRTNUKEInstanceStruct *)chartInstanceVoid;
  c10_x_dot = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_x_dot), &c10_thisId,
    c10_y);
  sf_mex_destroy(&c10_x_dot);
  for (c10_i38 = 0; c10_i38 < 3; c10_i38++) {
    (*(real_T (*)[3])c10_outData)[c10_i38] = c10_y[c10_i38];
  }

  sf_mex_destroy(&c10_mxArrayInData);
}

static const mxArray *c10_b_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  real_T c10_u;
  const mxArray *c10_y = NULL;
  SFc10_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance;
  chartInstance = (SFc10_SmAHTR_r1_PITTRTNUKEInstanceStruct *)chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  c10_u = *(real_T *)c10_inData;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", &c10_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static const mxArray *c10_c_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i39;
  real_T c10_b_inData[4];
  int32_T c10_i40;
  real_T c10_u[4];
  const mxArray *c10_y = NULL;
  SFc10_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance;
  chartInstance = (SFc10_SmAHTR_r1_PITTRTNUKEInstanceStruct *)chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i39 = 0; c10_i39 < 4; c10_i39++) {
    c10_b_inData[c10_i39] = (*(real_T (*)[4])c10_inData)[c10_i39];
  }

  for (c10_i40 = 0; c10_i40 < 4; c10_i40++) {
    c10_u[c10_i40] = c10_b_inData[c10_i40];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 0, 0U, 1U, 0U, 1, 4), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static real_T c10_c_emlrt_marshallIn(SFc10_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId)
{
  real_T c10_y;
  real_T c10_d0;
  (void)chartInstance;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), &c10_d0, 1, 0, 0U, 0, 0U, 0);
  c10_y = c10_d0;
  sf_mex_destroy(&c10_u);
  return c10_y;
}

static void c10_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_nargout;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  real_T c10_y;
  SFc10_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance;
  chartInstance = (SFc10_SmAHTR_r1_PITTRTNUKEInstanceStruct *)chartInstanceVoid;
  c10_nargout = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_nargout),
    &c10_thisId);
  sf_mex_destroy(&c10_nargout);
  *(real_T *)c10_outData = c10_y;
  sf_mex_destroy(&c10_mxArrayInData);
}

static const mxArray *c10_d_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i41;
  int32_T c10_i42;
  int32_T c10_i43;
  real_T c10_b_inData[9];
  int32_T c10_i44;
  int32_T c10_i45;
  int32_T c10_i46;
  real_T c10_u[9];
  const mxArray *c10_y = NULL;
  SFc10_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance;
  chartInstance = (SFc10_SmAHTR_r1_PITTRTNUKEInstanceStruct *)chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  c10_i41 = 0;
  for (c10_i42 = 0; c10_i42 < 3; c10_i42++) {
    for (c10_i43 = 0; c10_i43 < 3; c10_i43++) {
      c10_b_inData[c10_i43 + c10_i41] = (*(real_T (*)[9])c10_inData)[c10_i43 +
        c10_i41];
    }

    c10_i41 += 3;
  }

  c10_i44 = 0;
  for (c10_i45 = 0; c10_i45 < 3; c10_i45++) {
    for (c10_i46 = 0; c10_i46 < 3; c10_i46++) {
      c10_u[c10_i46 + c10_i44] = c10_b_inData[c10_i46 + c10_i44];
    }

    c10_i44 += 3;
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 0, 0U, 1U, 0U, 2, 3, 3), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static void c10_d_emlrt_marshallIn(SFc10_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId,
  real_T c10_y[9])
{
  real_T c10_dv3[9];
  int32_T c10_i47;
  (void)chartInstance;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), c10_dv3, 1, 0, 0U, 1, 0U, 2, 3,
                3);
  for (c10_i47 = 0; c10_i47 < 9; c10_i47++) {
    c10_y[c10_i47] = c10_dv3[c10_i47];
  }

  sf_mex_destroy(&c10_u);
}

static void c10_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_b;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  real_T c10_y[9];
  int32_T c10_i48;
  int32_T c10_i49;
  int32_T c10_i50;
  SFc10_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance;
  chartInstance = (SFc10_SmAHTR_r1_PITTRTNUKEInstanceStruct *)chartInstanceVoid;
  c10_b = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_b), &c10_thisId, c10_y);
  sf_mex_destroy(&c10_b);
  c10_i48 = 0;
  for (c10_i49 = 0; c10_i49 < 3; c10_i49++) {
    for (c10_i50 = 0; c10_i50 < 3; c10_i50++) {
      (*(real_T (*)[9])c10_outData)[c10_i50 + c10_i48] = c10_y[c10_i50 + c10_i48];
    }

    c10_i48 += 3;
  }

  sf_mex_destroy(&c10_mxArrayInData);
}

const mxArray *sf_c10_SmAHTR_r1_PITTRTNUKE_get_eml_resolved_functions_info(void)
{
  const mxArray *c10_nameCaptureInfo = NULL;
  c10_nameCaptureInfo = NULL;
  sf_mex_assign(&c10_nameCaptureInfo, sf_mex_createstruct("structure", 2, 20, 1),
                false);
  c10_info_helper(&c10_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c10_nameCaptureInfo);
  return c10_nameCaptureInfo;
}

static void c10_info_helper(const mxArray **c10_info)
{
  const mxArray *c10_rhs0 = NULL;
  const mxArray *c10_lhs0 = NULL;
  const mxArray *c10_rhs1 = NULL;
  const mxArray *c10_lhs1 = NULL;
  const mxArray *c10_rhs2 = NULL;
  const mxArray *c10_lhs2 = NULL;
  const mxArray *c10_rhs3 = NULL;
  const mxArray *c10_lhs3 = NULL;
  const mxArray *c10_rhs4 = NULL;
  const mxArray *c10_lhs4 = NULL;
  const mxArray *c10_rhs5 = NULL;
  const mxArray *c10_lhs5 = NULL;
  const mxArray *c10_rhs6 = NULL;
  const mxArray *c10_lhs6 = NULL;
  const mxArray *c10_rhs7 = NULL;
  const mxArray *c10_lhs7 = NULL;
  const mxArray *c10_rhs8 = NULL;
  const mxArray *c10_lhs8 = NULL;
  const mxArray *c10_rhs9 = NULL;
  const mxArray *c10_lhs9 = NULL;
  const mxArray *c10_rhs10 = NULL;
  const mxArray *c10_lhs10 = NULL;
  const mxArray *c10_rhs11 = NULL;
  const mxArray *c10_lhs11 = NULL;
  const mxArray *c10_rhs12 = NULL;
  const mxArray *c10_lhs12 = NULL;
  const mxArray *c10_rhs13 = NULL;
  const mxArray *c10_lhs13 = NULL;
  const mxArray *c10_rhs14 = NULL;
  const mxArray *c10_lhs14 = NULL;
  const mxArray *c10_rhs15 = NULL;
  const mxArray *c10_lhs15 = NULL;
  const mxArray *c10_rhs16 = NULL;
  const mxArray *c10_lhs16 = NULL;
  const mxArray *c10_rhs17 = NULL;
  const mxArray *c10_lhs17 = NULL;
  const mxArray *c10_rhs18 = NULL;
  const mxArray *c10_lhs18 = NULL;
  const mxArray *c10_rhs19 = NULL;
  const mxArray *c10_lhs19 = NULL;
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("mrdivide"), "name", "name",
                  0);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1388481696U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1370031486U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c10_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 1);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 1);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1363732556U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c10_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 2);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("rdivide"), "name", "name", 2);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1363731880U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c10_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 3);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1363732556U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c10_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 4);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1286840396U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c10_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_div"), "name", "name", 5);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c10_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 6);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1389329520U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c10_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(""), "context", "context", 7);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 7);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1383898894U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c10_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 8);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 8);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1363732556U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c10_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 9);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 9);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c10_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 10);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 10);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 10);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c10_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 11);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1389329520U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c10_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 12);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_xgemm"), "name", "name",
                  12);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1376002290U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c10_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 13);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 13);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1389329522U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c10_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 14);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("coder.internal.blas.xgemm"),
                  "name", "name", 14);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1389329522U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c10_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 15);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 15);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1389329522U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c10_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p!below_threshold"),
                  "context", "context", 16);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 16);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1389329522U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c10_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "context", "context", 17);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 17);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1381871900U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c10_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 18);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 18);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1389329520U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c10_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 19);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "coder.internal.refblas.xgemm"), "name", "name", 19);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgemm.p"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1389329522U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c10_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs19), "lhs", "lhs",
                  19);
  sf_mex_destroy(&c10_rhs0);
  sf_mex_destroy(&c10_lhs0);
  sf_mex_destroy(&c10_rhs1);
  sf_mex_destroy(&c10_lhs1);
  sf_mex_destroy(&c10_rhs2);
  sf_mex_destroy(&c10_lhs2);
  sf_mex_destroy(&c10_rhs3);
  sf_mex_destroy(&c10_lhs3);
  sf_mex_destroy(&c10_rhs4);
  sf_mex_destroy(&c10_lhs4);
  sf_mex_destroy(&c10_rhs5);
  sf_mex_destroy(&c10_lhs5);
  sf_mex_destroy(&c10_rhs6);
  sf_mex_destroy(&c10_lhs6);
  sf_mex_destroy(&c10_rhs7);
  sf_mex_destroy(&c10_lhs7);
  sf_mex_destroy(&c10_rhs8);
  sf_mex_destroy(&c10_lhs8);
  sf_mex_destroy(&c10_rhs9);
  sf_mex_destroy(&c10_lhs9);
  sf_mex_destroy(&c10_rhs10);
  sf_mex_destroy(&c10_lhs10);
  sf_mex_destroy(&c10_rhs11);
  sf_mex_destroy(&c10_lhs11);
  sf_mex_destroy(&c10_rhs12);
  sf_mex_destroy(&c10_lhs12);
  sf_mex_destroy(&c10_rhs13);
  sf_mex_destroy(&c10_lhs13);
  sf_mex_destroy(&c10_rhs14);
  sf_mex_destroy(&c10_lhs14);
  sf_mex_destroy(&c10_rhs15);
  sf_mex_destroy(&c10_lhs15);
  sf_mex_destroy(&c10_rhs16);
  sf_mex_destroy(&c10_lhs16);
  sf_mex_destroy(&c10_rhs17);
  sf_mex_destroy(&c10_lhs17);
  sf_mex_destroy(&c10_rhs18);
  sf_mex_destroy(&c10_lhs18);
  sf_mex_destroy(&c10_rhs19);
  sf_mex_destroy(&c10_lhs19);
}

static const mxArray *c10_emlrt_marshallOut(const char * c10_u)
{
  const mxArray *c10_y = NULL;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c10_u)), false);
  return c10_y;
}

static const mxArray *c10_b_emlrt_marshallOut(const uint32_T c10_u)
{
  const mxArray *c10_y = NULL;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", &c10_u, 7, 0U, 0U, 0U, 0), false);
  return c10_y;
}

static void c10_eml_scalar_eg(SFc10_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c10_eml_xgemm(SFc10_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, real_T c10_A[9], real_T c10_B[3], real_T c10_C[3], real_T
  c10_b_C[3])
{
  int32_T c10_i51;
  int32_T c10_i52;
  real_T c10_b_A[9];
  int32_T c10_i53;
  real_T c10_b_B[3];
  for (c10_i51 = 0; c10_i51 < 3; c10_i51++) {
    c10_b_C[c10_i51] = c10_C[c10_i51];
  }

  for (c10_i52 = 0; c10_i52 < 9; c10_i52++) {
    c10_b_A[c10_i52] = c10_A[c10_i52];
  }

  for (c10_i53 = 0; c10_i53 < 3; c10_i53++) {
    c10_b_B[c10_i53] = c10_B[c10_i53];
  }

  c10_b_eml_xgemm(chartInstance, c10_b_A, c10_b_B, c10_b_C);
}

static const mxArray *c10_e_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_u;
  const mxArray *c10_y = NULL;
  SFc10_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance;
  chartInstance = (SFc10_SmAHTR_r1_PITTRTNUKEInstanceStruct *)chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  c10_u = *(int32_T *)c10_inData;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", &c10_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static int32_T c10_e_emlrt_marshallIn(SFc10_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId)
{
  int32_T c10_y;
  int32_T c10_i54;
  (void)chartInstance;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), &c10_i54, 1, 6, 0U, 0, 0U, 0);
  c10_y = c10_i54;
  sf_mex_destroy(&c10_u);
  return c10_y;
}

static void c10_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_b_sfEvent;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  int32_T c10_y;
  SFc10_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance;
  chartInstance = (SFc10_SmAHTR_r1_PITTRTNUKEInstanceStruct *)chartInstanceVoid;
  c10_b_sfEvent = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_b_sfEvent),
    &c10_thisId);
  sf_mex_destroy(&c10_b_sfEvent);
  *(int32_T *)c10_outData = c10_y;
  sf_mex_destroy(&c10_mxArrayInData);
}

static uint8_T c10_f_emlrt_marshallIn(SFc10_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c10_b_is_active_c10_SmAHTR_r1_PITTRTNUKE, const
  char_T *c10_identifier)
{
  uint8_T c10_y;
  emlrtMsgIdentifier c10_thisId;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c10_b_is_active_c10_SmAHTR_r1_PITTRTNUKE), &c10_thisId);
  sf_mex_destroy(&c10_b_is_active_c10_SmAHTR_r1_PITTRTNUKE);
  return c10_y;
}

static uint8_T c10_g_emlrt_marshallIn(SFc10_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId)
{
  uint8_T c10_y;
  uint8_T c10_u0;
  (void)chartInstance;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), &c10_u0, 1, 3, 0U, 0, 0U, 0);
  c10_y = c10_u0;
  sf_mex_destroy(&c10_u);
  return c10_y;
}

static void c10_b_eml_xgemm(SFc10_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, real_T c10_A[9], real_T c10_B[3], real_T c10_C[3])
{
  int32_T c10_i55;
  int32_T c10_i56;
  int32_T c10_i57;
  (void)chartInstance;
  for (c10_i55 = 0; c10_i55 < 3; c10_i55++) {
    c10_C[c10_i55] = 0.0;
    c10_i56 = 0;
    for (c10_i57 = 0; c10_i57 < 3; c10_i57++) {
      c10_C[c10_i55] += c10_A[c10_i56 + c10_i55] * c10_B[c10_i57];
      c10_i56 += 3;
    }
  }
}

static void init_dsm_address_info(SFc10_SmAHTR_r1_PITTRTNUKEInstanceStruct
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

void sf_c10_SmAHTR_r1_PITTRTNUKE_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2323538981U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2094276284U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(573518334U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(42988306U);
}

mxArray *sf_c10_SmAHTR_r1_PITTRTNUKE_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("lf7t7Rt4ZrfaZZbf2gjERB");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,7,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
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
      pr[0] = (double)(3);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c10_SmAHTR_r1_PITTRTNUKE_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c10_SmAHTR_r1_PITTRTNUKE_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c10_SmAHTR_r1_PITTRTNUKE(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[5],T\"x_dot\",},{M[1],M[10],T\"y\",},{M[8],M[0],T\"is_active_c10_SmAHTR_r1_PITTRTNUKE\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c10_SmAHTR_r1_PITTRTNUKE_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc10_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc10_SmAHTR_r1_PITTRTNUKEInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _SmAHTR_r1_PITTRTNUKEMachineNumber_,
           10,
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
          _SFD_SET_DATA_PROPS(1,1,1,0,"mdots");
          _SFD_SET_DATA_PROPS(2,2,0,1,"x_dot");
          _SFD_SET_DATA_PROPS(3,1,1,0,"mdott");
          _SFD_SET_DATA_PROPS(4,1,1,0,"T_s1");
          _SFD_SET_DATA_PROPS(5,1,1,0,"T_t1");
          _SFD_SET_DATA_PROPS(6,1,1,0,"constants");
          _SFD_SET_DATA_PROPS(7,1,1,0,"Tamb");
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
        _SFD_CV_INIT_EML(0,1,1,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1089);
        _SFD_CV_INIT_EML_IF(0,1,0,616,628,660,693);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c10_sf_marshallOut,(MexInFcnForType)
            c10_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c10_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c10_sf_marshallOut,(MexInFcnForType)
            c10_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c10_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c10_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c10_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c10_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c10_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c10_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          real_T *c10_mdots;
          real_T *c10_mdott;
          real_T *c10_T_s1;
          real_T *c10_T_t1;
          real_T *c10_Tamb;
          real_T (*c10_y)[3];
          real_T (*c10_x_dot)[3];
          real_T (*c10_constants)[4];
          real_T (*c10_x)[3];
          c10_x = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 6);
          c10_Tamb = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c10_constants = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S,
            4);
          c10_T_t1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c10_T_s1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c10_mdott = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c10_x_dot = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
          c10_mdots = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          c10_y = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, *c10_y);
          _SFD_SET_DATA_VALUE_PTR(1U, c10_mdots);
          _SFD_SET_DATA_VALUE_PTR(2U, *c10_x_dot);
          _SFD_SET_DATA_VALUE_PTR(3U, c10_mdott);
          _SFD_SET_DATA_VALUE_PTR(4U, c10_T_s1);
          _SFD_SET_DATA_VALUE_PTR(5U, c10_T_t1);
          _SFD_SET_DATA_VALUE_PTR(6U, *c10_constants);
          _SFD_SET_DATA_VALUE_PTR(7U, c10_Tamb);
          _SFD_SET_DATA_VALUE_PTR(8U, *c10_x);
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
  return "VvOEM7HRXX25GtWAJ0XI2F";
}

static void sf_opaque_initialize_c10_SmAHTR_r1_PITTRTNUKE(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc10_SmAHTR_r1_PITTRTNUKEInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c10_SmAHTR_r1_PITTRTNUKE
    ((SFc10_SmAHTR_r1_PITTRTNUKEInstanceStruct*) chartInstanceVar);
  initialize_c10_SmAHTR_r1_PITTRTNUKE((SFc10_SmAHTR_r1_PITTRTNUKEInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c10_SmAHTR_r1_PITTRTNUKE(void *chartInstanceVar)
{
  enable_c10_SmAHTR_r1_PITTRTNUKE((SFc10_SmAHTR_r1_PITTRTNUKEInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c10_SmAHTR_r1_PITTRTNUKE(void *chartInstanceVar)
{
  disable_c10_SmAHTR_r1_PITTRTNUKE((SFc10_SmAHTR_r1_PITTRTNUKEInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c10_SmAHTR_r1_PITTRTNUKE(void *chartInstanceVar)
{
  sf_gateway_c10_SmAHTR_r1_PITTRTNUKE((SFc10_SmAHTR_r1_PITTRTNUKEInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c10_SmAHTR_r1_PITTRTNUKE
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c10_SmAHTR_r1_PITTRTNUKE
    ((SFc10_SmAHTR_r1_PITTRTNUKEInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c10_SmAHTR_r1_PITTRTNUKE();/* state var info */
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

extern void sf_internal_set_sim_state_c10_SmAHTR_r1_PITTRTNUKE(SimStruct* S,
  const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c10_SmAHTR_r1_PITTRTNUKE();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c10_SmAHTR_r1_PITTRTNUKE
    ((SFc10_SmAHTR_r1_PITTRTNUKEInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c10_SmAHTR_r1_PITTRTNUKE(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c10_SmAHTR_r1_PITTRTNUKE(S);
}

static void sf_opaque_set_sim_state_c10_SmAHTR_r1_PITTRTNUKE(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c10_SmAHTR_r1_PITTRTNUKE(S, st);
}

static void sf_opaque_terminate_c10_SmAHTR_r1_PITTRTNUKE(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc10_SmAHTR_r1_PITTRTNUKEInstanceStruct*) chartInstanceVar)
      ->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_SmAHTR_r1_PITTRTNUKE_optimization_info();
    }

    finalize_c10_SmAHTR_r1_PITTRTNUKE((SFc10_SmAHTR_r1_PITTRTNUKEInstanceStruct*)
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
  initSimStructsc10_SmAHTR_r1_PITTRTNUKE
    ((SFc10_SmAHTR_r1_PITTRTNUKEInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c10_SmAHTR_r1_PITTRTNUKE(SimStruct *S)
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
    initialize_params_c10_SmAHTR_r1_PITTRTNUKE
      ((SFc10_SmAHTR_r1_PITTRTNUKEInstanceStruct*)(chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c10_SmAHTR_r1_PITTRTNUKE(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_SmAHTR_r1_PITTRTNUKE_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      10);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,10,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,10,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,10);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,10,7);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,10,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 7; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,10);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3649097020U));
  ssSetChecksum1(S,(40642646U));
  ssSetChecksum2(S,(1468772421U));
  ssSetChecksum3(S,(3510299735U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c10_SmAHTR_r1_PITTRTNUKE(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c10_SmAHTR_r1_PITTRTNUKE(SimStruct *S)
{
  SFc10_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc10_SmAHTR_r1_PITTRTNUKEInstanceStruct *)utMalloc(sizeof
    (SFc10_SmAHTR_r1_PITTRTNUKEInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc10_SmAHTR_r1_PITTRTNUKEInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c10_SmAHTR_r1_PITTRTNUKE;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c10_SmAHTR_r1_PITTRTNUKE;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c10_SmAHTR_r1_PITTRTNUKE;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c10_SmAHTR_r1_PITTRTNUKE;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c10_SmAHTR_r1_PITTRTNUKE;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c10_SmAHTR_r1_PITTRTNUKE;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c10_SmAHTR_r1_PITTRTNUKE;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c10_SmAHTR_r1_PITTRTNUKE;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c10_SmAHTR_r1_PITTRTNUKE;
  chartInstance->chartInfo.mdlStart = mdlStart_c10_SmAHTR_r1_PITTRTNUKE;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c10_SmAHTR_r1_PITTRTNUKE;
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

void c10_SmAHTR_r1_PITTRTNUKE_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c10_SmAHTR_r1_PITTRTNUKE(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c10_SmAHTR_r1_PITTRTNUKE(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c10_SmAHTR_r1_PITTRTNUKE(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c10_SmAHTR_r1_PITTRTNUKE_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
