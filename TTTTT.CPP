#include <iostream.h>
#include <conio.h>
#include <process.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream.h>
#include <iomanip.h>
int flag = 0;
ofstream jishu;
ifstream jk;
class tbill
{
public:
    float fixamount1, fixamount2, fixamount3, natroamom, natroamim;
    float natroamor, natroamir, stdrate, stdmin, smsr;
    float gprsrate, gprskb, mmsr;
    int sms, mms, billid;

    float interroami, interroamir, interroamo, interroamor, misc, grandtotal, isdrate, isdmin;
    void ent();
    void sho();
    void edi();
    void cal();
    int ret()
    {
        return (billid);
    }
} x;
void tbill::cal()
{
    x.natroamor = x.natroamom * 2;
    x.natroamir = x.natroamim * 2.5;
    x.interroamor = x.interroamo * 1.5;
    x.interroamir = x.interroami * 1.7;
    x.gprsrate = x.gprskb * 0.10;
    x.smsr = x.sms * 0.50;
    x.mmsr = x.mms * 3;
    x.stdrate = x.stdmin * 1;
    x.isdrate = x.isdmin * 8;
    x.grandtotal = x.natroamor + x.natroamir + x.interroamor + x.interroamir + x.gprsrate + x.smsr + x.mmsr + x.stdrate + x.isdrate + x.misc;
}
void tbill::edi()
{
    clrscr();
    sho();
    cout << endl<< "========================================================";
         
    cout << endl
         << "\t      Press Any Key To Continue     ";
    cout << endl<< "=========================================================";
         
    getch();
    clrscr();
    sho();
    cout << endl<< "=========================================================";
         
    cout << endl<< "         Edit What?????   ";
         
    cout << endl<< "=========================================================";
    cout << endl;
    cout << "1.Incoming Call\t\t6. No of MMS" << endl;
    cout << "2.No of SMS\t\t\t\t7.ISD Calls\t\t" << endl;
    cout << "3.Roaming Incoming Call\t\t8.International Roaming Incoming" << endl;
    cout << "4.Roaming Outgoing Call\t\t9.International Roaming Outgoing" << endl;
    cout << "5.GPRS Usage(in Kb)\t\t\t10.Miscellaneous charges" << endl;
    cout << endl<<"=========================================================";
        
    cout << endl << "Enter Choice  :";
        
    int ch;
pp:
    cin >> ch;
    if (ch == 1)
    {
        cout << "Enter Incoming Call min  :";
        cin >> x.stdmin;
    }
    if (ch == 2)
    {
        cout << "Enter SMS  :";
        cin >> x.sms;
    }
    if (ch == 3)
    {
        cout << "Enter Roaming in   :";
        cin >> x.natroamim;
    }
    if (ch == 4)
    {
        cout << "Enter Roaming Out  :";
        cin >> x.natroamom;
    }
    if (ch == 5)
    {
        cout << "Enter GPRS Usage  :";
        cin >> x.gprskb;
    }
    if (ch == 6)
    {
        cout << "Enter MMS no.  :";
        cin >> x.mms;
    }
    if (ch == 7)
    {
        cout << "Enter ISD Min  :";
        cin >> x.isdmin;
    }
    if (ch == 8)
    {
        cout << "Enter ISD Roam in    :";
        cin >> x.interroami;
    }
    if (ch == 9)
    {
        cout << "Enter ISD Roamount  :";
        cin >> x.interroamo;
    }
    if (ch == 10)
    {
        cout << "Enter Misc Charge   :";
        cin >> x.misc;
    }
    if ((ch > 10) || (ch == 0))
    {
        cout << "\n\t\t\t\tInvalid Choice!!!!!" << endl
             << "\t\t\t\t";
        goto pp;
    }
    cal();
    jishu.write((char *)&x, sizeof(x));
}
void tbill::ent()
{
    cout << endl
         << " incoming Call(mts)   :";
    cin >> x.stdmin;
    cout << endl
         << " No. of SMS   :";
    cin >> x.sms;
    cout << endl
         << " Roaming Incoming Calls (mts)   :";
    cin >> x.natroamim;
    cout << endl
         << " Roaming Outgoing Calls(mts)    :";
    cin >> x.natroamom;
    cout << endl
         << " GPRS Usage (in Kb)     :";
    cin >> x.gprskb;
    cout << endl
         << " No. Of MMS             :";
    cin >> x.mms;
    cout << endl
         << " ISD Call(mts)          :";
    cin >> x.isdmin;
    cout << endl
         << " International Roaming Incoming(mts) :";
    cin >> x.interroami;
    cout << endl
         << " International Roaming Outgoing(mts) :";
    cin >> x.interroamo;
    cout << endl
         << " Miscellaneous Charges               :";
    cin >> x.misc;
    cal();
    jishu.write((char *)&x, sizeof(x));
    jishu.close();
}
void tbill::sho()
{
    cout << endl<< "====================================================================="<<endl;
    cout << "\t\t    CALL       ";
    cout << "\t\t    MINUTES/NO.      ";
    cout << "\t"<< " AMOUNT ";
    cout << endl;
    cout << endl<< "====================================================================="<<endl;
    cout << endl<< "\t\t Incoming Calls      ";
    cout << "\t" << x.stdmin;
    cout << "\t\t" << x.stdrate;
    cout << endl<< "\t\t No. of SMS          ";  
    cout << "\t" << x.sms;
    cout << "\t\t" << x.smsr;
    cout << "\t\t Roaming Incoming Calls    ";
    cout << "\t" << x.natroamim;
    cout << "\t\t" << x.natroamir;
    cout << "\t\t Roaming Outgoing Calls    ";
    cout << "\t" << x.natroamom;
    cout << "\t\t" << x.natroamor;
    cout << endl<< "\t\tGPRS Usage (in Kb)   ";
    cout << "\t" << x.gprskb;
    cout << "\t\t" << x.gprsrate;
    cout << endl<< "\t\t No. of MMS          ";
    cout << "\t" << x.mms;
    cout << "\t\t" << x.mmsr;
    cout << endl<< endl<< "\t\t ISD CAll      ";
    cout << "\t" << x.isdmin;
    cout << "\t\t" << x.isdrate;
    cout << endl<< "\n\t\t International Roaming Incoming ";
    cout << "\t" << x.interroami;
    cout << "\t\t" << x.interroamir;
    cout << endl<< "\n\t\t International Roaming Outgoing ";
    cout << "\t" << x.interroamo;
    cout << "\t\t" << x.interroamor;
    cout << endl<< "\n\t\t Miscellaneous Charges ";
    cout << "\t\t\t" << x.misc;
    cout << endl<< endl<< "\n\t\t | Total Charges|      ";
    cout << "\t\t\t" << x.grandtotal;
}

