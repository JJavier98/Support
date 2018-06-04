#ifndef POLILINEA_H
#define POLILINEA_H

#include <stdexcept>
#include<iostream>
#include<fstream>
#include "punto.h"

using namespace std;

class Polilinea {
private:
   // Vector con los puntos de la polilinea
   Punto *p;
   
   // Numero de puntos de la polilinea
   int num;
   
   /**
    * Metodo privado para liberar el espacio del array de puntos
    */
   void liberarEspacio(){
      if (p != 0){
         delete [] p;
      }
      p=0;
   }
   
   /**
    * Metodo privado para reservar espacio para el array de puntos
    * @param tam valor a asignar a num
    */
   void reservarEspacio(int tam){
      // Se reserva espacio
      p=new Punto[tam];
      
      // Se cambia el valor de num
      num=tam;
   }
   
   /**
    * Metodo para asignar los puntos de un array de puntos
    * @param num numero de puntos en el array
    * @param puntos 
    */
   void asignarPuntos(int num, Punto * const puntos){
      for(int i=0; i < num; i++){
         p[i]=puntos[i];
      }
   }
   
public:
   
   /**
    * Constructor por defecto
    */
   Polilinea(){
      // Se asigna p a null
      p=0;
      
      // El numero de puntos de la polilinea es 0
      num=0;
   }
   
   /**
    * Destructor de la clase
    */
   ~Polilinea(){
      // Se libera el array de puntos si es necesario
      liberarEspacio();
   }
   
   /**
    * Constructor de copia
    * @param aCopiar objeto a copiar
    */
   Polilinea(const Polilinea &aCopiar);
   
   /**
    * Operador de asignacion
    * @param aAsignar objeto a usar en la asignacion
    * @return 
    */
   Polilinea operator=(const Polilinea & aAsignar);
   
   /**
    * Operador corchete
    * @param indice
    * @return 
    */
   Punto & operator[](int indice) const;
   
   /**
    * Operador de igualdad
    * @param aComparar
    * @return 
    */
   bool operator==(const Polilinea &aComparar) const;
   
   /**
    * Operador de diferencia
    * @param aComparar
    * @return 
    */
   bool operator!=(const Polilinea &aComparar) const{
      return !(*this == aComparar);
   }
   
   /**
    * Operador + para poder agregar un punto al objeto
    * @param punto
    * @return 
    */
   Polilinea operator+(const Punto &punto) const;
   
   /**
    * Funcion amiga para poder agregar un punto al inicio
    * @param punto
    * @param linea
    */
   friend Polilinea operator+(const Punto & punto, const Polilinea &linea);
   
   /**
    * Metodo para leer el conjunto de puntos almacenados en un archivo
    * @param nombre
    */
   void leerPolilinea(const char *nombre);
   
   /**
    * Metodo para guardar en un archivo el contenido de un objeto
    * @param nombre
    * @param comentario
    */
   void escribirPolilinea(const char *nombre, const char *comentario);
   
   /**
    * Funcion amiga para mostrar el contenido de un objeto
    * @param flujo de salida
    * @param polilinea objeto a mostrar
    */
   friend ostream & operator<<(ostream &flujo, const Polilinea & polilinea);
};
#endif
