/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
// GRADO EN INGENIERÍA INFORMÁTICA
//
// CURSO 2013-2014
// (C) JUAN CARLOS CUBERO TALAVERA
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 5
// EJERCICIO 2 
//
/*	
	En este programa se usa la clase Punto2D para representar un punto en 
	R^2 y se emplea la clase Circunferencia parfa representar circunferencias 
	(recordad el ejercicio 33 de la Relación de Problemas III).
	
	La clase "Circunferencia" se caracteriza por: 
		1) centro (Punto2D)
		2) radio  (double) 

	Se ofrecen métodos públicos para:  	
		1) Calcular la longitud de la circunferencia.
		2) Calcular el área del círculo interior.
		3) Obtener el valor del centro.
		4) Obtener el valor del diámetro.
		5) Calcular si la circunferencia contiene a un punto dado. 
			Un punto (x, y) está dentro de una circunferencia con 
			centro (x_0, y_0) y radio r si se verifica que:
				(x-0 - x)^2 + (y_0 - y)^2 <= r^2
*/

/*********************************************************************/

#include <iostream>
#include <cctype>
#include <cmath>
#include <iomanip>
using namespace std;

/*********************************************************************/
// Función global (asociada a la constante PRECISION_SON_IGUALES) que
// permite que dos números reales muy próximos sean considerados iguales.

const double PRECISION_SON_IGUALES = 1e-6;

bool SonIguales(double uno, double otro) 
{
	return (abs(uno-otro) <= PRECISION_SON_IGUALES);
}

///////////////////////////////////////////////////////////////////////

class Punto2D
{

private:
	double x;
	double y;

public:
	
	/*****************************************************************/
	// Constructor con argumentos

	Punto2D (double abscisaPunto, double ordenadaPunto)
	{
		SetCoordenadas (abscisaPunto, ordenadaPunto);
	}

	/*****************************************************************/
	// Método Set para fijar las coordenadas

	void SetCoordenadas (double abscisaPunto, double ordenadaPunto)
	{
		x = abscisaPunto;
		y = ordenadaPunto;
	}

	/*****************************************************************/
	// Métodos Get para leer las coordenadas

	double GetX()
	{
		return x;
	}
	double GetY()
	{
		return y;
	}

	/*****************************************************************/
	// Calcula si dos puntos son iguales 

	bool EsIgual (Punto2D otro)
	{
		return (SonIguales(x,otro.x) && SonIguales(y,otro.y));
	}

	/*****************************************************************/
	// Calcula la distancia Euclídea del punto (objeto implícito) a 
	// otro que se recibe como argumento 

	double DistanciaEuclidea (Punto2D otro)
	{
		double dif_x = pow (x - otro.x, 2);
		double dif_y = pow (y - otro.y, 2);

		return (sqrt(dif_x + dif_y));
	}
	/*****************************************************************/
};

///////////////////////////////////////////////////////////////////////

class Circunferencia
{

private:

	static const double PI;		
	
	Punto2D centro;	// centro de la circunferencia
	double radio;	// longitud del radio

public:

	/*****************************************************************/
	// Constructor con argumentos

	Circunferencia (Punto2D el_centro, double el_radio) : centro (el_centro)
	{
		radio  = el_radio; 
	}

	/*****************************************************************/
	// Métodos Get
	
	Punto2D GetCentro ()
	{
		return (centro);
	}

	double GetRadio ()
	{
		return (radio);
	}

	double GetDiametro ()
	{
		return (radio*2);
	}

	/*****************************************************************/
	// Calcula la longitud de la circunferencia

	double Longitud()
	{
		return (2.0 * PI * radio);
	}

	/*****************************************************************/
	// Calcula el área del círculo
	
	double Area()
	{
		return (PI * radio * radio);
	}

