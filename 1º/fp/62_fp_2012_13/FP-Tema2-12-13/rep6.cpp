// Programa que lee caracteres hasta introducir el punto y muestra el
// número de vocales que se han introducido

#include <iostream>
using namespace std;

int main()
{
   char car;
   int numero_vocales = 0;

   cout << "Introducir caracter:";
   cin >> car; 

   while (car != '.') 
   { 
      if (car == 'a' || car == 'e' || car == 'i' || car == 'o' || car == 'u')
         numero_vocales++;
         
      cout << "Introducir caracter:";
      cin >> car;    
   }
   
   cout << "El número de vocales es: " << numero_vocales << endl;

   //Esperar hasta pulsar alguna tecla   
   system("PAUSE");
}
