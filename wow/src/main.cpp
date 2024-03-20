#include <Arduino.h>

int sw1 = 1;
int sw2 = 1;
int sw3 = 1;
int sw4 = 1;

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

  digitalWrite (2, 1);
  digitalWrite (3, 1);
  digitalWrite (4, 1);
  digitalWrite (5, 1);
  digitalWrite (6, 1);
  digitalWrite (7, 1);
  digitalWrite (8, 1);
  digitalWrite (9, 1);
}

void loop() {
  // put your main code here, to run repeatedly:
  sw1 = digitalRead (10);
  sw2 = digitalRead (10);
  sw3 = digitalRead (10);
  sw4 = digitalRead (10);
  if(sw1 == 0)
  {
    digitalWrite (2, 0);
    digitalWrite (3, 0);
  }
  if(sw1 == 1)
  {
    digitalWrite (2, 1);
    digitalWrite (3, 1);
  }

  if(sw2 == 0)
  {
    digitalWrite (4, 0);
    digitalWrite (5, 0);
  }
  if(sw2 == 1)
  {
    digitalWrite (4, 1);
    digitalWrite (5, 1);
  }

  if(sw3 == 0)
  {
    digitalWrite (6, 0);
    digitalWrite (7, 0);
  }
  if(sw3 == 1)
  {
    digitalWrite (6, 1);
    digitalWrite (7, 1);
  }

  if(sw4 == 0)
  {
    digitalWrite (8, 0);
    digitalWrite (9, 0);
  }
  if(sw4 == 1)
  {
    digitalWrite (8, 1);
    digitalWrite (9, 1);
  }
}