/* Include files */

#include <stddef.h>
#include "blas.h"
#include "SmAHTR_r1_PITTRTNUKE_sfun.h"
#include "c15_SmAHTR_r1_PITTRTNUKE.h"
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
static const char * c15_debug_family_names[15] = { "step_count", "kk", "j",
  "nargin", "nargout", "yout", "ydelay", "structure", "yout_delay", "i", "yin_d",
  "yin", "delay", "yin_all", "num" };

/* Function Declarations */
static void initialize_c15_SmAHTR_r1_PITTRTNUKE
  (SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance);
static void initialize_params_c15_SmAHTR_r1_PITTRTNUKE
  (SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance);
static void enable_c15_SmAHTR_r1_PITTRTNUKE
  (SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance);
static void disable_c15_SmAHTR_r1_PITTRTNUKE
  (SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance);
static void c15_update_debugger_state_c15_SmAHTR_r1_PITTRTNUKE
  (SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c15_SmAHTR_r1_PITTRTNUKE
  (SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance);
static void set_sim_state_c15_SmAHTR_r1_PITTRTNUKE
  (SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance, const mxArray
   *c15_st);
static void finalize_c15_SmAHTR_r1_PITTRTNUKE
  (SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance);
static void sf_gateway_c15_SmAHTR_r1_PITTRTNUKE
  (SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance);
static void initSimStructsc15_SmAHTR_r1_PITTRTNUKE
  (SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c15_machineNumber, uint32_T
  c15_chartNumber, uint32_T c15_instanceNumber);
static const mxArray *c15_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData);
static real_T c15_emlrt_marshallIn(SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c15_b_num, const char_T *c15_identifier);
static real_T c15_b_emlrt_marshallIn(SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId);
static void c15_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData);
static const mxArray *c15_b_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData);
static void c15_c_emlrt_marshallIn(SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c15_b_yin_all, const char_T *c15_identifier,
  real_T c15_y[7200009]);
static void c15_d_emlrt_marshallIn(SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId,
  real_T c15_y[7200009]);
static void c15_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData);
static const mxArray *c15_c_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData);
static void c15_e_emlrt_marshallIn(SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c15_b_delay, const char_T *c15_identifier,
  real_T c15_y[10]);
static void c15_f_emlrt_marshallIn(SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId,
  real_T c15_y[10]);
static void c15_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData);
static const mxArray *c15_d_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData);
static void c15_g_emlrt_marshallIn(SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c15_b_yin, const char_T *c15_identifier, real_T
  c15_y[9]);
static void c15_h_emlrt_marshallIn(SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId,
  real_T c15_y[9]);
static void c15_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData);
static const mxArray *c15_e_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData);
static void c15_i_emlrt_marshallIn(SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c15_b_yin_d, const char_T *c15_identifier,
  real_T c15_y[9]);
static void c15_j_emlrt_marshallIn(SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId,
  real_T c15_y[9]);
static void c15_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData);
static const mxArray *c15_f_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData);
static real_T c15_k_emlrt_marshallIn(SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c15_b_i, const char_T *c15_identifier);
static real_T c15_l_emlrt_marshallIn(SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId);
static void c15_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData);
static const mxArray *c15_g_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData);
static void c15_m_emlrt_marshallIn(SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c15_yout_delay, const char_T *c15_identifier,
  real_T c15_y[9]);
static void c15_n_emlrt_marshallIn(SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId,
  real_T c15_y[9]);
static void c15_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData);
static const mxArray *c15_h_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData);
static void c15_o_emlrt_marshallIn(SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId,
  c15_struct_a2CnFCSncMqluNCp4sL5hD *c15_y);
static real_T c15_p_emlrt_marshallIn(SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId);
static void c15_q_emlrt_marshallIn(SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId,
  real_T c15_y[9]);
static void c15_r_emlrt_marshallIn(SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId,
  real_T c15_y[9]);
static void c15_s_emlrt_marshallIn(SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId,
  real_T c15_y[5]);
static void c15_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData);
static const mxArray *c15_i_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData);
static const mxArray *c15_j_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData);
static void c15_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData);
static const mxArray *c15_k_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData);
static int32_T c15_t_emlrt_marshallIn(SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId);
static void c15_j_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData);
static uint8_T c15_u_emlrt_marshallIn(SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c15_b_is_active_c15_SmAHTR_r1_PITTRTNUKE, const
  char_T *c15_identifier);
