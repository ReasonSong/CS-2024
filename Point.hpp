//
//  Point.hpp
//  CppEssentialEx

#ifndef Point_hpp
#define Point_hpp

#include <stdio.h>
#include <iostream>
#include <sstream>

using namespace std;

class Point {
    
    int xCoordinate;
    int yCoordinate;
    bool failBit;

public:
    
    // Constructor: Creat a Point object and set the failBit to false.
    Point();
    
    // Getters
    int getX();
    int getY();
    bool getFailBit();
    
    // Setters
    void setX(int x);
    void setY(int y);
    void setFailBit(bool f);
    
    // Overload stream insertion operator
    friend inline ostream &operator << (ostream &, Point &);
    // Overload stream extraction operator
    friend istream &operator >> (istream &, Point &);

};

Point::Point(){
    failBit = false;
}

int Point::getX(){
    return xCoordinate;
}

int Point::getY(){
    return yCoordinate;
}

bool Point::getFailBit(){
    return failBit;
}

void Point::setX(int x){
    xCoordinate = x;
}

void Point::setY(int y){
    yCoordinate = y;
}

void Point::setFailBit(bool f){
    failBit = f;
}

// Insertion
inline ostream &operator << (ostream &os, Point &p){
    if (!p.getFailBit()) os << "(" << p.getX() << "," << p.getY() << ")" << endl;
    return os;
}

// Extraction
istream &operator >> (istream &is, Point &p){
    
    string s; is >> s;
    if(s[0] != '(' && s[s.length() - 1] != ')') {p.setFailBit(true); return is;}
    int i = 1;
    
    // Extract the first integer as X
    while(s[i] - '0' >= 0 && s[i] - '0' <= 9) ++ i;
    if(i == 1 || s[i] != ',') {p.setFailBit(true); return is;}
    stringstream convertX(s.substr(1, i-1));
    int x;
    convertX >> x;
    ++ i;
    
    // Extract the second integer as Y
    int j = i;
    while(s[j] - '0' >= 0 && s[j] - '0' <= 9) ++ j;
    if(j == 1 || s[j] != ')') {p.setFailBit(true); return is;}
    stringstream convertY(s.substr(i, j-i));
    int y;
    convertY >> y;
    
    p.setX(x); p.setY(y);
    
    return is;
}

#endif /* Point_hpp */
