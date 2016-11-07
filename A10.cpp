//
// CS2024 -- Assignment 10
//
// rs2352 (Ruochen Song), hy483 (Hongshu Ye)  11/07/2016
//
// Exercise 14.12 Deitel & Deitel's "C++ How to Program"
//
// Standard telephone keypads contain the digits 0 through 9. The numbers 2 through 9
// each have three letters associated with them, as is indicated by the following table:
//
//              2 ABC 3 DEF 4 GHI 5 JKL 6 MNO 7 PQRS 8 TUV 9 WXYZ
//
// Many people find it difficult to memorize phone numbers, so they use the correspondence
// between digits and letters to develop seven-letter words that correspond to their phone numbers.
// For example, a person whose telephone number is 686-2377 might use the correspondence indicated
// in the above table to develop the seven-letter word "NUMBERS". Businesses frequently attempt to
// get telephone numbers that are easy for their clients to remember. If a business can advertise
// a simple word for its customers to dial, then no doubt the business will receive a few more calls.
// Each seven-letter word corresponds to exactly one seven-digit telephone number.
//
// The restaurant wishing to increase its take-home business could surely do so with the number 825-3688
// (i.e., "TAKEOUT"). Each seven-digit phone number corresponds to many separate seven-letter words.
// Unfortunately, most of these represent unrecognizable juxtapositions of letters.
//
// It's possible, however, that the owner of a barber shop would be pleased to know that the shop's
// telephone number, 424-7288, corresponds to 'HAIRCUT'. A veterinarian with the phone number
// 738-2273 would be pleased to know that the number corresponds to 'PETCARE'.
//
// Write a program that, given a seven-digit number, writes to a file every possible seven-letter word
// corresponding to that number. There are 2187 (3 to the seventh power) such words. Avoid phone
// numbers with the digits 0 and 1.
//
// The output file is created in the root directory of the PC running this program.
//
// Compiled by Xcode.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    
    vector<char> static dialTable[8] = {
        {'A', 'B', 'C'},
        {'D', 'E', 'F'},
        {'G', 'H', 'I'},
        {'J', 'K', 'L'},
        {'M', 'N', 'O'},
        {'P', 'Q', 'R', 'S'},
        {'T', 'U', 'V', 'W'},
        {'X', 'Y', 'Z'}
    };
    
    while (1) {
        
        string num;
        cout << endl << "Enter the phone number you want to convert ('q' to exit): " << endl;
        cin >> num;
    
        if (num[0] == 'q') {
            cout << "Program exits." << endl;
            break;
        }
        
        if (num.length() != 7) {
            cout << "Phone number should be a 7-digit number. Please Enter again." << endl;
            continue;
        }
        
        bool valid = true;
        for(int i = 0; i < 7; ++i){
            if (num[i] < '2' || num[i] > '9') {
                cout << "Every digit should be a number between 2 ~ 9. Please Enter again." << endl;
                valid = false;
                break;
            }
        }
        if (!valid) continue;
        
        // Create a output file "output.dat" in the root directory of the current PC
        ofstream output("/output.dat", ios::trunc);
        if(!output.is_open()) {
            cout << "Can't create/open output file. Program exits.";
            break;
        }
        
        for (int d1 = 0; d1 < dialTable[num[0] - '2'].size(); ++d1) {
            string temp1 = "";
            temp1 += dialTable[num[0] - '2'][d1];
            for (int d2 = 0; d2 < dialTable[num[1] - '2'].size(); ++d2) {
                string temp2 = temp1;
                temp2 += dialTable[num[1] - '2'][d2];
                for (int d3 = 0; d3 < dialTable[num[2] - '2'].size(); ++d3) {
                    string temp3 = temp2;
                    temp3 += dialTable[num[2] - '2'][d3];
                    for (int d4 = 0; d4 < dialTable[num[3] - '2'].size(); ++d4) {
                        string temp4 = temp3;
                        temp4 += dialTable[num[3] - '2'][d4];
                        for (int d5 = 0; d5 < dialTable[num[4] - '2'].size(); ++d5) {
                            string temp5 = temp4;
                            temp5 += dialTable[num[4] - '2'][d5];
                            for (int d6 = 0; d6 < dialTable[num[5] - '2'].size(); ++d6) {
                                string temp6 = temp5;
                                temp6 += dialTable[num[5] - '2'][d6];
                                for (int d7 = 0; d7 < dialTable[num[6] - '2'].size(); ++d7) {
                                    string temp7 = temp6;
                                    temp7 += dialTable[num[6] - '2'][d7];
                                    output << temp7 << endl;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}



