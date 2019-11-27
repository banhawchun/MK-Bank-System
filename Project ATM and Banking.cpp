#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<iomanip>
#include<fstream>
#include<string.h>
#include<math.h>
#include <cctype>
#include <ctime>
#include "antheader.h"
#define FileName "Accounts.bin"
using namespace std;

//Glboal declaration
int x= 30, y= 10;
char aanumber[8]= {0}, aapin[5]= {0};

class machine
{
	private:
		
		float  amnt;
		char name[30], city[15], email[40], type;
		char accNum[7], pin[5]; //acc: 121200++
		int date, month, year;	
		
	public:
	
		machine()
		{
			strcpy(this->accNum, "121200");
			strcpy(this->pin, "1000");
		}
		//setter
		void setAccountNum(const char accNum[])
		{
			strcpy(this->accNum, accNum);
		}
		void setAutoPin(const char pins[])
		{
			strcpy(this->pin, pins);
		}
		//getter
		char* getAccountNum()
		{
			return this->accNum;
		}
		char* getAccountNumTransfer()
		{
			return this->accNum;
		}
		char* getPin()
		{
			return this->pin;
		}
		
		char* getAutoNum();
		
		void header();
		void main_menu();
		void sub_menu();
		void create_account();	
		void modify_account();
		void outputData();
		void help();
				
		void cash_deposit();
		void balance_enquiry();
		void change_pin();
		void other_services();
	
		void fast_cash();
		void cash_withdraw();
		bool cash_transfer(machine &fromAcc, float trsfamnt);
		void transfermsg();
		void mini_statement();

		void admin();
		void getname();
		void getnameTransfer();
		void exit_note();	
		machine loginAcc();
}; //***end class***/

//Global object
machine m1, m2;

//Creaate file stream
fstream rw; ifstream r; ofstream w;


char* machine::getAutoNum()
{
	long autoNum, autopin= 0;
	r.open(FileName, ios::in | ios::binary);
	if(r.good())
	{
		r.read( (char*)&m1, sizeof(m1) );
		
		while(!r.eof())
		{
			r.read( (char*)&m1, sizeof(m1) );
		}
		r.close();	
	}
	
	autoNum = atol(m1.accNum);
	autoNum ++;
	
	autopin = atol(m1.pin);
	srand(time(0));
	autopin = rand() % 9000 + 10;
	
	this->setAccountNum(to_string(autoNum).c_str());
	this->setAutoPin(to_string(autopin).c_str());
	return this->accNum;
	return this->pin;
}


void intro()
{
	int q= 20, w= 5, e= 54, o, p;
	system("color 8F");
	setcursor(0,0);
	foreColor(55);
//top M
	gotoxy(q+1, w); cout<<(char)178<<(char)178<<(char)178<<(char)178<<(char)178<<(char)178;
	gotoxy(q+6, w+1); cout<<(char)178<<(char)178;
	gotoxy(q+8, w+2); cout<<(char)178<<(char)178;
	gotoxy(q+10, w+3); cout<<(char)178<<(char)178;
	gotoxy(q+12, w+4); cout<<(char)178<<(char)178;
	gotoxy(q+14, w+3); cout<<(char)178<<(char)178;
	gotoxy(q+16, w+2); cout<<(char)178<<(char)178;
	gotoxy(q+18, w+1); cout<<(char)178<<(char)178;
	gotoxy(q+19, w); cout<<(char)178<<(char)178<<(char)178<<(char)178<<(char)178<<(char)178;		
//left M		
	gotoxy(q+1,w+1);cout<<(char)178<<(char)178;
	gotoxy(q+1,w+2);cout<<(char)178<<(char)178;
	gotoxy(q+1,w+3);cout<<(char)178<<(char)178;
	gotoxy(q+1,w+4);cout<<(char)178<<(char)178;
	gotoxy(q+1,w+5);cout<<(char)178<<(char)178;
	gotoxy(q+1,w+6);cout<<(char)178<<(char)178;
	gotoxy(q+1,w+7);cout<<(char)178<<(char)178;
	gotoxy(q+1,w+8);cout<<(char)178<<(char)178;
	gotoxy(q+1,w+9);cout<<(char)178<<(char)178;
	gotoxy(q+1,w+10);cout<<(char)178<<(char)178;	
//right M
	gotoxy(q+23,w+1);cout<<(char)178<<(char)178;
	gotoxy(q+23,w+2);cout<<(char)178<<(char)178;
	gotoxy(q+23,w+3);cout<<(char)178<<(char)178;
	gotoxy(q+23,w+4);cout<<(char)178<<(char)178;
	gotoxy(q+23,w+5);cout<<(char)178<<(char)178;
	gotoxy(q+23,w+6);cout<<(char)178<<(char)178;
	gotoxy(q+23,w+7);cout<<(char)178<<(char)178;
	gotoxy(q+23,w+8);cout<<(char)178<<(char)178;
	gotoxy(q+23,w+9);cout<<(char)178<<(char)178;
	gotoxy(q+23,w+10);cout<<(char)178<<(char)178;	
//left K
	gotoxy(e,w);cout<<(char)178<<(char)178;
	gotoxy(e,w+1);cout<<(char)178<<(char)178;
	gotoxy(e,w+2);cout<<(char)178<<(char)178;
	gotoxy(e,w+3);cout<<(char)178<<(char)178;
	gotoxy(e,w+4);cout<<(char)178<<(char)178;
	gotoxy(e,w+5);cout<<(char)178<<(char)178;
	gotoxy(e,w+6);cout<<(char)178<<(char)178;
	gotoxy(e,w+7);cout<<(char)178<<(char)178;
	gotoxy(e,w+8);cout<<(char)178<<(char)178;
	gotoxy(e,w+9);cout<<(char)178<<(char)178;
	gotoxy(e,w+10);cout<<(char)178<<(char)178;	
//top K
	gotoxy(e+2, w+5); cout<<(char)178<<(char)178;
	gotoxy(e+4, w+4); cout<<(char)178<<(char)178;
	gotoxy(e+6, w+3); cout<<(char)178<<(char)178;
	gotoxy(e+8, w+2); cout<<(char)178<<(char)178;
	gotoxy(e+10, w+1); cout<<(char)178<<(char)178;
	gotoxy(e+12, w); cout<<(char)178<<(char)178;	
//bottom K
	gotoxy(e+4, w+6); cout<<(char)178<<(char)178;
	gotoxy(e+6, w+7); cout<<(char)178<<(char)178;
	gotoxy(e+8, w+8); cout<<(char)178<<(char)178;
	gotoxy(e+10, w+9); cout<<(char)178<<(char)178;
	gotoxy(e+12, w+10); cout<<(char)178<<(char)178;
//line
foreColor(139);
	gotoxy(14, 18); cout<<setfill((char)205)<<setw(63)<<"";delay(500);
//bottom line text
e = 16, w = 20;
foreColor(143);
	gotoxy(e, w); cout<< "B"; delay(100);
	gotoxy(e+4, w); cout<< "A"; delay(100);
	gotoxy(e+8, w); cout<< "N"; delay(100);
	gotoxy(e+12, w); cout<< "K"; delay(100);
	gotoxy(e+22, w); cout<< "M"; delay(100);
	gotoxy(e+26, w); cout<< "A"; delay(100);
	gotoxy(e+30, w); cout<< "N"; delay(100);
	gotoxy(e+34, w); cout<< "A"; delay(100);
	gotoxy(e+38, w); cout<< "G"; delay(100);
	gotoxy(e+42, w); cout<< "E"; delay(100);
	gotoxy(e+46, w); cout<< "M"; delay(100);
	gotoxy(e+50, w); cout<< "E"; delay(100);
	gotoxy(e+54, w); cout<< "N"; delay(100);
	gotoxy(e+58, w); cout<< "T"; delay(100); delay(200);
	for (int c = 1; c <= 10; c++)  //randomly printing "$"
	{
		foreColor(142);
		o = rand() % 50 + 1;  p = rand() % 20 + 1;
		gotoxy(o, p);cout<<"$";
		delay(150);gotoxy(o,p);cout<<" ";
	}
//getch
foreColor(131);gotoxy(6, 28);
	for(int i = 1; i<=15; i++)
	{
		 cout<<(char)177;
	}
	foreColor(142);
	gotoxy(23, 28); cout<< "P R E S S   A N Y K E Y    T O    C O N T I N U E";

	foreColor(131);
	gotoxy(74, 28);
	for(int i = 1; i<=15; i++)
	{
		 cout<<(char)177;
	}	
	getch();
}

