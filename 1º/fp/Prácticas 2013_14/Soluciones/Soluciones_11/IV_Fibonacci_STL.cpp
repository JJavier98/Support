/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
// GRADO EN INGENIER�A INFORM�TICA
//
// CURSO 2013-2014
// (C) JUAN CARLOS CUBERO TALAVERA
// (C) FRANCISCO JOS� CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACI�N E INTELIGENCIA ARTIFICIAL
//
// RELACI�N DE PROBLEMAS 4
// EJERCICIO 13 (con vector de la STL)
//
/*	
	Este programa lee los valores de dos enteros, "n" y "k" y calcula, 
	almacena en un vector y muestra por pantalla los "k" primeros t�rminos 
	de la sucesi�n de Fibonacci de orden n.

		La sucesi�n de Fibonacci de orden n es una secuencia de n�meros en 
		la que los dos primeros son el 0 y el 1. A partir del tercero, los 
		elementos se calculan como la suma de los n anteriores, si ya hay 
		n elementos disponibles, o la suma de todos los anteriores si hay 
		menos de n elementos disponibles.

		Por ejemplo, la sucesi�n de Fibonacci de orden 4 ser�a la siguiente:
			0, 1, 1, 2, 4, 8, 15, 29, ...

	Para ello se construye la clase "Fibonacci": 
	
	1) Representaci�n: Usa un vector de la STL como dato miembro privado. 

	2) Ofrece los m�todos:  
	
	* Fibonacci (int orden)
		Constructor con par�metros. 
		La creaci�n de la serie conlleva el c�lculo de tantos elementos como el 
		orden de la serie. 
		POST: GetOrden() == TotalCalculados() 

	* int GetOrden (void)
		Devuelve el orden de la serie.

	* void CalculaPrimeros(int tope) 
		Calcula los "tope" primeros elementos de la sucesi�n. 
		Recordemos que los "orden" primeros elementos los calcula el constructor. 

	* int TotalCalculados() 
		Devuelve cu�ntos elementos hay actualmente almacenados (el valor 
		"tope" del m�todo anterior)

	* int Elemento(int indice) 
		Devuelve el elemento indice-�simo de la sucesi�n.
*/
/*********************************************************************/

#include <iostream>
#include <iomanip>

#include <vector>	// Para la almacenar los elementos de la serie 

using namespace std;

///////////////////////////////////////////////////////////////////////

class Fibonacci 
{

private:

	// Datos asociados a la estructura de datos empleada para guardar 
	// los valores de la serie (vector de la STL)

	vector <int> vector_privado;

	// Datos espec�ficos de la clase Fibonacci

	int orden; // Orden de la serie de Fobonacci
	
public:
	
	/*****************************************************************/
	// Constructor con par�metros. 
	// La creaci�n de la serie conlleva el c�lculo de tantos elementos 
	// como el orden de la serie. 
	// POST: GetOrden() == TotalCalculados() 

	Fibonacci(int n) 
	{

		orden = n; 

		// Calcular y guardar los primeros t�rminos (0,1,2,...,n)
		// donde "n" es el orden de la sucesi�n.

		vector_privado.push_back(0);	// vector_privado[0] = 0;
		vector_privado.push_back(1);	// vector_privado[1] = 1;

		for (int pos=2; pos<orden; pos++) {

			// suma desde 0 hasta "pos"

			int suma = 0;
			for (int i=0; i<pos; i++)
				suma += vector_privado[i];
	
			vector_privado.push_back(suma);	// vector_privado[pos] = suma;
		}

		// total_utilizados = orden; // actualizar el valor de "total_utilizados"

	}


	/*****************************************************************/
	// 	Devuelve cu�ntos elementos hay actualmente almacenados 
	
	int TotalCalculados (void) 
	{
		return (vector_privado.size());
	}

	/*****************************************************************/
	// Devuelve el orden de la sucesi�n
	
	int GetOrden()
	{
		return orden;
	}

	/*****************************************************************/
	// Devuelve el elemento de la casilla "indice" 
	// Calcula los "tope" primeros elementos de la sucesi�n.
	// NOTA: El constructor ya cre� los primeros n t�rminos 
    //		(hasta el equivalente al orden) de la sucesi�n. 
	//		Si tope <= orden, no se hace nada. 
	
