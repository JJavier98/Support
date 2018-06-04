/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
// GRADO EN INGENIER�A INFORM�TICA
//
// CURSO 2012-2013
// (C) JUAN CARLOS CUBERO TALAVERA
// (C) FRANCISCO JOS� CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACI�N E INTELIGENCIA ARTIFICIAL
//
// RELACI�N DE PROBLEMAS 2
// EJERCICIO 5
/*	
	Leer un car�cter desde teclado, y:
	1) si es may�scula, pasarlo a min�scula.
	2) si es min�scula, pasarlo a may�scula.
	3) si no es un car�cter alfab�tico, dejarlo tal cual.
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

	Lo anterior podr�a haberse puesto, de una forma m�s concisa como sigue:

	es_mayuscula = ((letra_original >= 'A') && (letra_original <= 'Z'));
	es_minuscula = !es_mayuscula;

	En cualquier caso, ya sea de la forma "extendida" o "concisa", la soluci�n
	est� mal planteada. La raz�n es que estamos diciendo que las letras
	entre la A y la Z son may�sculas, y que el resto son min�sculas!
	Debemos poner lo siguiente:
	*/


	es_mayuscula = ((letra_original >= 'A') && (letra_original <= 'Z'));
	es_minuscula = ((letra_original >= 'a') && (letra_original <= 'z'));

	
	// Ahora bastar�a hacer lo siguiente:

	/*
	if (es_mayuscula)
      letra_convertida = letra_original + DISTANCIA_MAY_MIN;    
	else 
		if (es_minuscula)
			letra_convertida = letra_original - DISTANCIA_MAY_MIN;

	cout << "\nEl car�cter " << letra_original  
		  << " una vez convertido es: " << letra_convertida;     
	*/

	/*
	Sin embargo, esta soluci�n da el siguiente warning:
	
	Advertencia	1	warning C4701: 
	posiblemente se utiliz� la variable local 'letra_convertida' sin inicializar
	
	�Por qu�?

	El problema es que si ambas variables l�gicas son false, la variable
	letra_convertida se queda sin ning�n valor asignado.

	Soluci�n:
   */

	if (es_mayuscula)
      letra_convertida = letra_original + DISTANCIA_MAY_MIN;    
	else 
		if (es_minuscula)
			letra_convertida = letra_original - DISTANCIA_MAY_MIN;
		else
			letra_convertida = letra_original; 

   cout << "\nEl car�cter " << letra_original  
		<< " una vez convertido es: " << letra_convertida;     
   cout << "\n\n";   

   system("pause");
}
