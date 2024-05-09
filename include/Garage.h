
#ifndef GARAGE_H
#define GARAGE_H

#include <iostream>
#include <string>
#include <vector>

#include "Customer.h"
#include "Mechanic.h"

using namespace std;

class Garage{
		
	public:
		//member functions
		Garage();
		~Garage();
		void addMechanic(const string& name);
		void addCustomer(const string& name, const string& make, const string& model, int year);
		void addRepair(const string&  customerId, int repairCode, double cost);
		void makeNextRepair(const string& mechanicId, const string& customerId);
		Customer* getCustomer(const string& id) const;
		Mechanic* getMechanic(const string& id) const;
		void printMechanics() const;
		void printCustomers() const;
		void printMechanicRepairs(const string& id) const;
		void printCustomerRepairs(const string& id) const;
		void resetIds();

		//static class variables
		static const int NUM_REPAIRS = 10;
		static const string REPAIRS[NUM_REPAIRS]; 

	private:
		vector <Customer*> customers;
		vector <Mechanic*> mechanics;

	
};
#endif