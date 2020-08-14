#include <iostream>
#include <string>
#include <string.h>
#include "khaibao.h"
#include "support.h"
#include "frame.h"
#include <sstream> 
//#include <boost>
#include <algorithm>
//#include <fstream.h>
#include <math.h>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */



using namespace std;
//hien thi danh sach may bay
////////////////////////////////////////////////////////////////////// MAY BAY //////////////////////////////////////////////////////////////////////
int showList_MB(List_MB listMB, boolean flag) {
	//system("cls") ;
	SetBGColor(Color_DarkWhite);							header();
	SetColor(Color_Pink);	SetBGColor(Color_DarkWhite);	vekhung(72,4,1,32);
	gotoxy(82,5);			SetColor(Color_Pink);			cout<<"DANH SACH MAY BAY";
	
	if (listMB.soluong == 0 && flag == TRUE) {
		Alert("CHUA CO MAY BAY", 77, 45, 3);return 0;
	}
	//else if(listMB.soluong==0 && flag==FALSE ){
	//		Alert("SAN SANG NHAP",79,45,1.2);
	//	}
	else {
		footer();
//		frameAdd_MB();
		//anConTro();
		int A[4]={20,50,65,80};
		SetColor(Color_Back);
		SetBGColor(Color_DarkWhite);
		table(positionX_listMB, positionY_listMB, 20, 100, 4, A);
		
		gotoxy(positionX_listMB + 3, positionY_listMB + 1);cout << "SO HIEU MAY BAY";
		gotoxy(positionX_listMB + 30, positionY_listMB + 1);cout << "LOAI MAY BAY";
		gotoxy(positionX_listMB + 55, positionY_listMB + 1);cout << "SO DAY";
		gotoxy(positionX_listMB + 70, positionY_listMB + 1);cout << "SO HANG";
		gotoxy(positionX_listMB+ 89, positionY_listMB + 1);cout << "SO GHE";
		for (int i = 0;i < listMB.soluong;i++) {
			SetColor(Color_DarkRed);
			
			gotoxy(positionX_listMB + 8, dongStart + i);cout << listMB.nodeMB[i]->sohieu_MB;
			gotoxy(positionX_listMB + 29, dongStart + i);cout << listMB.nodeMB[i]->loai_MB;
			gotoxy(positionX_listMB + 57, dongStart + i);cout << listMB.nodeMB[i]->soday_MB;
			gotoxy(positionX_listMB + 72, dongStart + i);cout << listMB.nodeMB[i]->sohang_MB;
			gotoxy(positionX_listMB + 89, dongStart + i);cout << (listMB.nodeMB[i]->soday_MB * listMB.nodeMB[i]->sohang_MB);
//			outDataMB(listMB, i);
		}
		return 1;
	}
}
//them thong tin cho may bay
int  addInfo_MB(List_MB& listMB, MAYBAY& mb) {
	ShowCur(true);
//	clrscr();
//	frameAdd_MB();
//	showList_MB(listMB, FALSE);
	formInput(positionFormInputX,positionFormInputY,5,ITEM);
	int key; int vitri;
SOHIEUCB:///////////////// NHAP SO HIEU MAY BAY //////////////
	// ghi chu
	alertHelp(positionAlertHelp,MAXYCONSOLE - 11,"         SO HIEU MB: GOM CAC KI TU (A-Z) & (0-9)           ");
	vitri = 0;
	//
	while (1) {
		gotoxy(positionFormInputX + 12 + vitri, positionFormInputY + 1);
//		gotoxy(positionX_listMB + 8 + vitri, dongStart + listMB.soluong);
		SetColor(Color_Blue);
		SetBGColor(Color_White);
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key >= 'a' && key <= 'z') || (key <= '9' && key >= '0')) && (vitri < maxSOHIEUMB)) {
			mb.sohieu_MB[vitri] = toupper((char)key);
			cout << mb.sohieu_MB[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0) {
			vitri--;
			gotoxy(positionFormInputX + 12 + vitri, positionFormInputY + 1);
			SetColor(Color_DarkRed);
			cout << " ";
		}
		if (key == ESC) {
			gotoxy(50, MAXYCONSOLE-3);

			SetBGColor(Color_DarkWhite);
			cout << "                                                            ";
			SetColor(Color_DarkRed);
			SetBGColor(Color_DarkWhite);
			gotoxy(76, MAXYCONSOLE-3);
			cout << "BAN CO CHAC CHAN HUY?";
			int cofirm = GetKey();
			if (cofirm == ENTER) {
				return 0;
			}
			gotoxy(76, MAXYCONSOLE - 3);
			SetBGColor(Color_DarkWhite);
			cout << "                                                            ";
		}
		if (key == ENTER) {
			mb.sohieu_MB[vitri] = '\0';
			if (mb.sohieu_MB[0] == '\0') {
				Alert("CHUA NHAP SO HIEU MAY BAY", 73, MAXYCONSOLE - 3, 2);
				goto SOHIEUCB;
			}
			else if (search(listMB, mb.sohieu_MB) > -1) {
				Alert("SO HIEU MB BI TRUNG!", 73, MAXYCONSOLE - 3, 2);
				gotoxy(positionFormInputX + 12 + vitri, positionFormInputY + 1);
				SetColor(Color_DarkRed);cout << "        ";
				goto SOHIEUCB;
			}
			else {
				goto LOAIMAYBAY;
			}
		}
	}

LOAIMAYBAY: /////////// NHAP LOAI MAY BAY //////////////
	alertHelp(positionAlertHelp,MAXYCONSOLE - 11,"        LOAI MAY BAY: GOM CAC KI TU (A-Z) & (0-9)          ");
	vitri = 0;
	//
	while (1) {
//		gotoxy(positionX_listMB + 29 + vitri, dongStart + listMB.soluong);
		gotoxy(positionFormInputX + 12 + vitri, positionFormInputY + 5);
		SetColor(Color_Blue);
		SetBGColor(Color_White);
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key >= 'a' && key <= 'z') || (key <= '9' && key >= '0')) && (vitri < maxLOAIMB)) {
			mb.loai_MB[vitri] = toupper((char)key);
			cout << mb.loai_MB[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0) {
			vitri--;
//			gotoxy(positionX_listMB + 29 + vitri, dongStart + listMB.soluong);
			gotoxy(positionFormInputX + 12 + vitri, positionFormInputY + 1);
			SetColor(Color_DarkRed);
			cout << " ";
		}
		if (key == ESC) {
			gotoxy(50, MAXYCONSOLE-3);

			SetBGColor(Color_DarkWhite);
			cout << "                                                            ";
			SetColor(Color_DarkRed);
			SetBGColor(Color_DarkWhite);
			gotoxy(76, MAXYCONSOLE-3);
			cout << "BAN CO CHAC CHAN HUY?";
			int cofirm = GetKey();
			if (cofirm == ENTER) {
				return 0;
			}
			gotoxy(76, MAXYCONSOLE-3);
			SetBGColor(Color_DarkWhite);
			cout << "                                                            ";
		}
		if (key == ENTER) {
			mb.loai_MB[vitri] = '\0';
			if (mb.loai_MB[0] == '\0') {
				Alert("CHUA NHAP LOAI MAY BAY", 73, MAXYCONSOLE-3, 2);
				goto LOAIMAYBAY;
			}
			else {
				goto SODAY;
			}
		}
	}
