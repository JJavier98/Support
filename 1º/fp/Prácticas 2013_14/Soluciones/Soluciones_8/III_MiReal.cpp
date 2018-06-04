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
// EJERCICIO 22
//
/*	
	Este programa presenta una clase llamada "MiReal" para trabajar con 
	reales "al estilo de las clases". Se trata de una clase que actúa 
	como envolventes (wrappers) de un tipo básico.

	La clase proporciona los siguientes métodos:
		a) Valor(). Devuelve el valor del real.
		b) Seno(). Devuelve un double.
		c) ValorAbsoluto(). Devolverá un tipo double que contendrá el 
		valor absoluto del real. 
*/
/*********************************************************************/

#include <iostream>
#include <cmath>
using namespace std;

///////////////////////////////////////////////////////////////////////

class MiReal
{

private:

	double real;

public:

	/*****************************************************************/
	// Constructor sin argumentos

	MiReal(void)
	{
		real = 0.0;
	}
	/*****************************************************************/
	// Constructor con argumentos

	MiReal(double un_real)
	{
		real = un_real;
	}

	/*****************************************************************/
	// Acceso de lectura

	double Valor()
	{
		return real;
	}

	/*****************************************************************/
	// Método de cálculo. Seno

	double Seno()
	{
		return (sin(real));
	}

	/*****************************************************************/
	// Método de cálculo. Valor absoluto

	double ValorAbsoluto()
	{
		double aux; 
		
		if (real < 0)
			aux = -real;
		else
			aux = real;

		return (aux);
	}

	/*****************************************************************/
};

///////////////////////////////////////////////////////////////////////

/*********************************************************************/

int main()
{
	double un_double;

	cout << "\nIntroduzca un valor real: ";
	cin >> un_double;

	// Iniciar un objeto de la clase MiReal con el valor leído
	MiReal un_objeto_real(un_double);

	cout << "\nValor = " << un_objeto_real.Valor();
	cout << "\nValor Absoluto = " << un_objeto_real.ValorAbsoluto();
	cout << "\nSeno = " << un_objeto_real.Seno();
	cout << "\n\n";

	// Crear un objeto de la clase MiReal vacío
	MiReal otro_objeto_real;

	cout << "\nValor = " << otro_objeto_real.Valor();
	
	cout << "\n\n";

	system("pause");

	return (0);
}