// *********Normal FUNCTION***************
void printTransaction()
{
	cls();
	setcursor(0,0);
	foreColor(63);
	gotoxy(34, 15); cout<< "TRANSACTION COMPLETE";
	gotoxy(54, 15); delay(800); cout<<".";
	gotoxy(55, 15); delay(800); cout<<".";
	gotoxy(56, 15); delay(800); cout<<"."; delay(800);
}

void printWrongTransaction()
{
	foreColor(63);
	setcursor(0,0);
	gotoxy(20, 31); cout<< "WITHDRAWAL AMOUNT IS HIGHER THAN AVAILABLE BALANCE \a";
	gotoxy(71, 31); delay(500); cout<< "!";
	gotoxy(72, 31); delay(500); cout<< "!";
	gotoxy(73, 31); delay(500); cout<< "!"; delay(1100);
}

void printExclamationMark()
{
	foreColor(63);
	setcursor(0,0);
	gotoxy(57, 20); delay(500); cout<< "!";
	gotoxy(58, 20); delay(500); cout<< "!";
	gotoxy(59, 20); delay(500); cout<< "!"; delay(1100);
}

void printLoginInfo()
{
	setcursor(0,0);
	gotoxy(30, 4); cout<< "SUCCESSFULLY CREATE NEW ACCOUNT";
	foreColor(253);
	gotoxy(0, 10); cout<< setfill('-')<<setw(105)<<"";
	gotoxy(34, 12); cout<< "ACCOUNT NUMBER: "<< m1.getAccountNum();
	gotoxy(34, 15); cout<< "YOUR PIN CODE IS: "<<m1.getPin();
	gotoxy(0, 17); cout<< setfill('-')<<setw(105)<<"";
	foreColor(252); delay(800);
	gotoxy(10, 22); cout<< "THESE ARE INFORMATION TO LOGIN TO YOUR ACCOUNT";
	gotoxy(10, 24); cout<< "ALSO DON'T GIVE ANY OF THESE INFORMATION TO ANYONE!!!";
	foreColor(240);
	gotoxy(10, 30); cout<< "Press anykey to continue...";
	getch();	
}
 
bool isLeap(int year)
{
	return ( ((year % 4 ==0) && (year % 100 !=0)) || (year % 400 ==0));
}

bool isValidDate(int day, int month, int year)
{
	//Handle February (Leap Year)
	if(month == 2)
	{
		if(isLeap(year))
		{
			return (day <= 29);
		}
		else
		{
			return (day <= 28);
		}
	}
	
	// Months of April, June, Sept and Nov must have number of days less than or equal to 30. 
    if (month == 4 || month == 6 || month == 9 || month == 11)
    {
    	return (day <=30);
	}
	
	return true;
}
// *********END Normal FUNCTION***************

//**************write and read to File***************
void writeAccount()
{
	w.open(FileName, ios::out | ios::app | ios::binary);
	
	m1.setAccountNum(m1.getAutoNum());
	
	m1.create_account();
	
	w.write( (char*)&m1, sizeof(m1) );
	w.close();
	
}

void readAccount()
{
	x= 3, y= 3;
	r.open(FileName, ios::out | ios::in | ios::binary);
	if(r.good())
	{
		r.seekg(0);
		r.read( (char*)&m1, sizeof(m1) );
		
		while(!r.eof())
		{
			gotoxy(x, y+=2); m1.outputData();
			r.read( (char*)&m1, sizeof(m1) );
		}
		r.close();
	}
	else
	{
		cls();
		gotoxy(20, 15); cout<<"File Not Found!!!";
	}
}
//**************End write and read to file**************

//--------------Function search update delete.....------------
void searchAccount()
{
	x= 3, y= 2;
	rw.open(FileName, ios::out | ios::in | ios::binary);
	if(rw.good())
	{
		char searchByAccNum[10]; bool is_Found = false;
		
		gotoxy(2, 15); cout<<"Press Enter to Search";
		gotoxy(10, 0);cout<<"\nEnter Account Number: ";
		cin>>searchByAccNum; fflush(stdin);
		
		rw.seekg(0);
		rw.read( (char*)&m1, sizeof(m1));
		while(!rw.eof())
		{
			if( strcmp(searchByAccNum, m1.getAccountNum()) == 0 )
			{				
					gotoxy(x, y+=3); m1.outputData();
					gotoxy(32, 12);cout<<"Press any key to continue... ";
					break;	
			}		
		 rw.read( (char*)&m1, sizeof(m1));
		 
		 	if( strcmp(searchByAccNum, m1.getAccountNum()) != 0 )
			{
				gotoxy(x+20, y+5);cout<<"THIS ACCOUNT NUMBER IS NOT AVAILABLE!!";
			}		 	
		}// end while
	  rw.close(); 	  
	} //end if good	
	else
	{
		cls();
		gotoxy(20, 5);cout<<"File not found";
	}	
}

void updateAccount()
{
	rw.open(FileName, ios::out | ios::in | ios::binary);
	if(rw.good())
	{
		char updateByAccNum[10]; bool is_Update = false;
		
		gotoxy(2, 17); cout<<"Press Enter to Search";
		gotoxy(10, 0); cout<<"\nEnter Account Number: ";
		cin>>updateByAccNum; fflush(stdin);
		
		rw.read( (char*)&m1, sizeof(m1) );
		while(!rw.eof())
		{
			if( strcmp(updateByAccNum, m1.getAccountNum()) == 0)
			{
				rw.seekg(0, ios::cur);
				int size= rw.tellg();
				m1.modify_account();
				
				rw.seekp(size - sizeof(m1) );
				rw.write( (char*)&m1, sizeof(m1) );
				is_Update = true;
			}
			rw.read( (char*)&m1, sizeof(m1) );
		}
		
			if(is_Update == false)
			{
				foreColor(236);
				gotoxy(10, 5);cout<<"THIS ACCOUNT NUMBER IS NOT AVAILABLE!!";
			}
			
			else
			{
				foreColor(233);
				gotoxy(10, 13);cout<<"Successfully Updated...";
			}	
			rw.close();			
	}//end if good
	else
	{
		cls();
		gotoxy(30, 10); cout<<"File not found!";
	}
}

void deleteAccount()
{
	r.open(FileName, ios::in | ios::binary);
	w.open("Filetmp.bin", ios::out | ios::app | ios::binary);
	
	if(r.fail())
	{
		cls();
		gotoxy(30, 10); cout<<"File not found!";
	}
	else
	{
		char deleteByAccNum[10]; bool is_Deleted = false;
		
		gotoxy(2, 12); cout<<"Press Enter to Search";
		gotoxy(0, 1); cout<<"Enter Account Number: "; 
		cin>>deleteByAccNum; fflush(stdin);
		
		r.seekg(0);
		r.read( (char*)&m1, sizeof(m1) );
		while(!r.eof())
		{
			if( strcmp(deleteByAccNum, m1.getAccountNum()) == 0 )
			{
				is_Deleted = true;
			}
			else
			{
				w.write((char*)&m1, sizeof(m1));
			}
		  r.read( (char*)&m1, sizeof(m1) );
		}
		r.close();
		w.close();
		remove(FileName);
		rename("Filetmp.bin", FileName);
		
		//Message for deleted
		if(is_Deleted == false)
		{
			foreColor(236);
			gotoxy(10, 5);cout<<"THIS ACCOUNT NUMBER IS NOT AVAILABLE!!";
		}
		else
		{
			foreColor(233);
			gotoxy(10, 8);cout<<"Successfully Deleted...";
		}
	}
}
//--------------End Function search update delete .....------------

