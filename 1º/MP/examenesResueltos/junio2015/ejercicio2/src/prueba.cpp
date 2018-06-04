#include <iostream>
#include <fstream>
#include "frecuencias.h"

using namespace std;

int main(int argc, char **argv){
   // Se crea objeto 
   Frecuencias objeto;
   
   // Se insertan valores
   objeto.add(9);
   
   // Se muestra el objeto tras cada paso
   cout << objeto;
   objeto.add(1);
   cout << objeto;
   objeto.add(3);
   cout << objeto;
   objeto.add(8);
   cout << objeto;
   objeto.add(2);
   cout << objeto;
   objeto.add(9);
   cout << objeto;
   objeto.add(10);
   cout << objeto;
   objeto.add(10);
   cout << objeto;
   objeto.add(0);
   cout << objeto;
   objeto.add(0);
   cout << objeto;
   objeto.add(9);
   cout << objeto;
   
   // Se agrega valor con +=
   objeto+=1;
   cout << objeto;
   
   // Se leen datos por teclado o por archivo
   Frecuencias leido;
   if (argc == 1){
     cout << "Introduzca numero de pares y parejas valor-frecuencia: " << endl;
     cin >> leido;
   }
   else{
      cout << "argv[1]" << argv[1] << endl;
      ifstream fichero(argv[1], ios::in);
      if (fichero.is_open()){
         fichero >> leido;
      }
   }
   
   cout << "Se muestran los datos leidos ....." << endl;
   cout << leido;
   
   // Se determinan las repeticiones de 10
   cout << "repeticiones de 10 : " << leido.repeticiones(10) << endl;
   cout << "repeticiones de 7 : " << leido.repeticiones(7) << endl;
}
