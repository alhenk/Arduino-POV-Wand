#include <FastLED.h>

#if FASTLED_VERSION < 3001000
#error "Requires" FastLED 3.1 or later: check github for latest code."
#endif

#define NUM_LEDS 24
#define SCAN_RESOLUTION 32
#define DATA_PIN 7
#define CLOCK_PIN 13
#define RENDERING_DELAY 4

const int forwardLEDPin = 6;
const int backwardLEDPin = 4;
const int gyroZeroValue = 478;

volatile int gyroAnalogInput = A3;
volatile int gyroRawValue = 0; 
volatile int angularRate = 0;
volatile byte angularRateSign = 1;
volatile byte angularRateSignPrevious = 1;

const int rateBufferSize = 8;
int averageRateBuffer[rateBufferSize];
volatile long rateBufferSum = 0;
volatile int avarageRate=0;
volatile int movingIndex = 0;

void renderForwardRastr();
void renderBackwardRastr();

// Define the array of leds
CRGB leds[NUM_LEDS];
void turnOffAllLeds();

const int disp[SCAN_RESOLUTION][NUM_LEDS] = {
  
    {0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0},
    {0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0},
    {0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 8, 4,   4, 4, 8, 8,   0, 0, 0, 0,   0, 0, 0, 0},
    {0, 0, 0, 0,   0, 0, 0, 0,   0, 8, 8, 8,   8, 8, 8, 8,   8, 8, 0, 0,   0, 0, 0, 0},
    {0, 0, 0, 0,   0, 0, 0, 0,   0, 8, 7, 7,   4, 4, 4, 8,   3, 8, 8, 0,   0, 0, 0, 0},
    {0, 0, 0, 0,   0, 0, 0, 0,   0, 8, 7, 0,   0, 0, 0, 0,   4, 3, 8, 8,   7, 0, 0, 0},
    {0, 0, 0, 0,   0, 0, 0, 7,   8, 7, 0, 0,   0, 0, 4, 0,   0, 4, 3, 8,   8, 0, 0, 0},
    {0, 0, 0, 0,   0, 0, 0, 7,   8, 0, 0, 8,   0, 4, 4, 0,   0, 0, 3, 8,   8, 7, 0, 0},

    {0, 0, 0, 0,   0, 0, 0, 7,   8, 0, 0, 8,   8, 4, 4, 8,   0, 0, 0, 4,   8, 7, 0, 0},
    {0, 0, 0, 0,   0, 0, 0, 7,   8, 0, 0, 0,   8, 4, 8, 8,   8, 0, 3, 4,   8, 7, 0, 0},
    {0, 0, 0, 0,   0, 0, 0, 4,   4, 0, 0, 0,   4, 4, 0, 8,   0, 0, 3, 4,   7, 0, 0, 0},
    {0, 0, 0, 0,   0, 0, 0, 4,   4, 8, 0, 0,   0, 4, 0, 0,   3, 3, 4, 8,   7, 0, 0, 0},
    {0, 0, 0, 0,   0, 0, 0, 0,   4, 4, 7, 0,   0, 0, 0, 0,   4, 8, 8, 7,   0, 0, 0, 0},
    {0, 0, 0, 0,   0, 0, 0, 0,   0, 4, 7, 7,   0, 0, 0, 7,   8, 8, 7, 0,   0, 0, 0, 0},
    {0, 0, 0, 0,   0, 0, 0, 0,   0, 4, 4, 7,   3, 7, 7, 8,   7, 7, 0, 0,   0, 0, 0, 0},
    {0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 4, 3,   8, 8, 8, 7,   0, 0, 0, 0,   0, 0, 0, 0},

    {0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 3, 8,   8, 4, 7, 7,   7, 0, 0, 0,   0, 0, 0, 0},
    {0, 0, 0, 0,   0, 0, 0, 0,   0, 3, 8, 8,   7, 0, 4, 4,   7, 7, 0, 0,   0, 0, 0, 0},
    {0, 0, 0, 0,   0, 0, 0, 0,   3, 3, 8, 7,   0, 0, 0, 4,   4, 7, 7, 8,   0, 0, 0, 0},
    {0, 0, 0, 0,   0, 0, 0, 0,   3, 8, 8, 7,   0, 0, 0, 0,   0, 0, 7, 7,   8, 4, 0, 0},
    {0, 0, 0, 0,   0, 0, 0, 0,   3, 8, 7, 0,   0, 0, 0, 0,   0, 0, 0, 7,   8, 3, 4, 0},
    {0, 0, 0, 0,   0, 0, 0, 3,   7, 8, 7, 0,   0, 0, 0, 0,   0, 0, 0, 0,   7, 3, 4, 0},
    {0, 0, 0, 0,   0, 0, 0, 3,   8, 8, 7, 0,   0, 0, 0, 0,   0, 0, 0, 0,   8, 3, 4, 0},
    {0, 0, 0, 0,   0, 0, 0, 0,   8, 8, 7, 0,   0, 0, 0, 0,   0, 0, 0, 0,   8, 3, 0, 0},

    {0, 0, 0, 0,   0, 0, 0, 0,   8, 8, 7, 0,   0, 0, 0, 0,   0, 0, 0, 8,   8, 0, 0, 0},
    {0, 0, 0, 0,   0, 0, 0, 0,   8, 7, 7, 7,   0, 0, 0, 0,   0, 0, 7, 4,   0, 0, 0, 0},
    {0, 0, 0, 0,   0, 0, 0, 0,   0, 4, 4, 7,   7, 0, 0, 7,   7, 7, 4, 4,   4, 0, 0, 0},
    {0, 0, 0, 0,   0, 0, 0, 0,   0, 4, 4, 8,   8, 7, 8, 8,   8, 8, 4, 4,   0, 0, 0, 0},
    {0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 4, 4,   7, 7, 7, 7,   4, 4, 3, 0,   0, 0, 0, 0},
    {0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 3,   4, 4, 4, 4,   3, 3, 3, 0,   0, 0, 0, 0},
    {0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   3, 3, 3, 3,   0, 0, 0, 0,   0, 0, 0, 0},
    {0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0},
    
};

