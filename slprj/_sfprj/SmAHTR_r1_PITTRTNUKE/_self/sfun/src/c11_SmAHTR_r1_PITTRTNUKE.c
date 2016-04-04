/* Include files */

#include <stddef.h>
#include "blas.h"
#include "SmAHTR_r1_PITTRTNUKE_sfun.h"
#include "c11_SmAHTR_r1_PITTRTNUKE.h"
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
static const char * c11_debug_family_names[35] = { "N1", "N2", "D1", "D2",
  "Beta", "B1", "B2", "B3", "B4", "B5", "B6", "L1", "L2", "L3", "L4", "L5", "L6",
  "lambda", "alpha", "rho_1", "rho_2", "rho_t", "A", "C", "nargin", "nargout",
  "PROMPTN1", "PROMPTN2", "DELAYEDN1", "DELAYEDN2", "pkeparams", "rho_temp", "x",
  "y", "xdot" };

/* Function Declarations */
static void initialize_c11_SmAHTR_r1_PITTRTNUKE
  (SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance);
static void initialize_params_c11_SmAHTR_r1_PITTRTNUKE
  (SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance);
static void enable_c11_SmAHTR_r1_PITTRTNUKE
  (SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance);
static void disable_c11_SmAHTR_r1_PITTRTNUKE
  (SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance);
static void c11_update_debugger_state_c11_SmAHTR_r1_PITTRTNUKE
  (SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c11_SmAHTR_r1_PITTRTNUKE
  (SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance);
static void set_sim_state_c11_SmAHTR_r1_PITTRTNUKE
  (SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance, const mxArray
   *c11_st);
static void finalize_c11_SmAHTR_r1_PITTRTNUKE
  (SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance);
static void sf_gateway_c11_SmAHTR_r1_PITTRTNUKE
  (SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance);
static void c11_chartstep_c11_SmAHTR_r1_PITTRTNUKE
  (SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance);
static void initSimStructsc11_SmAHTR_r1_PITTRTNUKE
  (SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c11_machineNumber, uint32_T
  c11_chartNumber, uint32_T c11_instanceNumber);
static const mxArray *c11_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static void c11_emlrt_marshallIn(SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c11_xdot, const char_T *c11_identifier, real_T
  c11_y[3]);
static void c11_b_emlrt_marshallIn(SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[3]);
static void c11_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_b_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static void c11_c_emlrt_marshallIn(SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c11_y, const char_T *c11_identifier, real_T
  c11_b_y[2]);
static void c11_d_emlrt_marshallIn(SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[2]);
static void c11_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_c_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static const mxArray *c11_d_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static real_T c11_e_emlrt_marshallIn(SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_e_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static void c11_f_emlrt_marshallIn(SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[6]);
static void c11_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_f_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static void c11_g_emlrt_marshallIn(SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[9]);
static void c11_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static void c11_info_helper(const mxArray **c11_info);
static const mxArray *c11_emlrt_marshallOut(const char * c11_u);
static const mxArray *c11_b_emlrt_marshallOut(const uint32_T c11_u);
static void c11_eml_scalar_eg(SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance);
static void c11_threshold(SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance);
static void c11_b_eml_scalar_eg(SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance);
static const mxArray *c11_g_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static int32_T c11_h_emlrt_marshallIn(SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static uint8_T c11_i_emlrt_marshallIn(SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c11_b_is_active_c11_SmAHTR_r1_PITTRTNUKE, const
  char_T *c11_identifier);
static uint8_T c11_j_emlrt_marshallIn(SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void init_dsm_address_info(SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c11_SmAHTR_r1_PITTRTNUKE
  (SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance)
{
  chartInstance->c11_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c11_is_active_c11_SmAHTR_r1_PITTRTNUKE = 0U;
}

static void initialize_params_c11_SmAHTR_r1_PITTRTNUKE
  (SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c11_SmAHTR_r1_PITTRTNUKE
  (SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c11_SmAHTR_r1_PITTRTNUKE
  (SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c11_update_debugger_state_c11_SmAHTR_r1_PITTRTNUKE
  (SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c11_SmAHTR_r1_PITTRTNUKE
  (SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance)
{
  const mxArray *c11_st;
  const mxArray *c11_y = NULL;
  int32_T c11_i0;
  real_T c11_u[3];
  const mxArray *c11_b_y = NULL;
  int32_T c11_i1;
  real_T c11_b_u[2];
  const mxArray *c11_c_y = NULL;
  uint8_T c11_hoistedGlobal;
  uint8_T c11_c_u;
  const mxArray *c11_d_y = NULL;
  real_T (*c11_e_y)[2];
  real_T (*c11_xdot)[3];
  c11_xdot = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c11_e_y = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 1);
  c11_st = NULL;
  c11_st = NULL;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_createcellmatrix(3, 1), false);
  for (c11_i0 = 0; c11_i0 < 3; c11_i0++) {
    c11_u[c11_i0] = (*c11_xdot)[c11_i0];
  }

  c11_b_y = NULL;
  sf_mex_assign(&c11_b_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_setcell(c11_y, 0, c11_b_y);
  for (c11_i1 = 0; c11_i1 < 2; c11_i1++) {
    c11_b_u[c11_i1] = (*c11_e_y)[c11_i1];
  }

  c11_c_y = NULL;
  sf_mex_assign(&c11_c_y, sf_mex_create("y", c11_b_u, 0, 0U, 1U, 0U, 1, 2),
                false);
  sf_mex_setcell(c11_y, 1, c11_c_y);
  c11_hoistedGlobal = chartInstance->c11_is_active_c11_SmAHTR_r1_PITTRTNUKE;
  c11_c_u = c11_hoistedGlobal;
  c11_d_y = NULL;
  sf_mex_assign(&c11_d_y, sf_mex_create("y", &c11_c_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c11_y, 2, c11_d_y);
  sf_mex_assign(&c11_st, c11_y, false);
  return c11_st;
}

static void set_sim_state_c11_SmAHTR_r1_PITTRTNUKE
  (SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance, const mxArray
   *c11_st)
{
  const mxArray *c11_u;
  real_T c11_dv0[3];
  int32_T c11_i2;
  real_T c11_dv1[2];
  int32_T c11_i3;
  real_T (*c11_xdot)[3];
  real_T (*c11_y)[2];
  c11_xdot = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c11_y = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c11_doneDoubleBufferReInit = true;
  c11_u = sf_mex_dup(c11_st);
  c11_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c11_u, 0)),
                       "xdot", c11_dv0);
  for (c11_i2 = 0; c11_i2 < 3; c11_i2++) {
    (*c11_xdot)[c11_i2] = c11_dv0[c11_i2];
  }

  c11_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c11_u, 1)),
    "y", c11_dv1);
  for (c11_i3 = 0; c11_i3 < 2; c11_i3++) {
    (*c11_y)[c11_i3] = c11_dv1[c11_i3];
  }

  chartInstance->c11_is_active_c11_SmAHTR_r1_PITTRTNUKE = c11_i_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c11_u, 2)),
     "is_active_c11_SmAHTR_r1_PITTRTNUKE");
  sf_mex_destroy(&c11_u);
  c11_update_debugger_state_c11_SmAHTR_r1_PITTRTNUKE(chartInstance);
  sf_mex_destroy(&c11_st);
}

