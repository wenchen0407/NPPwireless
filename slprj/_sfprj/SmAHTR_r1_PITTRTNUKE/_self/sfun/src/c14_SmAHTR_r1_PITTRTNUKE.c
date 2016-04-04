/* Include files */

#include <stddef.h>
#include "blas.h"
#include "SmAHTR_r1_PITTRTNUKE_sfun.h"
#include "c14_SmAHTR_r1_PITTRTNUKE.h"
#include "mwmathutil.h"
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
static const char * c14_debug_family_names[19] = { "iterations", "text",
  "result", "line_num", "emergency_instance", "resultz", "delay",
  "network_delay", "i_yg", "nargin", "nargout", "ymea", "ymea1", "ydelay",
  "ynetwork_delay", "delay1", "i", "last_emergency_instance", "network_array" };

static const char * c14_b_debug_family_names[7] = { "result_num", "sz_y", "i_rn",
  "nargin", "nargout", "result", "delay" };

/* Function Declarations */
static void initialize_c14_SmAHTR_r1_PITTRTNUKE
  (SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance);
static void initialize_params_c14_SmAHTR_r1_PITTRTNUKE
  (SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance);
static void enable_c14_SmAHTR_r1_PITTRTNUKE
  (SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance);
static void disable_c14_SmAHTR_r1_PITTRTNUKE
  (SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance);
static void c14_update_debugger_state_c14_SmAHTR_r1_PITTRTNUKE
  (SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c14_SmAHTR_r1_PITTRTNUKE
  (SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance);
static void set_sim_state_c14_SmAHTR_r1_PITTRTNUKE
  (SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance, const mxArray
   *c14_st);
static void finalize_c14_SmAHTR_r1_PITTRTNUKE
  (SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance);
static void sf_gateway_c14_SmAHTR_r1_PITTRTNUKE
  (SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance);
static void c14_chartstep_c14_SmAHTR_r1_PITTRTNUKE
  (SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance);
static void initSimStructsc14_SmAHTR_r1_PITTRTNUKE
  (SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c14_machineNumber, uint32_T
  c14_chartNumber, uint32_T c14_instanceNumber);
static boolean_T c14_emlrt_marshallIn(SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c14_ischar, const char_T *c14_identifier);
static boolean_T c14_b_emlrt_marshallIn(SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId);
static void c14_c_emlrt_marshallIn(SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c14_str2num, const char_T *c14_identifier,
  real_T c14_y[18]);
static void c14_d_emlrt_marshallIn(SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId,
  real_T c14_y[18]);
static void c14_e_emlrt_marshallIn(SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c14_transpose, const char_T *c14_identifier,
  real_T c14_y[10]);
static void c14_f_emlrt_marshallIn(SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId,
  real_T c14_y[10]);
static const mxArray *c14_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData);
static void c14_g_emlrt_marshallIn(SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c14_b_network_array, const char_T
  *c14_identifier, real_T c14_y[3600036]);
static void c14_h_emlrt_marshallIn(SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId,
  real_T c14_y[3600036]);
static void c14_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData);
static const mxArray *c14_b_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData);
static void c14_i_emlrt_marshallIn(SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c14_b_last_emergency_instance, const char_T
  *c14_identifier, real_T c14_y[9]);
static void c14_j_emlrt_marshallIn(SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId,
  real_T c14_y[9]);
static void c14_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData);
static const mxArray *c14_c_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData);
static real_T c14_k_emlrt_marshallIn(SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c14_b_i, const char_T *c14_identifier);
static real_T c14_l_emlrt_marshallIn(SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId);
static void c14_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData);
static const mxArray *c14_d_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData);
static void c14_m_emlrt_marshallIn(SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c14_b_delay1, const char_T *c14_identifier,
  real_T c14_y[10]);
static void c14_n_emlrt_marshallIn(SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId,
  real_T c14_y[10]);
static void c14_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData);
static const mxArray *c14_e_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData);
static void c14_o_emlrt_marshallIn(SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c14_ynetwork_delay, const char_T
  *c14_identifier, real_T c14_y[9]);
static void c14_p_emlrt_marshallIn(SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId,
  real_T c14_y[9]);
static void c14_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData);
static const mxArray *c14_f_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData);
static void c14_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData);
static const mxArray *c14_g_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData);
static real_T c14_q_emlrt_marshallIn(SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId);
static void c14_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData);
static const mxArray *c14_h_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData);
static void c14_r_emlrt_marshallIn(SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId,
  real_T c14_y[9]);
static void c14_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData);
static const mxArray *c14_i_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData);
static const mxArray *c14_j_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData);
static void c14_s_emlrt_marshallIn(SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId,
  real_T c14_y[18]);
static void c14_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData);
static void c14_info_helper(const mxArray **c14_info);
static const mxArray *c14_emlrt_marshallOut(const char * c14_u);
static const mxArray *c14_b_emlrt_marshallOut(const uint32_T c14_u);
static const mxArray *c14_k_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData);
static int32_T c14_t_emlrt_marshallIn(SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId);
static void c14_j_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData);
static const mxArray *c14_l_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData);
static void c14_u_emlrt_marshallIn(SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId,
  int32_T c14_y[10]);
static void c14_k_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData);
static uint8_T c14_v_emlrt_marshallIn(SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c14_b_is_active_c14_SmAHTR_r1_PITTRTNUKE, const
  char_T *c14_identifier);
static uint8_T c14_w_emlrt_marshallIn(SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId);
static int32_T c14_get_counter_global(SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, uint32_T c14_b);
static void c14_set_counter_global(SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, uint32_T c14_b, int32_T c14_c);
static int32_T *c14_access_counter_global
  (SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance, uint32_T c14_b);
static int32_T c14_get_ydelay_global(SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, uint32_T c14_b);
static void c14_set_ydelay_global(SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, uint32_T c14_b, int32_T c14_c);
static int32_T *c14_access_ydelay_global
  (SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance, uint32_T c14_b);
