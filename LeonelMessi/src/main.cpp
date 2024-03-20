#include <Arduino.h>

int a = 2; //포트 번호 a=1번 스위치 
int b = 2;//2번 스위치 포트
int c = 3;//3번 스위치 포트
int d = 9;//4번 스위치 포트
int bs1 = 1;//눌른 1번 버튼 값
int bs2 = 1;//눌른 2번 버튼 값
int bs3 = 1;//눌른 3번 버튼 값
int bs4 = 1;//눌른 4번 버튼 값
int lbs1 = 1;//전에 눌른 1번 버튼 값
int lbs2 = 1;//전에 눌른 2번 버튼 값
int lbs3 = 1;//전에 눌른 3번 버튼 값
int lbs4 = 1;//전에 눌른 4번 버튼 값
int bc1 = 0;//버튼 클릭 값
int bc2 = 0;//버튼 클릭 값
int bc3 = 0;//버튼 클릭 값
int bc4 = 0;//버튼 클릭 값

void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);//2~9번 led포트 설정
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);

  pinMode(10, INPUT);//10~13번 스위치 포트 설정
  pinMode(11, INPUT);
  pinMode(12, INPUT);
  pinMode(13, INPUT);

  digitalWrite (2, 1);//초기 상태에는 모든 led가 꺼지도록 설정
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
  bs1 = digitalRead (10);//스위치의 입력 값을 bs1에 설정
  bs2 = digitalRead (11);//스위치의 입력 값을 bs2에 설정
  bs3 = digitalRead (12);//스위치의 입력 값을 bs3에 설정
  bs4 = digitalRead (13);//스위치의 입력 값을 bs4에 설정

    if(bs1 != lbs1 && bs1 == 1)//스위치를 눌렀다 땟을 시, 버튼 클릭 값을 1로 설정
      bc1 = 1;
    if(bs2 != lbs2 && bs2 == 1)
      bc2 = 1;
    if(bs3 != lbs3 && bs3 == 1)
      bc3 = 1;
    if(bs4 != lbs4 && bs4 == 1)
      bc4 = 1;

 
    if(bc1 == 1) //1번 버튼 눌렀다 땟을 때, led1~8 순차 점멸 반복
    {
      digitalWrite (a, 0);
      delay(50);
      digitalWrite (a, 1);

      a++;

      if(a>9) a = 2;
    }

    if(bc2 == 1)//2번 버튼 눌렀다 땟을 때, led1-3-5-7 순차 점멸 반복
    {
      digitalWrite (b, 0);
      delay(50);
      digitalWrite (b, 1);

      b=b+2;

      if(b>9) b = 2;
    }

    if(bc3 == 1)//3번 버튼 눌렀다 땟을 때, led2-4-6-8 순차 점멸 반복
    {
      digitalWrite (c, 0);
      delay(50);
      digitalWrite (c, 1);

      c=c+2;

      if(c>9) c = 3;
    }

    if(bc4 == 1)//4번 버튼 눌렀다 땟을 때, led 반대로 순차 점멸 반복
    {
      digitalWrite (d, 0);
      delay(50);
      digitalWrite (d, 1);

      d--;

      if(d<2) d = 9;
    }


    if(bs1 == lbs1 && bs1 == 0) //스위치를 누르고 있을 때 led꺼짐
    {
      bc1 = 0;
      bc2 = 0;
      bc3 = 0;
      bc4 = 0;
    }
    if(bs2 == lbs2 && bs2 == 0)
    {
      bc2 = 0;
      bc1 = 0;
      bc3 = 0;
      bc4 = 0;
    }
    if(bs3 == lbs3 && bs3 == 0)
    {
      bc3 = 0;
      bc2 = 0;
      bc1 = 0;
      bc4 = 0;
    }
    if(bs4 == lbs4 && bs4 == 0)
    {
      bc4 = 0;
      bc2 = 0;
      bc3 = 0;
      bc1 = 0;
    }

    lbs1 = bs1;//lsb을 이번 입력한 bs의 값으로 대입하면서 다음 bs입력시, 전의 입력 값으로 됨.
    lbs2 = bs2;
    lbs3 = bs3;
    lbs4 = bs4;
}