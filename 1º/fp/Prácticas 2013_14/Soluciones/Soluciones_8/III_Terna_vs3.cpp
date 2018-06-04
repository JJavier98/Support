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
// EJERCICIO 13 (Terna_vs3)
//
//
/*	
	Implementación 3 de la clase "Terna", que se emplea para 
	representar un conjunto de 3 valores de tipo double, sobre los que se 
	quiere realizar las operaciones de calcular el máximo, el mínimo y 
	la media aritmética.

	vs3: Los tres datos son private.
		 Se pueden cambiar sus valores, pero conjuntamente. 
*/
/*********************************************************************/

#include <iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////

class Terna_vs3
{

private:

	double uno, dos, tres;

public:

	/*****************************************************************/
	// Constructor con argumentos (los valores de la terna)
	// Observar que llama al método SetValores(), lo que evita 
	// duplicidad de código. 
	
	Terna_vs3 (double primero, double segundo, double tercero)
	{
		SetValores (primero, segundo, tercero);
	}

	/*****************************************************************/
	// Método de escritura (Set) de los datos de la terna (conjuntamente)

	void SetValores (double primero, double segundo, double tercero)
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
// main para Terna_vs3 

int main()
{
	// Todo el código que sigue es de Terna_vs2

	double maximo, minimo, media_aritmetica;

	Terna_vs3 tres_reales (9.5, 8.5, 3.5);	
	
	minimo = tres_reales.Min();				
	maximo = tres_reales.Max();				
	media_aritmetica = tres_reales.Media();

	cout << endl; 
	cout << "Uno  = " << tres_reales.GetPrimero() << endl;	
	cout << "Dos  = " << tres_reales.GetSegundo() << endl;	 
	cout << "Tres = " << tres_reales.GetTercero() << endl;	
															
	cout << endl; 
	cout << "Mínimo = " << minimo << endl;
	cout << "Máximo = " << maximo << endl;
	cout << "Media  = " << media_aritmetica << endl;


	// Nuevo código

	tres_reales.SetValores (tres_reales.GetPrimero(), 
							0.5, 
							tres_reales.GetSegundo());	

		// Hemos cambiamos el valor de "dos", pero hemos tenido que 
		// reescribir los valores de "uno" y "tres" (eso sí, de una 
		// manera muy elegante).

	minimo = tres_reales.Min();				
	maximo = tres_reales.Max();				
	media_aritmetica = tres_reales.Media();

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