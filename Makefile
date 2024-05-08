objects = build/main.o build/Control.o build/View.o build/Garage.o build/Entity.o build/RepairList.o build/Repair.o build/Mechanic.o build/Customer.o build/Car.o build/Tester.o
testobjects = build/test.o build/TestControl.o build/View.o build/Garage.o build/Entity.o build/RepairList.o build/Repair.o build/Mechanic.o build/Customer.o build/Car.o build/Tester.o
compiler = g++ -std=c++11

TestDir = ./test
SourceDir = ./src
BuildDir = ./build

all : a3 a3test 

a3test: $(testobjects) 
	${compiler} -o a3test $(testobjects) 

a3: $(objects)
	${compiler} -o a3 $(objects) 

build/main.o: ${SourceDir}/main.cc ${SourceDir}/Control.h 
	${compiler} -c ${SourceDir}/main.cc -o build/main.o

build/test.o: ${TestDir}/test.cc ${TestDir}/TestControl.h
	${compiler} -c ${TestDir}/test.cc -o build/test.o

build/Control.o: ${SourceDir}/Control.h ${SourceDir}/Control.cc
	${compiler} -c ${SourceDir}/Control.cc -o build/Control.o

build/TestControl.o: ${TestDir}/TestControl.cc ${TestDir}/TestControl.h
	${compiler} -c ${TestDir}/TestControl.cc -o build/TestControl.o
	
build/View.o: ${SourceDir}/View.cc ${SourceDir}/View.h
	${compiler} -c ${SourceDir}/View.cc -o build/View.o
	
build/Garage.o: ${SourceDir}/Garage.cc ${SourceDir}/Garage.h
	${compiler} -c ${SourceDir}/Garage.cc -o build/Garage.o

build/Entity.o: ${SourceDir}/Entity.cc ${SourceDir}/Entity.h
	${compiler} -c ${SourceDir}/Entity.cc -o build/Entity.o

build/Car.o: ${SourceDir}/Car.cc ${SourceDir}/Car.h
	${compiler} -c ${SourceDir}/Car.cc -o build/Car.o 

build/RepairList.o: ${SourceDir}/RepairList.h ${SourceDir}/RepairList.cc
	${compiler} -c ${SourceDir}/RepairList.cc -o build/RepairList.o 

build/Repair.o: ${SourceDir}/Repair.h ${SourceDir}/Repair.cc
	${compiler} -c ${SourceDir}/Repair.cc -o build/Repair.o

build/Mechanic.o: ${SourceDir}/Mechanic.cc ${SourceDir}/Mechanic.h ${SourceDir}/Entity.h
	${compiler} -c ${SourceDir}/Mechanic.cc -o build/Mechanic.o

build/Customer.o: ${SourceDir}/Customer.cc ${SourceDir}/Customer.h 
	${compiler} -c ${SourceDir}/Customer.cc -o build/Customer.o

build/Tester.o: ${TestDir}/Tester.cc ${TestDir}/Tester.h
	${compiler} -c ${TestDir}/Tester.cc -o build/Tester.o
	
clean:
	cd build; 
	rm -f a3 a3test *.o; 
