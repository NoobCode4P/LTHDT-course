#pragma once
#include "CItem.h"
#include <vector>

class CFolder : public CItem{
	vector <CItem*> list;
public:
	CFolder(string name);
	int getSize() const;
	string getName() const;
	void add(CItem *);
	CItem* removeByName(string itemName);
	CItem* findByName(string itemName);
	void setHidden(bool isHidden, bool isAlsoApplyToChildren);
	void print(bool isPrintHiddenItems);
};