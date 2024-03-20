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

int firstt = 1; //첫 상태 실행 플래그 변수

int led[10] = { 225,200,175,150,125,100,75,50,25,0 }; //led1 밝기 값 함수

void Display_ten(int num){ //fnd 1 display
  digitalWrite(19,0);
  digitalWrite(18,1);
  digitalWrite(14,fnd_num[num][3]);
  digitalWrite(15,fnd_num[num][2]);
  digitalWrite(16,fnd_num[num][1]);
  digitalWrite(17,fnd_num[num][0]);
}

void Display_one(int num){ ////fnd 2 display
  digitalWrite(18,0);
  digitalWrite(19,1);
  digitalWrite(14,fnd_num[num][3]);
  digitalWrite(15,fnd_num[num][2]);
  digitalWrite(16,fnd_num[num][1]);
  digitalWrite(17,fnd_num[num][0]);
}

void Display(int num, int sec){ // sec 500*2=1000millisecond, 1500*2=3000millisecond
  int one = num%10;
  int ten = num/10;
  for(int i = 0; i<sec; i++){
    Display_ten(ten);
    delay(1);
    Display_one(one);
    delay(1);
  }
}

void first() {            //첫 실행 때 상태 함수(플래그)
  digitalWrite(2, 1); //led 끄기
  digitalWrite(7, 1); 

  Display(88, 750); //fnd 88출력

  delay(2000);  

  digitalWrite(18, 1);  //fnd 꺼짐
  digitalWrite(19, 1);

  delay(1000);
}

void setup() {
  pinMode(2, OUTPUT); //output 설정
  pinMode(7, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(17, OUTPUT);
  pinMode(18, OUTPUT);
  pinMode(19, OUTPUT);

  Serial.begin(9600);
}

void ggambak() {  //led2 깜빡거리는 함수
  digitalWrite(7, 0); 
  delay(1000);
  digitalWrite(7, 1);
}

void loop() {

  if(firstt == 1)   //처음 때 firstt는 1을 주고 한번 함수를 실행하고 다시 firstt를 0을줘, 최초실행 한번만 작동하게 만드는 코드
  {
    first();
    firstt = 0;
  }

  int readValue = analogRead(A2); //A2에 있는 조도 센서 값을 정수로 입력
  Serial.println(readValue);  //조도 센서 값 출력

  int mapVaule1 = map(readValue, 0, 999, 0, 99);  //조도 센서의 값 0~999 입력받은 아날로그 값을 0~99 출력하는 디지털 값으로 바꾸기 (map 함수)

  Display(mapVaule1, 500);  //fnd 조도센서 값 출력
  analogWrite(2, led[mapVaule1/10]);  //조도 센서 값의 10나눈 값의 led함수를 led1에 출력

  if(mapVaule1 < 39)  //조도 센서 값이 39이하일 시, led2 깜빡거리게 하는 함수
  {
    ggambak();
  }
}