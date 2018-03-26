#ifndef LMS_H
#define LMS_H
#pragma once
#include"user.h"
#include"Libitem.h"
#include"dvd.h"
#include"book.h"
#include"student.h"
#include"clerk.h"
#include"admin.h"
#include<vector>
#include<string>
using namespace std;

class user;
class Libitem;
class student;
class clerk;
class admin;
class dvd;
class book;

class LMS
{
public:

    LMS();
    ~LMS();

    void add_lib_item(Libitem * lib);
    void add_users(user * u);
    user * search_user(string n);
    Libitem* search_items(string n);
    Libitem* search_by_author(string n);

    void remove_item(string n);
    bool searchitem(string n);
    bool searchuser(string n);
    void update_student(string n);


private:
    vector<user *> users;
    vector<Libitem *> libraryitems;

};
#endif // LMS_H

