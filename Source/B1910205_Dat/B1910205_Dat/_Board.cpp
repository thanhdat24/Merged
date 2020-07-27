#include "_Board.h"
#include "_Play.h"
#include <vector>
#include<iostream>
#include<conio.h>
#include"_Game.h"
#include <ctime>
#define MAX 100
using namespace std;
// cấp độ 
int pause = 0;
int pause1 = 0;
int x_pause = 35;
int y_pause = 14;
int x1_pause = 35;
int y1_pause = 14;
int xcu_pause = 35;
int ycu_pause = 14;
int xcu1_pause = 35;
int ycu1_pause = 14;
int speed = 150;
int speed1 = 150;
int speed2 = 150;
int score = 0;
int score1 = 0;
int score2 = 0;
int level = 1;
int level1 = 1;
int level2 = 1;
int xqua;
int yqua;
int xtang;
int xtang1;
int xtang2;
int ytang;
int ytang1;
int ytang2;
int ytang3;
int xgiam;
int xgiam1;
int xgiam2;
int xgiam3;
int ygiam;
int ygiam1;
int ygiam2;
int ygiam3;
int dem = 0;
int x_vc = 30, y_vc = 1;
int x_vc_1 = 63, y_vc_1 = 16;
int xcu_vc = 30, ycu_vc = 1;
int xcu_vc_1 = 63, ycu_vc_1 = 16;
int xspeed = SIZE * 4 + 38;
int yspeed = 4;
int xspeed1 = SIZE * 4 + 38;
int yspeed1 = 6;
int xspeed2 = SIZE * 4 + 38;
int yspeed2 = 16;
int xcu_speed = SIZE * 4 + 38;
int ycu_speed = 4;
int xcu_speed1 = SIZE * 4 + 38;
int ycu_speed1 = 6;
int xcu_speed2 = SIZE * 4 + 38;
int ycu_speed2 = 16;
int k = 1;
int load = 0;
// số lượng đốt
int sl = 3;
int sl1 = 3; 
int sl2 = 3;
//tọa độ 
int toado_x[MAX];
int toado_y[MAX];
int toado_xcu[MAX];
int toado_ycu[MAX];
int toado_x_1[MAX];
int toado_y_1[MAX];
int toado_x_2[MAX];
int toado_y_2[MAX];
int toado_xcu_1[MAX];
int toado_ycu_1[MAX];
int toado_xcu_2[MAX];
int toado_ycu_2[MAX];
void ve_tuong()
{
	Textcolor(Green);
	// ##########################
	for (int i = 0; i < SIZE * 2; i++)
	{
		// Ve cot phai
		Sleep(1);
		_Common::gotoXY(SIZE * 4, i + 1);
		if ((i + 1) % 2 == 1)
			cout << "|";
		else
			cout << "|";
	}
	// ##########################
	for (int i = 0; i < SIZE * 2; i++)
	{
		Sleep(1);
		// Ve cot trai
		_Common::gotoXY(0, i + 1);
		if ((i + 1) % 2 == 1)
			cout << "|";
		else
			cout << "|";
	}
	// ##########################
	// Ve dong dau
	_Common::gotoXY(0, 0);
	for (int i = 0; i < SIZE * 4; i++)
	{
		Sleep(1);
		if (i % 4 == 0)
			cout << "_";
		else
			cout << "_";
	}
	_Common::gotoXY(0, 0); cout << char(201);
	_Common::gotoXY(SIZE * 4, 0); cout << char(187);

	// Ve dong cuoi
	_Common::gotoXY(0, SIZE * 2);
	for (int i = 0; i < SIZE * 4; i++)
	{
		Sleep(1);
		if (i % 4 == 0)
			cout << "_";
		else
			cout << "_";
	}
	_Common::gotoXY(0, SIZE * 2); cout << char(200);
	_Common::gotoXY(SIZE * 4, SIZE * 2);
	cout << char(188);
}

