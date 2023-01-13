#include "CFile.h"

CFile::CFile(string name, int size) : CItem(name, size){}

int CFile::getSize() const{
	return size;
}

string CFile::getName() const{
	return name;
}

void CFile::setHidden(bool isHidden, bool isAlsoApplyToChildren){
	this->isHidden = isHidden;
}

void CFile::print(bool isPrintHiddenItems){
	if (isHidden && isPrintHiddenItems == false)
		return;
	cout << "File: " << name << "  Size: " << size << endl;
}