SODAY:////////////// NHAP SO DAY MAY BAY/////////////////
	char sodaychar[3];
	
	alertHelp(positionAlertHelp,MAXYCONSOLE - 11,"                 0 < SO LUONG DAY < 10                     ");
	vitri = 0;
	
	///
	while (1) {
//		gotoxy(positionX_listMB + 57 + vitri, dongStart + listMB.soluong);
		gotoxy(positionFormInputX + 12 + vitri, positionFormInputY + 9);
		SetColor(Color_Blue);
		SetBGColor(Color_White);
		fflush(stdin);
		key = GetKey();
		if (key >= '0' && key <= '9' && vitri < 2) {
			sodaychar[vitri] = (char)key;
			cout << sodaychar[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0) {
			vitri--;
//			gotoxy(positionX_listMB + 57  + vitri, dongStart + listMB.soluong);
			gotoxy(positionFormInputX + 12 + vitri, positionFormInputY + 9);
			SetColor(Color_DarkRed);
			cout << " ";

		}if (key == ENTER) {
			sodaychar[vitri] = '\0';
			if (sodaychar[0] == '\0') {
				Alert("CHUA NHAP SO DAY", 77, MAXYCONSOLE - 3, 2);
				goto SODAY;
			}
			else {
				mb.soday_MB = atoi(sodaychar);
				if (mb.soday_MB > maxsoday || mb.soday_MB <= 0) {
					Alert("SO DAY KHONG THOA MAN ", 72, MAXYCONSOLE - 3, 2);
					SetColor(Color_DarkRed);
//					gotoxy(positionX_listMB + 57 , dongStart + listMB.soluong);
					SetBGColor(Color_White);
					gotoxy(positionFormInputX + 12, positionFormInputY + 9);
					cout << "  ";
					goto SODAY;
				}
				else {
					goto SOHANG;
				}
			}
		}
		if (key == ESC) {
			gotoxy(50, MAXYCONSOLE - 3);

			SetBGColor(Color_DarkWhite);
			cout << "                                                            ";
			SetColor(Color_DarkRed);
			SetBGColor(Color_DarkWhite);
			gotoxy(76, MAXYCONSOLE - 3);
			cout << "BAN CO CHAC CHAN HUY?";
			int cofirm = GetKey();
			if (cofirm == ENTER) {
				return 0;
			}
			gotoxy(76, MAXYCONSOLE - 3);
			SetBGColor(Color_DarkWhite);
			cout << "                                                            ";
		}
	}
SOHANG://///////////// NHAP SO HANG CUA MAY BAY ////////////////////
	char sohangchar[3];
	alertHelp(positionAlertHelp,MAXYCONSOLE - 11,"                 0 < SO LUONG HANG < 35                    ");
	vitri = 0;
	///
	while (1) {
//		gotoxy(positionX_listMB + 72 + vitri, dongStart + listMB.soluong);
		gotoxy(positionFormInputX + 12 + vitri, positionFormInputY + 13);
		SetColor(Color_Blue);
		SetBGColor(Color_White);
		fflush(stdin);
		key = GetKey();
		if (key >= '0' && key <= '9' && vitri < 2) {
			sohangchar[vitri] = (char)key;
			cout << sohangchar[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0) {
			vitri--;
//			gotoxy(positionX_listMB + 72 + vitri, dongStart + listMB.soluong);
			gotoxy(positionFormInputX + 12 + vitri, positionFormInputY + 13);
			SetColor(Color_DarkRed);
			cout << " ";
		}if (key == ENTER) {
			sohangchar[vitri] = '\0';
			if (sohangchar[0] == '\0') {
				Alert("CHUA NHAP SO HANG", 77, MAXYCONSOLE - 3, 2);
				goto SOHANG;
			}
			else {
				mb.sohang_MB = atoi(sohangchar);
				if (mb.sohang_MB > maxsohang || mb.sohang_MB <= 0) {
					Alert("SO HANG KHONG THOA MAN ", 72, MAXYCONSOLE - 3, 2);
					SetColor(Color_DarkRed);
//					gotoxy(positionX_listMB + 72, dongStart + listMB.soluong);
					SetBGColor(Color_White);
					gotoxy(positionFormInputX + 12, positionFormInputY + 13);
					cout << "  ";
					goto SOHANG;
				}
				else {
					goto ENDp;
				}
			}
		}
		if (key == ESC) {
			gotoxy(50, MAXYCONSOLE - 3);

			SetBGColor(Color_DarkWhite);
			cout << "                                                            ";
			SetColor(Color_DarkRed);
			SetBGColor(Color_DarkWhite);
			gotoxy(76, MAXYCONSOLE - 3);
			cout << "BAN CO CHAC CHAN HUY?";
			int cofirm = GetKey();
			if (cofirm == ENTER) {
				return 0;
			}
			gotoxy(76, MAXYCONSOLE - 3);
			SetBGColor(Color_DarkWhite);
			cout << "                                                            ";
		}
	}
ENDp:
//	gotoxy(positionX_listMB + 89, dongStart + listMB.soluong);
	gotoxy(positionFormInputX + 12, positionFormInputY + 17);
	cout << (mb.soday_MB * mb.sohang_MB);
	return 1;

}
//them may bay vao danh sach
void addList_MB(List_MB & listMB) {
	int key1;
	bool nhaptiep = false;
	
	ShowCur(true);
	do {
		if (isFull(listMB)) {//kiem tra day chua?
			alertHelp(55 ,MAXYCONSOLE-9 ,"                     DANH SACH DA DAY                      ");
			
			if(GetKey())
			gotoxy(55, MAXYCONSOLE-9);
			cout << "                                                           ";
			gotoxy(55, MAXYCONSOLE-8);
			cout << "                                                           ";
			gotoxy(55, MAXYCONSOLE-7);
			cout << "                                                           ";
			return;
		}
		else {//neu chua day...
			if (isEmpty(listMB)) {//... thi kiem tra xem co phan tu chua?
				MAYBAY mb;
				if (addInfo_MB(listMB, mb) == 0) {
					gotoxy(50, MAXYCONSOLE - 3);

					SetBGColor(Color_DarkWhite);
					cout << "                                                            ";
					Alert("DA HUY", 82, MAXYCONSOLE - 3, 2);
				}
				else {
					listMB.nodeMB[0] = new MAYBAY;
					*listMB.nodeMB[0] = mb; listMB.soluong++;
					Alert("THEM MAY BAY THANH CONG!", 70, MAXYCONSOLE - 3, 2);
				}
			}
			else {
				MAYBAY mb;
				if (addInfo_MB(listMB, mb) == 0) {
					gotoxy(50, MAXYCONSOLE - 3);
					SetBGColor(Color_DarkWhite);
					cout << "                                                            ";
					Alert("DA HUY", 82, MAXYCONSOLE - 3, 2);
				}
				else {
					int j, k;
					for (j = 0; j < listMB.soluong && strcmp(listMB.nodeMB[j]->sohieu_MB, mb.sohieu_MB) < 1; j++);
					for (k = listMB.soluong - 1; k >= j; k--)
						listMB.nodeMB[k + 1] = listMB.nodeMB[k];
					listMB.nodeMB[j] = new MAYBAY;
					*listMB.nodeMB[j] = mb; listMB.soluong++;
					Alert("THEM MAY BAY THANH CONG!", 70, MAXYCONSOLE - 3, 2);

				}
			}
		}
		nhaptiep = Hoi(55,MAXYCONSOLE-5,"                   BAN CO MUON THEM TIEP?                  ");
		SetBGColor(7);
	} while (nhaptiep == true);
}

void Insoluotbay(List_MB lMB, List_CB lCB)
{
	header();
	int dem = 0;
	int dem1=0;
	for(int i=0;i<lMB.soluong;i++)
	{
		Node_CB *p;
	    p=lCB.pHead;
		MAYBAY *temp;
	    while(p!=NULL)
	    {
			if(strcmp(p->data.sohieumb,lMB.nodeMB[i]->sohieu_MB)==0&&p->data.trangthai==3)
			{
				dem++;
			}
	        p=p->pNext;
	    }
	    for(int j=i+1;j< lMB.soluong;j++)
	    {
			Node_CB *q;
		    q=lCB.pHead;
		    while(q!=NULL)
		    {
				if(strcmp(q->data.sohieumb,lMB.nodeMB[j]->sohieu_MB)==0&&q->data.trangthai==3)
				{
					dem1++;
				}
		        q=q->pNext;
		    }
	    	if(dem1>dem)
	    	{
	    		temp=lMB.nodeMB[i];
	    		lMB.nodeMB[i]=lMB.nodeMB[j];
	    		lMB.nodeMB[j]=temp;
	    		dem = dem1;
			}
			dem1=0;
	    	
	    }
	    SetColor(Color_DarkRed);
		SetBGColor(Color_DarkWhite);
		gotoxy(48,dongStart+i);cout<<lMB.nodeMB[i]->sohieu_MB; 
		gotoxy(70,dongStart+i);cout<<lMB.nodeMB[i]->loai_MB;
		gotoxy(100,dongStart+i);cout<<dem;
//		gotoxy(positionX_listMB+103,dongStart+i);cout<<dem;
		dem=0;
	}
	

}
int frameDeleteMB(List_MB & listMB, List_CB l) {
	SetBGColor(Color_DarkWhite);
	header();
	if (isEmpty(listMB)) {
		Alert("CHUA CO MAY BAY TRONG DANH SACH ", 70, MAXYCONSOLE - 3, 1.2);
		return -1;
	}
	else {
		
		int A[4]={20,50,65,80};
		SetColor(Color_Back);
		SetBGColor(Color_DarkWhite);
		table(positionX_listMB, positionY_listMB, 20, 95, 4, A);
		
		gotoxy(positionX_listMB + 3, positionY_listMB + 1);cout << "SO HIEU MAY BAY";
		gotoxy(positionX_listMB + 30, positionY_listMB + 1);cout << "LOAI MAY BAY";
		gotoxy(positionX_listMB + 55, positionY_listMB + 1);cout << "SO DAY";
		gotoxy(positionX_listMB + 70, positionY_listMB + 1);cout << "SO HANG";
		gotoxy(positionX_listMB+ 84, positionY_listMB + 1);cout << "SO GHE";
		
		for (int i = 0;i < listMB.soluong;i++) {
			Normal();
			outDataMB(listMB, i);
		}
		HighLight();
		outDataMB(listMB, 0);
		
		int vitri = 0;
		SetBGColor(Color_DarkWhite);
		while (true) {
			int key = GetKey();
			switch (key) {
			case DOWN:
				if (vitri == listMB.soluong - 1) {
					Normal();
					outDataMB(listMB, vitri);
					vitri = 0;
					HighLight();
					outDataMB(listMB, vitri);
				}
				else {
					Normal();
					outDataMB(listMB, vitri);
					vitri++;
					HighLight();
					outDataMB(listMB, vitri);
				}
				break;
			case UP:
				if (vitri == 0) {
					Normal();
					outDataMB(listMB, vitri);
					vitri = listMB.soluong - 1;
					HighLight();
					outDataMB(listMB, vitri);
				}
				else {
					Normal();
					outDataMB(listMB, vitri);
					vitri--;
					HighLight();
					outDataMB(listMB, vitri);
				}
				break;
			case ENTER:
				if (listMB.soluong > 0) {
					return vitri;
				}
				frameCoverNotice();
				return -1;
			case F1:
				{
					addList_MB(listMB);
					return -2;
				}
			case F2: 
				{
					clrscr();
					
					int A[2]={20,50};
					table(40,8,20,70,2,A);
					gotoxy(43,9);	cout<<"SO HIEU MAY BAY";
					gotoxy(70,9);	cout<<"LOAI MAY BAY";
					gotoxy(95,9);	cout<<"SO LUOT BAY";
					
					Insoluotbay(listMB ,l);
					getch();
					
					return -2;
				}
			case ESC:
				return -1;
				break;
			}
		}
	}
}


string textInput(List_MB &listMB, MAYBAY &mb, int vitrinode, char tenField[20], string temp){

	int vitri = 0; int key;
	string text = "";
	int so = 0;
	int y = 0;
	char tmp[3] = "";
	if(tenField == "SOHIEUMB" ){
		if(temp == ""){
			text = listMB.nodeMB[vitrinode]->sohieu_MB;
		} else{
			text = temp;
		}
		y = 1;
	}else if(tenField == "LOAIMAYBAY" ){
		text = listMB.nodeMB[vitrinode]->loai_MB;
		y = 5;
	}else if(tenField == "SODAY" ){
		so = listMB.nodeMB[vitrinode]->soday_MB;
		itoa(so,tmp,3);
		text = 	tmp;
		y = 9;
	}else if(tenField == "SOHANG" ){
		
		so = listMB.nodeMB[vitrinode]->sohang_MB;
		itoa(so,tmp,3);
		text = 	tmp;
		y = 13;
//		text = listMB.nodeMB[vitrinode]->sohang_MB;
	}
//	string text = listMB.nodeMB[vitrinode]->sohieu_MB;

start:
	gotoxy(positionFormInputX + 12 + vitri, positionFormInputY + y);	SetBGColor(Color_White);	cout<<text;
	while (1) {
		key = GetKey();
		switch(key)
		{
			case ENTER:
				{
					if(text.length()==0){
						Alert("CHUA NHAP SO HIEU MAY BAY", 73, MAXYCONSOLE-3, 2);
						return 0;
					}
					if(tenField == "SOHIEUMB" ){
						text.copy(mb.sohieu_MB,15);
					}else if(tenField == "LOAIMAYBAY" ){
						text.copy(mb.loai_MB,40);
					}else if(tenField == "SODAY" ){
//						text.copy(mb.soday_MB,2);
						if(text.length()==0){
							Alert("CHUA NHAP SO DAY", 77, MAXYCONSOLE-3, 2);
							goto start;
						}
						mb.soday_MB = atoi(text.c_str());
						if(mb.soday_MB>maxsoday || mb.soday_MB<=0){
							Alert("SO DAY KHONG THOA MAN ", 72, MAXYCONSOLE-3, 2);
							SetColor(Color_DarkRed);
							gotoxy(positionX_listMB + 57, dongStart + vitrinode);
							cout << "  ";
							goto start;
						}
					}else if(tenField == "SOHANG" ){
//						text.copy(mb.sohang_MB,2);
//						mb.sohang_MB = atoi(text.c_str());
						if(text.length()==0){
							Alert("CHUA NHAP SO DAY", 77, MAXYCONSOLE-3, 2);
							goto start;
						}
						mb.sohang_MB = atoi(text.c_str());
						if(mb.sohang_MB>maxsohang || mb.sohang_MB<=0){
							Alert("SO DAY KHONG THOA MAN ", 72, MAXYCONSOLE-3, 2);
							SetColor(Color_DarkRed);
							gotoxy(positionX_listMB + 57, dongStart + vitrinode);
							cout << "  ";
							goto start;
						}
					}
//					text.copy(mb.sohieu_MB,15);
//						text
						return text;
				}
			case BACKSPACE:
				{
					if(text.length()>0){	
						text.erase(text.length()-1,1);
						cout<<"\b \b";
					}
					break;
				}
			case TAB:
				{
					strcpy(mb.sohieu_MB, listMB.nodeMB[vitrinode]->sohieu_MB);
					if(tenField == "SOHANG"){
						return "ok";
					}
					return text;
				}
			default:
				{
					if((key>47&&key<123) &&text.length()<15)
					{
						gotoxy(positionFormInputX + 12 + vitri, positionFormInputY + y);
						if(97<= key && key<=122)
						{
							text +=char(key-32);
						}else{
							text +=char(key);
						}
						cout<<text;
					}
					break;
				}	
		}
	}
}

int updateInfo_MB(List_MB &listMB, MAYBAY &mb, int vitrinode) {
	int vitri;int key;
	SetBGColor(Color_DarkWhite);
	SetColor(Color_DarkRed);
SOHIEUMB:///////////////// NHAP SO HIEU MAY BAY //////////////
	// ghi chu
	alertHelp(positionAlertHelp,MAXYCONSOLE - 11,"         SO HIEU MB: GOM CAC KI TU (A-Z) & (0-9)           ");
	string temp = "";
	temp = textInput(listMB, mb, vitrinode ,"SOHIEUMB" ,temp);
LOAIMAYBAY: /////////// NHAP LOAI MAY BAY //////////////
		// ghi chu
	string temp2 = "";
	alertHelp(positionAlertHelp,MAXYCONSOLE - 11,"        LOAI MAY BAY: GOM CAC KI TU (A-Z) & (0-9)          ");
//	vitri = 0;
	
	textInput(listMB, mb, vitrinode,"LOAIMAYBAY",temp2);
SODAY:////////////// NHAP SO DAY MAY BAY/////////////////
//	char sodaychar[3];
	// ghi chu
	
	alertHelp(positionAlertHelp,MAXYCONSOLE - 11,"                 0 < SO LUONG DAY < 10                     ");
	
	textInput(listMB, mb, vitrinode,"SODAY","");
//	vitri = 0;
//	///
//	while (1) {
//		gotoxy(positionX_listMB + 57 + vitri, dongStart + vitrinode);
//		SetColor(Color_Blue);
//		SetBGColor(Color_DarkWhite);
//		fflush(stdin);
//		key = GetKey();
//		if (key >= '0' && key <= '9' && vitri < 2) {
//			sodaychar[vitri] = (char)key;
//			cout << sodaychar[vitri];
//			vitri++;
//		}
//		if (key == BACKSPACE && vitri > 0) {
//			vitri--;
//			gotoxy(positionX_listMB + 57 + vitri, dongStart + vitrinode);SetColor(Color_DarkRed);
//			cout << " ";
//
//		}
//		if (key == TAB) {
//			mb.soday_MB = listMB.nodeMB[vitrinode]->soday_MB;
//			goto SOHANG;
//		}
//		if (key == ENTER) {
//			sodaychar[vitri] = '\0';
//			if (sodaychar[0] == '\0') {
//				Alert("CHUA NHAP SO DAY", 77, MAXYCONSOLE-3, 2);
//				goto SODAY;
//			}
//			else {
//				mb.soday_MB = atoi(sodaychar);
//				if (mb.soday_MB > maxsoday || mb.soday_MB <= 0) {
//					Alert("SO DAY KHONG THOA MAN ", 72, MAXYCONSOLE-3, 2);
//					SetColor(Color_DarkRed);
//					gotoxy(positionX_listMB + 57, dongStart + vitrinode);
//					cout << "  ";
//					goto SODAY;
//				}
//				else {
//					goto SOHANG;
//				}
//			}
//		}
//		if (key == ESC) {
//			gotoxy(50, MAXYCONSOLE-3);
//
//			SetBGColor(Color_DarkWhite);
//			cout << "                                                            ";
//			SetColor(Color_DarkRed);
//			SetBGColor(Color_DarkWhite);
//			gotoxy(76, MAXYCONSOLE-3);
//			cout << "BAN CO CHAC CHAN HUY?";
//			int cofirm = GetKey();
//			if (cofirm == ENTER) {
//				return 0;
//			}
//			gotoxy(76, MAXYCONSOLE-3);
//			SetBGColor(Color_DarkWhite);
//			cout << "                                                            ";
//		}
//	}
SOHANG://///////////// NHAP SO HANG CUA MAY BAY ////////////////////
//	char sohangchar[3];
	// ghi chu
	
	alertHelp(positionAlertHelp,MAXYCONSOLE - 11,"                 0 < SO LUONG HANG < 35                    ");
	string x = textInput(listMB, mb, vitrinode,"SOHANG","");
	if(x=="ok"){
		goto SOHIEUMB;
	}
	
//	vitri = 0;
//	///
//	while (1) {
//		gotoxy(positionX_listMB + 72 + vitri, dongStart + vitrinode);
//		SetColor(Color_Blue);
//		SetBGColor(Color_DarkWhite);
//		fflush(stdin);
//		key = GetKey();
//		if (key >= '0' && key <= '9' && vitri < 2) {
//			sohangchar[vitri] = (char)key;
//			cout << sohangchar[vitri];
//			vitri++;
//		}
//		if (key == BACKSPACE && vitri > 0) {
//			vitri--;
//			gotoxy(positionX_listMB + 72 + vitri, dongStart + vitrinode);SetColor(Color_DarkRed);
//			cout << " ";
//		}
//		if (key == TAB) {
//			mb.sohang_MB = listMB.nodeMB[vitrinode]->sohang_MB;
//			goto SOHIEUMB;
//		}
//		if (key == ENTER) {
//			sohangchar[vitri] = '\0';
//			if (sohangchar[0] == '\0') {
//				mb.sohang_MB = listMB.nodeMB[vitrinode]->sohang_MB;
//				goto ENDp;
//
//			}
//			else {
//				mb.sohang_MB = atoi(sohangchar);
//				if (mb.sohang_MB > maxsohang || mb.sohang_MB <= 0) {
//					Alert("SO HANG KHONG THOA MAN ", 72, MAXYCONSOLE-3, 2);
//					SetColor(Color_DarkRed);
//					gotoxy(positionX_listMB + 72, dongStart + vitrinode);
//					cout << "  ";
//					goto SOHANG;
//				}
//				else {
//					goto ENDp;
//				}
//			}
//		}
//		if (key == ESC) {
//			gotoxy(50, MAXYCONSOLE-3);
//
//			SetBGColor(Color_DarkWhite);
//			cout << "                                                            ";
//			SetColor(Color_DarkRed);
//			SetBGColor(Color_DarkWhite);
//			gotoxy(76, MAXYCONSOLE-3);
//			cout << "BAN CO CHAC CHAN HUY?";
//			int cofirm = GetKey();
//			if (cofirm == ENTER) {
//				return 0;
//			}
//			gotoxy(76, MAXYCONSOLE-3);
//			SetBGColor(Color_DarkWhite);
//			cout << "                                                            ";
//		}
//	}
ENDp:
	gotoxy(positionFormInputX + 12, positionFormInputY + 17);
//	gotoxy(positionX_listMB + 86, dongStart + vitrinode);
	cout << (mb.soday_MB * mb.sohang_MB);
	return 1;
}
// hieu chinh thong tin may bay
int editMB(List_MB & l, List_CB lCB, int vitrinode) {

	ShowCur(true);
	footerEditMB();
	int key;
	MAYBAY mb;
	if (updateInfo_MB(l, mb, vitrinode) == 0) {
		gotoxy(50, MAXYCONSOLE-3);
		SetBGColor(Color_DarkWhite);
		cout << "                                                            ";
		Alert("DA HUY", 82, MAXYCONSOLE-3, 2);
		return 0;
	}
	else {
		if (Hoi(55,MAXYCONSOLE-5,"   THONG TIN CU SE BI XOA. BAN CO CHAC CHAN MUON LUU MOI?  ")) {
			frameCoverNotice();
			strcpy(l.nodeMB[vitrinode]->sohieu_MB, mb.sohieu_MB);
			strcpy(l.nodeMB[vitrinode]->loai_MB, mb.loai_MB);
			l.nodeMB[vitrinode]->soday_MB = mb.soday_MB;
			l.nodeMB[vitrinode]->sohang_MB = mb.sohang_MB;

			Alert("DA CAP NHAT LAI THONG TIN", 72, MAXYCONSOLE-3, 1.6);
			return 0;
		}else{
			frameCoverNotice();
			Alert("DA HUY", 82, MAXYCONSOLE-3, 1.3);clrscr();
			return 0;
		}
	}
}
//xoa may bay khoi danh sach
int quanLyMayBay(List_MB & listMB, List_CB l) {

start:
	clrscr();
	footer();
	SetColor(Color_Pink);	SetBGColor(Color_DarkWhite);	vekhung(72,4,1,32);
	gotoxy(82,5);			SetColor(Color_Pink);			cout<<"DANH SACH MAY BAY";
	//FORM NHAP LIEU
	formInput(positionFormInputX,positionFormInputY,5,ITEM);
	int vitrinode = frameDeleteMB(listMB, l);
	
	int key;
	if (vitrinode == -1) {

		SetBGColor(Color_DarkWhite);
		return 0;
	}else if(vitrinode == -2){
		goto start;
	}
	else
	{
		// CHON XOA HOAC SUA MAY BAY
		if(alertOption(55,MAXYCONSOLE-5,"           BAN MUON XOA HAY CHINH SUA MAY BAY              ")){
			if (Hoi(55,MAXYCONSOLE-5,"      BAN CO CHAC CHAN XOA MAY BAY KHOI DANH SACH?         ")) {
				if (searchInfoShmb(l, listMB.nodeMB[vitrinode]->sohieu_MB) != NULL) {
					Alert("KHONG THE XOA MAY BAY VI DA TAO CHUYEN BAY", 64, MAXYCONSOLE-3, 3);
				}else{
					frameCoverNotice();
					delete  listMB.nodeMB[vitrinode];
					for (int j = vitrinode + 1; j < listMB.soluong; j++)
						listMB.nodeMB[j - 1] = listMB.nodeMB[j];
					listMB.soluong--;
					Alert("DA XOA THANH CONG", 77, MAXYCONSOLE - 11, 1.2);
					clrscr();
				}
			}else{
				frameCoverNotice();
				Alert("DA HUY", 82, MAXYCONSOLE - 11, 1.2);clrscr(); goto start;
			}
		}else{
			//SUA MAY BAY
			frameCoverNotice();
			editMB(listMB, l, vitrinode);
		}
	}
	goto start;

}

//luu file danh sach may bay
void saveFileList_MB(List_MB l) {
	ofstream fileMbOut ("Danhsachmaybay.txt");
	for(int i=0;i<l.soluong;i++){
	fileMbOut << l.nodeMB[i]->sohieu_MB<<" ";
	fileMbOut << l.nodeMB[i]->loai_MB<<" ";
	fileMbOut << l.nodeMB[i]->soday_MB<<" ";
	fileMbOut << l.nodeMB[i]->sohang_MB<<" ";
	if(i!=l.soluong-1){
		fileMbOut<<endl;
		}
		
	}
	fileMbOut.close();

}
int docFileInfo1MB(ifstream &fileMbIn,MAYBAY &mb){
	string data;
	getline(fileMbIn,data,' ');	strcpy(mb.sohieu_MB, data.c_str());
	getline(fileMbIn,data,' '); strcpy(mb.loai_MB,data.c_str());
	getline(fileMbIn,data,' ');mb.soday_MB= atoi(data.c_str());
	getline(fileMbIn,data,' ');mb.sohang_MB= atoi(data.c_str());	
	
	}
//doc file danh sach may bay
int openFileList_MB(List_MB &l) {
ifstream fileMbIn ("Danhsachmaybay.txt");
	string temp;
	l.soluong=0;
	while(!fileMbIn.eof()){
		MAYBAY mb;
		docFileInfo1MB(fileMbIn,mb);
		l.nodeMB[l.soluong]=new MAYBAY;
		*l.nodeMB[l.soluong]=mb;
		l.soluong++;
		getline(fileMbIn,temp);
	}
	fileMbIn.close();

}
///////////////////////////////////////////////////////////////// CHUYEN BAY ///////////////////////////////////////////////////////////////////////////////////
// tim kiem





//tao node chuyen bay, them du lieu cho node va tra ve dia chi node
Node_CB* createNodeCB(CHUYENBAY cb) {
	Node_CB* p = new Node_CB;
	if (p == NULL) {
		Alert("CAP PHAT BO NHO KHONG THANH CONG", 70, MAXYCONSOLE-3, 1.5);
		exit(1);
	}
	else {
		p->data = cb;
		p->pNext == NULL;
		return p;
	}
}

boolean isEmptyListCB(List_CB l) {
	if (l.pHead == NULL) {
		return true;
	}
	return false;
}
boolean checkTrungChuyenbay(List_CB l, CHUYENBAY cb) {
	for (Node_CB* p = l.pHead;p != NULL;p = p->pNext) {
		if (strcmp(p->data.sohieumb, cb.sohieumb) == 0) {// neu trung sohieu thi kiem tra thang
			if (p->data.ngaygioStart.month == cb.ngaygioStart.month) {// neu trung thang thi kiem tra ngay
				if (p->data.ngaygioStart.day == cb.ngaygioStart.day) {//neu trung ngay thi cach 6 tieng moi duoc bay
					if ((abs(p->data.ngaygioStart.hours - cb.ngaygioStart.hours + (p->data.ngaygioStart.minutes - cb.ngaygioStart.minutes) / (float)60) < 6))
						gotoxy(1,1);cout<<cb.ngaygioStart.month<<"/"<<cb.ngaygioStart.day;
						return false;
				}
			}
		}
	}
	return true;
}
boolean checkTrungChuyenbayEdit(List_CB & l, CHUYENBAY & cb, CHUYENBAY cbcansua) {
	for (Node_CB* p = l.pHead;p != NULL;p = p->pNext) {
		if (strcmp(p->data.sohieumb, cb.sohieumb) == 0 && strcmp(p->data.ma_CB, cbcansua.ma_CB) != 0) {// neu trung sohieu thi kiem tra thang
			if (p->data.ngaygioStart.month == cb.ngaygioStart.month) {// neu trung thang thi kiem tra ngay
				if (p->data.ngaygioStart.day == cb.ngaygioStart.day) {//neu trung ngay thi cach 6 tieng moi duoc bay
					if ((abs(p->data.ngaygioStart.hours - cb.ngaygioStart.hours + (p->data.ngaygioStart.minutes - cb.ngaygioStart.minutes) / (float)60) < 6))
						return false;
				}
			}
		}
	}
	return true;
}

void NhapLieu(int x, int y, string &text, int sokytu){

	int key;
	gotoxy(x, y);	SetBGColor(Color_DarkWhite);	cout<<text;
	while (true) {
		key = GetKey();
		switch(key)
		{
			case ESC:{
				text = "";
				return;
			}
			case TAB:
			case ENTER:
				{
					if(text.length()==0){
						gotoxy(x -10, y+1); SetColor(Color_DarkRed);
						cout<<"VUI LONG DIEN THONG TIN";
//						gotoxy(x,y); SetColor(Color_DarkBlue); cout<<text;
					}else{
						gotoxy(x -10, y+1); SetBGColor(Color_DarkWhite);
						cout<<"                       ";
						return;
					}
				}
			case BACKSPACE:
				{
					if(text.length()>0){	
						text.erase(text.length()-1,1);
						cout<<"\b \b";
					}
					break;
				}
			default:
				{
					if((key>47&&key<123) &&text.length()<sokytu)
					{
						gotoxy(x, y);
						if(97<= key && key<=122)
						{
							text +=char(key-32);
						}else{
							text +=char(key);
						}
						cout<<text;
					}
					break;
				}	
		}
	}
}
void NhapLieuso(int x, int y, string &text, int sokytu){

	int key;
	gotoxy(x, y);	SetBGColor(Color_DarkWhite);	cout<<text;
	while (true) {
		key = GetKey();
		switch(key)
		{
			case ESC:{
				text = "";
				return;
			}
			case TAB:
			case ENTER:
				{
					if(text.length()==0){
						gotoxy(x -10, y+1); SetColor(Color_DarkRed);
						cout<<"VUI LONG DIEN THONG TIN";
						gotoxy(x,y); SetColor(Color_DarkBlue); cout<<text;
					}else{
						gotoxy(x -10, y+1); SetBGColor(Color_DarkWhite);
						cout<<"                       ";
						return;
					}
				}
			case BACKSPACE:
				{
					if(text.length()>0){	
						text.erase(text.length()-1,1);
						cout<<"\b \b";
					}
					break;
				}
			default:
				{
					if((key>47&&key<58) &&text.length()<sokytu)
					{
						gotoxy(x, y);
						text +=char(key);
						cout<<text;
					}
					break;
				}	
		}
	}
}
string Chuyen(int x){
	ostringstream convert;   
    convert << x;
    string resuft = convert.str();
    if(resuft.length()==1){
    	resuft ="0" + resuft;
	}
    return resuft;
}

//them thong tin cho chuyen bay
int addInfo_CB(List_CB & listCB, List_MB & listMB, CHUYENBAY & cb) {
start:
//	frameAdd_CB();footer();
	int vitri; int key;
	SetColor(Color_DarkRed);
	SetBGColor(Color_DarkWhite);	gotoxy(2, dongStartCB);
	
	int A[6]={20,40,55,75,90,105};
	table(positionX_listCB ,40 , 3, 120, 6, A);
	SetColor(Color_Back);
	gotoxy(positionX_listCB + 4, 40 + 1); 	cout<<"MA CHUYEN BAY";
	gotoxy(positionX_listCB + 24, 40 + 1); 	cout<<"SO HIEU MB";
	gotoxy(positionX_listCB + 44, 40 + 1); 	cout<<"NOI DEN";
	gotoxy(positionX_listCB + 59, 40 + 1); 	cout<<"NGAY KHOI HANH ";
	gotoxy(positionX_listCB + 80, 40 + 1); 	cout<<"GIO KH";
	gotoxy(positionX_listCB + 93, 40 + 1); 	cout<<" SO GHE";
	gotoxy(positionX_listCB + 108, 40 + 1); 	cout<<"TRANG THAI";
	bool update = false;
	string ma_CB = "", sohieuMB = "", noiden = "", ngay = "", gio = "";
	ma_CB = cb.ma_CB;
	if(ma_CB != ""){
		update = true;
		string day 		= Chuyen(cb.ngaygioStart.day);
		string month 	= Chuyen(cb.ngaygioStart.month);
		string year 	= Chuyen(cb.ngaygioStart.year);
		string hours 	= Chuyen(cb.ngaygioStart.hours);
		string minutes 	= Chuyen(cb.ngaygioStart.minutes);
	    
		sohieuMB = cb.sohieumb;
		noiden	= cb.sanbayDen;
		ngay		= day + "/" + month + "/" + year;
		gio 		= hours + ":" + minutes;
		gotoxy(18 , 43);		cout<<ma_CB;
		gotoxy(34 , 43);		cout<<sohieuMB;
		gotoxy(53 , 43);		cout<<noiden;
		gotoxy(70 , 43);		cout<<ngay;
		gotoxy(91 , 43);		cout<<gio;
		gotoxy(107, 43);		cout<<cb.soluongVe;
		gotoxy(118, 43);		cout << staTus[cb.trangthai];
	}

MACHUYENBAY:///////////////////// MA CHUYEN BAY
	SetColor(Color_DarkRed);
	SetBGColor(Color_White);
	gotoxy(55, 47);
	cout << "                                                           ";
	gotoxy(55, 48);
	cout << "       MA CHUYEN BAY: GOM CAC KI TU (A-Z) & (0-9)          ";
	gotoxy(55, 49);
	cout << "                                                           ";
	NhapLieu(positionX_listCB + 8, 43, ma_CB, 15);
	if(ma_CB == "") return 0;
	ma_CB.copy(cb.ma_CB,15);
	if(!update){
		if (searchInfo(listCB, cb.ma_CB) != NULL) {
			Alert("MA CHUYEN BAY BI TRUNG!", 73, MAXYCONSOLE-3, 2);
			gotoxy(8, dongStartCB);
			SetColor(Color_DarkRed);cout << "        ";
			goto MACHUYENBAY;
		}
	}
SOHIEUMAYBAY://////////////// SO HIEU MAY BAY
			// ghi chu
	SetColor(Color_DarkRed);
	SetBGColor(Color_White);
	gotoxy(55, 47);
	cout << "                                                           ";
	gotoxy(55, 48);
	cout << "               CHON MAY BAY TRONG DANH SACH                ";
	gotoxy(55, 49);
	cout << "                                                           ";

	while (1) {
	start1:
		
		gotoxy(positionX_listCB+24,43);
		cout<<sohieuMB;
		do{
			
			key = GetKey();
			switch(key){
				case ENTER: {
					SetBGColor(Color_DarkWhite);
					vekhungdoi(144,10,20,13);		kengangdoi(144,12,13);
					gotoxy(146,11); 				cout<<"SO HIEU MB";
					int nodeout = frameAddShmb_AddCB(listMB);
					if (nodeout == -1) {
						goto start1;
					}
					SetColor(Color_Blue);
					SetBGColor(Color_DarkWhite);
					gotoxy(positionX_listCB + 24, 43);cout << listMB.nodeMB[nodeout]->sohieu_MB;
					sohieuMB = listMB.nodeMB[nodeout]->sohieu_MB;
					key = GetKey();
					if (key == ESC) {
						gotoxy(40, MAXYCONSOLE-3);
						SetBGColor(Color_DarkWhite);
						cout << "                                                                                                              ";
						SetColor(Color_DarkRed);
						SetBGColor(Color_DarkWhite);
						gotoxy(65, MAXYCONSOLE-3);
						cout << "BAN MUON CHON LAI(ENTER) HAY HUY NHAP(ESC)?";
						int cofirm = GetKey();
						if (cofirm == ENTER) {
							SetColor(Color_DarkRed);
							SetBGColor(Color_DarkWhite);
							gotoxy(positionX_listCB + 24, 43);cout << "        ";
							gotoxy(40, MAXYCONSOLE-3);
							SetBGColor(Color_DarkWhite);
							cout << "                                                                                                              ";
							goto SOHIEUMAYBAY;
						}
						else if (cofirm == ESC) {
							gotoxy(40, MAXYCONSOLE-3);
							SetBGColor(Color_DarkWhite);
							cout << "                                                                                                                ";
							return 0;
						}
			
					}
					if (key == ENTER || key == TAB) {
						strcpy(cb.sohieumb, listMB.nodeMB[nodeout]->sohieu_MB);
						
						SetBGColor(Color_DarkWhite);
						for (int i = 0;i < 22;i++) {
							gotoxy(144, 10 + i);cout << "               ";
						}
						goto NOIDEN;
					}
				}
				case TAB: {
					sohieuMB.copy(cb.sohieumb,15);
//					strcpy(cb.sohieumb, listMB.nodeMB[nodeout]->sohieu_MB);
					goto NOIDEN;
				}
			}
		}while(key != TAB);
	}
NOIDEN:/// NHAP SAN BAY DEN
	
	SetColor(Color_DarkRed);
	SetBGColor(Color_White);
	gotoxy(55, 47);
	cout << "                                                           ";
	gotoxy(55, 48);
	cout << "                   NHAP SAN BAY DEN                        ";
	gotoxy(55, 49);
	cout << "                                                           ";
	
	NhapLieu(53, 43, noiden, 4);
	noiden.copy(cb.sanbayDen,4);
	if (checkNoiDen(cb.sanbayDen) < 0) {
		Alert("NOI DEN KHONG HOP LE!", 73, MAXYCONSOLE-3, 2);
		gotoxy(43, dongStartCB);
		SetColor(Color_DarkRed);cout << "    ";
		goto NOIDEN;
	}
NGAY://NHAP NGAY KHOI HANH

	SetColor(Color_DarkRed);
	SetBGColor(Color_White);
	gotoxy(55, 47);
	cout << "                                                                ";
	gotoxy(55, 48);
	cout << " CU PHAP: dd/mm/yyyy. NEU NGAY,THANG < 10 THI THEM 0 PHIA TRUOC ";
	gotoxy(55, 49);
	cout << "                                                                ";
	vitri = 0;
	char ngaytemp[3];
	char thangtemp[3];
	char namtemp[5];
	char ddmmyy[11];
	ShowCur(true);
	gotoxy(70,43);cout<<ngay;
	while (1) {
		SetBGColor(Color_DarkWhite);
		SetColor(Color_Blue);
		key = GetKey();
		if ((key >= 47 && key < 58) && ngay.length() < 10) {
			ngay +=char(key);
			gotoxy(70,43);cout<<ngay;
		}
		if (key == BACKSPACE) {
			if(ngay.length()>0){	
				ngay.erase(ngay.length()-1,1);
				cout<<"\b \b";
			}
		}if (key == ENTER || key == TAB) {
			ngay.copy(ddmmyy,11);
			ddmmyy[11] = '\0';
			if (ddmmyy[0] == '\0') {
				Alert("CHUA NHAP NGAY KHOI HANH", 72, MAXYCONSOLE-3, 2);
				goto NGAY;
			}
			else {
				ngaytemp[0] = ddmmyy[0];ngaytemp[1] = ddmmyy[1];
				thangtemp[0] = ddmmyy[3];thangtemp[1] = ddmmyy[4];
				namtemp[0] = ddmmyy[6];namtemp[1] = ddmmyy[7];namtemp[2] = ddmmyy[8];namtemp[3] = ddmmyy[9];
				cb.ngaygioStart.day = atoi(ngaytemp);
				cb.ngaygioStart.month = atoi(thangtemp);
				cb.ngaygioStart.year = atoi(namtemp);
				if (checkYear(cb.ngaygioStart.year) != true || checkMonth(cb.ngaygioStart.month) != true || checkDay(cb.ngaygioStart.day, cb.ngaygioStart.month) != true) {
					Alert("NGAY KHOI HANH KHONG DUNG", 71, MAXYCONSOLE-3, 2);
					SetColor(Color_DarkRed);
					gotoxy(70, 43);
					cout << "          ";
					goto NGAY;
				}
				else if (checkCurrentDDMMYY(cb.ngaygioStart.day, cb.ngaygioStart.month) != true) {
					Alert("NGAY PHAI LON HON NGAY HIEN TAI", 70, MAXYCONSOLE-3, 2);
					SetColor(Color_DarkRed);
					gotoxy(70, 43);
					cout << "          ";
					goto NGAY;
				}
				SetBGColor(Color_DarkWhite);
				gotoxy(55, 47);
				cout << "                                                                                   ";
				gotoxy(55, 48);
				cout << "                                                                                   ";
				gotoxy(55, 49);
				cout << "                                                                                   ";
				goto GIO;
			}
		}
		if (key == ESC) {
			gotoxy(50, MAXYCONSOLE-3);

			SetBGColor(Color_DarkWhite);
			cout << "                                                            ";
			SetColor(Color_DarkRed);
			SetBGColor(Color_DarkWhite);
			gotoxy(76, MAXYCONSOLE-3);
			cout << "BAN CO CHAC CHAN HUY?";
			int cofirm = GetKey();
			if (cofirm == ENTER) {
				gotoxy(76, MAXYCONSOLE-3);
				SetBGColor(Color_DarkWhite);
				cout << "                                                            ";
				return 0;
			}
			gotoxy(76, MAXYCONSOLE-3);
			SetBGColor(Color_DarkWhite);
			cout << "                                                            ";
		}
	}

GIO:///////// NHAP GIO KHOI HANH

	SetColor(Color_DarkRed);
	SetBGColor(Color_White);
	gotoxy(55, 47);
	cout << "                                                                ";
	gotoxy(55, 48);
	cout << " CU PHAP: hh:mm. NEU GIO, PHUT NHO HON 10 THI THEM 0 PHIA TRUOC ";
	gotoxy(55, 49);
	cout << "                                                                ";

	vitri = 0;
	char giotemp[3];
	char phuttemp[3];
	char hhmm[6];
	ShowCur(true);
	gotoxy(91,43);cout<<gio;
	while (1) {
		SetBGColor(Color_DarkWhite);
		SetColor(Color_Blue);
//		fflush(stdin);
		key = GetKey();
		if ((key > 47 && key <= 58) && gio.length() < 5) {
			gio +=char(key);
			gotoxy(91,43);cout<<gio;
		}
		if (key == BACKSPACE) {
			if(gio.length()>0){	
				gio.erase(gio.length()-1,1);
				cout<<"\b \b";
			}
		}
		if (key == ENTER) {
			gio.copy(hhmm,6);
			hhmm[6] = '\0';
			if (ddmmyy[0] == '\0') {
				Alert("CHUA NHAP GIO KHOI HANH", 72, MAXYCONSOLE-3, 2);
				goto GIO;
			}
			else {
				giotemp[0] = hhmm[0];giotemp[1] = hhmm[1];
				phuttemp[0] = hhmm[3];phuttemp[1] = hhmm[4];
				cb.ngaygioStart.hours = atoi(giotemp);
				cb.ngaygioStart.minutes = atoi(phuttemp);
				if (cb.ngaygioStart.hours < 0 || cb.ngaygioStart.hours>23 || cb.ngaygioStart.minutes < 0 || cb.ngaygioStart.minutes>59) {
					Alert("GIO KHOI HANH KHONG DUNG", 71, MAXYCONSOLE-3, 2);
					SetColor(Color_DarkRed);
					gotoxy(91, 43);
					cout << "     ";
					goto GIO;
				}
				else if (checkTrungChuyenbay(listCB, cb) == false) {
					Alert("CHUYEN BAY BI TRUNG NGAY GIO KHOI HANH. KIEM TRA LAI THONG TIN", 55, MAXYCONSOLE-3, 4);
					int key1 = frameAddNext();//thay nhap tiep
					frameCoverNotice();
					SetBGColor(Color_DarkWhite);
					gotoxy(55, 47);
					cout << "                                                                    ";
					gotoxy(55, 48);
					cout << "                                                                    ";
					gotoxy(55, 49);
					cout << "                                                                    ";
					if (key1 == ENTER) {
						goto start;
					}
					else if (key1 = ESC) {
						return 0;
					}
				}

				goto ENDp;
			}
		}
		if (key == ESC) {
			gotoxy(50, MAXYCONSOLE-3);
			SetBGColor(Color_DarkWhite);
			cout << "                                                            ";
			SetColor(Color_DarkRed);
			SetBGColor(Color_DarkWhite);
			gotoxy(76, MAXYCONSOLE-3);
			cout << "BAN CO CHAC CHAN HUY?";
			int cofirm = GetKey();
			if (cofirm == ENTER) {
				gotoxy(76, MAXYCONSOLE-3);
				SetBGColor(Color_DarkWhite);
				cout << "                                                            ";
				return 0;
			}
			gotoxy(76, MAXYCONSOLE-3);
			SetBGColor(Color_DarkWhite);
			cout << "                                                            ";
		}
		if(key == TAB){
			goto MACHUYENBAY;
		}
	}
ENDp:
	key = GetKey();
	if(key == F2){
		SetColor(Color_Blue);
		cb.soluongVe = (listMB.nodeMB[search(listMB, cb.sohieumb)]->soday_MB * listMB.nodeMB[search(listMB, cb.sohieumb)]->sohang_MB);
		gotoxy(107, 43);cout << cb.soluongVe;
		cb.trangthai = 1;
		gotoxy(118, 43);cout << staTus[cb.trangthai];
//		return;
	}else if(key == TAB){
		goto MACHUYENBAY;
	}else{
		goto ENDp;
	}
	
}

//hien thi thong tin node chuyen bay
int showInfo_CB(CHUYENBAY cb, int x) {
	//char d[3],mo[3],h[3],mi[3];

	SetBGColor(Color_DarkWhite);SetColor(Color_DarkRed);
//	2,6,11,16,19,24,29
//		int A[6]={20,40,55,75,90,105};
//	gotoxy(2, dongStartCB + x);cout << "|__________________|________________|____________|________________|_________|__________|_______________|";
	gotoxy(positionX_listCB + 6, positionY_listCB + 3 + x);cout << cb.ma_CB;
	gotoxy(positionX_listCB + 22, positionY_listCB + 3 + x);cout << cb.sohieumb;
	gotoxy(positionX_listCB + 35, positionY_listCB + 3 + x);cout << cb.sanbayDen;
	////ngay
	if (cb.ngaygioStart.day < 10) {
		gotoxy(positionX_listCB + 46 , positionY_listCB + 3 + x);cout << "0";
		gotoxy(positionX_listCB + 47 , positionY_listCB + 3 + x);cout << cb.ngaygioStart.day << "/";
	}
	else {
		gotoxy(positionX_listCB + 46, positionY_listCB + 3 + x);cout << cb.ngaygioStart.day << "/";
	}
	//thang
	if (cb.ngaygioStart.month < 10) {
		gotoxy(positionX_listCB + 49, positionY_listCB + 3 + x);cout << "0";
		gotoxy(positionX_listCB + 50, positionY_listCB + 3 + x);cout << cb.ngaygioStart.month << "/";
	}
	else {
		gotoxy(positionX_listCB + 49, positionY_listCB + 3 + x);cout << cb.ngaygioStart.month << "/";
	}
	//nam
	gotoxy(positionX_listCB + 52, positionY_listCB + 3 + x);cout << cb.ngaygioStart.year;
	//gio
	if (cb.ngaygioStart.hours < 10) {
		gotoxy(positionX_listCB + 61, positionY_listCB + 3 + x);cout << "0";
		gotoxy(positionX_listCB + 62, positionY_listCB + 3 + x);cout << cb.ngaygioStart.hours << ":";
	}
	else {
		gotoxy(positionX_listCB + 61, positionY_listCB + 3 + x);cout << cb.ngaygioStart.hours << ":";
	}
	//phut
	if (cb.ngaygioStart.minutes < 10) {
		gotoxy(positionX_listCB + 64, positionY_listCB + 3 + x);cout << "0";
		gotoxy(positionX_listCB + 65, positionY_listCB + 3 + x);cout << cb.ngaygioStart.minutes;
	}
	else {
		gotoxy(positionX_listCB + 64, positionY_listCB + 3 + x);cout << cb.ngaygioStart.minutes;
	}
	gotoxy(positionX_listCB + 72, positionY_listCB + 3 + x);cout << cb.soluongVe;
	gotoxy(positionX_listCB + 82, positionY_listCB + 3 + x);cout << staTus[cb.trangthai];

	//	cout<<cb.ma_CB<<"\t"<<cb.sohieumb<<"\t"<<cb.ngaygioStart.day<<"/"<<cb.ngaygioStart.month<<"/"<<cb.ngaygioStart.year<<"\t"<<cb.ngaygioStart.hours<<":"<<cb.ngaygioStart.minutes<<"\t"<<cb.sanbayDen<<"\t"<<cb.soluongVe<<"\t"<<cb.trangthai<<endl;
}
//hien thi list cac chuyen bay
int showList_CB(List_CB listCB) {
	if (listCB.pHead == NULL) {
		Alert("DANH SACH CHUYEN BAY RONG", 73, MAXYCONSOLE-3, 2);
	}
	else {
//		frameSanbayDen();
		Node_CB* p;
		p = listCB.pHead;
		int i = 0;
		
//				  16 30 42 59 68 78
//				  16 30 42 17 9, 10 
//		int A[6]={20,40,55,75,90,105};
//		SetColor(Color_Back);
//		table(positionX_listCB ,positionY_listCB , 30, 120, 6, A);
//		gotoxy(positionX_listCB + 4, positionY_listCB + 1); 	cout<<"MA CHUYEN BAY";
//		gotoxy(positionX_listCB + 24, positionY_listCB + 1); 	cout<<"SO HIEU MB";
//		gotoxy(positionX_listCB + 44, positionY_listCB + 1); 	cout<<"NOI DEN";
//		gotoxy(positionX_listCB + 59, positionY_listCB + 1); 	cout<<"NGAY KHOI HANH ";
//		gotoxy(positionX_listCB + 80, positionY_listCB + 1); 	cout<<"GIO KH";
//		gotoxy(positionX_listCB + 93, positionY_listCB + 1); 	cout<<" SO GHE";
//		gotoxy(positionX_listCB + 108, positionY_listCB + 1); 	cout<<"TRANG THAI";
//		
//				  16 30 42 59 68 78
//				  16 30 42 17 9, 10 2,6,11,16,19,24,29
		int A[6]={16,30,42,59,68,78};
		SetColor(Color_Back);
		table(positionX_listCB ,positionY_listCB , 30, 93, 6, A);
		gotoxy(positionX_listCB + 2, positionY_listCB + 1); 	cout<<"MA CHUYEN BAY";
		gotoxy(positionX_listCB + 18, positionY_listCB + 1); 	cout<<"SO HIEU MB";
		gotoxy(positionX_listCB + 33, positionY_listCB + 1); 	cout<<"NOI DEN";
		gotoxy(positionX_listCB + 44, positionY_listCB + 1); 	cout<<"NGAY KHOI HANH ";
		gotoxy(positionX_listCB + 61, positionY_listCB + 1); 	cout<<"GIO KH";
		gotoxy(positionX_listCB + 69, positionY_listCB + 1); 	cout<<" SO GHE";
		gotoxy(positionX_listCB + 81, positionY_listCB + 1); 	cout<<"TRANG THAI";
		
	
		while (p != NULL)
		{
			showInfo_CB(p->data, i);
			p = p->pNext;
			i++;
		}
		return i;
	}

}

//xoa chuyen bay theo ma chuyen bay
int DeleteCB(List_CB & listCB) {
//	header();

	if (listCB.pHead == NULL) {
		Alert("DANH SACH CHUYEN BAY RONG", 72, MAXYCONSOLE-3, 1);
		return 0;
	}
	else {
		string temp = "";
		char maCB[15];
	NHAP:
		SetColor(Color_DarkRed);
		SetBGColor(Color_DarkWhite);
		ShowCur(true);
		
		SetBGColor(Color_DarkWhite);
		int key;
		while(1){
			
			gotoxy(135,8);		cout<<"NHAP ENTER DE NHAP MA CAN XOA";
			gotoxy(135,9);		cout<<"ESC DE THOAT";
			key = GetKey();
			switch(key){
				case ENTER: {
					SetColor(Color_Back);
					vekhungdoi(135,10,4,30);	kengangdoi(135,12,30);
					gotoxy(142,11); 			cout<<"SO HIEU MAY BAY";
					NhapLieu(150,13, temp, 15);
					temp.copy(maCB,15);
					Node_CB* p, * q;
					p = searchInfo(listCB, maCB);//tim va tra ve dia chi cua chuyen bay co ma chuyen bay la maCB
					if (p == NULL) {
						gotoxy(140, 16);SetColor(Color_Back);
						cout << "KHONG TIM THAY CHUYEN BAY!";
						getch();
						gotoxy(140, 16);SetColor(Color_DarkWhite);
						cout << "                          ";
						SetColor(Color_DarkRed);
//						gotoxy(149, 13);cout << "            ";
						goto NHAP;
					}
					if(p->data.trangthai==3){
						Alert2("CHUYEN BAY DA HOAN TAT",142,17,3);
						return 0;
					}		
					else{
						if(Hoi(134,17,"   BAN CO MUON XOA CHUYEN BAY   ")){
							gotoxy(134,17);		SetBGColor(Color_DarkWhite);		cout<<"                                ";
							gotoxy(134,18);		SetBGColor(Color_DarkWhite);		cout<<"                                ";
							gotoxy(134,19);		SetBGColor(Color_DarkWhite);		cout<<"                                ";
							gotoxy(134,20);		SetBGColor(Color_DarkWhite);		cout<<"                                ";
							if(checkTonTaiVe(p->data)!=0){// co chuyen bay va da co nguoi dat ve 
								Alert2("CHUYEN BAY DA CO HANH KHACH",138,17,2);
								goto NHAP;
							}
							Normal();
							if (p == listCB.pHead) {//neu chuyen bay can tim o dau danh sach
								listCB.pHead = p->pNext;
								delete p;
								Alert("XOA CHUYEN BAY THANH CONG", 70, MAXYCONSOLE-3, 1);
								
								SetBGColor(Color_DarkWhite);
								showList_CB(listCB);
//								gotoxy(149, 13);cout << "            ";
								goto NHAP;
							}
							else {
								q = listCB.pHead;
								for (q;q->pNext != p && q->pNext != NULL;q = q->pNext) {
								}
								q->pNext = p->pNext;
								delete p;
								showList_CB(listCB);
								Alert("XOA CHUYEN BAY THANH CONG", 70, MAXYCONSOLE-3, 1);
								SetBGColor(Color_DarkWhite);
								showList_CB(listCB);
//								gotoxy(149, 13);cout << "            ";
								goto NHAP;
							}
						}else{
							SetBGColor(Color_DarkWhite);
							gotoxy(134,17);		SetBGColor(Color_DarkWhite);		cout<<"                                ";
							gotoxy(134,18);		SetBGColor(Color_DarkWhite);		cout<<"                                ";
							gotoxy(134,19);		SetBGColor(Color_DarkWhite);		cout<<"                                ";
							gotoxy(134,20);		SetBGColor(Color_DarkWhite);		cout<<"                                ";
							
//							gotoxy(149, 13);cout << "            ";
							goto NHAP;
						}
					}
					break;
				}
				case ESC: {
					SetBGColor(Color_DarkWhite);
					gotoxy(135,8);		cout<<"                                ";
					gotoxy(135,9);		cout<<"                                ";
					
					gotoxy(135,10);		cout<<"                                ";
					gotoxy(135,11);		cout<<"                                ";
					gotoxy(135,12);		cout<<"                                ";
					gotoxy(135,13);		cout<<"                                ";
					gotoxy(135,14);		cout<<"                                ";
					gotoxy(135,15);		cout<<"                                ";
					return 1;
					break;
				}
			}
		}
	}
}

int updateInfo_CB(List_CB & lCB, List_MB & lMB, CHUYENBAY cb, CHUYENBAY &cbtemp) {
	Normal();
	int vitri;
	int key;
//	gotoxy(132, 15);cout << "|_______________TIM THAY__________________|";
	gotoxy(139, 17);cout << cb.ma_CB;
	gotoxy(139, 19);cout << cb.sohieumb;
	gotoxy(139, 21);cout << cb.sanbayDen;
	gotoxy(136, 23);cout << cb.ngaygioStart.day << "/" << cb.ngaygioStart.month << "/" << cb.ngaygioStart.year;
	gotoxy(139, 25);cout << cb.ngaygioStart.hours << ":" << cb.ngaygioStart.minutes;
	gotoxy(143, 27);cout << staTus[cb.trangthai];
	//	gotoxy(150,21);cout<<"THANG: "<<cb.ngaygioStart.month;
	//	gotoxy(140,22);cout<<"TRANG THAI: "<<staTus[cb.trangthai];
MACHUYENBAY:///////////////////// MA CHUYEN BAY
	SetColor(Color_DarkRed);
	SetBGColor(Color_White);
	gotoxy(55, 47);
	cout << "                                                           ";
	gotoxy(55, 48);
	cout << "       MA CHUYEN BAY: GOM CAC KI TU (A-Z) & (0-9)          ";
	gotoxy(55, 49);
	cout << "                                                           ";
	vitri = 0;
	//	gotoxy(151+vitri,17);
	while (1) {
		gotoxy(165 + vitri, 17);
		SetColor(Color_Blue);
		SetBGColor(Color_DarkWhite);
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key >= 'a' && key <= 'z') || (key <= '9' && key >= '0')) && (vitri < 15)) {
			cbtemp.ma_CB[vitri] = toupper((char)key);
			cout << cbtemp.ma_CB[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0) {
			vitri--;
			gotoxy(165 + vitri, 17);
			SetColor(Color_DarkRed);
			cout << " ";
		}
		if (key == TAB) {
			strcpy(cbtemp.ma_CB, cb.ma_CB);
			gotoxy(165,17);
			SetColor(Color_Blue);
			cout << cbtemp.ma_CB;
			goto SOHIEUMAYBAY;
		}
		if (key == ESC) {
			gotoxy(50, MAXYCONSOLE-3);
			SetBGColor(Color_DarkWhite);
			cout << "                                                            ";
			SetColor(Color_DarkRed);
			SetBGColor(Color_DarkWhite);
			gotoxy(76, MAXYCONSOLE-3);
			cout << "BAN CO CHAC CHAN HUY?";
			int cofirm = GetKey();
			gotoxy(76, MAXYCONSOLE-3);
			SetBGColor(Color_DarkWhite);
			cout << "                                                            ";
			if (cofirm == ENTER) {

				return 0;
			}
			//	gotoxy(76,MAXYCONSOLE-3);
			//	SetBGColor(Color_DarkWhite);
			//	cout<<"                                                            ";
		}
		if (key == ENTER) {
			cbtemp.ma_CB[vitri] = '\0';
			if (cbtemp.ma_CB[0] == '\0') {
				Alert("CHUA NHAP MA CHUYEN BAY", 73, MAXYCONSOLE-3, 2);
				goto MACHUYENBAY;
			}
			else if (searchInfo(lCB, cbtemp.ma_CB) != NULL && strcmp(cb.ma_CB, cbtemp.ma_CB) != 0) {
				Alert("MA CHUYEN BAY BI TRUNG!", 73, MAXYCONSOLE-3, 2);
				gotoxy(165, 17);
				cout << "          ";
				goto MACHUYENBAY;
			}
			else {
				goto SOHIEUMAYBAY;
			}
		}
	}
