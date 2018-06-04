/* 
        Lee un número positivo 'tope' desde teclado e imprime 'tope' 
        líneas con 5 estrellas cada una
*/

#include <iostream>
using namespace std;

int main() 
{
   
    int tope, total;
    
    cout << "Introducir numero de lineas:";
    cin >> tope;

    total = 1;
    while (total <= tope)
    {
           cout << "*****" << endl;
        
           total++;
    }
   
   //Esperar hasta pulsar alguna tecla   
   system("PAUSE");
}
