//
// CS2024 -- Assignment 6
//
// rs2352 (Ruochen Song), hy483 (Hongshu Ye)  9/31/2016
//
// Exercise 10.10 Deitel & Deitel's "C++ How to Program"
//
// RationalNumber class creates a class RationalNumber (fractions)
// with the following capabilities:
//
// a) Create a constructor that prevents a 0 denominator in a fraction,
//    reduces or simplifies fractions that are not in reduced form and avoids negative denominators.
// b) Overload the addition, subtraction, multiplication and division operators for this class.
// c) Overload the relational and equality operators for this class.
//
// In addition to doing a,b,c, we are also ask to implement a member function that "prints out" the rational number.
// To print out a rational number to the terminal, we can either leave it as numerator/denominator.
//
// Class RationalNumber is declared in RationalNumber.hpp and defined in RationalNumver.cpp.
//
// Test code is written in the main() function.
//
// Compiled by Xcode.
//

#include <iostream>
#include "RationalNumber.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    
    RationalNumber r1(2, -3);
    RationalNumber r2(-3, -9);
    RationalNumber r3(-1, -4);
    RationalNumber r4(-4, 9);
    
    cout << "r1 = " << r1.toString() << endl;
    cout << "r2 = " << r2.toString() << endl;
    cout << "r3 = " << r3.toString() << endl;
    cout << "r4 = " << r4.toString() << endl << endl;
    
    cout << r2.toString() << " + " << r3.toString() << " = " << (r2 + r3).toString() << endl;
    cout << r1.toString() << " - " << r2.toString() << " = " << (r1 - r2).toString() << endl;
    cout << r3.toString() << " * " << r4.toString() << " = " << (r3 + r4).toString() << endl;
    cout << r1.toString() << " / " << r4.toString() << " = " << (r1 / r4).toString() << endl << endl;
    
    cout << "r1 " << (r1 == r1 ? "equals to " : "does not equal to ") << "r1" << endl;
    cout << "r1 " << (r1 == r2 ? "equals to " : "does not equal to ") << "r2" << endl;
    cout << "r3 " << (r3 < r4 ? "is smaller than " : "is not smaller than ") << "r4" << endl;
    cout << "r2 " << (r2 > r3 ? "is larger than " : "is not larger than ") << "r3" << endl << endl;
    
    try { r4.setDominator(0);}
    catch (invalid_argument) { cout << "r4 dominator cannot be set to 0." << endl;}
    
    try { RationalNumber r5(-1, 0);}
    catch (invalid_argument) { cout << "r5 dominator invalid." << endl;}
    
}



