#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <string>

using namespace std;

class Car{
    public: 
        Car(string make, string model, int year);
        void print() const;
    private: 
        string make; 
        string model; 
        int year;        
};

#endif