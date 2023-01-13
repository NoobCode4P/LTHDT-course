#include "IntArray.h"

void IntArray::Input(){
    int n;
    do{
        cout << "Enter size (a positive integer): ";
        cin >> n;
    }while (n <= 0);

    int *tmp = new int[n];
    for (int i = 0; i < n; i++)
        cin >> tmp[i];
    
    Set(tmp,n);
    delete [] tmp;
}

void IntArray::Set(int *a, int n){
    size = n;
    array = new int[n];
    for (int i = 0; i < n; i++)
        array[i] = a[i]; 
}

IntArray& IntArray::operator = (const IntArray& arr){
    if (this != &arr){
        delete [] array;
        this->Set(arr.array, arr.size);
    }
    return *this;
}

istream& operator >> (istream& in, IntArray& a){
    int n;
    do{
        cout << "Enter size (a positive integer): ";
        in >> n;
    }while (n <= 0);

    int *tmp = new int[n];
    for (int i = 0; i < n; i++)
        in >> tmp[i];
    
    a.Set(tmp,n);
    delete [] tmp;
    return in;
}

ostream& operator << (ostream& out, IntArray& a){
    out << "Size: " << a.size << endl;
    for (int i = 0; i < a.size; i++)
        out << a[i] << " ";
    out << endl;
    return out;
}

int& IntArray::operator [] (int index){
    if (index < 0 || index >= size)
        exit(0);
    return array[index];
}

IntArray::operator int () const{
    return size;
}