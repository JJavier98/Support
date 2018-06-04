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
// EJERCICIO 19 
//
/*	
	Este programa amplía la funcionalidad descrita en los ejercicios 
	6 y 10 de la Relación de Problemas I acerca del reparto de ganancias 
	entre los 3 fabricantes y el diseñador de un producto sabiendo que 
	el diseñador cobra el doble que cada uno de los fabricantes. 

	En esta nueva versión se va a aplicar una retención fiscal para el 
	cómputo de los salarios netos. Dicha retención puede ser distinta 
	para el fabricante y el diseñador.

	La clase "Nomina" debe proporcionar, al menos, los métodos 
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
//	Sin embargo, hay casos en los que sí puede justificarse su uso.
//	Por ejemplo, cuando trabajamos con datos simples (int, double, etc) 
//	y son funciones muy genéricas que se usarán en muchos otros programas.
//	Tal es el caso de la función AplicaRetencion().
//
//	En el ejercicio 20 de esta misma relación encontraremos un caso 
//  similar a éste y lo resolvemos empleando un método privado.

double AplicaRetencion(double valor_bruto, double retencion_porcentual)
{
	return (valor_bruto * (1 - (retencion_porcentual/100.0)));
}


///////////////////////////////////////////////////////////////////////
//	Notas de diseño sobre la clase "Nomina": 
/*

	1) En el caso de que quisiésemos que todos los objetos de la clase
	"Nomina" tuviesen la misma retención, deberíamos usar una constante 
	estática (constante a nivel de clase) con el valor de retención fiscal 
	a aplicar, por ejemplo, 25.
	Pero entonces, la clase "Nomina" sólo serviría para una retención del 25%. 
	Habría que cambiar la definición de la clase si se quisiese aplicar otra 
	retención.
	
	Otra opción es declarar la retención como constante a nivel de objeto.
	Así, cada objeto tendrá un valor propio de retención fiscal. Por tanto, 
	dos objetos distintos de tipo "Nomina" podrán tener retenciones fiscales 
	distintas.

	Hemos optado por la segunda solución, y en este caso, la retención fiscal 
	la pasamos en el constructor y no permitimos que luego sea modificada. 

	2) Hemos decidido permitir asignar a un mismo objeto "Nomina" distintos 
	ingresos totales, es decir, que podemos calcular y cambiar los salarios 
	de fabricante y diseñador en tiempo de ejecución. Para realizar esta 
	tarea incorporamos el método SetIngresosTotales().
	Si no fueraa así, suprimiríamos el método y pasaríamos el valor de los 
	ingresos totales únicamente en el constructor. 
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
	// Observad cómo deben inicarse las constantes a nivel de objeto, 
	// mediante la lista de iniciación ": constante (valor_de_la_cte)" 

	Nomina (int porc_retencion_diseniador, 
			int porc_retencion_fabricante, 
			double ingresos_totales_nomina) : 
			PORC_RETENCION_FISCAL_DISENIADOR (porc_retencion_diseniador), 
			PORC_RETENCION_FISCAL_FABRICANTE (porc_retencion_fabricante)
	{
		SetIngresosTotales(ingresos_totales_nomina);
	}

	/*****************************************************************/
	// Método Set para los dos campos privados. 
	// Reparte los beneficios entre entre los fabricantes (3) y el 
	// diseñador (1) de un producto sabiendo que el diseñador cobra el 
	// doble que cada uno de los fabricantes. 

	void SetIngresosTotales(double ingresos_totales)
	{
		salario_bruto_fabricante = ingresos_totales / 5.0;
		salario_bruto_diseniador = 2.0 * salario_bruto_fabricante;
	}

   	/*****************************************************************/
	// Métodos Get para los porcentajes de retención
 	/*
		Si lo estimamos oportuno, podríamos añadir métodos Get para obtener 
		los valores actuales de ingresos totales (para lo cual habría 
		que añadir un dato miembro).
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
	// Métodos de cálculo. 
	// Calculan los salarios netos después de reducir la retención 
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
	// Método de cálculo. 
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
	
	cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales 


	double	ingresos_una_empresa;
	int		porc_retencion_diseniador, 
			porc_retencion_fabricante;

	cout << "Introduzca cantidad total de ingresos: ";
	cin >> ingresos_una_empresa;

	cout << "Introduzca porcentaje de retención para el diseñador: ";
	cin >> porc_retencion_diseniador;

	cout << "Introduzca porcentaje de retención para un fabricante: ";
	cin >> porc_retencion_fabricante;


	// Durante la ejecución del programa, el objeto "una_nomina" tendrá 
	// valores constantes de retención. 
	// Si se ejecuta el programa en otro momento, pueden usarse otros 
	// valores de retención.
	// Podría tener en la función main() varios objetos de tipo "Nomina", 
	// para manejar nóminas de distintas empresas con distintas retenciones 
	// (empresas que se ajusten al criterio de cómputo de los salarios de 
	// diseñador y fabricantes)

	// Creación de un objeto "Nomina" --> constructor
  
	Nomina nomina_empresa (porc_retencion_diseniador, 
						   porc_retencion_fabricante, 
						   ingresos_una_empresa);
	
	
	cout << "\n\nNómina inicial:\n";

	cout << "\nNómina del diseñador      (Ret = " << setw(2) 
		 << nomina_empresa.GetPorcRetencionFiscalDiseniador() 
		 << " %) = " << setw(10) << setprecision(2) 
		 << nomina_empresa.SalarioNetoDiseniador();
 
	cout << "\nNómina de cada fabricante (Ret = " << setw(2) 
		 << nomina_empresa.GetPorcRetencionFiscalFabricante() 
		 << " %) = " << setw(10) << setprecision(2) 
		 << nomina_empresa.SalarioNetoFabricante();

	cout << "\n\nDiseñador   = " << setw(10) << setprecision(2) 
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
	// Podemos recalcular los salarios haciendo uso del método 
	// SetIngresosTotales() 

	nomina_empresa.SetIngresosTotales(ingresos_una_empresa * 1.2);

	cout << "\n\n\nDespués de una subida de ingresos del 20%:\n";

	cout << "\nNómina del diseñador      (Ret = " << setw(2) 
		 << nomina_empresa.GetPorcRetencionFiscalDiseniador() 
		 << " %) = " << setw(10) << setprecision(2) 
		 << nomina_empresa.SalarioNetoDiseniador();
 
	cout << "\nNómina de cada fabricante (Ret = " << setw(2) 
		 << nomina_empresa.GetPorcRetencionFiscalFabricante() 
		 << " %) = " << setw(10) << setprecision(2) 
		 << nomina_empresa.SalarioNetoFabricante();

	cout << "\n\nDiseñador   = " << setw(10) << setprecision(2) 
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

