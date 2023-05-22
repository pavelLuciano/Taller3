#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

#define MIN 10
#define MAX 99

struct Number{
	bool grupoA;	// true pertenece al grupo A, false al grupo B
	int val;	// aleatorio perteneciente a [MIN..MAX]
};

vector<Number> createVector(int n, float pA);
void insertionSortGroupA(vector<Number> &v);
void imprimeVector(const vector<Number> &v);

int main(int argc, char **argv){	
	if(argc != 2){
		cout << "Error. Debe ejecutarse como ./problema n" << endl;
		exit(EXIT_FAILURE);
	}
	
	cout << "### Fin Problema ###" << endl;
	return EXIT_SUCCESS;
}

vector<Number> createVector(int n, float pA){

}


void insertionSortGroupA(vector<Number> &v){
	
}

void imprimeVector(const vector<Number> &v){
	for (unsigned int i=0; i<v.size(); i++){
		if (v[i].grupoA)
			cout << "(A," << v[i].val << ") ";
		else
			cout << "(B," << v[i].val << ") ";
	}
	cout << endl;
}


// insertionsort visto en clases: ordena los elementos de A con el algoritmo de la insertionSort
void insertionSort(int* A, int n){
	int i,j,key;

	for(i=1; i<n; i++){
		key = A[i];
		j = i-1;
		while (j>=0 && A[j]>key){
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = key;
	}
}