static uint8_T c15_v_emlrt_marshallIn(SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId);
static void init_dsm_address_info(SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c15_SmAHTR_r1_PITTRTNUKE
  (SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance)
{
  chartInstance->c15_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c15_i_not_empty = false;
  chartInstance->c15_yin_d_not_empty = false;
  chartInstance->c15_yin_not_empty = false;
  chartInstance->c15_delay_not_empty = false;
  chartInstance->c15_yin_all_not_empty = false;
  chartInstance->c15_num_not_empty = false;
  chartInstance->c15_is_active_c15_SmAHTR_r1_PITTRTNUKE = 0U;
}

static void initialize_params_c15_SmAHTR_r1_PITTRTNUKE
  (SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance)
{
  const mxArray *c15_m0 = NULL;
  const mxArray *c15_mxField;
  c15_struct_a2CnFCSncMqluNCp4sL5hD c15_r0;
  c15_m0 = sf_mex_get_sfun_param(chartInstance->S, 0, 1);
  c15_mxField = sf_mex_getfield(c15_m0, "i", "structure", 0);
  sf_mex_import_named("structure", sf_mex_dup(c15_mxField), &c15_r0.i, 1, 0, 0U,
                      0, 0U, 0);
  c15_mxField = sf_mex_getfield(c15_m0, "count", "structure", 0);
  sf_mex_import_named("structure", sf_mex_dup(c15_mxField), &c15_r0.count, 1, 0,
                      0U, 0, 0U, 0);
  c15_mxField = sf_mex_getfield(c15_m0, "sen_num", "structure", 0);
  sf_mex_import_named("structure", sf_mex_dup(c15_mxField), &c15_r0.sen_num, 1,
                      0, 0U, 0, 0U, 0);
  c15_mxField = sf_mex_getfield(c15_m0, "yin", "structure", 0);
  sf_mex_import_named("structure", sf_mex_dup(c15_mxField), c15_r0.yin, 1, 0, 0U,
                      1, 0U, 2, 1, 9);
  c15_mxField = sf_mex_getfield(c15_m0, "yin_d", "structure", 0);
  sf_mex_import_named("structure", sf_mex_dup(c15_mxField), c15_r0.yin_d, 1, 0,
                      0U, 1, 0U, 2, 9, 1);
  c15_mxField = sf_mex_getfield(c15_m0, "delay_v", "structure", 0);
  sf_mex_import_named("structure", sf_mex_dup(c15_mxField), c15_r0.delay_v, 1, 0,
                      0U, 1, 0U, 2, 9, 1);
  c15_mxField = sf_mex_getfield(c15_m0, "ynd_tmp", "structure", 0);
  sf_mex_import_named("structure", sf_mex_dup(c15_mxField), c15_r0.ynd_tmp, 1, 0,
                      0U, 1, 0U, 2, 1, 9);
  c15_mxField = sf_mex_getfield(c15_m0, "ranD", "structure", 0);
  sf_mex_import_named("structure", sf_mex_dup(c15_mxField), c15_r0.ranD, 1, 0,
                      0U, 1, 0U, 2, 1, 5);
  sf_mex_destroy(&c15_m0);
  chartInstance->c15_structure = c15_r0;
}

static void enable_c15_SmAHTR_r1_PITTRTNUKE
  (SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c15_SmAHTR_r1_PITTRTNUKE
  (SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c15_update_debugger_state_c15_SmAHTR_r1_PITTRTNUKE
  (SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c15_SmAHTR_r1_PITTRTNUKE
  (SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance)
{
  const mxArray *c15_st;
  const mxArray *c15_y = NULL;
  int32_T c15_i0;
  real_T c15_u[9];
  const mxArray *c15_b_y = NULL;
  int32_T c15_i1;
  real_T c15_b_u[10];
  const mxArray *c15_c_y = NULL;
  real_T c15_hoistedGlobal;
  real_T c15_c_u;
  const mxArray *c15_d_y = NULL;
  real_T c15_b_hoistedGlobal;
  real_T c15_d_u;
  const mxArray *c15_e_y = NULL;
  int32_T c15_i2;
  real_T c15_e_u[9];
  const mxArray *c15_f_y = NULL;
  int32_T c15_i3;
  static real_T c15_f_u[7200009];
  const mxArray *c15_g_y = NULL;
  int32_T c15_i4;
  real_T c15_g_u[9];
  const mxArray *c15_h_y = NULL;
  uint8_T c15_c_hoistedGlobal;
  uint8_T c15_h_u;
  const mxArray *c15_i_y = NULL;
  real_T (*c15_yout_delay)[9];
  c15_yout_delay = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c15_st = NULL;
  c15_st = NULL;
  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_createcellmatrix(8, 1), false);
  for (c15_i0 = 0; c15_i0 < 9; c15_i0++) {
    c15_u[c15_i0] = (*c15_yout_delay)[c15_i0];
  }

  c15_b_y = NULL;
  sf_mex_assign(&c15_b_y, sf_mex_create("y", c15_u, 0, 0U, 1U, 0U, 1, 9), false);
  sf_mex_setcell(c15_y, 0, c15_b_y);
  for (c15_i1 = 0; c15_i1 < 10; c15_i1++) {
    c15_b_u[c15_i1] = chartInstance->c15_delay[c15_i1];
  }

  c15_c_y = NULL;
  if (!chartInstance->c15_delay_not_empty) {
    sf_mex_assign(&c15_c_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c15_c_y, sf_mex_create("y", c15_b_u, 0, 0U, 1U, 0U, 2, 1, 10),
                  false);
  }

  sf_mex_setcell(c15_y, 1, c15_c_y);
  c15_hoistedGlobal = chartInstance->c15_i;
  c15_c_u = c15_hoistedGlobal;
  c15_d_y = NULL;
  if (!chartInstance->c15_i_not_empty) {
    sf_mex_assign(&c15_d_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c15_d_y, sf_mex_create("y", &c15_c_u, 0, 0U, 0U, 0U, 0),
                  false);
  }

  sf_mex_setcell(c15_y, 2, c15_d_y);
  c15_b_hoistedGlobal = chartInstance->c15_num;
  c15_d_u = c15_b_hoistedGlobal;
  c15_e_y = NULL;
  if (!chartInstance->c15_num_not_empty) {
    sf_mex_assign(&c15_e_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c15_e_y, sf_mex_create("y", &c15_d_u, 0, 0U, 0U, 0U, 0),
                  false);
  }

  sf_mex_setcell(c15_y, 3, c15_e_y);
  for (c15_i2 = 0; c15_i2 < 9; c15_i2++) {
    c15_e_u[c15_i2] = chartInstance->c15_yin[c15_i2];
  }

  c15_f_y = NULL;
  if (!chartInstance->c15_yin_not_empty) {
    sf_mex_assign(&c15_f_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c15_f_y, sf_mex_create("y", c15_e_u, 0, 0U, 1U, 0U, 2, 1, 9),
                  false);
  }

  sf_mex_setcell(c15_y, 4, c15_f_y);
  for (c15_i3 = 0; c15_i3 < 7200009; c15_i3++) {
    c15_f_u[c15_i3] = chartInstance->c15_yin_all[c15_i3];
  }

  c15_g_y = NULL;
  if (!chartInstance->c15_yin_all_not_empty) {
    sf_mex_assign(&c15_g_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c15_g_y, sf_mex_create("y", c15_f_u, 0, 0U, 1U, 0U, 2, 800001,
      9), false);
  }

  sf_mex_setcell(c15_y, 5, c15_g_y);
  for (c15_i4 = 0; c15_i4 < 9; c15_i4++) {
    c15_g_u[c15_i4] = chartInstance->c15_yin_d[c15_i4];
  }

  c15_h_y = NULL;
  if (!chartInstance->c15_yin_d_not_empty) {
    sf_mex_assign(&c15_h_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c15_h_y, sf_mex_create("y", c15_g_u, 0, 0U, 1U, 0U, 1, 9),
                  false);
  }

  sf_mex_setcell(c15_y, 6, c15_h_y);
  c15_c_hoistedGlobal = chartInstance->c15_is_active_c15_SmAHTR_r1_PITTRTNUKE;
  c15_h_u = c15_c_hoistedGlobal;
  c15_i_y = NULL;
  sf_mex_assign(&c15_i_y, sf_mex_create("y", &c15_h_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c15_y, 7, c15_i_y);
  sf_mex_assign(&c15_st, c15_y, false);
  return c15_st;
}

static void set_sim_state_c15_SmAHTR_r1_PITTRTNUKE
  (SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance, const mxArray
   *c15_st)
{
  const mxArray *c15_u;
  real_T c15_dv0[9];
  int32_T c15_i5;
  real_T c15_dv1[10];
  int32_T c15_i6;
  real_T c15_dv2[9];
  int32_T c15_i7;
  static real_T c15_dv3[7200009];
  int32_T c15_i8;
  real_T c15_dv4[9];
  int32_T c15_i9;
  real_T (*c15_yout_delay)[9];
  c15_yout_delay = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c15_doneDoubleBufferReInit = true;
  c15_u = sf_mex_dup(c15_st);
  c15_m_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c15_u, 0)),
    "yout_delay", c15_dv0);
  for (c15_i5 = 0; c15_i5 < 9; c15_i5++) {
    (*c15_yout_delay)[c15_i5] = c15_dv0[c15_i5];
  }

  c15_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c15_u, 1)),
    "delay", c15_dv1);
  for (c15_i6 = 0; c15_i6 < 10; c15_i6++) {
    chartInstance->c15_delay[c15_i6] = c15_dv1[c15_i6];
  }

  chartInstance->c15_i = c15_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c15_u, 2)), "i");
  chartInstance->c15_num = c15_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c15_u, 3)), "num");
  c15_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c15_u, 4)),
    "yin", c15_dv2);
  for (c15_i7 = 0; c15_i7 < 9; c15_i7++) {
    chartInstance->c15_yin[c15_i7] = c15_dv2[c15_i7];
  }

  c15_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c15_u, 5)),
    "yin_all", c15_dv3);
  for (c15_i8 = 0; c15_i8 < 7200009; c15_i8++) {
    chartInstance->c15_yin_all[c15_i8] = c15_dv3[c15_i8];
  }

  c15_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c15_u, 6)),
    "yin_d", c15_dv4);
  for (c15_i9 = 0; c15_i9 < 9; c15_i9++) {
    chartInstance->c15_yin_d[c15_i9] = c15_dv4[c15_i9];
  }

  chartInstance->c15_is_active_c15_SmAHTR_r1_PITTRTNUKE = c15_u_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c15_u, 7)),
     "is_active_c15_SmAHTR_r1_PITTRTNUKE");
  sf_mex_destroy(&c15_u);
  c15_update_debugger_state_c15_SmAHTR_r1_PITTRTNUKE(chartInstance);
  sf_mex_destroy(&c15_st);
}

