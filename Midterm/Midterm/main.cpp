//Keanuhea Dailey
//April 8th, 2014

//Library includes Here!!!
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
#include "bankstatement.h"
#include "employee.h"

//Global Constants Here!!!

//Function Prototypes Here!!!
void Menu();
int getN();
void def(int);
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();

//Begin Execution Here!!!
int main(int argv,char *argc[]){
    int inN;
    do{
        Menu();
        inN=getN();
        switch(inN){
        case 1:    problem1();break;
        case 2:    problem2();break;
        case 3:    problem3();break;
        case 4:    problem4();break;
        case 5:    problem5();break;
        case 6:    problem6();break;
        default:   def(inN);}
    }while(inN>=1&&inN<=6);
    return 0;//If midterm not perfect, return something other than 1
}

void Menu(){
    cout<<"Menu for the Midterm"<<endl;
    cout<<"Type 1 for problem 1"<<endl;
    cout<<"Type 2 for problem 2"<<endl;
    cout<<"Type 3 for problem 3"<<endl;
    cout<<"Type 4 for problem 4"<<endl;
    cout<<"Type 5 for problem 5"<<endl;
    cout<<"Type 6 for problem 6"<<endl;
    cout<<"Type anything else to exit \n"<<endl;
}

int getN(){
        int inN;
        cin>>inN;
        return inN;
}
void problem1(){
    cin.ignore();
    cout<<"In problem # 1"<<endl<<endl;
    Customer name;
    name.checks = 0;
    name.deposit = 0;
    cout << "Enter account number.\n";
    char *tempAcc = new char[6];
    cin >> tempAcc;
    while(strlen(tempAcc) != 5){
        cout << "Invalid account number. Please enter a valid"
                << "5 digit account number\n";
        cin >> tempAcc;
    }
    name.accNum = atoi(tempAcc);
    cout << "Enter your account balance as of 1st of the month\n";
    cin >> name.balance;
    cout << "Enter withdrawals.(-1 to stop)\n";
    int check = 0;
    while(check != -1){
        cin >> check;
        name.checks+= check;
    }
    cout << "Total withdrawn: $" << name.checks << endl;
    cout << "Enter deposits. (-1 to stop)\n";
    int deposit = 0;
    while(deposit != -1){
        cin >> deposit;
        name.deposit+= deposit;
    }
    cout << "Total deposited: $" << name.deposit << endl;
    if(name.checks > name.balance){
        cout << "Account overdrawn, a charge of $12 has automatically been"
                << "charged to your account\n";
        name.balance-+ 12;
    }
    name.balance -= name.checks;
    name.balance += name.deposit;
    cout << "Your new account balance is: $" << name.balance << endl; 
}

void problem2(){ 
    cout<<"In problem # 2"<<endl<<endl;
    string run;
    int size = 1;
    Employee *aray = new Employee[size];
    float gross = 0;
    do{
        cout << "Enter employee name.\n";
        cin >> aray[size-1].name;
        cout << "Enter hours worked.\n";
        cin >> aray[size-1].hours;
        while(aray[size-1].hours < 0){
            cout << "Invalid input: negative number. Please enter a positive"
                    << "integer.\n";
            cin >> aray[size-1].hours;
        }
        cout << "Enter hourly wage.\n";
        cin >> aray[size-1].pay;
        while(aray[size-1].pay < 0){
            cout << "Invalid input: negative number. Please enter a positive"
                    << "integer.\n";
            cin >> aray[size-1].pay;
        }
        if(aray[size-1].hours < 20){
            gross += (aray[size-1].hours * aray[size-1].pay);
        }
        if(aray[size-1].hours > 20){
            if(aray[size-1].hours > 40){
                gross += aray[size-1].pay*60;
                gross += aray[size-1].pay*3*(aray[size-1].hours - 40);
            }
            else{
                gross += aray[size-1].pay*20;
                gross += aray[size-1].pay*2*(aray[size-1].hours - 20);
            }
        }
        cout << endl << "--------------------------\n";
        cout << "Name: " << aray[size-1].name << endl;
        cout << "Hours worked: " << aray[size-1].hours << endl;
        cout << "Hourly wage: $" << aray[size-1].pay << endl;
        cout << "Enter another employee? (y/n)\n";
        cin >> run;
    }while(tolower(run[0]) == 'y');
    cout << "Total Gross Pay: $" << gross << endl;
}

void problem3(){
        cout<<"In problem # 3"<<endl<<endl;
}

void problem4(){
        cout<<"In problem # 4"<<endl<<endl;
}

void problem5(){
        cout<<"In problem # 5"<<endl<<endl;
}

void problem6(){
        cout<<"In problem # 6"<<endl<<endl;
}

void def(int inN){
        cout<<"You typed "<<inN<<" to exit the program"<<endl;
}

