/******************************************************************************
*
*   Copyright 2013-2015 Freescale Semiconductor
*   Copyright 2016-2019 NXP
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be used strictly in
*   accordance with the applicable license terms.  By expressly accepting such terms or by
*   downloading, installing, activating and/or otherwise using the software, you are agreeing that
*   you have read, and that you agree to comply with and are bound by, such license terms.  If you
*   do not agree to be bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
*
******************************************************************************/
/**
*
* @file       MLIB_Msu.h
*
* @version    1.0.50.0
*
* @date       17-April-2019
*
* @brief      Header file for MLIB_Msu function
*
******************************************************************************/
#ifndef MLIB_MSU_H
#define MLIB_MSU_H
/**
@if MLIB_GROUP
    @addtogroup MLIB_GROUP
@else
    @defgroup MLIB_GROUP   MLIB
@endif
*/

#ifdef __cplusplus
extern "C" {
#endif
/**
* @page misra_violations MISRA-C:2004 violations
* 
* @section MLIB_Msu_h_REF_1
* Violates MISRA 2004 Required Rule 19.4, Disallowed definition for macro. 
* To allow the user utilize the benefits of using all three supported implementation of each 
* function in user application, the macro dispatcher inevitably requires use of disallowed macro 
* definition. 
* 
* @section MLIB_Msu_h_REF_2
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined. 
* To allow the user utilize the benefits of using all three supported implementation of each 
* function in user application, the macro dispatcher inevitably requires the function-like macro 
* definition. 
* 
* @section MLIB_Msu_h_REF_3
* Violates MISRA 2004 Required Rule 19.10, Unparenthesized macro parameter in definition of macro. 
* To allow the user utilize the benefits of using all three supported implementation of each 
* function in user application, the macro dispatcher inevitably requires use of unparenthesized 
* macro parameters. 
* 
* @section MLIB_Msu_h_REF_4
* Violates MISRA 2004 Advisory Rule 19.13, #/##' operator used in macro. 
* To allow the user utilize the benefits of using all three supported implementation of each 
* function in user application, the macro dispatcher inevitably requires use of '#/##' operators. 
* 
* @section MLIB_Msu_h_REF_5
* Violates MISRA 2004 Required Rule 8.5, Object/function definition in header file. 
* Allowing the inline functions significantly increase the speed of the library thus the lowest 
* layer (MLIB) is implemented as inline. This approach removes the overhead caused by standard 
* function calling. 
*/
#include "SWLIBS_Defines.h"
#ifndef AMMCLIB_TESTING_ENV
  #include "MLIB_Sub.h"
  #include "MLIB_Mul.h"
  #include "MLIB_ConvertPU.h"
#else
  /* Following includes serve for NXP internal testing purposes only. 
  *  These headers are not part of the release. */
  #include "CCOV_MLIB_Sub.h"
  #include "CCOV_MLIB_Mul.h"
  #include "CCOV_MLIB_ConvertPU.h"
#endif

/****************************************************************************
* Defines and macros            (scope: module-local)
****************************************************************************/
#ifndef  _MATLAB_BAM_CREATE
  /*
  * @violates @ref MLIB_Msu_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition for macro. 
  * @violates @ref MLIB_Msu_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. 
  * @violates @ref MLIB_Msu_h_REF_3 MISRA 2004 Required Rule 19.10, Unparenthesized macro parameter 
  * in definition of macro. 
  */
  #define MLIB_Msu(...)     macro_dispatcher(MLIB_Msu, __VA_ARGS__)(__VA_ARGS__)     /* This function implements the multiply accumulate function. */

  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32)
    /*
    * @violates @ref MLIB_Msu_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition for 
    * macro. 
    * @violates @ref MLIB_Msu_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. 
    * @violates @ref MLIB_Msu_h_REF_3 MISRA 2004 Required Rule 19.10, Unparenthesized macro 
    * parameter in definition of macro. 
    */
    /* @remarks Implements DMLIB00271 */
    #define MLIB_Msu_Dsptchr_3(In1,In2,In3)     MLIB_Msu_Dsptchr_4(In1,In2,In3,F32)     /* Function dispatcher for MLIB_Msu_Dsptchr_4, do not modify!!! */
  #endif
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16)
    /*
    * @violates @ref MLIB_Msu_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition for 
    * macro. 
    * @violates @ref MLIB_Msu_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. 
    * @violates @ref MLIB_Msu_h_REF_3 MISRA 2004 Required Rule 19.10, Unparenthesized macro 
    * parameter in definition of macro. 
    */
    /* @remarks Implements DMLIB00271 */
    #define MLIB_Msu_Dsptchr_3(In1,In2,In3)     MLIB_Msu_Dsptchr_4(In1,In2,In3,F16)     /* Function dispatcher for MLIB_Msu_Dsptchr_4, do not modify!!! */
  #endif
