#ifndef CLERK_H
#define CLERK_H
#include"user.h"
#pragma once
class clerk:public user
{
public:
    clerk(string n);
    ~clerk();
    void set_name(string i);
    string get_name();



private:
    string name;

};


#endif // CLERK_H
