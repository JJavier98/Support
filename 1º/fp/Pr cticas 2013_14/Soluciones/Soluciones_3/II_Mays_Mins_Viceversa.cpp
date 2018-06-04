/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
// GRADO EN INGENIERÍA INFORMÁTICA
//
// CURSO 2012-2013
// (C) JUAN CARLOS CUBERO TALAVERA
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 2
// EJERCICIO 5
/*	
	Leer un carácter desde teclado, y:
	1) si es mayúscula, pasarlo a minúscula.
	2) si es minúscula, pasarlo a mayúscula.
	3) si no es un carácter alfabético, dejarlo tal cual.
*/

#include <iostream>
using namespace std;

int main(){
   char letra_convertida, letra_original;
   const int DISTANCIA_MAY_MIN = 'a'-'A';             
   bool es_mayuscula, es_minuscula;
  
   cout << "\nIntroduzca una letra  --> ";
   cin >> letra_original;
   
	/*	
   if ((letra_original >= 'A') && (letra_original <= 'Z'))
      es_mayuscula = true;
   else
      es_minuscula = true;
	
	Hay que tener mucho cuidado con estas asignaciones, ya que
	cuando a una le asigno true, la otra se queda sin un valor asignado.
	Para evitarlo:

	if ((letra_original >= 'A') && (letra_original <= 'Z')){
		es_mayuscula = true;
		es_minuscula = false;
	}
	else{
		es_mayuscula = false;
		es_minuscula = true;
	}

	Lo anterior podría haberse puesto, de una forma más concisa como sigue:

	es_mayuscula = ((letra_original >= 'A') && (letra_original <= 'Z'));
	es_minuscula = !es_mayuscula;

	En cualquier caso, ya sea de la forma "extendida" o "concisa", la solución
	está mal planteada. La razón es que estamos diciendo que las letras
	entre la A y la Z son mayúsculas, y que el resto son minúsculas!
	Debemos poner lo siguiente:
	*/


	es_mayuscula = ((letra_original >= 'A') && (letra_original <= 'Z'));
	es_minuscula = ((letra_original >= 'a') && (letra_original <= 'z'));

	
	// Ahora bastaría hacer lo siguiente:

	/*
	if (es_mayuscula)
      letra_convertida = letra_original + DISTANCIA_MAY_MIN;    
	else 
		if (es_minuscula)
			letra_convertida = letra_original - DISTANCIA_MAY_MIN;

	cout << "\nEl carácter " << letra_original  
		  << " una vez convertido es: " << letra_convertida;     
	*/

	/*
	Sin embargo, esta solución da el siguiente warning:
	
	Advertencia	1	warning C4701: 
	posiblemente se utilizó la variable local 'letra_convertida' sin inicializar
	
	¿Por qué?

	El problema es que si ambas variables lógicas son false, la variable
	letra_convertida se queda sin ningún valor asignado.

	Solución:
   */

	if (es_mayuscula)
      letra_convertida = letra_original + DISTANCIA_MAY_MIN;    
	else 
		if (es_minuscula)
			letra_convertida = letra_original - DISTANCIA_MAY_MIN;
		else
			letra_convertida = letra_original; 

   cout << "\nEl carácter " << letra_original  
		<< " una vez convertido es: " << letra_convertida;     
   cout << "\n\n";   

   system("pause");
}
