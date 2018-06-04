/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
// GRADO EN INGENIERÍA INFORMÁTICA
//
// CURSO 2013-2014
// (C) JUAN CARLOS CUBERO TALAVERA
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 3
// EJERCICIO 13 (Terna_vs2)
//
//
/*	
	Implementación 2 de la clase "Terna", que se emplea para 
	representar un conjunto de 3 valores de tipo double, sobre los que se 
	quiere realizar las operaciones de calcular el máximo, el mínimo y 
	la media aritmética.

	vs2: Los tres datos son private.
*/
/*********************************************************************/

#include <iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////

class Terna_vs2
{

private:

	double uno, dos, tres;

public:

	/*****************************************************************/
	// Constructor con argumentos (los valores de la terna)

	Terna_vs2 (double primero, double segundo, double tercero)
	{
		uno = primero;
		dos = segundo;
		tres = tercero;
	}

	/*****************************************************************/
	// Métodos de lectura (Get) de los datos individuales de la terna 
	
	double GetPrimero()
	{
		return uno; // Los métodos acceden libremente 
	}

	double GetSegundo()
	{
		return dos; // Los métodos acceden libremente 
	}

	double GetTercero()
	{
		return tres; // Los métodos acceden libremente 
	}

	/*****************************************************************/
	// Media aritmética de la terna

	double Media()
	{
		return (uno + dos + tres)/3.0;	
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
// main para Terna_vs2

int main()
{
	double maximo, minimo, media_aritmetica;
   
/*	No es posible crear un objeto de la clase de esta manera: 

		Terna_vs2 tres_reales;	

	porque al escribir un constructor con argumentos no está disponible 
	el constructor "de oficio". Si quiaiéramos disponer de él tendríamos 
	que escribirlo. 

	Tampoco son posibles las asignaciones (acceso de escritura):

		tres_reales.uno = 9.5; 
		tres_reales.dos = 8.5; 
		tres_reales.tres = 3.5;	 

	ni los accesos de lectura: 

		cout << "Uno  = " << tres_reales.uno << endl;
		cout << "Dos  = " << tres_reales.dos << endl;
		cout << "Tres = " << tres_reales.tres << endl;

	porque ahora los datos son private
*/


	Terna_vs2 tres_reales (9.5, 8.5, 3.5) ;	// Constructor con parámetros	

	minimo = tres_reales.Min();				// Ejecución de los métodos
	maximo = tres_reales.Max();				// sobre el objeto "tres_reales"
	media_aritmetica = tres_reales.Media();

	// Ahora, el acceso para lectura a los datos del objeto "tres_reales" se 
	// realiza mediante métodos específicos de lectura (Get) porque los datos 
	// se etiquetaron private

	cout << endl; 
	cout << "Uno  = " << tres_reales.GetPrimero() << endl;	
	cout << "Dos  = " << tres_reales.GetSegundo() << endl;	 
	cout << "Tres = " << tres_reales.GetTercero() << endl;	
															

	cout << endl; 
	cout << "Mínimo = " << minimo << endl;
	cout << "Máximo = " << maximo << endl;
	cout << "Media  = " << media_aritmetica << endl;

	cout << "\n\n";

	system("pause");

	return (0);
}
