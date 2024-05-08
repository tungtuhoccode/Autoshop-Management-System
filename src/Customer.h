#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Entity.h"
#include "Car.h"

using namespace std; 


class Customer: public Entity{
    public:     
        //member functions
        Customer(const string& name, const string& make, const string& model, int year);
        Car getCar() const;
        void print() const;
        void printRepairs() const;

        //class functions
        static void resetId();
    private:
        //static (class) member
        static const char code; 
        static int nextId;
        //member variables
        Car car;

};
#endif 