static void init_dsm_address_info(SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c14_SmAHTR_r1_PITTRTNUKE
  (SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance)
{
  chartInstance->c14_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c14_delay1_not_empty = false;
  chartInstance->c14_i_not_empty = false;
  chartInstance->c14_last_emergency_instance_not_empty = false;
  chartInstance->c14_network_array_not_empty = false;
  chartInstance->c14_is_active_c14_SmAHTR_r1_PITTRTNUKE = 0U;
}

static void initialize_params_c14_SmAHTR_r1_PITTRTNUKE
  (SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c14_SmAHTR_r1_PITTRTNUKE
  (SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c14_SmAHTR_r1_PITTRTNUKE
  (SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c14_update_debugger_state_c14_SmAHTR_r1_PITTRTNUKE
  (SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c14_SmAHTR_r1_PITTRTNUKE
  (SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance)
{
  const mxArray *c14_st;
  const mxArray *c14_y = NULL;
  int32_T c14_i0;
  real_T c14_u[10];
  const mxArray *c14_b_y = NULL;
  int32_T c14_i1;
  real_T c14_b_u[9];
  const mxArray *c14_c_y = NULL;
  int32_T c14_i2;
  real_T c14_c_u[9];
  const mxArray *c14_d_y = NULL;
  int32_T c14_i3;
  real_T c14_d_u[10];
  const mxArray *c14_e_y = NULL;
  real_T c14_hoistedGlobal;
  real_T c14_e_u;
  const mxArray *c14_f_y = NULL;
  int32_T c14_i4;
  real_T c14_f_u[9];
  const mxArray *c14_g_y = NULL;
  int32_T c14_i5;
  static real_T c14_g_u[3600036];
  const mxArray *c14_h_y = NULL;
  uint8_T c14_b_hoistedGlobal;
  uint8_T c14_h_u;
  const mxArray *c14_i_y = NULL;
  real_T (*c14_ynetwork_delay)[9];
  real_T (*c14_ymea1)[9];
  real_T (*c14_ydelay)[10];
  c14_ynetwork_delay = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 3);
  c14_ydelay = (real_T (*)[10])ssGetOutputPortSignal(chartInstance->S, 2);
  c14_ymea1 = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c14_st = NULL;
  c14_st = NULL;
  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_createcellmatrix(8, 1), false);
  for (c14_i0 = 0; c14_i0 < 10; c14_i0++) {
    c14_u[c14_i0] = (*c14_ydelay)[c14_i0];
  }

  c14_b_y = NULL;
  sf_mex_assign(&c14_b_y, sf_mex_create("y", c14_u, 0, 0U, 1U, 0U, 1, 10), false);
  sf_mex_setcell(c14_y, 0, c14_b_y);
  for (c14_i1 = 0; c14_i1 < 9; c14_i1++) {
    c14_b_u[c14_i1] = (*c14_ymea1)[c14_i1];
  }

  c14_c_y = NULL;
  sf_mex_assign(&c14_c_y, sf_mex_create("y", c14_b_u, 0, 0U, 1U, 0U, 1, 9),
                false);
  sf_mex_setcell(c14_y, 1, c14_c_y);
  for (c14_i2 = 0; c14_i2 < 9; c14_i2++) {
    c14_c_u[c14_i2] = (*c14_ynetwork_delay)[c14_i2];
  }

  c14_d_y = NULL;
  sf_mex_assign(&c14_d_y, sf_mex_create("y", c14_c_u, 0, 0U, 1U, 0U, 1, 9),
                false);
  sf_mex_setcell(c14_y, 2, c14_d_y);
  for (c14_i3 = 0; c14_i3 < 10; c14_i3++) {
    c14_d_u[c14_i3] = chartInstance->c14_delay1[c14_i3];
  }

  c14_e_y = NULL;
  if (!chartInstance->c14_delay1_not_empty) {
    sf_mex_assign(&c14_e_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c14_e_y, sf_mex_create("y", c14_d_u, 0, 0U, 1U, 0U, 1, 10),
                  false);
  }

  sf_mex_setcell(c14_y, 3, c14_e_y);
  c14_hoistedGlobal = chartInstance->c14_i;
  c14_e_u = c14_hoistedGlobal;
  c14_f_y = NULL;
  if (!chartInstance->c14_i_not_empty) {
    sf_mex_assign(&c14_f_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c14_f_y, sf_mex_create("y", &c14_e_u, 0, 0U, 0U, 0U, 0),
                  false);
  }

  sf_mex_setcell(c14_y, 4, c14_f_y);
  for (c14_i4 = 0; c14_i4 < 9; c14_i4++) {
    c14_f_u[c14_i4] = chartInstance->c14_last_emergency_instance[c14_i4];
  }

  c14_g_y = NULL;
  if (!chartInstance->c14_last_emergency_instance_not_empty) {
    sf_mex_assign(&c14_g_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c14_g_y, sf_mex_create("y", c14_f_u, 0, 0U, 1U, 0U, 2, 1, 9),
                  false);
  }

  sf_mex_setcell(c14_y, 5, c14_g_y);
  for (c14_i5 = 0; c14_i5 < 3600036; c14_i5++) {
    c14_g_u[c14_i5] = chartInstance->c14_network_array[c14_i5];
  }

  c14_h_y = NULL;
  if (!chartInstance->c14_network_array_not_empty) {
    sf_mex_assign(&c14_h_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c14_h_y, sf_mex_create("y", c14_g_u, 0, 0U, 1U, 0U, 2, 200002,
      18), false);
  }

  sf_mex_setcell(c14_y, 6, c14_h_y);
  c14_b_hoistedGlobal = chartInstance->c14_is_active_c14_SmAHTR_r1_PITTRTNUKE;
  c14_h_u = c14_b_hoistedGlobal;
  c14_i_y = NULL;
  sf_mex_assign(&c14_i_y, sf_mex_create("y", &c14_h_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c14_y, 7, c14_i_y);
  sf_mex_assign(&c14_st, c14_y, false);
  return c14_st;
}

static void set_sim_state_c14_SmAHTR_r1_PITTRTNUKE
  (SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance, const mxArray
   *c14_st)
{
  const mxArray *c14_u;
  real_T c14_dv0[10];
  int32_T c14_i6;
  real_T c14_dv1[9];
  int32_T c14_i7;
  real_T c14_dv2[9];
  int32_T c14_i8;
  real_T c14_dv3[10];
  int32_T c14_i9;
  real_T c14_dv4[9];
  int32_T c14_i10;
  static real_T c14_dv5[3600036];
  int32_T c14_i11;
  real_T (*c14_ydelay)[10];
  real_T (*c14_ymea1)[9];
  real_T (*c14_ynetwork_delay)[9];
  c14_ynetwork_delay = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 3);
  c14_ydelay = (real_T (*)[10])ssGetOutputPortSignal(chartInstance->S, 2);
  c14_ymea1 = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c14_doneDoubleBufferReInit = true;
  c14_u = sf_mex_dup(c14_st);
  c14_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c14_u, 0)),
    "ydelay", c14_dv0);
  for (c14_i6 = 0; c14_i6 < 10; c14_i6++) {
    (*c14_ydelay)[c14_i6] = c14_dv0[c14_i6];
  }

  c14_o_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c14_u, 1)),
    "ymea1", c14_dv1);
  for (c14_i7 = 0; c14_i7 < 9; c14_i7++) {
    (*c14_ymea1)[c14_i7] = c14_dv1[c14_i7];
  }

  c14_o_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c14_u, 2)),
    "ynetwork_delay", c14_dv2);
  for (c14_i8 = 0; c14_i8 < 9; c14_i8++) {
    (*c14_ynetwork_delay)[c14_i8] = c14_dv2[c14_i8];
  }

  c14_m_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c14_u, 3)),
    "delay1", c14_dv3);
  for (c14_i9 = 0; c14_i9 < 10; c14_i9++) {
    chartInstance->c14_delay1[c14_i9] = c14_dv3[c14_i9];
  }

  chartInstance->c14_i = c14_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c14_u, 4)), "i");
  c14_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c14_u, 5)),
    "last_emergency_instance", c14_dv4);
  for (c14_i10 = 0; c14_i10 < 9; c14_i10++) {
    chartInstance->c14_last_emergency_instance[c14_i10] = c14_dv4[c14_i10];
  }

  c14_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c14_u, 6)),
    "network_array", c14_dv5);
  for (c14_i11 = 0; c14_i11 < 3600036; c14_i11++) {
    chartInstance->c14_network_array[c14_i11] = c14_dv5[c14_i11];
  }

  chartInstance->c14_is_active_c14_SmAHTR_r1_PITTRTNUKE = c14_v_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c14_u, 7)),
     "is_active_c14_SmAHTR_r1_PITTRTNUKE");
  sf_mex_destroy(&c14_u);
  c14_update_debugger_state_c14_SmAHTR_r1_PITTRTNUKE(chartInstance);
  sf_mex_destroy(&c14_st);
}

static void finalize_c14_SmAHTR_r1_PITTRTNUKE
  (SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c14_SmAHTR_r1_PITTRTNUKE
  (SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance)
{
  int32_T c14_i12;
  int32_T c14_i13;
  int32_T c14_i14;
  int32_T c14_i15;
  real_T (*c14_ynetwork_delay)[9];
  real_T (*c14_ydelay)[10];
  real_T (*c14_ymea)[9];
  real_T (*c14_ymea1)[9];
  c14_ynetwork_delay = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 3);
  c14_ydelay = (real_T (*)[10])ssGetOutputPortSignal(chartInstance->S, 2);
  c14_ymea = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
  c14_ymea1 = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 11U, chartInstance->c14_sfEvent);
  chartInstance->c14_sfEvent = CALL_EVENT;
  c14_chartstep_c14_SmAHTR_r1_PITTRTNUKE(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_SmAHTR_r1_PITTRTNUKEMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c14_i12 = 0; c14_i12 < 9; c14_i12++) {
    _SFD_DATA_RANGE_CHECK((*c14_ymea1)[c14_i12], 0U);
  }

  for (c14_i13 = 0; c14_i13 < 9; c14_i13++) {
    _SFD_DATA_RANGE_CHECK((*c14_ymea)[c14_i13], 1U);
  }

  for (c14_i14 = 0; c14_i14 < 10; c14_i14++) {
    _SFD_DATA_RANGE_CHECK((*c14_ydelay)[c14_i14], 2U);
  }

  for (c14_i15 = 0; c14_i15 < 9; c14_i15++) {
    _SFD_DATA_RANGE_CHECK((*c14_ynetwork_delay)[c14_i15], 4U);
  }
}

