/*   Programa que resuelve que calcula x^n
*/
#include <iostream>
   
int main()
{
   double pot=1;
   double x; 
   int n;

   cout << "Introduzca el valor (real) de la base: " << endl;
   cin >> x;
   
   cout << "Introduzca el valor (entero) del exponente: " << endl;
   cin >> n;

    
   for(int i=1; i<=n; i++)
       pot=pot*x;
    
   
   cout << "La potencia es igual a: " << pot << endl;
   
   //Esperar hasta pulsar alguna tecla   
   system("PAUSE");
}
       
   
