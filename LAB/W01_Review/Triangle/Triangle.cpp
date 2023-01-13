#include "Triangle.h"

void Point::input(){
    float X, Y;
    cout << "x = "; cin >> X;
    cout << "y = "; cin >> Y;
    x = X; 
    y = Y;
}

void Point::output(){
    cout << "(x,y) = " << x << "," << y << endl;
}

float Point::distanceTo(Point b){
    return sqrt(pow(x - b.x, 2) + pow(y - b.y, 2));
}

float Point::distanceTo_Ox(){
    return abs(y);
}

float Point::distanceTo_Oy(){
    return abs(x);
}

//===============================

void Triangle::input(){
    cout << "Point A:" << endl;
    a.input();
    cout << "Point B:" << endl;
    b.input();
    cout << "Point C:" << endl;
    c.input();
}

void Triangle::output(){
    cout << "This triangle is formed by these 3 points:" << endl;
    cout << "A(" << a.x << ", " << a.y << ")" << endl;
    cout << "B(" << b.x << ", " << b.y << ")" << endl;
    cout << "C(" << c.x << ", " << c.y << ")" << endl;
}

bool Triangle::isValidTriangle(){
    float AB = a.distanceTo(b);
    float AC = a.distanceTo(c);
    float BC = b.distanceTo(c);
    return (AB + AC > BC && AB + BC > AC && BC + AC > AB);
}

void Triangle::ofType(){
    float AB = a.distanceTo(b);
    float AC = a.distanceTo(c);
    float BC = b.distanceTo(c);
    
    float epsilon = 0.0001; 

    if (abs(AB*AB + AC*AC - BC*BC) < epsilon || abs(BC*BC + AC*AC - AB*AB) < epsilon || abs(AB*AB + BC*BC - AC*AC) < epsilon)
            cout << "Right-angled ";

    if (AB == AC || AB == BC || AC == BC){
        if (AB == AC && AC == BC)
            cout << "Equilateral ";
        else 
            cout << "Isosceles ";
    }
    else
        cout << "Scalene ";
    
    cout << "Triangle" << endl;
}

float Triangle::perimeter(){
    float AB = a.distanceTo(b);
    float AC = a.distanceTo(c);
    float BC = b.distanceTo(c);
    return AB + AC + BC;
}

float Triangle::area(){
    float AB = a.distanceTo(b);
    float AC = a.distanceTo(c);
    float BC = b.distanceTo(c);
    float p = perimeter() / 2;
    return sqrt(p * (p - AB) * (p - AC) * (p - BC));
}

Point Triangle::Center(){
    Point g;
    g.x = (a.x + b.x + c.x)/3;
    g.y = (a.y + b.y + c.y)/3;
    return g;
}