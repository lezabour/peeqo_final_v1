void playMelody(){  
  if(melodyCount<=melodyMax) { 
    unsigned long currentToneMillis = millis();
    if(currentToneMillis - previousToneMillis > duration[melodyCount]*1.1) {
      // save the last time you blinked the LED 
      previousToneMillis = currentToneMillis;   
      // set the LED with the ledState of the variable:
      tone(speaker,melody[melodyCount],duration[melodyCount]);
      melodyCount++; 
    }
  }
} 

void playMelody2(){  
  if(melody2Count<=melody2Max) { 
    unsigned long currentToneMillis = millis();
    if(currentToneMillis - previousToneMillis > duration2[melody2Count]*1.1) {
      // save the last time you blinked the LED 
      previousToneMillis = currentToneMillis;   
      // set the LED with the ledState of the variable:
      tone(speaker,melody2[melody2Count],duration2[melody2Count]);
      melody2Count++; 
    }
  }
} 

void playMelody3(){  
  if(melody3Count<=melody3Max) { 
    unsigned long currentToneMillis = millis();
    if(currentToneMillis - previousToneMillis > duration3[melody3Count]*1.1) {
      // save the last time you blinked the LED 
      previousToneMillis = currentToneMillis;   
      // set the LED with the ledState of the variable:
      tone(speaker,melody3[melody3Count],duration3[melody3Count]);
      melody3Count++; 
    }
  }
} 

void playMelody4(){  
  if(melody4Count<=melody4Max) { 
    unsigned long currentToneMillis = millis();
    if(currentToneMillis - previousToneMillis > duration4[melody4Count]*1.1) {
      // save the last time you blinked the LED 
      previousToneMillis = currentToneMillis;   
      // set the LED with the ledState of the variable:
      tone(speaker,melody4[melody4Count],duration4[melody4Count]);
      melody4Count++; 
    }
  }
} 

void playMelody5(){  
  if(melody5Count<=melody5Max) { 
    unsigned long currentToneMillis = millis();
    if(currentToneMillis - previousToneMillis > duration5[melody5Count]*1.1) {
      // save the last time you blinked the LED 
      previousToneMillis = currentToneMillis;   
      // set the LED with the ledState of the variable:
      tone(speaker,melody5[melody5Count],duration5[melody5Count]);
      melody5Count++; 
    }
  }
} 

void playMelody6(){  
  if(melody6Count<=melody6Max) { 
    unsigned long currentToneMillis = millis();
    if(currentToneMillis - previousToneMillis > duration6[melody6Count]*1.1) {
      // save the last time you blinked the LED 
      previousToneMillis = currentToneMillis;   
      // set the LED with the ledState of the variable:
      tone(speaker,melody6[melody6Count],duration6[melody6Count]);
      melody6Count++; 
    }
  }
} 

void playMelody7(){  
  if(melody7Count<=melody7Max) { 
    unsigned long currentToneMillis = millis();
    if(currentToneMillis - previousToneMillis > duration7[melody7Count]*1.1) {
      // save the last time you blinked the LED 
      previousToneMillis = currentToneMillis;   
      // set the LED with the ledState of the variable:
      tone(speaker,melody7[melody7Count],duration7[melody7Count]);
      melody7Count++; 
    }
  }
} 

void playMelody8(){  
  if(melody8Count<=melody8Max) { 
    unsigned long currentToneMillis = millis();
    if(currentToneMillis - previousToneMillis > duration8[melody8Count]*1.1) {
      // save the last time you blinked the LED 
      previousToneMillis = currentToneMillis;   
      // set the LED with the ledState of the variable:
      tone(speaker,melody8[melody8Count],duration8[melody8Count]);
      melody8Count++; 
    }
  }
} 

void playMelody9(){  
  if(melody9Count<=melody9Max) { 
    unsigned long currentToneMillis = millis();
    if(currentToneMillis - previousToneMillis > duration9[melody9Count]*1.1) {
      // save the last time you blinked the LED 
      previousToneMillis = currentToneMillis;   
      // set the LED with the ledState of the variable:
      tone(speaker,melody9[melody9Count],duration9[melody9Count]);
      melody9Count++; 
    }
  }
} 

void playMelody10(){  
  if(melody10Count<=melody10Max) { 
    unsigned long currentToneMillis = millis();
    if(currentToneMillis - previousToneMillis > duration10[melody10Count]*1.1) {
      // save the last time you blinked the LED 
      previousToneMillis = currentToneMillis;   
      // set the LED with the ledState of the variable:
      tone(speaker,melody10[melody10Count],duration10[melody10Count]);
      melody10Count++; 
    }
  }
} 
