#include"user.h"

user::user()
{
}

user::~user()
{
}

void user::add_loan(loan * lo)
{
    loa.push_back(lo);
}
bool user::check_if_already_issued_or_not(string im)
{
    for(int i=0;i<loa.size();i++)
    {
        if(loa[i]->get_name_of_libitem().compare(im)==0)
        {
            return true;
        }
    }
    return false;
}
vector<loan *> user::show_all_loans()
{
    return loa;
}

void user::remove_loan(loan *l)
{
        for(int i=0;i<loa.size();i++)
        {
            if(loa[i]==l)
            {
                loa.erase(loa.begin() + i);
            }
        }


}
loan * user::search_loan(string n,string n1)
{
    for(int i=0;i<loa.size();i++)
    {
        if((loa[i]->get_name_of_libitem().compare(n)==0) &&(loa[i]->get_name_of_user().compare(n1)==0))
        {
            return loa[i];
        }
    }
    return nullptr;
}
