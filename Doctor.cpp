//
//  Doctor.cpp
//  Employee Management
//
//  Created by rui wang on 4/26/21.
//

#include "Doctor.h"
#include<iostream>
#include<string>
#include"Doctor.h"
using namespace std;
Doctor::Doctor(int id,string fname,string lname){
    this->id=id;
    this->firstname=fname;
    this->lastname=lname;
    this->doc=true;
}
void Doctor::showInfo(){
    cout<<"The student's ID: "<<this->id<<endl;
    cout<<"First Name: "<<this->firstname<<endl;
    cout<<"Last Name: "<<this->lastname<<endl;
    cout<<"This student is PhD degree"<<endl;
}
