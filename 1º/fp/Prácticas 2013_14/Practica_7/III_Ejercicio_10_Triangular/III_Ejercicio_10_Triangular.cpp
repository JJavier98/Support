/* 
	Fundamentos de Programación
	Grado en Ingeniería Informática

	2013 - FP
	------------------------------
	Se dice que un número es triangular si se puede poner como la suma de los 
	primeros m valores enteros, para algún valor de m. Por ejemplo, 6 es 
	triangular ya que 6 = 1 + 2 + 3. 
 
	Una forma de obtener los números triangulares es a través de la fórmula: 
			
			n(n + 1)  = ∀n ∈ N.
			_________
				2
 
	Se pide construir un programa que obtenga todos los números triangulares que 
	hay menores que un entero k introducido desde teclado, sin aplicar la fórmula 
	anterior.

*/
#include <iostream>   // Inclusión de los recursos de E/S

using namespace std; 

//Función para calcular el triangular de un numero  
void CalcularTriangulares(int numero){

	

	for(int i=1;i<=numero;i++) {

		int triangular = i*(i+1)/2;

		cout << "El triangular de " << i << " es " << triangular << "\n\n";  
	}

}  

int main(){   // Programa Principal 

	// Declara variables para guardar los datos
	int numero;   
      
	//Obtenemos los datos
	do {
		cout << "Introduzca un número positivo: ";
			cin >> numero;  
	} while (numero < 0);
	

	//Hacemos los calculos
	CalcularTriangulares(numero);

	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");

}