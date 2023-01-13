#include "Date.h"

const vector <int> Days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isValidDate(int d, int m, int y){
    if (m < 1 || m > 12 || d < 1 || y < 1)
        return false;

    switch(m){
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            if (d > 31)
                return false;
            break;
        case 4: case 6: case 9: case 11:
            if (d > 30)
                return false;
            break;
        case 2:
            if (isLeapYear(y)){
                if (d > 29)
                    return false;
            }
            else
                if (d > 28)
                    return false;
            break;
    }
    return true;
}

bool isLeapYear(int y){
    return (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0));
}

void Date::setDate(int d, int m, int y){
    day = d;
    month = m;
    year = y;
}

//================
void Date::Input(){
    int d,m,y;
    do{
        cout << "Ngay: "; cin >> d;
        cout << "Thang: "; cin >> m;
        cout << "Nam: "; cin >> y;
    }while(!isValidDate(d,m,y));
    
    setDate(d,m,y);
}

istream& operator >> (istream& in, Date& date){
    int d,m,y;
    do{
        cout << "Ngay: "; in >> d;
        cout << "Thang: "; in >> m;
        cout << "Nam: "; in >> y;
    }while(!isValidDate(d,m,y));
    
    date.setDate(d,m,y);
    return in;
}

ostream& operator << (ostream& out, const Date& date){
    out << date.day << "/" << date.month << "/" << date.year << endl;
    return out;
}

//================
Date& Date::operator = (const Date& b){
    this->setDate(b.day,b.month,b.year);
    return *this;
}

Date Date::Yesterday(){
    Date res;
    int d = day;
    int m = month;
    int y = year;

    if (d == 1){
        if (m == 1){
            d = Days[Days.size() - 1];
            m = Days.size();
            y--;
        }
        else{
            d = (m == 3 && isLeapYear(y)) ? 29 : Days[m - 2];
            m--;
        }
    }
    else
        d--;

    res.setDate(d,m,y);
    return res;
}

Date Date::Tomorrow(){
    Date res;
    int d = day, m = month, y = year;
    if (m == 2 && isLeapYear(y)){
        if (d == 28)
            d = 29;
    }
    else{
        if (d == Days[m - 1]){
            d = 1;
            if (m == Days.size()){
                m = 1;
                y++;
            }
            else
                m++;
        }
        else
            d++;
    }
    res.setDate(d,m,y);
    return res;
}

//===============
bool Date::operator == (const Date& b){
    return (day == b.day) && (month == b.month) && (year == b.year);
}

bool Date::operator != (const Date& b){
    return !(*this == b);
}

bool Date::operator > (const Date& b){
    if (year > b.year)
        return true;

    if (year == b.year){
        if (month > b.month)
            return true;
        else if (month == b.month){
            if (day > b.day)
                return true;
        }
    }
    return false;
}

bool Date::operator < (const Date& b){
    if (year < b.year)
        return true;

    if (year == b.year){
        if (month < b.month)
            return true;
        else if (month == b.month){
            if (day < b.day)
                return true;
        }
    }
    return false;
}

bool Date::operator >= (const Date& b){
    return (*this > b) || (*this == b);
}

bool Date::operator <= (const Date& b){
    return (*this < b) || (*this == b);
}

//=============
int dateToDays(const Date& date){
    int m = date.month, y = date.year;
    int res = date.day;
    if (m > 1)
        res += 31;
    if (m > 2)
        res += (isLeapYear(y) ? 29 : 28);
    if (m > 3)
        res += 31;
    if (m > 4)
        res += 30;
    if (m > 5)
        res += 31;
    if (m > 6)
        res += 30;
    if (m > 7)
        res += 31;
    if (m > 8)
        res += 31;
    if (m > 9)
        res += 30;
    if (m > 10)
        res += 31;
    if (m > 11)
        res += 30;
    return res;
}

Date daysToDate(int days){
    Date res;
    int d,m,y;

    y = days / 365;
    if (days < 0)
        y--;

    int dayLeft = days % 365;
    if (dayLeft < 0)
        dayLeft += 365;

    int i = 0;
    for ( ; dayLeft > 0 && i < Days.size(); i++)
        dayLeft -= Days[i];
        
    m = i;
    
    if (dayLeft < 0)
        d = Days[i - 1] + dayLeft;

    else if (dayLeft == 0)
        d = Days[i - 1];

    res.setDate(d,m,y);
    return res;
}

Date Date::operator + (int x){
    Date res;
    int n = dateToDays(*this) + x;  
    res = daysToDate(n);

    res.year += year;
    int y = res.year;
    
    for (int i = year; i <= y; i++){
        if (isLeapYear(i))
            res = res.Yesterday();
    }
    
    return res;
}

Date Date::operator - (int x){
    Date res;
    int n = dateToDays(*this) - x;
    res = daysToDate(n);

    res.year += year;

    if (n > 59)
        if (isLeapYear(year))
            res = res.Yesterday();

    return res;
}
//============
Date& Date::operator ++ (){
    *this = *this + 1;
    return *this;
}

Date Date::operator ++ (int){
    Date tmp;
    tmp = *this;
    ++ *this;
    return tmp;
}

Date& Date::operator -- (){
    *this = *this - 1;
    return *this;
}

Date Date::operator -- (int){
    Date tmp;
    tmp = *this;
    -- *this;
    return tmp;
}

Date& Date::operator += (int x){
    *this = *this + x;
    return *this;
}

Date& Date::operator -= (int x){
    *this = *this - x;
    return *this;
}

//===========
Date::operator int() const{
    return dateToDays(*this);
}

Date::operator long() const{
    int curDate = dateToDays(*this);
    long ans = 0;
    for (int i = 1; i < year; i++)
        ans += (isLeapYear(i) ? 366 : 365);
    return ans + curDate;
}