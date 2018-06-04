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
// EJERCICIOS 20 y 34 
//
/*	
	Este programa gestiona las n�minas de los empleados de una empresa. 
	El c�mputo de la n�mina se realiza en base a los siguientes criterios:
	a)	Categor�as laborales: Operario, Base, Administrativo y Directivo.
	b)	El salario base depende de la antig�edad del trabajador y de su 
		categor�a laboral (Operario = 900 euros, Base = 1100, 
		Administrativos = 1200, Directivos=2000). 
		Este salario base se incrementa con un tanto por ciento igual 
		al n�mero de a�os trabajados.
	c)	Complementos en su n�mina por el n�mero de horas extraordinarias. 
		La hora extra se paga: 16 euros para operarios, 23 para el puesto 
		Base, 25 para los Administrativos y para 30 los Directivos. 
		A este complemento se le aplica una subida con un tanto por ciento 
		igual al n�mero de a�os trabajados.
*/
/*********************************************************************/

#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

/*********************************************************************/
// Tipo enumerado para las categorias laborales

enum EnumCategoriaLaboral{Operario, Base, Administrativo, Directivo};

///////////////////////////////////////////////////////////////////////
// Cada empleado tendr� asociado un objeto de la clase "Salario"
/*
	Comentario avanzado sobre el dise�o de la clase:
		Observad los if-else de los m�todos CuantiaBase() y 
		ComplementoHorasExtraordinarias().
		Esto nos dice que hay distintos tipos de empleados, para los 
		cuales dichos m�todos se comportan de forma distinta. 
		El resto de m�todos de la clase Salario tienen el mismo 
		comportamiento, independientemente del tipo de empleado.
		Esto nos llevar�a a una mejora en el dise�o utilizando la t�cnica de 
		"herencia", aunque est� fuera del objetivo de la asignatura. 
*/

class Salario
{
private:

	EnumCategoriaLaboral categoria_laboral;	// Categoria
	unsigned int anios_antiguedad;			// a�os de antig�edad
	unsigned int horas_extraordinarias;		// horas extraordinarias

public:

	/*****************************************************************/
	// Constructor con argumentos
	//
	// El constructor recibe como argumentos valores para los tres 
	// campos privados. Lo hacemos as� porque suponemos que en la empresa, 
	// la mayor parte de los trabajadores realizan horas extraordinarias. 
	// Si no fuera s�, podr�amos omitir el n�mero de horas extra como 
	// par�metro al constructor y asignar el dato miembro privado 
	// "horas_extraordinarias" a cero (en el constructor).
	//
	// Posteriormente, no permitimos modificar los dos primeros valores, 
	// pero s� el tercero
	//
	// As� pues, un objeto de tipo Salario me sirve para gestionar �nicamente 
	// una misma categor�a, con un n�mero de a�os de antiguedad, aunque 
	// permito ir cambiando las horas extra.

	Salario (EnumCategoriaLaboral categoria_laboral_trabajador, 
			 unsigned int anios_antiguedad_trabajador, 
			 unsigned int horas_extraordinarias_trabajadas)
	{
		categoria_laboral = categoria_laboral_trabajador;
		anios_antiguedad = anios_antiguedad_trabajador;
		horas_extraordinarias = horas_extraordinarias_trabajadas;
	}

	/*****************************************************************/
	// M�todo Set para el campo "horas_extraordinarias", el �nico
	// que puede modificarse una vez construido el objeto

	void SetHorasExtraordinarias(unsigned int horas_extras_trabajadas)
	{
		horas_extraordinarias = horas_extras_trabajadas;
	}

	/*****************************************************************/
	// M�todos Get para la lectura de los campos privados
	
	EnumCategoriaLaboral GetCategoriaLaboral()
	{
		return (categoria_laboral);
	}

	int GetHorasExtraordinarias()
	{
		return (horas_extraordinarias);
	}

	/*****************************************************************/
	// Calcula la parte de salario que corresponde al sueldo base m�s 
	// el incremento que le corresponde por a�os de antig�edad.

	double CuantiaBase()
	{
		double cuantia_base;

		if (categoria_laboral == Operario)
			cuantia_base = 900;
		else if (categoria_laboral == Base)
			cuantia_base = 1100;
		else if (categoria_laboral == Administrativo)
			cuantia_base = 1200;
		else if (categoria_laboral == Directivo)
			cuantia_base = 2000;

		return (AplicaAumento(cuantia_base, anios_antiguedad));
	}

	/*****************************************************************/
	// Calcula la parte de salario que corresponde por horas 
	// extraordinarias y el incremento que le corresponde a esta 
	// parte por a�os de antig�edad.

	double ComplementoHorasExtraordinarias()
	{
		double total;
		double cuantia_por_hora;

		if (categoria_laboral == Operario)
			cuantia_por_hora = 16;
		else if (categoria_laboral == Base)
			cuantia_por_hora = 23;
		else if (categoria_laboral == Administrativo)
			cuantia_por_hora = 25;
		else if (categoria_laboral == Directivo)
			cuantia_por_hora = 30;

		total = cuantia_por_hora * horas_extraordinarias;

		return (AplicaAumento(total, anios_antiguedad));
	}

	/*****************************************************************/
	// Calcula el sueldo actualizado sumando los dos componentes 

	double Total_a_Cobrar()
	{
		return (CuantiaBase() + ComplementoHorasExtraordinarias());
	}

	/*****************************************************************/

private: 

	/*********************************************************************/
	// Incrementa "valor_inicial" en el porcentaje indicado por 
	// "aumento_porcentual" y devuelve el valor incrementado 

	double AplicaAumento(double valor, double aumento_porcentual)
	{
		return (valor * (1 + (aumento_porcentual/100.0)));
	}

	/*********************************************************************/
};

///////////////////////////////////////////////////////////////////////

/*********************************************************************/

int main()
{
	
	cout.setf(ios::fixed);		// Notaci�n de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales 


	unsigned int anios_antiguedad = 3;
	unsigned int horas_extras = 10;
 
	// Creaci�n de los objetos Salario --> constructor
  
	Salario salario_Operario  (Operario, anios_antiguedad, horas_extras);
	Salario salario_Directivo (Directivo, anios_antiguedad, horas_extras);
	
	// Calculo del salario tras los incrementos por antig�edad y por 
	// horas trabajadas: act�a el m�todo Total_a_Cobrar()

	cout << "\nSalarios con antig�edad = " << anios_antiguedad << " a�os y " 
		 << horas_extras << " horas extraordinarias";
	cout << "\n\tSalario del operario:  " << setw(10) << setprecision(2) 
		 << salario_Operario.Total_a_Cobrar();
	cout << "\n\tSalario del directivo: " << setw(10) << setprecision(2) 
		 << salario_Directivo.Total_a_Cobrar();
 
	// Actualizaci�n del n�mero de horas extra del operario (+5)
	// �ste es el �nico campo modificable

	salario_Operario.SetHorasExtraordinarias(
			salario_Operario.GetHorasExtraordinarias()+ 5);

	cout << "\n\nEl operario ha trabajado 5 horas extras m�s.";
	cout << "\n\tNuevo salario del operario:  " << setw(10) << setprecision(2) 
		 << salario_Operario.Total_a_Cobrar();

	cout << "\n\n";
	system("pause");
	return (0);
}