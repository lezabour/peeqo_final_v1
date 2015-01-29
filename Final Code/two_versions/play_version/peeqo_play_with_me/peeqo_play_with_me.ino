#include "Timer.h"s
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

Servo servoNeck;
Servo servoHead;
Servo servoArm;

int servoNeckPin = 6;
int servoHeadPin = 9;
int servoArmPin = 10;

float initialServoHeadPos = 90;
float initialServoNeckPos = 90;
float initialServoArmPos = 15;

// SERVO SAY NO 
float sayNoPos = 90;
float sayNoSpeed = 0; //set in the serial event
float sayNoMax = 120;
float sayNoMin = 60;
int sayNoShiftCount = 0;
int sayNoShiftThresh = 4;
boolean sayNoBoolean = false;
boolean sad = false;

// SAY YES
float sayYesPos = 90;
float sayYesSpeed = 0;  //set in the serial event
float sayYesMax = 95;
float sayYesMin = 85;
int sayYesShiftCount = 0;
int sayYesShiftThresh = 4;
boolean sayYesBoolean = false;

// BE SAD
float beSadPos = 90;
float beSadMin = 80;
float beSadSpeed = 0;
boolean beSadBoolean = false;

// BE SAD NECK
float beSadNeckPos = 90;
float beSadNeckMin = 120;
float beSadNeckSpeed = 0;
boolean beSadNeckBoolean = false;

// BE HAPPY
float beHappyPos = 90;
float beHappyMax = 102;
float beHappySpeed = 0;
boolean beHappyBoolean = false;

// BE HAPPY NECK
float beHappyNeckPos = 90;
float beHappyNeckMax = 120;
float beHappyNeckSpeed = 0;
boolean beHappyNeckBoolean = false;

// RESET HEAD
float resetHead = 90;
float resetHeadSpeed = 0;
boolean resetHeadBoolean = false;

// RESET NECK
float resetNeck = 90;
float resetNeckSpeed = 0;
boolean resetNeckBoolean = false;

// DANCE NECK 
float danceNeckPos = 90;
float danceNeckSpeed = 0; //set in the serial event
float danceNeckMax = 120;
float danceNeckMin = 60;
int danceNeckShiftCount = 0;
int danceNeckShiftThresh = 4;
boolean danceNeckBoolean = false;

// DANCE HEAD
float danceHeadPos = 90;
float danceHeadSpeed = 0;  //set in the serial event
float danceHeadMax = 95;
float danceHeadMin = 85;
int danceHeadShiftCount = 0;
int danceHeadShiftThresh = 8;
boolean danceHeadBoolean = false;

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
int blinkInterval = 5;

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

// SURPRISED EYE ARRAYS
uint8_t surprisedEyeOnLength = 26;
uint8_t surprisedEyeOffLength = 12;
uint8_t surprisedEyeOn[] = {0,1,2,3,4,5,6,7,8,9,10,11,18,      24,25,26,27,28,29,30,31,32,33,34,35,42};
uint8_t surprisedEyeOff[] = {12,13,14,15,16,17,     36,37,38,39,40,41};

// FLAT EYE ARRAYS
uint8_t flatEyeOnLength = 10;
uint8_t flatEyeOffLength = 28;
uint8_t flatEyeOn[] = {0,12,18,15,6,      24,36,42,39,30};
uint8_t flatEyeOff[] = {1,2,3,4,5,7,8,9,10,11,13,14,16,17,      25,26,27,28,29,31,32,33,34,35,37,38,40,41};

// SQUINT EYE ARRAYS
uint8_t squintEyeOnLength = 10;
uint8_t squintEyeOffLength = 28;
uint8_t squintEyeOn[] = {8,16,18,14,4,      34,41,42,37,26};
uint8_t squintEyeOff[] = {9,10,11,0,1,2,3,5,6,7,12,13,15,17,       33,32,31,30,29,28,27,25,24,35,36,38,39,40};

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

//DEAD EYES
uint8_t deadEyeOnLength = 18;
uint8_t deadEyeOffLength = 20;
uint8_t deadEyeOn[] = {2,4,8,10,13,14,16,17,18,      26,28,32,34,37,38,40,41,42};
uint8_t deadEyeOff[] = {0,1,3,5,6,7,9,11,12,15,    24,25,27,29,30,31,33,35,36,39};

//ANGRY EYES
uint8_t angryEyeOnLength = 24;
uint8_t angryEyeOffLength = 14;
uint8_t angryEyeOn[] = {2,3,4,5,6,7,8,13,14,15,16,18,      24,25,26,27,28,34,35,36,37,38,41,42};
uint8_t angryEyeOff[] = {0,1,9,10,11,12,17,    29,30,31,32,33,39,40};

// HEART LED FADE VARIABLES
float fadeValue = 30;
float fadeSpeed = 0.05;
int fadeLedPin = 5;

