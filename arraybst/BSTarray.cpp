#include <iostream>
#include <cstdlib>
using namespace std;

#define N 100

bool insertar(int* aBST, int val, int i);
void printPostOrder(int* aBST, int i);
void printInOrder(int* aBST, int i);
void printPreOrder(int* aBST, int i);


int main(int argc, char **argv) {

    int n = N;
    int* BSTarray = new int[n];
    for(int i = 0; i < n; i++) BSTarray[i] = 0; 

    int valores[10] = {31,16,45,24,7,19,29};
    for(int i = 0; i < 10; i++)
        insertar(BSTarray,valores[i],1);

    cout << "ARREGLO COMPLETO:\n";
    for (int i = 0; i < n; i++)
    {
        cout << BSTarray[i] << " ";
    }
    cout << endl;

    cout << "ARREGLO EN Preorder:\n";
    printPreOrder(BSTarray,1);
    cout << endl;

    cout << "ARREGLO EN Inorder:\n";
    printInOrder(BSTarray,1);
    cout << endl;

    cout << "ARREGLO EN PostOrder:\n";
    printPostOrder(BSTarray,1);
    cout << endl;
}

bool insertar(int* aBST, int val, int i)
{
    if (i > N) return false;
    if (aBST[i - 1] == 0)
    {
        aBST[i - 1] = val;
        return true;
    }
    else if (aBST[i -1] > val)
        return insertar(aBST,val, 2*i);
    else if (aBST[i -1] < val)
        return insertar(aBST,val, 2*i +1);
    else return false;
}

void printPreOrder(int* aBST, int i)
{
    if (i <= N && aBST[i-1] != 0)
    {
        cout << aBST[i - 1] <<  " ";
        printPreOrder(aBST, 2*i);
        printPreOrder(aBST, 2*i + 1); 
    }
    
}

void printInOrder(int* aBST, int i)
{
    if (i <= N && aBST[i-1] != 0)
    {
        printInOrder(aBST, 2*i);
        cout << aBST[i - 1] <<  " ";
        printInOrder(aBST, 2*i + 1)
;    } 
}

void printPostOrder(int* aBST, int i)
{
    if (i <= N && aBST[i-1] != 0)
    {
        printPostOrder(aBST, 2*i);
        printPostOrder(aBST, 2*i + 1); 
        cout << aBST[i - 1] <<  " ";
    }
}

