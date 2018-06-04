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
// EJERCICIO 4
//
/*	
	Programa que calcula el un n�mero combinatorio  

        ( n )      n!          n(n-1)...(n-m+1) 
        (   ) = ----------- = ------------------
        ( m )    m! (n-m)!            m!

	El combinatorio de n sobre m nos da las formas posibles de elegir 
	m elementos de un total de n, sin repetici�n y sin importar el orden.
	El ejemplo t�pico es la loter�a primitiva:   
		El n�mero de combinaciones diferentes de
		49 n�meros posibles (n) tomados en grupos de      (49)   
		6 (m) sin repetici�n es el n�mero combinatorio    ( 6) 

	Ampliaci�n del ejercicio 16 de la Relaci�n de Problemas 2, 
	modularizando con funciones.

	Entradas: n y m  
	Salidas:  El valor calculado seg�n las expresiones anteriores
*/
/*********************************************************************/

#include <iostream>
using namespace std;

/*********************************************************************/
// Funci�n extraida del problema 3 de la Relaci�n de Problemas 3

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
/* Calculo del combinatorio n somre m usando la formulaci�n directa: 

        ( n )      n! 
        (   ) = -----------
        ( m )    m! (n-m)!

	PRECAUCI�N: Esta soluci�n puede producir desbordamiento incluso 
	utilizando un tipo entero tan grande como __int64. 
	(Comprobadlo con 49 y 6 (combinaciones posibles en la loter�a primitiva) 
	http://www.nitrxgen.net/factorialcalc.php
		
	49! -> Tiene 63 cifras = 608281864034267560872252163321295376887552831	
	37921024000000000060415263063373835637355132068513997507264512000000000

	Se desborda con un __int64. 
	Con un double tampoco valdr�a ya que, aunque le cupiese y no hubiese 
	desbordamiento, s�lo habr�a 16 cifras de precisi�n.
*/

__int64 Combinatorio1 (int n, int m)
{
	return (Factorial (n) / (Factorial (m)  * Factorial (n - m)));
}

/*********************************************************************/
/* Calculo del combinatorio n somre m usando la formulaci�n simplificada: 

        ( n )      n!          n(n-1)...(n-m+1) 
        (   ) = ----------- = ------------------
        ( m )    m! (n-m)!            m!
*/

__int64 Combinatorio2 (int n, int m)
{
	
	__int64 numerador = 1;
	  int   i;

	for (i = n-m+1 ; i <= n ; i++)
		numerador = numerador * i; 

	return (numerador / Factorial (m));
}

/*********************************************************************/

int main()
{
	int total_a_elegir, // n
		elegidos;		// m

	__int64 combinatorio1;	// Resultado con la versi�n 1
	__int64 combinatorio2;	// Resultado con la versi�n 2


	cout << "\n\nIntroduzca total de elementos: ";
	cin >> total_a_elegir;
	cout << "\nIntroduzca cu�ntos va a elegir del total: ";
	cin >> elegidos;

	combinatorio1 = Combinatorio1 (total_a_elegir, elegidos);
	combinatorio2 = Combinatorio2 (total_a_elegir, elegidos);

	cout << "\nVersion directa:";
	cout << "\n\tCombinaciones de " << total_a_elegir << " elementos ";
	cout << "tomados de " << elegidos << " en " << elegidos;
	cout << " = " << combinatorio1 << endl;

	cout << "\nVersion simplificada:";
	cout << "\n\tCombinaciones de " << total_a_elegir << " elementos ";
	cout << "tomados de " << elegidos << " en " << elegidos;
	cout << " = " << combinatorio2 << endl;

	cout << "\n\n";
	system("pause");
}