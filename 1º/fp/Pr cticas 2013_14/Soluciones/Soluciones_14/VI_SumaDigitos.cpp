/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
// GRADO EN INGENIER�A INFORM�TICA
//
// CURSO 2013-2014
// (C) JUAN CARLOS CUBERO TALAVERA
// (C) FRANCISCO JOS� CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACI�N E INTELIGENCIA ARTIFICIAL
//
// RELACI�N DE PROBLEMAS VI
// EJERCICIO 1 
//
/*	
	Calcula la suma de los d�gitos de un entero positivo empleando una 
	funci�n recursiva
*/
/*********************************************************************/

#include <iostream>
using namespace std;

/*********************************************************************/

int SumaDigitos(unsigned int n){
   
	/*
	Caso base: Si n tiene un d�gito (0..9), la soluci�n es el mismo n
	Caso general: 
		n es la suma de dos n�meros, resultantes de "partir" n:
			1)	el d�gito menos significativo, el �ltimo de n (n%10)
			2)	la suma de los d�gitos que forman la primera parte de n, 
				lo que queda tras quitar "n" (n/10)
		
		Por ejemplo: S(1234) = 4+S(123), S(1230) = 0+S(123), S(12) = 2+S(1) 

	*/
   
	if (n < 10)
		return (n);
	else
		return (n%10 + SumaDigitos(n/10));
}


/*********************************************************************/
/*********************************************************************/

int main()
{   
	int numero; 

	cout << "Introduce un entero (terminar con un negativo) --> "; 
	cin >> numero; 

	while (numero >= 0) {

		cout << "\tLa suma de sus d�gitos es = "; 
		cout << SumaDigitos(numero) << endl;
		cout << endl;

		cout << "Introduce un entero (terminar con un negativo) --> "; 
		cin >> numero; 
	}

	cout << "\n\n";
	system("pause");
	return (0);
}