//--------------	Start Function in Sub Menu .....------------
void changePinCode()
{
	rw.open(FileName, ios::out | ios::in | ios::binary);
	if(rw.good())
	{
		char oldPin[5], updatePinByAcc[10]; bool is_Changed = false;
		
		m1.loginAcc();
		
		rw.read( (char*)&m1, sizeof(m1) );
		while(!rw.eof())
		{
			if( strcmp(aanumber, m1.getAccountNum()) == 0 )
			{
				if( strcmp(aapin, m1.getPin()) == 0 )
				{
					m1.getname();
					rw.seekg(0, ios::cur);
					int size= rw.tellg();
					m1.change_pin();
						
					rw.seekp(size - sizeof(m1) );
					rw.write( (char*)&m1, sizeof(m1) );
					is_Changed = true;
				}	
			}
			rw.read( (char*)&m1, sizeof(m1) );
		}
		rw.close();
		
		if(is_Changed == false)
		{
			foreColor(63);
			setcursor(0,0);
			gotoxy(10, 20);cout<<"THIS ACCOUNT NUMBER OR PIN CODE IS NOT CORRECT!";
			printExclamationMark();
		}
			
		else
		{
			foreColor(63);
			setcursor(0,0);
			gotoxy(20, 20);cout<<"Successfully Updated..."; delay(1000);
			printTransaction();
		}
		rw.close();
	}//end if good
	else
	{
		cls();
		gotoxy(30, 10); cout<<"File not found!"; getch();
	}
}

void depositCash()
{
	rw.open(FileName, ios::out | ios::in | ios::binary);
	char accCheck[10], pinCheck[5]; bool is_Added = false;
	
	if(rw.good())
	{	
		m1.loginAcc();
	
		rw.read( (char*)&m1, sizeof(m1) );
		while(!rw.eof())
		{
			if( strcmp(aanumber, m1.getAccountNum()) == 0 )
			{
				if( strcmp(aapin, m1.getPin()) == 0 )
				{
					m1.getname();
					rw.seekg(0, ios::cur);
					int size= rw.tellg();
					m1.cash_deposit();
					
					rw.seekp(size - sizeof(m1) );
					rw.write( (char*)&m1, sizeof(m1) );
					is_Added = true;
				}	
			}	
		  rw.read( (char*)&m1, sizeof(m1) );
		}	
		rw.close();
		
		if(is_Added == true)
		{
			foreColor(63);
			setcursor(0,0);
			gotoxy(20, 16);cout<<"Successfully Deposit..."; delay(1000);
			printTransaction();
		}	
		else
		{
			foreColor(63);
			setcursor(0,0);
			gotoxy(10, 20);cout<<"THIS ACCOUNT NUMBER OR PIN CODE IS NOT CORRECT!";
			printExclamationMark();
		}
		rw.close();		
	}//end if good
	else
	{
		cls();
		gotoxy(30, 10); cout<<"File not found!"; getch();
	}
}

void balanceCheck()
{
	rw.open(FileName, ios::out | ios::in | ios::binary);
	char balCheck[10], pinCheck[5]; bool is_Check = false;
	
	if(rw.good())
	{	
		m1.loginAcc();
	
		rw.read( (char*)&m1, sizeof(m1) );
		while(!rw.eof())
		{
			if( strcmp(aanumber, m1.getAccountNum()) == 0 )
			{
				if( strcmp(aapin, m1.getPin()) == 0 )
				{
					m1.getname();
					m1.balance_enquiry();
					is_Check = true;
				}
			}
		  rw.read( (char*)&m1, sizeof(m1) );
		}
		rw.close();
		
		if(is_Check == false)
		{
			foreColor(63);
			gotoxy(10, 20);cout<<"THIS ACCOUNT NUMBER OR PIN CODE IS NOT CORRECT!";
			printExclamationMark();
			setcursor(1, 10);
		}
		rw.close();	
	}//end if good
	else
	{
		cls();
		gotoxy(30, 10); cout<<"File not found!"; getch();
	}
}

void withdrawCash()
{
	rw.open(FileName, ios::out | ios::in | ios::binary);
	char accCheck[10], pinCheck[5]; bool is_Added = false;
	
	if(rw.good())
	{	
		m1.loginAcc();
	
		rw.read( (char*)&m1, sizeof(m1) );
		while(!rw.eof())
		{
			if( strcmp(aanumber, m1.getAccountNum()) == 0 )
			{
				if( strcmp(aapin, m1.getPin()) == 0 )
				{
					m1.getname();
					rw.seekg(0, ios::cur);
					int size= rw.tellg();
					m1.cash_withdraw();
					
					rw.seekp(size - sizeof(m1) );
					rw.write( (char*)&m1, sizeof(m1) );
					is_Added = true;
				}	
			}	
		  rw.read( (char*)&m1, sizeof(m1) );
		}	
		rw.close();
		
		if(is_Added == true)
		{
			foreColor(63);
			setcursor(0,0);
			gotoxy(20, 19);cout<<"Successfully Withdraw..."; delay(1000);
			printTransaction();	
		}	
		else
		{
			foreColor(63);
			setcursor(0,0);
			gotoxy(10, 20);cout<<"THIS ACCOUNT NUMBER OR PIN CODE IS NOT CORRECT!";
			printExclamationMark();
		}
		rw.close();		
	}//end if good
	else
	{
		cls();
		gotoxy(30, 10); cout<<"File not found!"; getch();
	}
}

void fastCashwithdraw()
{
	rw.open(FileName, ios::out | ios::in | ios::binary);
	char accCheck[10], pinCheck[5]; bool is_Added = false;
	
	if(rw.good())
	{	
		m1.loginAcc();
	
		rw.read( (char*)&m1, sizeof(m1) );
		while(!rw.eof())
		{
			if( strcmp(aanumber, m1.getAccountNum()) == 0 )
			{
				if( strcmp(aapin, m1.getPin()) == 0 )
				{
					m1.getname();
					rw.seekg(0, ios::cur);
					int size= rw.tellg();
					m1.fast_cash();
					
					rw.seekp(size - sizeof(m1) );
					rw.write( (char*)&m1, sizeof(m1) );
					is_Added = true;
				}	
			}	
		  rw.read( (char*)&m1, sizeof(m1) );
		}	
		rw.close();
		
		if(is_Added == false)
		{
			foreColor(63);
			setcursor(0,0);
			gotoxy(10, 20);cout<<"THIS ACCOUNT NUMBER OR PIN CODE IS NOT CORRECT!";
			printExclamationMark();
	
		}		
	}//end if good
	else
	{
		cls();
		gotoxy(30, 10); cout<<"File not found!"; getch();
	}
}

