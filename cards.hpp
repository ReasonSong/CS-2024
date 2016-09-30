//
//  cards.hpp

#ifndef cards_hpp
#define cards_hpp

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Card {
    
    int suit;   // suit of the Card, 1 for spades, 2 for hearts, 3 for diamonds, 4 for clubs
    int face;   // face of the Card, 1 for A, 11 for J, 12 for Q, 13 for K
    
    static string suits[4];     // 4 suits of card, spades, hearts, diamonds, clubs
    static string faces[13];    // 13 faces of card, A ~ K

public:
    
    Card();
    Card(int s, int f);
    
    int getSuit();
    int getFace();
    // return the Card as a string in the form of "face of suit"
    string toString();
    
};


class DeckOfCards {

    Card deck[52];      // store 52 Cards
    int currentCard;    // next Card to deal

public :
    
    // Defualt constructor, initialize Cards in the deck
    DeckOfCards();
    // Shuffle the cards in the deck by randomly swap two cards
    void shuffle();
    // return the next Card from the deck
    Card dealCard();
    // return whether there are more Cards to deal
    bool moreCards();
    
};


class Hand {
    
    vector<Card> hand;
    
public:
    
    Hand();
    
    vector<Card> showCards();
    // Determine whether the hand contains a pair
    bool isAPair();
    // Determine whether the hand contains two pairs
    bool isTwoPairs();
    // Determine whether the hand contains three of a kind
    bool isThreeOfAKind();
    // Determine whether the hand contains four of a kind
    bool isFourOfAKind();
    // Determine whether the hand contain a flush
    bool isAFlush();
    // Determine whether the hand contain a straight
    bool isAStraight();
    
};
#endif /* cards_hpp */
