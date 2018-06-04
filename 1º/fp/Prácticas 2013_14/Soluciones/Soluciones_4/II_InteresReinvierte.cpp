/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
// GRADO EN INGENIERÍA INFORMÁTICA
//
// CURSO 2013-2014
// (C) JUAN CARLOS CUBERO TALAVERA
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 2
// EJERCICIO 11
/*	
   Programa que calcula el dinero que se obtiene al realizar una 
   inversión un número dado de años.
   Ampliación del problema 2 de la Relación de Ejercicios I.

   Entradas: capital a invertir (capital_inicial)
			 interés a aplicar (interes)
			 número de años de la inversión (numero_anios)
   Salidas:  dinero total obtenido por la inversión 
			 (capital + ganancia obtenida) calculado -anualmente- por: 
				total = capital + (capital * interes/100)
			  reinvirtiendo cada año el nuevo total.
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
   
	cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales 


	cout << "Introduzca capital inicial --> ";
	cin >> capital_inicial;
	cout << "\nIntroduzca número de años --> ";
	cin >> numero_anios;
	cout << "\nIntroduzca interés (como un %) --> ";
	cin >> interes;   
   

	capital_acumulado = capital_inicial; // Capital inicial
	
	anio  = 1; // contador de años 
   
	while (anio <= numero_anios) {

		// Nuevo capital pasado un año
		capital_acumulado = capital_acumulado  +  
		                   (capital_acumulado * (interes / 100.0));   

		// No es preciso mostrar esta información, pero ayuda a entender
		cout << "\nCapital obtenido transcurrido el año número " 
			 << setw(2)  << anio << " = " 
			 << setw(10) << setprecision(2) << capital_acumulado;   

		anio++; // actualizar el año de inversión 
   }

   cout << "\n\n";
   system("pause");
}
