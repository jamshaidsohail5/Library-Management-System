#ifndef USER_H
#define USER_H
#pragma once

#include"loan.h"
#include"libitem.h"
#include<string>
#include<vector>
using namespace std;
class loan;
class Libitem;
class user
{
public:
    user();
    ~user();
    void add_loan(loan * lo);
    virtual string get_name()= 0;
    virtual void set_name(string i) = 0;
    bool check_if_already_issued_or_not(string u);
    vector<loan*> show_all_loans();
    void remove_loan(loan * l);
    loan * search_loan(string n,string n1);
private:
    vector<loan *> loa;
};

#endif // USER_H
