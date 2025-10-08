//
//  main.cpp
//  DividerNConquer
//
//  Created by Miriam Mendes on 15/06/25.
//

#include <iostream>
using namespace std;
#define N 6

//MARK: MergeSort

void merge(int* array, int left, int middle, int right){
    int i = left;
    int j = middle+1;
    int k = left;
    
    int* temp = new int[right-left+1];
    
    while(i <= middle && j<=right){
        if(array[i]<=array[j]){
            temp[k] = array[i];
            i++;
            k++;
        }
        else{
            temp[k] =  array[j];
            j++;
            k++;
        }
    }
    
    while(i<=middle){
        temp[k] = array[i];
        k++;
        i++;
    }
    while(j<=right){
        temp[k] = array[j];
        k++;
        j++;
    }
    
    for(int p = left; p<=right; p++){
        array[p] = temp[p];
    }
    delete[] temp;
}

void mergesort(int* array, int left, int right){
    if(left<right){
        int middle = (left+right)/2;
        mergesort(array, left, middle);
        mergesort(array, middle+1, right);
        merge(array, left, middle, right);
    }
}

int main() {
//    int array[N] = {5, 2, 9, 1, 7, 3, 8, 4, 6, 0};
    int array[N] = {2, 8, 5, 3, 9, 4};
    cout <<"Ordenado: "<< endl;
    mergesort(array, 0, N-1);
    for(int i=0; i<N; i++){
        cout << array[i] << " ";
    }
    return 0;
}