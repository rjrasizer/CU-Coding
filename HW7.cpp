#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void listNationalParks(string filename){
    // initialize variables
    ifstream file_in(filename); // opens a file
    if (file_in.fail()){
        cout << "Failed to open file." << endl;
        return;
    }

    const int MAX_SIZE = 63;
    string parks[MAX_SIZE];
    string park;
    int idx = 0;

    // Fill in the blank below with code to read from the file into the 'park' variable
    while(getline(file_in, park)){
        parks[idx] = park;
        idx += 1;

// Fill in the blank below with code to check if you are trying to store more values
// than possible in the parks array

    if(idx > MAX_SIZE){
        break;
    }
    }

    for (int i = 0; i < idx; ++i){
        cout << i << ": " << parks[i] << endl;
    }

    file_in.close();
}

void compareAttendanceSheet(string first_attendance_file, string second_attendance_file){
    ifstream in_file1(first_attendance_file);

    ifstream in_file2(second_attendance_file);

    string line1, line2;
    const int size = 30;
    string array1[size], array2[size], missingArray[size];
    int idx1 = 0, idx2 = 0, idx3 = 0;
    bool allStudents = true;


    if(!in_file1.is_open() || !in_file2.is_open()){
        cout << "Failed to open attendance files" << endl;
        return;
    }

    while(getline(in_file1, line1) && idx1 < 30){
        array1[idx1] = line1;
        idx1++;
    }

    while(getline(in_file2, line2) && idx2 < 30){
        array2[idx2] = line2;
        idx2++;
    }

    for(int i = 0; i < idx1; i++){
        bool missing = true;
        for(int j = 0; j < idx2; j++){
            if(array1[i] == array2[j]){
                missing = false;
            }
        }
        if(missing == true){
            missingArray[idx3] = array1[i];
            idx3++;
            allStudents = false;
        }
    }

    if(allStudents == true){
        cout << "Every student has boarded the bus. It's time to leave." << endl;
    }
    else if(allStudents == false){
        cout << "Students yet to board the bus are" << endl;
        for(int i = 0; i < idx3; i++){
            cout << missingArray[i] << endl;
        }
    }
}

//for question 3
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

void printHikeStats(string file_name){
    ifstream in_file(file_name);
    const int size = 20;
    string line, hikeTrail;
    string hikeArray[size], nameArray[size];
    int lengthArray[size], gainArray[size];
    int arrayPos = 0, arraySize = 0;
    int longestHike = 0, shortestHike = 0;
    double steepestHike = 0;

    if(in_file.is_open() == false){
        cout << "Could not open file." << endl;
        return;
    }

    while(getline(in_file, line)){
        hikeTrail = line;
        if(hikeTrail == ""){
            continue;
        }
        else{
            split(hikeTrail, '|', hikeArray, size);
            nameArray[arrayPos] = hikeArray[0];
            lengthArray[arrayPos] = stoi(hikeArray[1]);
            gainArray[arrayPos] = stoi(hikeArray[2]);
            hikeTrail = "";
            arrayPos++;
            arraySize++;
        }
    }

    //Prints out total lines
    cout << "Number of lines read: " << arrayPos << "." << endl;

    //check for longest hike
    for(int i = 0; i < arraySize; i++){
        int currentHike = lengthArray[i];
        if(currentHike > longestHike){
            longestHike = currentHike;
            arrayPos = i;
        }
    }

    //Print longest hike
    cout << "Longest hike: " << nameArray[arrayPos] << " at " << longestHike << " miles." << endl;
    
    //make a starter value for shortest hike
    shortestHike = longestHike;

    //check for shortest hike
    for(int i = 0; i < arraySize; i++){
        int currentHike = lengthArray[i];
        if(currentHike < shortestHike){
            shortestHike = currentHike;
            arrayPos = i;
        }
    }

    //Print shortest hike
    cout << "Shortest hike: " << nameArray[arrayPos] << " at " << shortestHike << " miles." << endl;

    //check for steepest hike
    for(int i = 0; i < arraySize; i++){
        double elevation = gainArray[i];
        double length = lengthArray[i];
        double currentHike = elevation/length;
        if(currentHike > steepestHike){
            steepestHike = currentHike;
            arrayPos = i;
        }
    }

    //Print steepest hike
    cout << "Steepest hike: " << nameArray[arrayPos] << " at " << setprecision(1) << fixed << steepestHike << " feet gained per mile." << endl;
}

    //using to check the array contents
    // for(int i = 0; i < arraySize; i++){
    //     cout << nameArray[i] << endl;
    // }
    // for(int i = 0; i < arraySize; i++){
    //     cout << lengthArray[i] << endl;
    // }
    // cout << "Elevation" << endl;
    // for(int i = 0; i < arraySize; i++){
    //     cout << gainArray[i] << endl;
    // }

struct Restaurant{
    string name;
    int food_quality;
    int cleanliness;
    int wait_time;
    double overall;
};

