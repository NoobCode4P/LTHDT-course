#include "League.h"

League::League(){}

void League::input(){
    string leagueName;
    cout << "Enter the name of the league: ";
    getline(cin, leagueName);

    name = leagueName;

    int n;
    cout << "Enter the number of matches: "; cin >> n;

    for (int i = 0 ; i < n; i++){
        Match tmp;
        cin >> tmp;
        list.push_back(tmp);
    }
}

int League::totalHomeGoals(){
    int count = 0;
    for (int i = 0; i < list.size(); i++)
        count += list[i].getHomeGoal();
    return count;
}

int League::totalAwayGoals(){
    int count = 0;
    for (int i = 0; i < list.size(); i++)
        count += list[i].getAwayGoal();
    return count;
}

int League::totalGoals(){
    int count = 0;
    for (int i = 0; i < list.size(); i++)
        count += list[i].getTotalGoal();
    return count;
}

int League::getPoint(){
    string name;
    cout << "Enter team name: "; cin >> name;
    int point = 0;
    for (int i = 0; i < list.size(); i++){
        Match tmp = list[i];
        if (tmp.getAwayName() == name){
            if (tmp.getAwayGoal() > tmp.getHomeGoal())
                point += 3;
            else if (tmp.getAwayGoal() < tmp.getHomeGoal())
                point += 0;
            else
                point += 1;
        }
        else if (tmp.getHomeName() == name){
            if (tmp.getHomeGoal() > tmp.getAwayGoal())
                point += 3;
            else if (tmp.getHomeGoal() < tmp.getAwayGoal())
                point += 0;
            else
                point += 1;
        }
    }
    return point;
}

void League::sortList(){
    for (int i = 0; i < list.size() - 1; i++){
        for (int j = i + 1; j < list.size(); j++){
            if (list[i].getTotalGoal() < list[j].getTotalGoal())
                swap(list[i],list[j]);
            else if (list[i].getTotalGoal() == list[j].getTotalGoal())
                if (list[i].getHomeName() > list[j].getHomeName())
                    swap(list[i],list[j]);
        }
    }
}

void League::saveInfo(string filename) {
    ofstream out(filename);
    if (!out){
        cout << "Unable to open " << filename << endl;
        return;
    }
    out << name << endl;
    sortList();
    for (int i = 0; i < list.size(); i++)
        out << list[i];
    out.close();
}
