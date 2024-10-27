//Problem 3.1a

// #include <iostream>
// #include <string>

// using namespace std;

// void flipSign(int numbers[]){

// for (int i = 0; i < 14; i++){
//     numbers[i] = -1.0 * numbers[i];
//     }

// //removed return statement since void functions cannot return values
// }

// int main(){

//     const int length = 4;
//     int numbers[] = {1, 2, 3, 4};

//     cout << "The contents of the array before changing: ";

//     for (int i = 0; i < length; i++){
//         cout << numbers[i] << " ";
//     }
//     cout << endl;

//     flipSign(numbers);

//     cout << "The contents of the array after changing: ";

//     for (int i = 0; i < length; i++){
//         cout << numbers[i] << " ";
//     }

// return 0;

// }

//Problem 3.1b

// #include <iostream>
// #include <string>
// #include <fstream> //added f stream

// using namespace std;

// int main(){

// ifstream in_file("visitors.txt");
// string full_line;
// string days[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
// int visitors[5] = {0, 0, 0, 0, 0};//changed array to visitors instead of vis to match the rest of the variable calls
// int i = 0;
// int traffic = 0;
// int j = 0;

// while (getline(in_file, full_line)){
//     for(int i = 0; i < static_cast<int>(full_line.length()); i+=1){
//         if(full_line[i] == ' ' && i < static_cast<int>(full_line.length())-1){
//             visitors[i]++;
//         }

//         if(full_line[i] == ','){//changed quotes to single quotes since it is looking for a character
//             visitors[i]++;
//         }
//     }
    
//     if (visitors[i] < traffic){
//         traffic = visitors[i];
//         j = i;
//     }
//     i++;
// }

// cout << days[j] << " is the busiest day of the week at the motel." << endl;

// return 0;

// }

//Problem 3.1c

// #include <iostream>
// #include <string>
// #include <cassert>

// using namespace std;

// int split(string input_string, char separator, string arr[], const int ARR_SIZE){
//     int arrayPosition = 0;
//     string newString;
//     bool presentSeparator = false;
    
//     if(input_string == ""){
//         return 0;
//     }
    
//     for(unsigned int i = 0; i < input_string.length() && arrayPosition < ARR_SIZE; i++){
//         if(input_string[i] != separator){
//             newString += input_string[i];
//         }
//         else if(input_string[i] == separator){
//                 arr[arrayPosition] = newString;
//                 newString = "";
//                 arrayPosition += 1;
//                 presentSeparator = true;
//         }
//     }
    
//     if(newString.length() > 0 && arrayPosition < ARR_SIZE){
//         arr[arrayPosition] = newString;
//     }

//     if(presentSeparator == false){
//         arr[0] = newString;
//         return 1;
//     }

//     else if(presentSeparator == true && arrayPosition >= ARR_SIZE){
//         return -1;
//     }

//     else if(presentSeparator == true){
//         return arrayPosition + 1;
//     }
//     return 0;
// }

// //added split function right before
// string appendPrepend(string message){

//     const int LENGTH = 4;
//     string message_fragments[LENGTH] = {};
//     string empty_word = "";

//     split(message, ' ', message_fragments, LENGTH);//added semicolon and removed the brackets from the array

//     //assert(message_fragments[4] == empty_word);//added semicolon

//     string answer, word;

//     for(int i = 0; i < LENGTH; i++){//removed double =
//         answer += "_" + message_fragments[i]; //removed the second _ and made message as the message fragment array instead
//     }

//     int first_word_length = message_fragments[0].length();
//     int second_word_length = message_fragments[1].length();

//     //assert(message_fragments[1] == answer.substr(first_word_length+3, second_word_length)); //made single equals double equals instead

// return answer;

// }

// int main(){

//     cout << "Please enter the string message:" << endl;
//     string message;

//     getline(cin, message);

//     cout << appendPrepend(message);

// }

//Problem 3.2

#include <iostream>
#include <fstream>
#include <cmath>
#include <sstream>

using namespace std;

int split(string input_string, char separator, string arr[], const int ARR_SIZE){
    int arrayPosition = 0;
    string newString;
    bool presentSeparator = false;
    
    if(input_string == ""){
        return 0;
    }
    
    for(unsigned int i = 0; i < input_string.length() && arrayPosition < ARR_SIZE; i++){
        if(input_string[i] != separator){
            newString += input_string[i];
        }
        else if(input_string[i] == separator){
                arr[arrayPosition] = newString;
                newString = "";
                arrayPosition += 1;
                presentSeparator = true;
        }
    }
    
    if(newString.length() > 0 && arrayPosition < ARR_SIZE){
        arr[arrayPosition] = newString;
    }

    if(presentSeparator == false){
        arr[0] = newString;
        return 1;
    }

    else if(presentSeparator == true && arrayPosition >= ARR_SIZE){
        return -1;
    }

    else if(presentSeparator == true){
        return arrayPosition + 1;
    }
    return 0;
}

bool validateDouble(string input){
    //if the string is empty return false
    if (input.length() == 0){
        return false;
    }

//the string must have at least one numerical digit, but it can also start with a minus sign
//it can have up to one decimal

int numDecimals = 0;
bool seenDigit = false;

//if the string is longer than 1, the first character can be a digit or a minus sign
switch(input[0]){
    case '-':
    break;

    case '.':
        numDecimals++;
    break;

    default:
        if (isdigit(input[0])){
        seenDigit = true;
    }
    else{
        return false;
    }
}

//check if all other digits are valid for index 1 through the end
for (int i = 1; i < (int)input.length(); i++){
    if (input[i] == '.'){ //if the character isn't a number return false
        numDecimals++;
    }
    else if (isdigit(input[i])){
        seenDigit = true;
    }
    else{
        return false;
    }
}
    if (numDecimals > 1){
        return false;
        return seenDigit;
    }
    return 0;
}


int main(){
    //declare variables
    ifstream in_file("coordinates1.txt");
    string line;
    const int size = 3;
    string coords[size];
    double doubCoords[size];
    double totalX, totalY, totalZ;
    double amountX = 0.0, amountY = 0.0, amountZ = 0.0;
    double avgX = 0.0, avgY = 0.0, avgZ = 0.0;

    //check the validate double function
    while(getline(in_file, line)){
        validateDouble(line);
    }

    //if there is an invalid double then return there is an invalid value
    if(validateDouble == 0){
        cout << "Invalid value detected!" << endl;
        return 0;
    }

    //else check each line, split them at the delimeter and add each coordinate depending on position
    else{
        while(getline(in_file, line)){
            split(line, ',', coords, size);
            for(int i = 0; i < size; i++){
                
                if(i == 0){
                    doubCoords[i] = stod(coords[i]);
                    totalX += doubCoords[i];
                    amountX += 1.0;
                }
                if(i == 1){
                    doubCoords[i] = stod(coords[i]);
                    totalY += doubCoords[i];
                    amountY += 1.0;
                }
                if(i == 2){
                    doubCoords[i] = stod(coords[i]);
                    totalZ += doubCoords[i];
                    amountZ += 1.0;
                }

            }
        }
    }

    avgX = totalX/amountX;
    avgY = totalY/amountY;
    avgZ = totalZ/amountZ;

    cout << "The center of mass is at: " << avgX << ", " << avgY << ", " << avgZ << "!" << endl;
}