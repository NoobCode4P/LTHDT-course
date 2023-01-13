#include "IntArray.h"

int main()
{
	// // Using dynamic allocated array
	//IntArray m1;
	IntArray m2;
	
	IntArray m3;
	IntArray m4;
	IntArray m5;

	//m1.Input();
	//m2.Input();
	m3.Input();
	m4.Input();
	m5.Input();

	cin>>m2;
	cout << "m2: ";
	cout<<m2;

	m5=m2;

	cout << "m5: " << m5;

	cout<<m3[3] << endl;
	m3[4]=1;

	cout << m3;

	cout<<(int)m4 << endl; // return the size of array

	return 0;
}