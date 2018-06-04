/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
// GRADO EN INGENIER�A INFORM�TICA
//
// CURSO 2013-2014
// (C) JUAN CARLOS CUBERO TALAVERA
// (C) FRANCISCO JOS� CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACI�N E INTELIGENCIA ARTIFICIAL
//
// RELACI�N DE PROBLEMAS 4
// EJERCICIO 3
//
/*	
	En este ejercico se ampl�a la clase MiVectorCaracteres con los m�todos:
	
	1)	void IntercambiaComponentes(int pos_1, int pos2) 

		Intercambia las componentes dadas por los �ndices "pos_1" y "pos_2". 
		Si alguno de los �ndices no es correcto el m�todo no hace nada. 

	2)	void Invierte() 
	
		Invierte el vector, de forma que se intercambian el primero con el 
		�ltimo, el segundo con el pen�ltimo, .... La implementaci�n est� 
		basada en IntercambiaComponentes() 
*/
/*********************************************************************/

#include <iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////

class MiVectorCaracteres 
{

private:

	static const int TAMANIO = 50;
	char vector_privado[TAMANIO];
	int total_utilizados;

public:
	
	/*****************************************************************/
	// Constructor sin argumentos

	MiVectorCaracteres() 
	{
		total_utilizados = 0;
	}

	/*****************************************************************/
	// M�todos de lectura (Get) de los datos individuales 

	int TotalUtilizados()
	{
		return total_utilizados;
	}

	int Capacidad()
	{
		return TAMANIO;
	}

	/*****************************************************************/
	// A�ade un elemento al vector
	// PRE: hay espacio para el nuevo elemento.
	// Si no lo hay, no hace nada.
	
	void Aniade(char nuevo)
	{
		if (total_utilizados < TAMANIO){
			vector_privado[total_utilizados] = nuevo;
			total_utilizados++;
		}
	}

	/*****************************************************************/
	// Devuelve el elemento de la casilla "indice" 
	// PRE: la posici�n dada por "indice" es correcta.
	// Si no es correcta,el comportamiento no est� definido.

	char Elemento(int indice)
	{
		return vector_privado[indice];
	}


	/*****************************************************************/

	// Intercambia los valores guardados en dos posiciones del vector.
	// PRE: pos_1 y pos_2 son posiciones v�lidas. 
	// Si no es as�, no se hace nada.

	void IntercambiaComponentes(int pos_1, int pos_2) 
	{
		if ((pos_1 >= 0) && (pos_2 >= 0) && 
			(pos_1 < total_utilizados) && (pos_2 < total_utilizados)) {

			char tmp; 
			tmp = vector_privado[pos_1];
			vector_privado[pos_1] = vector_privado[pos_2];
			vector_privado[pos_2] = tmp;
		}
	}		

	/*****************************************************************/

	// Invierte un vector, intercambiando el primer car�cter con el ultimo, 
	// el segundo con el pen�ltimo,... 
	
	void Invierte (void) 
	{
		
		int izda, dcha; // Para recorrer el vector por los dos extremos 
		
		izda = 0;	// De izqierda a derecha
		dcha = total_utilizados - 1;	// De derecha a izquierda

		while (izda < dcha) {

			IntercambiaComponentes (izda, dcha);
			izda++; 
			dcha--;
		} 	
	}

	/*****************************************************************/

};

///////////////////////////////////////////////////////////////////////

/*********************************************************************/


int main()
{

	MiVectorCaracteres vector;
	int tope;


	// A�adir datos al vector

	vector.Aniade('H');
	vector.Aniade('o');
	vector.Aniade('l');
	vector.Aniade('a');
	


	cout  << "Vector original: \n";	

	// Mostrar el contenido del vector: "Hola"

	tope = vector.TotalUtilizados();
	for (int i=0; i<tope; i++)
		cout  << vector.Elemento(i) << " ";	


	// Intercambia las componentes 1 y 3: "Halo"

	vector.IntercambiaComponentes(1,3);


	cout << "\n\n";
	cout  << "Vector modificado (1 con 3): \n";	

	// Mostrar el contenido del vector: "Halo"

	tope = vector.TotalUtilizados();       
	for (int i=0; i<tope; i++)
		cout  << vector.Elemento(i) << " ";	


	// Invierte el vector: "olaH"

	vector.Invierte();

	cout << "\n\n";
	cout  << "Vector invertido: \n";	

	// Mostrar el contenido del vector: "olaH"

	tope = vector.TotalUtilizados();       
	for (int i=0; i<tope; i++)
		cout  << vector.Elemento(i) << " ";	

	cout << "\n\n";
	system ("pause");

	return (0);
}
