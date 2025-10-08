//
//  main.cpp
//  BinarySearch
//
//  Created by Miriam Mendes on 03/06/25.
//

#include <iostream>
using namespace std;

string binary_search(int array[], int element, int left, int right);

int main() {
    int array[15] = {1,2,3,5,6,7,8,9,10,12,15,89,92,96,102};
    cout << binary_search(array, 9, 0, 14) << endl;
}

string binary_search(int array[], int element, int left, int right){
    
    int middle = (left + right)/2;
    
    if(left > right){
        return "Elemento não encontrado";
    }
    
    else if(element == array[middle]){
        return "Elemento encontrado na posição " + std::to_string(middle);
    }
    
    else if(element > array[middle]){
        return binary_search(array, element, middle + 1, right);
    }
    
    else{
        return binary_search(array, element, left, middle - 1);
    }
}

