#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cmath>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>
//#include "mylib.h"

using namespace std;
const int itemmenuchinh = 5;
const int itemmenuDV = 4;
const int itemmenuHK = 2;
//"                     "

char MENU[itemmenuchinh][100] = {"        QUAN LY MAY BAY        ",
								 "       QUAN LY CHUYEN BAY      ",
								 "         QUAN LY DAT VE        ",
								 "       QUAN LY HANH KHACH      ",
								 "            THOAT              " };
char MENUDATVE[itemmenuDV][50] = {  "             DAT VE            ",
									"             HUY VE            ",
									"     TIM CB CON VE dd/mm/yy    ",
									"    DANH SACH VE TRONG CB xx   " };

char MENUHK[itemmenuHK][50] = { "        TAT CA HANH KHAC       ",
								"      HANH KHACH CUA CB XXX    " };

char ITEM[5][16] = {"SO HIEU MAY BAY",
					"LOAI MAY BAY   ",
					"SO DAY         ",
					"SO HANG        ",
					"SO GHE         "};
//===== Giaodien =====


void kedocdoi(int x, int y, int h)
{
	gotoxy(x,y);
	cout<<char(203);
	
	while(h != 0)
	{
		gotoxy(x,++y);
		cout<<char(186);
		h--;	
	}
	gotoxy(x,++y);
	cout<<char(202);
}
void kengangdoi(int x, int y, int w)
{	
	gotoxy(x,y);
	cout<<char(204)<<setw(w)<<char(205)<<char(185);
}

void vekhung(int x,int y,int h,int w){
	cout.fill(196);
	gotoxy(x,y);
	cout<<char(218)<<setw(w)<<char(196)<<char(191);
	cout.fill(' ');
	for(int i=1;i<=h;++i){
		gotoxy(x,y+i);
		cout<<char(179)<<setw(w)<<' '<<char(179);	
	}
	gotoxy(x,y+h+1);
	cout.fill(196);
	cout<<char(192)<<setw(w)<<char(196)<<char(217);
}

void vekhungdoi(int x,int y,int h,int w){
	cout.fill(205);
	gotoxy(x,y);
	cout<<char(201)<<setw(w)<<char(205)<<char(187);
	cout.fill(' ');
	for(int i=1;i<=h;++i){
		gotoxy(x,y+i);
		cout<<char(186)<<setw(w)<<' '<<char(186);	
	}
	gotoxy(x,y+h+1);
	cout.fill(205);
	cout<<char(200)<<setw(w)<<char(205)<<char(188);
}

void table(int x, int y, int height, int width, int count, int A[]){
//int A[3]={20,44,70};
//	int x = 1, y = 10, width = 150, height = 30;
//	int socot = 3
//	SetColor(Color_DarkBlue);
	vekhungdoi(x,y,height,width);	
	kengangdoi(x,y+2,width);
	for(int i = 0; i<count; i++){
		
		kedocdoi(x+A[i],y,height);
		
		gotoxy(x+A[i],y+2);	cout<<char(206);
	}
	gotoxy(x+A[1],y+2);	cout<<char(206);
	gotoxy(x,y+2);	cout<<char(204);
	gotoxy(x+width+1,y+2);	cout<<char(185);
}
void header() {
	SetColor(Color_Back);
	SetBGColor(Color_DarkWhite);
	vekhungdoi(72,0,1,32);
	gotoxy(82,1);
	SetColor(Color_DarkRed);
	cout<<"QUAN LY MAY BAY";
}

