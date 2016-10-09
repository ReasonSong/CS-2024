//
//  BankAccount.cpp

#include "BankAccount.hpp"
#include <stdexcept>

using namespace std;


// =========================== class Account ===============================
// =========================================================================

Account::Account(double balance){
    if (balance < 0) throw invalid_argument("Error: Balance must be no less than 0.");
    this->balance = balance;
}

double Account::credit(double amount){
    if (amount < 0) return (this->debit(-amount));
    balance += amount;
    return balance;
}

double Account::debit(double amount){
    if (amount > balance) {
        printf("Debit amount exceeded account balance.\n");
    } else balance -= amount;
    return balance;
}

double Account::getBalance(){
    return balance;
}


// ========================= class SavingAccount ===========================
// =========================================================================

SavingAccount::SavingAccount(double balance, double interestRate)
: Account(balance),interestRate(interestRate){}

double SavingAccount::getInterestRate(){
    return interestRate;
}

double SavingAccount::calculteInterest(){
    return balance * interestRate;
}


// ========================= class CheckingAccount =========================
// =========================================================================

CheckingAccount::CheckingAccount(double balance, double transactionFee)
: Account(balance),transactionFee(transactionFee){}

double CheckingAccount::getTransactionFee(){
    return transactionFee;
}

double CheckingAccount::credit(double amount){
    return Account::credit(amount - transactionFee);
}

double CheckingAccount::debit(double amount){
    if (balance != Account::debit(amount)) balance -= transactionFee;
    return balance;
}
