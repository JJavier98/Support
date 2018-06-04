/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
// GRADO EN INGENIER�A INFORM�TICA
//
// CURSO 2013-2014
// (C) JUAN CARLOS CUBERO TALAVERA
// (C) FRANCISCO JOS� CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACI�N E INTELIGENCIA ARTIFICIAL
//
// RELACI�N DE PROBLEMAS VI
// EJERCICIO 4 
//
/*	
	Programa que usa la funci�n recursiva:

	int k_esimo (int n, int k);

	que devuelve el valor del d�gito k-�simo comenzando por la derecha del 
	n�mero n. Por ejemplo, k_esimo (427, 3) = 4
	Si k es mayor que el n�mero de d�gitos de n la funci�n devolver� el valor 0. 
	Por ejemplo, k_esimo (23, 5) = 0.
*/

/*********************************************************************/

#include <iostream>
using namespace std;

/*********************************************************************/
// Devuelve el valor del d�gito k-�simo, comenzando por la derecha, 
// del n�mero n
// PRE: n >=0 y k > 0

int k_esimo (int n, int k)
{
   /*
      Caso base:	El 1-�simo d�gito de cualquier "n" es n%10
      Caso general: La soluci�n es la misma que calcular el (k-1)-�simo 
					d�gito de n/10 ("quit�ndole" a "n" el �ltimo d�gito) 
   */

	if (k == 1)
		return (n % 10); // el d�gito menos significativo
	else
		return k_esimo (n/10, k-1); // Buscar el (k-1)-�simo d�gito de n/10
}

/*********************************************************************/
/*********************************************************************/

int main()
{   
	int numero, orden; 

	cout << "Introduce un n�mero (terminar con un negativo) --> "; 
	cin >> numero; 
	// Solo se pide el orden si el n�mero es v�lido
	if (numero >= 0) {
		cout << "Introduce el orden k (terminar con un negativo o cero) --> "; 
		cin >> orden; 
	}

	while ((numero>=0) && (orden>0)) {

		cout << "\tEl d�gito " << orden << "-�simo de " << numero << " es = "; 
		cout << k_esimo (numero, orden) << endl;

		cout << endl;

		cout << "Introduce un n�mero (terminar con un negativo) --> "; 
		cin >> numero; 
		// Solo se pide el orden si el n�mero es v�lido
		if (numero >= 0) {
			cout << "Introduce el orden k (terminar con un negativo o cero) --> "; 
			cin >> orden; 
		}

	} // while ((numero>=0) && (orden>0)) 

	cout << "\n\n";
	system("pause");
	return (0);
}