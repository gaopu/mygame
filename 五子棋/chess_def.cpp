#include"chess.h"
#include<graphics.h>

CHESS::CHESS()
{
	initgraph(534,530);
	loadimage(&chessboard,_T("chessboard.jpg"));
	loadimage(&white_win,_T("white_win.jpg"));
	loadimage(&black_win,_T("black_win.jpg"));
	loadimage(&white_chess,_T("white.jpg"));
	loadimage(&black_chess,_T("black.jpg"));//加载棋盘，黑白棋子的图片,底图
	condition=_black;
	int i;
	for(i=0;i<2*15*15;i++)
	{
		occupied[i]=1;//全部赋值为1，不赋值为0是因为可能存储的是(0,0)
	}
	for(i=0;i<15*15+1;i++)
	{
		white_occupied[i]=1;
		black_occupied[i]=1;
	}
	putimage(0,0,&chessboard);//绘画棋盘
	setorigin(chess_origin_x,chess_origin_y);//更改坐标原点到第一个棋子绘制的位置

}
bool CHESS::paint(short x,short y)
{
	x=x/distance*distance;
	y=y/distance*distance;//由于背景图限制,所以不可能绘画到其他不正确的地方，所以可以不判断是否绘画不在"棋点"上
	int i;
	for(i=0;i<2*15*15;i+=2)//先判断是否在此位置输出过棋子
	{
		if(occupied[i]!=1)
		{
			if(occupied[i]==x && occupied[i+1]==y)
			{
				return false;
			}
		}
	}
	for(i=0;i<2*15*15;i+=2)//先存储在公共的数组里
	{
		if(occupied[i]==1)
		{
			occupied[i]=x;
			occupied[i+1]=y;
			break;
		}
	}
	switch(condition)
	{
	case _black:
		putimage(x,y,&black_chess,SRCAND);
		for(i=0;i<15*15+1;i+=2)//没有的话就要存储起来这个位置
		{
			if(black_occupied[i]==1)
			{
				black_occupied[i]=x;
				black_occupied[i+1]=y;
				break;
			}
		}
		if(win(condition,x,y))
		{
			return true;
		}
		condition=_white;
		break;
	case _white:
		putimage(x,y,&white_chess,SRCPAINT);
		for(i=0;i<15*15+1;i+=2)//没有的话就要存储起来这个位置
		{
			if(white_occupied[i]==1)
			{
				white_occupied[i]=x;
				white_occupied[i+1]=y;
				break;
			}
		}
		if(win(condition,x,y))
		{
			return true;
		}
		condition=_black;
		break;
	}
	return false;
}
bool CHESS::win(const Condition t,short x,short y)
{
	int i,n=1,num=1;//num标记几个棋子相连,n标记判断向某个方向第几个的坐标是否存在
	int con=1;//标记是否继续搜索

	switch(t)
	{
	case _white:
		t_occupied=white_occupied;
		break;
	case _black:
		t_occupied=black_occupied;
		break;
	default:
		break;
	}
	//=============================================================
	//横向搜索
	while(con)//向左搜索
	{
		for(i=0;i<15*15+1;i+=2)
		{
			if(t_occupied[i]==x-n*distance && t_occupied[i+1]==y)
			{
				num++;
				n++;
				con=1;
				break;
			}
			else
			{
				con=0;
			}
		}
	}
	con=1;//继续搜索
	n=1;//为接下来搜索提供条件正确
	while(con)//向右
	{
		for(i=0;i<15*15+1;i+=2)
		{
			if(t_occupied[i]==x+n*distance && t_occupied[i+1]==y)
			{
				num++;
				n++;
				con=1;
				break;
			}
			else
			{
				con=0;
			}
		}
	}
	if(5<=num)//判断是否胜利
	{
		switch(t)
		{
		case _white:
			putimage(159,50,&white_win,SRCAND);
			break;
		case _black:
			putimage(159,50,&black_win,SRCAND);
			break;
		default:
			break;
		}
		return true;
	}
	num=1;
	con=1;
	n=1;
	//=============================================================
	//纵向搜索
	while(con)//向上搜索
	{
		for(i=0;i<15*15+1;i+=2)
		{
			if(t_occupied[i]==x && t_occupied[i+1]==y-n*distance)
			{
				num++;
				n++;
				con=1;
				break;
			}
			else
			{
				con=0;
			}
		}
	}
	con=1;//继续搜索
	n=1;//为接下来搜索提供条件正确
	while(con)//向下搜索
	{
		for(i=0;i<15*15+1;i+=2)
		{
			if(t_occupied[i]==x && t_occupied[i+1]==y+n*distance)
			{
				num++;
				n++;
				con=1;
				break;
			}
			else
			{
				con=0;
			}
		}
	}
	if(5<=num)//判断是否胜利
	{
		switch(t)
		{
		case _white:
			putimage(159,50,&white_win,SRCAND);
			break;
		case _black:
			putimage(159,50,&black_win,SRCAND);
			break;
		default:
			break;
		}
		return true;
	}
	num=1;
	con=1;
	n=1;
	//=============================================================
	//左上角到右下角搜索
	while(con)//向左上搜索
	{
		for(i=0;i<15*15+1;i+=2)
		{
			if(t_occupied[i]==x-n*distance && t_occupied[i+1]==y-n*distance)
			{
				num++;
				n++;
				con=1;
				break;
			}
			else
			{
				con=0;
			}
		}
	}
	con=1;//继续搜索
	n=1;//为接下来搜索提供条件正确
	while(con)//向右下搜索
	{
		for(i=0;i<15*15+1;i+=2)
		{
			if(t_occupied[i]==x+n*distance && t_occupied[i+1]==y+n*distance)
			{
				num++;
				n++;
				con=1;
				break;
			}
			else
			{
				con=0;
			}
		}
	}
	if(5<=num)//判断是否胜利
	{
		switch(t)
		{
		case _white:
			putimage(159,50,&white_win,SRCAND);
			break;
		case _black:
			putimage(159,50,&black_win,SRCAND);
			break;
		default:
			break;
		}
		return true;
	}
	num=1;
	con=1;
	n=1;
	//=============================================================
	//左下角到右上角搜索
	while(con)//向左下搜索
	{
		for(i=0;i<15*15+1;i+=2)
		{
			if(t_occupied[i]==x-n*distance && t_occupied[i+1]==y+n*distance)
			{
				num++;
				n++;
				con=1;
				break;
			}
			else
			{
				con=0;
			}
		}
	}
	con=1;//继续搜索
	n=1;//为接下来搜索提供条件正确
	while(con)//向右上搜索
	{
		for(i=0;i<15*15+1;i+=2)
		{
			if(t_occupied[i]==x+n*distance && t_occupied[i+1]==y-n*distance)
			{
				num++;
				n++;
				con=1;
				break;
			}
			else
			{
				con=0;
			}
		}
	}
	if(5<=num)//判断是否胜利
	{
		switch(t)
		{
		case _white:
			putimage(159,50,&white_win,SRCAND);
			break;
		case _black:
			putimage(159,50,&black_win,SRCAND);
			break;
		default:
			break;
		}
		return true;
	}
	
	return false;
}