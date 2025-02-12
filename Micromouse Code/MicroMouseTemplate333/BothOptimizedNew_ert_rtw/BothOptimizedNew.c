/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: BothOptimizedNew.c
 *
 * Code generated for Simulink model 'BothOptimizedNew'.
 *
 * Model version                  : 4.75
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Fri Oct 18 13:50:04 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "BothOptimizedNew.h"
#include "rtwtypes.h"
#include "BothOptimizedNew_types.h"
#include "BothOptimizedNew_private.h"
#include <string.h>
#include <math.h>
#include "stm_timer_ll.h"
#include "stm_adc_ll.h"

/* Named constants for Chart: '<Root>/HelloMicroMouse!' */
#define B_IN_Calibration_Left_and_Right ((uint8_T)3U)
#define Bot_IN_Turning_Right_Adjustment ((uint8_T)3U)
#define BothOpt_IN_Calibration_Forward1 ((uint8_T)2U)
#define BothOptim_IN_TurnLeftToStraight ((uint8_T)8U)
#define BothOptimi_IN_Calibration_Down1 ((uint8_T)1U)
#define BothOptimi_IN_CheckStraightWall ((uint8_T)3U)
#define BothOptimiz_IN_TurnRightToRight ((uint8_T)9U)
#define BothOptimize_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define BothOptimizedN_IN_CheckLeftWall ((uint8_T)1U)
#define BothOptimizedN_IN_CheckWallBack ((uint8_T)4U)
#define BothOptimizedN_IN_LineFollowing ((uint8_T)5U)
#define BothOptimizedNe_IN_Placeholder2 ((uint8_T)7U)
#define BothOptimizedNew_IN_Checks     ((uint8_T)1U)
#define BothOptimizedNew_IN_CrossRoad  ((uint8_T)4U)
#define BothOptimizedNew_IN_Done1      ((uint8_T)2U)
#define BothOptimizedNew_IN_Forward    ((uint8_T)1U)
#define BothOptimizedNew_IN_Forward_f  ((uint8_T)3U)
#define BothOptimizedNew_IN_MoveCentre ((uint8_T)5U)
#define BothOptimizedNew_IN_Optimised  ((uint8_T)6U)
#define BothOptimizedNew_IN_Ready2     ((uint8_T)8U)
#define BothOptimizedNew_IN_TurnAround ((uint8_T)4U)
#define BothOptimizedNew_IN_TurnAround2 ((uint8_T)5U)
#define BothOptimizedNew_IN_TurnLeft   ((uint8_T)6U)
#define BothOptimizedNew_IN_TurnLeft2  ((uint8_T)7U)
#define BothOptimizedNew_IN_TurnLeft3  ((uint8_T)8U)
#define BothOptimizedNew_IN_TurnRight  ((uint8_T)9U)
#define BothOptimizedNew_IN_TurnRight2 ((uint8_T)10U)
#define BothOptimizedNew_IN_TurnRight3 ((uint8_T)11U)
#define BothOptimizedNew_IN_Turns      ((uint8_T)9U)
#define BothOptimized_IN_CheckRightWall ((uint8_T)2U)
#define BothOptimized_IN_TurnLeftToBack ((uint8_T)6U)
#define BothOptimized_IN_TurnLeftToLeft ((uint8_T)7U)
#define Both_IN_Turning_Left_Adjustment ((uint8_T)2U)
#define Both_IN_WaitUntilButtonPressed6 ((uint8_T)10U)

/* user code (top of source file) */
/* System '<Root>' */
extern I2C_HandleTypeDef hi2c2;

/* Exported block states */
real32_T IMU_Accel[3];                 /* '<S7>/Data Store Memory' */
real32_T IMU_Gyro[3];                  /* '<S7>/Data Store Memory1' */
int32_T currTicksRS;                   /* '<S1>/Data Store Memory2' */
int32_T currTicksLS;                   /* '<S1>/Data Store Memory4' */
uint16_T Thresholds[8];                /* '<S1>/Data Store Memory1' */
uint16_T ADC1s[9];                     /* '<S6>/Data Store Memory' */
uint16_T ADC_H[9];                     /* '<S6>/Data Store Memory1' */
uint16_T ADC_L[9];                     /* '<S6>/Data Store Memory2' */
boolean_T Detections[8];               /* '<S1>/Data Store Memory' */

/* Block signals (default storage) */
B_BothOptimizedNew_T BothOptimizedNew_B;

/* Block states (default storage) */
DW_BothOptimizedNew_T BothOptimizedNew_DW;

/* Real-time model */
static RT_MODEL_BothOptimizedNew_T BothOptimizedNew_M_;
RT_MODEL_BothOptimizedNew_T *const BothOptimizedNew_M = &BothOptimizedNew_M_;

/* Forward declaration for local functions */
static void BothOptimizedNew_CrossRoad(const boolean_T *NOT1);
static boolean_T BothOptimizedNew_isequal(const real_T varargin_1[3], const
  real_T varargin_2[3]);
static void BothOptimizedNew_optimize_path(const real_T input_path[100], real_T
  optimized_path[100]);
static void BothOptimizedNew_LineFollowing(const boolean_T *NOT);
static void BothOptimizedNew_Optimised(void);
static void BothOptimizedNew_Turns(const boolean_T *NOT1, const boolean_T *NOT);
static void BothOptimizedN_SystemCore_setup(stm32cube_blocks_AnalogInput__T *obj);
static void BothOptim_PWMOutput_setupImpl_j(stm32cube_blocks_PWMOutput_Bo_T *obj);
static void BothOptimiz_PWMOutput_setupImpl(stm32cube_blocks_PWMOutput_Bo_T *obj);

/* System initialize for atomic system: */
void BothOptimize_MATLABSystem1_Init(DW_MATLABSystem1_BothOptimize_T *localDW,
  P_MATLABSystem1_BothOptimized_T *localP)
{
  int32_T i;

  /* Start for MATLABSystem: '<S47>/MATLAB System1' */
  localDW->objisempty = true;
  localDW->obj.InitialCondition = localP->MATLABSystem1_InitialCondition;
  localDW->obj.isInitialized = 1;

  /*  Number of inputs */
  /*  Initialize the buffer during the first call */
  for (i = 0; i < 25; i++) {
    localDW->obj.Buffer[i] = localDW->obj.InitialCondition;
  }

  /* End of Start for MATLABSystem: '<S47>/MATLAB System1' */
}

/* Output and update for atomic system: */
void BothOptimizedNew_MATLABSystem1(real_T rtu_0,
  B_MATLABSystem1_BothOptimized_T *localB, DW_MATLABSystem1_BothOptimize_T
  *localDW, P_MATLABSystem1_BothOptimized_T *localP)
{
  /* MATLABSystem: '<S47>/MATLAB System1' */
  if (localDW->obj.InitialCondition != localP->MATLABSystem1_InitialCondition) {
    localDW->obj.InitialCondition = localP->MATLABSystem1_InitialCondition;
  }

  /*  Number of inputs */
  /*  Number of outputs */
  /*  Output the current state of the buffer */
  memcpy(&localB->MATLABSystem1[0], &localDW->obj.Buffer[0], 25U * sizeof(real_T));

  /*  Update the buffer */
  localB->rtu_0[0] = rtu_0;
  memcpy(&localB->rtu_0[1], &localDW->obj.Buffer[0], 24U * sizeof(real_T));
  memcpy(&localDW->obj.Buffer[0], &localB->rtu_0[0], 25U * sizeof(real_T));

  /* End of MATLABSystem: '<S47>/MATLAB System1' */
}

/* System initialize for atomic system: */
void BothOptimize_MATLABSystem3_Init(DW_MATLABSystem3_BothOptimize_T *localDW,
  P_MATLABSystem3_BothOptimized_T *localP)
{
  int32_T i;

  /* Start for MATLABSystem: '<S47>/MATLAB System3' */
  localDW->objisempty = true;
  localDW->obj.InitialCondition = localP->MATLABSystem3_InitialCondition;
  localDW->obj.isInitialized = 1;

  /*  Number of inputs */
  /*  Initialize the buffer during the first call */
  for (i = 0; i < 10; i++) {
    localDW->obj.Buffer[i] = localDW->obj.InitialCondition;
  }

  /* End of Start for MATLABSystem: '<S47>/MATLAB System3' */
}

/* Output and update for atomic system: */
void BothOptimizedNew_MATLABSystem3(real_T rtu_0,
  B_MATLABSystem3_BothOptimized_T *localB, DW_MATLABSystem3_BothOptimize_T
  *localDW, P_MATLABSystem3_BothOptimized_T *localP)
{
  /* MATLABSystem: '<S47>/MATLAB System3' */
  if (localDW->obj.InitialCondition != localP->MATLABSystem3_InitialCondition) {
    localDW->obj.InitialCondition = localP->MATLABSystem3_InitialCondition;
  }

  /*  Number of inputs */
  /*  Number of outputs */
  /*  Output the current state of the buffer */
  memcpy(&localB->MATLABSystem3[0], &localDW->obj.Buffer[0], 10U * sizeof(real_T));

  /*  Update the buffer */
  localB->rtu_0[0] = rtu_0;
  memcpy(&localB->rtu_0[1], &localDW->obj.Buffer[0], 9U * sizeof(real_T));
  memcpy(&localDW->obj.Buffer[0], &localB->rtu_0[0], 10U * sizeof(real_T));

  /* End of MATLABSystem: '<S47>/MATLAB System3' */
}

