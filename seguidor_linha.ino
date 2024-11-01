int motorA1 = 11;
int motorA2 = 10;

int motorB1 = 5;
int motorB2 = 6;

int leftSensor = 0; // 4 digital
int rightSensor = 3; // 7 digital

int velocidade = 130;
void setup() {
  // put your setup code here, to run once:

  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);

  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);


  pinMode(leftSensor, INPUT);
  pinMode(rightSensor, INPUT);
  Serial.begin(9600);
}

void moveLeft(){
  analogWrite(motorA1, velocidade);
  analogWrite(motorA2, 0);

  analogWrite(motorB1, 0);
  analogWrite(motorB2, 0);
}


void moveRight(){
  analogWrite(motorA1, 0);
  analogWrite(motorA2, 0);

  analogWrite(motorB1, velocidade);
  analogWrite(motorB2, 0);
}

void moveFront(){
  analogWrite(motorA1, velocidade);
  analogWrite(motorA2, 0);

  analogWrite(motorB1, velocidade);
  analogWrite(motorB2, 0);
}


void loop() {
  int leftValue = analogRead(leftSensor);
  int rightValue = analogRead(rightSensor);

  if(rightValue > 100){
    moveRight();
  }else{
    moveFront();
  }

  if(leftValue > 100){
    moveLeft();
  }else{
    moveFront();
  }



  // analogWrite(motorA1, velocidade);
  // analogWrite(motorA2, 0);

  // analogWrite(motorB1, velocidade);
  // analogWrite(motorB2, 0);

  // Serial.print("sensor Esquerdo:");
  // Serial.println(leftValue);
  // delay(1200);
  // Serial.print("sensor Direito:");
  // Serial.println(rightValue);
  // delay(1200);

}
