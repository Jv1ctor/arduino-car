//Include the SoftwareSerial library
#include "SoftwareSerial.h"

#define FORWARD 'F'
#define BACKWARD 'B'
#define LEFT 'L'
#define RIGHT 'R'
#define CIRCLE 'C'


int motorA1 = 5;
int motorA2 = 6;

int motorB1 = 9;
int motorB2 = 10;


//Create a new software  serial
SoftwareSerial bluetooth(1, 0); //TX, RX (Bluetooth)

void setup(){
    pinMode(motorA1, OUTPUT);
    pinMode(motorA2, OUTPUT);
  
    pinMode(motorB1, OUTPUT);
    pinMode(motorB2, OUTPUT);

    bluetooth.begin(9600);
}

void loop(){ 
  if (bluetooth.available() > 0) {
    char val = bluetooth.read();

    Serial.print(val);
    if(val == FORWARD){
      digitalWrite(motorA1, HIGH);
      digitalWrite(motorA2, LOW);
               
      digitalWrite(motorB1, HIGH);
      digitalWrite(motorB2, LOW);
    }else if(val == BACKWARD){
      digitalWrite(motorA1, LOW);
      digitalWrite(motorA2, HIGH);
                
      digitalWrite(motorB1, LOW);
      digitalWrite(motorB2, HIGH);
    }else if(val == RIGHT){
      digitalWrite(motorA1, HIGH);
      digitalWrite(motorA2, LOW);
            
      digitalWrite(motorB1, LOW);
      digitalWrite(motorB2, LOW);
    }else if(val == LEFT){
      digitalWrite(motorA1, LOW);
      digitalWrite(motorA2, LOW);
     
      digitalWrite(motorB1, HIGH);
      digitalWrite(motorB2, LOW);
    }else if(val == CIRCLE){
      digitalWrite(motorA1, LOW);
      digitalWrite(motorA2, LOW);
                
      digitalWrite(motorB1, LOW);
      digitalWrite(motorB2, LOW);
    }
  }

}