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
// EJERCICIOS 5 y 6
//
/*	
	En este ejercico se amplía la clase MiVectorCaracteres con el método:
	
		void EliminaMayusculas (void) 
		
	para eliminar todas las mayúsculas del vector. 

	Se presentan dos versiones de este método, 
	
	1) Ineficiente 
		Se realiza un borrado físico de cada mayúscula detectada empleando 
		el método Elimina(). Cada borrado supone el desplazamiento de los 
		elementos situados en posiciones superiores. 

	2) Eficiente 
		Realiza un borrado físico, aunque ahora se emplean dos variables que 
		actúan como apuntadores, para indicar la posición de lectura y la 
		posición de escritura, respectivamente.

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
	// Métodos de lectura (Get) de los datos individuales 

	int TotalUtilizados()
	{
		return total_utilizados;
	}

	int Capacidad()
	{
		return TAMANIO;
	}

	/*****************************************************************/
	// Añade un elemento al vector
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
	// PRE: la posición dada por "indice" es correcta.
	// Si no es correcta,el comportamiento no está definido.

	char Elemento(int indice)
	{
		return vector_privado[indice];
	}

	/*****************************************************************/
	// Eliminar el carácter que se encuentre en la posición dada por 
	// "indice_componente".
	// Realiza un borrado físico (con desplazamiento y sustitución).
	// PRE: la posición dada por "posicion" es correcta.
	// Si no es correcta, no hace nada.

	void Elimina (int posicion) 
	{
		// Recorremos de izquierda a derecha toda las componentes 
		// que hay a la derecha de la posición a eliminar
		//		Le asignamos a cada componente la que hay a su derecha

		if ((posicion >= 0) && (posicion < total_utilizados)) {

			int tope = total_utilizados-1; // posición del último 
    
			for (int i = posicion ; i < tope ; i++)
				vector_privado[i] = vector_privado[i+1];  
    
			total_utilizados--;    
		}

		// Nota:
		// La asignación
		//    vector_privado[i] = vector_privado[i+1];
		// podría cambiarse por:
		//    Modifica(i, Elemento(i+1));
		// Hemos preferido acceder directamente a las componentes con la 
		// notación en corchete para aumentar la eficiencia del método 
		// Elimina() evitando usar métodos lo que conllevaría a una 
		// sobrecarga de procesamiento: llamada, paso de argumentos, 
		// gestión de los entornos en la pila, retorno,...
	}

	/*****************************************************************/
	// Eliminar los caracteres mayúscula del vector.
	// Realiza un borrado físico (con desplazamiento y sustitución) usando 
	// el método Elimina().
	// Versión ineficiente

	void EliminaMayusculasIneficiente()
	{
 		/* Algoritmo: 

			Recorrer todas las componentes que hay en el vector
				Si la componente actual es mayúscula
					Elimirla (llamar al método Elimina())
				en otro caso
					Pasar a la siguiente componente

			Actualizar el número de componentes utilizadas
		*/

		int i = 0;

		while (i < total_utilizados){
			if (isupper(vector_privado[i]))
				Elimina(i);
			else
				i++;
		}

		/*
			Hay que prestar atención y no cometer el error mostrado a 
			continuación, muy frecuente entre los proncipiantes: 
			El siguiente bucle es incorrecto porque cuando ha borrado 
			una mayúscula, NO debe avanzar i

			for (int i=0; i<total_utilizados; i++)
				if (isupper(vector_privado[i]))
					Elimina(i);
		*/
	}

	/*****************************************************************/
	// Eliminar los caracteres mayúscula del vector.
	// Realiza un borrado físico usando dos apuntadores para indicar la 
	// posición de lectura y la posición de escritura, respectivamente.
	// Versión eficiente

	void EliminaMayusculas()
	{
		int pos_escritura,  // posición donde escribir 
			pos_lectura;	// posición dónde leer 

		/* Algoritmo: 

			Recorrer todas las componentes que hay en el vector
				Si la componente actual no es mayúscula
					ponedla dónde indique pos_escritura
				Avanzar pos_lectura

			Actualizar el número de componentes utilizadas
		*/

		pos_escritura = 0;		
		
		for (pos_lectura = 0; pos_lectura < total_utilizados; pos_lectura++){

			if (islower(vector_privado[pos_lectura])) {

				vector_privado[pos_escritura] = vector_privado[pos_lectura];
				pos_escritura++;					

			}	// OJO: "pos_lectura" SIEMPRE avanza (for), mientras que
				// "pos_escritura" solo lo hace cuando encuentra minúsculas.
		}

		total_utilizados = pos_escritura;
	}

};

///////////////////////////////////////////////////////////////////////

/*********************************************************************/


int main()
{

	MiVectorCaracteres vector;
	int tope;


	// Añadir datos al vector

	vector.Aniade('h');   
	vector.Aniade('E');
	vector.Aniade('L');
	vector.Aniade('o');
	vector.Aniade('l');
	vector.Aniade('L');
	vector.Aniade('O');
	vector.Aniade('a');


	cout  << "Vector original: \n";	

	// Mostrar el contenido del vector

	tope = vector.TotalUtilizados();
	for (int i=0; i<tope; i++)
		cout  << vector.Elemento(i) << " ";	
	cout << endl; 


	// Eliminar las mayúsculas
	cout << endl; 
	cout  << "Eliminando mayúsculas\n";	

	vector.EliminaMayusculas();

	// Probad con: 
	//		vector.EliminaMayusculasIneficiente();
	// (debería dar el mismo resultado)

	cout << endl; 
	cout  << "Vector modificado: \n";	

	tope = vector.TotalUtilizados();  	// Es OBLIGADO recalcular "tope"
										// ya que el número de componentes 
										// utilizadas puede cambiar
    for (int i=0; i<tope; i++)
      cout  << vector.Elemento(i) << " ";
	cout << endl; 


	cout << "\n\n";
	system ("pause");

	return (0);
}