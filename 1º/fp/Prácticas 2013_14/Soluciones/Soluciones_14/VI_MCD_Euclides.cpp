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
// EJERCICIO 5 
//
/*	
	Programa que calcula el máximo común divisor de dos números empleando 
	el algoritmo de Euclides: 
		MCD (a, 0) = a
		MCD (a, b) = MCD (b, a%b)

	El cálculo del MCD se realiza en una función recursiva: 

		int MCD (int un_entero, int otro_entero); 
*/
/*********************************************************************/

#include <iostream>
using namespace std;

/*********************************************************************/
// Calcula el máximo común divisor de dos números enteros empleando 
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

	cout << "Cálculo del máximo común divisor de dos números\n\n"; 

	cout << "Introduce el primer número (terminar con un negativo) --> "; 
	cin >> numero1; 
	// Solo se pide el segundo si el primero es válido
	if (numero1 >= 0) {
		cout << "Introduce el segundo número (terminar con un negativo) --> "; 
		cin >> numero2; 
	}

	while ((numero1>=0) && (numero2>=0)) {

		cout << "\tMCD (" << numero1 << ", " << numero2 << ") = "; 
		cout << MCD (numero1, numero2) << endl;

		cout << endl;

		cout << "Introduce el primer número (terminar con un negativo) --> "; 
		cin >> numero1; 
		// Solo se pide el segundo si el primero es válido
		if (numero1 >= 0) {
			cout << "Introduce el segundo número (terminar con un negativo) --> "; 
			cin >> numero2; 
		}

	} // while ((numero1>=0) && (numero2>=0)) 

	cout << "\n\n";
	system("pause");

	return (0);
}