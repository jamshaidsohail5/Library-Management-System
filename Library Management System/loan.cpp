#include "loan.h"


loan::loan(user * u, Libitem * i,const Date & issue_date, const Date & return_date):i_date(issue_date),r_date(return_date)
{

    /*
      this->users = u;
   this->libraryitem = i;
   u->add_loan(this);
   i->add_loan(this);

 */
    this->users = u;
    this->libraryitem = i;


    i->get_state()->add_loan(u,i,issue_date,return_date,this);

}

loan::~loan(){}

string loan::get_name_of_libitem()
{
    return libraryitem->get_title();
}
string loan::get_name_of_user()
{
    return users->get_name();
}
Date loan::getida()
{
    return i_date;
}

Date loan::getrda()
{
    return r_date;
}


user * loan::get_user()
{
    return users;
}

Libitem * loan::get_item()
{
    return libraryitem;
}

