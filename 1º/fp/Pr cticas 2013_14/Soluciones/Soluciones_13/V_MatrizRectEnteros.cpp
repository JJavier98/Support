/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
// GRADO EN INGENIERÍA INFORMÁTICA
//
// CURSO 2013-2014
// (C) JUAN CARLOS CUBERO TALAVERA
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS V
// EJERCICIOS 16 y 17
//
/*	
	Este programa presenta la clase MiMatrizRectangularEnteros, que se 
	define de manera similar a la clase MiMatrizRectangularCaracteres 
	de los ejercicios 14 y 15. 
		(Esta clase es útil cuando se desea que forzosamente todas las 
		filas tengan el mismo número de columnas, es decir, que sea una 
		matriz rectangular).

	Se emplea como dato miembro privado una matriz "clásica" en la forma:

		int matriz_privada[MAXIMO_FILAS][MAXIMO_COLUMNAS];

	Además de los métodos básicos se ofrecen métodos para:

	a)	Sumar aquellos valores M_{ij} de la matriz M que verifiquen
		que i + j sea igual a:

                            k
                          _____
                         <
                          >  h^2    para algún k >= 1
                         <
                          -----
						   h = 1
						  
	b)	Calcular la posición de aquel elemento que sea el mayor de entre 
	los mínimos de cada fila. 
	
	c)	Ver si existe un valor MaxiMin, es decir, que sea a la vez, 
	máximo de su fila y mínimo de su columna.

	d) (EJERCICIO 17) Se amplía la clase MiMatrizRectangularEnteros con un 
	método que busque la fila de la matriz que más se parezca a un vector 
	de enteros (clase MiVectorEnteros). El método devuelve el número de la fila.
	
	La similitud entre dos vectores se calcula midiendo la distancia euclídea 
	entre ambos. Además, la búsqueda solo se hace sobre las filas de la matriz 
	enumeradas en un segundo vector de enteros (clase MiVectorEnteros).
*/
/*********************************************************************/


#include <iostream>
#include <iomanip>

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
	// La posición {-1,-1} debe interpretarse como "posición no válida"
	// (resulta útil en métodos de búsqueda, por ejemplo). 

	PosicionEnMatriz (void) : fila(-1), columna(-1) { }

	/*****************************************************************/
	// Método de escritura: establece simultaneamente los dos valores

	void SetPosicion (int la_fila, int la_columna)
	{
		fila = la_fila;
		columna = la_columna;
	}

	/*****************************************************************/
	// Métodos Get

	int GetFila (void)
	{
		return (fila);
	}
	
	int GetColumna (void)
	{
		return (columna);
	}

	/*****************************************************************/
	// Devuelve TRUE si la posición no es válida--> {-1,-1}

	bool EsPosicionNoValida (void)
	{
		return ((fila == -1) && (columna == -1));
	}

	/*****************************************************************/
	// Devuelve TRUE si las posiciones son iguales

	bool EsIgualA (PosicionEnMatriz otra)
	{
		return ((fila == otra.fila) && (columna == otra.columna));
	}
	/*****************************************************************/

};

///////////////////////////////////////////////////////////////////////

class MiMatrizRectangularEnteros
{
private:

	static const int MAXIMO_FILAS = 50;
	static const int MAXIMO_COLUMNAS = 40;

	int matriz_privada[MAXIMO_FILAS][MAXIMO_COLUMNAS];

	int filas_utilizadas;
	int col_utilizadas;

public:

	/*
	Para obligar a que una matriz sea rectangular, lo podemos hacer 
	de varias formas. Por ejemplo:
	a)	El constructor de la matriz recibe "numero_de_columnas", que 
		indica el número de columnas que deben tener todas las filas.
	b)	El constructor de la matriz recibe un vector. La longitud 
		(número de casillas utilizadas) de dicho vector será el valor 
		que se use dentro de la matriz como "numero_de_columnas"

	Para permitir ambas formas, sobrecargamos el constructor.
	*/
	
	/*****************************************************************/
	// Constructor a)
	// Recibe "numero_de_columnas" que indica el número de columnas 
	// que deben tener TODAS las filas.

	MiMatrizRectangularEnteros (int numero_de_columnas)
		: filas_utilizadas(0), col_utilizadas(numero_de_columnas) { }

	/*****************************************************************/
	// Constructor b)
	// Recibe un vector STL. La longitud de dicho vector (num. de casillas) 
	// es el valor que se usa como "numero_de_columnas"

