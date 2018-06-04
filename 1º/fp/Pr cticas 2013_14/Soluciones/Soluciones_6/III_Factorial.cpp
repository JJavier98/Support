/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
// GRADO EN INGENIER�A INFORM�TICA
//
// CURSO 2013-2014
// (C) JUAN CARLOS CUBERO TALAVERA
// (C) FRANCISCO JOS� CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACI�N E INTELIGENCIA ARTIFICIAL
//
// RELACI�N DE PROBLEMAS 3
// EJERCICIO 3
//
/*	
	Programa que calcula el factorial y la funci�n potencia, 
	modularizando estas operaciones con sendas funciones.

	Ampliaci�n del ejercicio 15 de la Relaci�n de Problemas 2

	Entradas: Para el factorial: Un n�mero entero 
			  Para la potencia, dos n�meros enteros: base y exponente. 
	Salidas:  Los valores calculados. 
*/
/*********************************************************************/

#include <iostream>
using namespace std;

/*********************************************************************/

__int64 Factorial (int n) {

	// C�lculo del factorial 
	// n! = n * (n-1) * (n-2) * ... * 1 si n>1
	// 0! = 1! = 1 

	__int64 factorial;	// OJO: el tipo permite gestionar enteros "grandes"
						// El dato local "factorial" no debe confundirse con
						// la funci�n "Factorial"
	int multiplicando;

	factorial = 1;

	for (multiplicando = 2; multiplicando <=n ; multiplicando++)
		factorial = factorial * multiplicando;

	return (factorial);
}

/*********************************************************************/

__int64 Potencia (int base, int exponente) {

	// C�lculo de la potencia
	// x^n = x * x * ... * x si n>1
	// x^1 = x 
	// x^0 = 1 

	__int64 potencia;	// OJO: el tipo permite gestionar enteros "grandes"
						
	int i;	

	potencia = 1;

	for (i = 1; i <= exponente; i++) 
		potencia = potencia * base;  

	// Observad que si exponente fuese cero, la variable potencia se quedar�a 
	// con 1, lo que es correcto ya que base elevado a 0 es siempre 1

	return (potencia);
}

/*********************************************************************/

int main()
{
	/////////////////////////////////////////////////////////////
	// Factorial
	/////////////////////////////////////////////////////////////

		int n;		// Entrada
	__int64 fact_n; // Salida: n!


	cout << "\nIntroduzca un entero positivo: ";
	cin >> n;

	fact_n = Factorial(n); // Llamada a la funci�n
						   // En este caso el resultado del c�lculo 
						   // se ha guardado en una variable.

	cout << "\n" << n << "! = " << fact_n;

	/////////////////////////////////////////////////////////////
	// Potencia
	/////////////////////////////////////////////////////////////

	int base, exponente;

	cout << "\n\nIntroduzca la base: ";
	cin >> base;
	cout << "\nIntroduzca el exponente: ";
	cin >> exponente;

	cout << "\n" << base << "^" << exponente 
		 << " = " << Potencia (base, exponente);

	// En este caso se llama a la funci�n justo antes de mostrar el 
	// resultado y �ste no se almacena: una vez enviado a cout ya no 
	// estar� disponible, y en el caso de necesitarse deber� volverse 
	// a llamar a la funci�n.

	/////////////////////////////////////////////////////////////

	cout << "\n\n";
	system("pause");
}