//
//  main.cpp
//  Heap
//
//  Created by Miriam Mendes on 02/08/25.
//

#include <iostream>
using namespace std;

#define CAPACIDADE 10

void createMaxHeap(int *v, int n);
void printHeap(int *v, int n);
void insertToHeap(int *v, int value, int &n);
void extractMax(int *v, int &n);
void heapify(int *v, int n, int i);
void heapsort(int *v, int &n);

int main() {
    //Tenho um array de dados
    int *vector = new int[10]{4, 10, 3, 5, 1};
    int n = 5;
    
    createMaxHeap(vector, n);
    printHeap(vector, n);
    
    insertToHeap(vector, 2, n);
    printHeap(vector, n);
    insertToHeap(vector, 11, n);
    printHeap(vector, n);
    insertToHeap(vector, 8, n);
    printHeap(vector, n);
    insertToHeap(vector, 6, n);
    printHeap(vector, n);
    insertToHeap(vector, 9, n);
    printHeap(vector, n);
    insertToHeap(vector, 12, n);
    
    extractMax(vector, n);
    extractMax(vector, n);
    extractMax(vector, n);
    extractMax(vector, n);
    extractMax(vector, n);
    extractMax(vector, n);
    extractMax(vector, n);
    extractMax(vector, n);
    extractMax(vector, n);
    extractMax(vector, n);
    extractMax(vector, n);
    
    delete [] vector;

    return 0;
}

//MARK: Cria heap BottomUp - O(n)
void createMaxHeap(int *v, int n){
    for(int i = (n/2)-1; i>=0; i--){
        heapify(v, n, i);
    }
}

void printHeap(int *v, int n){
    cout << "Heap: ";
    for(int i = 0; i<n; i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

void heapify(int *v, int n, int i){
    int highest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    
    if(left < n && v[left] > v[highest]){
        highest = left;
    }
    if(right < n && v[right] > v[highest]){
        highest = right;
    }
    if(highest!=i){
        swap(v[i],v[highest]);
        heapify(v, n, highest);
    }
}

//MARK: Inserir elemento - O(logn)
void insertToHeap(int *v, int value, int &n){
    
    if(n==CAPACIDADE){
        cout << "Heap está cheia, não foi possível adicionar o valor " << value << endl;
    }
    else{
        v[n] = value;
        int i = n;
        while (i>0 && v[i]>v[(i-1)/2]) {
            swap(v[i], v[(i-1)/2]);
            i = (i-1)/2;
        }
        n++;
        cout << "Valor " << value << " adicionado, a heap agora tem tamanho " << n << endl;
    }
}


//MARK: Extract Max - O(logn)
void extractMax(int *v, int &n){
    if(n<1){
        cout << "Heap Vazia!" << endl;
    }
    else{
        int removedElement = v[0];
        swap(v[0], v[n-1]);
        n--;
        heapify(v, n, 0);
        cout << "Valor " << removedElement << " renmovido, a heap agora tem tamanho " << n << endl;
    }
}

void heapsort(int *v, int &n){
    //ordenação
    for(int i=n-1; i>0; i--){
        swap(v[0], v[i]);
        heapify(v, n, i-1);
    }
}
