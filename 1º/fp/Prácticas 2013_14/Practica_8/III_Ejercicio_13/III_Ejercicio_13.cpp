/****************************************************************************** 
	Fundamentos de Programación
	Grado en Ingeniería Informática

	2013 - FP
	------------------------------
	Se pide crear una clase Terna que represente un conjunto de 3 valores de 
	tipo double, sobre los que se quiere realizar las operaciones de calcular 
	el máximo, el mínimo y la media aritmética.

******************************************************************************/
#include <iostream>   // Inclusión de los recursos de E/S

using namespace std; 

/*****************************************************************************/
//Definicion de la clase
class Terna_vs2 {

private: 

	//Atributos
	double uno;
	double dos;
	double tres;

public:

	//Constructor
	Terna_vs2(double pUno, double pDos, double pTres) {
		
		//Asignamos los atributos
		uno = pUno;
		dos = pDos;
		tres = pTres;

	}

	//Métodos
	double GetPrimero() {
		return uno;
	}
	double GetSegundo() {
		return dos;
	} 
	double GetTercero() {
		return tres;
	}

	double Max(){

		//Asignamos el primer valor al resultado
		double maximo = uno;

		//Si el segundo es mayor que el resultado, lo asignamos al resultado
		if (dos > maximo) 
				maximo = dos;

		//Si el tercero es mayor que el resultado, lo asignamos al resultado
		if (tres > maximo)
			maximo = tres;

		//Devolvemos el resultado
		return maximo;
	}

	double Min(){

		//Asignamos el primer valor al resultado
		double minimo = uno;

		//Si el segundo es menor que el resultado, lo asignamos al resultado
		if (dos < minimo) 
				minimo = dos;

		//Si el tercero es menor que el resultado, lo asignamos al resultado
		if (tres < minimo)
			minimo = tres;

		//Devolvemos el resultado
		return minimo;
	}

	double Media() {

		return (uno + dos + tres) / 3.0;  
		
	}

};
/*****************************************************************************/
//Definicion de la clase
class Terna_vs3 {

private: 

	//Atributos
	double uno;
	double dos;
	double tres;

public:

	//Constructor
	Terna_vs3(double pUno, double pDos, double pTres) {
		
		//Asignamos los atributos
		uno = pUno;
		dos = pDos;
		tres = pTres;

	}

	//Métodos
	double GetPrimero() {
		return uno;
	}
	double GetSegundo() {
		return dos;
	} 
	double GetTercero() {
		return tres;
	}

	void SetValores(double pUno, double pDos, double pTres) {
		
		//Asignamos los atributos
		uno = pUno;
		dos = pDos;
		tres = pTres;

	}

	double Max(){

		//Asignamos el primer valor al resultado
		double maximo = uno;

		//Si el segundo es mayor que el resultado, lo asignamos al resultado
		if (dos > maximo) 
				maximo = dos;

		//Si el tercero es mayor que el resultado, lo asignamos al resultado
		if (tres > maximo)
			maximo = tres;

		//Devolvemos el resultado
		return maximo;
	}

	double Min(){

		//Asignamos el primer valor al resultado
		double minimo = uno;

		//Si el segundo es menor que el resultado, lo asignamos al resultado
		if (dos < minimo) 
				minimo = dos;

		//Si el tercero es menor que el resultado, lo asignamos al resultado
		if (tres < minimo)
			minimo = tres;

		//Devolvemos el resultado
		return minimo;
	}

	double Media() {

		return (uno + dos + tres) / 3.0;  
		
	}

};
/*****************************************************************************/
//Definicion de la clase
class Terna_vs4 {

private: 

	//Atributos
	double uno;
	double dos;
	double tres;

	void SetValores(double pUno, double pDos, double pTres) {
		
		//Asignamos los atributos
		uno = pUno;
		dos = pDos;
		tres = pTres;

	}

public:

	//Constructor
	Terna_vs4(double pUno, double pDos, double pTres) {
		
		//Asignamos los atributos
		SetValores(pUno,pDos,pTres);

	}

	//Métodos
	double GetPrimero() {
		return uno;
	}
	double GetSegundo() {
		return dos;
	} 
	double GetTercero() {
		return tres;
	}

	void SetPrimero(double v) {
		uno = v;
	}
	void SetSegundo(double v) {
		dos = v;
	}
	void SetTercero(double v) {
		tres = v;
	}

	double Max(){

		//Asignamos el primer valor al resultado
		double maximo = uno;

		//Si el segundo es mayor que el resultado, lo asignamos al resultado
		if (dos > maximo) 
				maximo = dos;

		//Si el tercero es mayor que el resultado, lo asignamos al resultado
		if (tres > maximo)
			maximo = tres;

		//Devolvemos el resultado
		return maximo;
	}

	double Min(){

		//Asignamos el primer valor al resultado
		double minimo = uno;

		//Si el segundo es menor que el resultado, lo asignamos al resultado
		if (dos < minimo) 
				minimo = dos;

		//Si el tercero es menor que el resultado, lo asignamos al resultado
		if (tres < minimo)
			minimo = tres;

		//Devolvemos el resultado
		return minimo;
	}

	double Media() {

		return (uno + dos + tres) / 3.0;  
		
	}

};
/*****************************************************************************/
//Programa Principal 
int main(){    

	// Declara variables para guardar los datos   

	Terna_vs2 tr2(6,1,3);
	cout << "El máximo es " << tr2.Max() << "\n\n";  

	Terna_vs3 tr3(9,1,3);
	tr3.SetValores(8,20,1);
	cout << "El máximo es " << tr3.Max() << "\n\n";  

	Terna_vs4 tr4(9,1,3);
	tr4.SetPrimero(8);
	cout << "El máximo es " << tr4.Max() << "\n\n";  
      
	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");

}