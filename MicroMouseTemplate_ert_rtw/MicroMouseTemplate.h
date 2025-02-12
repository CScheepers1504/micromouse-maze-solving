/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: MicroMouseTemplate.h
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

#ifndef MicroMouseTemplate_h_
#define MicroMouseTemplate_h_
#ifndef MicroMouseTemplate_COMMON_INCLUDES_
#define MicroMouseTemplate_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "main.h"
#endif                                 /* MicroMouseTemplate_COMMON_INCLUDES_ */

#include "MicroMouseTemplate_types.h"
#include <stddef.h>
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* user code (top of header file) */
#include "MicroMouseProgramming\Core\Inc\IMU.h"
#include "MicroMouseProgramming\Core\Inc\CustomWhile.h"
#include "MicroMouseProgramming\Core\Inc\Motors.h"

/* Block signals for system '<S51>/MATLAB System1' */
typedef struct {
  real_T MATLABSystem1[25];            /* '<S51>/MATLAB System1' */
  real_T rtu_0[25];
} B_MATLABSystem1_MicroMouseTem_T;

/* Block states (default storage) for system '<S51>/MATLAB System1' */
typedef struct {
  CircularBuffer_MicroMouseTemp_T obj; /* '<S51>/MATLAB System1' */
  boolean_T objisempty;                /* '<S51>/MATLAB System1' */
} DW_MATLABSystem1_MicroMouseTe_T;

/* Block signals for system '<S51>/MATLAB System3' */
typedef struct {
  real_T MATLABSystem3[10];            /* '<S51>/MATLAB System3' */
  real_T rtu_0[10];
} B_MATLABSystem3_MicroMouseTem_T;

/* Block states (default storage) for system '<S51>/MATLAB System3' */
typedef struct {
  CircularBuffer_MicroMouseTe_p_T obj; /* '<S51>/MATLAB System3' */
  boolean_T objisempty;                /* '<S51>/MATLAB System3' */
} DW_MATLABSystem3_MicroMouseTe_T;

