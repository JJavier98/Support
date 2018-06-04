/****************************************************************************** 
	Fundamentos de Programación
	Grado en Ingeniería Informática

	2013 - FP
	------------------------------
	Cread una clase Permutacion para representar una permutación de enteros.

		• Para almacenar los valores enteros usaremos como dato miembro privado 
		un vector de la STL.

		• Pasaremos como parámetro al constructor un vector de la STL con los 
		valores enteros. Supondremos como precondición que el vector es una 
		permutación correcta, es decir, que contiene todos los enteros sin 
		repetir entre el mínimo y el máximo de dichos valores. Por ejemplo, 
		(2,3,6,5,4) es una permutación correcta pero no lo es (7,7,6,5) 
		(tiene el 7 como valor repetido) ni tampoco (7,6,4) (le falta el 5).

		• Añadid un método que calcule el número de lecturas de dicha 
		permutación. Una permutación de un conjunto de enteros, 
		C = {1, · · · , n}, tiene k lecturas, si para leer sus elementos en 
		orden creciente (de izquierda a derecha) tenemos que recorrer la 
		permutación k veces. Por ejemplo, la siguiente permutación del conjunto
		{0, . . . , 8}: 408125367
		necesita 3 lecturas. En la primera obtendríamos 0, 1, 2 y 3. En la 
		segunda 4, 5, 6 y 7 y finalmente, en la tercera, 8.

******************************************************************************/
#include <iostream>	//Inclusión de los recursos de E/S
#include <vector>	//Inclusión de las funciones para manejo de vectores
#include <climits>  //Inclusion de los ficheros de límites

using namespace std; 

/*****************************************************************************/
//Definicion de la clase
class Permutacion {
private:
	vector <int> vector_numeros;
public:

	/*********************************************************/
	//El constructor de la clase requiere un vector de permutaciones que se
	//presupone correcto.
	Permutacion(vector <int> v_numeros) {

		//Asignamos el parametro al atributo
		vector_numeros = v_numeros;

	}
	/*********************************************************/
	//Esta función devuelve el numero de lecturas que necesitamos hacer para leer
	//todos los numeros del vector.
	int NumeroLecturas() {

		//Declaracion de variables

		//En este contador iremos almacenando el numero de lecturas
		int n_lecturas = 0;
		//En este contador almacenamos los leidos tiene que llegar a vector_numeros.size()
		int n_leidos = 1; 

		//Bucle while con forma de for, recorrerá el vector hasta que esten todos los numeros leidos
		for (int i = 0; n_leidos < (int)vector_numeros.size() && i < (int)vector_numeros.size(); i++) {

			//Recorremos el vector para leer los numeros inferiores al actual
			for (int h = i+1; h < (int)vector_numeros.size(); h++) {

				//Si el valor es inferior al actual...
				if (vector_numeros[i] > vector_numeros[h]) {

					//...incrementamos el contador de leidos
					n_leidos++;

				}

			}

			//Incrementamos el contador de lecturas
			n_lecturas++;

		}

		//Devolvemos el numero de lecturas
		return n_lecturas;
	}

};
/*****************************************************************************/
//Programa Principal 
int main(){    

	//Declara variables para guardar los datos   
	vector<int> vector_permutacion;
	int lecturas;

	//Agregamos elementos al vector
	vector_permutacion.push_back(4);
	vector_permutacion.push_back(0);
	vector_permutacion.push_back(8);
	vector_permutacion.push_back(1);
	vector_permutacion.push_back(2);
	vector_permutacion.push_back(5);
	vector_permutacion.push_back(3);
	vector_permutacion.push_back(6);
	vector_permutacion.push_back(7);

	//Creamos un nuevo objeto de la clase Permutacion
	Permutacion perm(vector_permutacion);

	//Hacemos los calculos
	lecturas = perm.NumeroLecturas();

	//Pintamos los valores en la consola
	cout << "Para leer todo se necesitan " << lecturas << " lecturas\n\n";


	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");

}