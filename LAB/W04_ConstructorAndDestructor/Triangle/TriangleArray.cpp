#include "TriangleArray.h"

TriangleArray::TriangleArray(){
    array = NULL;
    size = 0;
}

TriangleArray::TriangleArray(int n){
    size = n;
    array = new Triangle[size];
    Triangle tmp;
    for (int i = 0; i < size; i++)
        array[i] = tmp;
    
}

TriangleArray::TriangleArray(Triangle a[], int n){
    size = n;
    array = new Triangle[size];
    for (int i = 0; i < size; i++)
        array[i] = a[i];
}

TriangleArray::TriangleArray(vector <Triangle> a){
    size = a.size();
    array = new Triangle[size];
    for (int i = 0; i < size; i++)
        array[i] = a[i];
}

TriangleArray::TriangleArray(string s){
    stringstream read(s);
    string triangle;
    vector <string> T;
    while (!read.eof()){
        read.ignore();     //ignore [
        getline(read,triangle,']' );
        read.ignore();     //ignore ;

        T.push_back(triangle);
    }
    size = T.size();
    array = new Triangle [size];
    for (int i = 0; i < T.size(); i++){
        Triangle tmp(T[i]);
        array[i] = tmp;
    }
}

TriangleArray::~TriangleArray(){
    delete [] array;
    size = 0;
}

istream& operator >> (istream& in, TriangleArray& a){
    int n;
    cout << "Nhap so luong: "; in >> n;
    Triangle *tmp = new Triangle[n];
    for (int i = 0; i < n; i++){
        in >> tmp[i];
    }
    
    a.size = n;
    a.array = new Triangle [a.size];
    for (int i = 0; i < n; i++)
        a.array[i] = tmp[i];
    return in;
}

ostream& operator << (ostream& out, const TriangleArray& a){
    for (int i = 0; i < a.size; i++)
        if (a.array[i].isValidTriangle())
            out << "[" << a.array[i] << "]" << ((i == a.size - 1) ? '\n' : ';');
    return out;
}

TriangleArray& TriangleArray::operator = (const TriangleArray& a){
    this->size = a.size;
    this->array = new Triangle [a.size];
    for (int i = 0; i < size; i++)
        array[i] = a.array[i];
    return *this;
}

void TriangleArray::loadArray(string file) {
    ifstream in(file);
    if (!in){
        cout << "Unable to open " << file << endl;
        return;
    }
    string a;
    getline(in, a);
    in.close();
    TriangleArray tmp(a);
    *this = tmp;
}

void TriangleArray::saveArray(string file){
    ofstream out(file);
    if (!out){
        cout << "Unable to open " << file << endl;
        return;
    }
    out << *this;
    out.close();
}

void TriangleArray::invalidTriangle(){
    for (int i = 0; i < size; i++)
        if (!array[i].isValidTriangle())
            cout << array[i] << endl;
}

double TriangleArray::findMaxArea(){
    double res = array[0].area();
    for (int i = 1; i < size; i++)
        if (res < array[i].area())
            res = array[i].area();
    return res;
}

int TriangleArray::countRightIsosceles(){
    int count = 0;
    for (int i = 0; i < size; i++)
        if (array[i].isValidTriangle() && array[i].typeOf() == "Right-angled Isosceles Triangle")
            count++;
    return count;
}

int TriangleArray::countIsosceles(){
    int count = 0;
    for (int i = 0; i < size; i++)
        if (array[i].isValidTriangle() && array[i].typeOf() == "Isosceles Triangle")
            count++;
    return count;
}

int TriangleArray::countRight(){
    int count = 0;
    for (int i = 0; i < size; i++)
        if (array[i].isValidTriangle() && array[i].typeOf() == "Right-angled Scalene Triangle")
            count++;
    return count;
}

int TriangleArray::countEquilateral(){
    int count = 0;
    for (int i = 0; i < size; i++)
        if (array[i].isValidTriangle() && array[i].typeOf() == "Equilateral Triangle")
            count++;
    return count;
}

int TriangleArray::countScalene(){
    int count = 0;
    for (int i = 0; i < size; i++)
        if (array[i].isValidTriangle() && array[i].typeOf() == "Scalene Triangle")
            count++;
    return count;
}