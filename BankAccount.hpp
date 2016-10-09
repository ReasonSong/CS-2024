//
//  BankAccount.hpp

#ifndef BankAccount_hpp
#define BankAccount_hpp

#include <stdio.h>

class Account {

protected:
    
    double balance;     // current balance

public:
    
    // Constructor: Create an acount and initialize the balance
    // Precondition: Initial balance should be no less than 0.0
    Account(double balance);
    
    // Add an amount to the current balance
    double credit(double amount);
    // Withdraw an amount from the current balance
    // Precondition: Amount does not exceed the balance
    double debit(double amount);
    
    // Return the current balance
    double getBalance();

};

class SavingAccount : public Account {

    double interestRate;    // the interest rate percentage assign to the account

public:
    
    // Constructor: Create a saving account
    //              Initialize the balance and interest rate
    SavingAccount(double balance, double interestRate);
    
    // The getter of interestRate
    double getInterestRate();
    // Return interest could earn
    double calculteInterest();
    
    
};

class CheckingAccount : public Account {

    double transactionFee;  // fee charged per transaction

public:
    
    // Constructor: Create a checking acount
    //              Initialize the balance and transaction fee
    CheckingAccount(double balance, double transactionFee);

    // The getter of transactionFee
    double getTransactionFee();
    
    // Add an amount to the current balance with transaction fee subtracted
    double credit(double amount);
    // Withdraw an amount from the current balance with transaction fee subtracted
    // Precondition: The sum of amount and transaction fee does not exceed the balance
    double debit(double amount);
    
};

#endif /* BankAccount_hpp */
