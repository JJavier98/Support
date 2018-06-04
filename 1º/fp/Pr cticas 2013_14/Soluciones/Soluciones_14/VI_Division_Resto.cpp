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
// EJERCICIO 2 
//
/*	
	Calcula la división entera y el resto de la división empleando sendas  
	funciones recursivas
*/
/*********************************************************************/

#include <iostream>
using namespace std;

/*********************************************************************/
// Calcula la división entera 
// PRE: dividendo > 0  y divisor > 0 

int DivisionEntera (int dividendo, int divisor)
{
	/*
	Idea: Hay que plantearlo como la solución al siguiente problema:

		¿Cuantas veces puedo quitarle "divisor" a "dividendo" sin 
		llegar a un negativo? 

		En definitiva se trata de CONTAR el número de veces que es posible 
		realizar esta resta,m por lo que cada ejecución sumará uno.  

		Caso base:		Si "dividendo" < "divisor", la solución es 0
		Caso general:	Hallar la solución a la división entera entre 
						"dividendo"-"divisor" y "divisor", y sumarle 1

	*/

	int dif = dividendo - divisor;

	if (dif < 0)	// No puedo seguir restando más 
		return (0);
	else
		return (1 + DivisionEntera(dif, divisor));	// Sumar uno
}

/*********************************************************************/
// Calcula el resto de la división entera 
// PRE: dividendo > 0  y divisor > 0 

int RestoDivision (int dividendo, int divisor)
{

	/*
    Idea: Hay que plantearlo como la solución al siguiente problema:
            
		¿Qué queda después de quitarle divisor a dividendo tantas 
		veces como se pueda sin llegar a un negativo?

		No estamos interesados en saber CUÁNTAS VECES podemos hacer 
		esta sustracción, sino en saber el resultado de la ÚLTIMA 
		resta. Por eso, el valor de la diferencia del caso base es el 
		que se devuelve SIN MODIFICACIONES como solución final. 

		Caso base:		Si "dividendo" < "divisor", la solución es 0
		Caso general:	La solución es la misma solución que la del 
						problema de calcular el resto de la división 
						entre "dividendo"-"divisor" y "divisor"
   */

	if (dividendo - divisor < 0)	// No puedo seguir restando más 
		return (dividendo);			// Este valor será el resultado final
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
	// Solo se pide el divisor si el dividendo es válido
	if (dividendo >= 0) {
		cout << "Introduce divisor (terminar con un negativo) --> "; 
		cin >> divisor; 
	}

	while ((dividendo>=0) && (divisor>=0)) {

		cout << "\tLa división entera es = "; 
		cout << DivisionEntera (dividendo, divisor) << endl;

		cout << "\tEl resto de la división es = "; 
		cout << RestoDivision (dividendo, divisor) << endl;

		cout << endl;

		cout << "Introduce dividendo (terminar con un negativo) --> "; 
		cin >> dividendo; 
		// Solo se pide el divisor si el dividendo es válido
		if (dividendo >= 0) {
			cout << "Introduce divisor (terminar con un negativo) --> "; 
			cin >> divisor; 
		}

	} // while ((dividendo>=0) && (divisor>=0)) 

	cout << "\n\n";
	system("pause");
	return (0);
}
