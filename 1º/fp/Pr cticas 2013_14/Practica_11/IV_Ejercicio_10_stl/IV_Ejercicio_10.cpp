/****************************************************************************** 
	Fundamentos de Programación
	Grado en Ingeniería Informática

	2013 - FP
	------------------------------
	Sobre el ejercicio 9, cread una clase especifica Mayusculas que implemente 
	los metodos necesarios para realizar la cuenta de las mayusculas. Lo que se 
	pretende es que la clase proporcione los metodos siguientes:

      void IncrementaCuenta (char mayuscula)
      int  CuantasHay (char mayuscula)

	Realizarlo mediante la clase vector de la stl

	NOTA: En este ejercicio pinto primero las letras para que quede mas bonito

******************************************************************************/
#include <iostream>   // Inclusión de los recursos de E/S
#include <vector>	//Inclusión de la clase vector

using namespace std; 

/*****************************************************************************/
//Definicion de la clase
class Mayusculas {
private:
    vector <int> vector_privado;
public:

	/*********************************************************/
	//Constructor
    Mayusculas() {

		//Recorremos los caracteres de la A a la Z
		for (char ch = 'A'; ch <= 'Z'; ch++) {
		
			//Inicializamos el elemento a 0 para cada letra
			vector_privado.push_back(0);

		}

	}

	/*********************************************************/
	//Este función devuelve el tamaño del vector
    int TotalUtilizados() {
        return vector_privado.size();
    }

   	/*********************************************************/
    //Esta función devuelve un elemento concreto del vector
    int Elemento(int indice) {
        return vector_privado[indice];
    }

	/*********************************************************/
	//Esta funcion incrementa la cuenta de la mayuscula pasada
	void IncrementaCuenta(char mayuscula) {

		//Restamos la mayuscula para averiguar la posicion (A sera la posicion 0)
		int pos = mayuscula - 'A';

		//Incrementamos el valor del valor de la posicion dada en 1
		vector_privado[pos]++;

	}
    /*********************************************************/
	//Esta funcion devuelve cuantas vecces está repetida la mayuscula pasada
	int CuantasHay(char mayuscula) {

		//Restamos la mayuscula para averiguar la posicion (A sera la posicion 0)
		int pos = mayuscula - 'A';

		return vector_privado[pos];

	}
};
/*****************************************************************************/
//Programa Principal 
int main(){    

	// Declara variables para guardar los datos   
	Mayusculas vector_caracteres;
	char caracter;
	const int POS_A = 'A';

	do {
		//Vamos pidiendole caracteres al usuario
		cout << "Introduzca un caracter: ";
		cin >> caracter;

		if ((caracter >= 'A') && (caracter <= 'Z')) {

			//Si es una mayuscula incrementamos su contador correspondiente
			vector_caracteres.IncrementaCuenta(caracter); 
		} 

	} while (caracter != '.'); //Cuando el usuario introduce un . se termina

	//Pintamos el vectores utilizando la funcion que nos hemos definido para ello
	cout << "Contador Mayusculas\n";

	//Pintamos el encabezado
	for (int i = 0; i < vector_caracteres.TotalUtilizados(); i++)
		cout << char(i + POS_A);	

	cout << "\n"; //Pintamos un salto de linea

	//Recorremos el vector y lo pintamos en la consola
	for (int i = 0; i < vector_caracteres.TotalUtilizados(); i++)
		cout << vector_caracteres.Elemento(i);

	cout << "\n\n"; //Pintamos dos saltos de linea

	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");

}