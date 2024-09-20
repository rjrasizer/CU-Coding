#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// double volumeEquation(double sideLength){
//     double volume = sideLength*sideLength*sideLength;
//     return volume;
// }

// int main(){

//     int sideLength;

//     cout << "What is the side length of the cube (in inches)?" << endl;
//     cin >> sideLength;

//     if (sideLength < 0){
//         cout << "Please enter valid side length" << endl;
//         return 0;
//     }
    
//     double volume = volumeEquation(sideLength);
//     cout << "The volume of your cube is " << volume << " inches cubed." << endl;

// }
// int main(){
// int try1;
    
//     cout << "Give me a letter" << endl;
//     cin >> try1;

//     cout << "Now actually enter a number";

// int try2;
//     cin >> try2;

//     cout << "You gave me this as a number:" << try2 << endl;

//     return 0;
// }

/*This function should take in a string and check if it is a valid 
birthdate following the MM/DD/YYYY format*/
bool validDate(string input){
    if (input.length() != 10){
        return false;
    }
    if (input.at(2) != '/' || input.at(5) != '/'){
        return false;
    }
    if (!isdigit(input.at(0)) || !isdigit(input.at(1))|| !isdigit(input.at(2)) || !isdigit(input.at(3)) || !isdigit(input.at(4))){//make sure that the month and days are digits
        return false;
    }
    if (!isdigit(input.at(0)) || !isdigit(input.at(1))|| !isdigit(input.at(2)) || !isdigit(input.at(3)) || !isdigit(input.at(4))){//make sure year is made of all digits
        return false;
    }

    if ( 0 >= stoi(input.substr(0,2)) || 12 < stoi(input.substr(0,2))){ //make sure month is between 1 and 12
        return false;
    }
    if ( 0 >= stoi(input.substr(3,2)) || 31 < stoi(input.substr(3,2))){ //make sure day is between 1 and 31
        return false;
    }

    return true;
}