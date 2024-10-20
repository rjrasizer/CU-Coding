// Problem 3.1a

// #include <iostream>
// #include <string>
// using namespace std;
// int main()
// {
// int size = 7; //changed size to 7 because the array size was too small
// double scores[size] = {85.4, 90.3, 100.0, 89.0, 74.5, 95.0, 82.3};//changed 100 and 89 to have .0 at the end
// double sum = 0;
// for(int i = 0; i < size; i++)
// {
// sum += scores[i];
// }
// double avg = sum / 7.0; //changed 6.0 to 7 and changed int avg to double avg
// cout << "Average = " << avg << endl;
// return 0;
// }

// Problem 3.1b

// #include <iostream>
// using namespace std;
// // Function to calculate the transpose of a matrix
// void transposeMatrix(int matrix[][3], int n, int m)//changed the function to a void function
// {
//     int temp; //initialize temp as an int beforehand
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i + 1; j < m; j++)
//         {
//             temp = matrix[i][j];
//             matrix[i][j] = matrix[j][i];
//             matrix[j][i] = temp;
//         }
//     }
//     //removed the return value
// }

// int main()
// {
//     const int rows = 3;
//     const int cols = 3;
//     int originalMatrix[rows][cols] =
//     {
//         {1, 1, 1},
//         {2, 2, 2},
//         {3, 3, 3}
//     };

//     // Calculate the transpose matrix using the function
//     transposeMatrix(originalMatrix, rows, cols); //changed the matrix to be just the matrix not matrix[][]

//     // Display the transpose matrix
//     cout << "Transpose Matrix:" << endl;
//     for (int i = 0; i < rows; i++)
//     {
//         for (int j = 0; j < cols; j++)
//         {
//             cout << originalMatrix[i][j] << " ";
//         }
//         cout << endl;
//     }
    
//     return 0;

// }

//Problem 3.1c
// #include <iostream>
// using namespace std;

// int main()
// {
//     int N = 3;
//     string item[] = {"book", "pen", "pencil", "eraser"};//changed variable type to string
// //printing all the items
// for (int i = 0; i < N; i++)
//     {
//     cout << "The item list has " << item[i] << endl;//changed items to item and j to i
//     }

// return 0;

// }

//Problem 3.1d
// #include <iostream>
// #include <string>
// using namespace std;
// int main()
// {
//     const int N = 6;
//     string animals[N] = {"lion", "cat", "bear", "dog", "elephant", "fox"};

//     for (int i = 0; i < N; i++)
//     {
//         int animalLength = animals[i].length(); //defined an integer at each string values length
//         if (animalLength == 4){ //changed the value to the integer that I defined
//             cout << animals[i] << endl;
//         }
// }

// return 0;

// }

// //Problem 3.2

// #include<iostream>

// using namespace std;

// //set a height of 15 as a const int
// //set a length of 40 as a const int

// //create a void function called makeBlank with an empty 2d string array inside called ART
//     //create blank ascii 2d array
//     //create a for loop adding i until reaching the height
//     //create a for loop adding j until reaching the length
//     //add an empty character to the array in that position
        
// void display(string ART[]){//create a void function called display with the same array as before
//     //print the art
//     //make a for loop that prints the array
//         //cout statement of each character

// int main(){
//     string ART[HEIGHT];
//     makeBlank(ART);
//        // **** CODING TELEPHONE STARTS HERE ****

//    //add top of witch hat
// //create a for loop starting at 0 that adds i until reaching the height value * 2/3
//    for (int i = 0; i<HEIGHT*(2/3); i++){
//    for(int j = (LENGTH/2) -i/1.5; i<= LENGTH/2 + i/1.5; j++){
//        ART[i*j];
//    }
//  }

// //add band of witch hat
// for(int i=height*2/3; i<= HEIGHT-3;i++){
//    for(int j = LENGTH/2-i/1.5; j<=LENGTH/2+i/1.5;j++){
//         ART[i][j] = 'o';
//         //set value at the counter positions to 'o'
//    }
//   }

// //add the narrow lines for brim of witch hat
//    for (int j = 3; j < LENGTH-3; j++){ 
//        ART[HEIGHT-3][j] = '*'; //
//        ART[HEIGHT-1][j] = '*';
//    }

// //add full length middle line for brim of witch hat
//    for (int j = 0; j < LENGTH; j++){
//        ART[HEIGHT-2][j] = '*';
//    }

// // **** CODING TELEPHONE ENDS HERE ****

//     display(ART);
//     return 0;
// }

//3.2 Questions
//a. Our final code did not compile and it had multiple errors because there was 
//still comments left over and the variables were changed so it was missing variables

//b. Could not fix it so it still didnt run and it had the same errors

//c. We miscommunicated on where to change the code since we ran out of time
// every time someone had their turn so in the end we had a lot of comments left over
//and also still had some of the loops missing which made it so it failed to compile properly

//Problem 3.3

#include <iostream>

using namespace std;

void matrixSum(int matrix1[2][3], int matrix2[2][3], int newMatrix[2][3]){ //make a void function with 3 different matrix of the same size
    for(int i = 0; i < 2; i++){//create a loop to go through each matrix value and change the newMatrix to those values
        for(int j = 0; j < 3; j++){
            newMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

int main(){
    const int rows = 2; //make the rows and columns the same for every matrix
    const int cols = 3;
    int userMatrix1[rows][cols];
    int userMatrix2[rows][cols];
    int newUserMatrix[rows][cols];

    //Prompt user for their matrix 1 row by row
    cout << "Enter values for matrix 1, one row at a time:" << endl;
    cin >> userMatrix1[0][0] >> userMatrix1[0][1] >> userMatrix1[0][2];
    cin >> userMatrix1[1][0] >> userMatrix1[1][1] >> userMatrix1[1][2];

    //Prompt user for their matrix 2 row by row
    cout << "Enter values for matrix 2, one row at a time:" << endl;
    cin >> userMatrix2[0][0] >> userMatrix2[0][1] >> userMatrix2[0][2];
    cin >> userMatrix2[1][0] >> userMatrix2[1][1] >> userMatrix2[1][2];

    //Run the matrix sum function for the new matrix
    matrixSum(userMatrix1, userMatrix2, newUserMatrix);

    //Print the new matrix row by row
    cout << "The sum is:" << endl;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout << newUserMatrix[i][j] << " ";
        }
        cout << endl;
    }
}