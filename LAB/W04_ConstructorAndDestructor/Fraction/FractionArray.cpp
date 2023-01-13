#include "FractionArray.h"

FractionArray::FractionArray(){
	size = 0;
	array.resize(size);
}

FractionArray::FractionArray(int n){
	Fraction tmp;
	array.resize(n);
	for (int i = 0; i < n; i++)
		array[i] = tmp;
	size = n;
}

FractionArray::FractionArray(Fraction a[], int n){
	size = n;
	array.resize(n);
	for (int i = 0; i < size; i++)
		array[i] = a[i];
}

FractionArray::FractionArray(vector <Fraction> a){
	size = a.size();
	for (int i = 0; i < a.size(); i++)
		array.push_back(a[i]);
}

FractionArray::FractionArray(string s){
	stringstream read(s);
	string frac;
	while (read >> frac){
		Fraction newFrac(frac);
		array.push_back(newFrac);
	}
	size = array.size();
}

istream& operator >> (istream& in, FractionArray& a){
	int n;
	cout << "Nhap so luong: "; in >> n;
	a.size = n;
	a.array.resize(n);
	for (int i = 0; i < a.size; i++)
		in >> a.array[i];
	return in;
}

ostream& operator << (ostream& out, const FractionArray& a){
	if (a.size == 0){
		out << "Empty Array" << endl;
		return out;
	}
	for (int i = 0; i < a.size; i++)
		out << a.array[i];
	out << endl;
	return out;
}

void FractionArray::loadFile(string file){
	ifstream in(file);
	if (!in){
		cout << "Unable to open " << file << endl;
		return;
	}
	string fracArray;
	getline(in, fracArray);
	in.close();
	FractionArray ans(fracArray);
	*this = ans;
}

void FractionArray::saveFile(string file) {
	ofstream out(file);
	if (!out) {
		cout << "Unable to open " << file << endl;
		return;
	}
	out << *this;
	out.close();
}

Fraction FractionArray::sumAll(){
	Fraction res;
	for (int i = 0; i < size; i++)
		res = res + array[i];
	return res;
}

Fraction FractionArray::findMax(){
	Fraction res = array[0];
	for (int i = 1; i < size; i++)
		if (array[i].compare(res) == 1)
			res = array[i];
	return res;
}

int FractionArray::countPositive(){
	int count = 0;
	for (int i = 0; i < size; i++)
		if (array[i].isPositive())
			count++;
	return count;
}

int FractionArray::countNegative(){
	int count = 0;
	for (int i = 0; i < size; i++)
		if (array[i].isNegative())
			count++;
	return count;
}

int FractionArray::countZero(){
	int count = 0;
	for (int i = 0; i < size; i++)
		if (array[i].isZero())
			count++;
	return count;
}

