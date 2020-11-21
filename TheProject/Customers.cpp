#include "MyShopDeclarations.h"
using namespace std;

void Spacer(ostream &inp, const string &Word, const int &Size)
{ for(int space=Size-Word.size(); space>0; --space) inp <<" "; }

void CustomerList(bool Display)
{
    bool Error= false;
    string fout= "\0";
    ifstream out(path+"Contacts"+type);
    ofstream inp(path+"Contacts"+type,ios::ate|ios::app);

    if(!Display)
    {
        if((inp.is_open() && inp.good()) && (out.is_open() && out.good()))
        {
            bool Exist= false;
            while(!out.eof())
            {
                getline(out,fout);
                if(!fout.empty() &&
                  (fout.compare(27,CurrentCustomer.Contact().size(),CurrentCustomer.Contact())==0)) Exist= true;
            }

            if(!Exist)
            {
                inp <<((FileStatus("Contacts"))?"\n####":"####");
                Spacer(inp,"####",5); //CustomerID
                inp <<"|" <<CurrentCustomer.Name();
                Spacer(inp,CurrentCustomer.Name(),20);
                inp <<"|" <<CurrentCustomer.Contact();
            }
        }
        else
        {
            if(out.bad()) cout <<"Error in opening File for Checking Customer Details!!!" <<endl;
            if(inp.bad()) cout <<"Error in opening File for Storing Customer Details!!!" <<endl;
            Error= true;
        }
    }
    else
    {
        if(out.is_open() && out.good())
        {
            cout <<"ID"; Spacer(cout,"ID",5);
            cout <<"|NAME"; Spacer(cout,"NAME",20);
            cout <<"|CONTACT" <<endl;

            while(!out.eof())
            { getline(out,fout); cout <<fout <<endl; }
            cout <<"-------------------------------------------\n";
        }
        else { cout <<"Error in Opening Customer File for Records Display!!!" <<endl; Error= true; }

        cout <<"1.Back(Main Menu)" <<endl;
        int choose=0;
        cout <<"Choose: "; cin.sync(); cin >>choose;
        if(choose==1)
        {
            cout <<"-------------------------------------------";
            FileAccess(true);
        }
        else cout <<"Invalid Option Selected!!!" <<endl;
    }
    out.clear(); out.close();
    inp.clear(); inp.close();
    if(Error) exit(1);
}
