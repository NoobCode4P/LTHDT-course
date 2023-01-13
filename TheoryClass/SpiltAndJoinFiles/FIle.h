#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

typedef unsigned long long ull;
typedef unsigned int ui;

class File{
private:
    string fileName;
    ull Size;

public:
    File(string fileName);
    File(string fileName, ull Size);
    int getSize() const;
    string getFileName() const;

    friend ostream& operator << (ostream&, const File&);

    friend void spilt(const File& file, ull size, vector <File>& subFiles);
    friend File join(const vector <File>& subFiles);

};