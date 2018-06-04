#ifndef BARQUITO_H
#define BARQUITO_H

#include <stdexcept>
#include <stdlib.h>
#include<iostream>
#include<fstream>

using namespace std;

class Barquito {
private:
   // Vector con los datos del tablero
   int **tablero;

   // Numero de filas del tablero
   int numeroFilas;

   // Numero de columnas del tablero
   int numeroColumnas;

   /**
    * Metodo privado para liberar el espacio del array de puntos
    */
   void liberarEspacio();

   /**
    * Metodo privado para reservar espacio para el array de puntos
    * @param tam valor a asignar a num
    */
   void reservarEspacio();

   /**
    * Metodo para inicializar a agua las casillas del tablero 
    */
   void inicializarAgua();

   /**
    * Metodo privado para asignar los valores de un tablero
    */
   void copiarTablero(int **otro);

   /**
    * Metodo de chequeo de posicionado de un barco en el tablero
    * @param fila caracter indicando la fila A..Z
    * @param columna entero
    * @param tam dimension del barco
    * @param direccion direccion horizontal o vertical
    * @return resultado de la operacion
    */
   bool chequearPosicionado(char fila, int columna, int tam, char direccion);

   /**
    * Metodo de insercion de barquito. Se asume que ya se comprobo
    * que puede ser insertado en esta posicion
    * @param fila
    * @param columna
    * @param direccion
    */
   void insertarBarco(int fila, int columna, int tam, char direccion);

   /**
    * Metodo de generacion de valor aleatorio entre min y max
    * @param min
    * @param max
    */
   int generarAleatorio(int min, int max) {
      return (min + rand() % max);
   }

public:

   // Constante para agua
   static const int AGUA = 9;

   // Constante para indicar direccion HORIZONTAL
   static const char HORIZONTAL = 'H';
   static const char VERTICAL = 'V';
   
   // Cadena para identificar los archivos
   static const string IDENTIFICADOR;

   /**
    * Constructor indicando el numero de filas y columnas
    * @param numFilas
    * @param numColumnas
    */
   Barquito(int numFilas, int numColumnas);

   /**
    * Destructor de la clase
    */
   ~Barquito() {
      // Se libera el array de puntos si es necesario
      liberarEspacio();
   }

   /**
    * Constructor de copia
    * @param aCopiar objeto a copiar
    */
   Barquito(const Barquito &aCopiar);

   /**
    * Operador de asignacion
    * @param aAsignar objeto a usar en la asignacion
    * @return 
    */
   Barquito & operator=(const Barquito & aAsignar);

   /**
    * Metodo de posicionado de barco de tamaño dado en una
    * posicion y sentido aleatorios
    */
   void posicionarBarco(int tam);

   /**
    * Metodo para mostrar el tablero
    */
   void mostrarTablero();
   
   /**
    * Metodo para leer los datos de un archivo
    */
   void leer(const char* nombreArchivo);
   
   /**
    * Metodo para escribir los datos en un archivo
    */
   void escribir(const char* nombreArchivo);
};

#endif
