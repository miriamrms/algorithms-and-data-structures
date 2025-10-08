//
//  main.cpp
//  ForcaBruta
//
//  Created by Miriam Mendes on 13/06/25.
//

#include <iostream>
using namespace std;

#define N 10

void selection_sort(int* array);

int main() {
    
    int array[N] = {5, 2, 9, 1, 7, 3, 8, 4, 6, 0};
    
    cout << "Desordenado: ";
    for(int i = 0; i < N;i++){
        cout << array[i] << " ";
    }
    cout << endl;
    
    selection_sort(array);
    
    cout << "Ordenado: ";
    for(int i = 0; i < N;i++){
        cout << array[i] << " ";
    }
    cout << endl;
    
    
    return 0;
}


void selection_sort(int* array){
    for(int j=0; j < (N - 1); j++){
        int currentMin = j;
        for(int i = j + 1; i < N; i++){
            if(array[i] < array[currentMin]){
                currentMin = i;
            }
        }
        swap(array[j],array[currentMin]);
    }
}

