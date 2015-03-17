/* 
 * File:   main.cpp
 * Author: Keanu
 *
 * Created on March 16, 2015, 4:46 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;
const float EURO_PER_DOLLAR = .74;
const float YEN_PER_DOLLAR = 98.93;
void clear();
float celsius(float);
int main(int argc, char** argv) {
    char go;   
    do{
        //Prompt for user input
        cout << "What problem would you like to run?\n";
        cout << "1. 3.12\n2. 3.13\n3. 4.10\n4. 5.11\n5. 6.7\n6. 7.6\n7. 8.7\n";
        int num;
        cin >> num;
        //If user enters 1 for num
        clear();
        if(num == 1){
            cout << "Enter temperature in degrees Celsius\n";
            //Degrees Celsius from user
            float temp;
            cin >> temp;
            //Convert Celsius to Fahrenheit
            float fahren = (9*temp/5) + 32;
            cout << temp << " degrees Celsius is " << fahren << " degrees"
                    << " Fahrenheit\n";
        }
        else if(num == 2){
            cout << "How many dollars (US) do you have?\n";
            float dollars;
            cin >> dollars;
            cout << dollars << " dollars is:\n" << dollars*YEN_PER_DOLLAR
                    << " yen\n" << dollars*EURO_PER_DOLLAR << " euros\n";
        }
        else if(num == 3){
            cout << "Enter a month (1-12): ";
            int month, year;
            cin >> month;
            cout << "\nEnter a year: ";
            cin >> year;
            cout << endl;
            if(month == 2){
                if(year%100 == 0){
                    if(year%400 == 0){
                        cout << "29 Days\n";
                    }
                }
                else if(year%4 == 0){
                    cout << "29 Days\n";
                }
                else{
                    cout << "28 Days\n";
                }
            }
            else if(month == 1 || month == 3 || month == 5 || month == 7
                    || month == 8 || month == 10 || month == 12){
                cout << "31 Days\n";
            }
            else{
                cout << "30 Days\n";
            }     
        }
        else if(num == 4){
            int population = 0, days = 0;
            float increase = -1;
            while(population < 2){
                cout << "Enter initial population (>1)\n";
                cin >> population;
            }
            while(increase < 0){
                cout << "Enter percent daily increase\n";
                cin >> increase;
            }
            while(days < 1){
                cout << "Enter number of days of growth\n";
                cin >> days;
            }
            cout << "There will be " << population*(increase/100)*days
                    << " people\n";
        }
        else if(num == 5){
            cout << "Enter degrees Fahrenheit\n";
            float fahren;
            cin >> fahren;
            cout << celsius(fahren) << " degrees Celsius\n";
            cout << "F :   C\n";
            for(int i = 0; i < 21; ++i){
                cout << i << " : " << celsius(i) << endl;
            }
        }
        else if(num == 7){
            string first, mid, last;
            string firstAray[1];
            string midAray[1];
            string lastAray[1];
            cout << "Enter first name\n";
            cin >> first;
            cout << "Enter middle name\n";
            cin >> mid;
            cout << "Enter last name\n";
            cin >> last;
            firstAray[0] = first;
            midAray[0] = mid;
            lastAray[0] = last;
            string fullAray[1];
            fullAray[0] = lastAray[0] + ", " + firstAray[0] + " " + midAray[0];
            cout << fullAray[0] << endl;
        }
        cout << "Would you like to view another problem?\n(y/n)\n";
        cin >> go;
        clear();
    }while(tolower(go)== 'y');
    return 0;
}
void clear(){
    for(int i = 0; i < 30; ++i){
        cout << endl;
    }
}
float celsius(float temp){
    return (temp-32)*5/9;
}
