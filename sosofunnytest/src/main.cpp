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
    delay(200);

    digitalWrite(18, 1);
    digitalWrite(19, 0);
    digitalWrite(14, fnd_num[one][3]);
    digitalWrite(15, fnd_num[one][2]);
    digitalWrite(16, fnd_num[one][1]);
    digitalWrite(17, fnd_num[one][0]);
    delay(200);
  }
}



void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);

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
  Serial.println(readValue);

  int mapVaule = map(readValue, 0, 999 , 0, 255);

  if(0 < readValue && readValue < 10)
    display_num (readValue%10);
    
  if(11 < readValue && readValue < 20)
    display_num (readValue%10);
  
  if(21 < readValue && readValue < 30)
    display_num (readValue%10);
  
  if(31 < readValue && readValue < 40)
    display_num (readValue%10);

  if(41 < readValue && readValue < 50)
    display_num (readValue%10);

  if(51 < readValue && readValue < 60)
    display_num (readValue%10);

  if(61 < readValue && readValue < 70)
    display_num (readValue%10);

  if(71 < readValue && readValue < 80)
    display_num (readValue%10);

  if(81 < readValue && readValue < 90)
    display_num (readValue%10); 

  if(91 < readValue && readValue < 100)
    display_num (readValue%10);

  analogWrite(2, mapVaule);

  if( 390 > readValue )
  {
    digitalWrite(3 ,1);
    delay(100);
    digitalWrite(3, 0);
    delay(100);
  }
  else 
    digitalWrite(3, 1);
}