static void finalize_c15_SmAHTR_r1_PITTRTNUKE
  (SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c15_SmAHTR_r1_PITTRTNUKE
  (SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance)
{
  int32_T c15_i10;
  int32_T c15_i11;
  int32_T c15_i12;
  real_T c15_yout[9];
  int32_T c15_i13;
  real_T c15_ydelay[10];
  c15_struct_a2CnFCSncMqluNCp4sL5hD c15_b_structure;
  uint32_T c15_debug_family_var_map[15];
  real_T c15_step_count;
  real_T c15_kk;
  real_T c15_j;
  real_T c15_nargin = 3.0;
  real_T c15_nargout = 1.0;
  real_T c15_yout_delay[9];
  int32_T c15_i14;
  int32_T c15_i15;
  int32_T c15_i16;
  int32_T c15_i17;
  int32_T c15_i18;
  int32_T c15_i19;
  int32_T c15_b_kk;
  int32_T c15_b_j;
  int32_T c15_i20;
  int32_T c15_i21;
  int32_T c15_i22;
  int32_T c15_i23;
  real_T (*c15_b_yout_delay)[9];
  real_T (*c15_b_ydelay)[10];
  real_T (*c15_b_yout)[9];
  c15_b_yout_delay = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c15_b_ydelay = (real_T (*)[10])ssGetInputPortSignal(chartInstance->S, 1);
  c15_b_yout = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 12U, chartInstance->c15_sfEvent);
  for (c15_i10 = 0; c15_i10 < 9; c15_i10++) {
    _SFD_DATA_RANGE_CHECK((*c15_b_yout)[c15_i10], 0U);
  }

  for (c15_i11 = 0; c15_i11 < 10; c15_i11++) {
    _SFD_DATA_RANGE_CHECK((*c15_b_ydelay)[c15_i11], 1U);
  }

  chartInstance->c15_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 12U, chartInstance->c15_sfEvent);
  for (c15_i12 = 0; c15_i12 < 9; c15_i12++) {
    c15_yout[c15_i12] = (*c15_b_yout)[c15_i12];
  }

  for (c15_i13 = 0; c15_i13 < 10; c15_i13++) {
    c15_ydelay[c15_i13] = (*c15_b_ydelay)[c15_i13];
  }

  c15_b_structure = chartInstance->c15_structure;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 15U, 15U, c15_debug_family_names,
    c15_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c15_step_count, 0U, c15_j_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_kk, 1U, c15_j_sf_marshallOut,
    c15_i_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_j, 2U, c15_j_sf_marshallOut,
    c15_i_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_nargin, 3U, c15_j_sf_marshallOut,
    c15_i_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_nargout, 4U, c15_j_sf_marshallOut,
    c15_i_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c15_yout, 5U, c15_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c15_ydelay, 6U, c15_i_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_b_structure, 7U,
    c15_h_sf_marshallOut, c15_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c15_yout_delay, 8U, c15_g_sf_marshallOut,
    c15_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c15_i, 9U,
    c15_f_sf_marshallOut, c15_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c15_yin_d, 10U,
    c15_e_sf_marshallOut, c15_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c15_yin, 11U,
    c15_d_sf_marshallOut, c15_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c15_delay, 12U,
    c15_c_sf_marshallOut, c15_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c15_yin_all, 13U,
    c15_b_sf_marshallOut, c15_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c15_num, 14U,
    c15_sf_marshallOut, c15_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 13);
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 14);
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 15);
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 18);
  c15_step_count = 800000.0;
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 21);
  if (CV_EML_IF(0, 1, 0, !chartInstance->c15_yin_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 22);
    chartInstance->c15_i = c15_b_structure.i;
    chartInstance->c15_i_not_empty = true;
    _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 23);
    for (c15_i14 = 0; c15_i14 < 9; c15_i14++) {
      chartInstance->c15_yin[c15_i14] = c15_b_structure.yin[c15_i14];
    }

    chartInstance->c15_yin_not_empty = true;
    _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 24);
    for (c15_i15 = 0; c15_i15 < 9; c15_i15++) {
      chartInstance->c15_yin_d[c15_i15] = c15_b_structure.yin_d[c15_i15];
    }

    chartInstance->c15_yin_d_not_empty = true;
    _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 25);
    for (c15_i16 = 0; c15_i16 < 7200009; c15_i16++) {
      chartInstance->c15_yin_all[c15_i16] = 0.0;
    }

    chartInstance->c15_yin_all_not_empty = true;
    _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 27);
    for (c15_i17 = 0; c15_i17 < 10; c15_i17++) {
      chartInstance->c15_delay[c15_i17] = 0.0;
    }

    chartInstance->c15_delay_not_empty = true;
    _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 28);
    for (c15_i18 = 0; c15_i18 < 10; c15_i18++) {
      chartInstance->c15_delay[c15_i18] = c15_ydelay[c15_i18];
    }

    _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 30);
    chartInstance->c15_num = 0.0;
    chartInstance->c15_num_not_empty = true;
  }

  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 34);
  chartInstance->c15_num++;
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 38);
  for (c15_i19 = 0; c15_i19 < 10; c15_i19++) {
    chartInstance->c15_delay[c15_i19] = c15_ydelay[c15_i19];
  }

  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 41);
  c15_kk = 1.0;
  c15_b_kk = 0;
  while (c15_b_kk < 3) {
    c15_kk = 1.0 + (real_T)c15_b_kk;
    CV_EML_FOR(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 42);
    chartInstance->c15_yin_all[(_SFD_EML_ARRAY_BOUNDS_CHECK("yin_all", (int32_T)
      _SFD_INTEGER_CHECK("num", chartInstance->c15_num), 1, 800001, 1, 0) +
      800001 * (_SFD_EML_ARRAY_BOUNDS_CHECK("yin_all", (int32_T)
      _SFD_INTEGER_CHECK("kk", c15_kk), 1, 9, 2, 0) - 1)) - 1] =
      c15_yout[_SFD_EML_ARRAY_BOUNDS_CHECK("yout", (int32_T)_SFD_INTEGER_CHECK(
      "kk", c15_kk), 1, 9, 1, 0) - 1];
    c15_b_kk++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 0, 0);
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 46);
  c15_j = 1.0;
  c15_b_j = 0;
  while (c15_b_j < 3) {
    c15_j = 1.0 + (real_T)c15_b_j;
    CV_EML_FOR(0, 1, 1, 1);
    _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 47);
    if (CV_EML_IF(0, 1, 1, chartInstance->c15_delay[_SFD_EML_ARRAY_BOUNDS_CHECK(
          "delay", (int32_T)_SFD_INTEGER_CHECK("j+1", c15_j + 1.0), 1, 10, 2, 0)
                  - 1] != 88.0)) {
      _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 48);
      chartInstance->c15_yin[_SFD_EML_ARRAY_BOUNDS_CHECK("yin", (int32_T)
        _SFD_INTEGER_CHECK("j", c15_j), 1, 9, 1, 0) - 1] =
        chartInstance->c15_yin_all[(_SFD_EML_ARRAY_BOUNDS_CHECK("yin_all",
        (int32_T)_SFD_INTEGER_CHECK("num", chartInstance->c15_num), 1, 800001, 1,
        0) + 800001 * (_SFD_EML_ARRAY_BOUNDS_CHECK("yin_all", (int32_T)
        _SFD_INTEGER_CHECK("j", c15_j), 1, 9, 2, 0) - 1)) - 1];
    } else {
      _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 50);
      if (CV_EML_IF(0, 1, 2, chartInstance->c15_num > 1.0)) {
        _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 52);
        chartInstance->c15_yin[_SFD_EML_ARRAY_BOUNDS_CHECK("yin", (int32_T)
          _SFD_INTEGER_CHECK("j", c15_j), 1, 9, 1, 0) - 1] =
          chartInstance->c15_yin_all[(_SFD_EML_ARRAY_BOUNDS_CHECK("yin_all",
          (int32_T)_SFD_INTEGER_CHECK("num-1", chartInstance->c15_num - 1.0), 1,
          800001, 1, 0) + 800001 * (_SFD_EML_ARRAY_BOUNDS_CHECK("yin_all",
          (int32_T)_SFD_INTEGER_CHECK("j", c15_j), 1, 9, 2, 0) - 1)) - 1];
        _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 53);
        chartInstance->c15_yin_all[(_SFD_EML_ARRAY_BOUNDS_CHECK("yin_all",
          (int32_T)_SFD_INTEGER_CHECK("num", chartInstance->c15_num), 1, 800001,
          1, 0) + 800001 * (_SFD_EML_ARRAY_BOUNDS_CHECK("yin_all", (int32_T)
          _SFD_INTEGER_CHECK("j", c15_j), 1, 9, 2, 0) - 1)) - 1] =
          chartInstance->c15_yin_all[(_SFD_EML_ARRAY_BOUNDS_CHECK("yin_all",
          (int32_T)_SFD_INTEGER_CHECK("num-1", chartInstance->c15_num - 1.0), 1,
          800001, 1, 0) + 800001 * (_SFD_EML_ARRAY_BOUNDS_CHECK("yin_all",
          (int32_T)_SFD_INTEGER_CHECK("j", c15_j), 1, 9, 2, 0) - 1)) - 1];
      }
    }

    c15_b_j++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 1, 0);
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 59);
  for (c15_i20 = 0; c15_i20 < 9; c15_i20++) {
    chartInstance->c15_yin_d[c15_i20] = chartInstance->c15_yin[c15_i20];
  }

  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 61);
  for (c15_i21 = 0; c15_i21 < 9; c15_i21++) {
    c15_yout_delay[c15_i21] = chartInstance->c15_yin_d[c15_i21];
  }

  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 67);
  chartInstance->c15_i++;
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, -67);
  _SFD_SYMBOL_SCOPE_POP();
  for (c15_i22 = 0; c15_i22 < 9; c15_i22++) {
    (*c15_b_yout_delay)[c15_i22] = c15_yout_delay[c15_i22];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 12U, chartInstance->c15_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_SmAHTR_r1_PITTRTNUKEMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c15_i23 = 0; c15_i23 < 9; c15_i23++) {
    _SFD_DATA_RANGE_CHECK((*c15_b_yout_delay)[c15_i23], 2U);
  }
}

