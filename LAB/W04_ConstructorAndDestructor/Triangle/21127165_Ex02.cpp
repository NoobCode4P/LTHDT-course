#include "TriangleArray.h"

int main(){
    string pointFile = "Point.txt";
    string triangleFile = "Triangle.txt";
    string triArrayFile = "TriangleArray.txt";
    Point a;
    Point b(3.1415);
    Point c(3.1415,-24.3);
    Point d("(-25.7909,3.1415)");

    //cout << a << b << c << d << endl;

    /* d.savePoint(pointFile);

    Point fromFile;
    fromFile.loadPoint(pointFile);
    cout << fromFile;

    cout << "Distance from a to b: " << a.distanceTo(b) << endl; */


    Triangle t1;
    Triangle t2(12.2,-4,22.45,-0.3,5,-6.7);
    Triangle t3("(1,1) (1,1) (2,4)");
    Triangle t4("(0,0) (6,0) (3,6)");

    /* if (t1.isValidTriangle()){
        cout << "Triangle1: " << t1 << endl;
        cout << "It is a " << t1.typeOf() << endl;
        cout << "Perimeter: " << t1.perimeter() << endl;
        cout << "Area: " << t1.area() << endl;
    }
    cout << "=============" << endl;
    if (t2.isValidTriangle()){
        cout << "Triangle2: " << t2 << endl;
        cout << "It is a " << t2.typeOf() << endl;
        cout << "Perimeter: " << t2.perimeter() << endl;
        cout << "Area: " << t2.area() << endl;
    }
    cout << "=============" << endl;
    if (t3.isValidTriangle()){
        cout << "Triangle3: " << t3 << endl;
        cout << "It is a " << t3.typeOf() << endl;
        cout << "Perimeter: " << t3.perimeter() << endl;
        cout << "Area: " << t3.area() << endl;
    }
    cout << "=============" << endl;
    if (t4.isValidTriangle()){
        cout << "Triangle4: " << t4 << endl;
        cout << "It is a " << t4.typeOf() << endl;
        cout << "Perimeter: " << t4.perimeter() << endl;
        cout << "Area: " << t4.area() << endl;
    }
    cout << "=============" << endl;
    t2.saveFile("Triangle.txt");
    
    Triangle t5;
    t5.loadFile(triangleFile);
    cout << t5 << endl; */

    Triangle mang[] = {t1, t2, t3, t4};
    vector <Triangle> vT = {t2,t3,t1};
    string listTri = "[(-12,4) (2.3,-3) (2,1)];[(0,3) (1,2) (4,5)]";

    TriangleArray arr1;
    TriangleArray arr2(4);
    TriangleArray arr3(mang,4);
    TriangleArray arr4(vT);
    TriangleArray arr5(listTri);

    //cout << arr1 << endl << arr2 << endl << arr3 << endl << arr4 << endl << arr5 << endl;
    
    /* arr4.saveArray(triArrayFile);

    TriangleArray arr6;
    arr6.loadArray(triArrayFile);
    cout << arr6 << endl; */

    // double maxArea = arr3.findMaxArea();
    // cout << maxArea << endl;

    //arr4.invalidTriangle();

    cout << arr3 << endl;
    
    int countRightIso = arr3.countRightIsosceles();
    int countIso = arr3.countIsosceles();
    int countRight = arr3.countRight();
    int countEquil = arr3.countEquilateral();
    int countScalene = arr3.countScalene();
    cout << "Number of Right Isosceles Triangle: " << countRightIso << endl;
    cout << "Number of Isosceles Triangle: " << countIso << endl;
    cout << "Number of Right Triangle: " << countRight << endl;
    cout << "Number of Equilateral Triangle: " << countEquil << endl;
    cout << "Number of Scalence Triangle: " << countScalene << endl;


    return 0;
}