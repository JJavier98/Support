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
// EJERCICIO 8
//
/*	
	En este ejercico se amplía la clase MiVectorCaracteres con el método:
	
		void EliminaExcesoBlancos(void) 
		
	para eliminar el exceso de caracteres en blanco, es decir, que sustituya 
	todas las secuencias de espacios en blanco por un sólo espacio.

	Se presentan dos implementaciones:

    1)	Ineficiente.

		Recorrer las componentes de "vector_privado"
			Si la componente actual es blanco 
				Si no hay siguiente componente, salir.
				Si la hay, y es un blanco, 
					eliminarla con Elimina() y repetir
					
		La implementación de Elimina() obliga a desplazar muchas componentes.

	2) 	Eficiente.

		Consiste en usar una estrategia ya conocida: mantener dos 
		apuntadores, uno para la posición de lectura y otro para la posición 
		de escritura. Básicamente consiste en que una vez que se ha leido y 
		escrito el primer blanco, se leen los siguientes blancos sin 
		escribirlos.  

		Evitamos los desplazamientos obligados por la ejecución de Elimina() 
		cada vez que detecta dos blancos consecutivos. 
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
	}

	/*****************************************************************/
	// Elimina secuencias de espacios en blanco y las sustituye por 
	// un unico espacio. 
	// Esta versión es ineficiente. Usa un algoritmo con dos bucles anidados

	void QuitaExcesoBlancos_Ineficiente()
	{
		/* 
		Recorrer las componentes de "vector_privado"
			Si la componente actual es blanco 
				Si no hay siguiente componente, salir.
				Si la hay y es un blanco, 
					eliminarla con Elimina() y repetir
					
		La implementación de Elimina() obliga a desplazar muchas componentes.

		*/

		int i = 0;

		bool sigo, ultima; 

		while (i < total_utilizados){

			if (vector_privado[i] == ' '){
			
				ultima = (i+1 == total_utilizados);
				if (ultima) 
					sigo = false;
				else  
					sigo = vector_privado[i+1] == ' ';
				

				while (sigo) {

					Elimina (i);  

					ultima = (i+1 == total_utilizados);
					if (ultima) 
						sigo = false;
					else  
						sigo = vector_privado[i+1] == ' ';
				}
			}

			i++;

		} // while (i < total_utilizados)
	}

	/*****************************************************************/
	// Elimina secuencias de espacios en blanco y las sustituye por 
	// un unico espacio. 
	// Versión eficiente. Realiza la limpieza con un solo ciclo.
	
	void QuitaExcesoBlancos()
	{

		// ¿cómo es el primer carácter del vector?

		bool en_blanco;

		if (vector_privado[0] == ' ') 
			en_blanco = true; // puede empezar una secuencia 
		else 
			en_blanco = false;


		int  pos_escritura = 1; // sea cual sea el primero, no cambiará.


		int  pos_lectura = 1;

		while (pos_lectura < total_utilizados) {
		
			char leido; // caracter leido en cada iteración del 
						// ciclo que recorre el vector  
			
			leido = vector_privado[pos_lectura];

			if (leido == ' ') 

				if (en_blanco) // ((leido == ' ') && (en_blanco))
			
					pos_lectura++;	// segimos en secuencia de blancos.
									// saltarlo: no se guarda

				else // ((leido == ' ') && (!en_blanco))
				{
					en_blanco=true; // puede empezar una secuencia 
					vector_privado[pos_escritura] = leido; // guardar el primer
					pos_lectura++;						   // blanco y avanzar 
					pos_escritura++;		
				}

			else // Ahora: leido != ' '

				if (en_blanco) // ((leido != ' ') && (en_blanco))
				{
					en_blanco=false; // termina la secuencia
					vector_privado[pos_escritura] = leido; // guardar y 
					pos_lectura++;						   // avanzar
					pos_escritura++;		
				}
				else  // ((leido != ' ') && (!en_blanco))
				{
					vector_privado[pos_escritura] = leido; // guardar y 
					pos_lectura++;						   // avanzar
					pos_escritura++;		
				}
		} // while (pos_lectura < total_utilizados)

		total_utilizados = pos_escritura; 
	
	} 

	/*****************************************************************/

};

///////////////////////////////////////////////////////////////////////

/*********************************************************************/

int main()
{

	MiVectorCaracteres vector;
	int tope;

	// Añadir datos al vector

	vector.Aniade(' ');   
	vector.Aniade(' ');  
	vector.Aniade('H');
	vector.Aniade(' ');
	vector.Aniade(' ');  
	vector.Aniade(' ');  
	vector.Aniade('o');
	vector.Aniade(' ');
	vector.Aniade(' ');  
	vector.Aniade(' ');
	vector.Aniade(' ');
	vector.Aniade('l');
	vector.Aniade('a');
	vector.Aniade(' ');
	vector.Aniade(' ');  
	vector.Aniade(' ');
	vector.Aniade(' ');

	cout  << "Vector original: \n";	

	// Mostrar el contenido del vector

	cout  << "|";
	tope = vector.TotalUtilizados();
	for (int i=0; i<tope; i++)
		cout  << vector.Elemento(i) << "|";	
	cout << endl; 


	// Eliminar exceso de blancos

	cout << endl; 

//	cout  << "Eliminando exceso de blancos con algoritmo ineficiente\n";	
// 	vector.QuitaExcesoBlancos_Ineficiente();

 	cout  << "Eliminando exceso de blancos con algoritmo eficiente\n";	
 	vector.QuitaExcesoBlancos();


	cout << endl; 
	cout  << "Vector sin exceso de blancos: \n";	

	tope = vector.TotalUtilizados();  	// Es OBLIGADO recalcular "tope"
										// ya que el número de componentes 
										// utilizadas puede cambiar
	cout  << "|";
	for (int i=0; i<tope; i++)
		cout  << vector.Elemento(i) << "|";	
	cout << endl; 

	cout << "\n\n";
	system ("pause");

	return (0);
}