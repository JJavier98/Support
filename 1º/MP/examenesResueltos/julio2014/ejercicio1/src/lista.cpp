
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

int Lista::longitud(){
  int longitud=0;
  Celda *pCelda=primero;

  while(pCelda != 0){
    longitud++;
    pCelda=pCelda->siguiente;
  }

  return longitud;
}

Celda ** Lista::particionar(int tam){
  // Se calcula el numero de fragmentos
  int trozos=longitud()/tam;
  if (trozos*tam < longitud()){
    trozos++;
  }

  // Se crea array de punteros a los trozos
  Celda **resultado=new Celda *[trozos];

  // Se considera ahora el recorrido sobre la lista
  Celda *pCelda=primero;
  Celda *auxiliar;
  for(int i=0; i < trozos; i++){

    // Se asigna pCelda a la posicion de resultado
    resultado[i]=pCelda;

    // Se avanza hasta la ultima del trozo
    for(int j=0; j < tam-1 && pCelda->siguiente != 0; j++){
      pCelda=pCelda->siguiente;
    }

    // Estamos en la ultima celda del trozo
    // Salvamos siguiente en auxiliar
    auxiliar=pCelda->siguiente;

    // Se pone a cero ahora siguiente
    pCelda->siguiente=0;

    // Para seguir el recorrido avanzamos pCelda hasta auxiliar
    pCelda=auxiliar;
  }

  // Devuelve el resultado
  return resultado;
}
