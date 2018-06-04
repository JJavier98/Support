/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
// GRADO EN INGENIER�A INFORM�TICA
//
// CURSO 2013-2014
// (C) JUAN CARLOS CUBERO TALAVERA
// (C) FRANCISCO JOS� CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACI�N E INTELIGENCIA ARTIFICIAL
//
// RELACI�N DE PROBLEMAS V
// EJERCICIOS 14 y 15
//
/*	
	Este programa presenta la clase MiMatrizRectangularCaracteres. 
	Esta clase es �til cuando se desea que forzosamente todas las filas 
	tengan el mismo n�mero de columnas, es decir, que sea una matriz 
	rectangular.

	Se emplea como dato miembro privado una matriz "cl�sica" en la forma:

		char matriz_privada[MAXIMO_FILAS][MAXIMO_COLUMNAS];

	y se ofrecen, entre otros, m�todos para:

	a)	Obtener el n�mero de filas y columnas utilizadas.

			int FilasUtilizadas();
			int ColumnasUtilizadas();

	b)	Obtener como el car�cter que hay en una fila y columna dadas.

			char Elemento (int fila, int columna);

	c) Devolver una fila y una columna completas, como un vector de la STL.

			vector <char> Fila    (int indice_fila);
			vector <char> Columna (int indice_columna);

	d) A�adir una fila entera. La fila ser� un vector de la STL.

			void Aniade(vector <char> fila_nueva);

	e-1) Encontrar un car�cter.

			bool ContieneCaracter (char buscado);

		Devuelve TRUE si la matriz contiene el car�cter "buscado"

	e-2) Encontrar un car�cter.

			PosicionEnMatriz PrimeraOcurrencia (char buscado);

		El valor devuelto contiene informaci�n acerca de la posici�n 
		(fila y columna) de "buscado".  En el caso de que no est� 
		contendr� {-1,-1}. 
		La consulta de la fila y la columna se delega en los m�todos de 
		la clase "PosicionEnMatriz" 

	f)	Comprobar si es igual a otra matriz rectangular.

			bool EsIgual_a (MiMatrizRectangularCaracteres otra_matriz);

	g)	Obtener la traspuesta de la matriz.

			MiMatrizRectangularCaracteres Traspuesta();

	h)	Comprobar si es sim�trica. 

			*	Puede hacerse calculando primero la traspuesta de la matriz 
				y viendo si es igual a su sim�trica, usando los m�todos 
				anteriores.

					bool EsSimetricaIneficiente()

			*	Tambi�n puede hacerse comprobando directamente si cada 
				componente es igual a su sim�trica y parando el recorrido 
				cuando encuentre una componente que no lo verifique.

					bool EsSimetricaEficiente()
*/
/*********************************************************************/


#include <iostream>
#include <vector>
#include <string>
using namespace std;

///////////////////////////////////////////////////////////////////////

class PosicionEnMatriz
{
private:
	int fila;
	int columna;

public: 
	
	/*****************************************************************/
	// Constructor por defecto
	// La posici�n {-1,-1} debe interpretarse como "posici�n no v�lida"
	// (resulta �til en m�todos de b�squeda, por ejemplo). 

	PosicionEnMatriz (void) : fila(-1), columna(-1) { }

	/*****************************************************************/
	// M�todo de escritura: establece simultaneamente los dos valores

	void SetPosicion (int la_fila, int la_columna)
	{
		fila = la_fila;
		columna = la_columna;
	}

	/*****************************************************************/
	// M�todos Get

	int GetFila (void)
	{
		return (fila);
	}
	
	int GetColumna (void)
	{
		return (columna);
	}

	/*****************************************************************/
	// Devuelve TRUE si la posici�n no es v�lida--> {-1,-1}

	bool EsPosicionNoValida (void)
	{
		return ((fila == -1) && (columna == -1));
	}
	/*****************************************************************/
};

///////////////////////////////////////////////////////////////////////

class MiMatrizRectangularCaracteres
{

private:

	static const int MAXIMO_FILAS = 50;
	static const int MAXIMO_COLUMNAS = 40;

	char matriz_privada[MAXIMO_FILAS][MAXIMO_COLUMNAS];

	int filas_utilizadas;
	int col_utilizadas;

public:

