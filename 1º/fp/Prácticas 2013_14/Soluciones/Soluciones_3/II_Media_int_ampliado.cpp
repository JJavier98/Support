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
// EJERCICIO 1
/*	
	Amplici�n del ejercicio I-7 
	Ahora, una vez calculada la media y la desviaci�n, el programa imprime 
	por cada uno de los valores si est� por encima o por debajo de la media.
	
	Entradas: los tres valores (altura1, altura2 y altura3) 

	Salidas:  El valor de la media y de la desviaci�n t�pica calculada 
			  mediante las expresiones conocidas: 

				(N es el n�mero de muestras)
 
			         1    N 
			media = --- suma (x_i)
			         N   i=1
			                ________________________________
			               /   1     N  (                 )
			desviacion =  / ( ---  suma ( (x_i - media)^2 )
			             V     N    i=1 (                 )

			y para cada valor, su relaci�n con la media.
*/
/*********************************************************************/


#include <iostream>
#include <cmath>
#include <string>    //  <- Es necesario para poder imprimir un string con cout

using namespace std;

int main()
{
	const string MENSAJE_ENTRADA_DATOS = "\nIntroduzca una altura en cm --> ";

	int		altura1, altura2, altura3;	// Datos de entrada
	double	media, desviacion;			// Datos de salida (Resultados)

	// Entrada

	cout << MENSAJE_ENTRADA_DATOS;
	cin >> altura1;
	cout << MENSAJE_ENTRADA_DATOS;
	cin >> altura2;   
	cout << MENSAJE_ENTRADA_DATOS;
	cin >> altura3;
   
	// C�lculos

	media = (altura1 + altura2 + altura3) / 3.0;  
	// Si las x_i son enteras, hay que dividir por 3.0 y no por 3 !!!

	desviacion =  sqrt( (
						  pow(altura1 - media , 2) +  
						  pow(altura2 - media , 2) + 
						  pow(altura3 - media , 2)
						 ) / 3.0
						);
   
	// Salida

	cout << "\nMedia aritm�tica: " << media;
	cout << "\nDesviaci�n t�pica: " << desviacion;
	cout << "\n\n";

	if (altura1 < media) 
		cout << altura1 << " es menor que su media\n";
	else 
		cout << altura1 << " es mayor o igual que su media\n";

	if (altura2 < media) 
		cout << altura2 << " es menor que su media\n";
	else 
		cout << altura2 << " es mayor o igual que su media\n";

	if (altura3 < media) 
		cout << altura3 << " es menor que su media\n";
	else 
		cout << altura3 << " es mayor o igual que su media\n";

	cout << "\n\n";



	system("pause");
}

