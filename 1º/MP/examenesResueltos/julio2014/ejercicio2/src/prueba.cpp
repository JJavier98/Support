
#include <iostream>
#include "barquito.h"

using namespace std;

// Inicializacion de IDENTIFICADOR
const string Barquito::IDENTIFICADOR="MP-BARQ-V1.0";

/*
 * 
 */
int main(int argc, char** argv) {

    // Pensamos en formas de crear un tablero de 12X11
    cout << "Creacion de tablero de 12 x 11......" << endl;
    Barquito barquito(12, 11);

    // Se posiciona un barquito de tamaño 4 en posicion aleatoria
    barquito.posicionarBarco(4);
    
    // Se posiciona un barquito de tamaño 3
    barquito.posicionarBarco(3);
    
    // Se muestra el tablero
    barquito.mostrarTablero();
    
    // Se escribe en un archivo
    barquito.escribir("barquito1.dat");

    // Se crea un barquito vacio de 3x3
    Barquito barquito2(3,4);
    
    // Si se lee el archivo sobre barquito2 debe terminar
    // siendo igual que el primer objeto
    barquito2.leer("barquito1.dat");
    
    // Se muestra el contenido
    barquito2.mostrarTablero();
    
    // Sentencia return indicando al SO todo OK
    return 0;
}

