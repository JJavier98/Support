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
// EJERCICIO 13
//
/*	
   Programa que lee un carácter (mayúscula), lo pasa a minúscula y lo imprime.
   No pueden usarse las funciones toupper() ni tolower() de la biblioteca cctype. 
   
   Entradas: caracter en mayúscula
   Salidas:  caracter en minúscula

   La tranformación debe realizarse considerando la equivalencia char - int
*/
/*********************************************************************/

#include <iostream>
using namespace std;

int main(){
   
	char letra_minuscula; // Entrada
	char letra_mayuscula; // Salida

	cout << "\nIntroduzca una letra mayúscula  --> ";
	cin >> letra_mayuscula;

	/*
	Las mayúsculas están antes que las minúsculas en la tabla ASCII.
	Además, sabemos que hay el mismo número de mayúsculas que de
	minúsculas y obviamente se encuentran en el mismo orden. Por
	tanto, sólo necesitamos saber cuantos caracteres hay entre
	'A' y 'a'.

	El orden de 'A' es 65 y el de 'a' 97. 
	Por tanto, hay 97-65 = 32 caracteres entre ellos. 
	Así pues, bastaría hacer 
   
		letra_minuscula = letra_mayuscula + 32   
   
	El problema es que debo conocer el número "mágico" 32
	*/
	
	letra_minuscula = letra_mayuscula + 32;      // :-(
   
	cout << "\nEl carácter " << letra_mayuscula  
         << " pasado a minúscula es: " << letra_minuscula;
	cout << "\n\n";


	/*
	El número de caracteres que hay entre 'A' y 'a' puede calcularse con 
	la expresión (int) 'a'-'A', que devuelve 32.
	Observe que 'a'-'a' es 0, 'b'-'a' es 1, ...
	*/

	const int DISTANCIA_MAY_MIN = 'a'-'A';    // :-)
  

	letra_minuscula = letra_mayuscula + DISTANCIA_MAY_MIN;      // :-)
   
	cout << "\nEl carácter " << letra_mayuscula  
         << " pasado a minúscula es: " << letra_minuscula;
	cout << "\n\n";

	system("pause");
}
