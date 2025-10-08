//
//  main.cpp
//  ForcaBruta
//
//  Created by Miriam Mendes on 13/06/25.
//

#include <iostream>
using namespace std;

#define N 10

void bubble_sort(int* array);
void bubble_sort_2(int* array);

int main() {
    
    int array[N] = {5, 2, 9, 1, 7, 3, 8, 4, 6, 0};
    
    cout << "Desordenado: ";
    for(int i = 0; i < N;i++){
        cout << array[i] << " ";
    }
    cout << endl;
    
    bubble_sort_2(array);
    
    cout << "Ordenado: ";
    for(int i = 0; i < N;i++){
        cout << array[i] << " ";
    }
    cout << endl;
    
    
    return 0;
}

void bubble_sort(int* array){
    for(int j = N; j > 1; j--){
        for(int i = 0; i < (j - 1); i++){
            if(array[i+1] < array[i]){
                swap(array[i+1], array[i]);
            }
        }
    }
}

void bubble_sort_2(int* array){
    for(int j = 0; j < (N - 1); j++){
        for(int i = 0; i < (N - 1 - j); i++){
            if(array[i+1] < array[i]){
                swap(array[i+1], array[i]);
            }
        }
    }
}
