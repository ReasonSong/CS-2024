//
//  cards.cpp

#include "cards.hpp"
#include <random>

using namespace std;


// =========================== class Card ===============================
// ======================================================================

// faces & suits initialization
string Card::suits[] = {"spades", "hearts", "diamonds", "clubs"};
string Card::faces[] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

Card::Card(){};
Card::Card(int s, int f):suit(s),face(f){};

int Card::getSuit(){
    return suit;
}

int Card::getFace(){
    return face;
}

string Card::toString(){
    return faces[face-1] + " of " + suits[suit-1];
}



// ========================== class DeckOfCard ==========================
// ======================================================================

DeckOfCards::DeckOfCards(){
    
    // Initialize the Cards in the dect
    for (int s = 1; s <= 4; ++s) {
        for (int f = 1; f <= 13; ++f) {
            deck[(s - 1) * 13 + f - 1] = Card(s, f);
        }
    }
    
    currentCard = 0;
}

void DeckOfCards::shuffle(){

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 51);
    
    int i = 0;
    while (i < 52) {
        int randC = dist(gen);
        swap(deck[i], deck[randC]);
        ++ i;
    }
}

Card DeckOfCards::dealCard(){
    ++ currentCard;
    return deck[currentCard-1];
}

bool DeckOfCards::moreCards(){
    return currentCard < 52;
}



// =========================== class Hand ===============================
// ======================================================================

Hand::Hand(){

    // Create a deck of cards and shuffle it
    DeckOfCards D;
    D.shuffle();
    
    // Deal a five-card poker hand
    for (int i = 0; i < 5; ++ i) {
        hand.push_back(D.dealCard());
    }
}


vector<Card> Hand::showCards(){
    return hand;
}

bool Hand::isAPair(){
    int faceTable[14] = {0};
    for (int i = 0; i < 5; ++ i) {
        ++ faceTable[hand[i].getFace()];
        if (faceTable[hand[i].getFace()] > 1) return true;
    }
    return false;
};

bool Hand::isTwoPairs(){
    int pairCount = 0;
    int faceTable[14] = {0};
    for (int i = 0; i < 5; ++ i) {
        ++ faceTable[hand[i].getFace()];
        if (faceTable[hand[i].getFace()] == 2 || faceTable[hand[i].getFace()] == 4)
            ++pairCount;
        if (pairCount == 2) return true;
    }
    return false;
};

bool Hand::isThreeOfAKind(){
    int faceTable[14] = {0};
    for (int i = 0; i < 5; ++ i) {
        ++ faceTable[hand[i].getFace()];
        if (faceTable[hand[i].getFace()] == 3) return true;
    }
    return false;
};

bool Hand::isFourOfAKind(){
    int faceTable[14] = {0};
    for (int i = 0; i < 5; ++ i) {
        ++ faceTable[hand[i].getFace()];
        if (faceTable[hand[i].getFace()] == 4) return true;
    }
    return false;
};

bool Hand::isAFlush(){
    
    for (int i = 0; i < 4; ++ i){
        if (hand[i].getSuit() != hand[i+1].getSuit()) return false;
    }
    return true;
};

bool Hand::isAStraight(){
    int table[5]= {0};
    for (int i = 0; i < 5; ++i) {
        table[i] = hand[i].getFace();
    }
    sort(table, table+5);
    for (int i = 0; i < 4; ++i) {
        if (table[i+1] - table[i] != 1){
            return false;
        }
    }
    return true;
};