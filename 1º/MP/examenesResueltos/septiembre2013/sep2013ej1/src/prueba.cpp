
#include <iostream>
#include <fstream>
#include "entero.h"

using namespace std;

Entero doble(Entero e){
   return e.get()*2;
}

/*
 * 
 */
int main(int argc, char** argv) {
   Entero x(5), y;
   
   y=doble(x);
   
   cout << "Resultado: " << y << endl;
   
   // Sentencia return indicando al SO todo OK
   return 0;
}

