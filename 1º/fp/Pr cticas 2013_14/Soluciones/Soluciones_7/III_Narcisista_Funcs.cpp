/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
// GRADO EN INGENIER�A INFORM�TICA
//
// CURSO 20132-2014
// (C) JUAN CARLOS CUBERO TALAVERA
// (C) FRANCISCO JOS� CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACI�N E INTELIGENCIA ARTIFICIAL
//
// RELACI�N DE PROBLEMAS 3
// EJERCICIO 26 (N�mero narcisista -con funciones-)
//
//
/*	
	Un n�mero entero de n d�gitos se dice que es narcisista si se puede 
	obtener como la suma de las potencias n-�simas de cada uno de sus 
	d�gitos. Por ejemplo 153 y 8208 son n�meros narcisistas porque 
		153 = 1^3 + 5^3 + 3^3  
		8208 = 8^4 + 2^4 + 0^4 + 8^4.

	Este programa nos indica si el n�mero es o no narcisista.

	Ampliaci�n del ejercicio 14 de la Relaci�n de Problemas 2, 
	modularizando con funciones.

	Entradas: Un n�mero entero 
	Salidas:  Un mensaje, indicando si el n�mero introducido 
			  es o no narcisista.
*/
/*********************************************************************/

#include <iostream>
#include <cmath>
using namespace std;


/*********************************************************************/
// Devuelve el n�mero de d�gitos de un n�mero int
// El algoritmo est� explicado en las transparencias de clase

int NumDigitos (int numero)
{
	int num_digitos = 1;
	
	while (numero > 9){
		numero = numero / 10;
		num_digitos++;
	}   

	return (num_digitos);
}

/*********************************************************************/
// Calcula la propiedad "ser Narcisista" sobre un numero: 
//		Un n�mero entero de n d�gitos se dice que es narcisista si se  
//		puede obtener como la suma de las potencias n-�simas de cada uno  
//		de sus d�gitos. 
//		Por ejemplo 153 y 8208 son n�meros narcisistas porque 
//			153 = 1^3 + 5^3 + 3^3  
//			8208 = 8^4 + 2^4 + 0^4 + 8^4.


bool EsNarcisista (int numero)
{
	double suma;
	int		i, num_digitos, ultima_cifra;
	
	num_digitos = NumDigitos (numero); 

	int copia = numero; // Como se va a modificar "numero" y necesitamos 
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

	return (suma == numero);  // Evaluaci�n de la propiedad
}

/*********************************************************************/

int main()
{
	int		n; // Entrada: n�mero para calcular la propiedad "narcisista"
   

	cout << "\nIntroduzca un entero: ";
	cin >> n;
   

	if (EsNarcisista (n))
		cout << "\nEs narcisista";
	else
		cout << "\nNo es narcisista";

	cout << "\n\n";
	
	system("pause");
}
