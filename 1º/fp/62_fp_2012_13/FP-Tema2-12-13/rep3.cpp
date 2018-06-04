// Hallar la media de 5 números enteros.
#include <iostream>
using namespace std;

int main()
{
   int i, valor, suma;
   double media;
   
   suma = 0;
   i=1 ;
   while ( i <= 5)
   {
       cout << "Introduce el número " << i << ":";
       cin >> valor;

       suma = suma + valor;
       
       i++;
   }

   media = suma / 5.0;
   cout << "La media es " << media << endl;

   //Esperar hasta pulsar alguna tecla   
   system("PAUSE");
}
