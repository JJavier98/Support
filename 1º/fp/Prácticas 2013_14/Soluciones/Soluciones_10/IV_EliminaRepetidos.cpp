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
// EJERCICIO 7
//
/*	
	En este ejercico se ampl�a la clase MiVectorCaracteres con el m�todo:
	
		void EliminaRepetidos(int posicion) 
		
	para eliminar los elementos repetidos de un vector de forma que cada 
	componente aparezca solo una vez. Se mantendr� la primera aparici�n, 
	de izquierda a derecha. 

	Se presentan tres implementaciones:

    1)	Con un vector local, "sin_repetidos", en el que almacenamos una 
		�nica aparici�n de cada componente:

			Recorrer todas las componentes del vector original
				Si la componente NO est� en "sin_repetidos",
					A�adirla (al vector "sin_repetidos")
			Asignar las componentes de "sin_repetidos" al vector_original

	2)	Sin vector local, aunque con un algoritmo mejorable.
	
		Si una componente est� repetida, se borrar� del mismo vector. 

			Recorrer todas las componentes del vector original
				Si la componente se encuentra en alguna posici�n anterior 
					Eliminarla (usar el m�todo Elimina()).

		La implementaci�n de Elimina() obliga a desplazar muchas componentes 
		cada vez que encontremos una repetida.

	3) 	Sin vector local, aunque con un algoritmo eficiente.

		Las componentes NO repetidas se almacenan al principio del vector. 
		Para cada nueva componente, comprobamos si est� en el subvector 
		izquierda (que contiene las componentes no repetidas).   
		En el caso de que no est�, colocamos la componente al final 
        de ese subvector
        
			Recorrer todas las componentes "v[pos_lectura]" con "pos_lectura" > 0
				Si la componente "v[pos_lectura]" NO se encuentra entre 
						las posiciones 0 y "pos_escritura",
					Colocamos dicha componente en "pos_escritura".     


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

	MiVectorCaracteres() 	{
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
	// Eliminar el car�cter que se encuentre en la posici�n dada por 
	// "indice_componente".
	// Realiza un borrado f�sico (con desplazamiento y sustituci�n).
	// PRE: la posici�n dada por "posicion" es correcta.
	// Si no es correcta, no hace nada.

	void Elimina (int posicion) 
	{
		// Recorremos de izquierda a derecha toda las componentes 
		// que hay a la derecha de la posici�n a eliminar
		//		Le asignamos a cada componente la que hay a su derecha

		if ((posicion >= 0) && (posicion < total_utilizados)) {

			int tope = total_utilizados-1; // posici�n del �ltimo 
    
			for (int i = posicion ; i < tope ; i++)
				vector_privado[i] = vector_privado[i+1];  
    
			total_utilizados--;    
		}
	}

	/*****************************************************************/
	// Busca la primera ocurrencia de "buscado" en el vector, entre las 
	// posiciones "pos_izda" y "pos_dcha". 
	// Si lo encuentra, devuelve la posici�n. En otro caso devuelve -1.
	// Consultar los apyuntes de clase para m�s detalles. 

	int PrimeraOcurrenciaEntre (int pos_izda, int pos_dcha, char buscado)
	{
		int i = pos_izda; 
		bool encontrado = false;
    
		while ((i <= pos_dcha) && (!encontrado))

			if (vector_privado[i] == buscado)
				encontrado = true;
			else
				i++;

		if (encontrado)
			return i;
		else
			return -1;
	}

	/*****************************************************************/
	// Eliminar los caractertes repetidos del vector. 
	// Emplea un vector local, en el que va guardando la primera 
	// ocurrencia de cada car�cter. 
	
	void EliminaRepetidos_VectorLocal()
	{
		/*
			Recorrer todas las componentes del vector original
				Si la componente NO est� en "sin_repetidos",
					A�adirla (al vector "sin_repetidos")

			Asignar las componentes de "sin_repetidos" al vector_original
		*/

		if (total_utilizados > 0){

			char sin_repetidos[TAMANIO]; // vector local

			int utilizados_en_sin_repetidos;

			sin_repetidos[0] = vector_privado[0];	// El primero SIEMPRE es 
			utilizados_en_sin_repetidos = 1;		// parte de la soluci�n


			// Recorrer todas las componentes del vector original 

			for (int pos_orig=1; pos_orig<total_utilizados; pos_orig++) {


				// Buscar la componente "actual" del vector original 
				// en "sin_repetidos"
			
				bool encontrado_en_sin_repetidos = false;

				for (int pos_local=0;((pos_local<utilizados_en_sin_repetidos)  
                            && (!encontrado_en_sin_repetidos)); pos_local++) {
			
					if (vector_privado[pos_orig] == sin_repetidos[pos_local])
						encontrado_en_sin_repetidos = true; // terminar: 
															// no a�adir
				} 

				// Si "vector_privado[pos_orig]" NO est� en "sin_repetidos"

				if (!encontrado_en_sin_repetidos) { // a�adir a "sin_repetidos"
					sin_repetidos[utilizados_en_sin_repetidos] = 
						vector_privado[pos_orig];
					utilizados_en_sin_repetidos++;
				}

			} // for pos_orig

			// Asignar las componentes de "sin_repetidos" al vector_original

			for (int i=0; i < utilizados_en_sin_repetidos; i++)
				vector_privado[i] = sin_repetidos[i];

			total_utilizados = utilizados_en_sin_repetidos;
 
		} // if (total_utilizados > 0) 
   
   }

	/*****************************************************************/
	// Eliminar los caractertes repetidos del vector. 
	// Si una componente est� repetida, se borrar� del mismo vector. 
	// Emplea un algoritmo ineficiente ya que realiza muchos desplazamientos. 
	
   	void EliminaRepetidos_Ineficiente ()
	{
		/*
			Recorrer todas las componentes del vector original
				Si la componente se encuentra en alguna posici�n anterior 
					Eliminarla (usar el m�todo Elimina()).
		*/ 
   
		// Recorrer todas las componentes del vector original
		// OJO: no debe emplearse un ciclo for, porque en cada iteraci�n 
		// puede cambiar el valor de "total_utilizados" 

		int i = 1;
		while (i < total_utilizados) {

			// Buscar la primera ocurrencia de vector_privado[i]
			int pos = PrimeraOcurrenciaEntre (0, i-1, vector_privado[i]); 
      
			if (pos != -1)	// Est�: borrarlo

				Elimina(i);

			else			// No est�, probar con el siguiente
				i++;

		} // while (i < total_utilizados)

	}

	/*****************************************************************/
	// Eliminar los caractertes repetidos del vector. 
	// Emplea un algoritmo eficiente.
	
	void EliminaRepetidos ()
	{
		/*
   
		Las componentes no repetidas se almacenan al principio del vector
		Empleamos apuntadores para las posiciones de lectura y escritura. 

			Recorrer las componentes "v[pos_lectura]" con "pos_lectura">0
				Si la componente "v[pos_lectura]" NO se encuentra entre 
						las posiciones 0 y "pos_escritura",
					Colocamos dicha componente en "pos_escritura".     
  
		*/ 

		if (total_utilizados > 0) {

			int pos_escritura = 1;	// La primera componente (posici�n 0) es 
									// parte de la soluci�n, por eso se empieza
									// a escribir por la posici�n 1
			int pos_lectura;
			int pos_encontrado;

			// Empiezo la lectura por la posici�n 1 (la posici�n 0 ya es 
			// parte de la soluci�n)

			for (pos_lectura=1; pos_lectura<total_utilizados; pos_lectura++){

				// Busco el caracter actual (el de "pos_lectura") en el 
				// subvector izquierdo (posiciones: 0 hasta "pos_escritura"-1)

				int pos_encontrado = PrimeraOcurrenciaEntre(0,pos_escritura-1, 
												 vector_privado[pos_lectura]);
         
				if (pos_encontrado == -1){  // Si no est�, lo copio en la 
											// "pos_escritura", incrementando 
											// tama�o del cevtor izquierdo  

					vector_privado[pos_escritura] = vector_privado[pos_lectura];
					pos_escritura++;
				}

			} // for pos_lectura
   
			total_utilizados = pos_escritura; // actualizo el tama�o

		} // if (total_utilizados > 0) 

	}

	/*****************************************************************/

};

