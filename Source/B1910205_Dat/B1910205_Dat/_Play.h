#pragma once
#include "_Common.h"
#define SIZE			16   // SIZE BÀN CỜ 
#define Black			0
#define DarkBlue		1
#define DarkGreen		2
#define DarkCyan		3
#define DarkRed			4
#define DarkPink		5
#define DarkYellow		6
#define DarkWhite		7
#define Grey			8
#define Blue			9
#define Green			10
#define Cyan			11
#define Red				12
#define Pink			13
#define Yellow			14
#define White			15
#define defaultColor	7 
#define MAX 100 
// MẶC ĐỊNH CÁC MÀU CƠ BẢN

void PrintCaro();
void PrintCaro2();
void PrintCaro3();
void Screen();

// In chữ CARO 
void Textcolor(int n); // Đổi màu kí tự 
void AnTroChuot();    // Ẩn trỏ chuột
void HienTroChuot();  // Hiện trỏ chuột
void ScreenStartGame(int); // Menu Chính
void PrintScoreBoard_1(); // In bảng điểm 1
void PrintScoreBoard_2(); // In bảng điểm 2
void Help(); // Help
void LoadLoad(); //Load
void About(); // About 
void Name(); // Name
void showHighScore(); 


