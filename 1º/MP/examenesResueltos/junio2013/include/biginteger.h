#ifndef BIGINTEGER_H
#define BIGINTEGER_H

#include<stdexcept>
#include<string.h>
#include<iostream>
#include<sstream>
#include<fstream>
#include<stdlib.h>

using namespace std;

class BigInteger {
private:
   // Array para almacenar los digitos
   int *datos;
   
   // Numero de digitos
   int numeroDigitos;
   
   /**
    * Metodo privado para liberar el espacio del array de puntos
    */
   void liberarEspacio(){
      if (datos != 0){
         delete [] datos;
      }
      datos=0;
      numeroDigitos=0;
   }
   
   /**
    * Metodo privado para reservar espacio para el array de puntos
    * @param tam valor a asignar a num
    */
   void reservarEspacio(int numeroDigitos){
      // Se reserva espacio
      datos=new int[numeroDigitos];
      
      // Se cambia el valor de numeroDigitos
      this->numeroDigitos=numeroDigitos;
   }
   
   /**
    * Metodo auxiliar para copia de datos
    * @param otro
    */
   void copiarDatos(const BigInteger &otro){
      for(int i=0; i < numeroDigitos; i++){
         datos[i]=otro.datos[i];
      }
   }
   
   /**
    * Metodo para determinar la existencia de acarreo ante una suma
    * @param otro
    * @return 
    */
   bool hayAcarreo(const BigInteger &otro);
      
public:
   
   /**
    * Constructor por defecto
    */
   BigInteger(){
      reservarEspacio(1);
      datos[0]=0;
   }
   
   /**
    * Constructor de objeto a partir de cadena de caracteres
    * @param cadena
    */
   BigInteger(const char* cadena);
   
   /**
    * Constructor a partir de valor
    * @param valor
    */
   BigInteger(unsigned long int valor);
   
   /**
    * Constructor de copia
    * @param otro
    */
   BigInteger(const BigInteger &otro);
   
   /**
    * Operador de asignacion
    * @param otro
    * @return 
    */
   const BigInteger & operator=(const BigInteger &otro);
   
   const BigInteger & operator+(const BigInteger &otro);
   
   friend ostream & operator<<(ostream &flujo, const BigInteger &objeto);
   
   friend istream & operator>>(istream &flujo, BigInteger &objeto);
   
   /**
    * Destructor de la clase
    */
   ~BigInteger(){
      // Se libera el array de puntos si es necesario
      liberarEspacio();
   }
   
   /**
    * Genera cadena con contenido del objeto
    * @return 
    */
   string toString();
};
#endif
