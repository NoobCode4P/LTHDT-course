#include "Math.h"
#define pi 3.141592654

int main(){
    cout << "|-10| = " << Math::absOOP(-10) << endl;
    cout << "23.09^(-4) = " << Math::powOOP(23.09,-4) << endl;
    cout << "sqrt(11.897) = " << Math::sqrtOOP(11.897) << endl;
    cout << "e^-90.23 = " << Math::expOOP(-90.23) << endl;
    cout << "ln(9.7) = " << Math::logOOP(9.7) << endl;

    cout << "sin(60) = " << Math::sinOOP(60*pi/180) << endl;
    cout << "cos(60) = " << Math::cosOOP(60*pi/180) << endl;
    cout << "tan(45) = " << Math::tanOOP(45*pi/180) << endl;

    cout << "arcsin(1/2) = " << Math::asinOOP((double)1/2) / pi * 180 << " degrees" << endl;
    cout << "arccos(1/2) = " << Math::acosOOP((double)1/2) / pi * 180 << " degrees" << endl;
    cout << "arctan(7/3) = " << Math::atanOOP((double)7/3) / pi * 180 << " degrees" << endl;

    cout << "ceil(-2.3) = " << Math::ceilOOP(-2.3) << endl;
    cout << "floor(-2.3) = " << Math::floorOOP(-2.3) <<endl;
    cout << "round(-2.3) = " << Math::roundOOP(-2.3) << endl;
    cout << "trunc(-2.3) = " << Math::truncOOP(-2.3) << endl;


    return 0;
}