SOHIEUMAYBAY://////////////// SO HIEU MAY BAY
			// ghi chu
	SetColor(Color_DarkRed);
	SetBGColor(Color_White);
	gotoxy(55, 47);
	cout << "                                                           ";
	gotoxy(55, 48);
	cout << "               CHON MAY BAY TRONG DANH SACH                ";
	gotoxy(55, 49);
	cout << "                                                           ";
	SetBGColor(Color_DarkWhite);
	gotoxy(165, 19);//cout<<"         ";
	while (1) {
		nhaplai:
		gotoxy(165, 19);		
		key = GetKey();
		if(key!=ENTER&&key!=ESC&&key!=TAB){
			goto nhaplai;
			}
		if (key == ENTER) {
		start1:
			int nodeout = frameAddShmb_AddCB(lMB);
			xoaSoHieuMayBay(lMB.soluong+5);
			if (nodeout == -1) {
				goto start1;
			}
			int key1;
			SetColor(Color_Blue);
			SetBGColor(Color_DarkWhite);
			gotoxy(165, 19);cout << lMB.nodeMB[nodeout]->sohieu_MB;
			nhaplai2:
			key1 = GetKey();
			if(key1!=ENTER&&key1!=ESC){
				goto nhaplai2;
				}
			if (key1 == ESC) {
				gotoxy(40, MAXYCONSOLE-3);
				SetBGColor(Color_DarkWhite);
				cout << "                                                                                                              ";
				SetColor(Color_DarkRed);
				SetBGColor(Color_DarkWhite);
				gotoxy(65, MAXYCONSOLE-3);
				cout << "BAN MUON CHON LAI(ENTER) HAY HUY NHAP(ESC)?";
				nhaplaicofirm:
				int cofirm = GetKey();
				if(cofirm!=ENTER&&cofirm!=ESC){
					goto nhaplaicofirm;
					}
				if (cofirm == ENTER) {
					SetColor(Color_DarkRed);
					SetBGColor(Color_DarkWhite);
					gotoxy(165, 19);cout << "         ";
					gotoxy(40, MAXYCONSOLE-3);
					SetBGColor(Color_DarkWhite);
					cout << "                                                                                                              ";
					goto SOHIEUMAYBAY;
				}
				else if (cofirm == ESC) {
					gotoxy(40, MAXYCONSOLE-3);
					SetBGColor(Color_DarkWhite);
					cout << "                                                                                                                ";
					return 0;
				}
			}
			if (key1 == ENTER) {
				if (lMB.nodeMB[nodeout]->soday_MB < lMB.nodeMB[search(lMB, cb.sohieumb)]->soday_MB || lMB.nodeMB[nodeout]->sohang_MB < lMB.nodeMB[search(lMB, cb.sohieumb)]->sohang_MB)
				{
					Alert("SO DAY, SO HANG PHAI >= SO DAY, SO HANG MAY BAY HIEN TAI", 60, MAXYCONSOLE-3, 2);
					gotoxy(165, 19);cout << "        ";
					goto SOHIEUMAYBAY;
				}
				else {

					strcpy(cbtemp.sohieumb, lMB.nodeMB[nodeout]->sohieu_MB);

					if (checkTonTaiVe(cb) == 1)
					{
						strcpy(cbtemp.sanbayDen, cb.sanbayDen);
						gotoxy(165, 21);
						cout << cbtemp.sanbayDen;
						goto NGAY;
					}
					else {

						goto NOIDEN;
					}
				}
			}
			}
			if (key == TAB) {
				strcpy(cbtemp.sohieumb, cb.sohieumb);
				SetColor(Color_Blue);
				cout << cbtemp.sohieumb;

				if (checkTonTaiVe(cb) == 1)
				{
					strcpy(cbtemp.sanbayDen, cb.sanbayDen);
					gotoxy(165, 21);
					cout << cbtemp.sanbayDen;
					goto NGAY;
				}
				else {
					goto NOIDEN;
				}

			}
			if (key == ESC) {

				gotoxy(50, MAXYCONSOLE-3);
				SetBGColor(Color_DarkWhite);
				cout << "                                                            ";
				SetColor(Color_DarkRed);
				SetBGColor(Color_DarkWhite);
				gotoxy(76, MAXYCONSOLE-3);
				cout << "BAN CO CHAC CHAN HUY?";
				int cofirm = GetKey();
				gotoxy(76, MAXYCONSOLE-3);
				SetBGColor(Color_DarkWhite);
				cout << "                                                            ";
				if (cofirm == ENTER) {
					return 0;
				}
			}
}
		
	NOIDEN:/// NHAP SAN BAY DEN
		coverOutDataSHMB(lMB);
		SetColor(Color_DarkRed);
		SetBGColor(Color_White);
		gotoxy(55, 47);
		cout << "                                                           ";
		gotoxy(55, 48);
		cout << "                   NHAP SAN BAY DEN                        ";
		gotoxy(55, 49);
		cout << "                                                           ";
		frameSanbayDen();
		vitri = 0;
		while (1) {
			gotoxy(165 + vitri, 21);
			SetColor(Color_Blue);
			SetBGColor(Color_DarkWhite);
			key = GetKey();
			if (((key >= 'A' && key <= 'Z') || (key >= 'a' && key <= 'z')) && (vitri < 4)) {
				cbtemp.sanbayDen[vitri] = toupper((char)key);
				cout << cbtemp.sanbayDen[vitri];
				vitri++;
			}
			if (key == BACKSPACE && vitri > 0) {
				vitri--;
				gotoxy(165 + vitri, 21);
				SetColor(Color_DarkRed);
				cout << " ";
			}
			if (key == ESC) {
				gotoxy(50, MAXYCONSOLE-3);
				SetBGColor(Color_DarkWhite);
				cout << "                                                            ";
				SetColor(Color_DarkRed);
				SetBGColor(Color_DarkWhite);
				gotoxy(76, MAXYCONSOLE-3);
				cout << "BAN CO CHAC CHAN HUY?";
				int cofirm = GetKey();
				if (cofirm == ENTER) {
					gotoxy(76, MAXYCONSOLE-3);
					SetBGColor(Color_DarkWhite);
					cout << "                                                            ";
					return 0;
				}
				gotoxy(76, MAXYCONSOLE-3);
				SetBGColor(Color_DarkWhite);
				cout << "                                                            ";
			}
			if (key == ENTER) {
				cbtemp.sanbayDen[vitri] = '\0';
				if (cbtemp.sanbayDen[0] == '\0') {
					Alert("CHUA NHAP NOI DEN", 73, MAXYCONSOLE-3, 2);
					goto NOIDEN;
				}
				else if (checkNoiDen(cbtemp.sanbayDen) < 0) {
					Alert("NOI DEN KHONG HOP LE!", 73, MAXYCONSOLE-3, 2);
					gotoxy(165, 21);
					SetColor(Color_DarkRed);cout << "         ";
					goto NOIDEN;
				}
				else {
					goto NGAY;
				}
			}
			if (key == TAB) {
				strcpy(cbtemp.sanbayDen, cb.sanbayDen);
				gotoxy(165,21);
				cout << cbtemp.sanbayDen;
				goto NGAY;
			}
		}
	NGAY://NHAP NGAY KHOI HANH

		SetColor(Color_DarkRed);
		SetBGColor(Color_White);
		gotoxy(55, 47);
		cout << "                                                                ";
		gotoxy(55, 48);
		cout << " CU PHAP: dd/mm/yyyy. NEU NGAY,THANG < 10 THI THEM 0 PHIA TRUOC ";
		gotoxy(55, 49);
		cout << "                                                                ";
		vitri = 0;
		char ngaytemp[3];
		char thangtemp[3];
		char namtemp[5];
		char ddmmyy[11];
		while (1) {
			gotoxy(158 + vitri, 23);
			SetBGColor(Color_DarkWhite);
			SetColor(Color_Blue);
			fflush(stdin);
			key = GetKey();
			if (((key >= '0' && key <= '9') || key == '/') && vitri < 10) {
				ddmmyy[vitri] = (char)key;
				cout << ddmmyy[vitri];
				vitri++;
			}
			if (key == BACKSPACE && vitri > 0) {
				vitri--;
				gotoxy(158 + vitri, 23);SetColor(Color_DarkRed);
				cout << " ";

			}if (key == ENTER) {
				ddmmyy[vitri] = '\0';
				if (ddmmyy[0] == '\0') {
					Alert("CHUA NHAP NGAY KHOI HANH", 72, MAXYCONSOLE-3, 2);
					goto NGAY;
				}
				else {
					ngaytemp[0] = ddmmyy[0];ngaytemp[1] = ddmmyy[1];
					thangtemp[0] = ddmmyy[3];thangtemp[1] = ddmmyy[4];
					namtemp[0] = ddmmyy[6];namtemp[1] = ddmmyy[7];namtemp[2] = ddmmyy[8];namtemp[3] = ddmmyy[9];
					cbtemp.ngaygioStart.day = atoi(ngaytemp);
					cbtemp.ngaygioStart.month = atoi(thangtemp);
					cbtemp.ngaygioStart.year = atoi(namtemp);
					if (checkYear(cbtemp.ngaygioStart.year) != true || checkMonth(cbtemp.ngaygioStart.month) != true || checkDay(cbtemp.ngaygioStart.day, cbtemp.ngaygioStart.month) != true) {
						Alert("NGAY KHOI HANH KHONG DUNG", 71, MAXYCONSOLE-3, 2);
						SetColor(Color_DarkRed);
						gotoxy(158, 23);
						cout << "          ";
						goto NGAY;
					}
					else if (checkCurrentDDMMYY(cbtemp.ngaygioStart.day, cbtemp.ngaygioStart.month) != true) {
						Alert("NGAY PHAI LON HON NGAY HIEN TAI", 70, MAXYCONSOLE-3, 2);
						SetColor(Color_DarkRed);
						gotoxy(158, 23);
						cout << "          ";
						goto NGAY;
					}
					SetBGColor(Color_DarkWhite);
					gotoxy(55, 47);
					cout << "                                                                    ";
					gotoxy(55, 48);
					cout << "                                                                    ";
					gotoxy(55, 49);
					cout << "                                                                    ";
					goto GIO;
				}
			}
			if (key == ESC) {
				gotoxy(50, MAXYCONSOLE-3);

				SetBGColor(Color_DarkWhite);
				cout << "                                                            ";
				SetColor(Color_DarkRed);
				SetBGColor(Color_DarkWhite);
				gotoxy(76, MAXYCONSOLE-3);
				cout << "BAN CO CHAC CHAN HUY?";
				int cofirm = GetKey();
				if (cofirm == ENTER) {
					gotoxy(76, MAXYCONSOLE-3);
					SetBGColor(Color_DarkWhite);
					cout << "                                                            ";
					return 0;
				}
				gotoxy(76, MAXYCONSOLE-3);
				SetBGColor(Color_DarkWhite);
				cout << "                                                            ";
			}
			if (key == TAB) {
				cbtemp.ngaygioStart.day = cb.ngaygioStart.day;
				cbtemp.ngaygioStart.month = cb.ngaygioStart.month;
				cbtemp.ngaygioStart.year = cb.ngaygioStart.year;
				gotoxy(158,23);
				cout << cbtemp.ngaygioStart.day << "/" << cbtemp.ngaygioStart.month << "/" << cbtemp.ngaygioStart.year;
				goto GIO;
			}
		}

	GIO:///////// NHAP GIO KHOI HANH

		SetColor(Color_DarkRed);
		SetBGColor(Color_White);
		gotoxy(55, 47);
		cout << "                                                                ";
		gotoxy(55, 48);
		cout << " CU PHAP: hh:mm. NEU GIO, PHUT NHO HON 10 THI THEM 0 PHIA TRUOC ";
		gotoxy(55, 49);
		cout << "                                                                ";
		vitri = 0;
		char giotemp[3];
		char phuttemp[3];
		char hhmm[6];
		while (1) {
			gotoxy(160 + vitri, 25);
			SetBGColor(Color_DarkWhite);
			SetColor(Color_Blue);
			fflush(stdin);
			key = GetKey();
			if (((key >= '0' && key <= '9') || key == ':') && vitri < 5) {
				hhmm[vitri] = (char)key;
				cout << hhmm[vitri];
				vitri++;
			}
			if (key == BACKSPACE && vitri > 0) {
				vitri--;
				gotoxy(160 + vitri, 25);SetColor(Color_DarkRed);
				cout << " ";

			}if (key == ENTER) {
				hhmm[vitri] = '\0';
				if (ddmmyy[0] == '\0') {
					Alert("CHUA NHAP GIO KHOI HANH", 72, MAXYCONSOLE-3, 2);
					goto GIO;
				}
				else {
					giotemp[0] = hhmm[0];giotemp[1] = hhmm[1];
					phuttemp[0] = hhmm[3];phuttemp[1] = hhmm[4];
					cbtemp.ngaygioStart.hours = atoi(giotemp);
					cbtemp.ngaygioStart.minutes = atoi(phuttemp);
					if (cbtemp.ngaygioStart.hours < 5 || cbtemp.ngaygioStart.hours>23 || cb.ngaygioStart.minutes < 0 || cb.ngaygioStart.minutes>59) {
						Alert("GIO KHOI HANH KHONG DUNG", 71, MAXYCONSOLE-3, 2);
						SetColor(Color_DarkRed);
						gotoxy(160, 25);
						cout << "     ";
						goto GIO;
					}
					else if (checkTrungChuyenbayEdit(lCB, cbtemp, cb) == false) {
						Alert("CHUYEN BAY BI TRUNG NGAY GIO KHOI HANH. KIEM TRA LAI THONG TIN", 55, MAXYCONSOLE-3, 4);
						SetColor(Color_DarkRed);
						gotoxy(160, 25);
						cout << "     ";
						goto GIO;

					}
					SetBGColor(Color_DarkWhite);
					gotoxy(55, 47);
					cout << "                                                                    ";
					gotoxy(55, 48);
					cout << "                                                                    ";
					gotoxy(55, 49);
					cout << "                                                                    ";
					goto TRANGTHAI;
				}
			}
			if (key == ESC) {
				gotoxy(50, MAXYCONSOLE-3);
				SetBGColor(Color_DarkWhite);
				cout << "                                                            ";
				SetColor(Color_DarkRed);
				SetBGColor(Color_DarkWhite);
				gotoxy(76, MAXYCONSOLE-3);
				cout << "BAN CO CHAC CHAN HUY?";
				int cofirm = GetKey();
				if (cofirm == ENTER) {
					gotoxy(76, MAXYCONSOLE-3);
					SetBGColor(Color_DarkWhite);
					cout << "                                                            ";
					return 0;
				}
				gotoxy(76, MAXYCONSOLE-3);
				SetBGColor(Color_DarkWhite);
				cout << "                                                            ";
			} if (key == TAB) {
				cbtemp.ngaygioStart.hours = cb.ngaygioStart.hours;
				cbtemp.ngaygioStart.minutes = cb.ngaygioStart.minutes;
						if (checkTrungChuyenbayEdit(lCB, cbtemp, cb) == false) {
						Alert("CHUYEN BAY BI TRUNG NGAY GIO KHOI HANH. KIEM TRA LAI THONG TIN", 55, MAXYCONSOLE-3, 4);
						SetColor(Color_DarkRed);
						gotoxy(160, 25);
						cout << "     ";
						goto GIO;

					}				
				cout << cbtemp.ngaygioStart.hours << ":" << cbtemp.ngaygioStart.minutes;
				goto TRANGTHAI;
			}
		}
	TRANGTHAI:
		SetColor(Color_DarkRed);
		SetBGColor(Color_White);
		gotoxy(55, 47);
		cout << "                                                                ";
		gotoxy(55, 48);
		cout << "     0 - HUY CHUYEN | 1 - CON VE | 2 - HET VE | 3 - HOAN TAT    ";
		gotoxy(55, 49);
		cout << "                                                                ";
		vitri = 0;
		char trangthaitemp[2];
		while (1) {
			SetBGColor(Color_DarkWhite);
			SetColor(Color_Blue);
			gotoxy(160, 27);
			fflush(stdin);
			key = GetKey();
			if (((key >= '0' && key <= '9')) && vitri < 2) {
				trangthaitemp[vitri] = (char)key;
				cout << trangthaitemp[vitri];
				vitri++;
			}
			if (key == BACKSPACE && vitri > 0) {
				vitri--;
				gotoxy(160 + vitri, 27);SetColor(Color_DarkRed);
				cout << " ";
			}
			if (key == ENTER) {
				trangthaitemp[vitri] = '\0';
				if (trangthaitemp[0] == '\0') {
					Alert("CHUA NHAP TRANG THAI", 72, MAXYCONSOLE-3, 2);
					goto TRANGTHAI;
				}
				else {
					cbtemp.trangthai = atoi(trangthaitemp);
					if (cbtemp.trangthai < 0 || cbtemp.trangthai>3) {
						Alert("TRANG THAI KHONG HOP LE", 73, MAXYCONSOLE-3, 2);
						gotoxy(160, 27);cout << "   ";
						goto TRANGTHAI;
					}
					gotoxy(160, 27);cout << staTus[cbtemp.trangthai];
					goto ENDp;
				}
			}if (key == TAB) {
				cbtemp.trangthai = cb.trangthai;
				gotoxy(160, 27);cout << staTus[cbtemp.trangthai];
				goto ENDp;
			}

		}



	ENDp:
		//	SetColor(Color_Blue);
		cbtemp.soluongVe = (lMB.nodeMB[search(lMB, cbtemp.sohieumb)]->soday_MB * lMB.nodeMB[search(lMB, cbtemp.sohieumb)]->sohang_MB);
		//	gotoxy(82,dongStartCB+dem);cout<<cb.soluongVe;
		return 1;

	
}

