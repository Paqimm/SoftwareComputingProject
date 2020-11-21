#include "MyShopDeclarations.h"

void UserAccount::ForgotPassword()
{
    cout <<"This Action Requires The Administrator's Approval" <<endl;
    cout <<"System Administrator "; Password();

    ifstream out(path+"SystemUsers"+type);

    if(out.is_open() && out.good())
    {
        string fout="\0", AdminTag="ADMIN", Temp="\0", SetPassword="\0";
        while(!out.eof())
        {
            getline(out,fout);
            if(fout.compare(6,5,AdminTag)==0)
            {
                if(fout.compare(27,password.size(),password)==0 && !password.empty())
                {
                    cout <<"\nAuthentication Status: Administrator Approved" <<endl;
                    out.clear(); out.close(); NewPassword();
                }
                else cout <<"\nAuthentication Status: Administrator Not Approved" <<endl;
                break;
            }
        }
    }
    else cout <<"Error in Opening File for System Admin Verification" <<endl;
    out.clear(); out.close();
}
/********************
#include<iostream>
#include<fstream>
#include<algorithm>
********************/
