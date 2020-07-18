#include <iostream>
#include <conio.h>

#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <string.h>
#include <windows.h>
//#include "frame.h"
//#define Enter 13
//const int WHITE=15;
#define PASSWORD "abcdef"
//const int WHITE=15;
//
char* Pwd() {
	char S[40]; int i = 0;
	while ((S[i] = getch()) != ENTER)
	{
		printf("%c", '*'); i++;
	}
	S[i] = '\0';
	return S;
}
void toUpperString(string &s){
	for (int i=0;i<s.length();i++){
		s[i]=toupper(s[i]);
	}
}
int CheckPwd() {
	int dem = 0;
	for (dem = 1; dem <= 3; dem++)
	{
		printf("Password :");
		if (strcmp(Pwd(), PASSWORD) == 0)   return 1;
		else printf("\nPassword sai. Hay nhap lai\n");
	}
	return 0;
}

void ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}
void gotoxy(short x, short y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x,y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

int wherex(void)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
	return screen_buffer_info.dwCursorPosition.X;
}

int wherey(void)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
	return screen_buffer_info.dwCursorPosition.Y;
}
void clreol() {
	COORD coord;
	DWORD written;
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
	coord.X = info.dwCursorPosition.X;
	coord.Y = info.dwCursorPosition.Y;
	FillConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE), ' ',
		info.dwSize.X - info.dwCursorPosition.X * info.dwCursorPosition.Y, coord, &written);
	gotoxy(info.dwCursorPosition.X, info.dwCursorPosition.Y);
}

void SetColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void SetBGColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	color <<= 4;
	wAttributes &= 0xff0f;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
int GetKey() {
	char key;
	fflush(stdin);
	key = _getch();
	if (key == -32 || key == 0)
		return -_getch();
	else return key;
}
void BaoLoi(char* s) {
	int x = wherex(), y = wherey();
	gotoxy(50, 24);
	cout << s;
	Sleep(2500);
	gotoxy(50, 26);
	clreol();
	gotoxy(x, y);
}
void NhapChuoi(char* tieude, char* S) {
	char* a;cout << tieude;  fflush(stdin);
	do {
		fflush(stdin);
		gets(S);
	} while (strcmp(S, "") == 0);
	a = _strupr(S);
	strcpy(S, a);
}
void Alert(string str, int x, int y, float time, int bgColor = 8) {
	gotoxy(x, y);
	SetColor(Color_White);
	SetBGColor(bgColor);
	std::cout << str;
	getch();
	//Sleep(time*1000);
	gotoxy(x, y);
	SetBGColor(Color_DarkWhite);
	std::cout << "                                                                                               ";
}
void Alert2(string str, int x, int y, float time, int bgColor = 8) {
	gotoxy(x, y);
	SetColor(Color_White);
	SetBGColor(bgColor);
	std::cout << str;
	getch();
	//Sleep(time*1000);
	gotoxy(x, y);
	SetBGColor(Color_DarkWhite);
	for (int i = 0;i <= str.length();i++) {
		gotoxy(x + i, y);cout << " ";
	}

}
void anConTro()
{
	HANDLE hOut;
	CONSOLE_CURSOR_INFO ConCurInf;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	ConCurInf.dwSize = 10;
	ConCurInf.bVisible = FALSE;
	SetConsoleCursorInfo(hOut, &ConCurInf);
}
void TextColor(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void Normal() {
	SetColor(Color_DarkRed);
	SetBGColor(Color_DarkWhite);
}
void HighLight() {
	SetColor(11);
	SetBGColor(Color_DarkBlue);
}
void HighLight1() {
	SetColor(Color_Back);
	SetBGColor(Color_Cyan);
}
void HighLight2() {
	SetColor(Color_White);
	SetBGColor(8);
}
void clrscr() {
	system("cls");
}

