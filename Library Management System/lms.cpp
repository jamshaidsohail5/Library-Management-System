#include"lms.h"
#include<string>
#include<iostream>
using namespace std;
LMS::LMS(){

}
LMS::~LMS()
{
}
void LMS::add_users(user *u)
{
    users.push_back(u);
}
void LMS::add_lib_item(Libitem * lib)
{
libraryitems.push_back(lib);
}
user * LMS::search_user(string n)
{
    for(int i=0;i<users.size();i++)
    {
        if(users[i]->get_name().compare(n)==0)
        {
            return users[i];
        }

    }
    return nullptr;
}

Libitem * LMS::search_items(string n)
{
    for (int i = 0; i < libraryitems.size(); i++)
    {
        if (libraryitems[i]->get_title().compare(n) == 0)
        {
            return libraryitems[i];
        }
    }
    return nullptr;
}
Libitem* LMS::search_by_author(string n)
{
    for(int i=0;i<libraryitems.size();i++)
    {
        if(libraryitems[i]->get_author().compare(n)==0)
        {
            return libraryitems[i];

        }
    }
    return nullptr;
}

bool LMS::searchitem(string n)
{
    for (int i = 0; i < libraryitems.size(); i++)
    {
        if (libraryitems[i]->get_title().compare(n) == 0)
        {
            return true;
        }
    }
    return false;
}
bool LMS::searchuser(string n){

    for(int i=0;i<users.size();i++)
    {
        if(users[i]->get_name().compare(n)==0)
        {
            return true;
        }
    }
    return false;

}
void LMS::update_student(string n)
{
    for(int i=0;i<users.size();i++)
    {
        if(users[i]->get_name().compare(n)==0)
        {
            users[i]->set_name(n);
        }
    }
}
void LMS::remove_item(string n)
{
    for(int i=0;i<libraryitems.size();i++)
    {
        if(libraryitems[i]->get_title().compare(n)==0)
        {
            libraryitems.erase(libraryitems.begin() + i);
        }
    }
}