real_T rt_roundd(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Function for Chart: '<Root>/HelloMicroMouse!' */
static void BothOptimizedNew_CrossRoad(const boolean_T *NOT1)
{
  if (*NOT1) {
    BothOptimizedNew_DW.temporalCounter_i1 = 0U;
    BothOptimizedNew_DW.bitsForTID0.is_c2_BothOptimizedNew =
      BothOptimizedN_IN_LineFollowing;
    BothOptimizedNew_B.LED0 = false;
    BothOptimizedNew_B.LED2 = false;
    BothOptimizedNew_B.LED_LEFT = false;
    BothOptimizedNew_B.LED_RIGHT = false;
    BothOptimizedNew_B.LED_FWD_LEFT = true;
    BothOptimizedNew_B.LED_FWD_RIGHT = true;
    BothOptimizedNew_B.LED_DOWN_RIGHT = true;
    BothOptimizedNew_B.LED_DOWN_LEFT = true;
    BothOptimizedNew_DW.bitsForTID0.is_LineFollowing =
      BothOptimizedNew_IN_Forward;
    BothOptimizedNew_B.LED1 = true;
    BothOptimizedNew_B.leftWheel = 80.0;
    BothOptimizedNew_B.rightWheel = 80.0;
  } else if ((BothOptimizedNew_DW.solved == 0.0) &&
             (BothOptimizedNew_DW.temporalCounter_i1 >= 10)) {
    BothOptimizedNew_DW.bitsForTID0.is_c2_BothOptimizedNew =
      BothOptimizedNew_IN_Turns;
    BothOptimizedNew_DW.solved = 0.0;
    BothOptimizedNew_B.LED0 = false;
    BothOptimizedNew_B.LED1 = false;
    BothOptimizedNew_B.LED2 = false;
    BothOptimizedNew_DW.R = 1.0;
    BothOptimizedNew_DW.S = 2.0;
    BothOptimizedNew_DW.L = 3.0;
    BothOptimizedNew_DW.B = 4.0;
    BothOptimizedNew_DW.temporalCounter_i1 = 0U;
    BothOptimizedNew_DW.bitsForTID0.is_Turns = BothOptimizedNew_IN_MoveCentre;
    BothOptimizedNew_B.leftWheel = 75.0;
    BothOptimizedNew_B.rightWheel = 75.0;
  } else if ((BothOptimizedNew_DW.solved == 1.0) &&
             (BothOptimizedNew_DW.temporalCounter_i1 >= 10)) {
    BothOptimizedNew_DW.bitsForTID0.is_c2_BothOptimizedNew =
      BothOptimizedNew_IN_Optimised;
    BothOptimizedNew_B.LED0 = true;
    BothOptimizedNew_B.LED1 = true;
    BothOptimizedNew_B.LED2 = true;
    BothOptimizedNew_DW.next = 0.0;
    BothOptimizedNew_DW.bitsForTID0.is_Optimised = BothOptimizedNew_IN_Checks;
    BothOptimizedNew_DW.checking = BothOptimizedNew_DW.optimisedPath[(int32_T)
      BothOptimizedNew_DW.index - 1];
  }
}

/* Function for Chart: '<Root>/HelloMicroMouse!' */
static boolean_T BothOptimizedNew_isequal(const real_T varargin_1[3], const
  real_T varargin_2[3])
{
  int32_T k;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  b_p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 3)) {
    if (varargin_1[k] != varargin_2[k]) {
      b_p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

/* Function for Chart: '<Root>/HelloMicroMouse!' */
static void BothOptimizedNew_optimize_path(const real_T input_path[100], real_T
  optimized_path[100])
{
  real_T opt_index;
  int32_T i;
  boolean_T b_p;
  boolean_T p;
  static const real_T b[3] = { 3.0, 4.0, 1.0 };

  static const real_T c[3] = { 1.0, 4.0, 3.0 };

  static const real_T d[3] = { 2.0, 4.0, 2.0 };

  static const real_T e[3] = { 1.0, 4.0, 2.0 };

  static const real_T f[3] = { 2.0, 4.0, 1.0 };

  static const real_T g[3] = { 3.0, 4.0, 3.0 };

  static const real_T h[3] = { 1.0, 4.0, 1.0 };

  int32_T exitg1;
  boolean_T exitg2;
  for (i = 0; i < 100; i++) {
    BothOptimizedNew_B.previous_path[i] = input_path[i];
    optimized_path[i] = 0.0;
  }

  do {
    exitg1 = 0;
    opt_index = 1.0;
    i = 0;
    while (i + 1 <= 100) {
      if (i + 1 <= 98) {
        if (BothOptimizedNew_isequal(&BothOptimizedNew_B.previous_path[i], b)) {
          optimized_path[(int32_T)opt_index - 1] = 4.0;
          i += 3;
        } else if (BothOptimizedNew_isequal(&BothOptimizedNew_B.previous_path[i],
                    c)) {
          optimized_path[(int32_T)opt_index - 1] = 4.0;
          i += 3;
        } else if (BothOptimizedNew_isequal(&BothOptimizedNew_B.previous_path[i],
                    d)) {
          optimized_path[(int32_T)opt_index - 1] = 4.0;
          i += 3;
        } else if (BothOptimizedNew_isequal(&BothOptimizedNew_B.previous_path[i],
                    e)) {
          optimized_path[(int32_T)opt_index - 1] = 3.0;
          i += 3;
        } else if (BothOptimizedNew_isequal(&BothOptimizedNew_B.previous_path[i],
                    f)) {
          optimized_path[(int32_T)opt_index - 1] = 3.0;
          i += 3;
        } else if (BothOptimizedNew_isequal(&BothOptimizedNew_B.previous_path[i],
                    g)) {
          optimized_path[(int32_T)opt_index - 1] = 2.0;
          i += 3;
        } else if (BothOptimizedNew_isequal(&BothOptimizedNew_B.previous_path[i],
                    h)) {
          optimized_path[(int32_T)opt_index - 1] = 2.0;
          i += 3;
        } else {
          optimized_path[(int32_T)opt_index - 1] =
            BothOptimizedNew_B.previous_path[i];
          i++;
        }
      } else {
        optimized_path[(int32_T)opt_index - 1] =
          BothOptimizedNew_B.previous_path[i];
        i++;
      }

      opt_index++;
    }

    p = false;
    b_p = true;
    i = 0;
    exitg2 = false;
    while ((!exitg2) && (i < 100)) {
      if (BothOptimizedNew_B.previous_path[i] != optimized_path[i]) {
        b_p = false;
        exitg2 = true;
      } else {
        i++;
      }
    }

    if (b_p) {
      p = true;
    }

    if (p) {
      exitg1 = 1;
    } else {
      for (i = 0; i < 100; i++) {
        BothOptimizedNew_B.previous_path[i] = optimized_path[i];
        optimized_path[i] = 0.0;
      }
    }
  } while (exitg1 == 0);
}

/* Function for Chart: '<Root>/HelloMicroMouse!' */
static void BothOptimizedNew_LineFollowing(const boolean_T *NOT)
{
  BothOptimizedNew_B.LED_LEFT = false;
  BothOptimizedNew_B.LED_RIGHT = false;
  BothOptimizedNew_B.LED_FWD_LEFT = true;
  BothOptimizedNew_B.LED_FWD_RIGHT = true;
  BothOptimizedNew_B.LED_DOWN_RIGHT = true;
  BothOptimizedNew_B.LED_DOWN_LEFT = true;
  if ((BothOptimizedNew_B.Flip[5] < BothOptimizedNew_DW.DOWN_L_DARK) &&
      (BothOptimizedNew_B.Flip[2] < BothOptimizedNew_DW.DOWN_R_DARK) &&
      (BothOptimizedNew_DW.temporalCounter_i1 >= 10)) {
    switch (BothOptimizedNew_DW.bitsForTID0.is_LineFollowing) {
     case BothOptimizedNew_IN_Forward:
      BothOptimizedNew_DW.bitsForTID0.is_LineFollowing =
        BothOptimize_IN_NO_ACTIVE_CHILD;
      break;

     case Both_IN_Turning_Left_Adjustment:
      BothOptimizedNew_DW.bitsForTID0.is_LineFollowing =
        BothOptimize_IN_NO_ACTIVE_CHILD;
      break;

     case Bot_IN_Turning_Right_Adjustment:
      BothOptimizedNew_DW.bitsForTID0.is_LineFollowing =
        BothOptimize_IN_NO_ACTIVE_CHILD;
      break;
    }

    BothOptimizedNew_DW.temporalCounter_i1 = 0U;
    BothOptimizedNew_DW.bitsForTID0.is_c2_BothOptimizedNew =
      BothOptimizedNew_IN_CrossRoad;
    BothOptimizedNew_B.LED0 = false;
    BothOptimizedNew_B.LED1 = false;
    BothOptimizedNew_B.LED2 = false;
    BothOptimizedNew_B.leftWheel = 0.0;
    BothOptimizedNew_B.rightWheel = 0.0;
  } else if (*NOT) {
    switch (BothOptimizedNew_DW.bitsForTID0.is_LineFollowing) {
     case BothOptimizedNew_IN_Forward:
      BothOptimizedNew_DW.bitsForTID0.is_LineFollowing =
        BothOptimize_IN_NO_ACTIVE_CHILD;
      break;

     case Both_IN_Turning_Left_Adjustment:
      BothOptimizedNew_DW.bitsForTID0.is_LineFollowing =
        BothOptimize_IN_NO_ACTIVE_CHILD;
      break;

     case Bot_IN_Turning_Right_Adjustment:
      BothOptimizedNew_DW.bitsForTID0.is_LineFollowing =
        BothOptimize_IN_NO_ACTIVE_CHILD;
      break;
    }

    BothOptimizedNew_B.LED0 = false;
    BothOptimizedNew_B.LED1 = false;
    BothOptimizedNew_B.LED2 = false;
    BothOptimizedNew_DW.bitsForTID0.is_c2_BothOptimizedNew =
      BothOptimizedNe_IN_Placeholder2;
    BothOptimizedNew_DW.index = 1.0;
    BothOptimizedNew_B.leftWheel = 0.0;
    BothOptimizedNew_B.rightWheel = 0.0;
    BothOptimizedNew_DW.solved = 1.0;
    BothOptimizedNew_optimize_path(BothOptimizedNew_DW.SolvedAlgorithm,
      BothOptimizedNew_DW.optimisedPath);
  } else {
    switch (BothOptimizedNew_DW.bitsForTID0.is_LineFollowing) {
     case BothOptimizedNew_IN_Forward:
      if (BothOptimizedNew_B.Flip[2] > BothOptimizedNew_B.Flip[5]) {
        BothOptimizedNew_B.LED1 = false;
        BothOptimizedNew_DW.bitsForTID0.is_LineFollowing =
          Bot_IN_Turning_Right_Adjustment;
        BothOptimizedNew_B.LED2 = true;
        BothOptimizedNew_B.leftWheel = 80.0;
        BothOptimizedNew_B.rightWheel = 70.0;
      } else if (BothOptimizedNew_B.Flip[2] < BothOptimizedNew_B.Flip[5]) {
        BothOptimizedNew_B.LED1 = false;
        BothOptimizedNew_DW.bitsForTID0.is_LineFollowing =
          Both_IN_Turning_Left_Adjustment;
        BothOptimizedNew_B.LED0 = true;
        BothOptimizedNew_B.rightWheel = 80.0;
        BothOptimizedNew_B.leftWheel = 70.0;
      }
      break;

     case Both_IN_Turning_Left_Adjustment:
      BothOptimizedNew_B.LED0 = false;
      BothOptimizedNew_DW.bitsForTID0.is_LineFollowing =
        BothOptimizedNew_IN_Forward;
      BothOptimizedNew_B.LED1 = true;
      BothOptimizedNew_B.leftWheel = 80.0;
      BothOptimizedNew_B.rightWheel = 80.0;
      break;

     default:
      /* case IN_Turning_Right_Adjustment: */
      BothOptimizedNew_B.LED2 = false;
      BothOptimizedNew_DW.bitsForTID0.is_LineFollowing =
        BothOptimizedNew_IN_Forward;
      BothOptimizedNew_B.LED1 = true;
      BothOptimizedNew_B.leftWheel = 80.0;
      BothOptimizedNew_B.rightWheel = 80.0;
      break;
    }
  }
}

/* Function for Chart: '<Root>/HelloMicroMouse!' */
static void BothOptimizedNew_Optimised(void)
{
  if (BothOptimizedNew_DW.next == 1.0) {
    if (BothOptimizedNew_DW.bitsForTID0.is_Optimised ==
        BothOptimizedNew_IN_Checks) {
      BothOptimizedNew_DW.index++;
      BothOptimizedNew_DW.bitsForTID0.is_Optimised =
        BothOptimize_IN_NO_ACTIVE_CHILD;
    } else {
      BothOptimizedNew_DW.bitsForTID0.is_Optimised =
        BothOptimize_IN_NO_ACTIVE_CHILD;
    }

    BothOptimizedNew_DW.temporalCounter_i1 = 0U;
    BothOptimizedNew_DW.bitsForTID0.is_c2_BothOptimizedNew =
      BothOptimizedN_IN_LineFollowing;
    BothOptimizedNew_B.LED0 = false;
    BothOptimizedNew_B.LED2 = false;
    BothOptimizedNew_B.LED_LEFT = false;
    BothOptimizedNew_B.LED_RIGHT = false;
    BothOptimizedNew_B.LED_FWD_LEFT = true;
    BothOptimizedNew_B.LED_FWD_RIGHT = true;
    BothOptimizedNew_B.LED_DOWN_RIGHT = true;
    BothOptimizedNew_B.LED_DOWN_LEFT = true;
    BothOptimizedNew_DW.bitsForTID0.is_LineFollowing =
      BothOptimizedNew_IN_Forward;
    BothOptimizedNew_B.LED1 = true;
    BothOptimizedNew_B.leftWheel = 80.0;
    BothOptimizedNew_B.rightWheel = 80.0;
  } else {
    switch (BothOptimizedNew_DW.bitsForTID0.is_Optimised) {
     case BothOptimizedNew_IN_Checks:
      if (BothOptimizedNew_DW.checking == BothOptimizedNew_DW.R) {
        BothOptimizedNew_DW.index++;
        BothOptimizedNew_DW.temporalCounter_i1 = 0U;
        BothOptimizedNew_DW.bitsForTID0.is_Optimised =
          BothOptimizedNew_IN_TurnRight;
        BothOptimizedNew_B.leftWheel = 75.0;
        BothOptimizedNew_B.rightWheel = 75.0;
      } else if (BothOptimizedNew_DW.checking == BothOptimizedNew_DW.S) {
        BothOptimizedNew_DW.index++;
        BothOptimizedNew_DW.bitsForTID0.is_Optimised =
          BothOptimizedNew_IN_Forward_f;
        BothOptimizedNew_B.leftWheel = 0.0;
        BothOptimizedNew_B.rightWheel = 0.0;
        BothOptimizedNew_DW.next = 1.0;
      } else if (BothOptimizedNew_DW.checking == BothOptimizedNew_DW.B) {
        BothOptimizedNew_DW.index++;
        BothOptimizedNew_DW.temporalCounter_i1 = 0U;
        BothOptimizedNew_DW.bitsForTID0.is_Optimised =
          BothOptimizedNew_IN_TurnAround;
        BothOptimizedNew_B.leftWheel = 75.0;
        BothOptimizedNew_B.rightWheel = -75.0;
      } else if (BothOptimizedNew_DW.checking == BothOptimizedNew_DW.L) {
        BothOptimizedNew_DW.index++;
        BothOptimizedNew_DW.temporalCounter_i1 = 0U;
        BothOptimizedNew_DW.bitsForTID0.is_Optimised =
          BothOptimizedNew_IN_TurnLeft;
        BothOptimizedNew_B.leftWheel = 75.0;
        BothOptimizedNew_B.rightWheel = 75.0;
      } else if (BothOptimizedNew_DW.checking == 0.0) {
        BothOptimizedNew_DW.index++;
        BothOptimizedNew_DW.bitsForTID0.is_Optimised = BothOptimizedNew_IN_Done1;
        BothOptimizedNew_B.leftWheel = 0.0;
        BothOptimizedNew_B.rightWheel = 0.0;
      }
      break;

     case BothOptimizedNew_IN_Done1:
     case BothOptimizedNew_IN_Forward_f:
     case BothOptimizedNew_IN_TurnAround2:
     case BothOptimizedNew_IN_TurnLeft3:
      break;

     case BothOptimizedNew_IN_TurnAround:
      if (BothOptimizedNew_DW.temporalCounter_i1 >= 23) {
        BothOptimizedNew_DW.bitsForTID0.is_Optimised =
          BothOptimizedNew_IN_TurnAround2;
        BothOptimizedNew_B.leftWheel = 0.0;
        BothOptimizedNew_B.rightWheel = 0.0;
        BothOptimizedNew_DW.next = 1.0;
      }
      break;

     case BothOptimizedNew_IN_TurnLeft:
      if (BothOptimizedNew_DW.temporalCounter_i1 >= 4) {
        BothOptimizedNew_DW.temporalCounter_i1 = 0U;
        BothOptimizedNew_DW.bitsForTID0.is_Optimised =
          BothOptimizedNew_IN_TurnLeft2;
        BothOptimizedNew_B.leftWheel = -75.0;
        BothOptimizedNew_B.rightWheel = 75.0;
      }
      break;

     case BothOptimizedNew_IN_TurnLeft2:
      if (BothOptimizedNew_DW.temporalCounter_i1 >= 12) {
        BothOptimizedNew_DW.bitsForTID0.is_Optimised =
          BothOptimizedNew_IN_TurnLeft3;
        BothOptimizedNew_B.leftWheel = 0.0;
        BothOptimizedNew_B.rightWheel = 0.0;
        BothOptimizedNew_DW.next = 1.0;
      }
      break;

     case BothOptimizedNew_IN_TurnRight:
      if (BothOptimizedNew_DW.temporalCounter_i1 >= 4) {
        BothOptimizedNew_DW.temporalCounter_i1 = 0U;
        BothOptimizedNew_DW.bitsForTID0.is_Optimised =
          BothOptimizedNew_IN_TurnRight2;
        BothOptimizedNew_B.leftWheel = 75.0;
        BothOptimizedNew_B.rightWheel = -75.0;
      }
      break;

     case BothOptimizedNew_IN_TurnRight2:
      if (BothOptimizedNew_DW.temporalCounter_i1 >= 11) {
        BothOptimizedNew_DW.bitsForTID0.is_Optimised =
          BothOptimizedNew_IN_TurnRight3;
        BothOptimizedNew_B.leftWheel = 0.0;
        BothOptimizedNew_B.rightWheel = 0.0;
        BothOptimizedNew_DW.next = 1.0;
      }
      break;

     default:
      /* case IN_TurnRight3: */
      break;
    }
  }
}

/* Function for Chart: '<Root>/HelloMicroMouse!' */
static void BothOptimizedNew_Turns(const boolean_T *NOT1, const boolean_T *NOT)
{
  if (BothOptimizedNew_B.LED1) {
    BothOptimizedNew_DW.bitsForTID0.is_Turns = BothOptimize_IN_NO_ACTIVE_CHILD;
    BothOptimizedNew_DW.temporalCounter_i1 = 0U;
    BothOptimizedNew_DW.bitsForTID0.is_c2_BothOptimizedNew =
      BothOptimizedN_IN_LineFollowing;
    BothOptimizedNew_B.LED0 = false;
    BothOptimizedNew_B.LED2 = false;
    BothOptimizedNew_B.LED_LEFT = false;
    BothOptimizedNew_B.LED_RIGHT = false;
    BothOptimizedNew_B.LED_FWD_LEFT = true;
    BothOptimizedNew_B.LED_FWD_RIGHT = true;
    BothOptimizedNew_B.LED_DOWN_RIGHT = true;
    BothOptimizedNew_B.LED_DOWN_LEFT = true;
    BothOptimizedNew_DW.bitsForTID0.is_LineFollowing =
      BothOptimizedNew_IN_Forward;
    BothOptimizedNew_B.leftWheel = 80.0;
    BothOptimizedNew_B.rightWheel = 80.0;
  } else if (*NOT) {
    BothOptimizedNew_DW.bitsForTID0.is_Turns = BothOptimize_IN_NO_ACTIVE_CHILD;
    BothOptimizedNew_DW.bitsForTID0.is_c2_BothOptimizedNew =
      BothOptimizedNe_IN_Placeholder2;
    BothOptimizedNew_DW.index = 1.0;
    BothOptimizedNew_B.leftWheel = 0.0;
    BothOptimizedNew_B.rightWheel = 0.0;
    BothOptimizedNew_DW.solved = 1.0;
    BothOptimizedNew_optimize_path(BothOptimizedNew_DW.SolvedAlgorithm,
      BothOptimizedNew_DW.optimisedPath);
  } else {
    switch (BothOptimizedNew_DW.bitsForTID0.is_Turns) {
     case BothOptimizedN_IN_CheckLeftWall:
      if (BothOptimizedNew_DW.temporalCounter_i1 >= 11) {
        BothOptimizedNew_DW.temporalCounter_i1 = 0U;
        BothOptimizedNew_DW.bitsForTID0.is_Turns =
          BothOptimized_IN_TurnLeftToBack;
        BothOptimizedNew_B.leftWheel = -75.0;
        BothOptimizedNew_B.rightWheel = 75.0;
      }
      break;

     case BothOptimized_IN_CheckRightWall:
      if (BothOptimizedNew_DW.temporalCounter_i1 >= 11) {
        BothOptimizedNew_DW.temporalCounter_i1 = 0U;
        BothOptimizedNew_DW.bitsForTID0.is_Turns =
          BothOptim_IN_TurnLeftToStraight;
        BothOptimizedNew_B.leftWheel = -75.0;
        BothOptimizedNew_B.rightWheel = 75.0;
      }
      break;

     case BothOptimi_IN_CheckStraightWall:
      if (BothOptimizedNew_DW.temporalCounter_i1 >= 11) {
        BothOptimizedNew_DW.temporalCounter_i1 = 0U;
        BothOptimizedNew_DW.bitsForTID0.is_Turns =
          BothOptimized_IN_TurnLeftToLeft;
        BothOptimizedNew_B.leftWheel = -75.0;
        BothOptimizedNew_B.rightWheel = 75.0;
      }
      break;

     case BothOptimizedN_IN_CheckWallBack:
      if (*NOT1) {
        BothOptimizedNew_DW.temporalCounter_i1 = 0U;
        BothOptimizedNew_DW.bitsForTID0.is_Turns =
          BothOptimiz_IN_TurnRightToRight;
        BothOptimizedNew_B.leftWheel = 75.0;
        BothOptimizedNew_B.rightWheel = -75.0;
      } else if ((BothOptimizedNew_B.Flip[6] <= (int32_T)rt_roundd(0.8 * (real_T)
                   BothOptimizedNew_DW.init_FWD_LEFT)) ||
                 (BothOptimizedNew_B.Flip[1] <= (int32_T)rt_roundd(0.8 * (real_T)
                   BothOptimizedNew_DW.init_FWD_RIGHT))) {
        BothOptimizedNew_DW.SolvedAlgorithm[(int32_T)BothOptimizedNew_DW.index -
          1] = BothOptimizedNew_DW.B;
        BothOptimizedNew_DW.index++;
        BothOptimizedNew_B.LED1 = true;
      }
      break;

     case BothOptimizedNew_IN_MoveCentre:
      if (BothOptimizedNew_DW.temporalCounter_i1 >= 4) {
        BothOptimizedNew_DW.temporalCounter_i1 = 0U;
        BothOptimizedNew_DW.bitsForTID0.is_Turns =
          BothOptimiz_IN_TurnRightToRight;
        BothOptimizedNew_B.leftWheel = 75.0;
        BothOptimizedNew_B.rightWheel = -75.0;
      }
      break;

     case BothOptimized_IN_TurnLeftToBack:
      if (BothOptimizedNew_DW.temporalCounter_i1 >= 12) {
        BothOptimizedNew_DW.bitsForTID0.is_Turns =
          BothOptimizedN_IN_CheckWallBack;
        BothOptimizedNew_B.leftWheel = 0.0;
        BothOptimizedNew_B.rightWheel = 0.0;
      }
      break;

     case BothOptimized_IN_TurnLeftToLeft:
      if (BothOptimizedNew_DW.temporalCounter_i1 >= 12) {
        BothOptimizedNew_DW.temporalCounter_i1 = 0U;
        BothOptimizedNew_DW.bitsForTID0.is_Turns =
          BothOptimizedN_IN_CheckLeftWall;
        BothOptimizedNew_B.leftWheel = 0.0;
        BothOptimizedNew_B.rightWheel = 0.0;
        if ((BothOptimizedNew_B.Flip[6] <= (int32_T)rt_roundd(0.8 * (real_T)
              BothOptimizedNew_DW.init_FWD_LEFT)) || (BothOptimizedNew_B.Flip[1]
             <= (int32_T)rt_roundd(0.8 * (real_T)
              BothOptimizedNew_DW.init_FWD_RIGHT))) {
          BothOptimizedNew_DW.SolvedAlgorithm[(int32_T)BothOptimizedNew_DW.index
            - 1] = BothOptimizedNew_DW.L;
          BothOptimizedNew_DW.index++;
          BothOptimizedNew_B.LED1 = true;
        }
      }
      break;

     case BothOptim_IN_TurnLeftToStraight:
      if (BothOptimizedNew_DW.temporalCounter_i1 >= 12) {
        BothOptimizedNew_DW.temporalCounter_i1 = 0U;
        BothOptimizedNew_DW.bitsForTID0.is_Turns =
          BothOptimi_IN_CheckStraightWall;
        BothOptimizedNew_B.leftWheel = 0.0;
        BothOptimizedNew_B.rightWheel = 0.0;
        if ((BothOptimizedNew_B.Flip[6] <= (int32_T)rt_roundd(0.8 * (real_T)
              BothOptimizedNew_DW.init_FWD_LEFT)) || (BothOptimizedNew_B.Flip[1]
             <= (int32_T)rt_roundd(0.8 * (real_T)
              BothOptimizedNew_DW.init_FWD_RIGHT))) {
          BothOptimizedNew_DW.SolvedAlgorithm[(int32_T)BothOptimizedNew_DW.index
            - 1] = BothOptimizedNew_DW.S;
          BothOptimizedNew_DW.index++;
          BothOptimizedNew_B.LED1 = true;
        }
      }
      break;

     default:
      /* case IN_TurnRightToRight: */
      if (BothOptimizedNew_DW.temporalCounter_i1 >= 11) {
        BothOptimizedNew_DW.temporalCounter_i1 = 0U;
        BothOptimizedNew_DW.bitsForTID0.is_Turns =
          BothOptimized_IN_CheckRightWall;
        BothOptimizedNew_B.leftWheel = 0.0;
        BothOptimizedNew_B.rightWheel = 0.0;
        if ((BothOptimizedNew_B.Flip[6] <= (int32_T)rt_roundd(0.8 * (real_T)
              BothOptimizedNew_DW.init_FWD_LEFT)) || (BothOptimizedNew_B.Flip[1]
             <= (int32_T)rt_roundd(0.8 * (real_T)
              BothOptimizedNew_DW.init_FWD_RIGHT))) {
          BothOptimizedNew_DW.SolvedAlgorithm[(int32_T)BothOptimizedNew_DW.index
            - 1] = BothOptimizedNew_DW.R;
          BothOptimizedNew_DW.index++;
          BothOptimizedNew_B.LED1 = true;
        }
      }
      break;
    }
  }
}

static void BothOptimizedN_SystemCore_setup(stm32cube_blocks_AnalogInput__T *obj)
{
  ADC_Type_T adcStructLoc;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S46>/Analog to Digital Converter' */
  obj->isInitialized = 1;
  adcStructLoc.InternalBufferPtr = (void*)(&obj->ADCInternalBuffer[0]);
  adcStructLoc.InjectedNoOfConversion = 0U;
  adcStructLoc.peripheralPtr = ADC2;
  adcStructLoc.dmaPeripheralPtr = DMA1;
  adcStructLoc.dmastream = LL_DMA_CHANNEL_2;
  adcStructLoc.DataTransferMode = ADC_DR_TRANSFER;
  adcStructLoc.DmaTransferMode = ADC_DMA_TRANSFER_UNLIMITED;
  adcStructLoc.InternalBufferSize = 9U;
  adcStructLoc.RegularNoOfConversion = 9U;
  obj->ADCHandle = ADC_Handle_Init(&adcStructLoc, ADC_DMA_INTERRUPT_MODE, 1,
    ADC_TRIGGER_AND_READ, LL_ADC_REG_SEQ_SCAN_ENABLE_9RANKS);
  enableADCAutomaticCalibrationOffset(obj->ADCHandle, 2);
  enableADC(obj->ADCHandle);
  startADCConversionForExternalTrigger(obj->ADCHandle, 1);
  obj->isSetupComplete = true;
}

static void BothOptim_PWMOutput_setupImpl_j(stm32cube_blocks_PWMOutput_Bo_T *obj)
{
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<S42>/PWM Output' */
  b.PeripheralPtr = TIM3;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S42>/PWM Output' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  enableTimerChannel1(obj->TimerHandle, ENABLE_CH);
  enableTimerChannel2(obj->TimerHandle, ENABLE_CH);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S42>/PWM Output' */
    enableCounter(obj->TimerHandle, false);
  }
}

static void BothOptimiz_PWMOutput_setupImpl(stm32cube_blocks_PWMOutput_Bo_T *obj)
{
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<S40>/PWM Output' */
  b.PeripheralPtr = TIM3;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S40>/PWM Output' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  enableTimerChannel3(obj->TimerHandle, ENABLE_CH);
  enableTimerChannel4(obj->TimerHandle, ENABLE_CH);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S40>/PWM Output' */
    enableCounter(obj->TimerHandle, false);
  }
}