int editCB(List_CB & listCB, List_MB & listMB) {
	if (listCB.pHead == NULL) {
		Alert("DANH SACH CHUYEN BAY RONG", 72, MAXYCONSOLE-3, 1);
		return 0;
	}
	else {
		string temp = "";
		char maCB[15];
	NHAP:
		SetColor(Color_DarkRed);
		SetBGColor(Color_DarkWhite);
		ShowCur(true);
		
		SetBGColor(Color_DarkWhite);
		int key;
		while(1){
			
			gotoxy(135,8);		cout<<"NHAP ENTER DE NHAP MA CAN XOA";
			gotoxy(135,9);		cout<<"ESC DE THOAT";
			key = GetKey();
			switch(key){
				case ENTER: {
					SetColor(Color_Back);
					vekhungdoi(135,10,4,30);	kengangdoi(135,12,30);
					gotoxy(142,11); 			cout<<"SO HIEU MAY BAY";
					NhapLieu(150,13, temp, 15);
					temp.copy(maCB,15);
					Node_CB* p, * q;
					p = searchInfo(listCB, maCB);
					if (p == NULL) {
						gotoxy(140, 16);SetColor(Color_Back);
						cout << "KHONG TIM THAY CHUYEN BAY!";
			//			gotoxy(140, 17);
			//			cout << "KIEM TRA LAI MA CHUYEN BAY";
						getch();
						goto NHAP;
//						SetColor(Color_DarkRed);
//						gotoxy(140, 16);
//						cout << "BAN CO MUON NHAP LAI?";
//						nhaplai:
//						int key = GetKey();
//						if(key!=ENTER&&key!=ESC){
//							goto nhaplai;
//							}
//						if (key == ENTER) {
//							gotoxy(149, 12);cout << "            ";
//							gotoxy(132, 16);cout << "|                                         |";
//							goto NHAP;
//						}
//						else if (key == ESC) {
//							gotoxy(149, 12);cout << "            ";
//							gotoxy(132, 16);cout << "|                                         |";
//							return 0;
//						}
					}
					if(p->data.trangthai==3){
						Alert2("KHONG THE CHINH SUA CHUYEN BAY DA HOAN TAT", 132,16,3);
//						return 0;
						goto NHAP;
						}
					else {
			
						CHUYENBAY cbtemp = p->data;
//						frameTitelEditCB2();addInfo_CB(listCB, listMB, cb
//						if (updateInfo_CB(listCB, listMB, p->data, cbtemp) == 0) {
						if (addInfo_CB(listCB, listMB, p->data) == 0) {
							Alert("DA HUY", 82, MAXYCONSOLE-3, 0);
							return 0;
						}
						else {
//							int key1;
							
								
//							
//							SetColor(Color_Back);
//							SetBGColor(Color_Cyan);
//							gotoxy(132, 32);cout << "             LUU THAY DOI?                 ";
//							
//							SetColor(Color_White);
//							SetBGColor(Color_DarkRed);
//							gotoxy(139, 34); cout << " ESC ";
//			
//							SetColor(Color_DarkYellow);
//							SetBGColor(Color_Back);
//							gotoxy(143, 34); cout << ":EXIT";
//			
//							// ok
//							SetColor(Color_White);
//							SetBGColor(Color_DarkGreen);
//							gotoxy(160, 34); cout << " ENTER ";
//			
//							SetColor(Color_DarkYellow);
//							SetBGColor(Color_Back);
//							gotoxy(167, 34); cout << ":OK";
//							SetBGColor(Color_DarkWhite);
//							nhaplai1:
//							 key1 = GetKey();
//							 if(key1!=ENTER && key1!=ESC){
//							 	goto nhaplai1;
//							 	}
//							SetColor(Color_DarkRed);SetBGColor(Color_DarkWhite);
//							gotoxy(132, 32);cout << "                                           ";
//							gotoxy(132, 33);cout << "                                           ";
//							gotoxy(132, 34);cout << "                                           ";
//							if (key1 == ENTER) {
//								strcpy(p->data.ma_CB, cbtemp.ma_CB);
//								strcpy(p->data.sohieumb, cbtemp.sohieumb);
//								strcpy(p->data.sanbayDen, cbtemp.sanbayDen);
//								p->data.ngaygioStart.day = cbtemp.ngaygioStart.day;
//								p->data.ngaygioStart.month = cbtemp.ngaygioStart.month;
//								p->data.ngaygioStart.year = cbtemp.ngaygioStart.year;
//								p->data.ngaygioStart.hours = cbtemp.ngaygioStart.hours;
//								p->data.ngaygioStart.minutes = cbtemp.ngaygioStart.minutes;
//								p->data.trangthai = cbtemp.trangthai;							
					///////////////////////////////////////////	 tao lai danh sach ve moi
								p->data.nodeVe= new VE[p->data.soluongVe];
									int sove = 0;
								for (int i = 0;i < listMB.nodeMB[search(listMB, p->data.sohieumb)]->soday_MB;i++) {
									for (int j = 1;j <= listMB.nodeMB[search(listMB, p->data.sohieumb)]->sohang_MB;j++) {
										ostringstream convert;convert << j;
										if (j < 10) {
											p->data.nodeVe[sove].soghe = sttday[i] + "0" + convert.str();
										}
										else {
											p->data.nodeVe[sove].soghe = sttday[i] + convert.str();
										}
										p->data.nodeVe[sove].cmnd = " ";
										sove++;
									}
								}
			//		//////////////////////////////////////////////////// ket thuc tao lai danh sach ve moi
			//		//////////////////////////////////////////// copy du lieu tren moi ve o danh sach ve cu sang moi ve o danh sach ve moi
								if(checkTonTaiVe11(cbtemp)!=0){//neu chuyen bay co nguoi dat ve roi thi copy du lieu, khong thi thoi
									for(int i=0;i<cbtemp.soluongVe;i++){// duyet danh sach ve cu..
										if(cbtemp.nodeVe[i].cmnd!=" "){//neu tai ve do da co nguoi dat roi (da co thong tin cmnd)...
											for(int j=0; j<p->data.soluongVe;j++){// duyet het danh sach ve moi
												if(cbtemp.nodeVe[i].soghe==p->data.nodeVe[j].soghe){// neu so ghe cu bang so ghe moi thi copy du lieu sang ve moi
													p->data.nodeVe[j].cmnd=cbtemp.nodeVe[i].cmnd;
												}
											}
										}
									}
								}
								delete [] cbtemp.nodeVe;
								cbtemp.nodeVe=p->data.nodeVe;
								cbtemp.soluongVe=p->data.soluongVe;		
					/////////////////////////////////////////// ket thuc copy du lieu		
								showList_CB(listCB);
								Alert2("DA CAP NHAT LAI THONG TIN", 139, 35, 3);
//							}
//							else if (key1 == ESC) {
//								Alert2("DA HUY", 150, MAXYCONSOLE-3, 2);
//								return 0;
//							}
						}
					}
				}
			}
		}
	}
}

