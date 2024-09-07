#include<iostream>

using namespace std;

int main(){
    int total_cents;
    int remaining_cents, num_quarters, num_dimes, num_nickles, num_pennies;

    // ask user for input and stores it
    cout << "Enter the amount of change you would like to split: " << endl;
    cin >> total_cents;

    num_quarters = total_cents/25;
    remaining_cents = total_cents%25; 
    //num cents after finding quarters

    num_dimes = remaining_cents/10;
    remaining_cents%=10; 
    //num cents after finding quarters and dimes

    num_nickles = remaining_cents/5;
    num_pennies = remaining_cents%5;
    //num cents after quarters, dimes, and nickels.

    cout << "Your change is: " << endl;
    cout << "Quarters: " << num_quarters << endl;
    cout << "Dimes: " << num_dimes << endl;
    cout << "Nickles: " << num_nickles << endl;
    cout << "Pennies: " << num_pennies << endl;
    //prints all values

    // Character Practice
    // char temp = 97;
    // temp-= 32;
    // cout << temp;

    return 0;
}