/* Model step function */
void BothOptimizedNew_step(void)
{
  real_T maxV;
  real_T maxV_0;
  real_T minV;
  real_T u1;
  int32_T i;
  uint32_T pinReadLoc;
  boolean_T NOT;
  boolean_T NOT1;
  for (i = 0; i < 8; i++) {
    /* DataStoreWrite: '<S1>/Data Store Write' */
    Detections[i] = false;

    /* DataStoreWrite: '<S1>/Data Store Write1' */
    Thresholds[i] = 0U;
  }

  /* DataStoreWrite: '<S1>/Data Store Write2' */
  currTicksRS = 0;

  /* DataStoreWrite: '<S1>/Data Store Write3' */
  currTicksLS = 0;

  /* MATLABSystem: '<S46>/Analog to Digital Converter' */
  regularReadADCDMA(BothOptimizedNew_DW.obj.ADCHandle, ADC_TRIGGER_AND_READ,
                    &ADC1s[0]);

  /* DSPFlip: '<S6>/Flip' incorporates:
   *  MATLABSystem: '<S46>/Analog to Digital Converter'
   */
  BothOptimizedNew_B.Flip[0] = ADC1s[7];
  BothOptimizedNew_B.Flip[7] = ADC1s[0];
  BothOptimizedNew_B.Flip[1] = ADC1s[6];
  BothOptimizedNew_B.Flip[6] = ADC1s[1];
  BothOptimizedNew_B.Flip[2] = ADC1s[5];
  BothOptimizedNew_B.Flip[5] = ADC1s[2];
  BothOptimizedNew_B.Flip[3] = ADC1s[4];
  BothOptimizedNew_B.Flip[4] = ADC1s[3];

  /* DataTypeConversion: '<S49>/Cast To Double' */
  for (i = 0; i < 8; i++) {
    BothOptimizedNew_B.CastToDouble[i] = BothOptimizedNew_B.Flip[i];
  }

  /* End of DataTypeConversion: '<S49>/Cast To Double' */
  BothOptimizedNew_MATLABSystem1((real_T)BothOptimizedNew_B.CastToDouble[0],
    &BothOptimizedNew_B.MATLABSystem2_ci, &BothOptimizedNew_DW.MATLABSystem2_ci,
    &BothOptimizedNew_P.MATLABSystem2_ci);

  /* MinMax: '<S47>/Max of Elements' incorporates:
   *  MATLABSystem: '<S49>/MATLAB System2'
   */
  BothOptimizedNew_B.maxV = BothOptimizedNew_B.MATLABSystem2_ci.MATLABSystem1[0];
  for (i = 0; i < 24; i++) {
    u1 = BothOptimizedNew_B.MATLABSystem2_ci.MATLABSystem1[i + 1];
    if (BothOptimizedNew_B.maxV < u1) {
      BothOptimizedNew_B.maxV = u1;
    }
  }

  BothOptimizedNew_MATLABSystem3((real_T)BothOptimizedNew_B.CastToDouble[1],
    &BothOptimizedNew_B.MATLABSystem4, &BothOptimizedNew_DW.MATLABSystem4,
    &BothOptimizedNew_P.MATLABSystem4);

  /* MinMax: '<S47>/Max of Elements1' incorporates:
   *  MATLABSystem: '<S47>/MATLAB System4'
   */
  BothOptimizedNew_B.maxV_m = BothOptimizedNew_B.MATLABSystem4.MATLABSystem3[0];
  for (i = 0; i < 9; i++) {
    u1 = BothOptimizedNew_B.MATLABSystem4.MATLABSystem3[i + 1];
    if (BothOptimizedNew_B.maxV_m < u1) {
      BothOptimizedNew_B.maxV_m = u1;
    }
  }

  BothOptimizedNew_MATLABSystem1(BothOptimizedNew_B.maxV_m,
    &BothOptimizedNew_B.MATLABSystem1, &BothOptimizedNew_DW.MATLABSystem1,
    &BothOptimizedNew_P.MATLABSystem1);

  /* End of MinMax: '<S47>/Max of Elements1' */

  /* MinMax: '<S47>/Min' incorporates:
   *  MATLABSystem: '<S47>/MATLAB System1'
   */
  BothOptimizedNew_B.minV = BothOptimizedNew_B.MATLABSystem1.MATLABSystem1[0];
  for (i = 0; i < 24; i++) {
    u1 = BothOptimizedNew_B.MATLABSystem1.MATLABSystem1[i + 1];
    if (BothOptimizedNew_B.minV > u1) {
      BothOptimizedNew_B.minV = u1;
    }
  }

  BothOptimizedNew_MATLABSystem1((real_T)BothOptimizedNew_B.CastToDouble[2],
    &BothOptimizedNew_B.MATLABSystem1_ci, &BothOptimizedNew_DW.MATLABSystem1_ci,
    &BothOptimizedNew_P.MATLABSystem1_ci);

  /* MinMax: '<S47>/Max of Elements2' incorporates:
   *  MATLABSystem: '<S49>/MATLAB System1'
   */
  BothOptimizedNew_B.maxV_m = BothOptimizedNew_B.MATLABSystem1_ci.MATLABSystem1
    [0];
  for (i = 0; i < 24; i++) {
    u1 = BothOptimizedNew_B.MATLABSystem1_ci.MATLABSystem1[i + 1];
    if (BothOptimizedNew_B.maxV_m < u1) {
      BothOptimizedNew_B.maxV_m = u1;
    }
  }

  BothOptimizedNew_MATLABSystem1((real_T)BothOptimizedNew_B.CastToDouble[3],
    &BothOptimizedNew_B.MATLABSystem3_c, &BothOptimizedNew_DW.MATLABSystem3_c,
    &BothOptimizedNew_P.MATLABSystem3_c);

  /* MinMax: '<S47>/Max of Elements3' incorporates:
   *  MATLABSystem: '<S49>/MATLAB System3'
   */
  BothOptimizedNew_B.maxV_c = BothOptimizedNew_B.MATLABSystem3_c.MATLABSystem1[0];
  for (i = 0; i < 24; i++) {
    u1 = BothOptimizedNew_B.MATLABSystem3_c.MATLABSystem1[i + 1];
    if (BothOptimizedNew_B.maxV_c < u1) {
      BothOptimizedNew_B.maxV_c = u1;
    }
  }

  BothOptimizedNew_MATLABSystem1((real_T)BothOptimizedNew_B.CastToDouble[4],
    &BothOptimizedNew_B.MATLABSystem4_c, &BothOptimizedNew_DW.MATLABSystem4_c,
    &BothOptimizedNew_P.MATLABSystem4_c);

  /* MinMax: '<S47>/Max of Elements4' incorporates:
   *  MATLABSystem: '<S49>/MATLAB System4'
   */
  BothOptimizedNew_B.maxV_k = BothOptimizedNew_B.MATLABSystem4_c.MATLABSystem1[0];
  for (i = 0; i < 24; i++) {
    u1 = BothOptimizedNew_B.MATLABSystem4_c.MATLABSystem1[i + 1];
    if (BothOptimizedNew_B.maxV_k < u1) {
      BothOptimizedNew_B.maxV_k = u1;
    }
  }

  BothOptimizedNew_MATLABSystem1((real_T)BothOptimizedNew_B.CastToDouble[5],
    &BothOptimizedNew_B.MATLABSystem5, &BothOptimizedNew_DW.MATLABSystem5,
    &BothOptimizedNew_P.MATLABSystem5);

  /* MinMax: '<S47>/Max of Elements5' incorporates:
   *  MATLABSystem: '<S49>/MATLAB System5'
   */
  maxV = BothOptimizedNew_B.MATLABSystem5.MATLABSystem1[0];
  for (i = 0; i < 24; i++) {
    u1 = BothOptimizedNew_B.MATLABSystem5.MATLABSystem1[i + 1];
    if (maxV < u1) {
      maxV = u1;
    }
  }

  BothOptimizedNew_MATLABSystem3((real_T)BothOptimizedNew_B.CastToDouble[6],
    &BothOptimizedNew_B.MATLABSystem3, &BothOptimizedNew_DW.MATLABSystem3,
    &BothOptimizedNew_P.MATLABSystem3);

  /* MinMax: '<S47>/Max of Elements6' incorporates:
   *  MATLABSystem: '<S47>/MATLAB System3'
   */
  maxV_0 = BothOptimizedNew_B.MATLABSystem3.MATLABSystem3[0];
  for (i = 0; i < 9; i++) {
    u1 = BothOptimizedNew_B.MATLABSystem3.MATLABSystem3[i + 1];
    if (maxV_0 < u1) {
      maxV_0 = u1;
    }
  }

  BothOptimizedNew_MATLABSystem1(maxV_0, &BothOptimizedNew_B.MATLABSystem2,
    &BothOptimizedNew_DW.MATLABSystem2, &BothOptimizedNew_P.MATLABSystem2);

  /* End of MinMax: '<S47>/Max of Elements6' */

  /* MinMax: '<S47>/Min1' incorporates:
   *  MATLABSystem: '<S47>/MATLAB System2'
   */
  minV = BothOptimizedNew_B.MATLABSystem2.MATLABSystem1[0];
  for (i = 0; i < 24; i++) {
    u1 = BothOptimizedNew_B.MATLABSystem2.MATLABSystem1[i + 1];
    if (minV > u1) {
      minV = u1;
    }
  }

  BothOptimizedNew_MATLABSystem1((real_T)BothOptimizedNew_B.CastToDouble[7],
    &BothOptimizedNew_B.MATLABSystem6, &BothOptimizedNew_DW.MATLABSystem6,
    &BothOptimizedNew_P.MATLABSystem6);

  /* MinMax: '<S47>/Max of Elements7' incorporates:
   *  MATLABSystem: '<S49>/MATLAB System6'
   */
  maxV_0 = BothOptimizedNew_B.MATLABSystem6.MATLABSystem1[0];

  /* MinMax: '<S47>/Max of Elements' */
  u1 = fmod(floor(BothOptimizedNew_B.maxV), 65536.0);

  /* DataStoreWrite: '<S44>/ADC_H Write' incorporates:
   *  MinMax: '<S47>/Max of Elements'
   */
  ADC_H[0] = (uint16_T)(u1 < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-u1 :
                        (int32_T)(uint16_T)u1);

  /* MinMax: '<S47>/Min' */
  u1 = fmod(floor(BothOptimizedNew_B.minV), 65536.0);

  /* DataStoreWrite: '<S44>/ADC_H Write' incorporates:
   *  MinMax: '<S47>/Min'
   */
  ADC_H[1] = (uint16_T)(u1 < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-u1 :
                        (int32_T)(uint16_T)u1);

  /* MinMax: '<S47>/Max of Elements2' */
  u1 = fmod(floor(BothOptimizedNew_B.maxV_m), 65536.0);

  /* DataStoreWrite: '<S44>/ADC_H Write' incorporates:
   *  MinMax: '<S47>/Max of Elements2'
   */
  ADC_H[2] = (uint16_T)(u1 < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-u1 :
                        (int32_T)(uint16_T)u1);

  /* MinMax: '<S47>/Max of Elements3' */
  u1 = fmod(floor(BothOptimizedNew_B.maxV_c), 65536.0);

  /* DataStoreWrite: '<S44>/ADC_H Write' incorporates:
   *  MinMax: '<S47>/Max of Elements3'
   */
  ADC_H[3] = (uint16_T)(u1 < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-u1 :
                        (int32_T)(uint16_T)u1);

  /* MinMax: '<S47>/Max of Elements4' */
  u1 = fmod(floor(BothOptimizedNew_B.maxV_k), 65536.0);

  /* DataStoreWrite: '<S44>/ADC_H Write' incorporates:
   *  MinMax: '<S47>/Max of Elements4'
   */
  ADC_H[4] = (uint16_T)(u1 < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-u1 :
                        (int32_T)(uint16_T)u1);

  /* MinMax: '<S47>/Max of Elements5' */
  u1 = fmod(floor(maxV), 65536.0);

  /* DataStoreWrite: '<S44>/ADC_H Write' incorporates:
   *  MinMax: '<S47>/Max of Elements5'
   */
  ADC_H[5] = (uint16_T)(u1 < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-u1 :
                        (int32_T)(uint16_T)u1);

  /* MinMax: '<S47>/Min1' */
  u1 = fmod(floor(minV), 65536.0);

  /* DataStoreWrite: '<S44>/ADC_H Write' incorporates:
   *  Constant: '<S44>/Constant'
   *  MinMax: '<S47>/Min1'
   */
  ADC_H[6] = (uint16_T)(u1 < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-u1 :
                        (int32_T)(uint16_T)u1);
  ADC_H[8] = BothOptimizedNew_P.Constant_Value_b;

  /* MinMax: '<S48>/Max of Elements8' incorporates:
   *  MATLABSystem: '<S49>/MATLAB System2'
   */
  BothOptimizedNew_B.minV = BothOptimizedNew_B.MATLABSystem2_ci.MATLABSystem1[0];
  for (i = 0; i < 24; i++) {
    /* MinMax: '<S47>/Max of Elements7' incorporates:
     *  MATLABSystem: '<S49>/MATLAB System6'
     */
    u1 = BothOptimizedNew_B.MATLABSystem6.MATLABSystem1[i + 1];
    if (maxV_0 < u1) {
      maxV_0 = u1;
    }

    /* MinMax: '<S48>/Max of Elements8' incorporates:
     *  MATLABSystem: '<S49>/MATLAB System2'
     */
    u1 = BothOptimizedNew_B.MATLABSystem2_ci.MATLABSystem1[i + 1];
    if (BothOptimizedNew_B.minV > u1) {
      BothOptimizedNew_B.minV = u1;
    }
  }

  /* MinMax: '<S47>/Max of Elements7' */
  u1 = fmod(floor(maxV_0), 65536.0);

  /* DataStoreWrite: '<S44>/ADC_H Write' incorporates:
   *  MinMax: '<S47>/Max of Elements7'
   */
  ADC_H[7] = (uint16_T)(u1 < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-u1 :
                        (int32_T)(uint16_T)u1);
  BothOptimizedNew_MATLABSystem1((real_T)BothOptimizedNew_B.CastToDouble[1],
    &BothOptimizedNew_B.MATLABSystem1_c, &BothOptimizedNew_DW.MATLABSystem1_c,
    &BothOptimizedNew_P.MATLABSystem1_c);

  /* MinMax: '<S48>/Max of Elements9' incorporates:
   *  MATLABSystem: '<S48>/MATLAB System1'
   */
  minV = BothOptimizedNew_B.MATLABSystem1_c.MATLABSystem1[0];

  /* MinMax: '<S48>/Max of Elements10' incorporates:
   *  MATLABSystem: '<S49>/MATLAB System1'
   */
  BothOptimizedNew_B.maxV_m = BothOptimizedNew_B.MATLABSystem1_ci.MATLABSystem1
    [0];

  /* MinMax: '<S48>/Max of Elements11' incorporates:
   *  MATLABSystem: '<S49>/MATLAB System3'
   */
  BothOptimizedNew_B.maxV_c = BothOptimizedNew_B.MATLABSystem3_c.MATLABSystem1[0];

  /* MinMax: '<S48>/Max of Elements12' incorporates:
   *  MATLABSystem: '<S49>/MATLAB System4'
   */
  BothOptimizedNew_B.maxV_k = BothOptimizedNew_B.MATLABSystem4_c.MATLABSystem1[0];

  /* MinMax: '<S48>/Max of Elements13' incorporates:
   *  MATLABSystem: '<S49>/MATLAB System5'
   */
  maxV = BothOptimizedNew_B.MATLABSystem5.MATLABSystem1[0];
  for (i = 0; i < 24; i++) {
    /* MinMax: '<S48>/Max of Elements9' incorporates:
     *  MATLABSystem: '<S48>/MATLAB System1'
     */
    u1 = BothOptimizedNew_B.MATLABSystem1_c.MATLABSystem1[i + 1];
    if (minV > u1) {
      minV = u1;
    }

    /* MinMax: '<S48>/Max of Elements10' incorporates:
     *  MATLABSystem: '<S49>/MATLAB System1'
     */
    u1 = BothOptimizedNew_B.MATLABSystem1_ci.MATLABSystem1[i + 1];
    if (BothOptimizedNew_B.maxV_m > u1) {
      BothOptimizedNew_B.maxV_m = u1;
    }

    /* MinMax: '<S48>/Max of Elements11' incorporates:
     *  MATLABSystem: '<S49>/MATLAB System3'
     */
    u1 = BothOptimizedNew_B.MATLABSystem3_c.MATLABSystem1[i + 1];
    if (BothOptimizedNew_B.maxV_c > u1) {
      BothOptimizedNew_B.maxV_c = u1;
    }

    /* MinMax: '<S48>/Max of Elements12' incorporates:
     *  MATLABSystem: '<S49>/MATLAB System4'
     */
    u1 = BothOptimizedNew_B.MATLABSystem4_c.MATLABSystem1[i + 1];
    if (BothOptimizedNew_B.maxV_k > u1) {
      BothOptimizedNew_B.maxV_k = u1;
    }

    /* MinMax: '<S48>/Max of Elements13' incorporates:
     *  MATLABSystem: '<S49>/MATLAB System5'
     */
    u1 = BothOptimizedNew_B.MATLABSystem5.MATLABSystem1[i + 1];
    if (maxV > u1) {
      maxV = u1;
    }
  }

  BothOptimizedNew_MATLABSystem1((real_T)BothOptimizedNew_B.CastToDouble[6],
    &BothOptimizedNew_B.MATLABSystem2_c, &BothOptimizedNew_DW.MATLABSystem2_c,
    &BothOptimizedNew_P.MATLABSystem2_c);

  /* MinMax: '<S48>/Max of Elements14' incorporates:
   *  MATLABSystem: '<S48>/MATLAB System2'
   */
  maxV_0 = BothOptimizedNew_B.MATLABSystem2_c.MATLABSystem1[0];

  /* MinMax: '<S48>/Max of Elements15' incorporates:
   *  MATLABSystem: '<S49>/MATLAB System6'
   */
  BothOptimizedNew_B.maxV = BothOptimizedNew_B.MATLABSystem6.MATLABSystem1[0];
  for (i = 0; i < 24; i++) {
    /* MinMax: '<S48>/Max of Elements14' incorporates:
     *  MATLABSystem: '<S48>/MATLAB System2'
     */
    u1 = BothOptimizedNew_B.MATLABSystem2_c.MATLABSystem1[i + 1];
    if (maxV_0 > u1) {
      maxV_0 = u1;
    }

    /* MinMax: '<S48>/Max of Elements15' incorporates:
     *  MATLABSystem: '<S49>/MATLAB System6'
     */
    u1 = BothOptimizedNew_B.MATLABSystem6.MATLABSystem1[i + 1];
    if (BothOptimizedNew_B.maxV > u1) {
      BothOptimizedNew_B.maxV = u1;
    }
  }

  /* MinMax: '<S48>/Max of Elements8' */
  u1 = fmod(floor(BothOptimizedNew_B.minV), 65536.0);

  /* DataStoreWrite: '<S44>/ADC_L Write' incorporates:
   *  MinMax: '<S48>/Max of Elements8'
   */
  ADC_L[0] = (uint16_T)(u1 < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-u1 :
                        (int32_T)(uint16_T)u1);

  /* MinMax: '<S48>/Max of Elements9' */
  u1 = fmod(floor(minV), 65536.0);

  /* DataStoreWrite: '<S44>/ADC_L Write' incorporates:
   *  MinMax: '<S48>/Max of Elements9'
   */
  ADC_L[1] = (uint16_T)(u1 < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-u1 :
                        (int32_T)(uint16_T)u1);

  /* MinMax: '<S48>/Max of Elements10' */
  u1 = fmod(floor(BothOptimizedNew_B.maxV_m), 65536.0);

  /* DataStoreWrite: '<S44>/ADC_L Write' incorporates:
   *  MinMax: '<S48>/Max of Elements10'
   */
  ADC_L[2] = (uint16_T)(u1 < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-u1 :
                        (int32_T)(uint16_T)u1);

  /* MinMax: '<S48>/Max of Elements11' */
  u1 = fmod(floor(BothOptimizedNew_B.maxV_c), 65536.0);

  /* DataStoreWrite: '<S44>/ADC_L Write' incorporates:
   *  MinMax: '<S48>/Max of Elements11'
   */
  ADC_L[3] = (uint16_T)(u1 < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-u1 :
                        (int32_T)(uint16_T)u1);

  /* MinMax: '<S48>/Max of Elements12' */
  u1 = fmod(floor(BothOptimizedNew_B.maxV_k), 65536.0);

  /* DataStoreWrite: '<S44>/ADC_L Write' incorporates:
   *  MinMax: '<S48>/Max of Elements12'
   */
  ADC_L[4] = (uint16_T)(u1 < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-u1 :
                        (int32_T)(uint16_T)u1);

  /* MinMax: '<S48>/Max of Elements13' */
  u1 = fmod(floor(maxV), 65536.0);

  /* DataStoreWrite: '<S44>/ADC_L Write' incorporates:
   *  MinMax: '<S48>/Max of Elements13'
   */
  ADC_L[5] = (uint16_T)(u1 < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-u1 :
                        (int32_T)(uint16_T)u1);

  /* MinMax: '<S48>/Max of Elements14' */
  u1 = fmod(floor(maxV_0), 65536.0);

  /* DataStoreWrite: '<S44>/ADC_L Write' incorporates:
   *  MinMax: '<S48>/Max of Elements14'
   */
  ADC_L[6] = (uint16_T)(u1 < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-u1 :
                        (int32_T)(uint16_T)u1);

  /* MinMax: '<S48>/Max of Elements15' */
  u1 = fmod(floor(BothOptimizedNew_B.maxV), 65536.0);

  /* DataStoreWrite: '<S44>/ADC_L Write' incorporates:
   *  Constant: '<S44>/Constant1'
   *  MinMax: '<S48>/Max of Elements15'
   */
  ADC_L[7] = (uint16_T)(u1 < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-u1 :
                        (int32_T)(uint16_T)u1);
  ADC_L[8] = BothOptimizedNew_P.Constant1_Value_c;

  /* MATLABSystem: '<S67>/Digital Port Read' */
  pinReadLoc = LL_GPIO_ReadInputPort(GPIOB);

  /* Logic: '<S9>/NOT1' incorporates:
   *  MATLABSystem: '<S67>/Digital Port Read'
   * */
  NOT1 = ((pinReadLoc & 4U) == 0U);

  /* MATLABSystem: '<S65>/Digital Port Read' */
  pinReadLoc = LL_GPIO_ReadInputPort(GPIOE);

  /* Logic: '<S9>/NOT' incorporates:
   *  MATLABSystem: '<S65>/Digital Port Read'
   * */
  NOT = ((pinReadLoc & 64U) == 0U);

  /* Chart: '<Root>/HelloMicroMouse!' */
  if (BothOptimizedNew_DW.temporalCounter_i1 < 63) {
    BothOptimizedNew_DW.temporalCounter_i1++;
  }

  if (BothOptimizedNew_DW.bitsForTID0.is_active_c2_BothOptimizedNew == 0) {
    BothOptimizedNew_DW.bitsForTID0.is_active_c2_BothOptimizedNew = 1U;
    BothOptimizedNew_DW.bitsForTID0.is_c2_BothOptimizedNew =
      Both_IN_WaitUntilButtonPressed6;
    BothOptimizedNew_B.LED_FWD_LEFT = false;
    BothOptimizedNew_B.LED_FWD_RIGHT = false;
    BothOptimizedNew_B.LED_LEFT = false;
    BothOptimizedNew_B.LED_RIGHT = false;
    BothOptimizedNew_B.LED_DOWN_RIGHT = false;
    BothOptimizedNew_B.LED_DOWN_LEFT = false;
  } else {
    switch (BothOptimizedNew_DW.bitsForTID0.is_c2_BothOptimizedNew) {
     case BothOptimi_IN_Calibration_Down1:
      BothOptimizedNew_B.LED_LEFT = false;
      BothOptimizedNew_B.LED_RIGHT = false;
      BothOptimizedNew_B.LED_FWD_LEFT = true;
      BothOptimizedNew_B.LED_FWD_RIGHT = true;
      BothOptimizedNew_B.LED_DOWN_RIGHT = true;
      BothOptimizedNew_B.LED_DOWN_LEFT = true;
      if (BothOptimizedNew_DW.temporalCounter_i1 >= 50) {
        BothOptimizedNew_DW.bitsForTID0.is_c2_BothOptimizedNew =
          BothOptimizedNew_IN_Ready2;
        BothOptimizedNew_B.rightWheel = 0.0;
        BothOptimizedNew_B.leftWheel = 0.0;
        BothOptimizedNew_B.LED2 = true;
        BothOptimizedNew_B.LED0 = true;
        BothOptimizedNew_B.LED1 = true;
        memset(&BothOptimizedNew_DW.SolvedAlgorithm[0], 0, 100U * sizeof(real_T));
        BothOptimizedNew_DW.index = 1.0;
      } else {
        if (BothOptimizedNew_DW.DOWN_R_DARK > BothOptimizedNew_B.Flip[2]) {
          BothOptimizedNew_DW.DOWN_R_DARK = BothOptimizedNew_B.Flip[2];
        }

        if (BothOptimizedNew_DW.DOWN_L_DARK > BothOptimizedNew_B.Flip[5]) {
          BothOptimizedNew_DW.DOWN_L_DARK = BothOptimizedNew_B.Flip[5];
        }

        if (BothOptimizedNew_DW.DOWN_R_LIGHT < BothOptimizedNew_B.Flip[2]) {
          BothOptimizedNew_DW.DOWN_R_LIGHT = BothOptimizedNew_B.Flip[2];
        }

        if (BothOptimizedNew_DW.DOWN_L_LIGHT < BothOptimizedNew_B.Flip[5]) {
          BothOptimizedNew_DW.DOWN_L_LIGHT = BothOptimizedNew_B.Flip[5];
        }
      }
      break;

     case BothOpt_IN_Calibration_Forward1:
      BothOptimizedNew_B.LED_LEFT = false;
      BothOptimizedNew_B.LED_RIGHT = false;
      BothOptimizedNew_B.LED_FWD_LEFT = true;
      BothOptimizedNew_B.LED_FWD_RIGHT = true;
      BothOptimizedNew_B.LED_DOWN_RIGHT = true;
      BothOptimizedNew_B.LED_DOWN_LEFT = true;
      if (NOT) {
        u1 = rt_roundd((real_T)BothOptimizedNew_DW.sum_FWD_LEFT /
                       BothOptimizedNew_DW.counter);
        if (u1 < 65536.0) {
          if (u1 >= 0.0) {
            BothOptimizedNew_DW.init_FWD_LEFT = (uint16_T)u1;
          } else {
            BothOptimizedNew_DW.init_FWD_LEFT = 0U;
          }
        } else {
          BothOptimizedNew_DW.init_FWD_LEFT = MAX_uint16_T;
        }

        u1 = rt_roundd((real_T)BothOptimizedNew_DW.sum_FWD_RIGHT /
                       BothOptimizedNew_DW.counter);
        if (u1 < 65536.0) {
          if (u1 >= 0.0) {
            BothOptimizedNew_DW.init_FWD_RIGHT = (uint16_T)u1;
          } else {
            BothOptimizedNew_DW.init_FWD_RIGHT = 0U;
          }
        } else {
          BothOptimizedNew_DW.init_FWD_RIGHT = MAX_uint16_T;
        }

        BothOptimizedNew_B.LED1 = false;
        BothOptimizedNew_DW.temporalCounter_i1 = 0U;
        BothOptimizedNew_DW.bitsForTID0.is_c2_BothOptimizedNew =
          BothOptimi_IN_Calibration_Down1;
        BothOptimizedNew_B.LED2 = true;
        BothOptimizedNew_B.rightWheel = 75.0;
        BothOptimizedNew_B.leftWheel = -75.0;
        BothOptimizedNew_DW.DOWN_R_DARK = BothOptimizedNew_B.Flip[2];
        BothOptimizedNew_DW.DOWN_L_DARK = BothOptimizedNew_B.Flip[5];
        BothOptimizedNew_DW.DOWN_R_LIGHT = BothOptimizedNew_B.Flip[2];
        BothOptimizedNew_DW.DOWN_L_LIGHT = BothOptimizedNew_B.Flip[5];
      } else if (BothOptimizedNew_DW.counter < 8000.0) {
        pinReadLoc = (uint32_T)BothOptimizedNew_DW.sum_FWD_LEFT +
          BothOptimizedNew_B.Flip[6];
        if (pinReadLoc > 65535U) {
          pinReadLoc = 65535U;
        }

        BothOptimizedNew_DW.sum_FWD_LEFT = (uint16_T)pinReadLoc;
        pinReadLoc = (uint32_T)BothOptimizedNew_DW.sum_FWD_RIGHT +
          BothOptimizedNew_B.Flip[1];
        if (pinReadLoc > 65535U) {
          pinReadLoc = 65535U;
        }

        BothOptimizedNew_DW.sum_FWD_RIGHT = (uint16_T)pinReadLoc;
        BothOptimizedNew_DW.counter++;
      }
      break;

     case B_IN_Calibration_Left_and_Right:
      BothOptimizedNew_B.LED_LEFT = true;
      BothOptimizedNew_B.LED_RIGHT = true;
      BothOptimizedNew_B.LED_FWD_LEFT = false;
      BothOptimizedNew_B.LED_FWD_RIGHT = false;
      BothOptimizedNew_B.LED_DOWN_RIGHT = false;
      BothOptimizedNew_B.LED_DOWN_LEFT = false;
      if (NOT1) {
        BothOptimizedNew_DW.bitsForTID0.is_c2_BothOptimizedNew =
          BothOpt_IN_Calibration_Forward1;
        BothOptimizedNew_B.LED0 = false;
        BothOptimizedNew_B.LED1 = true;
        BothOptimizedNew_B.LED2 = false;
        BothOptimizedNew_B.LED_LEFT = false;
        BothOptimizedNew_B.LED_RIGHT = false;
        BothOptimizedNew_B.LED_FWD_LEFT = true;
        BothOptimizedNew_B.LED_FWD_RIGHT = true;
        BothOptimizedNew_B.LED_DOWN_RIGHT = true;
        BothOptimizedNew_B.LED_DOWN_LEFT = true;
        BothOptimizedNew_DW.counter = 0.0;
        BothOptimizedNew_DW.sum_FWD_LEFT = 0U;
        BothOptimizedNew_DW.sum_FWD_RIGHT = 0U;
      } else if (BothOptimizedNew_DW.counter2 < 8000.0) {
        pinReadLoc = (uint32_T)BothOptimizedNew_DW.sum_LEFT +
          BothOptimizedNew_B.Flip[4];
        if (pinReadLoc > 65535U) {
          pinReadLoc = 65535U;
        }

        BothOptimizedNew_DW.sum_LEFT = (uint16_T)pinReadLoc;
        pinReadLoc = (uint32_T)BothOptimizedNew_DW.sum_RIGHT +
          BothOptimizedNew_B.Flip[3];
        if (pinReadLoc > 65535U) {
          pinReadLoc = 65535U;
        }

        BothOptimizedNew_DW.sum_RIGHT = (uint16_T)pinReadLoc;
        BothOptimizedNew_DW.counter2++;
      }
      break;

     case BothOptimizedNew_IN_CrossRoad:
      BothOptimizedNew_CrossRoad(&NOT1);
      break;

     case BothOptimizedN_IN_LineFollowing:
      BothOptimizedNew_LineFollowing(&NOT);
      break;

     case BothOptimizedNew_IN_Optimised:
      BothOptimizedNew_Optimised();
      break;

     case BothOptimizedNe_IN_Placeholder2:
      if (NOT1) {
        BothOptimizedNew_DW.temporalCounter_i1 = 0U;
        BothOptimizedNew_DW.bitsForTID0.is_c2_BothOptimizedNew =
          BothOptimizedN_IN_LineFollowing;
        BothOptimizedNew_B.LED0 = false;
        BothOptimizedNew_B.LED2 = false;
        BothOptimizedNew_B.LED_LEFT = false;
        BothOptimizedNew_B.LED_RIGHT = false;
        BothOptimizedNew_B.LED_FWD_LEFT = true;
        BothOptimizedNew_B.LED_FWD_RIGHT = true;
        BothOptimizedNew_B.LED_DOWN_RIGHT = true;
        BothOptimizedNew_B.LED_DOWN_LEFT = true;
        BothOptimizedNew_DW.bitsForTID0.is_LineFollowing =
          BothOptimizedNew_IN_Forward;
        BothOptimizedNew_B.LED1 = true;
        BothOptimizedNew_B.leftWheel = 80.0;
        BothOptimizedNew_B.rightWheel = 80.0;
      } else {
        BothOptimizedNew_B.LED1 = !BothOptimizedNew_B.LED1;
      }
      break;

     case BothOptimizedNew_IN_Ready2:
      if (NOT) {
        BothOptimizedNew_DW.temporalCounter_i1 = 0U;
        BothOptimizedNew_DW.bitsForTID0.is_c2_BothOptimizedNew =
          BothOptimizedN_IN_LineFollowing;
        BothOptimizedNew_B.LED0 = false;
        BothOptimizedNew_B.LED2 = false;
        BothOptimizedNew_B.LED_LEFT = false;
        BothOptimizedNew_B.LED_RIGHT = false;
        BothOptimizedNew_B.LED_FWD_LEFT = true;
        BothOptimizedNew_B.LED_FWD_RIGHT = true;
        BothOptimizedNew_B.LED_DOWN_RIGHT = true;
        BothOptimizedNew_B.LED_DOWN_LEFT = true;
        BothOptimizedNew_DW.bitsForTID0.is_LineFollowing =
          BothOptimizedNew_IN_Forward;
        BothOptimizedNew_B.LED1 = true;
        BothOptimizedNew_B.leftWheel = 80.0;
        BothOptimizedNew_B.rightWheel = 80.0;
      }
      break;

     case BothOptimizedNew_IN_Turns:
      BothOptimizedNew_Turns(&NOT1, &NOT);
      break;

     default:
      /* case IN_WaitUntilButtonPressed6: */
      BothOptimizedNew_B.LED_FWD_LEFT = false;
      BothOptimizedNew_B.LED_FWD_RIGHT = false;
      BothOptimizedNew_B.LED_LEFT = false;
      BothOptimizedNew_B.LED_RIGHT = false;
      BothOptimizedNew_B.LED_DOWN_RIGHT = false;
      BothOptimizedNew_B.LED_DOWN_LEFT = false;
      if (NOT) {
        BothOptimizedNew_DW.bitsForTID0.is_c2_BothOptimizedNew =
          B_IN_Calibration_Left_and_Right;
        BothOptimizedNew_B.LED0 = true;
        BothOptimizedNew_B.LED1 = false;
        BothOptimizedNew_B.LED2 = false;
        BothOptimizedNew_B.LED_LEFT = true;
        BothOptimizedNew_B.LED_RIGHT = true;
        BothOptimizedNew_DW.counter2 = 0.0;
        BothOptimizedNew_DW.sum_LEFT = 0U;
        BothOptimizedNew_DW.sum_RIGHT = 0U;
      } else {
        BothOptimizedNew_B.LED1 = !BothOptimizedNew_B.LED1;
      }
      break;
    }
  }

  /* End of Chart: '<Root>/HelloMicroMouse!' */

  /* Outputs for Atomic SubSystem: '<Root>/GPIO for IR LEDs' */
  /* MATLABSystem: '<S19>/Digital Port Write' */
  BothOptimizedNew_B.portNameLoc = GPIOE;
  if (BothOptimizedNew_B.LED_DOWN_LEFT) {
    i = 512;
  } else {
    i = 0;
  }

  LL_GPIO_SetOutputPin(BothOptimizedNew_B.portNameLoc, (uint32_T)i);
  LL_GPIO_ResetOutputPin(BothOptimizedNew_B.portNameLoc, ~(uint32_T)i & 512U);

  /* End of MATLABSystem: '<S19>/Digital Port Write' */

  /* MATLABSystem: '<S21>/Digital Port Write' */
  BothOptimizedNew_B.portNameLoc = GPIOE;
  if (BothOptimizedNew_B.LED_DOWN_RIGHT) {
    i = 16384;
  } else {
    i = 0;
  }

  LL_GPIO_SetOutputPin(BothOptimizedNew_B.portNameLoc, (uint32_T)i);
  LL_GPIO_ResetOutputPin(BothOptimizedNew_B.portNameLoc, ~(uint32_T)i & 16384U);

  /* End of MATLABSystem: '<S21>/Digital Port Write' */

  /* MATLABSystem: '<S23>/Digital Port Write' */
  BothOptimizedNew_B.portNameLoc = GPIOE;
  if (BothOptimizedNew_B.LED_FWD_LEFT) {
    i = 256;
  } else {
    i = 0;
  }

  LL_GPIO_SetOutputPin(BothOptimizedNew_B.portNameLoc, (uint32_T)i);
  LL_GPIO_ResetOutputPin(BothOptimizedNew_B.portNameLoc, ~(uint32_T)i & 256U);

  /* End of MATLABSystem: '<S23>/Digital Port Write' */

  /* MATLABSystem: '<S25>/Digital Port Write' */
  BothOptimizedNew_B.portNameLoc = GPIOE;
  if (BothOptimizedNew_B.LED_FWD_RIGHT) {
    i = 32768;
  } else {
    i = 0;
  }

  LL_GPIO_SetOutputPin(BothOptimizedNew_B.portNameLoc, (uint32_T)i);
  LL_GPIO_ResetOutputPin(BothOptimizedNew_B.portNameLoc, ~(uint32_T)i & 32768U);

  /* End of MATLABSystem: '<S25>/Digital Port Write' */

  /* MATLABSystem: '<S27>/Digital Port Write' */
  BothOptimizedNew_B.portNameLoc = GPIOE;
  if (BothOptimizedNew_B.LED_LEFT) {
    i = 4096;
  } else {
    i = 0;
  }

  LL_GPIO_SetOutputPin(BothOptimizedNew_B.portNameLoc, (uint32_T)i);
  LL_GPIO_ResetOutputPin(BothOptimizedNew_B.portNameLoc, ~(uint32_T)i & 4096U);

  /* End of MATLABSystem: '<S27>/Digital Port Write' */

  /* MATLABSystem: '<S29>/Digital Port Write' */
  BothOptimizedNew_B.portNameLoc = GPIOB;
  LL_GPIO_SetOutputPin(BothOptimizedNew_B.portNameLoc, 0U);
  LL_GPIO_ResetOutputPin(BothOptimizedNew_B.portNameLoc, 4096U);

  /* MATLABSystem: '<S31>/Digital Port Write' */
  BothOptimizedNew_B.portNameLoc = GPIOE;
  LL_GPIO_SetOutputPin(BothOptimizedNew_B.portNameLoc, 0U);
  LL_GPIO_ResetOutputPin(BothOptimizedNew_B.portNameLoc, 8192U);

  /* MATLABSystem: '<S33>/Digital Port Write' */
  BothOptimizedNew_B.portNameLoc = GPIOE;
  if (BothOptimizedNew_B.LED_RIGHT) {
    i = 2048;
  } else {
    i = 0;
  }

  LL_GPIO_SetOutputPin(BothOptimizedNew_B.portNameLoc, (uint32_T)i);
  LL_GPIO_ResetOutputPin(BothOptimizedNew_B.portNameLoc, ~(uint32_T)i & 2048U);

  /* End of MATLABSystem: '<S33>/Digital Port Write' */
  /* End of Outputs for SubSystem: '<Root>/GPIO for IR LEDs' */

  /* Switch: '<S5>/Switch3' incorporates:
   *  Constant: '<S5>/Constant2'
   */
  if (BothOptimizedNew_B.rightWheel > BothOptimizedNew_P.Switch3_Threshold) {
    u1 = BothOptimizedNew_P.Constant2_Value;
  } else {
    u1 = BothOptimizedNew_B.rightWheel;
  }

  /* MATLABSystem: '<S42>/PWM Output' incorporates:
   *  Abs: '<S5>/Abs1'
   *  Switch: '<S5>/Switch3'
   */
  setDutyCycleInPercentageChannel1(BothOptimizedNew_DW.obj_g.TimerHandle, fabs
    (u1));

  /* Switch: '<S5>/Switch2' incorporates:
   *  Constant: '<S5>/Constant2'
   */
  if (BothOptimizedNew_B.rightWheel > BothOptimizedNew_P.Switch2_Threshold) {
    u1 = BothOptimizedNew_B.rightWheel;
  } else {
    u1 = BothOptimizedNew_P.Constant2_Value;
  }

  /* MATLABSystem: '<S42>/PWM Output' incorporates:
   *  Switch: '<S5>/Switch2'
   */
  setDutyCycleInPercentageChannel2(BothOptimizedNew_DW.obj_g.TimerHandle, u1);

  /* Switch: '<S5>/Switch1' incorporates:
   *  Constant: '<S5>/Constant1'
   */
  if (BothOptimizedNew_B.leftWheel > BothOptimizedNew_P.Switch1_Threshold) {
    u1 = BothOptimizedNew_P.Constant1_Value;
  } else {
    u1 = BothOptimizedNew_B.leftWheel;
  }

  /* MATLABSystem: '<S40>/PWM Output' incorporates:
   *  Abs: '<S5>/Abs'
   *  Switch: '<S5>/Switch1'
   */
  setDutyCycleInPercentageChannel3(BothOptimizedNew_DW.obj_n.TimerHandle, fabs
    (u1));

  /* Switch: '<S5>/Switch' incorporates:
   *  Constant: '<S5>/Constant1'
   */
  if (BothOptimizedNew_B.leftWheel > BothOptimizedNew_P.Switch_Threshold) {
    u1 = BothOptimizedNew_B.leftWheel;
  } else {
    u1 = BothOptimizedNew_P.Constant1_Value;
  }

  /* MATLABSystem: '<S40>/PWM Output' incorporates:
   *  Switch: '<S5>/Switch'
   */
  setDutyCycleInPercentageChannel4(BothOptimizedNew_DW.obj_n.TimerHandle, u1);

  /* MATLABSystem: '<S38>/Digital Port Write' incorporates:
   *  Constant: '<S5>/Constant'
   */
  BothOptimizedNew_B.portNameLoc = GPIOD;
  if (BothOptimizedNew_P.Constant_Value != 0.0) {
    i = 128;
  } else {
    i = 0;
  }

  LL_GPIO_SetOutputPin(BothOptimizedNew_B.portNameLoc, (uint32_T)i);
  LL_GPIO_ResetOutputPin(BothOptimizedNew_B.portNameLoc, ~(uint32_T)i & 128U);

  /* End of MATLABSystem: '<S38>/Digital Port Write' */

  /* MATLABSystem: '<S57>/Digital Port Write' */
  BothOptimizedNew_B.portNameLoc = GPIOC;
  if (BothOptimizedNew_B.LED0) {
    i = 8192;
  } else {
    i = 0;
  }

  LL_GPIO_SetOutputPin(BothOptimizedNew_B.portNameLoc, (uint32_T)i);
  LL_GPIO_ResetOutputPin(BothOptimizedNew_B.portNameLoc, ~(uint32_T)i & 8192U);

  /* End of MATLABSystem: '<S57>/Digital Port Write' */

  /* MATLABSystem: '<S59>/Digital Port Write' */
  BothOptimizedNew_B.portNameLoc = GPIOC;
  if (BothOptimizedNew_B.LED1) {
    i = 16384;
  } else {
    i = 0;
  }

  LL_GPIO_SetOutputPin(BothOptimizedNew_B.portNameLoc, (uint32_T)i);
  LL_GPIO_ResetOutputPin(BothOptimizedNew_B.portNameLoc, ~(uint32_T)i & 16384U);

  /* End of MATLABSystem: '<S59>/Digital Port Write' */

  /* MATLABSystem: '<S61>/Digital Port Write' */
  BothOptimizedNew_B.portNameLoc = GPIOC;
  if (BothOptimizedNew_B.LED2) {
    i = 32768;
  } else {
    i = 0;
  }

  LL_GPIO_SetOutputPin(BothOptimizedNew_B.portNameLoc, (uint32_T)i);
  LL_GPIO_ResetOutputPin(BothOptimizedNew_B.portNameLoc, ~(uint32_T)i & 32768U);

  /* End of MATLABSystem: '<S61>/Digital Port Write' */

  /* MATLABSystem: '<S55>/Digital Port Write' incorporates:
   *  Constant: '<S8>/Constant'
   */
  BothOptimizedNew_B.portNameLoc = GPIOB;
  if (BothOptimizedNew_P.Constant_Value_i != 0.0) {
    i = 8;
  } else {
    i = 0;
  }

  LL_GPIO_SetOutputPin(BothOptimizedNew_B.portNameLoc, (uint32_T)i);
  LL_GPIO_ResetOutputPin(BothOptimizedNew_B.portNameLoc, ~(uint32_T)i & 8U);

  /* End of MATLABSystem: '<S55>/Digital Port Write' */

  /* user code (Update function Body) */

  /* System '<Root>' */
  refreshIMUValues();

  /* System '<Root>' */
  CustomWhile();
}

