#include <Arduino.h>

int fnd_num[10][4]  //fnd 출력 숫자
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

int led[10] = { 0, 0, 0, 50, 0, 100, 0, 150, 0, 255 }; //led 밝기 0~9숫자에 따라 밝기 조정, 짝수는 없으니 0으로 1도 100%이니 0로

void display_num(int num) //fnd 1 didigt 출력 함수
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

void setup() {
  pinMode(3, OUTPUT); //led
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);

  pinMode(7, INPUT); //sw
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(10, INPUT);

  pinMode(14, OUTPUT);  //fnd
  pinMode(15, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(17, OUTPUT);
  pinMode(18, OUTPUT);

  Serial.begin(9600);

  display_num(0); //초기에는 fnd 0출력

  digitalWrite(3, 1); //초기에는 led off 상태
  digitalWrite(4, 1);
  digitalWrite(5, 1);
  digitalWrite(6, 1);
}

int bs1 = 1;
int bs2 = 1;
int bs3 = 1;  //버튼 현재 상태
int bs4 = 1;

int lbs1 = 1;
int lbs2 = 1; //버튼 다음 상태
int lbs3 = 1;
int lbs4 = 1;

int count = 0;  //카운트 현재 상태
int count1 = 1;
int count2 = 9; //카운트 각 상태
int count3 = 1;
int count4 = 9;

int uc = 0; //업카운트 플래그 (눌렀다 떄는 3번 sw)
int dc = 0; //다운카운트 플래그 (눌렀다 때는 4번 sw)

void loop()
{
  bs1 = digitalRead(7); //sw 현재상태 입력
  bs2 = digitalRead(8);
  bs3 = digitalRead(9);
  bs4 = digitalRead(10);

  while(bs1 == lbs1 && bs1 == 0)  //1번 스위치 누르고 있을 때
  {
    bs1 = digitalRead(7); //1번 스위치 입력(while문에서는 바깥의 코드는 입력이 안되기 때문에 while안에 넣어서 상태를 입력받아야함)
    display_num(count); //fnd 출력
    count = count1 + 2; //2씩 추가
    analogWrite(3, led[count1]);  //led에 배열 만큼 밝기 
    if(count1 > 9)  count1 = 1; //9 이상으로 넘어갈 시, 다시 1부터 반복
    if(bs1 == 1) //현재 상태가 누르지 않고 있을 때
    {
      digitalWrite(3, 1); //led off
      break;  //break로 빠져나오기
    }
    lbs1 = bs1;
  }

  while(bs2 == lbs2 && bs2 == 0)
  {
    bs2 = digitalRead(8);
    display_num(count);
    count = count2 - 2;
    analogWrite(4, led[count2]);
    if(count2 < 1)  count2 = 9;
    if(bs2 == 1)
    {
      digitalWrite(4, 1);
      break;
    }
    lbs2 = bs2;
  }

  if(bs3 != lbs3 && bs3 == 1) //3번 스위치 눌렀다 땟을 때
  {
    uc = 1; //업카운트 플래그
    dc = 0;
  }

  if(bs4 != lbs4 && bs4 == 1)
  {
    uc = 0;
    dc = 1; //다운카운트 플래그
  }

  while(uc == 1)  //업카운트 플래그가 실행될 때
  {
    bs3 = digitalRead(9); //3번 스위치 입력(while문에서는 바깥의 코드는 입력이 안되기 때문에 while안에 넣어서 상태를 입력받아야함)
    display_num(count); //fnd 출력
    count = count3 + 2; //2씩 증가
    analogWrite(5, led[count3]);  //led 출력 숫자에 따라 밝기
    if(count3 > 9)  count3 = 1; //9보다 높을 시 다시1부터 반복
    if(bs3 != lbs3 && bs3 == 1) //다시 눌렀다 땟을 시 
    {
      digitalWrite(5, 1); //led 끄고
      uc = 0; //플래그를 빼서 끄기
    }
    lbs3 = bs3;
  }

  while(dc == 1)
  {
    bs4 = digitalRead(10);
    display_num(count);
    count = count4 - 2;
    analogWrite(6, led[count4]);
    if(count4 < 1)  count4 = 9;
    if(bs4 != lbs4 && bs4 == 1)
    {
      digitalWrite(6, 1);
      dc = 0;
    }
    lbs4 = bs4;
  }


  lbs1 = bs1;
  lbs2 = bs2;
  lbs3 = bs3;
  lbs4 = bs4;
}