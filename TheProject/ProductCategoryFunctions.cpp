#include "MyShopDeclarations.h"

void ProductCategoryFunctions(const string &File)
{
    cout <<"PRODUCT ID"; Spacer(cout,"PRODUCT ID",11);
    cout <<"|CATEGORY ID"; Spacer(cout,"CATEGORY ID",12);
    cout <<"|PRODUCT CODE"; Spacer(cout,"PRODUCT CODE",13);
    cout <<"|PRODUCT"; Spacer(cout,"PRODUCT",15);
    cout <<"|BRAND"; Spacer(cout,"BRAND",17);
    cout <<"|COLOR"; Spacer(cout,"COLOR",14);
    cout <<"|DESCRIPTION"; Spacer(cout,"DESCRIPTION",24);
    cout <<"|SIZE"; Spacer(cout,"SIZE",9);
    cout <<"|QUANTITY"; Spacer(cout,"QUANTITY",13);
    cout <<"|PRICE" <<endl;

    ifstream out; ofstream inp;
    out.open(path+File+type);
    if(out.is_open() && out.good())
    {
        string fout="\0";
        while(!out.eof())
        { getline(out,fout); cout <<fout <<endl; }
    }
    else cout <<"Error in Opening " <<File <<" File for Information Retrieval!!!" <<endl;
    out.clear(); out.close();

    cout <<"-----------------------------------------------------------------------------------------";
    cout <<"-----------------------------------------------------------";
    cout <<"\n1.New Record\t2.Modify Record\t\t3.Delete Record\t\t4.Back(Products Category)" <<endl;

    int choose=0;
    cout <<"Choose: "; cin.sync(); cin >>choose;

    switch(choose)
    {
        case 1:
        {
            inp.open(path+File+type,ios::ate|ios::app);
            if(inp.is_open() && inp.good())
            {
                cout <<"-----------------------------------------------------------------------------------------";
                cout <<"-----------------------------------------------------------\n";
                if(FileStatus(File)) inp <<endl;
                inp <<"####"; Spacer(inp,"####",11);
                inp <<"|####"; Spacer(inp,"####",12);
                inp <<"|####"; Spacer(inp,"####",13);

                cout <<"Product: "; cin.sync(); getline(cin,StoredProduct.Name());
                inp <<"|" <<StoredProduct.Name(); Spacer(inp,StoredProduct.Name(),15);

                cout <<"Brand: "; cin.sync(); getline(cin,StoredProduct.Brand());
                inp <<"|" <<StoredProduct.Brand(); Spacer(inp,StoredProduct.Brand(),17);

                cout <<"Color: "; cin.sync(); getline(cin,StoredProduct.Color());
                inp <<"|" <<StoredProduct.Color(); Spacer(inp,StoredProduct.Color(),14);

                cout <<"Description: "; cin.sync(); getline(cin,StoredProduct.Description());
                inp <<"|" <<StoredProduct.Description(); Spacer(inp,StoredProduct.Description(),24);

                cout <<"Size: "; cin.sync(); getline(cin,StoredProduct.Size());
                inp <<"|" <<StoredProduct.Size(); Spacer(inp,StoredProduct.Size(),9);

                cout <<"Quantity: "; cin.sync(); cin >>StoredProduct.StoredQuantity();
                inp <<"|" <<StoredProduct.StoredQuantity(); Spacer(inp,to_string(StoredProduct.StoredQuantity()),13);

                cout <<"Price: "; cin.sync(); cin >>StoredProduct.Price();
                inp <<"|" <<StoredProduct.Price();
                cout <<"-----------------------------------------------------------------------------------------";
                cout <<"-----------------------------------------------------------" <<endl;
            }
            else cout <<"Error in Opening " <<File <<" File For New Record Insertion!!!" <<endl;
            inp.clear(); inp.close();
            ProductCategoryFunctions(File);
        }
        break;

        case 2:
        {
            bool Error= false;
            out.open(path+File+type); inp.open(path+File+tempType);
            if((out.is_open() && out.good()) && (inp.is_open() && inp.good()))
            {
                string fout="\0", ProductID="\0";
                cout <<"-----------------------------------------------------------------------------------------";
                cout <<"-----------------------------------------------------------" <<endl;
                cout <<"Enter Product ID: "; cin.sync(); cin >>ProductID;

                bool first= true, found=true;
                while(!out.eof())
                {
                    getline(out,fout);
                    if(fout.compare(0,ProductID.size(),ProductID)==0 && !ProductID.empty())
                    {
                        found=false;
                        cout <<"-----------------------------------------------------------------------------------------";
                        cout <<"-----------------------------------------------------------" <<endl;
                        if(first) { inp <<ProductID; Spacer(inp,ProductID,11); first= false; }
                        else { inp <<"\n" <<ProductID; Spacer(inp,ProductID,11); }
                        inp <<"|####"; Spacer(inp,"####",12);
                        inp <<"|####"; Spacer(inp,"####",13);

                        cout <<"Product: "; cin.sync(); getline(cin,StoredProduct.Name());
                        inp <<"|" <<StoredProduct.Name(); Spacer(inp,StoredProduct.Name(),15);

                        cout <<"Brand: "; cin.sync(); getline(cin,StoredProduct.Brand());
                        inp <<"|" <<StoredProduct.Brand(); Spacer(inp,StoredProduct.Brand(),17);

                        cout <<"Color: "; cin.sync(); getline(cin,StoredProduct.Color());
                        inp <<"|" <<StoredProduct.Color(); Spacer(inp,StoredProduct.Color(),14);

                        cout <<"Description: "; cin.sync(); getline(cin,StoredProduct.Description());
                        inp <<"|" <<StoredProduct.Description(); Spacer(inp,StoredProduct.Description(),24);

                        cout <<"Size: "; cin.sync(); getline(cin,StoredProduct.Size());
                        inp <<"|" <<StoredProduct.Size(); Spacer(inp,StoredProduct.Size(),9);

                        cout <<"Quantity: "; cin.sync(); cin >>StoredProduct.StoredQuantity();
                        inp <<"|" <<StoredProduct.StoredQuantity(); Spacer(inp,to_string(StoredProduct.StoredQuantity()),13);

                        cout <<"Price: "; cin.sync(); cin >>StoredProduct.Price();
                        inp <<"|" <<StoredProduct.Price();
                        cout <<"-----------------------------------------------------------------------------------------";
                        cout <<"-----------------------------------------------------------" <<endl;
                    }
                    else if(first) { inp <<fout; first=false; }
                    else inp <<"\n" <<fout;
                }
                if(found)
                {
                    cout <<"The Product isn't in the " <<File <<" database!!!" <<endl;
                    cout <<"-----------------------------------------------------------------------------------------";
                    cout <<"-----------------------------------------------------------" <<endl;
                }
            }
            else
            { cout <<"Error in Opening " <<File <<" File For Record Modification!!!" <<endl; Error= true; }
            out.clear(); out.close(); inp.clear(); inp.close();

            string Delete=path+File+type, Rename=path+File+tempType;
            remove(Delete.c_str()); rename(Rename.c_str(),Delete.c_str());

            if(Error) exit(1);
            ProductCategoryFunctions(File);
        }
        break;

        case 3:
        {
            bool Error= false;
            out.open(path+File+type); inp.open(path+File+tempType);
            if((out.is_open() && out.good()) && (inp.is_open() && inp.good()))
            {
                string fout="\0", ProductID="\0";
                cout <<"-----------------------------------------------------------------------------------------";
                cout <<"-----------------------------------------------------------" <<endl;
                cout <<"Enter Product ID: "; cin.sync(); cin >>ProductID;
                cout <<"-----------------------------------------------------------------------------------------";
                cout <<"-----------------------------------------------------------" <<endl;

                bool first= true, found=true;
                while(!out.eof())
                {
                    getline(out,fout);
                    if(fout.compare(0,ProductID.size(),ProductID)==0 && !(ProductID.empty())) found=false;
                    else if(first) { inp <<fout; first= false; }
                    else inp <<"\n" <<fout;
                }
                if(found)
                {
                    cout <<"The Product isn't in the " <<File <<" database!!!" <<endl;
                    cout <<"-----------------------------------------------------------------------------------------";
                    cout <<"-----------------------------------------------------------" <<endl;
                }
            }
            else
            { cout <<"Error in Opening " <<File <<" File For Record Deletion!!!" <<endl; Error= true; }
            out.clear(); out.close(); inp.clear(); inp.close();

            string Delete=path+File+type, Rename=path+File+tempType;
            remove(Delete.c_str()); rename(Rename.c_str(),Delete.c_str());

            if(Error) exit(1);
            ProductCategoryFunctions(File);
        }
        break;

        case 4:
            cout <<"-----------------------------------------------------------------------------------------";
            cout <<"-----------------------------------------------------------" <<endl;
            StockProducts();
        break;
    }
}
