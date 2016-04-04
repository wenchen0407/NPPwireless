#ifndef __c14_SmAHTR_r1_PITTRTNUKE_h__
#define __c14_SmAHTR_r1_PITTRTNUKE_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct
#define typedef_SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c14_sfEvent;
  boolean_T c14_isStable;
  boolean_T c14_doneDoubleBufferReInit;
  uint8_T c14_is_active_c14_SmAHTR_r1_PITTRTNUKE;
  real_T c14_delay1[10];
  boolean_T c14_delay1_not_empty;
  real_T c14_i;
  boolean_T c14_i_not_empty;
  real_T c14_last_emergency_instance[9];
  boolean_T c14_last_emergency_instance_not_empty;
  real_T c14_network_array[3600036];
  boolean_T c14_network_array_not_empty;
  int32_T *c14_counter_global_address;
  int32_T c14_counter_global_index;
  int32_T (*c14_ydelay_global_address)[10];
  int32_T c14_ydelay_global_index;
} SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct;

#endif                                 /*typedef_SFc14_SmAHTR_r1_PITTRTNUKEInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c14_SmAHTR_r1_PITTRTNUKE_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c14_SmAHTR_r1_PITTRTNUKE_get_check_sum(mxArray *plhs[]);
extern void c14_SmAHTR_r1_PITTRTNUKE_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
