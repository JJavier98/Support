/* 
	Fundamentos de Programación
	Grado en Ingeniería Informática

	2013 - FP
	------------------------------
	Programa para calcular la suma de los n primeros términos de una sucesión.

	Devuelve:  Los terminos de la sucesion.
*/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//Funcion que calcula el término de i
double Termino(int i) {

	double resultado = (i*i - 1) / (2.0 * i); // término i

	return resultado;
}

int main()
{
	int i, tope, potencia;
	double suma_serie, termino;   
   
   	cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales 


	cout << "\nIntroduzca el límite de la serie: ";
	cin >> tope;
   
	suma_serie = 0;

	potencia = 1; 
   
	for (i = 1 ; i <= tope ; i++){

		potencia = -potencia;	// cambio de signo ->
								// para i=1, (-1)^i debe ser -1,  
								// para i=2, (-1)^i debe ser +1,...

		//Calculamos el termino llamando a la funcion, que es 
		//lo que pide el ejercicio
		termino = Termino(i);

		suma_serie = suma_serie + (potencia * termino);
	}
   
	cout << "\nSuma de la serie = " 
		 << setw(10) << setprecision(2) << suma_serie;      
	cout << "\n";
   
	system("pause");
}
