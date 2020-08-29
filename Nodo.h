#ifndef __NODO_H__
#define __NODO_H__
	
class Nodo{
public:
	Nodo(int);
	~Nodo();

	bool divTo(Nodo*);
	void setPoss(float, float);
	int getValue();

	float getX();
	float getY();

	void setX(float);
	void setY(float);
	
	void exPoss(float, float);
	void dePoss(float, float);

private:
	float x, y;
	int v;
};

typedef struct{
	int n;
	Nodo** arr;
} ArrayNodo;

typedef struct{
	int n;
	ArrayNodo** arr;
} HasseStruct;

ArrayNodo* CreateArrayNodo(ArrayNodo*, Nodo*);
HasseStruct* CreateHasseStruct(HasseStruct*, ArrayNodo*);
HasseStruct* BuildHasse(int*, int*, int);
void TransformHasse(HasseStruct*, float, float, float, float);

#endif