	void CalculaPrimeros(int tope) 
	{
		if (tope > orden) {
			
			// Para cada valor nuevo de la serie (posici�n "pos") sumar los 
			// "orden" anteriores valores de la serie.  

			for (int pos=orden; pos<tope; pos++) {

				int suma = 0;
				for (int i=1; i<=orden; i++) 
					suma += vector_privado[pos-i];

				// guardar el nuevo valor y actualizar "total_utilizados"

				vector_privado.push_back(suma); // vector_privado[pos] = suma;  											 

			} // for pos

		} // if (tope > orden) 
	}

	/*****************************************************************/
	// Devuelve el elemento de la casilla "indice" 
	// PRE: la posici�n dada por "indice" es correcta.
	// Si no es correcta,el comportamiento no est� definido.

	int Elemento(int indice)
	{
		return vector_privado[indice];
	}

	/*****************************************************************/

};

///////////////////////////////////////////////////////////////////////

/*********************************************************************/

int main()
{

	// Creaci�n de la serie de orden 3 con el m�nimo n�mero de valores, 
	// tal como est� dise�ado el constructor 

	Fibonacci fib (3);

	cout << "Creada una serie de Fibonacci de orden " << fib.GetOrden() 
		 << " (Contiene " << fib.TotalCalculados() << " valores)" << endl; 

	cout  << "Serie inmediatamente despu�s de crearse: " << endl; 
	cout << endl; 

	int tope_fib = fib.TotalCalculados();

	for (int i=0; i<tope_fib; i++)
		cout << fib.Elemento(i) << " ";

	cout << endl << endl << endl << endl; 



	// Creaci�n de la serie de orden 4 y generaci�n de los 10 primeros 
	// t�rminos de la serie 

	int n = 4; // orden 

	Fibonacci f(n); // Creaci�n de la serie -> constructor

	cout << "Creada una serie de Fibonacci de orden " << f.GetOrden() 
		 << " (Contiene " << f.TotalCalculados() << " valores)" << endl; 

	cout  << "Serie inmediatamente despu�s de crearse: " << endl; 
	cout << endl; 

	int tope_f = f.TotalCalculados();

	for (int i=0; i<tope_f; i++)
		cout << f.Elemento(i) << " ";

	cout << endl << endl;

	// Calcular los k primeros valores.  

	int k = 10; // N�mero de valores 

	f.CalculaPrimeros(k);

	cout  << "Despu�s de calcular los primeros " << k << " valores" 
		 << " (Contiene " << f.TotalCalculados() << " valores)" << endl; 
	cout << endl; 

	tope_f = f.TotalCalculados();	// Debe recalcularse

	for (int i=0; i<tope_f; i++)
		cout << f.Elemento(i) << " ";
	
	cout << endl << endl << endl << endl; 



	// Creaci�n de la serie de orden 6 y generaci�n de los 10 primeros 
	// t�rminos de la serie 

	Fibonacci fib6 (6); // Creaci�n de la serie -> constructor

	cout << "Creada una serie de Fibonacci de orden " << fib6.GetOrden() 
		 << " (Contiene " << fib6.TotalCalculados() << " valores)" << endl; 

	cout  << "Serie inmediatamente despu�s de crearse: " << endl; 
	cout << endl; 

	int tope_fib6 = fib6.TotalCalculados();

	for (int i=0; i<tope_fib6; i++)
		cout << fib6.Elemento(i) << " ";

	cout << endl << endl;


	// Calcular los k primeros valores.  

	int k_fib6 = 10; // N�mero de valores 

	fib6.CalculaPrimeros(k_fib6);


	cout  << "Despu�s de calcular los primeros " << k_fib6 << " valores" 
		 << " (Contiene " << fib6.TotalCalculados() << " valores)" << endl; 
	cout << endl; 


	tope_fib6 = fib6.TotalCalculados(); // Debe recalcularse

	for (int i=0; i<tope_fib6; i++)
		cout << fib6.Elemento(i) << " ";

	cout << endl; 


	cout << "\n\n";
	system ("pause");
}