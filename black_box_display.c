#include "black_box_display.h"


void color(word c)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
void gotoXY(uint16 x, uint16 y)
{
	COORD coord = {x*2, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void showString(char* s, uint16 x, uint16 y, word c)
{
	gotoXY(x,y);
	color(c);
	printf(s);
}


void box(char* s, uint16 x0, uint16 y0,uint16 x1, uint16 y1, word c)
{
	int i,j;
	x1+=x0;
	y1+=y0;
	for(i=x0;i!=x1;++i)
	{
		for(j=y0;j!=y1;++j)
		{
			showString(s,i,j,c);
		}
	}
}

int32 button(void)
{
	if(kbhit())return getch();
	else return 0;
}