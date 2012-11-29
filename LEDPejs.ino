#include "LPD8806.h"
#include "SPI.h"

// Example to control LPD8806-based RGB LED Modules in a strip

/*****************************************************************************/

// Choose which 2 pins you will use for output.
// Can be any valid output pins.
int dataPin = 3;   
int clockPin = 2; 

// Set the first variable to the NUMBER of pixels. 32 = 32 pixels in a row
// The LED strips are 32 LEDs per meter but you can extend/cut the strip
LPD8806 strip = LPD8806(32, dataPin, clockPin);

// you can also use hardware SPI, for ultra fast writes by leaving out the
// data and clock pin arguments. This will 'fix' the pins to the following:
// on Arduino 168/328 thats data = 11, and clock = pin 13
// on Megas thats data = 51, and clock = 52 
//LPD8806 strip = LPD8806(32);

int pixelsR[32];
int pixelsG[32];
int pixelsB[32];

void setup() {
  // Start up the LED strip
  strip.begin();

  // Update the strip, to start they are all 'off'
  strip.show();
  
  for(int i=0;i<32;i++){
    pixelsR[i] = 0;
    pixelsG[i] = 0;
    pixelsB[i] = 0;
  }
}



void loop() {
 for(int i=0;i<32;i++){
   float s = (sin(millis()/1000.0)+1)/2.0;
   
   pixelsR[i] = pixelsR[i] * 0.9 + (50+50*s) * 0.1;
   pixelsG[i] = pixelsG[i] * 0.9 + (random(0,s)) * 0.1;
   strip.setPixelColor(i, pixelsR[i], pixelsG[i], pixelsB[i]);
 }
 strip.show();
}


