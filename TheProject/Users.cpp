#include "MyShopDeclarations.h"

void Users()
{
    cout <<"1.Change User Details\t2.Delete User Account\n3.Back(Main menu)" <<endl;

    int choose=0;
    cout <<"Choose: "; cin.sync(); cin >>choose;
    switch(choose)
    {
        case 1:
        {
            cout <<"-------------------------------------------\n";
            cout <<"\tCHANGE ACCOUNT DETAILS";
            cout <<"\n-------------------------------------------\n";
            cout <<"1.Change User Name.\t2.Change Password.\n3.Back(Main Menu)\nChoice: ";
            int choose= 0; cin >>choose;
            cout <<"-------------------------------------------";

            if(choose==1) { ChangeDetails(choose); cout <<"-------------------------------------------"; }
            else if(choose==2) { ChangeDetails(choose); cout <<"-------------------------------------------";}
            else if(choose==3) ;
            FileAccess(true);
        }
        break;

        case 2:
        {
            cout <<"-------------------------------------------\n";
            cout <<"\tDELETE ACCOUNT";
            cout <<"\n-------------------------------------------\n";
            DeleteAccount();
        }
        break;

        case 3:
            cout <<"-------------------------------------------";
            FileAccess(true);
        break;
    }
}
