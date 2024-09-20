#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// int main(){
//     char carChoice;
    
//     cout << "Enter the first letter of the company: " << endl;
//     cin >> carChoice;
    
//     switch (carChoice){
//         case 'B':
//             cout << "Automobile manufacturer chosen: BMW" << endl;
//             break;
//         case 'V':
//             cout << "Automobile manufacturer chosen: Volkswagen" << endl;
//             break;
//         case 'H':
//             cout << "Automobile manufacturer chosen: Honda" << endl;
//             break;
//         case 'T':
//             cout << "Automobile manufacturer chosen: Tesla" << endl;
//             break;
//         default:
//             cout << "Automobile manufacturer chosen: Invalid" << endl;
//             break;
//     }
    
    
    
// }

// int main(){
    
//     int categChoice, instrumentChoice;
    
//     cout << "Select a category: (1)Brass (2)Woodwind (3)Percussion" << endl;
//     cin >> categChoice;

//     switch (categChoice){
//         case 1:
//             cout << "Select an instrument: (1)Trumpet (2)Trombone" << endl;
//             cin >> instrumentChoice;
//             switch (instrumentChoice){
//                 case 1:
//                     cout << "Your instrument will be $570." << endl;
//                     break;
//                 case 2:
//                     cout << "Your instrument will be $500." << endl;
//                     break;
//                 default:
//                 cout << "Please enter a valid input." << endl;
//                 break;
//             }
//         break;

//         case 2:
//             cout << "Select an instrument: (1)Flute (2)Saxophone" << endl;
//             cin >> instrumentChoice;
//             switch (instrumentChoice){
//                 case 1:
//                     cout << "Your instrument will be $425." << endl;
//                     break;
//                 case 2:
//                     cout << "Your instrument will be $225." << endl;
//                     break;
//                 default:
//                 cout << "Please enter a valid input." << endl;
//                 break;
//             }
//         break;

//         case 3:
//             cout << "Select an instrument: (1)Snare Drum (2)Cymbals" << endl;
//             cin >> instrumentChoice;
//             switch (instrumentChoice){
//                 case 1:
//                     cout << "Your instrument will be $275." << endl;
//                     break;
//                 case 2:
//                     cout << "Your instrument will be $350." << endl;
//                     break;
//                 default:
//                 cout << "Please enter a valid input." << endl;
//                 break;
//             }
//         break;

//         default:
//             cout << "Please enter a valid input." << endl;
//             break;




//     }
    
    
// }

// int main(){

//     int genre, director, movie;

//     cout << "Select the genre: (1) Animation (2) Adventure" << endl;
//     cin >> genre;

//     switch (genre){
//         case 1:
//             cout << "Select the director: (1) Pete Docter (2) Brad Bird (3) Andrew Stanton" << endl;
//             cin >> director;
//             switch (director){
//                 case 1:
//                     cout << "Select the movie: (1) Monsters, Inc. (2) Inside Out" << endl;
//                     cin >> movie;
//                     switch (movie){
//                         case 1:
//                             cout << "You have reserved the movie: Monsters, Inc." << endl;
//                             break;
//                         case 2:
//                             cout << "You have reserved the movie: Inside Out" << endl;
//                             break;
//                         default:
//                             cout << "Please enter a valid input" << endl;
//                             break;
//                     }
//                 break;

//                 case 2:
//                 cout << "Select the movie: (1) The Incredibles (2) Ratatouille" << endl;
//                     cin >> movie;
//                     switch (movie){
//                         case 1:
//                             cout << "You have reserved the movie: The Incredibles" << endl;
//                             break;
//                         case 2:
//                             cout << "You have reserved the movie: Ratatouille" << endl;
//                             break;
//                         default:
//                             cout << "Please enter a valid input" << endl;
//                             break;
//                     }
//                 break;

//                 case 3:
//                 cout << "Select the movie: (1) Finding Nemo (2) WALL-E" << endl;
//                     cin >> movie;
//                     switch (movie){
//                         case 1:
//                             cout << "You have reserved the movie: Finding Nemo" << endl;
//                             break;
//                         case 2:
//                             cout << "You have reserved the movie: WALL-E" << endl;
//                             break;
//                         default:
//                             cout << "Please enter a valid input" << endl;
//                             break;
//                     }
//                 break;

