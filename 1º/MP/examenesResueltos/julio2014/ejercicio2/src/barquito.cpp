
#include "barquito.h"

/**
 * Constructor indicando el numero de filas y columnas
 * @param numFilas
 * @param numColumnas
 */
Barquito::Barquito(int numFilas, int numColumnas) {
   // Se asigna numeroFilas
   this->numeroFilas = numFilas;

   // Se asigna numeroColumnas
   this->numeroColumnas = numColumnas;

   // Se reserva espacio de memoria
   reservarEspacio();

   // Se inicializa a agua
   inicializarAgua();
}

/**
 * Constructor de copia
 * @param aCopiar objeto a copiar
 */
Barquito::Barquito(const Barquito &aCopiar) {
   // Se asignan los datos miembro
   numeroFilas = aCopiar.numeroFilas;
   numeroColumnas = aCopiar.numeroColumnas;

   // Se reserva espacio para un tablero de iguales dimensiones
   // que el pasado como argumento
   reservarEspacio();

   // Se copian los valores del tablero pasado como
   // argumento en este objeto
   copiarTablero(aCopiar.tablero);
}

/**
 * Operador de asignacion
 * @param aAsignar objeto a usar en la asignacion
 * @return 
 */
Barquito & Barquito::operator=(const Barquito & aAsignar) {
   // Se libera el espacio actual
   liberarEspacio();

   // Se asignan los valores de los datos miembro
   numeroFilas = aAsignar.numeroFilas;
   numeroColumnas = aAsignar.numeroColumnas;

   // Se copian los valores del tablero
   copiarTablero(aAsignar.tablero);

   // Se devuelve this
   return *this;
}

/**
 * Metodo de posicionado de barco de tamaño dado en una
 * posicion y sentido aleatorios
 */
void Barquito::posicionarBarco(int tam) {
   bool insertado = false;

   // Bucle de repeticion mientras no haya sido insertado
   while (!insertado) {
      // Se genera fila aleatoria
      int numeroFila = generarAleatorio(0, numeroFilas - 1);
      char fila = 'A' + numeroFila;

      // Se genera columna aleatoria
      int numeroColumna = generarAleatorio(1, numeroColumnas - 1);

      // Se genera una direccion aleatoria
      int valorDireccion = generarAleatorio(1, 2);
      char direccion = (valorDireccion == 1) ? HORIZONTAL : VERTICAL;

      // Se prueba el posicionado
      insertado = chequearPosicionado(fila, numeroColumna, tam, direccion);
      cout << "Insertado: " << insertado << endl;

      // Si es posible el insertado, se coloca
      if (insertado) {
         insertarBarco(numeroFila, numeroColumna - 1, tam, direccion);
      }
   }
}

/**
 * Mtodo para mostrar el contenido del tablero
 */
void Barquito::mostrarTablero() {
   cout << "------------- Contenido tablero ------------------" << endl;
   // Se muestran las columnas
   cout << "   ";
   for (int i = 1; i <= numeroColumnas; i++) {
      cout << i << "  ";
   }
   cout << endl;

   // Se muestran las filas
   for (int i = 0; i < numeroFilas; i++) {
      cout << (char) ('A' + i) << "  ";
      for (int j = 0; j < numeroColumnas; j++) {
         cout << tablero[i][j] << "  ";
      }
      cout << endl;
   }
   cout << "--------------------------------------------------" << endl;
   cout << endl;
}

/**
 * Metodo para leer los datos de un archivo
 */
void Barquito::leer(const char * nombreArchivo) {
   // Se crea el archivo de entrada
   ifstream archivo(nombreArchivo, ios::in | ios::binary);

   // Si no pudo abrirse, se indica que hubo
   // problemas de apertura
   if (!archivo.is_open()) {
      cout << "Problema de apertura de archivo de lectura......" << endl;
   } 
   else {
      // Se lee el identificador de la primera linea
      char cadena[100];
      archivo.getline(cadena, 100);

      // Se comprueba que coincida con el identificador
      if (Barquito::IDENTIFICADOR.compare(cadena) != 0) {
         cout << "Identificador incorrecto en archivo de datos....." << endl;
      } else {
         // Se leen el numero de filas y de columnas
         int numeroFilas, numeroColumnas;
         archivo >> numeroFilas >> numeroColumnas;

         // Se evita el salto de linea
         archivo.ignore(1);

         // Se libera el espacio actual
         liberarEspacio();

         // Se asignan numero de filas y de columnas
         this->numeroFilas = numeroFilas;
         this->numeroColumnas = numeroColumnas;

         // Se reserva espacio
         reservarEspacio();

         // Se leen los valores, almacenados en binario
         int valor;
         for (int i = 0; i < numeroFilas; i++) {
            for (int j = 0; j < numeroColumnas; j++) {
               archivo.read((char*) (&valor), sizeof (int));

               // Se asigna el valor a la posicion
               tablero[i][j] = valor;
            }
         }
      }
   }
   
   // Se cierra el archivo
   archivo.close();
}

