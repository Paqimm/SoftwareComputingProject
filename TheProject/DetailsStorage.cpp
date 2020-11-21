#include "MyShopDeclarations.h"
using namespace std;

void StoreDetails(bool Verfication)
{
	if(Verfication)
	{
	    bool Error= false;
		ofstream inp(path+"SystemUsers"+type,ios::ate|ios::app);
		if(inp.is_open() && inp.good())
		{
		    if(FileStatus("SystemUsers")) inp <<endl;
		    inp <<"####"; Spacer(inp,"####",5); //UserID
			inp <<"|" <<SystemUser.Name();
			Spacer(inp,SystemUser.Name(),20); inp <<"|" <<SystemUser.Pass();

            cout <<"\n-------------------------------------------\n";
			cout <<"Details Stored!!!" <<endl;
            cout <<"-------------------------------------------\n";
		}
		else { cerr <<"Error in Opening File for Storing User Details!!!"; Error= true; }

        inp.clear(); inp.close();
        if(Error) exit(1);

	}
	else
    {
        cout <<"\n-------------------------------------------\n";
        cout <<"Details Not Stored!!!" <<endl;
        cout <<"-------------------------------------------\n";
    }
}
/***********************
#include<iostream>
#include<fstream>
#include<windows.h>
#include<stdlib.h>
***********************/
