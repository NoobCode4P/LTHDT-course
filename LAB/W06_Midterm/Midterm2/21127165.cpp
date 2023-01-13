#include "League.h"

int main(){
    League obj;
    obj.input();

    cout << "The total number of goals: " << obj.totalGoals() << endl;
    cout << "The total number of home-team goals: " << obj.totalHomeGoals() << endl;
    cout << "The total number of away-team goals: " << obj.totalAwayGoals() << endl;

    int point = obj.getPoint();
    cout << "The total points of the input team: " << point << endl;

    obj.saveInfo("league.txt");

    return 0;
}