void Game_1()
{
	sl = 3;
	ve_tuong();
	Let_Go();
	_Common::gotoXY(30, 27);
	cout << char(254);
	khoi_tao_ran();
	tao_qua();
	int x = 30, y = 15;
	int check = 2; // 0: đi xuống
				   // 1: đi lên
				   // 2: đi qua phải
				   // 3: đi qua trái 
	int checkvc = 0;
	int checkvc_1 = 0;
	while (true)
	{
		Xoa_du_lieu_cu();
		cap_nhap_du_lieu_cu();

		//-------B2: vẽ rắn và vật cản---------
		// ------- vật cản 1 -----------------
		int i = rand() % (15 - 1 + 1) + 1;
		Textcolor(i);
		_Common::gotoXY(xcu_vc, ycu_vc);
		cout << " ";
		xcu_vc = x_vc, ycu_vc = y_vc;
		_Common::gotoXY(x_vc, y_vc);
		cout << char(169);
		if (checkvc == 0)
		{
			y_vc++;
		}
		else if (checkvc == 1)
		{
			y_vc--;
		}
		if (y_vc == 31) // chạm biên dưới và đi lên
		{
			checkvc = 1;

		}
		else if (y_vc == 1) // chạm biên trên và đi xuống
		{
			checkvc = 0;

		}
		// ------- vật cản 2 -----------------
		int j = rand() % (15 - 1 + 1) + 1;
		Textcolor(j);
		_Common::gotoXY(xcu_vc_1, ycu_vc_1);
		cout << " ";
		xcu_vc_1 = x_vc_1, ycu_vc_1 = y_vc_1;
		_Common::gotoXY(x_vc_1, y_vc_1);
		cout << char(169);
		if (checkvc_1 == 3)
		{
			x_vc_1--;
		}
		else if (checkvc_1 == 2)
		{
			x_vc_1++;
		}
		if (x_vc_1 == 63) // chạm biên trái và đi qua phải
		{
			checkvc_1 = 3;

		}
		else if (x_vc_1 == 1) // chạm biên phải và đi qua trái
		{
			checkvc_1 = 2;

		}
		ve_ran();
		//========== GamOver rắn 1 ===========
		if (gameOver() == true)
		{
			PlaySound(TEXT("win.wav"), NULL, SND_ASYNC);
			system("cls");
			PWIN();
			while (k)
			{
				if (_kbhit())
				{
					switch (_getch())
					{
					case 'y':
						PlaySound(TEXT("move.wav"), NULL, SND_FILENAME | SND_ASYNC);
						system("cls");
						return Menu_1();
						break;
					case 27:
						PlaySound(TEXT("move.wav"), NULL, SND_FILENAME | SND_ASYNC);
						system("cls");
						ScreenStartGame(99);
						break;
					}
				}
			}
			break;
		}
		//======= Xử lí hướng đi rắn 1 ========
		if (_kbhit() == true)
		{
			char c = _getch();
			if (c == 27) // Exit
			{
				PlaySound(TEXT("move.wav"), NULL, SND_FILENAME | SND_ASYNC);
				system("cls");
				ScreenStartGame(99);
				break;
			}
			if (c == 32)
			{
				pause = 1;
			}
			if (c == -32)
			{
				c = _getch();
				{
					if (c == 72 && check != 0)
					{
						check = 1;
					}
					else if (c == 80 && check != 1)
					{
						check = 0;
					}
					else if (c == 77 && check != 3)
					{
						check = 2;
					}
					else if (c == 75 && check != 2)
					{
						check = 3;
					}
				}
			}
		}
		if (pause == 1)
		{
		
			Textcolor(Red);
			_Common::gotoXY(x_pause, y_pause);
			cout<<"Game Pause";
			while (_getch() != 32);//54 la ma aki cua 6
			pause++;
			_Common::gotoXY(xcu_pause, ycu_pause);
			cout << "          ";
			xcu_pause = x_pause, ycu_pause = y_pause;
		}
		//=============== Dựa vào hướng xử lí di chuyển rắn 1 ===========
		if (check == 0)
		{

			y++;
		}
		else if (check == 1)
		{

			y--;
		}
		else if (check == 2)
		{

			x++;
		}
		else if (check == 3)
		{

			x--;
		}
		them(x, y);
		//=========== khi rắn 1 ăn quả ==================
		if (toado_x[0] == xqua && toado_y[0] == yqua)
		{
			PlaySound(TEXT("eatFood.wav"), NULL, SND_ASYNC);
			SetLevelScore();
			tao_qua();
			Textcolor(DarkBlue);
			_Common::gotoXY(SIZE * 4 + 38, 14);
			cout << score;
			Textcolor(DarkBlue);
			_Common::gotoXY(SIZE * 4 + 38, 2);
			cout << level;
			Textcolor(DarkBlue);
			_Common::gotoXY(SIZE * 4 + 38, 4);
			cout << speed;
			_Common::gotoXY(xcu_speed, ycu_speed);
			cout << "   ";
			xcu_speed = xspeed; ycu_speed = yspeed;
			Textcolor(DarkBlue);
			_Common::gotoXY(xspeed, yspeed);
			cout << speed;
		}
		else
		{
			xoa();
		}

		// Ăn buff level 2
		if (toado_x[0] == xtang && toado_y[0] == ytang)
		{
			PlaySound(TEXT("eatFood.wav"), NULL, SND_ASYNC);
			speed -= 10;
			_Common::gotoXY(xcu_speed, ycu_speed);
			cout << "   ";
			xcu_speed = xspeed; ycu_speed = yspeed;
			Textcolor(DarkBlue);
			_Common::gotoXY(xspeed, yspeed);
			cout << speed;

		}
		if (toado_x[0] == xgiam && toado_y[0] == ygiam)
		{
			PlaySound(TEXT("eatFood.wav"), NULL, SND_ASYNC);
			speed += 10;
			_Common::gotoXY(xcu_speed, ycu_speed);
			cout << "   ";
			xcu_speed = xspeed; ycu_speed = yspeed;
			Textcolor(DarkBlue);
			_Common::gotoXY(xspeed, yspeed);
			cout << speed;
		}
		// Ăn buff level 5
		if (toado_x[0] == xtang1 && toado_y[0] == ytang1)
		{
			PlaySound(TEXT("eatFood.wav"), NULL, SND_ASYNC);
			speed -= 20;
			_Common::gotoXY(xcu_speed, ycu_speed);
			cout << "   ";
			xcu_speed = xspeed; ycu_speed = yspeed;
			Textcolor(DarkBlue);
			_Common::gotoXY(xspeed, yspeed);
			cout << speed;

		}
		if (toado_x[0] == xgiam1 && toado_y[0] == ygiam1)
		{
			PlaySound(TEXT("eatFood.wav"), NULL, SND_ASYNC);
			speed += 20;
			_Common::gotoXY(xcu_speed, ycu_speed);
			cout << "   ";
			xcu_speed = xspeed; ycu_speed = yspeed;
			Textcolor(DarkBlue);
			_Common::gotoXY(xspeed, yspeed);
			cout << speed;

		}
		// Ăn buff level 7
		if (toado_x[0] == xtang2 && toado_y[0] == ytang2)
		{
			PlaySound(TEXT("eatFood.wav"), NULL, SND_ASYNC);
			speed -= 30;
			_Common::gotoXY(xcu_speed, ycu_speed);
			cout << "   ";
			xcu_speed = xspeed; ycu_speed = yspeed;
			Textcolor(DarkBlue);
			_Common::gotoXY(xspeed, yspeed);
			cout << speed;

		}
		if (toado_x[0] == xgiam2 && toado_y[0] == ygiam2)
		{
			PlaySound(TEXT("eatFood.wav"), NULL, SND_ASYNC);
			speed += 30;
			_Common::gotoXY(xcu_speed, ycu_speed);
			cout << "   ";
			xcu_speed = xspeed; ycu_speed = yspeed;
			Textcolor(DarkBlue);
			_Common::gotoXY(xspeed, yspeed);
			cout << speed;

		}
		Sleep(speed);
	}

}
void Game_2()
{
	sl1 = 3;
	sl2 = 3;
	ve_tuong();
	Let_Go();
	khoi_tao_ran_1();
	khoi_tao_ran_2();
	tao_qua();
	int x1 = 30, y1 = 15;
	int x2 = 30, y2 = 20;
	int check1 = 2; // 0: đi xuống
				   // 1: đi lên
				   // 2: đi qua phải
				   // 3: đi qua trái 
	int check2 = 2; // 0: đi xuống
				   // 1: đi lên
				   // 2: đi qua phải
				   // 3: đi qua trái 
	int checkvt = 0; 
	while (true)
	{
		Xoa_du_lieu_cu_1();
		cap_nhap_du_lieu_cu_1();
		Xoa_du_lieu_cu_2();
		cap_nhap_du_lieu_cu_2();

		//-------B2: vẽ rắn và vật cản---------
		int i = rand() % (15 - 1 + 1) + 1;
		Textcolor(i);
		_Common::gotoXY(xcu_vc, ycu_vc);
		cout << " ";
		xcu_vc = x_vc, ycu_vc = y_vc;
		_Common::gotoXY(x_vc, y_vc);
		cout << char(169);
		if (checkvt == 0)
		{
			y_vc++;
		}
		else if (checkvt == 1)
		{
			y_vc--;
		}
		if (y_vc == 31) // chạm biên dưới và đi lên
		{
			checkvt = 1;

		}
		else if (y_vc == 1) // chạm biên trên và đi xuống
		{
			checkvt = 0;

		}
		ve_ran_1();
		ve_ran_2();
		//========== GamOver rắn 1 ===========
		if (gameOver_1() == true)
		{
			PlaySound(TEXT("win.wav"), NULL, SND_ASYNC);
			system("cls");
			P2WIN();
			while (k)
			{
				if (_kbhit())
				{
					switch (_getch())
					{
					case 'y':
						PlaySound(TEXT("move.wav"), NULL, SND_FILENAME | SND_ASYNC);
						system("cls");
						return Menu_2();
						break;
					case 27:
						PlaySound(TEXT("move.wav"), NULL, SND_FILENAME | SND_ASYNC);
						system("cls");
						ScreenStartGame(99);
						break;
					}
				}
			}
			break;
		}
		//========== GamOver rắn 1 ===========
		if (gameOver_2() == true)
		{
			PlaySound(TEXT("win.wav"), NULL, SND_ASYNC);
			system("cls");
			P1WIN();
			while (k)
			{
				if (_kbhit())
				{
					switch (_getch())
					{
					case 'y':
						PlaySound(TEXT("move.wav"), NULL, SND_FILENAME | SND_ASYNC);
						system("cls");
						return Menu_2();
						break;
					case 27:
						PlaySound(TEXT("move.wav"), NULL, SND_FILENAME | SND_ASYNC);
						system("cls");
						ScreenStartGame(99);
						break;
					}
				}
			}
			break;
		}
		//======= Xử lí hướng đi rắn 1 ========
		if (_kbhit() == true)
		{
			char c = _getch();
			if (c == 27) // Exit
			{
				PlaySound(TEXT("move.wav"), NULL, SND_FILENAME | SND_ASYNC);
				system("cls");
				ScreenStartGame(99);
				break;
			}
			if (c == 32)
			{
				pause1 = 1;
			}
			if (c == -32)
			{
				c = _getch();
				{
					if (c == 72 && check1 != 0)
					{
						check1 = 1;
					}
					else if (c == 80 && check1 != 1)
					{
						check1 = 0;
					}
					else if (c == 77 && check1 != 3)
					{
						check1 = 2;
					}
					else if (c == 75 && check1 != 2)
					{
						check1 = 3;
					}
				}
			}
			//======= Xử lí hướng đi rắn 2 ========
			if (c == 119 && check2 != 0)
			{
				check2 = 1;
			}
			else if (c == 115 && check2 != 1)
			{
				check2 = 0;
			}
			else if (c == 100 && check2 != 3)
			{
				check2 = 2;
			}
			else if (c == 97 && check2 != 2)
			{
				check2 = 3;
			}
		}	
		if (pause1 == 1)
		{

			Textcolor(Red);
			_Common::gotoXY(x1_pause, y1_pause);
			cout << "Game Pause";
			while (_getch() != 32); //32 mã kí tự phím cách
			pause1++;
			_Common::gotoXY(xcu1_pause, ycu1_pause);
			cout << "          ";
			xcu1_pause = x1_pause, ycu1_pause = y1_pause;
		}
		//=============== Dựa vào hướng xử lí di chuyển rắn 1 ===========
		if (check1 == 0)
		{

			y1++;
		}
		else if (check1 == 1)
		{

			y1--;
		}
		else if (check1 == 2)
		{

			x1++;
		}
		else if (check1 == 3)
		{

			x1--;
		}
		them1(x1, y1);
		//=============== Dựa vào hướng xử lí di chuyển rắn 2 ===========
		if (check2 == 0)
		{
			y2++;
		}
		else if (check2 == 1)
		{
			y2--;
		}
		else if (check2 == 2)
		{
			x2++;
		}
		else if (check2 == 3)
		{
			x2--;
		}
		them2(x2, y2);
		//=========== khi rắn 1 ăn quả ==================
		if (toado_x_1[0] == xqua && toado_y_1[0] == yqua) 
		{
			PlaySound(TEXT("eatFood.wav"), NULL, SND_ASYNC);
			SetLevelScore_1();
			tao_qua();
			Textcolor(DarkBlue);
			_Common::gotoXY(SIZE * 4 + 38, 4);
			cout << level1;
			Textcolor(DarkBlue);
			_Common::gotoXY(SIZE * 4 + 38, 5);
			cout << score1;
			_Common::gotoXY(xcu_speed1, ycu_speed1);
			cout << "   ";
			xcu_speed1 = xspeed1; ycu_speed1 = yspeed1;
			Textcolor(DarkBlue);
			_Common::gotoXY(xspeed1, yspeed1);
			cout << speed1;
		}
		else
		{
			xoa1();
		}
		//=========== khi rắn 2 ăn quả ==================
		if (toado_x_2[0] == xqua && toado_y_2[0] == yqua)
		{
			PlaySound(TEXT("eatFood.wav"), NULL, SND_ASYNC);
			SetLevelScore_2();
			tao_qua();
			Textcolor(Red);
			_Common::gotoXY(SIZE * 4 + 38, 14);
			cout << level2;
			Textcolor(Red);
			_Common::gotoXY(SIZE * 4 + 38, 15);
			cout << score2;
			_Common::gotoXY(xcu_speed2, ycu_speed2);
			cout << "   ";
			xcu_speed2 = xspeed2; ycu_speed2 = yspeed2;
			Textcolor(Red);
			_Common::gotoXY(xspeed2, yspeed2);
			cout << speed2;
		}
		else
		{

			xoa2();
		}
	
		// Ăn buff
		/* if (toado_x_1[0] == xtang && toado_y_1[0] == ytang)
		{
			PlaySound(TEXT("eatFood.wav"), NULL, SND_ASYNC);
			speed2 -= 10;
			_Common::gotoXY(xcu_speed, ycu_speed);
			cout << "   ";
			xcu_speed = xspeed; ycu_speed = yspeed;
			Textcolor(DarkBlue);
			_Common::gotoXY(xspeed, yspeed);
			cout << speed2;
			tao_buff_fast();
		}
		 if (toado_x_1[0] == xgiam && toado_y_1[0] == ygiam)
		 {
			 PlaySound(TEXT("eatFood.wav"), NULL, SND_ASYNC);
			 speed1 += 10;
			 _Common::gotoXY(xcu_speed, ycu_speed);
			 cout << "   ";
			 xcu_speed = xspeed; ycu_speed = yspeed;
			 Textcolor(DarkBlue);
			 _Common::gotoXY(xspeed, yspeed);
			 cout << speed1;
			 tao_buff_slow();
		 }*/

		Sleep(speed1);
	}
}
void khoi_tao_ran()
{
	int x = 30, y = 15;
	for (int i = 0; i < sl; i++)
	{
		toado_x[i] = x;
		toado_y[i] = y;
		x--;// 44 43 42
	}
}

