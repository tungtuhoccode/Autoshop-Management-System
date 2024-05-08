#include "Car.h"

Car::Car(string make, string model, int year){
    this->make = make;
    this->model = model;
    this->year = year;
}

void Car::print() const{
    cout << make << " " << model << " (" << year << ")" << endl;
}


