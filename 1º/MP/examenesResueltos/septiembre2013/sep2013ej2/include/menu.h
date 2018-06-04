/* 
 * File:   menu.h
 * Author: mgomez
 *
 * Created on 6 de junio de 2016, 13:34
 */

#ifndef MENU_H
#define	MENU_H

#include<string.h>
#include<iostream>

using namespace std;

class Menu{
private:
   char *titulo;
   char **opc;
   int nopc;
   
   void liberarEspacio();
   
   void copiarDatos(const Menu & otro);
   
public:
   
   Menu();
   
   ~Menu();
   
   Menu(const Menu &otro);
   
   const Menu & operator=(const Menu &otro);
   
   void setTitulo(char *titulo);
   
   int getNumeroOpciones();
   
   void addOpcion(char *opcion);
   
   void operator>>(int & opcion);
   
   friend ostream & operator<<(ostream & flujo, const Menu &objeto);
};


#endif	/* MENU_H */

