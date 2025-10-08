//
//  main.cpp
//  DividerNConquer
//
//  Created by Miriam Mendes on 15/06/25.
//

#include <iostream>
using namespace std;
#define N 6

//MARK: QuickSort

int partition(int* array, int left, int right){
    int pivot = array[left];
    int itemFromLeft = left+1;
    int itemFromRight = right;
    while(itemFromLeft<=itemFromRight){
        if(array[itemFromLeft]>pivot && array[itemFromRight]<pivot){
            swap(array[itemFromLeft],array[itemFromRight]);
            itemFromLeft++;
            itemFromRight--;
        }
        else if(array[itemFromLeft]<=pivot){
            itemFromLeft++;
        }
        else if(array[itemFromRight]>=pivot){
            itemFromRight--;
        }
    }
    swap(array[itemFromRight], array[left]);
    return itemFromRight;
}
void quicksort(int* array, int left, int right){
    if(left<right){
        int pivotIndex = partition(array, left, right);
        quicksort(array, left, pivotIndex-1);
        quicksort(array, pivotIndex+1, right);
    }
}

int partition2(int* array, int left, int right){
    int pivot = array[left];
    int pivotIndex = left;
    
    for(int i=left+1; i<=right; i++){
        if(array[i]<pivot){
            pivotIndex++;
            swap(array[i], array[pivotIndex]);
        }
    }
    swap(array[left], array[pivotIndex]);
    return pivotIndex;
}

void quicksort2(int* array, int left, int right){
    if(left<right){
        int pivotIndex = partition2(array, left, right);
        quicksort2(array, left, pivotIndex-1);
        quicksort2(array, pivotIndex+1, right);
    }
}

int partition_desc(int* array, int left, int right) {
    int pivot = array[left];
    int pivotIndex = left;

    for (int i = left + 1; i <= right; i++) {
        if (array[i] > pivot) {
            pivotIndex++;
            swap(array[i], array[pivotIndex]); // Usando std::swap
        }
    }

    swap(array[left], array[pivotIndex]); // Usando std::swap
    
    return pivotIndex;
}

void quicksort_desc(int* array, int left, int right) {
    if (left < right) {
        int pivotIndex = partition_desc(array, left, right);
        quicksort_desc(array, left, pivotIndex - 1);
        quicksort_desc(array, pivotIndex + 1, right);
    }
}

int main() {
    
    int array[N] = {2, 8, 5, 3, 9, 4};
    cout <<"Ordenado: "<< endl;
    quicksort_desc(array, 0, N-1);
    for(int i=0; i<N; i++){
        cout << array[i] << " ";
    }
    return 0;
}