	/*****************************************************************/
	// Calcular si la circunferencia contiene a un punto dado.
	/*
		Un punto (x, y) está dentro de una circunferencia con 
		centro (x_0, y_0) y radio r si se verifica que:
			(x-0 - x)^2 + (y_0 - y)^2 <= r^2
	*/

	bool Contiene (Punto2D un_punto)
	{
		double dif_x = pow (centro.GetX() - un_punto.GetX(), 2);
		double dif_y = pow (centro.GetY() - un_punto.GetY(), 2);

		return (dif_x + dif_y <= radio*radio);
	}

	/*****************************************************************/
	// Calcular si la circunferencia contiene a un punto dado 
	// usando un test explícito sobre la distancia Euclídea
	/*
		Un punto P(x, y) está dentro de una circunferencia con 
		centro C(x_0, y_0) y radio r si se verifica que:
			DistaciaEuclidea (P, C) <= r
	*/

	bool ContieneAlternativo (Punto2D un_punto)
	{
		Punto2D el_centro = GetCentro();
		double distancia = el_centro.DistanciaEuclidea (un_punto);
		
		return (distancia <= radio);
	}

	/*****************************************************************/
};

const double Circunferencia :: PI = 3.1415926;


///////////////////////////////////////////////////////////////////////

/*********************************************************************/


int main()
{
	cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales 

	double un_radio; 
	double centro_x, centro_y;

	cout << "Coordenada X del centro = ";
	cin >> centro_x; 

	cout << "Coordenada Y del centro = ";
	cin >> centro_y; 

	cout << "Introduzca el radio = ";
	cin >> un_radio; 


	// Crea un dato Punto2D y rellena las coordenadas con los 
	// valores leidos, para poder pasarlo al constructor de la 
	// clase Circunferencia

	Punto2D un_punto (centro_x, centro_y);


	// Creación de un objeto Circunferencia --> constructor

	Circunferencia mi_circunferencia (un_punto, un_radio);


	// Uso de los métodos Get

	Punto2D el_centro = mi_circunferencia.GetCentro(); 

	cout << "\nCircunferencia centrada en (" 
		 << setw(6) << setprecision(2) << el_centro.GetX() 
		 << ", " << setw(6) <<setprecision(2) << el_centro.GetY() 
		 << ") y diámetro " << setw(6) << setprecision(2) 
		 << mi_circunferencia.GetDiametro() << endl;

	// Uso de los métodos de cálculo sencillos

	cout << "\nLongitud de la circunferencia = " 
		<< setw(6) << setprecision(2) << mi_circunferencia.Longitud();
	cout << "\nArea del circulo = " 
		<< setw(6) << setprecision(2) << mi_circunferencia.Area();


	// Cálculo de la pertenencia (o no) de una serie de puntos.

	bool sigo = true; 

	while (sigo) {
	
		double punto_x, punto_y;

		cout << "\n\nPertenencia de un punto al círculo.\n";

		cout << "\tCoordenada X del punto = ";
		cin >> punto_x; 
		cout << "\tCoordenada Y del punto = ";
		cin >> punto_y; 

		// Crea un dato CoordenadasPunto2D y rellena los campos del struct 
		// con los valores leidos, para poder pasarlo al método Contiene()

		Punto2D un_punto (punto_x, punto_y);

		if (mi_circunferencia.Contiene(un_punto)) 
			cout << "\tEl punto SI está contenido en la circunferencia\n";
		else 
			cout << "\tEl punto NO está contenido en la circunferencia\n";

		if (mi_circunferencia.ContieneAlternativo(un_punto)) 
			cout << "\tEl punto SI está contenido en la circunferencia\n";
		else 
			cout << "\tEl punto NO está contenido en la circunferencia\n";


		// Preparando un nuevo test

		char respuesta;
		
		cout << "\nSi desea un nuevo test introduzca \'S\' --> "; 
		cin >> respuesta; 

		if (toupper(respuesta) != 'S') 
			sigo = false; 
	
	} // while (sigo)

	cout << "\n\n";
	system("pause");
}