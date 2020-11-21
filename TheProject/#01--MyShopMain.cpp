#include "MyShopDeclarations.h"
using namespace std;

/*************************
--------------------------
Login System
-->Create Account
---->User or Admin
-->Login Account
---->User or Admin
---->Password Re-Entry(action)
---->Forgot Password(action)
------>Password Reset(form)
--------------------------
**************************
--------------------------
New Customer(action)
-->Customer Queue(counter)
-->Purchase(action)
-->Product Purchase(form)
--->Multiple Purchases
-->Inquire(action)
-->Product Inquiry(form)
--->Multiple Inquiries
-->Pending(action)
--->Consider Documents
-->Next Customer(action)
--------------------------
**************************
--------------------------
Stock Products(action)
-->Categories(action)
-->Add stock(password protected action)
//---->Multiple Inputs
---->New Stock(form)
-->Modify Stock(password protected action)
---->ProductID(form)
---->The accessed product(s) (form)
-->Delete Stock(password protected action)
---->ProductID(form)
-->Save Details(action)
-->Identify Descriptions
--------------------------
**************************
--------------------------
Today's Records(file)
-->Authenticate and Backup(ADMIN action)
-->Google Drive(file)
--------------------------
**************************
--------------------------
Products Inquired(sorted file)
-->Clear list(action)
--------------------------
**************************
--------------------------
Business Debts(file)
-->Add Payment(action)
--------------------------
**************************
--------------------------
Customer List(file)
--------------------------
**************************
--------------------------
User(file)
-->Change Name(form)
-->Change Password(form)
-->Remove User(action)
--------------------------
**************************
-->VAT 14%
-->Receipt Format
-->Consider Time
-->Terms and Conditions
-->Documents in ZG-Supplies
-->Type of Transactions
-->Proforma/Invoice
-->Receipt
-->Delivery Note
-->Security Feature
-->Legal Issues
**************************/

bool FileStatus(const string &File)
{
    ifstream out;
    bool Content=false, Error= false;

    if(File=="MainSetPath") out.open(File+type);
    else out.open(path+File+type);

    if(out.is_open() && out.good())
    {
        string fout="\0";
        while(!out.eof())
        {
            getline(out,fout);
            if(fout!="\0") { Content=true; break; }
        }
    }
    else { cout <<"Error in Opening " <<File <<" for Status Checking!!!" <<endl; Error=true; }
    out.clear(); out.close();
    if(Error) exit(1);

    return Content;
}

string SetPath(bool Set)
{
    if(!Set)
    {
        system("MainSetPath.txt");
        Sleep(10000);
    }
    else
    {
        string pathSet="\0";
        bool Error= false;
        ifstream out("MainSetPath.txt");
        if(out.is_open() && out.good())
        {
            string fout="\0";
            while(!out.eof()) getline(out,fout);

            unsigned int c=0;
            while(c<fout.length())
            {
                if(fout[c]=='\\') pathSet += '\\';
                else pathSet += fout[c];
                ++c;
            }
            pathSet += '\\';
        }
        else { cout <<"Error in Opening Set Path Setting Path!!!" <<endl; Error=true; }
        out.clear(); out.close();
        if(Error) exit(1);

        return pathSet;
    }
    return "\0";
}

void UserActivities()
{
	cout <<"Choose Operation:";
	cout <<"\n1.Sign-in Account\n2.Create Account";
	cout <<"\n3.Exit Interface\nChoice: ";
	int chse= 0; cin >>chse; cin.sync();

	switch(chse)
	{
		case 1:
		SystemUser.LoginAccount();
		if(SystemUser.Status()=="Employer") SystemUser.Name().insert(0,"ADMIN");
		FileAccess(UserLoginVerfication(true));
		break;

		case 2:
        SystemUser.CreateAccount();
        if(SystemUser.Name()!="\0" && SystemUser.Pass()!="\0")
        {
            if(SystemUser.Status()=="Employer") SystemUser.Name().insert(0,"ADMIN");
            StoreDetails((PasswordVerfication())&&(!UserLoginVerfication(false)));
        }
		FileAccess(UserLoginVerfication(true));
		break;

		case 3:
		cout <<"\n-------------------------------------------\n";
        cout <<"\tINTERFACE CLOSED";
        cout <<"\n-------------------------------------------\n";
		break;
	}
}

int main()
{
    cout <<"===========================================\n";
    cout <<"\tZEPHMATT GENERAL SUPPLIES\n";
    cout <<"===========================================\n";

    if(!FileStatus("MainSetPath"))
    {
        cout <<"\tSETTING VALID PATHS FOR THE RECORDS";
        cout <<"\n-------------------------------------------\n";
        cout <<"1.Go to the folder where my project is located" <<endl;
        cout <<"2.Select the \"Accounts\" folder" <<endl;
        cout <<"3.Copy the full path of that folder" <<endl;
        cout <<"4.Once you press \"q\" at the \"Proceed\" field," <<endl;
        cout <<"  you will be directed to a file." <<endl;
        cout <<"5.Paste the full file path and save and close"<<endl;
        cout <<"  the document" <<endl;
        cout <<"6.Once you are done, re-run the system" <<endl;
        cout <<"-------------------------------------------\n";
        cout <<"Proceed(q): ";
        char proceed= '\0'; cin.sync(); cin >>proceed;

        if(proceed=='q') SetPath(false);
        else cout <<"Invalid Choice. Please Enter The Correct Character";
        cout <<"\n-------------------------------------------\n";
    }
    else UserActivities();

    cout <<"Done.System Closing\n";
	system("pause");
    return 0;
}
/***************************
--->add exit(1)
--->remove parameters
#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include<windows.h>
#include<stdlib.h>
***************************/
