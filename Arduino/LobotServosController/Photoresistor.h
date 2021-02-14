#ifndef PHOTORESISTOR_H
#define PHOTORESISTOR_H

#include <Arduino.h>

class Photoresistor
{
public:
    Photoresistor(int PhotoresistorPin);
    ~Photoresistor();

    int val;
    int pin;
    float sum = 0;
    bool internal_is_dark;
    bool resultArray[11];
    bool resultArrayCp[11];

    bool isDark();
};

Photoresistor::Photoresistor(int PhotoresistorPin)
{
    pin = PhotoresistorPin;
    pinMode(PhotoresistorPin, INPUT);
}

Photoresistor::~Photoresistor()
{
}

bool Photoresistor::isDark() {
  val = analogRead(pin);
  if (val < 400) {
      internal_is_dark = true;
  } else {
      internal_is_dark = false;
  }

  sum = 0;
  for(int i = 1; i < 11; i++) {
    resultArray[i-1] = resultArrayCp[i];
    resultArrayCp[i-1] = resultArray[i-1];
    sum += resultArray[i-1];
  }
  resultArray[10] = internal_is_dark;
  resultArrayCp[10] = resultArray[10];
  sum += resultArray[10];
  sum /= 11;

  if(sum < 0.3) {
    return false;
  }
  if(sum > 0.7) {
    return true;
  }
}


#endif
