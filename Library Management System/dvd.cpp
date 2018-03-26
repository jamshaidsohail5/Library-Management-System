#include"dvd.h"
dvd::dvd(string ti,bool fl)
{
    title = ti;
    flag = fl;
}

dvd::~dvd() {}


void dvd::set_title(string ti)
{
    title = ti;
}

string dvd::get_title()
{
    return title;
}

void dvd::set_issue(bool i)
{
    flag = i;
}

bool dvd::get_issue()
{
    return flag;
}

bool dvd::is_issued()
{
    return flag;
}
void dvd::add_on_hold_user(user * i)
{
    hold_wale.push_back(i);
}
string dvd::get_author()
{
    return "";
}
int dvd::no_of_holders()
{
    return hold_wale.size();
}
user * dvd::get_holder_front_holder_wala()
{
    user * temp = hold_wale.front();
    hold_wale.erase(hold_wale.begin() + 0);
    return temp;


}
State * dvd::get_state()
{
    return pt;
}

void dvd::set_state(State *s)
{
    pt = s;

}
