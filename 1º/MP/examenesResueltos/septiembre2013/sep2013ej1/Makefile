
prueba: prueba.o entero.o
	g++ -o bin/prueba obj/prueba.o obj/entero.o

prueba.o:	src/prueba.cpp include/entero.h 
	g++ -g -c -o obj/prueba.o src/prueba.cpp -I./include

entero.o:	src/entero.cpp include/entero.h 
	g++ -g -c -o obj/entero.o -I./include src/entero.cpp

clean:
	rm obj/*.o


