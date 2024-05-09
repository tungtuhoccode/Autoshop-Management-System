#include "../include/Entity.h"

Entity::Entity(char code, int num, const string& name): name(name), id(code + to_string(num)){
}

bool Entity::hasRepairs() const{
    return !repairs.isEmpty();
}

void Entity::addRepair(Repair* repair){
    repairs.add(repair);
}

Repair* Entity::getNextRepair(){
    return repairs.getNext();
}

string Entity::getId() const{
    return id;
}

void Entity::print() const{
    cout << "Entity: " << id << " " << name << " with " << repairs.size() << " repairs.\n" << endl;
}

void Entity::printRepairs() const{
    print();
    repairs.print();
    cout << endl;
}