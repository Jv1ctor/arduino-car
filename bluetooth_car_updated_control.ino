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

float velocity_min = 100;

//Create a new software  serial
SoftwareSerial bluetooth(1, 0); //TX, RX (Bluetooth)

void move_forward(){
    digitalWrite(motorA1, HIGH);
    digitalWrite(motorA2, LOW);
               
    digitalWrite(motorB1, HIGH);
    digitalWrite(motorB2, LOW);
}

void move_forward_left(int min){
    analogWrite(motorA1, min);
    digitalWrite(motorA2, LOW);
     
    digitalWrite(motorB1, HIGH);
    digitalWrite(motorB2, LOW);
} 

void move_forward_right(int min){
    digitalWrite(motorA1, HIGH);
    digitalWrite(motorA2, LOW);

    analogWrite(motorB1, min);
    digitalWrite(motorB2, LOW);
}

void move_backward(){
    digitalWrite(motorA1, LOW);
    digitalWrite(motorA2, HIGH);
                
    digitalWrite(motorB1, LOW);
    digitalWrite(motorB2, HIGH);
}

void move_backward_left(int min){
    digitalWrite(motorA1, LOW);
    analogWrite(motorA2, min);
     
    digitalWrite(motorB1, LOW);
    digitalWrite(motorB2, HIGH);
}

void move_backward_right(int min){
    digitalWrite(motorA1, LOW);
    digitalWrite(motorA2, HIGH);

    digitalWrite(motorB1, LOW);
    analogWrite(motorB2, min);   
}

void move_left(){
    digitalWrite(motorA1, LOW);
    digitalWrite(motorA2, LOW);
     
    digitalWrite(motorB1, HIGH);
    digitalWrite(motorB2, LOW);
}

void move_right(){
    digitalWrite(motorA1, HIGH);
    digitalWrite(motorA2, LOW);

    digitalWrite(motorB1, LOW);
    digitalWrite(motorB2, LOW);
}

void stop(){
    digitalWrite(motorA1, LOW);  
    digitalWrite(motorA2, LOW);
                
    digitalWrite(motorB1, LOW);
    digitalWrite(motorB2, LOW); 
}

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
      
      stop(); 
  }

  if (bluetooth.available() > 0) {
    char val = bluetooth.read();

    if(val == FORWARD){
      move_forward();
      is_run = true;
        
    }else if(val == BACKWARD){
      move_backward();
      is_run = true;
        
    }else if(val == RIGHT){
      move_right();
      is_run = true;
        
    }else if(val == FORWARD_RIGHT){
      move_forward_right(velocity_min);
      is_run = true;
        
    }else if(val == BACKWARD_RIGHT){
      move_backward_right(velocity_min);
      is_run = true;
        
    }else if(val == LEFT){
      move_left();
      is_run = true;
        
    }else if(val == FORWARD_LEFT){
      move_forward_left(velocity_min);
      is_run = true;
        
    }else if(val == BACKWARD_LEFT){
      move_backward_left(velocity_min);
      is_run = true;
        
    }
  }

  

  

}
