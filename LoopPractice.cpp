#include <iostream>
#include <cmath>

using namespace std;

// int addInts(int num, int num2){
//     int result = num + num2;
//     return num;
// }

// int main(){
// double userNum;
// double userNum2;
// do{
//         cout << "Enter a number to add:" << endl;
//         cin >> userNum;
// }while (userNum >= 0);

// cout << "The sum of your numbers is " << 

// }

// int main(){
//     //create variables
//     int total = 0, input = 0;

//     //print prompt
//     cout << "Enter numbers to sum together, and enter a negative number to stop." << endl;
//     //get initial value
//     cin >> input;

//     while (input >=0){//while out value is greater than or equal to 0...
//         //add it to our total
//         total += input;
//         //get a new number (value)
//         cin >> input;

//     }
//     //print our result
//     cout << "The total value is: " << total << endl;

//     return 0;
// }

//function version
int summationDoWhile();
int summationDoWhile(){
    int total = 0, input = 0;

    do {
        cout << "Enter a value to add, or a negative number to stop:" << endl;
        cin >> input;

        if (input >= 0){
            total += input;
        }

    }while (input >= 0);

    return total;
}

int main(){
    //create variables
    int result = summationDoWhile();

    cout << "The total is: " << result << endl;

}

