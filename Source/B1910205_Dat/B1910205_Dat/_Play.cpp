#include "_Play.h"
#include <vector>
#include <Windows.h>
#include <mmsystem.h>
#include <iostream>
#include<conio.h>
#include"_Common.h"
#include<fstream>
#include"_Board.h"
#include"mylib.h"
#include<fstream>
#define MAX 100
using namespace std;
void Textcolor(int color)
{
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleColor, color);
}
void AnTroChuot()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
void HienTroChuot()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = TRUE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
int ReadChedo(char a[30])
{
	int d1, d2, chedo;
	system("cls");
	ifstream f;
	f.open(a, ios::in);
	if (!f) {
		_Common::gotoXY(35, 46);
		cout << "\n FILE KHONG TON TAI!" << endl;
		Sleep(1000);
		ScreenStartGame(99);
	}
	else
		f >> d1 >> d2 >> chedo;
	f.close();
	return chedo;
}
void ReadNameFile()
{
	Textcolor(Cyan);
	_Common::gotoXY(60, 18);
	cout << "LIST FILE NAME";
	int i = 19;
	ifstream f;
	f.open("Name.txt", ios::in);
	while (!f.eof())
	{
		char s[30];
		f >> s;
		_Common::gotoXY(50, i);
		cout << s;
		i++;
	}
	f.close();
}
void PrintCaro()
{
	int x = 25, y = 0;
	Textcolor(rand() % 15 + 1);
	_Common::gotoXY(x, y);				   cout << "ooooooooooooo";
	_Common::gotoXY(x - 3, y + 1);			cout << "oooooooooooooooo";
	_Common::gotoXY(x - 5, y + 2);    cout << "oooooooooooooooooo";
	_Common::gotoXY(x - 6, y + 3);   cout << "ooooooooooooooooooo";
	Textcolor(rand() % 15 + 1);
	_Common::gotoXY(x - 7, y + 4);  cout << " ooooooo";
	_Common::gotoXY(x - 8, y + 5); cout << "    ooooooo";
	_Common::gotoXY(x - 8, y + 6); cout << "       ooooooo";
	_Common::gotoXY(x - 8, y + 7); cout << "         ooooooo";
	_Common::gotoXY(x - 8, y + 8); cout << "           ooooooo";
	_Common::gotoXY(x - 8, y + 9); cout << "             ooooooo";
	Textcolor(rand() % 15 + 1);
	_Common::gotoXY(x - 8, y + 10); cout << "             ooooooo";
	_Common::gotoXY(x - 7, y + 11); cout << "            ooooooo";
	_Common::gotoXY(x - 7, y + 12); cout << "ooooooooooooooooooo";
	_Common::gotoXY(x - 7, y + 13);cout <<"oooooooooooooooooo";
	Textcolor(rand() % 15 + 1);
	_Common::gotoXY(x - 7, y + 14);	cout << "oooooooooooooooo";
	_Common::gotoXY(x-7, y + 15);cout << "ooooooooooooo";
	Textcolor(rand() % 15 + 1);
	_Common::gotoXY(x - 4 + 22 - 3, y + 4);	    cout << "oo            oo";
	_Common::gotoXY(x - 4 + 22 - 3, y + 5);		cout << "oooo          oo";
	_Common::gotoXY(x - 4 + 22 - 3, y + 6);		cout << "oo oo         oo";
	Textcolor(rand() % 15 + 1);
	_Common::gotoXY(x - 4 + 22 - 3, y + 7);		cout << "oo  oo        oo";
	_Common::gotoXY(x - 4 + 22 - 3, y + 8);		cout << "oo   oo       oo";
	_Common::gotoXY(x - 4 + 22 - 3, y + 9);		cout << "oo    oo      oo";
	Textcolor(rand() % 15 + 1);
	_Common::gotoXY(x - 4 + 22 - 3, y + 10);	cout << "oo     oo     oo";
	_Common::gotoXY(x - 4 + 22 - 3, y + 11);	cout << "oo      oo    oo";
	_Common::gotoXY(x - 4 + 22 - 3, y + 12);	cout << "oo       oo   oo";
	Textcolor(rand() % 15 + 1);
	_Common::gotoXY(x - 4 + 22 - 3, y + 13);	cout << "oo         oo oo";
	_Common::gotoXY(x - 4 + 22 - 3, y + 14);	cout << "oo          oooo";
	_Common::gotoXY(x - 4 + 22 - 3, y + 15);	cout << "oo            oo";

	Textcolor(rand() % 15 + 1);

	_Common::gotoXY(x + 37, y + 4);			cout << "ooooooooooo";
	_Common::gotoXY(x + 35, y + 5);		   cout << "ooooooooooooooo";
	_Common::gotoXY(x + 34, y + 6);		  cout << "ooooooooooooooooo";
	Textcolor(rand() % 15 + 1);
	_Common::gotoXY(x + 34, y + 7);		  cout << "ooooooooooooooooo";
	_Common::gotoXY(x + 1 + 33, y + 8);	  cout << "oooooo     oooooo";
	_Common::gotoXY(x + 1 + 33, y + 9);	  cout << "oooooo     oooooo";
	Textcolor(rand() % 15 + 1);
	_Common::gotoXY(x + 1 + 33, y + 10);  cout << "oooooo     oooooo";
	_Common::gotoXY(x + 1 + 33, y + 11);  cout << "ooooooooooooooooo";
	_Common::gotoXY(x + 1 + 33, y + 12);  cout << "oooooo     oooooo";
	Textcolor(rand() % 15 + 1);
	_Common::gotoXY(x + 1 + 33, y + 13);  cout << "oooooo     oooooo";
	_Common::gotoXY(x + 1 + 33, y + 14);  cout << "oooooo     oooooo";
	_Common::gotoXY(x + 1 + 33, y + 15);  cout << "oooooo     oooooo";
	 Textcolor(Yellow);
	_Common::gotoXY(x + 54, y + 3);				 cout << "ooo     ooo";
	_Common::gotoXY(x + 54, y + 4);				 cout << "ooo    ooo";
	_Common::gotoXY(x + 54, y + 5);			     cout << "ooo   ooo";
	Textcolor(rand() % 15 + 1);
	_Common::gotoXY(x + 54 , y + 6);			 cout << "ooo  ooo";
	_Common::gotoXY(x + 54 , y + 7);			 cout << "ooo ooo";
	Textcolor(rand() % 15 + 1);
	_Common::gotoXY(x + 59 - 5, y + 8);			 cout << "ooooo";
	_Common::gotoXY(x + 59 - 5, y + 9);			 cout << "ooooo";
	_Common::gotoXY(x + 59 - 5, y + 10);		 cout << "ooooo";
	_Common::gotoXY(x + 59 - 5, y + 11);		 cout << "ooo ooo";
	Textcolor(rand() % 15 + 1);
	_Common::gotoXY(x + 59 - 5, y + 12);		 cout << "ooo  ooo";
	_Common::gotoXY(x + 59 - 5, y + 13);		 cout << "ooo   ooo";
	Textcolor(rand() % 15 + 1);
	_Common::gotoXY(x + 59 - 5, y + 14);		 cout << "ooo    ooo";
	_Common::gotoXY(x + 54, y + 15);			 cout << "ooo     ooo";
	Textcolor(Pink);
	_Common::gotoXY(x + 68, y + 4);			 cout << "ooooooooooooooooo";
	_Common::gotoXY(x + 68, y + 5);		      cout <<"ooooooooooooooooo";
	Textcolor(rand() % 15 + 1);
	_Common::gotoXY(x + 69, y + 6);	           cout << "ooooo     ooooo";
	_Common::gotoXY(x + 69, y + 7);		       cout << "ooooo";
	Textcolor(rand() % 15 + 1);
	_Common::gotoXY(x + 69, y + 8);		       cout << "ooooooooooo";
	_Common::gotoXY(x + 69, y + 9);	           cout << "ooooooooooo";
	_Common::gotoXY(x + 69, y + 10);	       cout << "ooooooooooo";
	_Common::gotoXY(x + 69, y + 11);	       cout << "ooooooooooo";
	Textcolor(rand() % 15 + 1);
	_Common::gotoXY(x + 69, y + 12);	       cout << "ooooo";
	_Common::gotoXY(x + 69, y + 13);	       cout << "ooooo     ooooo";
	Textcolor(rand() % 15 + 1);
	_Common::gotoXY(x + 68 , y + 14);		 cout << "ooooooooooooooooo";
	_Common::gotoXY(x + 68, y + 15);		 cout << "ooooooooooooooooo";
}


