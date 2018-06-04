/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
// GRADO EN INGENIERÍA INFORMÁTICA
//
// CURSO 2013-2014
// (C) JUAN CARLOS CUBERO TALAVERA
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS VI
// EJERCICIO 4 
//
/*	
	Programa que usa la función recursiva:

	int k_esimo (int n, int k);

	que devuelve el valor del dígito k-ésimo comenzando por la derecha del 
	número n. Por ejemplo, k_esimo (427, 3) = 4
	Si k es mayor que el número de dígitos de n la función devolverá el valor 0. 
	Por ejemplo, k_esimo (23, 5) = 0.
*/

/*********************************************************************/

#include <iostream>
using namespace std;

/*********************************************************************/
// Devuelve el valor del dígito k-ésimo, comenzando por la derecha, 
// del número n
// PRE: n >=0 y k > 0

int k_esimo (int n, int k)
{
   /*
      Caso base:	El 1-ésimo dígito de cualquier "n" es n%10
      Caso general: La solución es la misma que calcular el (k-1)-ésimo 
					dígito de n/10 ("quitándole" a "n" el último dígito) 
   */

	if (k == 1)
		return (n % 10); // el dígito menos significativo
	else
		return k_esimo (n/10, k-1); // Buscar el (k-1)-ésimo dígito de n/10
}

/*********************************************************************/
/*********************************************************************/

int main()
{   
	int numero, orden; 

	cout << "Introduce un número (terminar con un negativo) --> "; 
	cin >> numero; 
	// Solo se pide el orden si el número es válido
	if (numero >= 0) {
		cout << "Introduce el orden k (terminar con un negativo o cero) --> "; 
		cin >> orden; 
	}

	while ((numero>=0) && (orden>0)) {

		cout << "\tEl dígito " << orden << "-ésimo de " << numero << " es = "; 
		cout << k_esimo (numero, orden) << endl;

		cout << endl;

		cout << "Introduce un número (terminar con un negativo) --> "; 
		cin >> numero; 
		// Solo se pide el orden si el número es válido
		if (numero >= 0) {
			cout << "Introduce el orden k (terminar con un negativo o cero) --> "; 
			cin >> orden; 
		}

	} // while ((numero>=0) && (orden>0)) 

	cout << "\n\n";
	system("pause");
	return (0);
}