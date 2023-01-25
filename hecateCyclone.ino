#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

/*
Description: 

Code loops over the three strips (FIRST, SECOND, WEAK). 
For my Pack there are three strips- including one that is 'weak' (It's made to look weak on purpose).

*/

/////////////////////// Variables for the Strips ///////////////////////
// BRIGHT is set at 25 for testing
// Set BRIGHT to 255 when not in a testing enviroment
#define BRIGHT 25


// These variables define the length of the three LED strips
// If you're using this code, make sure you change the LED strip lenghts to match your own
#define LEN_FIRST 28
#define LEN_SECOND 32
#define LEN_WEAK 7
#define PULSE_LEN 10

// Initlizing NeoPixal Objects
Adafruit_NeoPixel FIRST(LEN_FIRST, 3, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel SECOND(LEN_SECOND, 5, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel WEAK(LEN_WEAK, 7, NEO_GRB + NEO_KHZ800);

// Assigning Colors for Easy Use
uint32_t BLUE = FIRST.Color(0,0,BRIGHT);
uint32_t RED = FIRST.Color(BRIGHT,0,0);
uint32_t DARK = FIRST.Color(0,0,0);
uint32_t GREEN = FIRST.Color(0,BRIGHT,0);

// For debugging, set testing to True and use Serial Moniter to debug program
bool testing = false;
 
/////////////////////// Loop Variables ///////////////////////
// currColor is used to define the default color of the pack
// Assign currColor a different color value to change color
uint32_t currColor = RED;

// delayVal is used to set the speed of the LEDs
// Origionally set at 15
// To speed up LEDs, set delayVal to less than 15
// To slow down, set delayVal to more than 15
int delayVal = 15;



void setup() {
  // Initilize the Neopixal Objects
  FIRST.begin();
  SECOND.begin();
  WEAK.begin();
  
  // For testing
  Serial.begin(9600);
}

void loop() {

  // Looping over FIRST strip
 for(int i = 0; i < LEN_FIRST; i++){

     FIRST.setPixelColor(i, currColor);
     FIRST.show();
     
     if(testing)Serial.print("i value:");
     if(testing)Serial.print(i);
     if(testing)Serial.print("\n");
    
    if(i >= PULSE_LEN){
     FIRST.setPixelColor(i-PULSE_LEN, DARK);
     FIRST.show();
    }
     delay(delayVal);
 }
 FIRST.clear();
 FIRST.show();

  // Looping over SECOND strip
 for(int i = 0; i < LEN_SECOND; i++){
     //    we're going to light them one by one
     //    for each, fill them with the color red
     SECOND.setPixelColor(i, currColor);
     SECOND.show();

     if(testing)Serial.print("i value:");
     if(testing)Serial.print(i);
     if(testing)Serial.print("\n");
    
    if(i >= PULSE_LEN){
     SECOND.setPixelColor(i-PULSE_LEN, DARK);
     SECOND.show();
    }
     delay(delayVal);
 }
 SECOND.clear();
 SECOND.show();

  // Looping over WEAK (or the last) strip
 for(int i = 0; i < LEN_WEAK; i++){
     //    we're going to light them one by one
     //    for each, fill them with the color red
     WEAK.setPixelColor(i, currColor);
     WEAK.show();
     
     if(testing)Serial.print("i value:");
     if(testing)Serial.print(i);
     if(testing)Serial.print("\n");

    if(i >= 5){
     
     if(testing)Serial.print("\t"); 
     if(testing)Serial.print(i-5);
     if(testing)Serial.print("\n");
     
     WEAK.setPixelColor(i-5, DARK);
     WEAK.show();
    }
     delay(delayVal+50);
 }
 WEAK.clear();
 WEAK.show();

  if(testing)Serial.print("End of Loop\n");
  if(testing)Serial.print("_______________________\n");

}
