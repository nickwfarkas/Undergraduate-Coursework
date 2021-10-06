//
//  Employee.hpp
//  Inventory_Management_System
//
//  Created by Nicholas Farkas
//  Copyright © 2020 Nicholas Farkas. All rights reserved.
//

#ifndef Employee_hpp
#define Employee_hpp

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class Employee
{
protected:
    int _employeeID;
    string _employeeName;
public:
    Employee(int, string);
    Employee();
    void setEmployeeID(int);
    void setEmployeeName(string);
    int getEmployeeID();
    string getEmployeeName();
};

#endif /* Employee_hpp */