static void finalize_c11_SmAHTR_r1_PITTRTNUKE
  (SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c11_SmAHTR_r1_PITTRTNUKE
  (SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance)
{
  int32_T c11_i4;
  int32_T c11_i5;
  int32_T c11_i6;
  int32_T c11_i7;
  real_T *c11_PROMPTN1;
  real_T *c11_PROMPTN2;
  real_T *c11_DELAYEDN1;
  real_T *c11_DELAYEDN2;
  real_T *c11_rho_temp;
  real_T (*c11_xdot)[3];
  real_T (*c11_y)[2];
  real_T (*c11_x)[3];
  real_T (*c11_pkeparams)[14];
  c11_xdot = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c11_y = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 1);
  c11_x = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 6);
  c11_rho_temp = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c11_pkeparams = (real_T (*)[14])ssGetInputPortSignal(chartInstance->S, 4);
  c11_DELAYEDN2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c11_DELAYEDN1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c11_PROMPTN2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c11_PROMPTN1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 9U, chartInstance->c11_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c11_PROMPTN1, 0U);
  _SFD_DATA_RANGE_CHECK(*c11_PROMPTN2, 1U);
  _SFD_DATA_RANGE_CHECK(*c11_DELAYEDN1, 2U);
  _SFD_DATA_RANGE_CHECK(*c11_DELAYEDN2, 3U);
  for (c11_i4 = 0; c11_i4 < 14; c11_i4++) {
    _SFD_DATA_RANGE_CHECK((*c11_pkeparams)[c11_i4], 4U);
  }

  _SFD_DATA_RANGE_CHECK(*c11_rho_temp, 5U);
  for (c11_i5 = 0; c11_i5 < 3; c11_i5++) {
    _SFD_DATA_RANGE_CHECK((*c11_x)[c11_i5], 6U);
  }

  chartInstance->c11_sfEvent = CALL_EVENT;
  c11_chartstep_c11_SmAHTR_r1_PITTRTNUKE(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_SmAHTR_r1_PITTRTNUKEMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c11_i6 = 0; c11_i6 < 2; c11_i6++) {
    _SFD_DATA_RANGE_CHECK((*c11_y)[c11_i6], 7U);
  }

  for (c11_i7 = 0; c11_i7 < 3; c11_i7++) {
    _SFD_DATA_RANGE_CHECK((*c11_xdot)[c11_i7], 8U);
  }
}

