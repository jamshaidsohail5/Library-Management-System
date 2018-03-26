#ifndef STUDENT_H
#define STUDENT_H
#pragma once
#include"user.h"
class  student:public user
{
public:
     student(string na);
    ~ student();
    void set_name(string i);
    string get_name();


private:
    string name;

};

#endif // STUDENT_H
