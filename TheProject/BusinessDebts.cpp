#include "MyShopDeclarations.h"

void InsertDebt(bool Exists)
{
    if(Exists)
    {
        bool Error=false;
        ifstream out(path+"BusinessDebts"+type);
        ofstream inp(path+"BusinessDebts"+tempType);

        if((inp.is_open() && inp.good()) && (out.is_open() && out.good()))
        {
            bool first=true;
            string fout="\0";
            while(!out.eof())
            {
                getline(out,fout);
                if((!fout.empty()) && (fout.compare(27,CurrentCustomer.Contact().size(),CurrentCustomer.Contact())==0))
                {
                    int c=39;
                    string Paid="\0", Balance="\0";
                    while(fout[c]!=' ') Paid += fout[c++];

                    c=50;
                    while(fout[c]) Balance += fout[c++];

                    Paid= to_string(int(stod(Balance) + PurchasedProduct.AmountPaid()));
                    Balance= to_string(int(stod(Balance) + (PurchasedProduct.BuyingPrice()-PurchasedProduct.AmountPaid())));

                    fout.erase(38);
                    fout += ("|" + Paid);
                    int Space= 10-Paid.size();
                    while(Space--) fout += " ";
                    fout += ("|" + Balance);

                    if(first) { inp <<fout; first=false; }
                    else inp <<"\n" <<fout;
                }
                else if(first) { inp <<fout; first=false; }
                else inp <<"\n" <<fout;
            }
        }
        else { cout <<"Error in Opening Business Debts File for Debt Addition!!!" <<endl; Error=true; }
        out.clear(); out.close(); inp.clear(); inp.close();
        remove("C:\\Users\\user\\Documents\\WORK\\3rd_Year_Sem1\\2205_Software_Computing_Project\\MyShop_Code\\Accounts\\BusinessDebts.txt");
        rename("C:\\Users\\user\\Documents\\WORK\\3rd_Year_Sem1\\2205_Software_Computing_Project\\MyShop_Code\\Accounts\\BusinessDebts(2).txt","C:\\Users\\user\\Documents\\WORK\\3rd_Year_Sem1\\2205_Software_Computing_Project\\MyShop_Code\\Accounts\\BusinessDebts.txt");
    }
    else
    {
        bool Error= false;
        ofstream inp(path+"BusinessDebts"+type,ios::ate|ios::app);

        if(inp.is_open() && inp.good())
        {
            if(FileStatus("BusinessDebts")) inp <<endl;
            inp <<"####"; Spacer(inp,"####",5);
            inp <<"|" <<CurrentCustomer.Name(); Spacer(inp,CurrentCustomer.Name(),20);
            inp <<"|" <<CurrentCustomer.Contact(); Spacer(inp,CurrentCustomer.Contact(),11);
            inp <<"|" <<PurchasedProduct.AmountPaid(); Spacer(inp,to_string((int)PurchasedProduct.AmountPaid()),10);
            inp <<"|" <<(PurchasedProduct.BuyingPrice()-PurchasedProduct.AmountPaid());
        }
        else { cout <<"Error in Opening Business Debt File for Debt Insertion!!!" <<endl; Error=true; }
        inp.clear(); inp.close();
        if(Error) exit(1);
    }
}

void BusinessDebts(bool Payment)
{
    if(!Payment)
    {
        bool Error=false, Exists=false;
        ifstream out(path+"BusinessDebts"+type);

        if(out.is_open() && out.good())
        {
            string fout="\0";
            while(!out.eof())
            {
                getline(out,fout);
                if((!fout.empty()) && (fout.compare(27,CurrentCustomer.Contact().size(),CurrentCustomer.Contact())==0))
                { Exists=true; }
            }
        }
        else { cout <<"Error in Opening Business Debts File for Confirmation!!!" <<endl; Error= true; }
        out.clear(); out.close();
        if(Error) exit(1);

        InsertDebt(Exists);
    }
    else
    {
        bool Error=false;
        ifstream out(path+"BusinessDebts"+type);

        cout <<"ID"; Spacer(cout,"ID",5);
        cout <<"|NAME"; Spacer(cout,"NAME",20);
        cout <<"|CONTACT"; Spacer(cout,"CONTACT",11);
        cout <<"|PAID"; Spacer(cout,"PAID",10);
        cout <<"|BALANCE" <<endl;

        if(out.is_open() && out.good())
        {
            string fout="\0";
            while(!out.eof())
            { getline(out,fout); cout <<fout <<endl; }
        }
        else { cout <<"Error in Opening Business Record File for Display!!!" <<endl; }
        out.clear(); out.close();
        if(Error) exit(1);

        cout <<"----------------------------------------------------------" <<endl;
        cout <<"1.Add Payment\t2.Back(Main Menu)" <<endl;

        int Choose=0;
        cout <<"Choose: "; cin.sync(); cin >>Choose;
        switch(Choose)
        {
            case 1:
            {
                Error=false;
                out.open(path+"BusinessDebts"+type);
                ofstream inp(path+"BusinessDebts"+tempType);

                if((inp.is_open() && inp.good()) && (out.is_open() && out.good()))
                {
                    double Added=0;
                    string Contact="\0", fout="\0";
                    cout <<"----------------------------------------------------------" <<endl;
                    cout <<"Customer Number: "; cin.sync(); getline(cin,Contact);
                    cout <<"Payment: "; cin.sync(); cin >>Added;
                    cout <<"----------------------------------------------------------" <<endl;

                    bool first= true;
                    while(!out.eof())
                    {
                        getline(out,fout);
                        if((!fout.empty()) && (fout.compare(27,Contact.size(),Contact)==0))
                        {
                            int c=39;
                            string Paid="\0", Balance="\0";
                            while(fout[c]!=' ') Paid += fout[c++];

                            c=50;
                            while(fout[c]) Balance += fout[c++];

                            Paid= to_string(int(stod(Balance) - Added));
                            Balance= to_string(int(stod(Balance) - Added));

                            if(Balance!="0")
                            {
                                fout.erase(38);
                                fout += ("|" + Paid);
                                int Space= 10-Paid.size();
                                while(Space--) fout += " ";
                                fout += ("|" + Balance);

                                if(first) { inp <<fout; first=false; }
                                else inp <<"\n" <<fout;
                            }
                        }
                        else if(first) { inp <<fout; first=false; }
                        else inp <<"\n" <<fout;
                    }
                }
                else { cout <<"Error in Opening Business Debts File for Debt Update!!!" <<endl; Error=true; }

                out.clear(); out.close(); inp.clear(); inp.close();
                remove("C:\\Users\\user\\Documents\\WORK\\3rd_Year_Sem1\\2205_Software_Computing_Project\\MyShop_Code\\Accounts\\BusinessDebts.txt");
                rename("C:\\Users\\user\\Documents\\WORK\\3rd_Year_Sem1\\2205_Software_Computing_Project\\MyShop_Code\\Accounts\\BusinessDebts(2).txt","C:\\Users\\user\\Documents\\WORK\\3rd_Year_Sem1\\2205_Software_Computing_Project\\MyShop_Code\\Accounts\\BusinessDebts.txt");
                if(Error) exit(1);
                BusinessDebts(true);
            }
            break;

            case 2:
                cout <<"----------------------------------------------------------" <<endl;
                FileAccess(true);
            break;
        }
    }
}