void khoi_tao_ran_1()
{
	int x = 30, y = 15;
	for (int i = 0; i < sl1; i++)
	{
		toado_x_1[i] = x;
		toado_y_1[i] = y;
		x--;
	}
}

void khoi_tao_ran_2()
{
	int x = 30, y = 20;
	for (int i = 0; i < sl2; i++)
	{
		toado_x_2[i] = x;
		toado_y_2[i] = y;
		x--;
	}
}

void ve_ran()
{
	Textcolor(DarkCyan);
	for (int i = 0; i < sl; i++)
	{
		if (i == 0)
		{
			_Common::gotoXY(toado_x[i], toado_y[i]);
			cout << "0";
		}
		else
		{
			_Common::gotoXY(toado_x[i], toado_y[i]);
			cout << "o";
		}
	}
}
void ve_ran_1()
{
	/*int i = rand() % (15 - 1 + 1) + 1;
	Textcolor(i);*/
	Textcolor(DarkCyan);
	for (int i = 0; i < sl1; i++)
	{
		if (i == 0)
		{
			_Common::gotoXY(toado_x_1[i], toado_y_1[i]);
			cout << "0";
		}
		else
		{
			_Common::gotoXY(toado_x_1[i], toado_y_1[i]);
			cout << "o";
		}
	}
}