void PrintCaro2()
{
	int x = 25, y = 0;
	Sleep(200);
	Textcolor(Red);
	_Common::gotoXY(x, y);				   cout << "ooooooooooooo";
	_Common::gotoXY(x - 3, y + 1);			cout << "oooooooooooooooo";
	_Common::gotoXY(x - 5, y + 2);    cout << "oooooooooooooooooo";
	_Common::gotoXY(x - 6, y + 3);   cout << "ooooooooooooooooooo";
	_Common::gotoXY(x - 7, y + 4);  cout << " ooooooo";
	_Common::gotoXY(x - 8, y + 5); cout << "    ooooooo";
	_Common::gotoXY(x - 8, y + 6); cout << "       ooooooo";
	_Common::gotoXY(x - 8, y + 7); cout << "         ooooooo";
	_Common::gotoXY(x - 8, y + 8); cout << "           ooooooo";
	_Common::gotoXY(x - 8, y + 9); cout << "             ooooooo";
	_Common::gotoXY(x - 8, y + 10); cout << "             ooooooo";
	_Common::gotoXY(x - 7, y + 11); cout << "            ooooooo";
	_Common::gotoXY(x - 7, y + 12); cout << "ooooooooooooooooooo";
	_Common::gotoXY(x - 7, y + 13); cout << "oooooooooooooooooo";
	_Common::gotoXY(x - 7, y + 14);	cout << "oooooooooooooooo";
	_Common::gotoXY(x - 7, y + 15); cout << "ooooooooooooo";
	Sleep(200);
	Textcolor(Green);
	_Common::gotoXY(x - 4 + 22 - 3, y + 4);	    cout << "oo            oo";
	_Common::gotoXY(x - 4 + 22 - 3, y + 5);		cout << "oooo          oo";
	_Common::gotoXY(x - 4 + 22 - 3, y + 6);		cout << "oo oo         oo";
	_Common::gotoXY(x - 4 + 22 - 3, y + 7);		cout << "oo  oo        oo";
	_Common::gotoXY(x - 4 + 22 - 3, y + 8);		cout << "oo   oo       oo";
	_Common::gotoXY(x - 4 + 22 - 3, y + 9);		cout << "oo    oo      oo";
	_Common::gotoXY(x - 4 + 22 - 3, y + 10);	cout << "oo     oo     oo";
	_Common::gotoXY(x - 4 + 22 - 3, y + 11);	cout << "oo      oo    oo";
	_Common::gotoXY(x - 4 + 22 - 3, y + 12);	cout << "oo       oo   oo";
	_Common::gotoXY(x - 4 + 22 - 3, y + 13);	cout << "oo         oo oo";
	_Common::gotoXY(x - 4 + 22 - 3, y + 14);	cout << "oo          oooo";
	_Common::gotoXY(x - 4 + 22 - 3, y + 15);	cout << "oo            oo";
	Sleep(200);
	Textcolor(Blue);

	_Common::gotoXY(x + 37, y + 4);			cout << "ooooooooooo";
	_Common::gotoXY(x + 35, y + 5);		   cout << "ooooooooooooooo";
	_Common::gotoXY(x + 34, y + 6);		  cout << "ooooooooooooooooo";
	_Common::gotoXY(x + 34, y + 7);		  cout << "ooooooooooooooooo";
	_Common::gotoXY(x + 1 + 33, y + 8);	  cout << "oooooo     oooooo";
	_Common::gotoXY(x + 1 + 33, y + 9);	  cout << "oooooo     oooooo";
	_Common::gotoXY(x + 1 + 33, y + 10);  cout << "oooooo     oooooo";
	_Common::gotoXY(x + 1 + 33, y + 11);  cout << "ooooooooooooooooo";
	_Common::gotoXY(x + 1 + 33, y + 12);  cout << "oooooo     oooooo";
	_Common::gotoXY(x + 1 + 33, y + 13);  cout << "oooooo     oooooo";
	_Common::gotoXY(x + 1 + 33, y + 14);  cout << "oooooo     oooooo";
	_Common::gotoXY(x + 1 + 33, y + 15);  cout << "oooooo     oooooo";
	Sleep(200);
	Textcolor(Yellow);
	_Common::gotoXY(x + 54, y + 3);				 cout << "ooo     ooo";
	_Common::gotoXY(x + 54, y + 4);				 cout << "ooo    ooo";
	_Common::gotoXY(x + 54, y + 5);			     cout << "ooo   ooo";
	_Common::gotoXY(x + 54, y + 6);			     cout << "ooo  ooo";
	_Common::gotoXY(x + 54, y + 7);			     cout << "ooo ooo";
	_Common::gotoXY(x + 59 - 5, y + 8);			 cout << "ooooo";
	_Common::gotoXY(x + 59 - 5, y + 9);			 cout << "ooooo";
	_Common::gotoXY(x + 59 - 5, y + 10);		 cout << "ooooo";
	_Common::gotoXY(x + 59 - 5, y + 11);		 cout << "ooo ooo";
	_Common::gotoXY(x + 59 - 5, y + 12);		 cout << "ooo  ooo";
	_Common::gotoXY(x + 59 - 5, y + 13);		 cout << "ooo   ooo";
	_Common::gotoXY(x + 59 - 5, y + 14);		 cout << "ooo    ooo";
	_Common::gotoXY(x + 54, y + 15);			 cout << "ooo     ooo";
	Sleep(200);
	Textcolor(Pink);
	_Common::gotoXY(x + 68, y + 4);			 cout << "ooooooooooooooooo";
	_Common::gotoXY(x + 68, y + 5);		      cout << "ooooooooooooooooo";
	_Common::gotoXY(x + 69, y + 6);	           cout << "ooooo     ooooo";
	_Common::gotoXY(x + 69, y + 7);		       cout << "ooooo";
	_Common::gotoXY(x + 69, y + 8);		       cout << "ooooooooooo";
	_Common::gotoXY(x + 69, y + 9);	           cout << "ooooooooooo";
	_Common::gotoXY(x + 69, y + 10);	       cout << "ooooooooooo";
	_Common::gotoXY(x + 69, y + 11);	       cout << "ooooooooooo";
	_Common::gotoXY(x + 69, y + 12);	       cout << "ooooo";
	_Common::gotoXY(x + 69, y + 13);	       cout << "ooooo     ooooo";
	_Common::gotoXY(x + 68, y + 14);		 cout << "ooooooooooooooooo";
	_Common::gotoXY(x + 68, y + 15);		 cout << "ooooooooooooooooo";
	Textcolor(defaultColor);


}
void PrintCaro3()
{
	int x = 25, y = 0;
	Textcolor(Red);
	_Common::gotoXY(x, y);				   cout << "ooooooooooooo";
	_Common::gotoXY(x - 3, y + 1);			cout << "oooooooooooooooo";
	_Common::gotoXY(x - 5, y + 2);    cout << "oooooooooooooooooo";
	_Common::gotoXY(x - 6, y + 3);   cout << "ooooooooooooooooooo";
	_Common::gotoXY(x - 7, y + 4);  cout << " ooooooo";
	_Common::gotoXY(x - 8, y + 5); cout << "    ooooooo";
	_Common::gotoXY(x - 8, y + 6); cout << "       ooooooo";
	_Common::gotoXY(x - 8, y + 7); cout << "         ooooooo";
	_Common::gotoXY(x - 8, y + 8); cout << "           ooooooo";
	_Common::gotoXY(x - 8, y + 9); cout << "             ooooooo";
	_Common::gotoXY(x - 8, y + 10); cout << "             ooooooo";
	_Common::gotoXY(x - 7, y + 11); cout << "            ooooooo";
	_Common::gotoXY(x - 7, y + 12); cout << "ooooooooooooooooooo";
	_Common::gotoXY(x - 7, y + 13); cout << "oooooooooooooooooo";
	_Common::gotoXY(x - 7, y + 14);	cout << "oooooooooooooooo";
	_Common::gotoXY(x - 7, y + 15); cout << "ooooooooooooo";
	Textcolor(Green);
	_Common::gotoXY(x - 4 + 22 - 3, y + 4);	    cout << "oo            oo";
	_Common::gotoXY(x - 4 + 22 - 3, y + 5);		cout << "oooo          oo";
	_Common::gotoXY(x - 4 + 22 - 3, y + 6);		cout << "oo oo         oo";
	_Common::gotoXY(x - 4 + 22 - 3, y + 7);		cout << "oo  oo        oo";
	_Common::gotoXY(x - 4 + 22 - 3, y + 8);		cout << "oo   oo       oo";
	_Common::gotoXY(x - 4 + 22 - 3, y + 9);		cout << "oo    oo      oo";
	_Common::gotoXY(x - 4 + 22 - 3, y + 10);	cout << "oo     oo     oo";
	_Common::gotoXY(x - 4 + 22 - 3, y + 11);	cout << "oo      oo    oo";
	_Common::gotoXY(x - 4 + 22 - 3, y + 12);	cout << "oo       oo   oo";
	_Common::gotoXY(x - 4 + 22 - 3, y + 13);	cout << "oo         oo oo";
	_Common::gotoXY(x - 4 + 22 - 3, y + 14);	cout << "oo          oooo";
	_Common::gotoXY(x - 4 + 22 - 3, y + 15);	cout << "oo            oo";
	Textcolor(Blue);

	_Common::gotoXY(x + 37, y + 4);			cout << "ooooooooooo";
	_Common::gotoXY(x + 35, y + 5);		   cout << "ooooooooooooooo";
	_Common::gotoXY(x + 34, y + 6);		  cout << "ooooooooooooooooo";
	_Common::gotoXY(x + 34, y + 7);		  cout << "ooooooooooooooooo";
	_Common::gotoXY(x + 1 + 33, y + 8);	  cout << "oooooo     oooooo";
	_Common::gotoXY(x + 1 + 33, y + 9);	  cout << "oooooo     oooooo";
	_Common::gotoXY(x + 1 + 33, y + 10);  cout << "oooooo     oooooo";
	_Common::gotoXY(x + 1 + 33, y + 11);  cout << "ooooooooooooooooo";
	_Common::gotoXY(x + 1 + 33, y + 12);  cout << "oooooo     oooooo";
	_Common::gotoXY(x + 1 + 33, y + 13);  cout << "oooooo     oooooo";
	_Common::gotoXY(x + 1 + 33, y + 14);  cout << "oooooo     oooooo";
	_Common::gotoXY(x + 1 + 33, y + 15);  cout << "oooooo     oooooo";
	Textcolor(Yellow);
	_Common::gotoXY(x + 54, y + 3);				 cout << "ooo     ooo";
	_Common::gotoXY(x + 54, y + 4);				 cout << "ooo    ooo";
	_Common::gotoXY(x + 54, y + 5);			     cout << "ooo   ooo";
	_Common::gotoXY(x + 54, y + 6);			     cout << "ooo  ooo";
	_Common::gotoXY(x + 54, y + 7);			     cout << "ooo ooo";
	_Common::gotoXY(x + 59 - 5, y + 8);			 cout << "ooooo";
	_Common::gotoXY(x + 59 - 5, y + 9);			 cout << "ooooo";
	_Common::gotoXY(x + 59 - 5, y + 10);		 cout << "ooooo";
	_Common::gotoXY(x + 59 - 5, y + 11);		 cout << "ooo ooo";
	_Common::gotoXY(x + 59 - 5, y + 12);		 cout << "ooo  ooo";
	_Common::gotoXY(x + 59 - 5, y + 13);		 cout << "ooo   ooo";
	_Common::gotoXY(x + 59 - 5, y + 14);		 cout << "ooo    ooo";
	_Common::gotoXY(x + 54, y + 15);			 cout << "ooo     ooo";
	Textcolor(Pink);
	_Common::gotoXY(x + 68, y + 4);			 cout << "ooooooooooooooooo";
	_Common::gotoXY(x + 68, y + 5);		      cout << "ooooooooooooooooo";
	_Common::gotoXY(x + 69, y + 6);	           cout << "ooooo     ooooo";
	_Common::gotoXY(x + 69, y + 7);		       cout << "ooooo";
	_Common::gotoXY(x + 69, y + 8);		       cout << "ooooooooooo";
	_Common::gotoXY(x + 69, y + 9);	           cout << "ooooooooooo";
	_Common::gotoXY(x + 69, y + 10);	       cout << "ooooooooooo";
	_Common::gotoXY(x + 69, y + 11);	       cout << "ooooooooooo";
	_Common::gotoXY(x + 69, y + 12);	       cout << "ooooo";
	_Common::gotoXY(x + 69, y + 13);	       cout << "ooooo     ooooo";
	_Common::gotoXY(x + 68, y + 14);		 cout << "ooooooooooooooooo";
	_Common::gotoXY(x + 68, y + 15);		 cout << "ooooooooooooooooo";
	Textcolor(defaultColor);

}
void About()
{
	system("cls");
	PrintCaro3();
	Textcolor(Green);
	_Common::gotoXY(60, 18);
	cout << "ABOUT";
	Sleep(1000);
	Textcolor(Cyan);
	_Common::gotoXY(48, 21);
	cout << "DO AN GAME RAN SAN MOI - CTU" << endl;
	Sleep(1000);
	_Common::gotoXY(48, 23);
	cout << "-> MSSV   : B1910205." << endl;
	Sleep(1000);
	_Common::gotoXY(48, 25);
	cout << "-> Ho ten : LE THANH DAT." << endl;
	Sleep(1000);
	_Common::gotoXY(48, 27);
	cout << "-> Lop    : DI19V7A3." << endl;
	Sleep(1000);
	_Common::gotoXY(48, 29);
	cout << "-> Nguoi huong dan : Huynh Cong Thanh " << endl;
	Sleep(1000);
	Textcolor(DarkRed);
	_Common::gotoXY(48, 31);
	cout << "-> Chuc moi nguoi choi game vui ve !!" << endl;
	Textcolor(Green);
	_Common::gotoXY(60, 33);
	cout << "BACK";
	char command = ' ';
	command = _getch();
	system("cls");
}


