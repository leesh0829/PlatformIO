#include <Arduino.h>

int fnd_num[10][4] =
{
  {0, 0, 0, 0},
  {0, 0, 0, 1},
  {0, 0, 1, 0},
  {0, 0, 1, 1},
  {0, 1, 0, 0},
  {0, 1, 0, 1},
  {0, 1, 1, 0},
  {0, 1, 1, 1},
  {1, 0, 0, 0},
  {1, 0, 0, 1}
};

int led[10] = { 0, 25, 50, 75, 100, 125, 150, 175, 200, 255};

void fnd(int num)
{
  for(int i = 0; i < 10; i++)
  {
    digitalWrite(18, 1);

    digitalWrite(14, fnd_num[num][3]);
    digitalWrite(15, fnd_num[num][2]);
    digitalWrite(16, fnd_num[num][1]);
    digitalWrite(17, fnd_num[num][0]);
    delay(100);
  }
}

int lbs1 = 1;
int lbs2 = 1;
int lbs3 = 1;
int bs1 = 1;
int bs2 = 1;
int bs3 = 1;
int count = 0;
int count1 = 0;
int count2 = 9;
int s2 = 0;
int s3 = 0;

void setup() {
  fnd(0);
  for(int i = 2; i <= 3; i++) pinMode(i, OUTPUT);
  for(int i = 4; i <= 6; i++) pinMode(i, INPUT);
  for(int i = 14; i <= 18; i++) pinMode(i, OUTPUT);  
  digitalWrite(2, 1);
  digitalWrite(3, 1);
}

void loop() {
  bs1 = digitalRead(4);
  bs2 = digitalRead(5);
  bs3 = digitalRead(6);

  if(bs1 == lbs1 && bs1 == 0)
  {
    s3 = 0;
    analogWrite(2, led[count]);
    count = count1;
    fnd(count);
    count1++;
    if(count1 > 9)  count1 = 0;
  }

  if(bs2 != lbs2 && bs2 == 1)
  {
    s2 = 1;
    s3 = 0;
  }

  if(bs3 != lbs3 && bs3 == 1)
  {
    s2 = 0;
    s3 = 1;
  }

  if(s2)
  {
    analogWrite(3, led[count]);
    count = count2;
    fnd(count);
    count2--;
    if(count2 < 0)  count2 = 9;
  }

  if(s3)
  {
    digitalWrite(2, 1);
    digitalWrite(3, 1);
    digitalWrite(18, 0);
  }

  lbs1 = bs1;
  lbs2 = bs2;
  lbs3 = bs3;
}