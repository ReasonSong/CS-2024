//
//  RationalNumber.hpp

#ifndef RationalNumber_hpp
#define RationalNumber_hpp

#include <stdio.h>
#include <string>

using namespace std;

class RationalNumber{

    int numerator;
    int dominator;
    int maxCommonDivisor(int n, int d);
    
public:
    
    // Constructor: reduces or simplifies fractions that are not
    //              in reduced form and avoids negative denominators
    // Precondition: dominator != 0,
    RationalNumber(int n, int d);
    
    // Setters and getters
    void setNumerator(int n);
    void setDominator(int d);
    int getNumerator();
    int getDominator();
    
    // return the rational num in the format of "numerator / dominator"
    string toString();
    
    // Arithmatic operators overload
    RationalNumber operator + (RationalNumber);
    RationalNumber operator - (RationalNumber);
    RationalNumber operator * (RationalNumber);
    RationalNumber operator / (RationalNumber);
    
    // Relational and equality operators overload
    bool operator == (RationalNumber);
    bool operator != (RationalNumber);
    bool operator <= (RationalNumber);
    bool operator >= (RationalNumber);
    bool operator < (RationalNumber);
    bool operator > (RationalNumber);

};

#endif /* RationalNumber_hpp */
