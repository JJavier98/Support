// Hallar el mayor de 5 reales
#include <iostream>
using namespace std;

int main()
{
   int i;
   double valor, mayor;
   
   for (i=1 ; i <= 5 ; i++)
   {
       cout << "Introduce el número " << i << ":";
       cin >> valor;

       if (i==1)
           mayor = valor;
       else{
           if (valor > mayor)
               mayor = valor;
       }   
                
   }

   cout << "El mayor número introducido es " << mayor << endl;

   //Esperar hasta pulsar alguna tecla   
   system("PAUSE");
}
