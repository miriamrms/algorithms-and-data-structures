//
//  main.cpp
//  Heapsort
//
//  Created by Miriam Mendes on 14/07/25.
//

#include <iostream>
using namespace std;

/*
Função heapify (sift-down): Corrige a posição de um nó, "afundando-o" na árvore
para manter a propriedade do max-heap. Retorna o número de trocas realizadas.
 */
int heapify(int *heap, int n, int i){
    int swaps = 0;
    int maior = i;
    int esquerdo = (2*i) + 1;
    int direiro = (2*i) + 2;
    
    if(esquerdo < n && heap[esquerdo] > heap[maior]){
        maior = esquerdo;
    }
    
    if(direiro < n && heap[direiro] > heap[maior]){
        maior = direiro;
    }
    
    if(maior != i){
        swap(heap[i], heap[maior]);
        swaps++;
        swaps += heapify(heap, n, maior); // soma trocas recursivas
    }
    return swaps;
}

/*
Função heapsort: Implementa APENAS a fase de ordenação de um heap já construído.
O objetivo principal aqui é contar as trocas que ocorrem nesta fase.
*/
int heapsort(int *heap, int n){
    int swaps = 0;
    
// O laço de construção do heap está comentado pois o heap já chega pronto.
//    for (int i = n / 2 - 1; i >= 0; i--){
//        swaps += heapify(heap, n, i); // conta trocas na construção
//    }
    
    for (int i = n - 1; i > 0; i--) {
        swap(heap[0], heap[i]);
        /*swaps++;*/ // troca da raiz com último
        swaps += heapify(heap, i, 0); // conta trocas no sift-down
    }
    return swaps;
}

// Função de construção de heap "Top-Down" (sift-up).
// Constrói o heap inserindo um elemento por vez e "subindo-o" para sua posição correta.
void heapify_top_down(int* arr, int n) {
    int i = 1;
    
    while (i < n) {
        int child = i;
        int parent = (child - 1) / 2;
        
        // Sobe o elemento enquanto violar a propriedade da heap mínima
        while (child > 0 && arr[child] > arr[parent]) {
            swap(arr[child], arr[parent]);
            child = parent;
            parent = (child - 1) / 2;
        }
        i++;
    }
}


int main() {
    
    int n;
    
    while(cin >> n){
        // OBJETIVO: Comparar qual método de construção de heap (Top-Down vs Bottom-Up)
        // resulta em um heap que exige MAIS TROCAS durante a FASE DE ORDENAÇÃO.

        // Cria dois arrays idênticos para servirem de base para os dois métodos.
        int *heap_topDown = new int[n];
        int *heap_bottomUp = new int[n];
        for(int i = n-1; i>=0; i--){
            heap_topDown[i] = i+1;
            heap_bottomUp[i] = i+1;
        }
        
        // --- CAMINHO 1: MÉTODO TOP-DOWN ---
        // 1. Constrói o heap com o método Top-Down (sift-up).
        heapify_top_down(heap_topDown, n);
        int *copy1 = new int[n];
        for(int j=0; j<n; j++){
            copy1[j] = heap_topDown[j];
        }
        // 2. Ordena o heap resultante e conta as trocas APENAS da fase de ordenação.
        int swaps_top_down = heapsort(copy1, n);
        delete[] copy1;
        
        // --- CAMINHO 2: MÉTODO BOTTOM-UP ---
        // 1. Constrói o heap com o método Bottom-Up (sift-down), o mais tradicional.
        for(int i = (n/2)-1; i>=0; i--){
            heapify(heap_bottomUp, n, i);
        }
        int *copy2 = new int[n];
        for(int j=0; j<n; j++){
            copy2[j] = heap_bottomUp[j];
        }
        // 2. Ordena o heap resultante e conta as trocas APENAS da fase de ordenação.
        int swaps_bottom_up = heapsort(copy2, n);
        delete[] copy2;
        
        // --- COMPARAÇÃO E RESULTADO ---
        // Compara o "custo de ordenação" de cada heap e imprime o heap original
        // que gerou o maior número de trocas ao ser ordenado.
        if(swaps_top_down > swaps_bottom_up){
            for(int i = 0; i<n; i++){
                cout << heap_topDown[i] << " ";
            }
        }
        else{
            for(int i = 0; i<n; i++){
                cout << heap_bottomUp[i] << " ";
            }
        }
        delete [] heap_topDown;
        delete [] heap_bottomUp;
        cout << endl;
    }
    
    
    return 0;
}
