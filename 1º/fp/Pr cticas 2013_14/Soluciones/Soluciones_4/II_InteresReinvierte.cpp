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
// EJERCICIO 11
/*	
   Programa que calcula el dinero que se obtiene al realizar una 
   inversi�n un n�mero dado de a�os.
   Ampliaci�n del problema 2 de la Relaci�n de Ejercicios I.

   Entradas: capital a invertir (capital_inicial)
			 inter�s a aplicar (interes)
			 n�mero de a�os de la inversi�n (numero_anios)
   Salidas:  dinero total obtenido por la inversi�n 
			 (capital + ganancia obtenida) calculado -anualmente- por: 
				total = capital + (capital * interes/100)
			  reinvirtiendo cada a�o el nuevo total.
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
   
	while (anio <= numero_anios) {

		// Nuevo capital pasado un a�o
		capital_acumulado = capital_acumulado  +  
		                   (capital_acumulado * (interes / 100.0));   

		// No es preciso mostrar esta informaci�n, pero ayuda a entender
		cout << "\nCapital obtenido transcurrido el a�o n�mero " 
			 << setw(2)  << anio << " = " 
			 << setw(10) << setprecision(2) << capital_acumulado;   

		anio++; // actualizar el a�o de inversi�n 
   }

   cout << "\n\n";
   system("pause");
}
