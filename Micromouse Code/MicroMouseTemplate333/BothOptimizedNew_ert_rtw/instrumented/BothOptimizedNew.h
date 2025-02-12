/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: BothOptimizedNew.h
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

#ifndef BothOptimizedNew_h_
#define BothOptimizedNew_h_
#ifndef BothOptimizedNew_COMMON_INCLUDES_
#define BothOptimizedNew_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "main.h"
#endif                                 /* BothOptimizedNew_COMMON_INCLUDES_ */

#include "BothOptimizedNew_types.h"
#include <stddef.h>
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* user code (top of header file) */
#include "MicroMouseProgramming\Core\Inc\IMU.h"
#include "MicroMouseProgramming\Core\Inc\CustomWhile.h"
#include "MicroMouseProgramming\Core\Inc\Motors.h"

/* Block signals for system '<S47>/MATLAB System1' */
typedef struct {
  real_T MATLABSystem1[25];            /* '<S47>/MATLAB System1' */
  real_T rtu_0[25];
} B_MATLABSystem1_BothOptimized_T;

/* Block states (default storage) for system '<S47>/MATLAB System1' */
typedef struct {
  CircularBuffer_BothOptimizedN_T obj; /* '<S47>/MATLAB System1' */
  boolean_T objisempty;                /* '<S47>/MATLAB System1' */
} DW_MATLABSystem1_BothOptimize_T;

/* Block signals for system '<S47>/MATLAB System3' */
typedef struct {
  real_T MATLABSystem3[10];            /* '<S47>/MATLAB System3' */
  real_T rtu_0[10];
} B_MATLABSystem3_BothOptimized_T;

/* Block states (default storage) for system '<S47>/MATLAB System3' */
typedef struct {
  CircularBuffer_BothOptimize_p_T obj; /* '<S47>/MATLAB System3' */
  boolean_T objisempty;                /* '<S47>/MATLAB System3' */
} DW_MATLABSystem3_BothOptimize_T;