void Help()
{
	system("cls");
	PrintCaro3();
	Textcolor(Green);
	_Common::gotoXY(60, 17);
	cout << "HELP";
	Textcolor(Green);
	_Common::gotoXY(41, 18);
	cout << "Huong dan:" << endl;
	Textcolor(Cyan);
	Sleep(1000);
	_Common::gotoXY(43, 19);
	cout << "Nguoi choi 1: Su dung cac phim W A S D de di chuyen." << endl;
	Sleep(1000);
	_Common::gotoXY(43, 20);
	cout << "Nguoi choi 2: Su dung cac phim "<< char(24) << " " << char(25) << " " << char(26) << " " << char(27) << " de di chuyen." << endl;
	Textcolor(Green);
	Sleep(1000);
	_Common::gotoXY(41, 22);
	cout << "Game duoc chia thanh 7 level:" << endl;
	Textcolor(Cyan);
	Sleep(1000);
	_Common::gotoXY(43, 23);
	cout << "Level 1 --> Level 7."  << endl;
	Sleep(1000);
	_Common::gotoXY(43, 24);
	cout << "Level 2, 3 ,5: Se co buff tang speed, giam speed nhau nhien." << endl;
	Textcolor(Green);
	Sleep(1000);
	_Common::gotoXY(41, 26);
	cout << "Cach choi:" << endl;
	Textcolor(Cyan);
	Sleep(1000);
	_Common::gotoXY(43, 27);
	cout << "Nguoi choi di chuyen ran an that nhieu qua de co duoc diem va to level up. " << endl;
	Sleep(1000);
	_Common::gotoXY(43, 28);
	cout << "Moi level se co mot do kho nhat dinh." << endl;
	Sleep(1000);
	_Common::gotoXY(43, 29);
	cout << "Nguoi choi can tranh cac vat can nhieu nhat co the, neu cham vao --> LOST." << endl;
	Sleep(1000);
	_Common::gotoXY(43, 30);
	cout << "Nguoi choi nao dat level 7 truoc --> WIN." << endl;
	Textcolor(DarkRed);
	_Common::gotoXY(44, 32);
	cout << "-> Chuc moi nguoi choi game vui ve !!" << endl;
	Textcolor(Green);
	_Common::gotoXY(60,34);
	cout << "BACK";
	char command = ' ';
	command = _getch();
	system("cls");
}
void LoadLoad()
{
	system("cls");
	PrintCaro3();
	ReadNameFile();
	char data[30];
	_Common::gotoXY(50, 32);
	HienTroChuot();
	cout << "ENTER FILE NAME: ";
	cin.getline(data, 30);
	int chedo = ReadChedo(data);
	
}

