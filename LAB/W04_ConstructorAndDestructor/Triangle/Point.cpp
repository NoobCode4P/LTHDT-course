#include "Point.h"

Point::Point(){
    x = y = 0;
}

Point::Point(double param){
    x = y = param;
}

Point::Point(double X, double Y){
    x = X;
    y = Y;
}

Point::Point(string s){
    string X = s.substr(1,s.find(',') - 1);
    string Y = s.substr(s.find(',') + 1, s.length() - s.find(',') - 2);
    x = stod(X);
    y = stod(Y);
}

void Point::setPoint(double x, double y){
    this->x = x;
    this->y = y;
}

istream& operator >> (istream& in, Point& a){
    double x,y;
    cout << "Nhap x: "; in >> x;
    cout << "Nhap y: "; in >> y;

    a.setPoint(x,y);
    return in;
}

ostream& operator << (ostream& out, Point& a){
    out << "(" << a.x << "," << a.y << ") ";
    return out;
}

void Point::loadPoint(string file) {
    ifstream in(file);
    if (!in) {
        cout << "Unable to open " << file << endl;
       return;
    }

    string point;
    getline(in, point);
    in.close();
    Point res(point);
    *this = res;
}

Point& Point::operator = (const Point& a){
    x = a.x;
    y = a.y;
    return *this;
} 

void Point::savePoint(string file) {
    ofstream out(file);
    if (!out){
        cout << "Unable to open " << file << endl;
        return;
    }
    out << *this;
    out.close();
}

double Point::distanceTo(const Point& b){
    return sqrt(pow(x - b.x, 2) + pow(y - b.y, 2));
}