class customer
{
    long phno, acno, pcode;
    char name[50], address[50], city[50];

public:
    long id;
    void ecustdet();
    void scustdet();
    void dcustdet();
    void edcustdet();
    int ret()
    {
        return (id);
    }
} a;

void customer::edcustdet()
{
    clrscr();
    
    int ch;
    cout << "=========================================================";
    cout << "\t\t\t Current Customer Details " << endl;
    cout << "=========================================================";
    scustdet();
    cout << "=========================================================";
    cout << "\t\t    Edit What?????       " << endl;
    cout << "=========================================================";
    cout << endl << "\t1.Name 2.Address 3.Street 4.pin code 5.Ph.no. 6.A/c no." << endl;
    cout << "=========================================================";
pp:
    cout << endl<< "\t\t\t\t Enter Option    :";
    cin >> ch;
    if (ch == 1)
    {
        cout << "\n\t\t\t\t Enter Name   :";
        gets(a.name);
    }
    if (ch == 2)
    {
        cout << "\n\t\t\t\t Enter Address   :";
        gets(a.address);
    }
    if (ch == 3)
    {
        cout << "\n\t\t\t\t Enter Street   :";
        gets(a.city);
    }
    if (ch == 4)
    {
        cout << "\n\t\t\t\t Enter Pincode   :";
        cin >> a.pcode;
    }
    if (ch == 5)
    {
        cout << "\n\t\t\t\t Enter Phone No.   :";
        cin >> a.phno;
    }
    if (ch == 6)
    {
        cout << "\n\t\t\t\t Enter A/C No.   :";
        cin >> a.acno;
    }
    if ((ch > 6) || (ch == 0))
    {
        cout << "\n\t\t\t\t Invalid choice!!!!!" << endl << "\t\t\t\t";
        goto pp;
    }
    jishu.write((char *)&a, sizeof(a));
}

