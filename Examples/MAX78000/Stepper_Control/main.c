/**
 * @file        main.c
 * @brief       I2C Loopback Example
 * @details     This example uses the I2C Master to read/write from/to the I2C Slave. For
 *              this example you must connect P0.12 to P0.18 (SCL) and P0.13 to P0.19 (SCL). The Master
 *              will use P0.12 and P0.13. The Slave will use P0.18 and P0.19. You must also
 *              connect the pull-up jumpers (JP23 and JP24) to the proper I/O voltage.
 *              Refer to JP27 to determine the I/O voltage.
 * @note        Other devices on the EvKit will be using the same bus. This example cannot be combined with
 *              a PMIC or bluetooth example because the I2C Slave uses GPIO pins for those devices.
 */

/*******************************************************************************
* Copyright (C) Maxim Integrated Products, Inc., All Rights Reserved.
*
* Permission is hereby granted, free of charge, to any person obtaining a
* copy of this software and associated documentation files (the "Software"),
* to deal in the Software without restriction, including without limitation
* the rights to use, copy, modify, merge, publish, distribute, sublicense,
* and/or sell copies of the Software, and to permit persons to whom the
* Software is furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included
* in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
* OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
* IN NO EVENT SHALL MAXIM INTEGRATED BE LIABLE FOR ANY CLAIM, DAMAGES
* OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
* ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
* OTHER DEALINGS IN THE SOFTWARE.
*
* Except as contained in this notice, the name of Maxim Integrated
* Products, Inc. shall not be used except as stated in the Maxim Integrated
* Products, Inc. Branding Policy.
*
* The mere transfer of this software does not imply any licenses
* of trade secrets, proprietary technology, copyrights, patents,
* trademarks, maskwork rights, or any other form of intellectual
* property whatsoever. Maxim Integrated Products, Inc. retains all
* ownership rights.
*
******************************************************************************/


/***** Includes *****/
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "mxc_device.h"
#include "mxc_delay.h"
#include "nvic_table.h"
#include "i2c_regs.h"
#include "i2c.h"
#include "dma.h"
// #include "led.h"
#include "pb.h"
#include "board.h"


// personal
#include "I2C_funcs.h"
#include "motor_funcs.h"
#include "tmr_funcs.h"
#include "ir_gpio_funcs.h"

#include "sorter.h"

// *****************************************************************************
int main()
{
    printf("\n\n***** STARTED *****\n\n");
    printf("Push PB1 to start the PWM\n");

    // SYSTICK
    SysTick_Setup();

    // GPIO
    gpio_init();

    // PWM & TMR
    PB_RegisterCallback(0, (pb_callback) PB1Handler);

    // I2C
    if (I2C_Init() != E_NO_ERROR) {
        printf("I2C INITIALIZATION FAILURE\n");
    } else {
        printf("I2C INITIALIZED :)\n");
    } 
    
    // Initialize test data
    for (int i = 0; i < I2C_BYTES; i++) {
        txdata[i] = 0;
        rxdata[i] = 0;
    }

    // MOTORS
    if (Motor_Init_Settings() != E_NO_ERROR) {
        printf("MOTOR SETTINGS INITIALIZATION FAILURE\n");
    } else {
        printf("MOTOR SETTINGS INITIALIZED :)\n");
    }

    // CNN accelerator
    // @geffen todo


    // int sanity_check = 0;
    while(1) {
        // sanity_check++;
        // if (sanity_check >= 100000000) {
        //     sanity_check = 0;
        //     printf("\nnot stalled :)\n");
        // }

        // if (MXC_GPIO_InGet(IR_MOTOR_PORT_0, IR_MOTOR_PIN_0)) {
        //     MXC_GPIO_OutSet(MXC_GPIO_PORT_INTERRUPT_STATUS, MXC_GPIO_PIN_INTERRUPT_STATUS);
        // } else {
        //     MXC_GPIO_OutClr(MXC_GPIO_PORT_INTERRUPT_STATUS, MXC_GPIO_PIN_INTERRUPT_STATUS);
        // }
        
    }
}
