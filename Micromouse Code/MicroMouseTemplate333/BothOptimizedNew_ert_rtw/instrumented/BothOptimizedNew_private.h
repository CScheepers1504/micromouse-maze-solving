/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: BothOptimizedNew_private.h
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

#ifndef BothOptimizedNew_private_h_
#define BothOptimizedNew_private_h_
#include "rtwtypes.h"
#include "BothOptimizedNew.h"
#include "BothOptimizedNew_types.h"

extern real_T rt_roundd(real_T u);
extern void BothOptimize_MATLABSystem1_Init(DW_MATLABSystem1_BothOptimize_T
  *localDW, P_MATLABSystem1_BothOptimized_T *localP);
extern void BothOptimizedNew_MATLABSystem1(real_T rtu_0,
  B_MATLABSystem1_BothOptimized_T *localB, DW_MATLABSystem1_BothOptimize_T
  *localDW, P_MATLABSystem1_BothOptimized_T *localP);
extern void BothOptimize_MATLABSystem3_Init(DW_MATLABSystem3_BothOptimize_T
  *localDW, P_MATLABSystem3_BothOptimized_T *localP);
extern void BothOptimizedNew_MATLABSystem3(real_T rtu_0,
  B_MATLABSystem3_BothOptimized_T *localB, DW_MATLABSystem3_BothOptimize_T
  *localDW, P_MATLABSystem3_BothOptimized_T *localP);

#endif                                 /* BothOptimizedNew_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
