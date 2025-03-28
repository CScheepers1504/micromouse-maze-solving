/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: MicroMouseTemplate.c
 *
 * Code generated for Simulink model 'MicroMouseTemplate'.
 *
 * Model version                  : 3.11
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Wed Oct 16 21:00:45 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "MicroMouseTemplate.h"
#include "rtwtypes.h"
#include "MicroMouseTemplate_types.h"
#include "MicroMouseTemplate_private.h"
#include <string.h>
#include <math.h>
#include "stm_timer_ll.h"
#include "stm_adc_ll.h"

/* Named constants for Chart: '<Root>/HelloMicroMouse!' */
#define Mic_IN_Turning_Right_Adjustment ((uint8_T)3U)
#define Micr_IN_CalibrationDownAndSides ((uint8_T)2U)
#define Micr_IN_Turning_Left_Adjustment ((uint8_T)2U)
#define MicroMous_IN_CalibrationForward ((uint8_T)3U)
#define MicroMouseTe_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define MicroMouseTem_IN_ButtonPressed3 ((uint8_T)1U)
#define MicroMouseTem_IN_CrossDetection ((uint8_T)1U)
#define MicroMouseTemplate_IN_Driving  ((uint8_T)2U)
#define MicroMouseTemplate_IN_Forward  ((uint8_T)1U)
#define MicroMouseTemplate_IN_Ready1   ((uint8_T)4U)
#define MicroMouseTemplate_IN_turnBack ((uint8_T)3U)
#define MicroMouseTemplate_IN_turnLeft ((uint8_T)4U)
#define MicroMouseTemplate_IN_turnRight ((uint8_T)5U)
#define Micro_IN_WaitUntilButtonPressed ((uint8_T)5U)

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
B_MicroMouseTemplate_T MicroMouseTemplate_B;

/* Block states (default storage) */
DW_MicroMouseTemplate_T MicroMouseTemplate_DW;

/* Real-time model */
static RT_MODEL_MicroMouseTemplate_T MicroMouseTemplate_M_;
RT_MODEL_MicroMouseTemplate_T *const MicroMouseTemplate_M =
  &MicroMouseTemplate_M_;

