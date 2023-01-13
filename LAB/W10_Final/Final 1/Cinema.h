#include "RegularTicket.h"
#include "ComboTicket.h"
#include <vector>
#include <algorithm>
#include <fstream>

class Cinema{
	vector <Ticket*> list;
public:
	~Cinema();
	void inputList();
	void sortList();

	void saveList(string fileName);

	void comboList();
};