// WAKE UP 
int wakeUpCount = 0;
int wakeUpInterval = 400;
long previousWakeUpMillis = 0;
boolean wakeUpBoolean = false;
boolean wakeUpState = false;
float wakeUpPos = initialServoHeadPos;
float wakeUpSpeed = 0;
boolean wakeUpServo = false;
boolean stopBlink = false;

// SLEEP
int sleepCount = 0;
int sleepInterval = 200;
long previousSleepMillis = 0;
boolean sleepBoolean = false;
boolean sleepState = false;
float sleepPos = 85;
float sleepSpeed = 0;
boolean sleepServo = false;

// HIGH FIVE 
int highFiveUpPos = 130;
boolean highFiveUpBoolean = false;

// HIGH FIVE DOWN
boolean highFived = false;

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
boolean playHappyMelody2 = false;
boolean playLoveMelody = false;
boolean playSadMelody = false;
boolean playAngryMelody = false;
boolean playProcessingMelody = false;

boolean alive = true;

void setup() {

   Serial.begin(9600);
   tlc.begin();
   
   servoHead.attach(servoHeadPin);
   servoNeck.attach(servoNeckPin);
   servoArm.attach(servoArmPin);
   
   servoHead.write(initialServoHeadPos);
   servoNeck.write(initialServoNeckPos);
   servoArm.write(initialServoArmPos);
   
   t.every(5000, setBlink);
   
   pinMode(vibrationPin, OUTPUT);
}

