#include <Arduino.h>

int fnd_num [10][4] = {
  {0,0,0,0}, {0,0,0,1}, {0,0,1,0}, {0,0,1,1}, {0,1,0,0}, {0,1,0,1}, {0,1,1,0}, {0,1,1,1}, {1,0,0,0}, {1,0,0,1}
};

int led_b[10] = {225,200,175,150,125,100,75,50,25,0};

int count = 00;
int bs1 = 1;
int bs2 = 1;
int lbs1 = 1;
int lbs2 = 1;
int led2 = 0;
int up = 0;
int down = 0;

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
    delay(5);

    digitalWrite(18, 1);
    digitalWrite(19, 0);

    digitalWrite(14, fnd_num[one] [3]);
    digitalWrite(15, fnd_num[one] [2]);
    digitalWrite(16, fnd_num[one] [1]);
    digitalWrite(17, fnd_num[one] [0]);
    delay(5);
  }
}

void blink(){
  digitalWrite(18,1);
  digitalWrite(19,1);
  delay(100);
  display_num(count);
}

void setup() {
  digitalWrite(2, 1);
  digitalWrite(3, 1);

  pinMode(3, OUTPUT);
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
}

void loop() {
  bs1 = digitalRead(10);
  bs2 = digitalRead(11);

  if(up){                       //업카운트                        
    display_num(count);
    count++;
    if(count > 99) count = 0;
  }

  if(down){                     //다운카운트                        
    display_num(count);
    count--;
    if(count<0) count = 99;
  }

  if((up==0 && down==0) && (bs1 != lbs1 && bs1 == 0)) //버튼1을 누르면 led꺼지고(초기화상태)업카운트
  {                 
    digitalWrite(2,1);                                                 
    digitalWrite(3,1);                                                 
    up = 1;
    down = 0;
  }

  else if(up==1 && (bs1 != lbs1 && bs1 == 0)){        //버튼1이 눌린상태에서(up=1) 버튼1을 한번 더 누르면 1번 led가 켜지고 fnd가 두번 깜빡거리고 다운카운트                 
    digitalWrite(2,0);
    blink();
    blink();                                                            
    up = 0;
    down = 1;
  }

  else if(down==1 && (bs1 != lbs1 && bs1 == 0)){      //버튼1을 두번 누른상태에서(두번 누른상태는 down카운트가 작동되기 때문에 down=1) 버튼1을 한번 더 누르면 led1번이 다시 꺼지고 두번 깜빡거리고 업카운트                  
    digitalWrite(2,1);
    blink();
    blink();                                                            
    up = 1;
    down = 0;
  }

  if((up == 1 || down == 1) && (bs2 != lbs2 && bs2 == 0)){  //다운카운트나 업카운트가 작동중일때(\\는 or) 버튼2번을 눌르면 led2번을 킨다.           
    up = 0;
    down = 0;                                                           
    led2 = 1;
  }

  else if(led2 == 1 && (up==0 && down==0) && (bs2 != lbs2 && bs2 == 0)){    //led2번이 켜져있을 때 00이 깜빡거릴때(업 카운트 다운카운트 둘다 작동하지 않을 때) 버튼 2번 누르면 초기화
    led2 = 0;
    count = 0;
  }             


  if(up==0 && down==0)  blink();    //00을 깜빡거리기

  lbs1 = bs1;
  lbs2 = bs2;
}