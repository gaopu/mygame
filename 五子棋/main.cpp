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
	CHESS five;//���������
	MOUSEMSG MSG;
	while(1)
	{
		while(MouseHit())//���������Ϣ
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