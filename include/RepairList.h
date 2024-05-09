

#ifndef REPAIRLIST_H
#define REPAIRLIST_H

#include <iostream>
#include <string>
#include "Repair.h"

using namespace std;

class RepairList{

    class Node {
        public:
            Repair* data;
            Node*    next;
    };

    public: 
        RepairList();
        ~RepairList();
        void add(Repair*);
        Repair* getNext();
        bool isEmpty() const;
        int size() const;
        void print() const;
    private:
        Node* head;  
        Node * tail;

};

#endif