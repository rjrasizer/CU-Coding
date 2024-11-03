// #include <iostream>
// #include <fstream>

// using namespace std;

// int main(){
    
//     ofstream file_out;

//     file_out.open("output.txt");
//     string message = "Hello, World!";

//     file_out << message << endl;

//     file_out.close(); //added a close statement

// return 0;
// }

// #include <iostream>
// #include <fstream>

// using namespace std;

// int main() {

// ofstream file_out;
// file_out.open("output.txt");
// string test_string = "C++ file handling is fun!";

//     file_out << "Writing this sentence to the file" << endl; //removed parenthesis and added insertion op
//     file_out << test_string << endl; //removed parenthesis and added insertion op

//     file_out.close();

// return 0;
// }

// #include <iostream>
// #include <fstream>

// using namespace std;

// int main() {
//     ofstream file_out; //need to initialize the file first
//     file_out.open("log.txt"); //then open the file after

//     string log_message = "This is a log entry.";
//     file_out << log_message << endl;

//     file_out.close();
//     return 0;
// }

#include <iostream>
#include <fstream>

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
    ifstream in_file("coordinates2.txt");
    in_file.open("coordinates2.txt");
    string line;
    const int size = 3;
    string coords[size];
    double doubCoords[size];
    double totalX, totalY, totalZ, amountX = 0.0, amountY = 0.0, amountZ = 0.0, avgX = 0.0, avgY = 0.0, avgZ = 0.0;
    int invalidEntry = 0, validEntry = 0;

    //declare and open files
    ofstream out_file1("error_log.txt");
    out_file1.open("error_log.txt");
    ofstream out_file2("summary.txt");
    out_file2.open("summary.txt");
    ofstream out_file3("correct_cords.txt");
    out_file3.open("correct_cords.txt");

    //check the validate double function
    while(getline(in_file, line)){
        validateDouble(line);
        
        if(validateDouble(line) == 0){
            out_file1 << "Invalid entry:" << line << endl;
            invalidEntry++;
        }
        else{
            out_file3 << line << endl;
            validEntry++;
        }
    }
    
    //close the file since it will be an input file now
    out_file3.close();
    ifstream in_file2("correct_cords.txt");
    in_file2.open("correctcords.txt");
   
    if(invalidEntry == 0){
        out_file2 << "No valid coordinated processed!" << endl;
        
        out_file1.close();
        out_file2.close();
        out_file3.close();
        
        return 0;
    }


    //if there is an invalid double then return there is an invalid value
    // if(validateDouble == 0){
    //     cout << "Invalid value detected!" << endl;
    //     return 0;
    // }

    //else check each line, split them at the delimeter and add each coordinate depending on position
    else{
        while(getline(in_file2, line)){
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

    cout << "Hello" << endl;
    avgX = totalX/amountX;
    avgY = totalY/amountY;
    avgZ = totalZ/amountZ;

    cout << "The center of mass is at: " << avgX << ", " << avgY << ", " << avgZ << "!" << endl;

    out_file2 << "Center of Mass:" << endl;
    out_file2 << "X: " << avgX << endl;
    out_file2 << "Y: " << avgY << endl;
    out_file2 << "Z: " << avgZ << endl;
    out_file2 << endl;
    out_file2 << "Number of valid entries: " << validEntry << endl;

    out_file1.close();
    out_file2.close();

    return 0;
}