	/*
	Para obligar a que una matriz sea rectangular, lo podemos hacer 
	de varias formas. Por ejemplo:
	a)	El constructor de la matriz recibe "numero_de_columnas", que 
		indica el n�mero de columnas que deben tener todas las filas.
	b)	El constructor de la matriz recibe un vector. La longitud 
		(n�mero de casillas utilizadas) de dicho vector ser� el valor 
		que se use dentro de la matriz como "numero_de_columnas"

	Para permitir ambas formas, sobrecargamos el constructor.
	*/
	
	/*****************************************************************/
	// Constructor a)
	// Recibe "numero_de_columnas" que indica el n�mero de columnas 
	// que deben tener TODAS las filas.

	MiMatrizRectangularCaracteres (int numero_de_columnas)
		: filas_utilizadas(0), 
		  col_utilizadas(numero_de_columnas)
	{
	}

	/*****************************************************************/
	// Constructor b)
	// Recibe un vector STL. La longitud de dicho vector (num. de casillas) 
	// es el valor que se usa como "numero_de_columnas"

	MiMatrizRectangularCaracteres (vector <char> primera_fila)
		: filas_utilizadas(0), 
		  col_utilizadas (primera_fila.size())
	{
		Aniade(primera_fila); // Actualiza "filas_utilizadas"
	}

	/*****************************************************************/
	// M�todo de lectura: n�mero m�ximo de filas

	int CapacidadFilas()
	{
		return (MAXIMO_FILAS);
	}

	/*****************************************************************/
	// M�todo de lectura: n�mero m�ximo de columnas

	int CapacidadColumnas()
	{
		return (MAXIMO_COLUMNAS);
	}

	/*****************************************************************/
	// M�todo de lectura: n�mero real de filas usadas

	int FilasUtilizadas()
	{
		return (filas_utilizadas);
	}

	/*****************************************************************/
	// M�todo de lectura: n�mero real de columnas usadas

	int ColumnasUtilizadas()
	{
		return (col_utilizadas);
	}

	/*****************************************************************/
	// M�todo de lectura: devuelve el caracter que ocupa la casilla 
	// de coordenadas (fila, columna)

	char Elemento(int fila, int columna)
	{
		return (matriz_privada[fila][columna]);
	}

	/*****************************************************************/
	// Devuelve una fila completa, en forma de un vector de la STL

	vector <char> Fila (int indice_fila)
	{
		vector <char>  fila;

		for (int col=0; col<col_utilizadas; col++)
			fila.push_back (matriz_privada[indice_fila][col]);

		return (fila);
	}

	/*****************************************************************/
	// Devuelve una columna completa, en forma de un vector de la STL

	vector <char> Columna(int indice_columna)
	{
		vector <char> columna;

		for (int fil=0; fil<filas_utilizadas; fil++)
			columna.push_back (matriz_privada[fil][indice_columna]);

		return (columna);
	}

	/*****************************************************************/
	// A�ade una fila completa. La fila se porporciona en forma de un 
	// vector de la STL. 
	// PRE: el n�mero de casillas de "fila_nueva" es igual a "col_utilizadas"

	void Aniade(vector <char>  fila_nueva)
	{
		int numero_columnas;

		if (filas_utilizadas < MAXIMO_FILAS){

			numero_columnas = fila_nueva.size();

			if (numero_columnas == col_utilizadas){

				for (int col = 0; col < numero_columnas; col++)
					matriz_privada[filas_utilizadas][col]=fila_nueva.at(col);

				filas_utilizadas++;
			}
		}

	}

	/*****************************************************************/
	// Devuelve TRUE si la matriz contiene el car�cter "buscado"
	
	bool ContieneCaracter (char buscado)
	{
		bool encontrado = false;

		// Recorrido por columnas 

		int col = 0;

		while (col < col_utilizadas && !encontrado) {

			int fil=0;

			while (fil < filas_utilizadas && !encontrado) {

				if (matriz_privada[fil][col] == buscado)
					encontrado = true;
				
				fil++;

			} // while fil

			col++; 

		} // while col

		return (encontrado);
	}

	/*****************************************************************/
	// Encontrar un car�cter en la matriz y devolver su posici�n.
	// El valor devuelto contiene informaci�n acerca de la posici�n 
	// (fila y columna) de "buscado".  En el caso de que no est� 
	// contendr� {-1,-1}. 
	// La consulta de la fila y la columna se delega en los m�todos de 
	//	la clase "ParejaEnteros" 

