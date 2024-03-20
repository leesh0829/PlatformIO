#include <Arduino.h>

int fnd_num [10][4] = {
  {0,0,0,0}, {0,0,0,1}, {0,0,1,0}, {0,0,1,1}, {0,1,0,0}, {0,1,0,1}, {0,1,1,0}, {0,1,1,1}, {1,0,0,0}, {1,0,0,1}
};

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
int a = 2;
int b = 9;
int c = 3;
int d = 8;
int a1 = 0;
int b1 = 9;
int c1 = 1;
int d1 = 8;

void display_num(int num)
{
  for(int i = 0; i < 50; i++){
    digitalWrite(18, 1);
    digitalWrite(19, 1);

    digitalWrite(14, fnd_num[num] [3]);
    digitalWrite(15, fnd_num[num] [2]);
    digitalWrite(16, fnd_num[num] [1]);
    digitalWrite(17, fnd_num[num] [0]);
    delay(10);
  }
}

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
  bs1 = digitalRead(10);
  bs2 = digitalRead(11);
  bs3 = digitalRead(12);
  bs4 = digitalRead(13);

  if(bs1 != lbs1 && bs1 == 1)
  {
    bc1 = 1;
    bc2 = 0;
    bc3 = 0;
    bc4 = 0;
  }

  if(bs2 != lbs2 && bs2 == 1)
  {
    bc2 = 1;
    bc1 = 0;
    bc3 = 0;
    bc4 = 0;
  }
  if(bs3 != lbs3 && bs3 == 1)
  {
    bc1 = 0;
    bc2 = 0;
    bc3 = 1;
    bc4 = 0;
  }

  if(bs4 != lbs4 && bs4 == 1)
  {
    bc1 = 0;
    bc2 = 0;
    bc3 = 0;
    bc4 = 1;
  }
  
  if(bc1 == 1)
    {
      digitalWrite(a, 0);
      delay(500);
      digitalWrite(a, 1);

      a++;

      if(a>9) a=2;

      display_num(a1);

      a1++;

      if(a1>9) a1 = 0;
    }
      if(bc2 == 1)
    {
      digitalWrite(b, 0);
      delay(500);
      digitalWrite(b, 1);

      b--;

      if(b<2) b=9;

      display_num(b1);

      b1--;

      if(b1<0) b1 = 9;
    }

      if(bc3 == 1)
    {
      digitalWrite(c, 0);
      delay(500);
      digitalWrite(c, 1);

      c= c+2;

      if(c>9) c=3;

      display_num(c1);

      c1= c1 + 2;

      if(c1>9) c1 = 1;
    }

      if(bc4 == 1)
    {
      digitalWrite(d, 0);
      delay(500);
      digitalWrite(d, 1);

      d = d-2;

      if(d<0) d=8;

      display_num(d1);

      d1 = d1 - 2;

      if(d1<0) d1 = 8;
    }

  lbs1 = bs1;
  lbs2 = bs2;
  lbs3 = bs3;
  lbs4 = bs4;
}