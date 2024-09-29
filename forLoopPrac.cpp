#include <iostream>
#include <iomanip>
#include <cassert>

using namespace std;

int main(){
    //declare variables
    string input;
    int numCapitals;

    //ask user for their string
    cout << "What is your string?" << endl;
    getline(cin, input);

    for (int i = 0; i < input.length(); i++)//for each character in the string...
        // if (isupper(input.at(i))){//is it a capital? if so, count up by 1
        //     numCapitals++;
        // }
        if (input.at(i) >= 'A' && input.at(i) <= 'Z'){
            numCapitals++;
        }
    //output result
    cout << "There are " << numCapitals << " captials in that string." << endl;

    return 0;
}