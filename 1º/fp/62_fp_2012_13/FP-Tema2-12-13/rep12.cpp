// Programa que determina si un entero es primo

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n, i;
    bool es_primo;
    double raiz;

    cout << "Introducir numero: ";
    cin >> n;

    es_primo = true;
    raiz = sqrt(1.0*n);
    
    for (i = 2; i <= raiz && es_primo; i++)
        if (n % i == 0)
           es_primo = false;
           
    if (es_primo)
        cout << n << " es primo\n";
    else
        cout << n << " no es primo\n";
  
    //Esperar hasta pulsar alguna tecla   
    system("PAUSE");
}
