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
   lista.imprimirInvertido();
}
