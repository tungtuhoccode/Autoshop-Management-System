
#ifndef REPAIR_H
#define REPAIR_H

#include <iostream>
#include <string>

using namespace std;

class Repair{
    public:
        Repair(int repairCode, double cost);
        bool isComplete();
        void completeRepair(const string& mechanicId);
        void print();
    private: 
        int repairCode; //will be used with Garage::REPAIRS
        double cost;
        string mechanicId;
        static const string NOTCOMPLETE; 
        
};

#endif