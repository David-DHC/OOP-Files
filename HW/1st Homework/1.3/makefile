all: main

main: main.o Student.o ClassSystem.o 
	g++ -std=c++11 main.o Student.o ClassSystem.o -o main

main.o: main.cpp Student.h ClassSystem.h
	g++ -std=c++11 -c main.cpp -o main.o

Student.o: Student.cpp Student.h ClassSystem.h
	g++ -std=c++11 -c Student.cpp -o Student.o

ClassSystem.o: ClassSystem.cpp Student.h ClassSystem.h
	g++ -std=c++11 -c ClassSystem.cpp -o ClassSystem.o

clean: 
	rm main.o Student.o ClassSystem.o \
	   main