
#include <iostream>
#include "matriz.h"

using namespace std;

/*
 * Metodo main para probar la funcionalidad de la clase Matriz
 */
int main(int argc, char** argv) {
   int tamFilas[]={3,2,5,2};
   
   // Se crea el objeto
   Matriz matriz1(4, tamFilas);
     
   cout << "Introduza elementos: 3 (f1), 2 (f2), 5 (f3), 2 (f4) " << endl;
 
   // Se leen sus valores
   cin >> matriz1;

   // Se muestra por pantalla
   cout << "Matriz leida .........................." <<endl;
   cout << matriz1;
   
   // Se escribe en un archivo
   matriz1.escribirArchivo("matriz1.txt","Contenido de la matriz 1");
   
   // Se crea matriz2 con las mismas dimensiones
   Matriz matriz2(4, tamFilas);
   
   cout << "Lectura del archivo con despcripcion de objeto " << endl;
   
   // Se lee el contenido del archivo
   matriz2.leerArchivo("matriz1.txt");
   
   // Se muestra el contenido de matriz2
   cout << "\nMatriz 2 leida del archivo" << endl;
   cout << matriz2;
   
   // Se usa el constructor de copia
   Matriz matriz3(matriz2);
   
   // Se muestra por pantalla
   cout << "Objeto creado mediante el constructor de copia....." << endl;
   cout << matriz3;
   
   // Se utiliza el operador de asignacion
   Matriz matriz4;
   matriz4=matriz3;
   
   // Se muestra el resultado
   cout << "Matriz creada mediante el operador de asignacion....." << endl;
   cout << matriz4 << endl;
   
   // Se hace el cambio en las filas de matriz
   Matriz matriz5=matriz4.vflip();
   
   // Se muestra el resultado
   cout << "Resultadod de vflip ......" << endl;
   cout << matriz5 << endl;
   
   // Se obtiene el valor maximo de matriz5
   int fila, columna;
   matriz5.obtenerMaximo(fila, columna);
   cout << "Fila " << fila << " y columna " << columna << endl;
   
   // Sentencia return indicando al SO todo OK
   return 0;
}

