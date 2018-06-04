
all:  polilinea

polilinea:	prueba.o polilinea.o
	g++ -g -o bin/polilinea obj/prueba.o obj/polilinea.o 

prueba.o:	src/prueba.cpp include/polilinea.h include/punto.h
	g++ -g -c -o obj/prueba.o src/prueba.cpp -I./include

polilinea.o:	src/polilinea.cpp include/polilinea.h include/punto.h
	g++ -g -c -o obj/polilinea.o -I./include src/polilinea.cpp

clean:
	rm obj/*.o


