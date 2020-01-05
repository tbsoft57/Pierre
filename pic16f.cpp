#include <xc.h>
#include <stdio.h>
#include <stdlib.h>

#define _XTAL_FREQ 500000

void pulse(){
    LATB = 0b00000000;
    _delay(1);
    LATB = 0b01000000;
    _delay(1);
}

void main(void){
    
    PORTA = 0b00000000;
    PORTB = 0b00000000;
    PORTC = 0b00000000;
    
    ANSELA = 0b00000000;
    ANSELB = 0b00000000;
    ANSELC = 0b00000000;
    
    TRISA = 0b00000000;
    TRISB = 0b00000000;
    TRISC = 0b00000000;
    
    int seg[]={0,0,0,0,1,0,1,0,1,0,1,1,0,1,1,0};
    LATA = 0b00010000;
    LATC = 0b00100000;
    for(int i=0; i<=15; i++){
        LATC = 0b00100000 | (seg[i]<<7);
        pulse();
    }
    _delay(1);
    LATC = 0b00100000;
    _delay(1);
    LATC = 0b01000000; 
    LATA = 0b00000000;
    
    return;
}
