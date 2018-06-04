/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
// GRADO EN INGENIER�A INFORM�TICA
//
// CURSO 2013-2014
// (C) JUAN CARLOS CUBERO TALAVERA
// (C) FRANCISCO JOS� CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACI�N E INTELIGENCIA ARTIFICIAL
//
// RELACI�N DE PROBLEMAS 3
// EJERCICIO 6
//
/*	
	Leer un car�cter desde teclado, y:
	1) si es may�scula, pasarlo a min�scula.
	2) si es min�scula, pasarlo a may�scula.
	3) si no es un car�cter alfab�tico, dejarlo tal cual.

	Ampliaci�n del ejercicio 5 de la Relaci�n de Problemas 2, 
	modularzando con funciones. 
*/
/*********************************************************************/

#include <iostream>
using namespace std;

/* Primera soluci�n:
	Declarar la constante como un dato GLOBAL.
	Al ser constante no se pueden producir efectos laterales 
	(ver transparencias de teor�a)
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

/* Segunda soluci�n:
	Declarar una funci�n que devuelva dicho valor
*/

/*********************************************************************/

int Dif_Mays_Mins()
{
	// 'a' tiene c�digo ASCII 97 y 'A' tiene c�digo ASCII 65 	

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

	cout << "\nIntroduzca un car�cter (* para terminar) --> ";
	cin >> caracter;

	while (caracter != '*') { 

		nuevo_caracter = Transforma (caracter);

		cout << "\nEl car�cter " << caracter 
			 << " una vez convertido es: " << nuevo_caracter;
		cout << "\n";  

		cout << "\nIntroduzca un car�cter (* para terminar) --> ";
		cin >> caracter;
	}

	cout << "\n\n";   

	system("pause");
}