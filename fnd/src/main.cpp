#include <Arduino.h>

int fnd_num [10][4] = {
  {0,0,0,0}, {0,0,0,1}, {0,0,1,0}, {0,0,1,1}, {0,1,0,0}, {0,1,0,1}, {0,1,1,0}, {0,1,1,1}, {1,0,0,0}, {1,0,0,1}
};

int b1;
int b2;
int b3;
int b4;
int bb1 = 0;
int bb2 = 0;
int bb3 = 0;
int bb4 = 0;
int count = 0;
void display_num(int num)
{
  for(int i = 0; i < 50; i++){
    digitalWrite(18, 1);
  
    digitalWrite(14, fnd_num[num] [3]);
    digitalWrite(15, fnd_num[num] [2]);
    digitalWrite(16, fnd_num[num] [1]);
    digitalWrite(17, fnd_num[num] [0]);
    delay(10);
  }
}

void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);

  pinMode(10, INPUT);
  pinMode(11, INPUT);
  pinMode(12, INPUT);
  pinMode(13, INPUT);

  pinMode(14, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(17, OUTPUT);
  pinMode(18, OUTPUT);
  pinMode(19, OUTPUT);

  digitalWrite(2, 1);
  digitalWrite(3, 1);
  digitalWrite(4, 1);
  digitalWrite(5, 1);
  digitalWrite(6, 1);
  digitalWrite(7, 1);
  digitalWrite(8, 1);
  digitalWrite(9, 1);
}

void loop() {
  // put your main code here, to run repeatedly:
  b1 = digitalRead(10);
  b2 = digitalRead(11);
  b3 = digitalRead(12);
  b4 = digitalRead(13);

  if(b1 == 0)
    bb1 = 1;
  if(b2 == 0)
    bb2 = 2;
  if(b3 == 0)
    bb3 = 4;
  if(b4 == 0)
    bb4 = 8;
  int num1 = bb1+bb2+bb3+bb4;
  display_num(num1);
}

