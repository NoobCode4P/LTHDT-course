#include <iostream>
#include <cmath>
using namespace std;

struct Point{
    float x, y;

    void input();
    void output();
    float distanceTo(Point b);
    float distanceTo_Ox();
    float distanceTo_Oy();
};

struct Triangle{
    Point a;
    Point b;
    Point c;

    void input();
    void output();
    bool isValidTriangle();
    void ofType();
    float perimeter();
    float area();
    Point Center();
};