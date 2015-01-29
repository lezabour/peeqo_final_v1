#include "Timer.h"
#include <Servo.h>
#include "Adafruit_TLC5947.h"
#include <Wire.h>
#include "Adafruit_MPR121.h"
#include "pitches.h"

//CAP TOUCH VARIABLES
Adafruit_MPR121 cap = Adafruit_MPR121();

// Keeps track of the last pins touched
// so we know when buttons are 'released'

uint16_t lastHeadtouched = 0;
uint16_t currHeadtouched = 0;

uint16_t lastHandtouched = 0;
uint16_t currHandtouched = 0;

int touchCountHead = 0;
int touchCountHand = 0;

// SERVO VARIABLES

Servo servoArm;

int servoArmPin = 10;

float initialServoArmPos = 20;


// LED EYES
#define NUM_TLC5974 2

#define data   4
#define clock   7
#define latch   8
#define oe -1 //2

Adafruit_TLC5947 tlc = Adafruit_TLC5947(NUM_TLC5974, clock, data, latch);

// BLINKING EYE VARIABLES
Timer t;
boolean atRest = true;

boolean blinkEyeBool = true;
int blinkCount = 0;
int blinkInterval = 1;

// HAPPY EYE ARRAYS
uint8_t happyEyeOnLength = 14;
uint8_t happyEyeOffLength = 24;
uint8_t happyEyeOn[] = {6,7,8,9,10,11,0,     30,31,32,33,34,35,24};
uint8_t happyEyeOff[] = {1,2,3,4,5,12,13,14,15,16,17,18,     25,26,27,28,29,36,37,38,39,40,41,42};

// SAD EYE ARRAYS
uint8_t sadEyeOnLength = 14;
uint8_t sadEyeOffLength = 24;
uint8_t sadEyeOn[] = {0,1,2,3,4,5,6,24,25,26,27,28,29,30};
uint8_t sadEyeOff[] = {7,8,9,10,11,12,13,14,15,16,17,18,31,32,33,34,35,36,37,38,39,40,41,42};

//VERY SAD EYES
uint8_t verySadEyeOnLength = 24;
uint8_t verySadEyeOffLength = 14;
uint8_t verySadEyeOn[] = {0,1,2,3,4,10,11,12,13,14,17,18,      26,27,28,29,30,31,32,37,38,39,40,42};
uint8_t verySadEyeOff[] = {5,6,7,8,9,15,16,      24,25,33,34,35,36,41};

//HEART EYES
uint8_t heartEyeOnLength = 24;
uint8_t heartEyeOffLength = 14;
uint8_t heartEyeOn[] = {3,7,8,10,11,12,13,14,15,16,17,18,      27,31,32,34,35,36,37,38,39,40,41,42};
uint8_t heartEyeOff[] = {0,1,2,4,5,6,9,     24,25,26,28,29,30,33};


// HEART LED FADE VARIABLES
float fadeValue = 30;
float fadeSpeed = 1;
int fadeLedPin = 5;

// HIGH FIVE 
int highFiveUpPos = 130;
boolean highFiveUpBoolean = false;

// HIGH FIVE DOWN
boolean highFiveDownBoolean = false;


//VIBRATION MOTOR
int vibrationPin = 13;

//TONES
long previousToneMillis = 0;       
long toneInterval = 5;// 120;  

int melodyCount = 0;  // very good - happy / completion
int melodyMax = 9;
int melody[] = { 
NOTE_F3, NOTE_G4, NOTE_A5, NOTE_G6, NOTE_F3, NOTE_E6, NOTE_D4, NOTE_C4,PAUSE };
int duration[] = {100,100,100,50,50,50,100,250,500};

int melody2Count = 0;  // very good - happy/ processing
int melody2Max = 7;
int melody2[] = { 
NOTE_B3, NOTE_A4, NOTE_B6, NOTE_A6, NOTE_E3, NOTE_A4,PAUSE};
int duration2[] = {50,50,100,150,50,100, 500};

int melody3Count = 0;  // very good - processing
int melody3Max = 7;
int melody3[] = { 
NOTE_A3, NOTE_F4, NOTE_A4, NOTE_F5, NOTE_A3, NOTE_F3, PAUSE};
int duration3[] = {50,150,50,100,50,100, 500};

int melody4Count = 0;  //very good - happy
int melody4Max = 6;
int melody4[] = { 
NOTE_C4, NOTE_D5, NOTE_E6, NOTE_F5, NOTE_G6,PAUSE};
int duration4[] = {50,50,50,50,100,500};

int melody5Count = 0;  // good - sad angry
int melody5Max = 7;
int melody5[] = { 
NOTE_B2, NOTE_C2, NOTE_B2, NOTE_E2, NOTE_B3, NOTE_E3,PAUSE};
int duration5[] = {100,100,100,100,100,100,500};

int melody6Count = 0; // very good - thinking / processing
int melody6Max = 7;
int melody6[] = { 
NOTE_G4, NOTE_D5, NOTE_G6, NOTE_D6, NOTE_G5, NOTE_D5,PAUSE};
int duration6[] = {50,100,50,50,100,150,500};

