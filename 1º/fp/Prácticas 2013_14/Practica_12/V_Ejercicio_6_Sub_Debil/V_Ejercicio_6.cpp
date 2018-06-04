/****************************************************************************** 
	Fundamentos de Programación
	Grado en Ingeniería Informática

	2013 - FP
	------------------------------
	Sobre la clase CaminoComeCocos, añadidle un metodo que compruebe si el 
	conjunto de movimientos de un camino contiene a los movimientos de un 
	segundo camino que se pasara como parámetro al método. Debe respetarse el
	orden en el que aparecen los movimientos, pero no tienen por que estar 
	consecutivos. Por ejemplo, el camino {’s’,’s’,’b’,’i’,’d’,’d’} contiene al 
	camino {’s’,’i’} pero no al camino {’i’,’s’}. Puede usarse la sobrecarga 
	del método find de la clase string.

******************************************************************************/
#include <iostream>	// Inclusión de los recursos de E/S
#include <string>	//Inclusión de las funciones para manejo de cadenas

using namespace std; 

/*****************************************************************************/
//Definicion de la clase
class CaminoComeCocos {
private:
    string cadena_privada;
public:

	/*********************************************************/
	//Este método agrega "s" a la cadena_privada
    void Subir() {
        cadena_privada.append("s");
    }
	/*********************************************************/
	//Este método agrega "b" a la cadena_privada
    void Bajar() {
        cadena_privada.append("b");
    }
	/*********************************************************/
	//Este método agrega "i" a la cadena_privada
    void Izquierda() {
        cadena_privada.append("i");
    }
	/*********************************************************/
	//Este método agrega "d" a la cadena_privada
    void Derecha() {
        cadena_privada.append("d");
    }
	/*********************************************************/
	//Esta función busca los movimientos consecutivos usando la funcion find 
	//de la clase string, para ello hay que pasarle el movimiento y el numero
	//de apariciones consecutivas
	int PosicionMovimientosConsecutivosA(string caracter_movimiento, int n_consecutivos) {
	
		//Declara variables para guardar los datos   
		int posicion;
		string a_buscar;

		//Creamos la cadena a_buscar agregando tantos elementos como se pidan
		for (int i = 0; i < n_consecutivos; i++) {
			a_buscar.append(caracter_movimiento);
		}

		//Buscamos la cadena usando el método find de la clase string
		//Si no lo encuentra devolvera -1
		posicion = cadena_privada.find(a_buscar);

		//Devolvemos el valor
		return posicion;
	}
	/*********************************************************/
	//Esta función busca los movimientos consecutivos sin hacer uso del find 
	//de la clase string, para ello hay que pasarle el movimiento y el numero
	//de apariciones consecutivas
	int PosicionMovimientosConsecutivosB(char caracter_movimiento, int n_consecutivos) {
	
		//Declara variables para guardar los datos   
		int posicion = -1; //si no lo encuentra devolverá -1
		bool encontrada = false; //Bandera para optimizar la salida de los bucles

		//Si se pide una repeticion mayor que el tamaño de la cadena es erroneo
		if (n_consecutivos < (int)cadena_privada.size()) {

			//Recorremos la cadena 
			//(si se encuentra la subcadena se saldrá) 
			//esto es un while con forma de for
			for (int i = 0; !encontrada && (i < (int)cadena_privada.size()); i++) {

				//Comprobamos el numero de consecutivo a partir de donde estamos no es superior
				//a la cadena, y si coincide la letra actual con la que vamos a buscar
				if ((i + n_consecutivos < (int)cadena_privada.size()) && (cadena_privada[i] == caracter_movimiento)) {

					//Nos guardamos un contador de consecutivos encontrados
					//empieza de 1 porque el primero ya se ha encontrado
					int caracteres_consecutivos_encontrados = 1;

					//Recorremos los caracteres siguientes a la aparición 
					//(si se encuentra la subcadena se saldrá) 
					//esto es un while con forma de for
					for (int j = i + 1; !encontrada && j < i + n_consecutivos; j++) {

						//Si el caracter coincide incrementamos el contador
						if (caracter_movimiento == cadena_privada[j]) {
		
							caracteres_consecutivos_encontrados++;
						}

					}

					if (caracteres_consecutivos_encontrados == n_consecutivos) {
						//Establecemos la bandera a true, asi salimos de 
						//los bucles mas eficientemente
						encontrada = true; 

						//Asignamos la posicion para devolverla
						posicion = i;	
					}

				}
			}

		}

		//Devolvemos el valor
		return posicion; 

	}

	/*********************************************************/
	//Esta función busca los movimientos no consecutivos usando la funcion find 
	//de la clase string, para ello hay que pasarle la subcadena a buscar.
	int ContieneMovimientos(string subcadena) {
	
		//Declara variables para guardar los datos   
		int posicion_previa = 0; //La primera vez siempre será 0
		int posicion_encontrada;
		bool contiene = true;

		//Recorremos la subcadena
		for (int i = 0; contiene && i < (int)subcadena.size(); i++) {

			//Obtenemos el caracter actual (por comodidad)
			char caracter = subcadena.at(i);

			//Buscamos la cadena usando el método find de la clase string
			//Si no lo encuentra devolvera -1
			posicion_encontrada = cadena_privada.find(caracter, posicion_previa);

			//Si la posicion encontrada es mayor que la previa vamos bien
			if (posicion_encontrada < posicion_previa) {

				//Si no activamos la bandera para que termine el while (con forma de for)
				contiene = false;

			}

			//Asignamos la posicion actual por la encontrada
			posicion_previa = posicion_encontrada;
		
		}

		//Devolvemos el resultado
		return contiene;
	}

};
/*****************************************************************************/
//Programa Principal 
int main(){    

	//Declara variables para guardar los datos   
	CaminoComeCocos ccc;
	bool contiene_movimientos;
	
	//Vamos moviendo el comecocos (y agregando letras a la cadena)
	ccc.Subir();
	ccc.Subir();
	ccc.Subir();
	ccc.Izquierda();	
	ccc.Bajar();
	ccc.Bajar();
	ccc.Subir();
	ccc.Subir();
	ccc.Bajar();
	ccc.Bajar();
	ccc.Bajar();
	ccc.Bajar();
	ccc.Izquierda();
	ccc.Izquierda();
	ccc.Izquierda();


	//Buscamos la cadena no consecutiva en el comecocos
	contiene_movimientos = ccc.ContieneMovimientos("sbi");


	//Pintamos los valores en la consola
	cout << "¿El comecocos ha hecho los movimientos? (0 = No | 1 = Si): ";
	cout << contiene_movimientos << "\n\n";

	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");

}