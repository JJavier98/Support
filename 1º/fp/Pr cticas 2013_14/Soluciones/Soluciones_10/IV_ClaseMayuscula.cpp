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
// EJERCICIO 10
//
/*	
	Programa que implementa la clase Mayusculas para ofrecer la funcionalidad 
	necesaria para realizar la cuenta de las mayúsculas presentes en una 
	secuencia de caracteres. 
	
	La funcionalidad mínima exigida es la de proporcionar los métodos:
	
		void IncrementaCuenta (char mayuscula);
		int CuantasHay (char mayuscula);

*/
/*********************************************************************/

#include <iostream>
#include <iomanip>

#include <vector>  // Para usar los <vector> de la STL
#include <string>  // Para usar objetos string

using namespace std;


///////////////////////////////////////////////////////////////////////

class Mayusculas 
{

private:

	static const int num_mayusculas = 'Z'-'A'+1; // Número de letras mayúsculas

	vector <int> contador_mayusculas;	// Vector de contadores. 

	// Vector de contadores. 
	// contador_mayusculas[0] --> número de 'A'
	// contador_mayusculas[1] --> número de 'B'
	//				......
	// contador_mayusculas[contador_mayusculas.size()-1] --> número de 'Z'

public:

	/*****************************************************************/
	// Constructor sin argumentos
	// Iniciar (a ceros) el vector de contadores

	Mayusculas() 
	{
		for (int pos=0; pos <num_mayusculas; pos++) 
			contador_mayusculas.push_back (0); 
	}

	/*****************************************************************/
	// Incrementa en uno el valor asociado a "mayuscula"
	// PRE: 'A' <= mayuscula <= 'Z'

	void IncrementaCuenta (char mayuscula)
	{
		int posicion = mayuscula-'A';	
		contador_mayusculas[posicion] = contador_mayusculas[posicion]+1;
	}

	/*****************************************************************/
	// Devuelve el número de apariciones de "mayuscula"
	// PRE: 'A' <= mayuscula <= 'Z'

	int CuantasHay (char mayuscula)
	{
		return (contador_mayusculas[mayuscula-'A']);
	}

};

///////////////////////////////////////////////////////////////////////


/*********************************************************************/
// Devuelve TRUE si el carácter recibido es una letra mayúscula 

bool EsMayuscula (char c)
{
	return ((c >= 'A') && (c <= 'Z'));
}

/*********************************************************************/


int main()
{
	// "mays_leidas_de_cin" es un objeto que se empleará para contar las 
	// mayúsculas que se van a leer de cin. 

	Mayusculas mays_leidas_de_cin;
	

	// Lectura de datos. Como el número de carcateres leidos es desconocido 
	// y la lectura finaliza con un carácter especifico debe usarse un ciclo 
	// con lectura adelantada

	const char TERMINADOR = '.';
	char caracter_leido;

	caracter_leido = cin.get();	// lectura adelantada 

	while (caracter_leido != TERMINADOR) {

		if (EsMayuscula (caracter_leido))												
			
			// Incrementa el número de apariciones del caracter leido 

			mays_leidas_de_cin.IncrementaCuenta(caracter_leido);


		caracter_leido = cin.get();	// lectura adelantada 

	} // while  (caracter_leido != TERMINADOR)


	// Presentación del resultado

	cout  << "Frecuencias absolutas de las mayúsculas leidas: \n";	

	for (char c='A'; c<='Z'; c++) {

		int num_veces_c = mays_leidas_de_cin.CuantasHay(c);
		cout <<setw(3) << c << setw(3) <<  num_veces_c << endl;	
	}
	cout << endl; 




	// Ahora mostramos el uso de esta clase con una fuente de datos 
	// diferente: los caracteres se toman de un dato string (cadena)

	string cadena; 

	// "mays_leidas_de_string" es un objeto que se empleará para contar las 
	// mayúsculas que se encuentran en un dato string. 

	Mayusculas mays_leidas_de_string;


	// Lectura de datos (lectura del string). 

	cin.ignore(); // Eliminar del buffer de entrada el '\n'
				  // para permitir la lectura corrrecta del string

	cout << "Introduzca una cadena de caracteres: ";
	getline (cin, cadena); 
	
	// Recorrido caracter a caracter de la cadena

	char caracter_actual; // Cada uno de los caracteres del string

	for (int pos=0; pos < cadena.length(); pos++) {

		caracter_actual = cadena[pos];

		if (EsMayuscula (caracter_actual))												
			
			// Incrementa el número de apariciones del caracter procesado 

			mays_leidas_de_string.IncrementaCuenta(caracter_actual);

	} // for (int pos=0; pos < cadena.length(); pos++) 


	// Presentación del resultado

	cout  << "Frecuencias absolutas de las mayúsculas del string: \n";	

	for (char c='A'; c<='Z'; c++) {

		int num_veces_c = mays_leidas_de_string.CuantasHay(c);
		cout <<setw(3) << c << setw(3) <<  num_veces_c << endl;	
	}
	cout << endl; 

	cout << "\n\n";
	system ("pause");

	return (0);
}