#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT)
    /*
    * @violates @ref MLIB_Msu_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition for 
    * macro. 
    * @violates @ref MLIB_Msu_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. 
    * @violates @ref MLIB_Msu_h_REF_3 MISRA 2004 Required Rule 19.10, Unparenthesized macro 
    * parameter in definition of macro. 
    */
    /* @remarks Implements DMLIB00271 */
    #define MLIB_Msu_Dsptchr_3(In1,In2,In3)     MLIB_Msu_Dsptchr_4(In1,In2,In3,FLT)     /* Function dispatcher for MLIB_Msu_Dsptchr_4, do not modify!!! */
  #endif
#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */

  /*
  * @violates @ref MLIB_Msu_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition for macro. 
  * @violates @ref MLIB_Msu_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. 
  * @violates @ref MLIB_Msu_h_REF_3 MISRA 2004 Required Rule 19.10, Unparenthesized macro parameter 
  * in definition of macro. 
  */
  #define MLIB_Msu_Dsptchr_4(In1,In2,In3,Impl)    MLIB_Msu_Dsptchr_(In1,In2,In3,Impl)     /* Function dispatcher for MLIB_Msu_Dsptchr_5, do not modify!!! */

  /*
  * @violates @ref MLIB_Msu_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition for macro. 
  * @violates @ref MLIB_Msu_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. 
  * @violates @ref MLIB_Msu_h_REF_3 MISRA 2004 Required Rule 19.10, Unparenthesized macro parameter 
  * in definition of macro. 
  * @violates @ref MLIB_Msu_h_REF_4 MISRA 2004 Advisory Rule 19.13, #/##' operator used in macro. 
  */
  /* @remarks Implements DMLIB00273 */
  #define MLIB_Msu_Dsptchr_(In1,In2,In3,Impl)     MLIB_Msu_##Impl(In1,In2,In3)            /* Function dispatcher for MLIB_Msu_Dsptchr_, do not modify!!! */
#endif

/****************************************************************************
* Typedefs and structures       (scope: module-local)
****************************************************************************/

/****************************************************************************
* Exported function prototypes
****************************************************************************/

/****************************************************************************
* Inline functions
****************************************************************************/
INLINE tFrac32 Msu_F32_C(register tFrac32 f32In1,register tFrac32 f32In2,register tFrac32 f32In3)
/*
* @violates @ref MLIB_Msu_h_REF_5 MISRA 2004 Required Rule 8.5, Object/function definition in header
* file.
*/
{
  /*
  * @violates @ref MLIB_Msu_h_REF_5 MISRA 2004 Required Rule 8.5, Object/function definition in 
  * header file. 
  */
  tFrac32 f32Temp;

  f32Temp = MLIB_Mul_F32(f32In2,f32In3);
  return(MLIB_Sub_F32(f32In1, f32Temp));
} 
INLINE tFrac32 Msu_F32F16F16_C(register tFrac32 f32In1,register tFrac16 f16In2,register tFrac16 f16In3)
/*
* @violates @ref MLIB_Msu_h_REF_5 MISRA 2004 Required Rule 8.5, Object/function definition in header
* file.
*/
{
  /*
  * @violates @ref MLIB_Msu_h_REF_5 MISRA 2004 Required Rule 8.5, Object/function definition in 
  * header file. 
  */
  tFrac32 f32Temp;

  f32Temp = MLIB_Mul_F32F16F16(f16In2,f16In3);
  return(MLIB_Sub_F32(f32In1, f32Temp));
}

