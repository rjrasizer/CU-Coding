#include <iostream>

using namespace std;

int main(){
    int userElements;
    int largestNum;

    cout << "Please enter the size of the array you would like: " << endl;
    cin >> userElements;

    if (userElements <= 0){
        return 0;
    }

    int userArray[userElements];
    for (int i = 0; i < userElements; i++){
        cout << "Provide the next number here: " << endl;
        cin >> userArray[i];
    }
    largestNum = userArray[0];
    for (int i = 0; i < userElements; i++){
        if(userArray[i] > largestNum){
            largestNum = userArray[i];
        }
    }
    cout << "The largest number in your array is " << largestNum << endl;
}