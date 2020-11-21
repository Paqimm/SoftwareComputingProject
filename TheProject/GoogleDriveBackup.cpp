#include "MyShopDeclarations.h"

void GoogleDriveBackUp()
{
    cout <<"1.Backup Now\t2.Backup Later" <<endl;

    int choose=0;
    cout <<"Choose: "; cin.sync(); cin >>choose;
    switch(choose)
    {
        case 1:
        {
            cout <<"\n-------------------------------------------\n";
            cout <<"\tTODAY'S RECORDS INFORMATION BACKUP";
            cout <<"\n-------------------------------------------\n";
            cout <<"Backup in Progress..."; Sleep(10000);
            cout <<"\r"; Spacer(cout,"Backup in Progress...",50); cout <<"\r";

            bool Error= false;
            ofstream inp(path+"GoogleDrive"+type,ios::ate|ios::app); ifstream out(path+"TodaysRecords"+type);
            if((inp.is_open() && inp.good()) && (out.is_open() && out.good()))
            {
                string fout="\0", Backup="\0";
                while(!out.eof()) { getline(out,fout); Backup += (fout + "\n"); }

                if(FileStatus("GoogleDrive")) inp <<endl;
                inp <<Backup; for(int c=240; c>0; --c) inp <<"-";
            }
            else
            {
                if(inp.bad()) cout <<"Error in Accessing Google Drive for Backup" <<endl;
                else cout <<"Error in Accessing Today's Records for Reading" <<endl;
                Error= true;
            }
            inp.clear(); inp.close(); out.clear(); out.close();
            if(Error) exit(1);

            cout <<"Backup Complete" <<endl;

            string Relations[]= {"TodaysRecords","EmployeeAttendance","ProductOrdered","PurchasedProduct","Record","SalesRecord"};
            for(string File: Relations)
            {
                Error= false;
                inp.open(path+File+type,ios::trunc);

                if(!(inp.is_open() && inp.good()))
                { cout <<"Error in Opening " <<File <<" File for Deletion" <<endl; Error= true; }
                inp.clear(); inp.close();
                if(Error) exit(1);
            }
        }

        case 2:
            cout <<"-------------------------------------------";
            FileAccess(true);
        break;
    }
}
