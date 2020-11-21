#include "MyShopDeclarations.h"

string Customer::contact;
string Customer::name;
string Customer::ID;

string &Customer::Name()
{ return name; }

string &Customer::Contact()
{ return contact; }

string Customer::CID()
{ return ID; }

void Customer::Details()
{
    cout <<"Customer Name: " <<Name() <<endl;
    cout <<"Customer Contact: " <<Contact() <<endl;
}
