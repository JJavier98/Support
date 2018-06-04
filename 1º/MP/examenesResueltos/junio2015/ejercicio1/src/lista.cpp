
#include "lista.h"

void Lista::agregarElemento(double valor){
   Celda *pCelda=new Celda(valor);

   // Si la lista esta vacia, se inserta al principio
   if(primero == 0){
      primero=pCelda;
   }
   else{
      // Se convierte en la primera
      pCelda->siguiente=primero;
      primero=pCelda;
   }
}

void Lista::imprimir(){
   Celda *pCelda=primero;

   // Bucle de recorrido de celdas
   while(pCelda != 0){
      cout << pCelda->valor << " ";

      // Se avanza el puntero
      pCelda=pCelda->siguiente;
   }
   cout << " | " << endl;
}

void Lista::imprimirInvertido(){
   // Se crea una lista vacia para ir incluyendo los 
   // elementos al principio
   Lista auxiliar;

   // Se recorren los elementos de this
   Celda *pCelda=primero;
   while(pCelda != 0){
      auxiliar.agregarElemento(pCelda->valor);
      pCelda=pCelda->siguiente;
   }

   // Ahora se imprime con el procedimiento normal
   // la lista auxliar
   auxiliar.imprimir();
}