void footerMB() {
	SetColor(Color_Grey);	gotoxy(15, MAXYCONSOLE-1);	int vitri = 35;
	cout << "---------------------------------------------------------------------------------------------------------------------------------------------";
	SetColor(Color_White);	SetBGColor(Color_DarkGreen);	gotoxy(vitri, MAXYCONSOLE); cout << "   THEM:  ";	vitri += 10;
	SetColor(Color_Yellow);	SetBGColor(Color_Blue);			gotoxy(vitri, MAXYCONSOLE); cout << "    F1    ";	vitri += 10;
	SetColor(Color_White);	SetBGColor(Color_DarkGreen);	gotoxy(vitri, MAXYCONSOLE); cout << " THONG KE:";	vitri += 10;
	SetColor(Color_Yellow);	SetBGColor(Color_Blue);			gotoxy(vitri, MAXYCONSOLE); cout << "    F2    ";	vitri += 10;
	SetColor(Color_White);	SetBGColor(Color_DarkGreen);	gotoxy(vitri, MAXYCONSOLE); cout << "  THOAT:  ";	vitri += 10;
	SetColor(Color_Yellow);	SetBGColor(Color_Blue);			gotoxy(vitri, MAXYCONSOLE); cout << "   ESC    ";	vitri += 10;
	SetColor(Color_White);	SetBGColor(Color_DarkGreen);	gotoxy(vitri, MAXYCONSOLE); cout << "   CHON:  ";	vitri += 10;
	SetColor(Color_Yellow);	SetBGColor(Color_Blue);			gotoxy(vitri, MAXYCONSOLE); cout <<"   ENTER  ";	vitri += 10;
	SetColor(Color_White);	SetBGColor(Color_DarkGreen);	gotoxy(vitri, MAXYCONSOLE); cout << " UP/DOWN  ";	vitri += 10;
	SetColor(Color_Yellow);	SetBGColor(Color_Blue);			gotoxy(vitri, MAXYCONSOLE); cout << "   "<< (char)94 << "  " << (char)118<<"   ";
	SetBGColor(Color_DarkWhite);
}

void footerCB() {
	SetBGColor(Color_DarkWhite);
	gotoxy(35,MAXYCONSOLE); cout<<"                                                                                                    ";
	SetColor(Color_Grey);	gotoxy(15, MAXYCONSOLE-1);	int vitri = 40;
	cout << "---------------------------------------------------------------------------------------------------------------------------------------------";
	SetColor(Color_White);	SetBGColor(Color_DarkGreen);	gotoxy(vitri, MAXYCONSOLE); cout << "   THEM:  ";	vitri += 10;
	SetColor(Color_Yellow);	SetBGColor(Color_Blue);			gotoxy(vitri, MAXYCONSOLE); cout << "    F1    ";	vitri += 10;
	SetColor(Color_White);	SetBGColor(Color_DarkGreen);	gotoxy(vitri, MAXYCONSOLE); cout << "    XOA   :";	vitri += 10;
	SetColor(Color_Yellow);	SetBGColor(Color_Blue);			gotoxy(vitri, MAXYCONSOLE); cout << "    F3    ";	vitri += 10;
	SetColor(Color_White);	SetBGColor(Color_DarkGreen);	gotoxy(vitri, MAXYCONSOLE); cout << "   SUA:   ";	vitri += 10;
	SetColor(Color_Yellow);	SetBGColor(Color_Blue);			gotoxy(vitri, MAXYCONSOLE); cout << "    F4    ";	vitri += 10;
	SetColor(Color_White);	SetBGColor(Color_DarkGreen);	gotoxy(vitri, MAXYCONSOLE); cout << "  THOAT:  ";	vitri += 10;
	SetColor(Color_Yellow);	SetBGColor(Color_Blue);			gotoxy(vitri, MAXYCONSOLE); cout << "    ESC   ";	vitri += 10;
	SetBGColor(Color_DarkWhite);
}
void footer() {
	SetColor(Color_Grey);	gotoxy(15, MAXYCONSOLE-1);	int vitri = 45;
	cout << "---------------------------------------------------------------------------------------------------------------------------------------------";
	SetColor(Color_White);	SetBGColor(Color_DarkGreen);	gotoxy(vitri, MAXYCONSOLE); cout << "  THOAT:  ";	vitri += 10;
	SetColor(Color_Yellow);	SetBGColor(Color_Blue);			gotoxy(vitri, MAXYCONSOLE); cout << "   ESC    ";	vitri += 20;
	SetColor(Color_White);	SetBGColor(Color_DarkGreen);	gotoxy(vitri, MAXYCONSOLE); cout << "   CHON:  ";	vitri += 10;
	SetColor(Color_Yellow);	SetBGColor(Color_Blue);			gotoxy(vitri, MAXYCONSOLE); cout <<"   ENTER  ";	vitri += 20;
	SetColor(Color_White);	SetBGColor(Color_DarkGreen);	gotoxy(vitri, MAXYCONSOLE); cout << " UP/DOWN  ";	vitri += 10;
	SetColor(Color_Yellow);	SetBGColor(Color_Blue);			gotoxy(vitri, MAXYCONSOLE); cout << "   "<< (char)94 << "  " << (char)118<<"   ";
	SetBGColor(Color_DarkWhite);
}
void footerDatVe() {
	SetColor(Color_Grey);	gotoxy(15, MAXYCONSOLE-1);	int vitri = 55;
	cout << "---------------------------------------------------------------------------------------------------------------------------------------------";
	SetColor(Color_White);	SetBGColor(Color_DarkGreen);	gotoxy(vitri, MAXYCONSOLE); cout << "  THOAT:  ";	vitri += 10;
	SetColor(Color_Yellow);	SetBGColor(Color_Blue);			gotoxy(vitri, MAXYCONSOLE); cout << "   ESC    ";	vitri += 20;
	SetColor(Color_White);	SetBGColor(Color_DarkGreen);	gotoxy(vitri, MAXYCONSOLE); cout << "   NEXT:  ";	vitri += 10;
	SetColor(Color_Yellow);	SetBGColor(Color_Blue);			gotoxy(vitri, MAXYCONSOLE); cout <<	" ENTER/TAB";
	SetBGColor(Color_DarkWhite);
}