char ten[30];
void Name()
{
	system("cls");
	PrintCaro3();

	Textcolor(DarkYellow);
	_Common::gotoXY(35, 29);
	cout << "ESC TO BACK TO MENU";
	Textcolor(DarkYellow);
	_Common::gotoXY(80, 29);
	cout << "ENTER TO CONTINUE";
	Textcolor(Green);
	_Common::gotoXY(58, 19);
	cout << "ENTER YOUR NAME ";
	_Common::gotoXY(59, 21);
	cout << "-> ";
	textcolor(Red);
	cin.getline(ten, 30);
}
void Mode()
{
	system("cls");
	PrintCaro3();
	AnTroChuot();
	int x = 50, y = 20;
	int check = 1;
	Textcolor(Cyan);
	_Common::gotoXY(60, 18); cout << "PLAYER MODE";
	Textcolor(Red);
	_Common::gotoXY(50, 20); cout << "ONE PLAYER" << endl;
	Textcolor(7);
	_Common::gotoXY(50, 21); cout << "TWO PLAYER" << endl;
	Textcolor(Cyan);
	_Common::gotoXY(50, 32); cout << "....... W - S : Move ( Off Unikey - Off Caps Lock ) ";
	_Common::gotoXY(50, 33); cout << "....... Enter : Select ";
	while (check)
	{
		if (_kbhit())
		{
			switch (_getch())
			{
			case 'w':
				PlaySound(TEXT("move.wav"), NULL, SND_FILENAME | SND_ASYNC);
				if (y > 20)
				{
					y--;
					_Common::gotoXY(x, y);
				}
				if (y == 20)
				{
					Textcolor(Cyan);
					_Common::gotoXY(60, 18); cout << "PLAYER MODE";
					Textcolor(Red);
					_Common::gotoXY(50, 20); cout << "ONE PLAYER" << endl;
					Textcolor(7);
					_Common::gotoXY(50, 21); cout << "TWO PLAYER" << endl;
				}
				if (y == 21)
				{
					Textcolor(Cyan);
					_Common::gotoXY(60, 18); cout << "PLAYER MODE";
					Textcolor(7);
					_Common::gotoXY(50, 20); cout << "ONE PLAYER" << endl;
					Textcolor(Red);
					_Common::gotoXY(50, 21); cout << "TWO PLAYER" << endl;
				}
				break;
			case 's':
				PlaySound(TEXT("move.wav"), NULL, SND_FILENAME | SND_ASYNC);
				if (y < 21)
				{
					y++;
					_Common::gotoXY(x, y);
				}
				if (y == 20)
				{
					Textcolor(Cyan);
					_Common::gotoXY(60, 18); cout << "PLAYER MODE";
					Textcolor(Red);
					_Common::gotoXY(50, 20); cout << "ONE PLAYER" << endl;
					Textcolor(7);
					_Common::gotoXY(50, 21); cout << "TWO PLAYER" << endl;
				}
				if (y == 21)
				{
					Textcolor(Cyan);
					_Common::gotoXY(60, 18); cout << "PLAYER MODE";
					Textcolor(7);
					_Common::gotoXY(50, 20); cout << "ONE PLAYER" << endl;
					Textcolor(Red);
					_Common::gotoXY(50, 21); cout << "TWO PLAYER" << endl;
				}
				break;
			case 13:
				PlaySound(TEXT("tick.wav"), NULL, SND_FILENAME | SND_ASYNC);
				if (y == 20)
				{
					system("cls");
					Name();

					char c = _getch();
					if (c == 13)
					{
						system("cls");
						Menu_1();
					}
					if (c == 27) // Exit
					{
						system("cls");
						ScreenStartGame(99);
						break;
					}
				}
				if (y == 21)
				{
					system("cls");
					Menu_2();
				}
			}
		}
	}
	
	
}
void ScreenStartGame(int n)
{
	AnTroChuot();
	int a[MAX];
	int x = 50, y = 20;
	int i;
	char s[30] = " ";
	int check = 1;
	Textcolor(Red);
	_Common::gotoXY(50, 20); cout << "NEW GAME ";
	Textcolor(7);
	_Common::gotoXY(50, 21); cout << "HIGH SCORE";
	_Common::gotoXY(50, 22); cout << "LOAD GAME";
	_Common::gotoXY(50, 23); cout << "HELP";
	_Common::gotoXY(50, 24); cout << "ABOUT";
	_Common::gotoXY(50, 25); cout << "EXIT";
	Textcolor(Cyan);
	_Common::gotoXY(50, 32); cout << "....... W - S : Move ( Off Unikey - Off Caps Lock ) ";
	_Common::gotoXY(50, 33); cout << "....... Enter : Select ";
	if (n == 100)
	{
		PlaySound(TEXT("nhacnen.wav"), NULL, SND_FILENAME | SND_ASYNC);
		Screen();
		PrintCaro2();
	}
	else
		PrintCaro3();

	while (check)
	{
		if (_kbhit())
		{
			switch (_getch())
			{
			case 'w':
				PlaySound(TEXT("move.wav"), NULL, SND_FILENAME | SND_ASYNC);
				if (y > 20)
				{
					y--;
					_Common::gotoXY(x, y);
				}
				if (y == 20)
				{
					Textcolor(Red);
					_Common::gotoXY(50, 20); cout << "NEW GAME";
					Textcolor(7);
					_Common::gotoXY(50, 21); cout << "HIGH SCORE";
					_Common::gotoXY(50, 22); cout << "LOAD GAME";
					_Common::gotoXY(50, 23); cout << "HELP";
					_Common::gotoXY(50, 24); cout << "ABOUT";
					_Common::gotoXY(50, 25); cout << "EXIT";
				}
				if (y == 21)
				{
					Textcolor(7);
					_Common::gotoXY(50, 20); cout << "NEW GAME";
					Textcolor(Red);
					_Common::gotoXY(50, 21); cout << "HIGH SCORE";
					Textcolor(7);
					_Common::gotoXY(50, 22); cout << "LOAD GAME";
					_Common::gotoXY(50, 23); cout << "HELP";
					_Common::gotoXY(50, 24); cout << "ABOUT";
					_Common::gotoXY(50, 25); cout << "EXIT";
				}
				if (y == 22)
				{
					Textcolor(7);
					_Common::gotoXY(50, 20); cout << "NEW GAME";
					_Common::gotoXY(50, 21); cout << "HIGH SCORE";
					Textcolor(Red);
					_Common::gotoXY(50, 22); cout << "LOAD GAME";
					Textcolor(7);
					_Common::gotoXY(50, 23); cout << "HELP";
					_Common::gotoXY(50, 24); cout << "ABOUT";
					_Common::gotoXY(50, 25); cout << "EXIT";
				}
				if (y == 23)
				{
					Textcolor(7);
					_Common::gotoXY(50, 20); cout << "NEW GAME";
					_Common::gotoXY(50, 21); cout << "HIGH SCORE";
					_Common::gotoXY(50, 22); cout << "LOAD GAME";
					Textcolor(Red);
					_Common::gotoXY(50, 23); cout << "HELP";
					Textcolor(7);
					_Common::gotoXY(50, 24); cout << "ABOUT";
					_Common::gotoXY(50, 25); cout << "EXIT";
				}
				if (y == 24)
				{
					Textcolor(7);
					_Common::gotoXY(50, 20); cout << "NEW GAME";
					_Common::gotoXY(50, 21); cout << "HIGH SCORE";
					_Common::gotoXY(50, 22); cout << "LOAD GAME";
					_Common::gotoXY(50, 23); cout << "HELP";
					Textcolor(Red);
					_Common::gotoXY(50, 24); cout << "ABOUT";
					Textcolor(7);
					_Common::gotoXY(50, 25); cout << "EXIT";
				}
				if (y == 25)
				{
					Textcolor(7);
					_Common::gotoXY(50, 20); cout << "NEW GAME";
					_Common::gotoXY(50, 21); cout << "HIGH SCORE";
					_Common::gotoXY(50, 22); cout << "LOAD GAME";
					_Common::gotoXY(50, 23); cout << "HELP";		
					_Common::gotoXY(50, 24); cout << "ABOUT";
					Textcolor(Red);
					_Common::gotoXY(50, 25); cout << "EXIT";
				}
				break;
			case 's':
				PlaySound(TEXT("move.wav"), NULL, SND_FILENAME | SND_ASYNC);
				if (y < 25)
				{
					y++;
					_Common::gotoXY(x, y);
				}
				if (y == 20)
				{
					Textcolor(Red);
					_Common::gotoXY(50, 20); cout << "NEW GAME";
					Textcolor(7);
					_Common::gotoXY(50, 21); cout << "HIGH SCORE";
					_Common::gotoXY(50, 22); cout << "LOAD GAME";
					_Common::gotoXY(50, 23); cout << "HELP";
					_Common::gotoXY(50, 24); cout << "ABOUT";
					_Common::gotoXY(50, 25); cout << "EXIT";
				}
				if (y == 21)
				{
					Textcolor(7);
					_Common::gotoXY(50, 20); cout << "NEW GAME";
					Textcolor(Red);
					_Common::gotoXY(50, 21); cout << "HIGH SCORE";
					Textcolor(7);
					_Common::gotoXY(50, 22); cout << "LOAD GAME";
					_Common::gotoXY(50, 23); cout << "HELP";
					_Common::gotoXY(50, 24); cout << "ABOUT";
					_Common::gotoXY(50, 25); cout << "EXIT";
				}
				if (y == 22)
				{
					Textcolor(7);
					_Common::gotoXY(50, 20); cout << "NEW GAME";
					_Common::gotoXY(50, 21); cout << "HIGH SCORE";
					Textcolor(Red);
					_Common::gotoXY(50, 22); cout << "LOAD GAME";
					Textcolor(7);
					_Common::gotoXY(50, 23); cout << "HELP";
					_Common::gotoXY(50, 24); cout << "ABOUT";
					_Common::gotoXY(50, 25); cout << "EXIT";
				}
				if (y == 23)
				{
					Textcolor(7);
					_Common::gotoXY(50, 20); cout << "NEW GAME";
					_Common::gotoXY(50, 21); cout << "HIGH SCORE";
					_Common::gotoXY(50, 22); cout << "LOAD GAME";
					Textcolor(Red);
					_Common::gotoXY(50, 23); cout << "HELP";
					Textcolor(7);
					_Common::gotoXY(50, 24); cout << "ABOUT";
					_Common::gotoXY(50, 25); cout << "EXIT";
				}
				if (y == 24)
				{
					Textcolor(7);
					_Common::gotoXY(50, 20); cout << "NEW GAME";
					_Common::gotoXY(50, 21); cout << "HIGH SCORE";
					_Common::gotoXY(50, 22); cout << "LOAD GAME";
					_Common::gotoXY(50, 23); cout << "HELP";
					Textcolor(Red);
					_Common::gotoXY(50, 24); cout << "ABOUT";
					Textcolor(7);
					_Common::gotoXY(50, 25); cout << "EXIT";
				}
				if (y == 25)
				{
					Textcolor(7);
					_Common::gotoXY(50, 20); cout << "NEW GAME";
					_Common::gotoXY(50, 21); cout << "HIGH SCORE";
					_Common::gotoXY(50, 22); cout << "LOAD GAME";
					_Common::gotoXY(50, 23); cout << "HELP";
					_Common::gotoXY(50, 24); cout << "ABOUT";
					Textcolor(Red);
					_Common::gotoXY(50, 25); cout << "EXIT";
				}
				break;
			case 13:
				PlaySound(TEXT("tick.wav"), NULL, SND_FILENAME | SND_ASYNC);
				if (y == 20)
				{
					system("cls");
					Mode();
				}
				if (y == 21)
				{
					showHighScore();
					ScreenStartGame(99);
				}
				if (y == 22)
				{
					LoadLoad();

				}
				if (y == 23)
				{
					Help();
					ScreenStartGame(99);
				}
				if (y == 24)
				{
					About();
					ScreenStartGame(99);
				}
				if (y == 25)
				{
					exit(0);
				}
				break;
			}
		}
	}
}