static void initSimStructsc15_SmAHTR_r1_PITTRTNUKE
  (SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c15_machineNumber, uint32_T
  c15_chartNumber, uint32_T c15_instanceNumber)
{
  (void)c15_machineNumber;
  (void)c15_chartNumber;
  (void)c15_instanceNumber;
}

static const mxArray *c15_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData)
{
  const mxArray *c15_mxArrayOutData = NULL;
  real_T c15_u;
  const mxArray *c15_y = NULL;
  SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance;
  chartInstance = (SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct *)chartInstanceVoid;
  c15_mxArrayOutData = NULL;
  c15_u = *(real_T *)c15_inData;
  c15_y = NULL;
  if (!chartInstance->c15_num_not_empty) {
    sf_mex_assign(&c15_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c15_y, sf_mex_create("y", &c15_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_assign(&c15_mxArrayOutData, c15_y, false);
  return c15_mxArrayOutData;
}

static real_T c15_emlrt_marshallIn(SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c15_b_num, const char_T *c15_identifier)
{
  real_T c15_y;
  emlrtMsgIdentifier c15_thisId;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_y = c15_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_b_num),
    &c15_thisId);
  sf_mex_destroy(&c15_b_num);
  return c15_y;
}

static real_T c15_b_emlrt_marshallIn(SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId)
{
  real_T c15_y;
  real_T c15_d0;
  if (mxIsEmpty(c15_u)) {
    chartInstance->c15_num_not_empty = false;
  } else {
    chartInstance->c15_num_not_empty = true;
    sf_mex_import(c15_parentId, sf_mex_dup(c15_u), &c15_d0, 1, 0, 0U, 0, 0U, 0);
    c15_y = c15_d0;
  }

  sf_mex_destroy(&c15_u);
  return c15_y;
}

static void c15_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData)
{
  const mxArray *c15_b_num;
  const char_T *c15_identifier;
  emlrtMsgIdentifier c15_thisId;
  real_T c15_y;
  SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance;
  chartInstance = (SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct *)chartInstanceVoid;
  c15_b_num = sf_mex_dup(c15_mxArrayInData);
  c15_identifier = c15_varName;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_y = c15_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_b_num),
    &c15_thisId);
  sf_mex_destroy(&c15_b_num);
  *(real_T *)c15_outData = c15_y;
  sf_mex_destroy(&c15_mxArrayInData);
}

static const mxArray *c15_b_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData)
{
  const mxArray *c15_mxArrayOutData = NULL;
  int32_T c15_i24;
  int32_T c15_i25;
  int32_T c15_i26;
  static real_T c15_b_inData[7200009];
  int32_T c15_i27;
  int32_T c15_i28;
  int32_T c15_i29;
  static real_T c15_u[7200009];
  const mxArray *c15_y = NULL;
  SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance;
  chartInstance = (SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct *)chartInstanceVoid;
  c15_mxArrayOutData = NULL;
  c15_i24 = 0;
  for (c15_i25 = 0; c15_i25 < 9; c15_i25++) {
    for (c15_i26 = 0; c15_i26 < 800001; c15_i26++) {
      c15_b_inData[c15_i26 + c15_i24] = (*(real_T (*)[7200009])c15_inData)
        [c15_i26 + c15_i24];
    }

    c15_i24 += 800001;
  }

  c15_i27 = 0;
  for (c15_i28 = 0; c15_i28 < 9; c15_i28++) {
    for (c15_i29 = 0; c15_i29 < 800001; c15_i29++) {
      c15_u[c15_i29 + c15_i27] = c15_b_inData[c15_i29 + c15_i27];
    }

    c15_i27 += 800001;
  }

  c15_y = NULL;
  if (!chartInstance->c15_yin_all_not_empty) {
    sf_mex_assign(&c15_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c15_y, sf_mex_create("y", c15_u, 0, 0U, 1U, 0U, 2, 800001, 9),
                  false);
  }

  sf_mex_assign(&c15_mxArrayOutData, c15_y, false);
  return c15_mxArrayOutData;
}

static void c15_c_emlrt_marshallIn(SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c15_b_yin_all, const char_T *c15_identifier,
  real_T c15_y[7200009])
{
  emlrtMsgIdentifier c15_thisId;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_b_yin_all), &c15_thisId,
    c15_y);
  sf_mex_destroy(&c15_b_yin_all);
}

static void c15_d_emlrt_marshallIn(SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId,
  real_T c15_y[7200009])
{
  static real_T c15_dv5[7200009];
  int32_T c15_i30;
  if (mxIsEmpty(c15_u)) {
    chartInstance->c15_yin_all_not_empty = false;
  } else {
    chartInstance->c15_yin_all_not_empty = true;
    sf_mex_import(c15_parentId, sf_mex_dup(c15_u), c15_dv5, 1, 0, 0U, 1, 0U, 2,
                  800001, 9);
    for (c15_i30 = 0; c15_i30 < 7200009; c15_i30++) {
      c15_y[c15_i30] = c15_dv5[c15_i30];
    }
  }

  sf_mex_destroy(&c15_u);
}

static void c15_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData)
{
  const mxArray *c15_b_yin_all;
  const char_T *c15_identifier;
  emlrtMsgIdentifier c15_thisId;
  static real_T c15_y[7200009];
  int32_T c15_i31;
  int32_T c15_i32;
  int32_T c15_i33;
  SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance;
  chartInstance = (SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct *)chartInstanceVoid;
  c15_b_yin_all = sf_mex_dup(c15_mxArrayInData);
  c15_identifier = c15_varName;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_b_yin_all), &c15_thisId,
    c15_y);
  sf_mex_destroy(&c15_b_yin_all);
  c15_i31 = 0;
  for (c15_i32 = 0; c15_i32 < 9; c15_i32++) {
    for (c15_i33 = 0; c15_i33 < 800001; c15_i33++) {
      (*(real_T (*)[7200009])c15_outData)[c15_i33 + c15_i31] = c15_y[c15_i33 +
        c15_i31];
    }

    c15_i31 += 800001;
  }

  sf_mex_destroy(&c15_mxArrayInData);
}

static const mxArray *c15_c_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData)
{
  const mxArray *c15_mxArrayOutData = NULL;
  int32_T c15_i34;
  real_T c15_b_inData[10];
  int32_T c15_i35;
  real_T c15_u[10];
  const mxArray *c15_y = NULL;
  SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance;
  chartInstance = (SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct *)chartInstanceVoid;
  c15_mxArrayOutData = NULL;
  for (c15_i34 = 0; c15_i34 < 10; c15_i34++) {
    c15_b_inData[c15_i34] = (*(real_T (*)[10])c15_inData)[c15_i34];
  }

  for (c15_i35 = 0; c15_i35 < 10; c15_i35++) {
    c15_u[c15_i35] = c15_b_inData[c15_i35];
  }

  c15_y = NULL;
  if (!chartInstance->c15_delay_not_empty) {
    sf_mex_assign(&c15_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c15_y, sf_mex_create("y", c15_u, 0, 0U, 1U, 0U, 2, 1, 10),
                  false);
  }

  sf_mex_assign(&c15_mxArrayOutData, c15_y, false);
  return c15_mxArrayOutData;
}

