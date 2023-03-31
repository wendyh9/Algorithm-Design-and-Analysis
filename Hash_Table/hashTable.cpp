// author: Wendy Haw

#include <iostream>
#include <list>
#include <string>
#include <stdlib.h>
using namespace std;

// hash table

// need to implement insert, search, and delete

// provide index for key
int hashFunction(int key, int size){
    return (key % size);
}

void insertKey(list<int>* hashTable, int size, int key){
    int index = hashFunction(key, size);
    // if empty, no collision
    if (hashTable[index].empty()){
        hashTable[index].push_back(key);
    }
    // there is a collision => insert at front
    else {
        hashTable[index].push_front(key);
    }
}

int search(list<int>* hashTable, int size, int key, int* x, int* y){
    int j = 0;
    for (int i = 0; i < size; i++){
        for (auto k: hashTable[i]){
            if (k == key){
                *x = i;
                *y = j;
                return 1;
            }
            j++;
        }
        j = 0;
    }
    return 0;
}

void searchKey(list<int>* hashTable, int size, int key){
    int i;
    int j;
    int* temp1 = &i;
    int* temp2 = &j;

    if (search(hashTable, size, key, temp1, temp2)){
        cout << key << ":FOUND_AT" << i << "," << j << ";" << endl;
        return;        
    }

    cout << key << ":NOT_FOUND" << ";" << endl;
    return;
}

void deleteKey(list<int>* hashTable, int size, int key){
    int i;
    int j;
    int* temp1 = &i;
    int* temp2 = &j;

    
    if (search(hashTable, size, key, temp1, temp2)){
        list<int>::iterator itr = hashTable[i].begin();
        advance(itr,j);        
        hashTable[i].erase(itr);
        cout << key << ":DELETED;" << endl;
        return;        
    }
    cout << key << ":DELETE_FAILED;" << endl;
    return;
}

void outputTable(list<int>* hashTable, int size){
    for (int i = 0; i < size; i++){
        cout << i << ":";
        for(auto j: hashTable[i]){
            cout << j << "->";
        }
        cout << ";" << endl;
    }
}


int main(){
    int size;
    cin >> size;
    cin.ignore();

    list<int>* hashTable;
    hashTable = new list<int>[size];
    string str;
    string instruction;
    int key;

    while(instruction != "e"){
        cin >> str;
        instruction = str.substr(0,1);
        if(str.length() > 1){
            key = stoi(str.substr(1,str.length() - 1));
        }

        // cout << "counter: " << counter << endl;
        // cout << "instruction: " << instruction << endl;
        // cout << "key: " << key << endl << endl;
        
        // insert key
        if(instruction == "i"){
            insertKey(hashTable, size, key);
        }
        // search key
        else if(instruction == "s"){
            searchKey(hashTable, size, key);
        }
        // delete key
        else if(instruction == "d"){
            deleteKey(hashTable, size, key);
        }
        // output hash table contents
        else if(instruction == "o"){
            outputTable(hashTable, size);
        }
    }
    
    // deallocate memory used by hashTable
    delete[] hashTable;
    
    return 0;
}