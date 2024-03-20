#include <Arduino.h>

int fnd_num [10][4] = {
  {0,0,0,0}, {0,0,0,1}, {0,0,1,0}, {0,0,1,1}, {0,1,0,0}, {0,1,0,1}, {0,1,1,0}, {0,1,1,1}, {1,0,0,0}, {1,0,0,1}
};

int count = 0;
int count1 = 0;
int count2 = 9;
int count3 = 1;
int count4 = 8;
int bs1 = 1;
int bs2 = 1;
int bs3 = 1;
int bs4 = 1;
int lbs1 = 1;
int lbs2 = 1;
int lbs3 = 1;
int lbs4 = 1;
int a = 2;
int b = 9;
int c = 3;
int d = 8;

void display_num(int num)
{
  int ten = num/10;
  int one = num%10;

  for(int i = 0; i < 50; i++){
    digitalWrite(18, 0);
    digitalWrite(19, 1);

    digitalWrite(14, fnd_num[ten] [3]);
    digitalWrite(15, fnd_num[ten] [2]);
    digitalWrite(16, fnd_num[ten] [1]);
    digitalWrite(17, fnd_num[ten] [0]);
    delay(10);

    digitalWrite(18, 1);
    digitalWrite(19, 0);

    digitalWrite(14, fnd_num[one] [3]);
    digitalWrite(15, fnd_num[one] [2]);
    digitalWrite(16, fnd_num[one] [1]);
    digitalWrite(17, fnd_num[one] [0]);
    delay(10);
  }
}

void setup() {
  //아 제발 for문 써;;
  digitalWrite(2, 1);
  digitalWrite(3, 1);
  digitalWrite(4, 1);
  digitalWrite(5, 1);
  digitalWrite(6, 1);
  digitalWrite(7, 1);
  digitalWrite(8, 1);
  digitalWrite(9, 1);

  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);


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
}

void loop() {
  bs1 = digitalRead(10);
  bs2 = digitalRead(11);
  bs3 = digitalRead(12);
  bs4 = digitalRead(13);

  if(bs1 == lbs1 && bs1 == 0)
  {
     digitalWrite(a, 0);
    delay(50);
    digitalWrite(a, 1);
    a++;
    if(a > 9) a = 2;

     display_num(count);
     count1++;
     count = count1;

     if(count1 > 9)  count1 = 0;
  }

  if(bs2 == lbs2 && bs2 == 0)
  {
    digitalWrite(b, 0);
    delay(50);
    digitalWrite(b, 1);
    b--;
    if(b < 2) a = 9;

     display_num(count);
     count2--;
     count = count2;

     if(count2 < 0)  count2 = 9;
  }

  if(bs3 == lbs3 && bs3 == 0)
  {
    digitalWrite(c, 0);
    delay(50);
    digitalWrite(c, 1);
    c = c+2;
    if(c > 9) c = 3;

     display_num(count);
     count3 = count3 + 2;
     count = count3;

     if(count3 > 9)  count3 = 1;
  }

  if(bs4 == lbs4 && bs4 == 0)
  {
    digitalWrite(d, 0);
    delay(50);
    digitalWrite(d, 1);
    d= d-2;
    if(d < 1) d = 8;

     display_num(count);
     count4 = count4 - 2;
     count = count4;

     if(count4 < 0)  count4 = 8;
  }

  lbs1 = bs1;
  lbs2 = bs2;
  lbs3 = bs3;
  lbs4 = bs4;
}