static void c15_e_emlrt_marshallIn(SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c15_b_delay, const char_T *c15_identifier,
  real_T c15_y[10])
{
  emlrtMsgIdentifier c15_thisId;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_b_delay), &c15_thisId,
    c15_y);
  sf_mex_destroy(&c15_b_delay);
}

static void c15_f_emlrt_marshallIn(SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId,
  real_T c15_y[10])
{
  real_T c15_dv6[10];
  int32_T c15_i36;
  if (mxIsEmpty(c15_u)) {
    chartInstance->c15_delay_not_empty = false;
  } else {
    chartInstance->c15_delay_not_empty = true;
    sf_mex_import(c15_parentId, sf_mex_dup(c15_u), c15_dv6, 1, 0, 0U, 1, 0U, 2,
                  1, 10);
    for (c15_i36 = 0; c15_i36 < 10; c15_i36++) {
      c15_y[c15_i36] = c15_dv6[c15_i36];
    }
  }

  sf_mex_destroy(&c15_u);
}

static void c15_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData)
{
  const mxArray *c15_b_delay;
  const char_T *c15_identifier;
  emlrtMsgIdentifier c15_thisId;
  real_T c15_y[10];
  int32_T c15_i37;
  SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance;
  chartInstance = (SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct *)chartInstanceVoid;
  c15_b_delay = sf_mex_dup(c15_mxArrayInData);
  c15_identifier = c15_varName;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_b_delay), &c15_thisId,
    c15_y);
  sf_mex_destroy(&c15_b_delay);
  for (c15_i37 = 0; c15_i37 < 10; c15_i37++) {
    (*(real_T (*)[10])c15_outData)[c15_i37] = c15_y[c15_i37];
  }

  sf_mex_destroy(&c15_mxArrayInData);
}

static const mxArray *c15_d_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData)
{
  const mxArray *c15_mxArrayOutData = NULL;
  int32_T c15_i38;
  real_T c15_b_inData[9];
  int32_T c15_i39;
  real_T c15_u[9];
  const mxArray *c15_y = NULL;
  SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance;
  chartInstance = (SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct *)chartInstanceVoid;
  c15_mxArrayOutData = NULL;
  for (c15_i38 = 0; c15_i38 < 9; c15_i38++) {
    c15_b_inData[c15_i38] = (*(real_T (*)[9])c15_inData)[c15_i38];
  }

  for (c15_i39 = 0; c15_i39 < 9; c15_i39++) {
    c15_u[c15_i39] = c15_b_inData[c15_i39];
  }

  c15_y = NULL;
  if (!chartInstance->c15_yin_not_empty) {
    sf_mex_assign(&c15_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c15_y, sf_mex_create("y", c15_u, 0, 0U, 1U, 0U, 2, 1, 9),
                  false);
  }

  sf_mex_assign(&c15_mxArrayOutData, c15_y, false);
  return c15_mxArrayOutData;
}

static void c15_g_emlrt_marshallIn(SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c15_b_yin, const char_T *c15_identifier, real_T
  c15_y[9])
{
  emlrtMsgIdentifier c15_thisId;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_b_yin), &c15_thisId,
    c15_y);
  sf_mex_destroy(&c15_b_yin);
}

static void c15_h_emlrt_marshallIn(SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId,
  real_T c15_y[9])
{
  real_T c15_dv7[9];
  int32_T c15_i40;
  if (mxIsEmpty(c15_u)) {
    chartInstance->c15_yin_not_empty = false;
  } else {
    chartInstance->c15_yin_not_empty = true;
    sf_mex_import(c15_parentId, sf_mex_dup(c15_u), c15_dv7, 1, 0, 0U, 1, 0U, 2,
                  1, 9);
    for (c15_i40 = 0; c15_i40 < 9; c15_i40++) {
      c15_y[c15_i40] = c15_dv7[c15_i40];
    }
  }

  sf_mex_destroy(&c15_u);
}

static void c15_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData)
{
  const mxArray *c15_b_yin;
  const char_T *c15_identifier;
  emlrtMsgIdentifier c15_thisId;
  real_T c15_y[9];
  int32_T c15_i41;
  SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance;
  chartInstance = (SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct *)chartInstanceVoid;
  c15_b_yin = sf_mex_dup(c15_mxArrayInData);
  c15_identifier = c15_varName;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_b_yin), &c15_thisId,
    c15_y);
  sf_mex_destroy(&c15_b_yin);
  for (c15_i41 = 0; c15_i41 < 9; c15_i41++) {
    (*(real_T (*)[9])c15_outData)[c15_i41] = c15_y[c15_i41];
  }

  sf_mex_destroy(&c15_mxArrayInData);
}

static const mxArray *c15_e_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData)
{
  const mxArray *c15_mxArrayOutData = NULL;
  int32_T c15_i42;
  real_T c15_b_inData[9];
  int32_T c15_i43;
  real_T c15_u[9];
  const mxArray *c15_y = NULL;
  SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance;
  chartInstance = (SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct *)chartInstanceVoid;
  c15_mxArrayOutData = NULL;
  for (c15_i42 = 0; c15_i42 < 9; c15_i42++) {
    c15_b_inData[c15_i42] = (*(real_T (*)[9])c15_inData)[c15_i42];
  }

  for (c15_i43 = 0; c15_i43 < 9; c15_i43++) {
    c15_u[c15_i43] = c15_b_inData[c15_i43];
  }

  c15_y = NULL;
  if (!chartInstance->c15_yin_d_not_empty) {
    sf_mex_assign(&c15_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c15_y, sf_mex_create("y", c15_u, 0, 0U, 1U, 0U, 1, 9), false);
  }

  sf_mex_assign(&c15_mxArrayOutData, c15_y, false);
  return c15_mxArrayOutData;
}

static void c15_i_emlrt_marshallIn(SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c15_b_yin_d, const char_T *c15_identifier,
  real_T c15_y[9])
{
  emlrtMsgIdentifier c15_thisId;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_b_yin_d), &c15_thisId,
    c15_y);
  sf_mex_destroy(&c15_b_yin_d);
}

static void c15_j_emlrt_marshallIn(SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId,
  real_T c15_y[9])
{
  real_T c15_dv8[9];
  int32_T c15_i44;
  if (mxIsEmpty(c15_u)) {
    chartInstance->c15_yin_d_not_empty = false;
  } else {
    chartInstance->c15_yin_d_not_empty = true;
    sf_mex_import(c15_parentId, sf_mex_dup(c15_u), c15_dv8, 1, 0, 0U, 1, 0U, 1,
                  9);
    for (c15_i44 = 0; c15_i44 < 9; c15_i44++) {
      c15_y[c15_i44] = c15_dv8[c15_i44];
    }
  }

  sf_mex_destroy(&c15_u);
}

static void c15_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData)
{
  const mxArray *c15_b_yin_d;
  const char_T *c15_identifier;
  emlrtMsgIdentifier c15_thisId;
  real_T c15_y[9];
  int32_T c15_i45;
  SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance;
  chartInstance = (SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct *)chartInstanceVoid;
  c15_b_yin_d = sf_mex_dup(c15_mxArrayInData);
  c15_identifier = c15_varName;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_b_yin_d), &c15_thisId,
    c15_y);
  sf_mex_destroy(&c15_b_yin_d);
  for (c15_i45 = 0; c15_i45 < 9; c15_i45++) {
    (*(real_T (*)[9])c15_outData)[c15_i45] = c15_y[c15_i45];
  }

  sf_mex_destroy(&c15_mxArrayInData);
}

