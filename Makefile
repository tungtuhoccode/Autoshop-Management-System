objects = main.o Control.o View.o Garage.o Entity.o RepairList.o Repair.o Mechanic.o Customer.o Car.o Tester.o
testobjects = test.o TestControl.o  View.o Garage.o Entity.o RepairList.o Repair.o Mechanic.o Customer.o Car.o Tester.o
compiler = g++ -std=c++11

all : a3 a3test 

a3test: $(testobjects) 
	${compiler} -o a3test $(testobjects) 

a3: $(objects)
	${compiler} -o a3 $(objects) 

main.o: main.cc Control.h 
	${compiler} -c main.cc 

test.o: test.cc TestControl.h
	${compiler} -c test.cc

Control.o: Control.h Control.cc
	${compiler} -c Control.cc

TestControl.o: TestControl.cc TestControl.h
	${compiler} -c TestControl.cc
	
View.o: View.cc View.h
	${compiler} -c View.cc
	
Garage.o: Garage.cc Garage.h
	${compiler} -c Garage.cc

Entity.o: Entity.cc Entity.h
	${compiler} -c Entity.cc

Car.o: Car.cc Car.h
	${compiler} -c Car.cc

RepairList.o: RepairList.h RepairList.cc
	${compiler} -c RepairList.cc

Repair.o: Repair.h Repair.cc
	${compiler} -c Repair.cc

Mechanic.o: Mechanic.cc Mechanic.h Entity.h
	${compiler} -c Mechanic.cc 

Customer.o: Customer.cc Customer.h 
	${compiler} -c Customer.cc

Tester.o: Tester.cc Tester.h
	${compiler} -c Tester.cc
	

clean:
	rm -f a3 a3test *.o