INLINE tFrac16 Msu_F16_C(register tFrac16 f16In1,register tFrac16 f16In2,register tFrac16 f16In3)
/*
* @violates @ref MLIB_Msu_h_REF_5 MISRA 2004 Required Rule 8.5, Object/function definition in header
* file.
*/
{
  /*
  * @violates @ref MLIB_Msu_h_REF_5 MISRA 2004 Required Rule 8.5, Object/function definition in
  * header file.
  */
  tFrac32 f32Temp;

  f32Temp = MLIB_Mul_F32F16F16(f16In2,f16In3);
  return(MLIB_ConvertPU_F16F32(MLIB_Sub_F32(MLIB_ConvertPU_F32F16(f16In1),f32Temp)));
}
#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
INLINE tFloat Msu_FLT_C(register tFloat fltIn1,register tFloat fltIn2,register tFloat fltIn3)
/*
* @violates @ref MLIB_Msu_h_REF_5 MISRA 2004 Required Rule 8.5, Object/function definition in header
* file.
*/
{
  return((tFloat)((tDouble)fltIn1 - ((tDouble)fltIn2 * (tDouble)fltIn3)));
}
#if (defined(__GNUC__) && defined(__ARM_EABI__))
  INLINE tFloat Msu_FLT_GCC_A32T32(register tFloat fltIn1,register tFloat fltIn2,register tFloat fltIn3)
/*
* @violates @ref MLIB_Msu_h_REF_5 MISRA 2004 Required Rule 8.5, Object/function definition in header
* file.
*/
  {
    /*
    * @violates @ref MLIB_Msu_h_REF_5 MISRA 2004 Required Rule 8.5, Object/function definition in
    * header file.
    */
    register tFloat fltReturn;
    fltReturn = fltIn1;
    __asm volatile(" vfms.f32 %0,%1,%2" : "+t"(fltReturn): "t"(fltIn2), "t"(fltIn3));
    return((tFloat)fltReturn);     
  }
#elif defined(__IAR_SYSTEMS_ICC__)
  /* [MCL-382] workaround for IAR bug */
  #pragma optimize=low    
  INLINE tFloat Msu_FLT_IAR_A32T32(register tFloat fltIn1,register tFloat fltIn2,register tFloat fltIn3)
/*
* @violates @ref MLIB_Msu_h_REF_5 MISRA 2004 Required Rule 8.5, Object/function definition in header
* file.
*/
  {
    /*
    * @violates @ref MLIB_Msu_h_REF_5 MISRA 2004 Required Rule 8.5, Object/function definition in
    * header file.
    */
    register tFloat fltReturn;
    fltReturn = fltIn1;
    __asm(" vfms.f32 %0,%1,%2" : "+t"(fltReturn): "t"(fltIn2), "t"(fltIn3));
    return((tFloat)fltReturn);     
  }
#elif defined(__ghs__)
#pragma ghs static_call 0
#pragma ghs extra_stack 0
  INLINE tFloat Msu_FLT_GHS_A32T32(register tFloat fltIn1,register tFloat fltIn2,register tFloat fltIn3)
