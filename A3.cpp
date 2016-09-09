//
// CS2024 -- Assignment 3
//
// rs2352 (Ruochen Song), hy483 (Hongshu Ye)  9/8/2016
//
// Exercise 6.38, Deitel & Deitel's "C++ How to Program"
//
//
// For this assignment we are asked to solve the Tower of Hanoi problem using recursion.
//
// a) Move n – 1 disks from peg 1 to peg 2, using peg 3 as a temporary holding area.
// b) Move the last disk (the largest) from peg 1 to peg 3.
// c) Move the n – 1 disks from peg 2 to peg 3, using peg 1 as a temporary holding area.
//
// Solution to the problem is function solveTowerOfHanoi(int, int, int, int) below.
// The solution is tested in the main().
// Compiled by Xcode.

#include <iostream>

using namespace std;

void solveTowerOfHanoi(int diskNum, int initPeg, int finalPeg, int tempPeg);

int main(int argc, const char * argv[]) {
   
    // Test
    solveTowerOfHanoi(8, 1, 3, 2);

}


/* Solution to the Hanoi problem
 */
void solveTowerOfHanoi(int diskNum, int initPeg, int finalPeg, int tempPeg){
    
    if(diskNum > 1){    // If more than one disks left
        
        // Move the n - 1 disks to the temp peg
        solveTowerOfHanoi(diskNum - 1, initPeg, tempPeg, finalPeg);
        
        // Move the last disk from the inti peg to the final peg
        cout << initPeg << " -> " << finalPeg << endl;
        
        // Move the rest n - 1 disks from the temp peg
        solveTowerOfHanoi(diskNum - 1, tempPeg, finalPeg, initPeg);
        
    } else {    //  If only one disk left
        
        // Move it directly to the final peg
        cout << initPeg << " -> " << finalPeg << endl;
        
    }
}







