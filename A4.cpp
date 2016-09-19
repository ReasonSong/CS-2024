//
// CS2024 -- Assignment 4
//
// rs2352 (Ruochen Song), hy483 (Hongshu Ye)  9/18/2016
//
// Exercise 8.9 & 8.12, Deitel & Deitel's "C++ How to Program"
//
//
// For exercise 8.9, we are asked to write a single statement that performs the specified task
// and the pointer statements to each questions are tacked AFTER the game running.
//
// For exercise 8.12, we are asked to create a class race of the tortoise and the hare
// Random number generation is used to implement this story, and use pointers to modify
// the positions of the turtoise and the hare according to the rules for moving animals
// This program will display a 70-position line showing the tortoise's and hare's position,
// and corresponding strings of the game result.
// If neither animal wins, the program will simulate again
//
// Complied by CLion


#include <iostream>
using namespace std;
#include <iomanip>
using std::setw;
#include <random>

// func prototypes
void moveTortoise(int *, int);
void moveHare(int *, int);

int main() {
    cout << "BANG !!!!!\n" << "AND THEY'RE OFF !!!!!\n" << endl;

    // Set initial position of tortoise and hare.
    int tortoise = 1;
    int hare = 1;

    // Using c++11's random header
    std::random_device rd;
    // Random number engine based on Mersenne Twister algorithm
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 10);

    while (tortoise != 70 && hare != 70) {
        int randT = dist(gen);
        moveTortoise(&tortoise, randT);
        int randH = dist(gen);
        moveHare(&hare, randH);

        // Display current race positions
        if (tortoise > hare) {
            cout << setw(hare) << 'H' << setw(tortoise - hare) << 'T';
        } else if (tortoise < hare) {
            cout << setw(tortoise) << 'T' << setw(hare - tortoise) << 'H';
        } else {
            cout << setw(tortoise) << "OUCH!!!";
        }
        cout << '\n';
    }

    // Display winning conditions
    if(tortoise > hare){
        cout << "\nTORTOISE WINS!!! YAY!!!\n";
    } else if (hare > tortoise){
        cout << "\nHare wins. Yuch.\n";
    } else {
        cout << "\nIt's a tie.\n";
        cout << "" << endl;
    }
    
    return 0;
}

// Adjust the position of tortoise according to the rules
// Fast plod   50%    3 squares to the right
// Slip        20%    6 squares to the left
// Slow plod   30%    1 square to the right
void moveTortoise(int *tPtr, int randT) {
    if (randT >= 1 && randT <= 5) { //fast plod, 3 squares to the right
        *tPtr += 3;
    } else if (randT > 5 && randT < 8) { //slip, 6 squares to the left
        *tPtr -= 6;
    } else { //slow plod, 1 square to the right
        *tPtr += 1;
    }

    if (*tPtr < 1) { //make sure tortoise won't be beyond starting gate
        *tPtr = 1;
    }
    if (*tPtr > 70) { //make sure tortoise won't be beyond finishline
        *tPtr = 70;
    }
}

// Adjust the position of hare according to the rules
// Sleep       20%     No move at all
// Big hop     20%     9 squares to the right
// Big slip    10%     12 squares to the left
// Small hop   30%     1 square to the right
// Small slip  20%     2 squares to the left
void moveHare(int *hPtr, int randH) {
    if (randH > 2 && randH < 5) { //big hop, 9 squares to the right
        *hPtr += 9;
    } else if (randH == 5) { //big slip, 12 squares to the left
        *hPtr -= 12;
    } else if (randH > 5 && randH < 9) { //small hop, 1 squares to the right
        *hPtr += 1;
    } else if (randH > 8 && randH < 11) { //small slip, 2 squares to the left
        *hPtr -= 2;
    }

    if (*hPtr < 1) { //make sure hare won't be beyond starting gate
        *hPtr = 1;
    }
    if (*hPtr > 70) { //make sure hare won't be beyond finishline
        *hPtr = 70;
    }
}


/**
 * Exercise 8.9
 * (a) long *longPtr;
 * (b) longPtr = &value1;
 * (c) std::cout << *longPtr << std::endl;
 * (d) value2 = *longPtr;
 * (e) std::cout << value2 << std::endl;
 * (f) std::cout << &value1 << std:;endl;
 * (g) std:;cout << longPtr << std::endl; Yes, the address displayed is the same as value1's.
**/
