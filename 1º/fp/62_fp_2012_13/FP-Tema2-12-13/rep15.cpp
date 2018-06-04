// Programa que muestra por pantalla los números primos existentes entre el 2 y
// un tope leido por teclado

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int dato, i, n;
    bool es_primo;
    double raiz;

    do{
       cout << "Introducir un entero positivo: ";
       cin >> dato;
    }while (dato < 0);

    for (n=2 ; n<=dato; n++)
    {
        es_primo = true;
        raiz = sqrt(1.0*n);
        
        for (i = 2; i <= raiz && es_primo; i++)
            if (n % i == 0)
               es_primo = false;
               
        if (es_primo)
            cout << n << endl;
    }           
  
    //Esperar hasta pulsar alguna tecla   
    system("PAUSE");
}
