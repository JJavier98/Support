/******************************************************************************
	Fundamentos de Programación
	Grado en Ingeniería Informática

	2013 - FP
	------------------------------
	Diseño e implementación de la clase MiReal como indica el ejercicio III.22

******************************************************************************/
#include <iostream>   // Inclusión de los recursos de E/S
#include <cmath> //Inclusion de las librerías matemáticas

using namespace std; 

/*****************************************************************************/
//Definicion de la clase
class MiReal {

private: 

	//Atributos
	double value; 

public:
/*****************************************************************************/
	//Constructor
	MiReal(double pValue) {

		//Asignamos los atributos
		value = pValue;

	}
/*****************************************************************************/
	//Métodos
	double Valor() {
		return value;
	}
/*****************************************************************************/
	double Seno() {
		return sin(value);
	}
/*****************************************************************************/
	double ValorAbsoluto() {

		if (value < 0) {
			return -value;
		} else {
			return value;
		}
	}
};
/*****************************************************************************/
//Programa Principal 
int main(){    

	//Declara variables para guardar los valores	
    MiReal real(-6.5);


	//Pintamos los valores en la consola
	cout << "\nEl seno de: " << real.Valor() << " es: " << real.Seno(); 
	cout << "\nEl absoluto de: " << real.Valor() << " es: " << real.ValorAbsoluto(); 

	cout << "\n\n";


	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");

}