void ve_ran_2()
{
	Textcolor(Pink);
	for (int i = 0; i < sl2; i++)
	{
		if (i == 0)
		{
			_Common::gotoXY(toado_x_2[i], toado_y_2[i]);
			cout << "0";
		}
		else
		{
			_Common::gotoXY(toado_x_2[i], toado_y_2[i]);
			cout << "o";
		}
	}
}
void them(int x, int y)
{
	for (int i = sl - 1; i >= 0; i--)
	{
		toado_x[i + 1] = toado_x[i];
		toado_y[i + 1] = toado_y[i];
	}
	toado_x[0] = x;
	toado_y[0] = y;
	sl++;
}
void them1(int x, int y)
{
	for (int i = sl1 - 1; i >= 0; i--)
	{
		toado_x_1[i + 1] = toado_x_1[i];
		toado_y_1[i + 1] = toado_y_1[i];
	}
	toado_x_1[0] = x;
	toado_y_1[0] = y;
	sl1++;
}
void them2(int x, int y)
{
	for (int i = sl2 - 1; i >= 0; i--)
	{
		toado_x_2[i + 1] = toado_x_2[i];
		toado_y_2[i + 1] = toado_y_2[i];
	}
	toado_x_2[0] = x;
	toado_y_2[0] = y;
	sl2++;
}
void xoa()
{
	sl--;
}
void xoa1()
{
	sl1--;
}