static void c11_chartstep_c11_SmAHTR_r1_PITTRTNUKE
  (SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance)
{
  real_T c11_hoistedGlobal;
  real_T c11_b_hoistedGlobal;
  real_T c11_c_hoistedGlobal;
  real_T c11_d_hoistedGlobal;
  real_T c11_e_hoistedGlobal;
  real_T c11_PROMPTN1;
  real_T c11_PROMPTN2;
  real_T c11_DELAYEDN1;
  real_T c11_DELAYEDN2;
  int32_T c11_i8;
  real_T c11_pkeparams[14];
  real_T c11_rho_temp;
  int32_T c11_i9;
  real_T c11_x[3];
  uint32_T c11_debug_family_var_map[35];
  real_T c11_N1;
  real_T c11_N2;
  real_T c11_D1;
  real_T c11_D2;
  real_T c11_Beta;
  real_T c11_B1;
  real_T c11_B2;
  real_T c11_B3;
  real_T c11_B4;
  real_T c11_B5;
  real_T c11_B6;
  real_T c11_L1;
  real_T c11_L2;
  real_T c11_L3;
  real_T c11_L4;
  real_T c11_L5;
  real_T c11_L6;
  real_T c11_lambda;
  real_T c11_alpha;
  real_T c11_rho_1;
  real_T c11_rho_2;
  real_T c11_rho_t;
  real_T c11_A[9];
  real_T c11_C[6];
  real_T c11_nargin = 7.0;
  real_T c11_nargout = 2.0;
  real_T c11_y[2];
  real_T c11_xdot[3];
  real_T c11_b_A;
  real_T c11_B;
  real_T c11_b_x;
  real_T c11_b_y;
  real_T c11_c_x;
  real_T c11_c_y;
  real_T c11_d_x;
  real_T c11_d_y;
  real_T c11_c_A;
  real_T c11_b_B;
  real_T c11_e_x;
  real_T c11_e_y;
  real_T c11_f_x;
  real_T c11_f_y;
  real_T c11_g_x;
  real_T c11_g_y;
  real_T c11_h_y;
  real_T c11_c_B;
  real_T c11_i_y;
  real_T c11_j_y;
  real_T c11_k_y;
  real_T c11_l_y;
  real_T c11_d_A;
  real_T c11_d_B;
  real_T c11_h_x;
  real_T c11_m_y;
  real_T c11_i_x;
  real_T c11_n_y;
  real_T c11_j_x;
  real_T c11_o_y;
  real_T c11_p_y;
  real_T c11_e_A;
  real_T c11_e_B;
  real_T c11_k_x;
  real_T c11_q_y;
  real_T c11_l_x;
  real_T c11_r_y;
  real_T c11_m_x;
  real_T c11_s_y;
  real_T c11_t_y;
  real_T c11_f_B;
  real_T c11_u_y;
  real_T c11_v_y;
  real_T c11_w_y;
  real_T c11_x_y;
  real_T c11_f_A;
  real_T c11_g_B;
  real_T c11_n_x;
  real_T c11_y_y;
  real_T c11_o_x;
  real_T c11_ab_y;
  real_T c11_p_x;
  real_T c11_bb_y;
  real_T c11_cb_y;
  real_T c11_g_A;
  real_T c11_h_B;
  real_T c11_q_x;
  real_T c11_db_y;
  real_T c11_r_x;
  real_T c11_eb_y;
  real_T c11_s_x;
  real_T c11_fb_y;
  real_T c11_gb_y;
  real_T c11_h_A;
  real_T c11_i_B;
  real_T c11_t_x;
  real_T c11_hb_y;
  real_T c11_u_x;
  real_T c11_ib_y;
  real_T c11_v_x;
  real_T c11_jb_y;
  real_T c11_kb_y;
  real_T c11_i_A;
  real_T c11_j_B;
  real_T c11_w_x;
  real_T c11_lb_y;
  real_T c11_x_x;
  real_T c11_mb_y;
  real_T c11_y_x;
  real_T c11_nb_y;
  real_T c11_ob_y;
  int32_T c11_i10;
  int32_T c11_i11;
  static real_T c11_dv2[3] = { 1.0, 0.0, 0.0 };

  int32_T c11_i12;
  int32_T c11_i13;
  real_T c11_a[9];
  int32_T c11_i14;
  real_T c11_b[3];
  int32_T c11_i15;
  int32_T c11_i16;
  int32_T c11_i17;
  real_T c11_b_C[3];
  int32_T c11_i18;
  int32_T c11_i19;
  int32_T c11_i20;
  int32_T c11_i21;
  int32_T c11_i22;
  int32_T c11_i23;
  int32_T c11_i24;
  int32_T c11_i25;
  real_T c11_b_a[6];
  int32_T c11_i26;
  int32_T c11_i27;
  int32_T c11_i28;
  int32_T c11_i29;
  real_T c11_c_C[2];
  int32_T c11_i30;
  int32_T c11_i31;
  int32_T c11_i32;
  int32_T c11_i33;
  int32_T c11_i34;
  int32_T c11_i35;
  int32_T c11_i36;
  int32_T c11_i37;
  real_T *c11_b_PROMPTN1;
  real_T *c11_b_PROMPTN2;
  real_T *c11_b_DELAYEDN1;
  real_T *c11_b_DELAYEDN2;
  real_T *c11_b_rho_temp;
  real_T (*c11_pb_y)[2];
  real_T (*c11_b_xdot)[3];
  real_T (*c11_ab_x)[3];
  real_T (*c11_b_pkeparams)[14];
  c11_b_xdot = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c11_pb_y = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 1);
  c11_ab_x = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 6);
  c11_b_rho_temp = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c11_b_pkeparams = (real_T (*)[14])ssGetInputPortSignal(chartInstance->S, 4);
  c11_b_DELAYEDN2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c11_b_DELAYEDN1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c11_b_PROMPTN2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c11_b_PROMPTN1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 9U, chartInstance->c11_sfEvent);
  c11_hoistedGlobal = *c11_b_PROMPTN1;
  c11_b_hoistedGlobal = *c11_b_PROMPTN2;
  c11_c_hoistedGlobal = *c11_b_DELAYEDN1;
  c11_d_hoistedGlobal = *c11_b_DELAYEDN2;
  c11_e_hoistedGlobal = *c11_b_rho_temp;
  c11_PROMPTN1 = c11_hoistedGlobal;
  c11_PROMPTN2 = c11_b_hoistedGlobal;
  c11_DELAYEDN1 = c11_c_hoistedGlobal;
  c11_DELAYEDN2 = c11_d_hoistedGlobal;
  for (c11_i8 = 0; c11_i8 < 14; c11_i8++) {
    c11_pkeparams[c11_i8] = (*c11_b_pkeparams)[c11_i8];
  }

  c11_rho_temp = c11_e_hoistedGlobal;
  for (c11_i9 = 0; c11_i9 < 3; c11_i9++) {
    c11_x[c11_i9] = (*c11_ab_x)[c11_i9];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 35U, 35U, c11_debug_family_names,
    c11_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_N1, 0U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_N2, 1U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_D1, 2U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_D2, 3U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_Beta, 4U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_B1, 5U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_B2, 6U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_B3, 7U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_B4, 8U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_B5, 9U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_B6, 10U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_L1, 11U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_L2, 12U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_L3, 13U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_L4, 14U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_L5, 15U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_L6, 16U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_lambda, 17U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_alpha, 18U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_rho_1, 19U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_rho_2, 20U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_rho_t, 21U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_A, 22U, c11_f_sf_marshallOut,
    c11_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_C, 23U, c11_e_sf_marshallOut,
    c11_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargin, 24U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargout, 25U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c11_PROMPTN1, 26U, c11_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c11_PROMPTN2, 27U, c11_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c11_DELAYEDN1, 28U, c11_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c11_DELAYEDN2, 29U, c11_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c11_pkeparams, 30U, c11_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c11_rho_temp, 31U, c11_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c11_x, 32U, c11_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_y, 33U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_xdot, 34U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 9);
  c11_N1 = c11_PROMPTN1;
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 10);
  c11_N2 = c11_PROMPTN2;
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 17);
  c11_D1 = c11_DELAYEDN1;
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 18);
  c11_D2 = c11_DELAYEDN2;
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 25);
  c11_Beta = c11_pkeparams[0];
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 25);
  c11_B1 = c11_pkeparams[1];
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 25);
  c11_B2 = c11_pkeparams[2];
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 25);
  c11_B3 = c11_pkeparams[3];
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 26);
  c11_B4 = c11_pkeparams[4];
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 26);
  c11_B5 = c11_pkeparams[5];
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 26);
  c11_B6 = c11_pkeparams[6];
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 26);
  c11_L1 = c11_pkeparams[7];
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 27);
  c11_L2 = c11_pkeparams[8];
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 27);
  c11_L3 = c11_pkeparams[9];
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 27);
  c11_L4 = c11_pkeparams[10];
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 27);
  c11_L5 = c11_pkeparams[11];
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 28);
  c11_L6 = c11_pkeparams[12];
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 28);
  c11_lambda = c11_pkeparams[13];
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 31);
  c11_b_A = 1.0 - c11_Beta;
  c11_B = c11_lambda;
  c11_b_x = c11_b_A;
  c11_b_y = c11_B;
  c11_c_x = c11_b_x;
  c11_c_y = c11_b_y;
  c11_d_x = c11_c_x;
  c11_d_y = c11_c_y;
  c11_alpha = c11_d_x / c11_d_y;
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 33);
  c11_c_A = c11_N1;
  c11_b_B = c11_x[0];
  c11_e_x = c11_c_A;
  c11_e_y = c11_b_B;
  c11_f_x = c11_e_x;
  c11_f_y = c11_e_y;
  c11_g_x = c11_f_x;
  c11_g_y = c11_f_y;
  c11_h_y = c11_g_x / c11_g_y;
  c11_c_B = c11_lambda;
  c11_i_y = c11_c_B;
  c11_j_y = c11_i_y;
  c11_k_y = c11_j_y;
  c11_l_y = 1.0 / c11_k_y;
  c11_d_A = 0.002 * c11_l_y * c11_D1;
  c11_d_B = c11_x[0];
  c11_h_x = c11_d_A;
  c11_m_y = c11_d_B;
  c11_i_x = c11_h_x;
  c11_n_y = c11_m_y;
  c11_j_x = c11_i_x;
  c11_o_y = c11_n_y;
  c11_p_y = c11_j_x / c11_o_y;
  c11_rho_1 = c11_lambda * 0.002 * (c11_alpha * c11_h_y + c11_p_y);
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 34);
  c11_e_A = c11_N2;
  c11_e_B = c11_x[0];
  c11_k_x = c11_e_A;
  c11_q_y = c11_e_B;
  c11_l_x = c11_k_x;
  c11_r_y = c11_q_y;
  c11_m_x = c11_l_x;
  c11_s_y = c11_r_y;
  c11_t_y = c11_m_x / c11_s_y;
  c11_f_B = c11_lambda;
  c11_u_y = c11_f_B;
  c11_v_y = c11_u_y;
  c11_w_y = c11_v_y;
  c11_x_y = 1.0 / c11_w_y;
  c11_f_A = 0.005 * c11_x_y * c11_D2;
  c11_g_B = c11_x[0];
  c11_n_x = c11_f_A;
  c11_y_y = c11_g_B;
  c11_o_x = c11_n_x;
  c11_ab_y = c11_y_y;
  c11_p_x = c11_o_x;
  c11_bb_y = c11_ab_y;
  c11_cb_y = c11_p_x / c11_bb_y;
  c11_rho_2 = c11_lambda * 0.005 * (c11_alpha * c11_t_y + c11_cb_y);
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 51);
  c11_rho_t = (c11_rho_temp + c11_rho_1) + c11_rho_2;
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 53);
  c11_g_A = c11_rho_t - c11_Beta;
  c11_h_B = c11_lambda;
  c11_q_x = c11_g_A;
  c11_db_y = c11_h_B;
  c11_r_x = c11_q_x;
  c11_eb_y = c11_db_y;
  c11_s_x = c11_r_x;
  c11_fb_y = c11_eb_y;
  c11_gb_y = c11_s_x / c11_fb_y;
  c11_h_A = c11_L1;
  c11_i_B = c11_lambda;
  c11_t_x = c11_h_A;
  c11_hb_y = c11_i_B;
  c11_u_x = c11_t_x;
  c11_ib_y = c11_hb_y;
  c11_v_x = c11_u_x;
  c11_jb_y = c11_ib_y;
  c11_kb_y = c11_v_x / c11_jb_y;
  c11_i_A = c11_L2;
  c11_j_B = c11_lambda;
  c11_w_x = c11_i_A;
  c11_lb_y = c11_j_B;
  c11_x_x = c11_w_x;
  c11_mb_y = c11_lb_y;
  c11_y_x = c11_x_x;
  c11_nb_y = c11_mb_y;
  c11_ob_y = c11_y_x / c11_nb_y;
  c11_A[0] = c11_gb_y;
  c11_A[3] = c11_kb_y;
  c11_A[6] = c11_ob_y;
  c11_A[1] = c11_B1;
  c11_A[4] = -c11_L1;
  c11_A[7] = 0.0;
  c11_A[2] = c11_B2;
  c11_A[5] = 0.0;
  c11_A[8] = -c11_L2;
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 57);
  c11_i10 = 0;
  for (c11_i11 = 0; c11_i11 < 3; c11_i11++) {
    c11_C[c11_i10] = c11_dv2[c11_i11];
    c11_i10 += 2;
  }

  c11_C[1] = 0.0;
  c11_C[3] = c11_L1;
  c11_C[5] = c11_L2;
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 60);
  for (c11_i12 = 0; c11_i12 < 3; c11_i12++) {
    c11_xdot[c11_i12] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 61);
  for (c11_i13 = 0; c11_i13 < 9; c11_i13++) {
    c11_a[c11_i13] = c11_A[c11_i13];
  }

  for (c11_i14 = 0; c11_i14 < 3; c11_i14++) {
    c11_b[c11_i14] = c11_x[c11_i14];
  }

  c11_eml_scalar_eg(chartInstance);
  c11_eml_scalar_eg(chartInstance);
  for (c11_i15 = 0; c11_i15 < 3; c11_i15++) {
    c11_xdot[c11_i15] = 0.0;
  }

  for (c11_i16 = 0; c11_i16 < 3; c11_i16++) {
    c11_xdot[c11_i16] = 0.0;
  }

  for (c11_i17 = 0; c11_i17 < 3; c11_i17++) {
    c11_b_C[c11_i17] = c11_xdot[c11_i17];
  }

  for (c11_i18 = 0; c11_i18 < 3; c11_i18++) {
    c11_xdot[c11_i18] = c11_b_C[c11_i18];
  }

  c11_threshold(chartInstance);
  for (c11_i19 = 0; c11_i19 < 3; c11_i19++) {
    c11_b_C[c11_i19] = c11_xdot[c11_i19];
  }

  for (c11_i20 = 0; c11_i20 < 3; c11_i20++) {
    c11_xdot[c11_i20] = c11_b_C[c11_i20];
  }

  for (c11_i21 = 0; c11_i21 < 3; c11_i21++) {
    c11_xdot[c11_i21] = 0.0;
    c11_i22 = 0;
    for (c11_i23 = 0; c11_i23 < 3; c11_i23++) {
      c11_xdot[c11_i21] += c11_a[c11_i22 + c11_i21] * c11_b[c11_i23];
      c11_i22 += 3;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 62);
  for (c11_i24 = 0; c11_i24 < 2; c11_i24++) {
    c11_y[c11_i24] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 63);
  for (c11_i25 = 0; c11_i25 < 6; c11_i25++) {
    c11_b_a[c11_i25] = c11_C[c11_i25];
  }

  for (c11_i26 = 0; c11_i26 < 3; c11_i26++) {
    c11_b[c11_i26] = c11_x[c11_i26];
  }

  c11_b_eml_scalar_eg(chartInstance);
  c11_b_eml_scalar_eg(chartInstance);
  for (c11_i27 = 0; c11_i27 < 2; c11_i27++) {
    c11_y[c11_i27] = 0.0;
  }

  for (c11_i28 = 0; c11_i28 < 2; c11_i28++) {
    c11_y[c11_i28] = 0.0;
  }

  for (c11_i29 = 0; c11_i29 < 2; c11_i29++) {
    c11_c_C[c11_i29] = c11_y[c11_i29];
  }

  for (c11_i30 = 0; c11_i30 < 2; c11_i30++) {
    c11_y[c11_i30] = c11_c_C[c11_i30];
  }

  c11_threshold(chartInstance);
  for (c11_i31 = 0; c11_i31 < 2; c11_i31++) {
    c11_c_C[c11_i31] = c11_y[c11_i31];
  }

  for (c11_i32 = 0; c11_i32 < 2; c11_i32++) {
    c11_y[c11_i32] = c11_c_C[c11_i32];
  }

  for (c11_i33 = 0; c11_i33 < 2; c11_i33++) {
    c11_y[c11_i33] = 0.0;
    c11_i34 = 0;
    for (c11_i35 = 0; c11_i35 < 3; c11_i35++) {
      c11_y[c11_i33] += c11_b_a[c11_i34 + c11_i33] * c11_b[c11_i35];
      c11_i34 += 2;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 65);
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, -65);
  _SFD_SYMBOL_SCOPE_POP();
  for (c11_i36 = 0; c11_i36 < 2; c11_i36++) {
    (*c11_pb_y)[c11_i36] = c11_y[c11_i36];
  }

  for (c11_i37 = 0; c11_i37 < 3; c11_i37++) {
    (*c11_b_xdot)[c11_i37] = c11_xdot[c11_i37];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c11_sfEvent);
}

