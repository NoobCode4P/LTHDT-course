#pragma once
#include <iostream>
#include <string>
using namespace std;

class CItem{
protected:
	string name;
	int size;
	bool isHidden;
public:
	CItem(string name, int size);
	virtual int getSize() const = 0;
	virtual string getName() const = 0;
	bool isHiddenItem();

	virtual CItem* removeByName(string itemName);
	virtual CItem* findByName(string itemName);
	virtual void setHidden(bool isHidden, bool isAlsoApplyToChildren) = 0;
	virtual void print(bool isPrintHiddenItems) = 0;
};