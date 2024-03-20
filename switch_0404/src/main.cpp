#include <Arduino.h>

int sw1 = 1;
int sw2 = 1;
int sw3 = 1;
int sw4 = 1;
int i;

void setup() {
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
  sw2 = digitalRead (11);
  sw3 = digitalRead (12);
  sw4 = digitalRead (13);

  if(sw1 == 1)
  {
    digitalWrite (2, 1);
    digitalWrite (3, 1);
    digitalWrite (4, 1);
    digitalWrite (5, 1);
    digitalWrite (6, 1);
    digitalWrite (7, 1);
    digitalWrite (8, 1);
    digitalWrite (9, 1);

    i = 0;
  }
  if(sw1 == 0)
  {
      digitalWrite (i, 0);
      delay(50);
      digitalWrite (i, 1);
      //delay(500);

      i++;

      if (i > 9) i=2;
    
  }

  if(sw2 == 1)
  {
    digitalWrite (2, 1);
    digitalWrite (3, 1);
    digitalWrite (4, 1);
    digitalWrite (5, 1);
    digitalWrite (6, 1);
    digitalWrite (7, 1);
    digitalWrite (8, 1);
    digitalWrite (9, 1);
  }

  if(sw2 == 0)
  {
    for(i=2; i<=9; i++)
    {
      digitalWrite (i, 0);
    }

    delay (50);
    
    for(i=2; i<=9; i++)
    {
      digitalWrite (i, 1);
    }
    delay (50);
  }

    if(sw3 == 1)
  {
    digitalWrite (2, 1);
    digitalWrite (3, 1);
    digitalWrite (4, 1);
    digitalWrite (5, 1);
    digitalWrite (6, 1);
    digitalWrite (7, 1);
    digitalWrite (8, 1);
    digitalWrite (9, 1);
  }

  if(sw3 == 0)
  {
    for(i=2; i<=9; i=i+2)
    {
      digitalWrite (i, 0);
    }
    for(i=3; i<=9; i=i+2)
    {
      digitalWrite (i, 1);
    }
    delay(50);
    for(i=3; i<=9; i=i+2)
    {
      digitalWrite (i, 0);
    }
    for(i=2; i<=9; i=i+2)
    {
      digitalWrite (i, 1);
    }
    delay(50);
  }

  if(sw4 == 1)
  {
    digitalWrite (2, 1);
    digitalWrite (3, 1);
    digitalWrite (4, 1);
    digitalWrite (5, 1);
    digitalWrite (6, 1);
    digitalWrite (7, 1);
    digitalWrite (8, 1);
    digitalWrite (9, 1);
  }

  if(sw4 == 0)
  {
    for(i=9; i>=6; i--)
    {
      digitalWrite (i, 0);
      delay(50);
      digitalWrite (i, 1);
      delay(50);
    }
    for(i=2; i<=5; i++)
    {
      digitalWrite (i, 0);
      delay(50);
      digitalWrite (i, 1);
      delay(50);
    }
  }
}