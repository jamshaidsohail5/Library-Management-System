#include "available.h"

available::available()
{

}

void available::add_loan(user * u,Libitem*li,Date ida,Date rda,loan *l){
    u->add_loan(l);
    li->add_loan(l);
}
