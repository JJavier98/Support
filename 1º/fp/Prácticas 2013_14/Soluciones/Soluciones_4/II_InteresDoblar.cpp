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
// EJERCICIO 12
/*	
   Programa que calcula el numero de años que han de transcurrir para 
   doblar el capital invertido.
   Ampliación de los problemas: 2 de la Relación de Ejercicios I y 
   11 de la Relación de Ejercicios II. 

   Entradas: capital a invertir (capital_inicial)
			 interés a aplicar (interes)
   Salidas:  número de años que deben pasart para doblar capital_inicial

			 El cálculo del capitalk acumulado anualmente se hace por: 
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
	   
	// Salidas
	int numero_anios;
  
	// Auxiliares 
	double capital_acumulado, cuantia_final_a_conseguir;
   

	cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales 


	cout << "Introduzca capital inicial --> ";
	cin >> capital_inicial;
	cout << "\nIntroduzca interés (como un %) --> ";
	cin >> interes;   
   

	capital_acumulado = capital_inicial; // Capital inicial
	cuantia_final_a_conseguir = capital_inicial * 2; // Objetivo

	numero_anios  = 0; // contador de años 
   
	while (capital_acumulado < cuantia_final_a_conseguir) {

		numero_anios++; // Ha pasado un nuevo año sin alcanzar el objetivo 

		// Nuevo capital pasado un año
		capital_acumulado = capital_acumulado  +  
		                   (capital_acumulado * (interes / 100.0));   

		// No es preciso mostrar esta información, pero ayuda a entender
		cout << "\nCapital obtenido transcurrido el año número " 
			 << setw(2)  << numero_anios << " = " 
			 << setw(10) << setprecision(2) << capital_acumulado;   

   }
  
	cout << "\n\nPara doblar la cantidad inicial han de pasar " 
		  << numero_anios << " años";
 
	cout << "\n\n";
	system("pause");
}
