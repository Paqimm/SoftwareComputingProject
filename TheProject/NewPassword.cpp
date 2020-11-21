#include "MyShopDeclarations.h"

void UserAccount::NewPassword()
{
    cout <<"\n-------------------------------------------\n";
    cout <<"\tNEW PASSWORD";
    cout <<"\n-------------------------------------------\n";
    cout <<"New "; Password();
    string NewSetPassword= password;
    cout <<"\nConfirm "; Password();
    string ConfirmSetPassword= password;

    if(!PasswordVerfication()) NewPassword();
    else
    {
        if(NewSetPassword==ConfirmSetPassword)
        {
            ifstream out(path+"SystemUsers"+type); ofstream inp(path+"SystemUsers"+tempType);

            if((out.is_open() && out.good()) && (inp.is_open() && inp.good()))
            {
                string fout="\0";
                bool First= true;

                while(!out.eof())
                {
                    getline(out,fout);
                    if(fout.compare(6,name.size(),name)==0)
                    {
                        fout.erase(27); fout.insert(27,password);
                        if(First) { inp <<fout; First=false; }
                        else inp <<"\n" <<fout;
                    }
                    else
                    {
                        if(First) { inp <<fout; First=false; }
                        else inp <<"\n" <<fout;
                    }
                }
            }
            else cout <<"Error in Opening Account for Setting New Password" <<endl;
            out.clear(); out.close(); inp.clear(); inp.close();

            string Delete=path+"SystemUsers"+type, Rename=path+"SystemUsers"+tempType;
            remove(Delete.c_str()); rename(Rename.c_str(),Delete.c_str());


            cout <<"\n-------------------------------------------\n";
            cout <<"Passwords Status: New Password is Set" <<endl;
            cout <<"-------------------------------------------\n";
        }
        else
        {
            cout <<"\n-------------------------------------------\n";
            cout <<"Passwords Status: New Password is Not Set" <<endl;
            cout <<"-------------------------------------------\n";
        }
    }
}
/*********************
#include<iostream>
#include<fstream>
#include<algorithm>
**********************/
