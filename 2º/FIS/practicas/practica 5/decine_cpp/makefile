#########################################
# 										#
# Fundamentos de Ingenieria de Software	#
# Grado en Ingeniería Informática		#
# 										#
# 2014 - Ernesto Serrano Collado		#
#										#
#########################################

# VARIABLES
BIN = bin
SRC = src
OBJ = obj
LIB = lib
INCLUDE = include

# TODO (sin empaquetado)
all: clean $(BIN)/decine 

# COMPILACION

$(BIN)/decine : $(OBJ)/main.o $(OBJ)/Actor.o $(OBJ)/Critica.o $(OBJ)/DeCine.o $(OBJ)/Director.o $(OBJ)/FestivalPremio.o $(OBJ)/Pelicula.o $(OBJ)/Premio.o $(OBJ)/UsuarioVIP.o
	g++ -std=c++11 -o $(BIN)/decine $(OBJ)/main.o $(OBJ)/Actor.o $(OBJ)/Critica.o $(OBJ)/DeCine.o $(OBJ)/Director.o $(OBJ)/FestivalPremio.o $(OBJ)/Pelicula.o $(OBJ)/Premio.o $(OBJ)/UsuarioVIP.o -I$(INCLUDE)

$(OBJ)/main.o : $(SRC)/main.cpp
	g++ -std=c++11 -c -o $(OBJ)/main.o $(SRC)/main.cpp -I$(INCLUDE)

$(OBJ)/Actor.o : $(SRC)/Actor.cpp
	g++ -std=c++11 -c -o $(OBJ)/Actor.o $(SRC)/Actor.cpp -I$(INCLUDE)

$(OBJ)/Critica.o : $(SRC)/Critica.cpp
	g++ -std=c++11 -c -o $(OBJ)/Critica.o $(SRC)/Critica.cpp -I$(INCLUDE)

$(OBJ)/DeCine.o : $(SRC)/DeCine.cpp
	g++ -std=c++11 -c -o $(OBJ)/DeCine.o $(SRC)/DeCine.cpp -I$(INCLUDE)

$(OBJ)/Director.o : $(SRC)/Director.cpp
	g++ -std=c++11 -c -o $(OBJ)/Director.o $(SRC)/Director.cpp -I$(INCLUDE)

$(OBJ)/FestivalPremio.o : $(SRC)/FestivalPremio.cpp
	g++ -std=c++11 -c -o $(OBJ)/FestivalPremio.o $(SRC)/FestivalPremio.cpp -I$(INCLUDE)

$(OBJ)/Pelicula.o : $(SRC)/Pelicula.cpp
	g++ -std=c++11 -c -o $(OBJ)/Pelicula.o $(SRC)/Pelicula.cpp -I$(INCLUDE)

$(OBJ)/Premio.o : $(SRC)/Premio.cpp
	g++ -std=c++11 -c -o $(OBJ)/Premio.o $(SRC)/Premio.cpp -I$(INCLUDE)

$(OBJ)/UsuarioVIP.o : $(SRC)/UsuarioVIP.cpp
	g++ -std=c++11 -c -o $(OBJ)/UsuarioVIP.o $(SRC)/UsuarioVIP.cpp -I$(INCLUDE)

# EMPAQUETADO
# Genera el archivo .zip de la práctica mediante la linea de comandos
# Omite los archivos propios de MacOSX y coge el nombre del directorio como nombre
.PHONY : package
package : clean
	@echo "Empaquetando..."	
	zip $(shell basename "$(CURDIR)").zip -9 -r ./* -x "*.DS_Store" -x "__MACOSX"

# LIMPEZA
# Limpia los archivos compilados, así como los archivos objeto y los paquetes zip
.PHONY : clean
clean : 
	@echo "Limpiando..."
	@rm -f $(OBJ)/*\
        $(BIN)/*\
        ./*.zip
