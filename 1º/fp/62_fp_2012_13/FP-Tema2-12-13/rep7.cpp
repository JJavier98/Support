// Programa que muestra los factores primos de un número

#include <iostream>
using namespace std;

int main()
{
   int n, i;
   
   cout << "Introducir numero:";
   cin >> n;
   
   i = 2;
   while (n != 1)
     if (n % i == 0)
     {  
        n = n / i;
        cout << i << endl;
     }   
     else
        i++;  
  
   system("pause");
}
