#include "Fraction.h"

int main()
{
	Fraction f1, f2;
	Fraction f3;
	Fraction f4;
	Fraction f5;
	Fraction f6, f7, f8;
	
	cout << "===Input f1===" << endl;
	 f1.Input();
	 cout << "===Input f2===" << endl;
	 f2.Input();
	 cout << "===Input f3===" << endl;
	 f3.Input();
	 cout << "===Input f4===" << endl;
	 f4.Input();
	 cout << "===Input f5===" << endl;
	 f5.Input();
	 cout << "===Input f6===" << endl;
	 f6.Input();
	 cout << "===Input f7===" << endl;
	 f7.Input();
	 cout << "===Input f8===" << endl;
	 f8.Input();
	
	cout << "=> set f6 = f3" << endl;
	 f6=f3;

	f7=f1+f5;
	cout << "f7 = f1 + f5" << endl;
	cout << "-> " << f7 << endl;

	f8=f2-f4;
	cout << "f8 = f2 - f4" << endl;
	cout << "-> " << f8 << endl;

	f2=f3*f4;
	cout << "f2 = f3 * f4" << endl;
	cout << "-> " << f2 << endl;

	f5=f6/f3;
	cout << "f5 = f6 / f3" << endl;
	cout << "-> " << f5 << endl;

	
	cout<<((f2==f3)? "f2 is equal to f3" : "f2 is not equal to f3") << endl;

	cout<<((f3!=f1)? "f3 is not equal to f1" : "f3 is equal to f1") << endl;
	
	cout<<((f2>=f5)? "f2 is greater than or equal to f5" : "f2 is less than f5") << endl;

	cout<<((f2>f5)? "f2 is greater than f5" : "f2 is less than or equal to f5") << endl;

	cout<<((f5<=f3)? "f5 is less than or equal to f3" : "f5 is greater than f3") << endl;

	cout<<((f5<f3)? "f5 is less than f3" : "f5 is greater than or equal to f3") << endl;

	//=============

	f1=f2+3;
	cout << "f1 = f2 + 3" << endl;
	cout << "-> " << f1 << endl;

	f3=-7+f1;
	cout << "f3 = -7 + f1" << endl;
	cout << "-> " << f3 << endl;

	f5=7*f3;
	cout << "f5 = 7 * f3" << endl;
	cout << "-> " << f5 << endl;

	f6=f4-6;
	cout << "f6 = f4 - 6" << endl;
	cout << "-> " << f6;
	
	// cout<<f3;
	// cout<<f6;

	//=============

	f1+=f5;
	cout << "f1 += f5" << endl;
	cout << "-> " << f1 << endl;

	f6-=f7;
	cout << "f6 -= f7" << endl;
	cout << "-> " << f6 << endl;

	f8*=f1;
	cout << "f8 *= f1" << endl;
	cout << "-> " << f8 << endl;

	f8/=f2;
	cout << "f8 /= f2" << endl;
	cout << "-> " << f8 << endl;

	//================

	cout <<"f8++ = ";
	cout<<f8++ << endl;

	cout << "++f7 = ";
	cout<<++f7 << endl;
	
	cout << "f8-- = ";
	cout<<f8-- << endl;

	cout << "--f7 = ";
	cout<<--f7 << endl;
	
	float f=(float)f3;				// 3/2 => 1.5
	cout << f << endl;

	return 0;
}