void transferCash()
{
	fstream f;
	float trsfamnt;
	char accountTrsf[10]; bool is_Log = false, is_Transfer = false;
	f.open(FileName, ios::out | ios::in | ios::binary);
	
	if(f.good())
	{
		cls();
		m1.loginAcc();
		f.seekg(0);
		
		while(f.read( (char*)&m1, sizeof(m1) ))
		{
			if( strcmp(aanumber, m1.getAccountNum()) == 0)
			{
				if( strcmp(aapin, m1.getPin()) == 0)
				{
					m1.getname();
					rw.open(FileName, ios::out | ios::in | ios::binary);
					cls();
					foreColor(62);
					gotoxy(2, 12); cout<<"Press Enter to confirm";
					gotoxy(3, 3); cout<<"Enter Account number you want to transfer to: ";cin>>accountTrsf;fflush(stdin);	
					if(rw)
					{
						rw.seekg(0);
						while(rw.read( (char*)&m2, sizeof(m2) ))
						{
							if(strcmp(accountTrsf, m2.getAccountNum()) ==0)
							{
						reEnter:
								cls();
								m2.getnameTransfer();
								gotoxy(2, 12); cout<<"Press Enter to confirm or Input 0 to exit";
								gotoxy(3, 5); cout<<"Enter Amount you want to transfer: $ "; cin>>trsfamnt;fflush(stdin);
								rw.seekg(0, ios::cur);
								int size = rw.tellg();
								if(trsfamnt <0)
								{
									gotoxy(28, 16); cout<<"YOU MUST INPUT AMOUNT BIGGER THAN $0...";
									getch();
									goto reEnter;
								}
								m2.cash_transfer(m1, trsfamnt);
								rw.seekp(size - sizeof(m2));
								rw.write((char*)&m2, sizeof(m2));
								is_Log = true;
							}
						}
						rw.close();
					}//end account transfer
					
					f.seekg(0, ios::cur);
					int size = f.tellg();
					f.seekp(size-sizeof(m1));
					f.write((char*)&m1, sizeof(m1));
				}
			}
		}
		f.close();
		
		if(is_Log == false)
		{
			foreColor(63);
			setcursor(0,0);
			gotoxy(10, 20);cout<<"THIS ACCOUNT NUMBER OR PIN CODE IS NOT CORRECT!";
			printExclamationMark();
		}
		else
		{
			foreColor(63);
			setcursor(0,0);
			gotoxy(20, 19);cout<<"Successfully Transfer Money..."; delay(1000);
			printTransaction();
		}
	}//end if good
	else
	{
		cls();
		gotoxy(30, 10); cout<<"File not found!"; getch();
	}
}
//--------------	Start Function in Sub MEnu .....------------

// +++++++++Definition to member function++++++++++++++++
//Header
void machine::header()
{
	int a= 2, b= 4;
	gotoxy(34, 2); cout<<"-----ACCOUNT HOLDER LIST-----";
	gotoxy(1, 3); cout<<setfill('=')<<setw(100)<<"";	
	gotoxy(1, 6); cout<<setfill('=')<<setw(100)<<"";
	
	gotoxy(a+1, b); cout<<"ACC NUMBER";
	gotoxy(a+18, b); cout<<"PIN";
	gotoxy(a+30, b); cout<<"FULL NAME";
	gotoxy(a+53, b); cout<<"DATE OF BIRTH";
	gotoxy(a+54, b+1); cout<<"(dd/mm/yyyy)";
	gotoxy(a+73, b); cout<<"TYPE";
	gotoxy(a+73, b+1); cout<<"(s/c)";
	gotoxy(a+86, b); cout<<"AMOUNT";
	
	gotoxy(1, 2+y); cout<<setfill('-')<<setw(100)<<"";
}

//Main menu
void machine::main_menu()
{
	start:	
	
		cls();
		string menu[] = {"1.CREATE ACCOUNT", "2.PROCEED TO LOGIN","3.ADMIN LOGIN", "4.HELP", "5.EXIT"};
		
		system("color 7F"); //set background color and font color
		setcursor(0, 0); 
		
		x= 33, y= 12;
		int n= sizeof(menu)/sizeof(string);
		 
		int ascii= 0, index= 0, press= 0;
		int coordMenuY= y, moveY= 0;
		
		foreColor(124);
		gotoxy(36, 3);	cout<< "**** MENU ****";
		
		gotoxy(33,1);foreColor(112);cout<<(char)219<<(char)219<<(char)219<<(char)219<<(char)219<<(char)219<<(char)219
				<<(char)219<<(char)219<<(char)219<<(char)219<<(char)219<<(char)219<<(char)219<<(char)219<<(char)219
				<<(char)219<<(char)219<<(char)219<<(char)219;  														   //top
	
		gotoxy(30,5);cout<<(char)219<<(char)219<<(char)219<<(char)219<<(char)219<<(char)219<<(char)219<<(char)219
				<<(char)219<<(char)219<<(char)219<<(char)219<<(char)219<<(char)219<<(char)219<<(char)219<<(char)219
				<<(char)219<<(char)219<<(char)219<<(char)219<<(char)219<<(char)219<<(char)219<<(char)219<<(char)219;   //bottom
				
				gotoxy(32,2);cout<<(char)186<<(char)186;
				gotoxy(31,3);cout<<(char)186<<(char)186;
				gotoxy(30,4);cout<<(char)186<<(char)186;  //left
				gotoxy(52,2);cout<<(char)186<<(char)186;
				gotoxy(53,3);cout<<(char)186<<(char)186;
				gotoxy(54,4);cout<<(char)186<<(char)186;  //right
		
		DrawRectangle(24, 8, 40, 20, 125);
		
		//Footer
		gotoxy(13, 32); cout<<"Press Arrow key to go up and down :  Press Enter to Select";
		
		//show menu
		for(int i= 0; i<n; i++)
		{
			gotoxy(x, y); cout<<menu[i]; y+=2;
		}
		
		moveY = y - 2;
		y= coordMenuY;
		
		//Select Menu
		while(1)
		{
			if(press == index)
			{
				foreColor(113);
				gotoxy(x, y); cout<<menu[index];
			}
						
			ascii= getch();
			switch(ascii)
			{
				case 80: //key down
				{
					foreColor(125);
					gotoxy(x, y); cout<<menu[index];

					index++; index= (index>=n)? 0 : index;   
					y+=2; y= (y>moveY)? coordMenuY: y; 
					press++; press = (press>=n)? 0 : press;
				}break;
						
				case 72: //key down
				{
					foreColor(125);
					gotoxy(x, y); cout<<menu[index];
						
					index--; index= (index<0)? n-1: index;	
					y-=2; y= (y<coordMenuY)? moveY : y;
					press--; press= (press<0)? n-1: press;
				}break;
				
				case 13:
				{
					char ch;
					do
					{
						if(press == 0)
						{
							cls();
							writeAccount();
							goto start;
						}
						if(press == 1)
						{
							cls();
							m1.sub_menu();
							
							
							gotoxy(30, 27); cout<<"Press TAB key to exit";
							ch= getch();
								if(ch == 9) m1.main_menu();	
						}
						if(press == 2)
						{
							cls();
							m1.admin();
							
							foreColor(236);
							gotoxy(30, 27); cout<<"Press TAB key to exit";
							ch= getch();
								if(ch == 9) goto start;	
						}
						if(press == 3)
						{
							cls();
							m1.help();
						}
						if(press == 4)
						{
							cls();
							foreColor(125);
							gotoxy(30, 12); cout<< "Thanks for using our service";
							gotoxy(36, 16); cout<< "HAVE A NICE DAY";
							getch();
							exit(0);	
						}	
					}while(ch!= 9);		
				}break;  //end case 13 (enter key) 			
			}//end switch
		}//end while
}//end void

