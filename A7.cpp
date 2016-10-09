//
// CS2024 -- Assignment 7
//
// rs2352 (Ruochen Song), hy483 (Hongshu Ye)  10/8/2016
//
// Exercise 12.10 Deitel & Deitel's "C++ How to Program"
//
// (Account Inheritance Hierarchy) Create an inheritance hierarchy that a bank might use to
// represent customers’ bank accounts. All customers at this bank can deposit (i.e., credit)
// money into their accounts and withdraw (i.e., debit) money from their accounts.
// More specific types of accounts also exist. Savings accounts, for instance, earn interest
// on the money they hold. Checking accounts, on the other hand, charge a fee per transaction.
//
// Class Account, SavingAccount, CheckingAccount are declared and defined in BankAccount.hpp and
// implemented in BankAccount.cpp.
//
// Tests code is written in the main() function.
//
// Compiled by Xcode.
//

#include <iostream>
#include "BankAccount.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    
    // Tests for invalid balance for all constructors
    try { Account a(-7);
    } catch (invalid_argument) {
        cout << "Acount balance cannot be initialized with a negative balance." << endl;
    }
    
    try { SavingAccount s(-7, 0.1);
    } catch (invalid_argument) {
        cout << "Saving account balance cannot be initialized with a negative balance." << endl;
    }
    
    try { CheckingAccount(-7, 5);
    } catch (invalid_argument) {
        cout << "Checking account balance cannot be initialized with a negative balance." << endl << endl;
    }
    
    // Tests for class Account
    cout << "# Tests for class Account #" << endl;
    Account a(7.8);
    cout << "a's balance is: " << a.getBalance() << endl;
    cout << "add 7.5 to a and now the balance is: " << a.credit(7.5) << endl;
    cout << "withdraw 4.1 from a and now the balance is: " << a.debit(4.1) << endl;
    cout << "withdraw 109.3 from a: " << a.debit(109.3) << endl << endl;
    
    // Tests for class SavingAccount
    cout << "# Tests for class SavingAccount #" << endl;
    SavingAccount s(a.getBalance(), 0.1);
    cout << "interest rate of saving account s is: " << s.getInterestRate() << endl;
    cout << "s's balance is: " << s.getBalance() << endl;
    cout << "add interest to s and now the balance is: " << s.credit(s.calculteInterest()) << endl << endl;
    
    // Tests for class CheckingAccount
    cout << "# Tests for class CheckingAccount #" << endl;
    CheckingAccount c(s.getBalance(), 4.5);
    cout << "transaction fee of checking account c is: " << c.getTransactionFee() << endl;
    cout << "c's balance is: " << c.getBalance() << endl;
    cout << "add 7.5 to c with transaction fee and now the balance is: " << c.credit(7.5) << endl;
    cout << "withdraw 4.1 from c with transaction fee and now the balance is: " << c.debit(4.1) << endl;
    cout << "withdraw 4.1 from c with transaction fee and now the balance is: " << c.debit(4.1) << endl;
}



