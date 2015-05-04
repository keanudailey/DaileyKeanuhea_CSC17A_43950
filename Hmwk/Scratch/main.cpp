/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on March 25, 2015, 1:27 PM
 */

#include <cstdlib>
#include <iostream>
#include <istream>

using namespace std;
#include "newfile.h"
/*
 * 
 */
unsigned char fact(int size){
    char num = size;
    for(int i = size; i > 1; --i){
        num *= (i-1);
    }
    return num;
}
int main(int argc, char** argv) {
    int num;
    do{
    cout << "Enter a number\n";
    cin >> num;
    cout << fact(num) << endl;        
    }while(num != -1);

    
    return 0;
    
}

