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
* @file       GFLIB_VLog10.h
*
* @version    1.0.3.0
*
* @date       17-April-2019
*
* @brief      Header file for GFLIB_VLog10 function
*
******************************************************************************/
#ifndef GFLIB_VLOG10_H
#define GFLIB_VLOG10_H

#ifdef __cplusplus
extern "C" {
#endif

/**
* @page misra_violations MISRA-C:2004 violations
* 
* @section GFLIB_VLog10_h_REF_1
* Violates MISRA 2004 Required Rule 19.4, Disallowed definition for macro. 
* To allow the user utilize the benefits of using all three supported implementation of each 
* function in user application, the macro dispatcher inevitably requires use of disallowed macro 
* definition. 
* 
* @section GFLIB_VLog10_h_REF_2
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined. 
* To allow the user utilize the benefits of using all three supported implementation of each 
* function in user application, the macro dispatcher inevitably requires the function-like macro 
* definition. 
* 
* @section GFLIB_VLog10_h_REF_3
* Violates MISRA 2004 Required Rule 19.10, Unparenthesized macro parameter in definition of macro. 
* To allow the user utilize the benefits of using all three supported implementation of each 
* function in user application, the macro dispatcher inevitably requires use of unparenthesized 
* macro parameters. 
* 
* @section GFLIB_VLog10_h_REF_4
* Violates MISRA 2004 Advisory Rule 19.13, #/##' operator used in macro. 
* To allow the user utilize the benefits of using all three supported implementation of each 
* function in user application, the macro dispatcher inevitably requires use of '#/##' operators. 
*/
#include "SWLIBS_Typedefs.h"
#include "SWLIBS_Defines.h"
#include "SWLIBS_MacroDisp.h"
#include "mlib.h"
#include "GFLIB_Sqrt.h"

/****************************************************************************
* Defines and macros            (scope: module-local)
****************************************************************************/
#ifndef  _MATLAB_BAM_CREATE
  /*
  * @violates @ref GFLIB_VLog10_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition for 
  * macro. 
  * @violates @ref GFLIB_VLog10_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. 
  * @violates @ref GFLIB_VLog10_h_REF_3 MISRA 2004 Required Rule 19.10, Unparenthesized macro 
  * parameter in definition of macro. 
  */
  #define GFLIB_VLog10(...)     macro_dispatcher(GFLIB_VLog10, __VA_ARGS__)(__VA_ARGS__)

  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT)
    /*
    * @violates @ref GFLIB_VLog10_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition for 
    * macro. 
    */
    #define GFLIB_VLOG10_T                        GFLIB_VLOG10_T_FLT                           /**< Definition of GFLIB_VLOG10_T as alias for GFLIB_VLOG10_T_FLT datatype in case the single precision floating point implementation is selected. */
    /*
    * @violates @ref GFLIB_VLog10_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition for 
    * macro. 
    */
    #define GFLIB_VLOG10_DEFAULT                  GFLIB_VLOG10_DEFAULT_FLT                     /**< Definition of GFLIB_VLOG10_DEFAULT as alias for GFLIB_VLOG10_DEFAULT_FLT default value in case the single precision floating point implementation is selected. */
    /*
    * @violates @ref GFLIB_VLog10_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition for 
    * macro. 
    * @violates @ref GFLIB_VLog10_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. 
    * @violates @ref GFLIB_VLog10_h_REF_3 MISRA 2004 Required Rule 19.10, Unparenthesized macro 
    * parameter in definition of macro. 
    */
    #define GFLIB_VLog10_Dsptchr_3(pInOut,N,pParam)     GFLIB_VLog10_Dsptchr_4(pInOut,N,pParam,FLT)        /* Function dispatcher for GFLIB_VLog10_Dsptchr_3, do not modify!!! */
    /*
    * @violates @ref GFLIB_VLog10_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition for 
    * macro. 
    * @violates @ref GFLIB_VLog10_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. 
    * @violates @ref GFLIB_VLog10_h_REF_3 MISRA 2004 Required Rule 19.10, Unparenthesized macro 
    * parameter in definition of macro. 
    */
    /* @remarks Implements DGFLIB00347 */
    #define GFLIB_VLog10_Dsptchr_2(pInOut,N)            GFLIB_VLog10_Dsptchr_3(pInOut,N,GFLIB_VLOG10_DEFAULT) /* Function dispatcher for GFLIB_VLog10_Dsptchr_2, do not modify!!! */
  #endif

  /*
  * @violates @ref GFLIB_VLog10_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition for 
  * macro. 
  * @violates @ref GFLIB_VLog10_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. 
  * @violates @ref GFLIB_VLog10_h_REF_3 MISRA 2004 Required Rule 19.10, Unparenthesized macro 
  * parameter in definition of macro. 
  */
  #define GFLIB_VLog10_Dsptchr_4(pInOut,N,pParam,Impl)    GFLIB_VLog10_Dsptchr_(pInOut,N,pParam,Impl)     /* Function dispatcher for GFLIB_VLog10_Dsptchr_4, do not modify!!! */
  
  /*
  * @violates @ref GFLIB_VLog10_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition for 
  * macro. 
  * @violates @ref GFLIB_VLog10_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. 
  * @violates @ref GFLIB_VLog10_h_REF_3 MISRA 2004 Required Rule 19.10, Unparenthesized macro 
  * parameter in definition of macro. 
  * @violates @ref GFLIB_VLog10_h_REF_4 MISRA 2004 Advisory Rule 19.13, #/##' operator used in macro. 
  */
  /* @remarks Implements DGFLIB00349 */
  #define GFLIB_VLog10_Dsptchr_(pInOut,N,pParam,Impl)     GFLIB_VLog10_##Impl(pInOut,N,pParam)            /* Function dispatcher for GFLIB_VLog10_Dsptchr_, do not modify!!! */
#endif
 
/****************************************************************************
* Typedefs and structures       (scope: module-local)
****************************************************************************/




/****************************************************************************
* Implementation variant: Single precision floating point
****************************************************************************/
#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
  /*
  * @violates @ref GFLIB_VLog10_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition for macro. 
  */
  #define GFLIB_VLOG10_DEFAULT_FLT &fltgflibVLog10Coef     /**< Default approximation coefficients for GFLIB_VLog10_FLT function. */

  /************************************************************************/
  /**
  @struct GFLIB_VLOG10_T_FLT "\GFLIB_VLog10.h" 

  @brief  Array of single precision floating point elements for storing the coefficients of the
          floating point log10 approximation polynomial.
  *//**********************************************************************/
  typedef struct{
    tFloat  fltA[5];
  }GFLIB_VLOG10_T_FLT;
  
  /************************************************************************/
  /**
  @brief  Default approximation coefficients for cosine approximation.
  *//**********************************************************************/
  extern const GFLIB_VLOG10_T_FLT fltgflibVLog10Coef;

  /****************************************************************************
  * Exported function prototypes
  ****************************************************************************/
  extern void GFLIB_VLog10_FLT(tFloat *pInOut, tU32 u32N, const GFLIB_VLOG10_T_FLT *const pParam);

#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */
/****************************************************************************
* Inline functions
****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* GFLIB_VLOG10_H */
