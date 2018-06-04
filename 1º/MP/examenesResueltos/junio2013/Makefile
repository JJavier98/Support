
all:  prueba lecturaArchivo

prueba: prueba.o biginteger.o
	g++ -o bin/prueba obj/prueba.o obj/biginteger.o

lecturaArchivo: lecturaArchivo.o biginteger.o
	g++ -o bin/lecturaArchivo obj/lecturaArchivo.o obj/biginteger.o

prueba.o:	src/prueba.cpp include/biginteger.h 
	g++ -g -c -o obj/prueba.o src/prueba.cpp -I./include

lecturaArchivo.o: src/lecturaArchivo.cpp include/biginteger.h 
	g++ -g -c -o obj/lecturaArchivo.o src/lecturaArchivo.cpp -I./include

biginteger.o:	src/biginteger.cpp include/biginteger.h 
	g++ -g -c -o obj/biginteger.o -I./include src/biginteger.cpp

clean:
	rm obj/*.o


