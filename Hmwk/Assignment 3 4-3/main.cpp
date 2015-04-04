/* 
 * File:   main.cpp
 * Author: Keanu
 *
 * Created on April 3, 2015, 2:36 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;
#include "mdata.h"

float length(char *, int);
void movieData(Mdata);
void movieData2(Mdata);
void showSpeaker(Speaker [], int);
void aTof(string, int *, int);
void fToa(string, int *, int);
int main(int argc, char** argv) {
    string run;
    do{
        cout << "Which problem would you like to see?\n1.  10.3  6.  11.9\n"
                << "2.  10.4  7.  12.1\n3.  10.6  8.  12.7\n4.  11.1  9.  12.8\n"
                << "5.  11.2  10. 12.11\n";      
        int probNum = -1;
        cin >> probNum;
        cin.clear();
        cin.ignore();
        if(probNum == 1){
            cout << "Enter a sentence\n";
            char c;
            int size = 1;
            char *a = new char[size];
            while(cin.get(c) && c != '.'){
                a[size-1] = c;
                ++size;
            }
            cout << "Word Count: " << length(a,size) << endl;
        }
        if(probNum == 2){
            cout << "Enter a sentence\n";
            char c;
            int size = 1;
            char *a = new char[size];
            while(cin.get(c) && c != '.'){
                a[size-1] = c;
                ++size;
            }
            cout << "Word Count: " << length(a,size) << endl;       
            cout << "Average Length: " << (size-1-length(a,size))/length(a,size) << endl;
        }
        if(probNum == 3){
            
        }
        if(probNum == 4){
            Mdata movie1, movie2;
            movie1.title = "Grand Budapest Hotel";
            movie1.director = "Wes Anderson";
            movie1.year = 2014;
            movie1.time = 99;
            movie2.title = "Raging Bull";
            movie2.director = "Martin Scorsese";
            movie2.year = 2000;
            movie2.time = 128;
            movieData(movie1);
            cout << endl;
            movieData(movie2);
        }
        if(probNum == 5){
            Mdata movie1, movie2;
            movie1.title = "Grand Budapest Hotel";
            movie1.director = "Wes Anderson";
            movie1.year = 2014;
            movie1.time = 99;
            movie1.cost = 26.7;
            movie1.revenue = 147.9;
            movie2.title = "Raging Bull";
            movie2.director = "Martin Scorsese";
            movie2.year = 2000;
            movie2.time = 128;
            movie2.cost = 18.54;
            movie2.revenue = 5.38;
            movieData2(movie1);
            cout << endl;
            movieData2(movie2);
        }
        if(probNum == 6){
            int run6;
            int num = 2;
            Speaker aRay[10];
            Speaker one,two,three,four,five,six,seven,eight,nine,ten;
            string name;
            int foNum;
            string topic;
            float fee;
            one.name = "Mark";
            one.foNum = 5554897;
            one.topic = "Chewing gum in schools";
            one.fee = 201.79;
            two.name = "Lisa";
            two.foNum = 5551903;
            two.topic = "Cell phones in schools";
            two.fee = 189.13;
            aRay[0] = one;
            aRay[1] = two;
            aRay[2] = three;
            aRay[3] = four;
            aRay[4] = five;
            aRay[5] = six;
            aRay[6] = seven;
            aRay[7] = eight;
            aRay[8] = nine;
            aRay[9] = ten;            
            do{
                cout << "1. Enter new speaker\n2. Edit a speaker\n"
                        << "3. Display speaker info\n4. Exit\n";
                cin >> run6;
                if(run6 == 1){
                    if(num < 10){
                        cout << "Speaker name?\n";
                        cin >> name;
                        cout << "Speaker phone number?\n";
                        cin >> foNum;
                        cout << "Speaker topic?\n";
                        cin >> topic;
                        cout << "Speaker fee?\n";
                        cin >> fee;
                        while(fee < 0){
                            cout << "Error: Please enter a positive number\n";
                            cin >> fee;
                        }
                        aRay[num].name = name;
                        aRay[num].foNum = foNum;
                        aRay[num].topic = topic;
                        aRay[num].fee = fee;
                        ++num;
                    }
                    else{
                        cout << "All speaker positions filled (10), please"
                                << "choose another option\n";
                    }
                }
                if(run6 == 2){
                    int edit = -1;
                    cout << "What position would you like to edit? (1-10)\n";
                    cin >> edit;
                    cout << "What would you like to edit?\n1. Name\n2. "
                            << "Phone Number\n3. Topic\n4. Fee\n";
                    int change = -1;
                    cin >> change;
                    if(change == 1){
                        cout << "Speaker name?\n";
                        cin >> name;
                        aRay[edit].name = name;
                    }
                    if(change == 2){
                       cout << "Speaker phone number?\n";
                        cin >> foNum; 
                        aRay[edit].foNum = foNum;
                    }
                    if(change == 3){
                        cout << "Speaker topic?\n";
                        cin >> topic;
                        aRay[edit].topic = topic;
                    }
                    if(change == 4){
                        cout << "Speaker fee?\n";
                        cin >> fee;
                        aRay[edit].fee = fee;
                    }   
                }
                if(run6 == 3){
                    showSpeaker(aRay,num);
                }
            }while(run6 != 4);
        }
        if(probNum == 7){
            cout << "What file do you want to read?\n";
            string fileName;
            cin >> fileName;
            fstream inFile;
            string word;
            int count = 0;
            inFile.open(fileName.c_str(), ios::in);
            if(inFile){
                getline(inFile,word);
                while(inFile && count < 10){
                    ++count;
                    cout << word << endl;
                    getline(inFile,word);
                }
                if(count < 10){
                    cout << "End of file\n";
                }
            }
            inFile.close();
        }
        if(probNum == 8){
            fstream inFile;
            fstream outFile;
            inFile.open("inside.txt", ios::in);
            outFile.open("outside.txt", ios::out);
            char c;
            bool period = true;
            while(inFile.get(c)){
                if(c == '.'){
                    period = true;
                    outFile.put(c);
                }
                else{
                    if(period){
                        outFile.put(toupper(c));
                        period = false;
                    }
                    else{
                        outFile.put(tolower(c));
                    }
                }
            }
            inFile.close();
            outFile.close();
        }
        if(probNum == 9){
            
        }
        if(probNum == 10){
            Division one, two, three, four;
            one.name = "North";
            one.quarter = 1;
            two.name = "South";
            two.quarter = 1;
            three.name = "East";
            three.quarter = 1;
            four.name = "West";
            four.quarter = 1;
            fstream outFile;
            outFile.open("outside.txt", ios::out);
            cout << "Enter North Division Q1 sales\n";
            int sales;
            cin >> sales;
            one.sales = sales;
            cout << "Enter South Division Q1 sales\n";
            cin >> sales;
            two.sales = sales;
            cout << "Enter East Division Q1 sales\n";
            cin >> sales;
            three.sales = sales;
            cout << "Enter West Division Q1 sales\n";
            cin >> sales;
            four.sales = sales;
            outFile << "Division: " << one.name << "\nQuarter: " << one.quarter
                    << "\nSales: $ " << one.sales << endl;
            outFile << "Division: " << two.name << "\nQuarter: " << two.quarter
                    << "\nSales: $ " << two.sales << endl;
            outFile << "Division: " << three.name << "\nQuarter: " << three.quarter
                    << "\nSales: $ " << three.sales << endl;
            outFile << "Division: " << four.name << "\nQuarter: " << four.quarter
                    << "\nSales: $ " << four.sales << endl;
            outFile.close();
        }
        cout << "Run another program?\n";
        cin >> run;
    }while(tolower(run[0]) == 'y');

    return 0;
}
float length(char *a, int size){
    int inc = 0;
    for(int i = 0; i < size; ++i){
        if(a[i] == ' '){
            ++inc;
        }
    }
    return inc+1;
}
void movieData(Mdata movie){
    cout << "Title:    " << movie.title << "\nDirector: " << movie.director
            << "\nReleased: " << movie.year << "\nLength:   " << movie.time
            << " minutes.\n";
}
void movieData2(Mdata movie){
    cout << "Title:    " << movie.title << "\nDirector: " << movie.director
            << "\nReleased: " << movie.year << "\nLength:   " << movie.time
            << " minutes.\nBudget:   $" << movie.cost << " million\nRevenue:  $"
            << movie.revenue << " million\n";
}
void showSpeaker(Speaker aRay[], int size){
    for(int i = 0; i < size; ++i){
        cout << "Speaker Name: " << aRay[i].name << "\nPhone Number: " 
                << aRay[i].foNum << "\nTopic: " << aRay[i].topic
                << "\nFee: $" << aRay[i].fee << endl << endl;
    }
}
void aTof(string name, int *a, int size){
    fstream outFile;
    outFile.open(name.c_str(), ios::out | ios::binary);
    for(int i = 0; i < size; ++i){
        outFile << a[i];
    }
    outFile.close();
}
void fToa(string name, int *a, int size){
    fstream inFile;
    inFile.open(name.c_str(), ios::in | ios::binary);
    char c;
    while(inFile.get(c)){
        int i = 0;
        a[i] = static_cast<int>(c);
        ++i;
    }
    inFile.close();
}