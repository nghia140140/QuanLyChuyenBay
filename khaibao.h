  #include <iostream>

// ==================== DEFINE VALUE ====================== //
// Ve dâu mui tên
#define ArrowRIGHT 27
#define ArrowLEFT 26
#define ArrowUP 25
#define ArrowDOWN 24
#define MAXMAYBAY 14
#define maxSOHIEUMB 15
#define maxLOAIMB 40
#define maxMACB 15
#define maxcao 740 
#define maxrong 1600 
#define maxsoday 10 
#define maxsohang 35
#define maxcmnd 10 
#define DOWN -80
#define UP -72
#define F1 -59
#define F2 -60
#define TAB 9
#define LEFT -75
#define RIGHT -77
#define ENTER 13
#define ESC 27
#define SPACE 32
#define BACKSPACE 8
#define DELETE 83
#define INSERT 82
#define END 79
#define positionMenuMB 7
#define positionMenuCB 38
#define positionMenuDV 69
#define positionMenuKH 100
#define MAXYCONSOLE 42
#define positionMainMenu 4
#define positionX_listMB 5
#define positionY_listMB 8

#define positionX_listCB 5
#define positionY_listCB 6


#define positionFormInputX 115
#define positionFormInputY 10
#define positionAlertHelp 107


	//COLOR
#define Color_Back			0
#define Color_DarkBlue		1
#define Color_DarkGreen		2
#define Color_DarkCyan		3
#define Color_DarkRed		4
#define Color_DarkPink		5
#define Color_DarkYellow	6
#define Color_DarkWhite		7
#define Color_Grey			8
#define Color_Blue			9
#define Color_Green			10
#define Color_Cyan			11
#define Color_Red			12
#define Color_Pink			13
#define Color_Yellow		14
#define Color_White			15

using namespace std;
const int cotStart= 51;
const int dongStart= 11;
const int cotStartCB= 2;
const int dongStartCB= 13;
const int dongStartHK= 9;
typedef struct  {
	int day,month,year,hours,minutes;
	
}DATETIME;
///////////////////
typedef struct {
	char sohieu_MB[15];
	char loai_MB[40];
	int soday_MB, sohang_MB;
	
}MAYBAY;
typedef struct {
	int soluong;
	MAYBAY *nodeMB[MAXMAYBAY];
}List_MB;
///////////////////
char sanBay[6][10] = {"SGN","HAN","CXR","PQC","UIH","HPH"};
string staTus[4] = {"HUY CHUYEN","CON VE","HET VE","HOAN TAT"};
string sex[2] = {"NAM","NU"};
string sttday[maxsoday]= {"A","B","C","D","E","F","G","H","K","I"};
typedef struct {
	string cmnd;
	string soghe;
}VE;
typedef struct  {
	char ma_CB[15];
	DATETIME ngaygioStart;
	char sanbayDen[40];
	int trangthai;
	char sohieumb[15];
	int soluongVe;
	VE *nodeVe;
}CHUYENBAY;
typedef struct Node_CB{
	CHUYENBAY data;
	struct Node_CB *pNext;
}Node_CB;
typedef struct {
	Node_CB *pHead;	
}List_CB;

void initList_CB(List_CB &listCB){	
	listCB.pHead = NULL;
}
	
struct hanhkhach
{
	string cmnd,ho,ten;
	int gioiTinh;
};
typedef struct hanhkhach HANHKHACH;

typedef struct nodeHK
{
	HANHKHACH data;		
	nodeHK *Left;
	nodeHK *Right;
};
typedef struct nodeHK NODEHK;
typedef NODEHK* NODEHKPTR;

void InitTree(NODEHKPTR &Root)
{
	Root = NULL;//cay rong
}



void InsertHanhKhach(NODEHKPTR &T,HANHKHACH hk)
{//theo kieu LNR
	//chen mot node vao cay
	if(T == NULL)
	{
		NODEHK *p = new NODEHK;
		p->data.cmnd=hk.cmnd;
		p->data.ho=hk.ho;
		p->data.ten=hk.ten;
		p->data.gioiTinh = hk.gioiTinh;
		p->Left = NULL;
		p->Right = NULL;
		T = p;//T cung la mot NODEHK va p cung la mot NODEHK
	}
	
	else
	{//TREE co ton tai phan tu
		if(T->data.cmnd>hk.cmnd)
		{
			return InsertHanhKhach(T->Left,hk);//chen vao node trai
		}
		else if(T->data.cmnd<hk.cmnd)
		{
			return InsertHanhKhach(T->Right,hk);//chen voo node phai
		}
	}
}


 
NODEHKPTR Search( NODEHKPTR T,  string cmndtemp )
{
    if ( T == NULL )
        return T;
    if(T->data.cmnd == cmndtemp){
        return T;
    }else if (T->data.cmnd>cmndtemp){
        return Search( T->Left, cmndtemp  );
    }else if( T->data.cmnd<cmndtemp ){
        return Search( T->Right,cmndtemp );
    }
}
//NODEHKPTR KiemTraHK(NODEHKPTR T, string cmndtemp)
//{
//	if(T == NULL)
//	{
//		return NULL;
//	}
//	else
//	{
//		if(T->data.cmnd>cmndtemp)
//		{
//			KiemTraHK(T->Left, cmndtemp);
//		}
//		
//		else if(T->data.cmnd<cmndtemp)
//		{
//			KiemTraHK(T->Right, cmndtemp);
//		}
//		
//		else 
//		return T;
//	}
//}


