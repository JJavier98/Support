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
// EJERCICIO 3 (variante)
//
/*	
	En este ejercicio comprobamos la validez de los m�todos presentados en 
	el ejercicio 3: 
		void IntercambiaComponentes(int pos_1, int pos2) 
		void Invierte(void) 
	usando el m�todo presentado en el ejercicio 1: 
		bool EsPalindromo (void)

	El procedimiento ser�: 
	1) Crear y rellenar con los mismos datos los vectores "v1" y "v2"
	2) Invertir "v1"
	3) A�adir a "v2" todos los elementos de "v1"
	4) Si el vector "v2" es un pal�ndromo, "Invierte()" es correcto.  

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

	MiVectorCaracteres v1, v2;
	int tope;


	// A�adir datos (los mismos) a los vectores

	v1.Aniade('H');
	v1.Aniade('o');
	v1.Aniade('l');
	v1.Aniade('a');
	
	v2.Aniade('H');
	v2.Aniade('o');
	v2.Aniade('l');
	v2.Aniade('a');

	// Podr�a pensarse que disponer de la operaci�n de asignaci�n entre 
	// objetos de la clase MiVectorCaracteres simplificar�a y clarificar�a 
	// el c�digo. Por ejemplo, en lugar de repetir las cuatro instrucciones 
	// Aniade() bastar�a con escribir, una vez relleno "v1"
	//		v2 = v1; 
	// Este punto se discutir� m�s adelante. 


	cout  << "Vector v1 original (v2 es id�ntico): \n";	

	// Mostrar el contenido de "v1"

	tope = v1.TotalUtilizados();
	for (int i=0; i<tope; i++)
		cout  << v1.Elemento(i) << " ";	
	cout << endl;


	// Invierte v1

	v1.Invierte(); 


	cout << endl;
	cout  << "Vector v1 invertido: \n";	

	// Mostrar el contenido de "v1"

	tope = v1.TotalUtilizados();       
	for (int i=0; i<tope; i++)
		cout  << v1.Elemento(i) << " ";	
	cout << endl;


	// A�adir a "v2" todos los elementos de "v1"

	tope = v1.TotalUtilizados();   

	for (int i=0; i<tope; i++)
		v2.Aniade (v1.Elemento(i));


	cout << endl;
	cout  << "Vector v2 ampliado, \"pegando\" v1: \n";	

	// Mostrar el contenido de "v2"

	tope = v2.TotalUtilizados();       
	for (int i=0; i<tope; i++)
		cout  << v2.Elemento(i) << " ";	
	cout << endl;


	// Comprobaci�n final 

	cout << endl;

	if (v2.EsPalindromo())
		cout << "v2 es un pal�ndromo --> Invierte() es corercto.";
	else
		cout << "v2 NO es un pal�ndromo --> Invierte() NO es corercto.";

	cout << "\n\n";
	system ("pause");

	return (0);
}