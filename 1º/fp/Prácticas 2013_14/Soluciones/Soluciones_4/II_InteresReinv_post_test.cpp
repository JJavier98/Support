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
// EJERCICIO 17-b
//
/*	
	El ejercicio 11 se calculaba el dinero que se obtiene al realizar una 
	inversión un número dado de años. En este programa se modifica la 
	solución, proponiéndose la sustitución del bucle while por un do-while. 
	
	PRECAUCIÓN: debemos considerar el caso en el que el número de años 
	leído fuese cero.
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
   
	do{

		if (anio <= numero_anios) { //  <-   DUPLICA CÓDIGO :-(((    
									// Preferimos la versión pre-test

			// Nuevo capital pasado un año
			capital_acumulado = capital_acumulado  +  
		                   (capital_acumulado * (interes / 100.0));   

			// No es preciso mostrar esta información, pero ayuda a entender
			cout << "\nCapital obtenido transcurrido el año número " 
				 << setw(2)  << anio << " = " 
				 << setw(10) << setprecision(2) << capital_acumulado;   

			anio++; // actualizar el año de inversión 
		}

	} while (anio <= numero_anios);

   cout << "\n\n";
   system("pause");
}