/* Block signals (default storage) */
typedef struct {
  real_T previous_path[100];
  uint16_T CastToDouble[8];            /* '<S49>/Cast To Double' */
  GPIO_TypeDef * portNameLoc;
  real_T leftWheel;                    /* '<Root>/HelloMicroMouse!' */
  real_T rightWheel;                   /* '<Root>/HelloMicroMouse!' */
  uint16_T Flip[8];                    /* '<S6>/Flip' */
  real_T maxV;
  real_T maxV_m;
  real_T minV;
  real_T maxV_c;
  real_T maxV_k;
  boolean_T LED_FWD_LEFT;              /* '<Root>/HelloMicroMouse!' */
  boolean_T LED_DOWN_LEFT;             /* '<Root>/HelloMicroMouse!' */
  boolean_T LED1;                      /* '<Root>/HelloMicroMouse!' */
  boolean_T LED2;                      /* '<Root>/HelloMicroMouse!' */
  boolean_T LED_LEFT;                  /* '<Root>/HelloMicroMouse!' */
  boolean_T LED_RIGHT;                 /* '<Root>/HelloMicroMouse!' */
  boolean_T LED_DOWN_RIGHT;            /* '<Root>/HelloMicroMouse!' */
  boolean_T LED_FWD_RIGHT;             /* '<Root>/HelloMicroMouse!' */
  boolean_T LED0;                      /* '<Root>/HelloMicroMouse!' */
  B_MATLABSystem1_BothOptimized_T MATLABSystem6;/* '<S47>/MATLAB System1' */
  B_MATLABSystem1_BothOptimized_T MATLABSystem5;/* '<S47>/MATLAB System1' */
  B_MATLABSystem1_BothOptimized_T MATLABSystem4_c;/* '<S47>/MATLAB System1' */
  B_MATLABSystem1_BothOptimized_T MATLABSystem3_c;/* '<S47>/MATLAB System1' */
  B_MATLABSystem1_BothOptimized_T MATLABSystem2_ci;/* '<S47>/MATLAB System1' */
  B_MATLABSystem1_BothOptimized_T MATLABSystem1_ci;/* '<S47>/MATLAB System1' */
  B_MATLABSystem1_BothOptimized_T MATLABSystem2_c;/* '<S47>/MATLAB System1' */
  B_MATLABSystem1_BothOptimized_T MATLABSystem1_c;/* '<S47>/MATLAB System1' */
  B_MATLABSystem3_BothOptimized_T MATLABSystem4;/* '<S47>/MATLAB System3' */
  B_MATLABSystem3_BothOptimized_T MATLABSystem3;/* '<S47>/MATLAB System3' */
  B_MATLABSystem1_BothOptimized_T MATLABSystem2;/* '<S47>/MATLAB System1' */
  B_MATLABSystem1_BothOptimized_T MATLABSystem1;/* '<S47>/MATLAB System1' */
} B_BothOptimizedNew_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T SolvedAlgorithm[100];         /* '<Root>/HelloMicroMouse!' */
  real_T optimisedPath[100];           /* '<Root>/HelloMicroMouse!' */
  stm32cube_blocks_AnalogInput__T obj; /* '<S46>/Analog to Digital Converter' */
  stm32cube_blocks_PWMOutput_Bo_T obj_g;/* '<S42>/PWM Output' */
  stm32cube_blocks_PWMOutput_Bo_T obj_n;/* '<S40>/PWM Output' */
  real_T counter;                      /* '<Root>/HelloMicroMouse!' */
  real_T counter2;                     /* '<Root>/HelloMicroMouse!' */
  real_T R;                            /* '<Root>/HelloMicroMouse!' */
  real_T B;                            /* '<Root>/HelloMicroMouse!' */
  real_T checking;                     /* '<Root>/HelloMicroMouse!' */
  real_T index;                        /* '<Root>/HelloMicroMouse!' */
  real_T L;                            /* '<Root>/HelloMicroMouse!' */
  real_T next;                         /* '<Root>/HelloMicroMouse!' */
  real_T solved;                       /* '<Root>/HelloMicroMouse!' */
  real_T S;                            /* '<Root>/HelloMicroMouse!' */
  struct {
    uint_T is_c2_BothOptimizedNew:4;   /* '<Root>/HelloMicroMouse!' */
    uint_T is_Optimised:4;             /* '<Root>/HelloMicroMouse!' */
    uint_T is_Turns:4;                 /* '<Root>/HelloMicroMouse!' */
    uint_T is_LineFollowing:2;         /* '<Root>/HelloMicroMouse!' */
    uint_T is_active_c2_BothOptimizedNew:1;/* '<Root>/HelloMicroMouse!' */
  } bitsForTID0;

  uint16_T init_FWD_RIGHT;             /* '<Root>/HelloMicroMouse!' */
  uint16_T init_FWD_LEFT;              /* '<Root>/HelloMicroMouse!' */
  uint16_T DOWN_L_LIGHT;               /* '<Root>/HelloMicroMouse!' */
  uint16_T DOWN_R_DARK;                /* '<Root>/HelloMicroMouse!' */
  uint16_T DOWN_L_DARK;                /* '<Root>/HelloMicroMouse!' */
  uint16_T DOWN_R_LIGHT;               /* '<Root>/HelloMicroMouse!' */
  uint16_T sum_FWD_LEFT;               /* '<Root>/HelloMicroMouse!' */
  uint16_T sum_FWD_RIGHT;              /* '<Root>/HelloMicroMouse!' */
  uint16_T sum_LEFT;                   /* '<Root>/HelloMicroMouse!' */
  uint16_T sum_RIGHT;                  /* '<Root>/HelloMicroMouse!' */
  uint8_T temporalCounter_i1;          /* '<Root>/HelloMicroMouse!' */
  DW_MATLABSystem1_BothOptimize_T MATLABSystem6;/* '<S47>/MATLAB System1' */
  DW_MATLABSystem1_BothOptimize_T MATLABSystem5;/* '<S47>/MATLAB System1' */
  DW_MATLABSystem1_BothOptimize_T MATLABSystem4_c;/* '<S47>/MATLAB System1' */
  DW_MATLABSystem1_BothOptimize_T MATLABSystem3_c;/* '<S47>/MATLAB System1' */
  DW_MATLABSystem1_BothOptimize_T MATLABSystem2_ci;/* '<S47>/MATLAB System1' */
  DW_MATLABSystem1_BothOptimize_T MATLABSystem1_ci;/* '<S47>/MATLAB System1' */
  DW_MATLABSystem1_BothOptimize_T MATLABSystem2_c;/* '<S47>/MATLAB System1' */
  DW_MATLABSystem1_BothOptimize_T MATLABSystem1_c;/* '<S47>/MATLAB System1' */
  DW_MATLABSystem3_BothOptimize_T MATLABSystem4;/* '<S47>/MATLAB System3' */
  DW_MATLABSystem3_BothOptimize_T MATLABSystem3;/* '<S47>/MATLAB System3' */
  DW_MATLABSystem1_BothOptimize_T MATLABSystem2;/* '<S47>/MATLAB System1' */
  DW_MATLABSystem1_BothOptimize_T MATLABSystem1;/* '<S47>/MATLAB System1' */
} DW_BothOptimizedNew_T;