// them node chuyen bay cho List chuyen bay
int addList_CB(List_CB & listCB, List_MB & listMB) {
//	frameAdd_CB();header();
	CHUYENBAY cb;
//	cb.ma_CB = '';
	string temp = "";
	temp.copy(cb.ma_CB, 15);
	int key; 
	if (listMB.soluong == 0) {
		clrscr();
		header();
		footer();
		Alert(" CHUA CO MAY BAY DE MO CHUYEN BAY", 58, MAXYCONSOLE-3, 2);
		return 0;
	}
	else {

		showList_CB(listCB);
		do {
			key = GetKey();
			switch(key){
				case F1: 
				{
					if (addInfo_CB(listCB, listMB, cb) == 0) {// kiem tra co huy trong qua trinh nhap hay khong
						Alert("DA HUY", 83, MAXYCONSOLE-3, 2);
						//return 0;
						break;
					}
					else {//neu khong huy...
						Node_CB* p = createNodeCB(cb);
						///// cap phat vung nho cho danh sach ve va dat so ghe cho moi ve
						p->data.nodeVe = new VE[p->data.soluongVe];
						int sove = 0;
						for (int i = 0;i < listMB.nodeMB[search(listMB, p->data.sohieumb)]->soday_MB;i++) {
							for (int j = 1;j <= listMB.nodeMB[search(listMB, p->data.sohieumb)]->sohang_MB;j++) {
								ostringstream convert;convert << j;
								if (j < 10) {
									p->data.nodeVe[sove].soghe = sttday[i] + "0" + convert.str();
								}
								else {
									p->data.nodeVe[sove].soghe = sttday[i] + convert.str();
								}
								p->data.nodeVe[sove].cmnd = " ";
								sove++;
							}
						}
						////////////////////////////////////////////////////		
						if (listCB.pHead == NULL) {//kiem tra xem dach rong hay kh
							listCB.pHead = p;  //neu rong thi them vao dau danh sach
						}
						else { // neu co phan tu roi thi insertorder
							Node_CB* temp = NULL, * q;
							for (q = listCB.pHead;q != NULL && strcmp(q->data.ma_CB, p->data.ma_CB) <= 0;q = q->pNext) {
								temp = q;
							}
							if (temp == NULL) {// neu tim duoc vi tri dau tien
								p->pNext = listCB.pHead;
								listCB.pHead = p;  // them vao dau luc nay p la phan tu dau
							}
							else {
								p->pNext = q;
								temp->pNext = p; //neu khong thi them sau node temp
							}
						}
						showList_CB(listCB);
						SetBGColor(Color_DarkWhite);
						cout.fill(' ');
						gotoxy(positionX_listCB,40); cout<<setw(122)<<' ';
						gotoxy(positionX_listCB,41); cout<<setw(122)<<' ';
						gotoxy(positionX_listCB,42); cout<<setw(122)<<' ';
						gotoxy(positionX_listCB,43); cout<<setw(122)<<' ';
						gotoxy(positionX_listCB,44); cout<<setw(122)<<' ';
//						vekhungdoi()
						Alert("DA THEM CHUYEN BAY THANH CONG", 70, MAXYCONSOLE-3, 5);
						break;
					}
				}
				case -61: {
					DeleteCB(listCB);
					break;
				}
				case -62:{
					editCB(listCB, listMB);
					break;
				}
				case ESC: {
					return 1;
				}			
			}

//			key = frameAddNext();//thay nhap tiep and delete
//			frameCoverNotice();
//			SetColor(Color_Yellow);
//			SetBGColor(Color_DarkPink);
//			gotoxy(55, MAXYCONSOLE-4);
//			cout << "                   BAN CO MUON THEM TIEP?                  ";
//			key = GetKey();
//			SetBGColor(Color_DarkWhite);
////			gotoxy(55, 47);
////			cout << "                                                                    ";
////			gotoxy(55, 48);
////			cout << "                                                                    ";
//			gotoxy(55, MAXYCONSOLE-4);
//			cout << "                                                                    ";
		} while (key != ESC);
	}
}
int addListCBFile(List_CB  &listCB, List_MB listMB, Node_CB *p) {
//	Node_CB* p = createNodeCB(cb);

	if (listCB.pHead == NULL) {//kiem tra xem dach rong hay kh
		listCB.pHead = p;  //neu rong thi them vao dau danh sach
	}
	else { // neu co phan tu roi thi insertorder
		Node_CB* temp = NULL, * q;
		for (q = listCB.pHead;q != NULL && strcmp(q->data.ma_CB, p->data.ma_CB) <= 0;q = q->pNext) {
			temp = q;
		}
		if (temp == NULL) {// neu tim duoc vi tri dau tien
			p->pNext = listCB.pHead;
			listCB.pHead = p;  // them vao dau luc nay p la phan tu dau
		}
		else {
			p->pNext = q;
			temp->pNext = p; //neu khong thi them sau node temp
		}
	}

}

int saveFileList_CB(List_CB lcb){
	ofstream fileCbOut ("Danhsachchuyenbay.txt");
	for(Node_CB *p=lcb.pHead;p!=NULL;p=p->pNext){
		fileCbOut << p->data.ma_CB<<" ";
		fileCbOut << p->data.sohieumb<<" ";
		fileCbOut << p->data.sanbayDen<<" ";
		fileCbOut << p->data.ngaygioStart.day<<"/"<<p->data.ngaygioStart.month<<"/"<<p->data.ngaygioStart.year<<" ";
		fileCbOut << p->data.ngaygioStart.hours<<":"<<p->data.ngaygioStart.minutes<<" ";
		fileCbOut << p->data.soluongVe<<" ";
		fileCbOut << p->data.trangthai<<" ";
		for(int i=0;i<p->data.soluongVe;i++){
			fileCbOut<<p->data.nodeVe[i].soghe<<"-"<<p->data.nodeVe[i].cmnd<<",";
		}
		if(p->pNext!=NULL){
		fileCbOut<<endl;	
		}
		
	}
	fileCbOut.close();
}
int docFileInfo1CB(ifstream &fileCbIn,CHUYENBAY &cb){
	string data;
	getline(fileCbIn,data,' ');	strcpy(cb.ma_CB,data.c_str());//doc tu dau den " " lay ma chuyen bay
	getline(fileCbIn,data,' '); strcpy(cb.sohieumb,data.c_str());//tiep tuc doc den " " lay SHMB
	getline(fileCbIn,data,' '); strcpy(cb.sanbayDen,data.c_str());//tiep tuc doc den " " lay san bay den
	getline(fileCbIn,data,'/');cb.ngaygioStart.day= atoi(data.c_str());//doc den dau / lay ngay
	getline(fileCbIn,data,'/');cb.ngaygioStart.month= atoi(data.c_str());//doc den dau/ lay thang
	getline(fileCbIn,data,' ');cb.ngaygioStart.year =atoi(data.c_str());
	getline(fileCbIn,data,':');cb.ngaygioStart.hours= atoi(data.c_str());
	getline(fileCbIn,data,' ');cb.ngaygioStart.minutes= atoi(data.c_str());
	getline(fileCbIn,data,' ');cb.soluongVe= atoi(data.c_str());
	getline(fileCbIn,data,' ');cb.trangthai= atoi(data.c_str());

/// luu danh sach ve
	cb.nodeVe= new VE[cb.soluongVe];
//	getline(fileCbIn,data);//xuong dong
		for(int i=0;i<cb.soluongVe;i++){
		getline(fileCbIn,cb.nodeVe[i].soghe,'-');
		getline(fileCbIn,cb.nodeVe[i].cmnd,',');
	}
//	getline(fileCbIn,data);
	
}


int openFileList_CB(List_CB &lcb,List_MB lmb){
	ifstream fileCbIn("Danhsachchuyenbay.txt");
	string temp;
	while(!fileCbIn.eof()){
		CHUYENBAY cb;
		Node_CB *q= createNodeCB(cb);	
		docFileInfo1CB(fileCbIn,q->data);
		if (checkTrangThai(q->data.ngaygioStart.day,q->data.ngaygioStart.month) == false)
		{
			q->data.trangthai = 3;
		}
		addListCBFile(lcb,lmb,q);
		getline(fileCbIn,temp);
	}
	fileCbIn.close();
}


///////////////////////////////////////////////////////////////////// HANH KHACH //////////////////////////////////////////////////////////////////

int showInfoHK(HANHKHACH hk, int y, string soghe) {
	gotoxy(6, dongStartHK + y);cout << "|_______|___________|______________|____________________|___________|";
	gotoxy(8, dongStartHK + y);cout << (y + 1);     //   A21        215445446         Do Long            Nam
	gotoxy(18, dongStartHK + y);cout << soghe;
	gotoxy(29, dongStartHK + y);cout << hk.cmnd;
	gotoxy(47, dongStartHK + y);cout << hk.ho << " " << hk.ten;
	gotoxy(66, dongStartHK + y);cout << sex[hk.gioiTinh];
}
int showCustomerOfCbXXX(List_CB lcb, NODEHKPTR lhk){
	header();
	char macbtemp[15];
	showList_CB(lcb);
start:
	SetColor(Color_DarkRed);
	SetBGColor(Color_DarkWhite);

	gotoxy(140, 8);	cout << "+-------------------------+";
	gotoxy(140, 9);	cout << "|    NHAP MA CHUYEN BAY   |";
	gotoxy(132, 10);cout << "+-------+-------------------------+-------+";
	gotoxy(132, 11);cout << "|                                         |";
	gotoxy(132, 12);cout << "|-----------------------------------------|";
	
	gotoxy(150, 11);fflush(stdin);gets(macbtemp);strupr(macbtemp);
	gotoxy(30, 20);SetColor(Color_Blue);
//	cout << "DANG LOAD HANH KHACH CUA CHUYEN BAY....";
	int soluongchuyenbay=0;
	for (Node_CB* p = lcb.pHead; p != NULL;p = p->pNext){
		if(strcmp(p->data.ma_CB, macbtemp) == 0&&checkTonTaiVe11(p->data)!=0){//tim co chuyen bay va da co hanh khach
		frameCoverListCB2(32);
frameSanbayDen();
			soluongchuyenbay++;
			gotoxy(30, 20);SetColor(Color_Blue);
			cout << "                                       ";
			SetColor(Color_DarkRed);
			SetBGColor(Color_DarkWhite);
			gotoxy(132, 13);cout << "|********** THONG TIN CHUYEN BAY *********|";
			gotoxy(132, 14);cout << "|                                         |";
			gotoxy(132, 15);cout << "|    CHUYEN BAY:                          |";
			gotoxy(132, 16);cout << "|    NOI DEN:                             |";
			gotoxy(132, 17);cout << "|    NGAY DI:                             |";//thong bao
			gotoxy(132, 18);cout << "|    GIO DI:                              |";
			gotoxy(132, 19);cout << "|_________________________________________|";//esc enter
			gotoxy(28, 8);cout << " DANH SACH HANH KHACH ";
			gotoxy(6, 9); cout << "+-------+-----------+--------------+--------------------+-----------+";
			gotoxy(6, 10);cout << "|  STT  |   SO VE   |    SO CMND   |        HO TEN      |    PHAI   |";
			gotoxy(6, 11);cout << "+-------+-----------+--------------+--------------------+-----------+";
			SetColor(Color_DarkRed);	  	    //"|_______|___________|______________|____________________|___________|"					//	2154MAXYCONSOLE-3446
			SetBGColor(Color_DarkWhite);
			gotoxy(155, 15);cout << p->data.ma_CB;
			gotoxy(155, 16);cout << p->data.sanbayDen;
			////ngay
			if (p->data.ngaygioStart.day < 10) {
				gotoxy(153, 17);cout << "0";
				gotoxy(154, 17);cout << p->data.ngaygioStart.day << "/";
			}
			else {
				gotoxy(153, 17);cout << p->data.ngaygioStart.day << "/";
			}
			//thang
			if (p->data.ngaygioStart.month < 10) {
				gotoxy(156, 17);cout << "0";
				gotoxy(157, 17);cout << p->data.ngaygioStart.month << "/";
			}
			else {
				gotoxy(156, 17);cout << p->data.ngaygioStart.month << "/";
			}
			//nam
			gotoxy(159, 17);cout << p->data.ngaygioStart.year;
			//gio
			if (p->data.ngaygioStart.hours < 10) {
				gotoxy(154, 18);cout << "0";
				gotoxy(155, 18);cout << p->data.ngaygioStart.hours << ":";
			}
			else {
				gotoxy(154, 18);cout << p->data.ngaygioStart.hours << ":";
			}
			//phut
			if (p->data.ngaygioStart.minutes < 10) {
				gotoxy(157, 18);cout << "0";
				gotoxy(158, 18);cout << p->data.ngaygioStart.minutes;
			}
			else {
				gotoxy(157, 18);cout << p->data.ngaygioStart.minutes;
			}
			NODEHKPTR nodehk; int hang = 0;
			for (int i = 0;i < p->data.soluongVe;i++) {
				if (p->data.nodeVe[i].cmnd != " ") {
					nodehk = Search(lhk, p->data.nodeVe[i].cmnd);

					showInfoHK(nodehk->data, hang, p->data.nodeVe[i].soghe);
					hang++;
				}
			}			
		}    //ket thuc co chuyen bay va co hanh khach
		if(strcmp(p->data.ma_CB, macbtemp) == 0&&checkTonTaiVe11(p->data)==0){
			soluongchuyenbay++;
			Alert2("CHUA CO HANH KHACH DAT VE",142,18,2);
			return 0;
		}//

	}
			if(soluongchuyenbay==0){
					Alert2("MA CHUYEN BAY KHONG TON TAI",138,14,2);
		SetColor(Color_Back);
		SetBGColor(Color_Cyan);
		gotoxy(141, 21);cout << "BAN CO MUON NHAP LAI KHONG?";//gio phut
		SetColor(Color_White);
		SetBGColor(Color_DarkRed);
		gotoxy(139, 23); cout << " ESC ";

		SetColor(Color_DarkYellow);
		SetBGColor(Color_Back);
		gotoxy(143, 23); cout << ":EXIT";

		// ok
		SetColor(Color_White);
		SetBGColor(Color_DarkGreen);
		gotoxy(160, 23); cout << " ENTER ";

		SetColor(Color_DarkYellow);
		SetBGColor(Color_Back);
		gotoxy(167, 23); cout << ":OK";
		SetBGColor(Color_DarkWhite);
		int key = GetKey();
		gotoxy(132, 21);cout << "                                           ";
		gotoxy(132, 23);cout << "                                           ";
		if(key==ENTER){
			goto start;
		}else if(key==ESC){
		return 0;
		}
		}	
	
}
void LoadDataHanhKhach(NODEHKPTR &lhk)
{
    fstream Data;
//    HANHKHACH temp ;
    string line;
    
    Data.open("Danhsachhanhkhach.txt",ios::in);
    if (  !Data   )
        exit(1);
    
    if ( Data.peek() != EOF )
    {
    	//KhoiTaoTree(dsnv);
    	while ( getline(Data, line) ) {
    		
    		HANHKHACH temp;
			int i = 0;
			    
			istringstream iss(line);
			string s;
			while ( getline( iss, s, ',' ) ) {
			    	
				switch (i) {
			        	
			        case 0:
			        	temp.cmnd = s;
						break;
						
			        case 1:
			        	temp.ho=s;
			        	break;
			        	
			        case 2:
			        	temp.ten=s;
			        	break;
			        	
			        case 3:
			        	temp.gioiTinh=atoi(s.c_str());;
			        	break;
			        }
			        
			        i++;
			        
			    }
			
				InsertHanhKhach(lhk,temp);
			
    	}
    }
    
    Data.close();
    return;
}
void SaveData(fstream &Data, NODEHKPTR lhk) {
	
	if (lhk != NULL) {
		
		SaveData(Data, lhk->Left);
		
		HANHKHACH temp;
		temp = lhk->data;
		
		Data << temp.cmnd << ","
        << temp.ho << ","
        << temp.ten << ","
        << temp.gioiTinh<< endl;
        
        SaveData(Data, lhk->Right);
	}
	
}

