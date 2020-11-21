#include "MyShopDeclarations.h"

void SortProductsInquired()
{
    bool Error= false;
    ifstream out(path+"ProductsInquired"+type); ofstream inp(path+"ProductsInquired"+tempType);
    if((out.is_open() && out.good()) && (inp.is_open() && inp.good()))
    {
        vector<string> Names;
        string fout="\0", Name="\0";
        while(!out.eof())
        {
            getline(out,fout);
            fout.erase(27);
            remove(fout.begin(),fout.end(),'|');
            Name.insert(0,fout,5,(remove(fout.begin(),fout.end(),' ')-fout.begin())-5);
            Names.push_back(Name);
            Name="\0";
        }
        out.clear();
        out.seekg(0,ios::beg);

        map<string,int> Sorted;
        int c=0, Count=0, loop=0;

        while(loop<Names.size())
        {
            Count= count(Names.begin(),Names.end(),Names[c]);
            Sorted.insert(pair<string,int>(Names[c++],Count)); ++loop;
        }

        multimap<int,string,greater<int>> Final;
        map<string,int>::iterator pSorted= Sorted.begin();
        while(pSorted!=Sorted.end())
        { Final.insert(pair<int,string>(pSorted->second,pSorted->first)); ++pSorted; }

        c=0; Count=0;
        fout= "\0", Name="\0";
        multimap<int,string>::iterator pFinal= Final.begin();

        bool First=true;
        while(c<Final.size())
        {
            Name= ("|" + pFinal->second);
            while(!out.eof())
            {
                getline(out,fout);
                if(search(fout.begin(),fout.end(),Name.begin(),Name.end())!=fout.end())
                {
                    if(First) { inp <<fout; First=false; }
                    else inp <<"\n" <<fout;
                }
            }
            ++pFinal; ++c; out.clear();
            out.seekg(0,ios::beg);
        }
    }
    else { cout <<"Error in Opening Today's Records File for Sorting" <<endl; Error= true; }
    out.clear(); out.close(); inp.clear(); inp.close();

    remove("C:\\Users\\user\\Documents\\WORK\\3rd_Year_Sem1\\2205_Software_Computing_Project\\MyShop_Code\\Accounts\\ProductsInquired.txt");
    rename("C:\\Users\\user\\Documents\\WORK\\3rd_Year_Sem1\\2205_Software_Computing_Project\\MyShop_Code\\Accounts\\ProductsInquired(2).txt","C:\\Users\\user\\Documents\\WORK\\3rd_Year_Sem1\\2205_Software_Computing_Project\\MyShop_Code\\Accounts\\ProductsInquired.txt");

    if(Error) exit(1);
}

void ProductsInquired(bool RecordEntry)
{
    bool Error= false;
    if(RecordEntry)
    {
        ofstream inp(path+"ProductsInquired"+type,ios::ate|ios::app);
        if(inp.is_open() && inp.good())
        {
            if(FileStatus("ProductsInquired")) inp <<endl;
            inp <<"#####"; Spacer(inp,"#####",11);

            cout <<"Product: "; cin.sync(); getline(cin,InquiredProduct.Name());
            inp <<"|" <<InquiredProduct.Name(); Spacer(inp,InquiredProduct.Name(),15);

            cout <<"Brand: "; cin.sync(); getline(cin,InquiredProduct.Brand());
            inp <<"|" <<InquiredProduct.Brand(); Spacer(inp,InquiredProduct.Brand(),17);

            cout <<"Color: "; cin.sync(); getline(cin,InquiredProduct.Color());
            inp <<"|" <<InquiredProduct.Color(); Spacer(inp,InquiredProduct.Color(),14);

            cout <<"Description: "; cin.sync(); getline(cin,InquiredProduct.Description());
            inp <<"|" <<InquiredProduct.Description(); Spacer(inp,InquiredProduct.Description(),24);

            cout <<"Size: "; cin.sync(); getline(cin,InquiredProduct.Size());
            inp <<"|" <<InquiredProduct.Size();
            cout <<"-------------------------------------------\n";
        }
        else { cout <<"Error in Opening Products Inquired File for Record Insertion" <<endl; Error= true; }
        inp.clear(); inp.close();
        if(Error) exit(1);
        SortProductsInquired();
    }
    else
    {
        cout <<"PRODUCT ID"; Spacer(cout,"PRODUCT ID",11);
        cout <<"|PRODUCT"; Spacer(cout,"PRODUCT",15);
        cout <<"|BRAND"; Spacer(cout,"BRAND",17);
        cout <<"|COLOR"; Spacer(cout,"COLOR",14);
        cout <<"|DESCRIPTION"; Spacer(cout,"DESCRIPTION",24);
        cout <<"|SIZE" <<endl;

        ifstream out(path+"ProductsInquired"+type);
        if(out.is_open() && out.good())
        {
            string fout="\0";
            while(!out.eof())
            { getline(out,fout); cout <<fout <<endl; }
            cout <<"------------------------------------------------------------------------------------------------\n";
        }
        else { cout <<"Error in Opening Products Inquired File for Records Display" <<endl; Error= true; }
        out.clear(); out.close();
        if(Error) exit(1);

        cout <<"1.Clear Products Inquired\t2.Back(Main Menu)" <<endl;
        int choose=0;
        cout <<"Choose: "; cin.sync(); cin >>choose;
        switch(choose)
        {
            case 1:
            {
                cout <<"\n-------------------------------------------\n";
                cout <<"\tPRODUCTS INQUIRED INFORMATION CLEARING";
                cout <<"\n-------------------------------------------\n";
                cout <<"Deletion in Progress..."; Sleep(10000);
                cout <<"\r"; Spacer(cout,"Backup in Progress...",50); cout <<"\r";

                Error= false;
                ofstream inp(path+"ProductsInquired"+type,ios::trunc);
                if(!(inp.is_open() && inp.good()))
                { cout <<"Error in Opening Products Inquired File for Deletion" <<endl; Error= true; }
                inp.clear(); inp.close();
                if(Error) exit(1);

                cout <<"Deletion Complete" <<endl;
            }

            case 2:
                cout <<"-------------------------------------------";
                FileAccess(true);
            break;
        }
    }
}
