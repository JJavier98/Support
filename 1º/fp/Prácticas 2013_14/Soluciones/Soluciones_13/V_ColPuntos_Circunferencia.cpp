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
// EJERCICIO 8 
//
/*	
	Se emplea la clase "ColeccionPuntos2D" para almacenar y gestionar una 
	colección de datos de tipo "Punto2D" (véase, por ejemplo el problema 2 
	de la Relación de Problemas 5). 
	NOTA: Por simplicidad se considerarn únicamente puntos cuyas coordenadas 
	son positivas.

	El programa lee del teclado un número indeterminado de datos de tipo
	"Punto2D" hasta que el usuario escribe -1 cuando el programa pide la 
	abscisa de un nuevo punto. 
	Los puntos leídos los almacena en un objeto "ColeccionPuntos2D".

	A continuación pide los datos necesarios, y crea un objeto 
	"Circunferencia" (véas el problema 2 de la Relación de Problemas 5), 
	y finalmente muestra cuáles de los puntos almacenados en la colección 
	está en el círculo delimitado por la circunferencia.
*/

/*********************************************************************/

#include <iostream>
#include <cctype>
#include <cmath>
#include <iomanip>

#include <vector>	// Para la almacenar la colección

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


class ColeccionPuntos2D 
{
private:

	// Datos asociados a la estructura de datos empleada para guardar 
	// los valores de la coleccion (vector de la STL)

	vector <Punto2D> vector_privado;

public:
	
	/*****************************************************************/
	// Constructor sin parámetros. 

	ColeccionPuntos2D (void) { }

	/*****************************************************************/
	// Constructor a partir de un punto. 

	ColeccionPuntos2D (Punto2D nuevo_punto) 
	{ 
		vector_privado.push_back (nuevo_punto);
	}

	/*****************************************************************/
	// Métodos de lectura (Get) sobre tamaño y capacidad de la colección 

	int NumPuntos()
	{
		return (vector_privado.size());
	}

	int CapacidadColeccion()
	{
		return (vector_privado.capacity());
	}


	/*****************************************************************/
	// Añade un elemento al vector
	
	void Aniade(Punto2D nuevo_punto)
	{
		vector_privado.push_back(nuevo_punto);
	}

	/*****************************************************************/
	// Devuelve el elemento de la casilla "indice" 
	// PRE: la posición dada por "indice" es correcta.
	// Si no es correcta,el comportamiento no está definido.

	Punto2D Elemento(int indice)
	{
		return (vector_privado[indice]);
	}

	/*****************************************************************/
	// Inserta un punto en la posición dada por "posicion".
	// Realiza un borrado físico (con desplazamiento y sustitución).
	// PRE: la posición dada por "posicion" es correcta.
	// Si no es correcta, no hace nada.
	
	void Inserta (int pos_insercion, Punto2D nuevo_punto)
	{
		int num_puntos = vector_privado.size();

		if (pos_insercion >= 0 && pos_insercion <= num_puntos){

			// CUIDADO: Hace falta una nueva casilla, por lo que añadiremos 
			// una nueva, sin importar el valor que tendrá ya que será 
			// sustituido en la primera iteración del ciclo siguiente. 

			vector_privado.push_back (nuevo_punto); 
			
			for (int i = num_puntos ; i > pos_insercion ; i--)
				vector_privado[i] = vector_privado[i-1];

			vector_privado[pos_insercion] = nuevo_punto;
		}
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
	// Calcular si la circunferencia contiene a un punto dado 
	// usando un test explícito sobre la distancia Euclídea
	/*
		Un punto P(x, y) está dentro de una circunferencia con centro 
		C(x_0, y_0) y radio r si DistaciaEuclidea (P, C) <= r
	*/

	bool Contiene (Punto2D un_punto)
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
	cout << endl << endl;


	// Pide una serie indeterminada de puntos y los almacena en una 
	// colección del tipo "ColeccionPuntos2D"

	// Creación de la colección

	ColeccionPuntos2D la_coleccion; 

	// Lectura de los puntos de la colección 

	double punto_x, punto_y;

	cout << "Coordenada X del punto = ";
	cin >> punto_x; 

	bool sigo = true; 

	while (punto_x != -1) {
	
		cout << "Coordenada Y del punto = ";
		cin >> punto_y; 

		// Crea un dato Punto2D y lo rellena con los valores leidos
		
		Punto2D un_punto (punto_x, punto_y);

		// Añade el punto a la colección

		la_coleccion.Aniade (un_punto);

		cout << "\t--> Num. de puntos: " << la_coleccion.NumPuntos();
		cout << endl << endl;

		cout << "Coordenada X del punto = ";
		cin >> punto_x; 

	} // while (sigo)

	// Mostrar los puntos de la colección

	int num_puntos = la_coleccion.NumPuntos();

	cout << endl << endl;
	cout << "La coleccion tiene " << setw(3) << num_puntos 
		 << " puntos." << endl;

	for (int num=0; num < num_puntos; num++) {

		Punto2D un_punto = la_coleccion.Elemento(num);

		cout << "\tPunto num. " << setw(3) << num+1 << " : ";
		cout << "(" << setw(5) << setprecision(2) << un_punto.GetX() << ", " 
			 << setw(5) << setprecision(2) << un_punto.GetY() << ")" << endl; 
	}
	cout << endl << endl;


	// Cálculo de la pertenencia (o no) de los puntos.

	cout << endl << endl;
	cout << "Comprobacion de pertenencia al circulo: " << endl;

	for (int num=0; num < num_puntos; num++) {

		Punto2D un_punto = la_coleccion.Elemento(num);

		cout << "\tPunto num. " << setw(3) << num+1 << " : ";
		cout << "(" << setw(5) << setprecision(2) << un_punto.GetX() << ", " 
			 << setw(5) << setprecision(2) << un_punto.GetY() << ")"; 

		if (mi_circunferencia.Contiene (un_punto)) 
			cout << " --> El punto SI esta contenido\n";
		else 
			cout << " --> El punto NO esta contenido\n";
	}

	cout << "\n\n";
	system("pause");

	return (0);
}