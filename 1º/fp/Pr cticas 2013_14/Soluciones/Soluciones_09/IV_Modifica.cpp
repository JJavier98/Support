/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
// GRADO EN INGENIERÍA INFORMÁTICA
//
// CURSO 2013-2014
// (C) JUAN CARLOS CUBERO TALAVERA
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 4
// EJERCICIO 2
//
/*	
	En este ejercico se amplía la clase MiVectorCaracteres con el método:
	
		void Modifica (int indice_componente, char nuevo)

	para que sustituya la componente con índice "indice_componente" por 
	el valor "nuevo".

	Este método está pensado para modificar una componente ya existente, 
	pero no para añadir componentes nuevas. Por tanto, en el caso de que 
	la componente no esté dentro del rango correcto, el método no 
	modificará nada.
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
	// Métodos de lectura (Get) de los datos individuales 

	int TotalUtilizados()
	{
		return total_utilizados;
	}

	int Capacidad()
	{
		return TAMANIO;
	}

	/*****************************************************************/
	// Añade un elemento al vector
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
	// PRE: la posición dada por "indice" es correcta.
	// Si no es correcta,el comportamiento no está definido.

	char Elemento(int indice)
	{
		return vector_privado[indice];
	}

	/*****************************************************************/
	// Sustituye la componente con índice "indice_componente" por el 
	// valor nuevo.
	// PRE: la posición dada por "indice_componente" es correcta.
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

	// Añadir datos al vector

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


	vector.Modifica(-1,'A'); // posición incorrecta
	vector.Modifica( 1,'A'); // posición correcta
	

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