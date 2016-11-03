//
// CS2024 -- Assignment 9
//
// rs2352 (Ruochen Song), hy483 (Hongshu Ye)  11/03/2016
//
// Exercise 13.15 Deitel & Deitel's "C++ How to Program"
//
// For this assignment we are required to write a very simple Array class called "SimpleArray" that behaves
// just like a C/C++ primitive array with the following additions:
// 1. It is a template class allowing for the user to specify the type stored in the array
// 2. Takes a template parameter specifying the size of the array. The size of the array does not change during the lifetime of the array.
// 3. Implements operator[] such that a simple exception is thrown if a bad index is specified.
//
// We provide a driver program that tests our array with more than one type and demonstrates that the proper behavior results when a bad
// index is encountered in the main() function.
//
// Compiled by Xcode.
//

#include <iostream>
#include "SimpleArray.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    
    // Create arraries with the type and size the user specifies
    SimpleArray<int> intArray(5);
    SimpleArray<float> floatArray(7);
    try {SimpleArray<long> longArray(-1);}
    catch (invalid_argument) {
        cout << "Cannot create an array of a negatice size." << endl;
    }
    
    // Assign values to the arraries
    for(int i = 0; i < intArray.getSize(); ++i) intArray[i] = i + 3;
    for(int i = 0; i < floatArray.getSize(); ++i) floatArray[i] = i * 1.238;
    
    // Get the values of all the elements in the arraries
    for(int i = 0; i < intArray.getSize(); ++i){
        cout << "value with the index of " << i << " in the int array is: " << intArray[i] << endl;
    }
    for(int i = 0; i < floatArray.getSize(); ++i){
        cout << "value with the index of " << i << " in the float array is: " << floatArray[i] << endl;
    }
    
    // Try to get the values of elements with bad indexes
    try {intArray[-1];}
    catch (invalid_argument) {cout << "Can't get the value with a negative index." << endl;}
    try {floatArray[floatArray.getSize()];}
    catch (invalid_argument) {cout << "Can't get the value with a index out of boundry." << endl;}
    
}