void footerEditMB() {
	SetBGColor(Color_DarkWhite);
	gotoxy(35,MAXYCONSOLE); cout<<"                                                                                                    ";
	SetColor(Color_Grey);	gotoxy(15, MAXYCONSOLE-1);	int vitri = 45;
	cout << "---------------------------------------------------------------------------------------------------------------------------------------------";
	SetColor(Color_White);	SetBGColor(Color_DarkGreen);	gotoxy(vitri, MAXYCONSOLE); cout << "  THOAT:  ";	vitri += 10;
	SetColor(Color_Yellow);	SetBGColor(Color_Blue);			gotoxy(vitri, MAXYCONSOLE); cout << "   ESC    ";	vitri += 20;
	SetColor(Color_White);	SetBGColor(Color_DarkGreen);	gotoxy(vitri, MAXYCONSOLE); cout << "   NEXT:  ";	vitri += 10;
	SetColor(Color_Yellow);	SetBGColor(Color_Blue);			gotoxy(vitri, MAXYCONSOLE); cout <<	"ENTER/TAB ";	vitri += 20;
	SetColor(Color_White);	SetBGColor(Color_DarkGreen);	gotoxy(vitri, MAXYCONSOLE); cout << "   LUU:   ";	vitri += 10;
	SetColor(Color_Yellow);	SetBGColor(Color_Blue);			gotoxy(vitri, MAXYCONSOLE); cout << "   F2     ";
	SetBGColor(Color_DarkWhite);
}
void alertHelp(int x, int y, char S[69]) {
	
	SetColor(Color_DarkRed);
	SetBGColor(Color_White);
	gotoxy(x, y);
	cout << "                                                           ";
	gotoxy(x, y +1);
	cout <<S;
	gotoxy(x, y + 2);
	cout << "                                                           ";
	SetColor(Color_DarkBlue);
	SetBGColor(Color_DarkWhite);
}


void thongTinVe() {
	SetColor(Color_DarkYellow);
	SetBGColor(Color_DarkWhite);
	gotoxy(135, 8);cout << "THONG TIN VE";
	gotoxy(118, 10);cout << "MA CHUYEN BAY";
	gotoxy(118, 12);cout << "NOI DEN: ";
	gotoxy(118, 14);cout << "NGAY KHOI HANH:";
	gotoxy(118, 16);cout << "GIO KHOI HANH:";
	gotoxy(118, 18);cout << "SO GHE:";
	gotoxy(118, 20);cout << "HO:";
	gotoxy(138, 20);cout << "TEN:";
	gotoxy(118, 22);cout << "CMND:";
	gotoxy(118, 24);cout << "GIOI TINH: ";
}
void clearOnePart(int x, int y, int width, int hight){
	SetBGColor(Color_DarkWhite);
	for(int i = 0; i<=hight; i++){
		gotoxy(x, y+i);
		cout.fill(' ');
		cout<<setw(width)<<" ";
	}	
}

void message(int x, int y, char* s){
	int count =0;
	while (s[count] != '\0') count++;
	gotoxy(x,y);	SetBGColor(Color_DarkWhite);	SetColor(Color_DarkBlue);	cout<<s;
	getch();
	gotoxy(x,y);	SetBGColor(Color_DarkWhite); cout.fill(' ');	cout<<setw(count)<<" ";
}

