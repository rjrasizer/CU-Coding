#include <iostream>

using namespace std;

int main(){
    // declare variables
    int year;
    int leap_year;
    bool D4, D100, D400;
    // take user input
    cout << "Input a year (4 digits): " << endl;
    cin >> year;

    // boolean values
    D4 = (year%4 == 0);
    D100 = (year%100 == 0);
    D400 = (year%400 == 0);

    // determine if the year is a leap year
    // if(D4 && !(D100 && !D400)){
    //     cout << "" << year << " is a leap year." << endl;
    // }
    // else {
    //     cout << "" << year << " is not a leap year." << endl;
    // }

    if (D4) {
        // might be a leap year
        if (D100 && !D400){
            cout << "The leap year was skipped that year." << endl;
        }
        else {
            cout << "That year is a leap year." << endl;
        }
    }
    else {
        cout << " That year is not a leap year." << endl;
    }
    
    return 0;
}