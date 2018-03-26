#include "singletonlms.h"

singletonlms::singletonlms(){}

LMS* singletonlms::getMySystem(){

    if(mySystem==nullptr)
        mySystem=new LMS;

    return mySystem;
}
State * singletonlms::getMySystem1()
{
    if(st==nullptr)
        st=new reference();

    return st;
}
State * singletonlms::getMySystem2()
{
    if(st1==nullptr)
        st1=new available();

    return st1;
    
}
State * singletonlms::getMySystem3()
{
    if(st2==nullptr)
        st2=new onhold();

    return st2;
    
}
State * singletonlms::getMySystem4()
{
    if(st3==nullptr)
        st3=new Issued();

    return st3;
}

LMS * singletonlms :: mySystem = nullptr;
State * singletonlms::st = nullptr;
State * singletonlms::st1 = nullptr;
State * singletonlms::st2 = nullptr;
State * singletonlms::st3 = nullptr;



/*
reference * singletonlms::mySystem1=nullptr;
available * singletonlms::mySystem2=nullptr;
onhold * singletonlms::mySystem3=nullptr;
Issued * singletonlms::mySystem4=nullptr;
*/