void setup() { 
       pinMode(forwardLEDPin, OUTPUT);
       pinMode(backwardLEDPin, OUTPUT);
  	   FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
       turnOffAllLeds();
       for (int i=0; i<rateBufferSize; i++){
          averageRateBuffer[i]=0;
       }
       movingIndex = 0;
       rateBufferSum = 0;
       avarageRate=0;
}

void loop() { 
   gyroRawValue = analogRead(gyroAnalogInput);  // read the input pin
   angularRate = gyroRawValue - gyroZeroValue;
   averageRateBuffer[movingIndex]=angularRate;
   movingIndex = (movingIndex++)%rateBufferSize;
   rateBufferSum=0;
   for (int i=0; i<rateBufferSize; i++){
    rateBufferSum += averageRateBuffer[i];
   }
   avarageRate=rateBufferSum/rateBufferSize;
   
   if (avarageRate < -20  ){
     angularRateSign = -1;
   }else if (avarageRate > 20  ) {
     angularRateSign = 1;
   }
   
   if (angularRateSignPrevious != angularRateSign){
    angularRateSignPrevious = angularRateSign;
    if (avarageRate < -20 ){
      renderForwardRastr();     
    } else if (avarageRate > 20 ) {   
      renderBackwardRastr();
    } else if (avarageRate == 0 ){
      digitalWrite(forwardLEDPin, 0);
      digitalWrite(backwardLEDPin, 0);
    }
   } 
}

void renderForwardRastr(){
  digitalWrite(forwardLEDPin, 1);
  digitalWrite(backwardLEDPin, 0);
  for (int scanStep=0; scanStep<SCAN_RESOLUTION; scanStep++){ 
      for (int ledPosition=0; ledPosition<NUM_LEDS; ledPosition++){
        switch(disp[scanStep][ledPosition]){
          case 3:
            leds[ledPosition] = CRGB::Orange;
            break;
          case 4:
            leds[ledPosition] = CRGB::Green;
            break;
          case 7:
            leds[ledPosition] = CRGB::Blue;
            break;
          case 8:
            leds[ledPosition] = CRGB::Violet;
            break;
          default:
            leds[ledPosition] = CRGB::Black;   
        }
      }
      FastLED.show();
      delay(RENDERING_DELAY);
  }
}

void renderBackwardRastr(){
  digitalWrite(forwardLEDPin, 0);
  digitalWrite(backwardLEDPin, 1);
  for (int scanStep=SCAN_RESOLUTION-1; scanStep>=0; scanStep--){ 
      for (int ledPosition=0; ledPosition<NUM_LEDS; ledPosition++){
        switch(disp[scanStep][ledPosition]){
          case 3:
            leds[ledPosition] = CRGB::Orange;
            break;
          case 4:
            leds[ledPosition] = CRGB::Green;
            break;
          case 7:
            leds[ledPosition] = CRGB::Blue;
            break;
          case 8:
            leds[ledPosition] = CRGB::Violet;
            break;
          default:
            leds[ledPosition] = CRGB::Black;   
        }
      }
      FastLED.show();
      delay(RENDERING_DELAY);
  }
}

void turnOffAllLeds(){
  for (int i=0; i<NUM_LEDS; i++){
    // Now turn the LED off, then pause
        leds[i] = CRGB::Black;
        FastLED.show();
  }
}
