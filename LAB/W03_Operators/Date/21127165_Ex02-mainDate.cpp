#include "Date.h"

int main()
{
	Date d1;
	Date d2;
	Date d3;
	Date d4;
	Date d5;
	Date d6;

	cout << "====Input d1===" << endl;
	d1.Input();
	cout << "====Input d2===" << endl;
	d2.Input();
	cout << "====Input d3===" << endl;
	d3.Input();
	cout << "====Input d4===" << endl;
	d4.Input();
	cout << "====Input d5===" << endl;
	 d5.Input();
	cout << "====Input d6===" << endl;
	d6.Input();

	cout << "=> set d6 = d3" << endl;
	d6=d3;

	cout << "d6=d3.Tomorrow()" << endl;
	d6=d3.Tomorrow();
	cout << "-> d6: " << d6 << endl;

	cout << "d5=d2.Yesterday()" << endl;
	d5=d2.Yesterday();
	cout << "-> d5: " << d5 << endl;
	
	cout<<((d6==d4) ? "d6 is equal to d4" : "d6 is not equal to d4") << endl;
	cout<<((d6!=d4) ? "d6 is not equal to d4" : "d6 is equal to d4") << endl;
	cout<<((d6>=d4) ? "d6 is after or the same as d4" : "d6 is before d4") << endl;
	cout<<((d6<=d4) ? "d6 is before or the same as d4" : "d6 is after d4") << endl;
	cout<<((d6>d4) ? "d6 is after d4" : "d6 is before or the same as d4") << endl;
	cout<<((d6<d4) ? "d6 is before d4" : "d6 is after or the same as d4") << endl;
	
	d3=d2+1;
	cout << "d3 = d2 + 1" << endl;
	cout << "-> " << d3 << endl;

	d2=d3-2;
	cout << "d2 = d3 - 2" << endl;
	cout << "-> " << d2 << endl;

	
	cout << "d4++ = " << d4++ << endl;

	cout << "++d2 = " << ++d2 << endl; 
	cout << "d5-- = " << d5-- << endl;
	cout << "--d6 = " << --d6 << endl;
	

	// cout<<d3;
	// cin>>d4;
	
	cout<<(int)d3<<endl;			// from the first day of current year
	
	cout<<(long)d4<<endl; 		// from 1/1/1

	Date d7;
	cout << "===Input d7===" << endl;
	cin >> d7;
	d7+=7;
	cout << "d7 += 7" << endl;
	cout << "-> " << d7 << endl;

	d2-=6;
	cout << "d2 -= 6" << endl;
	cout << "-> " << d2 << endl;

	return 0;
}