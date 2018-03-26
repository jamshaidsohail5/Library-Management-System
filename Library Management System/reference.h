#ifndef REFERENCE_H
#define REFERENCE_H
#include"state.h"
#include "user.h"
#include "libitem.h"
#include "date.h"
#include "loan.h"



class reference:public State
{
public:
    reference();
    void add_loan(user * u,Libitem*li,Date ida,Date rda,loan *l);
};

#endif // REFERENCE_H
