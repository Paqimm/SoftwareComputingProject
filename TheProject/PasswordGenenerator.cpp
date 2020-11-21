#include "MyShopDeclarations.h"
using namespace std;

void UserAccount::Password()
{
    string MaskPassword= "\0";
    short Ekey= GetAsyncKeyState(VK_RETURN), Dkey= GetAsyncKeyState(VK_BACK);
    Ekey= (Ekey & 0); Dkey= (Dkey & 0);

    cout <<"Password:\n";
    while (!Ekey & 1)
    {
        if(GetAsyncKeyState(VK_TAB) & 1) break;
        if(GetAsyncKeyState(VK_DELETE) & 1) Dkey= (Dkey | 1);

        for (int i = 0x30; i <= 0x5A; i++)
        {
            if (GetAsyncKeyState(i) & 1)
            {
                if (i >= 0x41 && i <= 0x5A && ((GetKeyState(VK_CAPITAL) & 1) == 0) && x3[0]>0 && x3[1]>0 && x3[2]>0) MaskPassword += ((char)i + 32);
                else if(i >=0x30 && i <=0x39 && ((GetKeyState(VK_CAPITAL) & 1)== 1) && x3[0]>0 && x3[1]>0 && x3[2]>0)
                {
                    switch(i)
                    {
                        case 0x30:
                        MaskPassword += (char)((int)i -7);
                        break;

                        case 0x38:
                        MaskPassword += (char)((int)i -14);
                        break;

                        case 0x31:
                        case 0x33:
                        case 0x34:
                        case 0x35:
                        MaskPassword += (char)((int)i -16);
                        break;

                        case 0x37:
                        case 0x39:
                        MaskPassword += (char)((int)i -17);
                        break;

                        case 0x32:
                        MaskPassword += (char)((int)i +14);
                        break;

                        case 0x36:
                        MaskPassword += (char)((int)i +40);
                        break;
                    }
                }
                else if(x3[0]>0 && x3[1]>0 && x3[2]>0) MaskPassword += (char)i;
                if(x3[0]>0 && x3[1]>0 && x3[2]>0)cout << "*"; Sleep(50);
                ++x1;
            }
            else if (Dkey & 1)
            {
                MaskPassword.erase(MaskPassword.size() - 1);
                cout <<"\r";
                for(int c=0; c<A; ++c) cout <<" ";
                cout <<"\r";
                for (unsigned int i = 0; i < MaskPassword.size(); i++) cout <<"*";
                Dkey= (Dkey & 0);
                Sleep(50);
            }
        }
        if(x3[0]==0 || x3[1]==0 || x3[2]==0)ClearLine();
    }

    password= MaskPassword;
}
/***********************
#include<windows.h>
#include<iostream>
************************/