/* Forward declaration for local functions */
static void MicroMouseTempla_ButtonPressed3(const uint32_T *Gain);
static void MicroMouseTemp_SystemCore_setup(stm32cube_blocks_AnalogInput__T *obj);
static void MicroMous_PWMOutput_setupImpl_d(stm32cube_blocks_PWMOutput_Mi_T *obj);
static void MicroMouseT_PWMOutput_setupImpl(stm32cube_blocks_PWMOutput_Mi_T *obj);
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void MicroMouseTemplate_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(MicroMouseTemplate_M, 1));
  eventFlags[2] = ((boolean_T)rtmStepTask(MicroMouseTemplate_M, 2));
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 1 shares data with slower tid rate: 2 */
  if (MicroMouseTemplate_M->Timing.TaskCounters.TID[1] == 0) {
    MicroMouseTemplate_M->Timing.RateInteraction.TID1_2 =
      (MicroMouseTemplate_M->Timing.TaskCounters.TID[2] == 0);
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (MicroMouseTemplate_M->Timing.TaskCounters.TID[1])++;
  if ((MicroMouseTemplate_M->Timing.TaskCounters.TID[1]) > 1) {/* Sample time: [0.05s, 0.0s] */
    MicroMouseTemplate_M->Timing.TaskCounters.TID[1] = 0;
  }

  (MicroMouseTemplate_M->Timing.TaskCounters.TID[2])++;
  if ((MicroMouseTemplate_M->Timing.TaskCounters.TID[2]) > 3) {/* Sample time: [0.1s, 0.0s] */
    MicroMouseTemplate_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/* System initialize for atomic system: */
void MicroMou_MATLABSystem1_Init(DW_MATLABSystem1_MicroMouseTe_T *localDW,
  P_MATLABSystem1_MicroMouseTem_T *localP)
{
  int32_T i;

  /* Start for MATLABSystem: '<S51>/MATLAB System1' */
  localDW->objisempty = true;
  localDW->obj.InitialCondition = localP->MATLABSystem1_InitialCondition;
  localDW->obj.isInitialized = 1;

  /*  Number of inputs */
  /*  Initialize the buffer during the first call */
  for (i = 0; i < 25; i++) {
    localDW->obj.Buffer[i] = localDW->obj.InitialCondition;
  }

  /* End of Start for MATLABSystem: '<S51>/MATLAB System1' */
}

/* Output and update for atomic system: */
void MicroMouseTem_MATLABSystem1(real_T rtu_0, B_MATLABSystem1_MicroMouseTem_T
  *localB, DW_MATLABSystem1_MicroMouseTe_T *localDW,
  P_MATLABSystem1_MicroMouseTem_T *localP)
{
  /* MATLABSystem: '<S51>/MATLAB System1' */
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

  /* End of MATLABSystem: '<S51>/MATLAB System1' */
}

/* System initialize for atomic system: */
void MicroMou_MATLABSystem3_Init(DW_MATLABSystem3_MicroMouseTe_T *localDW,
  P_MATLABSystem3_MicroMouseTem_T *localP)
{
  int32_T i;

  /* Start for MATLABSystem: '<S51>/MATLAB System3' */
  localDW->objisempty = true;
  localDW->obj.InitialCondition = localP->MATLABSystem3_InitialCondition;
  localDW->obj.isInitialized = 1;

  /*  Number of inputs */
  /*  Initialize the buffer during the first call */
  for (i = 0; i < 10; i++) {
    localDW->obj.Buffer[i] = localDW->obj.InitialCondition;
  }

  /* End of Start for MATLABSystem: '<S51>/MATLAB System3' */
}

/* Output and update for atomic system: */
void MicroMouseTem_MATLABSystem3(real_T rtu_0, B_MATLABSystem3_MicroMouseTem_T
  *localB, DW_MATLABSystem3_MicroMouseTe_T *localDW,
  P_MATLABSystem3_MicroMouseTem_T *localP)
{
  /* MATLABSystem: '<S51>/MATLAB System3' */
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

  /* End of MATLABSystem: '<S51>/MATLAB System3' */
}

/* Function for Chart: '<Root>/HelloMicroMouse!' */
static void MicroMouseTempla_ButtonPressed3(const uint32_T *Gain)
{
  boolean_T guard1;
  boolean_T tmp;
  boolean_T tmp_0;
  boolean_T tmp_1;
  guard1 = false;
  switch (MicroMouseTemplate_DW.bitsForTID1.is_ButtonPressed3) {
   case MicroMouseTem_IN_CrossDetection:
    if ((MicroMouseTemplate_DW.crossroadCondition == 7.0) ||
        (MicroMouseTemplate_DW.crossroadCondition == 1.0)) {
      MicroMouseTemplate_DW.bitsForTID1.is_ButtonPressed3 =
        MicroMouseTemplate_IN_Driving;
      MicroMouseTemplate_DW.timer = 0.0;
      MicroMouseTemplate_DW.bitsForTID1.is_Driving =
        MicroMouseTemplate_IN_Forward;
      MicroMouseTemplate_B.LED0 = false;
      MicroMouseTemplate_B.LED1 = false;
      MicroMouseTemplate_B.LED2 = false;
      MicroMouseTemplate_B.leftWheel_k = MicroMouseTemplate_DW.normal_speed_LEFT;
      MicroMouseTemplate_B.rightWheel_f =
        MicroMouseTemplate_DW.normal_speed_RIGHT;
    } else if (MicroMouseTemplate_DW.crossroadCondition == 3.0) {
      guard1 = true;
    } else if (MicroMouseTemplate_DW.crossroadCondition == 4.0) {
      MicroMouseTemplate_DW.temporalCounter_i1 = 0U;
      MicroMouseTemplate_DW.bitsForTID1.is_ButtonPressed3 =
        MicroMouseTemplate_IN_turnBack;
      MicroMouseTemplate_B.LED0 = false;
      MicroMouseTemplate_B.LED1 = true;
      MicroMouseTemplate_B.LED2 = false;
      MicroMouseTemplate_B.leftWheel_k = -75.0;
      MicroMouseTemplate_B.rightWheel_f = 75.0;
    } else if (MicroMouseTemplate_DW.crossroadCondition == 5.0) {
      guard1 = true;
    } else if (MicroMouseTemplate_DW.crossroadCondition == 2.0) {
      MicroMouseTemplate_DW.temporalCounter_i1 = 0U;
      MicroMouseTemplate_DW.bitsForTID1.is_ButtonPressed3 =
        MicroMouseTemplate_IN_turnRight;
      MicroMouseTemplate_B.LED0 = false;
      MicroMouseTemplate_B.LED1 = false;
      MicroMouseTemplate_B.LED2 = true;
      MicroMouseTemplate_B.leftWheel_k = 85.0;
      MicroMouseTemplate_B.rightWheel_f = 0.0;
    } else if (MicroMouseTemplate_DW.crossroadCondition == 6.0) {
      guard1 = true;
    } else {
      if (MicroMouseTemplate_DW.LEDtimer < 100.0) {
        MicroMouseTemplate_DW.LEDtimer++;
      } else {
        MicroMouseTemplate_DW.LEDtimer = 0.0;
        MicroMouseTemplate_DW.bitsForTID1.leftClear =
          (MicroMouseTemplate_B.Flip[4] < MicroMouseTemplate_DW.thresh_LEFT);
        MicroMouseTemplate_DW.bitsForTID1.rightClear =
          (MicroMouseTemplate_B.Flip[3] < MicroMouseTemplate_DW.thresh_RIGHT);
      }

      MicroMouseTemplate_B.LED_LS = 0.0;
      MicroMouseTemplate_B.LED_RS = 0.0;
      MicroMouseTemplate_B.LED_FWD_RS = 1.0;
      MicroMouseTemplate_B.LED_FWD_LS = 1.0;
      if (MicroMouseTemplate_DW.LEDtimer1 < 100.0) {
        MicroMouseTemplate_DW.LEDtimer1++;
      } else {
        MicroMouseTemplate_DW.LEDtimer = 0.0;
        MicroMouseTemplate_DW.bitsForTID1.frontClear =
          ((MicroMouseTemplate_B.Flip[6] < MicroMouseTemplate_DW.thresh_FWD_L) &&
           (MicroMouseTemplate_B.Flip[1] < MicroMouseTemplate_DW.thresh_FWD_R));
        MicroMouseTemplate_B.LED_FWD_RS = 0.0;
        MicroMouseTemplate_B.LED_FWD_LS = 0.0;
        MicroMouseTemplate_DW.processDone = 1.0;
      }

      if (MicroMouseTemplate_DW.processDone == 1.0) {
        tmp = !MicroMouseTemplate_DW.bitsForTID1.leftClear;
        tmp_0 = !MicroMouseTemplate_DW.bitsForTID1.rightClear;
        if (MicroMouseTemplate_DW.bitsForTID1.frontClear && tmp_0 && tmp) {
          MicroMouseTemplate_DW.crossroadCondition = 1.0;
        } else {
          tmp_1 = !MicroMouseTemplate_DW.bitsForTID1.frontClear;
          if (tmp && MicroMouseTemplate_DW.bitsForTID1.rightClear && tmp_1) {
            MicroMouseTemplate_DW.crossroadCondition = 2.0;
          } else if (tmp_0 && tmp_1 &&
                     MicroMouseTemplate_DW.bitsForTID1.leftClear) {
            MicroMouseTemplate_DW.crossroadCondition = 3.0;
          } else if (tmp && tmp_1 && tmp_0) {
            MicroMouseTemplate_DW.crossroadCondition = 4.0;
          } else if (MicroMouseTemplate_DW.bitsForTID1.rightClear &&
                     MicroMouseTemplate_DW.bitsForTID1.leftClear && tmp_1) {
            MicroMouseTemplate_DW.crossroadCondition = 5.0;
          } else if (MicroMouseTemplate_DW.bitsForTID1.leftClear && tmp_0 &&
                     MicroMouseTemplate_DW.bitsForTID1.frontClear) {
            MicroMouseTemplate_DW.crossroadCondition = 6.0;
          } else {
            MicroMouseTemplate_DW.crossroadCondition = 7.0;
          }
        }
      }
    }
    break;

   case MicroMouseTemplate_IN_Driving:
    /* Gain: '<Root>/Gain' */
    if ((*Gain < ((uint32_T)MicroMouseTemplate_DW.thresh_DOWN_AVG << 16)) &&
        (MicroMouseTemplate_DW.timer >= 25.0)) {
      MicroMouseTemplate_DW.bitsForTID1.is_Driving =
        MicroMouseTe_IN_NO_ACTIVE_CHILD;
      MicroMouseTemplate_DW.bitsForTID1.is_ButtonPressed3 =
        MicroMouseTem_IN_CrossDetection;
      MicroMouseTemplate_B.leftWheel_k = 0.0;
      MicroMouseTemplate_B.rightWheel_f = 0.0;
      MicroMouseTemplate_B.LED0 = true;
      MicroMouseTemplate_B.LED1 = true;
      MicroMouseTemplate_B.LED2 = true;
      MicroMouseTemplate_DW.LEDtimer = 0.0;
      MicroMouseTemplate_DW.LEDtimer1 = 0.0;
      MicroMouseTemplate_DW.processDone = 0.0;
      MicroMouseTemplate_DW.bitsForTID1.frontClear = false;
      MicroMouseTemplate_DW.bitsForTID1.leftClear = false;
      MicroMouseTemplate_DW.bitsForTID1.rightClear = false;
    } else {
      MicroMouseTemplate_DW.timer++;
      switch (MicroMouseTemplate_DW.bitsForTID1.is_Driving) {
       case MicroMouseTemplate_IN_Forward:
        if (MicroMouseTemplate_B.Flip[5] >
            MicroMouseTemplate_DW.thresh_DOWN_LEFT) {
          MicroMouseTemplate_DW.bitsForTID1.is_Driving =
            Mic_IN_Turning_Right_Adjustment;
          MicroMouseTemplate_B.leftWheel_k = 70.0;
          MicroMouseTemplate_B.rightWheel_f = 75.0;
        } else if (MicroMouseTemplate_B.Flip[2] >
                   MicroMouseTemplate_DW.thresh_DOWN_RIGHT) {
          MicroMouseTemplate_DW.bitsForTID1.is_Driving =
            Micr_IN_Turning_Left_Adjustment;
          MicroMouseTemplate_B.rightWheel_f = 70.0;
          MicroMouseTemplate_B.leftWheel_k = 75.0;
        }
        break;

       case Micr_IN_Turning_Left_Adjustment:
        if (MicroMouseTemplate_B.Flip[5] >
            MicroMouseTemplate_DW.thresh_DOWN_LEFT) {
          MicroMouseTemplate_DW.bitsForTID1.is_Driving =
            Mic_IN_Turning_Right_Adjustment;
          MicroMouseTemplate_B.leftWheel_k = 70.0;
          MicroMouseTemplate_B.rightWheel_f = 75.0;
        } else if ((MicroMouseTemplate_B.Flip[2] <
                    MicroMouseTemplate_DW.thresh_DOWN_RIGHT) &&
                   (MicroMouseTemplate_B.Flip[5] <
                    MicroMouseTemplate_DW.thresh_DOWN_LEFT)) {
          MicroMouseTemplate_DW.bitsForTID1.is_Driving =
            MicroMouseTemplate_IN_Forward;
          MicroMouseTemplate_B.LED0 = false;
          MicroMouseTemplate_B.LED1 = false;
          MicroMouseTemplate_B.LED2 = false;
          MicroMouseTemplate_B.leftWheel_k =
            MicroMouseTemplate_DW.normal_speed_LEFT;
          MicroMouseTemplate_B.rightWheel_f =
            MicroMouseTemplate_DW.normal_speed_RIGHT;
        }
        break;

       default:
        /* case IN_Turning_Right_Adjustment: */
        if ((MicroMouseTemplate_B.Flip[2] <
             MicroMouseTemplate_DW.thresh_DOWN_RIGHT) &&
            (MicroMouseTemplate_B.Flip[5] <
             MicroMouseTemplate_DW.thresh_DOWN_LEFT)) {
          MicroMouseTemplate_DW.bitsForTID1.is_Driving =
            MicroMouseTemplate_IN_Forward;
          MicroMouseTemplate_B.LED0 = false;
          MicroMouseTemplate_B.LED1 = false;
          MicroMouseTemplate_B.LED2 = false;
          MicroMouseTemplate_B.leftWheel_k =
            MicroMouseTemplate_DW.normal_speed_LEFT;
          MicroMouseTemplate_B.rightWheel_f =
            MicroMouseTemplate_DW.normal_speed_RIGHT;
        } else if (MicroMouseTemplate_B.Flip[2] >
                   MicroMouseTemplate_DW.thresh_DOWN_RIGHT) {
          MicroMouseTemplate_DW.bitsForTID1.is_Driving =
            Micr_IN_Turning_Left_Adjustment;
          MicroMouseTemplate_B.rightWheel_f = 70.0;
          MicroMouseTemplate_B.leftWheel_k = 75.0;
        }
        break;
      }
    }

    /* End of Gain: '<Root>/Gain' */
    break;

   case MicroMouseTemplate_IN_turnBack:
    if (MicroMouseTemplate_DW.temporalCounter_i1 >= 42U) {
      MicroMouseTemplate_DW.bitsForTID1.is_ButtonPressed3 =
        MicroMouseTemplate_IN_Driving;
      MicroMouseTemplate_DW.timer = 0.0;
      MicroMouseTemplate_DW.bitsForTID1.is_Driving =
        MicroMouseTemplate_IN_Forward;
      MicroMouseTemplate_B.LED0 = false;
      MicroMouseTemplate_B.LED1 = false;
      MicroMouseTemplate_B.LED2 = false;
      MicroMouseTemplate_B.leftWheel_k = MicroMouseTemplate_DW.normal_speed_LEFT;
      MicroMouseTemplate_B.rightWheel_f =
        MicroMouseTemplate_DW.normal_speed_RIGHT;
    }
    break;

   case MicroMouseTemplate_IN_turnLeft:
    if (MicroMouseTemplate_DW.temporalCounter_i1 >= 26U) {
      MicroMouseTemplate_DW.bitsForTID1.is_ButtonPressed3 =
        MicroMouseTemplate_IN_Driving;
      MicroMouseTemplate_DW.timer = 0.0;
      MicroMouseTemplate_DW.bitsForTID1.is_Driving =
        MicroMouseTemplate_IN_Forward;
      MicroMouseTemplate_B.LED0 = false;
      MicroMouseTemplate_B.LED1 = false;
      MicroMouseTemplate_B.LED2 = false;
      MicroMouseTemplate_B.leftWheel_k = MicroMouseTemplate_DW.normal_speed_LEFT;
      MicroMouseTemplate_B.rightWheel_f =
        MicroMouseTemplate_DW.normal_speed_RIGHT;
    }
    break;

   default:
    /* case IN_turnRight: */
    if (MicroMouseTemplate_DW.temporalCounter_i1 >= 26U) {
      MicroMouseTemplate_DW.bitsForTID1.is_ButtonPressed3 =
        MicroMouseTemplate_IN_Driving;
      MicroMouseTemplate_DW.timer = 0.0;
      MicroMouseTemplate_DW.bitsForTID1.is_Driving =
        MicroMouseTemplate_IN_Forward;
      MicroMouseTemplate_B.LED0 = false;
      MicroMouseTemplate_B.LED1 = false;
      MicroMouseTemplate_B.LED2 = false;
      MicroMouseTemplate_B.leftWheel_k = MicroMouseTemplate_DW.normal_speed_LEFT;
      MicroMouseTemplate_B.rightWheel_f =
        MicroMouseTemplate_DW.normal_speed_RIGHT;
    }
    break;
  }

  if (guard1) {
    MicroMouseTemplate_DW.temporalCounter_i1 = 0U;
    MicroMouseTemplate_DW.bitsForTID1.is_ButtonPressed3 =
      MicroMouseTemplate_IN_turnLeft;
    MicroMouseTemplate_B.LED0 = true;
    MicroMouseTemplate_B.LED1 = false;
    MicroMouseTemplate_B.LED2 = false;
    MicroMouseTemplate_B.leftWheel_k = 0.0;
    MicroMouseTemplate_B.rightWheel_f = 85.0;
  }
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

static void MicroMouseTemp_SystemCore_setup(stm32cube_blocks_AnalogInput__T *obj)
{
  ADC_Type_T adcStructLoc;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S50>/Analog to Digital Converter' */
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

static void MicroMous_PWMOutput_setupImpl_d(stm32cube_blocks_PWMOutput_Mi_T *obj)
{
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<S46>/PWM Output' */
  b.PeripheralPtr = TIM3;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S46>/PWM Output' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  enableTimerChannel1(obj->TimerHandle, ENABLE_CH);
  enableTimerChannel2(obj->TimerHandle, ENABLE_CH);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S46>/PWM Output' */
    enableCounter(obj->TimerHandle, false);
  }
}

static void MicroMouseT_PWMOutput_setupImpl(stm32cube_blocks_PWMOutput_Mi_T *obj)
{
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<S44>/PWM Output' */
  b.PeripheralPtr = TIM3;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S44>/PWM Output' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  enableTimerChannel3(obj->TimerHandle, ENABLE_CH);
  enableTimerChannel4(obj->TimerHandle, ENABLE_CH);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S44>/PWM Output' */
    enableCounter(obj->TimerHandle, false);
  }
}

/* Model step function for TID0 */
void MicroMouseTemplate_step0(void)    /* Sample time: [0.025s, 0.0s] */
{
  GPIO_TypeDef * portNameLoc;
  real_T rtb_PulseGenerator10;
  real_T rtb_PulseGenerator9;
  int32_T i;

  {                                    /* Sample time: [0.025s, 0.0s] */
    rate_monotonic_scheduler();
  }

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

  /* DiscretePulseGenerator: '<S4>/Pulse Generator9' */
  rtb_PulseGenerator9 = (MicroMouseTemplate_DW.clockTickCounter <
    MicroMouseTemplate_P.PulseGenerator9_Duty) &&
    (MicroMouseTemplate_DW.clockTickCounter >= 0) ?
    MicroMouseTemplate_P.PulseGenerator9_Amp : 0.0;
  if (MicroMouseTemplate_DW.clockTickCounter >=
      MicroMouseTemplate_P.PulseGenerator9_Period - 1.0) {
    MicroMouseTemplate_DW.clockTickCounter = 0;
  } else {
    MicroMouseTemplate_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<S4>/Pulse Generator9' */

  /* DiscretePulseGenerator: '<S4>/Pulse Generator10' */
  rtb_PulseGenerator10 = (MicroMouseTemplate_DW.clockTickCounter_i <
    MicroMouseTemplate_P.PulseGenerator10_Duty) &&
    (MicroMouseTemplate_DW.clockTickCounter_i >= 0) ?
    MicroMouseTemplate_P.PulseGenerator10_Amp : 0.0;
  if (MicroMouseTemplate_DW.clockTickCounter_i >=
      MicroMouseTemplate_P.PulseGenerator10_Period - 1.0) {
    MicroMouseTemplate_DW.clockTickCounter_i = 0;
  } else {
    MicroMouseTemplate_DW.clockTickCounter_i++;
  }

  /* End of DiscretePulseGenerator: '<S4>/Pulse Generator10' */

  /* Outputs for Atomic SubSystem: '<Root>/GPIO for IR LEDs' */
  /* MATLABSystem: '<S19>/Digital Port Write' */
  portNameLoc = GPIOE;
  if (rtb_PulseGenerator9 != 0.0) {
    i = 512;
  } else {
    i = 0;
  }

  LL_GPIO_SetOutputPin(portNameLoc, (uint32_T)i);
  LL_GPIO_ResetOutputPin(portNameLoc, ~(uint32_T)i & 512U);

  /* End of MATLABSystem: '<S19>/Digital Port Write' */

  /* MATLABSystem: '<S21>/Digital Port Write' */
  portNameLoc = GPIOE;
  if (rtb_PulseGenerator10 != 0.0) {
    i = 16384;
  } else {
    i = 0;
  }

  LL_GPIO_SetOutputPin(portNameLoc, (uint32_T)i);
  LL_GPIO_ResetOutputPin(portNameLoc, ~(uint32_T)i & 16384U);

  /* End of MATLABSystem: '<S21>/Digital Port Write' */

  /* MATLABSystem: '<S29>/Digital Port Write' */
  portNameLoc = GPIOB;
  LL_GPIO_SetOutputPin(portNameLoc, 0U);
  LL_GPIO_ResetOutputPin(portNameLoc, 4096U);

  /* MATLABSystem: '<S31>/Digital Port Write' */
  portNameLoc = GPIOE;
  LL_GPIO_SetOutputPin(portNameLoc, 0U);
  LL_GPIO_ResetOutputPin(portNameLoc, 8192U);

  /* End of Outputs for SubSystem: '<Root>/GPIO for IR LEDs' */

  /* MATLABSystem: '<S42>/Digital Port Write' incorporates:
   *  Constant: '<S5>/Constant'
   */
  portNameLoc = GPIOD;
  if (MicroMouseTemplate_P.Constant_Value != 0.0) {
    i = 128;
  } else {
    i = 0;
  }

  LL_GPIO_SetOutputPin(portNameLoc, (uint32_T)i);
  LL_GPIO_ResetOutputPin(portNameLoc, ~(uint32_T)i & 128U);

  /* End of MATLABSystem: '<S42>/Digital Port Write' */

  /* MATLABSystem: '<S59>/Digital Port Write' incorporates:
   *  Constant: '<S8>/Constant'
   */
  portNameLoc = GPIOB;
  if (MicroMouseTemplate_P.Constant_Value_i != 0.0) {
    i = 8;
  } else {
    i = 0;
  }

  LL_GPIO_SetOutputPin(portNameLoc, (uint32_T)i);
  LL_GPIO_ResetOutputPin(portNameLoc, ~(uint32_T)i & 8U);

  /* End of MATLABSystem: '<S59>/Digital Port Write' */

  /* user code (Update function Body for TID0) */

  /* System '<Root>' */
  refreshIMUValues();

  /* System '<Root>' */
  CustomWhile();
}

/* Model step function for TID1 */
void MicroMouseTemplate_step1(void)    /* Sample time: [0.05s, 0.0s] */
{
  real_T maxV;
  real_T maxV_0;
  real_T maxV_1;
  real_T u1;
  int32_T i;
  uint32_T Gain;
  uint32_T pinReadLoc;
  uint32_T pinReadLoc_0;
  uint16_T rtb_TmpRTBAtMaxofElements7Outpo;
  uint16_T rtb_TmpRTBAtMaxofElementsOutpor;
  int8_T rtPrevAction;
  boolean_T NOT;

  /* MATLABSystem: '<S50>/Analog to Digital Converter' */
  regularReadADCDMA(MicroMouseTemplate_DW.obj.ADCHandle, ADC_TRIGGER_AND_READ,
                    &ADC1s[0]);

  /* RateTransition generated from: '<S51>/Max of Elements' */
  rtb_TmpRTBAtMaxofElementsOutpor =
    MicroMouseTemplate_DW.TmpRTBAtMaxofElementsOutport1_B;

  /* DSPFlip: '<S6>/Flip' incorporates:
   *  MATLABSystem: '<S50>/Analog to Digital Converter'
   */
  MicroMouseTemplate_B.Flip[0] = ADC1s[7];
  MicroMouseTemplate_B.Flip[7] = ADC1s[0];
  MicroMouseTemplate_B.Flip[1] = ADC1s[6];
  MicroMouseTemplate_B.Flip[6] = ADC1s[1];
  MicroMouseTemplate_B.Flip[2] = ADC1s[5];
  MicroMouseTemplate_B.Flip[5] = ADC1s[2];
  MicroMouseTemplate_B.Flip[3] = ADC1s[4];
  MicroMouseTemplate_B.Flip[4] = ADC1s[3];

  /* DataTypeConversion: '<S53>/Cast To Double' */
  for (i = 0; i < 8; i++) {
    MicroMouseTemplate_B.CastToDouble[i] = MicroMouseTemplate_B.Flip[i];
  }

  /* End of DataTypeConversion: '<S53>/Cast To Double' */
  MicroMouseTem_MATLABSystem3((real_T)MicroMouseTemplate_B.CastToDouble[1],
    &MicroMouseTemplate_B.MATLABSystem4, &MicroMouseTemplate_DW.MATLABSystem4,
    &MicroMouseTemplate_P.MATLABSystem4);

  /* MinMax: '<S51>/Max of Elements1' incorporates:
   *  MATLABSystem: '<S51>/MATLAB System4'
   */
  MicroMouseTemplate_B.maxV = MicroMouseTemplate_B.MATLABSystem4.MATLABSystem3[0];
  for (i = 0; i < 9; i++) {
    u1 = MicroMouseTemplate_B.MATLABSystem4.MATLABSystem3[i + 1];
    if (MicroMouseTemplate_B.maxV < u1) {
      MicroMouseTemplate_B.maxV = u1;
    }
  }

  MicroMouseTem_MATLABSystem1(MicroMouseTemplate_B.maxV,
    &MicroMouseTemplate_B.MATLABSystem1, &MicroMouseTemplate_DW.MATLABSystem1,
    &MicroMouseTemplate_P.MATLABSystem1);

  /* End of MinMax: '<S51>/Max of Elements1' */

  /* MinMax: '<S51>/Min' incorporates:
   *  MATLABSystem: '<S51>/MATLAB System1'
   */
  MicroMouseTemplate_B.minV = MicroMouseTemplate_B.MATLABSystem1.MATLABSystem1[0];
  for (i = 0; i < 24; i++) {
    u1 = MicroMouseTemplate_B.MATLABSystem1.MATLABSystem1[i + 1];
    if (MicroMouseTemplate_B.minV > u1) {
      MicroMouseTemplate_B.minV = u1;
    }
  }

  MicroMouseTem_MATLABSystem1((real_T)MicroMouseTemplate_B.CastToDouble[2],
    &MicroMouseTemplate_B.MATLABSystem1_ci,
    &MicroMouseTemplate_DW.MATLABSystem1_ci,
    &MicroMouseTemplate_P.MATLABSystem1_ci);

  /* MinMax: '<S51>/Max of Elements2' incorporates:
   *  MATLABSystem: '<S53>/MATLAB System1'
   */
  MicroMouseTemplate_B.maxV =
    MicroMouseTemplate_B.MATLABSystem1_ci.MATLABSystem1[0];
  for (i = 0; i < 24; i++) {
    u1 = MicroMouseTemplate_B.MATLABSystem1_ci.MATLABSystem1[i + 1];
    if (MicroMouseTemplate_B.maxV < u1) {
      MicroMouseTemplate_B.maxV = u1;
    }
  }

  MicroMouseTem_MATLABSystem1((real_T)MicroMouseTemplate_B.CastToDouble[3],
    &MicroMouseTemplate_B.MATLABSystem3_c,
    &MicroMouseTemplate_DW.MATLABSystem3_c,
    &MicroMouseTemplate_P.MATLABSystem3_c);

  /* MinMax: '<S51>/Max of Elements3' incorporates:
   *  MATLABSystem: '<S53>/MATLAB System3'
   */
  MicroMouseTemplate_B.maxV_m =
    MicroMouseTemplate_B.MATLABSystem3_c.MATLABSystem1[0];
  for (i = 0; i < 24; i++) {
    u1 = MicroMouseTemplate_B.MATLABSystem3_c.MATLABSystem1[i + 1];
    if (MicroMouseTemplate_B.maxV_m < u1) {
      MicroMouseTemplate_B.maxV_m = u1;
    }
  }

  MicroMouseTem_MATLABSystem1((real_T)MicroMouseTemplate_B.CastToDouble[4],
    &MicroMouseTemplate_B.MATLABSystem4_c,
    &MicroMouseTemplate_DW.MATLABSystem4_c,
    &MicroMouseTemplate_P.MATLABSystem4_c);

  /* MinMax: '<S51>/Max of Elements4' incorporates:
   *  MATLABSystem: '<S53>/MATLAB System4'
   */
  maxV = MicroMouseTemplate_B.MATLABSystem4_c.MATLABSystem1[0];
  for (i = 0; i < 24; i++) {
    u1 = MicroMouseTemplate_B.MATLABSystem4_c.MATLABSystem1[i + 1];
    if (maxV < u1) {
      maxV = u1;
    }
  }

  MicroMouseTem_MATLABSystem1((real_T)MicroMouseTemplate_B.CastToDouble[5],
    &MicroMouseTemplate_B.MATLABSystem5, &MicroMouseTemplate_DW.MATLABSystem5,
    &MicroMouseTemplate_P.MATLABSystem5);

  /* MinMax: '<S51>/Max of Elements5' incorporates:
   *  MATLABSystem: '<S53>/MATLAB System5'
   */
  maxV_0 = MicroMouseTemplate_B.MATLABSystem5.MATLABSystem1[0];
  for (i = 0; i < 24; i++) {
    u1 = MicroMouseTemplate_B.MATLABSystem5.MATLABSystem1[i + 1];
    if (maxV_0 < u1) {
      maxV_0 = u1;
    }
  }

  MicroMouseTem_MATLABSystem3((real_T)MicroMouseTemplate_B.CastToDouble[6],
    &MicroMouseTemplate_B.MATLABSystem3, &MicroMouseTemplate_DW.MATLABSystem3,
    &MicroMouseTemplate_P.MATLABSystem3);

  /* MinMax: '<S51>/Max of Elements6' incorporates:
   *  MATLABSystem: '<S51>/MATLAB System3'
   */
  maxV_1 = MicroMouseTemplate_B.MATLABSystem3.MATLABSystem3[0];
  for (i = 0; i < 9; i++) {
    u1 = MicroMouseTemplate_B.MATLABSystem3.MATLABSystem3[i + 1];
    if (maxV_1 < u1) {
      maxV_1 = u1;
    }
  }

  MicroMouseTem_MATLABSystem1(maxV_1, &MicroMouseTemplate_B.MATLABSystem2,
    &MicroMouseTemplate_DW.MATLABSystem2, &MicroMouseTemplate_P.MATLABSystem2);

  /* End of MinMax: '<S51>/Max of Elements6' */

  /* MinMax: '<S51>/Min1' incorporates:
   *  MATLABSystem: '<S51>/MATLAB System2'
   */
  maxV_1 = MicroMouseTemplate_B.MATLABSystem2.MATLABSystem1[0];
  for (i = 0; i < 24; i++) {
    u1 = MicroMouseTemplate_B.MATLABSystem2.MATLABSystem1[i + 1];
    if (maxV_1 > u1) {
      maxV_1 = u1;
    }
  }

  /* RateTransition generated from: '<S51>/Max of Elements7' */
  rtb_TmpRTBAtMaxofElements7Outpo =
    MicroMouseTemplate_DW.TmpRTBAtMaxofElements7Outport1_;

  /* DataStoreWrite: '<S48>/ADC_H Write' */
  ADC_H[0] = rtb_TmpRTBAtMaxofElementsOutpor;

  /* MinMax: '<S51>/Min' */
  u1 = fmod(floor(MicroMouseTemplate_B.minV), 65536.0);

  /* DataStoreWrite: '<S48>/ADC_H Write' incorporates:
   *  MinMax: '<S51>/Min'
   */
  ADC_H[1] = (uint16_T)(u1 < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-u1 :
                        (int32_T)(uint16_T)u1);

  /* MinMax: '<S51>/Max of Elements2' */
  u1 = fmod(floor(MicroMouseTemplate_B.maxV), 65536.0);

  /* DataStoreWrite: '<S48>/ADC_H Write' incorporates:
   *  MinMax: '<S51>/Max of Elements2'
   */
  ADC_H[2] = (uint16_T)(u1 < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-u1 :
                        (int32_T)(uint16_T)u1);

  /* MinMax: '<S51>/Max of Elements3' */
  u1 = fmod(floor(MicroMouseTemplate_B.maxV_m), 65536.0);

  /* DataStoreWrite: '<S48>/ADC_H Write' incorporates:
   *  MinMax: '<S51>/Max of Elements3'
   */
  ADC_H[3] = (uint16_T)(u1 < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-u1 :
                        (int32_T)(uint16_T)u1);

  /* MinMax: '<S51>/Max of Elements4' */
  u1 = fmod(floor(maxV), 65536.0);

  /* DataStoreWrite: '<S48>/ADC_H Write' incorporates:
   *  MinMax: '<S51>/Max of Elements4'
   */
  ADC_H[4] = (uint16_T)(u1 < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-u1 :
                        (int32_T)(uint16_T)u1);

  /* MinMax: '<S51>/Max of Elements5' */
  u1 = fmod(floor(maxV_0), 65536.0);

  /* DataStoreWrite: '<S48>/ADC_H Write' incorporates:
   *  MinMax: '<S51>/Max of Elements5'
   */
  ADC_H[5] = (uint16_T)(u1 < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-u1 :
                        (int32_T)(uint16_T)u1);

  /* MinMax: '<S51>/Min1' */
  u1 = fmod(floor(maxV_1), 65536.0);

  /* DataStoreWrite: '<S48>/ADC_H Write' incorporates:
   *  Constant: '<S48>/Constant'
   *  MinMax: '<S51>/Min1'
   */
  ADC_H[6] = (uint16_T)(u1 < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-u1 :
                        (int32_T)(uint16_T)u1);
  ADC_H[7] = rtb_TmpRTBAtMaxofElements7Outpo;
  ADC_H[8] = MicroMouseTemplate_P.Constant_Value_b;

  /* RateTransition generated from: '<S52>/Max of Elements8' */
  rtb_TmpRTBAtMaxofElementsOutpor =
    MicroMouseTemplate_DW.TmpRTBAtMaxofElements8Outport1_;
  MicroMouseTem_MATLABSystem1((real_T)MicroMouseTemplate_B.CastToDouble[1],
    &MicroMouseTemplate_B.MATLABSystem1_c,
    &MicroMouseTemplate_DW.MATLABSystem1_c,
    &MicroMouseTemplate_P.MATLABSystem1_c);

  /* MinMax: '<S52>/Max of Elements9' incorporates:
   *  MATLABSystem: '<S52>/MATLAB System1'
   */
  MicroMouseTemplate_B.minV =
    MicroMouseTemplate_B.MATLABSystem1_c.MATLABSystem1[0];
  for (i = 0; i < 24; i++) {
    u1 = MicroMouseTemplate_B.MATLABSystem1_c.MATLABSystem1[i + 1];
    if (MicroMouseTemplate_B.minV > u1) {
      MicroMouseTemplate_B.minV = u1;
    }
  }

  /* MinMax: '<S52>/Max of Elements10' incorporates:
   *  MATLABSystem: '<S53>/MATLAB System1'
   */
  maxV_1 = MicroMouseTemplate_B.MATLABSystem1_ci.MATLABSystem1[0];
  for (i = 0; i < 24; i++) {
    u1 = MicroMouseTemplate_B.MATLABSystem1_ci.MATLABSystem1[i + 1];
    if (maxV_1 > u1) {
      maxV_1 = u1;
    }
  }

  /* MinMax: '<S52>/Max of Elements11' incorporates:
   *  MATLABSystem: '<S53>/MATLAB System3'
   */
  MicroMouseTemplate_B.maxV =
    MicroMouseTemplate_B.MATLABSystem3_c.MATLABSystem1[0];
  for (i = 0; i < 24; i++) {
    u1 = MicroMouseTemplate_B.MATLABSystem3_c.MATLABSystem1[i + 1];
    if (MicroMouseTemplate_B.maxV > u1) {
      MicroMouseTemplate_B.maxV = u1;
    }
  }

  /* MinMax: '<S52>/Max of Elements12' incorporates:
   *  MATLABSystem: '<S53>/MATLAB System4'
   */
  MicroMouseTemplate_B.maxV_m =
    MicroMouseTemplate_B.MATLABSystem4_c.MATLABSystem1[0];
  for (i = 0; i < 24; i++) {
    u1 = MicroMouseTemplate_B.MATLABSystem4_c.MATLABSystem1[i + 1];
    if (MicroMouseTemplate_B.maxV_m > u1) {
      MicroMouseTemplate_B.maxV_m = u1;
    }
  }

  /* MinMax: '<S52>/Max of Elements13' incorporates:
   *  MATLABSystem: '<S53>/MATLAB System5'
   */
  maxV = MicroMouseTemplate_B.MATLABSystem5.MATLABSystem1[0];
  for (i = 0; i < 24; i++) {
    u1 = MicroMouseTemplate_B.MATLABSystem5.MATLABSystem1[i + 1];
    if (maxV > u1) {
      maxV = u1;
    }
  }

  MicroMouseTem_MATLABSystem1((real_T)MicroMouseTemplate_B.CastToDouble[6],
    &MicroMouseTemplate_B.MATLABSystem2_c,
    &MicroMouseTemplate_DW.MATLABSystem2_c,
    &MicroMouseTemplate_P.MATLABSystem2_c);

  /* MinMax: '<S52>/Max of Elements14' incorporates:
   *  MATLABSystem: '<S52>/MATLAB System2'
   */
  maxV_0 = MicroMouseTemplate_B.MATLABSystem2_c.MATLABSystem1[0];
  for (i = 0; i < 24; i++) {
    u1 = MicroMouseTemplate_B.MATLABSystem2_c.MATLABSystem1[i + 1];
    if (maxV_0 > u1) {
      maxV_0 = u1;
    }
  }

  /* RateTransition generated from: '<S52>/Max of Elements15' */
  rtb_TmpRTBAtMaxofElements7Outpo =
    MicroMouseTemplate_DW.TmpRTBAtMaxofElements15Outport1;

  /* DataStoreWrite: '<S48>/ADC_L Write' */
  ADC_L[0] = rtb_TmpRTBAtMaxofElementsOutpor;

  /* MinMax: '<S52>/Max of Elements9' */
  u1 = fmod(floor(MicroMouseTemplate_B.minV), 65536.0);

  /* DataStoreWrite: '<S48>/ADC_L Write' incorporates:
   *  MinMax: '<S52>/Max of Elements9'
   */
  ADC_L[1] = (uint16_T)(u1 < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-u1 :
                        (int32_T)(uint16_T)u1);

  /* MinMax: '<S52>/Max of Elements10' */
  u1 = fmod(floor(maxV_1), 65536.0);

  /* DataStoreWrite: '<S48>/ADC_L Write' incorporates:
   *  MinMax: '<S52>/Max of Elements10'
   */
  ADC_L[2] = (uint16_T)(u1 < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-u1 :
                        (int32_T)(uint16_T)u1);

  /* MinMax: '<S52>/Max of Elements11' */
  u1 = fmod(floor(MicroMouseTemplate_B.maxV), 65536.0);

  /* DataStoreWrite: '<S48>/ADC_L Write' incorporates:
   *  MinMax: '<S52>/Max of Elements11'
   */
  ADC_L[3] = (uint16_T)(u1 < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-u1 :
                        (int32_T)(uint16_T)u1);

  /* MinMax: '<S52>/Max of Elements12' */
  u1 = fmod(floor(MicroMouseTemplate_B.maxV_m), 65536.0);

  /* DataStoreWrite: '<S48>/ADC_L Write' incorporates:
   *  MinMax: '<S52>/Max of Elements12'
   */
  ADC_L[4] = (uint16_T)(u1 < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-u1 :
                        (int32_T)(uint16_T)u1);

  /* MinMax: '<S52>/Max of Elements13' */
  u1 = fmod(floor(maxV), 65536.0);

  /* DataStoreWrite: '<S48>/ADC_L Write' incorporates:
   *  MinMax: '<S52>/Max of Elements13'
   */
  ADC_L[5] = (uint16_T)(u1 < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-u1 :
                        (int32_T)(uint16_T)u1);

  /* MinMax: '<S52>/Max of Elements14' */
  u1 = fmod(floor(maxV_0), 65536.0);

  /* DataStoreWrite: '<S48>/ADC_L Write' incorporates:
   *  Constant: '<S48>/Constant1'
   *  MinMax: '<S52>/Max of Elements14'
   */
  ADC_L[6] = (uint16_T)(u1 < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-u1 :
                        (int32_T)(uint16_T)u1);
  ADC_L[7] = rtb_TmpRTBAtMaxofElements7Outpo;
  ADC_L[8] = MicroMouseTemplate_P.Constant1_Value;

  /* RateTransition: '<S53>/Rate Transition' */
  if (MicroMouseTemplate_M->Timing.RateInteraction.TID1_2) {
    MicroMouseTemplate_DW.RateTransition_Buffer =
      MicroMouseTemplate_B.CastToDouble[0];

    /* RateTransition: '<S53>/Rate Transition1' */
    MicroMouseTemplate_DW.RateTransition1_Buffer =
      MicroMouseTemplate_B.CastToDouble[7];
  }

  /* End of RateTransition: '<S53>/Rate Transition' */

  /* Gain: '<Root>/Gain' incorporates:
   *  Sum: '<Root>/Sum'
   */
  Gain = (uint32_T)(uint16_T)((uint32_T)MicroMouseTemplate_B.Flip[2] +
    MicroMouseTemplate_B.Flip[5]) * MicroMouseTemplate_P.Gain_Gain;

  /* MATLABSystem: '<S71>/Digital Port Read' */
  pinReadLoc = LL_GPIO_ReadInputPort(GPIOB);

  /* MATLABSystem: '<S69>/Digital Port Read' */
  pinReadLoc_0 = LL_GPIO_ReadInputPort(GPIOE);

  /* Logic: '<S9>/NOT' incorporates:
   *  MATLABSystem: '<S69>/Digital Port Read'
   * */
  NOT = ((pinReadLoc_0 & 64U) == 0U);

  /* Chart: '<Root>/HelloMicroMouse!' incorporates:
   *  Logic: '<S9>/NOT1'
   *  MATLABSystem: '<S71>/Digital Port Read'
   * */
  if (MicroMouseTemplate_DW.temporalCounter_i1 < 127U) {
    MicroMouseTemplate_DW.temporalCounter_i1++;
  }

  if (MicroMouseTemplate_DW.bitsForTID1.is_active_c2_MicroMouseTemplate == 0U) {
    MicroMouseTemplate_DW.bitsForTID1.is_active_c2_MicroMouseTemplate = 1U;
    MicroMouseTemplate_DW.bitsForTID1.is_c2_MicroMouseTemplate =
      Micro_IN_WaitUntilButtonPressed;
  } else {
    switch (MicroMouseTemplate_DW.bitsForTID1.is_c2_MicroMouseTemplate) {
     case MicroMouseTem_IN_ButtonPressed3:
      MicroMouseTempla_ButtonPressed3(&Gain);
      break;

     case Micr_IN_CalibrationDownAndSides:
      if (MicroMouseTemplate_DW.temporalCounter_i1 >= 100U) {
        MicroMouseTemplate_DW.bitsForTID1.is_c2_MicroMouseTemplate =
          MicroMouseTemplate_IN_Ready1;
        MicroMouseTemplate_B.rightWheel_f = 0.0;
        MicroMouseTemplate_B.leftWheel_k = 0.0;
        MicroMouseTemplate_B.LED2 = true;
        MicroMouseTemplate_B.LED1 = true;
        MicroMouseTemplate_B.LED0 = true;
        MicroMouseTemplate_B.LED_FWD_RS = 0.0;
        MicroMouseTemplate_B.LED_FWD_LS = 0.0;
        MicroMouseTemplate_B.LED_LS = 0.0;
        MicroMouseTemplate_B.LED_RS = 0.0;
        Gain = (uint32_T)MicroMouseTemplate_DW.init_DOWN_R_LIGHT +
          MicroMouseTemplate_DW.init_DOWN_R_DARK;
        if (Gain > 65535U) {
          Gain = 65535U;
        }

        MicroMouseTemplate_DW.thresh_DOWN_RIGHT = (uint16_T)rt_roundd((real_T)
          Gain * 0.5);
        Gain = (uint32_T)MicroMouseTemplate_DW.init_DOWN_L_LIGHT +
          MicroMouseTemplate_DW.init_DOWN_L_DARK;
        if (Gain > 65535U) {
          Gain = 65535U;
        }

        MicroMouseTemplate_DW.thresh_DOWN_LEFT = (uint16_T)rt_roundd((real_T)
          Gain * 0.5);
        Gain = (uint32_T)MicroMouseTemplate_DW.init_DOWN_L_DARK +
          MicroMouseTemplate_DW.init_DOWN_R_DARK;
        if (Gain > 65535U) {
          Gain = 65535U;
        }

        MicroMouseTemplate_DW.thresh_DOWN_AVG = (uint16_T)rt_roundd((real_T)Gain
          * 0.5);
        Gain = (uint32_T)MicroMouseTemplate_DW.init_LEFT_FAR +
          MicroMouseTemplate_DW.init_LEFT_CLOSE;
        if (Gain > 65535U) {
          Gain = 65535U;
        }

        MicroMouseTemplate_DW.thresh_LEFT = (uint16_T)rt_roundd(rt_roundd
          ((real_T)Gain * 0.5) * 0.9);
        Gain = (uint32_T)MicroMouseTemplate_DW.init_RIGHT_FAR +
          MicroMouseTemplate_DW.init_RIGHT_CLOSE;
        if (Gain > 65535U) {
          Gain = 65535U;
        }

        MicroMouseTemplate_DW.thresh_RIGHT = (uint16_T)rt_roundd(rt_roundd
          ((real_T)Gain * 0.5) * 0.9);
        MicroMouseTemplate_DW.thresh_FWD_L = MicroMouseTemplate_DW.init_FWD_LEFT;
        MicroMouseTemplate_DW.thresh_FWD_R =
          MicroMouseTemplate_DW.init_FWD_RIGHT;
        MicroMouseTemplate_DW.normal_speed_LEFT = 75.0;
        MicroMouseTemplate_DW.normal_speed_RIGHT = 75.0;
      } else {
        if (MicroMouseTemplate_DW.init_DOWN_R_DARK > MicroMouseTemplate_B.Flip[2])
        {
          MicroMouseTemplate_DW.init_DOWN_R_DARK = MicroMouseTemplate_B.Flip[2];
        }

        if (MicroMouseTemplate_DW.init_DOWN_L_DARK > MicroMouseTemplate_B.Flip[5])
        {
          MicroMouseTemplate_DW.init_DOWN_L_DARK = MicroMouseTemplate_B.Flip[5];
        }

        if (MicroMouseTemplate_DW.init_DOWN_R_LIGHT < MicroMouseTemplate_B.Flip
            [2]) {
          MicroMouseTemplate_DW.init_DOWN_R_LIGHT = MicroMouseTemplate_B.Flip[2];
        }

        if (MicroMouseTemplate_DW.init_DOWN_L_LIGHT < MicroMouseTemplate_B.Flip
            [5]) {
          MicroMouseTemplate_DW.init_DOWN_L_LIGHT = MicroMouseTemplate_B.Flip[5];
        }

        if (MicroMouseTemplate_DW.init_LEFT_CLOSE < MicroMouseTemplate_B.Flip[4])
        {
          MicroMouseTemplate_DW.init_LEFT_CLOSE = MicroMouseTemplate_B.Flip[4];
        }

        if (MicroMouseTemplate_DW.init_RIGHT_CLOSE < MicroMouseTemplate_B.Flip[3])
        {
          MicroMouseTemplate_DW.init_RIGHT_CLOSE = MicroMouseTemplate_B.Flip[3];
        }

        if (MicroMouseTemplate_DW.init_LEFT_FAR > MicroMouseTemplate_B.Flip[4])
        {
          MicroMouseTemplate_DW.init_LEFT_FAR = MicroMouseTemplate_B.Flip[4];
        }

        if (MicroMouseTemplate_DW.init_RIGHT_FAR > MicroMouseTemplate_B.Flip[3])
        {
          MicroMouseTemplate_DW.init_RIGHT_FAR = MicroMouseTemplate_B.Flip[3];
        }
      }
      break;

     case MicroMous_IN_CalibrationForward:
      if (((pinReadLoc & 4U) == 0U) && (MicroMouseTemplate_DW.counter == 100.0))
      {
        MicroMouseTemplate_B.LED_FWD_RS = 0.0;
        MicroMouseTemplate_B.LED_FWD_LS = 0.0;
        MicroMouseTemplate_DW.temporalCounter_i1 = 0U;
        MicroMouseTemplate_DW.bitsForTID1.is_c2_MicroMouseTemplate =
          Micr_IN_CalibrationDownAndSides;
        MicroMouseTemplate_B.LED1 = true;
        MicroMouseTemplate_B.LED_LS = 1.0;
        MicroMouseTemplate_B.LED_RS = 1.0;
        MicroMouseTemplate_B.rightWheel_f = 75.0;
        MicroMouseTemplate_B.leftWheel_k = -75.0;
        MicroMouseTemplate_DW.init_DOWN_R_DARK = MicroMouseTemplate_B.Flip[2];
        MicroMouseTemplate_DW.init_DOWN_L_DARK = MicroMouseTemplate_B.Flip[5];
        MicroMouseTemplate_DW.init_DOWN_R_LIGHT = MicroMouseTemplate_B.Flip[2];
        MicroMouseTemplate_DW.init_DOWN_L_LIGHT = MicroMouseTemplate_B.Flip[5];
        MicroMouseTemplate_DW.init_LEFT_CLOSE = MicroMouseTemplate_B.Flip[4];
        MicroMouseTemplate_DW.init_RIGHT_CLOSE = MicroMouseTemplate_B.Flip[3];
        MicroMouseTemplate_DW.init_LEFT_FAR = MicroMouseTemplate_B.Flip[4];
        MicroMouseTemplate_DW.init_RIGHT_FAR = MicroMouseTemplate_B.Flip[3];
      } else {
        MicroMouseTemplate_B.leftWheel_k = -MicroMouseTemplate_B.leftWheel_k;
        MicroMouseTemplate_B.rightWheel_f = -MicroMouseTemplate_B.rightWheel_f;
        if (MicroMouseTemplate_DW.counter < 100.0) {
          Gain = (uint32_T)MicroMouseTemplate_DW.sum_FWD_LEFT +
            MicroMouseTemplate_B.Flip[6];
          if (Gain > 65535U) {
            Gain = 65535U;
          }

          MicroMouseTemplate_DW.sum_FWD_LEFT = (uint16_T)Gain;
          Gain = (uint32_T)MicroMouseTemplate_DW.sum_FWD_RIGHT +
            MicroMouseTemplate_B.Flip[1];
          if (Gain > 65535U) {
            Gain = 65535U;
          }

          MicroMouseTemplate_DW.sum_FWD_RIGHT = (uint16_T)Gain;
          MicroMouseTemplate_DW.counter++;
        } else {
          MicroMouseTemplate_DW.init_FWD_LEFT = (uint16_T)rt_roundd((real_T)
            MicroMouseTemplate_DW.sum_FWD_LEFT / 100.0);
          MicroMouseTemplate_DW.init_FWD_RIGHT = (uint16_T)rt_roundd((real_T)
            MicroMouseTemplate_DW.sum_FWD_RIGHT / 100.0);
          MicroMouseTemplate_B.leftWheel_k = 0.0;
          MicroMouseTemplate_B.rightWheel_f = 0.0;
        }
      }
      break;

     case MicroMouseTemplate_IN_Ready1:
      if (NOT) {
        MicroMouseTemplate_DW.bitsForTID1.is_c2_MicroMouseTemplate =
          MicroMouseTem_IN_ButtonPressed3;
        MicroMouseTemplate_DW.bitsForTID1.is_ButtonPressed3 =
          MicroMouseTemplate_IN_Driving;
        MicroMouseTemplate_DW.timer = 0.0;
        MicroMouseTemplate_DW.bitsForTID1.is_Driving =
          MicroMouseTemplate_IN_Forward;
        MicroMouseTemplate_B.LED0 = false;
        MicroMouseTemplate_B.LED1 = false;
        MicroMouseTemplate_B.LED2 = false;
        MicroMouseTemplate_B.leftWheel_k =
          MicroMouseTemplate_DW.normal_speed_LEFT;
        MicroMouseTemplate_B.rightWheel_f =
          MicroMouseTemplate_DW.normal_speed_RIGHT;
      }
      break;

     default:
      /* case IN_WaitUntilButtonPressed: */
      if (NOT) {
        MicroMouseTemplate_DW.bitsForTID1.is_c2_MicroMouseTemplate =
          MicroMous_IN_CalibrationForward;
        MicroMouseTemplate_DW.counter = 0.0;
        MicroMouseTemplate_DW.sum_FWD_LEFT = 0U;
        MicroMouseTemplate_DW.sum_FWD_RIGHT = 0U;
        MicroMouseTemplate_B.leftWheel_k = 75.0;
        MicroMouseTemplate_B.rightWheel_f = -75.0;
        MicroMouseTemplate_B.LED_FWD_RS = 1.0;
        MicroMouseTemplate_B.LED_FWD_LS = 1.0;
      } else {
        MicroMouseTemplate_B.LED1 = !MicroMouseTemplate_B.LED1;
      }
      break;
    }
  }

  /* End of Chart: '<Root>/HelloMicroMouse!' */

  /* Outputs for Atomic SubSystem: '<Root>/GPIO for IR LEDs' */
  /* MATLABSystem: '<S23>/Digital Port Write' */
  MicroMouseTemplate_B.portNameLoc = GPIOE;
  if (MicroMouseTemplate_B.LED_FWD_LS != 0.0) {
    i = 256;
  } else {
    i = 0;
  }

  LL_GPIO_SetOutputPin(MicroMouseTemplate_B.portNameLoc, (uint32_T)i);
  LL_GPIO_ResetOutputPin(MicroMouseTemplate_B.portNameLoc, ~(uint32_T)i & 256U);

  /* End of MATLABSystem: '<S23>/Digital Port Write' */

  /* MATLABSystem: '<S25>/Digital Port Write' */
  MicroMouseTemplate_B.portNameLoc = GPIOE;
  if (MicroMouseTemplate_B.LED_FWD_RS != 0.0) {
    i = 32768;
  } else {
    i = 0;
  }

  LL_GPIO_SetOutputPin(MicroMouseTemplate_B.portNameLoc, (uint32_T)i);
  LL_GPIO_ResetOutputPin(MicroMouseTemplate_B.portNameLoc, ~(uint32_T)i & 32768U);

  /* End of MATLABSystem: '<S25>/Digital Port Write' */

  /* MATLABSystem: '<S27>/Digital Port Write' */
  MicroMouseTemplate_B.portNameLoc = GPIOE;
  if (MicroMouseTemplate_B.LED_LS != 0.0) {
    i = 4096;
  } else {
    i = 0;
  }

  LL_GPIO_SetOutputPin(MicroMouseTemplate_B.portNameLoc, (uint32_T)i);
  LL_GPIO_ResetOutputPin(MicroMouseTemplate_B.portNameLoc, ~(uint32_T)i & 4096U);

  /* End of MATLABSystem: '<S27>/Digital Port Write' */

  /* MATLABSystem: '<S33>/Digital Port Write' */
  MicroMouseTemplate_B.portNameLoc = GPIOE;
  if (MicroMouseTemplate_B.LED_RS != 0.0) {
    i = 2048;
  } else {
    i = 0;
  }

  LL_GPIO_SetOutputPin(MicroMouseTemplate_B.portNameLoc, (uint32_T)i);
  LL_GPIO_ResetOutputPin(MicroMouseTemplate_B.portNameLoc, ~(uint32_T)i & 2048U);

  /* End of MATLABSystem: '<S33>/Digital Port Write' */
  /* End of Outputs for SubSystem: '<Root>/GPIO for IR LEDs' */

  /* If: '<S5>/If1' */
  rtPrevAction = MicroMouseTemplate_DW.If1_ActiveSubsystem;
  MicroMouseTemplate_DW.If1_ActiveSubsystem = -1;
  if (MicroMouseTemplate_B.rightWheel_f > 0.0) {
    MicroMouseTemplate_DW.If1_ActiveSubsystem = 0;
  } else if (MicroMouseTemplate_B.rightWheel_f <= 0.0) {
    MicroMouseTemplate_DW.If1_ActiveSubsystem = 1;
  }

  if (rtPrevAction != MicroMouseTemplate_DW.If1_ActiveSubsystem) {
    switch (rtPrevAction) {
     case 0:
      /* Disable for SignalConversion generated from: '<S36>/rightWheel' incorporates:
       *  Outport: '<S36>/Out1'
       * */
      MicroMouseTemplate_B.rightWheel_c = MicroMouseTemplate_P.Out1_Y0_d;
      break;

     case 1:
      /* Disable for SignalConversion generated from: '<S37>/rightWheel' incorporates:
       *  Outport: '<S37>/Out1'
       * */
      MicroMouseTemplate_B.rightWheel = MicroMouseTemplate_P.Out1_Y0_a;
      break;
    }
  }

  switch (MicroMouseTemplate_DW.If1_ActiveSubsystem) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S5>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S36>/Action Port'
     */
    /* SignalConversion generated from: '<S36>/rightWheel' */
    MicroMouseTemplate_B.rightWheel_c = MicroMouseTemplate_B.rightWheel_f;

    /* End of Outputs for SubSystem: '<S5>/If Action Subsystem2' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S5>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S37>/Action Port'
     */
    /* SignalConversion generated from: '<S37>/rightWheel' */
    MicroMouseTemplate_B.rightWheel = MicroMouseTemplate_B.rightWheel_f;

    /* End of Outputs for SubSystem: '<S5>/If Action Subsystem3' */
    break;
  }

  /* End of If: '<S5>/If1' */

  /* MATLABSystem: '<S46>/PWM Output' incorporates:
   *  Abs: '<S5>/Abs1'
   */
  setDutyCycleInPercentageChannel1(MicroMouseTemplate_DW.obj_g.TimerHandle,
    MicroMouseTemplate_B.rightWheel_c);
  setDutyCycleInPercentageChannel2(MicroMouseTemplate_DW.obj_g.TimerHandle, fabs
    (MicroMouseTemplate_B.rightWheel));

  /* If: '<S5>/If' */
  rtPrevAction = MicroMouseTemplate_DW.If_ActiveSubsystem;
  MicroMouseTemplate_DW.If_ActiveSubsystem = -1;
  if (MicroMouseTemplate_B.leftWheel_k > 0.0) {
    MicroMouseTemplate_DW.If_ActiveSubsystem = 0;
  } else if (MicroMouseTemplate_B.leftWheel_k <= 0.0) {
    MicroMouseTemplate_DW.If_ActiveSubsystem = 1;
  }

  if (rtPrevAction != MicroMouseTemplate_DW.If_ActiveSubsystem) {
    switch (rtPrevAction) {
     case 0:
      /* Disable for SignalConversion generated from: '<S34>/leftWheel' incorporates:
       *  Outport: '<S34>/Out1'
       * */
      MicroMouseTemplate_B.leftWheel_d = MicroMouseTemplate_P.Out1_Y0;
      break;

     case 1:
      /* Disable for SignalConversion generated from: '<S35>/leftWheel' incorporates:
       *  Outport: '<S35>/Out1'
       * */
      MicroMouseTemplate_B.leftWheel = MicroMouseTemplate_P.Out1_Y0_j;
      break;
    }
  }

  switch (MicroMouseTemplate_DW.If_ActiveSubsystem) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S5>/If Action Subsystem' incorporates:
     *  ActionPort: '<S34>/Action Port'
     */
    /* SignalConversion generated from: '<S34>/leftWheel' */
    MicroMouseTemplate_B.leftWheel_d = MicroMouseTemplate_B.leftWheel_k;

    /* End of Outputs for SubSystem: '<S5>/If Action Subsystem' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S5>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S35>/Action Port'
     */
    /* SignalConversion generated from: '<S35>/leftWheel' */
    MicroMouseTemplate_B.leftWheel = MicroMouseTemplate_B.leftWheel_k;

    /* End of Outputs for SubSystem: '<S5>/If Action Subsystem1' */
    break;
  }

  /* End of If: '<S5>/If' */

  /* MATLABSystem: '<S44>/PWM Output' incorporates:
   *  Abs: '<S5>/Abs'
   */
  setDutyCycleInPercentageChannel3(MicroMouseTemplate_DW.obj_n.TimerHandle,
    MicroMouseTemplate_B.leftWheel_d);
  setDutyCycleInPercentageChannel4(MicroMouseTemplate_DW.obj_n.TimerHandle, fabs
    (MicroMouseTemplate_B.leftWheel));

  /* MATLABSystem: '<S61>/Digital Port Write' */
  MicroMouseTemplate_B.portNameLoc = GPIOC;
  if (MicroMouseTemplate_B.LED0) {
    i = 8192;
  } else {
    i = 0;
  }

  LL_GPIO_SetOutputPin(MicroMouseTemplate_B.portNameLoc, (uint32_T)i);
  LL_GPIO_ResetOutputPin(MicroMouseTemplate_B.portNameLoc, ~(uint32_T)i & 8192U);

  /* End of MATLABSystem: '<S61>/Digital Port Write' */

  /* MATLABSystem: '<S63>/Digital Port Write' */
  MicroMouseTemplate_B.portNameLoc = GPIOC;
  if (MicroMouseTemplate_B.LED1) {
    i = 16384;
  } else {
    i = 0;
  }

  LL_GPIO_SetOutputPin(MicroMouseTemplate_B.portNameLoc, (uint32_T)i);
  LL_GPIO_ResetOutputPin(MicroMouseTemplate_B.portNameLoc, ~(uint32_T)i & 16384U);

  /* End of MATLABSystem: '<S63>/Digital Port Write' */

  /* MATLABSystem: '<S65>/Digital Port Write' */
  MicroMouseTemplate_B.portNameLoc = GPIOC;
  if (MicroMouseTemplate_B.LED2) {
    i = 32768;
  } else {
    i = 0;
  }

  LL_GPIO_SetOutputPin(MicroMouseTemplate_B.portNameLoc, (uint32_T)i);
  LL_GPIO_ResetOutputPin(MicroMouseTemplate_B.portNameLoc, ~(uint32_T)i & 32768U);

  /* End of MATLABSystem: '<S65>/Digital Port Write' */

  /* user code (Update function Body for TID1) */

  /* System '<Root>' */
  refreshIMUValues();

  /* System '<Root>' */
  CustomWhile();
}

/* Model step function for TID2 */
void MicroMouseTemplate_step2(void)    /* Sample time: [0.1s, 0.0s] */
{
  real_T maxV;
  real_T rtb_RateTransition;
  int32_T k;
  uint16_T rtb_MaxofElements;
  uint16_T rtb_MaxofElements7;

  /* RateTransition: '<S53>/Rate Transition' */
  rtb_RateTransition = MicroMouseTemplate_DW.RateTransition_Buffer;
  MicroMouseTem_MATLABSystem1(rtb_RateTransition,
    &MicroMouseTemplate_B.MATLABSystem2_ci,
    &MicroMouseTemplate_DW.MATLABSystem2_ci,
    &MicroMouseTemplate_P.MATLABSystem2_ci);

  /* MinMax: '<S51>/Max of Elements' incorporates:
   *  MATLABSystem: '<S53>/MATLAB System2'
   */
  maxV = MicroMouseTemplate_B.MATLABSystem2_ci.MATLABSystem1[0];
  for (k = 0; k < 24; k++) {
    rtb_RateTransition = MicroMouseTemplate_B.MATLABSystem2_ci.MATLABSystem1[k +
      1];
    if (maxV < rtb_RateTransition) {
      maxV = rtb_RateTransition;
    }
  }

  rtb_RateTransition = fmod(floor(maxV), 65536.0);
  rtb_MaxofElements = (uint16_T)(rtb_RateTransition < 0.0 ? (int32_T)(uint16_T)
    -(int16_T)(uint16_T)-rtb_RateTransition : (int32_T)(uint16_T)
    rtb_RateTransition);

  /* End of MinMax: '<S51>/Max of Elements' */

  /* RateTransition: '<S53>/Rate Transition1' */
  rtb_RateTransition = MicroMouseTemplate_DW.RateTransition1_Buffer;
  MicroMouseTem_MATLABSystem1(rtb_RateTransition,
    &MicroMouseTemplate_B.MATLABSystem6, &MicroMouseTemplate_DW.MATLABSystem6,
    &MicroMouseTemplate_P.MATLABSystem6);

  /* MinMax: '<S51>/Max of Elements7' incorporates:
   *  MATLABSystem: '<S53>/MATLAB System6'
   */
  maxV = MicroMouseTemplate_B.MATLABSystem6.MATLABSystem1[0];
  for (k = 0; k < 24; k++) {
    rtb_RateTransition = MicroMouseTemplate_B.MATLABSystem6.MATLABSystem1[k + 1];
    if (maxV < rtb_RateTransition) {
      maxV = rtb_RateTransition;
    }
  }

  rtb_RateTransition = fmod(floor(maxV), 65536.0);
  rtb_MaxofElements7 = (uint16_T)(rtb_RateTransition < 0.0 ? (int32_T)(uint16_T)
    -(int16_T)(uint16_T)-rtb_RateTransition : (int32_T)(uint16_T)
    rtb_RateTransition);

  /* End of MinMax: '<S51>/Max of Elements7' */

  /* RateTransition generated from: '<S51>/Max of Elements7' */
  MicroMouseTemplate_DW.TmpRTBAtMaxofElements7Outport1_ = rtb_MaxofElements7;

  /* RateTransition generated from: '<S51>/Max of Elements' */
  MicroMouseTemplate_DW.TmpRTBAtMaxofElementsOutport1_B = rtb_MaxofElements;

  /* MinMax: '<S52>/Max of Elements15' incorporates:
   *  MATLABSystem: '<S53>/MATLAB System6'
   */
  maxV = MicroMouseTemplate_B.MATLABSystem6.MATLABSystem1[0];
  for (k = 0; k < 24; k++) {
    rtb_RateTransition = MicroMouseTemplate_B.MATLABSystem6.MATLABSystem1[k + 1];
    if (maxV > rtb_RateTransition) {
      maxV = rtb_RateTransition;
    }
  }

  rtb_RateTransition = fmod(floor(maxV), 65536.0);
  rtb_MaxofElements = (uint16_T)(rtb_RateTransition < 0.0 ? (int32_T)(uint16_T)
    -(int16_T)(uint16_T)-rtb_RateTransition : (int32_T)(uint16_T)
    rtb_RateTransition);

  /* End of MinMax: '<S52>/Max of Elements15' */

  /* MinMax: '<S52>/Max of Elements8' incorporates:
   *  MATLABSystem: '<S53>/MATLAB System2'
   */
  maxV = MicroMouseTemplate_B.MATLABSystem2_ci.MATLABSystem1[0];
  for (k = 0; k < 24; k++) {
    rtb_RateTransition = MicroMouseTemplate_B.MATLABSystem2_ci.MATLABSystem1[k +
      1];
    if (maxV > rtb_RateTransition) {
      maxV = rtb_RateTransition;
    }
  }

  rtb_RateTransition = fmod(floor(maxV), 65536.0);
  rtb_MaxofElements7 = (uint16_T)(rtb_RateTransition < 0.0 ? (int32_T)(uint16_T)
    -(int16_T)(uint16_T)-rtb_RateTransition : (int32_T)(uint16_T)
    rtb_RateTransition);

  /* End of MinMax: '<S52>/Max of Elements8' */

  /* RateTransition generated from: '<S52>/Max of Elements15' */
  MicroMouseTemplate_DW.TmpRTBAtMaxofElements15Outport1 = rtb_MaxofElements;

  /* RateTransition generated from: '<S52>/Max of Elements8' */
  MicroMouseTemplate_DW.TmpRTBAtMaxofElements8Outport1_ = rtb_MaxofElements7;

  /* user code (Update function Body for TID2) */

  /* System '<Root>' */
  refreshIMUValues();

  /* System '<Root>' */
  CustomWhile();
}

/* Model initialize function */
void MicroMouseTemplate_initialize(void)
{
  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      /* Start for DataStoreMemory: '<S1>/Data Store Memory' */
      Detections[i] = MicroMouseTemplate_P.DataStoreMemory_InitialValue_p4;

      /* Start for DataStoreMemory: '<S1>/Data Store Memory1' */
      Thresholds[i] = MicroMouseTemplate_P.DataStoreMemory1_InitialValue_j;
    }

    /* Start for DataStoreMemory: '<S1>/Data Store Memory2' */
    currTicksRS = MicroMouseTemplate_P.DataStoreMemory2_InitialValue;

    /* Start for DataStoreMemory: '<S1>/Data Store Memory4' */
    currTicksLS = MicroMouseTemplate_P.DataStoreMemory4_InitialValue;

    /* Start for DataStoreMemory: '<S7>/Data Store Memory' */
    IMU_Accel[0] = MicroMouseTemplate_P.DataStoreMemory_InitialValue;

    /* Start for DataStoreMemory: '<S7>/Data Store Memory1' */
    IMU_Gyro[0] = MicroMouseTemplate_P.DataStoreMemory1_InitialValue;

    /* Start for DataStoreMemory: '<S7>/Data Store Memory' */
    IMU_Accel[1] = MicroMouseTemplate_P.DataStoreMemory_InitialValue;

    /* Start for DataStoreMemory: '<S7>/Data Store Memory1' */
    IMU_Gyro[1] = MicroMouseTemplate_P.DataStoreMemory1_InitialValue;

    /* Start for DataStoreMemory: '<S7>/Data Store Memory' */
    IMU_Accel[2] = MicroMouseTemplate_P.DataStoreMemory_InitialValue;

    /* Start for DataStoreMemory: '<S7>/Data Store Memory1' */
    IMU_Gyro[2] = MicroMouseTemplate_P.DataStoreMemory1_InitialValue;
    for (i = 0; i < 9; i++) {
      /* Start for DataStoreMemory: '<S6>/Data Store Memory' */
      ADC1s[i] = MicroMouseTemplate_P.DataStoreMemory_InitialValue_p;

      /* Start for DataStoreMemory: '<S6>/Data Store Memory1' */
      ADC_H[i] = MicroMouseTemplate_P.DataStoreMemory1_InitialValue_p;

      /* Start for DataStoreMemory: '<S6>/Data Store Memory2' */
      ADC_L[i] = MicroMouseTemplate_P.DataStoreMemory2_InitialValue_p;
    }

    /* Start for If: '<S5>/If1' */
    MicroMouseTemplate_DW.If1_ActiveSubsystem = -1;

    /* Start for If: '<S5>/If' */
    MicroMouseTemplate_DW.If_ActiveSubsystem = -1;

    /* user code (Initialize function Body) */

    /* System '<Root>' */
    initIMU();

    /* InitializeConditions for RateTransition generated from: '<S51>/Max of Elements' */
    MicroMouseTemplate_DW.TmpRTBAtMaxofElementsOutport1_B =
      MicroMouseTemplate_P.TmpRTBAtMaxofElementsOutport1_I;

    /* InitializeConditions for RateTransition generated from: '<S51>/Max of Elements7' */
    MicroMouseTemplate_DW.TmpRTBAtMaxofElements7Outport1_ =
      MicroMouseTemplate_P.TmpRTBAtMaxofElements7Outport1_;

    /* InitializeConditions for RateTransition generated from: '<S52>/Max of Elements8' */
    MicroMouseTemplate_DW.TmpRTBAtMaxofElements8Outport1_ =
      MicroMouseTemplate_P.TmpRTBAtMaxofElements8Outport1_;

    /* InitializeConditions for RateTransition generated from: '<S52>/Max of Elements15' */
    MicroMouseTemplate_DW.TmpRTBAtMaxofElements15Outport1 =
      MicroMouseTemplate_P.TmpRTBAtMaxofElements15Outport1;

    /* SystemInitialize for IfAction SubSystem: '<S5>/If Action Subsystem2' */
    /* SystemInitialize for SignalConversion generated from: '<S36>/rightWheel' incorporates:
     *  Outport: '<S36>/Out1'
     */
    MicroMouseTemplate_B.rightWheel_c = MicroMouseTemplate_P.Out1_Y0_d;

    /* End of SystemInitialize for SubSystem: '<S5>/If Action Subsystem2' */

    /* SystemInitialize for IfAction SubSystem: '<S5>/If Action Subsystem3' */
    /* SystemInitialize for SignalConversion generated from: '<S37>/rightWheel' incorporates:
     *  Outport: '<S37>/Out1'
     */
    MicroMouseTemplate_B.rightWheel = MicroMouseTemplate_P.Out1_Y0_a;

    /* End of SystemInitialize for SubSystem: '<S5>/If Action Subsystem3' */

    /* SystemInitialize for IfAction SubSystem: '<S5>/If Action Subsystem' */
    /* SystemInitialize for SignalConversion generated from: '<S34>/leftWheel' incorporates:
     *  Outport: '<S34>/Out1'
     */
    MicroMouseTemplate_B.leftWheel_d = MicroMouseTemplate_P.Out1_Y0;

    /* End of SystemInitialize for SubSystem: '<S5>/If Action Subsystem' */

    /* SystemInitialize for IfAction SubSystem: '<S5>/If Action Subsystem1' */
    /* SystemInitialize for SignalConversion generated from: '<S35>/leftWheel' incorporates:
     *  Outport: '<S35>/Out1'
     */
    MicroMouseTemplate_B.leftWheel = MicroMouseTemplate_P.Out1_Y0_j;

    /* End of SystemInitialize for SubSystem: '<S5>/If Action Subsystem1' */

    /* Start for MATLABSystem: '<S50>/Analog to Digital Converter' */
    MicroMouseTemplate_DW.obj.isInitialized = 0;
    MicroMouseTemplate_DW.obj.matlabCodegenIsDeleted = false;
    MicroMouseTemp_SystemCore_setup(&MicroMouseTemplate_DW.obj);
    MicroMou_MATLABSystem3_Init(&MicroMouseTemplate_DW.MATLABSystem4,
      &MicroMouseTemplate_P.MATLABSystem4);
    MicroMou_MATLABSystem1_Init(&MicroMouseTemplate_DW.MATLABSystem1,
      &MicroMouseTemplate_P.MATLABSystem1);
    MicroMou_MATLABSystem1_Init(&MicroMouseTemplate_DW.MATLABSystem1_ci,
      &MicroMouseTemplate_P.MATLABSystem1_ci);
    MicroMou_MATLABSystem1_Init(&MicroMouseTemplate_DW.MATLABSystem3_c,
      &MicroMouseTemplate_P.MATLABSystem3_c);
    MicroMou_MATLABSystem1_Init(&MicroMouseTemplate_DW.MATLABSystem4_c,
      &MicroMouseTemplate_P.MATLABSystem4_c);
    MicroMou_MATLABSystem1_Init(&MicroMouseTemplate_DW.MATLABSystem5,
      &MicroMouseTemplate_P.MATLABSystem5);
    MicroMou_MATLABSystem3_Init(&MicroMouseTemplate_DW.MATLABSystem3,
      &MicroMouseTemplate_P.MATLABSystem3);
    MicroMou_MATLABSystem1_Init(&MicroMouseTemplate_DW.MATLABSystem2,
      &MicroMouseTemplate_P.MATLABSystem2);
    MicroMou_MATLABSystem1_Init(&MicroMouseTemplate_DW.MATLABSystem1_c,
      &MicroMouseTemplate_P.MATLABSystem1_c);
    MicroMou_MATLABSystem1_Init(&MicroMouseTemplate_DW.MATLABSystem2_c,
      &MicroMouseTemplate_P.MATLABSystem2_c);

    /* Start for MATLABSystem: '<S46>/PWM Output' */
    MicroMouseTemplate_DW.obj_g.matlabCodegenIsDeleted = false;
    MicroMouseTemplate_DW.obj_g.isSetupComplete = false;
    MicroMouseTemplate_DW.obj_g.isInitialized = 1;
    MicroMous_PWMOutput_setupImpl_d(&MicroMouseTemplate_DW.obj_g);
    MicroMouseTemplate_DW.obj_g.isSetupComplete = true;

    /* Start for MATLABSystem: '<S44>/PWM Output' */
    MicroMouseTemplate_DW.obj_n.matlabCodegenIsDeleted = false;
    MicroMouseTemplate_DW.obj_n.isSetupComplete = false;
    MicroMouseTemplate_DW.obj_n.isInitialized = 1;
    MicroMouseT_PWMOutput_setupImpl(&MicroMouseTemplate_DW.obj_n);
    MicroMouseTemplate_DW.obj_n.isSetupComplete = true;
    MicroMou_MATLABSystem1_Init(&MicroMouseTemplate_DW.MATLABSystem2_ci,
      &MicroMouseTemplate_P.MATLABSystem2_ci);
    MicroMou_MATLABSystem1_Init(&MicroMouseTemplate_DW.MATLABSystem6,
      &MicroMouseTemplate_P.MATLABSystem6);
  }
}

