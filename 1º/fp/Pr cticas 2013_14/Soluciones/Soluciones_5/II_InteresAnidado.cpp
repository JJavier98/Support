/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
// GRADO EN INGENIER�A INFORM�TICA
//
// CURSO 2012-2013
// (C) JUAN CARLOS CUBERO TALAVERA
// (C) FRANCISCO JOS� CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACI�N E INTELIGENCIA ARTIFICIAL
//
// RELACI�N DE PROBLEMAS 2
// EJERCICIO 23
/*	
   Programa que calcula el dinero que se obtiene al realizar una 
   inversi�n un n�mero dado de a�os y con diferentes tipos de inter�s.

   Entradas: capital a invertir (capital_inicial)
			 inter�s m�ximo a aplicar (interes)
			 n�mero de a�os m�ximo de la inversi�n (numero_anios)
   Salidas:  dinero total obtenido por la inversi�n 
			 (capital + ganancia obtenida) calculado -anualmente- por: 
				total = capital + (capital * interes/100)
			  reinvirtiendo cada a�o el nuevo total y con diferentes 
			  tipos de inter�s.
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
	double interes_actual;


	cout.setf(ios::fixed);		// Notaci�n de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales 


	cout << "Introduzca capital inicial --> ";
	cin >> capital_inicial;
	cout << "\nIntroduzca n�mero de a�os --> ";
	cin >> numero_anios;
	cout << "\nIntroduzca inter�s (como un %) --> ";
	cin >> interes;   
   

	for (interes_actual=1.0; interes_actual <= interes ; interes_actual++) {

		cout << "\n\nResultados calculados para un inter�s del " 
			 << setw (3) << setprecision(2) << interes_actual << "% =\n";
		cout << "Capital inicial: " 
			 << setw(10) << setprecision(2) << capital_inicial;

		// Importante: la asignaci�n siguiente es necesaria 
		// antes de entrar al ciclo de los a�os
		
		capital_acumulado = capital_inicial; // Capital inicial
	
		for (anio=1 ; anio <= numero_anios; anio++) {

			capital_acumulado = capital_acumulado  +  
		                   (capital_acumulado * (interes_actual / 100.0)); 

			cout << "\nCapital obtenido transcurrido el a�o n�mero " 
				 << setw(2)  << anio << " = " 
			     << setw(10) << setprecision(2) << capital_acumulado;    
		}
	}
   
   cout << "\n\n";
   system("pause");

}