void customer::ecustdet()
{
    int id;
ret:
    jk.open("customer.dat", ios::binary);
    jk.seekg(0);
    cout << endl
         << " Enter customer id   :";
    cin >> id;
    while (!jk.eof())
    {
        jk.read((char *)&a, sizeof(a));
        int x = a.ret();
        if (x == id)
        {
            cout << "\n\t\t\t\t ERROR!!!ID ALREADY TAKEN.....CHOSE ANY OTHER ID \n\n";
            jk.close();
            goto ret;
        }
    }
    jk.close();
    a.id = id;
    cout << endl<< "Enter Name   :";
    gets(a.name);
    cout << endl<< "Enter Address   :";
    gets(a.address);
    cout << endl<< "Enter street   :";
    gets(a.city);
    cout << endl<< "Enter Pincode   :";
    cin >> a.pcode;
    cout << endl<< "Enter Phone No.   :";
    cin >> a.phno;
    cout << endl<< "Enter A/C No.   :";
    cin >> a.acno;
    jishu.write((char *)&a, sizeof(a));
    jishu.close();
}

void customer::scustdet()
{
    cout << endl
         << "\tName   :";
    puts(a.name);
    cout << endl
         << "\t\t\t\t\t\t"
         << "ID No.     :";
    cout << a.id;
    cout << endl<< "\tAddress   :";
    puts(a.address);
    cout << endl
         << "\t\t\t\t\t\t"<< "Phone No.     :";
    cout << a.phno;
    cout << endl<< "\tStreet   :";
    puts(a.city);
    cout << endl
         << "\t\t\t\t\t\t"<< "A/C No.     :";
    cout << a.acno;
    cout << endl<< "\tPincode   :";
    cout << a.pcode << endl;
}
void main()
{
    clrscr();
    int ch, cid;
y:
    gotoxy(1, 5);
    cout << "=========================================================";
    gotoxy(32, 6);
    cout << "TELEPHONE BILLING ";
    cout << endl;
    cout << "=========================================================";
    gotoxy(27, 10);
    cout << "1) ENTER CUSTOMER DATABASE ";
    gotoxy(27, 13);
    cout << "2) ENTER BILL DATABASE ";
    gotoxy(27, 16);
    cout << "3) ENTER BILLING DETAILS ";
    gotoxy(27, 19);
    cout << "4) EXIT FROM PROGRAM " << endl<< endl;
    cout << "=========================================================";
    cout << endl<< "     Enter Your Choice     :";
    gotoxy(1, 25);
    cout << "=========================================================";
    gotoxy(35, 22);
    cin >> ch;
    switch (ch)
    {
    case 1:
	clrscr();
	int op=0;
x:
	clrscr();
	cout << endl<< endl;
	cout << "**************************************";
	cout << endl;
	cout << "\n\t\t\t\t CUSTOMER SECTION ";
	cout << endl;
	cout << "\t\t\t   ================================== ";
	cout << endl<<endl<<endl;
	cout << "\t\t\t\t1) ADD \n\n";
	cout << "\t\t\t\t2) EDIT \n\n";
	cout << "\t\t\t\t3) DELETE\n\n";
	cout << "\t\t\t\t4) VIEW   \n\n";
	cout << "\t\t\t\t5) BACK TO MAIN";
	cout << endl<< endl << endl;
	cout << "**************************************";
	cout << endl << "    Enter Your Choice    :";
	cin >> op;

	if (op == 1)
    {
	    clrscr();
	    cout << "=========================================================";
	    cout << endl;
	    cout << "\t\t\tYOU HAVE CHOSEN TO ADD CUSTOMER";
	    cout << endl<< endl;
	    cout << "=========================================================";
	    jishu.open("customer.dat", ios::binary | ios::app);
	    a.ecustdet();
	    clrscr();
	    cout << "=========================================================";
	    cout << endl;
	    cout << "\t\t\tCUSTOMER ADDED SUCCESSFULLY";
	    cout << endl<< endl;
	    cout << "=========================================================";
	    getch();
	    goto x;
    }
	if (op == 2)
    {
	    flag = 0;
	    int r = 0;
	    clrscr();
	    cout << "=========================================================";
	    cout << endl;
	    cout << "\t\t\tYou Have Chosen To EDIT CUSTOMER";
	    cout << endl;
	    cout << "=========================================================";
	    cout << endl;
	    cout << "\n\n\n\n\n\n\n\n\n\t\t   Enter CUSTOMERR id to be EDITED        :";
	    cin >> cid;
	    clrscr();
	    jk.open("customer.dat", ios::binary);
	    jishu.open("customer.dat", ios::binary | ios::app);
	    if (!jk)
	    {
		cout << "\n\nFile Not Found...";
                goto x;
        }
            jk.seekg(0);
            while (!jk.eof())
            {
                r++;
                jk.read((char *)&a, sizeof(a));
                if (!jk.eof())
                {
                    int x = a.ret();
                    if (x == cid)
                    {
                        flag = 1;
                        jishu.seekp(r - 1 * sizeof(a));
                        a.edcustdet();
                        jishu.close();
                        jk.close();
                        clrscr();
                        cout << "=========================================================";
                        cout << "\t\t\tCUSTOMER EDITED SUCCESSFULLY";
                        cout << endl;
                        cout << "=========================================================";
                        getch();
                        goto x;
                    }
                }
            }
            if (flag == 0)
            {
                cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\tCUSTOMER DOESNOT EXIT...";
                getch();
                jk.close();
                clrscr();
                goto x;
            }
    }
        if (op == 3)
        {
            flag = 0;
            clrscr();

            cout << "=========================================================";
            cout << "\t\t\tYou Have Chosen DELETE CUSTOMER";
            cout << endl<< endl;
            cout << "=========================================================";
            cout << "\n\n\n\n\n\n\n\n\n\t\t   Enter CUSTOMER id to be DELETED  :";
            cin >> cid;
            char sure;
            jk.open("customer.dat", ios::binary);
            if (!jk)
            {
                cout << "\n\nFile Not Found...";
                goto x;
            }
            fstream tmp("temp.dat", ios::binary | ios::out);
            jk.seekg(0);
            while (jk.read((char *)&a, sizeof(a)))
            {
                int x = a.ret();
                if (x != cid)
                    tmp.write((char *)&a, sizeof(a));
                else
                {
                    flag = 1;
                    clrscr();

                    cout << "=========================================================";
                    cout << "\t\t\tAre You SURE You Want To DELETE This ";
                    cout << endl<< endl;

                    cout << "=========================================================";
                    a.scustdet();

                    cout << "=========================================================";
                    cout << endl<< "\n\n\n\n\n\n\t\tEnter 'y' for YES Or ANY other key for CANCLE ";
                    cin >> sure;
                    if (sure != 'y')
                    {
                        clrscr();
                        tmp.close();
                        jk.close();
                        goto x;
                    }
                }
            }
            clrscr();
            jk.close();
            tmp.close();
            jishu.open("customer.dat", ios::trunc | ios::binary);
            jishu.seekp(0);
            tmp.open("temp.dat", ios::binary | ios::in);
            if (!tmp)
            {
                cout << "Error in File";
                goto x;
            }
            while (tmp.read((char *)&a, sizeof(a)))
                jishu.write((char *)&a, sizeof(a));
            tmp.close();
            jishu.close();
            if (flag == 1)
            {
                clrscr();
                a.id = -32;
                cout << "=========================================================";
                cout << endl;
                cout << "\t\t\tCUSTOMER DELETED SUCCESSFULLY";
                cout << endl<< endl;
                cout << "=========================================================";
                getch();
                flag = 0;
                jk.open("bill.dat", ios::binary);
                if (!jk)
                {
                    cout << "\n\nFile Not Found...";
                    goto x;
                }
                fstream tmp("temp.dat", ios::binary | ios::out);
                jk.seekg(0);
                while (jk.read((char *)&x, sizeof(x)))
                {
                    int zx = x.ret();
                    if (zx != cid)
                        tmp.write((char *)&x, sizeof(x));
                    else
                    {
                        flag = 1;
                    }
                }
                tmp.close();
                jk.close();
                x.billid = -32;
                jishu.open("bill.dat", ios::trunc | ios::binary);
                jishu.seekp(0);
                tmp.open("temp.dat", ios::binary | ios::in);
                if (!tmp)
                {
                    cout << "Error in File";
                    getch();
                    goto x;
                }
                while (tmp.read((char *)&x, sizeof(x)))
                    jishu.write((char *)&x, sizeof(x));
                tmp.close();
                jishu.close();
                if (flag == 1)
                {
                    clrscr();
                    cout << "\n\n\n\n\n\n\n\n\n\n\t\t\tBILL OF THIS CUSTOMER ALSO DELETED.....";
                    getch();
                    clrscr();
                    goto x;
                }
                if (flag == 0)
                {
                    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t NO BILL FOUND TO DELETE......";
                    getch();
                    jk.close();
                    clrscr();
                    goto x;
                }
                clrscr();
                goto x;
            }
                if (flag == 0)
                {
                    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\tCUSTOMER DOESNOT EXIST...";
                    getch();
                    jk.close();
                    clrscr();
                    goto x;
                }
        }
            if (op == 4)
            {
                flag = 0;
                clrscr();
                cout << "=========================================================";
                cout << endl;
                cout << "\t\t\tYou Have Chosen To VIEW CUSTOMER";
                cout << endl<< endl;
                cout << "=========================================================";
                cout << "\n\n\n\n\n\n\n\n\n\t\t   Enter CUSTOMER id To be VIEWED      :";
                cin >> cid;
                clrscr();
                cout << "\n\n\n\n\n\n\n";
                jk.open("customer.dat", ios::binary);
                if (!jk)
                {
                    cout << "\n\nFile Not Found...";
                    goto x;
                }
                jk.seekg(0);
                while (!jk.eof())
                {
                    jk.read((char *)&a, sizeof(a));
                    int x = a.ret();
                    if (x == cid)
                    {
                        flag = 1;
                        a.scustdet();
                        jk.close();
                        getch();
                        clrscr();
                        goto x;
                    }
                }
                if(flag == 0)
                {
                clrscr();
                cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\tCUSTOMER DOESNOT EXIST...";
                getch();
                jk.close();
                clrscr();
                goto x;
                }
            }
        if (op == 5)
        {
            clrscr();
            goto y;
        }
        if ((op > 5) || (op == 0))
        {
            clrscr();
            cout << "======================================================================================================================";
            cout << endl;
            cout << "\t\t\tINVALID CHOICE TRY AGAIN  ";
            cout << endl<< endl;
            cout << "======================================================================================================================";
            goto x;
        }
        break;
    case 2:
        clrscr();

        int sel;
z:
        clrscr();
        cout << endl<< endl;
        cout << "****************************************";
        cout << endl;
        cout << "\t\t\t\tBILLING SECTION";
        cout << endl;
        cout << "\t\t\t\t===============";
        cout << endl<< endl<< endl;
        cout << "\t\t\t\t1) ADD \n\n";
        cout << "\t\t\t\t2) EDIT \n\n";
        cout << "\t\t\t\t3) DELETE\n\n";
        cout << "\t\t\t\t4) VIEW   \n\n";
        cout << "\t\t\t\t5) BACK TO MAIN";
        cout << endl<< endl<< endl;
        cout << "****************************************";
        cout << endl<< "    ENTER YOUR CHOICE     :";
        cin >> sel;
        if (sel == 1)
        {
rett:
            clrscr();
            flag = 0;
            cout << "======================================================================================================================";
            cout << endl;
            cout << "\t\t\tYou Have Chosen To ADD BILL ";
            cout << endl << endl;

            cout << "======================================================================================================================";

            cout << "\n\n\n\t\tEnter CUSTOMER id To ADD BILL   :";
            cin >> cid;

            cout << "======================================================================================================================";
            jk.open("customer.dat", ios::binary);
            if (!jk)
            {
                cout << "\n\nFile Not Found...";
                goto z;
            }
            jk.seekg(0);
            while (!jk.eof())
            {
                jk.read((char *)&a, sizeof(a));
                int x = a.ret();
                if (x == cid)
                {
                    flag = 1;
                    a.scustdet();
                    jk.close();
                    goto bill;
                }
            }
            if (flag == 0)
            {
                clrscr();
                cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\tCUSTOMER DOESNOT EXIST...";
                getch();
                jk.close();
                clrscr();
                goto z;
            }
bill:
            jk.open("bill.dat", ios::binary);
            jk.seekg(0);
            while (!jk.eof())
            {
                jk.read((char *)&x, sizeof(x));
                int xp = x.ret();
                if (xp == cid)
                {
                    clrscr();
                    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\tCUSTOMER ALREADY BILLED!!!!!\n\n";
                    jk.close();
                    getch();
                    goto rett;
                }
            }
            jk.close();
            flag = 0;
            jishu.open("bill.dat", ios::binary | ios::app);
            x.billid = cid;
            x.ent();
            clrscr();
            cout << "======================================================================================================================";
            cout << endl;
            cout << "\t\t\tBILL ADDED SUCESSFULLY";
            cout << endl << endl;

            cout << "======================================================================================================================";
            getch();
            goto z;
        }
        if (sel == 2)
        {
            flag = 0;
            int r = 0;
            clrscr();
            cout << "======================================================================================================================";
            cout << endl;
            cout << "\t\t\tYou Have Chosen To EDIT BILL";
            cout << endl;
            cout << "======================================================================================================================";
            cout << endl;
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t  Enter CUSTOMER id to EDIT BILL";
            cin >> cid;
            clrscr();
            jk.open("customer.dat", ios::binary);
            if (!jk)
            {
                cout << "\n\nFile Not Found...";
                goto z;
            }
            jk.seekg(0);
            while (!jk.eof())
            {
                jk.read((char *)&a, sizeof(a));
                int x = a.ret();
                if (x == cid)
                {
                    flag = 1;
                    a.scustdet();
                    jk.close();
                    cout << "\n\n\tPress Any Key To Continue Editing Bill Of This Customer...";
                    getch();
                    clrscr();
                    goto bill2;
                }
            }
            if (flag == 0)
            {
                clrscr();
                cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\tCUSTOMER DOESNOT EXIST...";
                getch();
                jk.close();
                clrscr();
                goto z;
            }
bill2:
            flag = 0;
            jk.open("bill.dat", ios::binary);
            jishu.open("bill.dat", ios::binary | ios::app);
            if (!jk)
            {
                cout << "\n\nFill Not Found...";
                goto z;
            }
            jk.seekg(0);
            while (!jk.eof())
            {
                r++;
                jk.read((char *)&x, sizeof(x));
                if (!jk.eof())
                {
                    int kkx = x.ret();
                    if (kkx == cid)
                    {
                        flag = 1;
                        jishu.seekp((r - 1) * sizeof(x));
                        x.edi();
                        jishu.close();
                        jk.close();
                        clrscr();
                        cout << "======================================================================================================================";
                        cout << "\t\t\tBILL Edited SUCCESSFULLY";
                        cout << endl;
                        cout << "======================================================================================================================";
                        getch();
                        goto z;
                    }
                }
            }
                if (flag == 0)
                {
                    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\tBILL DOESNOT EXIT......";
                    getch();
                    jk.close();
                    clrscr();
                    goto z;
                }
        }
            if (sel == 3)
            {
                flag = 0;
                clrscr();

                cout << "======================================================================================================================";
                cout << "\t\t\tYou Have Chosen To DELETE BILL";
                cout << endl << endl;

                cout << "======================================================================================================================";
                cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t Enter CUSTOMER id To DELETE BILL  :";
                cin >> cid;
                char sure;
                clrscr();
                jk.open("customar.dat", ios::binary);
                if (!jk)
                {
                    cout << "\n\nFile Not Found...";
                    goto z;
                }
                jk.seekg(0);
                while (!jk.eof())
                {
                    jk.read((char *)&a, sizeof(a));
                    int x = a.ret();
                    if (x == cid)
                    {
                        flag = 1;
                        a.scustdet();
                        jk.close();
                        cout << "\n\n\tPress Any Key To Continue Deleting Bill of this Customer...";
                        getch();
                        clrscr();
                        goto bill3;
                    }
                }
                if (flag == 0)
                {
                    clrscr();
                    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\tCUSTOMER DOESNOT EXIST...";
                    getch();
                    jk.close();
                    clrscr();
                    goto z;
                }
bill3:
                flag = 0;
                jk.open("bill.dat", ios::binary);
                if (!jk)
                {
                    cout << "\n\nFile Not Found...";
                    goto z;
                }
                fstream tmp("temp.dat", ios::binary | ios::out);
                jk.seekg(0);
                while (jk.read((char *)&x, sizeof(x)))
                {
                    int zx = x.ret();
                    if (zx != cid)
                        tmp.write((char *)&x, sizeof(x));
                    else
                    {
                        flag = 1;
                        clrscr();
                        cout << "======================================================================================================================";
                        cout << "\t\tAre You Sure You Want To DELETE This??????";
                        cout << endl;
                        cout << "======================================================================================================================";
                        x.sho();

                        cout << "======================================================================================================================";
                        cout<<"\n\t\tEnter 'y' For YES Or ANY oTHER Key For CANCLE : ";
                        cin>>sure;
                        if(sure!='y')
                        {
                            clrscr();
                            tmp.close();
                            jk.close();
                            goto z;
                        }
                    }
                    
                }
                clrscr();
                jk.close();
                tmp.close();
                x.billid=-32;
                jishu.open("bill.dat",ios::trunc|ios::binary);
                jishu.seekp(0);
                tmp.open("temp.dat",ios::binary|ios::in);
                if(!tmp)
                {
                    cout<<"Error in File";
                    goto z;
                }
                while(tmp.read((char*)&x,sizeof(x)))
                    jishu.write((char*)&x,sizeof(x));
                tmp.close();
                jishu.close();
                if(flag==1)
                {
                    clrscr();
                    cout << "======================================================================================================================";
                    cout << "\t\t\tBILL DELETED SUCCESSFULLY";
                    cout << endl << endl;
                    cout << "======================================================================================================================";
                    getch();
                    clrscr();
                    goto z;
                }
                if(flag == 0)
                {
                cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\tBILL DOESNOT EXIST.....";
                getch();
                jk.close();
                clrscr();
                goto z;
                }
            }
        if(sel==4)
        {
        flag=0;
        clrscr();
        cout << "======================================================================================================================";
        cout << endl;
        cout << "\t\t\tYou Have Chosen TO VIEW BILL";
        cout << endl << endl;
        cout << "======================================================================================================================";
        cout << "\n\n\n\n\n\n\n\n\n\t\t  Enter CUSTOME id To VIEW BILL     :";
        cin >> cid;
        clrscr();
        jk.open("customer.dat",ios::binary);
        if(!jk)
        {
            cout << "\n\nFile Not Found...";
            goto z;
        }
        jk.seekg(0);
        while(!jk.eof())
        {
            jk.read((char*)&a,sizeof(a));
            int x=a.ret();
            if(x==cid)
            {
                flag = 1;
                a.scustdet();
                jk.close();
                goto bill4;
            }
        }
        if(flag==0)
        {
            clrscr();
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\tCUSTOMER DOESNOT EXIST...";
            getch();
            jk.close();
            clrscr();
            goto z;
        }
bill4:
        flag = 0;
        jk.open("bill.dat",ios::binary);
        if(!jk)
        {
            cout << "\n\nFile Not Found...";
            goto z;
        }
            jk.seekg(0);
            while(!jk.eof())
            {
                jk.read((char*)&x,sizeof(x));
                int px=x.ret();
                if(px==cid)
                {
                    flag = 1;
                    x.sho();
                    jk.close();
                    getch();
                    clrscr();
                    goto z;
                }
            }
            if(flag==0)
            {
                clrscr();
                cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\tBILL DOESNOT EXIST......";
                getch();
                clrscr();
                jk.close();
                goto z; 
            }
        }
        if(sel==5)
        {
            clrscr();
            goto y;
        }
        if((sel>5)||(sel==-0))
        {
            clrscr();
            cout << "======================================================================================================================";
            gotoxy(28,2);
            cout << "INVALID CHOICE TRY AGAIN  ";
            cout << endl;
            cout << "======================================================================================================================";
            goto z;
        }
        break;
    case 3:
        char f[1];
        clrscr();
        cout << "======================================================================================================================";
        cout << endl;
        cout << "\t\t\tBILLING DETAILS";
        cout << endl <<endl;
        cout << "======================================================================================================================";
        cout << "\t\t STD RATE = Rs.1/minute"<<endl <<endl;
        cout << "\t\t National Roaming Outgoing RATE = Rs.2/minute"<<endl<<endl;
        cout << "\t\t National Roaming Incoming RATE = Rs.2.5/minute"<<endl<<endl;
        cout << "\t\t SMS RATE = Rs.0.50/SMS"<<endl<<endl;
        cout << "\t\t MMS RATE = Rs.3/MMS"<<endl<<endl;
        cout << "\t\t GRPS RATE = Rs.0.10/Kb"<<endl<<endl;
        cout << "\t\t ISD RATE = Rs.8/minute"<<endl<<endl;
        cout << "\t\t International Roaming Outgoing RATE = Rs.15/minute"<<endl<<endl;
        cout << "\t\t International Roaming Outgoing RATE = Rs.15/minute"<<endl<<endl;
        gets(f);
        clrscr();
        goto y;
        
    case 4:
        clrscr();
        char s;
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\tAre You Sure ??? (Enter 'y' for YES and ANY key for NO)    :";
        cin >> s;
        if(s=='y')
        {
            cout << "\n\n\nWe Readily acknowledge my indebtedness to our computer teacher for him support, dedication and honest efforts that has given us immense help in completing this project."<<endl;
            cout << "\n\n\t Created by Jishan Kumar, Rohit Kumar, Rajesh Kumar and Suraya dav kant BCA 6th sem"<<endl;
            getch();
            exit(0);
        }
        if(s!='y')
        {
            clrscr();
            goto y;
        }
    default:
        clrscr();
        cout << "======================================================================================================================";
        gotoxy(20,2);
        cout << "INVALID CHOICE TRY AGAIN   ";
        cout << endl;
        cout << "======================================================================================================================";
        goto y;
    }
    getch();
}

