/* 
 * File:   pareja.h
 * Author: mgomez
 *
 * Created on 9 de junio de 2016, 15:13
 */

#ifndef FRECUENCIAS_H
#define	FRECUENCIAS_H

#include<iostream>

using namespace std;

class Pareja{
public:
   int dato;
   int nveces;
   
   Pareja(){
   }
};

class Frecuencias{
private :
   Pareja *parejas;
   int npares;
   
   void liberarEspacio();
   
   void reservarEspacio(int npares);
   
   void copiarDatos(const Frecuencias &objeto);
   
   int buscarPosicionInsercion(int valor);
public :
   
   Frecuencias();
   
   ~Frecuencias();
   
   Frecuencias(const Frecuencias & objeto);
   
   const Frecuencias & operator=(const Frecuencias &objeto);
   
   void add(int valor);
   
   const Frecuencias & operator+=(int valor);
   
   int repeticiones(int valor);
   
   friend ostream & operator<<(ostream &flujo, const Frecuencias &objeto);
   
   friend istream & operator>>(istream &flujo, Frecuencias & objeto);
};

#endif	/* FRECUENCIAS_H */

