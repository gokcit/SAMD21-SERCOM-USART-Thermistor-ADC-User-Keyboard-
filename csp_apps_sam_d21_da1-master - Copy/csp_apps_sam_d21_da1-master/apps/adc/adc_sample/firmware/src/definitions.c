#include "definitions.h"

if(SERCOM3_USART_ReceiverIsReady() == true)
{
    if(SERCOM3_USART_ErrorGet() == USART_ERROR_NONE)
    {
        SERCOM3_USART_Read(&data, 1);

        if((data == '\n') || (data == '\r'))
        {
            SERCOM3_USART_Write(&newline[0],sizeof(newline));
            SERCOM3_USART_Write(&receiveBuffer[0],rxCounter);
            SERCOM3_USART_Write(&newline[0],sizeof(newline));
            rxCounter = 0;
            LED_Toggle();
        }
        else
        {
            receiveBuffer[rxCounter++] = data;
        }
    }
    else
    {
        SERCOM3_USART_Write(&errorMessage[0],sizeof(errorMessage));
    }
}