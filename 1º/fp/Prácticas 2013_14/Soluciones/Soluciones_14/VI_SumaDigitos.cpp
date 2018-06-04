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
// EJERCICIO 1 
//
/*	
	Calcula la suma de los dígitos de un entero positivo empleando una 
	función recursiva
*/
/*********************************************************************/

#include <iostream>
using namespace std;

/*********************************************************************/

int SumaDigitos(unsigned int n){
   
	/*
	Caso base: Si n tiene un dígito (0..9), la solución es el mismo n
	Caso general: 
		n es la suma de dos números, resultantes de "partir" n:
			1)	el dígito menos significativo, el último de n (n%10)
			2)	la suma de los dígitos que forman la primera parte de n, 
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

		cout << "\tLa suma de sus dígitos es = "; 
		cout << SumaDigitos(numero) << endl;
		cout << endl;

		cout << "Introduce un entero (terminar con un negativo) --> "; 
		cin >> numero; 
	}

	cout << "\n\n";
	system("pause");
	return (0);
}
