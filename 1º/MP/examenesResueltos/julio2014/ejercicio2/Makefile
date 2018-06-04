
all:  barquitos

barquitos:	prueba.o barquito.o
	g++ -g -o bin/barquitos obj/prueba.o obj/barquito.o 

prueba.o:	src/prueba.cpp include/barquito.h
	g++ -g -c -o obj/prueba.o src/prueba.cpp -I./include

barquito.o:	src/barquito.cpp include/barquito.h
	g++ -g -c -o obj/barquito.o -I./include src/barquito.cpp

clean:
	rm obj/*.o


