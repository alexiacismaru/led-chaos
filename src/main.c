#include <Arduino.h>
#define __DELAY_BACKWARD_COMPATIBLE__  
#include <util/delay.h>
#include <LEDlibrary.h>
#include <avr/io.h>
#include <stdlib.h>
#include <time.h>

#define NUMBER_OF_LEDS 4 

void enableLed ( int lednumber ) { 
    if ( lednumber < 0 || lednumber > NUMBER_OF_LEDS-1 ) return;  
    DDRB |= ( 1 << ( PB2 + lednumber ));  
}

void lightUpLed ( int lednumber ) {  
    if ( lednumber < 0 || lednumber > NUMBER_OF_LEDS-1 ) return;
    PORTB &= ~( 1 << ( PB2 + lednumber ));   
}

void lightDownLed ( int lednumber ) {
    if ( lednumber < 0 || lednumber > 3 ) return;
    PORTB |= ( 1 << ( PB2 + lednumber ));   
}

int main() {   
    srand(0);

    for ( int i = 0; i < 4; i++ ) {  
        enableLed(i);  
    }

    while (1) {
        for(int i=0; i<1; i++){
            int random_led = rand() % 4;
            lightUpLed(random_led);
            int random_delay = rand() % 1001;
            _delay_ms(random_delay);
        }

        for(int i=0; i<1; i++){
            int random_led = rand() % 4;
            lightDownLed(random_led);
            int random_delay = rand() % 1001;
            _delay_ms(random_delay);
        }
    }
    return 0;  
}
