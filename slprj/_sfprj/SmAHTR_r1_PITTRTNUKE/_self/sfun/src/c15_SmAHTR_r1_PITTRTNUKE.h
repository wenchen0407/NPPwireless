#ifndef __c15_SmAHTR_r1_PITTRTNUKE_h__
#define __c15_SmAHTR_r1_PITTRTNUKE_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef struct_struct_a2CnFCSncMqluNCp4sL5hD_tag
#define struct_struct_a2CnFCSncMqluNCp4sL5hD_tag

struct struct_a2CnFCSncMqluNCp4sL5hD_tag
{
  real_T i;
  real_T count;
  real_T sen_num;
  real_T yin[9];
  real_T yin_d[9];
  real_T delay_v[9];
  real_T ynd_tmp[9];
  real_T ranD[5];
};

#endif                                 /*struct_struct_a2CnFCSncMqluNCp4sL5hD_tag*/

#ifndef typedef_c15_struct_a2CnFCSncMqluNCp4sL5hD
#define typedef_c15_struct_a2CnFCSncMqluNCp4sL5hD

typedef struct struct_a2CnFCSncMqluNCp4sL5hD_tag
  c15_struct_a2CnFCSncMqluNCp4sL5hD;

#endif                                 /*typedef_c15_struct_a2CnFCSncMqluNCp4sL5hD*/

#ifndef typedef_SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct
#define typedef_SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c15_sfEvent;
  boolean_T c15_isStable;
  boolean_T c15_doneDoubleBufferReInit;
  uint8_T c15_is_active_c15_SmAHTR_r1_PITTRTNUKE;
  c15_struct_a2CnFCSncMqluNCp4sL5hD c15_structure;
  real_T c15_i;
  boolean_T c15_i_not_empty;
  real_T c15_yin_d[9];
  boolean_T c15_yin_d_not_empty;
  real_T c15_yin[9];
  boolean_T c15_yin_not_empty;
  real_T c15_delay[10];
  boolean_T c15_delay_not_empty;
  real_T c15_yin_all[7200009];
  boolean_T c15_yin_all_not_empty;
  real_T c15_num;
  boolean_T c15_num_not_empty;
} SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct;

#endif                                 /*typedef_SFc15_SmAHTR_r1_PITTRTNUKEInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c15_SmAHTR_r1_PITTRTNUKE_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c15_SmAHTR_r1_PITTRTNUKE_get_check_sum(mxArray *plhs[]);
extern void c15_SmAHTR_r1_PITTRTNUKE_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
