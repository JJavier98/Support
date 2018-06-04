// Programa que fuerza al usuario a introducir
// un valor positivo y devuelve el coseno.

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
   double valor;

   do{
      cout << "Introduzca un valor positivo: ";
      cin >> valor;
   }while (valor < 0);
   
   cout << "Coseno:" << cos(valor) << endl;
   
   //Esperar hasta pulsar alguna tecla   
   system("PAUSE");
}
