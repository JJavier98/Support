/* 
	Fundamentos de Programación
	Grado en Ingeniería Informática

	2013 - FP
	------------------------------
	Se quiere construir una clase DepositoSimulacion para simular préstamos, 
	ofre- ciendo la funcionalidad descrita en los ejercicios 11 (reinvierte 
	capital e interés un número de años) y 12 (reinvierte capital e interés 
	hasta obtener el doble de la canti- dad inicial) de la Relación de 
	Problemas II (página RP-II.6).

	------------------------------
	NOTA:
	No se ha creado un punto de entrada puesto que el ejercicio solo pide 
	crear el esqueleto de la clase.

*/

using namespace std; 

//Definicion de la clase
class DepositoSimulacion {

private: 

	//Atributos
	double capital;
	double interes;

public:

	//Constructor
	DepositoSimulacion(double pCapital, double pInteres) {
	
		capital = pCapital;
		interes = pInteres;

	}

	//Creamos un metodo para poder cambiar el capital
	void SetCapital(double pCapital) {
		capital = pCapital;
	}

	//Creamos un metodo para poder cambiar el interes
	void SetInteres(double pInteres) {
		interes = pInteres;
	}

	//Métodos
	double CalcularCapitalSegunAnios(int anios){

		//Aqui agregaremos la funcionalidad, el ejercicio no lo pide

	}

	int CalcularAniosHastaCapital(double capital_deseado){

		/*
		Es mas eficiente una función que calcule hasta el capital deseado, porque
		la podemos reutilizar en un futuro para otras cosas
		*/

		//Aqui agregaremos la funcionalidad, el ejercicio no lo pide

	}

	//Esta funcion llama a la anterior indicando el doble del capital
	//tenemos código reutilizable, mucho mas fácil de mantener
	int CalcularAniosHastaDoble(){

		return CalcularAniosHastaCapital(capital * 2);

	}

};
