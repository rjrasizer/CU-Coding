#include <iostream>

using namespace std;

int main(){
    // declare variables
    int year;
    int leap_year;
    // take user input
    cout << "Input a year (4 digits): " << endl;
    cin >> year;

    // determine if the year is a leap year
    if( (year%4 == 0 || year%4 == 0 && year%100 == 0 && year%400 == true) ){
        cout << "" << year << " is a leap year" << endl;
        return 0;
        if(year%4 != 0 || (year%4 == 0 && year%100 == 0 && year%400 != true)){
            cout << "" << year << " is not a leap year" << endl;
            return 0;
        }
    }
}