void SaveDataHanhKhach(NODEHKPTR lhk)
{
	system("cls");

    fstream Data;
    Data.open("Danhsachhanhkhach.txt",ios::out);
    
    SaveData(Data, lhk);

    Data.close();
    return;
}


/////////////////////////////////////////////////////////////////// DAT VE /////////////////////////////////////////////////////////////////////
  // time_t baygio = time(0);
 //  tm *ltm = localtime(&baygio);
 /////test



//////
int checkConVe(CHUYENBAY cb) {
	int dem = 0;
	for (int i = 0;i < cb.soluongVe;i++) {
		if (cb.nodeVe[i].cmnd == " ")
			dem++;
	}
	return dem; //= 0 la het ve
}

int checkCoCMND(CHUYENBAY cb, string cmndtemp) {
	for (int i = 0;i < cb.soluongVe;i++) {
		if (cb.nodeVe[i].cmnd == cmndtemp) {
			return i;
		}
	}
	return -1;
}
int checkCoGHE(CHUYENBAY cb, string soghetemp) {
	for (int i = 0;i < cb.soluongVe;i++) {
		if (cb.nodeVe[i].soghe == soghetemp)
			return i;
	}
	return -1;
}
	
int bookTicket(List_CB & lCB, List_MB listMB, NODEHKPTR & lHK) {
	header();footer();
//	frameDatVe();
	SetBGColor(Color_DarkWhite);
//	char A[3][16] = {"abc","cde", "sfas"};
//	formInput(131,3,3,A);
	
	frameSanbayDen();
	SetColor(Color_DarkYellow);
	gotoxy(118,10);		cout<<"NOI DEN: ";
	gotoxy(118,12);		cout<<"THANG: ";
	gotoxy(138,12);		cout<<"NGAY: ";
	
	
	int vitri = 0;
	char noiden[4];
	int thang = 0;
	int ngay = 0;
	string chuoi = "";
	string thangtemp = "";
	string ngaytemp = "";
	do{
		do{
			SetColor(Color_Blue);
//			gotoxy(135, 10);
			fflush(stdin);
			NhapLieu(135,10,chuoi, 3);
			strcpy(noiden, chuoi.c_str());
			if (checkNoiDen(noiden) == -1) {
				gotoxy(125,11); SetColor(Color_DarkRed); cout<<"NOI DEN KHONG PHU HOP";
			}
		}while(checkNoiDen(noiden) == -1);
		gotoxy(125,11); SetColor(Color_DarkRed); 		 cout<<"                     ";
		do{
			SetColor(Color_Blue);
			NhapLieuso(128,12,thangtemp,2);
			stringstream str2num(thangtemp);
			str2num >> thang;
			if (checkMonth(thang) == false ) {
				gotoxy(118,13); SetColor(Color_DarkRed); cout<<"THANG KHONG HOP LE";
			}
		}while(checkMonth(thang) == false);
		gotoxy(118,13); SetColor(Color_DarkRed); 		 cout<<"                  ";
		do{
			SetColor(Color_Blue);
			NhapLieuso(148,12,ngaytemp,2);
			stringstream str2num(ngaytemp);
			str2num >> ngay;
			if (checkDay(ngay, thang) == false || checkCurrentDDMMYY(ngay, thang) == false) {
				gotoxy(138,13); SetColor(Color_DarkRed); cout<<"NGAY KHONG HOP LE";
			}
		}while(checkDay(ngay, thang) == false || checkCurrentDDMMYY(ngay, thang) == false);
		gotoxy(138,13); SetColor(Color_DarkRed); cout<<"                 ";
		// 	BANG CHUYEN BAY
		int A[6]={16,30,42,59,68,78};
		SetColor(Color_Back);
		table(positionX_listCB ,positionY_listCB , 30, 93, 6, A);
		gotoxy(positionX_listCB + 2, positionY_listCB + 1); 	cout<<"MA CHUYEN BAY";
		gotoxy(positionX_listCB + 18, positionY_listCB + 1); 	cout<<"SO HIEU MB";
		gotoxy(positionX_listCB + 33, positionY_listCB + 1); 	cout<<"NOI DEN";
		gotoxy(positionX_listCB + 44, positionY_listCB + 1); 	cout<<"NGAY KHOI HANH ";
		gotoxy(positionX_listCB + 61, positionY_listCB + 1); 	cout<<"GIO KH";
		gotoxy(positionX_listCB + 69, positionY_listCB + 1); 	cout<<" SO GHE";
		gotoxy(positionX_listCB + 81, positionY_listCB + 1); 	cout<<"TRANG THAI";
		// CAC MAY BAY BAY DEN NOI XXX NGAY XXX
		for (Node_CB* p = lCB.pHead;p != NULL;p = p->pNext) {
			if (strcmp(p->data.sanbayDen, noiden) == 0 && p->data.ngaygioStart.month == thang && p->data.ngaygioStart.day == ngay && checkConVe(p->data) != 0 && p->data.trangthai!=0) {
				showInfo_CB(p->data, vitri);
				vitri++;
			}
		}
		if (vitri == 0) {/////////////////////////////////////////////////////////////////////neu khong co chuyen bay nao hop le
			if (Hoi(118,18," KHONG CO CHUYEN BAY PHU HOP, NHAP LAI? ")) {
//				gotoxy(135, 10);cout << "   ";
//				gotoxy(128, 12);cout << "  ";
//				gotoxy(148, 12);cout << "  ";
			}else{
				return 0;
			}
		}
	}while(vitri == 0);
	// CO CHUYEN BAY THOA DIEU KIEN
	if (vitri != 0) {
		char macbtemp[15];
		Node_CB* p;
		string macb = "";
		do{
			
			gotoxy(118,14);	SetColor(Color_DarkYellow);	cout<<"NHAP MA CHUYEN BAY:";
			SetColor(Color_Blue);		NhapLieu(140,14,macb,15);
			strcpy(macbtemp, macb.c_str());
			p = searchInfo(lCB, macbtemp);
			if (p == NULL || p->data.ngaygioStart.day != ngay || p->data.ngaygioStart.month != thang || p->data.trangthai != 1) {
				gotoxy(130,15); SetColor(Color_DarkRed); cout<<"CHUYEN BAY KHONG HOP LE";
			}else showInfo_CB(p->data, 0);
			
		}while(p == NULL || p->data.ngaygioStart.day != ngay || p->data.ngaygioStart.month != thang || p->data.trangthai != 1);
			
		string cmndtemp;
		// NHAP CMND
		bool nhapCMND;
		NODEHKPTR nodehk;
		do{
			nhapCMND = true;
			gotoxy(118,16); SetColor(Color_DarkYellow);	cout<<"NHAP CMND:";
			SetColor(Color_Blue);		NhapLieuso(135,16, cmndtemp, 10);
			if(cmndtemp=="") return 0;
			nodehk = Search(lHK, cmndtemp);
			if (nodehk != NULL && checkCoCMND(p->data, cmndtemp) == -1) {//co hanh khach trong ds hanh khac va chua co trong ds ve cua chuyen bay thi cho dat ve
				
				// THONG TIN KHACH HANG DA CO TRONG DL
				SetColor(Color_DarkYellow);
				gotoxy(128, 26);cout << "THONG TIN KHACH HANG";
				gotoxy(118, 28);cout << "CMND:";
				gotoxy(118, 30);cout << "HO:";
				gotoxy(118, 32);cout << "TEN:";
				gotoxy(118, 34);cout << "GIOI TINH:";
				SetColor(Color_Blue);
				gotoxy(135, 28);cout << nodehk->data.cmnd;
				gotoxy(135, 30);cout << nodehk->data.ho;
				gotoxy(135, 32);cout << nodehk->data.ten;
				gotoxy(135, 34);cout << sex[nodehk->data.gioiTinh];
				// SO DO CHO NGOI
				clearOnePart(positionX_listCB,positionY_listCB -2, 95, 33 );	
				SetColor(Color_Back);
				int x = 10, y = positionY_listCB;
				int sonode = 0;
				gotoxy(25, 4);SetBGColor(Color_Cyan);cout << "EMPTY";
				gotoxy(35, 4);SetBGColor(Color_Yellow);cout << "BOOKED";
				for (int i = 0;i < listMB.nodeMB[search(listMB, p->data.sohieumb)]->soday_MB;i++) {
					for (int j = 0;j< listMB.nodeMB[search(listMB, p->data.sohieumb)]->sohang_MB;j++) {
						gotoxy(x, y);
						if (p->data.nodeVe[sonode].cmnd == " ") {
							SetBGColor(Color_Cyan);
							cout << p->data.nodeVe[sonode].soghe;
						}
						else {
							SetBGColor(Color_Yellow);
							cout << p->data.nodeVe[sonode].soghe;
						}
						sonode++;
						y++;
					}
					x += 10;y = positionY_listCB;
				}
				// CHON GHE
				bool xacThucVe;
				string soghetemp = "";
				do{
					xacThucVe = true;
					SetColor(Color_DarkYellow);
					SetBGColor(Color_DarkWhite);
					gotoxy(118, 36);cout << "NHAP SO GHE:";
					NhapLieu(135,36,soghetemp,3);
				
					if (checkCoGHE(p->data, soghetemp) == -1) {
						if(Hoi(118,18,"   SO GHE KHONG CO. NHAP LAI?    ")){
							xacThucVe = false;
						}else return 0;
					}
					else if (p->data.nodeVe[checkCoGHE(p->data, soghetemp)].cmnd != " ") {
						if(Hoi(118,18,"   GHE DA CO NGUOI DAT. NHAP LAI    ")){
							xacThucVe = false;
						}else return 0;
					}
					else {
						clearOnePart(111,7, 48, 29);
						thongTinVe();
						SetColor(Color_Blue);
						gotoxy(135, 10), cout << p->data.ma_CB;
						switch(checkNoiDen(p->data.sanbayDen)){
							case 0:
								{
									gotoxy(135, 12), cout << "HO CHI MINH";
									break;
								}
							case 1:
								{
									gotoxy(135, 12), cout << "HA NOI";
									break;
								}
							case 2:
								{
									gotoxy(135, 12), cout << "NHA TRANG";
									break;
								}
							case 3:
								{
									gotoxy(135, 12), cout << "PHU QUOC";
									break;
								}
							case 4:
								{
									gotoxy(135, 12), cout << "QUY NHON";
									break;
								}
							case 5:
								{
									gotoxy(135, 12), cout << "HAI PHONG";
									break;
								}
						}
						if (p->data.ngaygioStart.day < 10) {
							gotoxy(135, 14);cout << "0";
							gotoxy(136, 14);cout << p->data.ngaygioStart.day << "/";
						}
						else {
							gotoxy(135, 14);cout << p->data.ngaygioStart.day << "/";
						}
						//thang
						if (p->data.ngaygioStart.month < 10) {
							gotoxy(138, 14);cout << "0";
							gotoxy(139, 14);cout << p->data.ngaygioStart.month << "/";
						}
						else {
							gotoxy(138, 14);cout << p->data.ngaygioStart.month << "/";
						}
						//nam
						gotoxy(141, 14);cout << p->data.ngaygioStart.year;
						//gio
						if (p->data.ngaygioStart.hours < 10) {
							gotoxy(135, 16);cout << "0";
							gotoxy(136, 16);cout << p->data.ngaygioStart.hours << ":";
						}
						else {
							gotoxy(135, 16);cout << p->data.ngaygioStart.hours << ":";
						}
						//phut
						if (p->data.ngaygioStart.minutes < 10) {
							gotoxy(139, 16);cout << "0";
							gotoxy(140, 16);cout << p->data.ngaygioStart.minutes;
						}
						else {
							gotoxy(139, 16);cout << p->data.ngaygioStart.minutes;
						}
						gotoxy(135, 18); cout << soghetemp;
						gotoxy(128, 20); cout << nodehk->data.ho;
						gotoxy(148, 20); cout << nodehk->data.ten;
						gotoxy(135, 22); cout << nodehk->data.cmnd;
						gotoxy(135, 24); cout << sex[nodehk->data.gioiTinh];
						// XAC NHAN CO DAT VE HAY KHONG
						if (Hoi(118,26,"         BAN CO MUON DAT VE KHONG?         ")) {
							p->data.nodeVe[checkCoGHE(p->data, soghetemp)].cmnd = cmndtemp; /////////// DAT VE THANH CONG
							if(checkConVe(p->data)==0){
								p->data.trangthai=2;
							}							
							///////////////////////////////////////////// hien thi so do may bay///////////////////////////////		
							SetColor(Color_Back);
							int x = 10, y = positionY_listCB;
							int sonode = 0;
							for (int i = 0;i < listMB.nodeMB[search(listMB, p->data.sohieumb)]->soday_MB;i++) {
								for (int j = 0;j < listMB.nodeMB[search(listMB, p->data.sohieumb)]->sohang_MB;j++) {
									gotoxy(x, y);
									if (p->data.nodeVe[sonode].cmnd == " ") {
										SetBGColor(Color_Cyan);
										cout << p->data.nodeVe[sonode].soghe;
									}
									else {
										SetBGColor(Color_Yellow);
										cout << p->data.nodeVe[sonode].soghe;
									}
									sonode++;
									y++;
								}
								x += 10;y = positionY_listCB;
							}
							SetBGColor(Color_DarkWhite);
							gotoxy(128,28);		cout<<"DAT VE THANH CONG";
							GetKey();
							return 1;
						}
						else{
							SetBGColor(Color_DarkWhite);
							gotoxy(128,28);		cout<<"DA HUY VE";
							GetKey();
							return 0;
						}
					}
				}while(!xacThucVe);
			}
			// KHACH HANG DA MUA VE
			else if (checkCoCMND(p->data, cmndtemp) != -1) {
				if(Hoi(118,18,"    SO CMND NAY DA DAT VE. NHAP LAI?      ")){
					nhapCMND = false;
				}
				return 0;
			}
		}while(!nhapCMND);
		// KHACH HNAG CHUA CO THONG TIN
		if (nodehk == NULL && checkCoCMND(p->data, cmndtemp) == -1) {
			HANHKHACH hkmoi;
			string ho = "";		string ten = "";	string gioitinh = "";
		
			SetColor(Color_DarkYellow);
			gotoxy(128, 24);	cout << "THONG TIN KHACH HANG";
			gotoxy(118, 26);	cout << "CMND:";
			gotoxy(118, 28);	cout << "HO:";
			gotoxy(118, 30);	cout << "TEN:";
			gotoxy(118, 32);	cout << "GIOI TINH:";
			SetColor(Color_Blue);
			hkmoi.cmnd = cmndtemp;
			gotoxy(135, 26);	cout << hkmoi.cmnd;
		//nhap ho
			do{
				SetColor(Color_Blue);
				NhapLieu(135,28,ho,15);
				hkmoi.ho = ho;
				if(ho == "") return 0;
			}while(ho == "");
			
		//nhap ten
			do{
				NhapLieu(135,30,ten, 15);
				hkmoi.ten = ten;
				if(ten == "") return 0;
			}while(ten == "");
		// nhap gioi tinh
			do{
				NhapLieu(135,32,gioitinh,3);
				if(gioitinh =="NAM" || gioitinh == "NU"){
					hkmoi.gioiTinh = checkSex(gioitinh);
					gotoxy(120,33); cout<<"                               ";
				}
				else {
					gotoxy(120,33);		SetColor(Color_DarkRed);		cout<<"VUI LONG CHON GIOI TINH: NAM/NU";
					SetColor(Color_Blue);
				}
			}while(!(gioitinh =="NAM" || gioitinh == "NU"));

			//NODEHKPTR nodehk1= KiemTraHK(lHK,hkmoi.cmnd);
		///////////////////////////////////////////// hien thi so do may bay///////////////////////////////		
			clearOnePart(positionX_listCB,positionY_listCB -2, 95, 33 );
			SetColor(Color_Back);
			int x = 10, y = positionY_listCB;
			int sonode = 0;
			gotoxy(25, 4);SetBGColor(Color_Cyan);cout << "EMPTY";
			gotoxy(35, 4);SetBGColor(Color_Yellow);cout << "BOOKED";
			for (int i = 0;i < listMB.nodeMB[search(listMB, p->data.sohieumb)]->soday_MB;i++) {
				for (int j = 0;j < listMB.nodeMB[search(listMB, p->data.sohieumb)]->sohang_MB;j++) {
					gotoxy(x, y);
					if (p->data.nodeVe[sonode].cmnd == " ") {
						SetBGColor(Color_Cyan);
						cout << p->data.nodeVe[sonode].soghe;
					}
					else {
						SetBGColor(Color_Yellow);
						cout << p->data.nodeVe[sonode].soghe;
					}
					sonode++;
					y++;
				}
				x += 10;y = positionY_listCB;
			}
			// NHAP SO GHE CAN DAT 
			string soghetemp = "";
			bool xacThucVe;
			do{
				xacThucVe = true;
				SetColor(Color_DarkYellow);	SetBGColor(Color_DarkWhite);	gotoxy(118, 34);	cout << "NHAP SO GHE:";
				SetColor(Color_Blue); 	NhapLieu(135,34,soghetemp,4);
				// KHONG CO GHE TRONG DL
				if (checkCoGHE(p->data, soghetemp) == -1) {
					if(Hoi(118,18,"     SO GHE KHONG CO. NHAP LAI      ")){
						xacThucVe = false;
					}else return 0;
				}
				// CO NGUOI DAT GHE ROI
				else if (p->data.nodeVe[checkCoGHE(p->data, soghetemp)].cmnd != " ") {
					if(Hoi(118,18,"   GHE DA CO NGUOI DAT. NHAP LAI    ")){
						xacThucVe = false;
					}else return 0;
				}
				else {
					// XUAT THONG TIN CUA VE DANG DAT, XAC NHAN CO DAT VE HAY KHONG
					clearOnePart(111,7, 48, 29);
					thongTinVe();
					SetColor(Color_Blue);
					gotoxy(135, 10), cout << p->data.ma_CB;
					switch(checkNoiDen(p->data.sanbayDen)){
						case 0:
							{
								gotoxy(135, 12), cout << "HO CHI MINH";
								break;
							}
						case 1:
							{
								gotoxy(135, 12), cout << "HA NOI";
								break;
							}
						case 2:
							{
								gotoxy(135, 12), cout << "NHA TRANG";
								break;
							}
						case 3:
							{
								gotoxy(135, 12), cout << "PHU QUOC";
								break;
							}
						case 4:
							{
								gotoxy(135, 12), cout << "QUY NHON";
								break;
							}
						case 5:
							{
								gotoxy(135, 12), cout << "HAI PHONG";
								break;
							}
					}
					if (p->data.ngaygioStart.day < 10) {
						gotoxy(135, 14);cout << "0";
						gotoxy(136, 14);cout << p->data.ngaygioStart.day << "/";
					}
					else {
						gotoxy(135, 14);cout << p->data.ngaygioStart.day << "/";
					}
					//thang
					if (p->data.ngaygioStart.month < 10) {
						gotoxy(138, 14);cout << "0";
						gotoxy(139, 14);cout << p->data.ngaygioStart.month << "/";
					}
					else {
						gotoxy(138, 14);cout << p->data.ngaygioStart.month << "/";
					}
					//nam
					gotoxy(141, 14);cout << p->data.ngaygioStart.year;
					//gio
					if (p->data.ngaygioStart.hours < 10) {
						gotoxy(135, 16);cout << "0";
						gotoxy(136, 16);cout << p->data.ngaygioStart.hours << ":";
					}
					else {
						gotoxy(135, 16);cout << p->data.ngaygioStart.hours << ":";
					}
					//phut
					if (p->data.ngaygioStart.minutes < 10) {
						gotoxy(139, 16);cout << "0";
						gotoxy(140, 16);cout << p->data.ngaygioStart.minutes;
					}
					else {
						gotoxy(139, 16);cout << p->data.ngaygioStart.minutes;
					}
					////
					gotoxy(135, 18); cout << soghetemp;
					gotoxy(128, 20); cout << hkmoi.ho;
					gotoxy(148, 20); cout << hkmoi.ten;
					gotoxy(135, 22); cout << hkmoi.cmnd;
					gotoxy(135, 24); cout << sex[hkmoi.gioiTinh];
					// XAC NHAN CO DAT VE HAY KHONG
					if (Hoi(118,28,"        BAN CO MUON DAT VE KHONG?       ")) {
						p->data.nodeVe[checkCoGHE(p->data, soghetemp)].cmnd = cmndtemp; /////////// DAT VE THANH CONG
						InsertHanhKhach(lHK, hkmoi);
						if(checkConVe(p->data)==0){
							p->data.trangthai=2;
							}							
						///////////////////////////////////////////// hien thi so do may bay///////////////////////////////		
						SetColor(Color_Back);
						int x = 10, y = positionY_listCB;
						int sonode = 0;
						for (int i = 0;i < listMB.nodeMB[search(listMB, p->data.sohieumb)]->soday_MB;i++) {
							for (int j = 0;j < listMB.nodeMB[search(listMB, p->data.sohieumb)]->sohang_MB;j++) {
								gotoxy(x, y);
								if (p->data.nodeVe[sonode].cmnd == " ") {
									SetBGColor(Color_Cyan);
									cout << p->data.nodeVe[sonode].soghe;
								}
								else {
									SetBGColor(Color_Yellow);
									cout << p->data.nodeVe[sonode].soghe;
								}
								sonode++;
								y++;
							}
							x += 10;y = positionY_listCB;
						}
						SetBGColor(Color_DarkWhite);	SetColor(Color_DarkRed);
						gotoxy(128,28);		cout<<"DAT VE THANH CONG";
						GetKey();
						return 1;
					}
					else{
						SetBGColor(Color_DarkWhite);	SetColor(Color_DarkRed);
						gotoxy(128,28);		cout<<"DA HUY VE";
						GetKey();
						return 0;
					}//XAC NHAN DAT VE
				}//XUAT THONG TIN VE
			}while(!xacThucVe); //CHON VE
		}//KHACH HNAG CHUA CO THONG TIN
	}// NEU CO CHUYEN BAY XX NGAY XX
}
///////////////////////////////////////////////////////////////////////// xong dat ve ////////////////////////////////////////
//////////////////////////////////////////// huy ve ////////////////////////////////////////////
int cancelTicket(List_CB & lCB, List_MB listMB, NODEHKPTR & lHK) {
	header();footer();
	SetBGColor(Color_DarkWhite);
	frameSanbayDen();
	
noiden:
	char noiden[4];
	int thang = 0;
	int ngay = 0;
	string chuoi = "";
	string thangtemp = "";
	string ngaytemp = "";
	bool xacNhanNoiDen;
	int soCbDaDatVe = 0;
	Node_CB* cbDuyNhat;
	string cmndtemp;
	NODEHKPTR nodehkDatVe;
	do{
		xacNhanNoiDen = true;
		do{
			SetColor(Color_Blue);
			fflush(stdin);
			NhapLieu(135,10,chuoi, 3);
			strcpy(noiden, chuoi.c_str());
			if (checkNoiDen(noiden) == -1) {
				gotoxy(125,11); SetColor(Color_DarkRed); cout<<"NOI DEN KHONG PHU HOP";
			}
		}while(checkNoiDen(noiden) == -1);
		gotoxy(125,11); SetColor(Color_DarkRed); 		 cout<<"                     ";
		do{
			SetColor(Color_Blue);
			NhapLieuso(128,12,thangtemp,2);
			stringstream str2num(thangtemp);
			str2num >> thang;
			if (checkMonth(thang) == false ) {
				gotoxy(118,13); SetColor(Color_DarkRed); cout<<"THANG KHONG HOP LE";
			}
		}while(checkMonth(thang) == false);
		gotoxy(118,13); SetColor(Color_DarkRed); 		 cout<<"                  ";
		do{
			SetColor(Color_Blue);
			NhapLieuso(148,12,ngaytemp,2);
			stringstream str2num(ngaytemp);
			str2num >> ngay;
			if (checkDay(ngay, thang) == false || checkCurrentDDMMYY(ngay, thang) == false) {
				gotoxy(138,13); SetColor(Color_DarkRed); cout<<"NGAY KHONG HOP LE";
			}
		}while(checkDay(ngay, thang) == false || checkCurrentDDMMYY(ngay, thang) == false);
		gotoxy(138,13); SetColor(Color_DarkRed); cout<<"                 ";
		//NHAP CMND
		bool xacThucCMND;
		do{
			xacThucCMND = true;
			gotoxy(118,16); SetColor(Color_DarkYellow);	cout<<"NHAP CMND:";
			SetColor(Color_Blue);		NhapLieuso(135,16, cmndtemp, 10);
			if(cmndtemp=="") return 0;
			///// kiem tra khach hang co trong ds hanh khach chua, neu chua thi bao chu dat ve
			nodehkDatVe = Search(lHK, cmndtemp);
			if (nodehkDatVe == NULL) {
				if(Hoi(118,18,"  KHONG CO DU LIEU KHACH HANG.NHAP LAI?  ")){
					xacThucCMND = false;
				}else return 0;
			}
		}while(!xacThucCMND);					
		// CAC CHUYEN BAY THOA DIEU KIEN
		int A[6]={16,30,42,59,68,78};
		SetColor(Color_Back);
		table(positionX_listCB ,positionY_listCB , 30, 93, 6, A);
		gotoxy(positionX_listCB + 2, positionY_listCB + 1); 	cout<<"MA CHUYEN BAY";
		gotoxy(positionX_listCB + 18, positionY_listCB + 1); 	cout<<"SO HIEU MB";
		gotoxy(positionX_listCB + 33, positionY_listCB + 1); 	cout<<"NOI DEN";
		gotoxy(positionX_listCB + 44, positionY_listCB + 1); 	cout<<"NGAY KHOI HANH ";
		gotoxy(positionX_listCB + 61, positionY_listCB + 1); 	cout<<"GIO KH";
		gotoxy(positionX_listCB + 69, positionY_listCB + 1); 	cout<<" SO GHE";
		gotoxy(positionX_listCB + 81, positionY_listCB + 1); 	cout<<"TRANG THAI";
		
		for (Node_CB* p = lCB.pHead;p != NULL;p = p->pNext) {
			if (strcmp(p->data.sanbayDen, noiden) == 0 && p->data.ngaygioStart.month == thang && p->data.ngaygioStart.day == ngay && p->data.trangthai != 0 && p->data.trangthai != 3 && checkCoCMND(p->data, cmndtemp) >= 0) {
				cbDuyNhat = p;
				showInfo_CB(p->data, soCbDaDatVe);
				soCbDaDatVe++;
			}
		}
		if (soCbDaDatVe == 0) {
			if (Hoi(118,18," KHONG CO CHUYEN BAY PHU HOP, NHAP LAI? ")) xacNhanNoiDen = false;
			else return 0;
		}
	}while(!xacNhanNoiDen);
	
	if (soCbDaDatVe == 1) {////// neu hanh khach dat chi co 1 chuyen bay thi hien thi thong tin chuyen bay len form huy ve
//		cheFormDatVe(25);
		clearOnePart(positionX_listCB,positionY_listCB -2, 95, 33 );	
//		frameHuyVe1Cb();
		///////////////////////////////////////////// hien thi so do may bay///////////////////////////////		
		SetColor(Color_Back);
		int x = positionX_listCB, y = positionY_listCB;
		int sonode = 0;
		gotoxy(25, 4);SetBGColor(Color_Cyan);cout << "EMPTY";
		gotoxy(35, 4);SetBGColor(Color_Yellow);cout << "BOOKED";
		gotoxy(45, 4);SetBGColor(8);cout << "YOU";
		for (int i = 0;i < listMB.nodeMB[search(listMB, cbDuyNhat->data.sohieumb)]->soday_MB;i++) {
			for (int j = 0;j < listMB.nodeMB[search(listMB, cbDuyNhat->data.sohieumb)]->sohang_MB;j++) {
				gotoxy(x, y);
				if (cbDuyNhat->data.nodeVe[sonode].cmnd == " ") {
					SetBGColor(Color_Cyan);
					cout << cbDuyNhat->data.nodeVe[sonode].soghe;
				}
				else if (cbDuyNhat->data.nodeVe[sonode].cmnd == cmndtemp) {
					SetBGColor(8);
					cout << cbDuyNhat->data.nodeVe[sonode].soghe;
				}
				else {
					SetBGColor(Color_Yellow);
					cout << cbDuyNhat->data.nodeVe[sonode].soghe;
				}
				sonode++;
				y++;
			}
			x += 10;y = positionY_listCB;
		}
		//	THONG TIN VE MUON HUY
		clearOnePart(111,7, 48, 29);	
		thongTinVe();
		SetColor(Color_Blue);
		gotoxy(135, 10), cout << cbDuyNhat->data.ma_CB;
		switch(checkNoiDen(cbDuyNhat->data.sanbayDen)){
			case 0:
				{
					gotoxy(135, 12), cout << "HO CHI MINH";
					break;
				}
			case 1:
				{
					gotoxy(135, 12), cout << "HA NOI";
					break;
				}
			case 2:
				{
					gotoxy(135, 12), cout << "NHA TRANG";
					break;
				}
			case 3:
				{
					gotoxy(135, 12), cout << "PHU QUOC";
					break;
				}
			case 4:
				{
					gotoxy(135, 12), cout << "QUY NHON";
					break;
				}
			case 5:
				{
					gotoxy(135, 12), cout << "HAI PHONG";
					break;
				}
		}
		if (cbDuyNhat->data.ngaygioStart.day < 10) {
			gotoxy(135, 14);cout << "0";
			gotoxy(136, 14);cout << cbDuyNhat->data.ngaygioStart.day << "/";
		}
		else {
			gotoxy(135, 14);cout << cbDuyNhat->data.ngaygioStart.day << "/";
		}
		//thang
		if (cbDuyNhat->data.ngaygioStart.month < 10) {
			gotoxy(138, 14);cout << "0";
			gotoxy(139, 14);cout << cbDuyNhat->data.ngaygioStart.month << "/";
		}
		else {
			gotoxy(138, 14);cout << cbDuyNhat->data.ngaygioStart.month << "/";
		}
		//nam
		gotoxy(141, 14);cout << cbDuyNhat->data.ngaygioStart.year;
		//gio
		if (cbDuyNhat->data.ngaygioStart.hours < 10) {
			gotoxy(135, 16);cout << "0";
			gotoxy(136, 16);cout << cbDuyNhat->data.ngaygioStart.hours << ":";
		}
		else {
			gotoxy(135, 16);cout << cbDuyNhat->data.ngaygioStart.hours << ":";
		}
		//phut
		if (cbDuyNhat->data.ngaygioStart.minutes < 10) {
			gotoxy(139, 16);cout << "0";
			gotoxy(140, 16);cout << cbDuyNhat->data.ngaygioStart.minutes;
		}
		else {
			gotoxy(139, 16);cout << cbDuyNhat->data.ngaygioStart.minutes;
		}
		////
		int vitrighe = checkCoCMND(cbDuyNhat->data, cmndtemp);
		gotoxy(135, 18); cout << cbDuyNhat->data.nodeVe[vitrighe].soghe;
		gotoxy(128, 20); cout << nodehkDatVe->data.ho;
		gotoxy(148, 20); cout << nodehkDatVe->data.ten;
		gotoxy(135, 22); cout << cmndtemp;
		gotoxy(135, 24); cout << sex[nodehkDatVe->data.gioiTinh];		
					
		if (Hoi(118,29,"   BAN CO CHAC CHAN MUON HUY VE KHONG?   ")) {
			cbDuyNhat->data.nodeVe[vitrighe].cmnd = " ";
			if(checkConVe(cbDuyNhat->data)!=0){
				cbDuyNhat->data.trangthai=1;
				}
			///////////////////////////////////////////// hien thi so do may bay///////////////////////////////		
			SetColor(Color_Back);
			int x = positionX_listCB, y = positionY_listCB;
			int sonode = 0;
			
			for (int i = 0;i < listMB.nodeMB[search(listMB, cbDuyNhat->data.sohieumb)]->soday_MB;i++) {
				for (int j = 0;j < listMB.nodeMB[search(listMB, cbDuyNhat->data.sohieumb)]->sohang_MB;j++) {
					gotoxy(x, y);
					if (cbDuyNhat->data.nodeVe[sonode].cmnd == " ") {
						SetBGColor(Color_Cyan);
						cout << cbDuyNhat->data.nodeVe[sonode].soghe;
					}
					else if (cbDuyNhat->data.nodeVe[sonode].cmnd == cmndtemp) {
						SetBGColor(8);
						cout << cbDuyNhat->data.nodeVe[sonode].soghe;
					}
					else {
						SetBGColor(Color_Yellow);
						cout << cbDuyNhat->data.nodeVe[sonode].soghe;
					}
					sonode++;
					y++;
				}
				x += 10;y = positionY_listCB;
			}
			gotoxy(118,30); SetColor(Color_Back);	cout<<"DA HUY VE THANH CONG";
			GetKey();
			return 1;
		}else{
			return 0;
		}
	}
	if (soCbDaDatVe > 1) {///////// neu hanh khach dat 2 hay nhieu chuyen trong ngay hom do thi cho hien thi form chon chuyen de huy
		char macbtemp[15];
	machuyenbay:// nhap ma chuyen bay muon huy

		SetColor(Color_DarkRed);
		gotoxy(132, 25);cout << "|      NHAP MA CHUYEN BAY BAN MUON HUY    |";//ngay thang
		gotoxy(132, 26);cout << "|-----------------------------------------|";//gio phut
		gotoxy(132, 27);cout << "|           |               |             |";//trang thai
		gotoxy(132, 28);cout << "|___________|_______________|_____________|";//trang thai				
		Alert("CHU Y NHAP DUNG MA CHUYEN BAY BAN MUON HUY", 65, MAXYCONSOLE-3, 4);
		gotoxy(150, 27);fflush(stdin);SetColor(Color_Blue);
		gets(macbtemp);fflush(stdin);strupr(macbtemp);
		Node_CB* cbCanHuy = searchInfo(lCB, macbtemp);
		///neu nhap khong dung chuyen bay thi quay l
		if (cbCanHuy == NULL || cbCanHuy->data.ngaygioStart.day != ngay || cbCanHuy->data.ngaygioStart.month != thang || cbCanHuy->data.trangthai == 0 || cbCanHuy->data.trangthai == 3 || checkCoCMND(cbCanHuy->data, cmndtemp) == -1) {
			Alert2("CHUYEN BAY KHONG HOP LE", 141, 30, 2);
			SetColor(Color_Blue);
			gotoxy(132, 30);cout << "     BAN CO MUON NHAP LAI MA CHUYEN BAY?   ";
			SetColor(Color_White);
			SetBGColor(Color_DarkRed);
			gotoxy(139, 32); cout << " ESC ";

			SetColor(Color_DarkYellow);
			SetBGColor(Color_Back);
			gotoxy(143, 32); cout << ":EXIT";

			// ok
			SetColor(Color_White);
			SetBGColor(Color_DarkGreen);
			gotoxy(160, 32); cout << " ENTER ";

			SetColor(Color_DarkYellow);
			SetBGColor(Color_Back);
			gotoxy(167, 32); cout << ":OK";
			SetBGColor(Color_DarkWhite);
			int key2 = GetKey();
			gotoxy(132, 30);cout << "                                           ";
			gotoxy(132, 31);cout << "                                           ";
			gotoxy(132, 32);cout << "                                           ";
			if (key2 == ENTER) {
				goto machuyenbay;
			}
			else if (key2 == ESC) {
				return 0;
			}
		}
		else { // neu nhap dung ma chuyen bay
			showInfo_CB(cbCanHuy->data, 0);
			frameCoverListCB(30);
//			cheFormDatVe(29);

			frameHuyVe1Cb();
			///////////////////////////////////////////// hien thi so do may bay///////////////////////////////		
			SetColor(Color_Back);
			clearOnePart(positionX_listCB,positionY_listCB -2, 95, 33 );
			int x = 6, y = 15;
			int sonode = 0;
			gotoxy(10, 14);SetBGColor(Color_Cyan);cout << "EMPTY";
			gotoxy(18, 14);SetBGColor(Color_Yellow);cout << "BOOKED";
			gotoxy(26, 14);SetBGColor(8);cout << "YOU";
			for (int i = 0;i < listMB.nodeMB[search(listMB, cbCanHuy->data.sohieumb)]->soday_MB;i++) {
				for (int j = 0;j < listMB.nodeMB[search(listMB, cbCanHuy->data.sohieumb)]->sohang_MB;j++) {
					gotoxy(x, y);
					if (cbCanHuy->data.nodeVe[sonode].cmnd == " ") {
						SetBGColor(Color_Cyan);
						cout << cbCanHuy->data.nodeVe[sonode].soghe;
					}
					else if (cbCanHuy->data.nodeVe[sonode].cmnd == cmndtemp) {
						SetBGColor(8);
						cout << cbCanHuy->data.nodeVe[sonode].soghe;
					}
					else {
						SetBGColor(Color_Yellow);
						cout << cbCanHuy->data.nodeVe[sonode].soghe;
					}
					sonode++;
					y++;
				}
				x += 6;y = 15;
			}
			////// hien thi thong tin chuyen bay da dat			
			clearOnePart(111,7, 48, 29);
			SetColor(Color_Blue);
			SetBGColor(Color_DarkWhite);
			gotoxy(155, 15);cout << cbCanHuy->data.ma_CB;
			gotoxy(155, 16);cout << cbCanHuy->data.sanbayDen;
			////ngay
			if (cbCanHuy->data.ngaygioStart.day < 10) {
				gotoxy(153, 17);cout << "0";
				gotoxy(154, 17);cout << cbCanHuy->data.ngaygioStart.day << "/";
			}
			else {
				gotoxy(153, 17);cout << cbCanHuy->data.ngaygioStart.day << "/";
			}
			//thang
			if (cbCanHuy->data.ngaygioStart.month < 10) {
				gotoxy(156, 17);cout << "0";
				gotoxy(157, 17);cout << cbCanHuy->data.ngaygioStart.month << "/";
			}
			else {
				gotoxy(156, 17);cout << cbCanHuy->data.ngaygioStart.month << "/";
			}
			//nam
			gotoxy(159, 17);cout << cbCanHuy->data.ngaygioStart.year;
			//gio
			if (cbCanHuy->data.ngaygioStart.hours < 10) {
				gotoxy(154, 18);cout << "0";
				gotoxy(155, 18);cout << cbCanHuy->data.ngaygioStart.hours << ":";
			}
			else {
				gotoxy(154, 18);cout << cbCanHuy->data.ngaygioStart.hours << ":";
			}
			//phut
			if (cbCanHuy->data.ngaygioStart.minutes < 10) {
				gotoxy(157, 18);cout << "0";
				gotoxy(158, 18);cout << cbCanHuy->data.ngaygioStart.minutes;
			}
			else {
				gotoxy(157, 18);cout << cbCanHuy->data.ngaygioStart.minutes;
			}

			gotoxy(151, 19);cout << cmndtemp;
			gotoxy(141, 20);cout << nodehkDatVe->data.ho;
			gotoxy(159, 20);cout << nodehkDatVe->data.ten;
			gotoxy(154, 21);cout << sex[nodehkDatVe->data.gioiTinh];
			int vitrighe = checkCoCMND(cbCanHuy->data, cmndtemp);
			gotoxy(153, 22);cout << cbCanHuy->data.nodeVe[vitrighe].soghe;
			//ket thuc hien thi thong tin chuyen bay da dat
			SetColor(Color_Red);
			SetBGColor(Color_Cyan);
			gotoxy(132, 28);
			cout << "                                           ";
			gotoxy(132, 29);
			cout << "         BAN CO CHAC CHAN HUY VE           ";
			gotoxy(132, 30);
			cout << "                                           ";
			SetColor(Color_White);
			SetBGColor(Color_DarkRed);
			gotoxy(139, 32); cout << " ESC ";

			SetColor(Color_DarkYellow);
			SetBGColor(Color_Back);
			gotoxy(143, 32); cout << ":EXIT";

			// ok
			SetColor(Color_White);
			SetBGColor(Color_DarkGreen);
			gotoxy(160, 32); cout << " ENTER ";

			SetColor(Color_DarkYellow);
			SetBGColor(Color_Back);
			gotoxy(167, 32); cout << ":OK";
			SetBGColor(Color_DarkWhite);
			int key2 = GetKey();
//			cheFormDatVe(25);
			if (key2 == ENTER) {
				cbCanHuy->data.nodeVe[vitrighe].cmnd = " ";
							if(checkConVe(cbCanHuy->data)!=0){
				cbCanHuy->data.trangthai=1;
				}
				///////////////////////////////////////////// hien thi so do may bay///////////////////////////////		
				SetColor(Color_Back);
				int x = 6, y = 15;
				int sonode = 0;
				gotoxy(10, 14);SetBGColor(Color_Cyan);cout << "EMPTY";
				gotoxy(18, 14);SetBGColor(Color_Yellow);cout << "BOOKED";
				gotoxy(26, 14);SetBGColor(8);cout << "YOU";
				for (int i = 0;i < listMB.nodeMB[search(listMB, cbCanHuy->data.sohieumb)]->soday_MB;i++) {
					for (int j = 0;j < listMB.nodeMB[search(listMB, cbCanHuy->data.sohieumb)]->sohang_MB;j++) {
						gotoxy(x, y);
						if (cbCanHuy->data.nodeVe[sonode].cmnd == " ") {
							SetBGColor(Color_Cyan);
							cout << cbCanHuy->data.nodeVe[sonode].soghe;
						}
						else if (cbCanHuy->data.nodeVe[sonode].cmnd == cmndtemp) {
							SetBGColor(8);
							cout << cbCanHuy->data.nodeVe[sonode].soghe;
						}
						else {
							SetBGColor(Color_Yellow);
							cout << cbCanHuy->data.nodeVe[sonode].soghe;
						}
						sonode++;
						y++;
					}
					x += 6;y = 15;
				}
				Alert2("DA HUY VE THANH CONG", 141, 15, 2);
				return 1;
			}
			else if (key2 == ESC) {
				return 0;
			}
		}
	}
}

