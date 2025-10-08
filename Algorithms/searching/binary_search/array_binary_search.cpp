//
//  main.cpp
//  BinarySearchStudent
//
//  Created by Miriam Mendes on 03/06/25.
//

#include <iostream>
using namespace std;

struct Student{
    int id;
    string name;
};

void add_students(Student *students);
int binary_search(Student students[], int element, int left, int right);

int main() {
    
    Student students[11];
    int findStudent;
    int idToFind;
    char option;
    
    add_students(students);
    
    cout << "Nessa escola existem alunos com matrículas de 20230001 a 20230011.\n\n";
    
    do{
        cout << "Para consultar um aluno digite <C> para finalizar o programa digite <S>: ";
        cin >> option;
        
        if(option == 'C' || option == 'c'){
            cout << "Insira o ID de um aluno: ";
            cin >> idToFind;
            
            findStudent = binary_search(students, idToFind, 0, 9);
            if(findStudent == -1){
                cout << "\nAluno não encontrado" << endl << endl;
            }
            
            else{
                cout << endl << "\nAluno encontrado: " << students[findStudent].name << " na posição " << findStudent << endl << endl;
            }
        }
        
    } while(option != 's' && option!= 'S');
    return 0;
}

int binary_search(Student students[], int id, int left, int right){
    
    int middle = (left + right)/2;
    
    if(left > right){
        return -1;
    }
    
    else if(id == students[middle].id){
        return middle;
    }
    
    else if(id > students[middle].id){
        return binary_search(students, id, middle + 1, right);
    }
    
    else{
        return binary_search(students, id, left, middle - 1);
    }
    
}

void add_students(Student *students){
    students[0] = {20230001, "Miriam Mendes"};
    students[1] = {20230002, "Luiz Ferreira"};
    students[2] = {20230003, "Sofia Izabella"};
    students[3] = {20230004, "Diego Santos"};
    students[4] = {20230005, "Lara Luchi"};
    students[5] = {20230006, "Livía Trindade"};
    students[6] = {20230007, "Luan Bezerra"};
    students[7] = {20230008, "Luciana Almeda"};
    students[8] = {20230009, "Bianca Sem Sobrenome"};
    students[9] = {202300010, "Karol Challegre"};
    students[10] = {20230011, "Fernanda Juncker"};
}
