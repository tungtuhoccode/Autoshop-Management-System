#include "Mechanic.h"

const char Mechanic::code = 'M';
int Mechanic::nextId = 1;

Mechanic::Mechanic(const string& name): Entity(code, nextId, name) {
    nextId++;
}

void Mechanic::resetId(){
    nextId = 1;
}

void Mechanic::print() const{
    cout << "Mechanic with id: " << id << " and name: " << name << " with " << repairs.size() << " repairs." << endl;
}