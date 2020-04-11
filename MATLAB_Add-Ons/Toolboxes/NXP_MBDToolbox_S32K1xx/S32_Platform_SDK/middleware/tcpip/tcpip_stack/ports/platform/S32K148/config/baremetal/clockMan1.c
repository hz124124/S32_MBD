/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : clockMan1.c
**     Project     : lwip_s32k148
**     Processor   : S32K148_144
**     Component   : clock_manager
**     Version     : Component SDK_S32K14x_09, Driver 01.00, CPU db: 3.00.000
**     Repository  : SDK_S32K14x_09
**     Compiler    : GNU C Compiler
**     Date/Time   : 2017-10-26, 17:06, # CodeGen: 0
**
**     Copyright 1997 - 2015 Freescale Semiconductor, Inc.
**     Copyright 2016-2017 NXP
**     All Rights Reserved.
**
**     THIS SOFTWARE IS PROVIDED BY NXP "AS IS" AND ANY EXPRESSED OR
**     IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
**     OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
**     IN NO EVENT SHALL NXP OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
**     INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
**     SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
**     HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
**     STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
**     IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
**     THE POSSIBILITY OF SUCH DAMAGE.
** ###################################################################*/
/*!
** @file clockMan1.c
** @version 01.00
*/
/*!
**  @addtogroup clockMan1_module clockMan1 module documentation
**  @{
*/

/* clockMan1. */

#include "clockMan1.h"

/**
 * @page misra_violations MISRA-C:2012 violations
 *
 * @section [global]
 * Violates MISRA 2012 Required Rule 9.4, Duplicate initialization of object element.
 * It's the only way to initialize an array that is member of struct.
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 8.7, External variable could be made static.
 * The external variables will be used in other source files in application code.
 */

/* *************************************************************************
 * Configuration structure for peripheral clock configuration 0
 * ************************************************************************* */
/*! @brief peripheral clock configuration 0 */
peripheral_clock_config_t peripheralClockConfig0[NUM_OF_PERIPHERAL_CLOCKS_0] = {
    {
        .clockName        = ENET0_CLK,
        .clkGate          = true,
        .clkSrc           = CLK_SRC_FIRC_DIV1,
        .frac             = MULTIPLY_BY_ONE,
        .divider          = DIVIDE_BY_ONE,
    },
    {
        .clockName        = PORTA_CLK,
        .clkGate          = true,
        .clkSrc           = CLK_SRC_OFF,
        .frac             = MULTIPLY_BY_ONE,
        .divider          = DIVIDE_BY_ONE,
    },
    {
        .clockName        = PORTB_CLK,
        .clkGate          = true,
        .clkSrc           = CLK_SRC_OFF,
        .frac             = MULTIPLY_BY_ONE,
        .divider          = DIVIDE_BY_ONE,
    },
    {
        .clockName        = PORTC_CLK,
        .clkGate          = true,
        .clkSrc           = CLK_SRC_OFF,
        .frac             = MULTIPLY_BY_ONE,
        .divider          = DIVIDE_BY_ONE,
    },
    {
        .clockName        = PORTD_CLK,
        .clkGate          = true,
        .clkSrc           = CLK_SRC_OFF,
        .frac             = MULTIPLY_BY_ONE,
        .divider          = DIVIDE_BY_ONE,
    },
    {
        .clockName        = PORTE_CLK,
        .clkGate          = true,
        .clkSrc           = CLK_SRC_OFF,
        .frac             = MULTIPLY_BY_ONE,
        .divider          = DIVIDE_BY_ONE,
    },
    {
        .clockName        = RTC0_CLK,
        .clkGate          = true,
        .clkSrc           = CLK_SRC_OFF,
        .frac             = MULTIPLY_BY_ONE,
        .divider          = DIVIDE_BY_ONE,
    },
};

/* *************************************************************************
 * Configuration structure for Clock Configuration 0
 * ************************************************************************* */