/* Block signals (default storage) */
typedef struct {
  uint16_T CastToDouble[8];            /* '<S53>/Cast To Double' */
  GPIO_TypeDef * portNameLoc;
  real_T rightWheel;                   /* '<S37>/rightWheel' */
  real_T rightWheel_c;                 /* '<S36>/rightWheel' */
  real_T leftWheel;                    /* '<S35>/leftWheel' */
  real_T leftWheel_d;                  /* '<S34>/leftWheel' */
  real_T leftWheel_k;                  /* '<Root>/HelloMicroMouse!' */
  real_T rightWheel_f;                 /* '<Root>/HelloMicroMouse!' */
  real_T LED_FWD_LS;                   /* '<Root>/HelloMicroMouse!' */
  real_T LED_FWD_RS;                   /* '<Root>/HelloMicroMouse!' */
  real_T LED_LS;                       /* '<Root>/HelloMicroMouse!' */
  real_T LED_RS;                       /* '<Root>/HelloMicroMouse!' */
  uint16_T Flip[8];                    /* '<S6>/Flip' */
  real_T maxV;
  real_T minV;
  real_T maxV_m;
  boolean_T LED1;                      /* '<Root>/HelloMicroMouse!' */
  boolean_T LED2;                      /* '<Root>/HelloMicroMouse!' */
  boolean_T LED0;                      /* '<Root>/HelloMicroMouse!' */
  B_MATLABSystem1_MicroMouseTem_T MATLABSystem6;/* '<S51>/MATLAB System1' */
  B_MATLABSystem1_MicroMouseTem_T MATLABSystem5;/* '<S51>/MATLAB System1' */
  B_MATLABSystem1_MicroMouseTem_T MATLABSystem4_c;/* '<S51>/MATLAB System1' */
  B_MATLABSystem1_MicroMouseTem_T MATLABSystem3_c;/* '<S51>/MATLAB System1' */
  B_MATLABSystem1_MicroMouseTem_T MATLABSystem2_ci;/* '<S51>/MATLAB System1' */
  B_MATLABSystem1_MicroMouseTem_T MATLABSystem1_ci;/* '<S51>/MATLAB System1' */
  B_MATLABSystem1_MicroMouseTem_T MATLABSystem2_c;/* '<S51>/MATLAB System1' */
  B_MATLABSystem1_MicroMouseTem_T MATLABSystem1_c;/* '<S51>/MATLAB System1' */
  B_MATLABSystem3_MicroMouseTem_T MATLABSystem4;/* '<S51>/MATLAB System3' */
  B_MATLABSystem3_MicroMouseTem_T MATLABSystem3;/* '<S51>/MATLAB System3' */
  B_MATLABSystem1_MicroMouseTem_T MATLABSystem2;/* '<S51>/MATLAB System1' */
  B_MATLABSystem1_MicroMouseTem_T MATLABSystem1;/* '<S51>/MATLAB System1' */
} B_MicroMouseTemplate_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  stm32cube_blocks_AnalogInput__T obj; /* '<S50>/Analog to Digital Converter' */
  stm32cube_blocks_PWMOutput_Mi_T obj_g;/* '<S46>/PWM Output' */
  stm32cube_blocks_PWMOutput_Mi_T obj_n;/* '<S44>/PWM Output' */
  real_T RateTransition_Buffer;        /* '<S53>/Rate Transition' */
  real_T RateTransition1_Buffer;       /* '<S53>/Rate Transition1' */
  real_T normal_speed_RIGHT;           /* '<Root>/HelloMicroMouse!' */
  real_T normal_speed_LEFT;            /* '<Root>/HelloMicroMouse!' */
  real_T counter;                      /* '<Root>/HelloMicroMouse!' */
  real_T timer;                        /* '<Root>/HelloMicroMouse!' */
  real_T crossroadCondition;           /* '<Root>/HelloMicroMouse!' */
  real_T LEDtimer;                     /* '<Root>/HelloMicroMouse!' */
  real_T processDone;                  /* '<Root>/HelloMicroMouse!' */
  real_T LEDtimer1;                    /* '<Root>/HelloMicroMouse!' */
  int32_T clockTickCounter;            /* '<S4>/Pulse Generator9' */
  int32_T clockTickCounter_i;          /* '<S4>/Pulse Generator10' */
  struct {
    uint_T is_c2_MicroMouseTemplate:3; /* '<Root>/HelloMicroMouse!' */
    uint_T is_ButtonPressed3:3;        /* '<Root>/HelloMicroMouse!' */
    uint_T is_Driving:2;               /* '<Root>/HelloMicroMouse!' */
    uint_T is_active_c2_MicroMouseTemplate:1;/* '<Root>/HelloMicroMouse!' */
    uint_T rightClear:1;               /* '<Root>/HelloMicroMouse!' */
    uint_T leftClear:1;                /* '<Root>/HelloMicroMouse!' */
    uint_T frontClear:1;               /* '<Root>/HelloMicroMouse!' */
  } bitsForTID1;

  volatile uint16_T TmpRTBAtMaxofElementsOutport1_B;/* synthesized block */
  volatile uint16_T TmpRTBAtMaxofElements7Outport1_;/* synthesized block */
  volatile uint16_T TmpRTBAtMaxofElements8Outport1_;/* synthesized block */
  volatile uint16_T TmpRTBAtMaxofElements15Outport1;/* synthesized block */
  uint16_T init_DOWN_L_LIGHT;          /* '<Root>/HelloMicroMouse!' */
  uint16_T thresh_DOWN_LEFT;           /* '<Root>/HelloMicroMouse!' */
  uint16_T init_DOWN_R_DARK;           /* '<Root>/HelloMicroMouse!' */
  uint16_T init_DOWN_L_DARK;           /* '<Root>/HelloMicroMouse!' */
  uint16_T thresh_DOWN_RIGHT;          /* '<Root>/HelloMicroMouse!' */
  uint16_T init_DOWN_R_LIGHT;          /* '<Root>/HelloMicroMouse!' */
  uint16_T sum_FWD_LEFT;               /* '<Root>/HelloMicroMouse!' */
  uint16_T sum_FWD_RIGHT;              /* '<Root>/HelloMicroMouse!' */
  uint16_T init_FWD_LEFT;              /* '<Root>/HelloMicroMouse!' */
  uint16_T init_FWD_RIGHT;             /* '<Root>/HelloMicroMouse!' */
  uint16_T thresh_DOWN_AVG;            /* '<Root>/HelloMicroMouse!' */
  uint16_T thresh_FWD_L;               /* '<Root>/HelloMicroMouse!' */
  uint16_T thresh_FWD_R;               /* '<Root>/HelloMicroMouse!' */
  uint16_T thresh_LEFT;                /* '<Root>/HelloMicroMouse!' */
  uint16_T thresh_RIGHT;               /* '<Root>/HelloMicroMouse!' */
  uint16_T init_LEFT_CLOSE;            /* '<Root>/HelloMicroMouse!' */
  uint16_T init_LEFT_FAR;              /* '<Root>/HelloMicroMouse!' */
  uint16_T init_RIGHT_CLOSE;           /* '<Root>/HelloMicroMouse!' */
  uint16_T init_RIGHT_FAR;             /* '<Root>/HelloMicroMouse!' */
  int8_T If1_ActiveSubsystem;          /* '<S5>/If1' */
  int8_T If_ActiveSubsystem;           /* '<S5>/If' */
  uint8_T temporalCounter_i1;          /* '<Root>/HelloMicroMouse!' */
  DW_MATLABSystem1_MicroMouseTe_T MATLABSystem6;/* '<S51>/MATLAB System1' */
  DW_MATLABSystem1_MicroMouseTe_T MATLABSystem5;/* '<S51>/MATLAB System1' */
  DW_MATLABSystem1_MicroMouseTe_T MATLABSystem4_c;/* '<S51>/MATLAB System1' */
  DW_MATLABSystem1_MicroMouseTe_T MATLABSystem3_c;/* '<S51>/MATLAB System1' */
  DW_MATLABSystem1_MicroMouseTe_T MATLABSystem2_ci;/* '<S51>/MATLAB System1' */
  DW_MATLABSystem1_MicroMouseTe_T MATLABSystem1_ci;/* '<S51>/MATLAB System1' */
  DW_MATLABSystem1_MicroMouseTe_T MATLABSystem2_c;/* '<S51>/MATLAB System1' */
  DW_MATLABSystem1_MicroMouseTe_T MATLABSystem1_c;/* '<S51>/MATLAB System1' */
  DW_MATLABSystem3_MicroMouseTe_T MATLABSystem4;/* '<S51>/MATLAB System3' */
  DW_MATLABSystem3_MicroMouseTe_T MATLABSystem3;/* '<S51>/MATLAB System3' */
  DW_MATLABSystem1_MicroMouseTe_T MATLABSystem2;/* '<S51>/MATLAB System1' */
  DW_MATLABSystem1_MicroMouseTe_T MATLABSystem1;/* '<S51>/MATLAB System1' */
} DW_MicroMouseTemplate_T;

