#include "MyShopDeclarations.h"

bool PasswordVerfication()
{
	bool Pver=false;
	string password= SystemUser.Pass();
	int entails=0, Small=0, Capital=0, Number=0, Special=0, ver=0;

	if(password.length()>=8)
	{
		for(unsigned int c=0; c<password.length(); ++c)
		{
			if((password[c]=='a'||password[c]=='b'||password[c]=='c'||password[c]=='d'||password[c]=='e'||password[c]=='f'||password[c]=='g'||password[c]=='h'||password[c]=='i'||password[c]=='j'||password[c]=='k'||password[c]=='l'||password[c]=='m'||password[c]=='n'||password[c]=='o'||password[c]=='p'||password[c]=='q'||password[c]=='r'||password[c]=='s'||password[c]=='t'||password[c]=='u'||password[c]=='v'||password[c]=='w'||password[c]=='x'||password[c]=='y'||password[c]=='z') && !Small)
            { ++entails; ++Small; }
			else if((password[c]=='A'||password[c]=='B'||password[c]=='C'||password[c]=='D'||password[c]=='E'||password[c]=='F'||password[c]=='G'||password[c]=='H'||password[c]=='I'||password[c]=='J'||password[c]=='K'||password[c]=='L'||password[c]=='M'||password[c]=='N'||password[c]=='O'||password[c]=='P'||password[c]=='Q'||password[c]=='R'||password[c]=='S'||password[c]=='T'||password[c]=='U'||password[c]=='V'||password[c]=='W'||password[c]=='X'||password[c]=='Y'||password[c]=='Z') && !Capital)
			{ ++entails; ++Capital; }
			else if((password[c]=='0'||password[c]=='1'||password[c]=='2'||password[c]=='3'||password[c]=='4'||password[c]=='5'||password[c]=='6'||password[c]=='7'||password[c]=='8'||password[c]=='9') && !Number)
			{ ++entails; ++Number; }
			else if((password[c]=='~'||password[c]=='!'||password[c]=='@'||password[c]=='#'||password[c]=='$'||password[c]=='%'||password[c]=='^'||password[c]=='&'||password[c]=='_'||password[c]=='-'||password[c]=='+'||password[c]=='|'||password[c]=='='||password[c]==':'||password[c]==';'||password[c]=='.'||password[c]=='?'||password[c]=='<'||password[c]=='>') && !Special)
            { ++entails; ++Special; }
		}
	}
	else
    {
        cout <<"\n-------------------------------------------\n";
        cout <<"\nPassword Should be either 8 or more characters long\n"; ++ver;
    }
	if(entails<4)
    {
        cout <<"\n-------------------------------------------\n";
        cout <<"\nPassword should contain numbers, special characters,\nboth capital letters and small letters\n"; ++ver;
    }
	if(ver==0) Pver= true;
	else Pver= false;

	return Pver;
}

bool UserLoginVerfication(bool exist)
{
	string fout= "\0";
	bool Nver= false, Error=false;

	ifstream out(path+"SystemUsers"+type);
	if(out.is_open() && out.good())
	{
		if(!exist)
		{
		    if(FileStatus("SystemUsers"))
            {
                string Tag= "ADMIN";
                bool TagDuplicate= false, TagPresent=false;

                while(!out.eof())
                {
                    getline(out,fout);
                    if(fout.compare(6,5,Tag)==0) TagPresent= true;
                    if(TagPresent && (SystemUser.Name().compare(0,5,Tag)==0)) TagDuplicate= true;
                    if(TagDuplicate || (fout.compare(6,SystemUser.Name().size(),SystemUser.Name())==0) || (fout.compare(11,SystemUser.Name().size(),SystemUser.Name())==0))
                    {
                        cout <<"\n-------------------------------------------\n";
                        cout <<"User Account Already Exists!!";
                        Nver= true; break;
                    }
                }
            }
		}
		else
		{
            if(FileStatus("SystemUsers"))
            {
                while(!out.eof())
                {
                    getline(out,fout);
                    if(fout.compare(6,SystemUser.Name().size(),SystemUser.Name())==0 && !(SystemUser.Name().empty()))
                    {
                        if(fout.compare(27,SystemUser.Pass().size(),SystemUser.Pass())==0 && !(SystemUser.Pass().empty()))
                        { Nver=true; break; }
                    }
                }
            }
		}
	}
	else { cerr <<"Error in Opening File For Verification!!!"; Error=true; }
	out.clear(); out.close();
	if(Error) exit(1);

	return Nver;
}
/***********************
#include<iostream>
#include<conio.h>
#include<fstream>
#include<windows.h>
#include<stdlib.h>
#include<algorithm>
***********************/
