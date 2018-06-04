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
// EJERCICIOS 16 y 17
//
/*	
	La clase "ParejaEnteros" representa una pareja de enteros cualesquiera. 
	La clase ofrece un constructor con argumentos y los métodos 
	get de acceso a los datos para lectura. No se permite su modificación 
	directa al usuario de la clase. 
	Otros métodos públicos: calcular el mayor, el menor, comprobar si se 
	dividen, ver quien es el dividendo y quien el divisor, 
	intercambiarlos y calcular el máximo común divisor. 

	Para ilustrar el uso de esta clase se ha construido un programa principal 
	en el que, una vez creado un objeto de la clase "ParejaEnteros" 
	se ofrece un menú con las opciones disponibles para realizar cualquiera 
	de las operaciones definidas sobre la clase.
*/
/*********************************************************************/

#include <iostream>
#include <string>
#include <cctype>
using namespace std;


///////////////////////////////////////////////////////////////////////

class Pareja_de_Enteros
{

private:

	int primero;
	int segundo;

public:

	/*****************************************************************/
	// Constructor con argumentos

	Pareja_de_Enteros (int primer_valor, int segundo_valor)
	{
		primero = primer_valor;
		segundo = segundo_valor;
   }

	/*****************************************************************/
	// Métodos de lectura (Get) de los datos individuales 
	
	int Primero()
	{
		return primero;
	}

	int Segundo()
	{
		return segundo;
	}

	/*****************************************************************/
	// Métodos públicos sencillos

	bool SeDividen()
	{
      return ((primero % segundo == 0  ||  segundo % primero == 0));
	}

	// PRE: primero y segundo se dividen
	int Dividendo()
	{
		return ElMayor();
	}

	// PRE: primero y segundo se dividen
	int Divisor()
	{
		return ElMenor();
	}

	int ElMenor()
	{ 
		int el_menor; 

		if (primero < segundo)
			el_menor = primero;
		else
			el_menor = segundo;

		return el_menor;
	}

	int ElMayor()
	{
		int el_mayor; 

		if (primero > segundo)
			el_mayor = primero;
		else
			el_mayor = segundo;

		return el_mayor;
	}

	void Intercambia()
	{
		int tmp;

		tmp = primero;
		primero = segundo;
		segundo = tmp;
	}

	/*****************************************************************/
	// Máximo común divisor
    // Algoritmo: Vamos dividiendo los dos enteros por todos los 
    //  enteros menores que el menor de ellos hasta que:
    //		- AMBOS sean divisibles por el mismo valor
    //		ó
	//		- lleguemos al 1

	int MCD()
	{
		bool hay_divisores, mcd_encontrado;
		int divisor, mcd;

		if (primero==0 || segundo==0)
			mcd = 0;

		else {

			divisor = ElMenor();
	
			hay_divisores = true;
			mcd_encontrado = false;

			while (hay_divisores && !mcd_encontrado){
				
				if (divisor == 1) { 
					hay_divisores = false;
					mcd = 1;
				}
				else{            
					if ((primero%divisor == 0) && (segundo%divisor == 0)) {
						mcd_encontrado = true;
						mcd = divisor;
					}    
					else{
						divisor--;
					}

				} // else de if (divisor == 1) 

			} // while (hay_divisores && !mcd_encontrado)
		
		} // else de if (primero==0 || segundo==0)

		return mcd;
	}

	/*****************************************************************/
};

///////////////////////////////////////////////////////////////////////

/*********************************************************************/

int main()
{
	int	 uno, otro;

	cout << "\nIntroduzca un valor entero: ";
	cin >> uno;
	cout << "\nIntroduzca otro valor entero: ";
	cin >> otro;


	// Creación de la pareja--> constructor

	Pareja_de_Enteros pareja(uno, otro);



	char opcion;
	bool continuar = true;

	while (continuar) {

		cout << "\n\n\n";
		cout << "\nP -> Imprimir el valor Primero";
		cout << "\nS -> Imprimir el valor Segundo";
		cout << "\nY -> Calcular el maYor";
		cout << "\nN -> Calcular el meNor";
		cout << "\nC -> Calcular el mCd";
		cout << "\nI -> Intercambiar los valores";
		cout << "\nD -> ¿Se Dividen?";
		cout << "\nO -> Imprimir el dividendO";
		cout << "\nR -> Imprimir el divisoR";
		cout << "\nX -> eXit";

		do {
			cout << "\n\nIntroduzca la opción elegida-->";
			cin >> opcion;
			opcion = toupper(opcion);
		} while (opcion!='P' && opcion!='S' && opcion!='Y' && 
				 opcion!='N' && opcion!='C' && opcion!='I' && 
				 opcion!='D' && opcion!='O' && opcion!='R' && 
				 opcion!='X');
		// Cuando conozcamos las cadenas de caracteres (clase string, 
		// o cadenas estilo "C" en <cstring> veremos cómo gestionar 
		// cómodamente condiciones complejas como la anterior

		switch (opcion) {
			
			case ('X'):	continuar = false;
						break; 
			case ('P'): cout << "\nEl Primero es: " << pareja.Primero();
						break; 
			case ('S'): cout << "\nEl Segundo es: " << pareja.Segundo();
						break; 
			case ('Y'): cout << "\nEl Mayor es: " << pareja.ElMayor();
						break; 
			case ('N'): cout << "\nEl Menor es: " << pareja.ElMenor();
						break; 
			case ('C'): cout << "\nEl MCD es:   " << pareja.MCD();
						break; 
			case ('I'): pareja.Intercambia();
						cout << "\nSe han intercambiado los valores";
						break; 

			default:	// Eleción de: 'D', 'O', 'R'

						if (!pareja.SeDividen())
							cout << "\nNo se dividen";

						else // se dividen

							if (opcion == 'D')
								cout << "\nSe dividen";
							else if (opcion == 'O')
								cout << "\nDividendo = " 
								     << pareja.Dividendo();
							else if (opcion == 'R')
								cout << "\nDivisor   = " 
								     << pareja.Divisor();
						break; 
		} // switch

	} // while (continuar)

	cout << "\n\n";

	system("pause");

	return (0);
}