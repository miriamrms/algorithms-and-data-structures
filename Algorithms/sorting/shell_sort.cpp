//
//  main.cpp
//  DecreaseNConquer
//
//  Created by Miriam Mendes on 14/06/25.
//

#include <iostream>
using namespace std;

#define N 10

void shell_sort(int* array);
void shell_sort_eficiente(int* array);

int main() {
    int array[N] = {5, 2, 9, 1, 7, 3, 8, 4, 6, 0};
    
    cout << "Desordenado: ";
    for(int i = 0; i < N;i++){
        cout << array[i] << " ";
    }
    cout << endl;
    
    shell_sort_eficiente(array);
    
    cout << "Ordenado: ";
    for(int i = 0; i < N;i++){
        cout << array[i] << " ";
    }
    cout << endl;
    
    return 0;
}

void shell_sort(int* array){
    for(int h = N-1; h > 0; h--){
        for(int i = 0; i+h < N; i++){
            if(array[i] > array[i+h]){
                swap(array[i], array[i+h]);
            }
        }
    }
}

void shell_sort_eficiente(int* array){
    for(int h = N/2; h > 0; h/=2){
        for(int i = h; i < N; i++){
            int j = i;
            while(j>=h && array[j-h]>array[j]){
                swap(array[j-h], array[j]);
                j -= h;
            }
        }
    }
}
