/* 
 * File:   Menu.cpp
 * Author: mgomez
 * 
 * Created on 6 de junio de 2016, 13:47
 */

#include "menu.h"

using namespace std;

Menu::Menu() {
   titulo=0;
   opc=0;
   nopc=0;
}

Menu::Menu(const Menu& orig) {
   // Se copian los datos de orig, reservando
   // espacio
   copiarDatos(orig);
}

Menu::~Menu() {
   // Se libera el espacio
   liberarEspacio();
}

const Menu & Menu::operator=(const Menu &otro){
   // Se libera el espacio actual
   liberarEspacio();
   
   // Se copian los datos de otro
   copiarDatos(otro);
   
   // Se devuelve this
   return *this;
}

void Menu::setTitulo(char *titulo){
   // Se libera el espacio del titulo actual, si es
   // necesario
   if (this->titulo != 0){
      delete [] this->titulo;
   }
   
   // Se reserva espacio para el nuevo titulo
   this->titulo=new char[strlen(titulo)];
   
   // Se copia el nuevo titulo
   strcpy(this->titulo, titulo);
}
   
int Menu::getNumeroOpciones(){
   return nopc;
}
   
void Menu::addOpcion(char *opcion){
   // Se reserva espacio para un nuevo array de opciones
   char **nuevoOpc=new char*[nopc+1];
   
   // Todas las opciones previas son validas
   for(int i=0; i < nopc; i++){
      nuevoOpc[i]=opc[i];
   }
   
   // La nueva opcion precisa reserva de espacio
   nuevoOpc[nopc]=new char[strlen(opcion)];
   
   // Se copia la opcion en si
   strcpy(nuevoOpc[nopc],opcion);
   
   // Se libera el array actual de puntero a opciones
   delete [] opc;
   
   // Se apunta al actual
   opc=nuevoOpc;
   
   // Se actualiza el contador de opciones
   nopc++;
}

ostream & operator<<(ostream &flujo, const Menu &objeto){
   flujo << "-------------------------------------------------------" << endl;
   flujo << "              " << objeto.titulo << endl;
   for(int i=0; i < objeto.nopc; i++){
      flujo << objeto.opc[i] << endl;
   }
   flujo << "-------------------------------------------------------" << endl;
   
   // Se devuelve el flujo
   return flujo;
}

void Menu::operator>>(int & opcion){
   // Se muestra por pantalla el menu
   cout << *this;
   
   // Se pide al usuario que se teclee una opcion
   cout << "Seleccione opcion (entre 1 y " << nopc << ") : ";
   opcion=-1;
   while(opcion < 1 || opcion > nopc){
      // Se lee la opcion
      cin >> opcion;
   }
}

void Menu::liberarEspacio(){
   // Se libera el espacio necesario para el titulo
   if (titulo != 0){
      delete [] titulo;
   }
   
   // Se libera el espacio de cada opcion
   for(int i=0; i < nopc; i++){
      delete [] opc[i];
   }
   
   // Se libera el array de punteros
   if (opc != 0){
      delete [] opc;
   }
}

void Menu::copiarDatos(const Menu &otro){
   // Se copia el titulo
   titulo=new char[strlen(otro.titulo)];
   strcpy(titulo,otro.titulo);
   
   // Se asigna el numero de opcion
   nopc=otro.nopc;
   
   // Se crea espacio para las cadenas de las opciones
   opc=new char*[nopc];
   
   // Se copian las opciones
   for(int i=0; i < nopc; i++){
      // Reserva de espacio
      opc[i]=new char[strlen(otro.opc[i])];
      
      // Se copia la cadena
      strcpy(opc[i],otro.opc[i]);
   }   
}

