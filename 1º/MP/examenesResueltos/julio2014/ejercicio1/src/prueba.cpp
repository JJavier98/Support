#include <iostream>
#include "lista.h"

using namespace std;

int main(){
   Lista lista;
   
   lista.agregarElemento(1);
   lista.agregarElemento(2);
   lista.agregarElemento(3);
   lista.agregarElemento(4);
   lista.agregarElemento(5);
   
   lista.imprimir();

   Celda ** trozos=lista.particionar(2);

   for(int i=0; i < 3; i++){
     cout << "Fragmento " << i << endl;
     Celda *pCelda=trozos[i];
     while(pCelda != 0) {
       cout << pCelda->valor << " ";
       pCelda=pCelda->siguiente;
     }
     cout << endl;
   }
}
