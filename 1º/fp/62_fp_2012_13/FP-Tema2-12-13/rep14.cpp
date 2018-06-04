// Programa que imprime la tabla de multiplicar de
// los N primeros números.

#include <iostream>
using namespace std;

int main()
{
    const int N=3;
    int i, j;

    for (i=1 ; i<=N ; i++) 
    {
       for (j=1 ; j<=N ; j++)
          cout << i << "*" << j <<"=" << i*j << " ";

       cout << endl;
    }

   //Esperar hasta pulsar alguna tecla   
   system("PAUSE");
}
