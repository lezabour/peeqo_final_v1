import processing.serial.*;

Serial myPort;

//Button Variables
color btnFill = color(0, 0, 0);
color btnStroke = color(0,0,0);
float[] btnDimensions = {280, 200};
float[] resetBtnDimensions = {260, 30};

//Button Enter
Button enterBtn;
float[] enterBtnCenter = new float[2];
color enterBtnHover = color(26, 165, 132);
String enterBtnText = "Click to Play With Me";
float[] enterBtnDimensions = {350, 150};



//submit Question
Button submitQuestionBtn;
float[] submitQuestionBtnCenter = new float[2];
color submitQuestionBtnHover = color(26, 165, 132);
String submitQuestionBtnText = "Ask Peeqo";
float[] submitQuestionBtnDimensions = {300, 100};

// Back Button
Button backBtn;
float[] backBtnCenter = {1280, 160};
color backBtnHover = color(26, 165, 132);
String backBtnText = "Go Back";
float[] backBtnDimensions = {200, 100};

//Ask Question
Button questionBtn;
float[] questionBtnCenter = {330, 180};
color questionBtnHover = color(229, 25, 55);
String questionBtnText = "Ask Him a Question";

//Pet Button
Button petBtn;
float[] petBtnCenter = {330, 430};
color petBtnHover = color(229, 25, 55);
String petBtnText = "Pet Peeqo";

// High Five
Button highFiveBtn;
float[] highFiveBtnCenter = {330, 680};
color highFiveBtnHover = color(229, 25, 55);
String highFiveBtnText = "Give him a High Five";

//Happy
Button happyBtn;
float[] happyBtnCenter = {715, 180};
color happyBtnHover = color(0, 155, 222);
String happyBtnText = "Make him Happy";

//Sad
Button sadBtn;
float[] sadBtnCenter = {715, 430};
color sadBtnHover = color(0, 155, 222);
String sadBtnText = "Make him Sad";

// Angry
Button angryBtn;
float[] angryBtnCenter = {715, 680};
color angryBtnHover = color(0, 155, 222);
String angryBtnText = "Make him Angry";

//Play Dead
Button playDeadBtn;
float[] playDeadBtnCenter = {1100, 180};
color playDeadBtnHover = color(200, 90, 25);
String playDeadBtnText = "Make him Play Dead";

// Love
Button loveBtn;
float[] loveBtnCenter = {1100, 430};
color loveBtnHover = color(200, 90, 25);
String loveBtnText = "Say I Love You";

// Dance
Button danceBtn;
float[] danceBtnCenter = {1100, 680};
color danceBtnHover = color(200, 90, 25);
String danceBtnText = "Make him Dance";

boolean enter = false;
boolean enterAnimation = false;
boolean askQuestion = false;
boolean pet = false;
boolean playDead = false;
boolean highFive = false;
boolean love = false;
boolean happy = false;
boolean sad = false;
boolean angry = false;
boolean dance = false;
boolean nextPage = false;

int animationCount = 0;
PImage enterScreen;
String question = "";
String questionHint = "Start typing your yes/no question...";
float largeText = 30;
float medText = 24;
float smallText = 16;

void setup() {
   size(displayWidth, displayHeight);
   String portname = "/dev/cu.usbserial-A703X5JQ";
   myPort = new Serial(this, portname, 9600);
   myPort.bufferUntil('\n');
   
   enterBtnCenter[0] = width/2;
   enterBtnCenter[1] = height/2 + 200;
   
   submitQuestionBtnCenter[0] = width/2;
   submitQuestionBtnCenter[1] = height/2 + 200;
   
   enterBtn = new Button(enterBtnCenter, enterBtnDimensions, btnFill, enterBtnHover, btnStroke, enterBtnText, largeText);
   questionBtn = new Button(questionBtnCenter, btnDimensions, btnFill, questionBtnHover, btnStroke, questionBtnText, medText);
   petBtn = new Button(petBtnCenter, btnDimensions, btnFill, petBtnHover, btnStroke, petBtnText, medText);
   playDeadBtn = new Button(playDeadBtnCenter, btnDimensions, btnFill, playDeadBtnHover, btnStroke, playDeadBtnText, medText);
   highFiveBtn = new Button(highFiveBtnCenter, btnDimensions, btnFill, highFiveBtnHover, btnStroke, highFiveBtnText, medText);
   loveBtn = new Button(loveBtnCenter, btnDimensions, btnFill, loveBtnHover, btnStroke, loveBtnText, medText);
   happyBtn = new Button(happyBtnCenter, btnDimensions, btnFill, happyBtnHover, btnStroke, happyBtnText, medText);
   sadBtn = new Button(sadBtnCenter, btnDimensions, btnFill, sadBtnHover, btnStroke, sadBtnText, medText);
   angryBtn = new Button(angryBtnCenter, btnDimensions, btnFill, angryBtnHover, btnStroke, angryBtnText, medText);
   danceBtn = new Button(danceBtnCenter, btnDimensions, btnFill, danceBtnHover, btnStroke, danceBtnText, medText);
   
   backBtn = new Button(backBtnCenter, backBtnDimensions, btnFill, backBtnHover, btnStroke, backBtnText, largeText);
   submitQuestionBtn = new Button(submitQuestionBtnCenter, submitQuestionBtnDimensions, btnFill, submitQuestionBtnHover, btnStroke, submitQuestionBtnText, medText);
   
   enterScreen = loadImage("peeqo.png");
}