/*
* @violates @ref MLIB_Msu_h_REF_5 MISRA 2004 Required Rule 8.5, Object/function definition in header
* file.
*/
  {
    /*
    * @violates @ref MLIB_Msu_h_REF_5 MISRA 2004 Required Rule 8.5, Object/function definition in
    * header file.
    */
    register tFloat fltReturn;
    fltReturn = fltIn1;
    #pragma ghs optasm
    asm(" vfms.f32 %0,%1,%2" : "+f"(fltReturn): "f"(fltIn2) "f"(fltIn3));
    return((tFloat)fltReturn);     
  }
#endif /* if defined(__IAR_SYSTEMS_ICC__) */
#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */





/****************************************************************************
* Implementation variant: 32-bit fractional
****************************************************************************/
/***************************************************************************/
/**
@ingroup    MLIB_GROUP

@functionality MLIB_Msu

@param[in]    f32In1     Input value from which to subtract.

@param[in]    f32In2     First value to be multiplied.

@param[in]    f32In3     Second value to be multiplied.

@return       First input value from which the multiplication result of the second and third
              input values is subtracted.

@details      The input values as well as output value is considered as 32-bit fractional values.
              The output saturation is not implemented in this function, thus in case the output
              value is outside the [-1, 1) interval, the output value will overflow.

              \par

              The output of the function is defined by the following simple equation:
              \anchor eq1_Msu_F32
              \image rtf msuF32Eq1.math "MLIB_Msu_F32_Eq1"

*/
/**
@note         Due to effectivity reason this function is implemented as inline, and thus is not ANSI-C compliant.
*/
/**

@par Code Example
\code
#include "mlib.h"

tFrac32 f32In1;
tFrac32 f32In2;
tFrac32 f32In3;
tFrac32 f32Out;

void main(void)
{
  // input1 value = 0.25
  f32In1 = FRAC32(0.25);

  // input2 value = 0.5
  f32In2 = FRAC32(0.5);

  // input3 value = 0.125
  f32In3 = FRAC32(0.125);

  // output should be FRAC32(0.1875) = 0x18000000
  f32Out = MLIB_Msu_F32(f32In1, f32In2, f32In3);

  // output should be FRAC32(0.1875) = 0x18000000
  f32Out = MLIB_Msu(f32In1, f32In2, f32In3, F32);

  // ##############################################################
  // Available only if 32-bit fractional implementation selected
  // as default
  // ##############################################################

  // output should be FRAC32(0.1875) = 0x18000000
  f32Out = MLIB_Msu(f32In1, f32In2, f32In3);
}
\endcode
****************************************************************************/
#if defined(__CWCC__) || defined(__MWERKS__)
#pragma always_inline on
#endif
/* @remarks Implements DMLIB00272, DMLIB00264, DMLIB00267, DMLIB00270 */
INLINE tFrac32 MLIB_Msu_F32(register tFrac32 f32In1,register tFrac32 f32In2,register tFrac32 f32In3)
/*
* @violates @ref MLIB_Msu_h_REF_5 MISRA 2004 Required Rule 8.5, Object/function definition in header 
* file. 
*/
{
  /* @remarks Implements DMLIB00268 */
  return(Msu_F32_C(f32In1,f32In2,f32In3)); 
}





