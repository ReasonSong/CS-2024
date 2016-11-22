//
// CS2024 -- Assignment 12
//
// rs2352 (Ruochen Song), hy483 (Hongshu Ye)  11/22/2016
//
// This assignment requires us to sort an integer array of size 5 using bubble sort.
//
// Step 1: Ask the user to enter 5 integers.
// Step 2: Use bubble sort algorithm and sort the array in ascending order.
// Step 3: Display the sorted array
//
// Compiled by Xcode.
//

#include <iostream>
#include <algorithm>

using namespace std;

void bubbleSort(int*);

int main(int argc, const char * argv[]) {
    
    int num[5];
    
    cout << "Please enter 5 integers saperately: " << endl;
    for (int i = 0; i < 5; ++i) cin >> num[i];
    bubbleSort(num);
    for (int i = 0; i < 5; ++i) cout << num[i] << " ";
    cout << endl;
    
}

void bubbleSort(int* array){
    for(int i = 0; i < 5; ++i){
        int min = *(array + i);
        for (int j = i + 1; j < 5; ++j) {
            if (*(array + j) < min) {
                min = *(array + j);
                swap(*(array + i), *(array + j));
            }
        }
    }
}