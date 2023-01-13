#include "Set.h"

int main(){
    vector <int> vA = {2,3,4,3,2,2};
    vector <int> vB = {5,4,6,5,5,4};
    Set a, b;

    a.add(vA);
    b.add(vB);

    a.print();
    cout << "========" << endl;
    b.print();

    Set unionSet = a.Union(b);
    Set intersectSet = a.Intersect(b);
    Set subtractSet = a.Subtract(b);
    
    unionSet.print();
    intersectSet.print();
    subtractSet.print();

    return 0;
}