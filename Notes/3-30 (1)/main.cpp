/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on March 30, 2015, 12:57 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;
#include "student.h"
/*
 * seekg(seek get)
 * seekp (seek put)
 * intData.seekg(25L, ios::beg);
 * -set read position at 25 byte from beginning of file
 *  
 */
Student *fillStu(int);
void prntStu(Student *, int);
void writeStu(char *, Student *, int);
Student *readStu(char *, int);

int main(int argc, char** argv) {
    srand(static_cast<unsigned int>(time(0)));
    int nStudents = 36;
    Student *stu = fillStu(nStudents);
    //Write students(binary) to file
    char fn[] = "stud.dat";
    writeStu(fn, stu, nStudents);
    prntStu(stu,nStudents);
    Student *one = readStu(fn,35);
    prntStu(one,1);
    //Deallocate Memory
    delete []stu;
    delete []one;
    return 0;
}
Student *fillStu(int n){
    //Allocate Memory
    Student *csc17a = new Student[n];
    //Fill Records
    for(int rec = 0; rec < n; ++rec){
        csc17a[rec].sid = rand();
        csc17a[rec].score = rand()%30 +70;
        if(csc17a[rec].score > 89)csc17a[rec].grade = 'A';
        else if(csc17a[rec].score > 79) csc17a[rec].grade = 'B';
        else csc17a[rec].grade = 'C';
    }
    return csc17a;
}
void prntStu(Student *a, int n){
    //Output results
    for(int rec = 0; rec < n; ++rec){
        cout << "Student ID = " << a[rec].sid;
        cout << " Score = " << a[rec].score;
        cout << " Grade = " << a[rec].grade << endl;
    }
}
void writeStu(char *fn, Student *a, int n){
    //Open file
    fstream out;
    out.open(fn,ios::out | ios::binary);
    //Write to file
    out.write(reinterpret_cast<char *>(a), sizeof(Student)*n);
    out.close();
}
Student *readStu(char *fn, int rec){
    fstream in;
    in.open(fn, ios::in | ios::binary);
    Student *one;
    in.seekg(rec*sizeof(Student) -1, ios::beg);
    in.read(reinterpret_cast<char *>(one), sizeof(Student)*rec);
    in.close();
}