static void initSimStructsc11_SmAHTR_r1_PITTRTNUKE
  (SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c11_machineNumber, uint32_T
  c11_chartNumber, uint32_T c11_instanceNumber)
{
  (void)c11_machineNumber;
  (void)c11_chartNumber;
  (void)c11_instanceNumber;
}

static const mxArray *c11_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i38;
  real_T c11_b_inData[3];
  int32_T c11_i39;
  real_T c11_u[3];
  const mxArray *c11_y = NULL;
  SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance;
  chartInstance = (SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i38 = 0; c11_i38 < 3; c11_i38++) {
    c11_b_inData[c11_i38] = (*(real_T (*)[3])c11_inData)[c11_i38];
  }

  for (c11_i39 = 0; c11_i39 < 3; c11_i39++) {
    c11_u[c11_i39] = c11_b_inData[c11_i39];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static void c11_emlrt_marshallIn(SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c11_xdot, const char_T *c11_identifier, real_T
  c11_y[3])
{
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_xdot), &c11_thisId, c11_y);
  sf_mex_destroy(&c11_xdot);
}

static void c11_b_emlrt_marshallIn(SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[3])
{
  real_T c11_dv3[3];
  int32_T c11_i40;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), c11_dv3, 1, 0, 0U, 1, 0U, 1, 3);
  for (c11_i40 = 0; c11_i40 < 3; c11_i40++) {
    c11_y[c11_i40] = c11_dv3[c11_i40];
  }

  sf_mex_destroy(&c11_u);
}

