#include "Customer.h"

const char Customer::code = 'C';
int Customer::nextId = 1;

Customer::Customer(const string& name, const string& make, const string& model, int year): Entity(code, nextId, name), car(make, model, year) {
    nextId++;
}

void Customer::resetId(){
    nextId = 1;
}

Car Customer::getCar() const{
    return car;
}

void Customer::print() const{
    cout << "Customer: " << id << " " << name << endl;
    cout << "Car: \n";
    car.print();
    cout << endl;
}

void Customer::printRepairs() const{
    print();
    repairs.print();
    cout << endl;
    cout << endl;
}