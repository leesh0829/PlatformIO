#include <Arduino.h>

// int sw1 = 0;
// int sw2 = 0;
// int sw3 = 0;
// int sw4 = 0;
int a = 2;
// int b = 2;
// int c = 2;
// int d = 9;
int bs1 = 0;
int bs2 = 0;
int bs3 = 0;
int bs4 = 0;
int lbs1 = 0;
int lbs2 = 0;
int lbs3 = 0;
int lbs4 = 0;
int bc1 = 0;
int bc4 = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);

  pinMode(10, INPUT);
  pinMode(11, INPUT);
  pinMode(12, INPUT);
  pinMode(13, INPUT);

  digitalWrite (2, 0);
  digitalWrite (3, 0);
  digitalWrite (4, 0);
  digitalWrite (5, 0);
  digitalWrite (6, 0);
  digitalWrite (7, 0);
  digitalWrite (8, 0);
  digitalWrite (9, 0);
}

void loop() {
  // put your main code here, to run repeatedly:
  bs1 = digitalRead (10);
  bs2 = digitalRead (11);
  bs3 = digitalRead (12);
  bs4 = digitalRead (13);


  // if(sw1 == 0)
  // {
  //   digitalWrite (2, 0);
  //   digitalWrite (3, 0);
  //   digitalWrite (4, 0);
  //   digitalWrite (5, 0);
  //   digitalWrite (6, 0);
  //   digitalWrite (7, 0);
  //   digitalWrite (8, 0);
  //   digitalWrite (9, 0);
  // }

  // if(sw2 == 0)
  // {
  //   digitalWrite (2, 0);
  //   digitalWrite (3, 0);
  //   digitalWrite (4, 0);
  //   digitalWrite (5, 0);
  //   digitalWrite (6, 0);
  //   digitalWrite (7, 0);
  //   digitalWrite (8, 0);
  //   digitalWrite (9, 0);
  // }

  // if(sw3 == 0)
  // {
  //   digitalWrite (2, 0);
  //   digitalWrite (3, 0);
  //   digitalWrite (4, 0);
  //   digitalWrite (5, 0);
  //   digitalWrite (6, 0);
  //   digitalWrite (7, 0);
  //   digitalWrite (8, 0);
  //   digitalWrite (9, 0);
  // }

  // if(sw4 == 0)
  // {
  //   digitalWrite (2, 0);
  //   digitalWrite (3, 0);
  //   digitalWrite (4, 0);
  //   digitalWrite (5, 0);
  //   digitalWrite (6, 0);
  //   digitalWrite (7, 0);
  //   digitalWrite (8, 0);
  //   digitalWrite (9, 0);
  // }

  // if(sw1 == 1)
  // {
  //     digitalWrite (a, 1);
  //     delay(50);
  //     digitalWrite (a, 0);
  //     //delay(500);

  //     a++;

  //     if (a > 9) a=2;
  // }

  // if(sw2 == 1)
  // {
  //     digitalWrite (b, 1);
  //     delay(50);
  //     digitalWrite (b, 0);
  //     //delay(500);

  //     b=b+2;

  //     if (b > 9) b=2;
  // }

  // if(sw3 == 1)
  // {
  //     digitalWrite (c, 1);
  //     delay(50);
  //     digitalWrite (c, 0);
  //     //delay(500);

  //     c=c+2;

  //     if (c > 9) c=3;
  // }

  // if(sw4 == 1)
  // {
  //     digitalWrite (d, 1);
  //     delay(50);
  //     digitalWrite (d, 0);
  //     //delay(500);

  //     d--;

  //     if (d < 2) d=9;
  // }

    if(bs4 != lbs4 && bs4 == 0)
      bc4 = 1;

    if(bc4 == 1) {
      digitalWrite (a, 1);
      delay(50);
      digitalWrite (a, 0);
      a++;
      if(a > 9) a = 2;
    }


    if(bs4 == lbs4 && bs4 == 1)
      bc1 = 0;
      
    lbs1 = bs1;
    lbs2 = bs2;
    lbs3 = bs3;
    lbs4 = bs4;
}