#include"book.h"
book::book(string ti,string au,bool fl)
{
    title = ti;
    author=au;
    flag = fl;
}
book::~book()
{
}
void book::set_title(string ti)
{
    title = ti;
}

void book::set_author(string au)
{
    author = au;
}

string book::get_title()
{
    return title;
}

string book::get_author()
{
    return author;
}


void book::set_issue(bool i)
{
    flag = i;
}

bool book::get_issue()
{
    return flag;
}

bool book::is_issued()
{
    return flag;
}

void book::add_on_hold_user(user * i)
{
    hold_wale.push_back(i);

}
int book::no_of_holders()
{
    return hold_wale.size();
}

user * book::get_holder_front_holder_wala()
{
    user * temp = hold_wale.front();
    hold_wale.erase(hold_wale.begin() + 0);
    return temp;

}

State * book::get_state()
{
    return pt;
}

void book::set_state(State *s)
{
    pt = s;

}

