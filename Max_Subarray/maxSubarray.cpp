// author: Wendy Haw

#include <iostream>
#include <limits.h>
#include <algorithm>
using namespace std;

// two functions needed for max subarray algorithm
int find_max_crossing_subarray(int A[], int low, int midpoint, int high){
    int left_sum = INT_MIN, right_sum = INT_MIN;
    int sum = 0;

    // left of midpoint
    for (int i = midpoint; i >= low; i--){
        sum += A[i];
        if (sum > left_sum){
            left_sum = sum;
        }
    }

    // reset sum to 0
    sum = 0;
    // right of midpoint
    for (int j = midpoint + 1; j <= high; j++){
        sum += A[j];
        if (sum > right_sum){
            right_sum = sum;
        }
    }
    // in case left_sum or right_sum is a negative value check if one is larger than left_sum + right_sum
    return max(left_sum + right_sum, max(left_sum, right_sum));
}

int find_max_subarray(int A[], int low, int high){
    // base case: only one element in subarray
    if (low == high){
        return A[low];
    }
    // break array in half
    int midpoint = (low + high) / 2;
    // cout << "midpoint: " << midpoint << endl;

    // max sum in left subarray A[low...midpoint]
    int max_sum_left_subarray = find_max_subarray(A, low, midpoint);
    // cout << "max_sum_left_subarray: " << max_sum_left_subarray << endl;
    
    // max sum in right subarray A[midpoint + 1...high]
    int max_sum_right_subarray = find_max_subarray(A, midpoint + 1, high);
    // cout << "max_sum_right_subarray: " << max_sum_right_subarray << endl;
    
    // max sum of crossing subarray A[low...midpoint...high]
    int max_crossing_subarray = find_max_crossing_subarray(A, low, midpoint, high);
    // cout << "max_crossing_subarray: " << max_crossing_subarray << endl;
    
    // return largest sum between left, right, and crossing subarrays
    return max(max(max_sum_left_subarray, max_sum_right_subarray), max_crossing_subarray);

}

int main(){
    // number of elements in array
    int n;
    cin >> n;

    // create array using n as size
    int* arr = new int[n];

    int temp;
    for (int i = 0; i < n; i++){
        cin >> temp;
        arr[i] = temp;
    }
    // use n - 1 in find_max_subarray() because we want to use the index
    cout << find_max_subarray(arr, 0, n - 1);

    // deallocate heap memory used by arr
    delete[] arr;

    return 0;
}