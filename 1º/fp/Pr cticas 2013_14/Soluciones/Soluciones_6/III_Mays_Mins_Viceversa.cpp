/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
// GRADO EN INGENIERÍA INFORMÁTICA
//
// CURSO 2013-2014
// (C) JUAN CARLOS CUBERO TALAVERA
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 3
// EJERCICIO 6
//
/*	
	Leer un carácter desde teclado, y:
	1) si es mayúscula, pasarlo a minúscula.
	2) si es minúscula, pasarlo a mayúscula.
	3) si no es un carácter alfabético, dejarlo tal cual.

	Ampliación del ejercicio 5 de la Relación de Problemas 2, 
	modularzando con funciones. 
*/
/*********************************************************************/

#include <iostream>
using namespace std;

/* Primera solución:
	Declarar la constante como un dato GLOBAL.
	Al ser constante no se pueden producir efectos laterales 
	(ver transparencias de teoría)
*/

/*
const int AMPLITUD = 'a'-'A';      

bool EsMinuscula (char una_letra)
{
	return ((una_letra >= 'a') && (una_letra <= 'z'));
}

bool EsMayuscula (char una_letra)
{
	return ((una_letra >= 'A') && (una_letra <= 'Z'));
}

char Convierte_a_Mayuscula (char caracter)
{             
	char caracter_convertido;

	if (EsMinuscula(caracter))
		caracter_convertido = caracter - AMPLITUD;
	else
		caracter_convertido = caracter;

	return (caracter_convertido);
}

char Convierte_a_Minuscula (char caracter)
{             
	char caracter_convertido;

	if (EsMayuscula(caracter))
		caracter_convertido = caracter + AMPLITUD;
	else
		caracter_convertido = caracter;

	return (caracter_convertido);
}

char Transforma (char caracter)
{           
	char caracter_convertido;

	if (EsMinuscula(caracter))
		caracter_convertido = Convierte_a_Mayuscula (caracter);
	else
		if (EsMayuscula(caracter))
			caracter_convertido = Convierte_a_Minuscula (caracter);
		else
			caracter_convertido = caracter;

	return (caracter_convertido);
}
*/

/* Segunda solución:
	Declarar una función que devuelva dicho valor
*/

/*********************************************************************/

int Dif_Mays_Mins()
{
	// 'a' tiene código ASCII 97 y 'A' tiene código ASCII 65 	

	return ('a'-'A');
}      

/*********************************************************************/

bool EsMinuscula (char una_letra)
{
	return ((una_letra >= 'a') && (una_letra <= 'z'));
}

/*********************************************************************/

bool EsMayuscula (char una_letra)
{
	return ((una_letra >= 'A') && (una_letra <= 'Z'));
}

/*********************************************************************/

char Convierte_a_Mayuscula (char caracter)
{             
	char caracter_convertido;

	if (EsMinuscula(caracter))
		caracter_convertido = caracter - Dif_Mays_Mins();
	else
		caracter_convertido = caracter;

	return (caracter_convertido);
}

/*********************************************************************/

char Convierte_a_Minuscula (char caracter)
{             
	char caracter_convertido;

	if (EsMayuscula(caracter))
		caracter_convertido = caracter + Dif_Mays_Mins();
	else
		caracter_convertido = caracter;

	return (caracter_convertido);
}

/*********************************************************************/

char Transforma (char caracter)
{           
	char caracter_convertido;

	if (EsMinuscula(caracter))
		caracter_convertido = Convierte_a_Mayuscula (caracter);
	else
		if (EsMayuscula(caracter))
			caracter_convertido = Convierte_a_Minuscula (caracter);
		else
			caracter_convertido = caracter;

	return (caracter_convertido);
}

/*********************************************************************/

int main()
{
	char caracter, nuevo_caracter;

	cout << "\nIntroduzca un carácter (* para terminar) --> ";
	cin >> caracter;

	while (caracter != '*') { 

		nuevo_caracter = Transforma (caracter);

		cout << "\nEl carácter " << caracter 
			 << " una vez convertido es: " << nuevo_caracter;
		cout << "\n";  

		cout << "\nIntroduzca un carácter (* para terminar) --> ";
		cin >> caracter;
	}

	cout << "\n\n";   

	system("pause");
}