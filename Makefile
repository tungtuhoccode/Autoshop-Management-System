objects = build/main.o build/Control.o build/View.o build/Garage.o build/Entity.o build/RepairList.o build/Repair.o build/Mechanic.o build/Customer.o build/Car.o build/Tester.o
testobjects = build/test.o build/TestControl.o build/View.o build/Garage.o build/Entity.o build/RepairList.o build/Repair.o build/Mechanic.o build/Customer.o build/Car.o build/Tester.o
compiler = g++ -std=c++11

TestDir = ./test
SourceDir = ./src
BuildDir = ./build
IncludeDir = ./include

all : a3 a3test 

a3test: $(testobjects) 
	${compiler} -o ./bin/tester $(testobjects) 

a3: $(objects)
	${compiler} -o ./bin/main $(objects) 

build/main.o: ${SourceDir}/main.cc ${IncludeDir}/Control.h 
	${compiler} -c ${SourceDir}/main.cc -o build/main.o

build/test.o: ${TestDir}/test.cc ${IncludeDir}/TestControl.h
	${compiler} -c ${TestDir}/test.cc -o build/test.o

build/Control.o: ${IncludeDir}/Control.h ${SourceDir}/Control.cc
	${compiler} -c ${SourceDir}/Control.cc -o build/Control.o

build/TestControl.o: ${TestDir}/TestControl.cc ${IncludeDir}/TestControl.h
	${compiler} -c ${TestDir}/TestControl.cc -o build/TestControl.o
	
build/View.o: ${SourceDir}/View.cc ${IncludeDir}/View.h
	${compiler} -c ${SourceDir}/View.cc -o build/View.o
	
build/Garage.o: ${SourceDir}/Garage.cc ${IncludeDir}/Garage.h
	${compiler} -c ${SourceDir}/Garage.cc -o build/Garage.o

build/Entity.o: ${SourceDir}/Entity.cc ${IncludeDir}/Entity.h
	${compiler} -c ${SourceDir}/Entity.cc -o build/Entity.o

build/Car.o: ${SourceDir}/Car.cc ${IncludeDir}/Car.h
	${compiler} -c ${SourceDir}/Car.cc -o build/Car.o 

build/RepairList.o: ${IncludeDir}/RepairList.h ${SourceDir}/RepairList.cc
	${compiler} -c ${SourceDir}/RepairList.cc -o build/RepairList.o 

build/Repair.o: ${IncludeDir}/Repair.h ${SourceDir}/Repair.cc
	${compiler} -c ${SourceDir}/Repair.cc -o build/Repair.o

build/Mechanic.o: ${SourceDir}/Mechanic.cc ${IncludeDir}/Mechanic.h ${IncludeDir}/Entity.h
	${compiler} -c ${SourceDir}/Mechanic.cc -o build/Mechanic.o

build/Customer.o: ${SourceDir}/Customer.cc ${IncludeDir}/Customer.h 
	${compiler} -c ${SourceDir}/Customer.cc -o build/Customer.o

build/Tester.o: ${TestDir}/Tester.cc ${IncludeDir}/Tester.h
	${compiler} -c ${TestDir}/Tester.cc -o build/Tester.o
	
clean:
	cd bin; rm -f main tester  *.o; cd ../build; rm -f *.o
