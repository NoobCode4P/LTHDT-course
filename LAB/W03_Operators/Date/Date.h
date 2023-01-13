#include <iostream>
#include <vector>
using namespace std;

class Date{
    int day, month, year;

    friend int dateToDays(const Date&);
    friend Date daysToDate(int);
public:
    void setDate(int, int, int);
    

    void Input();
    friend istream& operator >> (istream&, Date &);
    friend ostream& operator << (ostream&, const Date &);

    Date& operator = (const Date&);

    Date Yesterday();
    Date Tomorrow();

    bool operator == (const Date&);
    bool operator != (const Date&);
    bool operator >= (const Date&);
    bool operator <= (const Date&);
    bool operator > (const Date&);
    bool operator < (const Date&);

    Date operator + (int);
    Date operator - (int);

    Date& operator ++ ();
    Date operator ++ (int);
    Date& operator -- ();
    Date operator -- (int);
    Date& operator += (int);
    Date& operator -= (int);

    operator int () const;
    operator long() const;

};
bool isValidDate(int d, int m, int y);
bool isLeapYear(int y);