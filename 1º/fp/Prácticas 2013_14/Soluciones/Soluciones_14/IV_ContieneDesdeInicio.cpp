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
// EJERCICIO 6 
//
/*	
	En este programa se demuestra el uso de la función RECURSIVA:
	
		bool ContieneDesdeInicio (string cadena_grande, string cadena_peque)

	que compruebe si la cadena "cadena_peque" se encuentra al inicio de 
	la cadena "cadena_grande" (desde la posición cero)

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

/*********************************************************************/
/*********************************************************************/

int main()
{

	cout << "ContieneDesdeInicio(\"hhhola\", \"hh\") --> ";
	if (ContieneDesdeInicio("hhhola", "hh"))
		cout << "SI";
	else
		cout << "NO";
	cout << endl << endl;	 
   
   /*************/

	cout << "ContieneDesdeInicio(\"\", \"hh\") --> ";
	if (ContieneDesdeInicio("", "hh"))
		cout << "SI";
	else
		cout << "NO";
	cout << endl << endl;	 

	/*************/

   cout << "ContieneDesdeInicio(\"hhhola\", \"\") --> ";
   if (ContieneDesdeInicio("hhhola", ""))
		cout << "SI";
	else
		cout << "NO";
	cout << endl << endl;	 
   
   /*************/

	cout << "ContieneDesdeInicio(\"hhhola\", \"hhhh\") --> ";
	if (ContieneDesdeInicio("hhhola", "hhhh"))
		cout << "SI";
	else
		cout << "NO";
	cout << endl << endl;	 
   
   /*************/

	cout << "\n\n";
	system ("pause");

	return (0);
}