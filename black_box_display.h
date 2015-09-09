#ifndef __BLACK_BOX_DISPLAY_H__
#define __BLACK_BOX_DISPLAY_H__


#include "typedef.h"
#include <Windows.h>
#include <conio.h>
#include <stdio.h>
void color(word c);
void gotoXY(uint16 x, uint16 y);
void showString(char* s, uint16 x, uint16 y, word c);
void box(char* s, uint16 x0, uint16 y0,uint16 x1, uint16 y1, word c);
int32 button(void);

/*

#define FOREGROUND_BLUE      0x0001 // ��ɫ
#define FOREGROUND_GREEN     0x0002 // ��ɫ
#define FOREGROUND_RED       0x0004 // ��ɫ
#define FOREGROUND_INTENSITY 0x0008 // ��ɫ�ǼӾ�
#define BACKGROUND_BLUE      0x0010 // ������ɫ
#define BACKGROUND_GREEN     0x0020 // ������ɫ
#define BACKGROUND_RED       0x0040 // ������ɫ
#define BACKGROUND_INTENSITY 0x0080 // ������ɫ�ǼӾ�
#define COMMON_LVB_LEADING_BYTE    0x0100 // Leading Byte of DBCS
#define COMMON_LVB_TRAILING_BYTE   0x0200 // Trailing Byte of DBCS
#define COMMON_LVB_GRID_HORIZONTAL 0x0400 // DBCS: �ϻ���
#define COMMON_LVB_GRID_LVERTICAL  0x0800 // DBCS: ����
#define COMMON_LVB_GRID_RVERTICAL  0x1000 // DBCS: �һ���
#define COMMON_LVB_REVERSE_VIDEO   0x4000 // DBCS: �෴��ʾ
#define COMMON_LVB_UNDERSCORE      0x8000 // DBCS: �»���

#define COMMON_LVB_SBCSDBCS        0x0300 // SBCS or DBCS flag.

*/

#endif //__BLACK_BOX_DISPLAY_H__
