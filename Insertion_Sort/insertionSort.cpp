// author: Wendy Haw

#include <iostream>
using namespace std;

// Insertion sort
int main(){

    int array_size = 0;
    // take in first number
    cin >> array_size;

    if (array_size < 0){
        cout << "This is an incorrect size for array." << endl;
        return 0;
    }

    // create a dynamic array using first number as size
    int* array = new int[array_size]; 

    // create a temporary variable to store input
    int num = 0;

    // use a for loop to take in following input to store in array
    for (int i = 0; i < array_size; i++){
        cin >> num;
        array[i] = num;
    }   

    
    int key, j;
    for (int i = 1; i < array_size; i++){
        key = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > key){
            // shift all numbers to the right to make room for key
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;   

        // print out sorted subarray for each iteration
        for (int k = 0; k < i + 1; k++){
            cout << array[k] << ";";
        }
        cout << endl;
    }      

    // deallocate space used by array on heap
    delete[] array;
    return 0;
}