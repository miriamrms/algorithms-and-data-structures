//
//  main.cpp
//  HeapSort2
//
//  Created by Miriam Mendes on 02/08/25.
//

#include <iostream>
using namespace std;

#define CAPACIDADE 10

void printHeap(int *v, int n);
void heapify(int *v, int n, int i);
void heapsort(int *v, int n);

int main() {
    //Tenho um array de dados
    int *vector = new int[10]{4, 10, 3, 5, 1};
    int n = 5;
    
    cout << "Desordenado: ";
    printHeap(vector, n);
    heapsort(vector, n);
    cout << "Ordenado: ";
    printHeap(vector, n);
    
    delete [] vector;

    return 0;
}


void printHeap(int *v, int n){
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

void heapsort(int *v, int n){
    //MARK: construir heap
    for(int i = (n/2)-1; i>=0; i--){
        heapify(v, n, i);
    }
    cout << "Heap: ";
    printHeap(v, n);
    //MARK: ordenar heap
    for(int i=n-1; i>0; i--){
        swap(v[0], v[i]);
        heapify(v, i, 0);
    }
}