static void c14_chartstep_c14_SmAHTR_r1_PITTRTNUKE
  (SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance)
{
  int32_T c14_i16;
  real_T c14_ymea[9];
  uint32_T c14_debug_family_var_map[19];
  real_T c14_iterations;
  const mxArray *c14_text = NULL;
  const mxArray *c14_result = NULL;
  real_T c14_line_num;
  real_T c14_emergency_instance[9];
  real_T c14_resultz[18];
  const mxArray *c14_delay = NULL;
  real_T c14_network_delay[9];
  real_T c14_i_yg;
  real_T c14_nargin = 1.0;
  real_T c14_nargout = 3.0;
  real_T c14_ymea1[9];
  real_T c14_ydelay[10];
  real_T c14_ynetwork_delay[9];
  int32_T c14_i17;
  int32_T c14_i18;
  static char_T c14_cv0[11] = { 'n', 'o', 'E', 'r', 'r', 'o', 'r', '.', 't', 'x',
    't' };

  char_T c14_u[11];
  const mxArray *c14_y = NULL;
  real_T c14_dv6[18];
  int32_T c14_b_line_num;
  int32_T c14_i19;
  int32_T c14_i20;
  static real_T c14_dv7[10] = { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0
  };

  int32_T c14_i21;
  int32_T c14_i22;
  int32_T c14_i23;
  int32_T c14_i24;
  int32_T c14_i25;
  real_T c14_b_u[18];
  const mxArray *c14_b_y = NULL;
  real_T c14_dv8[10];
  int32_T c14_i26;
  int32_T c14_i27;
  real_T c14_b_result[18];
  uint32_T c14_b_debug_family_var_map[7];
  real_T c14_result_num[18];
  real_T c14_sz_y;
  real_T c14_i_rn;
  real_T c14_b_nargin = 1.0;
  real_T c14_b_nargout = 1.0;
  int32_T c14_i28;
  int32_T c14_i29;
  int32_T c14_i30;
  int32_T c14_b_i_rn;
  int32_T c14_i31;
  char_T c14_c_u;
  const mxArray *c14_c_y = NULL;
  real_T c14_hoistedGlobal;
  real_T c14_d_u;
  const mxArray *c14_d_y = NULL;
  int32_T c14_i32;
  int32_T c14_i33;
  int32_T c14_i34;
  int32_T c14_i35;
  int32_T c14_b_i_yg;
  real_T c14_d0;
  int32_T c14_i36;
  int64_T c14_i37;
  int32_T c14_i38;
  int32_T c14_i39;
  int32_T c14_i40;
  real_T (*c14_b_ymea1)[9];
  real_T (*c14_b_ydelay)[10];
  real_T (*c14_b_ynetwork_delay)[9];
  real_T (*c14_b_ymea)[9];
  boolean_T exitg1;
  c14_b_ynetwork_delay = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S,
    3);
  c14_b_ydelay = (real_T (*)[10])ssGetOutputPortSignal(chartInstance->S, 2);
  c14_b_ymea = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
  c14_b_ymea1 = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 11U, chartInstance->c14_sfEvent);
  for (c14_i16 = 0; c14_i16 < 9; c14_i16++) {
    c14_ymea[c14_i16] = (*c14_b_ymea)[c14_i16];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 19U, 19U, c14_debug_family_names,
    c14_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c14_iterations, 0U, c14_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c14_text, 1U, c14_i_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c14_result, 2U, c14_i_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c14_line_num, 3U, c14_g_sf_marshallOut,
    c14_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c14_emergency_instance, 4U,
    c14_h_sf_marshallOut, c14_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c14_resultz, 5U, c14_j_sf_marshallOut,
    c14_i_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c14_delay, 6U, c14_i_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c14_network_delay, 7U,
    c14_h_sf_marshallOut, c14_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c14_i_yg, 8U, c14_g_sf_marshallOut,
    c14_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c14_nargin, 9U, c14_g_sf_marshallOut,
    c14_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c14_nargout, 10U, c14_g_sf_marshallOut,
    c14_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c14_ymea, 11U, c14_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c14_ymea1, 12U, c14_e_sf_marshallOut,
    c14_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c14_ydelay, 13U, c14_f_sf_marshallOut,
    c14_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c14_ynetwork_delay, 14U,
    c14_e_sf_marshallOut, c14_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c14_delay1, 15U,
    c14_d_sf_marshallOut, c14_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c14_i, 16U,
    c14_c_sf_marshallOut, c14_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE
    (chartInstance->c14_last_emergency_instance, 17U, c14_b_sf_marshallOut,
     c14_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c14_network_array, 18U,
    c14_sf_marshallOut, c14_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 10);
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 11);
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 12);
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 13);
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 14);
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 15);
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 17);
  c14_iterations = 200002.0;
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 22);
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 23);
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 24);
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 25);
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 26);
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 28);
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 29);
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 30);
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 31);
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 32);
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 34);
  if (CV_EML_IF(0, 1, 0, !chartInstance->c14_i_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 35);
    chartInstance->c14_i = 0.0;
    chartInstance->c14_i_not_empty = true;
    _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 38);
    for (c14_i17 = 0; c14_i17 < 3600036; c14_i17++) {
      chartInstance->c14_network_array[c14_i17] = 0.0;
    }

    chartInstance->c14_network_array_not_empty = true;
    _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 39);
    for (c14_i18 = 0; c14_i18 < 11; c14_i18++) {
      c14_u[c14_i18] = c14_cv0[c14_i18];
    }

    c14_y = NULL;
    sf_mex_assign(&c14_y, sf_mex_create("y", c14_u, 10, 0U, 1U, 0U, 2, 1, 11),
                  false);
    sf_mex_assign(&c14_text, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "fopen", 1U, 1U, 14, c14_y), false);
    _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 41);
    sf_mex_assign(&c14_result, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "fgets", 1U, 1U, 14, sf_mex_dup(c14_text)), false);
    _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 45);
    c14_line_num = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 46);
    exitg1 = false;
    while ((exitg1 == false) && CV_EML_WHILE(0, 1, 0, c14_emlrt_marshallIn
            (chartInstance, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
              "ischar", 1U, 1U, 14, sf_mex_dup(c14_result)), "ischar"))) {
      _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 47);
      if (CV_EML_IF(0, 1, 1, c14_line_num <= c14_iterations)) {
        _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 48);
        c14_c_emlrt_marshallIn(chartInstance, sf_mex_call_debug
          (sfGlobalDebugInstanceStruct, "str2num", 1U, 1U, 14, sf_mex_dup
           (c14_result)), "str2num", c14_dv6);
        c14_b_line_num = _SFD_EML_ARRAY_BOUNDS_CHECK("network_array", (int32_T)
          _SFD_INTEGER_CHECK("line_num", c14_line_num), 1, 200002, 1, 0) - 1;
        for (c14_i19 = 0; c14_i19 < 18; c14_i19++) {
          chartInstance->c14_network_array[c14_b_line_num + 200002 * c14_i19] =
            c14_dv6[c14_i19];
        }

        _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 49);
        sf_mex_assign(&c14_result, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
          "fgets", 1U, 1U, 14, sf_mex_dup(c14_text)), false);
        _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 54);
        c14_line_num++;
        _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 46);
        _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
      } else {
        _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 51);
        exitg1 = true;
      }
    }

    _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 57);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "fclose", 0U, 1U, 14,
                      sf_mex_dup(c14_text));
  }

  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 61);
  chartInstance->c14_i++;
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 64);
  for (c14_i20 = 0; c14_i20 < 10; c14_i20++) {
    c14_ydelay[c14_i20] = c14_dv7[c14_i20];
  }

  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 65);
  for (c14_i21 = 0; c14_i21 < 9; c14_i21++) {
    c14_ynetwork_delay[c14_i21] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 67);
  for (c14_i22 = 0; c14_i22 < 9; c14_i22++) {
    c14_emergency_instance[c14_i22] = c14_ymea[c14_i22];
  }

  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 73);
  c14_i23 = _SFD_EML_ARRAY_BOUNDS_CHECK("network_array", (int32_T)
    _SFD_INTEGER_CHECK("i", chartInstance->c14_i), 1, 200002, 1, 0) - 1;
  for (c14_i24 = 0; c14_i24 < 18; c14_i24++) {
    c14_resultz[c14_i24] = chartInstance->c14_network_array[c14_i23 + 200002 *
      c14_i24];
  }

  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 81);
  for (c14_i25 = 0; c14_i25 < 18; c14_i25++) {
    c14_b_u[c14_i25] = c14_resultz[c14_i25];
  }

  c14_b_y = NULL;
  sf_mex_assign(&c14_b_y, sf_mex_create("y", c14_b_u, 0, 0U, 1U, 0U, 2, 1, 18),
                false);
  sf_mex_assign(&c14_delay, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
    "delay_summary", 1U, 1U, 14, c14_b_y), false);
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 82);
  c14_e_emlrt_marshallIn(chartInstance, sf_mex_call_debug
    (sfGlobalDebugInstanceStruct, "transpose", 1U, 1U, 14, sf_mex_dup(c14_delay)),
    "transpose", c14_dv8);
  for (c14_i26 = 0; c14_i26 < 10; c14_i26++) {
    c14_ydelay[c14_i26] = c14_dv8[c14_i26];
  }

  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 84);
  for (c14_i27 = 0; c14_i27 < 18; c14_i27++) {
    c14_b_result[c14_i27] = c14_resultz[c14_i27];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c14_b_debug_family_names,
    c14_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c14_result_num, 0U, c14_j_sf_marshallOut,
    c14_i_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c14_sz_y, 1U, c14_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c14_i_rn, 2U, c14_g_sf_marshallOut,
    c14_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c14_b_nargin, 3U, c14_g_sf_marshallOut,
    c14_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c14_b_nargout, 4U, c14_g_sf_marshallOut,
    c14_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c14_b_result, 5U, c14_j_sf_marshallOut,
    c14_i_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c14_network_delay, 6U,
    c14_h_sf_marshallOut, c14_h_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c14_sfEvent, 4);
  CV_SCRIPT_COND(0, 0, false);
  CV_SCRIPT_MCDC(0, 0, true);
  CV_SCRIPT_IF(0, 0, true);
  _SFD_SCRIPT_CALL(0U, chartInstance->c14_sfEvent, 5);
  for (c14_i28 = 0; c14_i28 < 18; c14_i28++) {
    c14_result_num[c14_i28] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c14_sfEvent, 6);
  for (c14_i29 = 0; c14_i29 < 18; c14_i29++) {
    c14_result_num[c14_i29] = c14_b_result[c14_i29];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c14_sfEvent, 7);
  c14_sz_y = 9.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c14_sfEvent, 9);
  for (c14_i30 = 0; c14_i30 < 9; c14_i30++) {
    c14_network_delay[c14_i30] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c14_sfEvent, 10);
  c14_i_rn = 1.0;
  c14_b_i_rn = 0;
  while (c14_b_i_rn < 9) {
    c14_i_rn = 1.0 + (real_T)c14_b_i_rn;
    CV_SCRIPT_FOR(0, 0, 1);
    _SFD_SCRIPT_CALL(0U, chartInstance->c14_sfEvent, 13);
    if (CV_SCRIPT_IF(0, 1, c14_result_num[_SFD_EML_ARRAY_BOUNDS_CHECK(
          "result_num", (int32_T)_SFD_INTEGER_CHECK("9+i_rn", 9.0 + c14_i_rn), 1,
          18, 1, 0) - 1] > 0.0)) {
      _SFD_SCRIPT_CALL(0U, chartInstance->c14_sfEvent, 14);
      c14_network_delay[_SFD_EML_ARRAY_BOUNDS_CHECK("delay", (int32_T)
        _SFD_INTEGER_CHECK("i_rn", c14_i_rn), 1, 9, 2, 0) - 1] =
        c14_result_num[_SFD_EML_ARRAY_BOUNDS_CHECK("result_num", (int32_T)
        _SFD_INTEGER_CHECK("9+i_rn", 9.0 + c14_i_rn), 1, 18, 1, 0) - 1];
    } else {
      _SFD_SCRIPT_CALL(0U, chartInstance->c14_sfEvent, 16);
      c14_network_delay[_SFD_EML_ARRAY_BOUNDS_CHECK("delay", (int32_T)
        _SFD_INTEGER_CHECK("i_rn", c14_i_rn), 1, 9, 2, 0) - 1] =
        c14_network_delay[_SFD_EML_ARRAY_BOUNDS_CHECK("delay", (int32_T)
        _SFD_INTEGER_CHECK("i_rn", c14_i_rn), 1, 9, 2, 0) - 1];
    }

    c14_b_i_rn++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_SCRIPT_FOR(0, 0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c14_sfEvent, -20);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 85);
  for (c14_i31 = 0; c14_i31 < 9; c14_i31++) {
    c14_ynetwork_delay[c14_i31] = c14_network_delay[c14_i31];
  }

  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 87);
  c14_c_u = 'i';
  c14_c_y = NULL;
  sf_mex_assign(&c14_c_y, sf_mex_create("y", &c14_c_u, 10, 0U, 0U, 0U, 0), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c14_c_y);
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 88);
  c14_hoistedGlobal = chartInstance->c14_i;
  c14_d_u = c14_hoistedGlobal;
  c14_d_y = NULL;
  sf_mex_assign(&c14_d_y, sf_mex_create("y", &c14_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c14_d_y);
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 90);
  for (c14_i32 = 0; c14_i32 < 9; c14_i32++) {
    chartInstance->c14_last_emergency_instance[c14_i32] = c14_ymea[c14_i32];
  }

  chartInstance->c14_last_emergency_instance_not_empty = true;
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 91);
  for (c14_i33 = 0; c14_i33 < 10; c14_i33++) {
    chartInstance->c14_delay1[c14_i33] = c14_ydelay[c14_i33];
  }

  chartInstance->c14_delay1_not_empty = true;
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 94);
  for (c14_i34 = 0; c14_i34 < 9; c14_i34++) {
    c14_ymea1[c14_i34] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 95);
  for (c14_i35 = 0; c14_i35 < 9; c14_i35++) {
    c14_ymea1[c14_i35] = c14_ymea[c14_i35];
  }

  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 98);
  c14_i_yg = 1.0;
  c14_b_i_yg = 0;
  while (c14_b_i_yg < 10) {
    c14_i_yg = 1.0 + (real_T)c14_b_i_yg;
    CV_EML_FOR(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 99);
    c14_d0 = muDoubleScalarRound(c14_ydelay[_SFD_EML_ARRAY_BOUNDS_CHECK("ydelay",
                                  (int32_T)_SFD_INTEGER_CHECK("i_yg", c14_i_yg),
      1, 10, 1, 0) - 1]);
    if (c14_d0 < 2.147483648E+9) {
      if (CV_SATURATION_EVAL(4, 0, 0, 1, c14_d0 >= -2.147483648E+9)) {
        c14_i36 = (int32_T)c14_d0;
      } else {
        c14_i36 = MIN_int32_T;
      }
    } else if (CV_SATURATION_EVAL(4, 0, 0, 0, c14_d0 >= 2.147483648E+9)) {
      c14_i36 = MAX_int32_T;
    } else {
      c14_i36 = 0;
    }

    c14_set_ydelay_global(chartInstance, _SFD_EML_ARRAY_BOUNDS_CHECK(
      "ydelay_global", (int32_T)_SFD_INTEGER_CHECK("i_yg", c14_i_yg), 1, 10, 1,
      0) - 1, c14_i36);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    c14_b_i_yg++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 0, 0);
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 103);
  c14_i37 = (int64_T)c14_get_counter_global(chartInstance, 0) + 1L;
  if (c14_i37 > 2147483647L) {
    CV_SATURATION_EVAL(4, 0, 1, 0, 1);
    c14_i37 = 2147483647L;
  } else {
    if (CV_SATURATION_EVAL(4, 0, 1, 0, c14_i37 < -2147483648L)) {
      c14_i37 = -2147483648L;
    }
  }

  c14_set_counter_global(chartInstance, 0, (int32_T)c14_i37);
  ssUpdateDataStoreLog(chartInstance->S, 0);
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, -103);
  _SFD_SYMBOL_SCOPE_POP();
  sf_mex_destroy(&c14_text);
  sf_mex_destroy(&c14_result);
  sf_mex_destroy(&c14_delay);
  for (c14_i38 = 0; c14_i38 < 9; c14_i38++) {
    (*c14_b_ymea1)[c14_i38] = c14_ymea1[c14_i38];
  }

  for (c14_i39 = 0; c14_i39 < 10; c14_i39++) {
    (*c14_b_ydelay)[c14_i39] = c14_ydelay[c14_i39];
  }

  for (c14_i40 = 0; c14_i40 < 9; c14_i40++) {
    (*c14_b_ynetwork_delay)[c14_i40] = c14_ynetwork_delay[c14_i40];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 11U, chartInstance->c14_sfEvent);
}

