
#include <iostream>
#include "polilinea.h"
#include "punto.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

   // Pensamos en formas de crear una polilinea usando el
   // constructor por defecto
   cout << "Creacion de polilinea......" << endl;
   Polilinea polilinea1;
   
   // Creo secuencia de tres puntos
   Punto punto1(1,1);
   Punto punto2(2,3);
   Punto punto3(3,4);
   
   // Se asignan los puntos a diferentes objetos
   Polilinea polilinea2=polilinea1+punto1;
   
   // Ahora se inserta otro al principio
   Polilinea polilinea3=punto3+polilinea2;
   
   // Ahora se inserta al final punto2
   Polilinea polilinea4=polilinea3+punto2;
   
   // Se comprueba la igualdad de polilinea4 y polilinea3
   cout << "Comparacion polilinea3 y polilinea4: " << (polilinea3 == polilinea4) << endl;
      
   // Se modifica uno de los objetos con los datos de un archivo
   polilinea1.leerPolilinea("./polilinea.dat");
   
   // Se muestra la linea cargada del archivo
   cout << "Objeto polilinea1 tras cargar datos de archivo: " << endl;
   cout << polilinea1<< endl;
   
   // Se almacena en un archivo auxiliar
   polilinea1.escribirPolilinea("./polilinea1.dat","Copia de objeto polilinea");
   
   // Se comprueba que se lee ok
   Polilinea polilinea5;
   polilinea5.leerPolilinea("./polilinea1.dat");
   
   // Se comprueba que sean iguales
   cout << "Igualdad de objetos " << (polilinea1 == polilinea5) << endl;
   
   // Sentencia return indicando al SO todo OK
   return 0;
}

