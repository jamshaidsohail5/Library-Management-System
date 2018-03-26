#ifndef LIBITEM_H
#define LIBITEM_H
#pragma once

#include"state.h"
#include"loan.h"
#include<string>
#include<vector>
#include"user.h"
using namespace std;
class user;
class loan;
class State;
class Libitem
{
public:
    Libitem();
    ~Libitem();
    virtual string get_title() = 0;
    virtual void set_title(string i) = 0;
    void add_loan(loan * lo);
    virtual void add_on_hold_user(user * i)=0;
    virtual void set_issue(bool i) = 0;
    virtual bool get_issue() = 0;
    virtual bool is_issued() = 0;
    virtual string get_author()=0;
    virtual int no_of_holders()=0;
    void remove_loan(loan * l);
    virtual user * get_holder_front_holder_wala()=0;
    void remov_loan(loan * l);

    virtual void set_state(State * s) = 0;
    virtual State * get_state() = 0;

private:
    vector<loan *> loa;
    bool flag;
    State * pt;
};

#endif // LIBITEM_H






