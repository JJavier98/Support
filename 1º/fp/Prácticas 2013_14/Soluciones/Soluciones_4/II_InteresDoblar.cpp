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
// EJERCICIO 12
/*	
   Programa que calcula el numero de a�os que han de transcurrir para 
   doblar el capital invertido.
   Ampliaci�n de los problemas: 2 de la Relaci�n de Ejercicios I y 
   11 de la Relaci�n de Ejercicios II. 

   Entradas: capital a invertir (capital_inicial)
			 inter�s a aplicar (interes)
   Salidas:  n�mero de a�os que deben pasart para doblar capital_inicial

			 El c�lculo del capitalk acumulado anualmente se hace por: 
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
	   
	// Salidas
	int numero_anios;
  
	// Auxiliares 
	double capital_acumulado, cuantia_final_a_conseguir;
   

	cout.setf(ios::fixed);		// Notaci�n de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales 


	cout << "Introduzca capital inicial --> ";
	cin >> capital_inicial;
	cout << "\nIntroduzca inter�s (como un %) --> ";
	cin >> interes;   
   

	capital_acumulado = capital_inicial; // Capital inicial
	cuantia_final_a_conseguir = capital_inicial * 2; // Objetivo

	numero_anios  = 0; // contador de a�os 
   
	while (capital_acumulado < cuantia_final_a_conseguir) {

		numero_anios++; // Ha pasado un nuevo a�o sin alcanzar el objetivo 

		// Nuevo capital pasado un a�o
		capital_acumulado = capital_acumulado  +  
		                   (capital_acumulado * (interes / 100.0));   

		// No es preciso mostrar esta informaci�n, pero ayuda a entender
		cout << "\nCapital obtenido transcurrido el a�o n�mero " 
			 << setw(2)  << numero_anios << " = " 
			 << setw(10) << setprecision(2) << capital_acumulado;   

   }
  
	cout << "\n\nPara doblar la cantidad inicial han de pasar " 
		  << numero_anios << " a�os";
 
	cout << "\n\n";
	system("pause");
}