double getOverallRating(Restaurant place){
    
    double rating1, rating2, rating3;
    
    if((place.food_quality < 0 || place.food_quality > 10) || (place.cleanliness < 0 || place.cleanliness > 10) || (place.wait_time < 0 || place.wait_time > 5)){
        return -1;
    }

    else{
        rating1 = place.food_quality*.5;
        rating2 = place.cleanliness*.3;
        rating3 = place.wait_time*.2;

        double total = rating1 + rating2 + rating3;

        place.overall = total;

        return place.overall;
    }
}

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

int readRestaurantDetails(string filename, Restaurant restaurant[], const int MAX_RESTAURANTS){
    ifstream in_file(filename);
    const int size = 50;
    string line;
    int idx = 0;

    //checks if the file opened properly
    if(!in_file.is_open()){
        return -1;
    }

    else{
        //check each line
        while(getline(in_file, line) && idx < MAX_RESTAURANTS){
            //make a new array every time that a new line is checked
            string mainArray[size];
            //run the split function with parts added to check if the restaurant has a proper entry
            int parts = split(line, '~', mainArray, size);
            
            //if the amount of parts is incorrect skip the line
            if(parts != 4){
                continue;
            }
           
            //set each part of the restaurant struct array to the lines array
            else{
                restaurant[idx].name = mainArray[0];
                restaurant[idx].food_quality = stoi(mainArray[1]);
                restaurant[idx].cleanliness = stoi(mainArray[2]);
                restaurant[idx].wait_time = stoi(mainArray[3]);
                restaurant[idx].overall = getOverallRating(restaurant[idx]);
                idx++;
            }
        }
    }

    //close the file and return the amount of restaurants checked
    in_file.close();
    return idx;
}

int getBest(Restaurant restaurants[], int arr_size, string metric){
    double bestScore = 0;
    int idx = 0;
    if(metric == "Food Quality"){
        for(int j = 0; j < arr_size; j++){
            if(restaurants[j].food_quality > bestScore){
                bestScore = restaurants[j].food_quality;
                idx = j;
                }
        }
        return idx;
    }

    else if(metric == "Cleanliness"){
        for(int j = 0; j < arr_size; j++){
            if(restaurants[j].cleanliness > bestScore){
                bestScore = restaurants[j].cleanliness;
                idx = j;
                }
        }
        return idx;
    }
    else if(metric == "Wait Time"){
        for(int j = 0; j < arr_size; j++){
            if(restaurants[j].wait_time > bestScore){
                bestScore = restaurants[j].wait_time;
                idx = j;
                }
        }
        return idx;
    }
    else if(metric == "Overall"){
        for(int j = 0; j < arr_size; j++){
            if(restaurants[j].overall > bestScore){
                bestScore = restaurants[j].overall;
                idx = j;
                }
        }
        return idx;
    }
    else{
        return -1;
    }
}

int main(){
    // string filename;
    // cout << "Enter national parks filename" << endl;
    // cin >> filename;
    // listNationalParks(filename);

    // compareAttendanceSheet("example_1.txt", "example_2.txt");
    
    //printHikeStats("long_hikes.txt");

    // Restaurant r;
    // r.name = "McDonalds";
    // r.food_quality = 4;
    // r.cleanliness = 7;
    // r.wait_time = 5;
    // r.overall = getOverallRating(r);
    // if (r.overall == -1){
    //     cout << "Invalid rating(s) entered." << endl;
    // }
    // else{
    //     cout << "Restaurant: " << r.name << " Overall: " << r.overall << endl;
    // }

//     Restaurant restaurants[30];
//     int res_size =
//         readRestaurantDetails("restaurants_3.txt", restaurants, 30);

//     // Checking if the file was opened correctly
//     if (res_size == -1)
//     {
//         cout << "Failed to open file." << endl;
//     }
//     else
//     {
//         for (int i = 0; i < res_size; ++i)
//         {
//             cout << "Restaurant: " << restaurants[i].name << " ";
//             cout << "Ratings: ";
//             cout << restaurants[i].food_quality << " ";
//             cout << restaurants[i].cleanliness << " ";
//             cout << restaurants[i].wait_time << " ";
//             cout << "Overall: ";
//             cout << restaurants[i].overall << " ";
//             cout << endl;
//         }
//     }

// return 0;

    Restaurant restaurants[30];
    int arr_size =
        readRestaurantDetails("restaurants_1.txt", restaurants, 30);

    // Checking if the file was opened correctly
    if (arr_size == -1){
        cout << "Failed to open file." << endl;
    }
    else if (arr_size == 0){
        cout << "Empty file." << endl;
    }
    else{
        int idx = getBest(restaurants, arr_size, "Courteousness");
            if (idx == -1){
            cout << "Invalid metric." << endl;
            }
            else{
            cout << "Restaurant: " << restaurants[idx].name << " ";
            cout << "Ratings: ";
            cout << restaurants[idx].food_quality << " ";
            cout << restaurants[idx].cleanliness << " ";
            cout << restaurants[idx].wait_time << " ";
            cout << "Overall: ";
            cout << restaurants[idx].overall << " ";
            cout << endl;
            }
    }
    return 0;
}