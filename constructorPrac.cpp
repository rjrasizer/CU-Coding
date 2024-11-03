#include <iostream>

using namespace std;

class Quadrilateral{
    private:
        double height, length;
    public:
        Quadrilateral();
        Quadrilateral(double h, double l);
        void setHeight(double h);
        void setLength(double l);
        double getHeight();
        double getLength();
        bool isSquare();
        double getPerimeter();
        double getArea();
};

//constructors
Quadrilateral::Quadrilateral(){
    height = 0;
    length = 0;
}
Quadrilateral::Quadrilateral(double h, double l){
    if(h > 0){
        height = h;
    }
    else{
        height = 0;
    }
    if(l > 0){
        length = l;
    }
    else{
        length = 0;
    }
}

//setters
void Quadrilateral::setHeight(double h){
    if(h > 0){
        height = h;
    }
}

void Quadrilateral::setLength(double l){
    if(l > 0){
        length = l;
    }
}

//getters
double Quadrilateral::getHeight(){
    return height;
}
double Quadrilateral::getLength(){
    return length;
}
bool Quadrilateral::isSquare(){
    return (height == length);
}
double Quadrilateral::getPerimeter(){
    return height*2+length*2;
}
double Quadrilateral::getArea(){
    return height*length;
}
