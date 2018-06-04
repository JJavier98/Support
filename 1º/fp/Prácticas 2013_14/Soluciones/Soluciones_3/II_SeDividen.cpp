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
// EJERCICIO 3
/*	

	Programa que lee dos valores enteros desde teclado y dice si
	cualquiera de ellos divide o no (de forma entera) al otro. 
	No hace falta decir quién divide a quién.

	Entradas: los dos valores (int) 
	Salidas: Un mensaje: "Uno divide al otro" ó "Ninguno divide al otro"
*/
/*********************************************************************/

#include <iostream>
using namespace std;

int main()
{
   int num1, num2;            
   
	// Entrada de datos

   cout << "\nIntroduzca primer valor ";      
   cin >> num1;                           
   cout << "\nIntroduzca segundo valor ";      
   cin >> num2;                          

	// Cómputos y Salida de Resultados 

   if ((num1 % num2 == 0) || (num2 % num1 == 0))
      cout << "\nUno divide al otro";
   else
      cout << "\nNinguno divide al otro";

	cout << "\n\n";

	system("pause");
}