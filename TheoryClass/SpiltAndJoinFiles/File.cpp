#include "File.h"

File::File(string fileName){
    this->fileName = fileName;

    ifstream in(fileName, ios::binary);
    in.seekg(0, ios::end);
    this->Size = in.tellg();
    in.close();
}

File::File(string fileName, ull Size){
    this->fileName = fileName;
    this->Size = Size;
}

int File::getSize() const{
    return Size;
}

string File::getFileName() const{
    return fileName;
}

void spilt(const File& file, ull size, vector <File>& subFiles){
    int numberOfsubFiles = file.Size / size;
    ull sizeOfSparesubFile = file.Size % size;

    ifstream in(file.fileName, ios::binary);
    if (!in){
        throw "Unable to open file " + file.fileName;
    }

    for (int i = 0; i < numberOfsubFiles; i++){
        string zero = "";
        if (i + 1 < 10)
            zero += "00";
        else if (10 <= i + 1 && i + 1 < 100)
            zero += "0";
        string name = file.fileName + '.' + zero + to_string(i + 1);

        char * data = new char[size];

        ofstream out(name, ios::binary);

        if (!out) {
            throw "Unable to open " + name;
        }

        in.read(data, size);

        out.write(data, size);

        out.close();

        File subfile(name, size);
        subFiles.push_back(subfile);

        delete [] data;
    }

    if (sizeOfSparesubFile > 0){
        string zero = "";
        if (numberOfsubFiles + 1 < 10)
            zero += "00";
        else if (10 <= numberOfsubFiles + 1 && numberOfsubFiles + 1 < 100)
            zero += "0";
        string name = file.fileName + '.' + zero + to_string(numberOfsubFiles + 1);

        char *data = new char[sizeOfSparesubFile];

        ofstream out(name, ios::binary);
        if (!out){
            throw "Unable to open " + name;
        }
        in.read(data, sizeOfSparesubFile);

        out.write(data, sizeOfSparesubFile);

        out.close();
        delete [] data;

        File lastSubFile(name, sizeOfSparesubFile);
        subFiles.push_back(lastSubFile);
    }

    in.close();
}

File join(const vector <File>& subFiles){
    string pieceName = subFiles.at(0).fileName;
    string name = pieceName.substr(0, pieceName.find_last_of('.'));
    name.insert(name.find_first_of('.'), "_join");

    ull Size = 0;

    for (int i = 0; i < subFiles.size(); i++) {
        string nameSub = subFiles[i].fileName;
        ull size = subFiles[i].Size;
        Size += size;

        ifstream in(nameSub, ios::binary);

        if (!in) {
            throw "Unable to open " + nameSub;
        }

        char *data = new char[size];

        in.read(data, size);
        in.close();

        ofstream out(name, ios::app | ios::binary);
        out.write(data, size);
        out.close();
    }
    File joinedFile(name, Size);
    return joinedFile;
}

ostream& operator << (ostream& out, const File& a){
    out << "****Information of the file****" << endl;
    out << "Name: " << a.fileName << endl;
    out << "Size: " << a.Size << " B" << endl;
    return out;
}