	MiMatrizRectangularEnteros (vector <int> primera_fila)
		: filas_utilizadas(0), col_utilizadas (primera_fila.size())
	{
		Aniade(primera_fila); // Actualiza "filas_utilizadas"
	}

	/*****************************************************************/
	// Método de lectura: número máximo de filas

	int CapacidadFilas()
	{
		return (MAXIMO_FILAS);
	}

	/*****************************************************************/
	// Método de lectura: número máximo de columnas

	int CapacidadColumnas()
	{
		return (MAXIMO_COLUMNAS);
	}

	/*****************************************************************/
	// Método de lectura: número real de filas usadas

	int FilasUtilizadas()
	{
		return (filas_utilizadas);
	}

	/*****************************************************************/
	// Método de lectura: número real de columnas usadas

	int ColumnasUtilizadas()
	{
		return (col_utilizadas);
	}

	/*****************************************************************/
	// Método de lectura: devuelve el caracter que ocupa la casilla 
	// de coordenadas (fila, columna)

	int Elemento(int fila, int columna)
	{
		return (matriz_privada[fila][columna]);
	}

	/*****************************************************************/
	// Devuelve una fila completa, en forma de un vector de la STL

	vector <int> Fila (int indice_fila)
	{
		vector <int>  fila;

		for (int col=0; col<col_utilizadas; col++)
			fila.push_back (matriz_privada[indice_fila][col]);

		return (fila);
	}

	/*****************************************************************/
	// Devuelve una columna completa, en forma de un vector de la STL

	vector <int> Columna(int indice_columna)
	{
		vector <int> columna;

		for (int fil=0; fil<filas_utilizadas; fil++)
			columna.push_back (matriz_privada[fil][indice_columna]);

		return (columna);
	}

	/*****************************************************************/
	// Añade una fila completa. La fila se porporciona en forma de un 
	// vector de la STL. 
	// PRE: el número de casillas de "fila_nueva" es igual a "col_utilizadas"

	void Aniade(vector <int>  fila_nueva)
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
	// Devuelve TRUE si la matriz contiene el número "buscado"
	
	bool Contiene (int buscado)
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
	// Encontrar un carácter en la matriz y devolver su posición.
	// El valor devuelto contiene información acerca de la posición 
	// (fila y columna) de "buscado".  En el caso de que no esté 
	// contendrá {-1,-1}. 
	// La consulta de la fila y la columna se delega en los métodos de 
	//	la clase "ParejaEnteros" 

	PosicionEnMatriz PrimeraOcurrencia (int buscado)
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
	// PRE: las dos matrices tienen el mismo número de filas y columnas.
	
	bool EsIgual_a (MiMatrizRectangularEnteros otra_matriz)
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

	MiMatrizRectangularEnteros Traspuesta()
	{
		// La traspuesta tiene tantas filas como columnas tiene la 
		// matriz original

		MiMatrizRectangularEnteros traspuesta (filas_utilizadas);


		vector <int> columna;	// Las filas de la traspuesta serán las 
								// columnas de la original

		for (int col = 0; col < col_utilizadas; col++){

			columna = Columna(col);
			traspuesta.Aniade(columna); 
		}

		return (traspuesta);
	}

	/*****************************************************************/
	// Calcula si una matriz es simétrica. 
	// Este método calcula primero la traspuesta de la matriz y 
	// después comprueba si es igual a su simétrica.

	bool EsSimetricaIneficiente()
	{
		bool es_simetrica;

		MiMatrizRectangularEnteros traspuesta (Traspuesta());

		es_simetrica = EsIgual_a(traspuesta);

		return (es_simetrica);
	}

	/*****************************************************************/
	// Calcula si una matriz es simétrica. 
	// Este método compueba directamente si cada componente es igual a 
	// su simétrica, parando el recorrido cuando encuentre una componente 
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
	// Sumar aquellos valores M_{ij} de la matriz M que verifiquen
	// que i + j sea igual a:
	/*
                            k
                          _____
                         <
                          >  h^2    para algún k >= 1
                         <
                          -----
						   h = 1
	*/

