/****************************************************************************** 
	Fundamentos de Programación
	Grado en Ingeniería Informática

	2013 - FP
	------------------------------
	Usad la clase Punto2D para representar un punto en R2 y cread una clase 
	llamada Circunferencia que represente el centro con un dato del tipo 
	Punto2D (recordad el ejercicio 33 de la Relación de Problemas III).

	Añadid métodos para:
		a) obtener la longitud de la circunferencia,
		b) obtener el área del círculo interior,
		c) obtener el valor del centro de la circunferencia, 
		d) obtener el valor del diámetro de la circunferencia,
		e) saber si la circunferencia contiene a un punto. 

	Observad que el valor de π debe ser constante, y el mismo para todos los 
	objetos de la clase Circunferencia.

******************************************************************************/
#include <iostream>	//Inclusión de los recursos de E/S
#include <cmath>	//Inclusión de las funciones matemáticas

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
//Programa Principal 
int main() {    

	//Declara variables para guardar los datos
	double radio = 10;
	double x_centro = 1;
	double y_centro = 2;
	Punto2D punto_centro(x_centro, y_centro);

	Circunferencia circulo(radio, punto_centro);

	double x_contiene = 1;
	double y_contiene = 2;
	Punto2D punto_contiene(x_contiene, y_contiene);

	//Obtenemos los datos necesarios
	double longitud = circulo.ObtenerLongitud();
	double area = circulo.ObtenerArea();
	Punto2D centro = circulo.ObtenerCentro();
	double diametro = circulo.ObtenerDiametro();
	bool contiene = circulo.ContienePunto(punto_contiene);

	//Pintamos los valores en la consola
	cout << "Datos de la circunferencia:\n";
	cout << "Longitud = " << longitud << "\n";
	cout << "Area = " << area << "\n";
	cout << "Centro = " << centro.GetAbscisa() << "," << centro.GetOrdenada() << "\n";
	cout << "Diametro = " << diametro << "\n";
	cout << "¿Contiene punto (0 = No | 1 = Si)?: " << contiene << "\n\n";

	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");

}