#include "Match.h"

Match::Match(){}

istream& operator >> (istream& in, Match& a){
    string hName, aName;
    int hGoal, aGoal;
    cout << "Enter home team's name(3 capital letters): ";
    in >> hName;
    cout << "Enter the number of home team's goal: ";
    in >> hGoal;
    cout << "Enter away team's name(3 capital letters): ";
    in >> aName;
    cout << "Enter the number of away team's goal: ";
    in >> aGoal;

    a.setHomeName(hName);
    a.setHomeGoal(hGoal);
    a.setAwayName(aName);
    a.setAwayGoal(aGoal);
}

ostream& operator << (ostream& out, const Match& a){
    out << a.homeName << " " << a.awayName << " " << a.homeGoal << " " << a.awayGoal << endl;
    return out;
}

void Match::setHomeName(string name){
    homeName = name;
}

void Match::setHomeGoal(int goal){
    homeGoal = goal;
}

void Match::setAwayName(string name){
    awayName = name;
}

void Match::setAwayGoal(int goal){
    awayGoal = goal;
}

int Match::getHomeGoal(){
    return homeGoal;
}

int Match::getAwayGoal(){
    return awayGoal;
}

int Match::getTotalGoal(){
    return homeGoal + awayGoal;
}

string Match::getHomeName(){
    return homeName;
}

string Match::getAwayName(){
    return awayName;
}