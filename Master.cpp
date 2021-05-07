//
//  Master.cpp
//  Employee Management
//
//  Created by rui wang on 4/26/21.
//

#include "Master.h"
#include<iostream>
using namespace std;
Master::Master(int id,string fname,string lname){
    this->id=id;
    this->firstname=fname;
    this->lastname=lname;
    this->doc=false;
}
void Master::showInfo(){
    cout<<"The student's ID: "<<this->id<<endl;
    cout<<"First Name: "<<this->firstname<<endl;
    cout<<"Last Name: "<<this->lastname<<endl;
    cout<<"This student is Master degree"<<endl;
}
