
#include "tetris.h"

void tetrisIni(tetris* t,int16 x0,int16 y0,int16 x1,int16 y1)
{
	srand(time(0));
	t->_x0			=x0;
	t->_y0			=y0;
	t->_x1			=x1;
	t->_y1			=y1;
	t->_drop_point	=-1;
	t->_clear_point	=-1;
	t->_z			=0;
	t->_flag		=1;
	t->_l			=1;
	t->_now			=(tetrisForm*)malloc(sizeof(tetrisForm));
	t->_after		=(tetrisForm*)malloc(sizeof(tetrisForm));
	tetrisUnsolvedInit(t,&t->_li);
	tetrisFormInit(t,t->_after,3,-3);
	tetrisFormInit(t,t->_now,3,-3);
	tetrisDisplay(t,0);
	tetrisDisplay(t,3,t->_after);
	tetrispoint(t,1);
	tetrispoint(t,2);
}
void tetrispoint(tetris* t,uint16 u)
{
	char str[32];
	switch(u)
	{
	case 1:
		++t->_drop_point;
		sprintf(str,"下落:%u\t",t->_drop_point);
		tetrisDisplay(t,7,str,0);
		break;
	case 2:
		++t->_clear_point;
		sprintf(str,"消除:%u\t",t->_clear_point);
		tetrisDisplay(t,7,str,1);
		t->_l=t->_clear_point/10+1;
		sprintf(str,"等级:%u\t",t->_l);
		tetrisDisplay(t,7,str,2);
		break;
	default:
		break;
	}
}
uint32 loopTetris(uint32 u,tetris* t)
{
	
	int32	ch;
	uint32	i;
	while(1)
	{
		Sleep(lv(t->_l));
		ch=button();
		for(i=0;i!=u;++i)
		{
			if(ch)tetrisAction(&t[i],ch);
			tetrisAction(&t[i],0);
			if(!t[i]._flag)
			{
				tetrisDisplay(&t[i],8,"游戏结束",0);
				return i;
			}
		}
		
	}
	
	return 0;
}
uint32 tetrisAction(tetris* t,int16 u)
{

	tetrisDisplay(t,2,t->_now);

	if(u==t->_w)tetrisFormMove(t,t->_now,0,0);
	else if(u==t->_a)tetrisFormMove(t,t->_now,-1,0);
	else if(u==t->_s)tetrisFormMove(t,t->_now,0,1);
	else if(u==t->_d)tetrisFormMove(t,t->_now,1,0);
	else
	{
		if(++t->_z==10)
		{
			t->_z=0;
			tetrisFormMove(t,t->_now,0,1);
		}
	}
	tetrisDisplay(t,1,t->_now);
	return 0;
}

void tetrisDisplay(tetris* t,int16 u,...)
{
	union
	{
		tetrisForm*			f;
		tetrisUnsolved*		u;
		char*				s;
	}p;

	int32 i,j,k,m,n;
	va_list valist;
	va_start(valist,u);
	
	switch(u)
	{
	case 0:
		box("□",tetris_X,tetris_Y,tetris_width_max,tetris_length_max,7);
		box("□",tetris_sub_box_X,tetris_sub_box_Y,4,4,7);
		break;
	case 1:
	case 2:
	case 3:
	case 4:
		p.f=va_arg(valist,tetrisForm*);
		for(i=0;i!=4;++i)
			for(j=0;j!=4;++j)
				if((1<<(j*4+i))&form[p.f->_f][p.f->_i])
					switch(u)
					{
					case 1:
						m=tetris_X+p.f->_x+i;
						n=tetris_Y+p.f->_y+j;
						if(n<tetris_Y)break;
						showString("■",m,n,p.f->_c);
						break;
					case 2:
						m=tetris_X+p.f->_x+i;
						n=tetris_Y+p.f->_y+j;
						if(n<tetris_Y)break;
						showString("□",m,n,7);
						break;
					case 3:
						showString("■",tetris_sub_box_X+i,tetris_sub_box_Y+j,p.f->_c);
						break;
					case 4:
						showString("□",tetris_sub_box_X+i,tetris_sub_box_Y+j,7);
						break;
					default:
						break;
					}
				
		break;
	case 5:
		p.u=va_arg(valist,tetrisUnsolved*);
		for(i=0;i!=tetris_width_max;++i)
			for(j=0;j!=tetris_length_max;++j)
				if(k=p.u[j*tetris_width_max+i])
					showString("  ",tetris_X+i,tetris_Y+j,k<<4);
		break;
	case 6:
		p.u=va_arg(valist,tetrisUnsolved*);
		for(i=0;i!=tetris_width_max;++i)
			for(j=0;j!=tetris_length_max;++j)
				if(p.u[j*tetris_width_max+i])
					showString("□",tetris_X+i,tetris_Y+j,7);
		break;
	case 7:
		p.s=va_arg(valist,char*);
		showString(p.s,tetris_sub_box_X,tetris_sub_box_Y+4+va_arg(valist,int16),7);
		break;
	case 8:
		p.s=va_arg(valist,char*);
		showString(p.s,tetris_X,tetris_Y+tetris_length_max+va_arg(valist,int16),7);
		break;
	default:
		break;
	}
	va_end (valist);
}
void tetrisSwapForm(tetris* t)
{
	tetrisForm* tm=t->_now;
	t->_now=t->_after;
	t->_after=tm;
	tetrisFormInit(t,t->_after,3,-3);
	tetrisDisplay(t,4,t->_now);
	tetrisDisplay(t,3,t->_after);
	tetrisDisplay(t,5,t->_li);

}