static void c11_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_xdot;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  real_T c11_y[3];
  int32_T c11_i41;
  SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance;
  chartInstance = (SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct *)chartInstanceVoid;
  c11_xdot = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_xdot), &c11_thisId, c11_y);
  sf_mex_destroy(&c11_xdot);
  for (c11_i41 = 0; c11_i41 < 3; c11_i41++) {
    (*(real_T (*)[3])c11_outData)[c11_i41] = c11_y[c11_i41];
  }

  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_b_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i42;
  real_T c11_b_inData[2];
  int32_T c11_i43;
  real_T c11_u[2];
  const mxArray *c11_y = NULL;
  SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance;
  chartInstance = (SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i42 = 0; c11_i42 < 2; c11_i42++) {
    c11_b_inData[c11_i42] = (*(real_T (*)[2])c11_inData)[c11_i42];
  }

  for (c11_i43 = 0; c11_i43 < 2; c11_i43++) {
    c11_u[c11_i43] = c11_b_inData[c11_i43];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 1, 2), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static void c11_c_emlrt_marshallIn(SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c11_y, const char_T *c11_identifier, real_T
  c11_b_y[2])
{
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_y), &c11_thisId, c11_b_y);
  sf_mex_destroy(&c11_y);
}

static void c11_d_emlrt_marshallIn(SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[2])
{
  real_T c11_dv4[2];
  int32_T c11_i44;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), c11_dv4, 1, 0, 0U, 1, 0U, 1, 2);
  for (c11_i44 = 0; c11_i44 < 2; c11_i44++) {
    c11_y[c11_i44] = c11_dv4[c11_i44];
  }

  sf_mex_destroy(&c11_u);
}

