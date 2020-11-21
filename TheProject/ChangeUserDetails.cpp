#include "MyShopDeclarations.h"
using namespace std;

void ChangeDetails(int choose)
{
	while(kbhit()) getch();

	string fout= "\0", Cname= SystemUser.Name();
	bool Error= false, Unverified= false, First=true;
	ifstream out(path+"SystemUsers"+type); ofstream inp(path+"SystemUsers"+tempType);

	if((inp.is_open() && inp.good()) && (out.is_open() && out.good()))
	{
		if(choose==1)
		{
			cout <<"\nEnter New Name: "; cin.sync(); getline(cin,SystemUser.Name());
			if(UserLoginVerfication(false)) Unverified= true;
			else
			{
				while(!out.eof())
				{
					getline(out,fout);
					if(search(fout.begin(),fout.end(),Cname.begin(),Cname.end())!=fout.end())
                    {
                        if(SystemUser.Status()=="Employer")
                        {
                            inp <<((First)?"####":"\n####"); Spacer(inp,"####",5);
                            inp <<"|ADMIN" <<SystemUser.Name();
                            Spacer(inp,("ADMIN"+SystemUser.Name()),20); inp <<"|" <<SystemUser.Pass();
                            SystemUser.Name().insert(0,"ADMIN");
                            if(First) First=false;
                        }
                        else
                        {
                            inp <<((First)?"####":"\n####"); Spacer(inp,"####",5);
                            inp <<"|" <<SystemUser.Name();
                            Spacer(inp,SystemUser.Name(),20); inp <<"|" <<SystemUser.Pass();
                            if(First) First=false;
                        }
                    }
                    else
                    {
                        inp <<((First)? fout:"\n"+fout);
                        if(First) First=false;
                    }
				}
				if(SystemUser.Name().compare(0,5,"ADMIN")==0) SystemUser.Name().erase(0,5);
				cout <<"Name Successfully Changed. Welcome " <<SystemUser.Name() <<endl;
			}
		}

		else if(choose==2)
		{
			cout <<"\nEnter New ";
			SystemUser.Password();

			if(!PasswordVerfication()) Unverified= true;
			else
			{
				while(!out.eof())
				{
					getline(out,fout);
					if(search(fout.begin(),fout.end(),Cname.begin(),Cname.end())!=fout.end())
                    {
                        if(SystemUser.Status()=="Employer")
                        {
                            inp <<((First)?"####":"\n####"); Spacer(inp,"####",5);
                            inp <<"|ADMIN" <<SystemUser.Name();
                            Spacer(inp,("ADMIN"+SystemUser.Name()),20); inp <<"|" <<SystemUser.Pass();
                            SystemUser.Name().insert(0,"ADMIN");
                            if(First) First=false;
                        }
                        else
                        {
                            inp <<((First)?"####":"\n####"); Spacer(inp,"####",5);
                            inp <<"|" <<SystemUser.Name();
                            Spacer(inp,SystemUser.Name(),20); inp <<"|" <<SystemUser.Pass();
                            if(First) First=false;
                        }
                    }
					else
                    {
                        inp <<((First)?fout:"\n"+fout);
                        if(First) First=false;
                    }
				}
				cout <<"\nUser Password Successfully Changed." <<endl;
			}
		}
    }

	else { cerr <<"Error in Opening File For Changing Account Details!!"; Error= true; }

	inp.clear(); out.clear(); inp.close(); out.close();
    remove("C:\\Users\\user\\Documents\\WORK\\3rd_Year_Sem1\\2205_Software_Computing_Project\\MyShop_Code\\Accounts\\SystemUsers.txt");
    rename("C:\\Users\\user\\Documents\\WORK\\3rd_Year_Sem1\\2205_Software_Computing_Project\\MyShop_Code\\Accounts\\SystemUsers(2).txt","C:\\Users\\user\\Documents\\WORK\\3rd_Year_Sem1\\2205_Software_Computing_Project\\MyShop_Code\\Accounts\\SystemUsers.txt");
	if(Error || Unverified ) { system("pause"); exit(1); }
}

/**************************
#include<iostream>
#include<conio.h>
#include<fstream>
#include<stdlib.h>
#include<windows.h>
**************************/
