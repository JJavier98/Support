/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
// GRADO EN INGENIER�A INFORM�TICA
//
// CURSO 2012-2013
// (C) JUAN CARLOS CUBERO TALAVERA
// (C) FRANCISCO JOS� CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACI�N E INTELIGENCIA ARTIFICIAL
//
// RELACI�N DE PROBLEMAS 1
// EJERCICIO 13
//
/*	
   Programa que lee un car�cter (may�scula), lo pasa a min�scula y lo imprime.
   No pueden usarse las funciones toupper() ni tolower() de la biblioteca cctype. 
   
   Entradas: caracter en may�scula
   Salidas:  caracter en min�scula

   La tranformaci�n debe realizarse considerando la equivalencia char - int
*/
/*********************************************************************/

#include <iostream>
using namespace std;

int main(){
   
	char letra_minuscula; // Entrada
	char letra_mayuscula; // Salida

	cout << "\nIntroduzca una letra may�scula  --> ";
	cin >> letra_mayuscula;

	/*
	Las may�sculas est�n antes que las min�sculas en la tabla ASCII.
	Adem�s, sabemos que hay el mismo n�mero de may�sculas que de
	min�sculas y obviamente se encuentran en el mismo orden. Por
	tanto, s�lo necesitamos saber cuantos caracteres hay entre
	'A' y 'a'.

	El orden de 'A' es 65 y el de 'a' 97. 
	Por tanto, hay 97-65 = 32 caracteres entre ellos. 
	As� pues, bastar�a hacer 
   
		letra_minuscula = letra_mayuscula + 32   
   
	El problema es que debo conocer el n�mero "m�gico" 32
	*/
	
	letra_minuscula = letra_mayuscula + 32;      // :-(
   
	cout << "\nEl car�cter " << letra_mayuscula  
         << " pasado a min�scula es: " << letra_minuscula;
	cout << "\n\n";


	/*
	El n�mero de caracteres que hay entre 'A' y 'a' puede calcularse con 
	la expresi�n (int) 'a'-'A', que devuelve 32.
	Observe que 'a'-'a' es 0, 'b'-'a' es 1, ...
	*/

	const int DISTANCIA_MAY_MIN = 'a'-'A';    // :-)
  

	letra_minuscula = letra_mayuscula + DISTANCIA_MAY_MIN;      // :-)
   
	cout << "\nEl car�cter " << letra_mayuscula  
         << " pasado a min�scula es: " << letra_minuscula;
	cout << "\n\n";

	system("pause");
}
