/* 
	Fundamentos de Programación
	Grado en Ingeniería Informática

	2013 - FP
	------------------------------
	Programa que pinta una pirámide en pantalla en base a los limites introducidos.

	Devuelve: Una pirámide.
*/
#include <iostream>   // Inclusión de los recursos de E/S

using namespace std; 

int main(){                    // Programa Principal

	//Declaramos variables donde almacenar los datos
	int inferior;
	int superior;

	//Obtenemos los datos necesarios
	cout << "Introduzca el numero inferior: ";
	cin >> inferior;
	cout << "Introduzca el numero superior: ";
	cin >> superior;

	//Hacemos los cálculos

	//NOTA: Le restamos 1 a inferior (inferior--) 
	//ya que al incrementarlo siemmpre empezara por 1 mas
	for (inferior--; inferior <= superior; inferior++){

		//Anidamos otro for donde el iterador comenzara en i+1
		for (int h = inferior + 1; h <= superior; h++) {

			/*	
				NOTA: Lo correcto seria no escribir aqui el resultado, si no
				almacenarlo en una variable temporal stringstream y luego pintarla 
			*/
		
			//Pintamos los valores en la consola
			cout << h << " ";

		}

		//Pintamos un salto de linea
		cout << "\n";

	}

	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	//system("pause");
}
