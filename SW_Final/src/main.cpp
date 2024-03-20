#include <Arduino.h>

int a = 2;
int b = 6;
int c = 5;
int d = 9;
int bs1 = 1;
int bs2 = 1;
int bs3 = 1;
int bs4 = 1;
int lbs1 = 1;
int lbs2 = 1;
int lbs3 = 1;
int lbs4 = 1;
int bc1 = 0;
int bc2 = 0;
int bc3 = 0;
int bc4 = 0;

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
  bs1 = digitalRead (10);
  bs2 = digitalRead (11);
  bs3 = digitalRead (12);
  bs4 = digitalRead (13);

    if(bs1 == lbs1 && bs1 == 0) {
      bc1 = 1;
      bc2 = 0;
      bc3 = 0;
      bc4 = 0;
    }
    if(bs2 == lbs2 && bs2 == 0) {
      bc2 = 1;
      bc1 = 0;
      bc3 = 0;
      bc4 = 0;
    }
    if(bs3 != lbs3 && bs3 == 1) {
      bc3 = 1;
      bc1 = 0;
      bc2 = 0;
      bc4 = 0;
    }
    if(bs4 != lbs4 && bs4 == 1) {
      bc4 = 1;
      bc1 = 0;
      bc2 = 0;
      bc3 = 0;
    }

 
    if(bc1 == 1)
    {
      digitalWrite (a, 0);
      delay(500);
      digitalWrite (a, 1);

      a++;

      if(a>5) a = 2;
    }

    if(bc2 == 1)
    {
      digitalWrite (b, 0);
      delay(500);
      digitalWrite (b, 1);

      b++;

      if(b>9) b = 6;
    }

    if(bc3 == 1)
    {
      digitalWrite (c, 0);
      delay(500);
      digitalWrite (c, 1);

      c--;

      if(c<1) c = 5;
    }

    if(bc4 == 1)
    {
      digitalWrite (d, 0);
      delay(500);
      digitalWrite (d, 1);

      d--;

      if(d<6) d = 9;
    }

    if(bs1 != lbs1 && bs1 == 1)
      bc1 = 0;
    if(bs2 != lbs2 && bs2 == 1)
      bc2 = 0;

    lbs1 = bs1;
    lbs2 = bs2;
    lbs3 = bs3;
    lbs4 = bs4;
}