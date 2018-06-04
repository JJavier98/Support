#include <iostream>
#include <vector>
using namespace std;

/*
Realizar un programa que vaya leyendo caracteres hasta que se encuentre un punto '.'. 
Queremos contar el número de veces que aparece cada caracter y mostrar por pantalla
el caracter que más se ha repetido (en caso de empate se mostrará el menor).
*/

class  ContadorCaracteres
{
private:
	vector <char> v_caracter;
	vector <int>  v_contador;
	
	int BuscarCaracter(char buscado)
    {
    	bool encontrado = false;
    	int i=0;
    	
    	while ( i < v_caracter.size() && !encontrado )
    		if (v_caracter[i] == buscado) 
    			encontrado = true;
    		else
                i ++;	
    
        if (encontrado)
          	return i;
        else 
            return -1;  	
    }
	
public:

	void Contabilizar(char c)
    {
         int pos = 	BuscarCaracter(c);
         
         if (pos != -1)
             v_contador.at(pos) ++;
         else
         {
             v_caracter.push_back(c);
             v_contador.push_back(1);
         }         	
   }
   
   void Ordenar()
   {
        int izda, i;
        char tmp_char, tmp_int;
        
        for(izda = 0; izda < v_caracter.size(); izda++)
           for(i = v_caracter.size() - 1; i>izda; i--)
              if ( v_contador.at(i) < v_contador.at(i-1) ||
                   (v_contador.at(i) == v_contador.at(i-1) 
                    && v_caracter.at(i) < v_caracter.at(i-1)) )
              {
                    tmp_char = v_caracter.at(i);
                    v_caracter.at(i) = v_caracter.at(i-1);
                    v_caracter.at(i-1) = tmp_char;
                    
                    tmp_int = v_contador.at(i);
                    v_contador.at(i) = v_contador.at(i-1);
                    v_contador.at(i-1) = tmp_int;                    
              }
   }
   
   char CaracterMasFrecuente()
   {
        return v_caracter.at(0);
   } 
     
   int FrecuenciaCMF()
   {
       return v_contador.at(0);
   }   	
};

//////////////////////////////////////////////////////////////////

int main()
{
	ContadorCaracteres cont_car; 
	char letra;

    cout << "Introducir caracter: ";
	cin >> letra;
	while (letra != '.')
    {
		cont_car.Contabilizar(letra);	
		
		cout << "Introducir caracter: ";
		cin >> letra;
	}
	
	cont_car.Ordenar();
    
	cout << "El caracter mas frecuente es: " << cont_car.CaracterMasFrecuente()
	     << " - Aparece: "                   <<  cont_car.FrecuenciaCMF() 
         << endl;
	     
	system ("pause");
}