bool Hoi(int x, int y, char* s)
{
	int count=0;
	ShowCur(false);
	while (s[count] != '\0') 
	{
		count++;
	}
	
	SetBGColor(Color_White);	gotoxy(x,y);
	for(int i =0;i<4;i++)
	{
		gotoxy(x,y+i);
		cout.fill(' ');
		cout<<setw(count)<<" ";
	}
	SetColor(Color_Green);		gotoxy(x,y);	cout<<s;
	gotoxy(x+6,y+2);		SetColor(15);	SetBGColor(0);	cout<<" YES ";
	gotoxy(x+count-10,y+2);	SetColor(15);	SetBGColor(Color_Cyan);	cout<<" NO ";
	int key; int i =0;
	do{
		key =GetKey();
		switch(key)
		{
			case ESC:
				{
					SetBGColor(Color_DarkWhite);
					gotoxy(x, y);	cout.fill(' ');	cout<<setw(count)<<" ";
					gotoxy(x, y+1);	cout.fill(' ');	cout<<setw(count)<<" ";
					gotoxy(x, y+2);	cout.fill(' ');	cout<<setw(count)<<" ";
					gotoxy(x, y+3);	cout.fill(' ');	cout<<setw(count)<<" ";
					SetBGColor(Color_DarkWhite);
					ShowCur(true);
					return false;
				}
			case ENTER:
				{
					if(i == 0)
					{
						SetBGColor(Color_DarkWhite);
						gotoxy(x, y);	cout.fill(' ');	cout<<setw(count)<<" ";
						gotoxy(x, y+1);	cout.fill(' ');	cout<<setw(count)<<" ";
						gotoxy(x, y+2);	cout.fill(' ');	cout<<setw(count)<<" ";
						gotoxy(x, y+3);	cout.fill(' ');	cout<<setw(count)<<" ";
						SetBGColor(Color_DarkWhite);
						ShowCur(true);
						return true;
					}else{
						SetBGColor(Color_DarkWhite);
						gotoxy(x, y);	cout.fill(' ');	cout<<setw(count)<<" ";
						gotoxy(x, y+1);	cout.fill(' ');	cout<<setw(count)<<" ";
						gotoxy(x, y+2);	cout.fill(' ');	cout<<setw(count)<<" ";
						gotoxy(x, y+3);	cout.fill(' ');	cout<<setw(count)<<" ";
						SetBGColor(Color_DarkWhite);
						ShowCur(true);
						return false;
					}
					
					break;
				}
			case RIGHT:
				{
					if(i==0)
					{
						gotoxy(x+count-10,y+2);
						SetColor(15);		SetBGColor(0);		cout<<" NO ";
						gotoxy(x+6,y+2);
						SetColor(15);		SetBGColor(Color_Cyan);		cout<<" YES ";
						i++;
					}
					break;
				}
			case LEFT:
				{
					if(i==1)
					{
						gotoxy(x+count-10,y+2);
						SetColor(15);		SetBGColor(Color_Cyan);		cout<<" NO ";
						gotoxy(x+6,y+2);
						SetColor(15);		SetBGColor(0);		cout<<" YES ";
						i--;
					}
					break;
					
				}
			default: break;
		}
	}while(key!=ENTER);
}
int alertOption(int x, int y, char* s, char* section1, char* section2){
	int count=0;
	ShowCur(false);
	while (s[count] != '\0') 
	{
		count++;
	}
	
	SetBGColor(Color_White);	gotoxy(x,y);
	for(int i =0;i<4;i++)
	{
		gotoxy(x,y+i);
		cout.fill(' ');
		cout<<setw(count)<<" ";
	}
	SetColor(Color_Green);		gotoxy(x,y);	cout<<s;
	gotoxy(x+4,y+2);		SetColor(15);	SetBGColor(0);	cout<<section1;
	gotoxy(x+count-14,y+2);	SetColor(15);	SetBGColor(Color_Cyan);	cout<<section2;
	int key; int i =0;
	do{
		key =GetKey();
		switch(key)
		{
			case ESC:
				{
					SetBGColor(Color_DarkWhite);
					gotoxy(x, y);	cout.fill(' ');	cout<<setw(count)<<" ";
					gotoxy(x, y+1);	cout.fill(' ');	cout<<setw(count)<<" ";
					gotoxy(x, y+2);	cout.fill(' ');	cout<<setw(count)<<" ";
					gotoxy(x, y+3);	cout.fill(' ');	cout<<setw(count)<<" ";
					SetBGColor(Color_DarkWhite);
					ShowCur(true);
					return -1;
				}
			case ENTER:
				{
					if(i == 0)
					{
						SetBGColor(Color_DarkWhite);
						gotoxy(x, y);	cout.fill(' ');	cout<<setw(count)<<" ";
						gotoxy(x, y+1);	cout.fill(' ');	cout<<setw(count)<<" ";
						gotoxy(x, y+2);	cout.fill(' ');	cout<<setw(count)<<" ";
						gotoxy(x, y+3);	cout.fill(' ');	cout<<setw(count)<<" ";
						SetBGColor(Color_DarkWhite);
						ShowCur(true);
						return 1;
					}else{
						SetBGColor(Color_DarkWhite);
						gotoxy(x, y);	cout.fill(' ');	cout<<setw(count)<<" ";
						gotoxy(x, y+1);	cout.fill(' ');	cout<<setw(count)<<" ";
						gotoxy(x, y+2);	cout.fill(' ');	cout<<setw(count)<<" ";
						gotoxy(x, y+3);	cout.fill(' ');	cout<<setw(count)<<" ";
						SetBGColor(Color_DarkWhite);
						ShowCur(true);
						return 2;
					}
					
					break;
				}
			case RIGHT:
				{
					if(i==0)
					{
						gotoxy(x+count-14,y+2);
						SetColor(15);		SetBGColor(0);		cout<<section2;
						gotoxy(x+4,y+2);
						SetColor(15);		SetBGColor(Color_Cyan);		cout<<section1;
						i++;
					}
					break;
				}
			case LEFT:
				{
					if(i==1)
					{
						gotoxy(x+count-14,y+2);
						SetColor(15);		SetBGColor(Color_Cyan);		cout<<section2;
						gotoxy(x+4,y+2);
						SetColor(15);		SetBGColor(0);		cout<<section1;
						i--;
					}
					break;
					
				}
			default: break;
		}
	}while(key!=ENTER);
}

