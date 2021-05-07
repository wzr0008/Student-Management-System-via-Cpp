//
//  Student.h
//  Employee Management
//
//  Created by rui wang on 4/26/21.
//

#ifndef Student_h
#define Student_h
#include <iostream>
using namespace std;
class Student{
public:
    int id;
    string firstname;
    string lastname;
    bool doc;
    virtual void showInfo()=0;
    virtual ~Student(){};
    
};

#endif /* Student_h */
