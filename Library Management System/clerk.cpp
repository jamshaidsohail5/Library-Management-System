#include"clerk.h"

clerk::clerk(string n)
{
    name = n;

}

clerk::~clerk()
{
}

void clerk::set_name(string i)
{
    name = i;
}

string clerk::get_name()
{
    return name;
}