static const mxArray *c15_f_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData)
{
  const mxArray *c15_mxArrayOutData = NULL;
  real_T c15_u;
  const mxArray *c15_y = NULL;
  SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance;
  chartInstance = (SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct *)chartInstanceVoid;
  c15_mxArrayOutData = NULL;
  c15_u = *(real_T *)c15_inData;
  c15_y = NULL;
  if (!chartInstance->c15_i_not_empty) {
    sf_mex_assign(&c15_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c15_y, sf_mex_create("y", &c15_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_assign(&c15_mxArrayOutData, c15_y, false);
  return c15_mxArrayOutData;
}

static real_T c15_k_emlrt_marshallIn(SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c15_b_i, const char_T *c15_identifier)
{
  real_T c15_y;
  emlrtMsgIdentifier c15_thisId;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_y = c15_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_b_i), &c15_thisId);
  sf_mex_destroy(&c15_b_i);
  return c15_y;
}

static real_T c15_l_emlrt_marshallIn(SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId)
{
  real_T c15_y;
  real_T c15_d1;
  if (mxIsEmpty(c15_u)) {
    chartInstance->c15_i_not_empty = false;
  } else {
    chartInstance->c15_i_not_empty = true;
    sf_mex_import(c15_parentId, sf_mex_dup(c15_u), &c15_d1, 1, 0, 0U, 0, 0U, 0);
    c15_y = c15_d1;
  }

  sf_mex_destroy(&c15_u);
  return c15_y;
}

static void c15_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData)
{
  const mxArray *c15_b_i;
  const char_T *c15_identifier;
  emlrtMsgIdentifier c15_thisId;
  real_T c15_y;
  SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance;
  chartInstance = (SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct *)chartInstanceVoid;
  c15_b_i = sf_mex_dup(c15_mxArrayInData);
  c15_identifier = c15_varName;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_y = c15_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_b_i), &c15_thisId);
  sf_mex_destroy(&c15_b_i);
  *(real_T *)c15_outData = c15_y;
  sf_mex_destroy(&c15_mxArrayInData);
}

static const mxArray *c15_g_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData)
{
  const mxArray *c15_mxArrayOutData = NULL;
  int32_T c15_i46;
  real_T c15_b_inData[9];
  int32_T c15_i47;
  real_T c15_u[9];
  const mxArray *c15_y = NULL;
  SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance;
  chartInstance = (SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct *)chartInstanceVoid;
  c15_mxArrayOutData = NULL;
  for (c15_i46 = 0; c15_i46 < 9; c15_i46++) {
    c15_b_inData[c15_i46] = (*(real_T (*)[9])c15_inData)[c15_i46];
  }

  for (c15_i47 = 0; c15_i47 < 9; c15_i47++) {
    c15_u[c15_i47] = c15_b_inData[c15_i47];
  }

  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", c15_u, 0, 0U, 1U, 0U, 1, 9), false);
  sf_mex_assign(&c15_mxArrayOutData, c15_y, false);
  return c15_mxArrayOutData;
}

static void c15_m_emlrt_marshallIn(SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c15_yout_delay, const char_T *c15_identifier,
  real_T c15_y[9])
{
  emlrtMsgIdentifier c15_thisId;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_yout_delay), &c15_thisId,
    c15_y);
  sf_mex_destroy(&c15_yout_delay);
}

static void c15_n_emlrt_marshallIn(SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId,
  real_T c15_y[9])
{
  real_T c15_dv9[9];
  int32_T c15_i48;
  (void)chartInstance;
  sf_mex_import(c15_parentId, sf_mex_dup(c15_u), c15_dv9, 1, 0, 0U, 1, 0U, 1, 9);
  for (c15_i48 = 0; c15_i48 < 9; c15_i48++) {
    c15_y[c15_i48] = c15_dv9[c15_i48];
  }

  sf_mex_destroy(&c15_u);
}

static void c15_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData)
{
  const mxArray *c15_yout_delay;
  const char_T *c15_identifier;
  emlrtMsgIdentifier c15_thisId;
  real_T c15_y[9];
  int32_T c15_i49;
  SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance;
  chartInstance = (SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct *)chartInstanceVoid;
  c15_yout_delay = sf_mex_dup(c15_mxArrayInData);
  c15_identifier = c15_varName;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_yout_delay), &c15_thisId,
    c15_y);
  sf_mex_destroy(&c15_yout_delay);
  for (c15_i49 = 0; c15_i49 < 9; c15_i49++) {
    (*(real_T (*)[9])c15_outData)[c15_i49] = c15_y[c15_i49];
  }

  sf_mex_destroy(&c15_mxArrayInData);
}

static const mxArray *c15_h_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData)
{
  const mxArray *c15_mxArrayOutData = NULL;
  c15_struct_a2CnFCSncMqluNCp4sL5hD c15_u;
  const mxArray *c15_y = NULL;
  real_T c15_b_u;
  const mxArray *c15_b_y = NULL;
  real_T c15_c_u;
  const mxArray *c15_c_y = NULL;
  real_T c15_d_u;
  const mxArray *c15_d_y = NULL;
  int32_T c15_i50;
  real_T c15_e_u[9];
  const mxArray *c15_e_y = NULL;
  int32_T c15_i51;
  real_T c15_f_u[9];
  const mxArray *c15_f_y = NULL;
  int32_T c15_i52;
  real_T c15_g_u[9];
  const mxArray *c15_g_y = NULL;
  int32_T c15_i53;
  real_T c15_h_u[9];
  const mxArray *c15_h_y = NULL;
  int32_T c15_i54;
  real_T c15_i_u[5];
  const mxArray *c15_i_y = NULL;
  SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance;
  chartInstance = (SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct *)chartInstanceVoid;
  c15_mxArrayOutData = NULL;
  c15_u = *(c15_struct_a2CnFCSncMqluNCp4sL5hD *)c15_inData;
  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c15_b_u = c15_u.i;
  c15_b_y = NULL;
  sf_mex_assign(&c15_b_y, sf_mex_create("y", &c15_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c15_y, c15_b_y, "i", "i", 0);
  c15_c_u = c15_u.count;
  c15_c_y = NULL;
  sf_mex_assign(&c15_c_y, sf_mex_create("y", &c15_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c15_y, c15_c_y, "count", "count", 0);
  c15_d_u = c15_u.sen_num;
  c15_d_y = NULL;
  sf_mex_assign(&c15_d_y, sf_mex_create("y", &c15_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c15_y, c15_d_y, "sen_num", "sen_num", 0);
  for (c15_i50 = 0; c15_i50 < 9; c15_i50++) {
    c15_e_u[c15_i50] = c15_u.yin[c15_i50];
  }

  c15_e_y = NULL;
  sf_mex_assign(&c15_e_y, sf_mex_create("y", c15_e_u, 0, 0U, 1U, 0U, 2, 1, 9),
                false);
  sf_mex_addfield(c15_y, c15_e_y, "yin", "yin", 0);
  for (c15_i51 = 0; c15_i51 < 9; c15_i51++) {
    c15_f_u[c15_i51] = c15_u.yin_d[c15_i51];
  }

  c15_f_y = NULL;
  sf_mex_assign(&c15_f_y, sf_mex_create("y", c15_f_u, 0, 0U, 1U, 0U, 2, 9, 1),
                false);
  sf_mex_addfield(c15_y, c15_f_y, "yin_d", "yin_d", 0);
  for (c15_i52 = 0; c15_i52 < 9; c15_i52++) {
    c15_g_u[c15_i52] = c15_u.delay_v[c15_i52];
  }

  c15_g_y = NULL;
  sf_mex_assign(&c15_g_y, sf_mex_create("y", c15_g_u, 0, 0U, 1U, 0U, 2, 9, 1),
                false);
  sf_mex_addfield(c15_y, c15_g_y, "delay_v", "delay_v", 0);
  for (c15_i53 = 0; c15_i53 < 9; c15_i53++) {
    c15_h_u[c15_i53] = c15_u.ynd_tmp[c15_i53];
  }

  c15_h_y = NULL;
  sf_mex_assign(&c15_h_y, sf_mex_create("y", c15_h_u, 0, 0U, 1U, 0U, 2, 1, 9),
                false);
  sf_mex_addfield(c15_y, c15_h_y, "ynd_tmp", "ynd_tmp", 0);
  for (c15_i54 = 0; c15_i54 < 5; c15_i54++) {
    c15_i_u[c15_i54] = c15_u.ranD[c15_i54];
  }

  c15_i_y = NULL;
  sf_mex_assign(&c15_i_y, sf_mex_create("y", c15_i_u, 0, 0U, 1U, 0U, 2, 1, 5),
                false);
  sf_mex_addfield(c15_y, c15_i_y, "ranD", "ranD", 0);
  sf_mex_assign(&c15_mxArrayOutData, c15_y, false);
  return c15_mxArrayOutData;
}

static void c15_o_emlrt_marshallIn(SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId,
  c15_struct_a2CnFCSncMqluNCp4sL5hD *c15_y)
{
  emlrtMsgIdentifier c15_thisId;
  static const char * c15_fieldNames[8] = { "i", "count", "sen_num", "yin",
    "yin_d", "delay_v", "ynd_tmp", "ranD" };

  c15_thisId.fParent = c15_parentId;
  sf_mex_check_struct(c15_parentId, c15_u, 8, c15_fieldNames, 0U, NULL);
  c15_thisId.fIdentifier = "i";
  c15_y->i = c15_p_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c15_u, "i", "i", 0)), &c15_thisId);
  c15_thisId.fIdentifier = "count";
  c15_y->count = c15_p_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c15_u, "count", "count", 0)), &c15_thisId);
  c15_thisId.fIdentifier = "sen_num";
  c15_y->sen_num = c15_p_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c15_u, "sen_num", "sen_num", 0)), &c15_thisId);
  c15_thisId.fIdentifier = "yin";
  c15_q_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c15_u, "yin",
    "yin", 0)), &c15_thisId, c15_y->yin);
  c15_thisId.fIdentifier = "yin_d";
  c15_r_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c15_u,
    "yin_d", "yin_d", 0)), &c15_thisId, c15_y->yin_d);
  c15_thisId.fIdentifier = "delay_v";
  c15_r_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c15_u,
    "delay_v", "delay_v", 0)), &c15_thisId, c15_y->delay_v);
  c15_thisId.fIdentifier = "ynd_tmp";
  c15_q_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c15_u,
    "ynd_tmp", "ynd_tmp", 0)), &c15_thisId, c15_y->ynd_tmp);
  c15_thisId.fIdentifier = "ranD";
  c15_s_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c15_u, "ranD",
    "ranD", 0)), &c15_thisId, c15_y->ranD);
  sf_mex_destroy(&c15_u);
}