/* Model initialize function */
void BothOptimizedNew_initialize(void)
{
  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      /* Start for DataStoreMemory: '<S1>/Data Store Memory' */
      Detections[i] = BothOptimizedNew_P.DataStoreMemory_InitialValue_p4;

      /* Start for DataStoreMemory: '<S1>/Data Store Memory1' */
      Thresholds[i] = BothOptimizedNew_P.DataStoreMemory1_InitialValue_j;
    }

    /* Start for DataStoreMemory: '<S1>/Data Store Memory2' */
    currTicksRS = BothOptimizedNew_P.DataStoreMemory2_InitialValue;

    /* Start for DataStoreMemory: '<S1>/Data Store Memory4' */
    currTicksLS = BothOptimizedNew_P.DataStoreMemory4_InitialValue;
    for (i = 0; i < 9; i++) {
      /* Start for DataStoreMemory: '<S6>/Data Store Memory' */
      ADC1s[i] = BothOptimizedNew_P.DataStoreMemory_InitialValue_p;

      /* Start for DataStoreMemory: '<S6>/Data Store Memory1' */
      ADC_H[i] = BothOptimizedNew_P.DataStoreMemory1_InitialValue_p;

      /* Start for DataStoreMemory: '<S6>/Data Store Memory2' */
      ADC_L[i] = BothOptimizedNew_P.DataStoreMemory2_InitialValue_p;
    }

    /* Start for DataStoreMemory: '<S7>/Data Store Memory' */
    IMU_Accel[0] = BothOptimizedNew_P.DataStoreMemory_InitialValue;

    /* Start for DataStoreMemory: '<S7>/Data Store Memory1' */
    IMU_Gyro[0] = BothOptimizedNew_P.DataStoreMemory1_InitialValue;

    /* Start for DataStoreMemory: '<S7>/Data Store Memory' */
    IMU_Accel[1] = BothOptimizedNew_P.DataStoreMemory_InitialValue;

    /* Start for DataStoreMemory: '<S7>/Data Store Memory1' */
    IMU_Gyro[1] = BothOptimizedNew_P.DataStoreMemory1_InitialValue;

    /* Start for DataStoreMemory: '<S7>/Data Store Memory' */
    IMU_Accel[2] = BothOptimizedNew_P.DataStoreMemory_InitialValue;

    /* Start for DataStoreMemory: '<S7>/Data Store Memory1' */
    IMU_Gyro[2] = BothOptimizedNew_P.DataStoreMemory1_InitialValue;

    /* user code (Initialize function Body) */

    /* System '<Root>' */
    initIMU();

    /* Start for MATLABSystem: '<S46>/Analog to Digital Converter' */
    BothOptimizedNew_DW.obj.isInitialized = 0;
    BothOptimizedNew_DW.obj.matlabCodegenIsDeleted = false;
    BothOptimizedN_SystemCore_setup(&BothOptimizedNew_DW.obj);
    BothOptimize_MATLABSystem1_Init(&BothOptimizedNew_DW.MATLABSystem2_ci,
      &BothOptimizedNew_P.MATLABSystem2_ci);
    BothOptimize_MATLABSystem3_Init(&BothOptimizedNew_DW.MATLABSystem4,
      &BothOptimizedNew_P.MATLABSystem4);
    BothOptimize_MATLABSystem1_Init(&BothOptimizedNew_DW.MATLABSystem1,
      &BothOptimizedNew_P.MATLABSystem1);
    BothOptimize_MATLABSystem1_Init(&BothOptimizedNew_DW.MATLABSystem1_ci,
      &BothOptimizedNew_P.MATLABSystem1_ci);
    BothOptimize_MATLABSystem1_Init(&BothOptimizedNew_DW.MATLABSystem3_c,
      &BothOptimizedNew_P.MATLABSystem3_c);
    BothOptimize_MATLABSystem1_Init(&BothOptimizedNew_DW.MATLABSystem4_c,
      &BothOptimizedNew_P.MATLABSystem4_c);
    BothOptimize_MATLABSystem1_Init(&BothOptimizedNew_DW.MATLABSystem5,
      &BothOptimizedNew_P.MATLABSystem5);
    BothOptimize_MATLABSystem3_Init(&BothOptimizedNew_DW.MATLABSystem3,
      &BothOptimizedNew_P.MATLABSystem3);
    BothOptimize_MATLABSystem1_Init(&BothOptimizedNew_DW.MATLABSystem2,
      &BothOptimizedNew_P.MATLABSystem2);
    BothOptimize_MATLABSystem1_Init(&BothOptimizedNew_DW.MATLABSystem6,
      &BothOptimizedNew_P.MATLABSystem6);
    BothOptimize_MATLABSystem1_Init(&BothOptimizedNew_DW.MATLABSystem1_c,
      &BothOptimizedNew_P.MATLABSystem1_c);
    BothOptimize_MATLABSystem1_Init(&BothOptimizedNew_DW.MATLABSystem2_c,
      &BothOptimizedNew_P.MATLABSystem2_c);

    /* Start for MATLABSystem: '<S42>/PWM Output' */
    BothOptimizedNew_DW.obj_g.matlabCodegenIsDeleted = false;
    BothOptimizedNew_DW.obj_g.isSetupComplete = false;
    BothOptimizedNew_DW.obj_g.isInitialized = 1;
    BothOptim_PWMOutput_setupImpl_j(&BothOptimizedNew_DW.obj_g);
    BothOptimizedNew_DW.obj_g.isSetupComplete = true;

    /* Start for MATLABSystem: '<S40>/PWM Output' */
    BothOptimizedNew_DW.obj_n.matlabCodegenIsDeleted = false;
    BothOptimizedNew_DW.obj_n.isSetupComplete = false;
    BothOptimizedNew_DW.obj_n.isInitialized = 1;
    BothOptimiz_PWMOutput_setupImpl(&BothOptimizedNew_DW.obj_n);
    BothOptimizedNew_DW.obj_n.isSetupComplete = true;
  }
}