void draw() {
  background(255);
  if(!enter){
    imageMode(CENTER);
    image(enterScreen, width/2, height/2 - 150);
    enterBtn.display();
    
    if(enterAnimation){
       animationCount++;
       if(animationCount >= 15){
          enter = true; 
       }
    }
    
  } else {
    
    if(askQuestion){
      textAlign(CENTER, CENTER);
      textSize(24);
      fill(0);
      text("Start typing a yes or no question", width/2, 200);
      
      textSize(30);
      textAlign(CENTER, CENTER);
      if(question.length() > 0){
        fill(0);
        text(question, width/2, height/2);
      } else {
        fill(150);
        text(questionHint, width/2, height/2);
      }
      
      if(question.length() > 10){
         submitQuestionBtn.display(); 
      }
      
      backBtn.display();
    } else if(pet){
      textSize(30);
      textAlign(CENTER, CENTER);
      fill(150);
      text("Stroke Peeqo's head, he likes it...", width/2, height/2);
      backBtn.display();
      
    }else if(playDead){
      textSize(30);
      textAlign(CENTER, CENTER);
      fill(150);
      text("The oldest trick in the book", width/2, height/2);
      backBtn.display();
      
    }else if(highFive){
      textSize(30);
      textAlign(CENTER, CENTER);
      fill(150);
      text("Give him a high five. Tap his hand!", width/2, height/2);
      backBtn.display();
      
    }else if(love){
      textSize(30);
      textAlign(CENTER, CENTER);
      fill(150);
      text("Peeqo loves you too", width/2, height/2);
      backBtn.display();
      
    }else if(happy){
      textSize(30);
      textAlign(CENTER, CENTER);
      fill(150);
      text("You're making him so happy", width/2, height/2);
      backBtn.display();
      
    }else if(sad){
      textSize(30);
      textAlign(CENTER, CENTER);
      fill(150);
      text("Awww...", width/2, height/2);
      backBtn.display();
      
    }else if(angry){
      
      textSize(30);
      textAlign(CENTER, CENTER);
      fill(150);
      text("Grrrr...", width/2, height/2);
      backBtn.display();
      
    }else if(dance){
      
      textSize(30);
      textAlign(CENTER, CENTER);
      fill(150);
      text("Look at him move!", width/2, height/2);
      backBtn.display();
      
    } else {
      
      questionBtn.display(); 
      petBtn.display();
      playDeadBtn.display();
      highFiveBtn.display();
      loveBtn.display();
      happyBtn.display();
      sadBtn.display();
      angryBtn.display();
      danceBtn.display();
    }
  }
}

void mousePressed() {
  if (enterBtn.clicked() && !enter) {
    enterAnimation = true;
  }
  
  if(questionBtn.clicked() && enter && !nextPage){
     askQuestion = true;
     nextPage = true;
     questionHint = "Start typing your yes/no question...";
  }
  
  if(petBtn.clicked() && enter && !nextPage) {
     pet = true; 
     nextPage = true;
     myPort.write('p');
  }
  
  if(playDeadBtn.clicked() && enter && !nextPage){
     playDead = true;
     nextPage = true;
     myPort.write('k');
  }
  
  if(highFiveBtn.clicked() && enter && !nextPage){
     highFive = true;
     nextPage = true;
     myPort.write('f');
  }
  
  if(happyBtn.clicked() && enter && !nextPage){
     happy = true;
     nextPage = true;
     myPort.write('h');
  }
  
  if(sadBtn.clicked() && enter && !nextPage){
     sad = true;
     nextPage = true;
     myPort.write('s');
  }
  
  if(angryBtn.clicked() && enter && !nextPage){
     angry = true;
     nextPage = true;
     myPort.write('a');
  }
  
  if(danceBtn.clicked() && enter && !nextPage){
     dance = true;
     nextPage = true;
     myPort.write('d');
  }
  
  if(loveBtn.clicked() && enter && !nextPage){
     love = true;
     nextPage = true;
     myPort.write('l');
  }
  
  if(submitQuestionBtn.clicked() && enter && askQuestion){
     int randomNum = int(random(0,2));
     if(randomNum == 0){
       myPort.write('y');
     } else if(randomNum == 1){
       myPort.write('n');
     } 
     question = "";
     questionHint = "Ask another question...";
  }
  
  if(backBtn.clicked() && enter && nextPage){
     askQuestion = false;
     pet = false;
     playDead = false;
     highFive = false;
     love = false;
     happy = false;
     sad = false;
     angry = false;
     dance= false;
     nextPage = false;
     myPort.write('r');
  }
}

void keyPressed() {
   if(key == ' ' && enter && !askQuestion){
       enter = false;
       askQuestion = false;
       pet = false;
       playDead = false;
       highFive = false;
       love = false;
       happy = false;
       sad = false;
       angry = false;
       dance= false;
       nextPage = false;
       animationCount = 0;
       enterAnimation = false;
       myPort.write('r');
       questionHint = "Start typing your yes/no question...";
   }
   
   if ((key >= 'A' && key <= 'z') || key == ' ') {
     question = question + key;
  }

    
    if(key == BACKSPACE) {
       if(enter && askQuestion && question.length()>0){
          question = question.substring(0,max(0,question.length()-1)); 
       }
    }
    
    if(key == ENTER) {
      if(enter && askQuestion && question.length() > 10){
         int randomNum = int(random(0,2));
         if(randomNum == 0){
           myPort.write('y');
         } else if(randomNum == 1){
           myPort.write('n');
         } 
         question = "";
         questionHint = "Ask another question...";
      }
    }

}

