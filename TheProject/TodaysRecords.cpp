#include "MyShopDeclarations.h"

string DateTime(bool Date)
{
    time_t Time= time(0);
	tm LocalTime= *localtime(&Time);
	const char *CurrentTime= ctime(&Time);

	string ActualDate="\0", ClockTime= "\0";
	int Year=LocalTime.tm_year, Month=LocalTime.tm_mon, Day=LocalTime.tm_mday;

	ClockTime.insert(0,CurrentTime,11,8);
	ActualDate += (to_string(Day) +"/" +to_string(Month) +"/" +to_string(1900+Year));

    if(Date) return ActualDate;
    else return ClockTime;
}

void TodaysRecords(bool Backup)
{
    if(!Backup)
    {
        bool Error= false;
        ofstream inp(path+"TodaysRecords"+type,ios::ate|ios::app),
        inpRecord(path+"Record"+type,ios::ate|ios::app), inpSalesRecord(path+"SalesRecord"+type,ios::ate|ios::app),
        inpProduct(path+"PurchasedProduct"+type,ios::ate|ios::app), inpProductOrdered(path+"ProductOrdered"+type,ios::ate|ios::app),
        inpEmployeeAttendance(path+"EmployeeAttendance"+type,ios::ate|ios::app);

        if((inp.is_open() && inp.good())&&
           (inpRecord.is_open() && inpRecord.good())&&
           (inpSalesRecord.is_open() && inpSalesRecord.good())&&
           (inpProduct.is_open() && inpProduct.good())&&
           (inpProductOrdered.is_open() && inpProductOrdered.good())&&
           (inpEmployeeAttendance.is_open() && inpEmployeeAttendance.good()))
        {
            inp <<((FileStatus("TodaysRecords"))?"\n":"");
            inp <<DateTime(true); Spacer(inp,DateTime(true),11);

            string Time= DateTime(false);
            inp <<"|" <<"####"; Spacer(inp,"####",5); //RecordID
            inp <<"|" <<Time; Spacer(inp,Time,11);

            inpRecord <<((FileStatus("Record"))?"\n####":"####"); Spacer(inpRecord,"####",5); //RecordID
            inpRecord <<"|" <<Time;

            inp <<"|" <<"####"; Spacer(inp,"####",5); //CustomerID
            inp <<"|" <<CurrentCustomer.Name(); Spacer(inp,CurrentCustomer.Name(),21);
            inp <<"|" <<CurrentCustomer.Contact(); Spacer(inp,CurrentCustomer.Contact(),11);

            inp <<"|" <<SystemUser.Name(); Spacer(inp,SystemUser.Name(),21);

            inpEmployeeAttendance <<((FileStatus("EmployeeAttendance"))?"\n####":"####");
            Spacer(inpEmployeeAttendance,"####",5); //EmployeeID
            inpEmployeeAttendance <<"|" <<"####"; //CustomerID

            inp <<"|" <<PurchasedProduct.Name(); Spacer(inp,PurchasedProduct.Name(),16);
            inp <<"|" <<PurchasedProduct.Brand(); Spacer(inp,PurchasedProduct.Brand(),18);
            inp <<"|" <<PurchasedProduct.Color(); Spacer(inp,PurchasedProduct.Color(),15);
            inp <<"|" <<PurchasedProduct.Description(); Spacer(inp,PurchasedProduct.Description(),25);
            inp <<"|" <<PurchasedProduct.Size(); Spacer(inp,PurchasedProduct.Size(),10);
            inp <<"|" <<PurchasedProduct.PurchasedQuantity(); Spacer(inp,to_string(PurchasedProduct.PurchasedQuantity()),14);
            inp <<"|" <<PurchasedProduct.TotalPrice(); Spacer(inp,to_string((int)PurchasedProduct.TotalPrice()),10);
            inp <<"|" <<PurchasedProduct.BuyingPrice(); Spacer(inp,to_string((int)PurchasedProduct.BuyingPrice()),10);
            inp <<"|" <<PurchasedProduct.Discount(); Spacer(inp,to_string((int)PurchasedProduct.Discount()),10);
            inp <<"|" <<((PurchasedProduct.AmountPaid()<PurchasedProduct.BuyingPrice())? "Pending" :"Paid");

            inpProduct <<((FileStatus("PurchasedProduct"))?"\n####":"####"); Spacer(inpProduct,"####",5); //PurchaseID
            inpProduct <<"|" <<"####"; Spacer(inpProduct,"####",5); //StoredID
            inpProduct <<"|" <<"####"; Spacer(inpProduct,"####",5); //CategoryID
            inpProduct <<"|" <<PurchasedProduct.Name(); Spacer(inpProduct,PurchasedProduct.Name(),16);
            inpProduct <<"|" <<PurchasedProduct.Brand(); Spacer(inpProduct,PurchasedProduct.Brand(),18);
            inpProduct <<"|" <<PurchasedProduct.Color(); Spacer(inpProduct,PurchasedProduct.Color(),15);
            inpProduct <<"|" <<PurchasedProduct.Description(); Spacer(inpProduct,PurchasedProduct.Description(),25);
            inpProduct <<"|" <<PurchasedProduct.Size(); Spacer(inpProduct,PurchasedProduct.Size(),10);
            inpProduct <<"|" <<PurchasedProduct.PurchasedQuantity(); Spacer(inpProduct,to_string((int)PurchasedProduct.PurchasedQuantity()),10);
            inpProduct <<"|" <<PurchasedProduct.TotalPrice(); Spacer(inpProduct,to_string((int)PurchasedProduct.TotalPrice()),10);
            inpProduct <<"|" <<PurchasedProduct.BuyingPrice(); Spacer(inpProduct,to_string((int)PurchasedProduct.BuyingPrice()),10);
            inpProduct <<"|" <<PurchasedProduct.Discount();

            inpProductOrdered <<((FileStatus("ProductOrdered"))?"\n####":"####"); Spacer(inpProductOrdered,"####",5); //CustomerID
            inpProductOrdered <<"|" <<"####"; Spacer(inpProductOrdered,"####",5); //ProductID
            inpProductOrdered <<"|" <<((PurchasedProduct.AmountPaid()<PurchasedProduct.BuyingPrice())? "Pending" :"Paid");

            inpSalesRecord <<((FileStatus("SalesRecord"))?"\n####":"####"); Spacer(inpSalesRecord,"####",5); //RecordID
            inpSalesRecord <<"|" <<"####"; Spacer(inpSalesRecord,"####",5); //CustomerID
            inpSalesRecord <<"|" <<"####"; Spacer(inpSalesRecord,"####",5); //ProductID
            inpSalesRecord <<"|" <<"####"; //UserID
        }
        else { cout <<"Error in Opening Today's Records File for Record Insertion!!!" <<endl; Error= true; }
        inp.clear(); inp.close();
        inpRecord.clear(); inpRecord.close();
        inpSalesRecord.clear(); inpSalesRecord.close();
        inpProduct.clear(); inpProduct.close();
        inpProductOrdered.clear(); inpProductOrdered.close();
        inpEmployeeAttendance.clear(); inpEmployeeAttendance.close();

        if(Error) exit(1);
    }
    else GoogleDriveBackUp();
}
