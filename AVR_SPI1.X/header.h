/* 
 * File:   header.h
 * Author: askan
 *
 * Created on 12 July, 2020, 8:27 AM
 */

#ifndef HEADER_H
#define	HEADER_H

#include <inttypes.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <util/delay.h>

#define ddrc DDRC
#define portc PORTC
#define ddrb DDRB
#define spi_control_reg SPCR
#define spi_status_reg SPSR
#define spi_data_reg SPDR
#define spi_interrupt_flag SPIF
#define spi_enable SPE
#define spi_interrupt_enable SPIE 

#define MOSI 2
#define MISO 3
#define SS   0
#define SCK  1

void SPI_SlaveInit(void);

#endif	/* HEADER_H */

