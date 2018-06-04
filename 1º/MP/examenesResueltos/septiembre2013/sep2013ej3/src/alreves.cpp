#include<iostream>
#include<fstream>

using namespace std;

int main(int argc, char *argv[]){
   // Se comprueba que se haya llamado al programa
   // con el nombre de un arhivo
   if (argc < 2){
      cout << "Uso del programa: alreves fichero.txt" << endl;
      return -1;
   }
   
   // Si todo va bien, se produce la apertura del archivo para
   // lectura
   ifstream fichero(argv[1]);
   
   string salida;
   char leido[200];
   
   // Si pudo abrirse, se lee el contenido
   if(fichero){
      while(!fichero.eof()){
         fichero.getline(leido,199);
         
         // Lo leido se concatena al principio de la cadena
         // de salida
         salida=salida+string("\n")+string(leido);
      }
   }
   
   // Se cierra el fichero
   fichero.close();
   
   cout << "Longitud de salida: " << salida.length() << endl;
   
   // Se muestra salida, caracter a caracter, de atras adelante
   for(int i=(salida.length()-1); i >= 0; i--){
      cout << salida.at(i);
   }
}
