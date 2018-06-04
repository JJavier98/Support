/****************************************************************************** 
	Fundamentos de Programación
	Grado en Ingeniería Informática

	2013 - FP
	------------------------------
	Escribir un programa que lea los valores de dos enteros, n y k y calcule, 
	almacene y muestre por pantalla los k primeros terminos de la sucesion de 
	Fibonacci de orden n. Para almacenar los enteros, se usara un dato miembro 
	de tipo vector de la STL.

	La sucesion de Fibonacci de orden n es una secuencia de numeros en la que 
	los dos primeros son el 0 y el 1. A partir del tercero, los elementos se 
	calculan como la suma de los n anteriores, si ya hay n elementos disponibles, 
	o la suma de todos los anteriores si hay menos de n elementos disponibles.

	Por ejemplo, la sucesion de Fibonacci de orden 4 seria la siguiente:
	0,1,1,2,4,8,15,29,...

	El programa debe definir una clase llamada Fibonacci. Al constructor se le 
	pasara como parametro el valor de n y la clase tendra metodos para observar 
	el valor de n y tres metodos:

	• void CalculaPrimeros(int tope) para que calcule los tope primeros 
		elementos de la sucesion.
	• int TotalCalculados() que devuelva cuantos elementos hay actualmente 
		almacenados (el valor tope del metodo anterior)
	• int Elemento(int indice) para que devuelva el elemento indice-esimo 
		de la sucesion.
	
	NOTA: En el guion se especifica que Elemento devuelve un int, pero es muy
	facil desbordarlo, ya que la sucesión de fibonacci es exponencial, se debería
	tener en cuenta

******************************************************************************/
#include <iostream>	// Inclusión de los recursos de E/S
#include <vector>	//Inclusión de las funciones para manejo de vectores

using namespace std; 

/*****************************************************************************/
//Definicion de la clase
class Fibonacci {
private:
	//Declaracion de atributos
    vector <int> vector_numeros;
    int n_inicio;
public:

	/*********************************************************/
	//El constructor de la clase requiere un entero (n) que es el inicio
	Fibonacci(int n) {
	
		//Asignamos el parametro al atributo
		n_inicio = n;

	}
	/*********************************************************/
	//Este método calcula los numeros de la sucesión de fibonnaci que hay desde
	//n_inicio hasta k, haciendo uso de dos bucles
	void CalculaPrimeros(int k) {

		//Primero agregamos los dos primeros elementos (0 y 1)
		vector_numeros.push_back(0);
		vector_numeros.push_back(1);

		//Empezamos a recorrer desde el tercero (indice 2) hasta k
		for (int i = 2; i <= k; i++) {

			//Declaramos variables para almacenar datos
			int suma = 0; //Acumulador de suma, posibilidad de desbordamiento
			
			//Nos guardamos el tamaño del vector, porque como lo vamos a usar
			//varias veces, asi no tenemos que estar llamando a la funcion .size()
			int tamanio_vector =  (int)vector_numeros.size();

			//Calculamos la posicion hasta la que tendrá que leer hacia atrás
			//que será el tamaño del vector menos lo pasado en n al constructor
			int n_previos = tamanio_vector - n_inicio;

			//Si el vector no contiene tantos elementos como hay que coger, se 
			//ira hasta 0, (hasta el principio)
			if (n_inicio >= tamanio_vector) {
				n_previos = 0;
			}

			//Recorreremos el vector hacia atras n posiciones (si el vector es mas pequeño
			//se recorrerá hasta 0)
			for (int j = tamanio_vector -1; j >= n_previos; j--) {

				//Incrementamos el acumulador
				suma += vector_numeros.at(j);

			}

			//Agregamos la suma de los 4 previos al vector
			vector_numeros.push_back(suma);

		}

	}
	/*********************************************************/
	//Esta función devuelve el tamaño del vector, que será igual al numero de
	//elementos calculados, quizá se podria haber almacenado en un atributo, 
	//pero pudiendo calcularlo cada vez nos ahorramos una variable y una
	//muy posible fuente de errores.
	int TotalCalculados() {

		return vector_numeros.size();

	}
	/*********************************************************/
	//Esta función devuelve un elemento del vector dada su posicion, si el elemento
	//no existiera se dispararía una excepción que podriamos controlar.
	//
	//NOTA: En el guion se especifica que esta funcion devuelve un int, pero es muy
	//facil desbordarlo, ya que la sucesión de fibonacci es exponencial, se debería
	//tener en cuenta
	int Elemento(int indice) {

		return vector_numeros.at(indice);

	}
};
/*****************************************************************************/
//Programa Principal 
int main(){    

	//Declara variables para guardar los datos   
	int k = 100; int n = 4; int tope;
	Fibonacci fibonacci(n);

	//Hacemos los calculos
	fibonacci.CalculaPrimeros(k);
	tope = fibonacci.TotalCalculados(); // tope = k
	           

	//Pintamos los valores en la consola
	cout << "Sucesion de Fibonacci desde " << n << " hasta " << k << ":\n";

	//NOTA: En el guion se especifica que la función Elemento devuelve un int, pero es muy
	//facil desbordarlo, ya que la sucesión de fibonacci es exponencial, se debería
	//tener en cuenta
	for (int i=0; i<tope; i++)
		cout << fibonacci.Elemento(i) << " ";

	cout << "\n\n";

	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");

}