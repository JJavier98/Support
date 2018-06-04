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
// EJERCICIO 14 (vector de la STL)
//
/*	
	La criba de Eratóstenes (Cirene, 276 a. C. - Alejandría, 194 a. C.) es 
	un algoritmo que permite hallar todos los números primos menores que un 
	número natural dado n.
	
	El procedimiento “manual” consiste en escribir todos los números naturales 
	comprendidos entre 2 y n, y tachar los números que NO son primos de la 
	siguiente manera: el primero (el 2) se declara primo y se tachan todos sus
	múltiplos; se busca el siguiente número entero que no ha sido tachado, 
	se declara primo y se procede a tachar todos sus múltiplos, y así 
	sucesivamente. El proceso termina cuando el cuadrado del número entero es 
	mayor o igual que el valor de n.

	La resolución de este programa se realiza usando la clase "Eratostenes":

	1) Representación: Usa un vector de la STL como dato miembro privado. 

	2) Ofrece los métodos:  

	* void CalculaHasta(int n) 
		Calcula los primos menores que n.

	* int TotalCalculados(void) 
		Devuelve cuántos primos hay actualmente almacenados.

	* int Elemento(int indice) 
		Devuelva el indice-ésimo primo.

	* int GetN(void) 
		Calcula el máximo valor.

	Los números resultantes de la "criba" se almacenan en el objeto de la clase.  
	Se establece un límite de TAMANIO = 500 valores para este almacén.

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
	// los números primos (vector de la STL)

	vector <int> vector_privado;

	// Datos específicos de la clase Eratostenes 

	int n; // Máximo numero --> Se calculan los primos menores o iguales a "n"


public:
	
	/*****************************************************************/
	// Constructor sin argumentos

	Eratostenes (void) 
	{
		n = 0; 
	}

	/*****************************************************************/
	// Cálculo de los primos por la criba de Eratóstenes. 
	// IMPORTANTE: El método ajusta el valor del máximo para que no 
	// supere la capacidad del vector. 

	void CalculaHasta (int max)
	{
		// Actualizar "n". Al usar un vector de la STL no nos preocupamos 
		// por la capacidad del vector. Se reajustará si es preciso.

		n = max; 

		// Empleremos un vector local (vector de la STL) de datos lógicos. 
		// "primos[i]" será TRUE si "i" es primo. 
		// Inicialmente se considerarán todos primos y se irán "tachando" 
		// (fijándose a FALSE) los valores no-primos. 

		vector <bool> primos; 

		for (int i=0; i<n; i++)		// Inicialización a TRUE
			primos.push_back(true);

		for (int num=2; num*num <= n; num++) { // empezar por num=2 y 
											   // terminar si num^2 > n		
			if (primos[num]) {

				for (int k=2; k*num <= n; k++) { // marcar los múltiplos de   
					primos[k*num] = false;		 // num como no-primos
				}
			} // if (primos[num])

		} // for num

			
		// Ya están "tachados" los números no-primos. 
		// Ahora recorremos "primos" completamente y copiamos a 
		// "vector_privado" únicamente los primos. 


		int pos = 0; 

		for (int num=1; num < n; num++) { // no es preciso pasar de "n": 
										  // de hecho, no queremos primos 
			if (primos[num]) {			  // mayores que "n"

				vector_privado.push_back (num);  
				pos++;
			}
		}

	//	total_utilizados = pos;		// número real de primos guardados

	}

	/*****************************************************************/
	// Métodos de lectura (Get) de los datos individuales 

	// Devuelve el número real de primos calculados y almacenados. 
	// Podrá accederse a ellos con el método Elemento(). 
	// Todos son menores que "n" 

	int TotalCalculados()
	{
		return (vector_privado.size());
	}
	
	// Devuelve el número mayor que todos los primos almacenados. 
	// El el valor que se usó para generar los primos. 

	int GetN()
	{
		return n;
	}

	/*****************************************************************/
	// Devuelve el elemento de la casilla "indice" 
	// PRE: la posición dada por "indice" es correcta.
	// Si no es correcta,el comportamiento no está definido.

	int Elemento(int indice)
	{
		return vector_privado[indice];
	}

	/*****************************************************************/

};

///////////////////////////////////////////////////////////////////////

int main()
{

	// Crear conjunto de primos (vacío) --> 

	Eratostenes primos;


	// Pedir y filtrar "n" 

	int n;

	do {
		cout << "Generar primos menores que el valor : ";
		cin >> n;
	} while (n < 0);


	// Calcular primos menores que "n" usando la criba de Eratóstenes

	primos.CalculaHasta(n);
	
	cout << "Calculados los primos menores que " 
		 << primos.GetN() << endl << endl;


	// Consultar cuántos primos se han calculado 

	int tope = primos.TotalCalculados();

	cout << "Encontrados = " << tope << " primos" << endl;
	cout << endl;


	// Mostrar los primos calculados 

	const int MAX_LINE = 10; // Mostrar MAX_LINE números por línea 
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