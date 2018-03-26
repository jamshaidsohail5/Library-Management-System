#include"student.h"

student::student(string n)
{
    name = n;
}

student::~student()
{
}

void student::set_name(string i)
{
    name = i;
}

string student::get_name()
{
    return name;
}
