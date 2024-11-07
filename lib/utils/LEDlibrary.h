#include <util/delay.h>
#include <avr/io.h>

#define LED_LIGHTS 4 //Define is a "preprocessor directive". It ensures that every LED_LIGHTS will be replaced by 4 in the following code

void enableLed ( int led );

void lightUpLed ( int led );

void lightDownLed ( int led );

void enableMultipleLeds (uint8_t leds);

void enableAllLeds ( );

void lightUpMultipleLeds (uint8_t leds);

void lightUpAllLeds( );

void lightDownMultipleLeds (uint8_t leds);

void lightDownAllLeds( );

void lightToggleOneLed (int led);

void dimLed (int led, int percentage, int duration);

void fadeInLed(int led, int duration);

void fadeOutLed(int led, int duration);