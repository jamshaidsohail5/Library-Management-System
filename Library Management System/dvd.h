#ifndef DVD_H
#define DVD_H
#pragma once
#include"Libitem.h"
#include"user.h"
#include"state.h"
#include<string>
using namespace std;
class user;
class State;
class dvd:public Libitem
{
public:
    dvd(string ti,bool fl);
    ~dvd();
    void set_title(string ti);
    string get_title();
    void set_issue(bool i);
    bool get_issue();
    bool is_issued();
    void add_on_hold_user(user * i) ;
    string get_author();
    int no_of_holders();
    State * get_state();
    user * get_holder_front_holder_wala();

    void set_state(State * s);
private:
    string title;
    bool flag;
    State * pt;
    vector<user *>hold_wale;
};


#endif // DVD_H