int melody7Count = 0;  // good - angry
int melody7Max = 6;
int melody7[] = { 
NOTE_G3,PAUSE, NOTE_A3,PAUSE, NOTE_G3, PAUSE};
int duration7[] = {100,150,100,150,100, 500};

int melody8Count = 0;  // good angry - sad
int melody8Max = 6;
int melody8[] = { 
NOTE_C3,NOTE_C3,NOTE_B3, PAUSE, NOTE_A3,PAUSE};
int duration8[] = {100,100,150,200,400,500};

int melody9Count = 0;  //very good - happy
int melody9Max = 7;
int melody9[] = { 
NOTE_B6,NOTE_A6,NOTE_G6, NOTE_D6, NOTE_E6, NOTE_F6, PAUSE};
int duration9[] = {100,100,150,100,100,100, 500};

int melody10Count = 0;  //very good - angry
int melody10Max = 7;
int melody10[] = { 
NOTE_B2,NOTE_B4,NOTE_B3, NOTE_B3, NOTE_B2, NOTE_B2, PAUSE};
int duration10[] = {50,100,150,200,250,300, 500};

const int max = 8;
const int speaker = 12;
boolean playHappyMelody = false;

boolean beingPet = false;
boolean completedTasks = false;
boolean highFived = false;


void setup() {

   Serial.begin(9600);
   tlc.begin();
   
   servoArm.attach(servoArmPin);

   servoArm.write(initialServoArmPos);
   
   cap.begin(0x5A);

   t.every(5000, setBlink);
   
   pinMode(vibrationPin, OUTPUT);
}

void loop() {

   // update the timer
   t.update();


    // BLINK EYES - blink the eyes only when no other action is happening
     if(atRest && blinkEyeBool){
       blinkEyes(); 
     }
     
        
     // FADE LED HEART
     analogWrite(fadeLedPin, fadeValue);
     fadeValue += fadeSpeed;
     if(fadeValue >= 255 || fadeValue <=5){
        fadeSpeed *= -1; 
     }
      

   // REACT TO TOUCH 
   // Get the currently touched pads
   currHeadtouched = cap.touched();  
   currHandtouched = cap.touched();
   
   // PET HEAD
   if(cap.touched() & (1 << 0)){
     if ((currHeadtouched & _BV(0)) && !(lastHeadtouched & _BV(0)) ) {
       digitalWrite(vibrationPin, HIGH);
       touchCountHead ++;
       beingPet = true;
       atRest = false;
     } 
  }
  
  if(!(cap.touched() & (1 << 0))){
     if (!(currHeadtouched & _BV(0)) && (lastHeadtouched & _BV(0)) ) {
       digitalWrite(vibrationPin, LOW);
    }
  }
  
  // CHECK TO SEE HOW MANY TIMES TOUCHED
  if(touchCountHead > 2){
     highFiveUpBoolean = true;
     highFiveDownBoolean = false;
     beingPet = false;
     completedTasks = true;
     atRest = false;
  }
  
  // HIGH FIVE
  if(cap.touched() & (1 << 5)){
     if ((currHandtouched & _BV(5)) && !(lastHandtouched & _BV(5)) ) {
       touchCountHand++;
       highFived = true;
     } 
  }
  
  if(!(cap.touched() & (1 << 5))){
     if (!(currHandtouched & _BV(5)) && (lastHandtouched & _BV(5)) ) {
       highFiveDownBoolean = true;
       highFiveUpBoolean = false;
       touchCountHead = 0;
       completedTasks = false;
    }
  }
  

  // reset touch state
  lastHeadtouched = currHeadtouched;
  lastHandtouched = currHandtouched;
  
   
  if(completedTasks){
     changeEyes(heartEyeOn,heartEyeOnLength,heartEyeOff,heartEyeOffLength); 
  } 
   
  // MOVE HAND UP
  if(highFiveUpBoolean) {
    highFiveUp();
  }
  
  //MOVE HAND DOWN
  if(highFiveDownBoolean) {
     highFiveDown(); 
  }
  
  // BEING PET
  if(beingPet) {
     changeEyes(happyEyeOn,happyEyeOnLength,happyEyeOff,happyEyeOffLength); 
     playMelody(); 
  }
  
  if(highFived) {
    changeEyes(happyEyeOn,happyEyeOnLength,happyEyeOff,happyEyeOffLength); 
    playMelody4();
  }

   // RESET TONES
   if(melodyCount == melodyMax){
      melodyCount = 0;
      atRest = true;
      beingPet = false;
   }
   
   
   if(melody2Count == melody2Max){
      melody2Count = 0;
      atRest = true;
      highFived = false;
   }
   if(melody3Count == melody3Max){
      melody3Count = melody3Max;
   }
   if(melody4Count == melody4Max){
      melody4Count = 0;
      atRest = true;
      highFived = false;
   }
   if(melody5Count == melody5Max){
      melody5Count = melody5Max;
   }
   if(melody6Count == melody6Max){
      melody6Count = melody6Max;
   }
   if(melody7Count == melody7Max){
      melody7Count = melody7Max;
   }
   if(melody8Count == melody8Max){
      melody8Count = melody8Max;
   }
   if(melody9Count == melody9Max){
      melody9Count = melody9Max;
   }
   if(melody10Count == melody10Max){
      melody10Count = melody10Max;
   }
   
}

