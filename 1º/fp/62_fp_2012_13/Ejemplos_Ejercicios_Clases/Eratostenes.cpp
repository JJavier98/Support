#include <iostream>
#include <vector>
using namespace std;

// Aplicar el algoritmo de Eratóstenes para mostrar por pantalla los números
// primos comprendidos entre el 2 y tope

class Eratostenes
{
private:

	vector <int> primos;

public:

	void CalculaHasta(int n)
    {
		vector <bool> es_primo;

		es_primo.reserve(n+1);       
		es_primo.push_back(false);   
		es_primo.push_back(false);   

		for (int i=2; i<=n; i++)
			es_primo.push_back(true);

		for (int entero = 2; entero * entero <= n; entero++) // Esta condición es 
        {			                                         // equivalente a "entero <= sqrt(n)"  
			if (es_primo[entero]){

				for (int a_tachar = 2*entero; a_tachar <= n; a_tachar = a_tachar + entero)
					es_primo[a_tachar] = false;
			}
		}

		for (int i=2; i<=n; i++)
			if (es_primo[i]){
				primos.push_back(i);
			}
	}

	int TotalCalculados()
    {
		return primos.size();
	}

	int Elemento(int indice) 
    {
		return primos.at(indice);
	} 
};

int main()
{
	int tope;
	int total_generados;
	Eratostenes primos;

	cout << "\nIntroduzca un entero: ";
	cin >> tope;

	primos.CalculaHasta(tope);
	total_generados = primos.TotalCalculados();

	for (int i=0; i<total_generados; i++)
		cout << primos.Elemento(i) << endl;
}
