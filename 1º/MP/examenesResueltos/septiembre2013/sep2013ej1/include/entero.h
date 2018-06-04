#ifndef ENTERO_H
#define ENTERO_H

#include<iostream>

using namespace std;

class Entero {
private:
   int *v;
   
public:
   Entero(int i=0){
      v=new int;
      *v=i;
   }
   
   ~Entero(){
      delete v;
   }
   
   // Se agrega el constructor de copia
   Entero(const Entero &otro);
   
   int set(int i){
      *v=i;
   }
   
   // Se modifica para que devuelve un objeto en lugar de int
   Entero get() const{
      return *(new Entero(*this));
   }
   
   Entero & operator*(int valor) const;
   
   const Entero & operator=(const Entero &otro);
   
   friend ostream & operator<<(ostream & flujo, const Entero &objeto);
};
#endif
