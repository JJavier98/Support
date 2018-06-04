/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
// GRADO EN INGENIER�A INFORM�TICA
//
// CURSO 2012-2013
// (C) JUAN CARLOS CUBERO TALAVERA
// (C) FRANCISCO JOS� CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACI�N E INTELIGENCIA ARTIFICIAL
//
// RELACI�N DE PROBLEMAS 3
// EJERCICIO 9 (Terna_vs4)
//
//
/*	
	Implementaci�n 4 de la clase "Terna", que se emplea para 
	representar un conjunto de 3 valores de tipo double, sobre los que se 
	quiere realizar las operaciones de calcular el m�ximo, el m�nimo y 
	la media aritm�tica.

	vs3: Los tres datos son private.
		 Se pueden cambiar sus valores individualmente.
*/
/*********************************************************************/

#include <iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////

class Terna_vs4
{

private:

	double uno, dos, tres;

public:

	/*****************************************************************/
	// Constructor con argumentos (los valores de la terna)
	// Observar que llama al m�todo SetValores(), lo que evita 
	// duplicidad de c�digo. 
	
	Terna_vs4 (double primero, double segundo, double tercero)
	{
		SetValores (primero, segundo, tercero);
	}

	/*****************************************************************/
	// M�todo de escritura (Set) de los datos de la terna (conjuntamente)

	void SetValores (double primero, double segundo, double tercero)
	{
		SetPrimero(primero);
		SetSegundo(segundo);
		SetTercero(tercero);
	}

	/*****************************************************************/
	// M�todos de lectura (Get) de los datos individuales de la terna 
	
	double GetPrimero()
	{
		return uno;
	}

	double GetSegundo()
	{
		return dos;
	}

	double GetTercero()
	{
		return tres; 
	}

	/*****************************************************************/
	// M�todos de escritura (Set) de los datos individuales de la terna 
	
	void SetPrimero(double valor)
	{
		uno = valor; 
	}

	void SetSegundo(double valor)
	{
		dos = valor; 
	}


	void SetTercero(double valor)
	{
		tres = valor; 
	}


	/*****************************************************************/
	// Media aritm�tica de la terna

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
// main para Terna_vs4 

int main()
{
	// Todo el c�digo que sigue es de Terna_vs2

	double maximo, minimo, media_aritmetica;

	Terna_vs4 tres_reales (9.5, 8.5, 3.5);	
	
	minimo = tres_reales.Min();				
	maximo = tres_reales.Max();				
	media_aritmetica = tres_reales.Media();

	cout << endl; 
	cout << "Uno  = " << tres_reales.GetPrimero() << endl;	
	cout << "Dos  = " << tres_reales.GetSegundo() << endl;	 
	cout << "Tres = " << tres_reales.GetTercero() << endl;	
															
	cout << endl; 
	cout << "M�nimo = " << minimo << endl;
	cout << "M�ximo = " << maximo << endl;
	cout << "Media  = " << media_aritmetica << endl;


	// Nuevo c�digo

	tres_reales.SetSegundo (0.5);	

		// Hemos cambiamos el valor de "dos" individualmente mediante 
		// el m�todo espec�fico de escritura "SetSegundo()".

	minimo = tres_reales.Min();				
	maximo = tres_reales.Max();				
	media_aritmetica = tres_reales.Media();

	cout << endl; 
	cout << "Uno  = " << tres_reales.GetPrimero() << endl;	
	cout << "Dos  = " << tres_reales.GetSegundo() << endl;	 
	cout << "Tres = " << tres_reales.GetTercero() << endl;	
															
	cout << endl; 
	cout << "M�nimo = " << minimo << endl;
	cout << "M�ximo = " << maximo << endl;
	cout << "Media  = " << media_aritmetica << endl;

	cout << "\n\n";

	system("pause");

	return (0);
}