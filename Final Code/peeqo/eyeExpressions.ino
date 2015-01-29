void allEyesOff(){
  // LEFT EYE
   for(int i=0; i < 19;i++){
      tlc.setPWM(i, 0);
      tlc.write();
   } 
   
   // RIGHT EYE
   for(int i=24; i < 43;i++){
      tlc.setPWM(i, 0);
      tlc.write();
   }
}

void fullEyes(){
   //LEFT EYE
    for(int i=0; i < 19;i++){
      tlc.setPWM(i, 4095);
      tlc.write();
   } 
   
   // RIGHT EYE
   for(int i=24; i < 43;i++){
      tlc.setPWM(i, 4095);
      tlc.write();
   }
}

void changeEyes(uint8_t eyeOnArray[], uint8_t eyeOnArrayLength, uint8_t eyeOffArray[], uint8_t eyeOffArrayLength){

  for(int i=0;i< eyeOnArrayLength;i++){
     tlc.setPWM(eyeOnArray[i], 4095); 
     tlc.write();
  }
  
  for(int i=0;i<eyeOffArrayLength;i++){
     tlc.setPWM(eyeOffArray[i], 0);
     tlc.write(); 
  }
  
}



