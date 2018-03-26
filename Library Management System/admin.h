#ifndef ADMIN_H
#define ADMIN_H
#pragma once
#include"user.h"
#include<string>
using namespace std;

class admin:public user
{
public:
    admin(string i);
    ~admin();
    void set_name(string i);
    string get_name();


private:

    string name;
};


#endif // ADMIN_H