static void c11_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_y;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  real_T c11_b_y[2];
  int32_T c11_i45;
  SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance;
  chartInstance = (SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct *)chartInstanceVoid;
  c11_y = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_y), &c11_thisId, c11_b_y);
  sf_mex_destroy(&c11_y);
  for (c11_i45 = 0; c11_i45 < 2; c11_i45++) {
    (*(real_T (*)[2])c11_outData)[c11_i45] = c11_b_y[c11_i45];
  }

  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_c_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  real_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance;
  chartInstance = (SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(real_T *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static const mxArray *c11_d_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i46;
  real_T c11_b_inData[14];
  int32_T c11_i47;
  real_T c11_u[14];
  const mxArray *c11_y = NULL;
  SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance;
  chartInstance = (SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i46 = 0; c11_i46 < 14; c11_i46++) {
    c11_b_inData[c11_i46] = (*(real_T (*)[14])c11_inData)[c11_i46];
  }

  for (c11_i47 = 0; c11_i47 < 14; c11_i47++) {
    c11_u[c11_i47] = c11_b_inData[c11_i47];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 1, 14), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static real_T c11_e_emlrt_marshallIn(SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  real_T c11_y;
  real_T c11_d0;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_d0, 1, 0, 0U, 0, 0U, 0);
  c11_y = c11_d0;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_nargout;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  real_T c11_y;
  SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance;
  chartInstance = (SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct *)chartInstanceVoid;
  c11_nargout = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_nargout),
    &c11_thisId);
  sf_mex_destroy(&c11_nargout);
  *(real_T *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_e_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i48;
  int32_T c11_i49;
  int32_T c11_i50;
  real_T c11_b_inData[6];
  int32_T c11_i51;
  int32_T c11_i52;
  int32_T c11_i53;
  real_T c11_u[6];
  const mxArray *c11_y = NULL;
  SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance;
  chartInstance = (SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_i48 = 0;
  for (c11_i49 = 0; c11_i49 < 3; c11_i49++) {
    for (c11_i50 = 0; c11_i50 < 2; c11_i50++) {
      c11_b_inData[c11_i50 + c11_i48] = (*(real_T (*)[6])c11_inData)[c11_i50 +
        c11_i48];
    }

    c11_i48 += 2;
  }

  c11_i51 = 0;
  for (c11_i52 = 0; c11_i52 < 3; c11_i52++) {
    for (c11_i53 = 0; c11_i53 < 2; c11_i53++) {
      c11_u[c11_i53 + c11_i51] = c11_b_inData[c11_i53 + c11_i51];
    }

    c11_i51 += 2;
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 2, 2, 3), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static void c11_f_emlrt_marshallIn(SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[6])
{
  real_T c11_dv5[6];
  int32_T c11_i54;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), c11_dv5, 1, 0, 0U, 1, 0U, 2, 2,
                3);
  for (c11_i54 = 0; c11_i54 < 6; c11_i54++) {
    c11_y[c11_i54] = c11_dv5[c11_i54];
  }

  sf_mex_destroy(&c11_u);
}

static void c11_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_C;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  real_T c11_y[6];
  int32_T c11_i55;
  int32_T c11_i56;
  int32_T c11_i57;
  SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance;
  chartInstance = (SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct *)chartInstanceVoid;
  c11_C = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_C), &c11_thisId, c11_y);
  sf_mex_destroy(&c11_C);
  c11_i55 = 0;
  for (c11_i56 = 0; c11_i56 < 3; c11_i56++) {
    for (c11_i57 = 0; c11_i57 < 2; c11_i57++) {
      (*(real_T (*)[6])c11_outData)[c11_i57 + c11_i55] = c11_y[c11_i57 + c11_i55];
    }

    c11_i55 += 2;
  }

  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_f_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i58;
  int32_T c11_i59;
  int32_T c11_i60;
  real_T c11_b_inData[9];
  int32_T c11_i61;
  int32_T c11_i62;
  int32_T c11_i63;
  real_T c11_u[9];
  const mxArray *c11_y = NULL;
  SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance;
  chartInstance = (SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_i58 = 0;
  for (c11_i59 = 0; c11_i59 < 3; c11_i59++) {
    for (c11_i60 = 0; c11_i60 < 3; c11_i60++) {
      c11_b_inData[c11_i60 + c11_i58] = (*(real_T (*)[9])c11_inData)[c11_i60 +
        c11_i58];
    }

    c11_i58 += 3;
  }

  c11_i61 = 0;
  for (c11_i62 = 0; c11_i62 < 3; c11_i62++) {
    for (c11_i63 = 0; c11_i63 < 3; c11_i63++) {
      c11_u[c11_i63 + c11_i61] = c11_b_inData[c11_i63 + c11_i61];
    }

    c11_i61 += 3;
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 2, 3, 3), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static void c11_g_emlrt_marshallIn(SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[9])
{
  real_T c11_dv6[9];
  int32_T c11_i64;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), c11_dv6, 1, 0, 0U, 1, 0U, 2, 3,
                3);
  for (c11_i64 = 0; c11_i64 < 9; c11_i64++) {
    c11_y[c11_i64] = c11_dv6[c11_i64];
  }

  sf_mex_destroy(&c11_u);
}

static void c11_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_A;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  real_T c11_y[9];
  int32_T c11_i65;
  int32_T c11_i66;
  int32_T c11_i67;
  SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance;
  chartInstance = (SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct *)chartInstanceVoid;
  c11_A = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_A), &c11_thisId, c11_y);
  sf_mex_destroy(&c11_A);
  c11_i65 = 0;
  for (c11_i66 = 0; c11_i66 < 3; c11_i66++) {
    for (c11_i67 = 0; c11_i67 < 3; c11_i67++) {
      (*(real_T (*)[9])c11_outData)[c11_i67 + c11_i65] = c11_y[c11_i67 + c11_i65];
    }

    c11_i65 += 3;
  }

  sf_mex_destroy(&c11_mxArrayInData);
}

const mxArray *sf_c11_SmAHTR_r1_PITTRTNUKE_get_eml_resolved_functions_info(void)
{
  const mxArray *c11_nameCaptureInfo = NULL;
  c11_nameCaptureInfo = NULL;
  sf_mex_assign(&c11_nameCaptureInfo, sf_mex_createstruct("structure", 2, 20, 1),
                false);
  c11_info_helper(&c11_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c11_nameCaptureInfo);
  return c11_nameCaptureInfo;
}

