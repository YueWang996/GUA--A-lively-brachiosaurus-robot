#ifndef SR04_H
#define SR04_H

#include <Arduino.h>

class SR04 {
    public:
        int trigPin;
        int echoPin;
        
        SR04(int trigPin, int echoPin);
        ~SR04();
    
    public:
        long duration; // variable for the duration of sound wave travel
        int distance; // variable for the distance measurement
        int i;
        float sum;
        float mean;
        float std;
        
        bool resultArray[11] = {0};
        bool resultArrayCp[11] = {0};
        bool internalPersonIsDetected = false;
        bool personIsDetected = false;

        void sr04_setup();
        int get_distance();
        void detectPerson(int data[10]);

        float get_std(int data[]);
        float get_mean(int data[]);

        

};
#endif
