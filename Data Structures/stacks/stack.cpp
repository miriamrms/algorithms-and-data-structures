//
//  main.cpp
//  Stacks
//
//  Created by Miriam Mendes on 29/05/25.
//

/*
 b) Implemente em C++ uma Stack (Pilha) de números inteiros com as seguintes
 operações:
 i) Inserir um elemento no topo. ✅
 ii) Remover um elemento do topo. ✅
 iii) Exibir todos os elementos da pilha. ✅
 iv) Exibir quantos elementos existem na pilha. ✅
 */

#include <iostream>
using namespace std;

typedef struct node {
    int value;
    struct node* next;
} Node;

typedef struct stack {
    int size;
    Node* top;
} Stack;

Stack* createStack();
void push(Stack* stack, int value);
void pop(Stack* stack);
void printStack(Stack* stack);

Stack* createStack(){
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack -> size = 0;
    stack -> top = NULL;
    return stack;
}

void push(Stack* stack, int value){
    Node* node = (Node*) malloc(sizeof(Node));
    node -> value = value;
    node -> next = stack -> top;
    stack -> top = node;
    stack -> size++;
}

void pop(Stack* stack){
    if(stack->size != 0){
        Node* auxNode = stack -> top;
        stack -> top = auxNode -> next;
        free(auxNode);
        stack -> size--;
    }
}

void printStack(Stack* stack){
    Node* currentNode = stack -> top;
    cout << "Pilha: ";
    while (currentNode != NULL) {
        cout << currentNode -> value << "  ";
        currentNode = currentNode -> next;
    }
    cout << endl;
}


int main() {
    
    Stack* stack = createStack();
    
    cout << "Inserindo 5 no topo: " << endl;
    push(stack, 5);
    printStack(stack);
    cout << "Inserindo 10 no topo: " << endl;
    push(stack, 10);
    printStack(stack);
    cout << "Inserindo 20 no topo: " << endl;
    push(stack, 20);
    printStack(stack);
    cout << "Inserindo 30 no topo: " << endl;
    push(stack, 30);
    printStack(stack);
    
    cout << "Removendo Elemento do Topo: " << endl;
    pop(stack);
    printStack(stack);
    
    cout << "Números de Elementos na Pilha: " << stack -> size << endl;
    
    return 0;
}
