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

#define F_CPU 8000000UL		                                                    /* Define CPU clock Frequency 8MHz */
#define SCL_CLK 100
#include <avr/io.h>		                                                        /* Include AVR std. library file */
#include <util/delay.h>	                                                    	/* Include Delay header file */
#include <string.h>		                                                        /* Include string header file */
#include <math.h>

/* Define bit rate */
#define BITRATE(TWSR)	((F_CPU/SCL_CLK)-16)/(2*pow(4,(TWSR&((1<<TWPS0)|(1<<TWPS1)))))
#define EEPROM_Write_Addess		0xA0

void I2C_Init()	;
uint8_t I2C_Start(char write_address);
uint8_t I2C_Write(char data);
void I2C_Stop();


#endif	/* HEADER_H */

