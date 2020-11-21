#include "MyShopDeclarations.h"

void Reset()
{
    PurchasedProduct.Discount()=
    PurchasedProduct.AmountPaid()=0;
}

bool InvalidInput= false, SameCustomer=false;

void NewCustomer()
{
    int choose=0;
    if(!InvalidInput)
    {
        cout <<"Choose an operation:" <<endl;
        cout <<"1.Product Purchase\t2.Product Inquiry\n3.Back(Main Menu)" <<endl;
        cout <<"-------------------------------------------\n";

        cout <<"Choose: "; cin.sync(); cin >>choose;
        cout <<"-------------------------------------------\n";
    }
    else { choose=1; InvalidInput= false; }

    switch(choose)
    {
        case 1:
        {
            if(!SameCustomer)
            {
                cout <<"Customer Name: "; cin.sync(); getline(cin,CurrentCustomer.Name());
                cout <<"Customer Contact: "; cin.sync(); cin >>CurrentCustomer.Contact();
            }

            cout <<"Product Name: "; cin.sync(); getline(cin,PurchasedProduct.Name());
            cout <<"Brand: "; cin.sync(); getline(cin,PurchasedProduct.Brand());
            cout <<"Color: "; cin.sync(); getline(cin,PurchasedProduct.Color());
            cout <<"Description: "; cin.sync(); getline(cin,PurchasedProduct.Description());
            cout <<"Size: "; cin.sync(); getline(cin,PurchasedProduct.Size());

            cout <<"Quantity: "; cin.sync(); cin >>PurchasedProduct.PurchasedQuantity();
            PurchasedProduct.TotalPrice()= FindPrice() * (double)PurchasedProduct.PurchasedQuantity();
            cout <<"Total Selling Price: " <<PurchasedProduct.TotalPrice() <<endl;

            if(PurchasedProduct.TotalPrice()!=0)
            {
                cout <<"-------------------------------------------\n";
                cout <<"Discount Offered: "; cin.sync(); cin >>PurchasedProduct.Discount();
                cout <<"Buying Price: " <<PurchasedProduct.BuyingPrice() <<endl;
                cout <<"Amount Paid: "; cin.sync(); cin >>PurchasedProduct.AmountPaid();
            }

            if((PurchasedProduct.BuyingPrice()-PurchasedProduct.AmountPaid())==0)
            {
                if(PurchasedProduct.TotalPrice()==0)
                {
                    cout <<"-------------------------------------------\n";
                    cout <<"Product Not Found" <<endl;
                    cout <<"Please Insert Proper Values in Their Respective Fields" <<endl;
                    cout <<"-------------------------------------------\n";
                    InvalidInput= true; NewCustomer();
                }
                else
                {
                    cout <<"-------------------------------------------\n";
                    cout <<"Thank You For Shopping with Zephmatt General Supplies" <<endl;
                    cout <<"-------------------------------------------\n";
                    TodaysRecords(); DeductQuantity();

                    if(!SameCustomer) CustomerList();
                    else SameCustomer= false;

                    cout <<"1.Same Customer\t2.New Customer\n3.Back(Main Menu)" <<endl;
                    int New=0;
                    cout <<"Choose: "; cin.sync(); cin >> New;
                    cout <<"-------------------------------------------\n";
                    switch(New)
                    {
                        case 1: SameCustomer= true;
                        case 2: Reset(); NewCustomer(); break;
                        case 3:  FileAccess(true); break;
                    }
                }
            }
            else
            {
                cout <<"Debt Owed By " <<CurrentCustomer.Name() <<": ";
                cout <<PurchasedProduct.BuyingPrice()-PurchasedProduct.AmountPaid() <<endl;
                cout <<"-------------------------------------------\n";
                cout <<"Honor Your Debt to Zephmatt General Supplies" <<endl;
                cout <<"-------------------------------------------\n";
                TodaysRecords(); BusinessDebts(); DeductQuantity();

                if(!SameCustomer) CustomerList();
                else SameCustomer= false;

                cout <<"1.Same Customer\t2.New Customer\n3.Back(Main Menu)" <<endl;
                int New=0;
                cout <<"Choose: "; cin.sync(); cin >> New;
                cout <<"-------------------------------------------\n";
                switch(New)
                {
                    case 1: SameCustomer= true;
                    case 2: Reset(); NewCustomer(); break;
                    case 3: FileAccess(true); break;
                }
                Reset();
            }
        }
        break;

        case 2:
        {
            ProductsInquired(true);
            if(SameCustomer) SameCustomer= false;

            cout <<"1.Same Customer\t2.New Customer\n3.Back(Main Menu)" <<endl;
            int New=0;
            cout <<"Choose: "; cin.sync(); cin >> New;
            cout <<"-------------------------------------------\n";
            switch(New)
            {
                case 1:
                case 2: Reset(); NewCustomer(); break;
                case 3: FileAccess(true); break;
            }
        }
        break;

        case 3: FileAccess(true); break;
    }
}
