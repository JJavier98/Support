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
// EJERCICIO 27
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
	
	Entradas: Un número entero "n", del que queremos saber si es "feliz"
			  Un número entero "k", el grado tentativo. 
			
	Salidas:  Un mensaje, indicando si el "n" es (o no) feliz de grado "k"
*/
/*********************************************************************/

#include <iostream>
#include <cmath>
using namespace std;


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



	int suma;			 // Para sumar los cuadrados de los dígitos
	int	num_digitos;	 // Num. de dígitos del valor que se comprueba 

 	int num_iteraciones; // Contador de iteraciones

   	int tmp; // Copia de un número. Se usará para trabajar sobre él y no 
			 // perder el valor del número.
	int act; // En cada iteración, "act" contendrá el nuevo valor resultante 
			 // de la suma de la iteración anterior  

	
	// Calcular el número de dígitos de "n"
	// El algoritmo está explicado en las transparencias de clase
	// Observad que este código es candidato a modularizarse con una función, 
	// de manera que se llamaría: 
	//		num_digitos = NumDigitos (n);	

	tmp = n;	// Copia para salvaguardar el valor de "n"
	num_digitos = 1;
	
	while (tmp > 9){
		tmp = tmp / 10;
		num_digitos++;
	}   
   
	


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

//		cout << "suma de " << act << " (" 
//			 << num_digitos << " digs.) = " << suma << endl;


		// Preparar la siguiente iteración: 

		act = suma; // Para la siguiente vuelta "act" será el valor a comprobar

		// Calcular el número de dígitos de "act"
		// Observad que este código es candidato a modularizarse con una función, 
		// de manera que se llamaría: 
		//		num_digitos = NumDigitos (act);	

		tmp = act;
		num_digitos = 1;

		while (tmp > 9){
			tmp = tmp / 10;
			num_digitos++;
		}   

	} // while (num_digitos > 1)


	// Test finales

	bool es_feliz = (suma == 1); 
	bool es_feliz_grado_k = ((es_feliz) && (num_iteraciones <= k)); 
	

	cout << endl << endl; 

	if (es_feliz_grado_k) {
		cout << n << " es feliz de grado " << k << endl;
		if (num_iteraciones < k) 
			cout << "Realmente, " << n << " es feliz de grado " 
			     << num_iteraciones << endl;
	}
	else {
		cout << n << " no es feliz de grado " << k << endl;
		if (es_feliz)
			cout << n << " es feliz de grado " << num_iteraciones << endl;
		else
			cout << n << " no es feliz.";
	}

	cout << "\n\n";
	
	system("pause");
}
