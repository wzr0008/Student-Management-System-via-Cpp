
//
//  Employee.cpp
//  Employee Management
//
//  Created by rui wang on 4/26/21.
//
#include<iostream>
#include<fstream>
#include "Employee.h"
#include "Student.h"
#include "Master.h"
#include "Doctor.h"
#define FILENAME "record.txt"
using namespace std;
Worker::Worker(){
    this->start=0;
    this->ptr=NULL;
}
void Worker::showmenu(){
    cout<<"***************************************************************"<<endl;
    cout<<"**** Welcome to use this Teaching Assistant Managerment System ****"<<endl;
    cout<<"***************** 1.Add new Teaching Assistant ***********"<<endl;
    cout<<"***************** 2.Show Teaching Assistant List *********"<<endl;
    cout<<"***************** 3.Delete graduated TA ******************"<<endl;
    cout<<"***************** 4.Modify personal information***********"<<endl;
    cout<<"***************** 5.Search on the List *******************"<<endl;
    cout<<"***************** 6.Sort the List ************************"<<endl;
    cout<<"***************** 7.Empty the List ***********************"<<endl;
    cout<<"***************** 0.Quit *********************************"<<endl;
    cout<<"**********************************************************"<<endl;
}
void Worker::ExitSystem(){
    cout<<"The system is terminated and good bye!";
    exit(0);
}
int Worker::isExist(int id){
    int index=-1;
    for(int i=0;i<this->start;i++){
        if(this->ptr[i]->id==id){
            index=i;
            break;
        }
    }
    return index;
}
void Worker::save(){
    fstream ofs("record.txt",fstream::out);
    ofs<<"nishi ge dashibi";
    for(int i=0;i<this->start;i++){
        ofs<<this->ptr[i]->id<<" "
           <<this->ptr[i]->firstname<<" "
           <<this->ptr[i]->lastname<<" "<<endl;
    }
    cout<<"The doc is created!"<<endl;
    ofs.close();
}
void Worker::Addperson(){
    cout<<"Please input the number of TA you want to input: "<<endl;
    int add=0;
    cin>>add;
    if(add>0){
        int newsize=this->start+add;
        Student ** newSpace=new Student*[newsize];
        if(this->ptr!=NULL){
            for(int i=0;i<this->start;i++)
            newSpace[i]=this->ptr[i];
        }
        for(int i=0;i<add;i++){
            int id;
            string fname;
            string lname;
            cout<<"Please input "<<i+1<<"th student's Id:"<<endl;
            cin>>id;
            cout<<"Please input the first name:"<<endl;
            cin>>fname;
            cout<<"Please input the last name:"<<endl;
            cin>>lname;
            cout<<"Whether the student is PhD or Not."<<endl;
            cout<<"Press Y means the student is a PhD, otherwise press N."<<endl;
            string press;
            Student *cur=NULL;
            cin>>press;
            if(press=="Y"){
                cur=new Doctor(id,fname,lname);
            }
            else
                cur=new Master(id,fname,lname);
            newSpace[this->start+i]=cur;
        }
        delete[] this->ptr;
        this->ptr=newSpace;
        this->start=newsize;
        this->save();
        cout<<"Add students successfully"<<endl;
    }
    else{
        cout<<"Wrong num,please input again:";
    }
}
void Worker::delEmployee(){
    int id=-1;
    cout<<"Please input the ID of student you want to delete:"<<endl;
    cin>>id;
    int index=isExist(id);
    if(index==-1)
        cout<<"There is no students owning this ID!!"<<endl;
    else{
        for(int i=index;i<this->start-1;i++){
            this->ptr[i]=this->ptr[i+1];
            
        }
        this->start--;
        cout<<"Delete successfully!!!!"<<endl;
    }
}
void Worker::showEmployee(){
    if(this->ptr==NULL)
        cout<<"No TA in the List"<<endl;
    else{
        for(int i=0;i<this->start;i++)
        this->ptr[i]->showInfo();
    }
}
void Worker::ModifyEmployee(){
    int newid=0;
    string newfname;
    string newlname;
    int index=-1;
    int id=0;
    cout<<"Please input the ID of the student";
    cin>>id;
    index=isExist(id);
    if(index==-1){
        cout<<"There is no such student in the list"<<endl;
    }
    else{
        cout<<"We find that student"<<endl;
        cout<<"Please input the new ID of the student:"<<endl;
        cin>>newid;
        cout<<"Please input the first name of the student:"<<endl;
        cin>>newfname;
        cout<<"Please input the last name of the student:"<<endl;
        cin>>newlname;
        string s="Y";
        cout<<"Press Y means the student is a PhD, otherwise press N."<<endl;
        cin>>s;
        Student *cur=NULL;
        if(s=="Y")
            cur=new Doctor(newid,newfname,newlname);
        else
            cur=new Master(newid,newfname,newlname);
        this->ptr[index]=cur;
        cout<<"It works!!!!"<<endl;
        this->save();
    }
}
void Worker::SearchEmployee(){
        int index=-1;
        cout<<"Please input the student ID";
        int id=-1;
        cin>>id;
        index=isExist(id);
        if(index!=-1){
            cout<<"ID: "<<this->ptr[index]->id<<endl;
            cout<<"First Name: "<<this->ptr[index]->firstname<<endl;
            cout<<"Last Name: "<<this->ptr[index]->lastname<<endl;
            cout<<"Degree: "<<((this->ptr[index]->doc)?"PhD":"Master")<<endl;
        }
        else{
            cout<<"There is no such student in the list."<<endl;
        }
    }
void Worker::SortEmployee(){
    for(int i=0;i<this->start;i++){
        int min=i;
        for(int j=i+1;j<this->start;j++){
            if(this->ptr[j]->id<this->ptr[min]->id)
                min=j;
        }
        if(min!=i){
            Student *temp=this->ptr[min];
            this->ptr[min]=this->ptr[i];
            this->ptr[i]=temp;
        }
    }
}
void Worker::clear(){
    if(this->start!=0){
        for(int i=0;i<this->start;i++){
            this->ptr[i]=NULL;
        }
        this->start=0;
        delete[] this->ptr;
    }
    cout<<"All clear!!!!!!!!"<<endl;
}
Worker::~Worker(){}
