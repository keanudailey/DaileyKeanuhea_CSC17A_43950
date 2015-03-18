/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on March 11, 2015, 11:14 AM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
float mean(int [],int);
float median(int [],int);
int *mode(int [],int);
void outAray(int [], int);
int main(int argc, char** argv) {
    srand(time(0));
    int size = rand()%50 +1;
    cout << size << endl;
    int aRay[size];
    int count = 0;
    while(count < size){
        int i = 0;
        while(i < 10 && count < size){
            aRay[count] = i;
            ++count;
            ++i;
        }
        ++count;
    }
    outAray(aRay,size);
    return 0;
}
void outAray(int a[], int size){
    for(int i = 0; i < size; ++i){
        cout << a[i] << " ";
    }
    cout << endl;
}
float mean(int a[],int size){
    
}
float median(int a[],int size);
int *mode(int a[],int size);