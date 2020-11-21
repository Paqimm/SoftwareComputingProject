#pragma once
#define A 100
#include<iostream>
#include<windows.h>
#include<algorithm>
#include<fstream>
#include<string>
#include<stdlib.h>
#include<conio.h>
#include<ctime>
#include<vector>
#include<map>
using namespace std;

class Customer
{
private:
    static string name, contact, ID;
public:
    static string &Name();
    static string CID();
    static string &Contact();
    static void Details();
};

class Product
{
private:
    static string ProdName, ProdBrand,
    ProdColor, ProdDescription, ProdSize;
public:
    static string &Name();
    static string &Brand();
    static string &Color();
    static string &Description();
    static string &Size();
};

class Purchased: public Product
{
private:
    //static string ID;
    static int ProdQuantity;
    static double ProdTotalPrice,
    ProdDiscount, ProdAmountPaid;
public:
    //static string &PurchasedID();
    static double &TotalPrice();
    static double &Discount();
    static double BuyingPrice();
    static double &AmountPaid();
    static void Details();
    static int &PurchasedQuantity();
};

class Stored: public Product
{
private:
    static int ProdQuantity;
    static double ProdPrice;
    static string ProdCategory;// ID;
public:
    //static string &StoredID();
    static double &Price();
    static string &Category();
    static int &StoredQuantity();
};

class UserAccount
{
private:
    int trials;
    int x1,x2,x3[A]= {0};
    static string name, password, status; //ID;

public:
    UserAccount();
    static string &Name();
    static string Pass();
    static string &Status();
    //static string &USID();
    int &Trial();
    void ClearLine();
    void Password();
    void CreateAccount();
    void LoginAccount();
    void ForgotPassword();
    void NewPassword();
};

static UserAccount SystemUser;
static Customer CurrentCustomer;
static Product InquiredProduct;
static Purchased PurchasedProduct;
static Stored StoredProduct;

bool PasswordVerfication();
bool UserLoginVerfication(bool exist);
void StoreDetails(bool Verification);
void FileAccess(bool Verification);
void Users();
void ChangeDetails(int choose);
void DeleteAccount();

void NewCustomer();
double FindPrice();
void DeductQuantity();

void TodaysRecords(bool Backup=false);
void GoogleDriveBackUp();

void ProductsInquired(bool RecordEntry= false);
void BusinessDebts(bool Payment=false);
void CustomerList(bool Display=false);
void Spacer(ostream &inp, const string &Word, const int &Size);

void StockProducts();
void ProductCategoryFunctions(const string &File);

string SetPath(bool Set);
bool FileStatus(const string &File);
static string type=".txt", tempType="(2).txt", path= SetPath(true);