	int SumaAlgunosValores (int k)
	{
		int num_filas = filas_utilizadas;
		int num_cols  = col_utilizadas;
		int Max_suma_i_j = (num_filas-1) + (num_cols-1);

		int max_k_posible;  // Se calculará el valor máximo para k

		// Crear e iniciar un vector con los elementos de la serie
		vector <int> serie;		
		serie.push_back(0);		// el primer elemento es 0

		int h=1; 
		bool sigo = true;

		while (sigo) {

			// Calcular la suma hasta h-1
			int suma = 0;
			for (int pos=0; pos<h; pos++) 
				suma += serie[pos];

			// Nueva suma, incorporando h*h
			int valor_siguiente = suma+(h*h);

			// Si el nuevo valor es mayor que la suma de la mayor fila 
			// y la mayor columna, parar: aunque sigamos calculando 
			// elementos de la serie nunca verificarían lo que se busca

			if (valor_siguiente > Max_suma_i_j) {
				sigo = false;
				max_k_posible = h-1; // máximo valor posible para k
			}
			else { // continuar con la serie
				serie.push_back (valor_siguiente); 
				h++; 
			}
		}

		// Reajustar el valor de k, si es preciso.
		if (k > max_k_posible) 
			k = max_k_posible;

		// Calcular la suma de los valores de la matriz que verifican 
		// que la suma de su fila y columna está en la serie calculada

		int suma = 0; 

		for (int i=0; i<num_filas; i++)
			for (int j=0; j<num_cols; j++)
				for (int h=1; h<=k; h++) 
					if (i+j == serie[h]) 
						suma += matriz_privada[i][j];

		return (suma);
	}

	/*****************************************************************/
	// Calcular la posición de aquel elemento que sea el mayor de 
	// entre los mínimos de cada fila. 

	PosicionEnMatriz MayorMinimos (void)
	{
		// Vectores que guardan los valores y las posiciones 
		// de los mínimos de cada fila

		vector <int> minimos;
		vector <PosicionEnMatriz> posic_minimos;

		// Calcular y guardar el mínimo de cada fila y su posición

		for (int f=0; f<filas_utilizadas; f++) {

			vector <int> v = Fila (f);	// Extraer fila "f"

			int min = v[0];		// El mínimo inicial es el primero 
			int col_min = 0;	// de la fila (columna 0)

			for (int c=1; c<col_utilizadas; c++) 
				
				if (v[c] < min) {
					min = v[c];		// Actualizar el valor del mínimo 
					col_min = c;	// y de su posición. 
				}

			minimos.push_back (min);	// Guardar el valor del mínimo
			
			PosicionEnMatriz posic_min_fila;			// Guardar la posición
			posic_min_fila.SetPosicion (f, col_min);	// del mínimo
			posic_minimos.push_back(posic_min_fila);	
		}

		// Calcular el máximo y su posición

		int max = minimos[0];	// El máximo inicial es el primero
		int fila_max = 0;

		for (int f=1; f<filas_utilizadas; f++) 
				
			if (minimos[f] > max) {
				max = minimos[f];	// Actualizar el valor del máximo
				fila_max = f;		// y de su posición. 
			}

		return (posic_minimos[fila_max]);
	}

	/*****************************************************************/

	PosicionEnMatriz Maximin(void)
	{
		PosicionEnMatriz pos_max_fila_f;	
		PosicionEnMatriz pos_min_columna_col_max;	
		PosicionEnMatriz pos_MaxiMin;

		pos_MaxiMin.SetPosicion (-1, -1);

		int f = 0;
		bool encontrado = false;

		while ((f<filas_utilizadas) && (!encontrado)) {
				
			// Calcular el máximo de la fila "f" y su posición

			vector <int> fila = Fila (f);

			int max = fila[0];	// El máximo inicial es el primero
			int col_max = 0;

			for (int c=1; c<col_utilizadas; c++) 
				if (fila[c] > max) {
					max = fila[c];	// Actualizar el valor del 
					col_max = c;	// máximo y de su posición. 
				}
			pos_max_fila_f.SetPosicion (f, col_max);
	
			// Calcular el mínimo de la columna "col_max" y su posición

			vector <int> columna = Columna (col_max);

			int min = columna[0];	// El máximo inicial es el primero
			int fila_min = 0;

			for (int fil=1; fil<filas_utilizadas; fil++) 
				if (columna[fil] < min) {
					min = columna[fil];	// Actualizar el valor del 
					fila_min = fil;		// máximo y de su posición. 
				}
			pos_min_columna_col_max.SetPosicion (fila_min, col_max);
	
			// Si la posición del máximo de la fila "f" (pos_max_fila_f) es la
			/// del mínimo de su columna (pos_min_columna_col_max) tenemos un 
			// elemento MaxiMin --> Terminar

			if (pos_min_columna_col_max.EsIgualA(pos_max_fila_f)) { 
				pos_MaxiMin = pos_max_fila_f;
				encontrado = true;
			}
			else
				f++;

		} // while ((f<filas_utilizadas) && (!encontrado))

		return (pos_MaxiMin);
	}