static void initSimStructsc14_SmAHTR_r1_PITTRTNUKE
  (SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c14_machineNumber, uint32_T
  c14_chartNumber, uint32_T c14_instanceNumber)
{
  (void)c14_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c14_chartNumber, c14_instanceNumber, 0U,
    sf_debug_get_script_id(
    "/Users/wangwenchen/wcps_apps/steady_state_HX/network_delay_summary.m"));
}

static boolean_T c14_emlrt_marshallIn(SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c14_ischar, const char_T *c14_identifier)
{
  boolean_T c14_y;
  emlrtMsgIdentifier c14_thisId;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_y = c14_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_ischar),
    &c14_thisId);
  sf_mex_destroy(&c14_ischar);
  return c14_y;
}

static boolean_T c14_b_emlrt_marshallIn(SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId)
{
  boolean_T c14_y;
  boolean_T c14_b0;
  (void)chartInstance;
  sf_mex_import(c14_parentId, sf_mex_dup(c14_u), &c14_b0, 1, 11, 0U, 0, 0U, 0);
  c14_y = c14_b0;
  sf_mex_destroy(&c14_u);
  return c14_y;
}

static void c14_c_emlrt_marshallIn(SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c14_str2num, const char_T *c14_identifier,
  real_T c14_y[18])
{
  emlrtMsgIdentifier c14_thisId;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_str2num), &c14_thisId,
    c14_y);
  sf_mex_destroy(&c14_str2num);
}

static void c14_d_emlrt_marshallIn(SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId,
  real_T c14_y[18])
{
  real_T c14_dv9[18];
  int32_T c14_i41;
  (void)chartInstance;
  sf_mex_import(c14_parentId, sf_mex_dup(c14_u), c14_dv9, 0, 0, 0U, 1, 0U, 2, 1,
                18);
  for (c14_i41 = 0; c14_i41 < 18; c14_i41++) {
    c14_y[c14_i41] = c14_dv9[c14_i41];
  }

  sf_mex_destroy(&c14_u);
}

static void c14_e_emlrt_marshallIn(SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c14_transpose, const char_T *c14_identifier,
  real_T c14_y[10])
{
  emlrtMsgIdentifier c14_thisId;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_transpose), &c14_thisId,
    c14_y);
  sf_mex_destroy(&c14_transpose);
}

static void c14_f_emlrt_marshallIn(SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId,
  real_T c14_y[10])
{
  real_T c14_dv10[10];
  int32_T c14_i42;
  (void)chartInstance;
  sf_mex_import(c14_parentId, sf_mex_dup(c14_u), c14_dv10, 1, 0, 0U, 1, 0U, 1,
                10);
  for (c14_i42 = 0; c14_i42 < 10; c14_i42++) {
    c14_y[c14_i42] = c14_dv10[c14_i42];
  }

  sf_mex_destroy(&c14_u);
}

static const mxArray *c14_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData)
{
  const mxArray *c14_mxArrayOutData = NULL;
  int32_T c14_i43;
  int32_T c14_i44;
  int32_T c14_i45;
  static real_T c14_b_inData[3600036];
  int32_T c14_i46;
  int32_T c14_i47;
  int32_T c14_i48;
  static real_T c14_u[3600036];
  const mxArray *c14_y = NULL;
  SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance;
  chartInstance = (SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct *)chartInstanceVoid;
  c14_mxArrayOutData = NULL;
  c14_i43 = 0;
  for (c14_i44 = 0; c14_i44 < 18; c14_i44++) {
    for (c14_i45 = 0; c14_i45 < 200002; c14_i45++) {
      c14_b_inData[c14_i45 + c14_i43] = (*(real_T (*)[3600036])c14_inData)
        [c14_i45 + c14_i43];
    }

    c14_i43 += 200002;
  }

  c14_i46 = 0;
  for (c14_i47 = 0; c14_i47 < 18; c14_i47++) {
    for (c14_i48 = 0; c14_i48 < 200002; c14_i48++) {
      c14_u[c14_i48 + c14_i46] = c14_b_inData[c14_i48 + c14_i46];
    }

    c14_i46 += 200002;
  }

  c14_y = NULL;
  if (!chartInstance->c14_network_array_not_empty) {
    sf_mex_assign(&c14_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c14_y, sf_mex_create("y", c14_u, 0, 0U, 1U, 0U, 2, 200002, 18),
                  false);
  }

  sf_mex_assign(&c14_mxArrayOutData, c14_y, false);
  return c14_mxArrayOutData;
}

static void c14_g_emlrt_marshallIn(SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c14_b_network_array, const char_T
  *c14_identifier, real_T c14_y[3600036])
{
  emlrtMsgIdentifier c14_thisId;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_b_network_array),
    &c14_thisId, c14_y);
  sf_mex_destroy(&c14_b_network_array);
}