/***************************************************************************/
/**
@ingroup    MLIB_GROUP

@functionality MLIB_Msu

@param[in]    f32In1     Input value from which to subtract.

@param[in]    f16In2     First value to be multiplied.

@param[in]    f16In3     Second value to be multiplied.

@return       First input value from which the multiplication result of the second and third
              input values is subtracted.

@details      The first input value as well as output value is considered as 32-bit fractional
              values. The second and third input values are considered as 16-bit fractional values.
              The output saturation is not implemented in this function, thus in case the output
              value is outside the [-1, 1) interval, the output value will overflow.

              \par

              The output of the function is defined by the following simple equation:
              \anchor eq1_Msu_F32F16F16
              \image rtf msuF32F16F16Eq1.math "MLIB_Msu_F32F16F16_Eq1"

              This implementation is available if 32-bit fractional implementations are enabled. However it is not
              possible to use the default implementation based function call, thus the implementation post-fix or additional
              parameter function call shall be used.

*/
/**
@note         Due to effectivity reason this function is implemented as inline, and thus is not ANSI-C compliant.
*/
/**

@par Code Example
\code
#include "mlib.h"

tFrac32 f32In1;
tFrac16 f16In2;
tFrac16 f16In3;
tFrac32 f32Out;

void main(void)
{
  // input1 value = 0.25
  f32In1 = FRAC32(0.25);

  // input2 value = 0.5
  f16In2 = FRAC16(0.5);

  // input3 value = 0.125
  f16In3 = FRAC16(0.125);

  // output should be FRAC32(0.1875) = 0x18000000
  f32Out = MLIB_Msu_F32F16F16(f32In1, f16In2, f16In3);

  // output should be FRAC32(0.1875) = 0x18000000
  f32Out = MLIB_Msu(f32In1, f32In2, f32In3, F32F16F16);

}
\endcode
****************************************************************************/
#if defined(__CWCC__) || defined(__MWERKS__)
#pragma always_inline on
#endif
/* @remarks Implements DMLIB00272, DMLIB00264, DMLIB00269, DMLIB00270 */
INLINE tFrac32 MLIB_Msu_F32F16F16(register tFrac32 f32In1,register tFrac16 f16In2,register tFrac16 f16In3)
/*
* @violates @ref MLIB_Msu_h_REF_5 MISRA 2004 Required Rule 8.5, Object/function definition in header 
* file. 
*/
{
  /* @remarks Implements DMLIB00268 */
  return(Msu_F32F16F16_C(f32In1,f16In2,f16In3));
}





/****************************************************************************
* Implementation variant: 16-bit fractional
****************************************************************************/
/***************************************************************************/
/**
@ingroup    MLIB_GROUP

@functionality MLIB_Msu

@param[in]    f16In1     Input value from which to subtract.

@param[in]    f16In2     First value to be multiplied.

@param[in]    f16In3     Second value to be multiplied.

@return       First input value from which the multiplication result of the second and third
              input values is subtracted.

@details      The input values as well as output value is considered as 16-bit fractional values.
              The output saturation is not implemented in this function, thus in case the output
              value is outside the [-1, 1) interval, the output value will overflow.

              \par

              The output of the function is defined by the following simple equation:
              \anchor eq1_Msu_F16
              \image rtf msuF16Eq1.math "MLIB_Msu_F16_Eq1"

@note         Due to effectivity reason this function is implemented as inline, and thus is not ANSI-C compliant.

@par Code Example
\code
#include "mlib.h"

tFrac16 f16In1;
tFrac16 f16In2;
tFrac16 f16In3;
tFrac16 f16Out;

void main(void)
{
  // input1 value = 0.25
  f16In1 = FRAC16(0.25);

  // input2 value = 0.5
  f16In2 = FRAC16(0.5);

  // input3 value = 0.125
  f16In3 = FRAC16(0.125);

  // output should be FRAC16(0.1875) = 0x1800
  f16Out = MLIB_Msu_F16(f16In1, f16In2, f16In3);

  // output should be FRAC16(0.1875) = 0x1800
  f16Out = MLIB_Msu(f16In1, f16In2, f16In3, F16);

  // ##############################################################
  // Available only if 16-bit fractional implementation selected
  // as default
  // ##############################################################

  // output should be FRAC16(0.1875) = 0x1800
  f16Out = MLIB_Msu(f16In1, f16In2, f16In3);
}
\endcode
****************************************************************************/
#if defined(__CWCC__) || defined(__MWERKS__)
#pragma always_inline on
#endif
/* @remarks Implements DMLIB00272, DMLIB00264, DMLIB00266, DMLIB00270 */
INLINE tFrac16 MLIB_Msu_F16(register tFrac16 f16In1,register tFrac16 f16In2,register tFrac16 f16In3)
/*
* @violates @ref MLIB_Msu_h_REF_5 MISRA 2004 Required Rule 8.5, Object/function definition in header 
* file. 
*/
{
  /* @remarks Implements DMLIB00268 */
  return(Msu_F16_C(f16In1,f16In2,f16In3));
}





