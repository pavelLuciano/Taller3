#include <iostream>	
#include <fstream>
#include <cstring>	
#include <cstdlib>
using namespace std;

#define MAX_VAL 999
#define MIN_VAL 100

struct nodoMatriz{
	int valor;
	int i;
	int j;
	nodoMatriz* up;
	nodoMatriz* down;
	nodoMatriz*	right;
	nodoMatriz* left;
};
typedef struct nodoMatriz nMat;

//FUNCIONES:
void agregarNodo(nMat** M, int num);
void creaMatriz(nMat** M, int n, int m);
void agregaFilaAbajo(nMat** M);
void agregaColumnaDer(nMat** M);
void agregaFilaArriba(nMat** M);
void agregaColumnaIzq(nMat** M);

void incrementaFilas(nMat** M);
void incrementaColumnas(nMat** M);

void printMat(nMat *M);

int main(int argc, char **argv)
{
	int n, m;
	if(argc != 3){
		cout << "Error. Debe ejecutarse como ./matriz n m" << endl;
		exit(EXIT_FAILURE);
	}

	n = atoi(argv[1]);//filas
	m = atoi(argv[2]);//columnas

	//Creamos la matriz
	nMat* Matriz = NULL;
	creaMatriz(&Matriz, n, m);
	printMat(Matriz);

	agregaColumnaDer(&Matriz);
	agregaFilaArriba(&Matriz);
	agregaColumnaIzq(&Matriz);
	printMat(Matriz);

	cout << "FIN DEL PROGRAMA!\n";
}

void creaMatriz(nMat** M, int n , int m)
{
	//La funcion crea la matriz por lo tanto asumimos que M = NULL
	//creamos la fila cero
	nMat* p = new nMat();
	*M = p;
	p->up = p->down = p->right = p->left = NULL;
	p->valor = MIN_VAL + rand()%(MAX_VAL + 1 - MIN_VAL);
	p->i = p->j = 1;

	int val;
	nMat* nuevo;
	for (int k = 2; k <= m; k++)
	{
		val = MIN_VAL + rand()%(MAX_VAL + 1 - MIN_VAL);

		nuevo = new nMat();
		nuevo->up = nuevo->down = nuevo->right = nuevo->left = NULL;
		nuevo->valor = val;
		nuevo->i = 1;
		nuevo->j = k;
		nuevo->left = p;

		p->right = nuevo;
		p = p->right;
	}

	p = *M;
	for(int k = 2; k <= n; k++)
	{
		agregaFilaAbajo(&p);
	}
}

void agregaFilaAbajo(nMat** M)
{
	//usaremos 3 punteros para esta funcion
	nMat *p, *q, *nuevo;
	p = *M;

	while((p->down) != nullptr) p = p->down;

	int fila = p->i + 1;
	int val = MIN_VAL + rand()%(MAX_VAL + 1 - MIN_VAL);
	q = p->right;
	nuevo = new nMat();
	nuevo->up = nuevo->down = nuevo->right = nuevo->left = NULL;
	nuevo->valor = val;
	nuevo->i = fila;
	nuevo->j = 1;
	nuevo->up = p;
	p->down = nuevo;
	p = nuevo;

	int k = 2;
	while(q != nullptr)
	{
		val = MIN_VAL + rand()%(MAX_VAL + 1 - MIN_VAL);
		nuevo = new nMat();
		nuevo->down = nuevo->right = NULL;
		nuevo->valor = val;
		nuevo->i = fila;
		nuevo->j = k;
		nuevo->up = q;
		nuevo->left = p;

		p->right = nuevo;
		q->down = nuevo;
		q = q->right;
		p = p->right;
		k++;
	}
}

//revisar
void agregaColumnaDer(nMat** M)
{
	//usaremos 3 punteros para esta funcion
	nMat *p, *q, *nuevo;
	p = *M;

	while((p->right) != nullptr) p = p->right;

	int columna = p->j + 1;
	int val = MIN_VAL + rand()%(MAX_VAL + 1 - MIN_VAL);
	q = p->down;
	nuevo = new nMat();
	nuevo->up = nuevo->down = nuevo->right = nuevo->left = NULL;
	nuevo->valor = val;
	nuevo->i = 1;
	nuevo->j = columna;
	nuevo->left = p;
	p->right = nuevo;
	p = nuevo;

	int k = 2;
	while(q != nullptr)
	{
		val = MIN_VAL + rand()%(MAX_VAL + 1 - MIN_VAL);
		nuevo = new nMat();
		nuevo->down = nuevo->right = NULL;
		nuevo->valor = val;
		nuevo->i = k;
		nuevo->j = columna;
		nuevo->left = q;
		nuevo->up = p;

		p->down = nuevo;
		q->right = nuevo;
		q = q->down;
		p = p->down;
		k++;
	}
}

void agregaFilaArriba(nMat** M)
{
	nMat *p, *q, *nuevo;
	p = *M;
	int val = MIN_VAL + rand()%(MAX_VAL + 1 - MIN_VAL);
	q = p->right;
	nuevo = new nMat();
	nuevo->up = nuevo->down = nuevo->right = nuevo->left = NULL;
	nuevo->valor = val;
	nuevo->i = 1;
	nuevo->j = 1;
	nuevo->down = p;
	incrementaFilas(&p);
	p->up = nuevo;
	p = nuevo;
	*M = nuevo;

	int k = 2;
	while(q != nullptr)
	{
		val = MIN_VAL + rand()%(MAX_VAL + 1 - MIN_VAL);
		nuevo = new nMat();
		nuevo->up = nuevo->right = NULL;
		nuevo->valor = val;
		nuevo->i = 1;
		nuevo->j = k;
		nuevo->left = p;
		nuevo->down = q;
		//funcion para incrementar las filas
		incrementaFilas(&q);

		p->right = nuevo;
		q->up = nuevo;
		q = q->right;
		p = p->right;
		k++;
	}
}

void agregaColumnaIzq(nMat** M)
{
	nMat *p, *q, *nuevo;
	p = *M;
	int val = MIN_VAL + rand()%(MAX_VAL + 1 - MIN_VAL);
	q = p->down;
	nuevo = new nMat();
	nuevo->up = nuevo->down = nuevo->right = nuevo->left = NULL;
	nuevo->valor = val;
	nuevo->i = 1;
	nuevo->j = 1;
	nuevo->right = p;
	p->left = nuevo;
	incrementaColumnas(&p);
	p = nuevo;
	*M = nuevo;

	int k = 2;
	while(q != nullptr)
	{
		val = MIN_VAL + rand()%(MAX_VAL + 1 - MIN_VAL);
		nuevo = new nMat();
		nuevo->down = nuevo->left = NULL;
		nuevo->valor = val;
		nuevo->i = k;
		nuevo->j = 1;
		nuevo->up = p;
		nuevo->right = q;
		incrementaColumnas(&q);

		p->down = nuevo;
		q->left = nuevo;
		q = q->down;
		p = p->down;
		k++;
	}
}

void incrementaFilas(nMat** M)
{
	nMat *p = *M;
	while(p != nullptr)
	{
		(p->i)++;
		p = p->down;
	}
}
void incrementaColumnas(nMat** M)
{
	nMat *p = *M;
	while(p != nullptr)
	{
		(p->j)++;
		p = p->right;
	}
}

void printMat(nMat* M)
{
	nMat *p, *q;
	p = M;
	while(p != nullptr)
	{
		q = p;
		while(q != nullptr)
		{
			cout << (q->valor) <<" ";
			q = q->right;
		}
		cout << endl;;
		p = p->down;
	}
}