/**
 * Metodo para escribir el contenido del objeto en un archivo
 */
void Barquito::escribir(const char *nombreArchivo) {
   // Se crea el archivo de salida
   ofstream archivo(nombreArchivo, ios::out | ios::binary);
   
   // Se comprueba si puedo abrirse ok
   if (!archivo.is_open()){
      cout << "Problema de apertura de archivo de escritura......" << endl;
   }
   else{
      // Se muestra el identificador de formato
      archivo << Barquito::IDENTIFICADOR << endl;
      
      // Se escribe el numero de filas y de columnas
      archivo << numeroFilas << " " << numeroColumnas << endl;
      
      // Se escriben los datos en binario
      for(int i=0; i < numeroFilas; i++){
         for(int j=0; j < numeroColumnas; j++){
            archivo.write((char*)(&tablero[i][j]),sizeof(int));
         }
      }
   }
   
   // Se cierra el archivo
   archivo.close();

}

/**
 * Metodo de chequeo de posicionado de un barco en el tablero
 * @param fila caracter indicando la fila A..Z
 * @param columna entero
 * @param tam dimension del barco
 * @param direccion direccion horizontal o vertical
 * @return resultado de la operacion
 */
bool Barquito::chequearPosicionado(char fila, int columna, int tam, char direccion) {
   // Varaible boolean para guardar el resultado de la operacion
   bool resultado = true;

   // Se determina el numero de fila
   int numeroFila = fila - 'A';
   cout << "    numeroFila: " << numeroFila << endl;

   // Se determina el numero de columna
   int numeroColumna = columna - 1;
   cout << "    numeroColumna: " << numeroColumna << endl;

   // Se determina si los datos son validos
   if (numeroFila >= numeroFilas || numeroColumna >= numeroColumnas) {
      resultado = false;
   } else {
      int columnaFinal = 0;
      int filaFinal = 0;

      cout << "    Direccion: " << direccion;

      // Se comprueba si cabe
      if (direccion == HORIZONTAL) {
         columnaFinal = numeroColumna + tam;
         cout << "    columnaFinal: " << columnaFinal << endl;
      } else {
         filaFinal = numeroFila + tam;
         cout << "    filaFinal: " << filaFinal << endl;
      }

      // Se comprueba que cabe
      if (columnaFinal >= numeroColumnas || filaFinal >= numeroFilas) {
         resultado = false;
      }
   }

   // Se devuelve el valor de resultado
   return resultado;
}

/**
 * Metodo de insercion de barquito. Se asume que ya se comprobo
 * que puede ser insertado en esta posicion
 * @param fila
 * @param columna
 * @param direccion
 */
void Barquito::insertarBarco(int fila, int columna, int tam, char direccion) {
   cout << "fila: " << fila << " columna: " << columna << " tam: " << tam << endl;
   if (direccion == HORIZONTAL) {
      for (int i = 0; i < tam; i++) {
         tablero[fila][columna + i] = tam;
      }
   }
   else {
      for (int i = 0; i < tam; i++) {
         tablero[fila + i][columna] = tam;
      }
   }
}

/**
 * Metodo privado para reservar espacio para el array de puntos 
 */
void Barquito::reservarEspacio() {
   // Se reserva espacio para el tamaño indicado por
   // numFilas y numColumnas. Se comienza reservando
   // espacio para el array de punteros a las filas
   tablero = new int*[numeroFilas];

   // Se reserva espacio para cada una de las filas
   for (int i = 0; i < numeroFilas; i++) {
      tablero[i] = new int[numeroColumnas];
   }
}

/**
 * Metodo privado para liberar el espacio del array de puntos
 */
void Barquito::liberarEspacio() {
   if (tablero != 0) {
      // Se libera el epsacio de las filas
      for (int i = 0; i < numeroFilas; i++) {
         delete [] tablero[i];
      }

      // Se libera el espacio de puntero a las filas
      delete [] tablero;
   }
   tablero = 0;
}

/**
 * Metodo para inicializar a agua las casillas del tablero 
 */
void Barquito::inicializarAgua() {
   for (int i = 0; i < numeroFilas; i++) {
      for (int j = 0; j < numeroColumnas; j++) {
         tablero[i][j] = AGUA;
      }
   }
}

/**
 * Metodo para copiar los valores de otro tablero
 * @param otro tablero a copiar
 * @see deben ser ambos del mismo tamaño
 */
void Barquito::copiarTablero(int **otro) {
   for (int i = 0; i < numeroFilas; i++) {
      for (int j = 0; j < numeroColumnas; j++) {
         tablero[i][j] = otro[i][j];
      }
   }
}

