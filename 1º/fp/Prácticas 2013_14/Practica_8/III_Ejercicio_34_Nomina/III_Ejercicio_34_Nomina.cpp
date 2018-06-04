/******************************************************************************
	Fundamentos de Programación
	Grado en Ingeniería Informática

	2013 - FP
	------------------------------
	Se pide implementar la funcionalidad de la clase Nomina del ejericio III.20

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
	int precioHora;
	int horasExtras;
	int salarioBase;
	double complementos;
	double salarioBruto;


public:
/*****************************************************************************/
	//Constructor
	Nomina(int pCategoria, int pAntiguedad, int pHorasExtras) {

		//Asignamos los atributos (lo considero básico en la definicion, no
		//estoy haciendo nada de la logica del programa, solo asignando)
		categoria = pCategoria;
		antiguedad = pAntiguedad;
		horasExtras = pHorasExtras;


		//Seleccionamos el salario base y el precio por hora extra segun la 
		//categoria del empleado
		switch (categoria) {
		
		case 1: //Operario
			salarioBase = 900;
			precioHora = 16;
			break;
		case 2: //Base
			salarioBase = 1100;
			precioHora = 23;
			break;
		case 3: //Administrativo
			salarioBase = 1200;
			precioHora = 25;
			break;
		case 4: //Directivo
			salarioBase = 2000;
			precioHora = 30;
			break;
		}



	}
/*****************************************************************************/
	//Métodos
	double CalcularImporteNomina() {

		double resultado;
		
		//Calculamos el salario base mas el plus de antiguedad
		resultado =	salarioBase + ( salarioBase * (antiguedad / 100)); 


		//Calculamos las horas extras
		complementos =	horasExtras * precioHora; 

		//Agregamos el plus de edad a los complementos
		complementos +=  (horasExtras * (antiguedad / 100));

		//Definimos el salario bruto
		salarioBruto = resultado + complementos;

		return salarioBruto;

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