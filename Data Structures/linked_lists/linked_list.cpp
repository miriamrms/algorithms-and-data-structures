//
//  main.cpp
//  Lista_Encadeada
//
//  Created by Miriam Mendes on 28/05/25.
//

/*
 Implemente em C++ uma lista encadeada simples de números inteiros com
 as seguintes operações:
 i) Inserir um elemento no início. ✅
 ii) Inserir um elemento no final. ✅
 iii) Remover um elemento do início. ✅
 iv) Remover um elemento de um índice específico. ✅
 v) Exibir todos os elementos da lista. ✅
 vi) Inverta toda a lista. ✅
 */

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
void removeFromBeginning(List* list);
void removeAtIndex(List* list, int index);
void reverseList(List* list);
void printList(List* list);

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

//remover do início
void removeFromBeginning(List* list){
    if(!isListEmpty(list)){
        Node* auxNode = list -> head;
        list -> head = auxNode -> next;
        free(auxNode);
        list -> size--;
    }
}

//remover de um índice específico
void removeAtIndex(List* list, int index){
    if(index >= 0 && index < list -> size && !isListEmpty(list)){
        if(index == 0){
            removeFromBeginning(list);
        }
        else{
            Node* prevNode = list -> head;
            Node* indexNode = prevNode -> next;
            for(int i = 1; i < index; i++){
                prevNode = prevNode -> next;
                indexNode = prevNode -> next;
            }
            prevNode -> next = indexNode -> next;
            free(indexNode);
            list -> size--;
        }
    }
}

//reverter lista
void reverseList(List* list){
    if (isListEmpty(list) || list->head->next == NULL) {
        cout << "Lista vazia ou com apenas um elemento, não é necessário inverter." << endl;
        return;
    }
    Node* prevNode = NULL;
    Node* currentNode = list->head;
    Node* nextNode = NULL;
    while (currentNode!=NULL) {
        nextNode = currentNode -> next;
        currentNode -> next = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
    }
    list -> head = prevNode;
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

int main() {
    
    List* lista = createList();
    
    cout << "Inserindo 5 no início: " << endl;
    insertAtBeginning(lista, 5);
    printList(lista);
    cout << "Inserindo 10 no início: " << endl;
    insertAtBeginning(lista, 10);
    printList(lista);
    cout << "Inserindo 15 no início: " << endl;
    insertAtBeginning(lista, 15);
    printList(lista);
    
    cout << "Inserindo 20 no final: " << endl;
    insertAtEnd(lista, 20);
    printList(lista);
    cout << "Inserindo 30 no final: " << endl;
    insertAtEnd(lista, 30);
    printList(lista);
    cout << "Inserindo 40 no final: " << endl;
    insertAtEnd(lista, 40);
    printList(lista);
    
    cout << "Removendo elemento do início: " << endl;
    removeFromBeginning(lista);
    printList(lista);
    
    cout << "Removendo elemento do índice 2: " << endl;
    removeAtIndex(lista, 2);
    printList(lista);
    
    cout << "Invertendo a Lista: " << endl;
    reverseList(lista);
    printList(lista);
    
    return 0;
}
