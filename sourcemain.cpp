#include <iostream>
#include <string>
#include <string.h>
#include "khaibao.h"
#include "support.h"
#include "frame.h"
//#include <sstream> 
//#include <algorithm>
//#include <math.h>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */



using namespace std;

//tao node chuyen bay, them du lieu cho node va tra ve dia chi node
Node_CB* createNodeCB(CHUYENBAY cb) {
	Node_CB* p = new Node_CB;
	if (p == NULL) {
		message(posXMessage,posYMessage, "CAP PHAT BO NHO KHONG THANH CONG");
		exit(1);
	}else {
		p->data = cb;
		p->pNext == NULL;
		return p;
	}
}
////////////////////////////////////////////////////////////////////// MAY BAY //////////////////////////////////////////////////////////////////////
int showList_MB(List_MB listMB, boolean flag) {
	SetBGColor(Color_DarkWhite);							header();
	SetColor(Color_Pink);	SetBGColor(Color_DarkWhite);	vekhung(72,4,1,32);
	gotoxy(82,5);			SetColor(Color_Pink);			cout<<"DANH SACH MAY BAY";
	
	if (listMB.soluong == 0 && flag == TRUE) {
		message(posXMessage,posYMessage, "CHUA CO MAY BAY"); return 0;
	}
	else {
		footer();
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
int addInfo_MB(List_MB list_MB, MAYBAY& mb) {
	ShowCur(true);
	footerEditMB();
	int key;
	// LAY CAC GIA TRI CU
	string sohieuMB = "";	gotoxy(136,11);		SetBGColor(Color_White);	cout<<"               ";
	string loaiMB = "";		gotoxy(136,15);		SetBGColor(Color_White);	cout<<"               ";
	int soday = 0;			gotoxy(136,19);		SetBGColor(Color_White);	cout<<"  ";
	int sohang = 0;			gotoxy(136,23);		SetBGColor(Color_White);	cout<<"  ";
	gotoxy(136,27);		SetBGColor(Color_White);	cout<<"   ";
	bool xacthuc;
	do{
		// SO HIEU MAY BAY
		alertHelp(positionAlertHelp,MAXYCONSOLE - 11,"         SO HIEU MB: GOM CAC KI TU (A-Z) & (0-9)           ");
		bool xacnhanSHMB;
		do{
			xacnhanSHMB = true;
			SetBGColor(Color_White);
			nhapMa(136,11,sohieuMB,15);
			if(sohieuMB == ""){
				return 0;
			}else strcpy(mb.sohieu_MB, sohieuMB.c_str());
			if (search(list_MB, mb.sohieu_MB) > -1) {
				gotoxy(126,13); SetColor(Color_Red);	SetBGColor(Color_DarkWhite);	cout<<"SO HIEU MAY BAY TRUNG";	SetColor(Color_DarkBlue);
				xacnhanSHMB = false;
			}
		}while(!xacnhanSHMB);
		gotoxy(126,13);		SetBGColor(Color_DarkWhite);	cout<<"                     ";	
		// LOAI MAY BAY
		alertHelp(positionAlertHelp,MAXYCONSOLE - 11,"        LOAI MAY BAY: GOM CAC KI TU (A-Z) & (0-9)          ");
		SetBGColor(Color_White);
		NhapLieu(136,15,loaiMB,40);
		if(loaiMB == ""){
			return 0;
		}else strcpy(mb.loai_MB, loaiMB.c_str());
		// SO DAY
		alertHelp(positionAlertHelp,MAXYCONSOLE - 11,"                 0 < SO LUONG DAY < 10                     ");
		do{
			SetBGColor(Color_White);
			NhapLieuSo(136,19,soday,2);
			if(soday == 0) return 0;
			else if(soday >10){
				gotoxy(126,21); SetColor(Color_Red);	SetBGColor(Color_DarkWhite);	cout<<"SO DAY KHONG HOP LE";	SetColor(Color_DarkBlue);
			}else mb.soday_MB = soday;
		}while(soday==0 || soday>10);
		gotoxy(126,21);	SetBGColor(Color_DarkWhite);	cout<<"                   ";
		// SO HANG
		alertHelp(positionAlertHelp,MAXYCONSOLE - 11,"                 0 < SO LUONG HANG < 30                    ");
		do{
			SetBGColor(Color_White);
			NhapLieuSo(136,23,sohang,2);
			if(sohang == 0) return 0;
			else if(sohang >30){
				gotoxy(126,25); SetColor(Color_Red);	SetBGColor(Color_DarkWhite);	cout<<"SO HANG KHONG HOP LE";	SetColor(Color_DarkBlue);
			}else mb.sohang_MB = sohang;
		}while(sohang>30);
		gotoxy(126,25);		SetBGColor(Color_DarkWhite);	cout<<"                    ";
		// 
		gotoxy(136, 27); 	SetBGColor(Color_White);		cout << (mb.soday_MB * mb.sohang_MB);
		bool xacthucKey;
		do{
			xacthucKey = true;
			key = GetKey();
			if(key == ESC) return 0;
			else if(key == F2) return 1;
			else if(key == TAB)	xacthuc = false;
			else xacthucKey= false;
		}while(!xacthucKey);
	}while(!xacthuc);
	return 0;
}
//them may bay vao danh sach
int addList_MB(List_MB & listMB) {
	ShowCur(true);
	if (isFull(listMB)) {//kiem tra day chua?
		return -1;
	}
	else {//neu chua day...
	
			// THEM VAO DAU
		if (isEmpty(listMB)) {//... thi kiem tra xem co phan tu chua?
			MAYBAY mb;
			if (addInfo_MB(listMB, mb) == 0) {
				return 0;
			}
			else {
				listMB.nodeMB[0] = new MAYBAY;
				*listMB.nodeMB[0] = mb; listMB.soluong++;
				return 1;
			}
		}
		else {
			MAYBAY mb;
			if (addInfo_MB(listMB, mb) == 0) {
				return 0;
			}
			else {
				int j, k;
				for (j = 0; j < listMB.soluong && strcmp(listMB.nodeMB[j]->sohieu_MB, mb.sohieu_MB) < 1; j++);
				for (k = listMB.soluong - 1; k >= j; k--)
					listMB.nodeMB[k + 1] = listMB.nodeMB[k];
				listMB.nodeMB[j] = new MAYBAY;
				*listMB.nodeMB[j] = mb; listMB.soluong++;
				return 1;
			}
		}
	}
}
//IN LUOT BAY SECTION_SORT
void Insoluotbay(List_MB lMB, List_CB list_CB)
{
	header();
	int dem = 0;
	int dem1=0;
	for(int i=0;i<lMB.soluong;i++)
	{
		Node_CB *p;
	    p=list_CB.pHead;
		MAYBAY *temp;
		int vitrimax = i;
	    while(p!=NULL)
	    {
			if(strcmp(p->data.sohieumb,lMB.nodeMB[i]->sohieu_MB)==0&&p->data.trangthai==3)
			dem++;
	        p=p->pNext;
	    }
	    for(int j=i+1;j< lMB.soluong;j++)
	    {
			Node_CB *q;
		    q=list_CB.pHead;
		    while(q!=NULL)
		    {
				if(strcmp(q->data.sohieumb,lMB.nodeMB[j]->sohieu_MB)==0&&q->data.trangthai==3)
					dem1++;
		        q=q->pNext;
		    }
	    	if(dem1>dem)
	    	{
	    		vitrimax = j;
	    		dem = dem1;
			}
			dem1=0;
	    }
	    
		temp=lMB.nodeMB[i];
		lMB.nodeMB[i]=lMB.nodeMB[vitrimax];
		lMB.nodeMB[vitrimax]=temp;
	    SetColor(Color_DarkRed);
		SetBGColor(Color_DarkWhite);
		gotoxy(48,dongStart+i);cout<<lMB.nodeMB[i]->sohieu_MB; 
		gotoxy(70,dongStart+i);cout<<lMB.nodeMB[i]->loai_MB;
		gotoxy(100,dongStart+i);cout<<dem;
//		gotoxy(positionX_listMB+103,dongStart+i);cout<<dem;
		dem=0;
	}
	

}
int optionMB(List_MB & list_MB, List_CB list_CB) {
	ShowCur(false);		header();	SetBGColor(Color_DarkWhite);
	if (isEmpty(list_MB)) {
		gotoxy(posXMessage,posYMessage); cout<<"CHUA CO MAY BAY TRONG DANH SACH "; getch();
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
		
		for (int i = 0;i < list_MB.soluong;i++) {
			Normal();	outDataMB(list_MB, i);
		}
		HighLight();	outDataMB(list_MB, 0);
	}
		
	int vitri = 0;	SetBGColor(Color_DarkWhite);
	while (true) {
		int key = GetKey();
		switch (key) {
			case DOWN:
				if (vitri == list_MB.soluong - 1) {
					Normal();		outDataMB(list_MB, vitri);	vitri = 0;
					HighLight();	outDataMB(list_MB, vitri);
				}
				else {
					Normal();		outDataMB(list_MB, vitri);	vitri++;
					HighLight();	outDataMB(list_MB, vitri);
				}
				break;
			case UP:
				if (vitri == 0) {
					Normal();		outDataMB(list_MB, vitri);	vitri = list_MB.soluong - 1;
					HighLight();	outDataMB(list_MB, vitri);
				}
				else {
					Normal();		outDataMB(list_MB, vitri);	vitri--;
					HighLight();	outDataMB(list_MB, vitri);
				}
				break;
			case ENTER:
				if (list_MB.soluong > 0) {
					return vitri;
				}	return -1;
			case F1:
				{
					int add = addList_MB(list_MB);
					SetBGColor(Color_DarkWhite);
					if(add == 1){
						gotoxy(posXMessage,30); cout<<"THEM MAY BAY THANH CONG!";
					}else if(add == -1){
						gotoxy(posXMessage,30); cout<<"DANH SACH DA DAY!";
					}else {
						gotoxy(posXMessage,30); cout<<"DA HUY!";
					}
					getch();	gotoxy(118,30); cout<<"                        ";
					gotoxy(positionAlertHelp,31); cout<<"                                                            ";
					gotoxy(positionAlertHelp,32); cout<<"                                                            ";
					gotoxy(positionAlertHelp,33); cout<<"                                                            ";	
					return -2;
				}
			case F2: 
				{
					SetBGColor(Color_DarkWhite);	clrscr();
					int A[2]={20,50};	table(40,8,20,70,2,A);
					gotoxy(43,9);	cout<<"SO HIEU MAY BAY";
					gotoxy(70,9);	cout<<"LOAI MAY BAY";
					gotoxy(95,9);	cout<<"SO LUOT BAY";
					Insoluotbay(list_MB ,list_CB);
					getch(); clrscr();	return -2;
				}
			case ESC:	return -1;
			default: break;
		}
	}
}

int updateInfo_MB(List_MB &listMB, MAYBAY &mb, int vitrinode) {
	int key;
	// LAY CAC GIA TRI CU
	string sohieuMB = listMB.nodeMB[vitrinode]->sohieu_MB;
	strcpy(mb.sohieu_MB, sohieuMB.c_str());
	string loaiMB = listMB.nodeMB[vitrinode]->loai_MB;
	int soday= listMB.nodeMB[vitrinode]->soday_MB;
	int sohang= listMB.nodeMB[vitrinode]->sohang_MB;
//	gotoxy(136,11); cout<<sohieuMB;
	bool xacthuc;
	do{
		SetColor(Color_DarkBlue);
		alertHelp(positionAlertHelp,MAXYCONSOLE - 11,"        LOAI MAY BAY: GOM CAC KI TU (A-Z) & (0-9)          ");
		SetBGColor(Color_White);
		NhapLieu(136,15,loaiMB,15);
		if(loaiMB == ""){
			return 0;
		}else strcpy(mb.loai_MB, loaiMB.c_str());
		// SO DAY
		alertHelp(positionAlertHelp,MAXYCONSOLE - 11,"                 0 < SO LUONG DAY < 10                     ");
		do{
			SetBGColor(Color_White);
			NhapLieuSo(136,19,soday,2);
			if(soday == 0) return 0;
			else if(soday >10){
				gotoxy(126,21); SetColor(Color_Red);	SetBGColor(Color_DarkWhite);	cout<<"SO DAY KHONG HOP LE";	SetColor(Color_DarkBlue);
			}else mb.soday_MB = soday;
		}while(soday==0 || soday>10);
		gotoxy(126,21);	SetBGColor(Color_DarkWhite);	cout<<"                   ";
		// SO HANG
		alertHelp(positionAlertHelp,MAXYCONSOLE - 11,"                 0 < SO LUONG HANG < 35                    ");
		do{
			SetBGColor(Color_White);
			NhapLieuSo(136,23,sohang,2);
			if(sohang == 0) return 0;
			else if(sohang >30){
				gotoxy(126,25); SetColor(Color_Red);	SetBGColor(Color_DarkWhite);	cout<<"SO HANG KHONG HOP LE";	SetColor(Color_DarkBlue);
			}else mb.sohang_MB = sohang;
		}while(sohang>30);
		gotoxy(126,25);		SetBGColor(Color_DarkWhite);	cout<<"                    ";
		// 
		gotoxy(136, 27); 	SetBGColor(Color_White);		cout << (mb.soday_MB * mb.sohang_MB);
		bool xacthucKey;
		do{
			xacthucKey = true;	key = GetKey();
			if(key == ESC) return 0;
			else if(key == F2) return 1;
			else if(key == TAB)	xacthuc = false;
			else xacthucKey= false;
		}while(!xacthucKey);
	}while(!xacthuc);
	return 0;
}
// hieu chinh thong tin may bay
int editMB(List_MB &list_MB, List_CB list_CB, int vitrinode) {

	ShowCur(true);
	footerEditMB();
	int key;
	MAYBAY mb;
	if (updateInfo_MB(list_MB, mb, vitrinode) == 0)	return 0;
	else {
		if (Hoi(55,MAXYCONSOLE-5,"   THONG TIN CU SE BI XOA. BAN CO CHAC CHAN MUON LUU MOI?  ")) {
			if (searchInfoShmb(list_CB, list_MB.nodeMB[vitrinode]->sohieu_MB) != NULL) return -1;
			else{
				strcpy(list_MB.nodeMB[vitrinode]->sohieu_MB, mb.sohieu_MB);
				strcpy(list_MB.nodeMB[vitrinode]->loai_MB, mb.loai_MB);
				list_MB.nodeMB[vitrinode]->soday_MB = mb.soday_MB;
				list_MB.nodeMB[vitrinode]->sohang_MB = mb.sohang_MB;
				return 1;
			}
		}else	return 0;
	}
}
//xoa may bay khoi danh sach
void quanLyMayBay(List_MB &list_MB, List_CB list_CB) {

	clrscr();
	SetColor(Color_Pink);	SetBGColor(Color_DarkWhite);	vekhung(72,4,1,32);
	gotoxy(82,5);			SetColor(Color_Pink);			cout<<"DANH SACH MAY BAY";
	while(1){
		footerMB();
		formInput(positionFormInputX,positionFormInputY,5,ITEM);
		int position = optionMB(list_MB, list_CB);
		int key;
		if (position == -1) {
			SetBGColor(Color_DarkWhite);		return;
		}else if(position == -2){
		}else{
			// CHON XOA HOAC SUA MAY BAY
			int choose = alertOption(55,MAXYCONSOLE-5,"           BAN MUON XOA HAY CHINH SUA MAY BAY              ","    SUA   ","    XOA   ");
			if(choose == 2){
				if (Hoi(55,MAXYCONSOLE-5,"      BAN CO CHAC CHAN XOA MAY BAY KHOI DANH SACH?         ")) {
					if (searchInfoShmb(list_CB, list_MB.nodeMB[position]->sohieu_MB) != NULL) {
						gotoxy(118,30); cout<<"KHONG THE XOA MAY BAY VI DA TAO CHUYEN BAY";
					}else{
						delete  list_MB.nodeMB[position];
						for (int j = position + 1; j < list_MB.soluong; j++)
							list_MB.nodeMB[j - 1] = list_MB.nodeMB[j];
						list_MB.soluong--;
						message(posXMessage,posYMessage,"DA XOA THANH CONG!");
						clrscr();	SetBGColor(Color_DarkWhite);
					}
				}else{
					message(posXMessage,posYMessage,"DA HUY!");	clrscr();
				}
			}else if(choose == 1){
				int update = editMB(list_MB, list_CB, position);
				SetBGColor(Color_DarkWhite);	SetColor(Color_DarkBlue);
				if(update == 1){
					message(posXMessage,posYMessage,"HIEU CHINH MAY BAY THANH CONG!");
				}else if(update == 0){
					message(posXMessage,posYMessage,"DA HUY!");
				}else{
					message(posXMessage,posYMessage,"MAY BAY DA TAO CHUYEN BAY, KHONG THE CHINH SUA");
				}
				clrscr();
			}
		}
	}
	return;

}

///////////////////////////////////////////////////////////////// CHUYEN BAY ///////////////////////////////////////////////////////////////////////////////////

string Chuyen(int num){
	string resuft;
	stringstream ss;	ss << num; resuft = ss.str();
	if(num<10) resuft = "0" + resuft;
    return resuft;
}

//them thong tin cho chuyen bay
int addInfo_CB(List_CB & listCB, List_MB listMB, CHUYENBAY & cb) {
	
	footerEditMB();frameSanbayDen();
	ShowCur(true);
	int vitri; int key;
	SetBGColor(Color_DarkWhite);
	bool xacthuc;
	string ma_CB = "", sohieuMB = "", noiden = "", ngay = "", gio = "";
	
	SetColor(Color_Back);
	vekhungdoi(105,6,30,60);
	SetColor(Color_DarkYellow);
	gotoxy(118,10);	cout<<"MA CHUYEN BAY:";
	gotoxy(118,12);	cout<<"SO HIEU MAY BAY:";
	gotoxy(118,14);	cout<<"NOI DEN:";
	gotoxy(118,16);	cout<<"NGAY KHOI HANH:";
	gotoxy(118,18);	cout<<"GIO KHOI HANH:";
	gotoxy(118,20);	cout<<"SO GHE:";
	gotoxy(118,22);	cout<<"TRANG THAI:";
	SetColor(Color_DarkYellow);
	do{
		xacthuc =true;
		bool xacnhan_maCB;
		do{
			SetColor(Color_DarkBlue);
			xacnhan_maCB = true;	SetBGColor(Color_DarkWhite);
			NhapLieu(135,10,ma_CB,15);
			if(ma_CB == "") return 0;
			strcpy(cb.ma_CB, ma_CB.c_str());
			if (searchInfo(listCB, cb.ma_CB) != NULL) {
				gotoxy(125,11);	SetColor(Color_DarkRed); 	cout<<"MA CHUYEN BAY BI TRUNG!";	SetColor(Color_DarkBlue);
				xacnhan_maCB = false;
			}
		}while(!xacnhan_maCB);
		gotoxy(125,11); 	cout<<"                       ";
		
		bool xacnhanSHMB;
		do{
			xacnhanSHMB = true;
			SetColor(Color_Back);	vekhungdoi(150,8,20,13);		kengangdoi(150,10,13);
			gotoxy(152,9); 				cout<<"SO HIEU MB";
			int nodeout = frameAddShmb_AddCB(listMB);
			if(nodeout == -1){
				gotoxy(posXMessage,posYMessage); cout<<"CHUA CO MAY BAY NAO!";	return 0;
			}else if(nodeout == -2)	return 0;
			else{
				sohieuMB = listMB.nodeMB[nodeout]->sohieu_MB;
				strcpy(cb.sohieumb, listMB.nodeMB[nodeout]->sohieu_MB);
				SetColor(Color_DarkBlue);	SetBGColor(Color_DarkWhite);
				gotoxy(135,12); cout<<sohieuMB;
				clearOnePart(150,8,15,21);
			}
		}while(!xacnhanSHMB);
		// NOI DEN
		bool xacnhan_ND;
		do{
			xacnhan_ND = true;	SetBGColor(Color_DarkWhite);
			nhapMa(135, 14, noiden, 4);
			strcpy(cb.sanbayDen, noiden.c_str());
			if (checkNoiDen(cb.sanbayDen) < 0) {
				gotoxy(125,15);	SetColor(Color_DarkRed); 	cout<<"NOI DEN KHONG HOP LE!";	SetColor(Color_DarkBlue);
				xacnhan_ND = false;
			}
		}while(!xacnhan_ND);
		gotoxy(125,15); 	cout<<"                     ";
		
		bool xacthucNgayGio;
		do{
			SetColor(Color_DarkBlue);
			xacthucNgayGio = true;
			bool xacthucNgay;
			do{
				char ngaytemp[3]="";	char thangtemp[3]="";	char namtemp[5]="";	char ddmmyy[11]="";
				xacthucNgay = true;	SetBGColor(Color_DarkWhite);
				NhapLieuso(135,16,ngay,10);
				gotoxy(118,17); 	cout<<"                                               ";
				if(ngay == "") return 0;
				strcpy(ddmmyy, ngay.c_str());
				if(ngay.length() <10 || (int)ddmmyy[2] != 47 || (int)ddmmyy[5] != 47){
					gotoxy(118,17);	SetColor(Color_DarkRed); 	cout<<"NGAY KHOI HANH KHONG DUNG. CU PHAP '09/09/2020'";	SetColor(Color_DarkBlue);
					xacthucNgay = false;
				}
				else{ 
					ngaytemp[0] = ddmmyy[0];ngaytemp[1] = ddmmyy[1];
					thangtemp[0] = ddmmyy[3];thangtemp[1] = ddmmyy[4];
					namtemp[0] = ddmmyy[6];namtemp[1] = ddmmyy[7];namtemp[2] = ddmmyy[8];namtemp[3] = ddmmyy[9];
					cb.ngaygioStart.day = atoi(ngaytemp);
					cb.ngaygioStart.month = atoi(thangtemp);
					cb.ngaygioStart.year = atoi(namtemp);
					if (checkYear(cb.ngaygioStart.year) != true || checkMonth(cb.ngaygioStart.month) != true || checkDay(cb.ngaygioStart.day, cb.ngaygioStart.month) != true) {
						gotoxy(125,17);	SetColor(Color_DarkRed); 	cout<<"NGAY KHOI HANH KHONG DUNG";	SetColor(Color_DarkBlue);
						xacthucNgay = false;
					}
					else if (checkCurrentDDMMYY(cb.ngaygioStart.day, cb.ngaygioStart.month) != true) {
						gotoxy(125,17);	SetColor(Color_DarkRed); 	cout<<"NGAY PHAI LON HON NGAY HIEN TAI";	SetColor(Color_DarkBlue);
						xacthucNgay = false;
					}
				}
			}while(!xacthucNgay);
			gotoxy(118,17); 	cout<<"                                               ";
			
			do{
				char giotemp[3]= "";	char phuttemp[3]="";	char hhmm[6]="";
				xacthucNgay= true;	SetBGColor(Color_DarkWhite);
				NhapLieuso(135,18,gio,5);
				if(gio == "") return 0;
				strcpy(hhmm, gio.c_str());
				gotoxy(118,19); 	cout<<"                                               ";
				if(ngay.length() <5 || (int)hhmm[2] != 58){
					gotoxy(118,19);	SetColor(Color_DarkRed); 	cout<<"GIO KHOI HANH KHONG DUNG. CU PHAP '09:09'";	SetColor(Color_DarkBlue);
					xacthucNgay = false;
				}
				else{
//					strcpy(hhmm, gio.c_str());
					giotemp[0] = hhmm[0];giotemp[1] = hhmm[1];
					phuttemp[0] = hhmm[3];phuttemp[1] = hhmm[4];
					cb.ngaygioStart.hours = atoi(giotemp);
					cb.ngaygioStart.minutes = atoi(phuttemp);
					if (cb.ngaygioStart.hours < 0 || cb.ngaygioStart.hours>23 || cb.ngaygioStart.minutes < 0 || cb.ngaygioStart.minutes>59) {
						gotoxy(110,19); 	cout<<"                                                    ";
						gotoxy(125,19);	SetColor(Color_DarkRed); 	cout<<"GIO KHOI HANH KHONG DUNG";	SetColor(Color_DarkBlue);
						xacthucNgay = false;
					}
					else if (checkTrungChuyenbay(listCB, cb) == false) {
						gotoxy(110,19);	SetColor(Color_DarkRed); 	cout<<"CHUYEN BAY BI TRUNG NGAY GIO KHOI HANH. KIEM TRA LAI";	SetColor(Color_DarkBlue);
						xacthucNgay = true; xacthucNgayGio = false;
					}
				}
			}while(!xacthucNgay);
		}while(!xacthucNgayGio);
		gotoxy(110,19); 	cout<<"                                                    ";
		SetColor(Color_DarkBlue);
		cb.soluongVe = (listMB.nodeMB[search(listMB, cb.sohieumb)]->soday_MB * listMB.nodeMB[search(listMB, cb.sohieumb)]->sohang_MB);
		gotoxy(135, 20);cout << cb.soluongVe;
		cb.trangthai = 1;
		gotoxy(135, 22);cout << staTus[cb.trangthai];
		do{
			key = GetKey();
			if(key == F2) 		return 1;
			else if(key == TAB) xacthuc = false;
			else if(key == ESC)	return 0;
		}while(!(key== ESC || key == F2 || key == TAB));
	}while(!xacthuc);
	return 0;
}
int update_CB(List_CB & listCB, List_MB listMB, CHUYENBAY & cb) {
	
	footerEditMB();		ShowCur(true);
	SetBGColor(Color_DarkWhite);
	bool xacthuc;
	
	SetColor(Color_Back);	vekhungdoi(105,6,30,60);
	SetColor(Color_DarkYellow);
	gotoxy(118,10);	cout<<"MA CHUYEN BAY:";
	gotoxy(118,12);	cout<<"SO HIEU MAY BAY:";
	gotoxy(118,14);	cout<<"NOI DEN:";
	gotoxy(118,16);	cout<<"NGAY KHOI HANH:";
	gotoxy(118,18);	cout<<"GIO KHOI HANH:";
	gotoxy(118,20);	cout<<"SO GHE:";
	gotoxy(118,22);	cout<<"TRANG THAI:";
	SetColor(Color_DarkBlue);
	char shmbTemp[15];
	strcpy(shmbTemp, cb.sohieumb);
	string day 		= Chuyen(cb.ngaygioStart.day);
	string month 	= Chuyen(cb.ngaygioStart.month);
	string year 	= Chuyen(cb.ngaygioStart.year);
	string hours 	= Chuyen(cb.ngaygioStart.hours);
	string minutes 	= Chuyen(cb.ngaygioStart.minutes);
    
	string sohieuMB = cb.sohieumb;
	string noiden	= cb.sanbayDen;
	string ngay		= day + "/" + month + "/" + year;
	string gio 		= hours + ":" + minutes;
	SetColor(Color_Red);
	gotoxy(135 , 10);		cout<<cb.ma_CB;
	gotoxy(135 , 12);		cout<<cb.sohieumb;
	gotoxy(135 , 14);		cout<<cb.sanbayDen;
	gotoxy(135 , 16);		cout<<ngay;
	gotoxy(135 , 18);		cout<<gio;
	gotoxy(135 , 20);		cout<<cb.soluongVe;
	gotoxy(135 , 22);		cout << staTus[cb.trangthai];
	
	do{
		xacthuc =true;
		
		bool xacnhanSHMB;
		do{
			xacnhanSHMB = true;
			vekhungdoi(150,8,20,13);		kengangdoi(150,10,13);
			gotoxy(152,9); 				cout<<"SO HIEU MB";
			int nodeout = frameAddShmb_AddCB(listMB);
			
			if(nodeout == -1){
				gotoxy(posXMessage,posYMessage); cout<<"CHUA CO MAY BAY NAO!";
				getch();	return 0;
			}else if(nodeout == -2){
				return 0;
			}else{
				if (listMB.nodeMB[nodeout]->soday_MB < listMB.nodeMB[search(listMB, shmbTemp)]->soday_MB ||
					listMB.nodeMB[nodeout]->sohang_MB < listMB.nodeMB[search(listMB, shmbTemp)]->sohang_MB){
					gotoxy(118,13); cout<<"SO GHE NHO HON MAY BAY HIEN TAI"; SetBGColor(Color_DarkWhite);
					xacnhanSHMB = false;
				}else{
					sohieuMB = listMB.nodeMB[nodeout]->sohieu_MB;
					strcpy(cb.sohieumb, listMB.nodeMB[nodeout]->sohieu_MB);
					SetColor(Color_DarkBlue);	SetBGColor(Color_DarkWhite);
					gotoxy(135,12); cout<<sohieuMB;
					clearOnePart(150,8,15,21);
				}
			}
		}while(!xacnhanSHMB);
		gotoxy(110,13); cout<<"                                       ";
		
		bool xacthucNgayGio;
		do{
			SetColor(Color_DarkBlue);
			xacthucNgayGio = true;
			bool xacthucNgay;
			do{
				char ngaytemp[3]="";	char thangtemp[3]="";	char namtemp[5]="";	char ddmmyy[11]="";
				xacthucNgay = true;	SetBGColor(Color_DarkWhite);
				NhapLieuso(135,16,ngay,10);
				if(ngay == "") return 0;
				else{
					strcpy(ddmmyy, ngay.c_str());
					ngaytemp[0] = ddmmyy[0];ngaytemp[1] = ddmmyy[1];
					thangtemp[0] = ddmmyy[3];thangtemp[1] = ddmmyy[4];
					namtemp[0] = ddmmyy[6];namtemp[1] = ddmmyy[7];namtemp[2] = ddmmyy[8];namtemp[3] = ddmmyy[9];
					cb.ngaygioStart.day = atoi(ngaytemp);
					cb.ngaygioStart.month = atoi(thangtemp);
					cb.ngaygioStart.year = atoi(namtemp);
					if (checkYear(cb.ngaygioStart.year) != true || checkMonth(cb.ngaygioStart.month) != true || checkDay(cb.ngaygioStart.day, cb.ngaygioStart.month) != true) {
						gotoxy(125,17);	SetColor(Color_DarkRed); 	cout<<"NGAY KHOI HANH KHONG DUNG";	SetColor(Color_DarkBlue);
						xacthucNgay = false;
					}
					else if (checkCurrentDDMMYY(cb.ngaygioStart.day, cb.ngaygioStart.month) != true) {
						gotoxy(125,17);	SetColor(Color_DarkRed); 	cout<<"NGAY PHAI LON HON NGAY HIEN TAI";	SetColor(Color_DarkBlue);
						xacthucNgay = false;
					}
				}
			}while(!xacthucNgay);
			gotoxy(125,17); 	cout<<"                               ";
			
			do{
				char giotemp[3]= "";	char phuttemp[3]="";	char hhmm[6]="";
				xacthucNgay= true;	SetBGColor(Color_DarkWhite);
				NhapLieuso(135,18,gio,5);
				if(gio == "") return 0;
				else{
					strcpy(hhmm, gio.c_str());
					giotemp[0] = hhmm[0];giotemp[1] = hhmm[1];
					phuttemp[0] = hhmm[3];phuttemp[1] = hhmm[4];
					cb.ngaygioStart.hours = atoi(giotemp);
					cb.ngaygioStart.minutes = atoi(phuttemp);
					if (cb.ngaygioStart.hours < 0 || cb.ngaygioStart.hours>23 || cb.ngaygioStart.minutes < 0 || cb.ngaygioStart.minutes>59) {
						gotoxy(110,19); 	cout<<"                                                    ";
						gotoxy(125,19);	SetColor(Color_DarkRed); 	cout<<"GIO KHOI HANH KHONG DUNG";	SetColor(Color_DarkBlue);
						xacthucNgay = false;
					}
					else if (checkTrungChuyenbay(listCB, cb) == false) {
						gotoxy(110,19);	SetColor(Color_DarkRed); 	cout<<"CHUYEN BAY BI TRUNG NGAY GIO KHOI HANH. KIEM TRA LAI";	SetColor(Color_DarkBlue);
						xacthucNgay = true; xacthucNgayGio = false;
					}
				}
			}while(!xacthucNgay);
		}while(!xacthucNgayGio);
		gotoxy(110,19); 	cout<<"                                                    ";
		SetColor(Color_DarkBlue);
		cb.soluongVe = (listMB.nodeMB[search(listMB, cb.sohieumb)]->soday_MB * listMB.nodeMB[search(listMB, cb.sohieumb)]->sohang_MB);
		gotoxy(135, 20);cout << cb.soluongVe;
		cb.trangthai = 1;
		gotoxy(135, 22);cout << staTus[cb.trangthai];
		int key;
		do{
			key = GetKey();
			if(key == F2) 		return 1;
			else if(key == TAB) xacthuc = false;
			else if(key == ESC)	return 0;
		}while(!(key== ESC || key == F2 || key == TAB));
	}while(!xacthuc);
	return 0;
}

//hien thi thong tin node chuyen bay
int showInfo_CB(CHUYENBAY cb, int x) {
	SetBGColor(Color_DarkWhite);SetColor(Color_DarkRed);
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
		message(posXMessage,posYMessage,"DANH SACH MAY BAY RONG");
	}
	else {
		
		Node_CB* p;
		p = listCB.pHead;
		int i = 0;
		
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
	if (listCB.pHead == NULL) {
		message(posXMessage, posYMessage,"DANH SACH CHUYEN BAY RONG");
		return 0;
	}
	else {
		ShowCur(true);
		string temp = "";		char maCB[15];
		SetColor(Color_Back);	vekhungdoi(105,6,30,60);
		SetColor(Color_Yellow);	gotoxy(118,10);	cout<<"MA CHUYEN BAY:";
		bool xacthuc;
		do{
			xacthuc = true; SetColor(Color_DarkBlue);
			nhapMa(135,10,temp, 15);
			if(temp == "") return -1;
			strcpy(maCB,temp.c_str());
			Node_CB* p, * q;
			p = searchInfo(listCB, maCB);//tim va tra ve dia chi cua chuyen bay co ma chuyen bay la maCB
			if (p == NULL) {
				message(posXMessage, posYMessage,"KHONG TIM THAY CHUYEN BAY!");
				xacthuc = false;
			}else if(p->data.trangthai==3){
				message(posXMessage, posYMessage,"CHUYEN BAY DA HOAN TAT");
				xacthuc = false;
			}
			else{
				int choose = alertOption(118,22,"        BAN CO MUON XOA CHUYEN BAY        ","    XOA   ","HUY CHUYEN");
				if(choose==1){
					if(checkTonTaiVe(p->data)==1){// co chuyen bay va da co nguoi dat ve 
						message(posXMessage, posYMessage,"CHUYEN BAY DA CO HANH KHACH");
						xacthuc = false;
					}else{
						if (p == listCB.pHead) {//neu chuyen bay can tim o dau danh sach
							listCB.pHead = p->pNext;
							delete p;
	//						message(posXMessage, posYMessage,"XOA CHUYEN BAY THANH CONG");
	//						SetBGColor(Color_DarkWhite);	showList_CB(listCB);
							return 1;
						}
						else {
							q = listCB.pHead;
							for (q;q->pNext != p && q->pNext != NULL;q = q->pNext) {
							}
							q->pNext = p->pNext;
							delete p;
							return 1;
						}
					}
				}else if(choose == 2){
					p->data.trangthai = 0;
					return 2;
				}else{
					return -1;
				}
			}
		}while(!xacthuc);
	}
}

int editCB(List_CB & listCB, List_MB listMB) {
	if (listCB.pHead == NULL) {
		message(posXMessage, posYMessage,"DANH SACH CHUYEN BAY RONG");
		return 0;
	}
	else {
		ShowCur(true);
		string temp = "";	char maCB[15];
		SetColor(Color_Back);	vekhungdoi(105,6,30,60);
		SetColor(Color_DarkYellow);	gotoxy(118,10);	cout<<"MA CHUYEN BAY:";
		bool xacthuc;
		do{
			xacthuc = true;
			SetColor(Color_DarkBlue);	nhapMa(135,10,temp, 15);
			if(temp == "") return 0;
			strcpy(maCB,temp.c_str());
			Node_CB* p, * q;
			p = searchInfo(listCB, maCB);
			if (p == NULL) {
				message(posXMessage, posYMessage,"KHONG TIM THAY CHUYEN BAY!");
				xacthuc= false;
			}
			if(p->data.trangthai==3){
				message(posXMessage, posYMessage,"KHONG THE CHINH SUA CHUYEN BAY DA HOAN TAT");
				xacthuc= false;
			}
			else {
				CHUYENBAY cbtemp = p->data;
				if (update_CB(listCB, listMB, p->data) == 0)	return 0;
				else {
					if(Hoi(118,30,"   BAN CO MUON THAY DOI THONG TIN CHUYEN BAY KHONG?    ")){
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
						if(checkTonTaiVe(cbtemp)==1){//neu chuyen bay co nguoi dat ve roi thi copy du lieu, khong thi thoi
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
						return 1;
					}else return 0;
				}
			}
		}while(!xacthuc);
	}
}

// them node chuyen bay cho List chuyen bay
void quanLyChuyenBay(List_CB & listCB, List_MB listMB) {
	header();
	CHUYENBAY cb;	int key;
	if (listMB.soluong == 0) {
		clrscr();	header();	footer();
		message(posXMessage,posYMessage, "CHUA CO MAY BAY DE MO CHUYEN BAY");	return;
	}
	else {
		showList_CB(listCB);
		while(true) {
			footerCB();
			ShowCur(false);	key = GetKey();
			switch(key){
				case F1: 
				{
					if (addInfo_CB(listCB, listMB, cb) == 0) {// kiem tra co huy trong qua trinh nhap hay khong
						message(posXMessage,posYMessage, "DA HUY!");	break;
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
						if (listCB.pHead == NULL) {//kiem tra xem dach rong hay kh
							listCB.pHead = p;  //neu rong thi them vao dau danh sach
						}
						else { // neu co phan tu roi thi insertorder
							Node_CB* temp = NULL, * q;
							// SO SANH VOI VI TRI DAU => THEM VAO DAU ELSE THEM SAU VI TRI ?(TIM)
							if (strcmp(listCB.pHead->data.ma_CB, p->data.ma_CB) > 0) {
								p->pNext = listCB.pHead;
								listCB.pHead = p;
							}else{
								for (q = listCB.pHead;q != NULL && strcmp(q->data.ma_CB, p->data.ma_CB) <= 0;q = q->pNext) {
									temp = q;
								}
								p->pNext = q;
								temp->pNext = p;
							}
						}
						showList_CB(listCB);
						message(posXMessage,posYMessage, "DA THEM CHUYEN BAY THANH CONG");
						clearOnePart(106,7,60,28);
						break;
					}
				}
				case F3: {
					if(editCB(listCB, listMB) == 1){
						showList_CB(listCB);
						message(posXMessage, posYMessage,"DA CAP NHAT LAI THONG TIN");
					}else message(posXMessage, posYMessage,"DA HUY");
					clearOnePart(106,7,60,28);	break;
				}
				case F4:{
					int deleteCB = DeleteCB(listCB);
					if(deleteCB == 1){
						showList_CB(listCB);
						message(posXMessage, posYMessage,"XOA CHUYEN BAY THANH CONG");
					}else if(deleteCB == 2){
						showList_CB(listCB);
						message(posXMessage, posYMessage,"HUY CHUYEN BAY THANH CONG");
					}else message(posXMessage, posYMessage,"DA HUY THAO TAC");
					clearOnePart(106,7,60,28);	break;
				}
				case ESC: return;
			}
		}
	}
}
///////////////////////////////////////////////////////////////////// HANH KHACH //////////////////////////////////////////////////////////////////

int showCustomerOfCbXXX(List_CB lcb, NODEHKPTR lhk){
	header();footerDatVe();
	SetColor(Color_Back);	vekhungdoi(110,positionY_listCB,30,50);
	string macb = "";
	ShowCur(true);
	Node_CB* p;
	bool xacthuc;
	do{
		xacthuc = true;
		showList_CB(lcb);
		gotoxy(118,14);	SetColor(Color_DarkYellow);	cout<<"NHAP MA CHUYEN BAY:";
		SetColor(Color_Blue);		nhapMa(140,14,macb,15);
		int soluongchuyenbay=0;
		for (Node_CB* p = lcb.pHead; p != NULL;p = p->pNext){
			if(strcmp(p->data.ma_CB, macb.c_str()) == 0){//tim co chuyen bay 
				soluongchuyenbay++;
				clearOnePart(111,7, 48, 29);// XOA VUNG NHAP LIEU
				SetColor(Color_DarkYellow);
				SetBGColor(Color_DarkWhite);
				gotoxy(135, 8);cout << "THONG TIN VE";
				gotoxy(118, 10);cout << "MA CHUYEN BAY";
				gotoxy(118, 12);cout << "NOI DEN: ";
				gotoxy(118, 14);cout << "NGAY KHOI HANH:";
				gotoxy(118, 16);cout << "GIO KHOI HANH:";
				SetColor(Color_Blue);
				gotoxy(135, 10), cout << p->data.ma_CB;
				switch(checkNoiDen(p->data.sanbayDen)){
					case 0:	{	gotoxy(135, 12), cout << "HO CHI MINH";		break;}
					case 1:	{	gotoxy(135, 12), cout << "HA NOI";			break;}
					case 2:	{	gotoxy(135, 12), cout << "NHA TRANG";		break;}
					case 3:	{	gotoxy(135, 12), cout << "PHU QUOC";		break;}
					case 4:	{	gotoxy(135, 12), cout << "QUY NHON";		break;}
					case 5:	{	gotoxy(135, 12), cout << "HAI PHONG";		break;}
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
				
				clearOnePart(positionX_listCB,positionY_listCB -2, 95, 33 );	// XOA BANG CHUYEN BAY
				
				int A[6]={10,20,35,60};
				SetColor(Color_Back);
				table(20 ,positionY_listCB , 30, 72, 4, A);
				gotoxy(24, positionY_listCB + 1); 	cout<<"STT";
				gotoxy(32, positionY_listCB + 1); 	cout<<"SO GHE";
				gotoxy(44, positionY_listCB + 1); 	cout<<"SO CMND";
				gotoxy(62, positionY_listCB + 1); 	cout<<"HO VA TEN";
				gotoxy(82, positionY_listCB + 1); 	cout<<"GIOI TINH";
				NODEHKPTR nodehk; int y = 0;
				for (int i = 0;i < p->data.soluongVe;i++) {
					if (p->data.nodeVe[i].cmnd != " ") {
						nodehk = Search(lhk, p->data.nodeVe[i].cmnd);
						if(nodehk!=NULL){
							gotoxy(24, dongStartHK + y);cout << (y + 1);
							gotoxy(34, dongStartHK + y);cout << p->data.nodeVe[i].soghe;
							gotoxy(43, dongStartHK + y);cout << nodehk->data.cmnd;
							gotoxy(58, dongStartHK + y);cout << nodehk->data.ho << " " << nodehk->data.ten;
							gotoxy(85, dongStartHK + y);cout << sex[nodehk->data.gioiTinh];
							y++;
						}else{
							gotoxy(24, dongStartHK + y);cout << (y + 1);
							gotoxy(34, dongStartHK + y);cout << p->data.nodeVe[i].soghe;
							gotoxy(43, dongStartHK + y);cout << p->data.nodeVe[i].cmnd;
							gotoxy(58, dongStartHK + y);cout << "NULL";
							gotoxy(85, dongStartHK + y);cout << "NULL";
							y++;
						}
					}
				}
				break;
			}	
		}
		// SAI MA
		if(soluongchuyenbay==0){
			if(Hoi(115, 20, "  MA CHUYEN BAY KHONG TON TAI. NHAP LAI?   ")){
				xacthuc = false;
				clearOnePart(111,7,48,28);
			}else return 0;
		}else if(Hoi(118 ,20, "  BAN CO MUON XEM CHUYEN BAY KHAC KHONG?   ")){
			xacthuc = false;
			clearOnePart(111,7,48,28);
		}else return 0;
	}while(!xacthuc);
}


	/////////////////////////////////////////////////////////////////// DAT VE /////////////////////////////////////////////////////////////////////
void thongTinVeVuaDat(Node_CB *cb,HANHKHACH hk, string soghe){
	clearOnePart(111,7, 48, 29);	
	thongTinVe();
	SetColor(Color_Blue);
	gotoxy(135, 10), cout << cb->data.ma_CB;
	switch(checkNoiDen(cb->data.sanbayDen)){
		case 0:	{	gotoxy(135, 12), cout << "HO CHI MINH";		break;}
		case 1:	{	gotoxy(135, 12), cout << "HA NOI";			break;}
		case 2:	{	gotoxy(135, 12), cout << "NHA TRANG";		break;}
		case 3:	{	gotoxy(135, 12), cout << "PHU QUOC";		break;}
		case 4:	{	gotoxy(135, 12), cout << "QUY NHON";		break;}
		case 5:	{	gotoxy(135, 12), cout << "HAI PHONG";		break;}
	}
	if (cb->data.ngaygioStart.day < 10) {
		gotoxy(135, 14);cout << "0";
		gotoxy(136, 14);cout << cb->data.ngaygioStart.day << "/";
	}
	else {
		gotoxy(135, 14);cout << cb->data.ngaygioStart.day << "/";
	}
	//thang
	if (cb->data.ngaygioStart.month < 10) {
		gotoxy(138, 14);cout << "0";
		gotoxy(139, 14);cout << cb->data.ngaygioStart.month << "/";
	}
	else {
		gotoxy(138, 14);cout << cb->data.ngaygioStart.month << "/";
	}
	//nam
	gotoxy(141, 14);cout << cb->data.ngaygioStart.year;
	//gio
	if (cb->data.ngaygioStart.hours < 10) {
		gotoxy(135, 16);cout << "0";
		gotoxy(136, 16);cout << cb->data.ngaygioStart.hours << ":";
	}
	else {
		gotoxy(135, 16);cout << cb->data.ngaygioStart.hours << ":";
	}
	//phut
	if (cb->data.ngaygioStart.minutes < 10) {
		gotoxy(139, 16);cout << "0";
		gotoxy(140, 16);cout << cb->data.ngaygioStart.minutes;
	}
	else {
		gotoxy(139, 16);cout << cb->data.ngaygioStart.minutes;
	}
	////
//	int vitrighe = checkCoCMND(cb->data, cmnd);
	gotoxy(135, 18); cout << soghe;
	gotoxy(122, 20); cout << hk.ho;
	gotoxy(148, 20); cout << hk.ten;
	gotoxy(135, 22); cout << hk.cmnd;
	gotoxy(135, 24); cout << sex[hk.gioiTinh];
}
	
int datVe(List_CB & list_CB, List_MB listMB, NODEHKPTR & lHK) {
	header();footerDatVe();
	SetBGColor(Color_DarkWhite);	frameSanbayDen();
	SetColor(Color_DarkYellow);
	gotoxy(118,10);		cout<<"NOI DEN: ";
	gotoxy(118,12);		cout<<"THANG: ";
	gotoxy(138,12);		cout<<"NGAY: ";
	
	ShowCur(true);	int vitri = 0;
	char noiden[4];	string noidenTemp = "";
	int thang = 0,	ngay = 0;
	do{
		showList_CB(list_CB);
		do{
			SetColor(Color_Blue);
			nhapMa(135,10,noidenTemp, 3);
			if(noidenTemp == "") return 0;
			strcpy(noiden, noidenTemp.c_str());
			if (checkNoiDen(noiden) == -1) {
				gotoxy(125,11); SetColor(Color_DarkRed); cout<<"NOI DEN KHONG PHU HOP";
			}
		}while(checkNoiDen(noiden) == -1);
		gotoxy(125,11);		cout<<"                     ";
		do{
			SetColor(Color_Blue);
			NhapLieuSo(128,12,thang,2);
			if(thang == 0) return 0;
			if (checkMonth(thang) == false ) {
				gotoxy(118,13); SetColor(Color_DarkRed); cout<<"THANG KHONG HOP LE";
			}
		}while(checkMonth(thang) == false);
		gotoxy(118,13);		cout<<"                  ";
		do{
			SetColor(Color_Blue);
			NhapLieuSo(148,12,ngay,2);
			if(ngay == 0) return 0;
			if (checkDay(ngay, thang) == false || checkCurrentDDMMYY(ngay, thang) == false) {
				gotoxy(138,13); SetColor(Color_DarkRed); cout<<"NGAY KHONG HOP LE";
			}
		}while(checkDay(ngay, thang) == false || checkCurrentDDMMYY(ngay, thang) == false);
		gotoxy(138,13);		cout<<"                 ";
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
		for (Node_CB* p = list_CB.pHead;p != NULL;p = p->pNext) {
			if (strcmp(p->data.sanbayDen, noiden) == 0 && p->data.ngaygioStart.month == thang && p->data.ngaygioStart.day == ngay && checkConVe(p->data) != 0 && p->data.trangthai!=0) {
				showInfo_CB(p->data, vitri);
				vitri++;
			}
		}
		if (vitri == 0 && !Hoi(118,18," KHONG CO CHUYEN BAY PHU HOP, NHAP LAI? ")) return 0;
	}while(vitri == 0);
	// CO CHUYEN BAY THOA DIEU KIEN
	char macbtemp[15];	string macb = "";
	Node_CB* p;
	do{
		gotoxy(118,14);	SetColor(Color_DarkYellow);	cout<<"NHAP MA CHUYEN BAY:";
		SetColor(Color_Blue);	nhapMa(140,14,macb,15);
		if(macb == "") return 0;
		strcpy(macbtemp, macb.c_str());
		p = searchInfo(list_CB, macbtemp);
		if (p == NULL || p->data.ngaygioStart.day != ngay || p->data.ngaygioStart.month != thang || p->data.trangthai != 1) {
			gotoxy(130,15); SetColor(Color_DarkRed); cout<<"CHUYEN BAY KHONG HOP LE";
		}else{
			// SO DO CHO NGOI
			clearOnePart(positionX_listCB,positionY_listCB -2, 95, 33 );	
			SetColor(Color_Back);
			int x = 10, y = positionY_listCB;
			int sonode = 0;
			gotoxy(25, 4);SetBGColor(Color_Cyan);cout << "GHE TRONG";
			gotoxy(45, 4);SetBGColor(Color_Yellow);cout << "GHE DA DAT";
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
		}
		
	}while(p == NULL || p->data.ngaygioStart.day != ngay || p->data.ngaygioStart.month != thang || p->data.trangthai != 1);
		
	string cmndtemp; SetBGColor(Color_DarkWhite);
	// NHAP CMND
	bool nhapCMND;
	NODEHKPTR nodehk;
	do{
		nhapCMND = true;
		gotoxy(118,16); SetColor(Color_DarkYellow);	cout<<"NHAP CMND:";
		SetColor(Color_Blue);
		NhapLieuso(135,16, cmndtemp, 9);
		if(cmndtemp=="") return 0;
		if(cmndtemp.length() < 9){
			nhapCMND = false;
			gotoxy(125,17);	SetColor(Color_DarkRed); cout<<"SO CMND PHAI CO 9 KY TU";
		}else{
			nodehk = Search(lHK, cmndtemp);
			if (nodehk != NULL && checkCoCMND(p->data, cmndtemp) == -1) {//co hanh khach trong ds hanh khac va chua co trong ds ve cua chuyen bay thi cho dat ve
				
				// THONG TIN KHACH HANG DA CO TRONG DL
				SetColor(Color_DarkYellow);
				gotoxy(128, 25);cout << "THONG TIN KHACH HANG";
				gotoxy(118, 27);cout << "CMND:";
				gotoxy(118, 29);cout << "HO:";
				gotoxy(118, 31);cout << "TEN:";
				gotoxy(118, 33);cout << "GIOI TINH:";
				SetColor(Color_Blue);
				gotoxy(135, 27);cout << nodehk->data.cmnd;
				gotoxy(135, 29);cout << nodehk->data.ho;
				gotoxy(135, 31);cout << nodehk->data.ten;
				gotoxy(135, 33);cout << sex[nodehk->data.gioiTinh];
				// CHON GHE
				bool xacThucVe;
				string soghetemp = "";
				do{
					xacThucVe = true;
					SetColor(Color_DarkYellow);
					SetBGColor(Color_DarkWhite);
					gotoxy(118, 35);cout << "NHAP SO GHE:";
					nhapMa(135,35,soghetemp,3);
					if(soghetemp == "") return 0;
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
						// XUAT THONG TIN VUA NHAP
						thongTinVeVuaDat(p, nodehk->data, soghetemp);
						
							// HIEN VE VUA DAT
						int position = checkCoGHE(p->data, soghetemp);
						gotoxy(65, 4);	SetColor(Color_Back);	SetBGColor(Color_Grey);cout << "VE VUA DAT";
						int posX = 10 + ((position+1) / (listMB.nodeMB[search(listMB, p->data.sohieumb)]->sohang_MB)) * 10;
						int posY = (position+1) % (listMB.nodeMB[search(listMB, p->data.sohieumb)]->sohang_MB)+ positionY_listCB - 1;
						if((position+1) % (listMB.nodeMB[search(listMB, p->data.sohieumb)]->sohang_MB) == 0){
							posX -=10;
							posY +=listMB.nodeMB[search(listMB, p->data.sohieumb)]->sohang_MB;
						}
						gotoxy(posX, posY);	SetColor(Color_Back);	SetBGColor(Color_Grey); cout<<soghetemp;
							
						// XAC NHAN CO DAT VE HAY KHONG
						if (Hoi(118,26,"         BAN CO MUON DAT VE KHONG?         ")) {
							p->data.nodeVe[position].cmnd = cmndtemp; /////////// DAT VE THANH CONG
							if(checkConVe(p->data)==0){
								p->data.trangthai=2;
							}
							message(posXMessage,posYMessage,"DAT VE THANH CONG!");
							return 1;
						}
						else{
							message(posXMessage,posYMessage,"HUY DAT VE");
							return 0;
						}
					}
				}while(!xacThucVe);
			}
			// KHACH HANG DA MUA VE
			else if (checkCoCMND(p->data, cmndtemp) != -1) {
				if(Hoi(118,18,"    SO CMND NAY DA DAT VE. NHAP LAI?      ")){
					nhapCMND = false;
				}else	return 0;
			}
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
			if(ho == "") return 0;
			hkmoi.ho = ho;
		}while(ho == "");
		
	//nhap ten
		do{
			NhapLieu(135,30,ten, 15);
			if(ten == "") return 0;
			hkmoi.ten = ten;
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
		// NHAP SO GHE CAN DAT 
		string soghetemp = "";
		bool xacThucVe;
		do{
			xacThucVe = true;
			SetColor(Color_DarkYellow);	SetBGColor(Color_DarkWhite);	gotoxy(118, 34);	cout << "NHAP SO GHE:";
			SetColor(Color_Blue); 	nhapMa(135,34,soghetemp,4);
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
				// XUAT THONG TIN CUA VE DANG DAT
				thongTinVeVuaDat(p, hkmoi, soghetemp);
				
//				thongTinVeVuaDat(p, nodehk->data, soghetemp);
				int position = checkCoGHE(p->data, soghetemp);
				gotoxy(65, 4);	SetColor(Color_Back);	SetBGColor(Color_Grey);cout << "VE VUA DAT";
				int posX = 10 + ((position+1) / (listMB.nodeMB[search(listMB, p->data.sohieumb)]->sohang_MB)) * 10;
				int posY = (position+1) % (listMB.nodeMB[search(listMB, p->data.sohieumb)]->sohang_MB)+ positionY_listCB - 1;
				if((position+1) % (listMB.nodeMB[search(listMB, p->data.sohieumb)]->sohang_MB) == 0){
					posX -=10;
					posY +=listMB.nodeMB[search(listMB, p->data.sohieumb)]->sohang_MB;
				}
				gotoxy(posX, posY);	SetColor(Color_Back);	SetBGColor(Color_Grey); cout<<soghetemp;
				// XAC NHAN CO DAT VE HAY KHONG
				if (Hoi(118,28,"        BAN CO MUON DAT VE KHONG?       ")) {
//					int position = checkCoGHE(p->data, soghetemp);
					p->data.nodeVe[position].cmnd = cmndtemp; /////////// DAT VE THANH CONG
					InsertHanhKhach(lHK, hkmoi);
					if(checkConVe(p->data)==0){
						p->data.trangthai=2;
					}		
					message(posXMessage,posYMessage,"DAT VE THANH CONG!");
					return 1;
				}
				else{
					message(posXMessage,posYMessage,"DA HUY DAT VE");
					return 0;
				}//XAC NHAN DAT VE
			}//XUAT THONG TIN VE
		}while(!xacThucVe); //CHON VE
	}//KHACH HNAG CHUA CO THONG TIN
}
// THONG TIN CHO NGUOI CUA CHUYEN BAY VA VE CAN HUY

int thongTinVeVaChoNgoi(Node_CB *cb, List_MB listMB,NODEHKPTR kh, string cmnd){
	SetColor(Color_Back);
	int x = 10, y = positionY_listCB;
	int sonode = 0;
	gotoxy(25, 4);SetBGColor(Color_Cyan);cout << "GHE TRONG";
	gotoxy(45, 4);SetBGColor(Color_Yellow);cout << "GHE DA DAT";
	gotoxy(65, 4);SetBGColor(8);cout << "VE MUON HUY";
	for (int i = 0;i < listMB.nodeMB[search(listMB, cb->data.sohieumb)]->soday_MB;i++) {
		for (int j = 0;j < listMB.nodeMB[search(listMB, cb->data.sohieumb)]->sohang_MB;j++) {
			gotoxy(x, y);
			if (cb->data.nodeVe[sonode].cmnd == " ") {
				SetBGColor(Color_Cyan);
				cout << cb->data.nodeVe[sonode].soghe;
			}
			else if (cb->data.nodeVe[sonode].cmnd == cmnd) {
				SetBGColor(8);
				cout << cb->data.nodeVe[sonode].soghe;
			}
			else {
				SetBGColor(Color_Yellow);
				cout << cb->data.nodeVe[sonode].soghe;
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
	gotoxy(135, 10), cout << cb->data.ma_CB;
	switch(checkNoiDen(cb->data.sanbayDen)){
		case 0:	{	gotoxy(135, 12), cout << "HO CHI MINH";		break;}
		case 1:	{	gotoxy(135, 12), cout << "HA NOI";			break;}
		case 2:	{	gotoxy(135, 12), cout << "NHA TRANG";		break;}
		case 3:	{	gotoxy(135, 12), cout << "PHU QUOC";		break;}
		case 4:	{	gotoxy(135, 12), cout << "QUY NHON";		break;}
		case 5:	{	gotoxy(135, 12), cout << "HAI PHONG";		break;}
	}
	if (cb->data.ngaygioStart.day < 10) {
		gotoxy(135, 14);cout << "0";
		gotoxy(136, 14);cout << cb->data.ngaygioStart.day << "/";
	}
	else {
		gotoxy(135, 14);cout << cb->data.ngaygioStart.day << "/";
	}
	//thang
	if (cb->data.ngaygioStart.month < 10) {
		gotoxy(138, 14);cout << "0";
		gotoxy(139, 14);cout << cb->data.ngaygioStart.month << "/";
	}
	else {
		gotoxy(138, 14);cout << cb->data.ngaygioStart.month << "/";
	}
	//nam
	gotoxy(141, 14);cout << cb->data.ngaygioStart.year;
	//gio
	if (cb->data.ngaygioStart.hours < 10) {
		gotoxy(135, 16);cout << "0";
		gotoxy(136, 16);cout << cb->data.ngaygioStart.hours << ":";
	}
	else {
		gotoxy(135, 16);cout << cb->data.ngaygioStart.hours << ":";
	}
	//phut
	if (cb->data.ngaygioStart.minutes < 10) {
		gotoxy(139, 16);cout << "0";
		gotoxy(140, 16);cout << cb->data.ngaygioStart.minutes;
	}
	else {
		gotoxy(139, 16);cout << cb->data.ngaygioStart.minutes;
	}
	////
	int vitrighe = checkCoCMND(cb->data, cmnd);
	gotoxy(135, 18); cout << cb->data.nodeVe[vitrighe].soghe;
	gotoxy(122, 20); cout << kh->data.ho;
	gotoxy(148, 20); cout << kh->data.ten;
	gotoxy(135, 22); cout << cmnd;
	gotoxy(135, 24); cout << sex[kh->data.gioiTinh];		
	return vitrighe;
}

int huyVe(List_CB &list_CB, List_MB list_MB, NODEHKPTR listKH) {
	header();footerDatVe();
	SetBGColor(Color_DarkWhite);	frameSanbayDen();
	SetColor(Color_DarkYellow);
	gotoxy(118,10);		cout<<"NOI DEN: ";
	gotoxy(118,12);		cout<<"THANG: ";
	gotoxy(138,12);		cout<<"NGAY: ";
	ShowCur(true);		int soCbDaDatVe = 0;
	char noiden[4];		string noidenTemp = "";
	int thang = 0,		ngay = 0;
	bool xacNhanNoiDen;
	Node_CB* cbDuyNhat;
	string cmndtemp = "";
	NODEHKPTR nodehkDatVe;
	do{
		xacNhanNoiDen = true;
		do{
			SetColor(Color_Blue);
			fflush(stdin);
			nhapMa(135,10,noidenTemp, 3);
			if(noidenTemp == "")	return 0;
			strcpy(noiden, noidenTemp.c_str());
			if (checkNoiDen(noiden) == -1) {
				gotoxy(125,11); SetColor(Color_DarkRed); cout<<"NOI DEN KHONG PHU HOP";
			}
		}while(checkNoiDen(noiden) == -1);
		
		gotoxy(125,11); SetColor(Color_DarkRed); 		 cout<<"                     ";
		do{
			SetColor(Color_Blue);
			NhapLieuSo(128,12,thang,2);
			if(thang == 0) return 0;
			if (checkMonth(thang) == false ) {
				gotoxy(118,13); SetColor(Color_DarkRed); cout<<"THANG KHONG HOP LE";
			}
		}while(checkMonth(thang) == false);
		gotoxy(118,13);	cout<<"                  ";
		do{
			SetColor(Color_Blue);
			NhapLieuSo(148,12,ngay,2);
			if(ngay == 0) return 0;
			if (checkDay(ngay, thang) == false || checkCurrentDDMMYY(ngay, thang) == false) {
				gotoxy(138,13); SetColor(Color_DarkRed); cout<<"NGAY KHONG HOP LE";
			}
		}while(checkDay(ngay, thang) == false || checkCurrentDDMMYY(ngay, thang) == false);
		gotoxy(138,13);	cout<<"                 ";
		//NHAP CMND
		bool xacThucCMND;
		do{
			xacThucCMND = true;
			gotoxy(118,14); SetColor(Color_DarkYellow);	cout<<"NHAP CMND:";
			SetColor(Color_Blue);
			NhapLieuso(135,14, cmndtemp, 9);
			if(cmndtemp=="") return 0;
			if(cmndtemp.length() < 9){
				xacThucCMND = false;
				gotoxy(125,15);	SetColor(Color_DarkRed); cout<<"SO CMND PHAI CO 9 KY TU";
			}else{
			///// kiem tra khach hang co trong ds hanh khach chua, neu chua thi bao chu dat ve
				nodehkDatVe = Search(listKH, cmndtemp);
				if (nodehkDatVe == NULL){
					if(Hoi(118,18,"  KHONG CO DU LIEU KHACH HANG.NHAP LAI?  ")){
						xacThucCMND = false;
					}else return 0;
				}
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
		
		for (Node_CB* p = list_CB.pHead;p != NULL;p = p->pNext) {
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
	// KHACH HANG CHI DAT 1 VE
	if (soCbDaDatVe == 1) {
		clearOnePart(positionX_listCB,positionY_listCB -2, 95, 33 );
		int position = thongTinVeVaChoNgoi(cbDuyNhat, list_MB, nodehkDatVe, cmndtemp);
		
//			gotoxy(65, 4);SetBGColor(Color_Grey);cout << "VE VUA DAT";
//			int posX = 10 + ((position+1) / (list_MB.nodeMB[search(list_MB, cbDuyNhat->data.sohieumb)]->sohang_MB)) * 10;
//			int posY = (position+1) % (list_MB.nodeMB[search(list_MB, cbDuyNhat->data.sohieumb)]->sohang_MB)+ positionY_listCB - 1;
//			gotoxy(posX, posY);	SetBGColor(Color_Cyan);	SetColor(Color_Back); cout << cbDuyNhat->data.nodeVe[position].soghe;
		if (Hoi(118,29,"   BAN CO CHAC CHAN MUON HUY VE KHONG?   ")) {
			cbDuyNhat->data.nodeVe[position].cmnd = " ";
			if(checkConVe(cbDuyNhat->data)!=0){
				cbDuyNhat->data.trangthai=1;
			}
			message(posXMessage,posYMessage,"DA HUY VE THANH CONG");
			return 1;
		}else{
			return 0;
		}
	}
	if (soCbDaDatVe > 1) {
		
		char macbtemp[15];
		Node_CB* cbCanHuy;
		string macb = "";
		bool xacNhanMaCB;
		do{
			xacNhanMaCB = true;
			gotoxy(118,16);	SetColor(Color_DarkYellow);	cout<<"NHAP MA CHUYEN BAY:";
			SetColor(Color_Blue);		nhapMa(140,16,macb,15);
			if(macb == "") return 0;
			strcpy(macbtemp, macb.c_str());
			cbCanHuy = searchInfo(list_CB, macbtemp);
			if (cbCanHuy == NULL || cbCanHuy->data.ngaygioStart.day != ngay || cbCanHuy->data.ngaygioStart.month != thang || cbCanHuy->data.trangthai == 0 || cbCanHuy->data.trangthai == 3 || checkCoCMND(cbCanHuy->data, cmndtemp) == -1) {
				gotoxy(130,15); SetColor(Color_DarkRed); cout<<"CHUYEN BAY KHONG HOP LE";
				xacNhanMaCB = false;
			}else{
				
				showInfo_CB(cbCanHuy->data, 0);
				clearOnePart(positionX_listCB,positionY_listCB -2, 95, 33 );	
				// XUAT SO DO MAY BAY
				int position = thongTinVeVaChoNgoi(cbCanHuy, list_MB, nodehkDatVe, cmndtemp);
				// VE MUON HUY
				gotoxy(65, 4);SetBGColor(Color_Grey);cout << "VE VUA DAT";
				int posX = 10 + ((position+1) / (list_MB.nodeMB[search(list_MB, cbDuyNhat->data.sohieumb)]->sohang_MB)) * 10;
				int posY = (position+1) % (list_MB.nodeMB[search(list_MB, cbDuyNhat->data.sohieumb)]->sohang_MB)+ positionY_listCB - 1;
				
				if((position+1) % (list_MB.nodeMB[search(list_MB, cbDuyNhat->data.sohieumb)]->sohang_MB) == 0){
					posX -=10;
					posY +=list_MB.nodeMB[search(list_MB, cbDuyNhat->data.sohieumb)]->sohang_MB;
				}
				gotoxy(posX, posY);	SetBGColor(Color_Cyan);	SetColor(Color_Back); cout << cbDuyNhat->data.nodeVe[position].soghe;
							
				if (Hoi(118,29,"   BAN CO CHAC CHAN MUON HUY VE KHONG?   ")) {
					cbCanHuy->data.nodeVe[position].cmnd = " ";
					if(checkConVe(cbCanHuy->data)!=0){
						cbCanHuy->data.trangthai=1;
					}
					message(posXMessage,posYMessage,"DA HUY VE THANH CONG");
					return 1;
				}else	return 0;
			}
		}while(!xacNhanMaCB);
	}
}

// cau F
int TimCBConve(List_CB list_CB){
	header();footerDatVe();
	SetBGColor(Color_DarkWhite);
	frameSanbayDen();
	SetColor(Color_DarkYellow);
	gotoxy(118,10);		cout<<"NOI DEN: ";
	gotoxy(118,12);		cout<<"THANG: ";
	gotoxy(138,12);		cout<<"NGAY: ";
	ShowCur(true);
	
	int vitri = 0;
	char noiden[4];
	int thang = 0;
	int ngay = 0;
	string noidenTemp = "";
	do{
		do{
			SetColor(Color_Blue);
			fflush(stdin);
			nhapMa(135,10,noidenTemp, 3);
			if(noidenTemp == "") return 0;
			strcpy(noiden, noidenTemp.c_str());
			if (checkNoiDen(noiden) == -1) {
				gotoxy(125,11); SetColor(Color_DarkRed); cout<<"NOI DEN KHONG PHU HOP";
			}
		}while(checkNoiDen(noiden) == -1);
		gotoxy(125,11); SetColor(Color_DarkRed); 		 cout<<"                     ";
		do{
			SetColor(Color_Blue);
			NhapLieuSo(128,12,thang,2);
			if(thang == 0) return 0;
			if (checkMonth(thang) == false ) {
				gotoxy(118,13); SetColor(Color_DarkRed); cout<<"THANG KHONG HOP LE";
			}
		}while(checkMonth(thang) == false);
		gotoxy(118,13); SetColor(Color_DarkRed); 		 cout<<"                  ";
		do{
			SetColor(Color_Blue);
			NhapLieuSo(148,12,ngay,2);
			if(ngay == 0) return 0;
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
		for (Node_CB* p = list_CB.pHead;p != NULL;p = p->pNext) {
			if (strcmp(p->data.sanbayDen, noiden) == 0 && p->data.ngaygioStart.month == thang && p->data.ngaygioStart.day == ngay && checkConVe(p->data) != 0) {
				showInfo_CB(p->data, vitri);
				vitri++;
			}
		}
		if (vitri == 0) {
			if (!Hoi(118,18," KHONG CO CHUYEN BAY PHU HOP, NHAP LAI? ")) return 0;
		}
	}while(vitri == 0);
	GetKey();
	return 1;
	
}
int danhSachVe(List_CB lcb, List_MB list_MB){
	header();footerDatVe();
	SetColor(Color_Back);
	vekhungdoi(110,positionY_listCB,30,50);
	ShowCur(true);
	char macbtemp[15];
	Node_CB* p;
	string macb = "";
	bool xacthuc;
	do{	
		showList_CB(lcb);
		xacthuc = true;
		gotoxy(118,14);	SetColor(Color_DarkYellow);	cout<<"NHAP MA CHUYEN BAY:";
		SetColor(Color_Blue);		nhapMa(140,14,macb,15);
		if(macb == "") return 0;
		strcpy(macbtemp, macb.c_str());
		int soluongchuyenbay=0;
		for (Node_CB* p = lcb.pHead; p != NULL;p = p->pNext){
			if(strcmp(p->data.ma_CB, macbtemp) == 0){//tim co chuyen bay 
				frameSanbayDen();
				soluongchuyenbay++;
				clearOnePart(111,7, 48, 29);// XOA VUNG NHAP LIEU
				SetColor(Color_DarkYellow);
				SetBGColor(Color_DarkWhite);
				gotoxy(135, 8);cout << "THONG TIN VE";
				gotoxy(118, 10);cout << "MA CHUYEN BAY";
				gotoxy(118, 12);cout << "NOI DEN: ";
				gotoxy(118, 14);cout << "NGAY KHOI HANH:";
				gotoxy(118, 16);cout << "GIO KHOI HANH:";
				SetColor(Color_Blue);
				gotoxy(135, 10), cout << p->data.ma_CB;
				switch(checkNoiDen(p->data.sanbayDen)){
					case 0:	{	gotoxy(135, 12), cout << "HO CHI MINH";		break;}
					case 1:	{	gotoxy(135, 12), cout << "HA NOI";			break;}
					case 2:	{	gotoxy(135, 12), cout << "NHA TRANG";		break;}
					case 3:	{	gotoxy(135, 12), cout << "PHU QUOC";		break;}
					case 4:	{	gotoxy(135, 12), cout << "QUY NHON";		break;}
					case 5:	{	gotoxy(135, 12), cout << "HAI PHONG";		break;}
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
				clearOnePart(positionX_listCB,positionY_listCB -2, 95, 33 );	// XOA BANG CHUYEN BAY
				SetColor(Color_Back);
				int x = 6, y = positionY_listCB;
				int sonode = 0;
				gotoxy(25, 4);SetBGColor(Color_Cyan);cout << "GHE TRONG";
				gotoxy(45, 4);SetBGColor(Color_Yellow);cout << "GHE DA DAT";
				for (int i = 0;i < list_MB.nodeMB[search(list_MB, p->data.sohieumb)]->soday_MB;i++) {
					for (int j = 0;j < list_MB.nodeMB[search(list_MB, p->data.sohieumb)]->sohang_MB;j++) {
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
				break;
			}	
		}
		
		// SAI MA CHUYEN BAY
		if(soluongchuyenbay==0){
			if(Hoi(115, 20, "  MA CHUYEN BAY KHONG TON TAI. NHAP LAI?   ")){
				xacthuc = false;
			}else return 0;
		}else if(Hoi(118 ,20, "  BAN CO MUON XEM CHUYEN BAY KHAC KHONG?   ")){
			xacthuc = false;
			clearOnePart(111,7,50,30);
		}else return 0;
		gotoxy(10,4); cout<<"                                                     ";
	}while(!xacthuc);
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
//doc file khach hang
void LoadDataHanhKhach(NODEHKPTR &lhk)
{
    fstream Data;
    string line;
    
    Data.open("Danhsachhanhkhach.txt",ios::in);
    if (  !Data   )    exit(1);
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
			        case 0:	temp.cmnd = s;	break;
			        case 1:	temp.ho=s;		break;
			        case 2:	temp.ten=s;		break;
			        case 3:	temp.gioiTinh=atoi(s.c_str());	break;
		        }
		        i++;
		    }
			InsertHanhKhach(lhk,temp);
    	}
    }
    Data.close();
    return;
}

// doc 1 chuyen bay
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
	for(int i=0;i<cb.soluongVe;i++){
		getline(fileCbIn,cb.nodeVe[i].soghe,'-');
		getline(fileCbIn,cb.nodeVe[i].cmnd,',');
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
// doc list chuyen bay
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

void saveFileList_CB(List_CB lcb){
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
// SAVE FILE KHACH HANG
void SaveData(fstream &Data, NODEHKPTR lhk) {
	
	if (lhk != NULL) {
		
		HANHKHACH temp;
		temp = lhk->data;
		
		Data << temp.cmnd << ","
        << temp.ho << ","
        << temp.ten << ","
        << temp.gioiTinh<< endl;
        
		SaveData(Data, lhk->Left);
        
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


void DuyetDSHK(NODEHKPTR listhk)//SHOW TAT CAC CAC HANH KHACH CO TRONG DANH SACH
{
     if(listhk!=NULL)
     {
      DuyetDSHK(listhk->Left);
      ///show thong tin
      cout<<listhk->data.cmnd<<endl;
      cout<<listhk->data.ho<<" "<<listhk->data.ten<<endl;
      cout<<listhk->data.gioiTinh<<endl;
      
      DuyetDSHK(listhk->Right);
     }
}
//void DuyetDSHK(NODEHKPTR listhk)//SHOW TAT CAC CAC HANH KHACH CO TRONG DANH SACH
//{
////	int A[6]={10,20,35,60};
////	SetColor(Color_Back);
////	table(20 ,positionY_listCB , 30, 72, 4, A);
////	gotoxy(24, positionY_listCB + 1); 	cout<<"STT";
////	gotoxy(32, positionY_listCB + 1); 	cout<<"SO GHE";
////	gotoxy(44, positionY_listCB + 1); 	cout<<"SO CMND";
////	gotoxy(62, positionY_listCB + 1); 	cout<<"HO VA TEN";
////	gotoxy(82, positionY_listCB + 1); 	cout<<"GIOI TINH";
//	if(listhk!=NULL)
//	{
//		DuyetDSHK(listhk->Left);
////		///show thong tin
////		gotoxy(24, dongStartHK + y);cout << (y + 1);
////		gotoxy(34, dongStartHK + y);cout << soghe;
////		gotoxy(43, dongStartHK + y);cout << data.cmnd;
////		gotoxy(58, dongStartHK + y);cout << data.ho << " " << data.ten;
////		gotoxy(85, dongStartHK + y);cout << sex[data.gioiTinh];
//		
//		cout<<listhk->data.cmnd<<endl;
//		cout<<listhk->data.ho<<" "<<listhk->data.ten<<endl;
//		cout<<listhk->data.gioiTinh<<endl;
//		
//		DuyetDSHK(listhk->Right);
//	}
//}
void duyetKH(NODEHKPTR listhk){
	
	int A[3]={10,25,50};
	SetColor(Color_Back);
	table(30 ,positionY_listCB , 30, 62, 3, A);
	gotoxy(34, positionY_listCB + 1); 	cout<<"STT";
	gotoxy(44, positionY_listCB + 1); 	cout<<"SO CMND";
	gotoxy(62, positionY_listCB + 1); 	cout<<"HO VA TEN";
	gotoxy(82, positionY_listCB + 1); 	cout<<"GIOI TINH";
	NODEHKPTR Stack[100];
	int sp = -1;
	NODEHKPTR p = listhk;
	int y =0;
	do{
		while(p!= NULL)
		{
			Stack[++sp] = p;
			p = p->Left;
		}
		if(sp != -1){
			p = Stack[sp--];
			gotoxy(34, dongStartHK + y);cout << (y + 1);
				gotoxy(43, dongStartHK + y);cout << p->data.cmnd;
				gotoxy(58, dongStartHK + y);cout << p->data.ho << " " << p->data.ten;
				gotoxy(85, dongStartHK + y);cout << sex[p->data.gioiTinh];
				y++;
			p = p->Right;
		}else break;
	}while(1);
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
void RootMenu(List_MB &list_MB, List_CB &list_CB, NODEHKPTR &list_HK) {
	int choice;
	int choiceMenuCon;
	openFileList_MB(list_MB);
	LoadDataHanhKhach(list_HK);
	openFileList_CB(list_CB,list_MB);
	while (true) {
		ShowCur(false);			SetBGColor(Color_DarkWhite);	clrscr();
		choice = mainMenu();	SetBGColor(Color_DarkWhite);
		switch (choice) {
			//  QUAN LY MAY BAY			
			case 1:
				SetBGColor(Color_DarkWhite);	clrscr();
				quanLyMayBay(list_MB, list_CB);			break;
			// QUAN LY CHUYEN BAY
			case 2:
				SetBGColor(Color_DarkWhite);	clrscr();
				quanLyChuyenBay(list_CB, list_MB);		break;
			//QUAN LY DAT VE
			case 3:
				choiceMenuCon = MenuCon(itemmenuDV, MENUDATVE,positionMenuDV);
				SetBGColor(Color_DarkWhite);	clrscr();
				switch (choiceMenuCon) {
				case 1://dat ve
					datVe(list_CB, list_MB, list_HK);	break;
				case 2:// huye ve
					huyVe(list_CB, list_MB, list_HK);	break;
				case 3://
					TimCBConve(list_CB);			break;
				case 4://
					danhSachVe(list_CB,list_MB);	break;
				}
				break;
			case 4:// quan ly hanh khach
				choiceMenuCon = MenuCon(itemmenuHK, MENUHK,positionMenuKH);
				SetBGColor(Color_DarkWhite);	clrscr();
				switch (choiceMenuCon) {
					case 1://tat ca hanh khach
//						DuyetDSHK(list_HK);
						duyetKH(list_HK);
						message(posXMessage, posYMessage, "NHAN PHIM BAT KY DE QUAY LAI!");	break;
					case 2:// hanh khach cua chuyen xxx
						showCustomerOfCbXXX(list_CB, list_HK);	break;
				}
				break;
			case 5: //thoat
				if(Hoi(60,20,"      BAN CO MUON LUU TAT CA CAC THAY DOI?       ")){
					saveFileList_MB(list_MB);
					saveFileList_CB(list_CB);
					SaveDataHanhKhach(list_HK);
				}	return ;
		}
	}
	return;
}

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	resizeConsole(maxrong, maxcao);
	SetBGColor(Color_DarkWhite);
	List_MB list_MB;
	list_MB.soluong = 0;
	List_CB list_CB;
	initList_CB(list_CB);
	NODEHKPTR list_HK;
	InitTree(list_HK);
	RootMenu(list_MB, list_CB, list_HK);
	return 0;
}
