#include "Others.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <Windows.h>

using namespace std;

void clrscr()
{
	COORD coordScreen = { 0, 0 }; // upper left corner
	DWORD cCharsWritten;
	DWORD dwConSize;
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hCon, &csbi);
	dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
	// fill with spaces
	FillConsoleOutputCharacter(hCon, TEXT(' '), dwConSize, coordScreen, &cCharsWritten);
	GetConsoleScreenBufferInfo(hCon, &csbi);
	FillConsoleOutputAttribute(hCon, csbi.wAttributes, dwConSize, coordScreen, &cCharsWritten);
	// cursor to upper left corner
	SetConsoleCursorPosition(hCon, coordScreen);
}

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void setcolor(unsigned int color)
{
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hcon, color);
}

void setcolor(unsigned int color, unsigned int background_color)
{
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE); if (background_color == 0)
		SetConsoleTextAttribute(hCon, color); else
		SetConsoleTextAttribute(hCon, color | background_color * 16 + color);
}

int makeMenu(string titulo, vector <string> opcoes)
{
	//mostrar opcoes
	cout << titulo << endl << endl;
	for (unsigned int i = 0; i < opcoes.size(); i++)
	{
		cout << endl << "   " << opcoes[i] << endl;
	}
	//ler input
	unsigned int input, option = 0;
	while (true)
	{
		gotoxy(0, 3 + option * 2);
		cout << "->";
		switch (input = _getch())
		{
		case '\r': //ENTER
		{
					   clrscr();
					   return option;
		}
		case 72: //up arrow
		{
					 if (option > 0)
					 {
						 gotoxy(0, 3 + option * 2);
						 cout << "  ";
						 option--;
					 }
					 break;
		}
		case 80: //down arrow
		{
					 if (option < opcoes.size() - 1)
					 {
						 gotoxy(0, 3 + option * 2);
						 cout << "  ";
						 option++;
					 }
					 break;
		}
		default:
			break;
		}
	}
}
