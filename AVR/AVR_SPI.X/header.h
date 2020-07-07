/* ************************************************************************** */
/** Header file for ATmega2560.
  @author : 
  @File Name : header.h
  @Summary
    This header file contains the configuration bits and variable and function definations. 
 */
/* ************************************************************************** */

#ifndef HEADER_H
#define	HEADER_H

#include <inttypes.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>

#define ddr_spi DDRB
#define port_spi PORTB
#define spi_control_reg SPCR
#define spi_status_reg SPSR
#define spi_data_reg SPDR
#define spi_interrupt_flag SPIF

#define MOSI 2
#define MISO 3
#define SS   0
#define SCK  1

void SPI_Write(char data);
void SPI_Init(void);

#endif	/* HEADER_H */

