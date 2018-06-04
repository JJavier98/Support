
all:  matriz

matriz:	prueba.o matriz.o
	g++ -g -o bin/matriz obj/prueba.o obj/matriz.o 

prueba.o:	src/prueba.cpp include/matriz.h 
	g++ -g -c -o obj/prueba.o src/prueba.cpp -I./include

matriz.o:	src/matriz.cpp include/matriz.h 
	g++ -g -c -o obj/matriz.o -I./include src/matriz.cpp

clean:
	rm obj/*.o


