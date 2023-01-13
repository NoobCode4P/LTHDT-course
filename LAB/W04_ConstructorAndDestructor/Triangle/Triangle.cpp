#include "Triangle.h"

Triangle::Triangle(){
    A.setPoint(0,0);
    B.setPoint(0,1);
    C.setPoint(1,0);
}

Triangle::Triangle(double xA, double yA, double xB, double yB, double xC, double yC){
    A.setPoint(xA,yA);
    B.setPoint(xB,yB);
    C.setPoint(xC,yC);
}

Triangle::Triangle(Point a, Point b, Point c){
    A = a;
    B = b;
    C = c;
}

Triangle::Triangle(string s){
    stringstream read(s);
    string point;
    
    read >> point;
    Point a(point);

    read >> point;
    Point b(point);

    read >> point;
    Point c(point);

    A = a;
    B = b;
    C = c;
}

istream& operator >> (istream& in, Triangle& a){
    cout << "Point A:" << endl;
    in >> a.A;
    cout << "Point B:" << endl;
    in >> a.B;
    cout << "Point C:" << endl;
    in >> a.C;
    return in;
}

ostream& operator << (ostream& out, Triangle& a){
    out << a.A << a.B << a.C;
    return out;
}

Triangle& Triangle::operator = (const Triangle& a){
    A = a.A;
    B = a.B;
    C = a.C;
    return *this;
}

void Triangle::loadFile(string file) {
    ifstream in(file);
    if (!in) {
        cout << "Unable to open " << file << endl;
        return ;
    }
    string t;
    getline(in,t);
    in.close();
    Triangle res(t);
    *this = res;
}

void Triangle::saveFile(string file) {
    ofstream out(file);
    if (!out){
        cout << "Unable to open " << file << endl;
        return;
    }
    out << *this << endl;
    out.close();
}

bool Triangle::isValidTriangle(){
    double AB = A.distanceTo(B);
    double AC = A.distanceTo(C);
    double BC = B.distanceTo(C);
    return (AB + AC > BC && AB + BC > AC && BC + AC > AB);
}

string Triangle::typeOf(){
    double AB = A.distanceTo(B);
    double AC = A.distanceTo(C);
    double BC = B.distanceTo(C);
    
    double epsilon = 0.0001;
    string res = "";

    if (abs(AB*AB + AC*AC - BC*BC) < epsilon || abs(BC*BC + AC*AC - AB*AB) < epsilon || abs(AB*AB + BC*BC - AC*AC) < epsilon)
            res += "Right-angled ";

    if (AB == AC || AB == BC || AC == BC){
        if (AB == AC && AC == BC)
            res += "Equilateral ";
        else 
            res += "Isosceles ";
    }
    else
        res += "Scalene ";
    
    res += "Triangle";
    return res;
}

double Triangle::perimeter(){
    double AB = A.distanceTo(B);
    double AC = A.distanceTo(C);
    double BC = B.distanceTo(C);
    return AB + AC + BC;
}

double Triangle::area(){
    double AB = A.distanceTo(B);
    double AC = A.distanceTo(C);
    double BC = B.distanceTo(C);
    double p = perimeter() / 2;
    return sqrt(p * (p - AB) * (p - AC) * (p - BC));
}
