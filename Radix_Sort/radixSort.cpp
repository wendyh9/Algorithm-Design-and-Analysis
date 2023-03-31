// author: Wendy Haw

#include <iostream>
#include <vector>
using namespace std;

// radix sort

void print_vect_2d(vector<vector<int>> vect_2d, int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < 10; j++){
            cout << vect_2d[i][j] << ";";
        }
        cout << endl;
    }      
}

// arrays consist of 0, 1, 2, 3 => only need to create 4 buckets
vector<vector<int>> bucketSort(vector<vector<int>> vect_2d, int n, int col){
    int i;
    
    vector<vector<int>> vect_0;
    vector<vector<int>> vect_1;
    vector<vector<int>> vect_2;
    vector<vector<int>> vect_3;
    for (i = 0; i < n; i++){
        if (vect_2d[i][col] == 0){
            vect_0.push_back(vect_2d[i]);
        }
        else if (vect_2d[i][col] == 1){
            vect_1.push_back(vect_2d[i]);
        }
        else if (vect_2d[i][col] == 2){
            vect_2.push_back(vect_2d[i]);
        }
        else if (vect_2d[i][col] == 3){
            vect_3.push_back(vect_2d[i]);
        }
    }
    vect_2d.clear();

    int size_vect_0 = vect_0.size();
    int size_vect_1 = vect_1.size();
    int size_vect_2 = vect_2.size();
    int size_vect_3 = vect_3.size();
    // cout << "size_vect_0: " << size_vect_0 << endl;
    // cout << "size_vect_1: " << size_vect_1 << endl;
    // cout << "size_vect_2: " << size_vect_2 << endl;
    // cout << "size_vect_3: " << size_vect_3 << endl;

    if (size_vect_0 > 0){
        for (i = 0; i < size_vect_0; i++){
            vect_2d.push_back(vect_0[i]);
        }
    }
    if (size_vect_1 > 0){
        for (i = 0; i < size_vect_1; i++){
            vect_2d.push_back(vect_1[i]);
        }        
    }
    if (size_vect_2 > 0){
        for (i = 0; i < size_vect_2; i++){
            vect_2d.push_back(vect_2[i]);
        }        
    }
    if (size_vect_3 > 0){
        for (i = 0; i < size_vect_3; i++){
            vect_2d.push_back(vect_3[i]);
        }        
    }
    // cout << "bucketSort" << endl;
    // print_vect_2d(vect_2d, n);
    // cout << endl;
    return vect_2d;
}

vector<vector<int>> radixSort(vector<vector<int>> vect_2d, int n){
    int col = 9;
    for (int i = 0; i < 10; i++){
        vect_2d = bucketSort(vect_2d, n, col);
        col--; 
    }
    return vect_2d;
}




int main(){
    // n number of vectors
    int n;
    cin >> n;
    cin.ignore();

    // n x 10 2D array
    vector<vector<int>> vect_2d;
    int temp_num;
    
    // read in input and store in arr
    for (int i = 0; i < n; i++){
        vector<int> temp_vect;
        for (int j = 0; j < 10; j++){
            scanf("%d", &temp_num);    
            temp_vect.push_back(temp_num);
        }
        vect_2d.push_back(temp_vect);
    }

    vect_2d = radixSort(vect_2d, n);
    
    // print arr
    print_vect_2d(vect_2d,n);

    return 0;
}