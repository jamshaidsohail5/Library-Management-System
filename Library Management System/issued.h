#ifndef ISSUED_H
#define ISSUED_H
#include"state.h"
#include "user.h"
#include "libitem.h"
#include "date.h"
#include "loan.h"

class Issued:public State
{
public:
    Issued();
    void add_loan(user * u,Libitem*li,Date ida,Date rda,loan *l);
};

#endif // ISSUED_H
