#include<iostream>
#include "functions.h"
#include "Nodo.h"

using std::cout;

int main(int args, const char ** kargs){
	// int* arr = get_array_divs(252);

	int r;


	if(args == 2)
		r = atoi(kargs[1]);


	int * arr = get_array_divs(r); // Lista de divisores
	int np = get_number_prime(r); // Numeros de Primos
	int* arr_prime = get_array_number_prime(arr); // Lista de Numeros de Primos

	cout << "Divisores\n";
	draw_array(arr);


	cout << "\nDiagrama de HASSE\n";
	HasseStruct* hasse = BuildHasse(arr, arr_prime, np);

	TransformHasse(hasse, 5, 2, 40, 6);

	for(int i=0; i<hasse->n; i++){
		ArrayNodo* arrnodo = hasse->arr[i];
		for(int j=0; j<arrnodo->n; j++){
			Nodo* nodo = arrnodo->arr[j];
			// cout << nodo->getValue() << " ";
			cout << "(" << nodo->getX() << "," << nodo->getY() << ") ";
			// cout << "\033[" << nodo->getY() << ";" << nodo->getX() << "H" <<  nodo->getValue();
		}
		cout << "\n";
	}


}
