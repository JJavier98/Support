// Programa que imprime el factorial de un numero leido

#include <iostream>
using namespace std;

int main()
{
    int i, n, factorial;

    cout << "Introducir numero: ";
    cin >> n;

    factorial = 1;
    for (i=1 ; i<=n ; i++) 
        factorial = factorial * i;

   cout << "Factorial de " << n << ": " << factorial << endl;
  
    //Esperar hasta pulsar alguna tecla   
   system("PAUSE");
}
