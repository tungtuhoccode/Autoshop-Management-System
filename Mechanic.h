#ifndef MECHANIC_H
#define MECHANIC_H

#include "Entity.h"

using namespace std;

class Mechanic: public Entity{
    public: 
        Mechanic(const string& name);
        void print() const;
        static void resetId();
    private: 
        //static variables
        static const char code;
        static int nextId; 
};

#endif



