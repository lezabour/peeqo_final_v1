import processing.serial.*;

Serial myPort;

void setup() {
  size(800,600);
  println(Serial.list());
  String portname = "/dev/cu.usbserial-A703X5JQ";
  myPort = new Serial(this, portname, 9600);
  myPort.bufferUntil('\n');
}

void draw() {
  background(255);
}

void keyPressed() {
   if(key == 'a'){
      myPort.write('a'); 
   }
   
   if(key == 'o') {
      myPort.write('o'); 
   }
   
   if(key == 'b'){
      myPort.write('b'); 
   }
  
}
