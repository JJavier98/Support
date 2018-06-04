/****************************************************************************** 
	Fundamentos de Programación
	Grado en Ingeniería Informática

	2013 - FP
	------------------------------
	Realizar un programa que vaya leyendo caracteres hasta que se encuentre un 
	punto ’.’. Queremos contar el número de veces que aparece cada una de las 
	letras mayusculas.

	Realizarlo mediante la clase vector de la stl

	NOTA: En este ejercicio pinto primero las letras para que quede mas bonito
	
******************************************************************************/
#include <iostream>	//Inclusión de los recursos de E/S
#include <vector>	//Inclusión de la clase vector

using namespace std; 

/*****************************************************************************/
//Programa Principal 
int main(){    

	//Declara variables para guardar los datos   
	vector <int> vector_caracteres;
	
	char caracter;
	const int POS_A = 'A';
	int indice;

	//Inicializamos el vector a 0
	for (char ch = 'A'; ch <= 'Z'; ch++) {
	
		//Inicializamos el elemento a 0 para cada letra
		vector_caracteres.push_back(0);

	}
	
	do {
		//Vamos pidiendole caracteres al usuario
		cout << "Introduzca un caracter: ";
		cin >> caracter;

		if ((caracter >= 'A') && (caracter <= 'Z')) {

			//Obtenemos la posición que debería tener el caracter en el vector
			indice = caracter - POS_A;
		
			//Obtenemos el valor actual de repeticiones para el caracter actual
			int valor = vector_caracteres.at(indice);

			//Incrementamos el valor y lo guardamos en el vector
			vector_caracteres.at(indice) = valor + 1; 
		
		} 

	} while (caracter != '.'); //Cuando el usuario introduce un . se termina

	//Pintamos el vectores utilizando la funcion que nos hemos definido para ello
	cout << "Contador Mayusculas\n";

	//Pintamos el encabezado
	for (int i = 0; i < vector_caracteres.size(); i++)
		cout << char(i + POS_A);	

	cout << "\n"; //Pintamos un salto de linea

	//Recorremos el vector y lo pintamos en la consola
	for (int i = 0; i < vector_caracteres.size(); i++)
		cout << vector_caracteres.at(i);

	cout << "\n\n"; //Pintamos dos saltos de linea

	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");

}