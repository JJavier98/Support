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
	double capital_inicial, capital_final;  // Declara variables para guardar
	int interes;               // los valores de capital, interés y el total
	int anyos;
	int anyo_actual;

	//Obtenemos los datos necesarios
	cout << "Introduzca el capital: " ;
	cin >> capital_inicial;
	cout << "Introduzca el interés: ";
	cin >> interes;
	cout << "Introduzca el número de años que desea: ";
	cin >> anyos;

	for (int i = 1; i < anyos; i++) {

		//Lo establecemos a 1 (la primera iteración es el primer año)
		anyo_actual = 1; 
		//Trabajaremos sobre capital final, ya que en cada iteracción hay que volver a usar
		//el capital inicial
		capital_final = capital_inicial;

		cout << "Cálculos realizados al " << i << "%:\n";

		while (anyo_actual <= anyos) {

			//Hacemos los cálculos 
			capital_final += capital_final * (i / 100.0);

			/*	
				NOTA: Lo correcto seria no escribir aqui el resultado, si no
				almacenarlo en un array temporal y luego pintarl los resultados
			*/

			//Pintamos los valores en la consola
			cout << "	Dinero obtenido en el año número " << anyo_actual << " = " << capital_final << "\n" ;
	


			//Incrementamos el año actual
			anyo_actual++;
	
		}

	}


	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");
}
