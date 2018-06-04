/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
// GRADO EN INGENIER�A INFORM�TICA
//
// CURSO 2013-2014
// (C) JUAN CARLOS CUBERO TALAVERA
// (C) FRANCISCO JOS� CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACI�N E INTELIGENCIA ARTIFICIAL
//
// RELACI�N DE PROBLEMAS 2
// EJERCICIO 17-b
//
/*	
	El ejercicio 11 se calculaba el dinero que se obtiene al realizar una 
	inversi�n un n�mero dado de a�os. En este programa se modifica la 
	soluci�n, proponi�ndose la sustituci�n del bucle while por un do-while. 
	
	PRECAUCI�N: debemos considerar el caso en el que el n�mero de a�os 
	le�do fuese cero.
*/
/*********************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	// Entradas: 
	double interes, capital_inicial;
	int numero_anios;
	   
	// Salidas
	double capital_acumulado;
  
	// Auxiliares 
	int anio;
   
	cout.setf(ios::fixed);		// Notaci�n de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales 

	cout << "Introduzca capital inicial --> ";
	cin >> capital_inicial;
	cout << "\nIntroduzca n�mero de a�os --> ";
	cin >> numero_anios;
	cout << "\nIntroduzca inter�s (como un %) --> ";
	cin >> interes;   
   
	capital_acumulado = capital_inicial; // Capital inicial
	
	anio  = 1; // contador de a�os 
   
	do{

		if (anio <= numero_anios) { //  <-   DUPLICA C�DIGO :-(((    
									// Preferimos la versi�n pre-test

			// Nuevo capital pasado un a�o
			capital_acumulado = capital_acumulado  +  
		                   (capital_acumulado * (interes / 100.0));   

			// No es preciso mostrar esta informaci�n, pero ayuda a entender
			cout << "\nCapital obtenido transcurrido el a�o n�mero " 
				 << setw(2)  << anio << " = " 
				 << setw(10) << setprecision(2) << capital_acumulado;   

			anio++; // actualizar el a�o de inversi�n 
		}

	} while (anio <= numero_anios);

   cout << "\n\n";
   system("pause");
}