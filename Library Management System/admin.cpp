#include"admin.h"

admin::admin(string i)
{
    name = i;
}

admin::~admin()
{
}

void admin::set_name(string i)
{
    name = i;
}

string admin::get_name()
{
    return name;
}
