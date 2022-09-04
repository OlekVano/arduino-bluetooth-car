class Motor {
  public:
    int speedPin;
    int directionPin1;
    int directionPin2;
  
    Motor(int speedPin_, int directionPin1_, int directionPin2_) {
      speedPin = speedPin_;
      directionPin1 = directionPin1_;
      directionPin2 = directionPin2_;
    }

    void start() {
      pinMode(speedPin, OUTPUT);
      pinMode(directionPin1, OUTPUT);
      pinMode(directionPin2, OUTPUT);
    }

    void stop() {
      analogWrite(speedPin, 0);
      digitalWrite(directionPin1, LOW);
      digitalWrite(directionPin2, LOW);
    }

    void move(int speed, bool reverse=false) {
      if (speed <= 255 && speed > 0) {
        if (reverse) {
          analogWrite(speedPin, speed);
          digitalWrite(directionPin1, LOW);
          digitalWrite(directionPin2, HIGH);
        }
        else {
          analogWrite(speedPin, speed);
          digitalWrite(directionPin1, HIGH);
          digitalWrite(directionPin2, LOW);
        } 
      }
      else {
        stop();
      }
    }
};