static void c14_h_emlrt_marshallIn(SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId,
  real_T c14_y[3600036])
{
  static real_T c14_dv11[3600036];
  int32_T c14_i49;
  if (mxIsEmpty(c14_u)) {
    chartInstance->c14_network_array_not_empty = false;
  } else {
    chartInstance->c14_network_array_not_empty = true;
    sf_mex_import(c14_parentId, sf_mex_dup(c14_u), c14_dv11, 1, 0, 0U, 1, 0U, 2,
                  200002, 18);
    for (c14_i49 = 0; c14_i49 < 3600036; c14_i49++) {
      c14_y[c14_i49] = c14_dv11[c14_i49];
    }
  }

  sf_mex_destroy(&c14_u);
}

static void c14_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData)
{
  const mxArray *c14_b_network_array;
  const char_T *c14_identifier;
  emlrtMsgIdentifier c14_thisId;
  static real_T c14_y[3600036];
  int32_T c14_i50;
  int32_T c14_i51;
  int32_T c14_i52;
  SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance;
  chartInstance = (SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct *)chartInstanceVoid;
  c14_b_network_array = sf_mex_dup(c14_mxArrayInData);
  c14_identifier = c14_varName;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_b_network_array),
    &c14_thisId, c14_y);
  sf_mex_destroy(&c14_b_network_array);
  c14_i50 = 0;
  for (c14_i51 = 0; c14_i51 < 18; c14_i51++) {
    for (c14_i52 = 0; c14_i52 < 200002; c14_i52++) {
      (*(real_T (*)[3600036])c14_outData)[c14_i52 + c14_i50] = c14_y[c14_i52 +
        c14_i50];
    }

    c14_i50 += 200002;
  }

  sf_mex_destroy(&c14_mxArrayInData);
}

static const mxArray *c14_b_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData)
{
  const mxArray *c14_mxArrayOutData = NULL;
  int32_T c14_i53;
  real_T c14_b_inData[9];
  int32_T c14_i54;
  real_T c14_u[9];
  const mxArray *c14_y = NULL;
  SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance;
  chartInstance = (SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct *)chartInstanceVoid;
  c14_mxArrayOutData = NULL;
  for (c14_i53 = 0; c14_i53 < 9; c14_i53++) {
    c14_b_inData[c14_i53] = (*(real_T (*)[9])c14_inData)[c14_i53];
  }

  for (c14_i54 = 0; c14_i54 < 9; c14_i54++) {
    c14_u[c14_i54] = c14_b_inData[c14_i54];
  }

  c14_y = NULL;
  if (!chartInstance->c14_last_emergency_instance_not_empty) {
    sf_mex_assign(&c14_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c14_y, sf_mex_create("y", c14_u, 0, 0U, 1U, 0U, 2, 1, 9),
                  false);
  }

  sf_mex_assign(&c14_mxArrayOutData, c14_y, false);
  return c14_mxArrayOutData;
}

static void c14_i_emlrt_marshallIn(SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c14_b_last_emergency_instance, const char_T
  *c14_identifier, real_T c14_y[9])
{
  emlrtMsgIdentifier c14_thisId;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_b_last_emergency_instance),
    &c14_thisId, c14_y);
  sf_mex_destroy(&c14_b_last_emergency_instance);
}

static void c14_j_emlrt_marshallIn(SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId,
  real_T c14_y[9])
{
  real_T c14_dv12[9];
  int32_T c14_i55;
  if (mxIsEmpty(c14_u)) {
    chartInstance->c14_last_emergency_instance_not_empty = false;
  } else {
    chartInstance->c14_last_emergency_instance_not_empty = true;
    sf_mex_import(c14_parentId, sf_mex_dup(c14_u), c14_dv12, 1, 0, 0U, 1, 0U, 2,
                  1, 9);
    for (c14_i55 = 0; c14_i55 < 9; c14_i55++) {
      c14_y[c14_i55] = c14_dv12[c14_i55];
    }
  }

  sf_mex_destroy(&c14_u);
}

static void c14_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData)
{
  const mxArray *c14_b_last_emergency_instance;
  const char_T *c14_identifier;
  emlrtMsgIdentifier c14_thisId;
  real_T c14_y[9];
  int32_T c14_i56;
  SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance;
  chartInstance = (SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct *)chartInstanceVoid;
  c14_b_last_emergency_instance = sf_mex_dup(c14_mxArrayInData);
  c14_identifier = c14_varName;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_b_last_emergency_instance),
    &c14_thisId, c14_y);
  sf_mex_destroy(&c14_b_last_emergency_instance);
  for (c14_i56 = 0; c14_i56 < 9; c14_i56++) {
    (*(real_T (*)[9])c14_outData)[c14_i56] = c14_y[c14_i56];
  }

  sf_mex_destroy(&c14_mxArrayInData);
}

static const mxArray *c14_c_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData)
{
  const mxArray *c14_mxArrayOutData = NULL;
  real_T c14_u;
  const mxArray *c14_y = NULL;
  SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance;
  chartInstance = (SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct *)chartInstanceVoid;
  c14_mxArrayOutData = NULL;
  c14_u = *(real_T *)c14_inData;
  c14_y = NULL;
  if (!chartInstance->c14_i_not_empty) {
    sf_mex_assign(&c14_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c14_y, sf_mex_create("y", &c14_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_assign(&c14_mxArrayOutData, c14_y, false);
  return c14_mxArrayOutData;
}

static real_T c14_k_emlrt_marshallIn(SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c14_b_i, const char_T *c14_identifier)
{
  real_T c14_y;
  emlrtMsgIdentifier c14_thisId;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_y = c14_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_b_i), &c14_thisId);
  sf_mex_destroy(&c14_b_i);
  return c14_y;
}

static real_T c14_l_emlrt_marshallIn(SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId)
{
  real_T c14_y;
  real_T c14_d1;
  if (mxIsEmpty(c14_u)) {
    chartInstance->c14_i_not_empty = false;
  } else {
    chartInstance->c14_i_not_empty = true;
    sf_mex_import(c14_parentId, sf_mex_dup(c14_u), &c14_d1, 1, 0, 0U, 0, 0U, 0);
    c14_y = c14_d1;
  }

  sf_mex_destroy(&c14_u);
  return c14_y;
}

static void c14_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData)
{
  const mxArray *c14_b_i;
  const char_T *c14_identifier;
  emlrtMsgIdentifier c14_thisId;
  real_T c14_y;
  SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance;
  chartInstance = (SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct *)chartInstanceVoid;
  c14_b_i = sf_mex_dup(c14_mxArrayInData);
  c14_identifier = c14_varName;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_y = c14_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_b_i), &c14_thisId);
  sf_mex_destroy(&c14_b_i);
  *(real_T *)c14_outData = c14_y;
  sf_mex_destroy(&c14_mxArrayInData);
}

static const mxArray *c14_d_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData)
{
  const mxArray *c14_mxArrayOutData = NULL;
  int32_T c14_i57;
  real_T c14_b_inData[10];
  int32_T c14_i58;
  real_T c14_u[10];
  const mxArray *c14_y = NULL;
  SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance;
  chartInstance = (SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct *)chartInstanceVoid;
  c14_mxArrayOutData = NULL;
  for (c14_i57 = 0; c14_i57 < 10; c14_i57++) {
    c14_b_inData[c14_i57] = (*(real_T (*)[10])c14_inData)[c14_i57];
  }

  for (c14_i58 = 0; c14_i58 < 10; c14_i58++) {
    c14_u[c14_i58] = c14_b_inData[c14_i58];
  }

  c14_y = NULL;
  if (!chartInstance->c14_delay1_not_empty) {
    sf_mex_assign(&c14_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c14_y, sf_mex_create("y", c14_u, 0, 0U, 1U, 0U, 1, 10), false);
  }

  sf_mex_assign(&c14_mxArrayOutData, c14_y, false);
  return c14_mxArrayOutData;
}

static void c14_m_emlrt_marshallIn(SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c14_b_delay1, const char_T *c14_identifier,
  real_T c14_y[10])
{
  emlrtMsgIdentifier c14_thisId;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_b_delay1), &c14_thisId,
    c14_y);
  sf_mex_destroy(&c14_b_delay1);
}

static void c14_n_emlrt_marshallIn(SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId,
  real_T c14_y[10])
{
  real_T c14_dv13[10];
  int32_T c14_i59;
  if (mxIsEmpty(c14_u)) {
    chartInstance->c14_delay1_not_empty = false;
  } else {
    chartInstance->c14_delay1_not_empty = true;
    sf_mex_import(c14_parentId, sf_mex_dup(c14_u), c14_dv13, 1, 0, 0U, 1, 0U, 1,
                  10);
    for (c14_i59 = 0; c14_i59 < 10; c14_i59++) {
      c14_y[c14_i59] = c14_dv13[c14_i59];
    }
  }

  sf_mex_destroy(&c14_u);
}

static void c14_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData)
{
  const mxArray *c14_b_delay1;
  const char_T *c14_identifier;
  emlrtMsgIdentifier c14_thisId;
  real_T c14_y[10];
  int32_T c14_i60;
  SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance;
  chartInstance = (SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct *)chartInstanceVoid;
  c14_b_delay1 = sf_mex_dup(c14_mxArrayInData);
  c14_identifier = c14_varName;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_b_delay1), &c14_thisId,
    c14_y);
  sf_mex_destroy(&c14_b_delay1);
  for (c14_i60 = 0; c14_i60 < 10; c14_i60++) {
    (*(real_T (*)[10])c14_outData)[c14_i60] = c14_y[c14_i60];
  }

  sf_mex_destroy(&c14_mxArrayInData);
}

