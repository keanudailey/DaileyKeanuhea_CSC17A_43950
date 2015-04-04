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
int main(int argc, char** argv) {
    int size = 1;
    int *array = new int [size];
    cout << "Enter a sentence\n";
    string sentence;
    getline(cin,sentence);
    cout << sentence;
    
    return 0;
}