void xoa2()
{
	sl2--;
}
void khoi_tao_toa_do_cu()
{
	for (int i = 0; i < sl; i++)
	{
		toado_xcu[i] = toado_x[i];
		toado_ycu[i] = toado_y[i];
	}
}
void khoi_tao_toa_do_cu_1()
{
	for (int i = 0; i < sl1; i++)
	{
		toado_xcu_1[i] = toado_x_1[i];
		toado_ycu_1[i] = toado_y_1[i];
	}
}
void khoi_tao_toa_do_cu_2()
{
	for (int i = 0; i < sl2; i++)
	{
		toado_xcu_2[i] = toado_x_2[i];
		toado_ycu_2[i] = toado_y_2[i];
	}
}
void cap_nhap_du_lieu_cu()
{
	for (int i = 0; i < sl; i++)
	{
		toado_xcu[i] = toado_x[i];
		toado_ycu[i] = toado_y[i];
	}
}
void cap_nhap_du_lieu_cu_1()
{
	for (int i = 0; i < sl1; i++)
	{
		toado_xcu_1[i] = toado_x_1[i];
		toado_ycu_1[i] = toado_y_1[i];
	}
}
void cap_nhap_du_lieu_cu_2()
{
	for (int i = 0; i < sl2; i++)
	{
		toado_xcu_2[i] = toado_x_2[i];
		toado_ycu_2[i] = toado_y_2[i];
	}
}
void Xoa_du_lieu_cu()
{
	for (int i = 0; i < sl; i++)
	{
		_Common::gotoXY(toado_xcu[i], toado_ycu[i]);
		cout << " ";
	}
}
void Xoa_du_lieu_cu_1()
{
	for (int i = 0; i < sl1; i++)
	{
		_Common::gotoXY(toado_xcu_1[i], toado_ycu_1[i]);
		cout << " ";
	}
}

void Xoa_du_lieu_cu_2()
{
	for (int i = 0; i < sl2; i++)
	{
		_Common::gotoXY(toado_xcu_2[i], toado_ycu_2[i]);
		cout << " ";
	}
}

