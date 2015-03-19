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
void outAray(int [],int);
void sortAray(int [],int);
float mean(int [],int);
float median(int [],int);
void mode(int [],int [],int);

int main(int argc, char** argv) {
    srand(time(0));
    int aRay[] = {0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3};
    int bRay[10];
    for(int i = 0; i < 10; ++i){
        bRay[i] = 0;
    }
    outAray(aRay,24);
    sortAray(aRay,24);
    outAray(aRay,24);
    cout << "Mean: " << mean(aRay,24) << endl;
    cout << "Median: " << median(aRay,24) << endl;
    outAray(bRay,10);
    mode(aRay,bRay,24);
    return 0;
}
void outAray(int a[], int size){
    for(int i = 0; i < size; ++i){
        cout << a[i] << " ";
    }
    cout << endl;
}
void sortAray(int a[], int size){ 
    for(int i = 0; i < size; ++i){
        for(int j = i+1; j < size; ++j){
            if(a[i] > a[j]){
                swap(a[i],a[j]);
            }
        }
    }
    
}
float mean(int a[],int size){
    int total = 0;
    for(int i = 0; i < size; ++i){
        total += a[i];
    }
    int avg = total/size;
    return avg;
}
float median(int a[],int size){
    if(size%2 == 0){
        int x = size/2;
        int y = size/2 -1;
        float c = (a[x] + a[y])/2;
        return c;
    }
    else{
        int pos = size/2;
        return a[pos]; 
    }
}
void mode(int a[], int b[], int size){                             
    for(int i = 0; i < size; ++i){         //by storing in array
        for(int j = 0; j < 10; ++j){
            if(a[i] == j){
                b[j]++;
                int x = j+1;
                while(a[x] == j){
                    b[j]++;
                    ++x;
                }
            }
        }
    }
    int high = 0;
    int y = 0;
    int *c = new int [y];
    for(int i = 0; i < 10; ++i){
        if(high < b[i]){
            high = b[i];
        }
    }
    for(int i = 0; i < 10; ++i){
        if(b[i] == high){
            c[y] = i;
            ++y;
        }
    }
    for(int i = 0; i < y; ++i){
        cout << c[i] << " ";
    }
}