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

// ==================== ADD FILE ====================== //




//Menu
const int itemmenuchinh = 5;
const int itemmenuMB = 5;
const int itemmenuCB = 4;
const int itemmenuDV = 4;
const int itemmenuHK = 2;
//"                     "

char MENU[itemmenuchinh][100] = {"        QUAN LY MAY BAY        ",
								 "       QUAN LY CHUYEN BAY      ",
								 "         QUAN LY DAT VE        ",
								 "       QUAN LY HANH KHACH      ",
								 "            THOAT              " };
char MENUMAYBAY[itemmenuMB][50] = {
								   "          THEM MAY BAY         ",
								   "           XOA MAY BAY         ",
								   "      HIEU CHINH THONG TIN     ",
								   "     IN DANH SACH MAY BAY      ",
								   "        IN SO LUOT BAY         " };
char MENUCHUYENBAY[itemmenuCB][50] = {"         THEM CHUYEN BAY       ",
									  "       XOA, HUY CHUYEN BAY     ",
									  "     HIEU CHINH CHUYEN BAY     ",
									  "     DANH SACH CHUYEN BAY      "};

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
//	SetColor(Color_White);	SetBGColor(Color_DarkGreen);	gotoxy(vitri, MAXYCONSOLE); cout << " UP/DOWN  ";	vitri += 10;
//	SetColor(Color_Yellow);	SetBGColor(Color_Blue);			gotoxy(vitri, MAXYCONSOLE); cout << "   "<< (char)94 << "  " << (char)118<<"   ";
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
int frameDocGhiFileCB() {
	SetColor(Color_Red);
	SetBGColor(Color_Cyan);
	gotoxy(55, 30);
	cout << "                                                           ";
	gotoxy(55, 31);
	cout << "              BAN MUON DOC FILE HAY GHI FILE               ";
	gotoxy(55, 32);
	cout << "                                                           ";
	SetBGColor(Color_Cyan);
	SetColor(Color_Red);
	gotoxy(65, 20);cout << "     ";
	gotoxy(65, 21);cout << "  F1 ";
	gotoxy(65, 22);cout << "     ";
	SetBGColor(Color_Back);
	SetColor(Color_DarkYellow);
	gotoxy(71, 21);cout << ": DOC FILE";

	SetBGColor(Color_Yellow);
	SetColor(Color_Red);
	gotoxy(88, 20);cout << "     ";
	gotoxy(88, 21);cout << "  F2 ";
	gotoxy(88, 22);cout << "     ";
	SetBGColor(Color_Back);
	SetColor(Color_DarkYellow);
	gotoxy(94, 21);cout << ": GHI FILE";
	SetBGColor(Color_DarkWhite);
	return GetKey();

}