static void c11_info_helper(const mxArray **c11_info)
{
  const mxArray *c11_rhs0 = NULL;
  const mxArray *c11_lhs0 = NULL;
  const mxArray *c11_rhs1 = NULL;
  const mxArray *c11_lhs1 = NULL;
  const mxArray *c11_rhs2 = NULL;
  const mxArray *c11_lhs2 = NULL;
  const mxArray *c11_rhs3 = NULL;
  const mxArray *c11_lhs3 = NULL;
  const mxArray *c11_rhs4 = NULL;
  const mxArray *c11_lhs4 = NULL;
  const mxArray *c11_rhs5 = NULL;
  const mxArray *c11_lhs5 = NULL;
  const mxArray *c11_rhs6 = NULL;
  const mxArray *c11_lhs6 = NULL;
  const mxArray *c11_rhs7 = NULL;
  const mxArray *c11_lhs7 = NULL;
  const mxArray *c11_rhs8 = NULL;
  const mxArray *c11_lhs8 = NULL;
  const mxArray *c11_rhs9 = NULL;
  const mxArray *c11_lhs9 = NULL;
  const mxArray *c11_rhs10 = NULL;
  const mxArray *c11_lhs10 = NULL;
  const mxArray *c11_rhs11 = NULL;
  const mxArray *c11_lhs11 = NULL;
  const mxArray *c11_rhs12 = NULL;
  const mxArray *c11_lhs12 = NULL;
  const mxArray *c11_rhs13 = NULL;
  const mxArray *c11_lhs13 = NULL;
  const mxArray *c11_rhs14 = NULL;
  const mxArray *c11_lhs14 = NULL;
  const mxArray *c11_rhs15 = NULL;
  const mxArray *c11_lhs15 = NULL;
  const mxArray *c11_rhs16 = NULL;
  const mxArray *c11_lhs16 = NULL;
  const mxArray *c11_rhs17 = NULL;
  const mxArray *c11_lhs17 = NULL;
  const mxArray *c11_rhs18 = NULL;
  const mxArray *c11_lhs18 = NULL;
  const mxArray *c11_rhs19 = NULL;
  const mxArray *c11_lhs19 = NULL;
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("mrdivide"), "name", "name",
                  0);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1388481696U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1370031486U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c11_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 1);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 1);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1363732556U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c11_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 2);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("rdivide"), "name", "name", 2);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1363731880U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c11_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 3);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1363732556U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c11_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 4);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1286840396U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c11_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_div"), "name", "name", 5);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c11_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 6);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1389329520U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c11_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "context", "context", 7);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 7);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1383898894U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c11_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 8);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 8);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1363732556U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c11_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 9);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 9);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c11_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 10);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 10);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 10);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c11_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 11);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1389329520U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c11_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 12);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_xgemm"), "name", "name",
                  12);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1376002290U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c11_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 13);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 13);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1389329522U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c11_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 14);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("coder.internal.blas.xgemm"),
                  "name", "name", 14);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1389329522U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c11_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 15);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 15);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1389329522U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c11_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p!below_threshold"),
                  "context", "context", 16);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 16);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1389329522U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c11_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "context", "context", 17);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 17);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1381871900U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c11_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 18);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 18);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1389329520U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c11_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 19);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "coder.internal.refblas.xgemm"), "name", "name", 19);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgemm.p"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1389329522U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c11_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs19), "lhs", "lhs",
                  19);
  sf_mex_destroy(&c11_rhs0);
  sf_mex_destroy(&c11_lhs0);
  sf_mex_destroy(&c11_rhs1);
  sf_mex_destroy(&c11_lhs1);
  sf_mex_destroy(&c11_rhs2);
  sf_mex_destroy(&c11_lhs2);
  sf_mex_destroy(&c11_rhs3);
  sf_mex_destroy(&c11_lhs3);
  sf_mex_destroy(&c11_rhs4);
  sf_mex_destroy(&c11_lhs4);
  sf_mex_destroy(&c11_rhs5);
  sf_mex_destroy(&c11_lhs5);
  sf_mex_destroy(&c11_rhs6);
  sf_mex_destroy(&c11_lhs6);
  sf_mex_destroy(&c11_rhs7);
  sf_mex_destroy(&c11_lhs7);
  sf_mex_destroy(&c11_rhs8);
  sf_mex_destroy(&c11_lhs8);
  sf_mex_destroy(&c11_rhs9);
  sf_mex_destroy(&c11_lhs9);
  sf_mex_destroy(&c11_rhs10);
  sf_mex_destroy(&c11_lhs10);
  sf_mex_destroy(&c11_rhs11);
  sf_mex_destroy(&c11_lhs11);
  sf_mex_destroy(&c11_rhs12);
  sf_mex_destroy(&c11_lhs12);
  sf_mex_destroy(&c11_rhs13);
  sf_mex_destroy(&c11_lhs13);
  sf_mex_destroy(&c11_rhs14);
  sf_mex_destroy(&c11_lhs14);
  sf_mex_destroy(&c11_rhs15);
  sf_mex_destroy(&c11_lhs15);
  sf_mex_destroy(&c11_rhs16);
  sf_mex_destroy(&c11_lhs16);
  sf_mex_destroy(&c11_rhs17);
  sf_mex_destroy(&c11_lhs17);
  sf_mex_destroy(&c11_rhs18);
  sf_mex_destroy(&c11_lhs18);
  sf_mex_destroy(&c11_rhs19);
  sf_mex_destroy(&c11_lhs19);
}

static const mxArray *c11_emlrt_marshallOut(const char * c11_u)
{
  const mxArray *c11_y = NULL;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c11_u)), false);
  return c11_y;
}

static const mxArray *c11_b_emlrt_marshallOut(const uint32_T c11_u)
{
  const mxArray *c11_y = NULL;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 7, 0U, 0U, 0U, 0), false);
  return c11_y;
}

