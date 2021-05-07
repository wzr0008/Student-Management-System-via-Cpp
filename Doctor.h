//
//  Doctor.h
//  Employee Management
//
//  Created by rui wang on 4/26/21.
//

#ifndef Doctor_h
#define Doctor_h
#include<iostream>
#include<string>
#include "Student.h"
class Doctor:public Student{
public:
    Doctor(int id,string fname,string lname);
    virtual void showInfo();
    virtual ~Doctor(){};
};

#endif /* Doctor_h */
