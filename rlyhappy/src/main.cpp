#include <Arduino.h>

/* 
처음에는 led 전부 off
sw1이 off -> on:                                led3 on, led1을 4단게로 점등
sw1이 on유지:                                   led3는 on유지

sw2 on, sw3 off 유지, led3 on:                  led1이 1단계 씩 밝아짐, 1초마다 led2가 1회점멸
sw2 on, sw3 off 유지, led1 최대밝기 도달 시:     led1 유지, led2 1초에 4회 점멸
sw2가 off:                                      led1 유지, led2 off 

sw2 off, sw3 on유지, led3 on:                   led1이 1단계 씩 어두워짐, 1초마다 led2 2회 점멸
sw2 off, sw3 on, led1 최소 밝기 도달:            led1 유지, led2 off

sw1 on, sw2 on, sw3 on:                         led1은 유지, led2 매초 4회씩 점멸

sw1 on -> off:                                  led3 1회 점멸 -> led123 off

sw1 off, sw2 on, sw3 on:                        1초마다 led2 4회 점멸
*/

int sw1 = 1;
int lsw1 = 1;
int sw2 = 1;
int sw3 = 1;
int led1 = 0;
int led2 = 0;
int led3 = 0;
int dangye = 0;


void ggambback()
{
    digitalWrite(4, 0);
    delay(500);
    digitalWrite(4, 1);
    delay(500);
}

void ggambbackk()
{
    digitalWrite(4, 0);
    delay(250);
    digitalWrite(4, 1);
    delay(250);
}

void ggambbackkk()
{
    digitalWrite(5, 0);
    delay(500);
    digitalWrite(5, 1);
    delay(500);
}

void setup() {
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);

    pinMode(7, INPUT);
    pinMode(8, INPUT);
    pinMode(9, INPUT);

    digitalWrite(3, 1);
    digitalWrite(4, 1);
    digitalWrite(5, 1);
}

void loop() {
    sw1 = digitalRead(7);
    sw2 = digitalRead(8);
    sw3 = digitalRead(9);

    if(sw1 != lsw1 && sw1 == 1)
    {
        led3 = 1;
        led1 = 1;
        dangye = 4;
        digitalWrite(5, 0);
        analogWrite(3, 255-(255/8.0) * dangye);
    
        if (sw1 == lsw1 && sw1 == 1 && sw2 == 1)
        {
            dangye++;
            ggambback();
            while (dangye == 8)
            {
                dangye = 8;
                ggambbackk();

                if(sw2 == 0)
                {
                    break;
                }
            }
        }
        else if(led3 == 1 && sw2 == 0 && sw3 == 1)
        {
            if(dangye != 1)
            {
                dangye--;
                ggambback();
                ggambback();
            }
                
        }
        else if(sw1 == 1 && sw2 == 1 && sw3 == 1)
        {
            dangye = 1;
            ggambbackk();
            ggambbackk();
        }
        else if(sw1 != lsw1 && sw3 == 0)
        {
            ggambbackkk();
            led1 = 0;
            led2 = 0;
            led3 = 0;
            digitalWrite(3, 1);
            digitalWrite(4, 1);
            digitalWrite(5, 1);
        }
        else if(sw1 == 0 && sw2 == 1 && sw3 == 1)
        {
            ggambbackk();
            ggambbackk();
        }
        
    }
    
    lsw1 = sw1;
}