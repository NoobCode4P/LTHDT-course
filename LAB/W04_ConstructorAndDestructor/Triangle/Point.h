#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
using namespace std;

class Point{
    double x,y;
public:
    Point();
    Point(double param);
    Point(double x, double y);
    Point(string);

    void setPoint(double x, double y);
    
    friend istream& operator >> (istream&, Point&);
    friend ostream& operator << (ostream&, Point&);
    Point& operator = (const Point&);

    void loadPoint(string file);
    void savePoint(string file);

    double distanceTo(const Point&);

};