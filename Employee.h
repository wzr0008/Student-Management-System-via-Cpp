//
//  Employee.h
//  Employee Management
//
//  Created by rui wang on 4/26/21.
//

#ifndef Employee_h
#define Employee_h
#include <stdio.h>
#include <string>
#include "Student.h"
#include <fstream>
#define FILENAME "record.txt"
using namespace std;
class Worker{
public:
    Worker();
    ~Worker();
    void showmenu();
    void ExitSystem();
    void Addperson();
    void save();
    void showEmployee();
    void delEmployee();
    int isExist(int id);
    void ModifyEmployee();
    void SearchEmployee();
    void SortEmployee();
    void clear();
    int start;
    Student **ptr;
    
};

#endif /* Employee_h */
