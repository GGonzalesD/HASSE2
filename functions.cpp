#include<iostream>
#include "functions.h"


using std::cout;


int * add_number_in_array(int* arr, int n){
	int * arrx;

	if(arr){
		arrx = new int[arr[0] + 1];

		for(int i=0; i<arr[0]; i++){
			arrx[i] = arr[i];
		}

		arrx[arr[0]] = n;
		arrx[0]++;

	}else{
		arrx = new int[2];
		arrx[0] = 2;
		arrx[1] = n;
	}

	if(arr)
		delete[]arr;

	return arrx;
}

int get_number_divs(int n){
	int c = 0;

	for(int i=1; i<=(n+1)/2; i++)
		if(!(n%i))
			c++;

	return c+1;
}

int * get_array_divs(int n){

	int * arr = new int[1];
	arr[0] = 1;

	for(int i=1; i<(n+2)/2; i++){
		if(!(n%i))
			arr = add_number_in_array(arr, i);
	}

	arr = add_number_in_array(arr, n);

	return arr;
}

int * get_prime(int n){
	int n_ = n;
	int * arr = new int[1];
	arr[0] = 1;

	for(int i=2; i<n; i++){
		while(!(n_%i)){
			n_ /= i;

			arr = add_number_in_array(arr, i);

		}
	}

	return arr;
}

int get_number_prime(int n){
	int n_ = n;
	int a = 0;

	for(int i=2; i<=n; i++){
		while(!(n_%i)){
			n_ /= i;
			a++;
		}
	}

	return a;
}
int * get_array_number_prime(int * arrp){
	int * arr = new int[1];
	arr[0] = 1;

	for(int i=1; i<arrp[0]; i++){
		arr = add_number_in_array(arr, get_number_prime(arrp[i]));
	}

	return arr;
}

int * get_line_HASSE(int * arr, int * arr_prime, int n){
	int * hasse = 0;

	for(int i=1; i<arr[0]; i++)
		if(arr_prime[i] == n)
			hasse = add_number_in_array(hasse, arr[i]);

	return hasse;
}


void draw_array(int * arr){
	if(arr){
		cout << "[";
		for(int i=1; i<arr[0]; i++){
			if(i!=arr[0]-1)
				cout << arr[i]<< ", ";
			else
				cout << arr[i] << "]"; 
		}
	}else{
		cout << "[]";
	}
	cout << "\n";

}