#include "_Play.h"
#include "_Common.h"
#include "_Play.h"
#include <string.h>
#include<iostream>
using namespace std;

int main()
{
	SetConsoleTitle(TEXT("Game ran san moi")); //Đặt tiêu đề cho game 
	int n = 100;
	_Common::fixConsoleWindow();
	_Common::setConsoleWindow(1000, 600);
	ScreenStartGame(n);
	system("pause");
	return 0;
}