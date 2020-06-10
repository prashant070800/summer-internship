/*
 * File:   newmain.c
 * Author: askan
 *
 * Created on 9 June, 2020, 8:14 AM
 */


#include <xc.h>
#define _XTAL_FREQ 3200000
void DELAY(void)
{
    unsigned int i;
    for(i=0;i<=99;i++) 
    {
        
    }
}


void main(void) 
{
    unsigned int a,v;
   
    ADCON0=0;
    ADCON1=0xA0;
    ADCON0bits.ADON=1;
   
    while(1)
    {
     ADCON0bits.GO=1;
    while(ADCON0bits.GO==1) ;
    a=ADRESL;
    a|=(ADRESH<<8);
    v=a*4.88*6.4/1000 ;            // to convert 10 bit resolution to 5 bit
      
   // TRISAbits.TRISA2=0;
    DACCON0=0xE0;
    DACCON1=v;
    }
 
    return;
}
