
#include "../include/Repair.h"
#include "../include/Garage.h"

const string Repair::NOTCOMPLETE = "not complete";

Repair::Repair(int repairCode, double cost){
    this->repairCode = repairCode;
    this->cost = cost;
    this->mechanicId = NOTCOMPLETE;   
}

bool Repair::isComplete(){
    return mechanicId != NOTCOMPLETE;
}

void Repair::completeRepair(const string& mechanicId){
    this->mechanicId = mechanicId;
}

void Repair::print(){
    cout << "repair: " << Garage::REPAIRS[repairCode] << " cost: " << cost << " mechanic: " << mechanicId << endl;
}