void loop() {

   if(Serial.available() > 0){
      char inByte = Serial.read();
      
      //HAPPY
      if(inByte == 'h'){
        atRest = false;
        // resetting variables otherwise screws up speed of movement
        beHappyPos = 90;
        beHappyBoolean = true;
        beHappySpeed = 0.02; //0.005;
        beHappyNeckPos = 90;
        beHappyNeckBoolean = true;
        beHappyNeckSpeed = 0.02;
        changeEyes(happyEyeOn,happyEyeOnLength,happyEyeOff,happyEyeOffLength);
        playHappyMelody = true;
      }
      
      //SAD
      if(inByte == 's'){
        atRest = false;
        beSadPos = 90;
        beSadBoolean = true;
        beSadSpeed = 0.01; //0.001;
        beSadNeckPos = 90;
        beSadNeckBoolean = true;
        beSadNeckSpeed = 0.01;
        changeEyes(verySadEyeOn,verySadEyeOnLength,verySadEyeOff,verySadEyeOffLength);
        playSadMelody = true;
      }
      
      //DANCE
      if(inByte == 'd'){
         atRest = false;
         danceNeckBoolean = true;
         danceHeadBoolean = true;
         danceHeadSpeed = 0.05;// 0.5;
         danceNeckSpeed = 0.04; //0.1;
      }
      
      //ANGRY
      if(inByte == 'a') {
         atRest = false;
         changeEyes(flatEyeOn,flatEyeOnLength,flatEyeOff,flatEyeOffLength); 
         servoNeck.write(110);
         servoHead.write(95);
         playAngryMelody = true;
      }
      
      // DEAD/KILL
      if(inByte == 'k'){
         atRest = false;
         beSadPos = 90;
         beSadBoolean = true;
         beSadSpeed = 0.05;
         changeEyes(deadEyeOn,deadEyeOnLength,deadEyeOff,deadEyeOffLength);
         //alive = false;
      }
      
      // LOVE
      if(inByte == 'l'){
         atRest = false;
         beHappyPos = 90;
         beHappyBoolean = true;
         beHappySpeed = 0.05;
         beHappyNeckPos = 90;
         beHappyNeckBoolean = true;
         beHappyNeckSpeed = 0.02;
         changeEyes(heartEyeOn,heartEyeOnLength,heartEyeOff,heartEyeOffLength);
         playLoveMelody = true;
      }
      
      // WAKE UP
      if(inByte == 'w'){
        wakeUpState = true;
        wakeUpCount = 0;
        wakeUpServo = true;
        stopBlink = false; // so that you can wake him up again
        wakeUpSpeed = 0.01;
        sleepPos = 90;
      }
      
      // SLEEP
      if(inByte == 'z'){
        sleepState = true;
        atRest = false;
        sleepCount = 0;
        sleepServo = true;
        sleepSpeed = 0.01; 
        wakeUpPos = initialServoHeadPos;  // reset it so as to be able to switch correctly between awake and asleep
      }
      
      // PET
      if(inByte == 'p'){
         atRest = false;
         beHappyPos = 90;
         beHappyBoolean = true;
         beHappySpeed = 0.05;
         beHappyNeckPos = 90;
         beHappyNeckBoolean = true;
         beHappyNeckSpeed = 0.02;
         changeEyes(happyEyeOn,happyEyeOnLength,happyEyeOff,happyEyeOffLength);
         digitalWrite(vibrationPin, HIGH);
      }
      
      // SURPRISE
      //changeEyes(surprisedEyeOn,surprisedEyeOnLength,surprisedEyeOff,surprisedEyeOffLength); 
      
      // ANSWER YES TO QUESTION
      if(inByte == 'y'){
        atRest = false;
        sayYesBoolean = true;
        sayYesSpeed = 0.008; //0.008;
        changeEyes(happyEyeOn,happyEyeOnLength,happyEyeOff,happyEyeOffLength);
        playProcessingMelody = true;
      }
      
      // ANSWER NO TO QUESTION
      if(inByte == 'n'){
        atRest = false;
        sayNoBoolean = true;
        sayNoSpeed = 0.05;
        changeEyes(sadEyeOn,sadEyeOnLength,sadEyeOff,sadEyeOffLength);
      }
      
      // HIGH FIVE 
      if(inByte == 'f'){
         atRest = false;
         changeEyes(happyEyeOn,happyEyeOnLength,happyEyeOff,happyEyeOffLength);
         highFiveUpBoolean = true;
         playHappyMelody2 = true;
      }
      
      // RESET 
      if(inByte == 'r'){
         // stop vibration motor
         digitalWrite(vibrationPin, LOW);
         
         // move hand back down
         highFiveUpBoolean = false;
         
         // to make eyes blink
         atRest = true;
         
         blinkCount = 0;
         blinkEyeBool = true;
         
         alive = true;
         
         // put servos back in place
         resetServos();
      }
      
      if(inByte == 't'){
         playHappyMelody = true;
        servoNeck.write(60); 
      }
      
   } 
   
   // update the timer
   t.update();

   // BLINK EYE - blink the eyes only when no other action is happening
   if(atRest && blinkEyeBool){
     blinkEyes(); 
   }
   
    // wake him up
    if(wakeUpState){
       wakeUpEyes();
       if(!stopBlink){
         blinkInterval = 100;
         blinkEyes();
       }
    }
    
    if(sleepState){
       // do eye stuff here
       sleepEyes();
    }
    
    if(sayNoBoolean){
       sayNoMovement();
       sayNo();
       //changeEyes(happyEyeOn,happyEyeOnLength,happyEyeOff,happyEyeOffLength);

    }
    
    if(sayYesBoolean){
      sayYesMovement();
      sayYes(); 
    }
    
    if(beSadBoolean) {
      beSadMovement();
      beSad();
    }
    
    if(beSadNeckBoolean){
       beSadNeckMovement();
       beSadNeck(); 
    }
  
    if(beHappyBoolean){
      beHappyMovement();
      beHappy(); 
    }
    
    if(beHappyNeckBoolean){
       beHappyNeckMovement();
       beHappyNeck(); 
    }

    if(danceHeadBoolean){
      danceHeadMovement(); 
      danceHead();
    }
  
    if(danceNeckBoolean){
      danceNeckMovement();
      danceNeck();
    }
    
    if(highFiveUpBoolean){
       highFiveUp(); 
       
    } else if(highFiveUpBoolean == false){
       highFiveDown(); 
    }

   
   // FADE LED HEART
   //if(alive){
     //fadeSpeed = 0.05;
     analogWrite(fadeLedPin, fadeValue);
     fadeValue += fadeSpeed;
     if(fadeValue >= 255 || fadeValue <=5){
        fadeSpeed *= -1; 
     }
   //} else {
     //analogWrite(fadeLedPin, 0);
    // fadeValue -= fadeSpeed;
   //}
   
   // PLAY TONES
   if(playHappyMelody){
      playMelody(); 
   }
   
   if(playSadMelody){
      playMelody8(); 
   }
   
   if(playAngryMelody){
      playMelody10(); 
   }
   
   if(playProcessingMelody){
      playMelody2(); 
   }
   
   if(playHappyMelody2){
      playMelody4(); 
   }
   
   if(playLoveMelody){
      playMelody9(); 
   }
   
   // RESET TONES
   if(melodyCount == melodyMax){
      melodyCount = 0;
      playHappyMelody = false;
   }
   if(melody2Count == melody2Max){
      melody2Count = 0;
      playProcessingMelody = false;
   }
   if(melody3Count == melody3Max){
      melody3Count = melody3Max;
   }
   if(melody4Count == melody4Max){
      melody4Count = 0;
      playHappyMelody2 = false;
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
      melody8Count = 0;
      playSadMelody = false;
   }
   if(melody9Count == melody9Max){
      melody9Count = 0;
      playLoveMelody = false;
   }
   if(melody10Count == melody10Max){
      melody10Count = 0;
      playAngryMelody = false;
   }
   
}

