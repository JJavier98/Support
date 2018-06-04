/*********************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2013-2014
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// Implementacion de la clase Matriz2D-1
//
// Implementacion del tipo Matriz2D_1
//
// Matriz 2D dinamica de datos "TipoBase" en la que cada fila es un 
// vector dinamico independiente. 
//
/*********************************************************************/

#include "Matriz2D-1.h"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;


/*********************************************************************/
// Constructor (1) sin argumentos (matriz vacia)
Matriz2D_1 :: Matriz2D_1(void)
	: filas(0), columnas(0), datos(0) 
{
}

//......

/*********************************************************************/
// CONSTRUCTOR PEDIDO EN EL EXAMEN: 
// Constructor que crea la matriz leyendo los datos de un fichero 
// mixto binario/texto. 
// El nombre del fichero se pasa como argumento.
// Este constructor lee del fichero los valores de los campos 
// "filas" y "columnas" (almacenados en binario en el fichero) y rellena 
// los datos que conforman la matriz desde a partir de los datos 
// almacenados (como texto) en el fichero "nombre"

Matriz2D_1 :: Matriz2D_1  (const char * nombre)
: filas(0), columnas(0), datos(0) 
{
	// Leer los datos del fichero
	RecuperaDatosDeFichero (nombre);
}

/*********************************************************************/
// Destructor
Matriz2D_1 :: ~Matriz2D_1(void) 
{
	LiberarMemoria();
}

/*********************************************************************/
// Método de lectura de las filas 
int Matriz2D_1 :: NumFilas (void) const
{
	return (filas);
}

/*********************************************************************/
// Método de lectura de las columnas
int Matriz2D_1 :: NumColumnas (void) const
{
	return (columnas);
}

//......

/*********************************************************************/
// Operador == 
bool Matriz2D_1 :: operator == (const Matriz2D_1 & otro) 
{
	// Si las dimensiones son diferentes, las matrices son distintas
	bool iguales = ((filas == otro.filas) && (columnas == otro.columnas));
	
	if (iguales) { // Comparar casilla a casilla

		for (int i = 0; (i<filas) && iguales; i++) {
			
			for (int j= 0; (j<columnas) && iguales; j++)
				
				if (datos[i][j] != otro.datos[i][j])
					iguales = false;
		}
	}
	return (iguales);
}

//......

/*********************************************************************/
// Operator ()
// PRE: 0 <= fila < NumFilas()
// PRE: 0 <= columna < NumColumnas()
TipoBase & Matriz2D_1 :: operator () (const int fila, const int columna)
{
	return (datos[fila][columna]);
}
TipoBase & Matriz2D_1 :: operator () (const int fila, const int columna) const
{
	return (datos[fila][columna]);
}

//......

/*********************************************************************/
// MÉTODO DEL EXAMEN: 
// Rellena una matriz (que ya existe) a partir de los datos presentes 
// en el fichero mixto (binario/texto) llamado "nombre". 
//
// Este método NO es un constructor: el objeto sobre el que se aplica 
// ya existe, por lo tanto, lo primero que debe hacerse es "limpiarlo" 
// y después, leer los valores almacenados en el fichero.
// 
// El nombre del fichero se pasa como argumento.
// Este método lee del fichero los valores de los campos "filas" y 
// "columnas" (almacenados en binario en el fichero) y rellena  los datos 
// que conforman la matriz desde a partir de los datos almacenados 
// (como texto) en el fichero "nombre".

void Matriz2D_1 :: LeeDeFichero (const char * nombre)
{
	// Limpiar el objeto: Liberar memoria reservada previamente
	LiberarMemoria (); 

	// Leer los datos del fichero
	RecuperaDatosDeFichero (nombre);
}

/*********************************************************************/
// MÉTODO DEL EXAMEN: 
// Guarda una matriz en el fichero mixto (binario/texto) llamado "nombre".
// 
// El nombre del fichero se pasa como argumento.
// Este método escribe en el fichero los valores de los campos "columnas" y 
// "filas" en este orden, en binario, y a continuación tantas lineas como 
// filas tenga la matriz. En cada línea escribe tantos datos como columnas 
// tiene la matriz, en formato texto.

