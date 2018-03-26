#ifndef BOOK_H
#define BOOK_H
#pragma once
#include"Libitem.h"
#include"user.h"
#include"state.h"
#include<string>
using namespace std;
class user;
class State;
class book:public Libitem
{
public:
    book(string ti,string author,bool flag);
    ~book();
    void set_title(string ti);
        void set_author(string au);
        string get_title();
        string get_author();
        void set_issue(bool i);
        bool get_issue();
        bool is_issued();
        void add_on_hold_user(user * i);
        int no_of_holders();
        State * get_state();
        user * get_holder_front_holder_wala();
        void set_state(State * s);


    private:
        State * pt;

    string title;
    string author;
    bool flag;
    vector<user *> hold_wale;

};

#endif // BOOK_H
