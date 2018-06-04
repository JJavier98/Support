/*********************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2013-2014
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// Fichero de cabecera asociado a la clase Matriz2D-1
//
// Implementacion del tipo Matriz2D_1
//
// Matriz 2D dinamica de datos "TipoBase" en la que cada fila es un 
// vector dinamico independiente. 
//
/*********************************************************************/

#ifndef MATRIZ2D1
#define MATRIZ2D1

// Definición del tipo TipoBase y el valor NULO asociado
typedef int TipoBase;
#define NULO 0

///////////////////////////////////////////////////////////////

class Matriz2D_1 {

	private:
		TipoBase ** datos;	// Los valores de la matriz
		int filas;			// Núm. de filas
		int columnas;		// Núm. de columnas

	public:
		// Constructor sin argumentos (matriz vacia)
		Matriz2D_1(void);       

		//......

		// CONSTRUCTOR PEDIDO EN EL EXAMEN: 
		// Constructor que crea la matriz leyendo los datos de un 
		// fichero mixto binario/texto. 
		// El nombre del fichero se pasa como argumento
		Matriz2D_1 (const char * nombre);

		// Destructor
		~Matriz2D_1(void); 
		
		//......

		// Métodos de lectura de las filas y columnas
		int NumFilas (void) const;
		int NumColumnas (void) const;

		//......

		// Operator ()
		// PRE: 0 <= fila < NumFilas()
		// PRE: 0 <= columna < NumColumnas()
		TipoBase & operator () (const int fila, const int columna);
		TipoBase & operator () (const int fila, const int columna) const;
		//......

		// Operadores == y != 
		bool operator == (const Matriz2D_1 & otro); 
		//...... 


		// LOS MÉTODOS DEL EXAMEN: Guardan/recuperan una matriz en/de un 
		// fichero mixto binario/texto. El nombre del fichero se pasa 
		// como argumento. 
		void GuardaEnFichero (const char *nombre); 
		void LeeDeFichero (const char *nombre); 


	private:
	
		// Pedir memoria para alojar "fils"x"cols" datos
		void ReservarMemoria (int fils, int cols);

		// Liberar la memoria ocupada
		void LiberarMemoria (void);

		// Copiar datos
		void CopiarDatos (const Matriz2D_1 & otro);

		// NUEVOS métodos privados de la clase.
		void RecuperaDatosDeFichero (const char * nombre);

};

///////////////////////////////////////////////////////////////

void PintaMatriz (const Matriz2D_1 & m);

///////////////////////////////////////////////////////////////

#endif
