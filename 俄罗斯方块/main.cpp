//欢迎加群348538085
#include<iostream>
#include<windows.h>
#include<conio.h>
#include<ctime>
#include"Game_cube.h"
using std::cout;
using std::cin;
using std::endl;
//================================================================
void gotoxy(short x,short y);
//================================================================
int main()
{
	system("mode con: cols=54 lines=26");
	srand((unsigned)time(0));
	enum {_224=224,up=72,down=80,left=75,right=77,space=32,enter=13};//接收上下左右键第一个需要两个变量，第一个值是224
	int score=0,level=0;
	short M=1;
	double _time=0.5;//下降的时间间隔(秒),其实说CLOCKS_PER_SEC在windows下是1000，这里time的单位才可以说是秒)
	//===========================================
	//场地对象
	Area area;
	area.paint();
	//===========================================
	//启动问候语
	gotoxy(10,5);cout<<"俄罗斯方块";
	gotoxy(8,6);
	system("pause");
	gotoxy(10,5);cout<<"         ";
	gotoxy(8,6);cout<<"                   ";
	//===========================================
	gotoxy(area.area_x+11,8);cout<<score;
	gotoxy(area.area_x+11,10);cout<<level;
	clock_t start,end;
	Cube *cube_one=new Cube;//方块1对象
LOOP:
	Cube *cube_two=new Cube;//下一个方块
	cube_two->paint_next(area);
	start=clock();
	cube_one->drop(area);
	while(1)
	{
		end=clock();
		while(_time*CLOCKS_PER_SEC<=end-start)
		{
			if(!cube_one->drop(area))
			{
				if(cube_one->over(area))
				{
					Gameover(area);
				}
				LOOP2:
				delete cube_one;
				cube_one=cube_two;//用2替换1
				goto LOOP;
			}
			start=clock();
		}
		short m;
		if(m=cube_one->clear(area))
		{
			cout<<"\a";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED);
			score+=m*10;
			gotoxy(area.area_x+11,8);cout<<score;
			if(score/60>level)
			{
				if(_time>0.1)
				{
					_time-=0.05;
					level=score/60;
					gotoxy(area.area_x+11,10);cout<<level;
				}
				else
				{
					gotoxy(area.area_x+11,10);cout<<"超神级别！";
				}
			}
			goto LOOP2;
		}
		while(kbhit())
		{
			short one,two;
			one=getch();
			switch(one)
			{
			case _224:two=getch();
						switch(two)
						  {
							case up:cube_one->up(area);			break;
							case left:cube_one->left(area);		break;
							case right:cube_one->right(area);	break;
							case down:cube_one->down(area);		break;
							default:							break;
						  }								break;
			case space:cube_one->end(area);				break;//空格到底部
			case enter:getch();							break;//回车是暂停
			default:									break;
			}
		}
		Sleep(1);
	}
	return 0;
}
//================================================================
void gotoxy(short x,short y)
{
	COORD coord;
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void Gameover(Area &t)
{
	short i;
	for(i=0;i<cube_xy;i+=2)
	{
		if(t.occupied[i])
		{
			gotoxy(t.occupied[i],t.occupied[i+1]);
			cout<<" ";
		}
	}
	gotoxy(10,5);cout<<"Game Over";
	gotoxy(8,6);
	system("pause");
	exit(EXIT_SUCCESS);
}
