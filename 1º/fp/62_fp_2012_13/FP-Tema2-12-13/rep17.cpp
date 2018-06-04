// Programa que muestra un triangulo por pantalla

#include <iostream>
using namespace std;

int main()
{
    int n, i, j, L;

    cout << "Introducir longitud de la base: ";
    cin >> n;

    for (L = 1; L <= n; L++)
    {
        for (j = 1; j <= L; j++)
           cout << '*';
        
        cout << endl;      
    }
  
    //Esperar hasta pulsar alguna tecla   
    system("PAUSE");
}