void Screen()
{
	int check = 1;
	while (check < 20)
	{
		PrintCaro();
		Sleep(100);
		check++;
	}
}

void Menu_1()
{
	PrintScoreBoard_1();
	Textcolor(Cyan);
	_Common::gotoXY(SIZE * 4 + 38, 24);
	cout << "PLAYER ";
	srand(time(NULL));
	ShowCur(0);
	Game_1();
	
	_getch();
}

void Menu_2()
{
	PrintScoreBoard_2();
	Textcolor(Cyan);
	_Common::gotoXY(SIZE * 4 + 32, 24);
	cout << " PLAYER YS PLAYER ";
	srand(time(NULL));
	ShowCur(0);
	Game_2();

	_getch();
}

void PrintScoreBoard_1()
{
	Textcolor(Pink);
	// cot doc
	for (int i = 1; i < SIZE * 2; i++) {
		Sleep(1);
		_Common::gotoXY(SIZE * 4 + 18, i);
		cout << char(219);
	}
	Textcolor(DarkPink);
	for (int i = 1; i < SIZE * 2; i++) {
		Sleep(1);
		_Common::gotoXY(SIZE * 4 + 17, i);
		cout << char(219);
	}
	//
	Textcolor(Red);
	Sleep(1);
	_Common::gotoXY(SIZE * 4 + 5, (SIZE * 2 - 1) / 2 + 1); cout << "S";
	Textcolor(Green);
	_Common::gotoXY(SIZE * 4 + 7, (SIZE * 2 - 1) / 2 + 1); cout << "N";
	Textcolor(Blue);
	_Common::gotoXY(SIZE * 4 + 9, (SIZE * 2 - 1) / 2 + 1); cout << "A";
	Textcolor(Yellow);
	_Common::gotoXY(SIZE * 4 + 11, (SIZE * 2 - 1) / 2 + 1); cout << "K";
	Textcolor(Cyan);
	_Common::gotoXY(SIZE * 4 + 13, (SIZE * 2 - 1) / 2 + 1); cout << "E";
	Textcolor(White);

	// cot ke ben ban co
	for (int i = 0; i < (SIZE * 2 - 1) / 2 - 2; i++)
	{
		Sleep(1);
		_Common::gotoXY(SIZE * 4 + 1, i + 1);
		cout << char(186);
	}
	Sleep(1);
	_Common::gotoXY(SIZE * 4 + 1, 0); cout << char(187);
	_Common::gotoXY(SIZE * 4 + 1, SIZE * 2); cout << char(188);
	for (int i = (SIZE * 2 - 1) / 2 + 3; i < SIZE * 2 - 1; i++)
	{
		Sleep(1);
		_Common::gotoXY(SIZE * 4 + 1, i + 1);
		cout << char(186);
	}
	//
	_Common::gotoXY(SIZE * 4 + 1, (SIZE * 2 - 1) / 2 - 1); cout << char(200);
	for (int i = 0; i < 15; i++)
	{
		Sleep(1);
		cout << char(205);
	}
	_Common::gotoXY(SIZE * 4 + 1, (SIZE * 2 - 1) / 2 + 3); cout << char(201);
	for (int i = 0; i < 15; i++)
	{
		Sleep(1);
		cout << char(205);
	}

	// Bang 3
	Sleep(1);
	_Common::gotoXY(SIZE * 4 + 19, (SIZE * 2 - 1) - 3);
	cout << char(219) << char(205) << char(205) << char(205) << char(205) << char(254);
	for (int i = 0; i < 10; i++) {
		Sleep(1);
		_Common::gotoXY(SIZE * 4 + 25, SIZE * 2 - i);
		cout << char(219);
	}
	for (int i = 0; i < 10; i++) {
		Sleep(1);
		_Common::gotoXY(SIZE * 4 + 61, SIZE * 2 - i);
		cout << char(219);
	}
	_Common::gotoXY(SIZE * 4 + 25, SIZE * 2);
	for (int i = 0; i < 37; i++) {
		Sleep(1);
		cout << char(223);
	}
	_Common::gotoXY(SIZE * 4 + 25, SIZE * 2 - 10);
	for (int i = 0; i < 37; i++) {
		Sleep(1);
		cout << char(220);
	}
	// Bang 1
	Sleep(1);
	_Common::gotoXY(SIZE * 4 + 19, 4);
	cout << char(219) << char(205) << char(205) << char(205) << char(205) << char(254);
	for (int i = 0; i < 8; i++) {
		Sleep(1);
		_Common::gotoXY(SIZE * 4 + 25, i + 1);
		cout << char(219);
	}
	for (int i = 0; i < 8; i++) {
		Sleep(1);
		_Common::gotoXY(SIZE * 4 + 61, i + 1);
		cout << char(219);
	}
	_Common::gotoXY(SIZE * 4 + 25, 0);
	for (int i = 0; i < 37; i++) {
		Sleep(1);
		cout << char(220);
	}
	_Common::gotoXY(SIZE * 4 + 25, 8 + 1);
	for (int i = 0; i < 37; i++) {
		Sleep(1);
		cout << char(223);
	}
	// Bang 2
	_Common::gotoXY(SIZE * 4 + 19, (SIZE * 2 - 1) / 2 + 1);
	cout << char(219) << char(205) << char(205) << char(205) << char(205) << char(254);
	for (int i = 0; i < 8; i++) {
		Sleep(1);
		_Common::gotoXY(SIZE * 4 + 25, 11 + i);
		cout << char(219);
	}
	for (int i = 0; i < 8; i++) {
		Sleep(1);
		_Common::gotoXY(SIZE * 4 + 61, 11 + i);
		cout << char(219);
	}
	_Common::gotoXY(SIZE * 4 + 25, 10);
	for (int i = 0; i < 37; i++) {
		Sleep(1);
		cout << char(220);
	}
	_Common::gotoXY(SIZE * 4 + 25, 11 + 8);
	for (int i = 0; i < 37; i++) {
		Sleep(1);
		cout << char(223);
	}


	_Common::gotoXY(SIZE * 4 + 30, 2);
	cout << "LEVEL :";
	_Common::gotoXY(SIZE * 4 + 30, 4);
	cout << "Speed : ";

	_Common::gotoXY(SIZE * 4 + 30, 12);
	cout << "PLAYER :";
	_Common::gotoXY(SIZE * 4 + 30, 14);
	cout << "Score : ";
	_Common::gotoXY(SIZE * 4 + 30, 16);
	cout << "Hight score : ";

	_Common::gotoXY(SIZE * 4 + 30, 26);
	cout << "-----------------------";
	_Common::gotoXY(SIZE * 4 + 30, 27);
	cout << " W A S D : Move ";
	_Common::gotoXY(SIZE * 4 + 30, 29);
	cout << " SPACE : Pause/Resume ";
	_Common::gotoXY(SIZE * 4 + 30, 31);
	cout << " ESC : Exit ";

	_Common::gotoXY(2, 1);

	Textcolor(DarkBlue);
	_Common::gotoXY(SIZE * 4 + 38, 2);
	cout << "1";
	Textcolor(DarkBlue);
	_Common::gotoXY(SIZE * 4 + 38, 4);
	cout << "150";

	Textcolor(Red);
	_Common::gotoXY(SIZE * 4 + 39, 12);
	cout << ten;
	Textcolor(DarkBlue);
	_Common::gotoXY(SIZE * 4 + 38, 14);
	cout << "0";
	Textcolor(Red);
	_Common::gotoXY(SIZE * 4 + 44, 16);
	cout << "300";
}

