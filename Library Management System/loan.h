#ifndef LOAN_H
#define LOAN_H

#pragma once
#include"Libitem.h"
#include"user.h"
#include"date.h"
#include<vector>
#include<string>
using namespace std;
class user;
class Libitem;
class Date;

class loan
{
public:
    loan(user * u,Libitem * i,const Date & issue_date,const Date & return_date);

~loan();
    string get_name_of_libitem();
    string get_name_of_user();
    Date getida ();
    Date getrda();

    user * get_user();
    Libitem * get_item();

private:
    user * users;
    Libitem * libraryitem;
    Date i_date;
    Date r_date;
};



#endif // LOAN_H
