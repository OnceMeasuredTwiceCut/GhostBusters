#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

/////////////////////// Variables for the NeoPixels ///////////////////////
// Pins where the two LED strips are soldered 
// Change these if yours are different
#define GRAPH_PIN 5
#define SLIME_PIN 3

// Change these values below to the length of your LED strips
#define LEN_GRAPH 12
#define LEN_SLIME 7

// Creating two NeoPixal objects
Adafruit_NeoPixel GRAPH(LEN_GRAPH, GRAPH_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel SLIME(LEN_SLIME, SLIME_PIN, NEO_GRB + NEO_KHZ800);

// BRIGHT is set to 25 I don't burn my eyes when testing strips
// Change Bright to 255 when outside of a testing enviroment
#define BRIGHT 25
uint32_t GREEN = SLIME.Color(0,BRIGHT,0);
uint32_t BLUE = SLIME.Color(0,0,BRIGHT);

// Values to help us 
int slimeCount = 1;
int graphCount = 1;
unsigned long prevTime = millis();
unsigned long currTime = millis();

// Originally set to 100
// Change this value to make the LEDs travel faster (less than 100) or slower (more than 100)
unsigned long delayTime = 100;

void setup(){
  // Initilize both Neopixal objects
    GRAPH.begin();
    SLIME.begin();
}

void loop(){

    currTime = millis();

    if (currTime - prevTime > delayTime){
      // this is when we update the different slime and graph indexes 
      // they are of different lengeths, make sure it's reflected 
      // slime
      if (slimeCount <= LEN_SLIME){
        SLIME.fill(GREEN, 0, slimeCount);
        SLIME.show();
        slimeCount++;
      }else{
        SLIME.clear();
        SLIME.show();
        slimeCount = 1;
      }

      // graph
      if (graphCount <= LEN_GRAPH){
        GRAPH.fill(BLUE, 0, graphCount);
        GRAPH.show();
        graphCount++;
      }else{
        GRAPH.clear();
        GRAPH.show();
        graphCount = 1;
      }
      
      // update the prevTime
      prevTime = millis();
    }
    // Do it all over again!
}
