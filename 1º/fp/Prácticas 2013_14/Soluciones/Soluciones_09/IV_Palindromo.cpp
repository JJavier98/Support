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
// EJERCICIO 1 
//
/*	
	En este ejercico se ampl�a la clase MiVectorCaracteres con el m�todo:
	
		bool EsPalindromo (void)

	Este m�todo indica si el vector es un pal�ndromo, es decir, que se 
	lee igual de izquierda a derecha que de derecha a izquierda. 
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
	// Devuelve TRUE si el vector es un pal�ndromo. 
	
	bool EsPalindromo()
	{
		bool es_palindromo;
		int izda, dcha; // Para recorrer el vector por los dos extremos 

		es_palindromo = true;
		
		izda = 0;	// De izqierda a derecha
		dcha = total_utilizados - 1;	// De derecha a izquierda

		while (izda < dcha && es_palindromo) {

			if (vector_privado[izda] != vector_privado[dcha])

				es_palindromo = false; // terminar

			else{	// seguir buscando

				izda++; 
				dcha--;
			}

		} // while (izda < dcha && es_palindromo)

		return es_palindromo;
	}

	/*****************************************************************/
};

///////////////////////////////////////////////////////////////////////

/*********************************************************************/

int main()
{
	MiVectorCaracteres vector;

	// A�adir datos al vector

	vector.Aniade('H');
	vector.Aniade('o');
	vector.Aniade('o');
	vector.Aniade('H');

	// Mostrar el contenido del vector

	int tope = vector.TotalUtilizados();
	for (int i=0; i<tope; i++)
		cout  << vector.Elemento(i) << " ";
	
	bool es_palindromo = vector.EsPalindromo();

	if (es_palindromo)
		cout << "\nEs un pal�ndromo";
	else
		cout <<"\nNo es un pal�ndromo";

	cout << "\n\n";
	system ("pause");

	return (0);
}