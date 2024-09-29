#include <iostream>

using namespace std;

int main(){

    int xPoint1, xPoint2;
    int yPoint1, yPoint2;

    cout << "What is the leftmost X coordinate of the rectangle? The rightmost?" << endl;
    cin >> xPoint1 >> xPoint2;

    cout << "What is the leftmost Y coordinate of the rectangle? The rightmost?" << endl;
    cin >> yPoint1 >> yPoint2;

    cout << "The points are:" << endl;
        for (int Xcoord = xPoint1; Xcoord <= xPoint2; Xcoord++){
            for (int Ycoord = yPoint1; Ycoord <= yPoint2; Ycoord++){
            cout << "(" << Xcoord << "," << Ycoord << ") ";
        }
        cout << endl;
    }

}