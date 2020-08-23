#include <iostream>
#include"mylib.h"
#include <ctime>
#include <algorithm>
#include <math.h>
//#include"frame.h"
using namespace std;
int isEmpty(List_MB l) {
	return l.soluong == 0;
}
int isFull(List_MB l) {
	return l.soluong == MAXMAYBAY;
}
time_t baygio = time(0);
tm* ltm = localtime(&baygio);
//tim va tra ve vi tri cua Mb có so hieu chuyen bay X
int search(List_MB listMB, char shmb[]) {
	for (int i = 0; i < listMB.soluong; i++)
		if (strcmp(listMB.nodeMB[i]->sohieu_MB, shmb) == 0) return i;
	return -1;
}
Node_CB * searchInfo(List_CB & l, char maCBtemp[]) {
	for (Node_CB* p = l.pHead;p != NULL;p = p->pNext)
		if (strcmp(p->data.ma_CB, maCBtemp) == 0) return p;
	return NULL;
}
Node_CB * searchInfoShmb(List_CB & l, char SHMBtemp[]) {
	for (Node_CB* p = l.pHead;p != NULL;p = p->pNext)
		if (strcmp(p->data.sohieumb, SHMBtemp) == 0) return p;
	return NULL;
}
void coverOutDataSHMB(List_MB l) {//remove
	SetBGColor(Color_DarkWhite);
	for (int i = 0;i < 15;i++) {
		gotoxy(144, 10 + i);cout << "               ";
	}
}
void outDataSHMB(List_MB l, int vitri) {
	int dong = 11;
	gotoxy(156, dong + vitri);cout << l.nodeMB[vitri]->sohieu_MB;
}
int checkNoiDen(char noiden[]) {
	for (int i = 0;i < 6;i++)
		if (strcmp(sanBay[i], noiden) == 0) return i;
	return -1;
}
boolean checkYear(int y) {
	if (y != (ltm->tm_year +1900) ) {
		return false;
	}
	return true;
}
boolean checkMonth(int m) {

	if (m < 1 || m>12 || m < 1 + ltm->tm_mon) {
		return false;
	}
	return true;
}
boolean checkDay(int d, int m) {
	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
		if (d < 1 || d>31)
			return false;
	}
	else if (m == 4 || m == 6 || m == 9 || m == 11) {
		if (d < 1 || d>30)
			return false;
	}
	else if (m == 2) {
		if (d < 1 || d>28)
			return false;
	}
	return true;
}
boolean checkCurrentDDMMYY(int d, int m) {
	if (m == (1 + ltm->tm_mon)) {
		if (d < 1 + ltm->tm_mday) return false;
	}
	return true;
}
boolean checkTrangThai(int d, int m) {
	if (m == (1 + ltm->tm_mon)) {
		if (d < ltm->tm_mday) return false;
	}
	else if (m < (1 + ltm->tm_mon)){
		return false;
	}
	return true;
}

