#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <string>
#include "Repair.h"
#include "RepairList.h"

class Entity{
    public:
        Entity(char code, int num, const string& name);
        bool hasRepairs() const;
        void addRepair(Repair* repair);
        Repair* getNextRepair();
        void print() const;
        void printRepairs() const;
        string getId() const; 
        
    protected:
        string name;
        string id;
        RepairList repairs;
};
#endif
