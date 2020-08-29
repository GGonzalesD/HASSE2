#include<cstdlib>
#include "functions.h"
#include "Nodo.h"

Nodo::Nodo(int value){
	v = value;
}

Nodo::~Nodo(){
}

// ------------------------------------

int Nodo::getValue(){
	return v;
}

bool Nodo::divTo(Nodo* nodo){
	return nodo->getValue() % v == 0;
}


// ------------------------------------

void Nodo::setPoss(float x, float y){
	this->x = x;
	this->y = y;
}

float Nodo::getX(){
	return x;
}

float Nodo::getY(){
	return y;
}

void Nodo::setX(float x){
	this->x = x;
}

void Nodo::setY(float y){
	this->y = y;
}

void Nodo::exPoss(float x, float y){
	this->x *= x;
	this->y *= y;
}

void Nodo::dePoss(float x, float y){
	this->x += x;
	this->y += y;
}

// ---------------------------------------------------------
// ---------------------------------------------------------

ArrayNodo* CreateArrayNodo(ArrayNodo* an, Nodo* nodo){
	if(an->arr){
		an->arr = (Nodo**)realloc(an->arr, sizeof(Nodo*)*(an->n + 1));
		an->arr[an->n] = nodo;
		(an->n)++;

	}else{
		an->arr = (Nodo**)malloc(sizeof(Nodo*)*1);
		an->arr[0] = nodo;
		an->n = 1;
	}

	return an;
}

HasseStruct* CreateHasseStruct(HasseStruct* hs, ArrayNodo* an){
	if(hs->arr){
		hs->arr = (ArrayNodo**)realloc(hs->arr, sizeof(ArrayNodo*)*(hs->n + 1));
		hs->arr[hs->n] = an;
		(hs->n)++;

	}else{
		hs->arr = (ArrayNodo**)malloc(sizeof(ArrayNodo*)*1);
		hs->arr[0] = an;
		hs->n = 1;
	}

	return hs;
}

HasseStruct* BuildHasse(int * arr, int * arr_prime, int np){
	HasseStruct* hasse = new HasseStruct;
	for(int i=0; i<=np; i++){
		hasse = CreateHasseStruct(hasse, new ArrayNodo);
		int * hl = get_line_HASSE(arr, arr_prime, i);
		for(int j=1; j<hl[0]; j++){
			Nodo* nodo = new Nodo(hl[j]);
			nodo->setPoss((j)-(float(hl[0])*0.5),i);
			hasse->arr[i] = CreateArrayNodo(hasse->arr[i], nodo);
		}
		delete[]hl;
	}

	return hasse;
}

void TransformHasse(HasseStruct* hasse, float ex, float ey, float dx, float dy){
	for(int i=0; i<hasse->n; i++){
		ArrayNodo* arrnodo = hasse->arr[i];
		for(int j=0; j<arrnodo->n; j++){
			Nodo* nodo = arrnodo->arr[j];
			nodo->exPoss(ex, ey);
			nodo->dePoss(dx, dy);
		}
	}
}