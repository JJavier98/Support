// Programa que suma los valores leídos desde teclado
// hasta que se introduzca el valor -1.

#include <iostream>
using namespace std;

int main()
{
   int suma, numero;

   suma = 0;

   cout << "Introducir numero:";
   cin >> numero; // Primer candidato

   while (numero != -1) // ¿Es bueno?
   { 
      suma = suma + numero;

      cout << "Introducir numero:";
      cin >> numero;    // Leer siguiente candidato
   }
   
   cout << "La suma es " << suma << endl;

   //Esperar hasta pulsar alguna tecla   
   system("PAUSE");
}
