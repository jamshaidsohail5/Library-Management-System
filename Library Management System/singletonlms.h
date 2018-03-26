#ifndef SINGLETONLMS_H
#define SINGLETONLMS_H
#include"lms.h"
#include"available.h"
#include"reference.h"
#include"onhold.h"
#include"issued.h"
#include"state.h"
class singletonlms
{
    static LMS* mySystem;

public:
    static State * st;
    static State * st1;
    static State * st2;
    static State * st3;

    singletonlms();
    LMS * getMySystem();
    State * getMySystem1();
    State * getMySystem2();
    State * getMySystem3();
    State * getMySystem4();
};
#endif // SINGLETONLMS_H