///////////////////////////////////////////////////////////////////////

/*********************************************************************/

int main()
{

	MiVectorCaracteres vector;
	int tope;


	// A�adir datos al vector

	vector.Aniade('H');
	vector.Aniade('H');
	vector.Aniade('o');
	vector.Aniade('l');
	vector.Aniade('a');
	vector.Aniade('a');
	vector.Aniade('a');
	vector.Aniade('H');
	

	cout  << "Vector original: \n";	

	// Mostrar el contenido del vector

	tope = vector.TotalUtilizados();
	for (int i=0; i<tope; i++)
		cout  << vector.Elemento(i) << " ";	
	cout << endl; 


	// Eliminar repetidos

	cout << endl; 

//	cout  << "Eliminando repetidos con vector local\n";	
//	vector.EliminaRepetidos_VectorLocal();

//	cout  << "Eliminando repetidos con algoritmo ineficiente\n";	
//	vector.EliminaRepetidos_Ineficiente();

	cout  << "Eliminando repetidos con algoritmo eficiente\n";	
	vector.EliminaRepetidos();


	cout << endl; 
	cout  << "Vector sin elementos repetidos: \n";	

	tope = vector.TotalUtilizados();  	// Es OBLIGADO recalcular "tope"
										// ya que el n�mero de componentes 
										// utilizadas puede cambiar
    for (int i=0; i<tope; i++)
      cout  << vector.Elemento(i) << " ";
	cout << endl; 


	cout << "\n\n";
	system ("pause");

	return (0);
}