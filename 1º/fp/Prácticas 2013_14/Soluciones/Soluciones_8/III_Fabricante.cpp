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
// EJERCICIO 19 
//
/*	
	Este programa ampl�a la funcionalidad descrita en los ejercicios 
	6 y 10 de la Relaci�n de Problemas I acerca del reparto de ganancias 
	entre los 3 fabricantes y el dise�ador de un producto sabiendo que 
	el dise�ador cobra el doble que cada uno de los fabricantes. 

	En esta nueva versi�n se va a aplicar una retenci�n fiscal para el 
	c�mputo de los salarios netos. Dicha retenci�n puede ser distinta 
	para el fabricante y el dise�ador.

	La clase "Nomina" debe proporcionar, al menos, los m�todos 
	SalarioNetoDisenador() y SalarioNetoFabricante(). 
*/
/*********************************************************************/


#include <iostream>
#include <iomanip>
using namespace std;


/*********************************************************************/
// Decrementa "valor_bruto" en el porcentaje indicado por 
// "retencion_porcentual" y devuelve el valor disminuido 
//	
//	Como norma general no debemos usar funciones globales.
//	Sin embargo, hay casos en los que s� puede justificarse su uso.
//	Por ejemplo, cuando trabajamos con datos simples (int, double, etc) 
//	y son funciones muy gen�ricas que se usar�n en muchos otros programas.
//	Tal es el caso de la funci�n AplicaRetencion().
//
//	En el ejercicio 20 de esta misma relaci�n encontraremos un caso 
//  similar a �ste y lo resolvemos empleando un m�todo privado.

double AplicaRetencion(double valor_bruto, double retencion_porcentual)
{
	return (valor_bruto * (1 - (retencion_porcentual/100.0)));
}


///////////////////////////////////////////////////////////////////////
//	Notas de dise�o sobre la clase "Nomina": 
/*

	1) En el caso de que quisi�semos que todos los objetos de la clase
	"Nomina" tuviesen la misma retenci�n, deber�amos usar una constante 
	est�tica (constante a nivel de clase) con el valor de retenci�n fiscal 
	a aplicar, por ejemplo, 25.
	Pero entonces, la clase "Nomina" s�lo servir�a para una retenci�n del 25%. 
	Habr�a que cambiar la definici�n de la clase si se quisiese aplicar otra 
	retenci�n.
	
	Otra opci�n es declarar la retenci�n como constante a nivel de objeto.
	As�, cada objeto tendr� un valor propio de retenci�n fiscal. Por tanto, 
	dos objetos distintos de tipo "Nomina" podr�n tener retenciones fiscales 
	distintas.

	Hemos optado por la segunda soluci�n, y en este caso, la retenci�n fiscal 
	la pasamos en el constructor y no permitimos que luego sea modificada. 

	2) Hemos decidido permitir asignar a un mismo objeto "Nomina" distintos 
	ingresos totales, es decir, que podemos calcular y cambiar los salarios 
	de fabricante y dise�ador en tiempo de ejecuci�n. Para realizar esta 
	tarea incorporamos el m�todo SetIngresosTotales().
	Si no fueraa as�, suprimir�amos el m�todo y pasar�amos el valor de los 
	ingresos totales �nicamente en el constructor. 
*/

class Nomina
{

private:
   double salario_bruto_diseniador;
   double salario_bruto_fabricante;

   const int PORC_RETENCION_FISCAL_DISENIADOR; // Constantes de objeto
   const int PORC_RETENCION_FISCAL_FABRICANTE;

public:   

	/*****************************************************************/
	// Constructor con argumentos
	// 
	// Observad c�mo deben inicarse las constantes a nivel de objeto, 
	// mediante la lista de iniciaci�n ": constante (valor_de_la_cte)" 

	Nomina (int porc_retencion_diseniador, 
			int porc_retencion_fabricante, 
			double ingresos_totales_nomina) : 
			PORC_RETENCION_FISCAL_DISENIADOR (porc_retencion_diseniador), 
			PORC_RETENCION_FISCAL_FABRICANTE (porc_retencion_fabricante)
	{
		SetIngresosTotales(ingresos_totales_nomina);
	}

	/*****************************************************************/
	// M�todo Set para los dos campos privados. 
	// Reparte los beneficios entre entre los fabricantes (3) y el 
	// dise�ador (1) de un producto sabiendo que el dise�ador cobra el 
	// doble que cada uno de los fabricantes. 

	void SetIngresosTotales(double ingresos_totales)
	{
		salario_bruto_fabricante = ingresos_totales / 5.0;
		salario_bruto_diseniador = 2.0 * salario_bruto_fabricante;
	}

   	/*****************************************************************/
	// M�todos Get para los porcentajes de retenci�n
 	/*
		Si lo estimamos oportuno, podr�amos a�adir m�todos Get para obtener 
		los valores actuales de ingresos totales (para lo cual habr�a 
		que a�adir un dato miembro).
	*/

	int GetPorcRetencionFiscalFabricante()
	{
      return (PORC_RETENCION_FISCAL_FABRICANTE);
	}

	int GetPorcRetencionFiscalDiseniador()
	{
      return (PORC_RETENCION_FISCAL_DISENIADOR);
	}

	/*****************************************************************/
	// M�todos de c�lculo. 
	// Calculan los salarios netos despu�s de reducir la retenci�n 
	// correspondiente.

	double SalarioNetoDiseniador()
	{
		return AplicaRetencion (salario_bruto_diseniador, 
							    PORC_RETENCION_FISCAL_DISENIADOR);
	}

