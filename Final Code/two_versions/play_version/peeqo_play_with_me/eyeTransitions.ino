////// BLINK EYE

void setBlink(){
  blinkEyeBool = true;
}  

void blinkEyes(){
   blinkCount++;
   
   if(blinkCount == blinkInterval*1){
     //left eye
     tlc.setPWM(9, 0);
     tlc.write();
     //right eye
     tlc.setPWM(33, 0);
     tlc.write();
   } else if(blinkCount == blinkInterval*2){
     //left eye
     tlc.setPWM(8, 0);
     tlc.write();
     tlc.setPWM(10, 0);
     tlc.write();
     //right eye
     tlc.setPWM(32, 0);
     tlc.write();
     tlc.setPWM(34, 0);
     tlc.write();
   } else if(blinkCount == blinkInterval*3){
     //left eye
     tlc.setPWM(7, 0);
     tlc.write();
     tlc.setPWM(16, 0);
     tlc.write();
     tlc.setPWM(17, 0);
     tlc.write();
     tlc.setPWM(11, 0);
     tlc.write();
     //right eye
     tlc.setPWM(31, 0);
     tlc.write();
     tlc.setPWM(40, 0);
     tlc.write();
     tlc.setPWM(41, 0);
     tlc.write();
     tlc.setPWM(35, 0);
     tlc.write();
   } else if(blinkCount == blinkInterval*4){
     //left eye
     tlc.setPWM(6, 0);
     tlc.write();
     tlc.setPWM(15, 0);
     tlc.write();
     tlc.setPWM(18, 0);
     tlc.write();
     tlc.setPWM(12, 0);
     tlc.write();
     tlc.setPWM(0, 0);
     tlc.write();
     //right eye
     tlc.setPWM(30, 0);
     tlc.write();
     tlc.setPWM(39, 0);
     tlc.write();
     tlc.setPWM(42, 0);
     tlc.write();
     tlc.setPWM(36, 0);
     tlc.write();
     tlc.setPWM(24, 0);
     tlc.write();
   } else if(blinkCount== blinkInterval*5){
     //left eye
     tlc.setPWM(5, 0);
     tlc.write();
     tlc.setPWM(14, 0);
     tlc.write();
     tlc.setPWM(13, 0);
     tlc.write();
     tlc.setPWM(1, 0);
     tlc.write();
     //right eye
     tlc.setPWM(29, 0);
     tlc.write();
     tlc.setPWM(38, 0);
     tlc.write();
     tlc.setPWM(37, 0);
     tlc.write();
     tlc.setPWM(25, 0);
     tlc.write();
   } else if(blinkCount == blinkInterval*6){
     //left eye
     tlc.setPWM(4, 0);
     tlc.write();
     tlc.setPWM(2, 0);
     tlc.write();
     //right eye
     tlc.setPWM(28, 0);
     tlc.write();
     tlc.setPWM(26, 0);
     tlc.write();
   } else if(blinkCount == blinkInterval*7){
     //left eye
     tlc.setPWM(3, 0);
     tlc.write();
     //right eye
     tlc.setPWM(27, 0);
     tlc.write();
   } else if(blinkCount == blinkInterval*9){
     //left eye
     tlc.setPWM(3, 4095);
     tlc.write();
     //right eye
     tlc.setPWM(27, 4095);
     tlc.write();
   } else if(blinkCount == blinkInterval*10){
     //left eye
     tlc.setPWM(4, 4095);
     tlc.write();
     tlc.setPWM(2, 4095);
     tlc.write();
     //right eye
     tlc.setPWM(28, 4095);
     tlc.write();
     tlc.setPWM(26, 4095);
     tlc.write();
   } else if(blinkCount == blinkInterval*11){
     //left eye
     tlc.setPWM(5, 4095);
     tlc.write();
     tlc.setPWM(14, 4095);
     tlc.write();
     tlc.setPWM(13, 4095);
     tlc.write();
     tlc.setPWM(1, 4095);
     tlc.write();
     //right eye
     tlc.setPWM(29, 4095);
     tlc.write();
     tlc.setPWM(38, 4095);
     tlc.write();
     tlc.setPWM(37, 4095);
     tlc.write();
     tlc.setPWM(25, 4095);
     tlc.write();
   } else if(blinkCount == blinkInterval*12){
     //left eye
     tlc.setPWM(6, 4095);
     tlc.write();
     tlc.setPWM(15, 4095);
     tlc.write();
     tlc.setPWM(18, 4095);
     tlc.write();
     tlc.setPWM(12, 4095);
     tlc.write();
     tlc.setPWM(0, 4095);
     tlc.write();
     //right eye
     tlc.setPWM(30, 4095);
     tlc.write();
     tlc.setPWM(39, 4095);
     tlc.write();
     tlc.setPWM(42, 4095);
     tlc.write();
     tlc.setPWM(36, 4095);
     tlc.write();
     tlc.setPWM(24, 4095);
     tlc.write();
   } else if(blinkCount == blinkInterval*13){
     //left eye
     tlc.setPWM(7, 4095);
     tlc.write();
     tlc.setPWM(16, 4095);
     tlc.write();
     tlc.setPWM(17, 4095);
     tlc.write();
     tlc.setPWM(11, 4095);
     tlc.write();
     //right eye
     tlc.setPWM(31, 4095);
     tlc.write();
     tlc.setPWM(40, 4095);
     tlc.write();
     tlc.setPWM(41, 4095);
     tlc.write();
     tlc.setPWM(35, 4095);
     tlc.write();
   } else if(blinkCount == blinkInterval*14){
     //left eye
     tlc.setPWM(8, 4095);
     tlc.write();
     tlc.setPWM(10, 4095);
     tlc.write();
     //right eye
     tlc.setPWM(32, 4095);
     tlc.write();
     tlc.setPWM(34, 4095);
     tlc.write();
   } else if(blinkCount == blinkInterval*15){
     //left eye
     tlc.setPWM(9, 4095);
     tlc.write();
     //right eye
     tlc.setPWM(33, 4095);
     tlc.write();
     
     blinkEyeBool = false;
     blinkCount = 0;
   }
    
}

//////// WAKE UP //////////

void wakeUpEyes(){
   long currentMillis = millis();
   
   if(currentMillis - previousWakeUpMillis > wakeUpInterval){
    wakeUpBoolean = !wakeUpBoolean;
    wakeUpCount++;
    previousWakeUpMillis = currentMillis;
  }

  
  if(wakeUpCount == 7){
     fullEyes(); 
     stopBlink = true;
     blinkInterval = 100;
  }
}

//////// SLEEP //////////

void sleepEyes(){
   long currentMillis = millis();
   
   if(currentMillis - previousSleepMillis > sleepInterval){
    sleepBoolean = !sleepBoolean;
    sleepCount++;
    previousSleepMillis = currentMillis;
  }
  
  if(sleepCount <= 6){
     if(sleepBoolean){
        fullEyes();
     }
     
     if(!sleepBoolean){
        allEyesOff(); 
     }
  }
  
  if(sleepCount == 6){
     allEyesOff(); 
  }
}
