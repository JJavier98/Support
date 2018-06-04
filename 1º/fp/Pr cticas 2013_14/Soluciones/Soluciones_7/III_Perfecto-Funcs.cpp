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
// EJERCICIO 12
/*	
	Un n�mero perfecto es aquel que es igual a la suma de todos sus 
	divisores positivos excepto �l mismo. 
	Por ejemplo, el primer n�mero perfecto es el 6 ya que sus divisores 
	son 1, 2 y 3 y 6=1+2+3. 
	
	Este programa calcula el mayor n�mero perfecto que es menor 
	que un entero k introducido desde teclado.

	Entradas: Un n�mero entero, k
	Salidas:  El mayor n�mero perfecto menor que k
*/
/*********************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/*********************************************************************/
// Funci�n que calcula si un n�mero "a" divide a otro "b"

bool EsDivisor (int a, int b)
{
	return (b % a == 0); // TRUE si a es divisor de b
}

/*********************************************************************/
// Funci�n que calcula si un n�mero n es perfecto

bool EsPerfecto (int n)
{
	bool es_perfecto;

	int suma = 0;
	int divisor = 1;   // Primer divisor a tener en cuenta 
	int ultimo = n/2;  // Ultimo valor a probar como divisor tentativo 
	
	while (divisor <= ultimo) { 

		if (EsDivisor(divisor, n)) // Si es divisor, se suma
			suma += divisor; 

		divisor++; // Prueba con el siguiente
	}

	if (suma == n) // Condici�n para ser un n�mero perfecto
		es_perfecto = true;
	else
		es_perfecto = false;
	
	return (es_perfecto);
}

/*********************************************************************/

int main()
{
	int	k; 

	cout << "\nIntroduzca un entero: ";
	cin >> k;

	int i=k-1;	// Buscamos el mayor n�mero perfecto MENOR que k 
				// Si quisi�ramos menor o igual, escribimos  int i=k;

	bool encontrado = false;	// Ser� TRUE cuando encuentre un numero perfecto.
								// OJO: No buscamos TODOS los n�meros perfectos, 
								// solo el mayor entre todos los menores que k

	while ((i>1) && (!encontrado)) { // Terminar cuando se encuentre un n�mero
									 // perfecto o al llegar a 1 (no hay). 
		if (EsPerfecto (i))
			encontrado = true;  // para terminar
		else 
			i--; // probar con el anterior
	}

	if (encontrado) 
		cout << "\nEl mayor n�mero perfecto menor que " << setw(4) << k 
			 << " es " << setw(4) << i << "\n";
	else 
		cout << "\nNo hay ning�n n�mero perfecto menor que " 
			 <<setw(4)<< k << "\n";

	cout << "\n\n";
	system("pause");
}