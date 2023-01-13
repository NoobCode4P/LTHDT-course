#include <iostream>
#include <vector>
using namespace std;

class IntArray{
    int *array;
    int size;
public:
    void Input();
    void Set(int *, int);
    
    IntArray& operator = (const IntArray&);

    friend istream& operator >> (istream&, IntArray&);
    friend ostream& operator << (ostream&, IntArray&);

    int& operator [] (int);

    operator int () const;

};