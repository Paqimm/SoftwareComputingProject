#include "MyShopDeclarations.h"
using namespace std;

string UserAccount::name;
string UserAccount::password;
string UserAccount::status;

UserAccount::UserAccount()
{ x1=x2=trials= 0; }

string &UserAccount::Name()
{ return name; }

string UserAccount::Pass()
{ return password; }

string &UserAccount::Status()
{ return status; }

int &UserAccount::Trial()
{ return trials; }

void UserAccount::ClearLine()
{
    x3[x2]= x1;
    ++x2;
}

void UserAccount::CreateAccount()
{
    cout <<"\n-------------------------------------------\n";
    cout <<"\tCREATE ACCOUNT";
    cout <<"\n-------------------------------------------\n";
    cout <<"(Interface Closes if any Detail Field is Empty)" <<endl;
    cout <<"(Interface Closes if the Password Don't Match)" <<endl;
    cout <<"(Password should contain numbers, special)" <<endl;
    cout <<"(characters, both capital letters and small letters)" <<endl;
    cout <<"-------------------------------------------\n";
    cout <<"Choose Your Status:\n1.Employer\t2.Employee\nChoose: ";

    int choose=0; cin.sync(); cin >>choose;
    switch(choose)
    {
        case 1:
        {
            SystemUser.Status()= "Employer";
            cout <<"-------------------------------------------\n";
            cout <<"Name:\n"; cin.sync(); getline(cin,name);
            cout <<"Create "; Password();
            string CreatedPassword= password;
            cout <<"\nConfirm "; Password();
            string ConfirmPassword= password;

            if(CreatedPassword!=ConfirmPassword)
            {
                cout <<"\n-------------------------------------------\n";
                cout <<"The Passwords Entered Should Match" <<endl;
                cout <<"-------------------------------------------\n";
                system("pause");
                exit(1);
            }

            if(name.empty() || password.empty())
            {
                cout <<"\n-------------------------------------------";
                cout <<((name.empty() && password.empty())?"\nName and Password Fields Can't Be Left Blank":(name.empty())?"\nName Field Can't Be Left Blank":"\nPassword Field Can't Be Left Blank") <<endl;
                cout <<"-------------------------------------------" <<endl;
                system("pause");
                exit(1);
            }
        }
        break;

        case 2:
        {
            SystemUser.Status()= "Employee";
            cout <<"-------------------------------------------\n";
            cout <<"Name:\n"; cin.sync(); getline(cin,name);
            cout <<"Create "; Password();
            string CreatedPassword= password;
            cout <<"\nConfirm "; Password();
            string ConfirmPassword= password;

            if(CreatedPassword!=ConfirmPassword)
            {
                cout <<"\n-------------------------------------------\n";
                cout <<"The Passwords Entered Should Match" <<endl;
                cout <<"-------------------------------------------\n";
                system("pause");
                exit(1);
            }

            if(name.empty() || password.empty())
            {
                cout <<"\n-------------------------------------------";
                cout <<((name.empty() && password.empty())?"\nName and Password Fields Can't Be Left Blank":(name.empty())?"\nName Field Can't Be Left Blank":"\nPassword Field Can't Be Left Blank") <<endl;
                cout <<"-------------------------------------------" <<endl;
                system("pause");
                exit(1);
            }
        }
        break;

        default:
            cout <<"-------------------------------------------" <<endl;
        break;
    }
}

void UserAccount::LoginAccount()
{
    cout <<"\n-------------------------------------------\n";
    cout <<"\tLOGIN ACCOUNT";
    cout <<"\n-------------------------------------------\n";
    cout <<"Choose Your Status:\n1.Employer\t2.Employee\nChoose: ";

    int choose=0; cin.sync(); cin >>choose;
    switch(choose)
    {
        case 1:
            SystemUser.Status()= "Employer";
            cout <<"-------------------------------------------\n";
            cout <<"Name:\n"; cin.sync(); getline(cin,name);
            Password();
            cout <<"\n-------------------------------------------";
        break;

        case 2:
            SystemUser.Status()= "Employee";
            cout <<"-------------------------------------------\n";
            cout <<"Name:\n"; cin.sync(); getline(cin,name);
            Password();
            cout <<"\n-------------------------------------------";
        break;
    }
}

/********************
#include<iostream>
#include<windows.h>
*********************/
