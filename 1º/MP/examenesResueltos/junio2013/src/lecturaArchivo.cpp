
#include <iostream>
#include <fstream>
#include "biginteger.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
   // Se implementa aqui la suma de valores almacenados en archivos
   ifstream flujo;
   BigInteger suma, valor;
   
   // Se comprueba que al menos se haya pasado un argumento en la
   // llamada
   if(argc < 2){
      cerr << "Forma de uso: lecturaArchivo nombreArchivo";
      exit(1);
   }
   
   // Se procede a la apertura del archivo
   flujo.open(argv[1]);
   
   // Se comprueba si pudo abrirse
   if(flujo){
      // Se lee mientras la lectura no genere problemas
      while(flujo >> valor){
         // Se hace uso de suma y del operador de asignacion
         suma=suma+valor;
      }
      
      // Se muestra la suma al final
      cout << "Suma obtenida: " << suma << endl;
   }
   
   // Sentencia return indicando al SO todo OK
   return 0;
}

