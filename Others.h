#ifndef Other_h
#define Other_h

#include <vector>

using namespace std;

void clrscr();

void gotoxy(int x, int y);

void setcolor(unsigned int color);

void setcolor(unsigned int color, unsigned int background_color);

int makeMenu (string titulo, vector <string> opcoes, int frase);

void pause();

#endif