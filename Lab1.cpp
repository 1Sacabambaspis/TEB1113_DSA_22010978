#include <iostream>
#include <string>
using namespace std;

typedef struct{
    string name;
    string email;
    string ID;
}Students;

int main(){
    Students students[5];
    for(int i = 0;i<5;i++){
        cout<<"Student #"<<(i+1)<<endl;
        cout<<"Enter Student Name: "<<endl;getline(cin,students[i].name);
        cout<<"Enter Student Email: "<<endl;getline(cin,students[i].email);
        cout<<"Enter Student ID: "<<endl;cin>> students[i].ID;
    }
    cout<<"List Of Students: \n"<<endl;
    cout << "------------------------------------------------\n";
    for(int i = 0; i<5; i++){
        cout<<"Student #"<<(i+1)<<" : "<<endl;
        cout<<"Student Name: "<<students[i].name<<endl;
        cout<<"Student Email: "<<students[i].email<<endl;
        cout<<"Student ID: "<<students[i].ID<<endl;
        cout<<endl;
    }
}