static real_T c15_p_emlrt_marshallIn(SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId)
{
  real_T c15_y;
  real_T c15_d2;
  (void)chartInstance;
  sf_mex_import(c15_parentId, sf_mex_dup(c15_u), &c15_d2, 1, 0, 0U, 0, 0U, 0);
  c15_y = c15_d2;
  sf_mex_destroy(&c15_u);
  return c15_y;
}

static void c15_q_emlrt_marshallIn(SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId,
  real_T c15_y[9])
{
  real_T c15_dv10[9];
  int32_T c15_i55;
  (void)chartInstance;
  sf_mex_import(c15_parentId, sf_mex_dup(c15_u), c15_dv10, 1, 0, 0U, 1, 0U, 2, 1,
                9);
  for (c15_i55 = 0; c15_i55 < 9; c15_i55++) {
    c15_y[c15_i55] = c15_dv10[c15_i55];
  }

  sf_mex_destroy(&c15_u);
}

static void c15_r_emlrt_marshallIn(SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId,
  real_T c15_y[9])
{
  real_T c15_dv11[9];
  int32_T c15_i56;
  (void)chartInstance;
  sf_mex_import(c15_parentId, sf_mex_dup(c15_u), c15_dv11, 1, 0, 0U, 1, 0U, 2, 9,
                1);
  for (c15_i56 = 0; c15_i56 < 9; c15_i56++) {
    c15_y[c15_i56] = c15_dv11[c15_i56];
  }

  sf_mex_destroy(&c15_u);
}

static void c15_s_emlrt_marshallIn(SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId,
  real_T c15_y[5])
{
  real_T c15_dv12[5];
  int32_T c15_i57;
  (void)chartInstance;
  sf_mex_import(c15_parentId, sf_mex_dup(c15_u), c15_dv12, 1, 0, 0U, 1, 0U, 2, 1,
                5);
  for (c15_i57 = 0; c15_i57 < 5; c15_i57++) {
    c15_y[c15_i57] = c15_dv12[c15_i57];
  }

  sf_mex_destroy(&c15_u);
}

static void c15_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData)
{
  const mxArray *c15_b_structure;
  const char_T *c15_identifier;
  emlrtMsgIdentifier c15_thisId;
  c15_struct_a2CnFCSncMqluNCp4sL5hD c15_y;
  SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance;
  chartInstance = (SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct *)chartInstanceVoid;
  c15_b_structure = sf_mex_dup(c15_mxArrayInData);
  c15_identifier = c15_varName;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_o_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_b_structure), &c15_thisId,
    &c15_y);
  sf_mex_destroy(&c15_b_structure);
  *(c15_struct_a2CnFCSncMqluNCp4sL5hD *)c15_outData = c15_y;
  sf_mex_destroy(&c15_mxArrayInData);
}

static const mxArray *c15_i_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData)
{
  const mxArray *c15_mxArrayOutData = NULL;
  int32_T c15_i58;
  real_T c15_b_inData[10];
  int32_T c15_i59;
  real_T c15_u[10];
  const mxArray *c15_y = NULL;
  SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance;
  chartInstance = (SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct *)chartInstanceVoid;
  c15_mxArrayOutData = NULL;
  for (c15_i58 = 0; c15_i58 < 10; c15_i58++) {
    c15_b_inData[c15_i58] = (*(real_T (*)[10])c15_inData)[c15_i58];
  }

  for (c15_i59 = 0; c15_i59 < 10; c15_i59++) {
    c15_u[c15_i59] = c15_b_inData[c15_i59];
  }

  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", c15_u, 0, 0U, 1U, 0U, 1, 10), false);
  sf_mex_assign(&c15_mxArrayOutData, c15_y, false);
  return c15_mxArrayOutData;
}

static const mxArray *c15_j_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData)
{
  const mxArray *c15_mxArrayOutData = NULL;
  real_T c15_u;
  const mxArray *c15_y = NULL;
  SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance;
  chartInstance = (SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct *)chartInstanceVoid;
  c15_mxArrayOutData = NULL;
  c15_u = *(real_T *)c15_inData;
  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", &c15_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c15_mxArrayOutData, c15_y, false);
  return c15_mxArrayOutData;
}

static void c15_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData)
{
  const mxArray *c15_nargout;
  const char_T *c15_identifier;
  emlrtMsgIdentifier c15_thisId;
  real_T c15_y;
  SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance;
  chartInstance = (SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct *)chartInstanceVoid;
  c15_nargout = sf_mex_dup(c15_mxArrayInData);
  c15_identifier = c15_varName;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_y = c15_p_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_nargout),
    &c15_thisId);
  sf_mex_destroy(&c15_nargout);
  *(real_T *)c15_outData = c15_y;
  sf_mex_destroy(&c15_mxArrayInData);
}

const mxArray *sf_c15_SmAHTR_r1_PITTRTNUKE_get_eml_resolved_functions_info(void)
{
  const mxArray *c15_nameCaptureInfo = NULL;
  c15_nameCaptureInfo = NULL;
  sf_mex_assign(&c15_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c15_nameCaptureInfo;
}

static const mxArray *c15_k_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData)
{
  const mxArray *c15_mxArrayOutData = NULL;
  int32_T c15_u;
  const mxArray *c15_y = NULL;
  SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance;
  chartInstance = (SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct *)chartInstanceVoid;
  c15_mxArrayOutData = NULL;
  c15_u = *(int32_T *)c15_inData;
  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", &c15_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c15_mxArrayOutData, c15_y, false);
  return c15_mxArrayOutData;
}

static int32_T c15_t_emlrt_marshallIn(SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId)
{
  int32_T c15_y;
  int32_T c15_i60;
  (void)chartInstance;
  sf_mex_import(c15_parentId, sf_mex_dup(c15_u), &c15_i60, 1, 6, 0U, 0, 0U, 0);
  c15_y = c15_i60;
  sf_mex_destroy(&c15_u);
  return c15_y;
}

static void c15_j_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData)
{
  const mxArray *c15_b_sfEvent;
  const char_T *c15_identifier;
  emlrtMsgIdentifier c15_thisId;
  int32_T c15_y;
  SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance;
  chartInstance = (SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct *)chartInstanceVoid;
  c15_b_sfEvent = sf_mex_dup(c15_mxArrayInData);
  c15_identifier = c15_varName;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_y = c15_t_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_b_sfEvent),
    &c15_thisId);
  sf_mex_destroy(&c15_b_sfEvent);
  *(int32_T *)c15_outData = c15_y;
  sf_mex_destroy(&c15_mxArrayInData);
}

