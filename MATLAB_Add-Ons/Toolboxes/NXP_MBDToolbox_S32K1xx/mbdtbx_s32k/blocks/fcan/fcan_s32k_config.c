/*-----------------------------------------------------------------------------
 *
 * Copyright Freescale Semiconductor Inc
 * 2014 All Rights Reserved
 *
 *-----------------------------------------------------------------------------*/

#define S_FUNCTION_NAME  fcan_s32k_config
#define S_FUNCTION_LEVEL 2

#include "simstruc.h"


static void mdlInitializeSizes(SimStruct *S)
{
    /* Number of expected parameters */
    ssSetNumSFcnParams(S, 0);

    /* Parameter mismatch will be reported by Simulink */
    if (ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S)) {
        return;
    }

    /* Set the Input/Output ports */
    ssSetNumInputPorts(S, 0);
    ssSetNumOutputPorts(S, 0);

    /* Set Work Sizes */
    ssSetNumSampleTimes(S, 1);
    ssSetNumRWork(S, 0);
    ssSetNumPWork(S, 0);
    ssSetNumModes(S, 0);
    ssSetNumNonsampledZCs(S, 0);
    ssSetNumIWork(S, 0);

    /* Set the number of states */
    ssSetNumContStates(S, 0);
    ssSetNumDiscStates(S, 0);

    /* Other Options for Code Generation */
    ssSetOptions(S, SS_OPTION_USE_TLC_WITH_ACCELERATOR      |
            SS_OPTION_SFUNCTION_INLINED_FOR_RTW     |
            SS_OPTION_WORKS_WITH_CODE_REUSE         |
            SS_OPTION_DISALLOW_CONSTANT_SAMPLE_TIME |
            SS_OPTION_RUNTIME_EXCEPTION_FREE_CODE   |
            SS_OPTION_CAN_BE_CALLED_CONDITIONALLY   |
            SS_OPTION_CALL_TERMINATE_ON_EXIT);
}


static void mdlOutputs(SimStruct *S, int_T tid)
{
    return;
}


static void mdlInitializeSampleTimes(SimStruct *S)
{
    /* Set the sample times */
    ssSetSampleTime(S, 0, INHERITED_SAMPLE_TIME);
    ssSetOffsetTime(S, 0, 0.0);
#if defined(ssSetModelReferenceSampleTimeDefaultInheritance)
    ssSetModelReferenceSampleTimeDefaultInheritance(S);
#endif

    return;
}


static void mdlInitializeConditions(SimStruct *S)
{
    return;
}


static void mdlStart(SimStruct *S)
{

    /* Indicate that first time is incomplete */
    ssGetIWork(S)[0] = 0;

    return;
}


static void mdlUpdate(SimStruct *S, int_T tid)
{
    return;
}


static void mdlDerivatives(SimStruct *S)
{
    return;
}


static void mdlTerminate(SimStruct *S)
{
    return;
}


#ifdef  MATLAB_MEX_FILE    /* Is this file being compiled as a MEX-file? */
#include "simulink.c"      /* MEX-file interface mechanism */
#else
#include "cg_sfun.h"       /* Code generation registration function */
#endif
