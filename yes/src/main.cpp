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

int led_value[10][4]
{
  {0, int(1*255)},
  {1, int(0.9*255)},
  {2, int(0.8* 255)},
  {3, int(0.7*255)},
  {4, int(0.6*255)},
  {5, int(0.5*255)},
  {6, int(0.4*255)},
  {7, int(0.3*255)},
  {8, int(0.2*255)},
  {9, int(0.1*255)}
};

void display_num(int num) 
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

int lbs1 = 1;
int lbs2 = 1;
int lbs3 = 1;

int count = 0;

int count1 = 0;
int count2 = 9;
int count3 = 0;

void setup() {
  pinMode(2, OUTPUT);

  pinMode(10, INPUT);
  pinMode(11, INPUT);
  pinMode(12, INPUT);

  pinMode(14, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(17, OUTPUT);
  pinMode(18, OUTPUT);
  pinMode(19, OUTPUT);

  Serial.begin(9600);

  display_num(0); 

  digitalWrite(2, 1);
}

void loop() {

  bs1 = digitalRead(10);
  bs2 = digitalRead(11);
  bs3 = digitalRead(12);

  if(bs1 == lbs1 && bs1 == 0)
  {
    display_num (count);
    count = count1;
    count1++;
    if(count1 > 9)  count1 = 0;
  }

  if(bs2 == lbs2 && bs2 == 0)
  {
    display_num (count);
    count = count2;
    count2--;
    if(count2 < 0) count2 = 9;
  }

  if(count == 9)
  {
    if(bs1 == lbs1 && bs1 == 0)
    {
      digitalWrite(18, 0);
      delay(500);
      digitalWrite(18, 1);
      delay(500);
    }
  }

  if(count == 0)
  {
    if(bs2 == lbs2 && bs2 == 0)
    {
      digitalWrite(18, 0);
      delay(500);
      digitalWrite(18, 1);
      delay(500);
    }
  }

  if(bs3 == lbs3 && bs3 == 0)
  {
      display_num(led_value[count3][0]);
      analogWrite(2, led_value[count3][1]);
      count3++;
      delay(1000);
      if(count3 > 9) count3 = 0;
  }

  lbs1 = bs1;
  lbs2 = bs2;
  lbs3 = bs3;
}