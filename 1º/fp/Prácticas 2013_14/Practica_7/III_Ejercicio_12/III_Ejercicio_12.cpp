/* 
	Fundamentos de Programación
	Grado en Ingeniería Informática

	2013 - FP
	------------------------------
	Un número perfecto es aquel que es igual a la suma de todos sus divisores 
	positivos excepto él mismo. El primer número perfecto es el 6 ya que sus 
	divisores son 1, 2 y 3 y 6=1+2+3. Escribir un programa que muestre el mayor
	número perfecto que sea menor a un número dado por el usuario.

*/
#include <iostream>   // Inclusión de los recursos de E/S

using namespace std; 

//Función para calcular si el número suministrado es perfecto o no  
bool EsPerfecto(int numero){

	//Declaramos variables
    int suma = 0; 

	//El iterador comenzara en el numero anterior al introducido  
	int i = numero - 1; 
      
	//Vamos recorriendo desde el anterior del numero suministrado hasta el 1
    while(i > 0){  

		//Si es divisor (el resto da 0) lo agregamos a la suma
        if(numero % i == 0) { 
			suma += i;
		}

		//Decrementamos el iterador
        i--;  
    }  
      
	//Devolvemos si la suma de sus componentes es igual al numero suministrado
    return suma == numero;  
}  

int main(){                    // Programa Principal 

	// Declara variables para guardar los datos
	int numero, i;   
    bool esPerfecto = false;  
      
	//Obtenemos los datos
	do {
		cout << "Introduzca un número positivo: ";
			cin >> numero;  
	} while (numero < 0);
	
	//Asignamos el numero introducido al iterador
	i = numero;  

	//Hacemos los cálculos

	//Vamos recorriendo del anterior al numero introducido hasta el 1
	//o hasta que sea perfecto
    while(!esPerfecto && i > 0){  
		//Decrementamos el iterador
        i--;  
		//Comprobamos si es perfecto
        esPerfecto = EsPerfecto(i);  
    }  
      
	//Pintamos los valores en la consola
    cout << "El mayor numero perfecto menor a " << numero << " es " << i << "\n\n";  
      
	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");

}