void xoaSoHieuMayBay(int y){
	SetBGColor(Color_DarkWhite);
	for(int i=0;i<=y;i++){
	gotoxy(109,10+i);cout<<"                  ";	
		}
		
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
void frameFull() {
	SetColor(Color_Blue);
	SetBGColor(Color_DarkWhite);
	gotoxy(53, 16);cout << "      ============|  ====        ====   ====            ====                ";
	gotoxy(53, 17);cout << "      ============|  ====        ====   ====            ====                ";
	gotoxy(53, 18);cout << "      =====          ====        ====   ====            ====                ";
	gotoxy(53, 19);cout << "      =====          ====        ====   ====            ====                ";
	gotoxy(53, 20);cout << "      =====          ====        ====   ====            ====                ";
	gotoxy(53, 21);cout << "      ============|  ====        ====   ====            ====                ";
	gotoxy(53, 22);cout << "      ============|  ====        ====   ====            ====                ";
	gotoxy(53, 23);cout << "      ======         ====        ====   ====            ====                ";
	gotoxy(53, 24);cout << "      ======         ====        ====   ====            ====                ";
	gotoxy(53, 25);cout << "      ======         ================   =============   ==============      ";
	gotoxy(53, 26);cout << "      ======         ================   =============   ==============      ";
	//	SetBGColor(Color_DarkWhite);
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

void frameContinue() {
	SetColor(Color_DarkRed);
	SetBGColor(Color_White);
	gotoxy(55, 47);
	cout << "                                                           ";
	gotoxy(55, 48);
	cout << "             NHAN PHIM BAT KY DE TIEP TUC                  ";
	gotoxy(55, 49);
	cout << "                                                           ";
	SetBGColor(Color_DarkWhite);
}

void frameTitelAddCB() {
	SetColor(Color_Pink);
	SetBGColor(Color_DarkWhite);
	gotoxy(45, 8);
	cout << "+-------------------------+";
	gotoxy(45, 9);
	cout << "|     THEM CHUYEN BAY     |";
	gotoxy(45, 10);
	cout << "+-------------------------+";
}
int frameExit(){
	SetColor(Color_Back);
	SetBGColor(Color_Cyan);
	gotoxy(40,28);cout<<"                                                     ";
	gotoxy(40,29);cout<<"       BAN CO MUON LUU LAI TAT CA CAC DANH SACH      ";
	gotoxy(40,30);cout<<"                                                     ";	
SetColor(Color_White);
	SetBGColor(Color_DarkRed);
	gotoxy(48, 32); cout << " ESC ";

	SetColor(Color_DarkYellow);
	SetBGColor(Color_Back);
	gotoxy(53, 32); cout << ":EXIT";

	// ok
	SetColor(Color_White);
	SetBGColor(Color_DarkGreen);
	gotoxy(69, 32); cout << " ENTER ";

	SetColor(Color_DarkYellow);
	SetBGColor(Color_Back);
	gotoxy(76, 32); cout << ":OK";
	SetBGColor(Color_DarkWhite);
	return GetKey();	
	
}
void frameTitelDelCB() {
	SetColor(Color_DarkRed);
	SetBGColor(Color_DarkWhite);

	gotoxy(140, 7);	cout << "+-------------------------+";

	gotoxy(140, 8);	cout << "|   CAP NHAT CHUYEN BAY   |";

	gotoxy(132, 9);	cout << "--------+-------------------------+--------";
	gotoxy(132, 10);cout << "|  NHAP MA CHUYEN BAY CAN XOA, HUY CHUYEN |";
	gotoxy(132, 11);cout << "|-----------------------------------------|";
	gotoxy(132, 12);cout << "|       |                         |       |";
	gotoxy(132, 13);cout << "|       |_________________________|       |";
	gotoxy(132, 14);cout << "|                                         |";
	gotoxy(132, 15);cout << "|                                         |";
	gotoxy(132, 16);cout << "|                                         |";
	gotoxy(132, 17);cout << "|                                         |";
	gotoxy(132, 18);cout << "|                                         |";
	gotoxy(132, 19);cout << "|                                         |";
	gotoxy(132, 20);cout << "|                                         |";
	gotoxy(132, 21);cout << "|                                         |";
	gotoxy(132, 22);cout << "|                                         |";
	gotoxy(132, 23);cout << "|                                         |";
	gotoxy(132, 24);cout << "|-----------------------------------------|";
	gotoxy(132, 25);cout << "|                                         |";
	gotoxy(132, 26);cout << "|_________________________________________|";
	// exit
	SetColor(Color_White);
	SetBGColor(Color_DarkRed);
	gotoxy(140, 25); cout << " ESC ";

	SetColor(Color_DarkYellow);
	SetBGColor(Color_Back);
	gotoxy(145, 25); cout << ":EXIT";

	// ok
	SetColor(Color_White);
	SetBGColor(Color_DarkGreen);
	gotoxy(156, 25); cout << " ENTER ";

	SetColor(Color_DarkYellow);
	SetBGColor(Color_Back);
	gotoxy(163, 25); cout << ":OK";

}
int frameButtonDelEdit() {
	SetBGColor(Color_Cyan);
	SetColor(Color_Red);
	gotoxy(134, 20);cout << "     ";
	gotoxy(134, 21);cout << "  F1 ";
	gotoxy(134, 22);cout << "     ";
	SetBGColor(Color_Back);
	SetColor(Color_DarkYellow);
	gotoxy(140, 21);cout << ": XOA";

	SetBGColor(Color_Yellow);
	SetColor(Color_Red);
	gotoxy(152, 20);cout << "     ";
	gotoxy(152, 21);cout << "  F2 ";
	gotoxy(152, 22);cout << "     ";
	SetBGColor(Color_Back);
	SetColor(Color_DarkYellow);
	gotoxy(158, 21);cout << ": HUY CHUYEN";

	return GetKey();
}
void frameTitelEditCB() {
	SetColor(Color_DarkRed);
	SetBGColor(Color_DarkWhite);

	gotoxy(140, 7);	cout << "+-------------------------+";
	gotoxy(140, 8);	cout << "|  HIEU CHINH CHUYEN BAY  |";
	gotoxy(132, 9);	cout << "--------+-------------------------+--------";
	gotoxy(132, 10);cout << "|    NHAP MA CHUYEN BAY CAN HIEU CHINH    |";
	gotoxy(132, 11);cout << "-------------------------------------------";
	gotoxy(132, 12);cout << "|       |                         |       |";
	gotoxy(132, 13);cout << "|       |_________________________|       |";
	gotoxy(132, 14);cout << "|                                         |";
	gotoxy(132, 15);cout << "|                                         |";//tim thay
	gotoxy(132, 16);cout << "|                                         |";
	gotoxy(132, 17);cout << "|                                         |";//macb
	gotoxy(132, 18);cout << "|                                         |";//shmb
	gotoxy(132, 19);cout << "|                                         |";//noi den								
	gotoxy(132, 20);cout << "|                                         |";//ngay thang
	gotoxy(132, 21);cout << "|                                         |";//gio phut
	gotoxy(132, 22);cout << "|                                         |";//trang thai
	gotoxy(132, 23);cout << "|                                         |";
	gotoxy(132, 24);cout << "|                                         |";//thong bao
	gotoxy(132, 25);cout << "|                                         |";
	gotoxy(132, 26);cout << "|_________________________________________|";//esc enter
//	gotoxy(132, 27);cout <<						"|                                         |";
//	gotoxy(132, 28);cout <<						"|                                         |";
//	gotoxy(132, 29);cout <<						"|                                         |";
//	gotoxy(132, 30);cout <<						"|                                         |";						
//	gotoxy(132, 31);cout <<						"|_________________________________________|";
}
void frameTitelEditCB2() {
	SetColor(Color_DarkRed);
	SetBGColor(Color_DarkWhite);

	gotoxy(140, 7);	cout << "+-------------------------+";
	gotoxy(140, 8);	cout << "|  HIEU CHINH CHUYEN BAY  |";
	gotoxy(132, 9);	cout << "--------+-------------------------+--------";
	gotoxy(132, 10);cout << "|    NHAP MA CHUYEN BAY CAN HIEU CHINH    |";
	gotoxy(132, 11);cout << "-------------------------------------------";
	gotoxy(132, 12);cout << "|       |                         |       |";
	gotoxy(132, 13);cout << "|       |_________________________|       |";
	gotoxy(132, 14);cout << "|                                         |";
	gotoxy(132, 15);cout << "|                                         |";//tim thay
	gotoxy(132, 16);cout << "|             MA CHUYEN BAY               |";
	gotoxy(132, 17);cout << "|                    |                    |";//macb
	gotoxy(132, 18);cout << "|             SO HIEU MAY BAY             |";//noi den								
	gotoxy(132, 19);cout << "|                    |                    |";//ngay thang
	gotoxy(132, 20);cout << "|                 NOI DEN                 |";//trang thai
	gotoxy(132, 21);cout << "|                    |                    |";
	gotoxy(132, 22);cout << "|                NGAY THANG               |";
	gotoxy(132, 23);cout << "|                    |                    |";
	gotoxy(132, 24);cout << "|                 GIO PHUT                |";
	gotoxy(132, 25);cout << "|                    |                    |";
	gotoxy(132, 26);cout << "|               TRANG THAI                |";
	gotoxy(132, 27);cout << "|                    |                    |";
	gotoxy(132, 28);cout << "|_________________________________________|";
	//	gotoxy(132, 28);cout <<						"|                    |                    |";				
	//	gotoxy(132, 29);cout <<						"|_________________________________________|";
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
void frameInfoCbXXX() {
	SetColor(Color_DarkRed);
	SetBGColor(Color_DarkWhite);

	gotoxy(140, 8);	cout << "+-------------------------+";
	gotoxy(140, 9);	cout << "|    NHAP MA CHUYEN BAY   |";
	gotoxy(132, 10);	cout << "--------+-------------------------+--------";
	gotoxy(132, 11);cout << "|                                         |";
	gotoxy(132, 12);cout << "|-----------------------------------------|";
}
int frameKhCoCBHople() {
	SetColor(Color_Back);
	SetBGColor(Color_Cyan);
	gotoxy(8, 15);cout << "                                                                ";
	gotoxy(8, 16);cout << "     KHONG CO CHUYEN BAY HOP LE. BAN CO MUON NHAP LAI KHONG?    ";
	gotoxy(8, 17);cout << "                                                                ";
	SetColor(Color_White);
	SetBGColor(Color_DarkRed);
	gotoxy(27, 19); cout << " ESC ";

	SetColor(Color_DarkYellow);
	SetBGColor(Color_Back);
	gotoxy(32, 19); cout << ":EXIT";

	// ok
	SetColor(Color_White);
	SetBGColor(Color_DarkGreen);
	gotoxy(48, 19); cout << " ENTER ";

	SetColor(Color_DarkYellow);
	SetBGColor(Color_Back);
	gotoxy(55, 19); cout << ":OK";
	SetBGColor(Color_DarkWhite);
	return GetKey();

}
void frameCoverkhCoCBHopLe() {
	SetColor(Color_Blue);
	SetBGColor(Color_DarkWhite);
	gotoxy(8, 15);cout << "                                                                ";
	gotoxy(8, 16);cout << "                                                                ";
	gotoxy(8, 17);cout << "                                                                ";
	gotoxy(8, 19);cout << "                                                                ";
}

void frameSoCbConVe() {

	header();footer();
	//frameTitelAddCB();
	SetColor(Color_DarkRed);
	SetBGColor(Color_DarkWhite);
	gotoxy(2, 10);cout << "+------------------+----------------+------------+----------------+---------+---------------+";
	gotoxy(2, 11);cout << "|   MA CHUYEN BAY  |   SO HIEU MB   |   NOI DEN  | NGAY KHOI HANH |  GIO KH |  SO GHE TRONG |";
	gotoxy(2, 12);cout << "+------------------+----------------+------------+----------------+---------+---------------+";
	SetBGColor(Color_DarkWhite);  //    "|__________________|________________|____________|________________|_________|_______________|"      


}
void frameCoverListCB(int sodongcanxoa) {
	SetBGColor(Color_DarkWhite);
	for (int i = 0;i <= sodongcanxoa;i++) {
		gotoxy(2, 14 + i);cout << "                                                                                                        ";
	}
}
void frameCoverListCB2(int sodongcanxoa) {
	SetBGColor(Color_DarkWhite);
	for (int i = 0;i <= sodongcanxoa;i++) {
		gotoxy(2, 10 + i);cout << "                                                                                                        ";
	}
}
//void cheFormDatVe(int sodongcanxoa) {
//	SetBGColor(Color_DarkWhite);
//	for (int i = 0;i <= sodongcanxoa;i++) {
//		gotoxy(132, 7 + i);cout << "                                           ";
//	}
//}
void frameTitelAdd_MB() {
	SetColor(Color_Pink);
	gotoxy(72, 8);
	cout << "+-------------------------+";
	gotoxy(72, 9);
	cout << "|  NHAP DANH SACH MAY BAY |";
	gotoxy(72, 10);
	cout << "+-------------------------+";
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
int frameAddNext() {
	SetColor(Color_Red);
	SetBGColor(Color_Cyan);
	gotoxy(55, MAXYCONSOLE-5);
	cout << "                                                           ";
	gotoxy(55, MAXYCONSOLE-4);
	cout << "                   BAN CO MUON THEM TIEP?                  ";
	gotoxy(55, MAXYCONSOLE-3);
	cout << "                                                           ";
	SetBGColor(Color_DarkWhite);
	return GetKey();

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
void TextViewChuDe(char s[], int x, int y, int dodai, int background, int textcolor)
{
	gotoxy(x, y);              cout << (char)218;
	for (int i = 0; i < dodai; i++)  cout << (char)196;   cout << (char)191;
	gotoxy(x, y + 1);          cout << (char)179;
	gotoxy(x + dodai + 1, y + 1); cout << (char)179;
	gotoxy(x, y + 2);          cout << (char)192;
	for (int i = 0; i < dodai;i++)  cout << (char)196;       cout << (char)217;
	SetColor(background);
	gotoxy(x + 1, y + 1); cout << s;
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
void frameTitelXoaMB() {
	SetColor(Color_Pink);
	SetBGColor(Color_DarkWhite);
	gotoxy(72, 8);
	cout << "+-------------------------+";
	gotoxy(72, 9);
	cout << "|       XOA MAY BAY       |";
	gotoxy(72, 10);
	cout << "+-------------------------+";
}
void frameTitelShowMB() {
	SetColor(Color_Pink);
	gotoxy(72, 8);
	cout << "+-------------------------+";
	gotoxy(72, 9);
	cout << "|    DANH SACH MAY BAY    |";
	gotoxy(72, 10);
	cout << "+-------------------------+";
}
void frameTitelOpenfile() {
	SetColor(Color_Pink);
	gotoxy(72, 8);
	cout << "+-------------------------+";
	gotoxy(72, 9);
	cout << "|         MO FILE         |";
	gotoxy(72, 10);
	cout << "+-------------------------+";
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
//-----------------CHILDREN MENU-------------------------




