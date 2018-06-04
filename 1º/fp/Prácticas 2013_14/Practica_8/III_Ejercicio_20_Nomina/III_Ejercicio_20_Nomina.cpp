/******************************************************************************
	Fundamentos de Programación
	Grado en Ingeniería Informática

	2013 - FP
	------------------------------
	Se pide diseñar la interfaz de una clase (también hay que incluir los datos 
	miembro privados) para poder trabajar con esta información. No se pide 
	implementar la clase, únicamente determinar la interfaz.

******************************************************************************/
#include <iostream>   // Inclusión de los recursos de E/S

using namespace std; 

/*****************************************************************************/
//Definicion de la clase
class Nomina {

private: 

	//Atributos
	int categoria; 
	int antiguedad;
	int horasExtra;
	int salarioBase;


public:
/*****************************************************************************/
	//Constructor
	Nomina(int pCategoria, int pAntiguedad, int pHoras_extra) {

		//Asignamos los atributos (lo considero básico en la definicion, no
		//estoy haciendo nada de la logica del programa, solo asignando)
		categoria = pCategoria;
		antiguedad = pAntiguedad;
		horas_extra = pHorasExtra;

	}
/*****************************************************************************/
	//Métodos
	double CalcularImporteNomina() {

	}

};
/*****************************************************************************/
//Programa Principal 
int main(){    

	//Declara variables para guardar los valores
	Nomina operario1(1,2,10);
	Nomina operario2(1,3,8);
	Nomina base1(2,5,5);
	Nomina administrativo1(3,4,4);
	Nomina directivo1(4,5,3);

	//Pintamos los valores en la consola
	cout << "\nNomina del operario 1: " << operario1.CalcularImporteNomina(); 
	cout << "\nNomina del operario 2: " << operario2.CalcularImporteNomina(); 

	cout << "\nNomina del base 1: " << base1.CalcularImporteNomina(); 

	cout << "\nNomina del administrativo 1: " << administrativo1.CalcularImporteNomina(); 

	cout << "\nNomina del directivo 1: " << directivo1.CalcularImporteNomina(); 

	cout << "\n\n";


	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");

}