	/*****************************************************************/

	int FilaMasCercana (vector <int> referencia, vector <int> lista_filas)
	{
		double	 min_dist = 9999999999999999.9;
		int		 fila_min;

		int num_filas_a_comparar = lista_filas.size();

		for (int f_comp=0; f_comp<num_filas_a_comparar; f_comp++) {

			vector <int> fila = Fila (lista_filas[f_comp]);

			// Distancia desde "fila" a "referencia"
			double dist = 0.0;
			for (int c=0; c<col_utilizadas; c++)
				dist += dist + ((fila[c]-referencia[c])*(fila[c]-referencia[c]));

			if (dist < min_dist){
				min_dist = dist;
				fila_min = lista_filas[f_comp];
			}
		}

		return (fila_min);
	}

	/*****************************************************************/

};

///////////////////////////////////////////////////////////////////////

class ImpresorVectorInt
{

private:

	string inicio, final, intermedio;

public:

	/*****************************************************************/

	ImpresorVectorInt (string cadena_inicio, 
						string cadena_final, 
						string cadena_intermedio)
		: inicio(cadena_inicio), 
		  final(cadena_final), 
		  intermedio(cadena_intermedio)
	{
	}

	/*****************************************************************/

	void Imprime(string mensaje_inicial, vector <int> un_vector)
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

class LectorVectorInt
{

public:

	/*****************************************************************/

	vector <int> LeeHastaTerminador(int terminador)
	{
		vector <int> a_leer;
		int valor;

		cin >> valor;

		while (valor != terminador) {
			a_leer.push_back(valor);
			cin >> valor;
		}		

		return a_leer;
	}

	/*****************************************************************/

	vector <int> LeeNumeroFijo(int numero_valores)
	{
		vector <int> a_leer;
		int valor;

		for (int i = 0; i < numero_valores; i++){
			cin >> valor;
			a_leer.push_back(valor);
		}		

		return a_leer;
	}

	/*****************************************************************/

};

///////////////////////////////////////////////////////////////////////

class LectorMatrizRectangularEnteros
{
private:
	int numero_columnas;
	int numero_filas;

public:

	/*****************************************************************/

	LectorMatrizRectangularEnteros (int numero_filas, int numero_columnas)
		: numero_filas (numero_filas), 
		  numero_columnas (numero_columnas)
	{
	}

	/*****************************************************************/

