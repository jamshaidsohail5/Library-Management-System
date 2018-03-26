#ifndef STATE_H
#define STATE_H
#pragma once
#include"user.h"
#include"libitem.h"
#include"date.h"
#include"loan.h"


class user;
class Libitem;
class Date;
class loan;

class State
{
public:
    State();
    virtual void add_loan(user * u,Libitem*li,Date ida,Date rda,loan *l)=0;
};

#endif // STATE_H