static uint8_T c15_u_emlrt_marshallIn(SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c15_b_is_active_c15_SmAHTR_r1_PITTRTNUKE, const
  char_T *c15_identifier)
{
  uint8_T c15_y;
  emlrtMsgIdentifier c15_thisId;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_y = c15_v_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c15_b_is_active_c15_SmAHTR_r1_PITTRTNUKE), &c15_thisId);
  sf_mex_destroy(&c15_b_is_active_c15_SmAHTR_r1_PITTRTNUKE);
  return c15_y;
}

static uint8_T c15_v_emlrt_marshallIn(SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId)
{
  uint8_T c15_y;
  uint8_T c15_u0;
  (void)chartInstance;
  sf_mex_import(c15_parentId, sf_mex_dup(c15_u), &c15_u0, 1, 3, 0U, 0, 0U, 0);
  c15_y = c15_u0;
  sf_mex_destroy(&c15_u);
  return c15_y;
}

static void init_dsm_address_info(SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct
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

void sf_c15_SmAHTR_r1_PITTRTNUKE_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3364650530U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1430893758U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4113872792U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3903491807U);
}

mxArray *sf_c15_SmAHTR_r1_PITTRTNUKE_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("fy29dwUDd9N6OYAW6JWfLE");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(13));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c15_SmAHTR_r1_PITTRTNUKE_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c15_SmAHTR_r1_PITTRTNUKE_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c15_SmAHTR_r1_PITTRTNUKE(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x8'type','srcId','name','auxInfo'{{M[1],M[5],T\"yout_delay\",},{M[4],M[0],T\"delay\",S'l','i','p'{{M1x2[332 337],M[0],}}},{M[4],M[0],T\"i\",S'l','i','p'{{M1x2[308 309],M[0],}}},{M[4],M[0],T\"num\",S'l','i','p'{{M1x2[346 349],M[0],}}},{M[4],M[0],T\"yin\",S'l','i','p'{{M1x2[328 331],M[0],}}},{M[4],M[0],T\"yin_all\",S'l','i','p'{{M1x2[338 345],M[0],}}},{M[4],M[0],T\"yin_d\",S'l','i','p'{{M1x2[310 315],M[0],}}},{M[8],M[0],T\"is_active_c15_SmAHTR_r1_PITTRTNUKE\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 8, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c15_SmAHTR_r1_PITTRTNUKE_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _SmAHTR_r1_PITTRTNUKEMachineNumber_,
           15,
           1,
           1,
           0,
           4,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"yout");
          _SFD_SET_DATA_PROPS(1,1,1,0,"ydelay");
          _SFD_SET_DATA_PROPS(2,2,0,1,"yout_delay");
          _SFD_SET_DATA_PROPS(3,10,0,0,"structure");
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
        _SFD_CV_INIT_EML(0,1,1,3,0,0,0,2,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1427);
        _SFD_CV_INIT_EML_IF(0,1,0,468,483,-1,726);
        _SFD_CV_INIT_EML_IF(0,1,1,968,987,1042,1261);
        _SFD_CV_INIT_EML_IF(0,1,2,1055,1063,-1,1245);
        _SFD_CV_INIT_EML_FOR(0,1,0,840,853,898);
        _SFD_CV_INIT_EML_FOR(0,1,1,954,964,1265);

        {
          unsigned int dimVector[1];
          dimVector[0]= 9;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c15_g_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 10;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c15_i_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 9;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c15_g_sf_marshallOut,(MexInFcnForType)
            c15_g_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(3,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c15_h_sf_marshallOut,(MexInFcnForType)
          c15_h_sf_marshallIn);

        {
          real_T (*c15_yout)[9];
          real_T (*c15_ydelay)[10];
          real_T (*c15_yout_delay)[9];
          c15_yout_delay = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S,
            1);
          c15_ydelay = (real_T (*)[10])ssGetInputPortSignal(chartInstance->S, 1);
          c15_yout = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c15_yout);
          _SFD_SET_DATA_VALUE_PTR(1U, *c15_ydelay);
          _SFD_SET_DATA_VALUE_PTR(2U, *c15_yout_delay);
          _SFD_SET_DATA_VALUE_PTR(3U, &chartInstance->c15_structure);
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
  return "9htdjBkdkIn9BfDQsw5xWE";
}

static void sf_opaque_initialize_c15_SmAHTR_r1_PITTRTNUKE(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c15_SmAHTR_r1_PITTRTNUKE
    ((SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct*) chartInstanceVar);
  initialize_c15_SmAHTR_r1_PITTRTNUKE((SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c15_SmAHTR_r1_PITTRTNUKE(void *chartInstanceVar)
{
  enable_c15_SmAHTR_r1_PITTRTNUKE((SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c15_SmAHTR_r1_PITTRTNUKE(void *chartInstanceVar)
{
  disable_c15_SmAHTR_r1_PITTRTNUKE((SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c15_SmAHTR_r1_PITTRTNUKE(void *chartInstanceVar)
{
  sf_gateway_c15_SmAHTR_r1_PITTRTNUKE((SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c15_SmAHTR_r1_PITTRTNUKE
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c15_SmAHTR_r1_PITTRTNUKE
    ((SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c15_SmAHTR_r1_PITTRTNUKE();/* state var info */
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

extern void sf_internal_set_sim_state_c15_SmAHTR_r1_PITTRTNUKE(SimStruct* S,
  const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c15_SmAHTR_r1_PITTRTNUKE();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c15_SmAHTR_r1_PITTRTNUKE
    ((SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c15_SmAHTR_r1_PITTRTNUKE(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c15_SmAHTR_r1_PITTRTNUKE(S);
}

static void sf_opaque_set_sim_state_c15_SmAHTR_r1_PITTRTNUKE(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c15_SmAHTR_r1_PITTRTNUKE(S, st);
}

static void sf_opaque_terminate_c15_SmAHTR_r1_PITTRTNUKE(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct*) chartInstanceVar)
      ->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_SmAHTR_r1_PITTRTNUKE_optimization_info();
    }

    finalize_c15_SmAHTR_r1_PITTRTNUKE((SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct*)
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
  initSimStructsc15_SmAHTR_r1_PITTRTNUKE
    ((SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c15_SmAHTR_r1_PITTRTNUKE(SimStruct *S)
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
    initialize_params_c15_SmAHTR_r1_PITTRTNUKE
      ((SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct*)(chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c15_SmAHTR_r1_PITTRTNUKE(SimStruct *S)
{
  /* Actual parameters from chart:
     structure
   */
  const char_T *rtParamNames[] = { "structure" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0],
    sf_get_param_data_type_id(S,0));
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_SmAHTR_r1_PITTRTNUKE_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      15);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,15,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,15,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,15);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,15,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,15,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 2; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,15);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3275509218U));
  ssSetChecksum1(S,(283278360U));
  ssSetChecksum2(S,(2391010678U));
  ssSetChecksum3(S,(59501449U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c15_SmAHTR_r1_PITTRTNUKE(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c15_SmAHTR_r1_PITTRTNUKE(SimStruct *S)
{
  SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct *)utMalloc(sizeof
    (SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c15_SmAHTR_r1_PITTRTNUKE;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c15_SmAHTR_r1_PITTRTNUKE;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c15_SmAHTR_r1_PITTRTNUKE;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c15_SmAHTR_r1_PITTRTNUKE;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c15_SmAHTR_r1_PITTRTNUKE;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c15_SmAHTR_r1_PITTRTNUKE;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c15_SmAHTR_r1_PITTRTNUKE;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c15_SmAHTR_r1_PITTRTNUKE;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c15_SmAHTR_r1_PITTRTNUKE;
  chartInstance->chartInfo.mdlStart = mdlStart_c15_SmAHTR_r1_PITTRTNUKE;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c15_SmAHTR_r1_PITTRTNUKE;
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

void c15_SmAHTR_r1_PITTRTNUKE_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c15_SmAHTR_r1_PITTRTNUKE(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c15_SmAHTR_r1_PITTRTNUKE(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c15_SmAHTR_r1_PITTRTNUKE(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c15_SmAHTR_r1_PITTRTNUKE_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
