#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

// Realizar un programa que lea dos números representados en binario y los sume.

class Binario
{
private: 
	vector <int> representacion;

    int Potencia2 (int n)
    {
          int pot = 1;
          for (int i=1; i<=n; i++)
              pot = pot * 2;
    
          return pot;
    }

public:
	Binario()
	{
         representacion.push_back(0);
    }

    // Precondición: v contiene una cadena de enteros 0 y 1
	Binario(vector <int> v)
         :representacion(v) {}

	int Binario_a_Entero()
    {
         int entero=0, n;
		
		 n = representacion.size();
		
         for(int p = n-1; p>=0; p--)
             entero = entero + representacion.at(n-1-p)*Potencia2(p);
         
         return entero;        
	}

	void Entero_a_Binario(int entero)
    {
        vector <int> v;
    
        while ( entero > 0 )
        {
             if ( entero % 2 == 1)
                v.push_back(1); 
             else
                v.push_back(0);
            
             entero = entero / 2;
        } 
        
	    representacion.clear();
  	    
        for(int i = v.size()-1; i>=0; i--)
           representacion.push_back ( v.at(i) );
     }
     
	string Binario_a_String()
    {
        string cadena;
    
        for(int i = 0; i < representacion.size(); i++)
           if (representacion.at(i) == 1)
                cadena.push_back ('1');
           else     
                cadena.push_back ('0');
           
        return cadena;   
    }

	void Sumar(Binario b1, Binario b2)
    {
        int suma = b1.Binario_a_Entero() + b2.Binario_a_Entero();
    
        Entero_a_Binario(suma);   
    }
};

int main()
{
    vector <int> v;
	int n, x; 

    // Lectura de un número binario ...
    
    cout << "Numero de cifras: ";
    cin >> n;

	for (int i=0; i<n; i++)
	{
        do{
		     cout << "Introducir cifra (0/1): ";
		     cin >> x;
		}while (x != 0 && x != 1);       
		   
		v.push_back(x);
    }
    
    Binario b1(v);

    // Lectura de otro número binario ...

    v.clear(); // Borrar todos los elementos de v, para poder leer otro binario    
    
    cout << "\nNumero de cifras: ";
    cin >> n;
    
	for (int i=0; i<n; i++)
	{
        do{
		     cout << "Introducir cifra (0/1): ";
		     cin >> x;
		}while (x != 0 && x != 1);       
		   
		v.push_back(x);
    }

    Binario b2(v);

    // Suma de los números binarios ...
    Binario bs;

    bs.Sumar(b1, b2);
    
    cout << endl;
    
    cout << b1.Binario_a_String() << "(" << b1.Binario_a_Entero() << ") + " 
         << b2.Binario_a_String() << "(" << b2.Binario_a_Entero() << ") = "
         << bs.Binario_a_String() << "(" << bs.Binario_a_Entero() << ")" << endl;
         
	system("pause");
}
