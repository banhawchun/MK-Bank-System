#ifndef ANTHEADER_H
#define ANTHEADER_H

#include<windows.h>
#include<stdlib.h>
#include<iostream>
#include<sstream>
#include<string.h>
#include<ctype.h>
#include<time.h>
#include<stdio.h>
#include<conio.h>
using namespace std;
/*void swap(int (*a)[2], int (*b)[2])
{
    int temp[sizeof(*a)/sizeof((*a)[0])];
    memcpy(temp,a,sizeof(temp));
    memcpy(a,b,sizeof(*a));
    memcpy(b,temp,sizeof(*b));
}*/


void delay(int milliseconds)
{
	long pause;
	clock_t now,then;

	pause = milliseconds*(CLOCKS_PER_SEC/1000);
	now = then = clock();
	while( (now-then) < pause )
		now = clock();
}

void toLower(char str[])
   {
		int n;
		char c;
		for ( n=0 ; str[n]!='\0' ; n++)
		 {
			c=str[n];
			putchar(tolower(c));                         
		 }
   }
void toUpper(char str[])
   {
		int n;
		char c;
		for ( n=0 ; str[n]!='\0' ; n++)
		 {
			c=str[n];
			putchar(toupper(c));                         
		 }
   }   
   
int is_number(char * pchar, int lnum){
	int i, is_num=0;
	for(i=0; i<lnum; i++)
	{
		if(!isalnum(*pchar)) // Loop until it a character is not alpha-numeric.
		 break;
		// printf("%c - ",*pchar);
		if(!isdigit(*pchar))
		{
			is_num++;
			break;
		}
		pchar++;
	}
	// printf("\nis_num = %i\n",is_num);
	return is_num;
}

void gotoxy(int x,int y){
	HANDLE hConsoleOutput;
	COORD coord;
	hConsoleOutput=GetStdHandle(STD_OUTPUT_HANDLE);
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(hConsoleOutput,coord);
}
void cls()
{
	system("cls");
}
void foreColor(int color)
{
	HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle,color|FOREGROUND_INTENSITY);		
}
template<class T>
string int_string(T number){
	stringstream converter;//at sstream header
	converter<<number;
	return converter.str();
}

int string_int(string str_number){
	stringstream converter(str_number);
	int result;
	return converter>>result?result:0;
}

bool is_number(float &num){
	cin>>num;
	if(cin.fail()){
		cin.clear();
		cin.ignore(80,'\n');
		return false;
	}
	return true;
}
bool is_number(int &num){
	cin>>num;
	if(cin.fail()){
		cin.clear();
		cin.ignore(80,'\n');
		return false;
	}
	return true;
}

void setcursor(bool visible, DWORD size)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	if(size == 0)
	{
		size = 20;	// default cursor size Changing to numbers from 1 to 20, decreases cursor width
	}
	CONSOLE_CURSOR_INFO lpCursor;	
	lpCursor.bVisible = visible;
	lpCursor.dwSize = size;
	SetConsoleCursorInfo(console,&lpCursor);
}
void drawRec(int x,int y,int w,int h,string s){
	gotoxy(x,y);cout<<(char)218;
	for(int i=x+1;i<(w*2+x)-2;i++){
		gotoxy(i,y);cout<<(char)196;	
	}
	cout<<(char)191;
	//
	int x_s=(x*2)-s.length()/2;
	int y_s=y+(h/2);
	gotoxy(x_s,y_s);cout<<s;
	//
	for(int i=y+1;i<h+y;i++){
		gotoxy(x,i);cout<<(char)179;
		gotoxy(x+(w*2)-2,i);cout<<(char)179;
	}

	gotoxy(x,y+h);cout<<(char)192;
	for(int i=x+1;i<(w*2+x)-2;i++){
		gotoxy(i,y+h);cout<<(char)196;	
	}
	cout<<(char)217;
}
void clrXY(int x, int y,int count){
	COORD topLeft  = {(short)x,(short)y};
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen;
	DWORD written;
	GetConsoleScreenBufferInfo(console,&screen);
	FillConsoleOutputCharacterA(console,'\0',count,topLeft,&written);//replace with count(ex:80 characters) NULL at this line
	FillConsoleOutputAttribute(console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
							   screen.dwSize.X * screen.dwSize.Y,topLeft,&written);
	SetConsoleCursorPosition(console, topLeft);
}
string ToLower(string s){
	string result="";
	for(int i=0;i<s.length();i++){
		result+=tolower(s[i]);
	}
	return result;
}
string ToUpper(string s){
	string result="";
	for(int i=0;i<s.length();i++){
		result+=toupper(s[i]);
	}
	return result;
}

void DrawRectangle(int x, int y, int w, int h, int c = 7)
{
	foreColor(c);
	for(int i = 0; i < w; i++)
	{
		gotoxy(x + i,y);
		cout << (char)205;
		gotoxy(x + i, y + h + 1);
		cout << (char)205;
	}
	for(int i = 0; i < h; i++)
	{
		gotoxy(x - 1,y + i + 1);
		cout << (char)186;
		gotoxy(x + w,y + i + 1);
		cout << (char)186;
	}
	//top-left
	gotoxy(x - 1,y);
	cout << (char)201;
	//top-right
	gotoxy(x + w ,y);
	cout << (char)187;
	//bottom-left
	gotoxy(x - 1,y + h + 1);
	cout << (char)200;
	//bottom-right
	gotoxy(x + w,y + h + 1);
	cout << (char)188;
	
}

void ShowMenu(string menus[],int n,int index,int x, int y)
{
	for(int i = 0; i < n; i++)
	{
		clrXY(x - 4,y + i,menus[i].length() + 4);
		if(i != index)
		{
			gotoxy(x,y + i);
			foreColor(3);
			cout << menus[i];
		}
		else
		{
			gotoxy(x - 4,y + i);
			foreColor(3);
			cout << "==> " << menus[i];
		}
	}
}
	void drawline(int x, int y, int w, int h, int a,int b)/*x,y,wight,hight,place to break ,Number of information-1*/
{
	foreColor(3);
	for(int i = 0; i < w; i++)
	{
		gotoxy(x + i,y);
		cout << (char)205;
		gotoxy(x + i, y + h + 1);
		cout << (char)205;
	}
	for(int i = 0; i < h; i++)
	{
		gotoxy(x - 1,y + i + 1);
		cout << (char)186;
		gotoxy(x + w,y + i + 1);
		cout << (char)186;
	}
	//top-left
	gotoxy(x - 1,y);
	cout << (char)201;
	//top-right
	gotoxy(x + w ,y);
	cout << (char)187;
	//bottom-left
	gotoxy(x - 1,y + h + 1);
	cout << (char)200;
	//bottom-right
	gotoxy(x + w,y + h + 1);
	cout << (char)188;
	

for(int i=0;i<b*15;i+=15){
	 gotoxy(a+i,y+0);cout<<(char)203;gotoxy(a+i,y+1);cout<<(char)186;gotoxy(a+i,y+2);cout<<(char)186;
            gotoxy(a+i,y+3);cout<<(char)202;
}

}

#endif
