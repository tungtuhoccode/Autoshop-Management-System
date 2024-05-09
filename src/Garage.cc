
#include "../include/Garage.h"


const string Garage::REPAIRS[NUM_REPAIRS] = {"Oil Change", "Brake Check", "Tire Rotation", "Battery Check", "Air Filter Replacement", "Coolant Flush", "Transmission Flush", "A/C Recharge", "Engine Diagnostic", "Brake Pad Replacement"};

Garage::Garage(){
    // no initilization needed. vector are on stack already
}

Garage::~Garage(){
    for (Customer* c: customers){
        delete c;
    }
    for (Mechanic* m: mechanics){
        delete m;
    }
}

void Garage::addMechanic(const string& name){
    Mechanic* m = new Mechanic(name);
    mechanics.push_back(m);
}

void Garage::addCustomer(const string& name, const string& make, const string& model, int year){
    Customer* c = new Customer(name, make, model, year);
    customers.push_back(c);
}

Customer* Garage::getCustomer(const string& id) const{
    for (Customer* c: customers){
        if (c->getId() == id){
            return c;
        }
    }
    return nullptr;
}

Mechanic* Garage::getMechanic(const string& id) const{
    for (Mechanic* m: mechanics){
        if (m->getId() == id){
            return m;
        }
    }
    return nullptr;
}

void Garage::addRepair(const string&  customerId, int repairCode, double cost){
    Customer* c = getCustomer(customerId);
    if (c == nullptr) cout << "Customer " << customerId << " not found." << endl;
    else c->addRepair(new Repair(repairCode, cost));
}

void Garage::makeNextRepair(const string& mechanicId, const string& customerId){
    Mechanic* m = getMechanic(mechanicId);
    Customer* c = getCustomer(customerId);
    if (m == nullptr) cout << "Mechanic " << mechanicId << " not found." << endl;
    else if (c == nullptr) cout << "Customer " << customerId << " not found." << endl;
    else{
        Repair* todo = c->getNextRepair();
        if (todo == nullptr) cout << "No repairs left for " << customerId << endl;
        else{
            todo->completeRepair(mechanicId);
            m->addRepair(todo);
        }
    }
}

void Garage::printMechanics() const{
    for (Mechanic* m: mechanics){
        m->print();
    }
}

void Garage::printCustomers() const{
    for (Customer* c: customers){
        c->print();
    }
}

void Garage::printMechanicRepairs(const string& id) const{
    Mechanic* m = getMechanic(id);
    if (m == nullptr) cout << "Mechanic " << id << " not found." << endl;
    else m->printRepairs();
}

void Garage::printCustomerRepairs(const string& id) const{
    Customer* c = getCustomer(id);
    if (c == nullptr) cout << "Customer " << id << " not found." << endl;
    else {
        c->Customer::print();
        c->Customer::printRepairs();
    }
}

void Garage::resetIds(){
    Customer::resetId();
    Mechanic::resetId();
}
