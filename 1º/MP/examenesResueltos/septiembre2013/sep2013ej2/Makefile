
all:  menu

menu:	prueba.o menu.o
	g++ -g -o bin/menu obj/prueba.o obj/menu.o 

prueba.o:	src/prueba.cpp include/menu.h
	g++ -g -c -o obj/prueba.o src/prueba.cpp -I./include

menu.o:	src/menu.cpp include/menu.h 
	g++ -g -c -o obj/menu.o -I./include src/menu.cpp

clean:
	rm obj/*.o