/* Parameters for system: '<S51>/MATLAB System1' */
struct P_MATLABSystem1_MicroMouseTem_T_ {
  real_T MATLABSystem1_InitialCondition;/* Expression: 0
                                         * Referenced by: '<S51>/MATLAB System1'
                                         */
};

/* Parameters for system: '<S51>/MATLAB System3' */
struct P_MATLABSystem3_MicroMouseTem_T_ {
  real_T MATLABSystem3_InitialCondition;/* Expression: 0
                                         * Referenced by: '<S51>/MATLAB System3'
                                         */
};

/* Parameters (default storage) */
struct P_MicroMouseTemplate_T_ {
  real_T Out1_Y0;                      /* Expression: 0
                                        * Referenced by: '<S34>/Out1'
                                        */
  real_T Out1_Y0_j;                    /* Expression: 0
                                        * Referenced by: '<S35>/Out1'
                                        */
  real_T Out1_Y0_d;                    /* Expression: 0
                                        * Referenced by: '<S36>/Out1'
                                        */
  real_T Out1_Y0_a;                    /* Expression: 0
                                        * Referenced by: '<S37>/Out1'
                                        */
  real_T PulseGenerator9_Amp;          /* Expression: 1
                                        * Referenced by: '<S4>/Pulse Generator9'
                                        */
  real_T PulseGenerator9_Period;   /* Computed Parameter: PulseGenerator9_Period
                                    * Referenced by: '<S4>/Pulse Generator9'
                                    */
  real_T PulseGenerator9_Duty;       /* Computed Parameter: PulseGenerator9_Duty
                                      * Referenced by: '<S4>/Pulse Generator9'
                                      */
  real_T PulseGenerator9_PhaseDelay;   /* Expression: 0
                                        * Referenced by: '<S4>/Pulse Generator9'
                                        */
  real_T PulseGenerator10_Amp;         /* Expression: 1
                                        * Referenced by: '<S4>/Pulse Generator10'
                                        */
  real_T PulseGenerator10_Period; /* Computed Parameter: PulseGenerator10_Period
                                   * Referenced by: '<S4>/Pulse Generator10'
                                   */
  real_T PulseGenerator10_Duty;     /* Computed Parameter: PulseGenerator10_Duty
                                     * Referenced by: '<S4>/Pulse Generator10'
                                     */
  real_T PulseGenerator10_PhaseDelay;  /* Expression: 0
                                        * Referenced by: '<S4>/Pulse Generator10'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S5>/Constant'
                                        */
  real_T Constant_Value_i;             /* Expression: 1
                                        * Referenced by: '<S8>/Constant'
                                        */
  int32_T DataStoreMemory2_InitialValue;
                            /* Computed Parameter: DataStoreMemory2_InitialValue
                             * Referenced by: '<S1>/Data Store Memory2'
                             */
  int32_T DataStoreMemory4_InitialValue;
                            /* Computed Parameter: DataStoreMemory4_InitialValue
                             * Referenced by: '<S1>/Data Store Memory4'
                             */
  real32_T DataStoreMemory_InitialValue;
                             /* Computed Parameter: DataStoreMemory_InitialValue
                              * Referenced by: '<S7>/Data Store Memory'
                              */
  real32_T DataStoreMemory1_InitialValue;
                            /* Computed Parameter: DataStoreMemory1_InitialValue
                             * Referenced by: '<S7>/Data Store Memory1'
                             */
  uint16_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<Root>/Gain'
                                        */
  uint16_T DataStoreMemory1_InitialValue_j;
                          /* Computed Parameter: DataStoreMemory1_InitialValue_j
                           * Referenced by: '<S1>/Data Store Memory1'
                           */
  uint16_T TmpRTBAtMaxofElementsOutport1_I;
                          /* Computed Parameter: TmpRTBAtMaxofElementsOutport1_I
                           * Referenced by:
                           */
  uint16_T TmpRTBAtMaxofElements7Outport1_;
                          /* Computed Parameter: TmpRTBAtMaxofElements7Outport1_
                           * Referenced by:
                           */
  uint16_T Constant_Value_b;           /* Computed Parameter: Constant_Value_b
                                        * Referenced by: '<S48>/Constant'
                                        */
  uint16_T TmpRTBAtMaxofElements8Outport1_;
                          /* Computed Parameter: TmpRTBAtMaxofElements8Outport1_
                           * Referenced by:
                           */
  uint16_T TmpRTBAtMaxofElements15Outport1;
                          /* Computed Parameter: TmpRTBAtMaxofElements15Outport1
                           * Referenced by:
                           */
  uint16_T Constant1_Value;            /* Computed Parameter: Constant1_Value
                                        * Referenced by: '<S48>/Constant1'
                                        */
  uint16_T DataStoreMemory_InitialValue_p;
                           /* Computed Parameter: DataStoreMemory_InitialValue_p
                            * Referenced by: '<S6>/Data Store Memory'
                            */
  uint16_T DataStoreMemory1_InitialValue_p;
                          /* Computed Parameter: DataStoreMemory1_InitialValue_p
                           * Referenced by: '<S6>/Data Store Memory1'
                           */
  uint16_T DataStoreMemory2_InitialValue_p;
                          /* Computed Parameter: DataStoreMemory2_InitialValue_p
                           * Referenced by: '<S6>/Data Store Memory2'
                           */
  boolean_T DataStoreMemory_InitialValue_p4;
                          /* Computed Parameter: DataStoreMemory_InitialValue_p4
                           * Referenced by: '<S1>/Data Store Memory'
                           */
  P_MATLABSystem1_MicroMouseTem_T MATLABSystem6;/* '<S51>/MATLAB System1' */
  P_MATLABSystem1_MicroMouseTem_T MATLABSystem5;/* '<S51>/MATLAB System1' */
  P_MATLABSystem1_MicroMouseTem_T MATLABSystem4_c;/* '<S51>/MATLAB System1' */
  P_MATLABSystem1_MicroMouseTem_T MATLABSystem3_c;/* '<S51>/MATLAB System1' */
  P_MATLABSystem1_MicroMouseTem_T MATLABSystem2_ci;/* '<S51>/MATLAB System1' */
  P_MATLABSystem1_MicroMouseTem_T MATLABSystem1_ci;/* '<S51>/MATLAB System1' */
  P_MATLABSystem1_MicroMouseTem_T MATLABSystem2_c;/* '<S51>/MATLAB System1' */
  P_MATLABSystem1_MicroMouseTem_T MATLABSystem1_c;/* '<S51>/MATLAB System1' */
  P_MATLABSystem3_MicroMouseTem_T MATLABSystem4;/* '<S51>/MATLAB System3' */
  P_MATLABSystem3_MicroMouseTem_T MATLABSystem3;/* '<S51>/MATLAB System3' */
  P_MATLABSystem1_MicroMouseTem_T MATLABSystem2;/* '<S51>/MATLAB System1' */
  P_MATLABSystem1_MicroMouseTem_T MATLABSystem1;/* '<S51>/MATLAB System1' */
};

