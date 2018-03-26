#include"Libitem.h"

Libitem::Libitem()
{
}
Libitem::~Libitem()
{
}
void Libitem::add_loan(loan * lo)
{
    loa.push_back(lo);
}

void Libitem::remove_loan(loan *l)
{
     user * u = l->get_user();
     u->remove_loan(l);
     this->remov_loan(l);
     delete l;


}

void Libitem::remov_loan(loan * l)
{
    for(int i=0;i<loa.size();i++)
    {
        if(loa[i]==l)
        {
            loa.erase(loa.begin() + i);
        }
    }

}

