//
//  Employee.cpp

#include "Employee.hpp"

Employee::Employee(string first, string last, int salary = 0):firstName(first), lastName(last), monthlySalary(salary){}

void Employee::setFirstName(string first){
    firstName = first;
}

void Employee::setLastName(string last){
    lastName = last;
}

void Employee::setMonthlySalary(int salary){
    if(salary < 0) salary = 0;
    monthlySalary = salary;
}

string Employee::getFirstName(){
    return firstName;
}

string Employee::getLastName(){
    return lastName;
}

int Employee::getMonthlySalary(){
    return monthlySalary;
}


