#include <iostream>

using namespace std;

int main(){

    for (int hour = 1; hour <= 12; hour++){
        for (int minute = 0; minute <= 59; minute++){
            if (minute < 10){
                cout << hour << ":0" << minute << endl;
            }
            else
            cout << hour << ":" << minute << endl;
        }
    }



}