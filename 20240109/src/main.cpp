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

int bs1 = 1;
int bs2 = 1;
int bs3 = 1;
int bs4 = 1;

int lbs1 = 1;
int lbs2 = 1;
int lbs3 = 1;
int lbs4 = 1;

int count;
int count1 = 9;
int count2 = 8;
int count3 = 1;
int count4 = 0;

int s1 = 0;
int s2 = 0;
int s3 = 0;
int s4 = 0;

void setup() {
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, INPUT);
    pinMode(5, INPUT);
    pinMode(6, INPUT);
    pinMode(14, OUTPUT);
    pinMode(15, OUTPUT);
    pinMode(16, OUTPUT);
    pinMode(17, OUTPUT);
    pinMode(18, OUTPUT);

    digitalWrite(2, 1);
    digitalWrite(3, 1);
    fnd(0);

    Serial.begin(9600);
}

void loop() {
    int readValue = analogRead(A0);
    int mapVaule = map(readValue, 0, 1023, 0, 100);
    Serial.println(mapVaule);

    bs1 = digitalRead(4);
    bs2 = digitalRead(5);
    bs3 = digitalRead(6);

    if(mapVaule <= 50)
    {
        if(bs1 != lbs1 && bs1 == 1)
        {
            s1 = 1 - s1;
            s2 = 0;
            s3 = 0;
            s4 = 0;

            if(s1 == 0) digitalWrite(2, 1);
        }
        if(bs2 != lbs2 && bs2 == 1)
        {
            s1 = 0;
            s2 = 1 - s2;
            s3 = 0;
            s4 = 0;

            if(s2 == 0) digitalWrite(3, 1);
        }
    }

    if(mapVaule > 50)
    {
        if(bs1 != lbs1 && bs1 == 1)
        {
            s1 = 0;
            s2 = 0;
            s3 = 1 - s3;
            s4 = 0;

            if(s3 == 0) digitalWrite(2, 1);
        }
        if(bs2 != lbs2 && bs2 == 1)
        {
            s1 = 0;
            s2 = 0;
            s3 = 0;
            s4 = 1 - s4;

            if(s4 == 0) digitalWrite(3, 1);
        }
    }

    if(bs3 != lbs3 && bs3 == 1)
    {
        s1 = 0;
        s2 = 0;
        s3 = 0;
        s4 = 0;
        fnd(0);
        digitalWrite(2, 1);
        digitalWrite(3, 1);
    }

    if(s1 == 1)
    {
        digitalWrite(2, 0);
        count = count1;
        fnd(count);
        count1 = count1 - 2;
        if(count1 < 1)  count1 = 9;
    }

    if(s2 == 1)
    {
        digitalWrite(3, 0);
        count = count2;
        fnd(count);
        count2 = count2 - 2;
        if(count2 < 0)  count2 = 8;
    }


    if(s3 == 1)
    {
        digitalWrite(2, 0);
        count = count3;
        fnd(count);
        count3 = count3 + 2;
        if(count3 > 9)  count3 = 1;
    }

    if(s4 == 1)
    {
        digitalWrite(3, 0);
        count = count4;
        fnd(count);
        count4 = count4 + 2;
        if(count4 > 8)  count2 = 0;
    }

    lbs1 = bs1;
    lbs2 = bs2;
    lbs3 = bs3;
}