#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
/****************************************************************************
* Implementation variant: Single precision floating point
****************************************************************************/
/***************************************************************************/
/**
@ingroup    MLIB_GROUP

@functionality MLIB_Msu

@param[in]    fltIn1     Input value from which to subtract.

@param[in]    fltIn2     First value to be multiplied.

@param[in]    fltIn3     Second value to be multiplied.

@return       First input value from which the multiplication result of the second and third
              input values is subtracted.

@details      The input values as well as output value are considered as single precision floating
              point data type. Intermediate results are computed in infinite precision.

              \par

              The output of the function is defined by the following simple equation:
              \anchor eq1_Msu_FLT
              \image rtf msuFLTEq1.math "MLIB_Msu_FLT_Eq1"

*/
/**
@note         The function may raise floating-point exceptions (invalid operation,
              overflow, underflow, inexact, input denormal). The floating-point unit must be enabled
              in CPACR register to prevent NOCP UsageFault exception.
*/
/**
@note         Due to effectivity reason this function is implemented as inline assembly, and thus is not ANSI-C compliant.
*/
/**

@par Code Example
\code
#include "mlib.h"

tFloat fltIn1;
tFloat fltIn2;
tFloat fltIn3;
tFloat fltOut;

void main(void)
{
  // input1 value = 1.150236353278160e-01
  fltIn1 = (tFloat)1.150236353278160e-01f;

  // input2 value = 9.057919383049011e-01
  fltIn2 = (tFloat)9.057919383049011e-01f;

  // input3 value = 1.269868165254593e-01
  fltIn3 = (tFloat)1.269868165254593e-01f;

  // output should be 6.4805139e-10
  fltOut = MLIB_Msu_FLT(fltIn1, fltIn2, fltIn3);

  // output should be 6.4805139e-10
  fltOut = MLIB_Msu(fltIn1, fltIn2, fltIn3, FLT);

  // ##############################################################
  // Available only if single precision floating point
  // implementation selected as default
  // ##############################################################

  // output should be 6.4805139e-10
  fltOut = MLIB_Msu(fltIn1, fltIn2, fltIn3);
}
\endcode
****************************************************************************/
#if defined(__CWCC__) || defined(__MWERKS__)
#pragma always_inline on
#endif
/* @remarks Implements DMLIB00272, DMLIB00264, DMLIB00265, DMLIB00270 */
INLINE tFloat MLIB_Msu_FLT(register tFloat fltIn1,register tFloat fltIn2,register tFloat fltIn3)
/*
* @violates @ref MLIB_Msu_h_REF_5 MISRA 2004 Required Rule 8.5, Object/function definition in header 
* file. 
*/
{
  #if (defined(__GNUC__) && defined(__ARM_EABI__))
    /* @remarks Implements DMLIB00268 */
    return(Msu_FLT_GCC_A32T32(fltIn1,fltIn2,fltIn3));
  #elif defined(__IAR_SYSTEMS_ICC__)
    /* @remarks Implements DMLIB00268 */
    return(Msu_FLT_IAR_A32T32(fltIn1,fltIn2,fltIn3));
  #elif defined(__ghs__)
    /* @remarks Implements DMLIB00268 */
    return(Msu_FLT_GHS_A32T32(fltIn1,fltIn2,fltIn3));
  #else
    /* @remarks Implements DMLIB00268 */
    return(Msu_FLT_C(fltIn1,fltIn2,fltIn3));
  #endif /* if defined (__IAR_SYSTEMS_ICC__) */
}


#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */
#ifdef __cplusplus
}
#endif

#endif /* MLIB_MSU_H */
