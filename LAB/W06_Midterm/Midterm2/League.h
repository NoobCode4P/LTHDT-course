#include "Match.h"
#include <vector>
#include <fstream>

class League{
    string name;
    vector <Match> list;
public:
    League();
    void input();
    int totalGoals();
    int totalHomeGoals();
    int totalAwayGoals();

    int getPoint();
    void sortList();

    void saveInfo(string file);
};