/* Include files */

#include "SmAHTR_r1_PITTRTNUKE_sfun.h"
#include "SmAHTR_r1_PITTRTNUKE_sfun_debug_macros.h"
#include "c1_SmAHTR_r1_PITTRTNUKE.h"
#include "c3_SmAHTR_r1_PITTRTNUKE.h"
#include "c4_SmAHTR_r1_PITTRTNUKE.h"
#include "c5_SmAHTR_r1_PITTRTNUKE.h"
#include "c6_SmAHTR_r1_PITTRTNUKE.h"
#include "c7_SmAHTR_r1_PITTRTNUKE.h"
#include "c8_SmAHTR_r1_PITTRTNUKE.h"
#include "c9_SmAHTR_r1_PITTRTNUKE.h"
#include "c10_SmAHTR_r1_PITTRTNUKE.h"
#include "c11_SmAHTR_r1_PITTRTNUKE.h"
#include "c12_SmAHTR_r1_PITTRTNUKE.h"
#include "c14_SmAHTR_r1_PITTRTNUKE.h"
#include "c15_SmAHTR_r1_PITTRTNUKE.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _SmAHTR_r1_PITTRTNUKEMachineNumber_;

/* Function Declarations */

/* Function Definitions */
void SmAHTR_r1_PITTRTNUKE_initializer(void)
{
}

