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
// EJERCICIO 9 (variante - STL)
//
/*	
	Este programa lee caracteres hasta que se encuentra un punto �.�. 
	Entonces muestra el n�mero de veces que aparece cada una de las letras 
	may�sculas.

	Esta versi�n emplea un <vector> de la STL en lugar de un objeto de 
	la clase MiVectorEnteros

*/
/*********************************************************************/

#include <iostream>
#include <iomanip>

#include <vector>  // Para usar los <vector> de la STL

using namespace std;


/*********************************************************************/
// Devuelve TRUE si el car�cter recibido es una letra may�scula 

bool EsMayuscula (char c)
{
	return ((c >= 'A') && (c <= 'Z'));
}

/*********************************************************************/

int main()
{

	const int NUM_MAYUSCULAS= 'Z'-'A'+1; // N�mero de letras may�sculas


	vector <int> contador_mayusculas;	// Vector de contadores. 
	// contador_mayusculas[0] contendr� el n�mero de 'A'
	// contador_mayusculas[1] contendr� el n�mero de 'B'
	//				......
	// contador_mayusculas[num_casillas-1] contendr� el n�mero de 'Z'


	// Iniciar (a ceros) el vector de contadores
	//
	// MUY IMPORTANTE: no puede hacerse con el ciclo: 
	// 	for (int pos=0; pos <num_casillas; pos++) 
	//		contadores[pos] = 0;
	// porque inicialmente contadores.size()=0 y el acceso a casillas no 
	// inicializadas provocar�a un error en tiempo de ejecuci�n. 
	
	for (int pos=0; pos <NUM_MAYUSCULAS; pos++) 
		contador_mayusculas.push_back (0); 

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
			contador_mayusculas[posicion] = contador_mayusculas[posicion]+1;
		}

		caracter_leido = cin.get();	// lectura adelantada 

	} // while  (caracter_leido != TERMINADOR)


	// Presentaci�n del resultado

	cout  << "Frecuencias absolutas de las may�sculas: \n";	

	int tope = contador_mayusculas.size();
	
	for (int i=0; i<tope; i++) {

		char c = 'A'+i;  // IMPORTANTE: Transformar a char el valor int
		cout  << setw(3) << c << setw(3) << contador_mayusculas[i] << endl;	
	}
	cout << endl; 

	// Observad que el ciclo anterior podr�a haberse escrito tambi�n: 
	//
	//	for (int i=0; i<NUM_MAYUSCULAS; i++) {
	//		......


	cout << "\n\n";

}
