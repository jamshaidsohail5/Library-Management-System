#include"date.h"
#include<iostream>
using namespace std;

int max(int a, int b)
{
    if (a>b) return(a); else return (b);
}

int min(int a, int b)
{
    if (a>b) return(b); else return (a);
}

Date::Date()
{
    month = day = year = 1;
}

Date::Date(int yr, int mn, int dy)
{
    static int length[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    month = max(1, mn);
    month = min(month, 12);

    day = max(1, dy);
    day = min(day, length[month]);

    year = max(1, yr);
}


Date::~Date(){

}
int Date::get_month()
{
    return month;
}
int Date::get_day()
{
    return day;
}
int Date::get_year()
{
    return year;
}

int Date::rdn(int y, int m, int d) { /* Rata Die day one is 0001-01-01 */
    if (m < 3)
        y--, m += 12;
    return 365 * y + y / 4 - y / 100 + y / 400 + (153 * m - 457) / 5 + d - 306;
}