void PrintScoreBoard_2()
{
	Textcolor(Pink);
	// cot doc
	for (int i = 1; i < SIZE * 2; i++) {
		Sleep(1);
		_Common::gotoXY(SIZE * 4 + 18, i);
		cout << char(219);
	}
	Textcolor(DarkPink);
	for (int i = 1; i < SIZE * 2; i++) {
		Sleep(1);
		_Common::gotoXY(SIZE * 4 + 17, i);
		cout << char(219);
	}
	//
	Textcolor(Red);
	Sleep(1);
	_Common::gotoXY(SIZE * 4 + 5, (SIZE * 2 - 1) / 2 + 1); cout << "S";
	Textcolor(Green);
	_Common::gotoXY(SIZE * 4 + 7, (SIZE * 2 - 1) / 2 + 1); cout << "N";
	Textcolor(Blue);
	_Common::gotoXY(SIZE * 4 + 9, (SIZE * 2 - 1) / 2 + 1); cout << "A";
	Textcolor(Yellow);
	_Common::gotoXY(SIZE * 4 + 11, (SIZE * 2 - 1) / 2 + 1); cout << "K";
	Textcolor(Cyan);
	_Common::gotoXY(SIZE * 4 + 13, (SIZE * 2 - 1) / 2 + 1); cout << "E";
	Textcolor(White);

	// cot ke ben ban co
	for (int i = 0; i < (SIZE * 2 - 1) / 2 - 2; i++)
	{
		Sleep(1);
		_Common::gotoXY(SIZE * 4 + 1, i + 1);
		cout << char(186);
	}
	Sleep(1);
	_Common::gotoXY(SIZE * 4 + 1, 0); cout << char(187);
	_Common::gotoXY(SIZE * 4 + 1, SIZE * 2); cout << char(188);
	for (int i = (SIZE * 2 - 1) / 2 + 3; i < SIZE * 2 - 1; i++)
	{
		Sleep(1);
		_Common::gotoXY(SIZE * 4 + 1, i + 1);
		cout << char(186);
	}
	//
	_Common::gotoXY(SIZE * 4 + 1, (SIZE * 2 - 1) / 2 - 1); cout << char(200);
	for (int i = 0; i < 15; i++)
	{
		Sleep(1);
		cout << char(205);
	}
	_Common::gotoXY(SIZE * 4 + 1, (SIZE * 2 - 1) / 2 + 3); cout << char(201);
	for (int i = 0; i < 15; i++)
	{
		Sleep(1);
		cout << char(205);
	}

	// Bang 3
	Sleep(1);
	_Common::gotoXY(SIZE * 4 + 19, (SIZE * 2 - 1) - 3);
	cout << char(219) << char(205) << char(205) << char(205) << char(205) << char(254);
	for (int i = 0; i < 10; i++) {
		Sleep(1);
		_Common::gotoXY(SIZE * 4 + 25, SIZE * 2 - i);
		cout << char(219);
	}
	for (int i = 0; i < 10; i++) {
		Sleep(1);
		_Common::gotoXY(SIZE * 4 + 61, SIZE * 2 - i);
		cout << char(219);
	}
	_Common::gotoXY(SIZE * 4 + 25, SIZE * 2);
	for (int i = 0; i < 37; i++) {
		Sleep(1);
		cout << char(223);
	}
	_Common::gotoXY(SIZE * 4 + 25, SIZE * 2 - 10);
	for (int i = 0; i < 37; i++) {
		Sleep(1);
		cout << char(220);
	}
	// Bang 1
	Sleep(1);
	_Common::gotoXY(SIZE * 4 + 19, 4);
	cout << char(219) << char(205) << char(205) << char(205) << char(205) << char(254);
	for (int i = 0; i < 8; i++) {
		Sleep(1);
		_Common::gotoXY(SIZE * 4 + 25, i + 1);
		cout << char(219);
	}
	for (int i = 0; i < 8; i++) {
		Sleep(1);
		_Common::gotoXY(SIZE * 4 + 61, i + 1);
		cout << char(219);
	}
	_Common::gotoXY(SIZE * 4 + 25, 0);
	for (int i = 0; i < 37; i++) {
		Sleep(1);
		cout << char(220);
	}
	_Common::gotoXY(SIZE * 4 + 25, 8 + 1);
	for (int i = 0; i < 37; i++) {
		Sleep(1);
		cout << char(223);
	}
	// Bang 2
	_Common::gotoXY(SIZE * 4 + 19, (SIZE * 2 - 1) / 2 + 1);
	cout << char(219) << char(205) << char(205) << char(205) << char(205) << char(254);
	for (int i = 0; i < 8; i++) {
		Sleep(1);
		_Common::gotoXY(SIZE * 4 + 25, 11 + i);
		cout << char(219);
	}
	for (int i = 0; i < 8; i++) {
		Sleep(1);
		_Common::gotoXY(SIZE * 4 + 61, 11 + i);
		cout << char(219);
	}
	_Common::gotoXY(SIZE * 4 + 25, 10);
	for (int i = 0; i < 37; i++) {
		Sleep(1);
		cout << char(220);
	}
	_Common::gotoXY(SIZE * 4 + 25, 11 + 8);
	for (int i = 0; i < 37; i++) {
		Sleep(1);
		cout << char(223);
	}


	_Common::gotoXY(SIZE * 4 + 40, 2);
	cout << "PLAYER 1";
	_Common::gotoXY(SIZE * 4 + 30, 4);
	cout << "Level : ";
	_Common::gotoXY(SIZE * 4 + 30, 5);
	cout << "Score : ";
	_Common::gotoXY(SIZE * 4 + 30, 6);
	cout << "Speed : ";
	_Common::gotoXY(SIZE * 4 + 30, 7);
	cout << "Hight score : ";

	_Common::gotoXY(SIZE * 4 + 40, 12);
	cout << "PLAYER 2";
	_Common::gotoXY(SIZE * 4 + 30, 14);
	cout << "Level : ";
	_Common::gotoXY(SIZE * 4 + 30, 15);
	cout << "Score : ";
	_Common::gotoXY(SIZE * 4 + 30, 16);
	cout << "Speed : ";
	_Common::gotoXY(SIZE * 4 + 30, 17);
	cout << "Hight score : ";

	_Common::gotoXY(SIZE * 4 + 30, 25);
	cout << "-----------------------";
	_Common::gotoXY(SIZE * 4 + 30, 26);
	cout << " PLAYER 1: " << char(24) << " " << char(25) << " " << char(26) << " " << char(27) << " :" << " Move";
	_Common::gotoXY(SIZE * 4 + 30, 28);
	cout << " PLAYER 2: W A S D : Move ";
	_Common::gotoXY(SIZE * 4 + 30, 29);
	cout << " L : Save Game ";
	_Common::gotoXY(SIZE * 4 + 30, 30);
	cout << " T : Load Game ";
	_Common::gotoXY(SIZE * 4 + 30, 31);
	cout << " ESC : Exit ";

	_Common::gotoXY(2, 1);

	Textcolor(DarkBlue);
	_Common::gotoXY(SIZE * 4 + 38, 4);
	cout << "1";
	Textcolor(DarkBlue);
	_Common::gotoXY(SIZE * 4 + 38, 5);
	cout << "0";
	_Common::gotoXY(SIZE * 4 + 38, 6);
	cout << "150";
	/*Textcolor(Red);*/
	/*_Common::gotoXY(SIZE * 4 + 44, 7);
	cout << "250";*/

	Textcolor(Red);
	_Common::gotoXY(SIZE * 4 + 38, 14);
	cout << "1";
	Textcolor(Red);
	_Common::gotoXY(SIZE * 4 + 38, 15);
	cout << "0";
	_Common::gotoXY(SIZE * 4 + 38, 16);
	cout << "150";
	/*Textcolor(Red);
	_Common::gotoXY(SIZE * 4 + 44, 17);
	cout << "250";*/
}

