/* ************************************************************************** */
/** Header file for ATmega2560.
  @author : 
  @File Name : header.h
  @Summary
    This header file contains the configuration bits and variable and function definations. 
 */
/* ************************************************************************** */

#ifndef UART_H
#define	UART_H

#define F_CPU 8000000UL            /* Define frequency here its 8MHz */
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)

void UART_init(long USART_BAUDRATE);
unsigned char UART_RxChar();
void UART_TxChar(char ch);
void UART_SendString(const char *str);

#endif	/* UART_H */

