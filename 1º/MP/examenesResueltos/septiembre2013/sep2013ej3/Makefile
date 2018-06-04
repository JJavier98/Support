
all:  alreves

alreves: alreves.o 
	g++ -g -o bin/alreves obj/alreves.o 

alreves.o: src/alreves.cpp 
	g++ -g -c -o obj/alreves.o src/alreves.cpp -I./include

clean:
	rm obj/*.o


