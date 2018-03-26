#ifndef DATE_H
#define DATE_H
#include<iostream>
#include<string>
#include<vector>
using namespace std;
#pragma once

class Date
{
public:
    Date();
    Date(int mn, int day, int yr);  // constructor
    ~Date();
    int get_month();
    int get_day();
    int get_year();
    int rdn(int mn,int day,int yr);

private:
    int month, day, year;
};


#endif // DATE_H
