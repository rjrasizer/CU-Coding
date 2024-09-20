// include cmath, iostream and iomanip
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

// set up main function
int main(){

// identify variables
int userVelocity, finalVelocity;
char fuelType;
int x = 20;

// prompt user
cout << "Enter the initial velocity:" << endl;
cin >> userVelocity;

cout << "Enter the fuel type:" << endl;
cin >> fuelType;

// create if statements for errors
if (userVelocity < 0){
    cout << "Please enter valid velocity." << endl;
}

if (fuelType != 'A' || fuelType != 'B' || fuelType != 'C'){
    cout << "Please enter valid fuel type." << endl;
}
// first if statement is if entered velocity is less than 10
if (userVelocity < 10 && userVelocity >= 0){
	// add case statement for each entered fuel type and use each acceleration based upon that
    switch (fuelType){
        case 'A': 
        finalVelocity = userVelocity + (5*x);
        cout << "The final velocity is " << finalVelocity << " m/s." << endl;
        break;
        case 'B':
        finalVelocity = userVelocity + (10*x);
        cout << "The final velocity is " << finalVelocity << " m/s." << endl;
        break;
        case 'C':
        finalVelocity = userVelocity + (20*x);
        cout << "The final velocity is " << finalVelocity << " m/s." << endl;
        break;
    }
}

// second if statement is if entered velocity is between 10 and 40
if (userVelocity >= 10 && userVelocity <= 40){
	// add case statement for each entered fuel type and use each acceleration based upon that
    switch (fuelType){
        case 'A': 
        finalVelocity = userVelocity + (6*x);
        cout << "The final velocity is " << finalVelocity << " m/s." << endl;
        break;
        case 'B':
        finalVelocity = userVelocity + (12*x);
        cout << "The final velocity is " << finalVelocity << " m/s." << endl;
        break;
        case 'C':
        finalVelocity = userVelocity + (24*x);
        cout << "The final velocity is " << finalVelocity << " m/s." << endl;
        break;
    }
}
	

// third if statement is if entered velocity is greater than 40
if (userVelocity > 40){
	// add case statement for each entered fuel type and use each acceleration based upon that
    switch (fuelType){
        case 'A': 
        finalVelocity = userVelocity + (3*x);
        cout << "The final velocity is " << finalVelocity << " m/s." << endl;
        break;
        case 'B':
        finalVelocity = userVelocity + (6*x);
        cout << "The final velocity is " << finalVelocity << " m/s." << endl;
        break;
        case 'C':
        finalVelocity = userVelocity + (9*x);
        cout << "The final velocity is " << finalVelocity << " m/s." << endl;
        break;
    }
}

return 0;

}