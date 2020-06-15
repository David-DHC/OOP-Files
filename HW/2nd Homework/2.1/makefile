all: main

main: main.o Student.o StudentCollection.o 
	g++ -std=c++14 main.o Student.o StudentCollection.o -o main

main.o: main.cpp Student.h StudentCollection.h
	g++ -std=c++14 -c main.cpp -o main.o
	
Student.o: Student.cpp Student.h StudentCollection.h
	g++ -std=c++14 -c Student.cpp -o Student.o

StudentCollection.o: StudentCollection.cpp Student.h StudentCollection.h
	g++ -std=c++14 -c StudentCollection.cpp -o StudentCollection.o

-PHONY: clean
clean: 
	rm main.o Student.o StudentCollection.o \
	   main