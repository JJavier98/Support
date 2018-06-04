/* 
        Este programa muestra por pantalla 20 líneas con asteriscos
*/

#include <iostream>
using namespace std;

int main() 
{
   
    int total;
    
    total = 1;
    while (total <= 20)
    {
         cout << "*****" << endl;
         
         total=total+1;
    }      

   //Esperar hasta pulsar alguna tecla   
   system("PAUSE");
}
