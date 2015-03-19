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
int *mode(int [],int [],int);

int main(int argc, char** argv) {
    srand(time(0));
    int const size = rand()%50;
    int aRay[size];
    int count = 0;
    while(count < size){
        int i = 0;
        while(i < 10 && count < size){
            aRay[count] = i;
            ++count;
            ++i;
        }
    }
    int bRay[10];
    for(int i = 0; i < 10; ++i){
        bRay[i] = 0;
    }
    outAray(aRay,size);
    sortAray(aRay,size);
    outAray(aRay,size);
    cout << "Mean: " << mean(aRay,size) << endl;
    cout << "Median: " << median(aRay,size) << endl;
    int *c = mode(aRay, bRay,size);
    cout << "# of Modes: " << c[0] << endl;
    cout << "Max Frequency: " << c[1] << endl;
    for(int i = 0; i < c[0]; ++i){
        cout << c[i+2] << " ";
    }
    delete(c);
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
int *mode(int a[], int b[], int size){                             
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