void tetrisFormInit(tetris* t,tetrisForm* f,int16 x,int16 y)
{
	f->_i= 0;
	f->_x= x;
	f->_y= y;
	f->_c=random(6)+1;
	f->_f=random(7);
}
void tetrisFormMove(tetris* t,tetrisForm* f,int16 x,int16 y)
{
	tetrisForm ft;

	tetrisFormCopy(t,&ft,f);
	if(!(x||y))
		form_next(ft._i);
	else
	{
		ft._x+=x;
		ft._y+=y;
	}
	
	if(tetrisFormInto(t,&ft))
	{
		if(y)
		{
			tetrisDisplay(t,1,t->_now);
			tetrisUnsolvedAddForm(t,t->_li,f);
			tetrisSwapForm(t);
			tetrispoint(t,1);
		}
	}else tetrisFormCopy(t,f,&ft);
}
boolean tetrisFormInto(tetris* t,tetrisForm* f)
{
	int16 i,j;

	int16 m,n;
	for(i=0;i!=4;++i)
		for(j=0;j!=4;++j)
			if((1<<(j*4+i))&form[f->_f][f->_i])
			{
				m=f->_x+i;
				n=f->_y+j;
				if(n<0)continue;
				if(m<0||m>=tetris_width_max)
					return 1;
				if(t->_li[n*tetris_width_max+m]||n>=tetris_length_max)
					return 2;
			}
	return 0;
}

void tetrisFormCopy(tetris* t,tetrisForm* f1,tetrisForm* f2)
{
	f1->_c=f2->_c;
	f1->_f=f2->_f;
	f1->_i=f2->_i;
	f1->_x=f2->_x;
	f1->_y=f2->_y;
}

void tetrisUnsolvedInit(tetris* t,tetrisUnsolved** w)
{
	int16 i;
	(*w)=(tetrisUnsolved*)malloc(tetris_width_max*tetris_length_max*sizeof(tetrisUnsolved));
	for(i=0;i!=tetris_width_max*tetris_length_max;++i)
		(*w)[i]=0;
}
int32 tetrisUnsolvedFull(tetris* t,tetrisUnsolved* w,int16 y)
{
	int16 i,j;
	for(i=0;i!=tetris_width_max;++i)
		if(!w[y*tetris_width_max+i])return 0;
	tetrisDisplay(t,6,t->_li);
	for(i=0;i!=tetris_width_max;++i)
		w[i]=0;
	for(j=y-1;j!=0;--j)
		for(i=0;i!=tetris_width_max;++i)
			w[(j+1)*tetris_width_max+i]=w[j*tetris_width_max+i];
	tetrisDisplay(t,5,t->_li);
	tetrispoint(t,2);
	return 1;
}

void tetrisUnsolvedAddForm(tetris* t,tetrisUnsolved* w,tetrisForm* f)
{
	int16 i,j;
	for(i=0;i!=4;++i)
		for(j=0;j!=4;++j)
			if((1<<(j*4+i))&form[f->_f][f->_i])
			{
				if(f->_y+j<=0)t->_flag=0;
				w[(f->_y+j)*tetris_width_max+(f->_x+i)]=f->_c;
			}
	for(i=0;i!=4;++i)
		tetrisUnsolvedFull(t,w,f->_y+i);

}