/* Code_Instrumentation_Declarations_Placeholder */

/* Real-time Model Data Structure */
struct tag_RTM_MicroMouseTemplate_T {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID[3];
    } TaskCounters;

    struct {
      boolean_T TID1_2;
    } RateInteraction;
  } Timing;
};

/* Block parameters (default storage) */
extern P_MicroMouseTemplate_T MicroMouseTemplate_P;

/* Block signals (default storage) */
extern B_MicroMouseTemplate_T MicroMouseTemplate_B;

/* Block states (default storage) */
extern DW_MicroMouseTemplate_T MicroMouseTemplate_DW;

/*
 * Exported States
 *
 * Note: Exported states are block states with an exported global
 * storage class designation.  Code generation will declare the memory for these
 * states and exports their symbols.
 *
 */
extern real32_T IMU_Accel[3];          /* '<S7>/Data Store Memory' */
extern real32_T IMU_Gyro[3];           /* '<S7>/Data Store Memory1' */
extern int32_T currTicksRS;            /* '<S1>/Data Store Memory2' */
extern int32_T currTicksLS;            /* '<S1>/Data Store Memory4' */
extern uint16_T Thresholds[8];         /* '<S1>/Data Store Memory1' */
extern uint16_T ADC1s[9];              /* '<S6>/Data Store Memory' */
extern uint16_T ADC_H[9];              /* '<S6>/Data Store Memory1' */
extern uint16_T ADC_L[9];              /* '<S6>/Data Store Memory2' */
extern boolean_T Detections[8];        /* '<S1>/Data Store Memory' */

