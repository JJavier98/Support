
#ifndef PUNTO_H
#define PUNTO_H

#include<iostream>

using namespace std;

class Punto{
   private:
      int x, y;
      
   public:
      /**
       * Constructor por defecto
       */
      Punto(){
         x=0;
         y=0;
      }
      
      /**
       * Constructor indicando los valores
       * @param x
       * @param y
       */
      Punto(int x, int y){
         this->x=x;
         this->y=y;
      }
      
      /**
       * Acceso al valor de x
       */
      int obtenerX(){
         return x;
      }
      
      /**
       * Acceso al valor de y
       */
      int obtenerY(){
         return y;
      }
      
      /**
       * Operador de igualdad
       * @param aComparar
       * @return 
       */
      bool operator==(const Punto &aComparar) const{
         return (x == aComparar.x && y == aComparar.y);
      }
      
      /**
       * Funcion amiga para mostrar el contenido de un punto
       * @param flujo flujo de salida
       * @param punto a mostrar
       */
      friend ostream & operator<<(ostream &flujo, const Punto &punto){
         flujo << "x: " << punto.x << " y: " << punto.y << endl;
         
         // Devuelve el flujo
         return flujo;
      }
};
#endif