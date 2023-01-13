#include "CFolder.h"

CFolder::CFolder(string name) : CItem(name, 0){}

int CFolder::getSize() const{
	return size;
}

string CFolder::getName() const{
	return name;
}

void CFolder::add(CItem* item){
	for (int i = 0; i < list.size(); i++)
		if (list[i] && list[i]->getName() == item->getName()){
			cout << "This item have already existed." << endl;
			return;
		}
	list.push_back(item);
	this->size += item->getSize();
}

CItem* CFolder::removeByName(string itemName){
	CItem* res = NULL;
	for (int i = 0; i < list.size(); i++){
		if (list[i]->getName() == itemName){
			res = list[i];
			list.erase(list.begin() + i);
			this->size -= res->getSize();
		}
		else{
			CItem *tmp = res;
			res = list[i]->removeByName(itemName);
			if (res == NULL)
				res = tmp;
			if (res)
				this->size -= res->getSize();
		}
	}
	return res;
}

CItem* CFolder::findByName(string itemName){
	CItem* res = NULL;
	for (int i = 0; i < list.size(); i++){
		if (list[i]->getName() == itemName){
			res = list[i];
			break;
		}
		else{
			res = list[i]->findByName(itemName);
			if (res && res->getName() == itemName)
				break;
		}
	}
	return res;
}

void CFolder::setHidden(bool isHidden, bool isAlsoApplyToChildren){
	this->isHidden = isHidden;
	if (isAlsoApplyToChildren)
		for (int i = 0; i < list.size(); i++)
			list[i]->setHidden(isHidden, isAlsoApplyToChildren);
}

void CFolder::print(bool isPrintHiddenItems){
	if (isHidden && isPrintHiddenItems == false){}
	else{
		cout << "Folder: " << name << "  Size: " << size << endl;
	}
	for (int i = 0; i < list.size(); i++){
		if (list[i]->isHiddenItem() && isPrintHiddenItems == false)
			continue;
		else
			list[i]->print(isPrintHiddenItems);
	}
}