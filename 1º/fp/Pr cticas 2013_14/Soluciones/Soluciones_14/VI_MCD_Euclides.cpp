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
// EJERCICIO 5 
//
/*	
	Programa que calcula el m�ximo com�n divisor de dos n�meros empleando 
	el algoritmo de Euclides: 
		MCD (a, 0) = a
		MCD (a, b) = MCD (b, a%b)

	El c�lculo del MCD se realiza en una funci�n recursiva: 

		int MCD (int un_entero, int otro_entero); 
*/
/*********************************************************************/

#include <iostream>
using namespace std;

/*********************************************************************/
// Calcula el m�ximo com�n divisor de dos n�meros enteros empleando 
// el algoritmo de Euclides:   
//		MCD (a, 0) = a
//		MCD (a, b) = MCD (b, a%b)

int MCD(int un_entero, int otro_entero)
{
	if (otro_entero == 0)

		return un_entero;  // Caso base 
	else

		return MCD (otro_entero, un_entero%otro_entero);
}

/*********************************************************************/
/*********************************************************************/

int main()
{   
	int numero1, numero2; 

	cout << "C�lculo del m�ximo com�n divisor de dos n�meros\n\n"; 

	cout << "Introduce el primer n�mero (terminar con un negativo) --> "; 
	cin >> numero1; 
	// Solo se pide el segundo si el primero es v�lido
	if (numero1 >= 0) {
		cout << "Introduce el segundo n�mero (terminar con un negativo) --> "; 
		cin >> numero2; 
	}

	while ((numero1>=0) && (numero2>=0)) {

		cout << "\tMCD (" << numero1 << ", " << numero2 << ") = "; 
		cout << MCD (numero1, numero2) << endl;

		cout << endl;

		cout << "Introduce el primer n�mero (terminar con un negativo) --> "; 
		cin >> numero1; 
		// Solo se pide el segundo si el primero es v�lido
		if (numero1 >= 0) {
			cout << "Introduce el segundo n�mero (terminar con un negativo) --> "; 
			cin >> numero2; 
		}

	} // while ((numero1>=0) && (numero2>=0)) 

	cout << "\n\n";
	system("pause");

	return (0);
}