void showHighScore() 
{
	system("cls");
	PrintCaro3();
	/*ifstream filein;
	filein.open("highscore.txt", ios_base::in);
	string s[100];*/
	Textcolor(Green);
	_Common::gotoXY(58, 18);
	cout <<"SCOREBOARD";
	Sleep(500);
	Textcolor(Red);
	_Common::gotoXY(31, 21);
	cout << "Rank" << endl;
	_Common::gotoXY(45, 21);
	cout << "Player" << endl;
	_Common::gotoXY(65, 21);
	cout << "Score" << endl;
	_Common::gotoXY(87, 21);
	cout << "Level" << endl;
	Sleep(500);
	Textcolor(Cyan);
	_Common::gotoXY(32, 23);
	cout << "1";
	_Common::gotoXY(45, 23);
	cout << "abcxyz";
	_Common::gotoXY(66, 23);
	cout << "300" << endl;
	_Common::gotoXY(89, 23);
	cout << "7" << endl;
	Sleep(500);
	Textcolor(Cyan);
	_Common::gotoXY(32, 25);
	cout << "2";
	_Common::gotoXY(45, 25);
	cout << "player1";
	_Common::gotoXY(66, 25);
	cout << "240" << endl;
	_Common::gotoXY(89, 25);
	cout << "6" << endl;
	Sleep(500);
	Textcolor(Cyan);
	_Common::gotoXY(32, 27);
	cout << "3";
	_Common::gotoXY(45, 27);
	cout << "test_1";
	_Common::gotoXY(66, 27);
	cout << "200" << endl;
	_Common::gotoXY(89, 27);
	cout << "6" << endl;
	Sleep(500);
	Textcolor(Cyan);
	_Common::gotoXY(32, 29);
	cout << "4";
	_Common::gotoXY(45, 29);
	cout << "Thanh Dat";
	_Common::gotoXY(66, 29);
	cout << "160" << endl;
	_Common::gotoXY(89, 29);
	cout << "5" << endl;
	Sleep(500);
	Textcolor(Cyan);
	_Common::gotoXY(32, 31);
	cout << "5";
	_Common::gotoXY(45, 31);
	cout << "test_2";
	_Common::gotoXY(66, 31);
	cout << "130" << endl;
	_Common::gotoXY(89, 31);
	cout << "4" << endl;
	char command = ' ';
	command = _getch();
	system("cls");
	/*while (filein.eof() != true)
	{
		_Common::gotoXY(31, 21);
		filein >> a[n];
		n++;
		filein.ignore();
	}

	filein.close();*/
}
