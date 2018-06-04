/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
// GRADO EN INGENIERÍA INFORMÁTICA
//
// CURSO 2013-2014
// (C) JUAN CARLOS CUBERO TALAVERA
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS VI
// EJERCICIO 7 
//
/*	
	En este programa se demuestra el uso de la función RECURSIVA:
	
		bool Contiene (string cadena_grande, string cadena_peque)

	que compruebe si la cadena "cadena_peque" se encuentra dentro de  
	la cadena "cadena_grande" (desde cualquier posición). Esta función 
	hace uso de la función "ContieneDesde()" que se empleó en el 
	ejercicio 6 de la Relación de Problemas VI.

*/
/*********************************************************************/

#include <iostream>
#include <string>

using namespace std;

/*********************************************************************/

bool ContieneDesdeInicio(string cadena_grande, string cadena_peque)
{
	/*
	Casos base:
		1)	Una "cadena_peque" de longitud cero está 
			<incluida desde el inicio> en cualquier "cadena_grande"
		2)	Una "cadena_grande" de longitud cero no 
			<contiene desde el inicio> a ninguna "cadena_peque"
		3)	Si los dos primeros caracteres de las cadenas son distintos, 
		ninguna <contiene desde el inicio> a la otra
   
	Caso General:
		Si los dos primeros caracteres de las cadenas son iguales, podemos
		continuar. La solución será la del problema de ver si 
		"cadena_grande" menos el primer carácter <contiene desde el inicio>
		a "cadena_peque" menos el primer carácter.
   */

	if (cadena_peque.length() == 0)  // Caso base 1
	
		return true;

	else 
		
		if (cadena_grande.length() == 0) // Caso base 2
		
			return false;

		else 
			
			if (cadena_peque.at(0) != cadena_grande.at(0)) // Caso base 3
		
				return false;

			else // Caso general

				return ContieneDesdeInicio (cadena_grande.erase(0,1), 
											 cadena_peque.erase(0,1));
}
/***************************************************************************/

bool Contiene(string cadena_grande, string cadena_peque)
{
	/*
	Casos base:
		1)	Una "cadena_peque" de longitud cero está 
			<incluida> en cualquier "cadena_grande"
		2)	Una "cadena_grande" de longitud cero no 
			<contiene> a ninguna "cadena_peque"
		3)	Si "cadena_grande" <contiene desde el inicio> a "cadena_peque", 
			entonces la contiene
   
	Caso General:
		Si "cadena_grande" no <contiene desde el inicio> a "cadena_peque", 
		entonces la solución es la misma que la del problema de ver si 
		"cadena_grande" menos el primer carácter <contiene> a 
		"cadena_peque".
   */

	bool contiene = false;

	if (cadena_peque.length() == 0) // Caso base 1

		return true;
	
	else 
		
		if (cadena_grande.length() == 0)  // Caso base 2

			return false;

		else 
			
			if (ContieneDesdeInicio(cadena_grande, cadena_peque)) 
		
				return true;  // Caso base 3

			else // caso general
		
				return Contiene(cadena_grande.erase(0,1), cadena_peque);
}



/*********************************************************************/
/*********************************************************************/

int main()
{

	cout << "Contiene(\"hhhola\", \"hh\") --> ";
	if (Contiene("hhhola", "hh"))
		cout << "SI";
	else
		cout << "NO";
	cout << endl << endl;	 
   
   /*************/

	cout << "Contiene(\"\", \"hh\") --> ";
	if (Contiene("", "hh"))
		cout << "SI";
	else
		cout << "NO";
	cout << endl << endl;	 

	/*************/

   cout << "Contiene(\"hhhola\", \"\") --> ";
   if (Contiene("hhhola", ""))
		cout << "SI";
	else
		cout << "NO";
	cout << endl << endl;	 
   
   /*************/

	cout << "Contiene(\"hhhola\", \"hhhh\") --> ";
	if (Contiene("hhhola", "hhhh"))
		cout << "SI";
	else
		cout << "NO";
	cout << endl << endl;	 
    
	/*************/

	cout << "Contiene(\"hhhola\", \"hola\") --> ";
	if (Contiene("hhhola", "hola"))
		cout << "SI";
	else
		cout << "NO";
	cout << endl << endl;

	/*************/

	cout << "Contiene(\"hhhola\", \"a\") --> ";
	if (Contiene("hhhola", "a"))
		cout << "SI";
	else
		cout << "NO";
	cout << endl << endl;

	/*************/

	cout << "\n\n";
	system ("pause");

	return (0);
}