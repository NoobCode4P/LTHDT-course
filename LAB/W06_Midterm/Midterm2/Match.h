#include <iostream>
using namespace std;

class Match{
    string homeName;
    string awayName;
    int homeGoal;
    int awayGoal;
public:
    Match();
    friend istream& operator >> (istream&, Match&);
    friend ostream& operator << (ostream&, const Match&);

    void setHomeName(string);
    void setAwayName(string);
    void setHomeGoal(int);
    void setAwayGoal(int);

    int getHomeGoal();
    int getAwayGoal();
    int getTotalGoal();
    string getHomeName();
    string getAwayName();

    
};