void tao_qua()
{
	int i = rand() % (15 - 1 + 1) + 1;
	Textcolor(i);
	//------------- Ramdom ra vị trí quả -----------
	xqua = rand() % (63 - 1 + 1) + 1; // (1,63)
	yqua = rand() % (31 - 1 + 1) + 1; // (1, 31)
	//------------- tạo quả ---------------------
	_Common::gotoXY(xqua, yqua);
	cout << char(164);
	/*int j = rand() % (15 - 1 + 1) + 1;
	Textcolor(j);*/
}

void tao_buff_fast()
{
	Textcolor(Blue);
	//------------- Ramdom ra vị trí buff -----------
	xtang = rand() % (63 - 1 + 1) + 1; // (1,63)
	ytang = rand() % (31 - 1 + 1) + 1; // (1, 31)
	//------------- tạo buff ---------------------
	_Common::gotoXY(xtang, ytang);
	cout << char(187);
}
void tao_buff_fast_1()
{
	Textcolor(Blue);
	//------------- Ramdom ra vị trí buff -----------
	xtang1 = rand() % (63 - 1 + 1) + 1; // (1,63)
	ytang1 = rand() % (31 - 1 + 1) + 1; // (1, 31)
	//------------- tạo buff ---------------------
	_Common::gotoXY(xtang1, ytang1);
	cout << char(187);
}
void tao_buff_fast_2()
{
	Textcolor(Blue);
	//------------- Ramdom ra vị trí buff -----------
	xtang2= rand() % (63 - 1 + 1) + 1; // (1,63)
	ytang2 = rand() % (31 - 1 + 1) + 1; // (1, 31)
	//------------- tạo buff ---------------------
	_Common::gotoXY(xtang2, ytang2);
	cout << char(187);
}
void tao_buff_slow()
{
	Textcolor(Red);
	//------------- Ramdom ra vị trí buff -----------
	xgiam = rand() % (63 - 1 + 1) + 1; // (1,63)
	ygiam = rand() % (31 - 1 + 1) + 1; // (1, 31)
	//------------- tạo buff ---------------------
	_Common::gotoXY(xgiam, ygiam);
	cout << char(171);
}
void tao_buff_slow_1()
{
	Textcolor(Red);
	//------------- Ramdom ra vị trí buff -----------
	xgiam1 = rand() % (63 - 1 + 1) + 1; // (1,63)
	ygiam1 = rand() % (31 - 1 + 1) + 1; // (1, 31)
	//------------- tạo buff ---------------------
	_Common::gotoXY(xgiam1, ygiam1);
	cout << char(171);
}
void tao_buff_slow_2()
{
	Textcolor(Red);
	//------------- Ramdom ra vị trí buff -----------
	xgiam2 = rand() % (63 - 1 + 1) + 1; // (1,63)
	ygiam2 = rand() % (31 - 1 + 1) + 1; // (1, 31)
	//------------- tạo buff ---------------------
	_Common::gotoXY(xgiam2, ygiam2);
	cout << char(171);
}
 // ========== Xử lí thua rắn 1 ==============

