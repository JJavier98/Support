/* 
	Fundamentos de Programación
	Grado en Ingeniería Informática

	2013 - FP
	------------------------------
	Programa que calcula los intereses.

	Necesita: Capital, interés y número de años.

	Devuelve: El beneficio interanual.
*/

#include <iostream>   // Inclusión de los recursos de E/S

using namespace std; 

int main(){                    // Programa Principal
	double capital;               // Declara variables para guardar
	double interes;               // los valores de capital, interés y el total
	int anyos;
	int anyo_actual = 1; //Lo establecemos a 1 (la primera iteración es el primer año)

	//Obtenemos los datos necesarios
	cout << "Introduzca el capital: " ;
	cin >> capital;
	cout << "Introduzca el interés: ";
	cin >> interes;
	cout << "Introduzca el número de años que desea: ";
	cin >> anyos;

	/*	
		NOTA: Este codigo es ineficiente, lo correcto seria un while
	*/
	do {

		if (anyos == 0) {
			/*
				NOTA: Esto es una chapucilla para que salga, lo correcto seria un while
				pero como lo pide el ejercicio, en caso de que el total de años sea 0 nos
				salimos del bucle con un break
			*/
			break;
		}

		//Hacemos los cálculos 
		//(lo almacenamos en la variable original capital tal y como sugiere el ejercicio)
		capital += capital * (interes / 100);

		/*	
			NOTA: Lo correcto seria no escribir aqui el resultado, si no
			almacenarlo en un array temporal y luego pintarl los resultados
		*/

		//Pintamos los valores en la consola
		cout << "Total en el año numero " << anyo_actual << " = " << capital << "\n" ;

		//Incrementamos el año actual
		anyo_actual++;

	} while (anyo_actual <= anyos);

	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");
}
