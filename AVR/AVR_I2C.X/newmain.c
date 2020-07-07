/* Experiment: Communication with I2C using ATmega2560
 *
 * @author     
 * @date       2020/07/07
 *
 * \subsection Aim
 * Getting familiar with I2C and its communication protocol 
 * 
 * \subsection Connections
 * SDA Pin  :    pin 44	, (PD1)
 * SCL Pin  :    pin 43 , (PD0)
 * 
 * \MCU Used : ATmega2560
 */
///////////////////////////////////////////////////////////////////////////////////////////////////////
//I2C Mater Write INTERFACING//////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////

//---------------------------------- HEADER FILES -----------------------------------------------------
#include"header.h"

//---------------------------------- MAIN -------------------------------------------------------------
int main(void)
{
    char array[10] = "asdfgh";	                                                /* Declare array to be print */
   int i;
    I2C_Init();			                                                        /* Initialize I2C */
    I2C_Start(EEPROM_Write_Addess);
   I2C_Write(0x40);		                                                        /* Write start memory address for data write */
    for ( i = 0; i<strlen(array); i++)
		I2C_Write(array[i]); 
	
    I2C_Stop();		
    return 0;
}

//---------------------------------- FUNCTIONS ---------------------------------------------------------
void I2C_Init()			                                                        /* I2C initialize function */
{
    TWBR = BITRATE(TWSR=0x00);	                                                /* Get bit rate register value by formula */
}

uint8_t I2C_Start(char write_address)                                           /* I2C start function */
{
    uint8_t status;		                                                        /* Declare variable */
    TWCR=(1<<TWSTA)|(1<<TWEN)|(1<<TWINT);                                       /* Enable TWI, generate START */
    while(!(TWCR&(1<<TWINT)));	                                                /* Wait until TWI finish its current job */
    status=TWSR&0xF8;		                                                    /* Read TWI status register */
    if(status!=0x08)		                                                    /* Check weather START transmitted or not? */
    return 0;			                                                        /* Return 0 to indicate start condition fail */
    TWDR=write_address;	                                                    	/* Write SLA+W in TWI data register */
    TWCR=(1<<TWEN)|(1<<TWINT);	                                                /* Enable TWI & clear interrupt flag */
    while(!(TWCR&(1<<TWINT)));	                                                /* Wait until TWI finish its current job */
    status=TWSR&0xF8;		                                                    /* Read TWI status register */	
    if(status==0x18)		                                                    /* Check for SLA+W transmitted &ack received */
    return 1;			                                                        /* Return 1 to indicate ack received */
    if(status==0x20)		                                                    /* Check for SLA+W transmitted &nack received */
    return 2;			                                                        /* Return 2 to indicate nack received */
    else
    return 3;			                                                        /* Else return 3 to indicate SLA+W failed */
}

uint8_t I2C_Write(char data)	                                                /* I2C write function */
{
    uint8_t status;		                                                        /* Declare variable */
    TWDR=data;			                                                        /* Copy data in TWI data register */
    TWCR=(1<<TWEN)|(1<<TWINT);	                                                /* Enable TWI and clear interrupt flag */
    while(!(TWCR&(1<<TWINT)));	                                                /* Wait until TWI finish its current job */
    status=TWSR&0xF8;		                                                    /* Read TWI status register */
    if(status==0x28)		                                                    /* Check for data transmitted &ack received */
    return 0;			                                                        /* Return 0 to indicate ack received */
    if(status==0x30)		                                                    /* Check for data transmitted &nack received */
    return 1;			                                                        /* Return 1 to indicate nack received */
    else
    return 2;			                                                        /* Else return 2 for data transmission failure */
}

void I2C_Stop()			                                                        /* I2C stop function */
{
    TWCR=(1<<TWSTO)|(1<<TWINT)|(1<<TWEN);                                       /* Enable TWI, generate stop */
    while(TWCR&(1<<TWSTO));                                                 	/* Wait until stop condition execution */
}
