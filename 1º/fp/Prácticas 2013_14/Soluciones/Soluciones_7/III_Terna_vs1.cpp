/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
// GRADO EN INGENIER�A INFORM�TICA
//
// CURSO 2013-2014
// (C) JUAN CARLOS CUBERO TALAVERA
// (C) FRANCISCO JOS� CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACI�N E INTELIGENCIA ARTIFICIAL
//
// RELACI�N DE PROBLEMAS 3
// EJERCICIO 13 (Terna_vs1)
//
//
/*	
	Implementaci�n 1 de la clase "Terna", que se emplea para 
	representar un conjunto de 3 valores de tipo double, sobre los que se 
	quiere realizar las operaciones de calcular el m�ximo, el m�nimo y 
	la media aritm�tica.

	vs1: Los tres datos son public.
*/
/*********************************************************************/

#include <iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////

class Terna_vs1
{

public:

   double uno, dos, tres;

	/*****************************************************************/
	// Media aritm�tica de la terna

	double Media()
	{
		return (uno + dos + tres)/3.0;	// Los m�todos acceden libremente
										// a los datos de la clase
	}

	/*****************************************************************/
	// Mayor valor en la terna
 
	double Max()
	{
		double max;

		if (uno > dos)
			max = uno;
		else
			max = dos;

		if (tres > max)
			max = tres;

		return max; 
	}

	/*****************************************************************/
	// Menor valor en la terna
 
	double Min()
	{
		double min;

		if (uno < dos)
			min = uno;
		else
			min = dos;

		if (tres < min)
			min = tres;

		return min; 
	}

	/*****************************************************************/

};

///////////////////////////////////////////////////////////////////////

/*********************************************************************/
// main para Terna_vs1 

int main()
{
	double maximo, minimo, media_aritmetica;
   
	Terna_vs1 tres_reales;	// "tres_reales" es un objeto de 
							// la clase "Terna_vs1"

	tres_reales.uno = 9.5;		// Observar el acceso (escritura) a los 
	tres_reales.dos = 8.5;		// datos del objeto "tres_reales". No hay  
	tres_reales.tres = 3.5;		// ninguna restricci�n (son public) 

	minimo = tres_reales.Min();				// Ejecuci�n de los m�todos
	maximo = tres_reales.Max();				// sobre el objeto "tres_reales"
	media_aritmetica = tres_reales.Media();

	cout << endl; 
	cout << "Uno  = " << tres_reales.uno << endl;	// Acceso (lectura) a 
	cout << "Dos  = " << tres_reales.dos << endl;	// los datos del objeto 
	cout << "Tres = " << tres_reales.tres << endl;	// "tres_reales". No hay
													// restricci�n (public) 
	cout << endl; 
	cout << "M�nimo = " << minimo << endl;
	cout << "M�ximo = " << maximo << endl;
	cout << "Media  = " << media_aritmetica << endl;

	cout << "\n\n";

	system("pause");

	return (0);
}
