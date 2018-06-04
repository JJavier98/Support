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
// EJERCICIO 2
//
/*	
	En este ejercico se ampl�a la clase MiVectorCaracteres con el m�todo:
	
		void Modifica (int indice_componente, char nuevo)

	para que sustituya la componente con �ndice "indice_componente" por 
	el valor "nuevo".

	Este m�todo est� pensado para modificar una componente ya existente, 
	pero no para a�adir componentes nuevas. Por tanto, en el caso de que 
	la componente no est� dentro del rango correcto, el m�todo no 
	modificar� nada.
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
	// Sustituye la componente con �ndice "indice_componente" por el 
	// valor nuevo.
	// PRE: la posici�n dada por "indice_componente" es correcta.
	// Si no es correcta, no hace nada.

	void Modifica (int indice_componente, char nuevo)
	{
		if ((indice_componente >= 0)  &&  (indice_componente < total_utilizados))

			vector_privado[indice_componente] = nuevo;
	}		

	/*****************************************************************/
};

///////////////////////////////////////////////////////////////////////

/*********************************************************************/

int main()
{
	MiVectorCaracteres vector;

	// A�adir datos al vector

	vector.Aniade('h');   
	vector.Aniade('E');
	vector.Aniade('L');
	vector.Aniade('L');
	vector.Aniade('O');
	
	cout  << "Vector original: \n";	

	// Mostrar el contenido del vector

	int tope = vector.TotalUtilizados();
	for (int i=0; i<tope; i++)
		cout  << vector.Elemento(i) << " ";	
	cout << endl; 


	vector.Modifica(-1,'A'); // posici�n incorrecta
	vector.Modifica( 1,'A'); // posici�n correcta
	

	cout  << "\nVector modificado: \n";	

	// Mostrar el contenido del vector

	tope = vector.TotalUtilizados();       
	for (int i=0; i<tope; i++)
		cout  << vector.Elemento(i) << " ";	
	cout << endl;

	cout << "\n\n";
	system ("pause");

	return (0);
}