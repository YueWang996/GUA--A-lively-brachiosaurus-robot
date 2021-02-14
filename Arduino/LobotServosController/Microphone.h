#ifndef MICROPHONE_H
#define MICROPHONE_H

#include <Arduino.h>

class Microphone
{
public:
    int pin;
    Microphone(int MicrophonePin);
    ~Microphone();

    bool isScreaming();

};

Microphone::Microphone(int MicrophonePin)
{
    pin = MicrophonePin;
    pinMode(pin, INPUT);
}

Microphone::~Microphone()
{
}

bool Microphone::isScreaming() {
  Serial.println(analogRead(pin));
    if(analogRead(pin) > 70) {
        return true;
    } else {
        return false;
    }
}

#endif