bool gameOver()
{
	// nếu rắn chạm tường
	if ((toado_x[0] == 0 || toado_x[0] == 64) || (toado_y[0] == 0 || toado_y[0] == 32))
	{
		return true;
	}
	// nếu rắn chạm đuôi
	for (int i = 1; i < sl; i++) // bắt đầu từ vị trí 1, bỏ vị trí đầu ra 
	{
		if (toado_x[0] == toado_x[i] && toado_y[0] == toado_y[i])
		{
			return true;
		}
	}
	// nếu rắn chạm vật cản 1
	if ((toado_x[0] == xcu_vc) && (toado_y[0] == ycu_vc))
	{
		return true;
	}
	for (int i = 1; i < sl; i++) // bắt đầu từ vị trí 1, bỏ vị trí đầu ra 
	{
		if (xcu_vc == toado_x[i] && ycu_vc == toado_y[i])
		{
			return true;
		}
	}
	// nếu rắn chạm vật cản 2
	if ((toado_x[0] == xcu_vc_1) && (toado_y[0] == ycu_vc_1))
	{
		return true;
	}
	for (int i = 1; i < sl; i++) // bắt đầu từ vị trí 1, bỏ vị trí đầu ra 
	{
		if (xcu_vc_1 == toado_x[i] && ycu_vc_1 == toado_y[i])
		{
			return true;
		}
	}

}
bool gameOver_1()
{
	// nếu rắn chạm tường
	if ((toado_x_1[0] == 0 || toado_x_1[0] == 64) || (toado_y_1[0] == 0 || toado_y_1[0] == 32))
	{
		return true;
	}
	// nếu rắn chạm đuôi
	for (int i = 1; i < sl1; i++) // bắt đầu từ vị trí 1, bỏ vị trí đầu ra 
	{
		if (toado_x_1[0] == toado_x_1[i] && toado_y_1[0] == toado_y_1[i])
		{
			return true;
		}
	}
	// nếu rắn chạm vật cản
	if ((toado_x_1[0] == xcu_vc) && (toado_y_1[0] == ycu_vc))
	{
		return true;
	}

	for (int i = 1; i < sl1; i++) // bắt đầu từ vị trí 1, bỏ vị trí đầu ra 
	{
		if (xcu_vc == toado_x_1[i] && ycu_vc == toado_y_1[i])
		{
			return true;
		}
	}
}
// ========== Xử lí thua rắn 1 ==============
bool gameOver_2()
{
	// nếu rắn chạm tường
	if ((toado_x_2[0] == 0 || toado_x_2[0] == 64) || (toado_y_2[0] == 0 || toado_y_2[0] == 32))
	{
		return true;
	}
	// nếu rắn chạm đuôi
	for (int i = 1; i < sl2; i++) // bắt đầu từ vị trí 1, bỏ vị trí đầu ra 
	{
		if (toado_x_2[0] == toado_x_2[i] && toado_y_2[0] == toado_y_2[i])
		{
			return true;
		}
	}
	// nếu rắn chạm vật cản
	if ((toado_x_2[0] == xcu_vc) && (toado_y_2[0] == ycu_vc))
	{
		return true;
	}

	for (int i = 1; i < sl2; i++) // bắt đầu từ vị trí 1, bỏ vị trí đầu ra 
	{
		if (xcu_vc == toado_x_2[i] && ycu_vc == toado_y_2[i])
		{
			return true;
		}
	}

	// nếu 2 con rắn chạm nhau
	for (int i = 0; i < sl2; i++) // bắt đầu từ rắn 2
	if ((toado_x_1[0] == toado_x_2[i]) && (toado_y_1[0] == toado_y_2[i])) // nếu rắn 1 chạm rắn 2
	{
		return true;
	}

	for (int i = 0; i < sl1; i++) // bắt đầu từ rắn 2
	if ((toado_x_2[0] == toado_x_1[i]) && (toado_y_2[0] == toado_y_1[i])) // nếu rắn 2 chạm rắn 1
	{
		return true;
	}
}
void SetLevelScore()
{
	score += 10;
	if (score >= 20 && level < 2) // level 2
	{
		level++;
		if (level == 2)  speed -= 20;
		tao_buff_fast();
		tao_buff_slow();
	}
	else if (score >= 50 && level < 3) // level 3
	{
		level++;
		if (level == 3) speed -= 30;

	}
	else if (score >= 100 && level < 4) // level 4
	{
		level++;
		if (level == 4) speed -= 20;
	}
	else if (score >= 150 && level < 5) // level 5
	{
		level++;
		if (level == 5) speed -= 30;
		tao_buff_fast_1();
		tao_buff_slow_1();
	}

	else if (score >= 200 && level < 6) // level 6
	{
		level++;
		if (level == 6) speed -= 20;
	}
	else if (score >= 300 && level < 7) // level 7
	{
		level++;
		if (level == 7) speed -= 30;
		tao_buff_fast_2();
		tao_buff_slow_2();
	}
}
void SetLevelScore_1()
{
	score1 += 10;
	if (score1 >= 20 && level1 < 2) // level 2
	{
		level1++;
		if (level1 == 2)  speed1 -= 20;
	}
	else if (score1 >= 50 && level1 < 3) // level 3
	{
		level1++;
		if (level1 == 3) speed1 -= 30;
		
	}
	else if (score1 >= 100 && level1 < 4) // level 4
	{
		level1++;
		if (level1 == 4) speed1 -= 20;
	}
	else if (score1 >= 150 && level1 < 5) // level 5
	{
		level1++;
		if (level1 == 5) speed1 -= 30;
	}

	else if (score1 >= 200 && level1 < 6) // level 6
	{
		level1++;
		if (level1 == 6) speed1 -= 20;
	}
	else if (score1 >= 250 && level1 < 7) // level 7
	{
		level1++;

		if (level1 == 7) speed1 -= 30;
	}
}

void SetLevelScore_2()
{
	score2 += 10;
	if (score2 >= 20 && level2 < 2) // level 2
	{
		level2++;
		if (level2 == 2)  speed2 -= 20;
	}
	else if (score2 >= 50 && level2 < 3) // level 3
	{
		level2++;
		if (level2 == 3) speed2 -= 30;

	}
	else if (score2 >= 100 && level2 < 4) // level 4
	{
		level2++;
		if (level2 == 4) speed2 -= 20;
	}
	else if (score2 >= 150 && level2 < 5) // level 5
	{
		level2++;
		if (level2 == 5) speed2 -= 30;
	}

	else if (score2 >= 200 && level2 < 6) // level 6
	{
		level2++;
		if (level2 == 6) speed2 -= 20;
	}
	else if (score2 >= 250 && level2 < 7) // level 7
	{
		level2++;

		if (level2 == 7) speed2 -= 30;
	}
}

