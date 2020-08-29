#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// Se entiende un array de la solucion como
// [n0, e1, e2, ..., en-1]
// [3, 12, 5]
// [5, 1, 3, 1, 5]

// Agregar un numero en un array
int * add_number_to_array(int*, int);

// Obtener el numero de divisores y un array de divisores
int get_number_divs(int);
int* get_array_divs(int);

// Obtener array de numeros primos
int* get_prime(int);

// Obtener el numero de primos
int get_number_prime(int);

// Obtener un array de los numeros primos del array
int * get_array_number_prime(int*);

// Obtiene un array con los divisores de un numero con la misma cantidad de numero primos
int * get_line_HASSE(int*, int*, int);

// Dibujar un array
void draw_array(int*);

#endif