	MiMatrizRectangularEnteros Lee()
	{
		MiMatrizRectangularEnteros matriz(numero_columnas);

		LectorVectorInt lector_filas;
		vector <int> fila;
		
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

class ImpresorMatrizRectangularEnteros
{
private: 
	ImpresorVectorInt output_vector;

public:

	ImpresorMatrizRectangularEnteros (ImpresorVectorInt output_vector_enteros)
		: output_vector(output_vector_enteros)
	{
	}
	
	/*****************************************************************/

	void Imprime (string mensaje_general, 
				  string mensaje_por_fila, 
				  MiMatrizRectangularEnteros una_matriz)
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
		cout << "Número de filas: ";
		cin >> num_filas; 
	} while (num_filas < 0);

	do{
		cout << "Número de columnas: ";
		cin >> num_columnas; 
	} while (num_columnas < 0);

	// Objeto lector de matrices rectangulares
	LectorMatrizRectangularEnteros lector_matriz(num_filas,num_columnas);

	// Objetos escritores de vectores (filas) y matrices rectangulares
	ImpresorVectorInt output_vector_enteros("{","}",",");
	ImpresorMatrizRectangularEnteros output_matriz (output_vector_enteros);


	cout << endl;
	cout << "Introduzca los valores de la matriz por filas: \n";

	// Creación de la matriz como resultado del valor devuelto por el objeto 
	// lector después de ejecutar sobre él el método Lee()

	MiMatrizRectangularEnteros matriz(lector_matriz.Lee());

	// Impresión de la matriz leida
	output_matriz.Imprime("\nMatriz leida:","\n\tFila: ", matriz);	
	cout << endl << endl;


	// Suma algunos valores

	cout << "\n------------------------------------------------";
	cout << "\n\nSuma de algunos valores de la matriz.\n\n";

	int valor_k;

	do{
		cout << "Valor de k: ";
		cin >> valor_k; 
	} while (valor_k < 1);

	cout << "La suma es: " << setw (5) << matriz.SumaAlgunosValores (valor_k); 


	// Mayor de los mínnimos (por filas) de una matriz

	cout << "\n------------------------------------------------";
	cout << "\n\nMayor de los minimos (por filas) de la matriz.\n\n";

	PosicionEnMatriz posicion = matriz.MayorMinimos();
	
	cout << "El mayor de los minimos es: " 
		<< matriz.Elemento (posicion.GetFila(), posicion.GetColumna())
		<< endl;
	cout << "Posicion: (" << posicion.GetFila() << ", " 
		 << posicion.GetColumna() << ")" << endl; 



	// Cálculo del MaxiMin

	cout << "\n------------------------------------------------";
	cout << "\n\nMaximin\n\n";

	PosicionEnMatriz posicionMaxiMin = matriz.Maximin();
	
	if (posicionMaxiMin.EsPosicionNoValida()) 
		cout << "No hay ningun elemento MaxiMin."<< endl;
	else 
	{
		int filaMaxiMin = posicionMaxiMin.GetFila();
		int colMaxiMin  = posicionMaxiMin.GetColumna();
		cout << "Un elemento MaxiMin es: " 
		     << matriz.Elemento (filaMaxiMin, colMaxiMin) << endl;
		cout << "Posicion: (" << filaMaxiMin << ", " 
			 << colMaxiMin << ")" << endl; 
	}

	// Distancia vector-matriz

	cout << "\n------------------------------------------------";
	cout << "\n\nCercanía entre vectores\n\n";

	LectorVectorInt lector_referencia;
	vector <int> referencia;
		
	cout << "Vector de referencia:\n";
	referencia = lector_referencia.LeeNumeroFijo (num_columnas);

	LectorVectorInt lector_filas_a_comparar;
	vector <int> filas_a_comparar;
		
	cout << "Filas a comparar: (terminar con -1)\n";
	filas_a_comparar = lector_filas_a_comparar.LeeHastaTerminador (-1);

	int fila_mas_cercana = matriz.FilaMasCercana (referencia, filas_a_comparar);

	cout << "\nLa fila mas cercana es: " << fila_mas_cercana << endl;

/*
	// Pruebas equivalentes a las del los ejercicios 14 y 15:

	// Búsqueda

	int valor_a_buscar; 

	cout << endl << endl;
	cout << "\nIntroduzca el valor a buscar: ";
	cin >> valor_a_buscar;


	bool encontrado_valor = matriz.Contiene (valor_a_buscar);

	cout << endl << endl;

	if (encontrado_valor) 
		cout << "SE HA ENCONTRADO el valor " << valor_a_buscar;
	else 
		cout << "NO SE HA ENCONTRADO el valor " << valor_a_buscar;
	cout << endl << endl;


	PosicionEnMatriz posicion = matriz.PrimeraOcurrencia (valor_a_buscar);

	if (posicion.EsPosicionNoValida()) 
		cout << "NO SE HA ENCONTRADO el valor " << valor_a_buscar;
	else {
		cout << "SE HA ENCONTRADO el valor " << valor_a_buscar;
		cout << " en la posicion (" << posicion.GetFila() 
			 << ", " <<posicion.GetColumna() << ")";
	}
	cout << endl << endl;


	// Traspuesta y simetría

	cout << "\n------------------------------------------------";
	cout << "\n\nTraspuesta.\n\n";
	
	MiMatrizRectangularEnteros traspuesta(matriz.Traspuesta());
	output_matriz.Imprime("\nMatriz Traspuesta:","\n\tFila: ", traspuesta);	

	cout << "\n------------------------------------------------";
	cout << "\n\nSimetría.\n\n";

	bool es_simetrica;
	
	es_simetrica = matriz.EsSimetricaEficiente();

	if (es_simetrica)
		cout << "\nEs simétrica (eficiente)";
	else
		cout << "\nNo es simétrica (eficiente)";
	
	es_simetrica = matriz.EsSimetricaIneficiente();

	if (es_simetrica)
		cout << "\nEs simétrica (ineficiente)";
	else
		cout << "\nNo es simétrica (ineficiente)";

	cout << "\n------------------------------------------------";

*/
	cout << "\n\n";

	system("pause");

	return (0);
}