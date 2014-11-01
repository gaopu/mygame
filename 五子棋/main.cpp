#include<iostream>
#include<graphics.h>
#include<Windows.h>
#include<conio.h>
#include"chess.h"
using std::cout;
using std::cin;
using std::endl;

int main()
{
	CHESS five;//五子棋对象
	MOUSEMSG MSG;
	while(1)
	{
		while(MouseHit())//若有鼠标消息
		{
			MSG=GetMouseMsg();
			switch(MSG.uMsg)
			{
			case WM_LBUTTONUP:
				if(five.paint(MSG.x,MSG.y))
				{
					getch();
					return 0;
				}
				break;
			default:
				break;
			}
		}

		Sleep(1);
	}
	return 0;
}