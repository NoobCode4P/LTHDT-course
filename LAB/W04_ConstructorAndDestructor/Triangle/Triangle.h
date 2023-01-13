#include "Point.h"

class Triangle{
    Point A, B, C;
public:
    Triangle();
    Triangle(double xA, double yA, double xB, double yB, double xC, double yC);
    Triangle(Point, Point, Point);
    Triangle(string);

    friend istream& operator >> (istream&, Triangle&);
    friend ostream& operator << (ostream&, Triangle&);
    Triangle& operator = (const Triangle&);

    void loadFile(string file);
    void saveFile(string file);

    bool isValidTriangle();
    string typeOf();
    double perimeter();
    double area();
};