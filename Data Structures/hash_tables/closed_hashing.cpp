//
//  main.cpp
//  ClosedHashing
//
//  Created by Miriam Mendes on 07/10/25.
//

#include <iostream>
using namespace std;

/*
 Implemente em C++ um dicionário usando closed hashing com pseudo random probing
 com as seguintes operações:
 i) Criar dicionário ✅
 ii) Inserir elemento ✅
 iii) Buscar elemento ✅
 iv) Remover elemento ✅
 v) Exibir dicionário ✅
 vi) Verificar se está vazio ✅
 */

#define TABLE_SIZE 7

typedef enum { EMPTY, OCCUPIED, DELETED } State;

typedef struct entry {
    int key;
    string name;
    State state;
} Entry;

typedef struct {
    int m;                     
    int cnt;                   
    Entry H[TABLE_SIZE];       
    int Perm[TABLE_SIZE - 1];  
} Dictionary;

//Functions

Dictionary* createDictionary();
void create_permutation(int perm[]);

int h(int key);

void insert(Dictionary* d, int key, string name);
void search_student(Dictionary* d, int key);
bool student_is_found(Dictionary* d, int key);
void delete_student(Dictionary* d, int key);
void print_dictionary(Dictionary* d);

int main() {
    Dictionary* d = createDictionary();
    int option = 1;
    while (option != 0) {
        
        cout << "0 - Exit" << endl;
        cout << "1 - Insert student" << endl;
        cout << "2 - Search student" << endl;
        cout << "3 - Delete student" << endl;
        cout << "4 - Print dictionary" << endl;
        
        cout << "Type your option: ";
        cin >> option;
        
        if (option == 1) {
            cout << "Type the key: ";
            int key;
            cin >> key;
            cout << "Type the name: ";
            string name;
            cin.ignore();
            getline(cin, name);
            insert(d, key, name);
        }
        else if (option == 2) {
            cout << "Type the key: ";
            int key;
            cin >> key;
            search_student(d, key);
        }
        else if (option == 3) {
            cout << "Type the key: ";
            int key;
            cin >> key;
            delete_student(d, key);
        }
        else if (option == 4) {
            print_dictionary(d);
        }
    }
}

Dictionary* createDictionary(){
    Dictionary* d = new Dictionary;
    d -> m = TABLE_SIZE;
    d -> cnt = 0;
    for(int i = 0; i < TABLE_SIZE; i++){
        d -> H[i].state = EMPTY;
    }
    create_permutation(d -> Perm);
    return d;
}

void create_permutation(int perm[]){
    for (int i = 0; i < TABLE_SIZE; i++) {
        perm[i] = i + 1;
    }
    for (int i = TABLE_SIZE - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swap(perm[i], perm[j]);
    }
}

int h(int key){
    int r = key % TABLE_SIZE;
    return (r < 0) ? r + TABLE_SIZE : r;
}

void insert(Dictionary* d, int key, string name){
    if (student_is_found(d, key)){
        cout << "Key " << key << " already exists." << endl;
        return;
    }
    int position = h(key);
    if (d -> H[position].state == OCCUPIED) {
        for(int i = 0; i < TABLE_SIZE - 1; i++){
            position = (position + d -> Perm[i]) % TABLE_SIZE;
            if (d -> H[position].state != OCCUPIED) {
                break;
            }
        }
    }
    if (d -> H[position].state == OCCUPIED) {
        cout << "Hash table is full!" << endl;
        return;
    } else {
        cout << "Inserting key " << key << " at position " << position << endl;
        d -> H[position].key = key;
        d -> H[position].name = name;
        d -> H[position].state = OCCUPIED;
        d -> cnt++;
    }
}

void search_student(Dictionary* d, int key){
    for (int i = 0; i < TABLE_SIZE; i++) {
        int position = 0;
        if (i==0){
            position = h(key);
        }
        else {
            position = (position + d->Perm[i-1]) % TABLE_SIZE;
        }
        
        if (d->H[position].state == OCCUPIED && d->H[position].key == key){
            cout << "Student found: " << d->H[position].name << endl;
            return;
        }
        else if (d->H[position].state == EMPTY){
            cout << "Key " << key << " not found." << endl;
            cout << "Never used Slot" << endl;
            return;
        }
    }
    cout << "Key " << key << " not found." << endl;
}

bool student_is_found(Dictionary* d, int key){
    for (int i = 0; i < TABLE_SIZE; i++) {
        int position = 0;
        if (i==0){
            position = h(key);
        }
        else {
            position = (position + d->Perm[i-1]) % TABLE_SIZE;
        }
        
        if (d->H[position].state == OCCUPIED && d->H[position].key == key){
            return true;
        }
        else if (d->H[position].state == EMPTY){
            return false;
        }
    }
    return false;
}

void delete_student(Dictionary* d, int key){
    for (int i = 0; i < TABLE_SIZE; i++) {
        int position = 0;
        if (i==0){
            position = h(key);
        }
        else{
            position = (position + d->Perm[i-1]) % TABLE_SIZE;
        }
        if (d->H[position].state == OCCUPIED && d->H[position].key == key){
            d->H[position].state = DELETED;
            d->cnt--;
            cout << "Key " << key << " deleted." << endl;
            return;
        }
        else if (d->H[position].state == EMPTY){
            cout << "Key " << key << " not found." << endl;
            cout << "Never used Slot" << endl;
            return;
        }
    }
        
}

void print_dictionary(Dictionary* d){
    if (d -> cnt == 0) {
        cout << "Dictionary is empty!" << endl;
        return;
    }
    cout << "Students:" << endl;
    for(int i = 0; i < TABLE_SIZE; i++){
        if (d -> H[i].state == OCCUPIED) {
            cout << "(i = " << i << ") | Key: " << d -> H[i].key << " | Name: " << d -> H[i].name << endl;
        }
    }
}