/*! @brief User Configuration structure clockMan1_InitConfig0 */
clock_manager_user_config_t clockMan1_InitConfig0 = {
    /*! @brief Configuration of SIRC */
    .scgConfig =
    {
        .sircConfig =
        {
            .initialize       = true,                                /*!< Initialize */
            /* SIRCCSR */
            .enableInStop     = false,                               /*!< SIRCSTEN  */
            .enableInLowPower = true,                                /*!< SIRCLPEN  */
            .locked           = false,                               /*!< LK        */
            /* SIRCCFG */
            .range            = SCG_SIRC_RANGE_HIGH,                 /*!< RANGE - High range (8 MHz) */
            /* SIRCDIV */
            .div1             = SCG_ASYNC_CLOCK_DIV_BY_1,            /*!< SIRCDIV1  */
            .div2             = SCG_ASYNC_CLOCK_DIV_BY_1,            /*!< SIRCDIV2  */
        },
        .fircConfig =
        {
            .initialize       = true,                                /*!< Initialize */
            /* FIRCCSR */
            .regulator        = true,                                /*!< FIRCREGOFF */
            .locked           = false,                               /*!< LK         */
            /* FIRCCFG */
            .range            = SCG_FIRC_RANGE_48M,                  /*!< RANGE      */
            /* FIRCDIV */
            .div1             = SCG_ASYNC_CLOCK_DIV_BY_1,            /*!< FIRCDIV1   */
            .div2             = SCG_ASYNC_CLOCK_DIV_BY_1,            /*!< FIRCDIV2   */
        },
        .rtcConfig =
        {
            .initialize       = true,                                /*!< Initialize  */
            .rtcClkInFreq     = 0U,                                  /*!< RTC_CLKIN   */
        },
        .soscConfig =
        {
            .initialize       = true,                                /*!< Initialize */
            .freq             = 8000000U,                            /*!< Frequency  */
            /* SOSCCSR */
            .monitorMode      = SCG_SOSC_MONITOR_DISABLE,            /*!< SOSCCM      */
            .locked           = false,                               /*!< LK          */
            /* SOSCCFG */
            .extRef           = SCG_SOSC_REF_OSC,                    /*!< EREFS       */
            .gain             = SCG_SOSC_GAIN_LOW,                   /*!< HGO         */
            .range            = SCG_SOSC_RANGE_MID,                  /*!< RANGE       */
            /* SOSCDIV */
            .div1             = SCG_ASYNC_CLOCK_DIV_BY_1,            /*!< SOSCDIV1    */
            .div2             = SCG_ASYNC_CLOCK_DIV_BY_1,            /*!< SOSCDIV2    */
        },
        .spllConfig =
        {
            .initialize       = true,                                /*!< Initialize */
            /* SPLLCSR */
            .monitorMode      = SCG_SPLL_MONITOR_DISABLE,            /*!< SPLLCM     */
            .locked           = false,                               /*!< LK         */
            /* SPLLCFG */
            .prediv           = SCG_SPLL_CLOCK_PREDIV_BY_1,          /*!< PREDIV     */
            .mult             = SCG_SPLL_CLOCK_MULTIPLY_BY_40,       /*!< MULT       */
            .src              = 0U,                                  /*!< SOURCE     */
            /* SPLLDIV */
            .div1             = SCG_ASYNC_CLOCK_DIV_BY_1,            /*!< SPLLDIV1   */
            .div2             = SCG_ASYNC_CLOCK_DIV_BY_1,            /*!< SPLLDIV2   */
        },
        .clockOutConfig =
        {
            .initialize       = true,                                /*!< Initialize    */
            .source           = SCG_CLOCKOUT_SRC_FIRC,               /*!< SCG CLKOUTSEL     */
        },
        .clockModeConfig =
        {
            .initialize       = true,                                /*!< Initialize */
            .rccrConfig =              /*!< RCCR - Run Clock Control Register          */
            {
                .src          = SCG_SYSTEM_CLOCK_SRC_SYS_PLL,        /*!< SCS        */
                .divCore      = SCG_SYSTEM_CLOCK_DIV_BY_2,           /*!< DIVCORE    */
                .divBus       = SCG_SYSTEM_CLOCK_DIV_BY_2,           /*!< DIVBUS     */
                .divSlow      = SCG_SYSTEM_CLOCK_DIV_BY_3,           /*!< DIVSLOW    */
            },
            .vccrConfig =              /*!< VCCR - VLPR Clock Control Register         */
            {
                .src          = SCG_SYSTEM_CLOCK_SRC_SIRC,           /*!< SCS        */
                .divCore      = SCG_SYSTEM_CLOCK_DIV_BY_2,           /*!< DIVCORE    */
                .divBus       = SCG_SYSTEM_CLOCK_DIV_BY_1,           /*!< DIVBUS     */
                .divSlow      = SCG_SYSTEM_CLOCK_DIV_BY_4,           /*!< DIVSLOW    */
            },
            .hccrConfig =              /*!< HCCR - HSRUN Clock Control Register        */
            {
                .src          = SCG_SYSTEM_CLOCK_SRC_SYS_PLL,        /*!< SCS        */
                .divCore      = SCG_SYSTEM_CLOCK_DIV_BY_2,           /*!< DIVCORE    */
                .divBus       = SCG_SYSTEM_CLOCK_DIV_BY_2,           /*!< DIVBUS     */
                .divSlow      = SCG_SYSTEM_CLOCK_DIV_BY_3,           /*!< DIVSLOW    */
            },
        },
    },
    .pccConfig =
    {
        .peripheralClocks = peripheralClockConfig0,                  /*!< Peripheral clock control configurations  */
        .count = NUM_OF_PERIPHERAL_CLOCKS_0,                         /*!< Number of the peripheral clock control configurations  */
    },
    .simConfig =
    {
        .clockOutConfig =              /*!< Clock Out configuration.           */
        {
            .initialize       = true,                                /*!< Initialize    */
            .enable           = false,                               /*!< CLKOUTEN      */
            .source           = SIM_CLKOUT_SEL_SYSTEM_SCG_CLKOUT,    /*!< CLKOUTSEL     */
            .divider          = SIM_CLKOUT_DIV_BY_1,                 /*!< CLKOUTDIV     */
        },
        .lpoClockConfig =              /*!< Low Power Clock configuration.     */
        {
            .initialize       = true,                                /*!< Initialize    */
            .enableLpo1k      = true,                                /*!< LPO1KCLKEN    */
            .enableLpo32k     = true,                                /*!< LPO32KCLKEN   */
            .sourceLpoClk     = SIM_LPO_CLK_SEL_LPO_128K,            /*!< LPOCLKSEL     */
            .sourceRtcClk     = SIM_RTCCLK_SEL_LPO_32K,              /*!< RTCCLKSEL     */
        },
        .platGateConfig =              /*!< Platform Gate Clock configuration. */
        {
            .initialize       = true,                                /*!< Initialize    */
            .enableMscm       = true,                                /*!< CGCMSCM       */
            .enableMpu        = true,                                /*!< CGCMPU        */
            .enableDma        = true,                                /*!< CGCDMA        */
            .enableErm        = true,                                /*!< CGCERM        */
            .enableEim        = true,                                /*!< CGCEIM        */
        },

        .qspiRefClkGating =            /*!< Quad Spi Internal Reference Clock Gating. */
        {
            .enableQspiRefClk  = false,                              /*!< Qspi reference clock gating    */
        },
        .tclkConfig =                  /*!< TCLK CLOCK configuration. */
        {
            .initialize       = true,                                /*!< Initialize    */
            .tclkFreq[0]      = 0U,                                  /*!< TCLK0         */
            .tclkFreq[1]      = 0U,                                  /*!< TCLK1         */
            .tclkFreq[2]      = 0U,                                  /*!< TCLK2         */
        },
        .traceClockConfig =            /*!< Debug trace Clock Configuration. */
        {
            .initialize       = true,                                /*!< Initialize    */
            .divEnable        = true,                                /*!< TRACEDIVEN    */
            .source           = CLOCK_TRACE_SRC_CORE_CLK,            /*!< TRACECLK_SEL  */
            .divider          = 0U,                                  /*!< TRACEDIV      */
            .divFraction      = false,                               /*!< TRACEFRAC     */
        },
    },
    .pmcConfig =
    {
        .lpoClockConfig =              /*!< Low Power Clock configuration.     */
        {
            .initialize       = true,                                /*!< Initialize             */
            .enable           = true,                                /*!< Enable/disable LPO     */
            .trimValue        = 0,                                   /*!< Trimming value for LPO */
        },
    },
};

/*! @brief Array of pointers to User configuration structures */
clock_manager_user_config_t const * g_clockManConfigsArr[] = {
    &clockMan1_InitConfig0
};
/*! @brief Array of pointers to User defined Callbacks configuration structures */
clock_manager_callback_user_config_t * g_clockManCallbacksArr[] = {(void*)0};
/* END clockMan1. */

/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.1 [05.21]
**     for the Freescale S32K series of microcontrollers.
**
** ###################################################################
*/

