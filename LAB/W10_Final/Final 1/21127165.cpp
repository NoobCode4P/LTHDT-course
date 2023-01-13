#include "Cinema.h"

int main(){
	Cinema x;
	x.inputList();

	x.sortList();
	x.saveList("ve.txt");

	x.comboList();

	return 0;
}