void ToMauMenuChinh(int textColor, int bGColor, int vitri) {
	SetColor(textColor);
	SetBGColor(bGColor);
	gotoxy(7 + vitri*31, positionMainMenu); 	cout << "                               ";
	gotoxy(7 + vitri*31, positionMainMenu + 1); cout << MENU[vitri];
	gotoxy(7 + vitri*31, positionMainMenu + 2); cout << "                               ";

}
void ToMauMenuCon(int textColor, int bGColor, char MenuCon[][50], int vitri, int x) {
	SetColor(textColor);
	SetBGColor(bGColor);
	gotoxy(x, positionMainMenu + 4 + (vitri * 4));	cout << "                               ";
	gotoxy(x, positionMainMenu + 5 + (vitri * 4));	cout << MenuCon[vitri];
	gotoxy(x, positionMainMenu + 6 + (vitri * 4));	cout << "                               ";

}
void frameSanbayDen() {
	SetColor(Color_Back);
	vekhungdoi(110,positionY_listCB,30,50);
	SetColor(Color_White);
	SetBGColor(Color_DarkRed);
	gotoxy(20, 39);	cout << "      NOI DEN:     ";
	HighLight1();
	cout << " SGN - HO CHI MINH ";
	HighLight2();
	cout << "   HAN - HA NOI    ";
	HighLight1();
	cout << "  CXR - NHA TRANG  ";
	HighLight2();
	cout << "  PQC - PHU QUOC   ";
	HighLight1();
	cout << "  UIH - QUY NHON   ";
	HighLight2();
	cout << "  HPH - HAI PHONG  ";
	SetBGColor(Color_DarkWhite);
	SetColor(Color_DarkRed);
}

void formInput(int x, int y, int col,char item[][16]){
	for(int i = 0; i<col; i++){
		SetBGColor(Color_DarkWhite);
		SetColor(0);
		gotoxy(x-8, y + i*4 + 1);
		cout<<item[i];
		SetBGColor(15);
		gotoxy(x + 10, y + i*4);
		cout<<"                                          ";
		gotoxy(x + 10, y + i*4 + 1);
		cout<<"                                          ";
		gotoxy(x + 10, y + i*4 + 2);
		cout<<"                                          ";
	}
}




