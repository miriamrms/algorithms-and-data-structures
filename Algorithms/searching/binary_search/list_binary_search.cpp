//
//  main.cpp
//  BinarySearch
//
//  Created by Miriam Mendes on 03/06/25.
//

#include <iostream>
using namespace std;

//Nó
typedef struct node {
    int value;
    struct node* next;
} Node;

//Lista
typedef struct list {
    int size;
    Node* head;
} List;

//MARK: Declarar Funções
List* createList();
bool isListEmpty(List* list);
void insertAtBeginning(List* list, int value);
void insertAtEnd(List* list, int value);
Node* getNode(List* list, int index);
void printList(List* list);

void binary_search(List* list, int element, int left, int right);

int main() {
    List* lista = createList();
    for(int k = 1; k < 1000; k++){
        insertAtEnd(lista, k + 399);
    }
    cout << "Elementos Visitados" << endl;
    binary_search(lista, 450, 0, (lista -> size) - 1);
    cout << endl;
}

void binary_search(List* list, int element, int left, int right){
    
    int middle = (left + right)/2;
    int valor = getNode(list, middle) -> value;
    
    if(left > right){
        cout << endl << "Elemento não encontrado!" << endl;
    }
    else if(element == valor){
        cout << valor << " ";
    }
    else if(element > valor){
        cout << valor << " ";
        binary_search(list, element, middle + 1, right);
    }
    else{
        cout << valor << " ";
        binary_search(list, element, left, middle - 1);
    }
}


//MARK: Escrever Funções

//criar lista
List* createList(){
    List* list = (List*) malloc(sizeof(List));
    
    list -> size = 0;
    list -> head = NULL;
    return list;
}

//verificar se está vazia
bool isListEmpty(List* list){
    if (list -> size == 0){
        return true;
    }
    return false;
}

//inserir no início
void insertAtBeginning(List* list, int value){
    Node* node = (Node*) malloc(sizeof(Node));
    node -> value = value;
    node -> next = list -> head;
    list -> head = node;
    list -> size++;
}

//inserir no final
void insertAtEnd(List* list, int value){
    if(isListEmpty(list)){
        insertAtBeginning(list, value);
    }
    else{
        Node* node = (Node*) malloc(sizeof(Node));
        node -> value = value;
        node -> next = NULL;
        Node* auxNode = list -> head;
        while (auxNode -> next != NULL) {
            auxNode = auxNode -> next;
        }
        auxNode -> next = node;
        list -> size++;
    }
}

//remover de um índice específico
Node* getNode(List* list, int index){
    Node* node = list -> head;
    for(int i = 1; i <= index; i++){
        node = node -> next;
    }
    return node;
}

void printList(List* list){
    Node* auxNode = list -> head;
    cout << "Lista: ";
    while (auxNode != NULL) {
        cout << auxNode -> value << "  ";
        auxNode = auxNode -> next;
    }
    cout << endl << endl;
}
