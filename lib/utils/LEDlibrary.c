#define __DELAY_BACKWARD_COMPATIBLE__  
#include <util/delay.h>
#include <avr/io.h>
#include <stdio.h>
#include <LEDlibrary.h>

void enableOneLed(int led) {
    if ( led < 0 || led > LED_LIGHTS - 1 ) return;
    DDRB |= ( 1 << ( PB2 + led ));
}

void enableMultipleLeds (uint8_t leds) {
    for(leds = 0b00000000; leds < 0b00010000; leds++) {
        DDRB |= (1 << (PB2 + leds));
    }
}

void enableAllLeds() {
    DDRB |= (1 << (PB2 + LED_LIGHTS));
}

void lightUpOneLed(int led) {
    if ( led < 0 || led > LED_LIGHTS-1) return;
    PORTB &= ~( 1 << ( PB2 + led ));
}

void lightUpMultipleLeds(uint8_t leds){
    for(leds = 0b00000000; leds < 0b00010000; leds++) {
        DDRB &= ~(1 << (PB2 + leds));
    }
}

void lightUpAllLeds() {
    DDRB &= ~(1 << (PB2 + LED_LIGHTS));
}

void lightDownOneLed ( int led ) {
    if ( led < 0 || led > LED_LIGHTS - 1 ) return;
    PORTB |= (1 << ( PB2 + led ));   
}

void lightDownMultipleLeds (uint8_t leds) {
    for(leds = 0b00000000; leds < 0b00010000; leds++) {
        PORTB |= (1 << ( PB2 + leds )); 
    }
}

void lightDownAllLeds() {
    PORTB |= (1 << (PB2 + LED_LIGHTS));
}

void lightToggleOneLed(int led) {
    if(DDRB |= ( 1 << ( PB2 + led ))) PORTB &= ~( 1 << ( PB2 + led ));
} //turn off led if it's on

void dimLed (int led, int percentage, int duration){
    DDRB = 0b00100000; 

    for(percentage = 0; percentage <= 100; percentage++){ //as long as the percentage is not 100%
        PORTB = (0 << (PB2 + 3));
        _delay_ms(duration * (20/100)); //switched on 20% of the time

        PORTB = (1 << (PB2 + 3));
        _delay_ms(duration * (80/100)); //switched off 80% of the time
    }

    /*DDRB = led; 
    percentage = (duration/duration) * 100;
    while (1){ //endless loop
        PORTB = (0 << (PB2 + 3));
        _delay_ms(duration/2);
        PORTB = (1 << (PB2 + 3));
        _delay_ms(duration/2);
    }
    return;

    f ( led < 0 || led > LED_LIGHTS - 1 ) { //any led on the shield
        for(percentage; percentage < 100; percentage++){ // as long as the led is not 100% on
            PORTB = (0 << (PB2 + 3));//turn it on
            _delay_ms(duration); 
        }
        for(percentage; percentage <= 100; percentage--){//after turing the led of, start turning it off
            PORTB = (1 << (PB2 + 3)); //turn led off
            _delay_ms(duration);
        }
        percentage = (duration/duration) * 100; //pwm formula
    }*/
}

void fadeInLed(int led, int duration){
    for ( int i = 0; i < 4; i++ ) { 
        dimLed(i, 100, 10);
    }
}
