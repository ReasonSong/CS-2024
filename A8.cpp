//
// CS2024 -- Assignment 8
//
// rs2352 (Ruochen Song), hy483 (Hongshu Ye)  10/26/2016
//
// Exercise 13.15 Deitel & Deitel's "C++ How to Program"
//
// For this assignment we may implement all of the functionality of the Point class in the file Point.h.
// A "point" should be read and printed as a comma separated pair of integers wrapped in parenthesis: (4,5).
// There is no whitespace between the numbers and the parentheses or the numbers and the comma.
//
// 13.15 (Point Class) Write a program that accomplishes each of the following:
// a) Create a user-defined class Point that contains the private integer data members xCoordinate and yCoordinate,
//    and declares stream insertion and stream extraction overloaded operator functions as friends of the class.
// b) Define the stream insertion and stream extraction operator functions. The stream extraction operator function
//    should determine whether the data entered is valid, and, if not, it should set the failbit to indicate improper input.
//    The stream insertion operator should not be able to display the point after an input error occurred.
// c) Write a main function that tests input and output of user-defined class Point, using the overloaded stream extraction
//    and stream insertion operators.
//
// WITH THE FOLLOWING ADDITION:
// In main.cpp, test reading from a file and writing to a file with the Point class.
// Use the "input.dat" as an input file.
//
//
// Class Point is defined and implemented in Point.hpp.
//
// Tests code is written in the main() function.
//
// Compiled by Xcode.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include "Point.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    
    ifstream input("input.dat");
    ofstream output("output.dat", ios::trunc);
    
    if(!input.is_open()) {
        cout << "Can't open input file." << endl;
        return -1;
    }
    if(!output.is_open()) {
        cout << "Can't open output file." << endl;
        return -2;
    }
    
    while (input && output) {
        Point p;
        input >> p;
        output << p;
    }
    
}



