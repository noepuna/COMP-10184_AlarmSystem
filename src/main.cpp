//I, Noe Puna, 000781646, I acknowledge that this my own work and no other
// person's work has been copied without acknowledgement.

// COMP-10184 – Mohawk College 
// PIR Sensor Test Application 
// Turn on the blue LED with motion is detected. 
 
#include <Arduino.h> 
 
// digital input pin definitions 
#define PIN_PIR D5 
#define PIN_BUTTON D6 

bool bState = false;

//buton states
#define BTN_UP 0
#define BTN_DOWN 1

// button levels
#define DOWN 0
#define Up 1

int iBtnState = BTN_UP;
 
 
// ************************************************************* 
void setup() { 
  // configure the USB serial monitor 
  Serial.begin(115200); 
 
  // configure the LED output 
  pinMode(LED_BUILTIN, OUTPUT); 
 
  // PIR sensor is an INPUT 
  pinMode(PIN_PIR, INPUT); 
 
  // Button is an INPUT 
  pinMode(PIN_BUTTON, INPUT_PULLUP); 
} 
 
// ************************************************************* 
void loop() { 
  bool bPIR; 
 
  // read PIR sensor (true = Motion detected!).  As long as there 
  // is motion, this signal will be true.  About 2.5 seconds after  
  // motion stops, the PIR signal will become false. 
  bPIR = digitalRead(PIN_PIR); 
 
  // send the PIR signal directly to the LED 
  // but invert it because true = LED off! 
  //digitalWrite(LED_BUILTIN, !bPIR); 

  if (bPIR){
    // flashing loop
    for (int i =0; i < 40; i++){
      digitalWrite(LED_BUILTIN, LOW);
      delay(125);
      digitalWrite(LED_BUILTIN, HIGH);
      delay(125);
    }
  }
  digitalWrite(LED_BUILTIN, LOW);  

/*
  // if button pressed
  if(digitalRead(D5) == Up){
    bPIR = false;
    Serial.println("Pressed");
    
  } else {
    
  }*/


} 