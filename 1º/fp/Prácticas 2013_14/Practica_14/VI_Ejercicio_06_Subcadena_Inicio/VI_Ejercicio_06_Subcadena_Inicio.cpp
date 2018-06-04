/****************************************************************************** 
	Fundamentos de Programación
	Grado en Ingeniería Informática

	2014 - FP
	------------------------------
	Cread una función recursiva con la siguiente cabecera
	
		bool ContieneDesdeInicio(string cadena_grande, string cadena_peque) 

	que compruebe si la cadena cadena_peque se encuentra al inicio de la cadena
	cadena_grande (desde la posición cero)

	
******************************************************************************/
#include <iostream>	//Inclusión de los recursos de E/S
#include <string> //Inclusión de las funciones de cadenas

using namespace std; 

/*************************************************************/
//Esta función comprueba si la cadena cadena_peque se encuentra al 
//inicio de la cadena cadena_grande (desde la posición cero)
bool ContieneDesdeInicio(string cadena_grande, string cadena_peque) {

	
	if (cadena_peque.size() == 0)  {
		//Si la cadena peque llega a 0 es que ha sido igual en todas las iteraciones
        return true;
    } else if (cadena_grande.at(0) != cadena_peque.at(0)) {
		
		//Si el primer caracter de la cadena es distinto las dos cadenas son distintas
		return false;
		
	} else {

		//Le quitamos el primer caracter a las dos cadenas
		cadena_grande = cadena_grande.erase(0, 1);
		cadena_peque = cadena_peque.erase(0, 1);
			
		//Volvemos a llamar a la función
		return ContieneDesdeInicio(cadena_grande, cadena_peque);
		
    }

}

/*****************************************************************************/
//Programa Principal 
int main(){    

	//Declara variables para guardar los datos   
	string cadena_grande, cadena_peque;
	bool resultado;

	//Solicita datos al usuario
	cout << "Introduzca una cadena grande: ";
	cin >> cadena_grande;
	cout << "Introduzca una cadena pequeña: "; 
	cin >> cadena_peque;

	//Comprobamos que la cadena grande sea mayor que la pequeña
	if (cadena_grande.size() < cadena_peque.size()) {
	
		cout << "La cadena grande debe ser mayor o igual a la cadena peque" << endl;

	} else {

		//Hacemos los calculos
		resultado = ContieneDesdeInicio(cadena_grande, cadena_peque);

		//Pintamos el resultado en la consola
		cout << "La cadena " << cadena_grande << " contiene " << cadena_peque << " (0=No|1=Si)? " << resultado << endl << endl;

	}

	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");

}