int showInfo_CB2(CHUYENBAY cb, int x) {
	//char d[3],mo[3],h[3],mi[3];

	SetBGColor(Color_DarkWhite);SetColor(Color_DarkRed);
	gotoxy(2, dongStartCB + x);cout << "|__________________|________________|____________|________________|_________|_______________|";
	gotoxy(8, dongStartCB + x);cout << cb.ma_CB;
	gotoxy(27, dongStartCB + x);cout << cb.sohieumb;
	gotoxy(43, dongStartCB + x);cout << cb.sanbayDen;

	////ngay
	if (cb.ngaygioStart.day < 10) {
		gotoxy(55, dongStartCB + x);cout << "0";
		gotoxy(56, dongStartCB + x);cout << cb.ngaygioStart.day << "/";
	}
	else {
		gotoxy(55, dongStartCB + x);cout << cb.ngaygioStart.day << "/";
	}
	//thang
	if (cb.ngaygioStart.month < 10) {
		gotoxy(58, dongStartCB + x);cout << "0";
		gotoxy(59, dongStartCB + x);cout << cb.ngaygioStart.month << "/";
	}
	else {
		gotoxy(58, dongStartCB + x);cout << cb.ngaygioStart.month << "/";
	}
	//nam
	gotoxy(61, dongStartCB + x);cout << cb.ngaygioStart.year;
	//gio
	if (cb.ngaygioStart.hours < 10) {
		gotoxy(72, dongStartCB + x);cout << "0";
		gotoxy(73, dongStartCB + x);cout << cb.ngaygioStart.hours << ":";
	}
	else {
		gotoxy(72, dongStartCB + x);cout << cb.ngaygioStart.hours << ":";
	}
	//phut
	if (cb.ngaygioStart.minutes < 10) {
		gotoxy(75, dongStartCB + x);cout << "0";
		gotoxy(76, dongStartCB + x);cout << cb.ngaygioStart.minutes;
	}
	else {
		gotoxy(75, dongStartCB + x);cout << cb.ngaygioStart.minutes;
	}
//	gotoxy(82, dongStartCB + x);cout << cb.soluongVe;
	gotoxy(85, dongStartCB + x);cout << checkConVe(cb);

	//	cout<<cb.ma_CB<<"\t"<<cb.sohieumb<<"\t"<<cb.ngaygioStart.day<<"/"<<cb.ngaygioStart.month<<"/"<<cb.ngaygioStart.year<<"\t"<<cb.ngaygioStart.hours<<":"<<cb.ngaygioStart.minutes<<"\t"<<cb.sanbayDen<<"\t"<<cb.soluongVe<<"\t"<<cb.trangthai<<endl;
}
int cauF(List_CB lCB){
	header();footer();
	frameTimChuyenBay();
	frameSanbayDen();
	char noiden[4];
	int ngay, thang;
noiden:
	SetColor(Color_Blue);
	gotoxy(151, 12);fflush(stdin);
	gets(noiden);
	strupr(noiden);
	if (strcmp(noiden, "") == 0) {
		Alert("CHUA NHAP NOI DEN", 76, MAXYCONSOLE-3, 2);
		gotoxy(151, 12);cout << "         ";
		goto noiden;
	}
	if (checkNoiDen(noiden) == -1) {
		Alert("NOI DEN KHONG CO TRONG DANH SACH", 70, MAXYCONSOLE-3, 2);
		gotoxy(151, 12);cout << "         ";
		goto noiden;
	}
thang:
	SetColor(Color_Blue);
	gotoxy(142, 18); cin >> thang;
	if (checkMonth(thang) == false) {
		Alert("THANG KHONG HOP LE", 72, MAXYCONSOLE-3, 5);
		gotoxy(142, 18);cout << "    ";
		goto thang;
	}
ngay:	SetColor(Color_Blue);
	gotoxy(163, 18);cin >> ngay;
	if (checkDay(ngay, thang) == false || checkCurrentDDMMYY(ngay, thang) == false) {
		Alert("NGAY KHONG HOP LE", 75, MAXYCONSOLE-3, 2);
		gotoxy(163, 18);cout << "    ";
		goto ngay;
	}
	////	  xu ly
	int vitri = 0;
	for (Node_CB* p = lCB.pHead;p != NULL;p = p->pNext) {
		if (strcmp(p->data.sanbayDen, noiden) == 0 && p->data.ngaygioStart.month == thang && p->data.ngaygioStart.day == ngay && checkConVe(p->data) != 0) {
			frameSoCbConVe();
			showInfo_CB2(p->data, vitri);
			vitri++;
		}
	}
	if (vitri == 0) {/////////////////////////////////////////////////////////////////////neu khong co chuyen bay nao hop le
		int key = frameKhCoCBHople();
		frameCoverkhCoCBHopLe();
		if (key == ENTER) {
			gotoxy(163, 18);cout << "    ";
			gotoxy(142, 18);cout << "    ";
			gotoxy(151, 12);cout << "         ";
			goto noiden;
		}
		else if (key == ESC) {
			return 0;
		}
	}	
	
		
}
int cauG(List_CB lcb, List_MB listMB){
	header();
	char macbtemp[15];
	showList_CB(lcb);
start:
	SetColor(Color_DarkRed);
	SetBGColor(Color_DarkWhite);

	gotoxy(140, 8);	cout << "+-------------------------+";
	gotoxy(140, 9);	cout << "|    NHAP MA CHUYEN BAY   |";
	gotoxy(132, 10);cout << "+-------+-------------------------+-------+";
	gotoxy(132, 11);cout << "|                                         |";
	gotoxy(132, 12);cout << "|-----------------------------------------|";
	
	gotoxy(150, 11);fflush(stdin);gets(macbtemp);strupr(macbtemp);
	gotoxy(30, 20);SetColor(Color_Blue);
//	cout << "DANG LOAD HANH KHACH CUA CHUYEN BAY....";
	int soluongchuyenbay=0;
	for (Node_CB* p = lcb.pHead; p != NULL;p = p->pNext){	
	if(strcmp(p->data.ma_CB, macbtemp) == 0){//tim co chuyen bay 
		frameCoverListCB2(32);
frameSanbayDen();
			soluongchuyenbay++;
			gotoxy(30, 20);SetColor(Color_Blue);
			cout << "                                       ";
			SetColor(Color_DarkRed);
			SetBGColor(Color_DarkWhite);
			gotoxy(132, 13);cout << "|********** THONG TIN CHUYEN BAY *********|";
			gotoxy(132, 14);cout << "|                                         |";
			gotoxy(132, 15);cout << "|    CHUYEN BAY:                          |";
			gotoxy(132, 16);cout << "|    NOI DEN:                             |";
			gotoxy(132, 17);cout << "|    NGAY DI:                             |";//thong bao
			gotoxy(132, 18);cout << "|    GIO DI:                              |";
			gotoxy(132, 19);cout << "|_________________________________________|";//esc enter
			gotoxy(28, 10);cout << " SO DO VE CUA CHUYEN BAY ";
			SetColor(Color_DarkRed);	  	    //"|_______|___________|______________|____________________|___________|"					//	215445446
			SetBGColor(Color_DarkWhite);
			gotoxy(155, 15);cout << p->data.ma_CB;
			gotoxy(155, 16);cout << p->data.sanbayDen;
			////ngay
			if (p->data.ngaygioStart.day < 10) {
				gotoxy(153, 17);cout << "0";
				gotoxy(154, 17);cout << p->data.ngaygioStart.day << "/";
			}
			else {
				gotoxy(153, 17);cout << p->data.ngaygioStart.day << "/";
			}
			//thang
			if (p->data.ngaygioStart.month < 10) {
				gotoxy(156, 17);cout << "0";
				gotoxy(157, 17);cout << p->data.ngaygioStart.month << "/";
			}
			else {
				gotoxy(156, 17);cout << p->data.ngaygioStart.month << "/";
			}
			//nam
			gotoxy(159, 17);cout << p->data.ngaygioStart.year;
			//gio
			if (p->data.ngaygioStart.hours < 10) {
				gotoxy(154, 18);cout << "0";
				gotoxy(155, 18);cout << p->data.ngaygioStart.hours << ":";
			}
			else {
				gotoxy(154, 18);cout << p->data.ngaygioStart.hours << ":";
			}
			//phut
			if (p->data.ngaygioStart.minutes < 10) {
				gotoxy(157, 18);cout << "0";
				gotoxy(158, 18);cout << p->data.ngaygioStart.minutes;
			}
			else {
				gotoxy(157, 18);cout << p->data.ngaygioStart.minutes;
			}
				///////////////////////////////////////////// hien thi so do may bay///////////////////////////////		
				SetColor(Color_Back);
				int x = 6, y = 15;
				int sonode = 0;
				gotoxy(10, 13);SetBGColor(Color_Cyan);cout << "EMPTY";
				gotoxy(18, 13);SetBGColor(Color_Yellow);cout << "BOOKED";
				for (int i = 0;i < listMB.nodeMB[search(listMB, p->data.sohieumb)]->soday_MB;i++) {
					for (int j = 0;j < listMB.nodeMB[search(listMB, p->data.sohieumb)]->sohang_MB;j++) {
						gotoxy(x, y);
						if (p->data.nodeVe[sonode].cmnd == " ") {
							SetBGColor(Color_Cyan);
							cout << p->data.nodeVe[sonode].soghe;
						}
						else {
							SetBGColor(Color_Yellow);
							cout << p->data.nodeVe[sonode].soghe;
						}
						sonode++;
						y++;
					}
					x += 6;y = 15;
				}
				//////////////////////////////////////// nhap so ghe
			
		}	
	
		}
 if(soluongchuyenbay==0){
					Alert2("MA CHUYEN BAY KHONG TON TAI",138,14,2);
		SetColor(Color_Back);
		SetBGColor(Color_Cyan);
		gotoxy(141, 21);cout << "BAN CO MUON NHAP LAI KHONG?";//gio phut
		SetColor(Color_White);
		SetBGColor(Color_DarkRed);
		gotoxy(139, 23); cout << " ESC ";

		SetColor(Color_DarkYellow);
		SetBGColor(Color_Back);
		gotoxy(143, 23); cout << ":EXIT";

		// ok
		SetColor(Color_White);
		SetBGColor(Color_DarkGreen);
		gotoxy(160, 23); cout << " ENTER ";

		SetColor(Color_DarkYellow);
		SetBGColor(Color_Back);
		gotoxy(167, 23); cout << ":OK";
		SetBGColor(Color_DarkWhite);
		int key = GetKey();
		gotoxy(132, 21);cout << "                                           ";
		gotoxy(132, 23);cout << "                                           ";
		if(key==ENTER){
			goto start;
		}else if(key==ESC){
		return 0;
		}
		}
		SetBGColor(Color_DarkWhite);		
}
int endProgram(List_CB &lcb, List_MB &lmb, NODEHKPTR &lhk){
	SetBGColor(Color_DarkWhite);
	int key;
	do{
		key=frameExit();
		if(key==ENTER){
			saveFileList_MB(lmb);
			saveFileList_CB(lcb);
			SaveDataHanhKhach(lhk);
			return 1;
		}
		if(key==ESC){
			return 0;
			}
	}while(key!=ENTER||key!=ESC);
	}


