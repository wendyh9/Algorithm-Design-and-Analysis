// author: Wendy Haw

#include <iostream>
#define NEG_MAX_NUM -21000
using namespace std;

// followed pseudocode from pg 369 in textbook

int* arr1;
int* arr2;

void extendedBottomUpCutRod(int prices[], int n){
    // size of arr1 and arr2 need to correlate to size of prices
    // gives us the max revenue
    arr1 = new int[n + 1];
    // holds optimal decomposition of rod
    arr2 = new int[n + 1];
    int q;
    
    arr1[0] = 0;
    for (int j = 1; j < n + 1; j++){
        q = NEG_MAX_NUM;
        for (int i = 1; i < j + 1; i++){
            if (q < (prices[i] + arr1[j - i])){
                q = prices[i] + arr1[j - i];
                arr2[j] = i;
            }
        }
        arr1[j] = q;
    }
    cout << arr1[n] << endl;
}

void printCutRodSoln(int prices[], int n){
    extendedBottomUpCutRod(prices, n);
    while(n > 0){
        cout << arr2[n] << " ";
        n = n - arr2[n];
    }
    cout << "-1" << endl;
}

int main(){

    int n;
    cin >> n;

    // n + 1 because prices[0] needs to be initialized to 0
    int* prices = new int[n + 1];
    prices[0] = 0;

    for (int i = 1; i < n + 1; i++){
        cin >> prices[i];
    }
    
    printCutRodSoln(prices, n);

    // deallocate heap memory reserved for prices, arr1, and arr2
    delete[] prices;
    delete[] arr1;
    delete[] arr2;

    return 0;
}