//Sub menu
void machine::sub_menu()
{
	cls();
	setcursor(1,10);
afterlog:
	char action;
	x= 35, y= 2;	
	foreColor(63);	
	
	cls();
	foreColor(62);
	gotoxy(x, y); cout<<"CHOOSE YOUR OPERATION";	
		
	foreColor(63);
	gotoxy(0, 5); cout<<setfill('-')<< setw(100)<<"";
	gotoxy(7, 7); cout<<"1.CASH DEPOSIT";
	gotoxy(7, 12); cout<<"2.BALANCE INQUIRY";
	gotoxy(7, 17); cout<<"3.CHANGE PIN CODE";
	gotoxy(7, 22); cout<<"4.OTHER SERVICES";
	gotoxy(70, 7); cout<<"5.FAST CASH";
	gotoxy(70, 12); cout<<"6.CASH WITHDRAWAL";
	gotoxy(70, 17); cout<<"7.CASH TRANSFER";
	gotoxy(70, 22); cout<<"8.EXIT TO MAIN MENU";
	gotoxy(0, 24); cout<<setfill('-')<< setw(100)<<"";
	
	foreColor(62);
	gotoxy(26, 35); cout<< "Choose your operation from 1 to 8";
	gotoxy(31, 37); cout<< "Press Enter to confirm";
		
	while(1)
 	{
		foreColor(62);
		gotoxy(0, 28); cout<<setfill(' ')<<setw(80)<<"";
		gotoxy(0, 32); cout<<setfill(' ')<<setw(80)<<"";
		gotoxy(10, 28); cout<<"SELECT YOUR OPTION:  "; cin>>action; fflush(stdin);
		
		switch(action)
		{
					case '1':
					{
						cls();
						depositCash();
						m1.main_menu();
						
					} break;
					case '2':
					{
						cls();
						balanceCheck();
						goto afterlog;
						
					} break;
					case '3':
					{
						cls();
						changePinCode();
						m1.main_menu();
					
					} break;
					case '4':
					{
						cls();
						m1.other_services();
						getch();
						goto afterlog;
						
					} break;
					case '5':
					{
						cls();
						fastCashwithdraw();
						m1.main_menu();
						
					} break;
					case '6':
					{
						cls();
						withdrawCash();
						m1.main_menu();
						
					} break;
					case '7':
					{
						cls();
						transferCash();
						m1.main_menu();
						
					} break;
					case '8':
					{
						delay(500);
						m1.main_menu();
						getch(); 
						
					} break;
					default:
					{
						foreColor(63);
						gotoxy(36, 32); cout<<"WRONG INPUT! \a";
						getch();
					}
		}// end switch
 	}//end while
}

//create account
void machine::create_account()
{
	string draw;
	int count = 0;
	char input;
	const int minYear = 1800;
	const int maxYear = 3000;
	
	x= 35, y=2;
	system("color FD");
	setcursor(1,10);
	foreColor(252);
	gotoxy(x, y); cout<<"*** APPLICATION FORM ***";
	DrawRectangle(2, 4, 90, 29, 248);
	
	//draw box for input
	foreColor(242);
	drawRec(2, 5, 45, 2, draw);
	drawRec(2, 8, 45, 5, draw);
	drawRec(2, 14, 45, 2, draw);
	drawRec(2, 17, 45, 2, draw);
	drawRec(2, 20, 45, 2, draw);
	drawRec(2, 23, 45, 2, draw);
	
	
	foreColor(253);
	gotoxy(5, 32); cout<<"Press Enter to confirm";
	
name1:	
	gotoxy(6, 6); cout<<"Enter Full Name: "; gets(name);
			if(strlen(name)<= 1)
			{
					delay(40);
					for(int i= 0; i<60; i++)
					{
						gotoxy(15+i, 6); cout<<" ";
					}
					goto name1;
			}
dobDate:
	gotoxy(6, 9); cout<<"Date of Birth";
	
	gotoxy(8, 10); cout<<"Date (1-31) : "; cin>>date; fflush(stdin); 
	for(int i= 0; i<50; i++){	gotoxy(35+i, 11); cout<<" "; } //loop clear cout month valid from 1-30
	for(int i= 0; i<50; i++){	gotoxy(35+i, 12); cout<<" "; } //loop clear cout year leap year
	if(date >31)
	{
		for(int i= 0; i<60; i++)
		{
			gotoxy(10+i, 10); cout<<" "; //loop clear cout date if !condition
		}
		goto dobDate;
	}
	
dobMonth:	
	gotoxy(8, 11); cout<<"Month (1-12): "; cin>>month; fflush(stdin);
	if(month < 1 || month > 12)
	{
		for(int i= 0; i<60; i++)
		{
			gotoxy(10+i, 11); cout<<" ";
		}
		goto dobMonth;
	}
	else if(month == 4 || month == 6 || month == 9 || month == 11)
	{	
		if(date >=31)
		{
		    gotoxy(35, 11); cout<< "Date only valid from 1-30 during month 4,6,9,11";
		    for(int i= 0; i<8; i++)
			{
				gotoxy(22+i, 10); cout<<" "; //loop clear cout date if !condition
				gotoxy(22+i, 11); cout<<" "; //loop clear cout month if !condition
			}
		    goto dobDate;
		}
	}
	
dobYear:	
	gotoxy(8, 12); cout<<"Year	    : "; cin>>year; fflush(stdin);
	if(year > maxYear || year < minYear)
	{
		for(int i= 0; i<60; i++)
		{
			gotoxy(10+i, 12); cout<<" ";
		}
		goto dobYear;
	}
	else if(month == 2)
	{
		if(isLeap(year))
		{
			if(date >=30)
			{
			    gotoxy(35, 12); cout<<"Leap year, valid date from 1-29";
			    for(int i= 0; i<8; i++)
				{
					gotoxy(22+i, 10); cout<<" "; //loop clear cout date if !condition
					gotoxy(22+i, 11); cout<<" "; //loop clear cout month if !condition
					gotoxy(22+i, 12); cout<<" "; //loop clear cout year if !condition
				}
			    goto dobDate;
			}
		}
		else
		{
			if(date >=29)
			{
			    gotoxy(35, 12); cout<<"Not Leap year, valid date from 1-28";
			    for(int i= 0; i<8; i++)
				{
					gotoxy(22+i, 10); cout<<" "; //loop clear cout date if !condition
					gotoxy(22+i, 11); cout<<" "; //loop clear cout month if !condition
					gotoxy(22+i, 12); cout<<" "; //loop clear cout year if !condition
				}
			    goto dobDate;
			}
		}
	}
	
em1:
	gotoxy(6, 15); cout<<"Email: "; cin>>email; fflush(stdin);
			if(strlen(email)<= 1)
			{
					delay(40);
					for(int i= 0; i<60; i++)
					{
						gotoxy(10+i, 15); cout<<" ";
					}
					goto em1;
			}
ct1:
	gotoxy(6, 18); cout<<"City/Province: "; gets(city);
			if(strlen(city)<= 1)
			{
					delay(40);
					for(int i= 0; i<60; i++)
					{
						gotoxy(10+i, 18); cout<<" ";
					}
					goto ct1;
			}
ty1:
	gotoxy(6, 21); cout<<"Choose Your Account Type (s/c): ";
			
			while(input !=13)
			{
				input = getch();
				
				if(count < 1)
				{
					if(input == 99 || input == 115)
					{
						cout<< input;
						type = input;
						count++;
					}	
				}
				else if(input=='\b')
				{
					cout<<"\b \b";
					type = '\0';
					count--;
				}
			}
			
am1:
	gotoxy(6, 24); cout<<"Amount to Deposit (>=100): ";	cin>>amnt; fflush(stdin);
			if(amnt<= 99)
			{
					delay(40);
					for(int i= 0; i<60; i++)
					{
						gotoxy(10+i, 24); cout<<" ";
					}
					goto am1;
			}
	
	setcursor(1,90);
	gotoxy(35, 27); cout<<"SUBMIT ";	
	getch();
	gotoxy(17, 29); cout<<"Loading";
	delay(400); cout<<".";
	delay(400); cout<<".";
	delay(400); cout<<"."; 
	delay(400);	cout<<"."; delay(400);
	
	cls();
	printLoginInfo();	
}

//modify account
void machine::modify_account()
{
	x= 30, y= 3;
	string draw;
	
	setcursor(1,10);
	foreColor(233);
	gotoxy(x, y); cout<<"*** MODIFYING YOUR ACCOUNT ***";
	DrawRectangle(2, 4, 90, 10, 237);
	
	foreColor(237);
	drawRec(2, 7, 45, 4, draw);
	
	foreColor(233);
name1:
	gotoxy(6, 9); cout<<"Enter Full Name: "; gets(name);
			if(strlen(name)<= 1)
			{
					delay(40);
					for(int i= 0; i<60; i++)
					{
						gotoxy(15+i, 9); cout<<" ";
					}
					goto name1;
			}
}

