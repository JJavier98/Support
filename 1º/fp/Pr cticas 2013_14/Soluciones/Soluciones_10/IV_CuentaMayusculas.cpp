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
// EJERCICIO 9
//
/*	
	Este programa lee caracteres hasta que se encuentra un punto �.�. 
	Entonces muestra el n�mero de veces que aparece cada una de las letras 
	may�sculas.
*/
/*********************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

///////////////////////////////////////////////////////////////////////

class MiVectorEnteros 
{

private:

	static const int TAMANIO = 50;
	int vector_privado[TAMANIO];
	int total_utilizados;

public:
	
	/*****************************************************************/
	// Constructor sin argumentos

	MiVectorEnteros() 
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
	
	void Aniade(int nuevo)
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

	int Elemento(int indice)
	{
		return vector_privado[indice];
	}

	/*****************************************************************/
	// Sustituye la componente con �ndice "indice_componente" por el 
	// valor nuevo.
	// PRE: la posici�n dada por "indice_componente" es correcta.
	// Si no es correcta, no hace nada.

	void Modifica (int indice_componente, int nuevo)
	{
		if ((indice_componente >= 0)  &&  (indice_componente < total_utilizados))

			vector_privado[indice_componente] = nuevo;
	}		

	/*****************************************************************/

};

///////////////////////////////////////////////////////////////////////

/*********************************************************************/
// Devuelve TRUE si el car�cter recibido es una letra may�scula 

bool EsMayuscula (char c)
{
	return ((c >= 'A') && (c <= 'Z'));
}

/*********************************************************************/

int main()
{

	int num_casillas = 'Z'-'A'+1; // N�mero de letras may�sculas

	MiVectorEnteros contador_mayusculas; 	// Vector de contadores. 
	// contador_mayusculas.Elemento(0) --> n�mero de 'A'
	// contador_mayusculas.Elemento(1) --> n�mero de 'B'
	//				......
	// contador_mayusculas.Elemento(num_casillas-1) --> n�mero de 'Z'


	// Iniciar (a ceros) el vector de contadores
	//
	// MUY IMPORTANTE: no puede hacerse con el ciclo: 
	// 	for (int pos=0; pos <num_casillas; pos++) 
	//		contadores.Modifica(pos, 0);
	// porque aunque efectivamente pondr�a todas las casillas a cero, el 
	// m�todo Modifica() no cambia el valor de "total_utilizados". De hecho, 
	// con la clase proporcionada solo es posible su modificaci�n con el 
	// m�todo Aniade()

	for (int pos=0; pos <num_casillas; pos++) 
		contador_mayusculas.Aniade(0);

	// Lectura de datos. Como el n�mero de carcateres leidos es desconocido 
	// y la lectura finaliza con un car�cter especifico debe usarse un ciclo 
	// con lectura adelantada

	const char TERMINADOR = '.';
	char caracter_leido;

	caracter_leido = cin.get();	// lectura adelantada 

	while (caracter_leido != TERMINADOR) {

		if (EsMayuscula (caracter_leido)) {

			// casilla que le corresponde al car�cter (may�scula) le�do.
			int posicion = caracter_leido-'A';	

			// Incrementa en uno el valor almacenado
			contador_mayusculas.Modifica(posicion, 
				                contador_mayusculas.Elemento(posicion)+1); 
		}

		caracter_leido = cin.get();	// lectura adelantada 

	} // while  (caracter_leido != TERMINADOR)


	// Presentaci�n del resultado

	cout  << "Frecuencias absolutas de las may�sculas: \n";	

	int tope = contador_mayusculas.TotalUtilizados();

	for (int i=0; i<tope; i++) {

		char c = 'A'+i;  // IMPORTANTE: Transformar a char el valor int
		cout  << setw(3) << c <<setw(3)<< contador_mayusculas.Elemento(i) <<endl;	
	}
	cout << endl; 

	cout << "\n\n";
	system ("pause");

	return (0);
}