	PosicionEnMatriz PrimeraOcurrencia (char buscado)
	{
		PosicionEnMatriz posicion_dato_buscado;
      
		bool encontrado = false;

		// Recorrido por filas 

		for (int i=0; i < filas_utilizadas && !encontrado ; i++){

			for (int j=0; j < col_utilizadas && !encontrado; j++){

				if (matriz_privada[i][j] == buscado){
					encontrado = true;
					posicion_dato_buscado.SetPosicion (i,j);
				}

			} // for j

		} // for i
      
		return (posicion_dato_buscado);
	} 

	/*****************************************************************/
	// Calcula si dos matrices rectangulares son iguales
	// PRE: las dos matrices tienen el mismo n�mero de filas y columnas.
	
	bool EsIgual_a (MiMatrizRectangularCaracteres otra_matriz)
	{
		bool iguales = true;

		for (int fil=0; fil<filas_utilizadas && iguales; fil++)
			for (int col=0; col<col_utilizadas && iguales; col++)
				iguales = (matriz_privada[fil][col] == 
						   otra_matriz.Elemento(fil, col));

		return (iguales);
	}

	/*****************************************************************/
	// Devuelve la traspuesta de la matriz.

	MiMatrizRectangularCaracteres Traspuesta()
	{
		// La traspuesta tiene tantas filas como columnas tiene la 
		// matriz original

		MiMatrizRectangularCaracteres traspuesta (filas_utilizadas);


		vector <char> columna;	// Las filas de la traspuesta ser�n las 
								// columnas de la original

		for (int col = 0; col < col_utilizadas; col++){

			columna = Columna(col);
			traspuesta.Aniade(columna); 
		}

		return (traspuesta);
	}

	/*****************************************************************/
	// Calcula si una matriz es sim�trica. 
	// Este m�todo calcula primero la traspuesta de la matriz y 
	// despu�s comprueba si es igual a su sim�trica.

	bool EsSimetricaIneficiente()
	{
		bool es_simetrica;

		MiMatrizRectangularCaracteres traspuesta (Traspuesta());

		es_simetrica = EsIgual_a(traspuesta);

		return (es_simetrica);
	}

	/*****************************************************************/
	// Calcula si una matriz es sim�trica. 
	// Este m�todo compueba directamente si cada componente es igual a 
	// su sim�trica, parando el recorrido cuando encuentre una componente 
	// que no lo verifique.

	bool EsSimetricaEficiente()
	{
		bool es_simetrica;
		
		es_simetrica = (filas_utilizadas == col_utilizadas);

		if (es_simetrica)
			for (int fil=0; fil<filas_utilizadas && es_simetrica; fil++)
				for (int col=0; col<col_utilizadas && es_simetrica; col++)
					es_simetrica = (matriz_privada[fil][col] == 
									matriz_privada[col][fil]);

		return (es_simetrica);
	}

	/*****************************************************************/
};

///////////////////////////////////////////////////////////////////////

class ImpresorVectorChar
{

private:

	string inicio, final, intermedio;

public:

	/*****************************************************************/

	ImpresorVectorChar (string cadena_inicio, 
						string cadena_final, 
						string cadena_intermedio)
		: inicio(cadena_inicio), 
		  final(cadena_final), 
		  intermedio(cadena_intermedio)
	{
	}

	/*****************************************************************/

	void Imprime(string mensaje_inicial, vector <char> un_vector)
	{
		int tope = un_vector.size() - 1;

		cout << mensaje_inicial;
		cout << inicio;

		for (int i=0; i<tope; i++)
			cout << un_vector.at(i) << intermedio;

		cout << un_vector.at(tope) << final;
   }

	/*****************************************************************/
};

///////////////////////////////////////////////////////////////////////

class LectorVectorChar
{

public:

	/*****************************************************************/

	vector <char> LeeHastaTerminador(char terminador)
	{
		vector <char> a_leer;
		char caracter;

		cin >> caracter;

		while (caracter != terminador) {
			a_leer.push_back(caracter);
			cin >> caracter;
		}		

		return a_leer;
	}

	/*****************************************************************/

	vector <char> LeeNumeroFijo(int numero_valores)
	{
		vector <char> a_leer;
		char caracter;

		for (int i = 0; i < numero_valores; i++){
			cin >> caracter;
			a_leer.push_back(caracter);
		}		

		return a_leer;
	}

	/*****************************************************************/

};

///////////////////////////////////////////////////////////////////////

class LectorMatrizRectangularCaracteres
{

private:
	int numero_columnas;
	int numero_filas;

public:

	/*****************************************************************/

	LectorMatrizRectangularCaracteres (int numero_filas, int numero_columnas)
		: numero_filas (numero_filas), 
		  numero_columnas (numero_columnas)
	{
	}