static const mxArray *c14_e_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData)
{
  const mxArray *c14_mxArrayOutData = NULL;
  int32_T c14_i61;
  real_T c14_b_inData[9];
  int32_T c14_i62;
  real_T c14_u[9];
  const mxArray *c14_y = NULL;
  SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance;
  chartInstance = (SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct *)chartInstanceVoid;
  c14_mxArrayOutData = NULL;
  for (c14_i61 = 0; c14_i61 < 9; c14_i61++) {
    c14_b_inData[c14_i61] = (*(real_T (*)[9])c14_inData)[c14_i61];
  }

  for (c14_i62 = 0; c14_i62 < 9; c14_i62++) {
    c14_u[c14_i62] = c14_b_inData[c14_i62];
  }

  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_create("y", c14_u, 0, 0U, 1U, 0U, 1, 9), false);
  sf_mex_assign(&c14_mxArrayOutData, c14_y, false);
  return c14_mxArrayOutData;
}

static void c14_o_emlrt_marshallIn(SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c14_ynetwork_delay, const char_T
  *c14_identifier, real_T c14_y[9])
{
  emlrtMsgIdentifier c14_thisId;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_p_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_ynetwork_delay),
    &c14_thisId, c14_y);
  sf_mex_destroy(&c14_ynetwork_delay);
}

static void c14_p_emlrt_marshallIn(SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId,
  real_T c14_y[9])
{
  real_T c14_dv14[9];
  int32_T c14_i63;
  (void)chartInstance;
  sf_mex_import(c14_parentId, sf_mex_dup(c14_u), c14_dv14, 1, 0, 0U, 1, 0U, 1, 9);
  for (c14_i63 = 0; c14_i63 < 9; c14_i63++) {
    c14_y[c14_i63] = c14_dv14[c14_i63];
  }

  sf_mex_destroy(&c14_u);
}

static void c14_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData)
{
  const mxArray *c14_ynetwork_delay;
  const char_T *c14_identifier;
  emlrtMsgIdentifier c14_thisId;
  real_T c14_y[9];
  int32_T c14_i64;
  SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance;
  chartInstance = (SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct *)chartInstanceVoid;
  c14_ynetwork_delay = sf_mex_dup(c14_mxArrayInData);
  c14_identifier = c14_varName;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_p_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_ynetwork_delay),
    &c14_thisId, c14_y);
  sf_mex_destroy(&c14_ynetwork_delay);
  for (c14_i64 = 0; c14_i64 < 9; c14_i64++) {
    (*(real_T (*)[9])c14_outData)[c14_i64] = c14_y[c14_i64];
  }

  sf_mex_destroy(&c14_mxArrayInData);
}

static const mxArray *c14_f_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData)
{
  const mxArray *c14_mxArrayOutData = NULL;
  int32_T c14_i65;
  real_T c14_b_inData[10];
  int32_T c14_i66;
  real_T c14_u[10];
  const mxArray *c14_y = NULL;
  SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance;
  chartInstance = (SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct *)chartInstanceVoid;
  c14_mxArrayOutData = NULL;
  for (c14_i65 = 0; c14_i65 < 10; c14_i65++) {
    c14_b_inData[c14_i65] = (*(real_T (*)[10])c14_inData)[c14_i65];
  }

  for (c14_i66 = 0; c14_i66 < 10; c14_i66++) {
    c14_u[c14_i66] = c14_b_inData[c14_i66];
  }

  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_create("y", c14_u, 0, 0U, 1U, 0U, 1, 10), false);
  sf_mex_assign(&c14_mxArrayOutData, c14_y, false);
  return c14_mxArrayOutData;
}

static void c14_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData)
{
  const mxArray *c14_transpose;
  const char_T *c14_identifier;
  emlrtMsgIdentifier c14_thisId;
  real_T c14_y[10];
  int32_T c14_i67;
  SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance;
  chartInstance = (SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct *)chartInstanceVoid;
  c14_transpose = sf_mex_dup(c14_mxArrayInData);
  c14_identifier = c14_varName;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_transpose), &c14_thisId,
    c14_y);
  sf_mex_destroy(&c14_transpose);
  for (c14_i67 = 0; c14_i67 < 10; c14_i67++) {
    (*(real_T (*)[10])c14_outData)[c14_i67] = c14_y[c14_i67];
  }

  sf_mex_destroy(&c14_mxArrayInData);
}

static const mxArray *c14_g_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData)
{
  const mxArray *c14_mxArrayOutData = NULL;
  real_T c14_u;
  const mxArray *c14_y = NULL;
  SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance;
  chartInstance = (SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct *)chartInstanceVoid;
  c14_mxArrayOutData = NULL;
  c14_u = *(real_T *)c14_inData;
  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_create("y", &c14_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c14_mxArrayOutData, c14_y, false);
  return c14_mxArrayOutData;
}

static real_T c14_q_emlrt_marshallIn(SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId)
{
  real_T c14_y;
  real_T c14_d2;
  (void)chartInstance;
  sf_mex_import(c14_parentId, sf_mex_dup(c14_u), &c14_d2, 1, 0, 0U, 0, 0U, 0);
  c14_y = c14_d2;
  sf_mex_destroy(&c14_u);
  return c14_y;
}

static void c14_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData)
{
  const mxArray *c14_nargout;
  const char_T *c14_identifier;
  emlrtMsgIdentifier c14_thisId;
  real_T c14_y;
  SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance;
  chartInstance = (SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct *)chartInstanceVoid;
  c14_nargout = sf_mex_dup(c14_mxArrayInData);
  c14_identifier = c14_varName;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_y = c14_q_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_nargout),
    &c14_thisId);
  sf_mex_destroy(&c14_nargout);
  *(real_T *)c14_outData = c14_y;
  sf_mex_destroy(&c14_mxArrayInData);
}

static const mxArray *c14_h_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData)
{
  const mxArray *c14_mxArrayOutData = NULL;
  int32_T c14_i68;
  real_T c14_b_inData[9];
  int32_T c14_i69;
  real_T c14_u[9];
  const mxArray *c14_y = NULL;
  SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance;
  chartInstance = (SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct *)chartInstanceVoid;
  c14_mxArrayOutData = NULL;
  for (c14_i68 = 0; c14_i68 < 9; c14_i68++) {
    c14_b_inData[c14_i68] = (*(real_T (*)[9])c14_inData)[c14_i68];
  }

  for (c14_i69 = 0; c14_i69 < 9; c14_i69++) {
    c14_u[c14_i69] = c14_b_inData[c14_i69];
  }

  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_create("y", c14_u, 0, 0U, 1U, 0U, 2, 1, 9), false);
  sf_mex_assign(&c14_mxArrayOutData, c14_y, false);
  return c14_mxArrayOutData;
}

static void c14_r_emlrt_marshallIn(SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId,
  real_T c14_y[9])
{
  real_T c14_dv15[9];
  int32_T c14_i70;
  (void)chartInstance;
  sf_mex_import(c14_parentId, sf_mex_dup(c14_u), c14_dv15, 1, 0, 0U, 1, 0U, 2, 1,
                9);
  for (c14_i70 = 0; c14_i70 < 9; c14_i70++) {
    c14_y[c14_i70] = c14_dv15[c14_i70];
  }

  sf_mex_destroy(&c14_u);
}

static void c14_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData)
{
  const mxArray *c14_network_delay;
  const char_T *c14_identifier;
  emlrtMsgIdentifier c14_thisId;
  real_T c14_y[9];
  int32_T c14_i71;
  SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance;
  chartInstance = (SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct *)chartInstanceVoid;
  c14_network_delay = sf_mex_dup(c14_mxArrayInData);
  c14_identifier = c14_varName;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_r_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_network_delay),
    &c14_thisId, c14_y);
  sf_mex_destroy(&c14_network_delay);
  for (c14_i71 = 0; c14_i71 < 9; c14_i71++) {
    (*(real_T (*)[9])c14_outData)[c14_i71] = c14_y[c14_i71];
  }

  sf_mex_destroy(&c14_mxArrayInData);
}

static const mxArray *c14_i_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData)
{
  const mxArray *c14_mxArrayOutData = NULL;
  const mxArray *c14_u;
  const mxArray *c14_y = NULL;
  SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance;
  chartInstance = (SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct *)chartInstanceVoid;
  c14_mxArrayOutData = NULL;
  c14_u = sf_mex_dup(*(const mxArray **)c14_inData);
  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_duplicatearraysafe(&c14_u), false);
  sf_mex_destroy(&c14_u);
  sf_mex_assign(&c14_mxArrayOutData, c14_y, false);
  return c14_mxArrayOutData;
}

static const mxArray *c14_j_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData)
{
  const mxArray *c14_mxArrayOutData = NULL;
  int32_T c14_i72;
  real_T c14_b_inData[18];
  int32_T c14_i73;
  real_T c14_u[18];
  const mxArray *c14_y = NULL;
  SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance;
  chartInstance = (SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct *)chartInstanceVoid;
  c14_mxArrayOutData = NULL;
  for (c14_i72 = 0; c14_i72 < 18; c14_i72++) {
    c14_b_inData[c14_i72] = (*(real_T (*)[18])c14_inData)[c14_i72];
  }

  for (c14_i73 = 0; c14_i73 < 18; c14_i73++) {
    c14_u[c14_i73] = c14_b_inData[c14_i73];
  }

  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_create("y", c14_u, 0, 0U, 1U, 0U, 2, 1, 18),
                false);
  sf_mex_assign(&c14_mxArrayOutData, c14_y, false);
  return c14_mxArrayOutData;
}

