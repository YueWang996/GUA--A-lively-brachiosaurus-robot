#include "sr04.h"

SR04::SR04(int trigPin, int echoPin) {
    this->trigPin = trigPin;
    this->echoPin = echoPin;
};

SR04::~SR04() {
    
};

void SR04::sr04_setup() {
    pinMode(this->trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
    pinMode(this->echoPin, INPUT); // Sets the echoPin as an INPUT
};

int SR04::get_distance() {
    // Clears the trigPin condition
    digitalWrite(this->trigPin, LOW);
    delayMicroseconds(2);
    // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
    digitalWrite(this->trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(this->trigPin, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(this->echoPin, HIGH);
    // Calculating the distance
    distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
    return distance;
};

float SR04::get_mean(int data[10]) {
  sum = 0.0;
  for(i = 0; i < 10; i++) {
    sum += data[i];
  }
  return sum/10.0;
}

float SR04::get_std(int data[10]) {
  mean = get_mean(data);
  sum = 0.0;
  for(i = 0; i < 10; i++) {
    sum += sq(data[i] - mean);
  }

  std = sqrt(sum/10.0);
  return std;
}

void SR04::detectPerson(int data[10]) {
  if(get_std(data) < 10.0) {
    mean = get_mean(data);
    if(mean < 60.0) {
      internalPersonIsDetected = true;
    }
    if(mean >= 60.0) {
      internalPersonIsDetected = false;
    }
  }

  sum = 0;
  for(int i = 1; i < 11; i++) {
    resultArray[i-1] = resultArrayCp[i];
    resultArrayCp[i-1] = resultArray[i-1];
    sum += resultArray[i-1];
  }
  resultArray[10] = internalPersonIsDetected;
  resultArrayCp[10] = resultArray[10];
  sum += resultArray[10];
  sum /= 11;

  if(sum < 0.3) {
    personIsDetected = false;
  }
  if(sum > 0.7) {
    personIsDetected = true;
  }
}
