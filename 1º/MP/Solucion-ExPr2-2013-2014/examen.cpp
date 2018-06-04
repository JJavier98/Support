/*********************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2013-2014
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// Examen Pr�ctico 2 (Junio 2014)
//
// Programa que muestra el funcionamiento de los nuevos m�todos de la 
// clase Matriz2D-1 pedidos en el examen pr�ctico 2:
//
//	* Constructor: 
//			Matriz2D-1 (const char * nombre_fichero); 
//	* M�todo de lectura: 
//			void LeeDeFichero (const char * nombre_fichero);
//	* M�todo de escritura: 
//			void GuardaEnFichero (const char * nombre_fichero);
//
/*********************************************************************/

#include "Matriz2D-1.h"

#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char *argv[]) 
{
	// Comprobar numero de argumentos  
	if (argc !=3) {
		cerr << "Error: Numero de argumentos incorrecto\n";
		cerr << "Formato: " << argv[0] << "<fich1> <fich2>\n";
		cerr << "   <fich1> es un fichero mixto con los datos de entrada.\n";
		cerr << "   <fich2> es un fichero mixto con los datos de salida.\n";
		exit (1);
	}

    // Prueba de los m�todos de lectura/escritura

    Matriz2D_1 m1 (argv[1]); // Constructor
    PintaMatriz (m1);

    m1.GuardaEnFichero (argv[2]); // M�todo de escritura

    Matriz2D_1 m2;
    m2.LeeDeFichero(argv[2]); // M�todo de lectura
    PintaMatriz (m2);

    if (m1==m2)
        cout << "Lectura y escritura correcta." << endl;
    else
        cout << "Error en la lectura y/o escritura." << endl;

	cout << endl << endl; 
	return (0);
}
