#include <iostream>
#include <vector>
using namespace std;

// Determinar el número de lecturas de una permutación en el conjunto {1,...,n}

class Permutacion
{
private: 
	vector <int> permutacion;

	int PosEncontrado(int buscado, int pos_inicial){
		bool encontrado = false;
		int pos_encontrado = -1;
		int tope = permutacion.size();

		for (int i=pos_inicial; i<tope && !encontrado; i++){
			if (permutacion[i] == buscado) 
            {
				pos_encontrado = i;
				encontrado = true;
			}
		}

		return pos_encontrado;
	}

public:
    // Precondición: permutacion_enteros es una permutacion 
	Permutacion(vector <int> permutacion_enteros)
		:permutacion (permutacion_enteros) {}

	int TotalUtilizados()
    {
		return permutacion.size();
	}

	int Elemento(int indice)
    {
		return permutacion.at(indice);
	}

	int NumeroLecturas()
    {
		int primero, ultimo, pos_ultimo_encontrado, numero_lecturas, a_buscar;

		primero = 1;
		ultimo = permutacion.size();
		
		pos_ultimo_encontrado = -1;

		numero_lecturas = 1;

        a_buscar = primero;

		while (a_buscar <= ultimo)
        {
			 pos_ultimo_encontrado = 
                         PosEncontrado(a_buscar, pos_ultimo_encontrado + 1);  

			 if (pos_ultimo_encontrado == -1)  
			 	 numero_lecturas++;
			 else
                 a_buscar++;				
		}

		return numero_lecturas;
	}
};

int main(){
	vector <int> v;
	int n, x; 

    cout << "Numero de elementos: ";
    cin >> n;

	for (int i=0; i<n; i++)
	{
		cout << "Introducir elemento: ";
		cin >> x;
		v.push_back(x);
    }

	Permutacion permutacion(v);

	cout << permutacion.NumeroLecturas() << endl;
	
	system("pause");
}
