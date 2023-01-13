#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Set{
    vector <int> set;
public:
    Set();
    bool add(int x);
    bool add(vector <int> v);
    bool contains(int x);
    bool remove(int x);
    int size();
    
    Set Union(Set s2);
    Set Intersect(Set s2);
    Set Subtract(Set s2);
    void print();
};