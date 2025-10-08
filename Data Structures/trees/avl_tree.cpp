//
//  main.cpp
//  AVL_Tree
//
//  Created by Miriam Mendes on 14/07/25.
//

#include <iostream>
using namespace std;

//Nó da Árvore
typedef struct node {
    int value;
    struct node* left;
    struct node* right;
    int height;
} Node;

//Árvore
typedef struct tree {
    Node* root;
} AVLTree;

//MARK: Declarar Funções
AVLTree* createTree();
int height(Node* n);
Node* rightRotate(Node* y);
Node* leftRotate(Node* x);
int getBalance(Node *N);
Node* insertNode(Node* node, int val);
Node* minValueNode(Node* node);
Node* deleteNode(Node* root, int val);

//Imprimir arvore
void pre_Ordem(Node* currentNode);
void em_Ordem(Node* currentNode);
void pos_Ordem(Node* currentNode);

int main() {
    
    int n;
    char op;
    int valor;
    
    AVLTree* arvore = createTree();
    
    cin >> n;
    
    for(int i = 0; i<n; i++){
        cin >> op;
        cin >> valor;
        if (op == 'i'){
            arvore -> root = insertNode(arvore -> root, valor);
        }
        else{
            arvore -> root = deleteNode(arvore -> root, valor);
        }
    }
    
    pre_Ordem(arvore -> root);
    cout << endl;
    em_Ordem(arvore -> root);
    cout << endl;
    pos_Ordem(arvore -> root);
    
    return 0;
}

//MARK: Escrever Funções

//criar árvore
AVLTree* createTree() {
    AVLTree* tree = new AVLTree;
    tree->root = nullptr;
    return tree;
}

//retorna a altura de um nó
int height(Node* n) {
    if (n == NULL) {
        return 0;
    }
    return n->height;
}

Node* rightRotate(Node* y){
    Node* x = y->left;
    Node* temp = x -> right;
    
    x->right = y;
    y->left = temp;
    
    // atualiza as alturas
    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));
    
    // nova raiz da subarvore
    return x;
}

Node *leftRotate(Node *x) {
    Node *y = x->right;
    Node *temp = y->left;

    y->left = x;
    x->right = temp;

    // atualiza as alturas
    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    // nova raiz da subarvore
    return y;
}

int getBalance(Node *N) {
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

//MARK: Inserir nó

Node* insertNode(Node* node, int val) {
  
    if (node == NULL){
        Node* newNode = new Node;
        newNode->value = val;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->height = 1;
        return newNode;
    }

    if (val < node->value){
        node->left = insertNode(node->left, val);
    }
    else if (val > node->value){
        node->right = insertNode(node->right, val);
    }
    else{
        return node;
    }
    
    node->height = 1 + max(height(node->left), height(node->right));

    // Fator de balanceamento
    int balance = getBalance(node);

    //LL
    if (balance > 1 && val < node->left->value){
        cout << node->value << endl;
        return rightRotate(node);
    }

    //RR
    if (balance < -1 && val > node->right->value){
        cout << node->value << endl;
        return leftRotate(node);
    }

    //LR
    if (balance > 1 && val > node->left->value) {
        cout << node->value << endl;
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    //RL
    if (balance < -1 && val < node->right->value) {
        cout << node->value << endl;
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    
    return node;
}

//MARK: deletar nó

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

Node* deleteNode(Node* root, int val) {
    if (root == NULL){
        return root;
    }

    if (val < root->value){
        root->left = deleteNode(root->left, val);
    }
        
    else if (val > root->value){
        root->right = deleteNode(root->right, val);
    }
    else {
        // Nó com apenas um filho ou nenhum filho
        if ((root->left == NULL) || (root->right == NULL)) {
            Node* temp = root->left ? root->left : root->right;
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else {
                *root = *temp;
            }
            delete temp;
        } else {
            // Nó com dois filhos
            Node* temp = minValueNode(root->right);
            root->value = temp->value;
            root->right = deleteNode(root->right, temp->value);
        }
    }

    if (root == NULL){
        return root;
    }

    root->height = 1 + max(height(root->left), height(root->right));

    // fator de balanceamento
    int balance = getBalance(root);

    // LL
    if (balance > 1 && getBalance(root->left) >= 0) {
        cout << root->value << endl;
        return rightRotate(root);
    }
    // LR
    if (balance > 1 && getBalance(root->left) < 0) {
        cout << root->value << endl;
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    // RR
    if (balance < -1 && getBalance(root->right) <= 0) {
        cout << root->value << endl;
        return leftRotate(root);
    }
    // RL
    if (balance < -1 && getBalance(root->right) > 0) {
        cout << root->value << endl;
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

//MARK: Imprimir

void pre_Ordem(Node* currentNode){
    if (currentNode != NULL){
        cout << (currentNode -> value) << " ";
        pre_Ordem(currentNode -> left);
        pre_Ordem(currentNode -> right);
    }
}

void em_Ordem(Node* currentNode){
    if (currentNode != NULL){
        em_Ordem(currentNode -> left);
        cout << (currentNode -> value) << " ";
        em_Ordem(currentNode -> right);
    }
}

void pos_Ordem(Node* currentNode){
    if (currentNode != NULL){
        pos_Ordem(currentNode -> left);
        pos_Ordem(currentNode -> right);
        cout << (currentNode -> value) << " ";
    }
}