////////////////////////////////////////////////////////////////Menu///////////////////////////////////////////////////////////////////////////	
int MenuCon(int item, char MenuCon[][50], int x) {
	int countitem = 4;
	if(x==positionMenuKH) countitem = 2;
	if(x==positionMenuMB) countitem = 5;
	for (int i = 0; i < countitem; i++) {
		if (i == 0) {
			SetColor(Color_DarkRed);
			SetBGColor(Color_Yellow);
		}
		else {
			SetColor(Color_DarkRed);
			SetBGColor(Color_Cyan);
		}
		gotoxy(x, positionMainMenu + 4 + (i * 4));	cout << "                               ";
		gotoxy(x, positionMainMenu + 5 + (i * 4));	cout << MenuCon[i];
		gotoxy(x, positionMainMenu + 6 + (i * 4));	cout << "                               ";
	}
	char key;
	int vitri = 0;
	while (true) {
		key = GetKey();
		if (key == ENTER)
			return vitri + 1;
		if (key == ESC || key == LEFT)
			return 0;
		switch (key) {
		case DOWN:
			if (vitri == (item - 1)) {
				ToMauMenuCon(4, 11, MenuCon, vitri,x);
				vitri = 0;
				ToMauMenuCon(4, 14, MenuCon, vitri,x);
			}
			else {
				ToMauMenuCon(4, 11, MenuCon, vitri,x);
				vitri++;
				ToMauMenuCon(4, 14, MenuCon, vitri,x);
			}
			break;
		case UP:
			if (vitri == 0) {
				ToMauMenuCon(4, 11, MenuCon, vitri,x);
				vitri = item - 1;
				ToMauMenuCon(4, 14, MenuCon, vitri,x);
			}
			else {
				ToMauMenuCon(4, 11, MenuCon, vitri,x);
				vitri--;
				ToMauMenuCon(4, 14, MenuCon, vitri,x);
			}
			break;
		}
	}
	return 0;
}

//------------------DAD MENU--------------------------
int mainMenu(){
	for (int i = 0; i < itemmenuchinh; i++) {
		if (i == 0) {
			SetColor(Color_DarkRed);
			SetBGColor(Color_Yellow);
		}
		else {
			SetColor(Color_DarkRed);
			SetBGColor(Color_Cyan);
		}
		gotoxy(positionMenuMB + i*31, positionMainMenu); 	cout << "                               ";
		gotoxy(positionMenuMB + i*31, positionMainMenu + 1); cout << MENU[i];
		gotoxy(positionMenuMB + i*31, positionMainMenu + 2); cout << "                               ";
	}
	int vitri = 0;
	while (true) {
		header();
		footer();
		char key = GetKey();
		if (key == ENTER)// || (key == RIGHT && vitri != itemmenuchinh)) // 4 === THOAT
			return vitri + 1;
		switch (key) {
		case RIGHT:
			if (vitri == (itemmenuchinh - 1)) {
				ToMauMenuChinh(4, 11, vitri);
				vitri = 0;
				ToMauMenuChinh(4, 14, vitri);
			}
			else {
				ToMauMenuChinh(4, 11, vitri);
				ToMauMenuChinh(4, 14, ++vitri);
			}
			break;
		case LEFT:
			if (vitri == 0) {
				ToMauMenuChinh(4, 11, vitri); 
				vitri = (itemmenuchinh - 1);
				ToMauMenuChinh(4, 14, vitri);
			}
			else {
				ToMauMenuChinh(4, 11, vitri);
				ToMauMenuChinh(4, 14, --vitri);
			}
			break;
		}
	}
	return 0;
}

//---------------ROOT MENU------------------------
void RootMenu(List_MB & l, List_CB & lCB, NODEHKPTR & lHK) {
	int choice;
	int choiceMenuCon;
	openFileList_MB(l);
	LoadDataHanhKhach(lHK);
	openFileList_CB(lCB,l);
	while (true) {
		clrscr();
		choice = mainMenu();
		SetBGColor(Color_DarkWhite);
		switch (choice) {
//////////////////////////////////////////////////////  QUAN LY MAY BAY			
			case 1:// Quan ly may bay
				SetBGColor(Color_DarkWhite);
				clrscr();
					quanLyMayBay(l, lCB);
				break;
////////////////////// QUAN LY CHUYEN BAY		///////////////////////
			case 2://quan ly chuyen bay
				choiceMenuCon = MenuCon(itemmenuCB, MENUCHUYENBAY,positionMenuCB);
				// item la so chuc nang cua lop con
				SetBGColor(Color_DarkWhite);
				clrscr();
				switch (choiceMenuCon) {
				case 1://them chuyen bay
					addList_CB(lCB, l);
					break;
				case 2:// xoa chuyen bay
					DeleteCB(lCB);
					break;
				case 3://hieu chinh thong tin chuyen bay				
					editCB(lCB, l);
					break;
				case 4://hien thi danh sach
					showList_CB(lCB);
					getch();
					break;
				}
				break;
			case 3://quan ly dat ve
				choiceMenuCon = MenuCon(itemmenuDV, MENUDATVE,positionMenuDV);
				// item la so chuc nang cua lop con
				SetBGColor(Color_DarkWhite);
				clrscr();
				switch (choiceMenuCon) {
				case 1://dat ve
					bookTicket(lCB, l, lHK);
	
					break;
				case 2:// huye ve
					cancelTicket(lCB, l, lHK);
					break;
				case 3://
					cauF(lCB);
					getch();	
					break;
				case 4://
					cauG(lCB,l);
					getch();
					break;
				}
				break;
			case 4:// quan ly hanh khach
				choiceMenuCon = MenuCon(itemmenuHK, MENUHK,positionMenuKH);
				// item la so chuc nang cua lop con
				SetBGColor(Color_DarkWhite);
				clrscr();
				switch (choiceMenuCon) {
				case 1://tat ca hanh khach
					DuyetDSHK(lHK);
					getch();
					break;
				case 2:// hanh khach cua chuyen xxx
					showCustomerOfCbXXX(lCB, lHK);
					getch();
					break;
				}
				break;
			case 5: //thoat
				endProgram(lCB,l,lHK);
				return ;
		}
	}
	return;
}
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
		resizeConsole(maxrong, maxcao);
	SetBGColor(Color_DarkWhite);
	List_MB lMB;
	lMB.soluong = 0;
	List_CB lCB;
	initList_CB(lCB);
	NODEHKPTR listhk;
	InitTree(listhk);
	RootMenu(lMB, lCB, listhk);
	return 0;
}
