#include <Servo.h>


float cm = 0;
int trig = 2;
int echo = 3;
int servMotor = 11;
Servo servo;

int motorA1 = 5;
int motorA2 = 6;

int motorB1 = 9;
int motorB2 = 10;

int velocidade = 255;

void moveLeft(){
  analogWrite(motorA1, 0);
  analogWrite(motorA2, 0);

  analogWrite(motorB1, velocidade);
  analogWrite(motorB2, 0);
}

void moveRight(){
  analogWrite(motorA1, velocidade);
  analogWrite(motorA2, 0);

  analogWrite(motorB1, 0);
  analogWrite(motorB2, 0);
}

void moveFront(){
  analogWrite(motorA1, velocidade);
  analogWrite(motorA2, 0);

  analogWrite(motorB1, velocidade);
  analogWrite(motorB2, 0);
}

void moveBack(){
  analogWrite(motorA1, 0);
  analogWrite(motorA2, velocidade);

  analogWrite(motorB1, 0);
  analogWrite(motorB2, velocidade);
}

void stop(){
  analogWrite(motorA1, 0);
  analogWrite(motorA2, velocidade);

  analogWrite(motorB1, 0);
  analogWrite(motorB2, velocidade);
}

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup(){ 
  servo.attach(servMotor, 500, 2500);;
  Serial.begin(9600);
  servo.write(90);

  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);

  Serial.begin(9600);
}

// forward_left = 135
// left = 180
// right = 0
// forward_right = 35
// forward = 90

int angles[5] = {0, 135, 180, 35, 90};

void loop(){
  float max_dist = 30.0;
  // measure the ping time in cm
  cm = 0.01723 * readUltrasonicDistance(trig, echo);

  // Serial.println(cm);

  if( cm <= max_dist){
    servo.write(angles[0]);
    if(cm > max_dist){
      Serial.println("livre");
    }
    delay(1000);

    servo.write(angles[1]);
    if(cm > max_dist){
      Serial.println("livre");
    }
    delay(1000);
    servo.write(angles[2]);
    if(cm > max_dist){
      Serial.println("livre");
    }
    delay(1000);

    servo.write(angles[3]);
    if(cm > max_dist){
      Serial.println("livre");
    }
    delay(1000);

    servo.write(angles[4]);
    if(cm > max_dist){
      Serial.println("livre");
    }
    delay(1000);
  
  }else{
    moveFront();
  }

  // if (cm <= max_dist){
  // 	servo.write(180);
  //   if (cm <= max_dist){
  //     servo.write(0);
  //       if (cm <= max_dist){
  //         stop();
  //       }else if (cm > max_dist){
  //       	moveLeft();
  //       }
  //   }else if (cm > max_dist){
  //     moveRight();
  //   }else if (cm > max_dist){
  //     moveFront();
  //   }
    
  // }
}
    
 