/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
// GRADO EN INGENIERÍA INFORMÁTICA
//
// CURSO 2013-2014
// (C) JUAN CARLOS CUBERO TALAVERA
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 3
// EJERCICIO 12
/*	
	Un número perfecto es aquel que es igual a la suma de todos sus 
	divisores positivos excepto él mismo. 
	Por ejemplo, el primer número perfecto es el 6 ya que sus divisores 
	son 1, 2 y 3 y 6=1+2+3. 
	
	Este programa calcula el mayor número perfecto que es menor 
	que un entero k introducido desde teclado.

	Entradas: Un número entero, k
	Salidas:  El mayor número perfecto menor que k
*/
/*********************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/*********************************************************************/
// Función que calcula si un número "a" divide a otro "b"

bool EsDivisor (int a, int b)
{
	return (b % a == 0); // TRUE si a es divisor de b
}

/*********************************************************************/
// Función que calcula si un número n es perfecto

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

	if (suma == n) // Condición para ser un número perfecto
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

	int i=k-1;	// Buscamos el mayor número perfecto MENOR que k 
				// Si quisiéramos menor o igual, escribimos  int i=k;

	bool encontrado = false;	// Será TRUE cuando encuentre un numero perfecto.
								// OJO: No buscamos TODOS los números perfectos, 
								// solo el mayor entre todos los menores que k

	while ((i>1) && (!encontrado)) { // Terminar cuando se encuentre un número
									 // perfecto o al llegar a 1 (no hay). 
		if (EsPerfecto (i))
			encontrado = true;  // para terminar
		else 
			i--; // probar con el anterior
	}

	if (encontrado) 
		cout << "\nEl mayor número perfecto menor que " << setw(4) << k 
			 << " es " << setw(4) << i << "\n";
	else 
		cout << "\nNo hay ningún número perfecto menor que " 
			 <<setw(4)<< k << "\n";

	cout << "\n\n";
	system("pause");
}