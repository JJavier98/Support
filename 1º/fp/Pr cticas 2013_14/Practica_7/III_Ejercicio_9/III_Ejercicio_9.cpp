/* 
	Fundamentos de Programaci�n
	Grado en Ingenier�a Inform�tica

	2013 - FP
	------------------------------
	Programa que calcula una progresi�n geom�trica 
   utilizando funciones.

	Necesita: r, a1 y k.

	Devuelve: El total.
*/
#include <iostream>   // Inclusi�n de los recursos de E/S
#include <iomanip>
#include <cmath>

using namespace std; 

double SumaHasta(int termino_primero, int tope, double razon) {
   
   double suma = termino_primero * ((pow(razon,tope) -1) / (razon - 1)) ;

   return suma;

}

//Funci�n que calcula la suma hasta infinito indicada 
//en el guion
double SumaHastaInfinito(int termino_primero, int tope, double razon) {

   double suma = 0; 
   
   if (abs(razon) <= 1) {
      suma = (termino_primero / (1 - razon));
   }

   return suma;

}

//Funci�n que multiplica los k primeros elementos de 
//la progresi�n aplicando la f�rmula dada en el guion
double MultiplicaHasta(int termino_primero, int tope, double razon) {

   double suma = sqrt(pow((termino_primero*tope),tope * 1.0));

   return suma;

}

int main(){                    // Programa Principal 
	// Declara variables para guardar los datos

   double termino_primero, razon;
	int n, tope;

	double suma_hasta, suma_infinito, multiplica_hasta; 

	cout.setf(ios::fixed);		// Notaci�n de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales 

   //Obtenemos los datos
	cout << "Primer t�rmino de la progresi�n (a_1): ";
	cin >> termino_primero;
	cout << "Raz�n de la progresi�n (r): ";
	cin >> razon;

	do {
		cout << "Indice (debe ser >=1) del �ltimo t�rmino a sumar (k): ";
		cin >> tope;
	} while (tope < 1);
	

	/*
	En vez de hacer la operaci�n pow, que es costosa, bastar�a multiplicar
	en cada iteraci�n, el valor de a_{n-1} por la raz�n, y ya tengo a_n
	Observad que en Matem�ticas decimos:
		a_i = a_{i-1} * r
	Mientras que en un algoritmo debemos poner:
		termino = termino * r
	*/

   suma_hasta = SumaHasta(termino_primero,tope,razon);

   suma_infinito = SumaHastaInfinito(termino_primero,tope,razon);

   multiplica_hasta = MultiplicaHasta(termino_primero,tope,razon);

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
