all:main

main: main.o product.o sum.o functions.h
	g++ $(FLAG) main.o product.o sum.o -o main

main.o: main.cpp functions.h
	g++ $(FLAG) -c main.cpp -o main.o

sum.o: sum.cpp functions.h
	g++ -c sum.cpp -o sum.o

product.o: product.cpp functions.h
	g++ -c product.cpp -o product.o

clean: 
	rm -f main product.o main.o sum.o