/******************************************************************************
	Fundamentos de Programación
	Grado en Ingeniería Informática

	2013 - FP
	------------------------------
	Diseño e implementación de la clase MiEntero como pide el ejercicio III.27

******************************************************************************/
#include <iostream>   // Inclusión de los recursos de E/S
#include <cmath> //Inclusion de las librerías matemáticas

using namespace std; 

/*****************************************************************************/
//Definicion de la clase
class MiEntero {

private: 

	//Atributos
	int value; 

	int NumDigitos(int n) {
	
		// Calcular el número de dígitos de "n"
		// El algoritmo está explicado en las transparencias de clase

		int num_digitos = 1;
	
		while (n > 9){
			n = n / 10;
			num_digitos++;
		}   

		return num_digitos;
   
	}

public:
/*****************************************************************************/
	//Constructor
	MiEntero(int pValue) {

		//Asignamos los atributos
		value = pValue;

	}
/*****************************************************************************/
	//Métodos
	double Valor() {
		return value;
	}
/*****************************************************************************/
	double Factorial() {
		//Asignamos el valor por defecto a 1
		int resultado = 1;
	
		//Hacemos los calculos
		for (int i = 2; i <= value; i++)
			resultado *= i;

		//Devolvemos el valor
		return resultado;
	}
/*****************************************************************************/
	bool EsNarcisista() {

		// Comprobar si el número es narcisista: 
		// Para cada cifra se calculará su potencia de orden "num_digitos"
		// y se sumarán. Si la suma de los "num_digitos" sumandos es "n" 
		// el número es narcisista. 

		int i;
		int ultima_cifra;
		double suma = 0;
		int num_digitos = NumDigitos(value);
		int n = value;
   
		for (i = 1 ; i <= num_digitos; i++){  // Usamos un ciclo for porque 
											  // sabemos el núm. de iteraciones
			ultima_cifra = n % 10; // tomamos la cifra menos significativa

			suma = suma + pow (1.0 * ultima_cifra, num_digitos);

			n = n/10; // descartar la cifra menos significativa
		}

		return (suma == value);
	}
/*****************************************************************************/
	bool EsFeliz() {

		int suma = 0;			 // Para sumar los cuadrados de los dígitos
		int	num_digitos;	 // Num. de dígitos del valor que se comprueba 

		int num_iteraciones; // Contador de iteraciones

		int tmp; // Copia de un número. Se usará para trabajar sobre él y no 
					// perder el valor del número.
		int act; // En cada iteración, "act" contendrá el nuevo valor resultante 
					// de la suma de la iteración anterior  

			int n = value;
	
		// Calcular el número de dígitos de "n"
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
	
		act = value; // inicialmente, "act" es el valor que se comprueba 

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
			num_digitos = NumDigitos (act);	 

		} // while (num_digitos > 1)


		return (suma == 1); 
	}
};
/*****************************************************************************/
//Programa Principal 
int main(){    

	//Declara variables para guardar los valores	
     MiEntero entero(153);


	//Pintamos los valores en la consola
	cout << "\nEl factorial de: " << entero.Valor() << " es: " << entero.Factorial(); 
	cout << "\nEl numero: " << entero.Valor() << " ¿es narcisista?: " << entero.EsNarcisista(); 
	cout << "\nEl numero: " << entero.Valor() << " ¿es feliz?: " << entero.EsFeliz(); 

	cout << "\n\n";


	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");

}