//                 default:
//                     cout << "Please enter a valid input" << endl;
//                     break;
//             }
//         break;

//         case 2:
//             cout << "Select the director: (1) Steven Spielberg (2) Jon Favreau (3) Robert Zemeckis" << endl;
//             cin >> director;
//             switch (director){
//                 case 1:
//                     cout << "Select the movie: (1) E.T. the Extra-Terrestrial (2) The BFG" << endl;
//                     cin >> movie;
//                     switch (movie){
//                         case 1:
//                             cout << "You have reserved the movie: E.T. the Extra-Terrestrial" << endl;
//                             break;
//                         case 2:
//                             cout << "You have reserved the movie: The BFG" << endl;
//                             break;
//                         default:
//                             cout << "Please enter a valid input" << endl;
//                             break;
//                     }
//                 break;

//                 case 2:
//                 cout << "Select the movie: (1) The Jungle Book (2016) (2) Elf" << endl;
//                     cin >> movie;
//                     switch (movie){
//                         case 1:
//                             cout << "You have reserved the movie: The Jungle Book (2016)" << endl;
//                             break;
//                         case 2:
//                             cout << "You have reserved the movie: Elf" << endl;
//                             break;
//                         default:
//                             cout << "Please enter a valid input" << endl;
//                             break;
//                     }
//                 break;

//                 case 3:
//                 cout << "Select the movie: (1) Back to the Future (2) Who Framed Roger Rabbit" << endl;
//                     cin >> movie;
//                     switch (movie){
//                         case 1:
//                             cout << "You have reserved the movie: Back to the Future" << endl;
//                             break;
//                         case 2:
//                             cout << "You have reserved the movie: Who Framed Roger Rabbit" << endl;
//                             break;
//                         default:
//                             cout << "Please enter a valid input" << endl;
//                             break;
//                     }
//                 break;

//                 default:
//                     cout << "Please enter a valid input" << endl;
//                     break;
//             }
//         break;

//         default:
//             cout << "Please enter a valid input" << endl;
//             break;
//     }


// }

// double calculateRoomArea(double length, double width);

// double calculateRoomArea(double length, double width){
//     if (length <= 0 || width <= 0){
//         cout << "Length or width is invalid. Area cannot be calculated." << endl;
//         return -1;
//     }
//     else {
//         double area = length*width;
//         return area;
//     }
// }

// int main(){

//     double lchoice, wchoice;
//     cout << "Enter the length of the room in ft:" << endl;
//     cin >> lchoice;

//     cout << "Enter the width of the room in ft:" << endl;
//     cin >> wchoice;

//     double area = calculateRoomArea(lchoice, wchoice);
//     if (area > 0){
//     cout << "The area is: " << area << " sq ft." << endl;
//     }
//     else{
//         return 0;
//     }
// }

double calculateSowingTime(double area, char machine_type);

double calculateSowingTime(double area, char machine_type){
    if ((area > 0 && area != 0) && ((machine_type == 'W') || (machine_type == 'X') || (machine_type == 'Y') || (machine_type == 'Z'))){
        return 1;
    }
    else{
        cout << "Area or machine type is invalid. Time cannot be calculated." << endl;
        return 0;
    }
}

int main(){

    double farmArea;
    char sowMachine;

    cout << "Enter area of the farmland in sq ft:" << endl;
    cin >> farmArea;

    cout << "Enter the type of sowing machine to be used:" << endl;
    cin >> sowMachine;

    double time = calculateSowingTime(farmArea, sowMachine);
    if (time == 1){
        switch (sowMachine){
            case 'W':
            time = farmArea/(8.0/12.0);
            cout << "The time taken is: " << time << " minutes." << endl;
            break;

            case 'X':
            time = farmArea/(3.0/10.0);
            cout << "The time taken is: " << time << " minutes." << endl;
            break;

            case 'Y':
            time = farmArea/(2.0/7.0);
            cout << "The time taken is: " << time << " minutes." << endl;
            break;

            case 'Z':
            time = farmArea/(7.0/8.0);
            cout << "The time taken is: " << time << " minutes." << endl;
            break;
        }
    }
    else{
        return 0;
    }
}