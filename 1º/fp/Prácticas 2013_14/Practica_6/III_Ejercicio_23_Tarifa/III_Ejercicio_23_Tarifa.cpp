/* 
	2013 - FP
	------------------------------
	Programa para calcular el precio de un vuelo dependiendo de 
	la distancia recorrida.

	Necesita: Distancia y si es cliente previo.
	
	Calcula: El precio aplicando los descuentos ofertados por 
	la compañía.
*/
#include <iostream>
#include <cctype>
using namespace std;

//Función que calcula un porcentaje en base a unos valores dados
double Porcentaje(double tarifa,double descuento) {

	double resultado = tarifa * descuento/100.0;

	return resultado;
}

//Programa Principal
int main()
{
	//Declaración de variables
	const double TARIFA_BASE = 150.0;

	const int    LIMITE_KMS_TARIFICACION_ADICIONAL = 200;
	const double TARIFA_POR_KM_ADICIONAL = 0.1;

	const int    MINIMO_KMS_TRAYECTO_MEDIO = 600;
	const int    MINIMO_KMS_TRAYECTO_LARGO = 1100;

	const double DESCUENTO_TRAYECTO_MEDIO = 3.0;  // 3%
	const double DESCUENTO_TRAYECTO_LARGO = 4.0;  // 4%
	const double DESCUENTO_CLIENTE_PREVIO = 5.0;  // 5%

	const double REBAJA_LINEAL = 15.0;			  // 15 Euros

	double	tarifa_con_km_adicionales, 
			tarifa_final_descuentos_acumulados, 
			tarifa_final_descuentos_excluyentes, 
			rebaja;

	int distancia_recorrido, 
		distancia_tarificacion_adicional;

	bool es_cliente_previo;
	char opcion_es_cliente_previo;

	bool es_trayecto_medio, es_trayecto_largo;

	//Obtenemos los datos necesarios
	cout << "\Introduzca la distancia del recorrido del viaje: ";
	cin >> distancia_recorrido;

	cout << "¿Es un cliente previo (s/n)? ";
	cin >> opcion_es_cliente_previo;

	opcion_es_cliente_previo = toupper(opcion_es_cliente_previo);
	
	es_cliente_previo = (opcion_es_cliente_previo == 'S');  
	// En el caso de que introduzca cualquier carácter distinto a 
	// 's' y 'S' se considera que NO es cliente previo

	//Hacemos los cálculos

	tarifa_con_km_adicionales = TARIFA_BASE;

	if (distancia_recorrido > LIMITE_KMS_TARIFICACION_ADICIONAL) {

		distancia_tarificacion_adicional = 
		         distancia_recorrido - LIMITE_KMS_TARIFICACION_ADICIONAL;

		tarifa_con_km_adicionales = tarifa_con_km_adicionales + 
			(distancia_tarificacion_adicional) * TARIFA_POR_KM_ADICIONAL;
	}

	es_trayecto_medio = 
		(distancia_recorrido >= MINIMO_KMS_TRAYECTO_MEDIO) && 
		(distancia_recorrido <  MINIMO_KMS_TRAYECTO_LARGO);

	es_trayecto_largo = 
		(distancia_recorrido >= MINIMO_KMS_TRAYECTO_LARGO);


	// Política 1

	rebaja = REBAJA_LINEAL;

	if (es_cliente_previo)
		rebaja = rebaja + Porcentaje(tarifa_con_km_adicionales,DESCUENTO_CLIENTE_PREVIO); 
	if (es_trayecto_medio)
		rebaja = rebaja + Porcentaje(tarifa_con_km_adicionales,DESCUENTO_TRAYECTO_MEDIO);
	else if (es_trayecto_largo)
		rebaja = rebaja + Porcentaje(tarifa_con_km_adicionales,DESCUENTO_TRAYECTO_LARGO);
	

	// Cuidado: por si la rebaja lineal fuese mayor que el precio del billete

	if (rebaja < tarifa_con_km_adicionales)                     
		tarifa_final_descuentos_acumulados = 
				tarifa_con_km_adicionales - rebaja;
	else
		tarifa_final_descuentos_acumulados = 0.0;

	cout << "\n\nTarifa final (todos los descuentos): ";
	cout << tarifa_final_descuentos_acumulados;


	// Política 2

	rebaja = REBAJA_LINEAL;
	/*NOTA no se puede pasar a funcion esto y lo de arriba porque los IF 
	son distinto, uno es un IF y el otro un ELSE IF*/
	if (es_cliente_previo)
		rebaja = rebaja + Porcentaje(tarifa_con_km_adicionales,DESCUENTO_CLIENTE_PREVIO);
	else if (es_trayecto_medio)
		rebaja = rebaja + Porcentaje(tarifa_con_km_adicionales,DESCUENTO_TRAYECTO_MEDIO);
	else if (es_trayecto_largo)
		rebaja = rebaja + Porcentaje(tarifa_con_km_adicionales,DESCUENTO_TRAYECTO_LARGO);

	// Cuidado: por si la rebaja lineal fuese mayor que el precio del billete
   	
   if (rebaja < tarifa_con_km_adicionales)                     
	   tarifa_final_descuentos_excluyentes = 
			tarifa_con_km_adicionales - rebaja;
   else
      tarifa_final_descuentos_excluyentes = 0.0;

	//Pintamos los valores en la consola
	cout << "\n\nTarifa final (cliente previo, de forma excluyente) ";
	cout << tarifa_final_descuentos_excluyentes;

	cout << "\n\n";

	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");
}