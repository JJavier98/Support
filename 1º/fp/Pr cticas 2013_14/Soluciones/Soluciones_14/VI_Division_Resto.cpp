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
// EJERCICIO 2 
//
/*	
	Calcula la divisi�n entera y el resto de la divisi�n empleando sendas  
	funciones recursivas
*/
/*********************************************************************/

#include <iostream>
using namespace std;

/*********************************************************************/
// Calcula la divisi�n entera 
// PRE: dividendo > 0  y divisor > 0 

int DivisionEntera (int dividendo, int divisor)
{
	/*
	Idea: Hay que plantearlo como la soluci�n al siguiente problema:

		�Cuantas veces puedo quitarle "divisor" a "dividendo" sin 
		llegar a un negativo? 

		En definitiva se trata de CONTAR el n�mero de veces que es posible 
		realizar esta resta,m por lo que cada ejecuci�n sumar� uno.  

		Caso base:		Si "dividendo" < "divisor", la soluci�n es 0
		Caso general:	Hallar la soluci�n a la divisi�n entera entre 
						"dividendo"-"divisor" y "divisor", y sumarle 1

	*/

	int dif = dividendo - divisor;

	if (dif < 0)	// No puedo seguir restando m�s 
		return (0);
	else
		return (1 + DivisionEntera(dif, divisor));	// Sumar uno
}

/*********************************************************************/
// Calcula el resto de la divisi�n entera 
// PRE: dividendo > 0  y divisor > 0 

int RestoDivision (int dividendo, int divisor)
{

	/*
    Idea: Hay que plantearlo como la soluci�n al siguiente problema:
            
		�Qu� queda despu�s de quitarle divisor a dividendo tantas 
		veces como se pueda sin llegar a un negativo?

		No estamos interesados en saber CU�NTAS VECES podemos hacer 
		esta sustracci�n, sino en saber el resultado de la �LTIMA 
		resta. Por eso, el valor de la diferencia del caso base es el 
		que se devuelve SIN MODIFICACIONES como soluci�n final. 

		Caso base:		Si "dividendo" < "divisor", la soluci�n es 0
		Caso general:	La soluci�n es la misma soluci�n que la del 
						problema de calcular el resto de la divisi�n 
						entre "dividendo"-"divisor" y "divisor"
   */

	if (dividendo - divisor < 0)	// No puedo seguir restando m�s 
		return (dividendo);			// Este valor ser� el resultado final
	else
		return RestoDivision(dividendo-divisor, divisor);
}

/*********************************************************************/
/*********************************************************************/

int main()
{   
	int dividendo, divisor; 

	cout << "Introduce dividendo (terminar con un negativo) --> "; 
	cin >> dividendo; 
	// Solo se pide el divisor si el dividendo es v�lido
	if (dividendo >= 0) {
		cout << "Introduce divisor (terminar con un negativo) --> "; 
		cin >> divisor; 
	}

	while ((dividendo>=0) && (divisor>=0)) {

		cout << "\tLa divisi�n entera es = "; 
		cout << DivisionEntera (dividendo, divisor) << endl;

		cout << "\tEl resto de la divisi�n es = "; 
		cout << RestoDivision (dividendo, divisor) << endl;

		cout << endl;

		cout << "Introduce dividendo (terminar con un negativo) --> "; 
		cin >> dividendo; 
		// Solo se pide el divisor si el dividendo es v�lido
		if (dividendo >= 0) {
			cout << "Introduce divisor (terminar con un negativo) --> "; 
			cin >> divisor; 
		}

	} // while ((dividendo>=0) && (divisor>=0)) 

	cout << "\n\n";
	system("pause");
	return (0);
}
