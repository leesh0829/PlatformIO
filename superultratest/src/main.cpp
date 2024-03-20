#include <Arduino.h>


int fnd_num[10][4] 
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

void display_num(int num) 
{
  int ten = num/10;
  int one = num%10;

  for(int i = 0; i < 10; i++)
  {
    digitalWrite(19, 1);
    digitalWrite(18, 0);
    digitalWrite(14, fnd_num[ten][3]);
    digitalWrite(15, fnd_num[ten][2]);
    digitalWrite(16, fnd_num[ten][1]);
    digitalWrite(17, fnd_num[ten][0]);
    delay(10);

    digitalWrite(18, 1);
    digitalWrite(19, 0);
    digitalWrite(14, fnd_num[one][3]);
    digitalWrite(15, fnd_num[one][2]);
    digitalWrite(16, fnd_num[one][1]);
    digitalWrite(17, fnd_num[one][0]);
    delay(10);
  }
}

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

int count = 0;

int count1 = 0;
int count2 = 99;
int count3 = 1;
int count4 = 98;

void setup() {
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

  Serial.begin(9600);
}

void loop() {
  int readValue = analogRead(A0);
  // Serial.println(readValue);

  int readValue1 = analogRead(A1);
  Serial.println(readValue1);

  int mapVaule = map(readValue, 600, 1023, 0, 255);

  int mapVaulee = map(readValue,  1023, 600, 0, 255);

  int mapVauleee = map(readValue1, 1023, 0, 0, 255);

  int mapVauleeee = map(readValue1, 0, 1023, 0, 255);

  analogWrite(2, mapVaule);
  analogWrite(3, mapVaule);
  analogWrite(4, mapVaulee);
  analogWrite(5, mapVaulee);
  analogWrite(6, mapVauleee);
  analogWrite(7, mapVauleee);
  analogWrite(8, mapVauleeee);
  analogWrite(9, mapVauleeee);

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
    bc1 = 0;
    bc2 = 1;
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

  if(bc1)
  {
    display_num (count);
    count = count1;
    count1 = count1 + 1;
    if(count1 > 99) count1 = 0;
  }

  if(bc2)
  {
    display_num (count);
    count = count2;
    count2 = count2 - 1;
    if(count1 < 0) count2 = 99;
  }

  if(bc3)
  {
    display_num (count);
    count = count3;
    count3 = count3 + 2;
    if(count3 > 99) count3 = 1;
  }

  if(bc4)
  {
    display_num (count);
    count = count4;
    count4 = count4 - 2;
    if(count4 < 0) count4 = 98;
  }

  lbs1 = bs1;
  lbs2 = bs2;
  lbs3 = bs3;
  lbs4 = bs4;
}