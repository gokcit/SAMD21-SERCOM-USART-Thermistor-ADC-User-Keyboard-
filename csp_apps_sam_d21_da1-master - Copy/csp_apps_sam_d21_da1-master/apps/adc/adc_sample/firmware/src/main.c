/*******************************************************************************
  Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This file contains the "main" function for a project.

  Description:
    This file contains the "main" function for a project.  The
    "main" function calls the "SYS_Initialize" function to initialize the state
    machines of all modules in the system
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include <stdio.h>
#include "definitions.h"                // SYS function prototypes

#define ADC_VREF                (1650)   //1650 mV (1.65V)
#define DAC_COUNT_INCREMENT     (31U)    // equivalent to 0.1V (0.1 / (3.3 / ((2^10) - 1))) 
#define DAC_COUNT_MAX           (511)
#define RX_BUFFER_SIZE 256


uint16_t adc_count;
uint32_t input_voltage;  
char messageStart[] = "**** USART Line Echo Demo: Blocking Transfer without the interrupt ****\r\n\
**** Type a line of characters and press the Enter key. **** \r\n\
**** Entered line will be echoed back, and the LED is toggled. ****\r\n";
char newline[] = "\r\n";
char errorMessage[] = "\r\n**** USART error has occurred ****\r\n";
char receiveBuffer[RX_BUFFER_SIZE] = {};
char data = 0;

static void EIC_User_Handler(uintptr_t context);


void mySysTickEventHandler(uintptr_t context){
        
//    UserInputValid = SERCOM3_USART_Read(*userInput, 3);
//    userInput1 = SERCOM3_USART_ReadByte();
    switch (input_voltage){
        case 0 ... 1015:
            printf("More than 50 Celsius\r\n");
            break;
        case 1016 ... 1038:
            printf("49 Celsius\r\n");
            break;
        case 1039 ... 1061:
            printf("48 Celsius\r\n");
            break;
        case 1062 ... 1084:
            printf("47 Celsius\r\n");
            break;
        case 1109 ... 1132:
            printf("46 Celsius\r\n");
            break;
        case 1133 ... 1157:
            printf("45 Celsius\r\n");
            break;
        case 1158 ... 1181:
            printf("44 Celsius\r\n");
            break;
        case 1182 ... 1207:
            printf("43 Celsius\r\n");
            break;
        case 1208 ... 1232:
            printf("42 Celsius\r\n");
            break;
        case 1233 ... 1256:
            printf("41 Celsius\r\n");
            break;
        case 1257 ... 1281:
            printf("40 Celsius\r\n");
            break;
        case 1282 ... 1306:
            printf("39 Celsius\r\n");
            break;
        case 1307 ... 1331:
            printf("38 Celsius\r\n");
            break;
        case 1332 ... 1357:
            printf("37 Celsius\r\n");
            break;
        case 1358 ... 1382:
            printf("36 Celsius\r\n");
            break;
        case 1383 ... 1407:
            printf("35 Celsius\r\n");
            break;
        case 1408 ... 1433:
            printf("34 Celsius\r\n");
            break;
        case 1434 ... 1458:
            printf("33 Celsius\r\n");
            break;
        case 1459 ... 1483:
            printf("32 Celsius\r\n");
            break;
        case 1484 ... 1508:
            printf("31 Celsius\r\n");
            break;
        case 1509 ... 1533:
            printf("30 Celsius\r\n");
            break;
        case 1534 ... 1558:
            printf("29 Celsius\r\n");
            break;
        case 1559 ... 1584:
            printf("28 Celsius\r\n");
            break;
        case 1585 ... 1608:
            printf("27 Celsius\r\n");
            break;
        case 1609 ... 1632:
            printf("26 Celsius\r\n");
            break;
        case 1633 ... 1700:
            printf("25 Celsius\r\n");
            break;
        default:
            printf(" not in range\n");
            break;
        }
        printf("ADC Value = 0x%x, ADC Input Voltage = %d.%03d V \r\n\n", adc_count, (int)(input_voltage/1000), (int)(input_voltage%1000));
        printf("ADC Value = 0x%x\r", adc_count);
}

void mySysTickEventHandler1(uintptr_t context){
    printf("\n\r---------------------------------------------------------");
    printf("\n\r                    Test                 ");
    printf("\n\r---------------------------------------------------------\n\r");
}
// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************

int main ( void )
{
    //uint16_t rxCounter=0;
    
    /* Initialize all modules */
    SYS_Initialize ( NULL );
    LED_Set();
    
        /* Send start message */
    SERCOM3_USART_Write(&messageStart[0], sizeof(messageStart));
   
    
    //SYSTICK_TimerCallbackSet(&mySysTickEventHandler, (uintptr_t) NULL);
//    EIC_CallbackRegister(EIC_PIN_15, mySysTickEventHandler, (uintptr_t) NULL);
    EIC_CallbackRegister(EIC_PIN_15,EIC_User_Handler, 0);
    
//    ADC_Enable();
    //SYSTICK_TimerStart();
    
//    printf("\n\r---------------------------------------------------------");
//    printf("\n\r                    ADC Sample Demo                 ");
//    printf("\n\r---------------------------------------------------------\n\r");
//    EIC_CallbackRegister(EIC_PIN_15, switch_handler, (uintptr_t) NULL);
    
//    DAC_DataWrite(dac_count);
    while (1)
    {
        SYS_Tasks ( );
        // Check if there is a received character
//        if(SERCOM3_USART_ReceiverIsReady() == true)
//        {
//            if(SERCOM3_USART_ErrorGet() == USART_ERROR_NONE)
//            {
//                SERCOM3_USART_Read(&data, 1);
//
//                if((data == '\n') || (data == '\r'))
//                {
//                    SERCOM3_USART_Write(&newline[0],sizeof(newline));
//                    SERCOM3_USART_Write(&receiveBuffer[0],rxCounter);
//                    SERCOM3_USART_Write(&newline[0],sizeof(newline));
//                    rxCounter = 0;
//                    LED_Toggle();
//                }
//                else
//                {
//                    receiveBuffer[rxCounter++] = data;
//                }
//            }
//            else
//            {
//                SERCOM3_USART_Write(&errorMessage[0],sizeof(errorMessage));
//            }
//        }
        /* Start ADC conversion */
//        ADC_ConversionStart();

        /* Wait till ADC conversion result is available */
//        while(!ADC_ConversionStatusGet())
//        {
//
//        };
//
//        /* Read the ADC result */
//        adc_count = ADC_ConversionResultGet();
//        input_voltage = adc_count * ADC_VREF / 4095U;

//        printf("ADC Count = 0x%x, ADC Input Voltage = %d.%03d V \r", adc_count, (int)(input_voltage/1000), (int)(input_voltage%1000));
//        SYSTICK_DelayMs(500);
    }

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}

static void EIC_User_Handler(uintptr_t context)
{
    LED_Toggle();
}

/*******************************************************************************
 End of File
*/

