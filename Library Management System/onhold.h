#ifndef ONHOLD_H
#define ONHOLD_H
#include"state.h"
#include "user.h"
#include "libitem.h"
#include "date.h"
#include "loan.h"



class onhold:public State
{
public:
    onhold();
    void add_loan(user * u,Libitem*li,Date ida,Date rda,loan *l);
};

#endif // ONHOLD_H