	double SalarioNetoFabricante()
	{
		return AplicaRetencion (salario_bruto_fabricante, 
							    PORC_RETENCION_FISCAL_FABRICANTE);
	}

	/*****************************************************************/
	// M�todo de c�lculo. 
	// Calcula el dinero a pagar por impuestos

	double CalculaImpuestosTotales ()
	{
		double imp_fabricante, imp_diseniador;

		imp_fabricante = salario_bruto_fabricante - SalarioNetoFabricante();
		imp_diseniador = salario_bruto_diseniador - SalarioNetoDiseniador();

		return (3.0*imp_fabricante + imp_diseniador);
	}

   	/*****************************************************************/

};

///////////////////////////////////////////////////////////////////////

/*********************************************************************/

int main()
{
	
	cout.setf(ios::fixed);		// Notaci�n de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales 


	double	ingresos_una_empresa;
	int		porc_retencion_diseniador, 
			porc_retencion_fabricante;

	cout << "Introduzca cantidad total de ingresos: ";
	cin >> ingresos_una_empresa;

	cout << "Introduzca porcentaje de retenci�n para el dise�ador: ";
	cin >> porc_retencion_diseniador;

	cout << "Introduzca porcentaje de retenci�n para un fabricante: ";
	cin >> porc_retencion_fabricante;


	// Durante la ejecuci�n del programa, el objeto "una_nomina" tendr� 
	// valores constantes de retenci�n. 
	// Si se ejecuta el programa en otro momento, pueden usarse otros 
	// valores de retenci�n.
	// Podr�a tener en la funci�n main() varios objetos de tipo "Nomina", 
	// para manejar n�minas de distintas empresas con distintas retenciones 
	// (empresas que se ajusten al criterio de c�mputo de los salarios de 
	// dise�ador y fabricantes)

	// Creaci�n de un objeto "Nomina" --> constructor
  
	Nomina nomina_empresa (porc_retencion_diseniador, 
						   porc_retencion_fabricante, 
						   ingresos_una_empresa);
	
	
	cout << "\n\nN�mina inicial:\n";

	cout << "\nN�mina del dise�ador      (Ret = " << setw(2) 
		 << nomina_empresa.GetPorcRetencionFiscalDiseniador() 
		 << " %) = " << setw(10) << setprecision(2) 
		 << nomina_empresa.SalarioNetoDiseniador();
 
	cout << "\nN�mina de cada fabricante (Ret = " << setw(2) 
		 << nomina_empresa.GetPorcRetencionFiscalFabricante() 
		 << " %) = " << setw(10) << setprecision(2) 
		 << nomina_empresa.SalarioNetoFabricante();

	cout << "\n\nDise�ador   = " << setw(10) << setprecision(2) 
		 << nomina_empresa.SalarioNetoDiseniador()
		 << " ---------> " << setw(10) << setprecision(2) 
		 << nomina_empresa.SalarioNetoDiseniador();
	cout << "\nFabricantes = " << setw(10) << setprecision(2) 
		 << nomina_empresa.SalarioNetoFabricante()
		 << " -- x 3 --> " << setw(10) << setprecision(2) 
		 << 3.0 * nomina_empresa.SalarioNetoFabricante();
	cout << "\nImpuestos totales =                 " 
		 << setw(10) << setprecision(2) 
		 << nomina_empresa.CalculaImpuestosTotales();
	cout << "\n                                     ---------";
	cout << "\n                                    "
		 << setw(10) << setprecision(2) 
		 << (nomina_empresa.SalarioNetoDiseniador() + 
		 3.0 * nomina_empresa.SalarioNetoFabricante() + 
		 nomina_empresa.CalculaImpuestosTotales());


	// Los ingresos de la empresa aumentan un 10 %
	// Podemos recalcular los salarios haciendo uso del m�todo 
	// SetIngresosTotales() 

	nomina_empresa.SetIngresosTotales(ingresos_una_empresa * 1.2);

	cout << "\n\n\nDespu�s de una subida de ingresos del 20%:\n";

	cout << "\nN�mina del dise�ador      (Ret = " << setw(2) 
		 << nomina_empresa.GetPorcRetencionFiscalDiseniador() 
		 << " %) = " << setw(10) << setprecision(2) 
		 << nomina_empresa.SalarioNetoDiseniador();
 
	cout << "\nN�mina de cada fabricante (Ret = " << setw(2) 
		 << nomina_empresa.GetPorcRetencionFiscalFabricante() 
		 << " %) = " << setw(10) << setprecision(2) 
		 << nomina_empresa.SalarioNetoFabricante();

	cout << "\n\nDise�ador   = " << setw(10) << setprecision(2) 
		 << nomina_empresa.SalarioNetoDiseniador()
		 << " ---------> " << setw(10) << setprecision(2) 
		 << nomina_empresa.SalarioNetoDiseniador();
	cout << "\nFabricantes = " << setw(10) << setprecision(2) 
		 << nomina_empresa.SalarioNetoFabricante()
		 << " -- x 3 --> " << setw(10) << setprecision(2) 
		 << 3.0 * nomina_empresa.SalarioNetoFabricante();
	cout << "\nImpuestos totales =                 " 
		 << setw(10) << setprecision(2) 
		 << nomina_empresa.CalculaImpuestosTotales();
	cout << "\n                                     ---------";
	cout << "\n                                    "
		 << setw(10) << setprecision(2) 
		 << (nomina_empresa.SalarioNetoDiseniador() + 
		 3.0 * nomina_empresa.SalarioNetoFabricante() + 
		 nomina_empresa.CalculaImpuestosTotales());

	cout << "\n\n";
	system("pause");
}

