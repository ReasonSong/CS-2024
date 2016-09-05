//
//  Employee.hpp

#ifndef Employee_hpp
#define Employee_hpp

#include <string>

using std::string;

class Employee {

private:
    
    string firstName;
    string lastName;
    int monthlySalary;
    Employee();
    
public:
    
    Employee(string, string, int);
    void setFirstName(string);
    void setLastName(string);
    void setMonthlySalary(int);
    string getFirstName();
    string getLastName();
    int getMonthlySalary();

};



#endif /* Employee_hpp */
