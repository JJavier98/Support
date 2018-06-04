/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
// GRADO EN INGENIER�A INFORM�TICA
//
// CURSO 2012-2013
// (C) JUAN CARLOS CUBERO TALAVERA
// (C) FRANCISCO JOS� CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACI�N E INTELIGENCIA ARTIFICIAL
//
// RELACI�N DE PROBLEMAS 2
// EJERCICIO 14
//
/*	
	Un n�mero entero de n d�gitos se dice que es narcisista si se puede 
	obtener como la suma de las potencias n-�simas de cada uno de sus 
	d�gitos. Por ejemplo 153 y 8208 son n�meros narcisistas porque 
		153 = 1^3 + 5^3 + 3^3  
		8208 = 8^4 + 2^4 + 0^4 + 8^4.

	Este programa nos indica si el n�mero es o no narcisista.

	Entradas: Un n�mero entero 
	Salidas:  Un mensaje, indicando si el n�mero introducido 
			  es o no narcisista.
*/
/*********************************************************************/

#include <iostream>
#include <cmath>
using namespace std;


int main()
{
	bool es_narcisista;

	int	n; // Entrada: n�mero para calcular la propiedad "narcisista"
	int n_copia;	// Copia de "n". Se usar� para trabajar sobre �l y as�
					// no modificar el valor inicial de "n"
	int i;
	int	num_digitos, ultima_cifra;
	double suma;
   
	cout << "\nIntroduzca un entero: ";
	cin >> n;
   
	
	// Calcular el n�mero de d�gitos de "n"
	// El algoritmo est� explicado en las transparencias de clase
	// Observad que este c�digo es candidato a modularizarse con una funci�n, 
	// de manera que se llamar�a: 
	//		num_digitos = NumDigitos (n);

	n_copia = n;	// Copia para salvaguardar el valor de "n"

	num_digitos = 1;
	
	while (n_copia > 9){
		n_copia = n_copia / 10;
		num_digitos++;
	}   
   

	// Comprobar si el n�mero es narcisista: 
	// Para cada cifra se calcular� su potencia de orden "num_digitos"
	// y se sumar�n. Si la suma de los "num_digitos" sumandos es "n" 
	// el n�mero es narcisista. 
	
	n_copia = n;	// Copia para salvaguardar el valor de "n"

	suma = 0;
   
	for (i = 1 ; i <= num_digitos; i++){  // Usamos un ciclo for porque 
										  // sabemos el n�m. de iteraciones

		ultima_cifra = n_copia % 10; // tomamos la cifra menos significativa

		suma = suma + pow (1.0 * ultima_cifra, num_digitos);

		n_copia = n_copia/10; // descartar la cifra menos significativa
	}

	es_narcisista = (suma == n); // Evaluaci�n de la propiedad
   
	if (es_narcisista)
		cout << "\nEs narcisista";
	else
		cout << "\nNo es narcisista";

	cout << "\n\n";
	
	system("pause");
}
