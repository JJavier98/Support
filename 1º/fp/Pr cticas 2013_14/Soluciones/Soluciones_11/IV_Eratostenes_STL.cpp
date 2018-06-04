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
// EJERCICIO 14 (vector de la STL)
//
/*	
	La criba de Erat�stenes (Cirene, 276 a. C. - Alejandr�a, 194 a. C.) es 
	un algoritmo que permite hallar todos los n�meros primos menores que un 
	n�mero natural dado n.
	
	El procedimiento �manual� consiste en escribir todos los n�meros naturales 
	comprendidos entre 2 y n, y tachar los n�meros que NO son primos de la 
	siguiente manera: el primero (el 2) se declara primo y se tachan todos sus
	m�ltiplos; se busca el siguiente n�mero entero que no ha sido tachado, 
	se declara primo y se procede a tachar todos sus m�ltiplos, y as� 
	sucesivamente. El proceso termina cuando el cuadrado del n�mero entero es 
	mayor o igual que el valor de n.

	La resoluci�n de este programa se realiza usando la clase "Eratostenes":

	1) Representaci�n: Usa un vector de la STL como dato miembro privado. 

	2) Ofrece los m�todos:  

	* void CalculaHasta(int n) 
		Calcula los primos menores que n.

	* int TotalCalculados(void) 
		Devuelve cu�ntos primos hay actualmente almacenados.

	* int Elemento(int indice) 
		Devuelva el indice-�simo primo.

	* int GetN(void) 
		Calcula el m�ximo valor.

	Los n�meros resultantes de la "criba" se almacenan en el objeto de la clase.  
	Se establece un l�mite de TAMANIO = 500 valores para este almac�n.

*/
/*********************************************************************/

#include <iostream>
#include <iomanip>

#include <vector>	// Para la almacenar los primos calculados

using namespace std;

///////////////////////////////////////////////////////////////////////

class Eratostenes 
{

private:

	// Datos asociados a la estructura de datos empleada para guardar 
	// los n�meros primos (vector de la STL)

	vector <int> vector_privado;

	// Datos espec�ficos de la clase Eratostenes 

	int n; // M�ximo numero --> Se calculan los primos menores o iguales a "n"


public:
	
	/*****************************************************************/
	// Constructor sin argumentos

	Eratostenes (void) 
	{
		n = 0; 
	}

	/*****************************************************************/
	// C�lculo de los primos por la criba de Erat�stenes. 
	// IMPORTANTE: El m�todo ajusta el valor del m�ximo para que no 
	// supere la capacidad del vector. 

	void CalculaHasta (int max)
	{
		// Actualizar "n". Al usar un vector de la STL no nos preocupamos 
		// por la capacidad del vector. Se reajustar� si es preciso.

		n = max; 

		// Empleremos un vector local (vector de la STL) de datos l�gicos. 
		// "primos[i]" ser� TRUE si "i" es primo. 
		// Inicialmente se considerar�n todos primos y se ir�n "tachando" 
		// (fij�ndose a FALSE) los valores no-primos. 

		vector <bool> primos; 

		for (int i=0; i<n; i++)		// Inicializaci�n a TRUE
			primos.push_back(true);

		for (int num=2; num*num <= n; num++) { // empezar por num=2 y 
											   // terminar si num^2 > n		
			if (primos[num]) {

				for (int k=2; k*num <= n; k++) { // marcar los m�ltiplos de   
					primos[k*num] = false;		 // num como no-primos
				}
			} // if (primos[num])

		} // for num

			
		// Ya est�n "tachados" los n�meros no-primos. 
		// Ahora recorremos "primos" completamente y copiamos a 
		// "vector_privado" �nicamente los primos. 


		int pos = 0; 

		for (int num=1; num < n; num++) { // no es preciso pasar de "n": 
										  // de hecho, no queremos primos 
			if (primos[num]) {			  // mayores que "n"

				vector_privado.push_back (num);  
				pos++;
			}
		}

	//	total_utilizados = pos;		// n�mero real de primos guardados

	}

	/*****************************************************************/
	// M�todos de lectura (Get) de los datos individuales 

	// Devuelve el n�mero real de primos calculados y almacenados. 
	// Podr� accederse a ellos con el m�todo Elemento(). 
	// Todos son menores que "n" 

	int TotalCalculados()
	{
		return (vector_privado.size());
	}
	
	// Devuelve el n�mero mayor que todos los primos almacenados. 
	// El el valor que se us� para generar los primos. 

	int GetN()
	{
		return n;
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

};

///////////////////////////////////////////////////////////////////////

int main()
{

	// Crear conjunto de primos (vac�o) --> 

	Eratostenes primos;


	// Pedir y filtrar "n" 

	int n;

	do {
		cout << "Generar primos menores que el valor : ";
		cin >> n;
	} while (n < 0);


	// Calcular primos menores que "n" usando la criba de Erat�stenes

	primos.CalculaHasta(n);
	
	cout << "Calculados los primos menores que " 
		 << primos.GetN() << endl << endl;


	// Consultar cu�ntos primos se han calculado 

	int tope = primos.TotalCalculados();

	cout << "Encontrados = " << tope << " primos" << endl;
	cout << endl;


	// Mostrar los primos calculados 

	const int MAX_LINE = 10; // Mostrar MAX_LINE n�meros por l�nea 
	char separador;

	for (int i=0; i<tope; i++) {

		if ((i+1)%MAX_LINE == 0) 
			separador = '\n';
		else 
			separador = ' ';
		cout << setw(4) << primos.Elemento(i) << separador;
	}

	cout << endl << endl;

	cout << "\n\n";
	system ("pause");
}