void SmAHTR_r1_PITTRTNUKE_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_SmAHTR_r1_PITTRTNUKE_method_dispatcher(SimStruct *simstructPtr,
  unsigned int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_SmAHTR_r1_PITTRTNUKE_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_SmAHTR_r1_PITTRTNUKE_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_SmAHTR_r1_PITTRTNUKE_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_SmAHTR_r1_PITTRTNUKE_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==6) {
    c6_SmAHTR_r1_PITTRTNUKE_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==7) {
    c7_SmAHTR_r1_PITTRTNUKE_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==8) {
    c8_SmAHTR_r1_PITTRTNUKE_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==9) {
    c9_SmAHTR_r1_PITTRTNUKE_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==10) {
    c10_SmAHTR_r1_PITTRTNUKE_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==11) {
    c11_SmAHTR_r1_PITTRTNUKE_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==12) {
    c12_SmAHTR_r1_PITTRTNUKE_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==14) {
    c14_SmAHTR_r1_PITTRTNUKE_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==15) {
    c15_SmAHTR_r1_PITTRTNUKE_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_SmAHTR_r1_PITTRTNUKE_process_check_sum_call( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1541801379U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1652211915U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(711780170U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3702218308U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4083533288U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4266102188U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3964060305U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4126199930U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_SmAHTR_r1_PITTRTNUKE_get_check_sum(mxArray *plhs[]);
          sf_c1_SmAHTR_r1_PITTRTNUKE_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_SmAHTR_r1_PITTRTNUKE_get_check_sum(mxArray *plhs[]);
          sf_c3_SmAHTR_r1_PITTRTNUKE_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_SmAHTR_r1_PITTRTNUKE_get_check_sum(mxArray *plhs[]);
          sf_c4_SmAHTR_r1_PITTRTNUKE_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_SmAHTR_r1_PITTRTNUKE_get_check_sum(mxArray *plhs[]);
          sf_c5_SmAHTR_r1_PITTRTNUKE_get_check_sum(plhs);
          break;
        }

       case 6:
        {
          extern void sf_c6_SmAHTR_r1_PITTRTNUKE_get_check_sum(mxArray *plhs[]);
          sf_c6_SmAHTR_r1_PITTRTNUKE_get_check_sum(plhs);
          break;
        }

       case 7:
        {
          extern void sf_c7_SmAHTR_r1_PITTRTNUKE_get_check_sum(mxArray *plhs[]);
          sf_c7_SmAHTR_r1_PITTRTNUKE_get_check_sum(plhs);
          break;
        }

       case 8:
        {
          extern void sf_c8_SmAHTR_r1_PITTRTNUKE_get_check_sum(mxArray *plhs[]);
          sf_c8_SmAHTR_r1_PITTRTNUKE_get_check_sum(plhs);
          break;
        }

       case 9:
        {
          extern void sf_c9_SmAHTR_r1_PITTRTNUKE_get_check_sum(mxArray *plhs[]);
          sf_c9_SmAHTR_r1_PITTRTNUKE_get_check_sum(plhs);
          break;
        }

       case 10:
        {
          extern void sf_c10_SmAHTR_r1_PITTRTNUKE_get_check_sum(mxArray *plhs[]);
          sf_c10_SmAHTR_r1_PITTRTNUKE_get_check_sum(plhs);
          break;
        }

       case 11:
        {
          extern void sf_c11_SmAHTR_r1_PITTRTNUKE_get_check_sum(mxArray *plhs[]);
          sf_c11_SmAHTR_r1_PITTRTNUKE_get_check_sum(plhs);
          break;
        }

       case 12:
        {
          extern void sf_c12_SmAHTR_r1_PITTRTNUKE_get_check_sum(mxArray *plhs[]);
          sf_c12_SmAHTR_r1_PITTRTNUKE_get_check_sum(plhs);
          break;
        }

       case 14:
        {
          extern void sf_c14_SmAHTR_r1_PITTRTNUKE_get_check_sum(mxArray *plhs[]);
          sf_c14_SmAHTR_r1_PITTRTNUKE_get_check_sum(plhs);
          break;
        }

       case 15:
        {
          extern void sf_c15_SmAHTR_r1_PITTRTNUKE_get_check_sum(mxArray *plhs[]);
          sf_c15_SmAHTR_r1_PITTRTNUKE_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2316031951U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2258360620U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2887754621U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2119700794U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2063446671U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(341205262U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4226926528U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2718339155U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_SmAHTR_r1_PITTRTNUKE_autoinheritance_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char aiChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;
  mxGetString(prhs[2], aiChksum,sizeof(aiChksum)/sizeof(char));
  aiChksum[(sizeof(aiChksum)/sizeof(char)-1)] = '\0';

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(aiChksum, "3gmITF2oI7zigi3nxtTCSC") == 0) {
          extern mxArray *sf_c1_SmAHTR_r1_PITTRTNUKE_get_autoinheritance_info
            (void);
          plhs[0] = sf_c1_SmAHTR_r1_PITTRTNUKE_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 3:
      {
        if (strcmp(aiChksum, "3gmITF2oI7zigi3nxtTCSC") == 0) {
          extern mxArray *sf_c3_SmAHTR_r1_PITTRTNUKE_get_autoinheritance_info
            (void);
          plhs[0] = sf_c3_SmAHTR_r1_PITTRTNUKE_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "sjAQNaVx4vlpPRV8vqJfy") == 0) {
          extern mxArray *sf_c4_SmAHTR_r1_PITTRTNUKE_get_autoinheritance_info
            (void);
          plhs[0] = sf_c4_SmAHTR_r1_PITTRTNUKE_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 5:
      {
        if (strcmp(aiChksum, "7R9ZlocbzPZmG0rkaQWAyD") == 0) {
          extern mxArray *sf_c5_SmAHTR_r1_PITTRTNUKE_get_autoinheritance_info
            (void);
          plhs[0] = sf_c5_SmAHTR_r1_PITTRTNUKE_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 6:
      {
        if (strcmp(aiChksum, "EQUsc0EIjfYh6z32gnDdrF") == 0) {
          extern mxArray *sf_c6_SmAHTR_r1_PITTRTNUKE_get_autoinheritance_info
            (void);
          plhs[0] = sf_c6_SmAHTR_r1_PITTRTNUKE_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 7:
      {
        if (strcmp(aiChksum, "3gmITF2oI7zigi3nxtTCSC") == 0) {
          extern mxArray *sf_c7_SmAHTR_r1_PITTRTNUKE_get_autoinheritance_info
            (void);
          plhs[0] = sf_c7_SmAHTR_r1_PITTRTNUKE_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 8:
      {
        if (strcmp(aiChksum, "PSMjelVyZDcvUaAxPVC6kE") == 0) {
          extern mxArray *sf_c8_SmAHTR_r1_PITTRTNUKE_get_autoinheritance_info
            (void);
          plhs[0] = sf_c8_SmAHTR_r1_PITTRTNUKE_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 9:
      {
        if (strcmp(aiChksum, "kNFURNIMqv06tgfv0cWXZC") == 0) {
          extern mxArray *sf_c9_SmAHTR_r1_PITTRTNUKE_get_autoinheritance_info
            (void);
          plhs[0] = sf_c9_SmAHTR_r1_PITTRTNUKE_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 10:
      {
        if (strcmp(aiChksum, "lf7t7Rt4ZrfaZZbf2gjERB") == 0) {
          extern mxArray *sf_c10_SmAHTR_r1_PITTRTNUKE_get_autoinheritance_info
            (void);
          plhs[0] = sf_c10_SmAHTR_r1_PITTRTNUKE_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 11:
      {
        if (strcmp(aiChksum, "YP5yRvYbyYQfBFFXHXerp") == 0) {
          extern mxArray *sf_c11_SmAHTR_r1_PITTRTNUKE_get_autoinheritance_info
            (void);
          plhs[0] = sf_c11_SmAHTR_r1_PITTRTNUKE_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 12:
      {
        if (strcmp(aiChksum, "CCwEcIpDI6l5PAFZLyUMgB") == 0) {
          extern mxArray *sf_c12_SmAHTR_r1_PITTRTNUKE_get_autoinheritance_info
            (void);
          plhs[0] = sf_c12_SmAHTR_r1_PITTRTNUKE_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 14:
      {
        if (strcmp(aiChksum, "Jh11LqnWxGXsX5ibnh5J5B") == 0) {
          extern mxArray *sf_c14_SmAHTR_r1_PITTRTNUKE_get_autoinheritance_info
            (void);
          plhs[0] = sf_c14_SmAHTR_r1_PITTRTNUKE_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 15:
      {
        if (strcmp(aiChksum, "fy29dwUDd9N6OYAW6JWfLE") == 0) {
          extern mxArray *sf_c15_SmAHTR_r1_PITTRTNUKE_get_autoinheritance_info
            (void);
          plhs[0] = sf_c15_SmAHTR_r1_PITTRTNUKE_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_SmAHTR_r1_PITTRTNUKE_get_eml_resolved_functions_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        extern const mxArray
          *sf_c1_SmAHTR_r1_PITTRTNUKE_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_SmAHTR_r1_PITTRTNUKE_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray
          *sf_c3_SmAHTR_r1_PITTRTNUKE_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_SmAHTR_r1_PITTRTNUKE_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray
          *sf_c4_SmAHTR_r1_PITTRTNUKE_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_SmAHTR_r1_PITTRTNUKE_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray
          *sf_c5_SmAHTR_r1_PITTRTNUKE_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_SmAHTR_r1_PITTRTNUKE_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 6:
      {
        extern const mxArray
          *sf_c6_SmAHTR_r1_PITTRTNUKE_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c6_SmAHTR_r1_PITTRTNUKE_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 7:
      {
        extern const mxArray
          *sf_c7_SmAHTR_r1_PITTRTNUKE_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c7_SmAHTR_r1_PITTRTNUKE_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 8:
      {
        extern const mxArray
          *sf_c8_SmAHTR_r1_PITTRTNUKE_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c8_SmAHTR_r1_PITTRTNUKE_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 9:
      {
        extern const mxArray
          *sf_c9_SmAHTR_r1_PITTRTNUKE_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c9_SmAHTR_r1_PITTRTNUKE_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 10:
      {
        extern const mxArray
          *sf_c10_SmAHTR_r1_PITTRTNUKE_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c10_SmAHTR_r1_PITTRTNUKE_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 11:
      {
        extern const mxArray
          *sf_c11_SmAHTR_r1_PITTRTNUKE_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c11_SmAHTR_r1_PITTRTNUKE_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 12:
      {
        extern const mxArray
          *sf_c12_SmAHTR_r1_PITTRTNUKE_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c12_SmAHTR_r1_PITTRTNUKE_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 14:
      {
        extern const mxArray
          *sf_c14_SmAHTR_r1_PITTRTNUKE_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c14_SmAHTR_r1_PITTRTNUKE_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 15:
      {
        extern const mxArray
          *sf_c15_SmAHTR_r1_PITTRTNUKE_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c15_SmAHTR_r1_PITTRTNUKE_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_SmAHTR_r1_PITTRTNUKE_third_party_uses_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the third_party_uses_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_third_party_uses_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "vYWYqEZzyViFKOXmpgyeqF") == 0) {
          extern mxArray *sf_c1_SmAHTR_r1_PITTRTNUKE_third_party_uses_info(void);
          plhs[0] = sf_c1_SmAHTR_r1_PITTRTNUKE_third_party_uses_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "vYWYqEZzyViFKOXmpgyeqF") == 0) {
          extern mxArray *sf_c3_SmAHTR_r1_PITTRTNUKE_third_party_uses_info(void);
          plhs[0] = sf_c3_SmAHTR_r1_PITTRTNUKE_third_party_uses_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "M0Fg57o25c3rzoFLBpKB9E") == 0) {
          extern mxArray *sf_c4_SmAHTR_r1_PITTRTNUKE_third_party_uses_info(void);
          plhs[0] = sf_c4_SmAHTR_r1_PITTRTNUKE_third_party_uses_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "irChmHpsNdFbLwcgcTmczE") == 0) {
          extern mxArray *sf_c5_SmAHTR_r1_PITTRTNUKE_third_party_uses_info(void);
          plhs[0] = sf_c5_SmAHTR_r1_PITTRTNUKE_third_party_uses_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "HEAHrQEefgbYWyyoAXy8oD") == 0) {
          extern mxArray *sf_c6_SmAHTR_r1_PITTRTNUKE_third_party_uses_info(void);
          plhs[0] = sf_c6_SmAHTR_r1_PITTRTNUKE_third_party_uses_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "vYWYqEZzyViFKOXmpgyeqF") == 0) {
          extern mxArray *sf_c7_SmAHTR_r1_PITTRTNUKE_third_party_uses_info(void);
          plhs[0] = sf_c7_SmAHTR_r1_PITTRTNUKE_third_party_uses_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "fCEkJTKowrEUEY1VIhCtvG") == 0) {
          extern mxArray *sf_c8_SmAHTR_r1_PITTRTNUKE_third_party_uses_info(void);
          plhs[0] = sf_c8_SmAHTR_r1_PITTRTNUKE_third_party_uses_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "OV9lzu2c8FVpplEGyyLevE") == 0) {
          extern mxArray *sf_c9_SmAHTR_r1_PITTRTNUKE_third_party_uses_info(void);
          plhs[0] = sf_c9_SmAHTR_r1_PITTRTNUKE_third_party_uses_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "VvOEM7HRXX25GtWAJ0XI2F") == 0) {
          extern mxArray *sf_c10_SmAHTR_r1_PITTRTNUKE_third_party_uses_info(void);
          plhs[0] = sf_c10_SmAHTR_r1_PITTRTNUKE_third_party_uses_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "bxgwXwwlQU8JAG3eqC3dhG") == 0) {
          extern mxArray *sf_c11_SmAHTR_r1_PITTRTNUKE_third_party_uses_info(void);
          plhs[0] = sf_c11_SmAHTR_r1_PITTRTNUKE_third_party_uses_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "pFIOfB6gEmUU42zrc5SofE") == 0) {
          extern mxArray *sf_c12_SmAHTR_r1_PITTRTNUKE_third_party_uses_info(void);
          plhs[0] = sf_c12_SmAHTR_r1_PITTRTNUKE_third_party_uses_info();
          break;
        }
      }

     case 14:
      {
        if (strcmp(tpChksum, "KtbF8o6u2NL4xmTHFmhKgC") == 0) {
          extern mxArray *sf_c14_SmAHTR_r1_PITTRTNUKE_third_party_uses_info(void);
          plhs[0] = sf_c14_SmAHTR_r1_PITTRTNUKE_third_party_uses_info();
          break;
        }
      }

     case 15:
      {
        if (strcmp(tpChksum, "9htdjBkdkIn9BfDQsw5xWE") == 0) {
          extern mxArray *sf_c15_SmAHTR_r1_PITTRTNUKE_third_party_uses_info(void);
          plhs[0] = sf_c15_SmAHTR_r1_PITTRTNUKE_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_SmAHTR_r1_PITTRTNUKE_updateBuildInfo_args_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the updateBuildInfo_args_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_updateBuildInfo_args_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "vYWYqEZzyViFKOXmpgyeqF") == 0) {
          extern mxArray *sf_c1_SmAHTR_r1_PITTRTNUKE_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c1_SmAHTR_r1_PITTRTNUKE_updateBuildInfo_args_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "vYWYqEZzyViFKOXmpgyeqF") == 0) {
          extern mxArray *sf_c3_SmAHTR_r1_PITTRTNUKE_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c3_SmAHTR_r1_PITTRTNUKE_updateBuildInfo_args_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "M0Fg57o25c3rzoFLBpKB9E") == 0) {
          extern mxArray *sf_c4_SmAHTR_r1_PITTRTNUKE_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c4_SmAHTR_r1_PITTRTNUKE_updateBuildInfo_args_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "irChmHpsNdFbLwcgcTmczE") == 0) {
          extern mxArray *sf_c5_SmAHTR_r1_PITTRTNUKE_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c5_SmAHTR_r1_PITTRTNUKE_updateBuildInfo_args_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "HEAHrQEefgbYWyyoAXy8oD") == 0) {
          extern mxArray *sf_c6_SmAHTR_r1_PITTRTNUKE_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c6_SmAHTR_r1_PITTRTNUKE_updateBuildInfo_args_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "vYWYqEZzyViFKOXmpgyeqF") == 0) {
          extern mxArray *sf_c7_SmAHTR_r1_PITTRTNUKE_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c7_SmAHTR_r1_PITTRTNUKE_updateBuildInfo_args_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "fCEkJTKowrEUEY1VIhCtvG") == 0) {
          extern mxArray *sf_c8_SmAHTR_r1_PITTRTNUKE_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c8_SmAHTR_r1_PITTRTNUKE_updateBuildInfo_args_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "OV9lzu2c8FVpplEGyyLevE") == 0) {
          extern mxArray *sf_c9_SmAHTR_r1_PITTRTNUKE_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c9_SmAHTR_r1_PITTRTNUKE_updateBuildInfo_args_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "VvOEM7HRXX25GtWAJ0XI2F") == 0) {
          extern mxArray *sf_c10_SmAHTR_r1_PITTRTNUKE_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c10_SmAHTR_r1_PITTRTNUKE_updateBuildInfo_args_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "bxgwXwwlQU8JAG3eqC3dhG") == 0) {
          extern mxArray *sf_c11_SmAHTR_r1_PITTRTNUKE_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c11_SmAHTR_r1_PITTRTNUKE_updateBuildInfo_args_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "pFIOfB6gEmUU42zrc5SofE") == 0) {
          extern mxArray *sf_c12_SmAHTR_r1_PITTRTNUKE_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c12_SmAHTR_r1_PITTRTNUKE_updateBuildInfo_args_info();
          break;
        }
      }

     case 14:
      {
        if (strcmp(tpChksum, "KtbF8o6u2NL4xmTHFmhKgC") == 0) {
          extern mxArray *sf_c14_SmAHTR_r1_PITTRTNUKE_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c14_SmAHTR_r1_PITTRTNUKE_updateBuildInfo_args_info();
          break;
        }
      }

     case 15:
      {
        if (strcmp(tpChksum, "9htdjBkdkIn9BfDQsw5xWE") == 0) {
          extern mxArray *sf_c15_SmAHTR_r1_PITTRTNUKE_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c15_SmAHTR_r1_PITTRTNUKE_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void SmAHTR_r1_PITTRTNUKE_debug_initialize(struct SfDebugInstanceStruct*
  debugInstance)
{
  _SmAHTR_r1_PITTRTNUKEMachineNumber_ = sf_debug_initialize_machine
    (debugInstance,"SmAHTR_r1_PITTRTNUKE","sfun",0,13,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _SmAHTR_r1_PITTRTNUKEMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,
    _SmAHTR_r1_PITTRTNUKEMachineNumber_,0);
}

void SmAHTR_r1_PITTRTNUKE_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_SmAHTR_r1_PITTRTNUKE_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info(
      "SmAHTR_r1_PITTRTNUKE", "SmAHTR_r1_PITTRTNUKE");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_SmAHTR_r1_PITTRTNUKE_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
