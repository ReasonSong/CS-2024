//
//  RationalNumber.cpp

#include "RationalNumber.hpp"
#include <exception>

int RationalNumber:: maxCommonDivisor(int n, int d){
    
    int nPos = n;
    if (n < 0)  nPos = -n;
    
    int min = (nPos <= d ? nPos : d);
    int comDivisor = 1;
    int i = 2;
    
    while (i <= min) {
        if (nPos % i == 0 && d % i == 0) {
            comDivisor *= i;
            break;
        }
        ++ i;
    }
    return  comDivisor == 1 ? 1 : comDivisor * maxCommonDivisor(n/i, d/i);
}

RationalNumber::RationalNumber(int n, int d){
    
    if (d == 0) throw invalid_argument( "Dominator cannot be 0." );
    
    if (d < 0) {
        d = -d;
        n = -n;
    }
    
    int maxComDivisor = maxCommonDivisor(n, d);
    
    numerator = n / maxComDivisor;
    dominator = d / maxComDivisor;
}


void RationalNumber::setNumerator(int n){
    numerator = n;
}

void RationalNumber::setDominator(int d){
    
    if (d == 0) throw invalid_argument( "Dominator cannot be 0." );
    
    if (d < 0) {
        d = -d;
        numerator = -numerator;
    }
    dominator = d;
}

int RationalNumber::getNumerator(){
    return numerator;
}

int RationalNumber::getDominator(){
    return dominator;
}

string RationalNumber::toString(){
    if (dominator == 1) return to_string(numerator);
    return to_string(numerator) + "/" + to_string(dominator);
}


RationalNumber RationalNumber:: operator + (RationalNumber r){
    
    int newNum = numerator * r.getDominator() + dominator * r.getNumerator();
    int newDom = dominator * r.getDominator();
    
    return RationalNumber(newNum, newDom);
}

RationalNumber RationalNumber:: operator - (RationalNumber r){
    
    int newNum = numerator * r.getDominator() - dominator * r.getNumerator();
    int newDom = dominator * r.getDominator();
    
    return RationalNumber(newNum, newDom);
}

RationalNumber RationalNumber:: operator * (RationalNumber r){
    
    int newNum = numerator * r.getNumerator();
    int newDom = dominator * r.getDominator();
    
    return RationalNumber(newNum, newDom);
}

RationalNumber RationalNumber:: operator / (RationalNumber r){
    
    int newNum = numerator * r.getDominator();
    int newDom = dominator * r.getNumerator();
    
    return RationalNumber(newNum, newDom);
}


bool RationalNumber:: operator == (RationalNumber r){
    return numerator * r.getDominator() == dominator * r.getNumerator();
}

bool RationalNumber:: operator != (RationalNumber r){
    return numerator * r.getDominator() != dominator * r.getNumerator();
}

bool RationalNumber:: operator <= (RationalNumber r){
    return numerator * r.getDominator() <= dominator * r.getNumerator();
}

bool RationalNumber:: operator >= (RationalNumber r){
    return numerator * r.getDominator() >= dominator * r.getNumerator();
}

bool RationalNumber:: operator < (RationalNumber r){
    return numerator * r.getDominator() < dominator * r.getNumerator();
}

bool RationalNumber:: operator > (RationalNumber r){
    return numerator * r.getDominator() > dominator * r.getNumerator();
}