/* External function called from main */
extern void MicroMouseTemplate_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void MicroMouseTemplate_initialize(void);
extern void MicroMouseTemplate_step0(void);
extern void MicroMouseTemplate_step1(void);
extern void MicroMouseTemplate_step2(void);
extern void MicroMouseTemplate_terminate(void);

/* Real-time Model object */
extern RT_MODEL_MicroMouseTemplate_T *const MicroMouseTemplate_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S4>/Pulse Generator11' : Unused code path elimination
 * Block '<S4>/Pulse Generator12' : Unused code path elimination
 * Block '<S4>/Pulse Generator13' : Unused code path elimination
 * Block '<S4>/Pulse Generator8' : Unused code path elimination
 * Block '<S48>/Cast1' : Eliminate redundant data type conversion
 * Block '<S48>/Cast3' : Eliminate redundant data type conversion
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'MicroMouseTemplate'
 * '<S1>'   : 'MicroMouseTemplate/Detections and Thresholds'
 * '<S2>'   : 'MicroMouseTemplate/GPIO for IR LEDs'
 * '<S3>'   : 'MicroMouseTemplate/HelloMicroMouse!'
 * '<S4>'   : 'MicroMouseTemplate/IR LED Pattern'
 * '<S5>'   : 'MicroMouseTemplate/Motors'
 * '<S6>'   : 'MicroMouseTemplate/Subsystem'
 * '<S7>'   : 'MicroMouseTemplate/Subsystem1'
 * '<S8>'   : 'MicroMouseTemplate/Subsystem2'
 * '<S9>'   : 'MicroMouseTemplate/Subsystem3'
 * '<S10>'  : 'MicroMouseTemplate/GPIO for IR LEDs/LED_DOWN_LEFT'
 * '<S11>'  : 'MicroMouseTemplate/GPIO for IR LEDs/LED_DOWN_RIGHT'
 * '<S12>'  : 'MicroMouseTemplate/GPIO for IR LEDs/LED_FWD_LEFT'
 * '<S13>'  : 'MicroMouseTemplate/GPIO for IR LEDs/LED_FWD_RIGHT'
 * '<S14>'  : 'MicroMouseTemplate/GPIO for IR LEDs/LED_LEFT'
 * '<S15>'  : 'MicroMouseTemplate/GPIO for IR LEDs/LED_MOT_LEFT'
 * '<S16>'  : 'MicroMouseTemplate/GPIO for IR LEDs/LED_MOT_RIGHT'
 * '<S17>'  : 'MicroMouseTemplate/GPIO for IR LEDs/LED_RIGHT'
 * '<S18>'  : 'MicroMouseTemplate/GPIO for IR LEDs/LED_DOWN_LEFT/ECSoC'
 * '<S19>'  : 'MicroMouseTemplate/GPIO for IR LEDs/LED_DOWN_LEFT/ECSoC/ECSimCodegen'
 * '<S20>'  : 'MicroMouseTemplate/GPIO for IR LEDs/LED_DOWN_RIGHT/ECSoC'
 * '<S21>'  : 'MicroMouseTemplate/GPIO for IR LEDs/LED_DOWN_RIGHT/ECSoC/ECSimCodegen'
 * '<S22>'  : 'MicroMouseTemplate/GPIO for IR LEDs/LED_FWD_LEFT/ECSoC'
 * '<S23>'  : 'MicroMouseTemplate/GPIO for IR LEDs/LED_FWD_LEFT/ECSoC/ECSimCodegen'
 * '<S24>'  : 'MicroMouseTemplate/GPIO for IR LEDs/LED_FWD_RIGHT/ECSoC'
 * '<S25>'  : 'MicroMouseTemplate/GPIO for IR LEDs/LED_FWD_RIGHT/ECSoC/ECSimCodegen'
 * '<S26>'  : 'MicroMouseTemplate/GPIO for IR LEDs/LED_LEFT/ECSoC'
 * '<S27>'  : 'MicroMouseTemplate/GPIO for IR LEDs/LED_LEFT/ECSoC/ECSimCodegen'
 * '<S28>'  : 'MicroMouseTemplate/GPIO for IR LEDs/LED_MOT_LEFT/ECSoC'
 * '<S29>'  : 'MicroMouseTemplate/GPIO for IR LEDs/LED_MOT_LEFT/ECSoC/ECSimCodegen'
 * '<S30>'  : 'MicroMouseTemplate/GPIO for IR LEDs/LED_MOT_RIGHT/ECSoC'
 * '<S31>'  : 'MicroMouseTemplate/GPIO for IR LEDs/LED_MOT_RIGHT/ECSoC/ECSimCodegen'
 * '<S32>'  : 'MicroMouseTemplate/GPIO for IR LEDs/LED_RIGHT/ECSoC'
 * '<S33>'  : 'MicroMouseTemplate/GPIO for IR LEDs/LED_RIGHT/ECSoC/ECSimCodegen'
 * '<S34>'  : 'MicroMouseTemplate/Motors/If Action Subsystem'
 * '<S35>'  : 'MicroMouseTemplate/Motors/If Action Subsystem1'
 * '<S36>'  : 'MicroMouseTemplate/Motors/If Action Subsystem2'
 * '<S37>'  : 'MicroMouseTemplate/Motors/If Action Subsystem3'
 * '<S38>'  : 'MicroMouseTemplate/Motors/MOTOR_EN'
 * '<S39>'  : 'MicroMouseTemplate/Motors/PWM Output'
 * '<S40>'  : 'MicroMouseTemplate/Motors/PWM Output1'
 * '<S41>'  : 'MicroMouseTemplate/Motors/MOTOR_EN/ECSoC'
 * '<S42>'  : 'MicroMouseTemplate/Motors/MOTOR_EN/ECSoC/ECSimCodegen'
 * '<S43>'  : 'MicroMouseTemplate/Motors/PWM Output/ECSoC'
 * '<S44>'  : 'MicroMouseTemplate/Motors/PWM Output/ECSoC/ECSimCodegen'
 * '<S45>'  : 'MicroMouseTemplate/Motors/PWM Output1/ECSoC'
 * '<S46>'  : 'MicroMouseTemplate/Motors/PWM Output1/ECSoC/ECSimCodegen'
 * '<S47>'  : 'MicroMouseTemplate/Subsystem/ADC2 IN10  IN1'
 * '<S48>'  : 'MicroMouseTemplate/Subsystem/get Highs and Lows'
 * '<S49>'  : 'MicroMouseTemplate/Subsystem/ADC2 IN10  IN1/ECSoC'
 * '<S50>'  : 'MicroMouseTemplate/Subsystem/ADC2 IN10  IN1/ECSoC/ECSimCodegen'
 * '<S51>'  : 'MicroMouseTemplate/Subsystem/get Highs and Lows/Subsystem'
 * '<S52>'  : 'MicroMouseTemplate/Subsystem/get Highs and Lows/Subsystem1'
 * '<S53>'  : 'MicroMouseTemplate/Subsystem/get Highs and Lows/Subsystem2'
 * '<S54>'  : 'MicroMouseTemplate/Subsystem2/CTRL_LEDs'
 * '<S55>'  : 'MicroMouseTemplate/Subsystem2/LED_0'
 * '<S56>'  : 'MicroMouseTemplate/Subsystem2/LED_1'
 * '<S57>'  : 'MicroMouseTemplate/Subsystem2/LED_2'
 * '<S58>'  : 'MicroMouseTemplate/Subsystem2/CTRL_LEDs/ECSoC'
 * '<S59>'  : 'MicroMouseTemplate/Subsystem2/CTRL_LEDs/ECSoC/ECSimCodegen'
 * '<S60>'  : 'MicroMouseTemplate/Subsystem2/LED_0/ECSoC'
 * '<S61>'  : 'MicroMouseTemplate/Subsystem2/LED_0/ECSoC/ECSimCodegen'
 * '<S62>'  : 'MicroMouseTemplate/Subsystem2/LED_1/ECSoC'
 * '<S63>'  : 'MicroMouseTemplate/Subsystem2/LED_1/ECSoC/ECSimCodegen'
 * '<S64>'  : 'MicroMouseTemplate/Subsystem2/LED_2/ECSoC'
 * '<S65>'  : 'MicroMouseTemplate/Subsystem2/LED_2/ECSoC/ECSimCodegen'
 * '<S66>'  : 'MicroMouseTemplate/Subsystem3/SW_1'
 * '<S67>'  : 'MicroMouseTemplate/Subsystem3/SW_2'
 * '<S68>'  : 'MicroMouseTemplate/Subsystem3/SW_1/ECSoC'
 * '<S69>'  : 'MicroMouseTemplate/Subsystem3/SW_1/ECSoC/ECSimCodegen'
 * '<S70>'  : 'MicroMouseTemplate/Subsystem3/SW_2/ECSoC'
 * '<S71>'  : 'MicroMouseTemplate/Subsystem3/SW_2/ECSoC/ECSimCodegen'
 */
#endif                                 /* MicroMouseTemplate_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
