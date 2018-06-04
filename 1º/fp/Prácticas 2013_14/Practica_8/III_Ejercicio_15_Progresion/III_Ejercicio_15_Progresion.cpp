/******************************************************************************
	Fundamentos de Programación
	Grado en Ingeniería Informática

	2013 - FP
	------------------------------
	Programa que calcula una progresión geométrica 

	Necesita: r, a1 y k.

	Devuelve: El total.

******************************************************************************/
#include <iostream>   // Inclusión de los recursos de E/S
#include <iomanip>
#include <cmath>

using namespace std; 

/*****************************************************************************/
//Definicion de la clase
class ProgresionGeometrica {

private: 

	//Atributos
	double termino_primero;
	int tope;
	double razon;

public:
/*****************************************************************************/
	//Constructor
	ProgresionGeometrica(double pTermino_primero, int pTope, double pRazon) {
		
		//Asignamos los atributos
		termino_primero = pTermino_primero;
		tope = pTope;
		razon = pRazon;

	}

	//Métodos
	double SumaHasta() {
   
	   double suma = termino_primero * ((pow(razon,tope) -1) / (razon - 1)) ;

	   return suma;

	}
/*****************************************************************************/
	//Función que calcula la suma hasta infinito indicada 
	//en el guion
	double SumaHastaInfinito() {

	   double suma = 0; 
   
	   if (abs(razon) <= 1) {
		  suma = (termino_primero / (1 - razon));
	   }

	   return suma;

	}
/*****************************************************************************/
	//Función que multiplica los k primeros elementos de 
	//la progresión aplicando la fórmula dada en el guion
	double MultiplicaHasta() {

	   double suma = sqrt(pow((termino_primero*tope),tope * 1.0));

	   return suma;

	}

};
/*****************************************************************************/
//Programa Principal 
int main(){    

	// Declara variables para guardar los datos   
	double termino_primero, razon;
	int tope;

	double suma_hasta, suma_infinito, multiplica_hasta; 

	cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales 

   //Obtenemos los datos
	cout << "Primer término de la progresión (a_1): ";
	cin >> termino_primero;
	cout << "Razón de la progresión (r): ";
	cin >> razon;

	do {
		cout << "Indice (debe ser >=1) del último término a sumar (k): ";
		cin >> tope;
	} while (tope < 1);
	

	/*
	En vez de hacer la operación pow, que es costosa, bastaría multiplicar
	en cada iteración, el valor de a_{n-1} por la razón, y ya tengo a_n
	Observad que en Matemáticas decimos:
		a_i = a_{i-1} * r
	Mientras que en un algoritmo debemos poner:
		termino = termino * r
	*/

   ProgresionGeometrica pg(termino_primero,tope,razon);

   suma_hasta = pg.SumaHasta();

   suma_infinito = pg.SumaHastaInfinito();

   multiplica_hasta = pg.MultiplicaHasta();

   //Pintamos los valores en la consola
	cout << "\nSuma hasta " << setw(3) << tope 
		 << " = " << setw(10) << setprecision (2) << suma_hasta;
	cout << "\n\n";

	cout << "\nSuma hasta " << setw(3) << tope 
		 << " = " << setw(10) << setprecision (2) << suma_hasta;
	cout << "\n\n";
      
	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");

}