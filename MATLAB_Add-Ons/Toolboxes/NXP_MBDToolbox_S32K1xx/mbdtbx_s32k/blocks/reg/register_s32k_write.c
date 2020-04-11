/*-----------------------------------------------------------------------------
%
% Copyright (c) 2017 NXP.
% All rights reserved.
%
-----------------------------------------------------------------------------*/

#define S_FUNCTION_NAME  register_s32k_write
#define S_FUNCTION_LEVEL 2

#include <math.h>
#include "simstruc.h"

/*==============================================================================
' Function:
'
==============================================================================*/
static void mdlInitializeSizes(SimStruct *S)
/*============================================================================*/
{
    int_T size;

    /*------------------------------------
       Number of expected parameters
    --------------------------------------*/
    ssSetNumSFcnParams(S, 1);

    /*-----------------------------------------------------
       Parameter mismatch will be reported by Simulink
    --------------------------------------------------------*/
    if (ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S)) {
        return;
    }

     /*-------------------------
     Set the input/Output ports
    ---------------------------*/
    ssSetNumOutputPorts(S, 0); /* Define 0 outputs required */
    ssSetNumInputPorts(S, 1);  /* Define 1 inputs required */

    size = mxGetPr(ssGetSFcnParam(S, 0))[0];
    if (size == 8){
        ssSetInputPortDataType(S, 0, SS_UINT8);
    } else if (size == 16){
        ssSetInputPortDataType(S, 0, SS_UINT16);
    } else if (size == 32){
        ssSetInputPortDataType(S, 0, SS_UINT32);
    }
    ssSetInputPortWidth(S, 0, DYNAMICALLY_SIZED);
   /* ssSetInputPortWidth(S, 0, 1);*/
    ssSetInputPortDirectFeedThrough(S, 0, 1);
    ssSetInputPortRequiredContiguous(S,0, 1);

    /*---------------------------------------
        Set Work Sizes
    -------------------------------------------*/
    ssSetNumSampleTimes(S, 1);
    ssSetNumRWork(S, 0);
    ssSetNumPWork(S, 0);
    ssSetNumModes(S, 0);
    ssSetNumNonsampledZCs(S, 0);
    ssSetNumIWork(S, 0);

     /*------------------------------
       Set the number of states
    --------------------------------*/
    ssSetNumContStates(S, 0);
    ssSetNumDiscStates(S, 0);

    /*---------------------------------------
         Other OPtions for Code Generation
    ------------------------------------------*/
    ssSetOptions(S, SS_OPTION_SFUNCTION_INLINED_FOR_RTW     |
                    SS_OPTION_WORKS_WITH_CODE_REUSE         |
                    SS_OPTION_PLACE_ASAP                    |
                    SS_OPTION_DISALLOW_CONSTANT_SAMPLE_TIME |
                    SS_OPTION_RUNTIME_EXCEPTION_FREE_CODE   |
                    SS_OPTION_CAN_BE_CALLED_CONDITIONALLY   |
                    SS_OPTION_CALL_TERMINATE_ON_EXIT);
}



/*==============================================================================
' Function:
'           Call the Reset Function once.
==============================================================================*/
static void mdlOutputs(SimStruct *S, int_T tid)
/*============================================================================*/
{
    return;
}

/*==============================================================================
' Function:
'
==============================================================================*/
static void mdlInitializeSampleTimes(SimStruct *S)
/*============================================================================*/
{
    /*-------------------------
      Set the sample times
    ---------------------------*/
    ssSetSampleTime(S, 0, INHERITED_SAMPLE_TIME);
    ssSetOffsetTime(S, 0,  0.0);

    return;
}

/*==============================================================================
' Function:
'
==============================================================================*/
static void mdlInitializeConditions(SimStruct *S)
/*============================================================================*/
{
    return;
}

/*==============================================================================
' Function:
'
==============================================================================*/
static void mdlStart(SimStruct *S)
/*============================================================================*/
{
    /*--------------------------------------------
       Indicate that first time is incomplete
    ----------------------------------------------*/
    ssGetIWork(S)[0]=0;

    return;
}

/*==============================================================================
' Function:
'
==============================================================================*/
static void mdlUpdate(SimStruct *S, int_T tid)
/*============================================================================*/
{
    return;
}

/*==============================================================================
' Function:
'
==============================================================================*/
static void mdlDerivatives(SimStruct *S)
/*============================================================================*/
{
    return;
}

/*==============================================================================
' Function:
'
==============================================================================*/
static void mdlTerminate(SimStruct *S)
/*============================================================================*/
{
    return;
}

#ifdef  MATLAB_MEX_FILE    /* Is this file being compiled as a MEX-file? */
#include "simulink.c"      /* MEX-file interface mechanism */
#else
#include "cg_sfun.h"       /* Code generation registration function */
#endif
