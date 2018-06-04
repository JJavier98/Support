/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
// GRADO EN INGENIER�A INFORM�TICA
//
// CURSO 2013-2014
// (C) JUAN CARLOS CUBERO TALAVERA
// (C) FRANCISCO JOS� CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACI�N E INTELIGENCIA ARTIFICIAL
//
// RELACI�N DE PROBLEMAS VI
// EJERCICIO 3 
//
/*	
	En este ejercico se ampl�a la clase MiVectorCaracteres con el 
	m�todo RECURSIVO:
	
		bool EsPalindromoRecursivo (int izda, int dcha)

	Este m�todo indica si el vector es un pal�ndromo entre las posiciones 
	"izda" y "dcha", es decir, que se lee igual de izquierda a derecha que 
	de derecha a izquierda considerando los extremos indicados. 
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

	MiVectorCaracteres() : total_utilizados (0)	{}

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
	// Devuelve TRUE si el vector es un pal�ndromo entre las posiciones 
	// dadas por "izda" y "dcha".
	// PRE: 0 <= izda <= dcha <= TotalUtilizados()-1

	bool EsPalindromoRecursivo (int izda, int dcha)
	{
		if (izda > dcha)	// Caso base 1 --> Es un pal�ndromo
							// Se cruzan los �ndices (tama�o par)
			return true;	// Han ido coincidiendo todas las parejas 
							// (vector_privado[izda],vector_privado[dcha])
		else 

			if (izda == dcha) // Caso base 2 --> Es un pal�ndromo
							  // Coinciden los �ndices (tama�o impar)
				return true;  // Han ido coincidiendo todas las parejas 
							  // (vector_privado[izda],vector_privado[dcha])
			else 

				if (vector_privado[izda] == vector_privado[dcha])  
					
					// Hay que seguir buscando. Observad que la funci�n 
					// devuelve el valor que se obtiene en el caso base 

					return EsPalindromoRecursivo (izda+1, dcha-1);

				else // Caso base 3 --> No es un pal�ndromo
					 // porque se encuentra una discrepancia en la pareja 
					 // (vector_privado[izda],vector_privado[dcha])

					return false;
	}
	/*****************************************************************/
};

///////////////////////////////////////////////////////////////////////

/*********************************************************************/

int main (void)
{
	MiVectorCaracteres vector1, vector2, vector3;
	int tope;

	/************************/
	// A�adir datos a vector1

	vector1.Aniade('H');
	vector1.Aniade('o');
	vector1.Aniade('o');
	vector1.Aniade('H');

	// Mostrar el contenido de vector1

	tope = vector1.TotalUtilizados();
	for (int i=0; i<tope; i++)
		cout  << vector1.Elemento(i) << " ";

	if (vector1.EsPalindromoRecursivo(0, vector1.TotalUtilizados()-1))
		cout << "\nEs un pal�ndromo";
	else
		cout <<"\nNo es un pal�ndromo";
	cout << endl << endl; 

	/************************/
	// A�adir datos a vector2

	vector2.Aniade('H');
	vector2.Aniade('o');
	vector2.Aniade('l');
	vector2.Aniade('a');
	vector2.Aniade('l');
	vector2.Aniade('o');
	vector2.Aniade('H');

	// Mostrar el contenido del vector

	tope = vector2.TotalUtilizados();
	for (int i=0; i<tope; i++)
		cout  << vector2.Elemento(i) << " ";

	if (vector2.EsPalindromoRecursivo(0, vector2.TotalUtilizados()-1))
		cout << "\nEs un pal�ndromo";
	else
		cout <<"\nNo es un pal�ndromo";
	cout << endl << endl; 

	/************************/
	// A�adir datos a vector3

	vector3.Aniade('H');
	vector3.Aniade('o');
	vector3.Aniade('l');
	vector3.Aniade('a');
	vector3.Aniade('k');
	vector3.Aniade('o');
	vector3.Aniade('H');

	// Mostrar el contenido del vector

	tope = vector3.TotalUtilizados();
	for (int i=0; i<tope; i++)
		cout  << vector3.Elemento(i) << " ";

	if (vector3.EsPalindromoRecursivo(0, vector3.TotalUtilizados()-1))
		cout << "\nEs un pal�ndromo";
	else
		cout <<"\nNo es un pal�ndromo";
	cout << "\n\n";

	system ("pause");
	return (0);
}