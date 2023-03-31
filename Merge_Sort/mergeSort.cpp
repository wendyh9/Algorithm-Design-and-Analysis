// author: Wendy Haw

#include <iostream>
using namespace std;

// merge sort algorithm

void merge(int arr[], int left, int middle, int right){
    // size of firstHalf subarray
    int n1 = middle - left + 1;

    // size of lastHalf subarray
    int n2 = right - middle;

    // create 2 subarrays
    int firstHalf[n1];
    int lastHalf[n2];

    // populate firstHalf with elements from arr[0 : n1 - 1]
    for (int i = 0; i < n1; i++){
        firstHalf[i] = arr[left + i];
    }

    // populate lastHalf with elements from arr[n1 : n2 - 1]
    for (int j = 0; j < n2; j++){
        lastHalf[j] = arr[middle + j + 1];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while ((i < n1) && (j < n2)){
        // if number in firstHalf is smaller than or equal to number in lastHalf
        if (firstHalf[i] <= lastHalf[j]){
            arr[k] = firstHalf[i];
            i++;
        }
        // if number in lastHalf is smaller than or equal to number in firstHalf
        else{
            arr[k] = lastHalf[j];
            j++;
        }
        k++;
    }

    // if there are extra numbers in firstHalf after sorting between firstHalf and lastHalf
    // (size of arr was odd) 
    while (i < n1){
        arr[k] = firstHalf[i];
        i++;
        k++;
    }
    // if there are extra numbers in lastHalf after sorting between firstHalf and lastHalf
    // (size of arr was odd)
    while (j < n2){
        arr[k] = lastHalf[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right){
    // if there are more than one number in arr
    if (left < right){
        // middle is where arr will split into two subarrays
        int middle = (left + right) / 2;
        // recursively call mergeSort() on first subarray
        mergeSort(arr, left, middle);
        // recursively call mergeSort() on other subarray
        mergeSort(arr, middle + 1, right);
        // merge() will put back all the subarrays together
        merge(arr, left, middle, right);
    }
}



int main(){
    // n is the number of elements 
    int n;
    cin >> n;

    // dynamically allocated space for an int array of size n 
    int* arr = new int[n];

    // take in input from user and store in arr
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // call merge() function to sort arr
    mergeSort(arr, 0, n - 1); 

    // print out sorted arr
    for (int i = 0; i < n; i++){
        cout << arr[i] << ";";
    }

    // free up space used by arr in heap
    delete[] arr;

    return 0;
}