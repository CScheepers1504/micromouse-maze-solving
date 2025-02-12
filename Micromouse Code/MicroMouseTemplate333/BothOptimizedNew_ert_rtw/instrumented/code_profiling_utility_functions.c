/*
 * File: code_profiling_utility_functions.c
 *
 * Code generated for instrumentation.
 *
 */

#include "code_profiling_utility_functions.h"

/* Code instrumentation offset(s) for model BothOptimizedNew */
#define taskTimeStart_BothOptimizedNew_offset 0
#define taskTimeEnd_BothOptimizedNew_offset 0

/* Code instrumentation offset(s) for model BothOptimizedNew */

/* A function parameter may be intentionally unused */
#ifndef UNUSED_PARAMETER
# if defined(__LCC__)
#   define UNUSED_PARAMETER(x)
# else
#   define UNUSED_PARAMETER(x)         (void) (x)
# endif
#endif

void xilUploadProfilingData(uint32_T sectionId)
{
  code_profiling_atomic_read_store(sectionId);
}

/* For real-time, multitasking case this function is stubbed out. */
#define xilProfilingTimerFreezeInternal() {}

void xilProfilingTimerFreeze(void)
{
}

#define xilProfilingTimerUnFreezeInternal() {}

void xilProfilingTimerUnFreeze(void)
{
}

/* Tic/Toc methods for task profiling */
#define taskTimeStart(id)              { \
 xilUploadProfilingData(id); \
 xilProfilingTimerUnFreezeInternal(); \
}
#define taskTimeEnd(id)                { \
 uint32_T sectionIdNeg = id; \
 sectionIdNeg = ~sectionIdNeg; \
 xilProfilingTimerFreezeInternal(); \
 xilUploadProfilingData(sectionIdNeg); \
}

/* Code instrumentation method(s) for model BothOptimizedNew */
void taskTimeStart_BothOptimizedNew(uint32_T sectionId)
{
  taskTimeStart(taskTimeStart_BothOptimizedNew_offset + sectionId);
}

void taskTimeEnd_BothOptimizedNew(uint32_T sectionId)
{
  taskTimeEnd(taskTimeEnd_BothOptimizedNew_offset + sectionId);
}

/* Code instrumentation method(s) for model BothOptimizedNew */