void Let_Go()
{
	// So 3
	int x = 30, y = 11;
	Textcolor(Green);
	_Common::gotoXY(x, y);		     cout << "#######";
	_Common::gotoXY(x - 1, y + 1);  cout << "##     ##";
	_Common::gotoXY(x + 6, y + 2);         cout << "##";
	_Common::gotoXY(x, y + 3);       cout << "#######";
	_Common::gotoXY(x + 6, y + 4);         cout << "##";
	_Common::gotoXY(x - 1, y + 5);  cout << "##     ##";
	_Common::gotoXY(x, y + 6);       cout << "#######";
	Sleep(1000);
	_Common::gotoXY(x, y);		     cout << "       ";
	_Common::gotoXY(x - 1, y + 1);  cout << "         ";
	_Common::gotoXY(x + 6, y + 2);         cout << "  ";
	_Common::gotoXY(x, y + 3);       cout << "       ";
	_Common::gotoXY(x + 6, y + 4);         cout << "  ";
	_Common::gotoXY(x - 1, y + 5);  cout << "          ";
	_Common::gotoXY(x, y + 6);       cout << "       ";

	// So 2
	Sleep(50);
	Textcolor(Pink);
	_Common::gotoXY(x, y);		     cout << "#######";
	_Common::gotoXY(x - 1, y + 1);  cout << "##     ##";
	_Common::gotoXY(x + 6, y + 2);         cout << "##";
	_Common::gotoXY(x, y + 3);       cout << "#######";
	_Common::gotoXY(x - 1, y + 4);  cout << "##";
	_Common::gotoXY(x - 1, y + 5);  cout << "##";
	_Common::gotoXY(x, y + 6);       cout << "########";

	Sleep(1000);
	_Common::gotoXY(x, y);		     cout << "       ";
	_Common::gotoXY(x - 1, y + 1);  cout << "         ";
	_Common::gotoXY(x + 6, y + 2);         cout << "  ";
	_Common::gotoXY(x, y + 3);       cout << "       ";
	_Common::gotoXY(x - 1, y + 4);         cout << "  ";
	_Common::gotoXY(x - 1, y + 5);  cout << "  ";
	_Common::gotoXY(x, y + 6);       cout << "        ";

	//So 1
	Sleep(50);
	Textcolor(DarkYellow);
	_Common::gotoXY(x + 3, y);		     cout << "##";
	_Common::gotoXY(x + 1, y + 1);	   cout << "####";
	_Common::gotoXY(x + 3, y + 2);       cout << "##";
	_Common::gotoXY(x + 3, y + 3);       cout << "##";
	_Common::gotoXY(x + 3, y + 4);       cout << "##";
	_Common::gotoXY(x + 3, y + 5);       cout << "##";
	_Common::gotoXY(x, y + 6);         cout << "########";

	Sleep(1000);
	_Common::gotoXY(x + 3, y);		     cout << "  ";
	_Common::gotoXY(x + 1, y + 1);  cout << "    ";
	_Common::gotoXY(x + 3, y + 2);         cout << "  ";
	_Common::gotoXY(x + 3, y + 3);       cout << "  ";
	_Common::gotoXY(x + 3, y + 4);         cout << "  ";
	_Common::gotoXY(x + 3, y + 5);  cout << "  ";
	_Common::gotoXY(x, y + 6);       cout << "        ";

	// Chu GO
	Textcolor(Red);
	_Common::gotoXY(x - 4, y);		     cout << "#######";
	_Common::gotoXY(x - 5, y + 1);      cout << "########";
	_Common::gotoXY(x - 6, y + 2);      cout << "###";
	_Common::gotoXY(x - 6, y + 3);      cout << "###    ###";
	_Common::gotoXY(x - 6, y + 4);      cout << "###    ###";
	_Common::gotoXY(x - 5, y + 5);       cout << "########";
	_Common::gotoXY(x - 4, y + 6);        cout << "#######";


	_Common::gotoXY(x + 9, y);		     cout << "#######";
	_Common::gotoXY(x + 8, y + 1);      cout << "#########";
	_Common::gotoXY(x + 7, y + 2);     cout << "###     ###";
	_Common::gotoXY(x + 7, y + 3);     cout << "###     ###";
	_Common::gotoXY(x + 7, y + 4);     cout << "###     ###";
	_Common::gotoXY(x + 8, y + 5);      cout << "#########";
	_Common::gotoXY(x + 9, y + 6);       cout << "#######";
	Sleep(1000);
	_Common::gotoXY(x - 4, y);		     cout << "       ";
	_Common::gotoXY(x - 5, y + 1);      cout << "         ";
	_Common::gotoXY(x - 6, y + 2);      cout << "   ";
	_Common::gotoXY(x - 6, y + 3);      cout << "          ";
	_Common::gotoXY(x - 6, y + 4);      cout << "          ";
	_Common::gotoXY(x - 5, y + 5);       cout << "        ";
	_Common::gotoXY(x - 4, y + 6);        cout << "       ";

	_Common::gotoXY(x + 9, y);		     cout << "       ";
	_Common::gotoXY(x + 8, y + 1);      cout << "         ";
	_Common::gotoXY(x + 7, y + 2);     cout << "           ";
	_Common::gotoXY(x + 7, y + 3);     cout << "           ";
	_Common::gotoXY(x + 7, y + 4);     cout << "           ";
	_Common::gotoXY(x + 8, y + 5);      cout << "         ";
	_Common::gotoXY(x + 9, y + 6);       cout << "       ";
}


