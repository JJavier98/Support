
#include <iostream>
#include <string>
#include "menu.h"

using namespace std;

int main(){
   // Se crea objeto de la clase menu
   Menu menu;
   
   // Se asigna el titulo
   char titulo[]="Menu de prueba de programa de examen";
   menu.setTitulo(titulo);
   
   // Se agregan 4 opciones
   char opcion1[]="1. Opcion 1";
   char opcion2[]="2. Opcion 2";
   char opcion3[]="3. Opcion 3";
   char opcion4[]="4. Opcion 4";
   
   menu.addOpcion(opcion1);
   menu.addOpcion(opcion2);
   menu.addOpcion(opcion3);
   menu.addOpcion(opcion4);
   
   // Se muestra por pantalla
   cout << menu;
   
   // Se elige una opcion
   int opcion;
   menu >> opcion;
   cout << "Opcion elegida: " << opcion << endl;
}