//admin login
void machine::admin()
{
	setcursor(1,10);
	char admname[7], pw[7];
	char adminname[] = "mako";
	char pass[] = "12345";
	string drew;
	char a;
	int i = 0;
	
	cls();
	system("color E0");	
	DrawRectangle(18, 9, 50, 15, 234);
	foreColor(233);
	gotoxy(37, 9); cout<<"LOGIN FORM";
	gotoxy(30, 31); cout<<"Press Enter to confirm";
	gotoxy(20, 12); cout<<"Enter Admin Name: "; cin>>admname;
		
	if(strcmp(admname, adminname) ==0)
	{
		gotoxy(20, 16); cout<<"Enter Password: ";
		
		while(a != 13)//infinite loop
    	{
	        a=getch();//stores char typed in a
	        
	        if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9')) //check if a is numeric or alphabet
	        {
	            pw[i++] = a;
	            cout<< "*";
	        }
	        if(a == '\b' && i >= 1)
	        {
	            cout<<"\b \b";
	            --i;
	        }
    	}
    
		if(strcmp(pw, pass) ==0)
		{
			while(1)
			{
				cls();
				char op;
				foreColor(225);
				gotoxy(38, 4); cout<<"ADMIN MENU";
				
				gotoxy(34,2);foreColor(228);cout<<(char)220<<(char)220<<(char)220<<(char)220<<(char)220<<(char)220<<(char)220<<(char)220
				<<(char)220<<(char)220<<(char)220<<(char)220<<(char)220<<(char)220<<(char)220<<(char)220<<(char)220<<(char)220; //top
	
				gotoxy(34,6);cout<<(char)220<<(char)220<<(char)220<<(char)220<<(char)220<<(char)220<<(char)220<<(char)220
				<<(char)220<<(char)220<<(char)220<<(char)220<<(char)220<<(char)220<<(char)220<<(char)220<<(char)220<<(char)220;  //bottom
				
				gotoxy(34,3);cout<<(char)220<<(char)220;
				gotoxy(34,4);cout<<(char)220<<(char)220;
				gotoxy(34,5);cout<<(char)220<<(char)220;
				gotoxy(50,3);cout<<(char)220<<(char)220;
				gotoxy(50,4);cout<<(char)220<<(char)220;
				gotoxy(50,5);cout<<(char)220<<(char)220;
				
				foreColor(228);
				drawRec(8, 8, 36, 17, drew);
				
				foreColor(237);
				gotoxy(29, 10); cout<<"1. SHOW ALL ACCOUNT HOLDERS";
				gotoxy(29, 13); cout<<"2. SEARCH ACCOUNT INFORMATION";
				gotoxy(29, 16); cout<<"3. MODIFY ACCOUNT INFORMATION";
				gotoxy(29, 19); cout<<"4. DELETE ACCOUNT HOLDER";
				gotoxy(29, 22); cout<<"5. GO BACK TO MAIN MENU";
				
				foreColor(237);
				gotoxy(0, 27); cout<<setfill('-')<<setw(80)<<"";
				gotoxy(10, 29); cout<<"Select Your Option:  "; cin>>op; fflush(stdin);
				
				switch(op)
				{
					case '1':
					{
						cls();
						readAccount();
						getch(); 						
						break;
					} 
					case '2':
					{
						cls();
						searchAccount();
						getch();
						break;
					}
					case '3':
					{
						cls();
						updateAccount();
						getch();
						break;
					}
					case '4':
					{
						cls();
						deleteAccount();
						getch();
						break;
					}
					case '5':
					{
						delay(400);
						m1.main_menu();
						getch(); 
						break;
					} 
					default:
					{
						foreColor(236);
						gotoxy(36, 29); cout<<"WRONG INPUT!! \a";
						getch(); 
						break;
					}
				}
			}//end while
		}//end if pw
		else
		{
			gotoxy(33, 21); cout<<"INVALID PASSWORD \a";
		}
	}//end if admin
	else
	{
		gotoxy(33, 21); cout<<"INVALID USERNAME";
	}
}

//Output From file
void machine::outputData()
{
	x= 2;
	m1.header();

	gotoxy(x+3, y+3); cout<<m1.getAccountNum(); 		
	gotoxy(x+18, y+3); cout<<m1.getPin(); 
	gotoxy(x+30, y+3); cout<<name; 
	gotoxy(x+55, y+3); cout<<date<<"/" << month << "/" << year;
	gotoxy(x+74, y+3); cout<<type;
	gotoxy(x+86, y+3);
	if(m1.amnt <=100)
	{
		cout<< "$" << setprecision(4) <<m1.amnt;
	}
	else if(m1.amnt <=1000)
	{
		cout<< "$" << setprecision(5) <<m1.amnt;
	}
	else if(m1.amnt <=10000)
	{
		cout<< "$" << setprecision(6) <<m1.amnt;
	}
	else if(m1.amnt <= 100000)
	{
		cout<< "$" << setprecision(7) <<m1.amnt;
	}
	else if(m1.amnt <=1000000)
	{
		cout<< "$" << setprecision(8) <<m1.amnt;
	}
	else
	{
		if(m1.amnt >1000000)		
		cout<< "$" << setprecision(9) <<m1.amnt;
	}	
}

//Login Check
machine machine::loginAcc()
{
	char a;
	int i = 0;
	int showX = 38;
	
	cls();	
log:	
	cls();
	x= 30, y= 10;

starts:
	cls();
	setcursor(1,10);
	gotoxy(x+2, y+12); cout<<"PRESS ENTER TO ACCEPT";
	gotoxy(x, y); cout<<"ENTER YOUR ACCOUNT NUMBER";
	gotoxy(x+10, y+3); cin>>aanumber;
	
	cls();
	gotoxy(10, y+8); cout<<"PRESS TAB TO RE-ENTER YOUR ACCOUNT NUMBER.";
	gotoxy(10, y+10); cout<<"PRESS ESC TO EXIT!";
	gotoxy(x, y); cout<<"ENTER YOUR PIN NUMBER"; gotoxy(showX, y+3);
	
		while(a != 27)
    	{
	        a = getch();
	        
	        if(a >= '0' && a <= '9') //check if a is numeric or alphabet
	        {
	            aapin[i++] = a;
	            gotoxy(showX++, y+3); cout<< "X" << "\a";
	            if(i>=4)
	            {
	            	break;
				}
	        }
	        else if(a == '\b' && i >= 1)
	        {
	            cout<<"\b \b";
	            --i;
	            --showX;
	        }
	        else if(a == 9)
	        {
				i = 0;
	        	goto starts;
			}
			
			aapin[i]='\0'; //set it back to null after break loop;
    	}
}

//GetName
void machine::getname()
{
	foreColor(55);
	gotoxy(2,5); cout<<"HELLO__MR / MRS:  "<< strupr(m1.name);
	delay(1200);
}
void machine::getnameTransfer()
{
	foreColor(62);
	gotoxy(2,2); cout<<"TRANSFER FROM__MR / MRS:  "<< strupr(m1.name) << "	TO__MR/MRS:  " << strupr(m2.name);
}

