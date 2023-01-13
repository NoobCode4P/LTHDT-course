#include "Triangle.h"
#include <vector>

class TriangleArray{
    Triangle *array;
    int size;
public:
    TriangleArray();
    TriangleArray(int n);
    TriangleArray(Triangle a[], int n);
    TriangleArray(vector <Triangle> a);
    TriangleArray(string s);
    ~TriangleArray();

    friend istream& operator >> (istream&, TriangleArray&);
    friend ostream& operator << (ostream&, const TriangleArray&);
    TriangleArray& operator = (const TriangleArray&);

    void loadArray(string file);
    void saveArray(string file);

    double findMaxArea();

    void invalidTriangle();

    int countRightIsosceles();
    int countIsosceles();
    int countRight();
    int countEquilateral();
    int countScalene();
};