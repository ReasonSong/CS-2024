//
// CS2024 -- Assignment 2
//
// rs2352 (Ruochen Song), hy483 (Hongshu Ye)  9/2/2016
//
// Exercise 3.16, Deitel & Deitel's "C++ How to Program"
//
//
// For this assignment we are asked to create a class called Employee that
// includes three pieces of information as data members — a first name (type string),
// a last name (type string) and a monthly salary (type int).
// Our class should have a constructor that initializes the three data members.
// We are ask to provide a set and a get function for each data member. If the monthly
// salary is not positive, set it to 0.
//
// Write a test program that demonstrates class Employee’s capabilities.
// Create two Employee objects and display each object’s yearly salary. Then give each
// Employee a 10 percent raise and display each Employee’s yearly salary again.
//
// Compiled by Xcode

#include <iostream>
#include "Employee.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
   
    int salaryA = 1000;
    int salaryB = 2000;
    // Create and initiate two instances of class Employee
    Employee employeeA("Ruochen", "Song", salaryA);
    Employee employeeB("Hongshu", "Ye", salaryB);
    
    cout << "The monthly salary of employee A, " << employeeA.getFirstName() << " " << employeeA.getLastName() << ", is: " << employeeA.getMonthlySalary() << endl;
    cout << "The monthly salary of employee B, " << employeeB.getFirstName() << " " << employeeB.getLastName() << ", is: " << employeeB.getMonthlySalary() << endl;
    
    // Increase the salary
    salaryA *= 1.1;
    salaryB *= 1.1;
    employeeA.setMonthlySalary(salaryA);
    employeeB.setMonthlySalary(salaryB);
    
    cout << "After 10 percent raise of salary..." << endl;
    cout << "The monthly salary of employee A, " << employeeA.getFirstName() << " " << employeeA.getLastName() << ", is: " << employeeA.getMonthlySalary() << endl;
    cout << "The monthly salary of employee B, " << employeeB.getFirstName() << " " << employeeB.getLastName() << ", is: " << employeeB.getMonthlySalary() << endl;
}
