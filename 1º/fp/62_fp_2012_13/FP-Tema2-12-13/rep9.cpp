// Hallar la media de 5 números enteros.
#include <iostream>
using namespace std;

int main()
{
   int i, valor, suma;
   double media;
   
   suma = 0;
   for (i=1 ; i <= 5 ; i++)
   {
       cout << "Introduce el número " << i << ":";
       cin >> valor;

       suma = suma + valor;
   }

   media = suma / 5.0;
   
   cout << "La media es " << media << endl;

   //Esperar hasta pulsar alguna tecla   
   system("PAUSE");
}
