#include <IRremote.h>

// the pin where you connect the output pin of TSOP4838
int RECV_PIN = 3;
int LED1 = 2;
int LED2 = 4;
int LED3 = 7;
int itsONled[] = {0,0,0,0};

/* the initial state of LEDs is OFF (zero) 
the first zero must remain zero but you can 
change the others to 1's if you want a certain
led to light when the board is powered */

#define code1  58747 // code received from button 1
#define code2  15355 // code received from button 2
#define code3  5699 // code received from button 3

IRrecv irrecv(RECV_PIN);
decode_results results;
void setup() {
  Serial.begin(9600); 
  irrecv.enableIRIn(); // Start the receiver
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
}

void loop() {
    if (irrecv.decode(&results)) {
        unsigned int value = results.value;
        switch(value) {
          case code1:
          if(itsONled[1] == 1) {        // if first led is on then
             digitalWrite(LED1, LOW);   // turn it off when button is pressed
             itsONled[1] = 0;           // and set its state as off
            } else {                      // else if first led is off
             digitalWrite(LED1, HIGH); // turn it on when the button is pressed
             itsONled[1] = 1;          // and set its state as on
            }
          break; 
          
          case code2:
          if(itsONled[2] == 1) {
             digitalWrite(LED2, LOW);
             itsONled[2] = 0;
            } else {
             digitalWrite(LED2, HIGH);
             itsONled[2] = 1;
            }
          break;
          
          case code3:
          if(itsONled[3] == 1) {
             digitalWrite(LED3, LOW);
             itsONled[3] = 0;
            } else {
             digitalWrite(LED3, HIGH);
             itsONled[3] = 1;
            }
          break;
        }

          Serial.println(value); // you can comment this line
    irrecv.resume(); // Receive the next value
    }
}
