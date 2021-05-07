//
//  Master.h
//  Employee Management
//
//  Created by rui wang on 4/26/21.
//

#ifndef Master_h
#define Master_h
#include<iostream>
#include<string>
#include "Student.h"
using namespace std;
class Master:public Student{
public:
    Master(int id,string fname,string lname);
    virtual void showInfo();
    virtual ~Master(){};
};

#endif /* Master_h */