//help 
void machine::help()
{
	cls();
	system("COLOR 70");
	
	for(int i=0; i<26; i++)
	{
		gotoxy(2,i);
		cout<<"|";
		gotoxy(77,i);
		cout<<"|";
	}
	
	gotoxy(3,1); cout<<"In order to use our ATM services be sure that,";
	gotoxy(3,3); cout<<"you might have already opened an account previously. ";
	
	gotoxy(3,6);  cout<<"ATM Services";
	gotoxy(3,9);  cout<<"Balance Enquiry : To check the current balance in your account.";
	gotoxy(3,11); cout<<"Pin Change : Use this service to change your ATM password.";	
	gotoxy(3,13); cout<<"Fast Cash : This enables to withdraw your preferred amounts with a touch.";
	gotoxy(3,15); cout<<"Cash Withdrawal : Use this service to withdraw amount.";
	gotoxy(3,17); cout<<"Cash Transfer : Transfers amount instantly to any accounts.";
		
	gotoxy(3,22); cout<<"For more information,";
	gotoxy(3,24); cout<<"Call our 24x7 helpline through 089 995 123.";
	foreColor(117);
	for(int i=26; i<34; i++)
	{		
		gotoxy(2,i);
		cout<<(char)186;
		gotoxy(77,i);
		cout<<(char)186;
	}
	gotoxy(2, 25); cout<<(char)201; gotoxy(3, 25); cout<<setfill((char)205)<<setw(75)<<""; gotoxy(77, 25); cout<<(char)187;
	gotoxy(12,27); cout<<"CREATED BY:  CHUN BANHAW";
	gotoxy(17,29); cout<<"EMAIL:  banhawchun@gmail.com / banhaw2015@gmail.com";
	gotoxy(13,31); cout<<"TELEPHONE:  089 995 123 / 086 515 666";
	gotoxy(2, 33); cout<<(char)200; gotoxy(3, 33); cout<<setfill((char)205)<<setw(75)<<""; gotoxy(77, 33); cout<<(char)188;
	
	getch();
	m1.main_menu();	
}

//cash deposit
void machine::cash_deposit()
{
	cls();
	float cash;
	
reEnter:
	cls();
	setcursor(1,10);
	foreColor(62);
	gotoxy(2, 12); cout<<"Press to Enter to confirm or Input 0 to exit";
	gotoxy(1, 5); cout<<"Enter Amount you want to deposit: $ ";
	cin>>cash; fflush(stdin);
	
	if(cash <0)
	{
		foreColor(63);
		gotoxy(20, 20); cout<<"THE DEPOSIT AMOUNT MUST NOT BE $0 OR BELOW !!!"; delay(1000);
		goto reEnter;
	}
	else if(cash >=100000)
	{
		foreColor(63);
		gotoxy(20, 20); cout<<"YOU CAN DEPOSIT ONLY UNDER $100000 !!!"; delay(1000);
		goto reEnter;
	}
	else
	{
		amnt += cash;
	}	
}

//balance check
void machine::balance_enquiry()
{
	cls();
	gotoxy(33,10); cout<<"ACCOUNT HOLDER NAME  : "<<strupr(m1.name);
	if(m1.amnt <=100)
	{
		gotoxy(33,13); cout<<"CURRENT BALANCE      : "<<"$" << setprecision(4) <<m1.amnt;
	}
	else if(m1.amnt <=1000)
	{
		gotoxy(33,13); cout<<"CURRENT BALANCE      : "<<"$" << setprecision(5) <<m1.amnt;
	}
	else if(m1.amnt <=10000)
	{
		gotoxy(33,13); cout<<"CURRENT BALANCE      : "<<"$" << setprecision(6) <<m1.amnt;
	}
	else if(m1.amnt <=100000)
	{
		gotoxy(33,13); cout<<"CURRENT BALANCE      : "<<"$" << setprecision(7) <<m1.amnt;
	}
	else if(m1.amnt <=1000000)
	{
		gotoxy(33,13); cout<<"CURRENT BALANCE      : "<<"$" << setprecision(8) <<m1.amnt;
	}
	else
	{
		if(m1.amnt >1000000)	
		gotoxy(33,13); cout<<"CURRENT BALANCE      : "<<"$" << setprecision(9) <<m1.amnt;
	}
	delay(1000);	
	foreColor(62);
	gotoxy(18,20);
	cout<<"PRESS ANY KEY TO CONTINUE... ";
	getch();
}

//change pin
void machine::change_pin()
{
	cls();
	char a;
	int i = 0;
	int showX = 38;
	
	setcursor(1,10);
	foreColor(62);
	gotoxy(x, y); cout<<"ENTER YOUR NEW 4-PIN NUMBER"; gotoxy(showX, y+3);
	
	while(a != (00,68) ) //key F10 (Hidden when change new pin)
    	{
	        a = getch();
	        
	        if(a >= '0' && a <= '9') //check if a is numeric or alphabet
	        {
	            pin[i++] = a;
	            gotoxy(showX++, y+3); cout<< "X" << "\a";
	            if(i>=4)
	            {
	            	break;
				}
	        }
	        else if(a == '\b' && i >= 1)
	        {
	            cout<<"\b \b";
	            --i;
	            --showX;
	        }
    	}
	
}

//other service
void machine::other_services()
{
	cls();
	system("COLOR 70");
	
	for(int i=0; i<30; i++)
	{
		gotoxy(2,i);
		cout<<"|";
		gotoxy(77,i);
		cout<<"|";
	}
	
	gotoxy(3,0);  cout<<"Good to see you here ";
	gotoxy(3,3); cout<<"Ensure that you change the PIN number after you first using your card also";
	gotoxy(3,5); cout<<"frequently change PIN number.";
	gotoxy(3,7);  cout<<"Ensure that nobody else can see you entering your PIN number at the ATM.";
	
	gotoxy(3,11);  cout<<"Do not use the ATM machine when strangers are inside the ATM counter.";
	gotoxy(3,13); cout<<"Do not seek the assistance of strangers while operating the ATM machine.";	
	gotoxy(3,15); cout<<"Do not give your PIN CODE to anyone becuase the bank will never ask";
	gotoxy(3,17); cout<<"for your PIN CODE!";
	gotoxy(3,19); cout<<"In case you Forgot your PIN CODE, Please contact customer service.";
		
	gotoxy(3,23); cout<<"For more information,";
	gotoxy(3,25); cout<<"Call our 24x7 customer service through 089 995 123 / 086 515 666.";
	gotoxy(3,27); cout<<"Contact at banhawchun@gmail.com";
}

//cash withdraw
void machine::cash_withdraw()
{
	cls();
	float cash;
reEnter:
	cls();
	setcursor(1,10);
	foreColor(63);	
	gotoxy(1, 25); cout<< "NOTE: If you don't have any balance please input 0 to exit!!";
	
	foreColor(62);
	gotoxy(2, 12); cout<<"Press Enter to confirm";
	gotoxy(1, 5); cout<< "Enter Amount you want to withdraw: $ ";
	cin>>cash; fflush(stdin);

	if(cash <0)
	{
		foreColor(63);
		gotoxy(20, 20); cout<<"YOU MUST INPUT AMOUNT BIGGER THAN $0 !!!"; delay(1000);
		goto reEnter;
	}
	else if(m1.amnt < cash)
	{
		foreColor(63);
		gotoxy(20, 20); cout<<"WITHDRAWAL AMOUNT IS HIGHER THAN AVAILABLE BALANCE!!!\a"; delay(1000);
		goto reEnter;
	}
	else
	{
		amnt -= cash;
	}	
}

