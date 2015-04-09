//Keanuhea Dailey
//April 8th, 2014

//Library includes Here!!!
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
#include "bankstatement.h"
#include "employee.h"
#include "statsResult.h"

//Global Constants Here!!!

//Function Prototypes Here!!!
void Menu();
int getN();
void def(int);
void problem1();
void problem2();
float mean(int [],int);
float median(int [],int);
int *mode(int [],int [],int);
void printStat(statsResult *);
statsResult *avgMedMode(int *,int);
void problem3();
void problem4();
void problem5();
void problem6();
void problem7();

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
    delete [] aray;
}
statsResult *avgMedMode(int *aray, int size){
    statsResult *test=new statsResult;  
    test->avg = mean(aray,size);
    test->median = median(aray,size);
    int bray[10];
    for(int i = 0; i < 10; ++i){
        bray[i] = 0;
    }
    test->mode = mode(aray,bray,size);
    test->nModes = test->mode[0];
    test->maxFreq = test->mode[1];
    return test;
}
float mean(int *a,int size){
    float total = 0;
    for(int i = 0; i < size; ++i){
        total += a[i];
    }
    float avg = total/size;
    return avg;
}
float median(int *a,int size){
    if(size%2 == 0){
        int x = size/2;
        int y = size/2 -1;
        float c = (a[x] + a[y])/2.0;
        return c;
    }
    else{
        int pos = size/2;
        return a[pos]; 
    }
}
int *mode(int *a, int b[], int size){                             
    for(int i = 0; i < size; ++i){
        ++b[a[i]];
    }
    int high = -1;
    int mode_cnt = 0;
    for(int i = 0; i < 10; ++i){
        if(high < b[i]){
            high = b[i];
            mode_cnt = 1;
        }
        else if (high == b[i])
        {
            ++mode_cnt;
        }
    }
    
    int *c = new int [mode_cnt + 2];
    int y = 2;
    c[0] = mode_cnt;
    c[1] = high;
    for(int i = 0; i < 10; ++i){
        if(b[i] == high){
            c[y] = i;
            ++y;
        }
    }
    return c;
}
void printStat(statsResult *test){
    cout << "Average: " << test->avg << endl;
    cout << "Median: " << test->median << endl;
    cout << "Mode(s): ";
    for(int i = 0; i < test->mode[0]; ++i){
        cout << test->mode[i+2] << " ";
    }
    cout << endl;
    cout << "Number of Modes: " << test->nModes << endl;
    cout << "Max frequency: " << test->maxFreq << endl;
     
}
void problem3(){
    cout <<"In problem # 3"<<endl<<endl;
    cout << "Enter size of array.\n";
    int size;
    cin >> size;
    int *aray = new int[size];
    cout << "Enter values for array.\n";
    for(int i = 0; i < size; ++i){
        cin >> aray[i];
    }
    printStat(avgMedMode(aray,size));
    delete [] aray; 
}

void problem4(){
    cout<<"In problem # 4"<<endl<<endl;
    cout << "Enter a four digit integer with numbers from 0-7.\n";
    char cData[5];
    cin >> cData;
    int data[4];
    for(int i = 0; i < 4; ++i){
        data[i] = (cData[i] - 48);
        data[i] += 3;
        data[i] %= 8;
    }
    swap(data[0],data[1]);
    swap(data[2],data[3]);
    for(int i = 0; i < 4; ++i){
        cout << data[i] << " ";
    }
    cout << endl << "(Part 2)Enter a four digit integer with numbers from 0-7.\n";
    char cDat[5];
    cin >> cDat;
    int dat[4];
    for(int i = 0; i < 4; ++i){
        dat[i] = (cDat[i] - 43);
        dat[i] %= 8;
    }
    swap(dat[0],dat[1]);
    swap(dat[2],dat[3]);
    for(int i = 0; i < 4; ++i){
        cout << dat[i] << " ";
    }
    cout << endl;
}

void problem5(){
    cout <<"In problem # 5"<<endl<<endl;
    cout << "int:16\n";
    cout << "unsigned int:33\n";
    cout << "short:7\n";
    cout << "unsigned short:8\n";
    cout << "long:16\n";
    cout << "unsigned long:33\n";
    cout << "float:16\n";
    cout << "double:16\n";
}

void problem6(){
    cout<<"In problem # 6"<<endl<<endl;
}

void problem7(){
    cout<<"In problem # 6"<<endl<<endl;
}

void def(int inN){
        cout<<"You typed "<<inN<<" to exit the program"<<endl;
}

