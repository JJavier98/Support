// Programa que determina si un entero es un número perfecto:
// Un número n es perfecto cuando es igual a la suma de sus divisores propios

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n, i, suma;
    
    cout << "Introducir numero: ";
    cin >> n;
    
    suma = 0;
    for(i=1; i<n; i++)
       if (n % i == 0)
          suma = suma + i;
    
    if (suma == n)
        cout << n << " es perfecto\n";
    else
        cout << n << " no es perfecto\n";
  
    //Esperar hasta pulsar alguna tecla   
    system("PAUSE");
}
