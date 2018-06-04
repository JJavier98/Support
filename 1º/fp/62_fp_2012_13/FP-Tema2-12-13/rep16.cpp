// Programa que muestra los números perfectos menores a un entero leido

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n, i, suma, tope;
    
    cout << "Introducir tope: ";
    cin >> tope;
    
    for (n=2; n<=tope; n++)
    {
        suma = 0;
        for(i=1; i<n; i++)
          if (n % i == 0)
             suma = suma + i;
        
        if (suma == n)
            cout << n << endl;
    }  
    
    //Esperar hasta pulsar alguna tecla   
    system("PAUSE");
}
