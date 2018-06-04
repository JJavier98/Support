
#include "entero.h"

using namespace std;

Entero::Entero(const Entero &otro){
   v=new int;
   *v=*(otro.v);   
}

Entero & Entero::operator*(int valor) const {
   Entero *resultado=new Entero(*(this->v)*valor);
   return *resultado;
}

const Entero & Entero::operator=(const Entero &otro){
   delete v;
   v=new int;
   *v=*(otro.v);
   return *this;
}

ostream & operator<<(ostream & flujo, const Entero &objeto){
   flujo << *(objeto.v) << endl;
   return flujo;
}