	/*****************************************************************/

	MiMatrizRectangularCaracteres Lee()
	{
		MiMatrizRectangularCaracteres matriz(numero_columnas);

		LectorVectorChar lector_filas;
		vector <char> fila;
		
		for (int i=0; i<numero_filas; i++){

			fila = lector_filas.LeeNumeroFijo (numero_columnas);

			matriz.Aniade(fila);

			fila.clear();
		}

		return matriz;
	}

	/*****************************************************************/
};

///////////////////////////////////////////////////////////////////////

class ImpresorMatrizRectangularCaracteres
{

private: 

	ImpresorVectorChar output_vector;

public:

	ImpresorMatrizRectangularCaracteres 
		(ImpresorVectorChar output_vector_caracteres)
		: output_vector(output_vector_caracteres)
	{
	}
	
	/*****************************************************************/

	void Imprime (string mensaje_general, 
				  string mensaje_por_fila, 
				  MiMatrizRectangularCaracteres una_matriz)
	{
		cout << mensaje_general;
            
		for (int i=0; i<una_matriz.FilasUtilizadas(); i++) 

			output_vector.Imprime(mensaje_por_fila, una_matriz.Fila(i));
   }
	
	/*****************************************************************/

};

///////////////////////////////////////////////////////////////////////


int main()
{

	int num_filas, num_columnas; // filas y columnas de la matriz rectangular

	do{
		cout << "N�mero de filas: ";
		cin >> num_filas; 
	} while (num_filas < 0);

	do{
		cout << "N�mero de columnas: ";
		cin >> num_columnas; 
	} while (num_columnas < 0);

	// Objeto lector de matrices rectangulares
	LectorMatrizRectangularCaracteres lector_matriz(num_filas,num_columnas);

	// Objetos escritores de vectores (filas) y matrices rectangulares
	ImpresorVectorChar output_vector_caracteres("{","}",",");
	ImpresorMatrizRectangularCaracteres output_matriz (output_vector_caracteres);


	cout << endl;
	cout << "Introduzca los caracteres de la matriz por filas: \n";

	// Creaci�n de la matriz como resultado del valor devuelto por el objeto 
	// lector despu�s de ejecutar sobre �l el m�todo Lee()

	MiMatrizRectangularCaracteres matriz(lector_matriz.Lee());

	// Impresi�n de la matriz leida
	output_matriz.Imprime("\nMatriz leida:","\n\tFila: ", matriz);	


	// B�squeda

	char caracter_a_buscar; 

	cout << endl << endl;
	cout << "\nIntroduzca el caracter a buscar: ";
	cin >> caracter_a_buscar;


	bool encontrado_caracter = matriz.ContieneCaracter (caracter_a_buscar);

	cout << endl << endl;

	if (encontrado_caracter) 
		cout << "SE HA ENCONTRADO el caracter " << caracter_a_buscar;
	else 
		cout << "NO SE HA ENCONTRADO el caracter " << caracter_a_buscar;
	cout << endl << endl;


	PosicionEnMatriz posicion = matriz.PrimeraOcurrencia (caracter_a_buscar);

	if (posicion.EsPosicionNoValida()) 
		cout << "NO SE HA ENCONTRADO el caracter " << caracter_a_buscar;
	else {
		cout << "SE HA ENCONTRADO el caracter " << caracter_a_buscar;
		cout << " en la posicion (" << posicion.GetFila() 
			 << ", " <<posicion.GetColumna() << ")";
	}
	cout << endl << endl;


	// Traspuesta y simetr�a

	cout << "\n------------------------------------------------";
	cout << "\n\nTraspuesta.\n\n";
	
	MiMatrizRectangularCaracteres traspuesta(matriz.Traspuesta());
	output_matriz.Imprime("\nMatriz Traspuesta:","\n\tFila: ", traspuesta);	

	cout << "\n------------------------------------------------";
	cout << "\n\nSimetr�a.\n\n";

	bool es_simetrica;
	
	es_simetrica = matriz.EsSimetricaEficiente();

	if (es_simetrica)
		cout << "\nEs sim�trica (eficiente)";
	else
		cout << "\nNo es sim�trica (eficiente)";
	
	es_simetrica = matriz.EsSimetricaIneficiente();

	if (es_simetrica)
		cout << "\nEs sim�trica (ineficiente)";
	else
		cout << "\nNo es sim�trica (ineficiente)";

	cout << "\n------------------------------------------------";

	cout << "\n\n";

	system("pause");

	return (0);
}