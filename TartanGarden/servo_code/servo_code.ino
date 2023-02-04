// Include the Servo library 
#include <Servo.h> 
// Declare the Servo pin 
int servoPin = 3; 
// Create a servo object 
Servo Servo1; 
String command;
void setup() { 
   // We need  the servo to the used pin number 
   Serial.begin(9600);
}

void runOnce() {
  Servo1.attach(servoPin);
  Servo1.write(180);
  delay(650);
  Servo1.detach();

  Servo1.write(180);
  delay(650);
  Servo1.detach();
}

void runStop() {
  Servo1.detach();
}

void loop(){ 
   // Make servo go to 0 degrees 

   if(Serial.available()){
        command = Serial.readStringUntil('\n');
         
        if(command.equals("run")){
            runOnce();
        } else if (command.equals("stop")) {
          runStop();
        }
    }
}