/*
 * File:   newmain.c
 * Author: askan
 *
 * Created on 9 June, 2020, 8:14 AM
 */


#include <xc.h>

void DELAY(void)
{
    unsigned int i;
    for(i=0;i<=9999;i++) 
    {
        
    }
}


void main(void) 
{
    unsigned int a,v;
    ADCON0=0;
    ADCON1=0xE0;
    ADCON0bits.ADON=1;
    ADCON0bits.GO=1;
    while(ADCON0bits.GO==1) ;
    a=ADRESL;
    a|=(ADRESH<<8);
    v=a*4.88*6.4/1000 ;            // to convert 10 bit resolution to 5 bit
            DELAY();
   // TRISAbits.TRISA2=0;
    DACCON0=0xE0;
    DACCON1=v;
     DELAY();
     DELAY();
      DELAY();
    return;
}
