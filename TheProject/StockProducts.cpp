#include "MyShopDeclarations.h"

void StockProducts()
{
    cout <<"1.Clothes\t\t2.Shoes" <<endl;
    cout <<"3.Inner Garments\t4.Other Accessories" <<endl;
    cout <<"5.Back(Main Menu)" <<endl;

    int choose=0;
    cout <<"Choose: "; cin.sync(); cin >>choose;
    switch(choose)
    {
        case 1:
        {
            cout <<"\n-------------------------------------------\n";
            cout <<"\tCLOTHES";
            cout <<"\n-------------------------------------------\n";
            ProductCategoryFunctions("Clothes");
        }
        break;

        case 2:
            cout <<"\n-------------------------------------------\n";
            cout <<"\tSHOES";
            cout <<"\n-------------------------------------------\n";
            ProductCategoryFunctions("Shoes");
        break;

        case 3:
            cout <<"\n-------------------------------------------\n";
            cout <<"\tINNER GARMENTS";
            cout <<"\n-------------------------------------------\n";
            ProductCategoryFunctions("InnerGarments");
        break;

        case 4:
            cout <<"\n-------------------------------------------\n";
            cout <<"\tOTHER ACCESSORIES";
            cout <<"\n-------------------------------------------\n";
            ProductCategoryFunctions("OtherAccessories");
        break;

        case 5:
            cout <<"-------------------------------------------";
            FileAccess(true);
        break;
    }
}
/*************************
cout <<"|Product ID"; Spacer(cout,"Product ID",15);
cout <<"|Category ID"; Spacer(cout,"Category ID",16);
cout <<"|Product Code"; Spacer(cout,"Product Code",17);
cout <<"|Product"; Spacer(cout,"Product",15);
cout <<"|Brand"; Spacer(cout,"Brand",13);
cout <<"|Color"; Spacer(cout,"Color",10);
cout <<"|Description"; Spacer(cout,"Description",20);
cout <<"|Size"; Spacer(cout,"Size",9);
cout <<"|Quantity"; Spacer(cout,"Quantity",13);
cout <<"|Price"; Spacer(cout,"Price",10); cout <<"|" <<endl;
**************************/
