/* 
 * File:   lista.h
 * Author: mgomez
 *
 * Created on 9 de junio de 2016, 15:13
 */

#ifndef LISTA_H
#define	LISTA_H

#include<iostream>

using namespace std;

class Celda{
public:
   Celda *siguiente;
   double valor;
   
   Celda(double valor){
      this->valor=valor;
      siguiente=0;
   }
};

class Lista{
private :
   Celda *primero;

   int longitud();
public :
   Lista(){
      primero=0;
   }
   
   void agregarElemento(double valor);
   
   void imprimir();

   Celda **particionar(int tam);
};

#endif	/* LISTA_H */