static void c14_s_emlrt_marshallIn(SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId,
  real_T c14_y[18])
{
  real_T c14_dv16[18];
  int32_T c14_i74;
  (void)chartInstance;
  sf_mex_import(c14_parentId, sf_mex_dup(c14_u), c14_dv16, 1, 0, 0U, 1, 0U, 2, 1,
                18);
  for (c14_i74 = 0; c14_i74 < 18; c14_i74++) {
    c14_y[c14_i74] = c14_dv16[c14_i74];
  }

  sf_mex_destroy(&c14_u);
}

static void c14_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData)
{
  const mxArray *c14_resultz;
  const char_T *c14_identifier;
  emlrtMsgIdentifier c14_thisId;
  real_T c14_y[18];
  int32_T c14_i75;
  SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance;
  chartInstance = (SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct *)chartInstanceVoid;
  c14_resultz = sf_mex_dup(c14_mxArrayInData);
  c14_identifier = c14_varName;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_s_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_resultz), &c14_thisId,
    c14_y);
  sf_mex_destroy(&c14_resultz);
  for (c14_i75 = 0; c14_i75 < 18; c14_i75++) {
    (*(real_T (*)[18])c14_outData)[c14_i75] = c14_y[c14_i75];
  }

  sf_mex_destroy(&c14_mxArrayInData);
}

const mxArray *sf_c14_SmAHTR_r1_PITTRTNUKE_get_eml_resolved_functions_info(void)
{
  const mxArray *c14_nameCaptureInfo = NULL;
  c14_nameCaptureInfo = NULL;
  sf_mex_assign(&c14_nameCaptureInfo, sf_mex_createstruct("structure", 2, 2, 1),
                false);
  c14_info_helper(&c14_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c14_nameCaptureInfo);
  return c14_nameCaptureInfo;
}

static void c14_info_helper(const mxArray **c14_info)
{
  const mxArray *c14_rhs0 = NULL;
  const mxArray *c14_lhs0 = NULL;
  const mxArray *c14_rhs1 = NULL;
  const mxArray *c14_lhs1 = NULL;
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("fclose"), "name", "name", 0);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("mxArray"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fclose.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1381871900U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c14_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c14_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(""), "context", "context", 1);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("network_delay_summary"),
                  "name", "name", 1);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[E]/Users/wangwenchen/wcps_apps/steady_state_HX/network_delay_summary.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1459525395U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c14_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c14_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs1), "lhs", "lhs",
                  1);
  sf_mex_destroy(&c14_rhs0);
  sf_mex_destroy(&c14_lhs0);
  sf_mex_destroy(&c14_rhs1);
  sf_mex_destroy(&c14_lhs1);
}

static const mxArray *c14_emlrt_marshallOut(const char * c14_u)
{
  const mxArray *c14_y = NULL;
  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_create("y", c14_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c14_u)), false);
  return c14_y;
}

static const mxArray *c14_b_emlrt_marshallOut(const uint32_T c14_u)
{
  const mxArray *c14_y = NULL;
  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_create("y", &c14_u, 7, 0U, 0U, 0U, 0), false);
  return c14_y;
}

static const mxArray *c14_k_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData)
{
  const mxArray *c14_mxArrayOutData = NULL;
  int32_T c14_u;
  const mxArray *c14_y = NULL;
  SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance;
  chartInstance = (SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct *)chartInstanceVoid;
  c14_mxArrayOutData = NULL;
  c14_u = *(int32_T *)c14_inData;
  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_create("y", &c14_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c14_mxArrayOutData, c14_y, false);
  return c14_mxArrayOutData;
}

static int32_T c14_t_emlrt_marshallIn(SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId)
{
  int32_T c14_y;
  int32_T c14_i76;
  (void)chartInstance;
  sf_mex_import(c14_parentId, sf_mex_dup(c14_u), &c14_i76, 1, 6, 0U, 0, 0U, 0);
  c14_y = c14_i76;
  sf_mex_destroy(&c14_u);
  return c14_y;
}

static void c14_j_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData)
{
  const mxArray *c14_b_sfEvent;
  const char_T *c14_identifier;
  emlrtMsgIdentifier c14_thisId;
  int32_T c14_y;
  SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance;
  chartInstance = (SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct *)chartInstanceVoid;
  c14_b_sfEvent = sf_mex_dup(c14_mxArrayInData);
  c14_identifier = c14_varName;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_y = c14_t_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_b_sfEvent),
    &c14_thisId);
  sf_mex_destroy(&c14_b_sfEvent);
  *(int32_T *)c14_outData = c14_y;
  sf_mex_destroy(&c14_mxArrayInData);
}

static const mxArray *c14_l_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData)
{
  const mxArray *c14_mxArrayOutData = NULL;
  int32_T c14_i77;
  int32_T c14_b_inData[10];
  int32_T c14_i78;
  int32_T c14_u[10];
  const mxArray *c14_y = NULL;
  SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance;
  chartInstance = (SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct *)chartInstanceVoid;
  c14_mxArrayOutData = NULL;
  for (c14_i77 = 0; c14_i77 < 10; c14_i77++) {
    c14_b_inData[c14_i77] = (*(int32_T (*)[10])c14_inData)[c14_i77];
  }

  for (c14_i78 = 0; c14_i78 < 10; c14_i78++) {
    c14_u[c14_i78] = c14_b_inData[c14_i78];
  }

  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_create("y", c14_u, 6, 0U, 1U, 0U, 1, 10), false);
  sf_mex_assign(&c14_mxArrayOutData, c14_y, false);
  return c14_mxArrayOutData;
}

static void c14_u_emlrt_marshallIn(SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId,
  int32_T c14_y[10])
{
  int32_T c14_iv0[10];
  int32_T c14_i79;
  (void)chartInstance;
  sf_mex_import(c14_parentId, sf_mex_dup(c14_u), c14_iv0, 1, 6, 0U, 1, 0U, 1, 10);
  for (c14_i79 = 0; c14_i79 < 10; c14_i79++) {
    c14_y[c14_i79] = c14_iv0[c14_i79];
  }

  sf_mex_destroy(&c14_u);
}

static void c14_k_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData)
{
  const mxArray *c14_ydelay_global;
  const char_T *c14_identifier;
  emlrtMsgIdentifier c14_thisId;
  int32_T c14_y[10];
  int32_T c14_i80;
  SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance;
  chartInstance = (SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct *)chartInstanceVoid;
  c14_ydelay_global = sf_mex_dup(c14_mxArrayInData);
  c14_identifier = c14_varName;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_u_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_ydelay_global),
    &c14_thisId, c14_y);
  sf_mex_destroy(&c14_ydelay_global);
  for (c14_i80 = 0; c14_i80 < 10; c14_i80++) {
    (*(int32_T (*)[10])c14_outData)[c14_i80] = c14_y[c14_i80];
  }

  sf_mex_destroy(&c14_mxArrayInData);
}

static uint8_T c14_v_emlrt_marshallIn(SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c14_b_is_active_c14_SmAHTR_r1_PITTRTNUKE, const
  char_T *c14_identifier)
{
  uint8_T c14_y;
  emlrtMsgIdentifier c14_thisId;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_y = c14_w_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c14_b_is_active_c14_SmAHTR_r1_PITTRTNUKE), &c14_thisId);
  sf_mex_destroy(&c14_b_is_active_c14_SmAHTR_r1_PITTRTNUKE);
  return c14_y;
}

static uint8_T c14_w_emlrt_marshallIn(SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId)
{
  uint8_T c14_y;
  uint8_T c14_u0;
  (void)chartInstance;
  sf_mex_import(c14_parentId, sf_mex_dup(c14_u), &c14_u0, 1, 3, 0U, 0, 0U, 0);
  c14_y = c14_u0;
  sf_mex_destroy(&c14_u);
  return c14_y;
}

static int32_T c14_get_counter_global(SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, uint32_T c14_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 0, NULL, c14_b);
  if (chartInstance->c14_counter_global_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'counter_global\' (#166) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c14_counter_global_address;
}

static void c14_set_counter_global(SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, uint32_T c14_b, int32_T c14_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 0, NULL, c14_b);
  if (chartInstance->c14_counter_global_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'counter_global\' (#166) in the initialization routine of the chart.\n");
  }

  *chartInstance->c14_counter_global_address = c14_c;
}

static int32_T *c14_access_counter_global
  (SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance, uint32_T c14_b)
{
  int32_T *c14_c;
  ssReadFromDataStore(chartInstance->S, 0, NULL);
  if (chartInstance->c14_counter_global_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'counter_global\' (#166) in the initialization routine of the chart.\n");
  }

  c14_c = chartInstance->c14_counter_global_address;
  if (c14_b == 0) {
    ssWriteToDataStore(chartInstance->S, 0, NULL);
  }

  return c14_c;
}

static int32_T c14_get_ydelay_global(SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, uint32_T c14_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 1, NULL, c14_b);
  if (chartInstance->c14_ydelay_global_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'ydelay_global\' (#164) in the initialization routine of the chart.\n");
  }

  return (*chartInstance->c14_ydelay_global_address)[c14_b];
}

static void c14_set_ydelay_global(SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, uint32_T c14_b, int32_T c14_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 1, NULL, c14_b);
  if (chartInstance->c14_ydelay_global_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'ydelay_global\' (#164) in the initialization routine of the chart.\n");
  }

  (*chartInstance->c14_ydelay_global_address)[c14_b] = c14_c;
}

