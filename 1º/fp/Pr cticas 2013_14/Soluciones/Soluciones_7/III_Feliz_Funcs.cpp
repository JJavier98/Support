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
// EJERCICIO 26 (Número feliz -con funciones-)
//
/*	
	Se dice que un número natural es feliz si cumple que si sumamos 
	los cuadrados de sus dígitos y seguimos el proceso con los resultados 
	obtenidos, finalmente obtenemos uno (1) como resultado. 
		Por ejemplo, 203 es un número feliz ya que.
		203 --> 2^2 + 0^2 + 3^2 = 13 
 		13 --> 1^2 + 3^2 = 10 
		10 --> 1^2 + 0^2 = 1

	Se dice que un número es feliz de grado k si es feliz en un máximo 
	de k iteraciones (una iteración se produce cada vez que se elevan al 
	cuadrado los dígitos del valor actual y se suman)
		Por ejemplo, 203 es un número feliz de grado 3 (además, es feliz 
		de cualquier grado mayor o igual

	Este programa indica si un número natural "n" es feliz para un 
	grado "k" dado de antemano. 
	
	Ampliación del ejercicio 27 de la Relación de Problemas 2, 
	modularizando con funciones.

	Entradas: Un número entero "n", del que queremos saber si es "feliz"
			  Un número entero "k", el grado tentativo. 
			
	Salidas:  Un mensaje, indicando si el "n" es (o no) feliz de grado "k"
*/
/*********************************************************************/

#include <iostream>
#include <cmath>
using namespace std;

/*********************************************************************/
// Devuelve el número de dígitos de un número int
// El algoritmo está explicado en las transparencias de clase

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
// Calcula la propiedad "ser feliz de grado k" sobre un numero: 
//
//		Se dice que un número natural es feliz si cumple que si sumamos 
//		los cuadrados de sus dígitos y seguimos el proceso con los resultados 
//		obtenidos, finalmente obtenemos uno (1) como resultado. 
//		Por ejemplo, 203 es un número feliz ya que.
//			203 --> 2^2 + 0^2 + 3^2 = 13 
// 			13 --> 1^2 + 3^2 = 10 
//			10 --> 1^2 + 0^2 = 1
//
//		Se dice que un número es feliz de grado k si es feliz en un máximo 
//		de k iteraciones (una iteración se produce cada vez que se elevan al 
//		cuadrado los dígitos del valor actual y se suman)
//		Por ejemplo, 203 es un número feliz de grado 3 (además, es feliz 
//		de cualquier grado mayor o igual

bool EsFelizGradoK (int n, int k)
{
	int suma;			 // Para sumar los cuadrados de los dígitos
	int	num_digitos;	 // Num. de dígitos del valor que se comprueba 

 	int num_iteraciones; // Contador de iteraciones


	num_digitos = NumDigitos (n);

	if (num_digitos == 1) { // Cuidado con los números con un dígito
		suma = n;
		num_iteraciones = 1;
	}
	else 
		num_iteraciones = 0; // Se va a empezar a iterar

	// Comprobar si el número es feliz: 
	// Para cada cifra se calculará su cuadrado y se sumarán. 
	// Este proceso se repetirá hasta obtener un número de una cifra
	// Si es 1, el número es feliz.


   	int tmp; // Copia de un número. Se usará para trabajar sobre él y no 
			 // perder el valor del número.
	int act; // En cada iteración, "act" contendrá el nuevo valor resultante 
			 // de la suma de la iteración anterior  


	act = n; // inicialmente, "act" es el valor que se comprueba 

	while (num_digitos > 1) {

		suma = 0;

		tmp = act;

		// Suma de los dígitos que forman el número actual 

		int i;
		int	ultima_cifra;

		for (i = 1 ; i <= num_digitos; i++){  // sabemos el núm. de iteraciones
			ultima_cifra = tmp % 10; // tomamos la cifra menos significativa
			suma = suma + ultima_cifra*ultima_cifra;
			tmp = tmp/10; // descartar la cifra menos significativa
		}
			
		num_iteraciones++; // Una iteración más


		// Preparar la siguiente iteración: 

		act = suma; // Para la siguiente vuelta "act" será el valor a comprobar

		num_digitos = NumDigitos (act);	


	} // while (num_digitos > 1)


	// Test finales

	bool es_feliz = (suma == 1); 
	bool es_feliz_grado_k = ((es_feliz) && (num_iteraciones <= k)); 

	return (es_feliz_grado_k);

}

/*********************************************************************/

int main()
{

	int	n; // Entrada: número para calcular la propiedad "feliz"
	int	k; // Entrada: grado tentativo.


	cout << "\nTest: comprobar si un número es feliz con un grado dado.";
	cout << "\n\n";
	cout << "Introduzca un número para comprobar si es feliz: ";
	cin >> n;
	cout << "Introduzca el grado tentativo: ";
	cin >> k;


	cout << "\n\n";

	if (EsFelizGradoK (n, k)) 
		cout << n << " es feliz de grado " << k << " (y grados mayores)" << endl;
	else 
		cout << n << " no es feliz de grado " << k << endl;

	cout << "\n\n";
	system("pause");
}