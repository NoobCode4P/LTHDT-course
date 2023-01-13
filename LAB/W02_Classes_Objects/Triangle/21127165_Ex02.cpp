#include "Triangle.h"

int main(){
    Triangle T;
    T.input();
    cout << "===========" << endl;
    if (T.isValidTriangle()){
        T.output();
        cout << "===========" << endl;
        T.ofType();
        cout << "Perimeter = " << T.perimeter() << endl;
        cout << "Area = " << T.area() << endl;
        Point G = T.Center();
        cout << "Center G(" << G.getX() << "," << G.getY() << ")" << endl;
    }
    else
        cout << "Does not exist such Triangle" << endl;
    

    return 0;
}