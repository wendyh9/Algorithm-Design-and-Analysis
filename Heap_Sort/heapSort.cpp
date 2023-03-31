// author: Wendy Haw

#include <iostream>
#include <algorithm>
using namespace std;

// Implement Heap-Sort

// refer to lecture 7, slide 11 or textbook, pg 175
void heapify(int A[], int i, int size){
    // set indices for leftChild and rightChild nodes
    int leftChild = (2 * i) + 1;
    int rightChild = (2 * i) + 2;

    // initialize largest as root node
    int largest = i;

    // check if value of leftChild node is larger than or equal to value at index largest 
    if (leftChild < size && A[leftChild] > A[largest]){
        largest = leftChild;
    }

    // check if value of rightChild node is larger than or equal to value at index largest 
    if (rightChild < size && A[rightChild] > A[largest]) {
        largest = rightChild;
    }

    // check if largest value of subtree is not the value at root of subtree
    if (largest != i){
        swap(A[i], A[largest]);
        heapify(A, largest, size);
    }
}   

// refer to lecture 7, slides 16 - 17
void buildHeap(int A[], int size){
    // rearrange nodes in arr
    for (int i = (size / 2) - 1; i >= 0; i--){
        heapify(A, i, size);
    }
}   

// refer to lecture 7, slide 20 or textbook, pg 181
void heapSort(int A[], int size){
    buildHeap(A, size);

    // extract largest value
    for (int i = size - 1; i > 0; i--){
        // move largest value to the end of arr
        swap(A[0], A[i]);
        // heapify the subarray
        heapify(A, 0, i);
    }
}       

int main(){
    int i;

    // n is the number of elements in arr 
    int n;
    cin >> n;

    // create a dynamic int array of size n
    int* arr = new int[n];
    
    int temp;
    for (i = 0; i < n; i++){
        cin >> temp;
        arr[i] = temp;
    }

    heapSort(arr, n);

    // print arr after heapSort()
    for (i = 0; i < n; i++){
        cout << arr[i] << ";";
    }

    // deallocate memory used by arr in heap
    delete[] arr;

    return 0;
}