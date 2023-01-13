#include "Set.h"

Set::Set(){}

bool Set::add(int x){
    if (find(set.begin(), set.end(), x) == set.end()){
        set.push_back(x);
        sort(set.begin(), set.end());
        return true;
    }
    return false;
}

bool Set::add(vector <int> v){
    bool isAddAll = true;
    for (int i = 0; i < v.size(); i++)
        isAddAll = add(v[i]) && isAddAll;
    return isAddAll;
}

bool Set::contains(int x){
    return (find(set.begin(), set.end(), x) != set.end());
}

bool Set::remove(int x){
    for (int i = 0; i < set.size(); i++){
        if (set[i] == x){
            set.erase(set.begin() + i);
            return true;
        }
    }
    return false;
}

int Set::size() {
    return set.size();
}

Set Set::Union(Set s2){
    Set res;
    res.add(set);
    res.add(s2.set);
    return res;
}

Set Set::Intersect(Set s2){
    Set res;
    for (int x : s2.set)
        for (int y : set)
            if (x == y)
                res.add(x);
    return res;   
}

Set Set::Subtract(Set s2){
    Set res;
    for (int x : set){
        if (find(s2.set.begin(), s2.set.end(), x) == s2.set.end())
            res.add(x);
    }
    return res;
}

void Set::print(){
    for (int x : set)
        cout << x << " ";
    cout << endl;
}