static void c11_eml_scalar_eg(SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c11_threshold(SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c11_b_eml_scalar_eg(SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *c11_g_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance;
  chartInstance = (SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(int32_T *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static int32_T c11_h_emlrt_marshallIn(SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  int32_T c11_y;
  int32_T c11_i68;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_i68, 1, 6, 0U, 0, 0U, 0);
  c11_y = c11_i68;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_b_sfEvent;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  int32_T c11_y;
  SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance;
  chartInstance = (SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct *)chartInstanceVoid;
  c11_b_sfEvent = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_b_sfEvent),
    &c11_thisId);
  sf_mex_destroy(&c11_b_sfEvent);
  *(int32_T *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

static uint8_T c11_i_emlrt_marshallIn(SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c11_b_is_active_c11_SmAHTR_r1_PITTRTNUKE, const
  char_T *c11_identifier)
{
  uint8_T c11_y;
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c11_b_is_active_c11_SmAHTR_r1_PITTRTNUKE), &c11_thisId);
  sf_mex_destroy(&c11_b_is_active_c11_SmAHTR_r1_PITTRTNUKE);
  return c11_y;
}

static uint8_T c11_j_emlrt_marshallIn(SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  uint8_T c11_y;
  uint8_T c11_u0;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_u0, 1, 3, 0U, 0, 0U, 0);
  c11_y = c11_u0;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void init_dsm_address_info(SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct
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

void sf_c11_SmAHTR_r1_PITTRTNUKE_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2196456654U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2633929770U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1880388153U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1968274736U);
}

mxArray *sf_c11_SmAHTR_r1_PITTRTNUKE_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("YP5yRvYbyYQfBFFXHXerp");
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
      pr[0] = (double)(14);
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
      pr[0] = (double)(2);
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

mxArray *sf_c11_SmAHTR_r1_PITTRTNUKE_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c11_SmAHTR_r1_PITTRTNUKE_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c11_SmAHTR_r1_PITTRTNUKE(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[17],T\"xdot\",},{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c11_SmAHTR_r1_PITTRTNUKE\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c11_SmAHTR_r1_PITTRTNUKE_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _SmAHTR_r1_PITTRTNUKEMachineNumber_,
           11,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"PROMPTN1");
          _SFD_SET_DATA_PROPS(1,1,1,0,"PROMPTN2");
          _SFD_SET_DATA_PROPS(2,1,1,0,"DELAYEDN1");
          _SFD_SET_DATA_PROPS(3,1,1,0,"DELAYEDN2");
          _SFD_SET_DATA_PROPS(4,1,1,0,"pkeparams");
          _SFD_SET_DATA_PROPS(5,1,1,0,"rho_temp");
          _SFD_SET_DATA_PROPS(6,1,1,0,"x");
          _SFD_SET_DATA_PROPS(7,2,0,1,"y");
          _SFD_SET_DATA_PROPS(8,2,0,1,"xdot");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,2286);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_c_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 14;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_c_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_b_sf_marshallOut,(MexInFcnForType)
            c11_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_sf_marshallOut,(MexInFcnForType)
            c11_sf_marshallIn);
        }

        {
          real_T *c11_PROMPTN1;
          real_T *c11_PROMPTN2;
          real_T *c11_DELAYEDN1;
          real_T *c11_DELAYEDN2;
          real_T *c11_rho_temp;
          real_T (*c11_pkeparams)[14];
          real_T (*c11_x)[3];
          real_T (*c11_y)[2];
          real_T (*c11_xdot)[3];
          c11_xdot = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
          c11_y = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 1);
          c11_x = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 6);
          c11_rho_temp = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c11_pkeparams = (real_T (*)[14])ssGetInputPortSignal(chartInstance->S,
            4);
          c11_DELAYEDN2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c11_DELAYEDN1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c11_PROMPTN2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c11_PROMPTN1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c11_PROMPTN1);
          _SFD_SET_DATA_VALUE_PTR(1U, c11_PROMPTN2);
          _SFD_SET_DATA_VALUE_PTR(2U, c11_DELAYEDN1);
          _SFD_SET_DATA_VALUE_PTR(3U, c11_DELAYEDN2);
          _SFD_SET_DATA_VALUE_PTR(4U, *c11_pkeparams);
          _SFD_SET_DATA_VALUE_PTR(5U, c11_rho_temp);
          _SFD_SET_DATA_VALUE_PTR(6U, *c11_x);
          _SFD_SET_DATA_VALUE_PTR(7U, *c11_y);
          _SFD_SET_DATA_VALUE_PTR(8U, *c11_xdot);
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
  return "bxgwXwwlQU8JAG3eqC3dhG";
}

static void sf_opaque_initialize_c11_SmAHTR_r1_PITTRTNUKE(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c11_SmAHTR_r1_PITTRTNUKE
    ((SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct*) chartInstanceVar);
  initialize_c11_SmAHTR_r1_PITTRTNUKE((SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c11_SmAHTR_r1_PITTRTNUKE(void *chartInstanceVar)
{
  enable_c11_SmAHTR_r1_PITTRTNUKE((SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c11_SmAHTR_r1_PITTRTNUKE(void *chartInstanceVar)
{
  disable_c11_SmAHTR_r1_PITTRTNUKE((SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c11_SmAHTR_r1_PITTRTNUKE(void *chartInstanceVar)
{
  sf_gateway_c11_SmAHTR_r1_PITTRTNUKE((SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c11_SmAHTR_r1_PITTRTNUKE
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c11_SmAHTR_r1_PITTRTNUKE
    ((SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c11_SmAHTR_r1_PITTRTNUKE();/* state var info */
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

extern void sf_internal_set_sim_state_c11_SmAHTR_r1_PITTRTNUKE(SimStruct* S,
  const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c11_SmAHTR_r1_PITTRTNUKE();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c11_SmAHTR_r1_PITTRTNUKE
    ((SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c11_SmAHTR_r1_PITTRTNUKE(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c11_SmAHTR_r1_PITTRTNUKE(S);
}

static void sf_opaque_set_sim_state_c11_SmAHTR_r1_PITTRTNUKE(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c11_SmAHTR_r1_PITTRTNUKE(S, st);
}

static void sf_opaque_terminate_c11_SmAHTR_r1_PITTRTNUKE(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct*) chartInstanceVar)
      ->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_SmAHTR_r1_PITTRTNUKE_optimization_info();
    }

    finalize_c11_SmAHTR_r1_PITTRTNUKE((SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct*)
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
  initSimStructsc11_SmAHTR_r1_PITTRTNUKE
    ((SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c11_SmAHTR_r1_PITTRTNUKE(SimStruct *S)
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
    initialize_params_c11_SmAHTR_r1_PITTRTNUKE
      ((SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct*)(chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c11_SmAHTR_r1_PITTRTNUKE(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_SmAHTR_r1_PITTRTNUKE_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      11);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,11,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,11,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,11);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,11,7);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,11,2);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,11);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2545470087U));
  ssSetChecksum1(S,(3285652536U));
  ssSetChecksum2(S,(1937497838U));
  ssSetChecksum3(S,(1711808754U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c11_SmAHTR_r1_PITTRTNUKE(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c11_SmAHTR_r1_PITTRTNUKE(SimStruct *S)
{
  SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct *)utMalloc(sizeof
    (SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc11_SmAHTR_r1_PITTRTNUKEInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c11_SmAHTR_r1_PITTRTNUKE;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c11_SmAHTR_r1_PITTRTNUKE;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c11_SmAHTR_r1_PITTRTNUKE;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c11_SmAHTR_r1_PITTRTNUKE;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c11_SmAHTR_r1_PITTRTNUKE;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c11_SmAHTR_r1_PITTRTNUKE;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c11_SmAHTR_r1_PITTRTNUKE;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c11_SmAHTR_r1_PITTRTNUKE;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c11_SmAHTR_r1_PITTRTNUKE;
  chartInstance->chartInfo.mdlStart = mdlStart_c11_SmAHTR_r1_PITTRTNUKE;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c11_SmAHTR_r1_PITTRTNUKE;
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

void c11_SmAHTR_r1_PITTRTNUKE_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c11_SmAHTR_r1_PITTRTNUKE(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c11_SmAHTR_r1_PITTRTNUKE(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c11_SmAHTR_r1_PITTRTNUKE(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c11_SmAHTR_r1_PITTRTNUKE_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
