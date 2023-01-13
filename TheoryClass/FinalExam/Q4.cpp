#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Role{
protected:
    string role;
    static map <string, double> mp;
    int t;
public:
    void setRole(string s){role = s;}
    void setTime(int t){this->t = t;}
    virtual double salary(){return (double)t * mp[role];}
    
};

map <string, double> Role::mp = {
      {"GK",  300},
      {"CB", 520},
      {"LB", 500}
    };

class Primary : public Role{
    public:
    double salary(){return Role::salary() * 1.2;}
};

class Additional : public Role{};

class Player{
    string name;
    int doB;
    vector <Role*> dsR;
    
public:
    ~Player(){
        for (int i = 0; i < dsR.size(); i++)
            delete dsR[i];
    }
    double totalRoleSalaries(){
        double res = 0;
        for (Role* r : dsR)
            res += r->salary();
        return res;
    }
    
    void nhapTT(){
        cout << "Nhap ten cau thu: ";
        string ten;
        getline(cin, ten);
        cout << "Nhap nam sinh: ";
        int d;
        cin >> d;
        cin.ignore();
        name = ten;
        doB = d;
        
        int n;
        cout << "Nhap so luong vai tro: "; cin >> n;
        for (int i = 0; i < n; i++){
            string vtro;
            cin >> vtro;
            int t;
            cout << "Nhap tgian:"; cin >> t;
            int c;
            do{
                cout << "Nhap 1-chinh, 2-phu: "; cin >> c;
            }while(c != 1 && c!= 2);
            cin.ignore();
            Role *r = NULL;
            switch(c){
            case 1:
                r = new Primary;
                break;
            case 2:
                r = new Additional;
                break;
            }
            r->setRole(vtro);
            r->setTime(t);
            dsR.push_back(r);
        }
    }
};

class FBTeam{
    string name;
    int yoE;
    vector <Player*> DS;
    public:
    ~FBTeam(){
        for (int i = 0; i < DS.size(); i++)
            delete DS[i];
    }
    void nhapThongTin(){
        string ten;
        cout << "Nhap ten clb: ";
        getline(cin, ten);
        cout << "Nhap nam: ";
        int y; cin >> yoE;
        name = ten;
        y = yoE;
        
        int n; cout << "Nhap sl: "; cin >> n;
        cin.ignore();
        for (int i = 0; i < n; i++){
            cout << "===========Player " << i + 1 << endl;
            Player* p = new Player;
            p->nhapTT();
            DS.push_back(p);
        }
    }
    double money(){
        double res = 0; 
        for (Player* p : DS)
            res += p->totalRoleSalaries();
        return res;
    }
};

int main()
{
    FBTeam team;
    team.nhapThongTin();
    cout << "Tong tien tra: " << team.money() << endl;

    return 0;
}
