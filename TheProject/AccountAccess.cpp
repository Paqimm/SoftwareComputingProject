#include "MyShopDeclarations.h"

void FileAccess(bool Verfication)
{
	while(kbhit()) getch();
	if(Verfication)
	{
	    if(SystemUser.Status()=="Employer")
        {
            if(SystemUser.Name().compare(0,5,"ADMIN")==0) SystemUser.Name().erase(0,5);
            cout <<"\n\nWelcome Back " <<SystemUser.Name() <<"\nWhat Do You Wish To Do:\n";
            cout <<"1.New Customer\n2.Stock Products" <<endl;
            cout <<"3.Today's Records\n4.Products Inquired" <<endl;
            cout <<"5.Business Debts\n6.Customer List" <<endl;
            cout <<"7.Users\n8.User Log Out\nChoose: ";
            int chse=0; cin >>chse;

            switch(chse)
            {
                case 1:
                    cout <<"\n-------------------------------------------\n";
                    cout <<"\tNEW CUSTOMER";
                    cout <<"\n-------------------------------------------\n";
                    NewCustomer();
                break;

                case 2:
                    cout <<"\n-------------------------------------------\n";
                    cout <<"\tSTOCK PRODUCTS";
                    cout <<"\n-------------------------------------------\n";
                    StockProducts();
                break;
                case 3:
                    cout <<"\n-------------------------------------------\n";
                    cout <<"\tTODAY'S RECORDS";
                    cout <<"\n-------------------------------------------\n";
                    system("C:\\Users\\user\\Documents\\WORK\\3rd_Year_Sem1\\2205_Software_Computing_Project\\MyShop_Code\\Accounts\\TodaysRecords.txt");
                    TodaysRecords(true);
                break;
                case 4:
                    cout <<"\n------------------------------------------------";
                    cout <<"------------------------------------------------\n";
                    cout <<"\tPRODUCTS INQUIRED";
                    cout <<"\n------------------------------------------------";
                    cout <<"------------------------------------------------\n";
                    ProductsInquired();
                break;
                case 5:
                    cout <<"\n-------------------------------------------\n";
                    cout <<"\tBUSINESS DEBTS";
                    cout <<"\n-------------------------------------------\n";
                    BusinessDebts(true);
                break;
                case 6:
                    cout <<"\n-------------------------------------------\n";
                    cout <<"\tCUSTOMER LIST";
                    cout <<"\n-------------------------------------------\n";
                    CustomerList(true);
                break;
                case 7:
                    cout <<"\n-------------------------------------------\n";
                    cout <<"\tUSER ACCOUNT";
                    cout <<"\n-------------------------------------------\n";
                    //Users(SystemUser.Name(),SystemUser.Pass());
                    Users();
                break;

                case 8:
                    cout <<"\n-------------------------------------------\n";
                    cout <<"\tLOGGING OUT FROM THE SYSTEM";
                    cout <<"\n-------------------------------------------\n";
                break;
            }
        }
        else
        {
            cout <<"\n\nWelcome Back " <<SystemUser.Name() <<"\nWhat Do You Wish To Do:\n";
            cout <<"1.New Customer\n2.Customer List" <<endl;
            cout <<"3.Users\n4.User Log Out\nChoose: ";
            int chse=0; cin >>chse;
            switch(chse)
            {
                case 1:
                    cout <<"\n-------------------------------------------\n";
                    cout <<"\tNEW CUSTOMER";
                    cout <<"\n-------------------------------------------\n";
                    NewCustomer();
                break;

                case 2:
                    cout <<"\n-------------------------------------------\n";
                    cout <<"\tCUSTOMER LIST";
                    cout <<"\n-------------------------------------------\n";
                    CustomerList(true);
                break;
                case 3:
                    cout <<"\n-------------------------------------------\n";
                    cout <<"\tUSER ACCOUNT";
                    cout <<"\n-------------------------------------------\n";
                    Users();
                break;

                case 4:
                    cout <<"\n-------------------------------------------\n";
                    cout <<"\tLOGGING OUT FROM THE SYSTEM";
                    cout <<"\n-------------------------------------------\n";
                break;
            }
        }
    }

	else
    {
        if(FileStatus("SystemUsers"))
        {
            if(SystemUser.Trial()==0)
            {
                cout <<"\n\nIncorrect User Details. Choose an Operation:";
                cout <<"\n1.Re-try Account Login(One Trial)\n2.Forgot Password\n";

                int choice=0;
                cout <<"Choose: "; cin.sync(); cin >>choice;

                switch(choice)
                {
                    case 1:
                        ++SystemUser.Trial();
                        SystemUser.LoginAccount();
                        if(SystemUser.Status()=="Employer") SystemUser.Name().insert(0,"ADMIN");
                        FileAccess(UserLoginVerfication(true));
                    break;

                    case 2:
                        cout <<"\n-------------------------------------------\n";
                        cout <<"\tFORGOT PASSWORD";
                        cout <<"\n-------------------------------------------\n";
                        SystemUser.ForgotPassword();
                    break;

                    default:
                        cout <<"\n-------------------------------------------\n";
                    break;
                }
            }
            else
            {
                cout <<"\n\nContact Admin For Access to The System";
                cout <<"\n-------------------------------------------\n";
                cout <<"\tFORGOT PASSWORD";
                cout <<"\n-------------------------------------------\n";
                SystemUser.ForgotPassword();
            }
        }
        else
        {
            cout <<"\nThere are no Accounts Registered in the System" <<endl;
            cout <<"Create an Account and Login to access the System" <<endl;
            cout <<"-------------------------------------------\n";
        }
    }
}
/****************************
#include<iostream>
#include<conio.h>
#include<fstream>
#include<stdlib.h>
#include<windows.h>
****************************/