//cash transfer
bool machine::cash_transfer(machine &fromAcc, float trsfamnt)
{
	if(trsfamnt > fromAcc.amnt)
	{
		gotoxy(20, 16); cout<<"WITHDRAWAL AMOUNT IS HIGHER THAN AVAILABLE BALANCE!!!\a"; delay(1000);
		return false;
	}
	else
	{
		fromAcc.amnt -= trsfamnt;
		this->amnt += trsfamnt;
		return true;
	}
	
}
//fast cash
void machine::fast_cash()
{
	cls();
	
reChoose:
	cls();
	setcursor(1,10);
	char choice;
	
	foreColor(63);
	gotoxy(39, 2); cout<< "CHOOSE ONE OF THE OPTION";
	foreColor(63);
	gotoxy(3, 8); cout<< "1. $100"; foreColor(62);
				gotoxy(11,6);cout<<(char)223<<(char)223;
				gotoxy(12,7);cout<<(char)223<<(char)223;
				gotoxy(13,8);cout<<(char)223<<(char)223;
				gotoxy(12,9);cout<<(char)223<<(char)223;
				gotoxy(11,10);cout<<(char)223<<(char)223; //right
				gotoxy(0,6);cout<<(char)223<<(char)223<<(char)223<<(char)223<<(char)223<<(char)223<<(char)223<<(char)223<<(char)223
				<<(char)223<<(char)223; //top
				gotoxy(0,10);cout<<(char)223<<(char)223<<(char)223<<(char)223<<(char)223<<(char)223<<(char)223<<(char)223<<(char)223
				<<(char)223<<(char)223; //bottom
	foreColor(63);	
	gotoxy(3,14); cout<< "2. $200"; foreColor(62);
				gotoxy(11,12);cout<<(char)223<<(char)223;
				gotoxy(12,13);cout<<(char)223<<(char)223;
				gotoxy(13,14);cout<<(char)223<<(char)223;
				gotoxy(12,15);cout<<(char)223<<(char)223;
				gotoxy(11,16);cout<<(char)223<<(char)223; //right
				gotoxy(0,12);cout<<(char)223<<(char)223<<(char)223<<(char)223<<(char)223<<(char)223<<(char)223<<(char)223<<(char)223
					<<(char)223<<(char)223; //top
				gotoxy(0,16);cout<<(char)223<<(char)223<<(char)223<<(char)223<<(char)223<<(char)223<<(char)223<<(char)223<<(char)223
					<<(char)223<<(char)223; //bottom
	foreColor(63);				
	gotoxy(3,20); cout<< "3. $500"; foreColor(62);
				gotoxy(11,18);cout<<(char)223<<(char)223;
				gotoxy(12,19);cout<<(char)223<<(char)223;
				gotoxy(13,20);cout<<(char)223<<(char)223;
				gotoxy(12,21);cout<<(char)223<<(char)223;
				gotoxy(11,22);cout<<(char)223<<(char)223; //right
				gotoxy(0,18);cout<<(char)223<<(char)223<<(char)223<<(char)223<<(char)223<<(char)223<<(char)223<<(char)223<<(char)223
					<<(char)223<<(char)223; //top
				gotoxy(0,22);cout<<(char)223<<(char)223<<(char)223<<(char)223<<(char)223<<(char)223<<(char)223<<(char)223<<(char)223
					<<(char)223<<(char)223; //bottom
	foreColor(63);				
	gotoxy(95,8); cout<< "4. $700"; foreColor(62);
				gotoxy(92,6);cout<<(char)223<<(char)223;
				gotoxy(91,7);cout<<(char)223<<(char)223;
				gotoxy(90,8);cout<<(char)223<<(char)223;	
				gotoxy(91,9);cout<<(char)223<<(char)223;
				gotoxy(92,10);cout<<(char)223<<(char)223; //left
				gotoxy(94,6);cout<<(char)223<<(char)223<<(char)223<<(char)223<<(char)223<<(char)223<<(char)223<<(char)223<<(char)223
					<<(char)223<<(char)223; //top
				gotoxy(94,10);cout<<(char)223<<(char)223<<(char)223<<(char)223<<(char)223<<(char)223<<(char)223<<(char)223<<(char)223
					<<(char)223<<(char)223; //bottom
	foreColor(63);
	gotoxy(95,14); cout<< "5. $900"; foreColor(62);
				gotoxy(92,12);cout<<(char)223<<(char)223;
				gotoxy(91,13);cout<<(char)223<<(char)223;
				gotoxy(90,14);cout<<(char)223<<(char)223;
				gotoxy(91,15);cout<<(char)223<<(char)223;
				gotoxy(92,16);cout<<(char)223<<(char)223; //left
				gotoxy(94,12);cout<<(char)223<<(char)223<<(char)223<<(char)223<<(char)223<<(char)223<<(char)223<<(char)223<<(char)223
					<<(char)223<<(char)223; //top
				gotoxy(94,16);cout<<(char)223<<(char)223<<(char)223<<(char)223<<(char)223<<(char)223<<(char)223<<(char)223<<(char)223
					<<(char)223<<(char)223; //bottom
	foreColor(63);
	gotoxy(95,20); cout<< "6. $1000"; foreColor(62);
				gotoxy(92,18);cout<<(char)223<<(char)223;
				gotoxy(91,19);cout<<(char)223<<(char)223;
				gotoxy(90,20);cout<<(char)223<<(char)223;
				gotoxy(91,21);cout<<(char)223<<(char)223;
				gotoxy(92,22);cout<<(char)223<<(char)223; //left
				gotoxy(94,18);cout<<(char)223<<(char)223<<(char)223<<(char)223<<(char)223<<(char)223<<(char)223<<(char)223<<(char)223
					<<(char)223<<(char)223; //top
				gotoxy(94,22);cout<<(char)223<<(char)223<<(char)223<<(char)223<<(char)223<<(char)223<<(char)223<<(char)223<<(char)223
					<<(char)223<<(char)223; //bottom
	
	foreColor(62);
	gotoxy(2, 33);cout<<"Press Enter to confirm or Input 0 to Exit";
	gotoxy(5, 28); cout<< "SELECT YOUR CHOICE: "; cin>>choice; fflush(stdin);
	
	switch(choice)
	{
		case '1': 
			if(	m1.amnt < 100)
			{
				printWrongTransaction();
			}
			else
			{
				foreColor(63);
				gotoxy(25, 30); cout<< "Successfully Withdraw...";
				delay(1000);
				m1.amnt = m1.amnt - 100;
				printTransaction();
			}			
			break;
		case '2': 
			m1.amnt;
			if(	m1.amnt < 200)
			{
				printWrongTransaction();
			}
			else
			{
				foreColor(63);
				gotoxy(25, 30); cout<< "Successfully Withdraw...";
				delay(1000);
				m1.amnt = m1.amnt - 200;
				printTransaction();
			}		
			break;
		case '3': 
			m1.amnt;
			if(	m1.amnt < 500)
			{
				printWrongTransaction();
			}
			else
			{
				foreColor(63);
				gotoxy(25, 30); cout<< "Successfully Withdraw...";
				delay(1000);
				m1.amnt = m1.amnt - 500;
				printTransaction();
			}		
			break;
		case '4': 
			m1.amnt;
			if(	m1.amnt < 700)
			{
				printWrongTransaction();
			}
			else
			{
				foreColor(63);
				gotoxy(25, 30); cout<< "Successfully Withdraw...";
				delay(1000);
				m1.amnt = m1.amnt - 700;
				printTransaction();
			}
			break;
		case '5': 
			m1.amnt;
			if(	m1.amnt < 900)
			{
				printWrongTransaction();
			}
			else
			{
				foreColor(63);
				gotoxy(25, 30); cout<< "Successfully Withdraw...";
				delay(1000);
				m1.amnt = m1.amnt - 900;
				printTransaction();
			}
			break;
		case '6': 
			m1.amnt;
			if(	m1.amnt < 1000)
			{
				printWrongTransaction();
			}
			else
			{
				foreColor(63);
				gotoxy(25, 30); cout<< "Successfully Withdraw...";
				delay(1000);
				m1.amnt = m1.amnt - 1000;
				printTransaction();
			}
			break;
		case '0': 
			break;
		default:
			foreColor(63);
			gotoxy(28, 30); cout<<"INVALID OPTION!! \a";
			delay(1200);
			goto reChoose;
	}//end switch
}
// +++++++++End Definition to member function++++++++++++++++

int main()
{
	
	system("title MK Banking Management");
	system("mode con: cols=105");
	intro();
	m1.main_menu();
	
	return 0;
}
