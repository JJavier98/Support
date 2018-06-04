/****************************************************************************** 
	Fundamentos de Programación
	Grado en Ingeniería Informática

	2013 - FP
	------------------------------
	Realizar un programa que lea del teclado un número indeterminado de datos 
	de tipo Punto2D de manera que termine la lectura si el usuario escribe -1 
	cuando el progra- ma le pide la abscisa de un nuevo punto. Los puntos 
	leídos los almacena en un objeto ColeccionPuntos2D.

	A continuación pide los datos necesarios, y crea un objeto Circunferencia, 
	y finalmente muestra cuáles de los puntos almacenados en la colección 
	ColeccionPuntos2D está en el círculo delimitado por la circunferencia.

******************************************************************************/
#include <iostream>	//Inclusión de los recursos de E/S
#include <cmath>	//Inclusión de las funciones matemáticas
#include <vector>	//Inclusión de las funciones de vectores

using namespace std; 
/*****************************************************************************/
//Definicion de la clase Punto2D
class Punto2D {
private:
   double abscisa;
   double ordenada;
public:
   Punto2D(double abscisaPunto, double ordenadaPunto) {
      SetCoordenadas (abscisaPunto, ordenadaPunto);
   }
   void SetCoordenadas (double abscisaPunto, double ordenadaPunto) {
      abscisa = abscisaPunto;
      ordenada = ordenadaPunto;
   }
   double GetAbscisa() {
      return abscisa;
   }
   double GetOrdenada() {
      return ordenada;
   }
};
/*****************************************************************************/
//Definicion de la clase Circunferencia
class Circunferencia {
private:

	//Nota: el compilador de Visual Studio no permite declarar un tipo de dato
	//double como static const (como si permite con int y otros) tal y como
	//se puede ver en http://stackoverflow.com/questions/370283/why-cant-i-have-a-non-integral-static-const-member-in-a-class
	//así que para solventar el problema he creado una funcion PI() que devuelve
	//el valor.

	//static const int PI = 3.14159265; //Esta línea da error
	static double PI() { return 3.14159265; } //Solucion al problema del compilador

	Punto2D centro;
	double radio;
public:
	/*********************************************************/
	//Constructor de la clase circunferencia, se le pasa el radio y el punto.
	Circunferencia(double p_radio, Punto2D p_centro) : centro(p_centro.GetAbscisa(), p_centro.GetOrdenada()) {

		radio = p_radio;

   }

	/*********************************************************/
	//Esta función devuelve la longitud de la circunferencia.
	double ObtenerLongitud() {

		return 2 * PI() * radio;
	}
	/*********************************************************/
	//Esta función devuelve el área de la circunferencia.
	double ObtenerArea() {

		return PI() * pow(radio, 2);
	}
	/*********************************************************/
	//Esta función devuelve el centro de la circunferencia.
	Punto2D ObtenerCentro() {

		return centro;
	}
	/*********************************************************/
	//Esta función devuelve el diámetro de la circunferencia.
	double ObtenerDiametro() {

		return 2 * radio;
	}
	/*********************************************************/
	//Esta función comprueba si el punto pasado como parámetro
	//está dentro de la circunferencia.
	bool ContienePunto(Punto2D punto) {

		//Comprobamos si está segun los calculos de la fórmula dada en el ejercicio
		double calculos = pow(centro.GetAbscisa() - punto.GetAbscisa(), 2);
		calculos += pow(centro.GetOrdenada() - punto.GetOrdenada(), 2);

		return calculos <= pow(radio, 2);
	}
};
/*****************************************************************************/
//Definicion de la clase ColeccionPuntos2D
class ColeccionPuntos2D {
private:

	vector <Punto2D> vector_privado;

public:

	/*********************************************************/
	//Este método agrega un nuevo punto a la colección.
	void Aniade(Punto2D punto) {

		vector_privado.push_back(punto);

	}
	/*********************************************************/
	//Esta función devuelve un punto dado su índice en la coleccion.
	//NOTA: Si el indice es incorrecto se disparará una excepcion,
	//por eso se usa la función at()
	Punto2D Elemento(int indice) {

		return vector_privado.at(indice);
	}
	/*********************************************************/
	//Esta función devuelve el tamaño de la colección.
	int Tamanio() {

		return vector_privado.size();
	}

};
/*****************************************************************************/
//Programa Principal 
int main() {    

	//Declara variables para guardar los datos
	ColeccionPuntos2D coleccion;
	int abscisa, ordenada, radio_circunferencia;

	cout << "Coleccion de Puntos\n";
	cout << "-------------------\n\n";

	cout << "Introduccion de puntos...\n";
	do {
		
		//Obtenemos los datos necesarios
		cout << "Introduzca la abscisa (entero positivo -1 para salir): ";
		cin >> abscisa;

		//Comprobamos que no haya metido un -1 (salir)
		if (abscisa != -1) {

			cout << "Introduzca la ordenada (entero positivo): ";
			cin >> ordenada;
		
			//Creamos un nuevo punto
			Punto2D punto(abscisa, ordenada);
			//Lo agregamos a la colecciónaa
			coleccion.Aniade(punto);

			//Pintamos un salto de linea
			cout << "\n";
	
		}

	} while (abscisa != -1); //El bucle termina al introducir un -1


	//Solicitamos los datos para crear una nueva circunferencia

	if (coleccion.Tamanio() == 0) {
	
		cout << "\nLa colección no contiene puntos. Fin del programa.\n\n";
	
	} else {
	
		//Pedimos los datos de la circunferencia
		cout << "\nIntroduccion de circunferencia...\n";
		
		cout << "Introduzca el radio de la circunferencia: ";
		cin >> radio_circunferencia;

		cout << "Introduzca la abscisa del centro de la circunferencia: ";
		cin >> abscisa; //reutilizamos esta variable

		cout << "Introduzca la ordenada del centro de la circunferencia: ";
		cin >> ordenada; //reutilizamos esta variable

		//Creamos un nuevo punto2D para el centro de la circunferencia
		Punto2D punto_circunferencia(abscisa, ordenada);

		//Creamos un nuevo objeto circunferencia con su radio y su punto centro
		Circunferencia circunferencia(radio_circunferencia, punto_circunferencia);

		//Pintamos los valores en la consola
		cout << "\nLos puntos que estan dentro de la circunferencia son:\n";

		//Recorremos los puntos introducidos
		for (int i = 0; i < coleccion.Tamanio(); i++) {
	
			//Obtenemos el punto (para hacer mas legible el codigo)
			Punto2D punto = coleccion.Elemento(i);

			//Si la circunferencia contiene el punto...
			if (circunferencia.ContienePunto(punto)) {
		
				//...lo pintamos
				cout << "x = " << punto.GetAbscisa() << ", y = " << punto.GetOrdenada() << "\n";

			}

		}

		//Pintamos un salto de línea
		cout << "\n";

	}
	
	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");

}