static int32_T *c14_access_ydelay_global
  (SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance, uint32_T c14_b)
{
  int32_T *c14_c;
  ssReadFromDataStore(chartInstance->S, 1, NULL);
  if (chartInstance->c14_ydelay_global_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'ydelay_global\' (#164) in the initialization routine of the chart.\n");
  }

  c14_c = *chartInstance->c14_ydelay_global_address;
  if (c14_b == 0) {
    ssWriteToDataStore(chartInstance->S, 1, NULL);
  }

  return c14_c;
}

static void init_dsm_address_info(SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance)
{
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "counter_global", (void **)
    &chartInstance->c14_counter_global_address,
    &chartInstance->c14_counter_global_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "ydelay_global", (void **)
    &chartInstance->c14_ydelay_global_address,
    &chartInstance->c14_ydelay_global_index);
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

void sf_c14_SmAHTR_r1_PITTRTNUKE_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2209485859U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(27306473U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(674317938U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2894938505U);
}

mxArray *sf_c14_SmAHTR_r1_PITTRTNUKE_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("Jh11LqnWxGXsX5ibnh5J5B");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(9);
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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(9);
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
      pr[0] = (double)(10);
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
      pr[0] = (double)(9);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c14_SmAHTR_r1_PITTRTNUKE_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c14_SmAHTR_r1_PITTRTNUKE_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c14_SmAHTR_r1_PITTRTNUKE(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x8'type','srcId','name','auxInfo'{{M[1],M[5],T\"ydelay\",},{M[1],M[7],T\"ymea1\",},{M[1],M[13],T\"ynetwork_delay\",},{M[4],M[0],T\"delay1\",S'l','i','p'{{M1x2[184 190],M[0],}}},{M[4],M[0],T\"i\",S'l','i','p'{{M1x2[216 217],M[0],}}},{M[4],M[0],T\"last_emergency_instance\",S'l','i','p'{{M1x2[238 261],M[0],}}},{M[4],M[0],T\"network_array\",S'l','i','p'{{M1x2[288 301],M[0],}}},{M[8],M[0],T\"is_active_c14_SmAHTR_r1_PITTRTNUKE\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 8, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c14_SmAHTR_r1_PITTRTNUKE_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _SmAHTR_r1_PITTRTNUKEMachineNumber_,
           14,
           1,
           1,
           0,
           6,
           0,
           0,
           0,
           0,
           1,
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
          _SFD_SET_DATA_PROPS(0,2,0,1,"ymea1");
          _SFD_SET_DATA_PROPS(1,1,1,0,"ymea");
          _SFD_SET_DATA_PROPS(2,2,0,1,"ydelay");
          _SFD_SET_DATA_PROPS(3,11,0,0,"ydelay_global");
          _SFD_SET_DATA_PROPS(4,2,0,1,"ynetwork_delay");
          _SFD_SET_DATA_PROPS(5,11,0,0,"counter_global");
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
        _SFD_CV_INIT_EML(0,1,1,2,0,2,0,1,1,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,2354);
        _SFD_CV_INIT_EML_SATURATION(0,1,0,2221,-1,2261);
        _SFD_CV_INIT_EML_SATURATION(0,1,1,2335,-1,2353);
        _SFD_CV_INIT_EML_IF(0,1,0,722,735,-1,1260);
        _SFD_CV_INIT_EML_IF(0,1,1,1009,1035,1136,1171);
        _SFD_CV_INIT_EML_FOR(0,1,0,2201,2217,2266);
        _SFD_CV_INIT_EML_WHILE(0,1,0,980,1001,1212);
        _SFD_CV_INIT_SCRIPT(0,1,2,0,0,0,1,0,1,1);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"network_delay_summary",0,-1,610);
        _SFD_CV_INIT_SCRIPT_IF(0,0,97,117,571,610);
        _SFD_CV_INIT_SCRIPT_IF(0,1,398,423,489,558);
        _SFD_CV_INIT_SCRIPT_FOR(0,0,302,320,570);

        {
          static int condStart[] = { 101 };

          static int condEnd[] = { 116 };

          static int pfixExpr[] = { 0, -1 };

          _SFD_CV_INIT_SCRIPT_MCDC(0,0,100,116,1,0,&(condStart[0]),&(condEnd[0]),
            2,&(pfixExpr[0]));
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 9;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c14_e_sf_marshallOut,(MexInFcnForType)
            c14_e_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 9;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c14_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 10;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c14_f_sf_marshallOut,(MexInFcnForType)
            c14_f_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 10;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_INT32,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c14_l_sf_marshallOut,(MexInFcnForType)
            c14_k_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 9;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c14_e_sf_marshallOut,(MexInFcnForType)
            c14_e_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(5,SF_INT32,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c14_k_sf_marshallOut,(MexInFcnForType)
          c14_j_sf_marshallIn);

        {
          real_T (*c14_ymea1)[9];
          real_T (*c14_ymea)[9];
          real_T (*c14_ydelay)[10];
          real_T (*c14_ynetwork_delay)[9];
          c14_ynetwork_delay = (real_T (*)[9])ssGetOutputPortSignal
            (chartInstance->S, 3);
          c14_ydelay = (real_T (*)[10])ssGetOutputPortSignal(chartInstance->S, 2);
          c14_ymea = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
          c14_ymea1 = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, *c14_ymea1);
          _SFD_SET_DATA_VALUE_PTR(1U, *c14_ymea);
          _SFD_SET_DATA_VALUE_PTR(2U, *c14_ydelay);
          _SFD_SET_DATA_VALUE_PTR(3U, *chartInstance->c14_ydelay_global_address);
          _SFD_SET_DATA_VALUE_PTR(4U, *c14_ynetwork_delay);
          _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c14_counter_global_address);
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
  return "KtbF8o6u2NL4xmTHFmhKgC";
}

static void sf_opaque_initialize_c14_SmAHTR_r1_PITTRTNUKE(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c14_SmAHTR_r1_PITTRTNUKE
    ((SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct*) chartInstanceVar);
  initialize_c14_SmAHTR_r1_PITTRTNUKE((SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c14_SmAHTR_r1_PITTRTNUKE(void *chartInstanceVar)
{
  enable_c14_SmAHTR_r1_PITTRTNUKE((SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c14_SmAHTR_r1_PITTRTNUKE(void *chartInstanceVar)
{
  disable_c14_SmAHTR_r1_PITTRTNUKE((SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c14_SmAHTR_r1_PITTRTNUKE(void *chartInstanceVar)
{
  sf_gateway_c14_SmAHTR_r1_PITTRTNUKE((SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c14_SmAHTR_r1_PITTRTNUKE
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c14_SmAHTR_r1_PITTRTNUKE
    ((SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c14_SmAHTR_r1_PITTRTNUKE();/* state var info */
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

extern void sf_internal_set_sim_state_c14_SmAHTR_r1_PITTRTNUKE(SimStruct* S,
  const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c14_SmAHTR_r1_PITTRTNUKE();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c14_SmAHTR_r1_PITTRTNUKE
    ((SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c14_SmAHTR_r1_PITTRTNUKE(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c14_SmAHTR_r1_PITTRTNUKE(S);
}

static void sf_opaque_set_sim_state_c14_SmAHTR_r1_PITTRTNUKE(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c14_SmAHTR_r1_PITTRTNUKE(S, st);
}

static void sf_opaque_terminate_c14_SmAHTR_r1_PITTRTNUKE(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct*) chartInstanceVar)
      ->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_SmAHTR_r1_PITTRTNUKE_optimization_info();
    }

    finalize_c14_SmAHTR_r1_PITTRTNUKE((SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct*)
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
  initSimStructsc14_SmAHTR_r1_PITTRTNUKE
    ((SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c14_SmAHTR_r1_PITTRTNUKE(SimStruct *S)
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
    initialize_params_c14_SmAHTR_r1_PITTRTNUKE
      ((SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct*)(chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c14_SmAHTR_r1_PITTRTNUKE(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_SmAHTR_r1_PITTRTNUKE_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      14);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,14,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,14,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,14);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,14,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,14,3);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=3; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 1; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,14);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2531110305U));
  ssSetChecksum1(S,(4256040152U));
  ssSetChecksum2(S,(659893827U));
  ssSetChecksum3(S,(3968204720U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,0);
}

static void mdlRTW_c14_SmAHTR_r1_PITTRTNUKE(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c14_SmAHTR_r1_PITTRTNUKE(SimStruct *S)
{
  SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct *)utMalloc(sizeof
    (SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c14_SmAHTR_r1_PITTRTNUKE;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c14_SmAHTR_r1_PITTRTNUKE;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c14_SmAHTR_r1_PITTRTNUKE;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c14_SmAHTR_r1_PITTRTNUKE;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c14_SmAHTR_r1_PITTRTNUKE;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c14_SmAHTR_r1_PITTRTNUKE;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c14_SmAHTR_r1_PITTRTNUKE;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c14_SmAHTR_r1_PITTRTNUKE;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c14_SmAHTR_r1_PITTRTNUKE;
  chartInstance->chartInfo.mdlStart = mdlStart_c14_SmAHTR_r1_PITTRTNUKE;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c14_SmAHTR_r1_PITTRTNUKE;
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

void c14_SmAHTR_r1_PITTRTNUKE_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c14_SmAHTR_r1_PITTRTNUKE(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c14_SmAHTR_r1_PITTRTNUKE(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c14_SmAHTR_r1_PITTRTNUKE(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c14_SmAHTR_r1_PITTRTNUKE_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
