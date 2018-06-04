
all:	prueba

prueba : prueba.o frecuencias.o
	g++ -g -o bin/prueba obj/prueba.o obj/frecuencias.o

prueba.o : src/prueba.cpp include/frecuencias.h
	g++ -g -c -o obj/prueba.o -I./include src/prueba.cpp

frecuencias.o:	src/frecuencias.cpp include/frecuencias.h 
	g++ -g -c -o obj/frecuencias.o -I./include src/frecuencias.cpp

clean:
	rm obj/*.o


