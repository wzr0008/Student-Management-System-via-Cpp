//
//  main.cpp
//  Employee Management
//
//  Created by rui wong on 4/17/21.
//

#include <iostream>
#include <string>
#include "Employee.h"
#include "Student.h"
#include "Master.h"
#include "Doctor.h"
using namespace std;
int main(int argc, const char * argv[]) {
    Worker worker;
    Student *a;
    a=new Master(123,"rui","wang");
    a->showInfo();
    delete a;
    a=new Doctor(234,"rui","wang");
    a->showInfo();
    delete a;
    int select=0;
    while(true){
        worker.showmenu();
        cout<<"Please input the Number:"<<endl;
        cin>>select;
        switch(select){
        case 0:{
            worker.ExitSystem();
            break;
        }
            case 1:{
                worker.Addperson();
                break;
            }
            case 2:{
                worker.showEmployee();
                break;
            }
            case 3:{
                worker.delEmployee();
                break;
            }
            case 4:{
                worker.ModifyEmployee();
                break;
            }
            case 5:{
                worker.SearchEmployee();
                break;
            }
            case 6:{
                worker.SortEmployee();
                break;
            }
            case 7:{
                worker.clear();
                break;
            }
            default:
                exit(0);
        }
        
    }
    return 0;
}
