
#include <iostream>
#include <fstream>
#include "biginteger.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

   // Creacion de objeto con constructor por defecto
   BigInteger objeto1;

   // Se muestra el contenido
   cout << "Objeto con constructor por defecto: " << objeto1.toString() << endl;

   // Constructor con cadena de caracteres
   char cadena[]="123456789";
   BigInteger objeto2(cadena);

   // Se muestra su contenido
   cout << "Objeto con cadena: " << objeto2.toString() << endl;
   
   // Constructor con valor unsigned int
   unsigned long int valor=98765432109876;
   BigInteger objeto3(valor);
   
   // Se muestra su contenido
   cout << "Objeto con unsigned int: " << objeto3.toString() << endl;
   
   // Prueba del constructor de copia
   BigInteger objeto4(objeto3);
   
   // Se muestra su contenido
   cout << "Objeto con construtor de copia: " << objeto4.toString() << endl;
   
   // Prueba del operador de asignacion
   objeto4=objeto2;
   
   // Se muestra su contenido
   cout << "Objeto tras asignacion (igual a cadena): " << objeto4.toString() << endl;
      
   // Se prueba el operador de suma
   char cadena5[]="9859";
   BigInteger objeto5(cadena5);
   char cadena6[]="9954";
   BigInteger objeto6(cadena6);
   
   BigInteger suma=objeto5+objeto6;
   cout << "Valor de suma: " << objeto5.toString() << endl;
   
   // Se muestra la suma con el operador <<
   cout << "Suma mostrada con <<" << endl;
   cout << suma << endl;
   
   // Se lee nuevo valor sobre objeto
   cin >> suma;
   
   // Se muestra el nuevo valor
   cout << "Nuevo valor de suma: " << endl;
   cout << suma << endl;
   
   // Sentencia return indicando al SO todo OK
   return 0;
}

