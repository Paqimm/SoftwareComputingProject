#include "MyShopDeclarations.h"

string Product::ProdSize;
string Product::ProdName;
string Product::ProdBrand;
string Product::ProdColor;
string Product::ProdDescription;

int Purchased::ProdQuantity;
double Purchased::ProdTotalPrice;
double Purchased::ProdDiscount;
double Purchased::ProdAmountPaid;

int Stored::ProdQuantity;
double Stored::ProdPrice;
string Stored::ProdCategory;

string &Product::Name()
{ return ProdName; }

string &Product::Brand()
{ return ProdBrand; }

string &Product::Color()
{ return ProdColor; }

string &Product::Description()
{ return ProdDescription; }

string &Product::Size()
{ return ProdSize; }

int &Purchased::PurchasedQuantity()
{ return ProdQuantity; }

double &Purchased::TotalPrice()
{ return ProdTotalPrice; }

double &Purchased::Discount()
{ return ProdDiscount; }

double Purchased::BuyingPrice()
{ return (TotalPrice()-Discount()); }

double &Purchased::AmountPaid()
{ return ProdAmountPaid; }

void Purchased::Details()
{
    cout <<"Product Name: " <<Name() <<endl;
    cout <<"Brand: " <<Brand() <<endl;
    cout <<"Color: " <<Color() <<endl;
    cout <<"Description: " <<Description() <<endl;
    cout <<"Size: " <<Size() <<endl;
    cout <<"Quantity: " <<PurchasedQuantity() <<endl;
    cout <<"Total Selling Price: " <<TotalPrice() <<endl;
    cout <<"Discount Offered: " <<Discount() <<endl;
    cout <<"Total Buying Price: " <<BuyingPrice() <<endl;
}

string &Stored::Category()
{ return ProdCategory; }

double &Stored::Price()
{ return ProdPrice; }

int &Stored::StoredQuantity()
{ return ProdQuantity; }

double FindPrice()
{
    double Price=0;
    string Categories[]= {"Clothes","Shoes","InnerGarments","OtherAccessories"},
    ProductDetails= PurchasedProduct.Name()+PurchasedProduct.Brand()
    +PurchasedProduct.Color()+PurchasedProduct.Description()+PurchasedProduct.Size();

    ProductDetails.erase(ProductDetails.size()-(ProductDetails.end()
    -(remove(ProductDetails.begin(),ProductDetails.end(),' '))));

    for(string File: Categories)
    {
        bool Error= false;
        string fout="\0", Temp="\0";
        ifstream out(path+File+type);

        if(out.is_open() && out.good())
        {
            while(!out.eof())
            {
                getline(out,fout);

                int c=39;
                while(c<121) Temp += fout[c++];

                Temp.erase(Temp.size()-(Temp.end()-(remove(Temp.begin(),Temp.end(),' '))));
                Temp.erase(Temp.size()-(Temp.end()-(remove(Temp.begin(),Temp.end(),'|'))));

                if(Temp==ProductDetails)
                {
                    c=137;
                    string ProdPrice="\0";
                    while(fout[c]) ProdPrice += fout[c++];
                    Price= stod(ProdPrice);
                    return Price;
                }
                Temp.clear();
            }
        }
        else { cout <<"Error in opening " <<File <<" For Price Retrieval" <<endl; Error= true;}
        out.clear(); out.close();
        if(Error) exit(1);
    }
    return Price;
}

void DeductQuantity()
{
    int Quantity=0;
    string Categories[]= {"Clothes","Shoes","InnerGarments","OtherAccessories"},
    ProductDetails= PurchasedProduct.Name()+PurchasedProduct.Brand()
    +PurchasedProduct.Color()+PurchasedProduct.Description()+PurchasedProduct.Size();

    ProductDetails.erase(ProductDetails.size()-(ProductDetails.end()
    -(remove(ProductDetails.begin(),ProductDetails.end(),' '))));

    for(string File: Categories)
    {
        string fout="\0", Temp="\0";
        bool Error= false, Deducted=false;
        ifstream out(path+File+type); ofstream inp(path+File+tempType);

        if((out.is_open() && out.good()) && (inp.is_open() && inp.good()))
        {
            bool first=true;
            while(!out.eof())
            {
                getline(out,fout);

                if(fout.size()!=0)
                {
                    int c=39;
                    while(c<121) Temp += fout[c++];

                    Temp.erase(Temp.size()-(Temp.end()-(remove(Temp.begin(),Temp.end(),' '))));
                    Temp.erase(Temp.size()-(Temp.end()-(remove(Temp.begin(),Temp.end(),'|'))));

                    if(Temp==ProductDetails)
                    {
                        c=123;
                        string ProdQuantity="\0";
                        while(fout[c]!=' ') ProdQuantity += fout[c++];
                        Quantity= stoi(ProdQuantity);

                        string Complete="\0";
                        Complete.insert(0,fout,136,(fout.size()-136));

                        Quantity -= PurchasedProduct.PurchasedQuantity();

                        if(Quantity)
                        {
                            fout.erase(123);
                            fout += to_string(Quantity);

                            int Space= 13-(to_string(Quantity).size());
                            while(Space--) fout += " ";

                            fout += Complete;

                            if(first) { inp <<fout; first=false; }
                            else inp <<"\n" <<fout;
                        }
                        Deducted=true;
                    }
                    else if(first) { inp <<fout; first=false; }
                    else inp <<"\n" <<fout;
                    Temp.clear();
                }
            }
        }
        else { cout <<"Error in Opening " <<File <<" File for Quantity Deduction" <<endl; Error=true; }
        out.clear(); out.close(); inp.clear(); inp.close();

        string Delete=path+File+type, Rename=path+File+tempType;
        remove(Delete.c_str()); rename(Rename.c_str(),Delete.c_str());

        if(Deducted) break;
    }
}
