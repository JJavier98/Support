/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
// GRADO EN INGENIERÍA INFORMÁTICA
//
// CURSO 2012-2013
// (C) JUAN CARLOS CUBERO TALAVERA
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 2
// EJERCICIO 23
/*	
   Programa que calcula el dinero que se obtiene al realizar una 
   inversión un número dado de años y con diferentes tipos de interés.

   Entradas: capital a invertir (capital_inicial)
			 interés máximo a aplicar (interes)
			 número de años máximo de la inversión (numero_anios)
   Salidas:  dinero total obtenido por la inversión 
			 (capital + ganancia obtenida) calculado -anualmente- por: 
				total = capital + (capital * interes/100)
			  reinvirtiendo cada año el nuevo total y con diferentes 
			  tipos de interés.
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


	cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales 


	cout << "Introduzca capital inicial --> ";
	cin >> capital_inicial;
	cout << "\nIntroduzca número de años --> ";
	cin >> numero_anios;
	cout << "\nIntroduzca interés (como un %) --> ";
	cin >> interes;   
   

	for (interes_actual=1.0; interes_actual <= interes ; interes_actual++) {

		cout << "\n\nResultados calculados para un interés del " 
			 << setw (3) << setprecision(2) << interes_actual << "% =\n";
		cout << "Capital inicial: " 
			 << setw(10) << setprecision(2) << capital_inicial;

		// Importante: la asignación siguiente es necesaria 
		// antes de entrar al ciclo de los años
		
		capital_acumulado = capital_inicial; // Capital inicial
	
		for (anio=1 ; anio <= numero_anios; anio++) {

			capital_acumulado = capital_acumulado  +  
		                   (capital_acumulado * (interes_actual / 100.0)); 

			cout << "\nCapital obtenido transcurrido el año número " 
				 << setw(2)  << anio << " = " 
			     << setw(10) << setprecision(2) << capital_acumulado;    
		}
	}
   
   cout << "\n\n";
   system("pause");

}
