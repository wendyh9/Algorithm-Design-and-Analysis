// author: Wendy Haw

#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

// Implement Quick-Sort

int partition(int A[], int left, int right){
    int pivot = A[right];
    int i = left - 1;
    // move elements <= pivot into subarray to the left of pivot
    for (int j = left; j <= right - 1; j++){
        if (A[j] <= pivot){
            i++;
            swap(A[i], A[j]);
        }
    }
    swap(A[i + 1], A[right]);
    return (i + 1);
}

int partitionRand(int A[], int left, int right){
    // how to get a random number within a range
    // ensures that we won't generate the same random number every time  
    srand(time(NULL));
    // int random = offset + (rand() % range);    
    int randNum = left + (rand() % (right - left));
    swap(A[randNum], A[right]);
    return partition(A, left, right);
}


void quickSort(int A[], int left, int right){
    if (left < right){
        // get random number within range [left, right]
        int pivot = partitionRand(A, left, right);
        // sort left side of pivot
        quickSort(A, left, pivot - 1);
        // sort right side of pivot
        quickSort(A, pivot + 1, right);
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

    quickSort(arr, 0, n - 1);

    // print arr after quickSort()
    for (i = 0; i < n; i++){
        cout << arr[i] << ";";
    }

    // deallocate memory used by arr in heap
    delete[] arr;

    return 0;
}