void Matriz2D_1 :: GuardaEnFichero (const char * nombre)
{
	const int ANCHO = 9;

	ofstream fo (nombre, ios::binary);

	if (!fo) 
		cerr << "Error: no pudo crearse " << nombre << endl;

	else {
		fo.write ((const char *) &columnas, sizeof(int));
		fo.write ((const char *) &filas,    sizeof(int));

		if(datos != 0) {
			for (int i = 0; i < filas; i++) {
				for (int j = 0; j < columnas; j++)
					fo << setw(ANCHO) << datos[i][j] << " ";
				fo << endl;
			}
		}

		fo.close();
	}
}


//**********************************************
// METODOS PRIVADOS
//**********************************************
		
// Pedir memoria para alojar "fils"x"cols" datos
void Matriz2D_1 :: ReservarMemoria (int fils, int cols)
{
	datos = 0;

	if ((fils > 0) && (cols > 0)) {

		// Reservar vector de punteros
		datos = new TipoBase * [fils];

		// Reservar para cada una de las filas
		for(int i = 0; i < fils; i++)
			datos[i] = new TipoBase[cols];
	}
}

// Liberar la memoria ocupada
void Matriz2D_1 :: LiberarMemoria (void)
{
	if (datos) {
		
		for(int i = 0; i < filas; i++)
			delete [] datos[i];

		delete [] datos;
	}
}

// Copiar campos privados y datos de la matriz
void Matriz2D_1 :: CopiarDatos (const Matriz2D_1 & otro)
{
    // Copiar campos privados
    filas = otro.filas;
    columnas = otro.columnas;

	/*
    // Copiar cada una de las casillas 
	for (int f=0; f<filas; f++)
		for (int c=0; c<columnas; c++)
			datos[f][c] = otro.datos[f][c];
	*/

    // Copiar cada una de las filas
	for (int f=0; f<filas; f++)
		memcpy (datos[f], otro.datos[f], columnas*sizeof(TipoBase));
}

/*********************************************************************/
// Método PRIVADO que rellena un dato "Matriz2D_1" con los datos 
// guardados en el fichero mixto (binario/texto) llamado "nombre".
// 
// Lee el valor de los campos privados "columnas" y "filas" del 
// fichero, donde están en este orden y guardados en binario. 
// A continuación hay una exactamente "filas" líneas de texto 
// no vacías que contienen exactamente "columnas" valores 
// enteros cada una.
//
// Este método es usado por:
// 1) Constructor 
//       Matriz2D_1 :: Matriz2D_1 (const char * nombre); 
// 2) Método
//	void Matriz2D_1 :: LeeDeFichero (const char * nombre);

void Matriz2D_1 :: RecuperaDatosDeFichero (const char * nombre)
{
	// Inicializar "preventivamente" los miembros privados
	filas = columnas = 0;
	datos = 0;

	ifstream fi (nombre, ios::binary);

	if (!fi)

		cerr << "Error: no puede abrirse " << nombre << endl;

	else 
	{
		// Leer núm. de columnas y filas (en binario) y reservar 
		// la memoria necesaria.

		fi.read ((char *) &columnas, sizeof(int));
		fi.read ((char *) &filas,    sizeof(int));

		ReservarMemoria (filas, columnas);

		// Leer los valores (en texto) y guardarlos en la casilla 
		// correspondiente de la matriz

		for (int f=0; f<filas; f++)
			for (int c=0; c<columnas; c++) 
				fi >> datos[f][c]; 

		fi.close();
	}
}

//**********************************************
// OTRAS FUNCIONES
//**********************************************

void PintaMatriz (const Matriz2D_1 & m)
{
	int fils = m.NumFilas();
	int cols = m.NumColumnas();

	for (int f=0; f<fils; f++) {
		for (int c=0; c<cols; c++)
			cout << m(f,c) << " "; 
		cout << endl;
	}
	cout << endl; 
}
