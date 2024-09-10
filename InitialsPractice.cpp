#include <iostream>

using namespace std;

int main(){
    // declare variables
    string name1, name2, name3, name4;

    // ask user for their name(s)
    cout << "Please enter your full name (including middle name(s)). Enter N/A for the remaining names you have left out of 4." << endl;
    cin >> name1 >> name2 >> name3 >> name4;

    // if they have 2 names...
    if (name3 == "N/A"){
        cout << name1.at(0) << ". " << name2 << endl;
    }
    // if they have 3 names...
    else if (name4 == "N/A"){
    cout << name1.at(0) << ". " << name2.at(0) << ". " << name3 << endl;
    }
    // if they have 4 names...
    else{
    cout << name1.at(0) << ". " << name2.at(0) << ". " << name3 << ". " << name3.at(0) << ". " << name4 << endl;
    }

    return 0;
}

