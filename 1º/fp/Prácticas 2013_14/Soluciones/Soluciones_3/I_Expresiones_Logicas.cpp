/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
// GRADO EN INGENIERÍA INFORMÁTICA
//
// CURSO 2012-2013
// (C) JUAN CARLOS CUBERO TALAVERA
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 1
// EJERCICIO 16
/*	
	Programa que evalúa expresiones lógicas, siendo verdad cuando: 
	* una variable de tipo carácter llamada letra es una letra minúscula.
	* una variable de tipo entero llamada edad es menor de 18 o mayor de 65.
	* una variable de tipo int llamada anio representa un año bisiesto. 
	  Los años bisiestos son aquellos que o bien son divisibles por 4 
	  pero no por 100, o bien son divisibles por 400.
*/
/*********************************************************************/


#include <iostream>
using namespace std;

int main()
{

	// Detectar minúsculas

	char letra;
	bool es_minuscula;
   
	cout << "\nIntroduzca una letra  --> ";
	cin >> letra;
   
	es_minuscula = (letra >= 'a') && (letra <= 'z');

	cout << "\n¿Minúscula? --> " << es_minuscula;
	cout << "\n\n";

	// Detectar no-activos 

	int edad;
	bool es_no_activo;

	cout << "\nIntroduzca la edad  --> ";
	cin >> edad;   
   
	es_no_activo = (edad > 65) || (edad < 18);

	cout << "\n¿No activo? --> " << es_no_activo;
	cout << "\n\n";


	// Detectar años bisiestos

   	int	anio;
	bool es_bisiesto;

	cout << "\nIntroduzca un año --> ";
	cin >> anio;

	es_bisiesto = ( (anio % 4 == 0) && (anio % 100 != 0) )   ||  (anio % 400 == 0) ;
	
	cout << "\n¿Bisiesto? --> " << es_bisiesto;
	cout << "\n\n";

	system("pause");
}
