
#include "tetris.h"
#include <Windows.h>





//tmp p2;

int main(int argc,char *argv[])
{
	int32	i;
	int32	c;
	tetris	t[2];
	t[0]._w='w';
	t[0]._a='a';
	t[0]._s='s';
	t[0]._d='d';
	t[1]._w=72;
	t[1]._a=75;
	t[1]._s=80;
	t[1]._d=77;
	while(1)
	{
		showString("����˹����",5,4,7);
		showString("a.��ʼ������Ϸ",5,6,7);
		showString("b.��ʼ˫����Ϸ",5,7,7);
		showString("c.�޸����1����",5,8,7);
		showString("d.�޸����2����",5,9,7);
		showString("e.����",5,11,7);
		i=getch();
		system("cls");
		switch(i)
		{
		case 'a':
			tetrisIni(&t[0],10,3,10,20);
			loopTetris(1,t);
			break;
		case 'b':
			tetrisIni(&t[0],2,3,10,20);
			tetrisIni(&t[1],20,3,10,20);
			loopTetris(2,t);
			break;
		case 'c':
			showString("��ת",5,6,7);
			c=getch();
			if(c==224)c=getch();
			t[0]._w=c;
			showString("����",5,6,7);
			c=getch();
			if(c==224)c=getch();
			t[0]._a=c;
			showString("����",5,6,7);
			c=getch();
			if(c==224)c=getch();
			t[0]._s=c;
			showString("����",5,6,7);
			c=getch();
			if(c==224)c=getch();
			t[0]._d=c;
			break;
		case 'd':
			showString("��ת",5,6,7);
			c=getch();
			if(c==224)c=getch();
			t[1]._w=c;
			showString("����",5,6,7);
			c=getch();
			if(c==224)c=getch();
			t[1]._a=c;
			showString("����",5,6,7);
			c=getch();
			if(c==224)c=getch();
			t[1]._s=c;
			showString("����",5,6,7);
			c=getch();
			if(c==224)c=getch();
			t[1]._d=c;
			break;
		case 'e':
			system("pause");
			return 1;
		default:
			break;
		}
		system("cls");
	}
	system("pause");
	return 0;
}