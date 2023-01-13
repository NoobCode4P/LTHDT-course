#pragma once
#include "CItem.h"

class CFile : public CItem{

public:
	CFile(string name, int size);
	int getSize() const;
	string getName() const;
	void setHidden(bool isHidden, bool isAlsoApplyToChildren);
	void print(bool isPrintHiddenItems);
};