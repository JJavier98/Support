#ifndef MATRIZ_H
#define MATRIZ_H

#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;

/**
 * Clase Matriz: matriz con filas de tamaño variable
 */
class Matriz {
private:
   /**
    * Dato miembro para almacenar el numero de filas
    */
   int nfilas;

   /**
    * Dato miembro para almacenar el tamaño de las columnas
    */
   int *ncolumnas;

   /**
    * Dato miembro para los punteros a los arrays de las filas
    */
   double **datos;
   
   /**
    * Metodo privado para liberar espacio de memoria
    */
   void liberarEspacio();

   /**
    * Metodo de reserva de espacio
    * @param nfilas numero de filas de la matriz
    * @param ncolumnas array indicando el tamaño de cada fila
    */
   void reservarEspacio(int nfilas, int *ncolumnas);
   
   /**
    * Metodo privado de copia de datos de otro objeto, que se
    * asume tiene las mismas dimensiones que this
    * @param otro objeto del que copiar los datos
    */
   void copiarDatos(const Matriz &otro);
   
public:
   
   /**
    * Constructor por defecto
    */
   Matriz();
   
   /**
    * Constructor inicializando las dimensiones de la matriz
    * @param nfilas numero de filas
    * @param ncolumnas tamaño de las filas
    */
   Matriz(int nfilas, int *ncolumnas);
   
   /**
    * Destructor
    */
   ~Matriz();
   
   /**
    * Constructor de copia
    * @param otro objeto a copiar
    */
   Matriz(const Matriz &otro);
   
   /**
    * Operador de asignacion
    * @param otro objeto que asignar
    * @return objeto modificado
    */
   const Matriz & operator=(const Matriz & otro);
   
   /**
    * Funcion amiga para sobrecargar el operador <<
    * @param flujo flujo a usar para la salida
    * @param objeto objeto a mostrar
    */
   friend ostream & operator<<(ostream &flujo, const Matriz &objeto);
   
   /**
    * Funcion amiga a la clase para sobrecargar el operador <<
    * @param flujo flujo de entrada
    * @param objeto objeto sobre el que almacenar los datos leidos
    */
   friend istream & operator>>(istream &flujo, const Matriz &objeto);
   
   /**
    * Metodo para acceder al contenido de una posicion
    * @param fila
    * @param columna
    * @return 
    */
   double get(int fila, int columna);
   
   /**
    * Metodo para asignar valor a una posicion
    * @param fila
    * @param columna
    * @param valor
    */
   void set(int fila, int columna, double valor);
   
   /**
    * Metodo para devolver una nueva matriz intercambiando las
    * filas de la matriz sobre la que se hace la llamada
    * (primera por ultima, segunda por penultima, ....)
    * @param nombreArchivo
    * @param comentario
    */
   Matriz & vflip();
   
   /**
    * Metodo para obtener la posicion del valor de maximo
    * valor de la matriz
    * @param fila
    * @param columna
    */
   void obtenerMaximo(int &fila, int &columna);
   
   /**
    * Metodo para escribir el contenido del objeto en un archivo
    * @param nombreArchivo nombre del archivo a escribir
    * @param comentario comentario a agregar al archivo
    */
   void escribirArchivo(string nombreArchivo, string comentario);
   
   /**
    * Metodo para leer los datos desde un archivo. El objeto sobre el
    * que se hace la llamada se modifica y cambia su estructura para
    * poder capturar los datos del archivo
    * @param nombreArchivo nombre del archivo del que leer los datos
    */
   void leerArchivo(string nombreArchivo);
};
#endif
