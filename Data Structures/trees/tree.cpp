//
//  main.cpp
//  Tree
//
//  Created by Miriam Mendes on 10/06/25.
//

#include <iostream>
using namespace std;

//Nó
typedef struct node {
    int value;
    struct node* left;
    struct node* right;
} Node;

//Arvore
typedef struct tree {
    int size;
    Node* root;
} Tree;

Tree* createTree();
bool isTreeEmpty(Tree* tree);
void addElement(Tree* tree, int value);
void busca_Pre_Ordem(Node* currentNode);
void busca_Em_Ordem(Node* currentNode);
void busca_Pos_Ordem(Node* currentNode);

int main() {
    Tree* arvore = createTree();
    addElement(arvore, 8);
    addElement(arvore, 3);
    addElement(arvore, 10);
    addElement(arvore, 1);
    addElement(arvore, 6);
    addElement(arvore, 14);
    addElement(arvore, 4);
    addElement(arvore, 7);
    addElement(arvore, 13);
    busca_Pos_Ordem(arvore -> root);
    return 0;
}

//criar arvore
Tree* createTree(){
    Tree* tree = (Tree*) malloc(sizeof(Tree));
    tree -> size = 0;
    tree -> root = NULL;
    return tree;
}

//verificar se está vazia
bool isTreeEmpty(Tree* tree){
    if (tree -> size == 0){
        return true;
    }
    return false;
}

void addElement(Tree* tree, int value){
    Node* node = (Node*) malloc(sizeof(Node));
    node -> value = value;
    node -> left = NULL;
    node -> right = NULL;
    if (isTreeEmpty(tree)){
        tree -> root = node;
    }
    else{
        Node* currentNode = tree -> root;
        Node* previousNode = NULL;
        while (currentNode != NULL) {
            previousNode = currentNode;
            if(value <= currentNode -> value){
                currentNode = currentNode -> left;
            }
            else{
                currentNode = currentNode -> right;
            }
        }
        if(value <= previousNode -> value){
            previousNode -> left = node;
        }
        else{
            previousNode -> right = node;
        }
    }
    tree -> size++;
}

void busca_Pre_Ordem(Node* currentNode){
    if (currentNode != NULL){
        cout << (currentNode -> value) << endl;
        busca_Pre_Ordem(currentNode -> left);
        busca_Pre_Ordem(currentNode -> right);
    }
}

void busca_Em_Ordem(Node* currentNode){
    if (currentNode != NULL){
        busca_Em_Ordem(currentNode -> left);
        cout << (currentNode -> value) << endl;
        busca_Em_Ordem(currentNode -> right);
    }
}

void busca_Pos_Ordem(Node* currentNode){
    if (currentNode != NULL){
        busca_Pos_Ordem(currentNode -> left);
        busca_Pos_Ordem(currentNode -> right);
        cout << (currentNode -> value) << endl;
    }
}

