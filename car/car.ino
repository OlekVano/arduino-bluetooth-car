#include <SoftwareSerial.h>
#include "motor.h"

SoftwareSerial BSerial(7,6);

Motor motor1 = Motor(11, 12, 13);
Motor motor2 = Motor(10, 8, 9);

void setup() {
  Serial.begin(9600);
  BSerial.begin(9600);

  motor1.start();
  motor2.start();
}

void loop() {
  if (!BSerial.available()) return
  char command = BSerial.read();
  //Serial.println(command);
  switch(command) {
    case 'l':
    motor1.move(150);
    motor2.move(50);
    break;
    
    case 'r':
    motor1.move(50);
    motor2.move(150);
    break;
    
    case 'f':
    motor1.move(100);
    motor2.move(100);
    break;

    case 'b':
    motor1.move(100, true);
    motor2.move(100, true);
    break;

    case 's':
    motor1.stop();
    motor2.stop();
    break;
  }
}
