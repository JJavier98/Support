﻿/******************************************************************************
 *
 * Metodología de la Programación
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano Collado
 * ------------------------------
 *
 *  Escribir un programa que lea una secuencia indefinida de caracteres de la 
 *  entrada estandar y muestre en la salida estandar unicamente las lineas 
 *  no vacias que hay en esa secuencia.
 *
 ******************************************************************************/
#include <iostream> // Inclusión de los recursos de E/S

#include <fstream>
#include <cstdlib>

using namespace std;

// Declaramos la funcion, para no tener que escribirla al principio
void copiar (istream & entrada);

/************************************************/
// Programa Principal
int main (int argc, char **argv) {

    copiar(cin);

    // Terminamos la ejecución del programa
    return (0);
}

/************************************************/
// Copia la entrada en la salida omitiendo las lineas en blanco
void copiar (istream & entrada) {

    char c[256];

    entrada.getline(c, 256);

    while (!entrada.eof()) {


        // Comprobamos que la linea no esté vacia
        if (strlen(c) > 0) {
            // La pintamos en la salida estándar
            cout << c << endl;
        }

        // Vamos leyendo líneas
        entrada.getline(c, 256);

    } 

    // // Comprobamos que la linea no esté vacia
    // if (strlen(c) > 0) {
    //     // La pintamos en la salida estándar
    //     cout << c << endl;
    // }

}
/************************************************/
