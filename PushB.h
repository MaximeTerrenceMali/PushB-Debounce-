#ifndef PushB_H
#define PushB_H

#include<Arduino.h>

class PushB{

private:
int pin;

public:
LED(){}       // default construtor
LED(int pin); //the constructor

void init();  //to initialize the pin as output
void on();    //to turn the LED on
void off();   //to turn the LED off

};

#endif
