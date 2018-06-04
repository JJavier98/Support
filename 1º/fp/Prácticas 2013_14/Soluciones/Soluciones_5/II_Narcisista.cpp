/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
// GRADO EN INGENIERÍA INFORMÁTICA
//
// CURSO 2012-2013
// (C) JUAN CARLOS CUBERO TALAVERA
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 2
// EJERCICIO 14
//
/*	
	Un número entero de n dígitos se dice que es narcisista si se puede 
	obtener como la suma de las potencias n-ésimas de cada uno de sus 
	dígitos. Por ejemplo 153 y 8208 son números narcisistas porque 
		153 = 1^3 + 5^3 + 3^3  
		8208 = 8^4 + 2^4 + 0^4 + 8^4.

	Este programa nos indica si el número es o no narcisista.

	Entradas: Un número entero 
	Salidas:  Un mensaje, indicando si el número introducido 
			  es o no narcisista.
*/
/*********************************************************************/

#include <iostream>
#include <cmath>
using namespace std;


int main()
{
	bool es_narcisista;

	int	n; // Entrada: número para calcular la propiedad "narcisista"
	int n_copia;	// Copia de "n". Se usará para trabajar sobre él y así
					// no modificar el valor inicial de "n"
	int i;
	int	num_digitos, ultima_cifra;
	double suma;
   
	cout << "\nIntroduzca un entero: ";
	cin >> n;
   
	
	// Calcular el número de dígitos de "n"
	// El algoritmo está explicado en las transparencias de clase
	// Observad que este código es candidato a modularizarse con una función, 
	// de manera que se llamaría: 
	//		num_digitos = NumDigitos (n);

	n_copia = n;	// Copia para salvaguardar el valor de "n"

	num_digitos = 1;
	
	while (n_copia > 9){
		n_copia = n_copia / 10;
		num_digitos++;
	}   
   

	// Comprobar si el número es narcisista: 
	// Para cada cifra se calculará su potencia de orden "num_digitos"
	// y se sumarán. Si la suma de los "num_digitos" sumandos es "n" 
	// el número es narcisista. 
	
	n_copia = n;	// Copia para salvaguardar el valor de "n"

	suma = 0;
   
	for (i = 1 ; i <= num_digitos; i++){  // Usamos un ciclo for porque 
										  // sabemos el núm. de iteraciones

		ultima_cifra = n_copia % 10; // tomamos la cifra menos significativa

		suma = suma + pow (1.0 * ultima_cifra, num_digitos);

		n_copia = n_copia/10; // descartar la cifra menos significativa
	}

	es_narcisista = (suma == n); // Evaluación de la propiedad
   
	if (es_narcisista)
		cout << "\nEs narcisista";
	else
		cout << "\nNo es narcisista";

	cout << "\n\n";
	
	system("pause");
}
