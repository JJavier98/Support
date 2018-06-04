
all:	prueba

prueba : prueba.o lista.o
	g++ -g -o bin/prueba obj/prueba.o obj/lista.o

prueba.o : src/prueba.cpp include/lista.h
	g++ -g -c -o obj/prueba.o -I./include src/prueba.cpp

lista.o:	src/lista.cpp include/lista.h 
	g++ -g -c -o obj/lista.o -I./include src/lista.cpp

clean:
	rm obj/*.o


