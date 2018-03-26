#ifndef AVAILABLE_H
#define AVAILABLE_H
#include"state.h"
#include "user.h"
#include "libitem.h"
#include "date.h"
#include "loan.h"
class user;
class Libitem;
class Date;
class loan;

class available:public State
{

    user * u;
    Libitem *o;
public:
    available();
    void add_loan(user * u,Libitem*li,Date ida,Date rda,loan *l);
};

#endif // AVAILABLE_H