boolean checkTrungChuyenbay(List_CB l, CHUYENBAY cb) {
	for (Node_CB* p = l.pHead;p != NULL;p = p->pNext) {
		if (strcmp(p->data.sohieumb, cb.sohieumb) == 0 && strcmp(p->data.ma_CB, cb.ma_CB) != 0) {// neu trung sohieu thi kiem tra thang
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
int frameAddShmb_AddCB(List_MB listMB) {
	
	SetBGColor(Color_DarkWhite);SetColor(Color_DarkRed);
	for (int i = 0;i < listMB.soluong;i++) {
		if (i == 0) 	HighLight();
		else	Normal();
		outDataSHMB(listMB, i);
	}
	int vitri = 0;
	while (true) {
		int key = GetKey();
		switch (key) {
		case DOWN:
			if (vitri == listMB.soluong - 1) {
				Normal();
				outDataSHMB(listMB, vitri);
				vitri = 0;
				HighLight();
				outDataSHMB(listMB, vitri);
			}
			else {
				Normal();
				outDataSHMB(listMB, vitri);
				vitri++;
				HighLight();
				outDataSHMB(listMB, vitri);
			}
			break;
		case UP:
			if (vitri == 0) {
				Normal();
				outDataSHMB(listMB, vitri);
				vitri = listMB.soluong - 1;
				HighLight();
				outDataSHMB(listMB, vitri);
			}
			else {
				Normal();
				outDataSHMB(listMB, vitri);
				vitri--;
				HighLight();
				outDataSHMB(listMB, vitri);
			}
			break;
		case ENTER:
			if (listMB.soluong > 0) {
				return vitri;
			}
			return -1;
		case ESC:
			return -2;
		}
	}
}
void outDataMB(List_MB listMB ,int i) {
	
	gotoxy(positionX_listMB + 8, dongStart + i);	cout << listMB.nodeMB[i]->sohieu_MB;
	gotoxy(positionX_listMB + 30, dongStart + i);	cout << listMB.nodeMB[i]->loai_MB;
	gotoxy(positionX_listMB + 57, dongStart + i);	cout << listMB.nodeMB[i]->soday_MB;
	gotoxy(positionX_listMB + 72, dongStart + i);	cout << listMB.nodeMB[i]->sohang_MB;
	gotoxy(positionX_listMB + 86, dongStart + i);	cout << (listMB.nodeMB[i]->soday_MB * listMB.nodeMB[i]->sohang_MB);
	SetColor(Color_DarkRed);
	SetBGColor(Color_White);
	gotoxy(positionFormInputX + 21, positionFormInputY + 1);	cout<<"                               ";
	gotoxy(positionFormInputX + 21, positionFormInputY + 5);	cout<<"                               ";
	gotoxy(positionFormInputX + 21, positionFormInputY + 9);	cout<<"                               ";
	gotoxy(positionFormInputX + 21, positionFormInputY + 13);	cout<<"                               ";
	gotoxy(positionFormInputX + 21, positionFormInputY + 17);	cout<<"                               ";
	
	gotoxy(positionFormInputX + 21, positionFormInputY + 1);	cout << listMB.nodeMB[i]->sohieu_MB;
	gotoxy(positionFormInputX + 21, positionFormInputY + 5);	cout << listMB.nodeMB[i]->loai_MB;
	gotoxy(positionFormInputX + 21, positionFormInputY + 9);	cout << listMB.nodeMB[i]->soday_MB;
	gotoxy(positionFormInputX + 21, positionFormInputY + 13);	cout << listMB.nodeMB[i]->sohang_MB;
	gotoxy(positionFormInputX + 21, positionFormInputY + 17);	cout << (listMB.nodeMB[i]->soday_MB * listMB.nodeMB[i]->sohang_MB);
}
int checkSex(string gioitinh) {
	for (int i = 0;i < 2;i++) {
		if (gioitinh == sex[i]) {
			return i;
		}
	}
	return -1;
}
int checkTonTaiVe(CHUYENBAY cb) {
	for (int i = 0;i < cb.soluongVe;i++) {
		if (cb.nodeVe[i].cmnd != " ")
		{
			return 1;
		}
	}
	return 0; //neu chua co ai dat ve het thi tra ve 0
}

//int checkTonTaiVe(CHUYENBAY cb) {
//	int dem=0;
//	for (int i = 0;i < cb.soluongVe;i++) {
//		if (cb.nodeVe[i].cmnd != " ")
//		{
//			dem = 1;
//			break;
//		}
//	}
//	return dem; //= 0 la het ve
//}
//int checkTonTaiVe11(CHUYENBAY cb) {
//	int dem=0;
//	for (int i = 0;i < cb.soluongVe;i++) {
//		if (cb.nodeVe[i].cmnd != " ")
//		{
//			dem++;//ve co nguoi dat r thi +1
//		}
//	}
//	return dem; //neu chua co ai dat ve het thi tra ve 0
//}
//hien thi dach sach may bay

