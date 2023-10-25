//-------------------------------------------------------------------------------------
// Pumpkin Flames
// Copyright 2023 Hazze Molin
// 
// History
//  1.0 2023-10-25:   Initial release
//
// MIT License
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), 
// to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, 
// and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS 
// IN THE SOFTWARE.
//-------------------------------------------------------------------------------------

#include <Arduino.h>

// Defining the pins use for the LEDs
#define PIN_LED_YELLOW1 10
#define PIN_LED_YELLOW2 5
#define PIN_LED_YELLOW3 9
#define PIN_LED_RED1 11
#define PIN_LED_RED2 6

// Defining the states for the LEDs
#define NUM_LEDS  5
int ledPin[NUM_LEDS] = {PIN_LED_YELLOW1, PIN_LED_YELLOW2, PIN_LED_YELLOW3, PIN_LED_RED1, PIN_LED_RED2};
unsigned long ledDelayTime[NUM_LEDS];
unsigned long ledLastTime[NUM_LEDS];

void setup() {
  digitalWrite(LED_BUILTIN, LOW); // Turn-off built-in LED
  pinMode(LED_BUILTIN, OUTPUT);

  digitalWrite(PIN_LED_YELLOW1, LOW);
  digitalWrite(PIN_LED_YELLOW2, LOW);
  digitalWrite(PIN_LED_YELLOW3, LOW);
  digitalWrite(PIN_LED_RED1, LOW);
  digitalWrite(PIN_LED_RED2, LOW);  
  pinMode(PIN_LED_YELLOW1, OUTPUT);
  pinMode(PIN_LED_YELLOW2, OUTPUT);
  pinMode(PIN_LED_YELLOW3, OUTPUT);
  pinMode(PIN_LED_RED1, OUTPUT);
  pinMode(PIN_LED_RED2, OUTPUT);

  // Initial time state for the LEDs
  for (int r = 0; r < NUM_LEDS; r++) {
    ledDelayTime[r] = 45 + random(20) * 20;
  }
}

// Defining the brightness levels
#define BRIGHTNESS_POS_OFF  0
#define BRIGHTNESS_POS_MIN  1
#define BRIGHTNESS_POS_MAX  8
int brightnessLevels[] = {0, 1, 2, 4, 8, 16, 32, 127, 255};

void loop() {
  unsigned long millisTime = millis();

  for (int r = 0; r < NUM_LEDS; r++) {
    if (millisTime - ledLastTime[r] > ledDelayTime[r]) {
      ledLastTime[r] = millisTime;

      // Set random brightness and delay time
      int level = BRIGHTNESS_POS_OFF;
      switch(r) {
        case 0: // Yellow 1
          level = 2 + random(BRIGHTNESS_POS_MAX-2);
          ledDelayTime[r] = 45 + random(20) * 20;
          break;
        case 1: // Yellow 2
          level = random(BRIGHTNESS_POS_MAX);
          ledDelayTime[r] = 15 + random(10) * 10;
          break;
        case 2: // Yellow 3
          level = random(BRIGHTNESS_POS_MAX);
          ledDelayTime[r] = 15 + random(10) * 10;
          break;
        case 3: // Red 1
          level = random(BRIGHTNESS_POS_MAX);
          ledDelayTime[r] = 50 + random(30) * 20;
          break;
        case 4: // Red 2
          level = random(BRIGHTNESS_POS_MAX);
          ledDelayTime[r] = 15 + random(20) * 15;
          break;
      }            

      analogWrite(ledPin[r], brightnessLevels[level]);
    }
  }
}
