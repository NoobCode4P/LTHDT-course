#include <iostream>
#include <cmath>
using namespace std;

class Point{
    float x, y;

public:
    void input();
    void output();
    float distanceTo(Point);
    float distanceTo_Ox();
    float distanceTo_Oy();

    float getX();
    float getY();
    void setXY(float, float);
};

class Triangle{
    Point a;
    Point b;
    Point c;

public:
    void input();
    void output();
    bool isValidTriangle();
    void ofType();
    float perimeter();
    float area();
    Point Center();
};