/* Parameters for system: '<S47>/MATLAB System1' */
struct P_MATLABSystem1_BothOptimized_T_ {
  real_T MATLABSystem1_InitialCondition;/* Expression: 0
                                         * Referenced by: '<S47>/MATLAB System1'
                                         */
};

/* Parameters for system: '<S47>/MATLAB System3' */
struct P_MATLABSystem3_BothOptimized_T_ {
  real_T MATLABSystem3_InitialCondition;/* Expression: 0
                                         * Referenced by: '<S47>/MATLAB System3'
                                         */
};

/* Parameters (default storage) */
struct P_BothOptimizedNew_T_ {
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S5>/Constant2'
                                        */
  real_T Switch3_Threshold;            /* Expression: 0
                                        * Referenced by: '<S5>/Switch3'
                                        */
  real_T Switch2_Threshold;            /* Expression: 0
                                        * Referenced by: '<S5>/Switch2'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S5>/Constant1'
                                        */
  real_T Switch1_Threshold;            /* Expression: 0
                                        * Referenced by: '<S5>/Switch1'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S5>/Switch'
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
  uint16_T DataStoreMemory1_InitialValue_j;
                          /* Computed Parameter: DataStoreMemory1_InitialValue_j
                           * Referenced by: '<S1>/Data Store Memory1'
                           */
  uint16_T Constant_Value_b;           /* Computed Parameter: Constant_Value_b
                                        * Referenced by: '<S44>/Constant'
                                        */
  uint16_T Constant1_Value_c;          /* Computed Parameter: Constant1_Value_c
                                        * Referenced by: '<S44>/Constant1'
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
  P_MATLABSystem1_BothOptimized_T MATLABSystem6;/* '<S47>/MATLAB System1' */
  P_MATLABSystem1_BothOptimized_T MATLABSystem5;/* '<S47>/MATLAB System1' */
  P_MATLABSystem1_BothOptimized_T MATLABSystem4_c;/* '<S47>/MATLAB System1' */
  P_MATLABSystem1_BothOptimized_T MATLABSystem3_c;/* '<S47>/MATLAB System1' */
  P_MATLABSystem1_BothOptimized_T MATLABSystem2_ci;/* '<S47>/MATLAB System1' */
  P_MATLABSystem1_BothOptimized_T MATLABSystem1_ci;/* '<S47>/MATLAB System1' */
  P_MATLABSystem1_BothOptimized_T MATLABSystem2_c;/* '<S47>/MATLAB System1' */
  P_MATLABSystem1_BothOptimized_T MATLABSystem1_c;/* '<S47>/MATLAB System1' */
  P_MATLABSystem3_BothOptimized_T MATLABSystem4;/* '<S47>/MATLAB System3' */
  P_MATLABSystem3_BothOptimized_T MATLABSystem3;/* '<S47>/MATLAB System3' */
  P_MATLABSystem1_BothOptimized_T MATLABSystem2;/* '<S47>/MATLAB System1' */
  P_MATLABSystem1_BothOptimized_T MATLABSystem1;/* '<S47>/MATLAB System1' */
};

/* Code_Instrumentation_Declarations_Placeholder */

/* Real-time Model Data Structure */
struct tag_RTM_BothOptimizedNew_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern P_BothOptimizedNew_T BothOptimizedNew_P;

/* Block signals (default storage) */
extern B_BothOptimizedNew_T BothOptimizedNew_B;

