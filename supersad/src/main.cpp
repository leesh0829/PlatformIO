#include <Arduino.h>

/*
가변저항이 50% 이하
	1.led2가 꺼지고 sw1 눌렀다 땟으면: 홀수 다운 카운트(9~1) led1 on -> 다시 한번 누르면 fnd 멈추고 led1 off
	2.led1가 꺼지고 sw2 눌렀다 때면: 짝수 다운 카운트(8~0) led2 on -> 다시 한번 누르면 fnd 멈추고 led2 off
가변저항이 50% 이상
	1.led2가 꺼지고 sw1 눌렀다 때면: 홀수 업 카운트(1~9) led1 on -> 다시 한번 누르면 fnd 멈추고 led1 off
	2.led1가 꺼지고 sw2 눌렀다 때면: 짝수 업 카운트(0~8) led2 on -> 다시 한번 누르면 fnd 멈추고 led2 off
어떤 동작중에서도 sw3 눌렀다 때면 fnd 0, 모든 led off (초기화) */

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

int count1 = 9;
int count2 = 8;
int count3 = 1;
int count4 = 0;
int bs1 = 1;
int bs2 = 1;
int bs3 = 1;
int lbs1 = 1;
int lbs2 = 1;
int lbs3 = 1;

void setup() {
}

void loop() {
}