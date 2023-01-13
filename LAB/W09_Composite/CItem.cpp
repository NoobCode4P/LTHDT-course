#include "CItem.h"

CItem::CItem(string name, int size){
	this->name = name;
	this->size = size;
	isHidden = false;
}

bool CItem::isHiddenItem(){
	return isHidden;
}

CItem* CItem::removeByName(string itemName){
	return NULL;
}

CItem* CItem::findByName(string itemName){
	return NULL;
}