/* Model terminate function */
void BothOptimizedNew_terminate(void)
{
  /* Terminate for MATLABSystem: '<S46>/Analog to Digital Converter' */
  if (!BothOptimizedNew_DW.obj.matlabCodegenIsDeleted) {
    BothOptimizedNew_DW.obj.matlabCodegenIsDeleted = true;
    if ((BothOptimizedNew_DW.obj.isInitialized == 1) &&
        BothOptimizedNew_DW.obj.isSetupComplete) {
      ADC_Handle_Deinit(BothOptimizedNew_DW.obj.ADCHandle,
                        ADC_DMA_INTERRUPT_MODE, 1);
    }
  }

  /* End of Terminate for MATLABSystem: '<S46>/Analog to Digital Converter' */

  /* Terminate for MATLABSystem: '<S42>/PWM Output' */
  if (!BothOptimizedNew_DW.obj_g.matlabCodegenIsDeleted) {
    BothOptimizedNew_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((BothOptimizedNew_DW.obj_g.isInitialized == 1) &&
        BothOptimizedNew_DW.obj_g.isSetupComplete) {
      disableCounter(BothOptimizedNew_DW.obj_g.TimerHandle);
      disableTimerInterrupts(BothOptimizedNew_DW.obj_g.TimerHandle, 0);
      disableTimerChannel1(BothOptimizedNew_DW.obj_g.TimerHandle, ENABLE_CH);
      disableTimerChannel2(BothOptimizedNew_DW.obj_g.TimerHandle, ENABLE_CH);
    }
  }

  /* End of Terminate for MATLABSystem: '<S42>/PWM Output' */

  /* Terminate for MATLABSystem: '<S40>/PWM Output' */
  if (!BothOptimizedNew_DW.obj_n.matlabCodegenIsDeleted) {
    BothOptimizedNew_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((BothOptimizedNew_DW.obj_n.isInitialized == 1) &&
        BothOptimizedNew_DW.obj_n.isSetupComplete) {
      disableCounter(BothOptimizedNew_DW.obj_n.TimerHandle);
      disableTimerInterrupts(BothOptimizedNew_DW.obj_n.TimerHandle, 0);
      disableTimerChannel3(BothOptimizedNew_DW.obj_n.TimerHandle, ENABLE_CH);
      disableTimerChannel4(BothOptimizedNew_DW.obj_n.TimerHandle, ENABLE_CH);
    }
  }

  /* End of Terminate for MATLABSystem: '<S40>/PWM Output' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
