#include "MyShopDeclarations.h"
using namespace std;

void DeleteAccount()
{
    cout <<"Are You Sure You Want to Delete Your Account?\n1.Yes\n2.No\nChoice: ";
    int chse=0; cin >>chse;
    cout <<"-------------------------------------------" <<endl;

    if(chse==1)
    {
        bool Error= false;
        string fout= "\0";
        ifstream out(path+"SystemUsers"+type); ofstream inp(path+"SystemUsers"+tempType);

        if((inp.is_open() && inp.good()) && (out.is_open() && out.good()))
        {
            cout <<"Deleting Account...."; Sleep(10000);
            cout <<"\r";
            for(int c=0; c<A; ++c) cout <<" ";
            cout <<"\r";

            bool first= true;
            while(!out.eof())
            {
                getline(out,fout);
                if(search(fout.begin(),fout.end(),SystemUser.Name().begin(),SystemUser.Name().end())!=fout.end()) ;
                else if(first) { inp <<fout; first= false; }
                else inp <<"\n" <<fout;
            }
            cout <<"Account Deleted Successfully. Goodbye " <<SystemUser.Name() <<endl;
            cout <<"-------------------------------------------" <<endl;
        }
        else
        { cerr <<"Error in Opening Files for Deleting User Account!!!"; Error= true; }

        inp.clear(); out.clear(); inp.close(); out.close();
        remove("C:\\Users\\user\\Documents\\WORK\\3rd_Year_Sem1\\2205_Software_Computing_Project\\MyShop_Code\\Accounts\\SystemUsers.txt");
        rename("C:\\Users\\user\\Documents\\WORK\\3rd_Year_Sem1\\2205_Software_Computing_Project\\MyShop_Code\\Accounts\\SystemUsers(2).txt","C:\\Users\\user\\Documents\\WORK\\3rd_Year_Sem1\\2205_Software_Computing_Project\\MyShop_Code\\Accounts\\SystemUsers.txt");
        if(Error) exit(1);
    }

    else if(chse==2)
    {
        cout <<"Account Not Deleted.Thank You " <<SystemUser.Name() <<" For Staying." <<endl;
        cout <<"-------------------------------------------" <<endl; FileAccess(true);
    }
}

/**********************
#include<iostream>
#include<conio.h>
#include<fstream>
#include<stdlib.h>
#include<windows.h>
**********************/