/* Model terminate function */
void MicroMouseTemplate_terminate(void)
{
  /* Terminate for MATLABSystem: '<S50>/Analog to Digital Converter' */
  if (!MicroMouseTemplate_DW.obj.matlabCodegenIsDeleted) {
    MicroMouseTemplate_DW.obj.matlabCodegenIsDeleted = true;
    if ((MicroMouseTemplate_DW.obj.isInitialized == 1) &&
        MicroMouseTemplate_DW.obj.isSetupComplete) {
      ADC_Handle_Deinit(MicroMouseTemplate_DW.obj.ADCHandle,
                        ADC_DMA_INTERRUPT_MODE, 1);
    }
  }

  /* End of Terminate for MATLABSystem: '<S50>/Analog to Digital Converter' */

  /* Terminate for MATLABSystem: '<S46>/PWM Output' */
  if (!MicroMouseTemplate_DW.obj_g.matlabCodegenIsDeleted) {
    MicroMouseTemplate_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((MicroMouseTemplate_DW.obj_g.isInitialized == 1) &&
        MicroMouseTemplate_DW.obj_g.isSetupComplete) {
      disableCounter(MicroMouseTemplate_DW.obj_g.TimerHandle);
      disableTimerInterrupts(MicroMouseTemplate_DW.obj_g.TimerHandle, 0);
      disableTimerChannel1(MicroMouseTemplate_DW.obj_g.TimerHandle, ENABLE_CH);
      disableTimerChannel2(MicroMouseTemplate_DW.obj_g.TimerHandle, ENABLE_CH);
    }
  }

  /* End of Terminate for MATLABSystem: '<S46>/PWM Output' */

  /* Terminate for MATLABSystem: '<S44>/PWM Output' */
  if (!MicroMouseTemplate_DW.obj_n.matlabCodegenIsDeleted) {
    MicroMouseTemplate_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((MicroMouseTemplate_DW.obj_n.isInitialized == 1) &&
        MicroMouseTemplate_DW.obj_n.isSetupComplete) {
      disableCounter(MicroMouseTemplate_DW.obj_n.TimerHandle);
      disableTimerInterrupts(MicroMouseTemplate_DW.obj_n.TimerHandle, 0);
      disableTimerChannel3(MicroMouseTemplate_DW.obj_n.TimerHandle, ENABLE_CH);
      disableTimerChannel4(MicroMouseTemplate_DW.obj_n.TimerHandle, ENABLE_CH);
    }
  }

  /* End of Terminate for MATLABSystem: '<S44>/PWM Output' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
