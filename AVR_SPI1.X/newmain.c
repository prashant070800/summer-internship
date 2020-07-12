/* Experiment: Communication with SPI using ATmega2560
 *
 * @author     
 * @date       2020/07/07
 *
 * \subsection Aim
 * Getting familiar with SPI and its communication protocol 
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
    ddrc = 0xff;
    portc = 0;
    sei();
    SPI_SlaveInit();
    portc = 0;
   while (1)
      ;
   return 0;
 }

//---------------------------------- FUNCTIONS ---------------------------------------------------------

void SPI_SlaveInit(void)
{
      /* Set MISO output, all others input */
      ddrb = (1<<MISO);
      /* Enable SPI and SPI interrupt */
      spi_control_reg = (1 << spi_enable )|(1<<spi_interrupt_enable) ;
}
 
 ISR (SPI_STC_vect)
 {
     portc = spi_data_reg;
    _delay_ms(100);
 }
