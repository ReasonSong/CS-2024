//
// CS2024 -- Assignment 5
//
// rs2352 (Ruochen Song), hy483 (Hongshu Ye)  9/30/2016
//
// Exercise 9.23 & 9.24 Deitel & Deitel's "C++ How to Program"
//
// In this assignment, we are asked to create the classes requested in 9.23.
// Then, implement the driver program using the guidelines in 9.24.
//
// 9.24 should be implemented using a class called something like Hand. Hand class would have the five cards (a vector of cards is preferred),
// and then can have public functions that return a bool for the different hand types.
//
// All the classes, Card, DeckOfCards and Hand, are declared in "cards.hpp" and implemented in "card.cpp".
// Tests for 9.24 are written in the main() function.
//
// Compiled by Xcode.
//

#include <iostream>
#include "cards.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    
    Hand h;
    vector<Card> c = h.showCards();
    
    for (int i = 0; i < 5; ++ i) {
        cout << c[i].toString() << endl;
    }
    
    cout << "This hand" << (h.isAPair() ? " contains" : " does not contain") << " a pair." << endl ;
    cout << "This hand" << (h.isTwoPairs() ? " contains" : " does not contain") << " two pairs." << endl ;
    cout << "This hand" << (h.isThreeOfAKind() ? " contains" : " does not contain") << " three of a kind." << endl ;
    cout << "This hand" << (h.isFourOfAKind() ? " contains" : " does not contain") << " four of a kind." << endl ;
    cout << "This hand" << (h.isAFlush() ? " contains" : " does not contain") << " a flush." << endl ;
    cout << "This hand" << (h.isAStraight() ? " contains" : " does not contain") << " a straight." << endl ;

}



