
//
//  main.cpp
//  DecreaseNConquer
//
//  Created by Miriam Mendes on 14/06/25.
//

#include <iostream>
using namespace std;

#define N 10

void insertion_sort(int* array);

int main() {
    int array[N] = {5, 2, 9, 1, 7, 3, 8, 4, 6, 0};
    
    cout << "Desordenado: ";
    for(int i = 0; i < N;i++){
        cout << array[i] << " ";
    }
    cout << endl;
    
    insertion_sort(array);
    
    cout << "Ordenado: ";
    for(int i = 0; i < N;i++){
        cout << array[i] << " ";
    }
    cout << endl;
    
    return 0;
}

void insertion_sort(int* array){
    for(int j=1; j < N; j++){
        int i = j;
        while(i > 0 && array[i]<array[i-1]){
            swap(array[i], array[i-1]);
            i--;
        }
    }
}

