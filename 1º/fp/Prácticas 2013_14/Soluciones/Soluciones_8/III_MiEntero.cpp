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
// EJERCICIO 27
//
/*	
	Este programa presenta una clase llamada "MiEntero" para trabajar con 
	enteros "al estilo de las clases". Se trata de una clase que act�a 
	como envolventes (wrappers) de un tipo b�sico.

	La clase proporciona los siguientes m�todos:
		a) Valor(). Devuelve el valor del real.
		b) Factorial().    \ Problemas ya resueltos
		c) EsNarcisista(). /
*/
/*********************************************************************/

#include <iostream>
#include <cmath>
using namespace std;

///////////////////////////////////////////////////////////////////////

class MiEntero
{

private:

	int entero;

public:

	/*****************************************************************/
	// Constructor con argumentos

	MiEntero (int un_entero)
	{
		entero = un_entero;
	}
	
	/*****************************************************************/
	// Constructor sin argumentos

	MiEntero (void)
	{
		entero = 0;
	}

	/*****************************************************************/
	// Acceso de lectura

	double Valor()
	{
		return entero;
	}

	/*****************************************************************/
	// M�todo de c�lculo. Factorial
	//
	//		n! = n * (n-1) * (n-2) * ... * 1 si n>1
	//		0! = 1! = 1 
	// La soluci�n se ha discutido en ejercicios previos

	__int64 Factorial () {


		__int64 factorial = 1;

		for (int multiplicando = 2; multiplicando <= entero; multiplicando++)
			factorial = factorial * multiplicando;

		return (factorial);
	}

	/*****************************************************************/
	// M�todo de c�lculo. EsNarcisista	
	//
	// Calcula la propiedad "ser Narcisista" sobre un numero: 
	//		Un n�mero entero de n d�gitos se dice que es narcisista si se  
	//		puede obtener como la suma de las potencias n-�simas de cada uno  
	//		de sus d�gitos. 
	//		Por ejemplo 153 y 8208 son n�meros narcisistas porque 
	//			153 = 1^3 + 5^3 + 3^3  
	//			8208 = 8^4 + 2^4 + 0^4 + 8^4.
	// La soluci�n se ha discutido en ejercicios previos

	bool EsNarcisista ()
	{
		double suma;
		int		i, num_digitos, ultima_cifra;
	
		num_digitos = NumDigitos (entero); 

		int copia = entero; // Como se va a modificar "entero" y necesitamos 
							// conservar su valor, lo copiamos a "copia" y podremos 
							// cambiar el valor del �ltimo sin problemas.

		// Comprobar si el n�mero es narcisista: Para cada cifra se calcular� su 
		// potencia de orden "num_digitos" y se sumar�n. Ser� narcisista si la suma 
		// de los "num_digitos" sumandos es "numero" 

		suma = 0.0;
   
		for (i = 1 ; i <= num_digitos; i++){   

			ultima_cifra = copia % 10; // tomamos la cifra menos significativa

			suma = suma + pow (1.0 * ultima_cifra, num_digitos);

			copia = copia/10; // descartar la cifra menos significativa
		}

		return (suma == entero);  // Evaluaci�n de la propiedad
	}

	/*********************************************************************/


private: 

	/*****************************************************************/
	// Devuelve el n�mero de d�gitos de un n�mero int
	// El algoritmo est� explicado en las transparencias de clase
	// 
	// Se considera privado porque va a ser usado �nicamente por el 
	// m�todo EsNarcisista() y no se ha considerado su oferta para se  
	// usado fuera de la clase. No deja de ser una decisi�n de ESTE dise�o,
	// y, evidentemente, podr�a ofrecerse copmo m�todo p�blico.  

	int NumDigitos (int numero)
	{
		int num_digitos = 1;
	
		while (numero > 9){
			numero = numero / 10;
			num_digitos++;
		}   

		return (num_digitos);
	}

	/*****************************************************************/
};

///////////////////////////////////////////////////////////////////////

/*********************************************************************/

int main()
{
	int un_entero;

	cout << "\nIntroduzca un valor entero: ";
	cin >> un_entero;

	MiEntero un_objeto_entero (un_entero);

	cout << endl; 
	cout << "Valor = " << un_objeto_entero.Valor() << endl;
	cout << "Factorial = " << un_objeto_entero.Factorial()<< endl;

	if (un_objeto_entero.EsNarcisista()) 
		cout << un_objeto_entero.Valor() << " es narcisista";
	else 
		cout << un_objeto_entero.Valor() << " NO es narcisista";

	cout << "\n\n";

	system("pause");

	return (0);
}