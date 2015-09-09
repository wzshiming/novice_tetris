#ifndef __TETRIS_H__
#define __TETRIS_H__
#include "black_box_display.h"
#include <Windows.h>
#include "typedef.h"

#include <stdarg.h>

#include <stdlib.h>
#include <time.h>

//form_1
//¡õ¡õ¡õ¡õ	0
//¡õ¡ö¡ö¡õ	6
//¡õ¡ö¡ö¡õ	6
//¡õ¡õ¡õ¡õ	0
#define form_1_a	0x0660
#define form_1_b	form_1_a
#define form_1_c	form_1_a
#define form_1_d	form_1_a


//form_2
//¡õ¡õ¡ö¡õ	2
//¡õ¡õ¡ö¡õ	2
//¡õ¡õ¡ö¡õ	2
//¡õ¡õ¡ö¡õ	2
#define form_2_a	0x2222
#define form_2_c	form_2_a
//¡õ¡õ¡õ¡õ	0
//¡õ¡õ¡õ¡õ	0
//¡ö¡ö¡ö¡ö	f
//¡õ¡õ¡õ¡õ	0
#define form_2_b	0x00f0
#define form_2_d	form_2_b


//form_3
//¡õ¡õ¡ö¡õ	2
//¡õ¡õ¡ö¡õ	2
//¡õ¡ö¡ö¡õ	6
//¡õ¡õ¡õ¡õ	0
#define form_3_a	0x2260
//¡õ¡õ¡õ¡õ	0
//¡ö¡ö¡ö¡õ	e
//¡õ¡õ¡ö¡õ	2
//¡õ¡õ¡õ¡õ	0
#define form_3_b	0x0e20
//¡õ¡õ¡õ¡õ	0
//¡õ¡ö¡ö¡õ	6
//¡õ¡ö¡õ¡õ	4
//¡õ¡ö¡õ¡õ	4
#define form_3_c	0x0644
//¡õ¡õ¡õ¡õ	0
//¡õ¡ö¡õ¡õ	4
//¡õ¡ö¡ö¡ö	7
//¡õ¡õ¡õ¡õ	0
#define form_3_d	0x0470


//form_4
//¡õ¡ö¡õ¡õ	4
//¡õ¡ö¡õ¡õ	4
//¡õ¡ö¡ö¡õ	6
//¡õ¡õ¡õ¡õ	0
#define form_4_a	0x4460
//¡õ¡õ¡õ¡õ	0
//¡õ¡õ¡ö¡õ	2
//¡ö¡ö¡ö¡õ	e
//¡õ¡õ¡õ¡õ	0
#define form_4_b	0x02e0
//¡õ¡õ¡õ¡õ	0
//¡õ¡ö¡ö¡õ	6
//¡õ¡õ¡ö¡õ	2
//¡õ¡õ¡ö¡õ	2
#define form_4_c	0x0622
//¡õ¡õ¡õ¡õ	0
//¡õ¡ö¡ö¡ö	7
//¡õ¡ö¡õ¡õ	4
//¡õ¡õ¡õ¡õ	0
#define form_4_d	0x0740


//form_5
//¡õ¡õ¡õ¡õ	0
//¡õ¡ö¡ö¡õ	6
//¡õ¡õ¡ö¡ö	3
//¡õ¡õ¡õ¡õ	0
#define form_5_a	0x0630
#define form_5_c	form_5_a
//¡õ¡õ¡õ¡õ	0
//¡õ¡õ¡ö¡õ	2
//¡õ¡ö¡ö¡õ	6
//¡õ¡ö¡õ¡õ	4
#define form_5_b	0x0264
#define form_5_d	form_5_b


//form_6
//¡õ¡õ¡õ¡õ	0
//¡õ¡õ¡ö¡ö	3
//¡õ¡ö¡ö¡õ	6
//¡õ¡õ¡õ¡õ	0
#define form_6_a	0x0360
#define form_6_c	form_6_a
//¡õ¡õ¡õ¡õ	0
//¡õ¡ö¡õ¡õ	4
//¡õ¡ö¡ö¡õ	6
//¡õ¡õ¡ö¡õ	2
#define form_6_b	0x0462
#define form_6_d	form_6_b


//form_7
//¡õ¡õ¡õ¡õ	0
//¡õ¡õ¡ö¡õ	2
//¡õ¡ö¡ö¡ö	7
//¡õ¡õ¡õ¡õ	0
#define form_7_a	0x0270
//¡õ¡õ¡õ¡õ	0
//¡õ¡õ¡ö¡õ	2
//¡õ¡ö¡ö¡õ	6
//¡õ¡õ¡ö¡õ	2
#define form_7_b	0x0262
//¡õ¡õ¡õ¡õ	0
//¡õ¡õ¡õ¡õ	0
//¡õ¡ö¡ö¡ö	7
//¡õ¡õ¡ö¡õ	2
#define form_7_c	0x0072
//¡õ¡õ¡õ¡õ	0
//¡õ¡õ¡ö¡õ	2
//¡õ¡õ¡ö¡ö	3
//¡õ¡õ¡ö¡õ	2
#define form_7_d			0x0232

#define random(x)			(rand()%x)
#define tetris_X			(t->_x0)
#define tetris_Y			(t->_y0)
#define tetris_width_max	(t->_x1)
#define tetris_length_max	(t->_y1)
#define tetris_sub_box_X	(tetris_X+tetris_width_max+1)
#define tetris_sub_box_Y	(tetris_Y+3)
#define lv(x)				(100-x)
#define form_size			3
#define form_next(i)		((i)!=form_size?++(i):((i)=0))
#define form__(s)			{form_## s ##_a,form_## s ##_b,form_## s ##_c,form_## s ##_d}
static word form[][4]={form__(1),form__(2),form__(3),form__(4),form__(5),form__(6),form__(7),};


typedef struct
{
	int16	_f;//0-6
	int16	_i;//0-3
	word	_c;//ÑÕÉ«
	int16	_x;
	int16	_y;
}tetrisForm;
typedef word tetrisUnsolved;
typedef struct
{
	tetrisUnsolved*	_li;
	int16			_x0;
	int16			_y0;
	int16			_x1;
	int16			_y1;
	int16			_z;
	uint32			_drop_point;
	uint32			_clear_point;
	tetrisForm*		_now;
	tetrisForm*		_after;
	boolean			_flag;
	int32			_l;
	int32			_w,_a,_s,_d;
}tetris;


void	tetrisIni(tetris* t,int16 x0,int16 y0,int16 x1,int16 y1);
uint32	loopTetris(uint32 u,tetris* t);
void	tetrispoint(tetris* t,uint16 u);
uint32	tetrisAction(tetris* t,int16 u);
void	tetrisDisplay(tetris* t,int16 u,...);
void	tetrisSwapForm(tetris* t);
void	tetrisFormInit(tetris* t,tetrisForm* f,int16 x,int16 y);
void	tetrisFormMove(tetris* t,tetrisForm* f,int16 x,int16 y);
boolean	tetrisFormInto(tetris* t,tetrisForm* f);
void	tetrisFormCopy(tetris* t,tetrisForm* f1,tetrisForm* f2);
void	tetrisUnsolvedInit(tetris* t,tetrisUnsolved** w);
int32	tetrisUnsolvedFull(tetris* t,tetrisUnsolved* w,int16 y);
void	tetrisUnsolvedAddForm(tetris* t,tetrisUnsolved* w,tetrisForm* f);


#endif //__TETRIS_H__