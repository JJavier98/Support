#include <iostream>
#include <stdexcept>

using namespace std;

class MiVector_int
{
    private:
    
        static const int TAMANIO = 5;
        int vector_privado[TAMANIO];
        int total_utilizados;
    
    public:
    
        MiVector_int()
            :total_utilizados(0) { }

        int TotalUtilizados()
        {
            return total_utilizados;
        }
        
        int Capacidad()
        {
            return TAMANIO;
        }
        
        int Elemento(int indice)
        {
            return vector_privado[indice];
        }
        
        void Aniade(int nuevo)
        {
            if (total_utilizados < TAMANIO)
            {
                vector_privado[total_utilizados] = nuevo;
                total_utilizados++;
            }    
            else
                throw logic_error("No hay componentes suficientes");
        }
        
       void BorrarTodos()
       {
           total_utilizados = 0;
       }
};

int main()
{
      char opcion;
      int x;
      bool seguir;
     
      MiVector_int v;
      
      do{
        cout << "    \nIntroducir real: ";
        cin >> x;
        
        try
        {
             v.Aniade(x);
        }
        catch(logic_error excepcion)
        { 
             cout << "\n\nERROR LOGICO: " << excepcion.what();
        }        
   
        cout << "\n\n-Desea introducir otro elemento del vector (s/n): ";
        cin >> opcion;
        
        seguir = (opcion == 's') || (opcion == 'S');
     }while(seguir);
         
         
     for (int i=0; i<v.TotalUtilizados(); i++)
        cout << v.Elemento(i) << endl;    
               
     system("pause");     
} 


