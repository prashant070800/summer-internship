/* Experiment: Communication with UART using ATmega2560
 *
 * @author     
 * @date       2020/07/07
 *
 * \subsection Aim
 * Getting familiar with UART and its communication protocol 
 * 
 * \subsection Connections
 * Tx Pin  :    pin 3	, (PE1)
 * Rx Pin  :    pin 2 , (PE0)
 * 
 * \MCU Used : ATmega2560
 */
///////////////////////////////////////////////////////////////////////////////////////////////////////
//UART INTERFACING/////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////

//---------------------------------- HEADER FILES -----------------------------------------------------
#include"uart.h"

//---------------------------------- MAIN -------------------------------------------------------------

int main()
{
    DDRA=0xFF;
    char c;
    UART_init(9600);

    UART_SendString("eyantra");    
    while(1)
    {
       c=UART_RxChar();
      
        UART_TxChar(c);
    }    
}

//---------------------------------- FUNCTIONS ---------------------------------------------------------
void UART_init(long USART_BAUDRATE)
{
   
    UCSR0B |= (1 << RXEN0) | (1 << TXEN0);                     /* Turn on transmission and reception */
    UCSR0C |=  (1 << UCSZ00) | (1 << UCSZ01);                  /* Use 8-bit character sizes */
    UBRR0L = BAUD_PRESCALE;                                    /* Load lower 8-bits of the baud rate value */
    UBRR0H = (BAUD_PRESCALE >> 8);                             /* Load upper 8-bits*/
}

unsigned char UART_RxChar()
{
    while ((UCSR0A & (1 << RXC0)) == 0);                       /* Wait till data is received */
    return(UDR0);                                              /* Return the byte*/
}

void UART_TxChar(char ch)
{
    while (! (UCSR0A & (1<<UDRE0)));                           /* Wait for empty transmit buffer*/
    UDR0 = ch ;
}

void UART_SendString(const char *str)
{
   
    unsigned int j=0;
    
    while (str[j]!=0)                                           /* Send string till null */
    {
        UART_TxChar(str[j]);    
        j++;
    }
}