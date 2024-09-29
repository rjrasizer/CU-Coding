// #include <iostream>
// #include <string>
// #include <cassert>

// using namespace std;

// double getPrice(double area, string color){

// assert(area>=0); double cost = 0.0;

// if (color == "green"){
//     cost = 4; 
//     }

// else if (color == "red"){ 
//     cost = 3; 
//     }

// else if (color == "orange"){
//     cost = 2;
//     }

// else if (color == "blue"){
//     cost = 1;
//     } 
//     return area * cost;
// }
// int main(){

// string color, shape;
// int area_choice;
// double radius;
// double area = 0;

// cout << "Enter the area of the frame: (1) 5x5 (2) 4x6 (3) 8x10" << endl;
// cin >> area_choice;

// assert(area_choice == 1 || area_choice == 2 || area_choice == 3);

// if(area_choice == 1){
//     area = 5*5;
//     }

// else if (area_choice == 2){
//     area = 4*6;
//     }

// else if (area_choice == 3){
//     area = 8*10;
//     }

// cout << "Enter the color of the frame: (green, red, orange, blue): ";
// cin >> color;

// assert(color == "green" || color == "red" || color == "orange" || color == "blue");

// double price = getPrice(area, color);

// cout << "You will receive a "<< color << " color frame with a price of $" << price << ". ";
// cout << "Thank you for your business." << endl;

// return 0;
// }

#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;

/**
@brief Function to determine the volume of a pumpkin-shaped candy using its radii
@param radiusX Radius along the x-axis = 0 < x
@param radiusY Radius along the y-axis = 0 < x
@param radiusZ Radius along the z-axis = 0 < x
@return double - volume of the pumpkin-shaped candy
*/ double calculateVolumeOfPumpkinCandy(double radiusX, double radiusY, double radiusZ) { // Yourcode goes here. 
    //set up equation for the volume and declare it as pumpkinVolume
    double pumpkinVolume = (4.0/3.0)*3.14159*radiusX*radiusY*radiusZ;

    //make parameters in the function for all 3 variables
    if (radiusX < 0.0 || radiusY < 0.0 || radiusZ < 0.0){
        cout << "Please enter valid radius." << endl;
        return 0;
    }
    else{
        return pumpkinVolume;
    }

}

/**
@brief Function to determine the volume of a witch's hat-shaped candy using its base radius and
height
@param radius Base radius of the witch's hat-shaped candy
@param height Height of the witch's hat-shaped candy
@return double - volume of the witch's hat-shaped candy
*/ double calculateVolumeOfWitchHatCandy(double radius, double height) { // Your code goes here.
    //set up equation for the volume and declare it as pumpkinVolume
    double witchVolume = (1.0/3.0)*3.14159*(radius*radius)*height;

    //make parameters in the function for both variables
    if (radius < 0.0 || height < 0.0){
        cout << "Please enter valid radius/height." << endl;
        return 0;
    }
    else{
        return witchVolume;
    }
}

//set up main function
int main(){

//declare variables
int candyChoice;
double radius1, radius2, radius3;
double radiusW, heightW;
double vofPumpkin, vofWitch;

//prompt for which candy they would like to choose from using switch statement
cout << "Which candy would you like to find the area for? (1)Pumpkin (2)Witch" << endl;
cin >> candyChoice;

switch (candyChoice){
    case 1:
        cout << "Please enter your X, Y, and Z radii." << endl;
        cin >> radius1;
        cin >> radius2; 
        cin >> radius3;
        vofPumpkin = calculateVolumeOfPumpkinCandy(radius1, radius2, radius3);

        if (vofPumpkin == 0){
            return 0;
        }
        else{
            cout << "The area of your Pumpkin is " << vofPumpkin << endl;
        }
        return 0;
    break;
    case 2:
        cout << "Please enter your radius and height." << endl;
        cin >> radiusW;
        cin >> heightW;
        vofWitch = calculateVolumeOfWitchHatCandy(radiusW, heightW);

        if (vofWitch == 0){
            return 0;
        }
        else{
            cout << "The area of your Witch Hat is " << vofWitch << endl;
        }
        return 0;
    break;
    default:
        cout << "Please enter valid candy choice." << endl;
        return 0;
        break;
}

}