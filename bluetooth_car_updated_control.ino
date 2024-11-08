//Include the SoftwareSerial library
#include "SoftwareSerial.h"

#define FORWARD 'F'
#define FORWARD_LEFT 'G'
#define FORWARD_RIGHT 'I'
#define BACKWARD 'B'
#define BACKWARD_LEFT 'H'
#define BACKWARD_RIGHT 'J'
#define LEFT 'L'
#define RIGHT 'R'

int motorA1 = 5;
int motorA2 = 6;

int motorB1 = 9;
int motorB2 = 10;

unsigned long after_time = 0;
unsigned long interval = 500;

bool is_run = false;

float velocity = 10;

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
  unsigned long current_time = millis();

  if(is_run && current_time - after_time >= interval){
      is_run = false;
      after_time = current_time;
      
      digitalWrite(motorA1, LOW);  
      digitalWrite(motorA2, LOW);
                
      digitalWrite(motorB1, LOW);
      digitalWrite(motorB2, LOW); 

  }

  if (bluetooth.available() > 0) {
    char val = bluetooth.read();

    if(val == FORWARD){
      digitalWrite(motorA1, HIGH);
      digitalWrite(motorA2, LOW);
               
      digitalWrite(motorB1, HIGH);
      digitalWrite(motorB2, LOW);

      is_run = true;
    }else if(val == BACKWARD){
      digitalWrite(motorA1, LOW);
      digitalWrite(motorA2, HIGH);
                
      digitalWrite(motorB1, LOW);
      digitalWrite(motorB2, HIGH);

      is_run = true;
    }else if(val == RIGHT){
      digitalWrite(motorA1, HIGH);
      digitalWrite(motorA2, LOW);

      digitalWrite(motorB1, LOW);
      digitalWrite(motorB2, LOW);
         

      is_run = true;
    }else if(val == FORWARD_RIGHT){
      digitalWrite(motorA1, HIGH);
      digitalWrite(motorA2, LOW);

      analogWrite(motorB1, 100);
      digitalWrite(motorB2, LOW);
         

      is_run = true;
    }else if(val == BACKWARD_RIGHT){
      digitalWrite(motorA1, LOW);
      digitalWrite(motorA2, HIGH);

      digitalWrite(motorB1, LOW);
      analogWrite(motorB2, 100);
         

      is_run = true;
    }else if(val == LEFT){
      digitalWrite(motorA1, LOW);
      digitalWrite(motorA2, LOW);
     
      digitalWrite(motorB1, HIGH);
      digitalWrite(motorB2, LOW);

      is_run = true;
    }else if(val == FORWARD_LEFT){
      analogWrite(motorA1, 100);
      digitalWrite(motorA2, LOW);
     
      digitalWrite(motorB1, HIGH);
      digitalWrite(motorB2, LOW);

      is_run = true;
    }else if(val == BACKWARD_LEFT){
      digitalWrite(motorA1, LOW);
      analogWrite(motorA2, 100);
     
      digitalWrite(motorB1, LOW);
      digitalWrite(motorB2, HIGH);

      is_run = true;
    }
  }

  

  

}