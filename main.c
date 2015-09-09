
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
		showString("俄罗斯方块",5,4,7);
		showString("a.开始单人游戏",5,6,7);
		showString("b.开始双人游戏",5,7,7);
		showString("c.修改玩家1按键",5,8,7);
		showString("d.修改玩家2按键",5,9,7);
		showString("e.结束",5,11,7);
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
			showString("旋转",5,6,7);
			c=getch();
			if(c==224)c=getch();
			t[0]._w=c;
			showString("向左",5,6,7);
			c=getch();
			if(c==224)c=getch();
			t[0]._a=c;
			showString("向下",5,6,7);
			c=getch();
			if(c==224)c=getch();
			t[0]._s=c;
			showString("向右",5,6,7);
			c=getch();
			if(c==224)c=getch();
			t[0]._d=c;
			break;
		case 'd':
			showString("旋转",5,6,7);
			c=getch();
			if(c==224)c=getch();
			t[1]._w=c;
			showString("向左",5,6,7);
			c=getch();
			if(c==224)c=getch();
			t[1]._a=c;
			showString("向下",5,6,7);
			c=getch();
			if(c==224)c=getch();
			t[1]._s=c;
			showString("向右",5,6,7);
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