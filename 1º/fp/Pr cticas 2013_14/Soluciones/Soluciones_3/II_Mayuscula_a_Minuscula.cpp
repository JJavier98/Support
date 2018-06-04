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
// EJERCICIO 4
//
/*	
	Leer un carácter letra_original desde teclado, y comprobar con una
	estructura condicional si es una letra mayúscula.
*/

#include <iostream>
using namespace std;

int main()
{
   char letra_convertida, letra_original;
   const int DISTANCIA_MAY_MIN = 'a'-'A';             
   bool es_mayuscula;
  
   cout << "\nIntroduzca una letra  --> ";
   cin >> letra_original;
   
	/*
	if ((letra_original >= 'A') && (letra_original <= 'Z')){
		letra_convertida = letra_original + DISTANCIA_MAY_MIN
		cout << letra_convertida;
	}
	else{
		cout << letra_original << " no es una mayúscula";
	}
	*/

	/*
	El problema de la anterior solución es que se mezclan C/S.
	Para resolverlo, usamos la variable adicional es_mayuscula.
	Planteamos una posible solución:
	
	if (letra_original >= 'A') && (letra_original <= 'Z')
      es_mayuscula = true;
      
	if (es_mayuscula)
		letra_convertida = letra_original + DISTANCIA_MAY_MIN;    
	else 
		letra_convertida = letra_original;
      
	Sin embargo, hay un error lógico ya que la variable es_mayuscula
	se podría quedar sin un valor asignado (en el caso de que 
	la expresión lógica fuese false) El compilador lo detecta y
	da el error al inicio de la sentencia  if (es_mayuscula)
   
	Para resolverlo debemos poner:
	
	if (letra_original >= 'A') && (letra_original <= 'Z')
		es_mayuscula = true;
	else
		es_mayuscula = false;

	O mucho mejor, de una forma más concisa:
   */
   
	es_mayuscula = (letra_original >= 'A') && (letra_original <= 'Z');

	if (es_mayuscula)
		letra_convertida = letra_original + DISTANCIA_MAY_MIN;    
	else 
		letra_convertida = letra_original;

   cout << "\nEl carácter " << letra_original  
	    << " una vez convertido es: " << letra_convertida;     
   cout << "\n\n";   

   system("pause");
}
