#include "frecuencias.h"

Frecuencias::Frecuencias() {
   parejas = 0;
   npares = 0;
}

Frecuencias::~Frecuencias() {
   liberarEspacio();
}

void Frecuencias::liberarEspacio() {
   if (npares != 0) {
      delete [] parejas;
      npares = 0;
   }
}

Frecuencias::Frecuencias(const Frecuencias &objeto) {
   // se reserva espacio
   reservarEspacio(objeto.npares);

   // Se copian los datos
   copiarDatos(objeto);
}

void Frecuencias::add(int valor) {
   // se busca la posicion de insercion
   int posInsercion = buscarPosicionInsercion(valor);
   cout << endl;

   // si en la posicion esta el valor pasado como
   // argumento, se incrementa el contador
   if (npares != 0 && posInsercion < npares && parejas[posInsercion].dato == valor) {
      parejas[posInsercion].nveces++;
   }
   else {
      // si npares es 0, se inserta directamente
      if (npares == 0) {
         reservarEspacio(1);

         // Se asigna el par
         parejas[0].dato = valor;
         parejas[0].nveces = 1;
      }
      else {
         // hay que redimensionar el objeto para incluir una nueva
         // pareja. Creamos objeto auxiliar con constructor de copia
         Frecuencias copiaThis(*this);

         // Se libera el espacio actual
         liberarEspacio();

         // Se reserva espacio para un elemento mas
         reservarEspacio(copiaThis.npares+1);

         // Se van copiando los datos de copiaThis, teniendo en
         // cuenta que en la posicion pos va el nuevo
         int posCopia = 0;
         int posNuevo = 0;
         while (posNuevo < npares) {
            if (posNuevo == posInsercion) {
               parejas[posNuevo].dato = valor;
               parejas[posNuevo].nveces = 1;
            }
            else {
               // Se copia desde copiaThis
               parejas[posNuevo].dato = copiaThis.parejas[posCopia].dato;
               parejas[posNuevo].nveces = copiaThis.parejas[posCopia].nveces;

               // Se incrementa posCopia
               posCopia++;
            }

            // Se incrementa posInsercion
            posNuevo++;
         }
      }
   }
}

const Frecuencias & Frecuencias::operator+=(int valor){
   // Se agrega el valor
   add(valor);

   // Se devuelve this
   return *this;
}

void Frecuencias::reservarEspacio(int npares) {
   this->npares = npares;
   parejas = new Pareja[npares];
}

void Frecuencias::copiarDatos(const Frecuencias & objeto) {
   // Se van asignando los objetos uno a uno
   for (int i = 0; i < objeto.npares; i++) {
      parejas[i] = objeto.parejas[i];
   }
}

int Frecuencias::buscarPosicionInsercion(int valor) {
   int posInsercion = 0;
   bool mayor = false;

   for (int i = 0; i < npares && !mayor; i++) {
      if (parejas[i].dato >= valor) {
         mayor = true;
      }
      else{
         posInsercion++;
      }
   }

   return posInsercion;
}

int Frecuencias::repeticiones(int valor){
   int repeticiones=0;
   bool encontrado=false;

   // Se recorren los pares
   for(int i=0; i < npares && !encontrado; i++){
      if (valor == parejas[i].dato){
         repeticiones=parejas[i].nveces;
         encontrado=true;
      }
   }

   // Se devuelve repeticiones
   return repeticiones;
}

ostream & operator<<(ostream &flujo, const Frecuencias &objeto) {
   flujo << "---------------------------------------" << endl;
   for (int i = 0; i < objeto.npares; i++) {
      flujo << "(" << objeto.parejas[i].dato << " - " << objeto.parejas[i].nveces << ") ";
   }
   flujo << endl;
   flujo << "---------------------------------------" << endl;
   return flujo;
}

istream & operator>>(istream &flujo, Frecuencias & objeto){
   int numeroParejas;

   // El objeto pasado como argumento se limpia
   objeto.liberarEspacio();

   // Se lee el numero de parejas a leer
   flujo >> numeroParejas;

   // Se reserva espacio
   objeto.reservarEspacio(numeroParejas);

   // Bucle de lectura de datos
   for(int i=0; i < numeroParejas; i++){
      flujo >> objeto.parejas[i].dato >> objeto.parejas[i].nveces;
   }

   // Se devuelve el flujo
   return flujo;
}
