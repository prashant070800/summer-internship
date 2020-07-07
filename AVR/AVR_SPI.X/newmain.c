/* Experiment: Communication with SPI using ATmega2560
 *
 * @author     
 * @date       2020/07/07
 *
 * \subsection Aim
 * Getting familiar with SPI and its communication protocol 
 * 
 * \subsection Connections
 * Transmitter Pin  :   TX , pin 21	, (PB2)
 * Receiver Pin     :   RX , pin 22 , (PB3)
 * Clock pin        :   SCK, pin 20 , (PB1)
 * 
 * \MCU Used : ATmega2560
 */
///////////////////////////////////////////////////////////////////////////////////////////////////////
//SPI INTERFACING//////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////


//---------------------------------- HEADER FILES -----------------------------------------------------
#include"header.h"

//---------------------------------- MAIN ----------------------------------------------------------------
int main()
 { 
   // Write your code here
     SPI_Init();
     SPI_Write(0x50);
    while (1)
      ;
   return 0;
 }

//---------------------------------- FUNCTIONS ---------------------------------------------------------
void SPI_Init(void) // SPI Initialize function for mater transmit by pooling 
{
   ddr_spi  |= (1 << MOSI )|(1 << SCK )|(1 <<SS); 
   ddr_spi  &= ~(1 << MISO);
   port_spi |= (1 << SS);
   spi_control_reg = (1 << SPE ) | (1 << MSTR) | (1 <<SPR0);
   spi_status_reg = ~(1 << SPI2X );
}

void SPI_Write(char data)
{
   char flush_buffer;
   spi_data_reg = data;
   while(!(spi_status_reg & (1 << spi_interrupt_flag ))); 
   flush_buffer = spi_data_reg; 
}