/* Block states (default storage) */
extern DW_BothOptimizedNew_T BothOptimizedNew_DW;

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

/* Model entry point functions */
extern void BothOptimizedNew_initialize(void);
extern void BothOptimizedNew_step(void);
extern void BothOptimizedNew_terminate(void);

/* Real-time Model object */
extern RT_MODEL_BothOptimizedNew_T *const BothOptimizedNew_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S44>/Cast1' : Eliminate redundant data type conversion
 * Block '<S44>/Cast3' : Eliminate redundant data type conversion
 * Block '<S49>/Rate Transition' : Eliminated since input and output rates are identical
 * Block '<S49>/Rate Transition1' : Eliminated since input and output rates are identical
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
 * '<Root>' : 'BothOptimizedNew'
 * '<S1>'   : 'BothOptimizedNew/Detections and Thresholds'
 * '<S2>'   : 'BothOptimizedNew/GPIO for IR LEDs'
 * '<S3>'   : 'BothOptimizedNew/HelloMicroMouse!'
 * '<S4>'   : 'BothOptimizedNew/IR LED Pattern'
 * '<S5>'   : 'BothOptimizedNew/Motors'
 * '<S6>'   : 'BothOptimizedNew/Subsystem'
 * '<S7>'   : 'BothOptimizedNew/Subsystem1'
 * '<S8>'   : 'BothOptimizedNew/Subsystem2'
 * '<S9>'   : 'BothOptimizedNew/Subsystem3'
 * '<S10>'  : 'BothOptimizedNew/GPIO for IR LEDs/LED_DOWN_LEFT'
 * '<S11>'  : 'BothOptimizedNew/GPIO for IR LEDs/LED_DOWN_RIGHT'
 * '<S12>'  : 'BothOptimizedNew/GPIO for IR LEDs/LED_FWD_LEFT'
 * '<S13>'  : 'BothOptimizedNew/GPIO for IR LEDs/LED_FWD_RIGHT'
 * '<S14>'  : 'BothOptimizedNew/GPIO for IR LEDs/LED_LEFT'
 * '<S15>'  : 'BothOptimizedNew/GPIO for IR LEDs/LED_MOT_LEFT'
 * '<S16>'  : 'BothOptimizedNew/GPIO for IR LEDs/LED_MOT_RIGHT'
 * '<S17>'  : 'BothOptimizedNew/GPIO for IR LEDs/LED_RIGHT'
 * '<S18>'  : 'BothOptimizedNew/GPIO for IR LEDs/LED_DOWN_LEFT/ECSoC'
 * '<S19>'  : 'BothOptimizedNew/GPIO for IR LEDs/LED_DOWN_LEFT/ECSoC/ECSimCodegen'
 * '<S20>'  : 'BothOptimizedNew/GPIO for IR LEDs/LED_DOWN_RIGHT/ECSoC'
 * '<S21>'  : 'BothOptimizedNew/GPIO for IR LEDs/LED_DOWN_RIGHT/ECSoC/ECSimCodegen'
 * '<S22>'  : 'BothOptimizedNew/GPIO for IR LEDs/LED_FWD_LEFT/ECSoC'
 * '<S23>'  : 'BothOptimizedNew/GPIO for IR LEDs/LED_FWD_LEFT/ECSoC/ECSimCodegen'
 * '<S24>'  : 'BothOptimizedNew/GPIO for IR LEDs/LED_FWD_RIGHT/ECSoC'
 * '<S25>'  : 'BothOptimizedNew/GPIO for IR LEDs/LED_FWD_RIGHT/ECSoC/ECSimCodegen'
 * '<S26>'  : 'BothOptimizedNew/GPIO for IR LEDs/LED_LEFT/ECSoC'
 * '<S27>'  : 'BothOptimizedNew/GPIO for IR LEDs/LED_LEFT/ECSoC/ECSimCodegen'
 * '<S28>'  : 'BothOptimizedNew/GPIO for IR LEDs/LED_MOT_LEFT/ECSoC'
 * '<S29>'  : 'BothOptimizedNew/GPIO for IR LEDs/LED_MOT_LEFT/ECSoC/ECSimCodegen'
 * '<S30>'  : 'BothOptimizedNew/GPIO for IR LEDs/LED_MOT_RIGHT/ECSoC'
 * '<S31>'  : 'BothOptimizedNew/GPIO for IR LEDs/LED_MOT_RIGHT/ECSoC/ECSimCodegen'
 * '<S32>'  : 'BothOptimizedNew/GPIO for IR LEDs/LED_RIGHT/ECSoC'
 * '<S33>'  : 'BothOptimizedNew/GPIO for IR LEDs/LED_RIGHT/ECSoC/ECSimCodegen'
 * '<S34>'  : 'BothOptimizedNew/Motors/MOTOR_EN'
 * '<S35>'  : 'BothOptimizedNew/Motors/PWM Output'
 * '<S36>'  : 'BothOptimizedNew/Motors/PWM Output1'
 * '<S37>'  : 'BothOptimizedNew/Motors/MOTOR_EN/ECSoC'
 * '<S38>'  : 'BothOptimizedNew/Motors/MOTOR_EN/ECSoC/ECSimCodegen'
 * '<S39>'  : 'BothOptimizedNew/Motors/PWM Output/ECSoC'
 * '<S40>'  : 'BothOptimizedNew/Motors/PWM Output/ECSoC/ECSimCodegen'
 * '<S41>'  : 'BothOptimizedNew/Motors/PWM Output1/ECSoC'
 * '<S42>'  : 'BothOptimizedNew/Motors/PWM Output1/ECSoC/ECSimCodegen'
 * '<S43>'  : 'BothOptimizedNew/Subsystem/ADC2 IN10  IN1'
 * '<S44>'  : 'BothOptimizedNew/Subsystem/get Highs and Lows'
 * '<S45>'  : 'BothOptimizedNew/Subsystem/ADC2 IN10  IN1/ECSoC'
 * '<S46>'  : 'BothOptimizedNew/Subsystem/ADC2 IN10  IN1/ECSoC/ECSimCodegen'
 * '<S47>'  : 'BothOptimizedNew/Subsystem/get Highs and Lows/Subsystem'
 * '<S48>'  : 'BothOptimizedNew/Subsystem/get Highs and Lows/Subsystem1'
 * '<S49>'  : 'BothOptimizedNew/Subsystem/get Highs and Lows/Subsystem2'
 * '<S50>'  : 'BothOptimizedNew/Subsystem2/CTRL_LEDs'
 * '<S51>'  : 'BothOptimizedNew/Subsystem2/LED_0'
 * '<S52>'  : 'BothOptimizedNew/Subsystem2/LED_1'
 * '<S53>'  : 'BothOptimizedNew/Subsystem2/LED_2'
 * '<S54>'  : 'BothOptimizedNew/Subsystem2/CTRL_LEDs/ECSoC'
 * '<S55>'  : 'BothOptimizedNew/Subsystem2/CTRL_LEDs/ECSoC/ECSimCodegen'
 * '<S56>'  : 'BothOptimizedNew/Subsystem2/LED_0/ECSoC'
 * '<S57>'  : 'BothOptimizedNew/Subsystem2/LED_0/ECSoC/ECSimCodegen'
 * '<S58>'  : 'BothOptimizedNew/Subsystem2/LED_1/ECSoC'
 * '<S59>'  : 'BothOptimizedNew/Subsystem2/LED_1/ECSoC/ECSimCodegen'
 * '<S60>'  : 'BothOptimizedNew/Subsystem2/LED_2/ECSoC'
 * '<S61>'  : 'BothOptimizedNew/Subsystem2/LED_2/ECSoC/ECSimCodegen'
 * '<S62>'  : 'BothOptimizedNew/Subsystem3/SW_1'
 * '<S63>'  : 'BothOptimizedNew/Subsystem3/SW_2'
 * '<S64>'  : 'BothOptimizedNew/Subsystem3/SW_1/ECSoC'
 * '<S65>'  : 'BothOptimizedNew/Subsystem3/SW_1/ECSoC/ECSimCodegen'
 * '<S66>'  : 'BothOptimizedNew/Subsystem3/SW_2/ECSoC'
 * '<S67>'  : 'BothOptimizedNew/Subsystem3/SW_2/ECSoC/ECSimCodegen'
 */
#endif                                 /* BothOptimizedNew_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
