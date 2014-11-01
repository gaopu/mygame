#include"chess.h"
#include<graphics.h>

CHESS::CHESS()
{
	initgraph(534,530);
	loadimage(&chessboard,_T("chessboard.jpg"));
	loadimage(&white_win,_T("white_win.jpg"));
	loadimage(&black_win,_T("black_win.jpg"));
	loadimage(&white_chess,_T("white.jpg"));
	loadimage(&black_chess,_T("black.jpg"));//�������̣��ڰ����ӵ�ͼƬ,��ͼ
	condition=_black;
	int i;
	for(i=0;i<2*15*15;i++)
	{
		occupied[i]=1;//ȫ����ֵΪ1������ֵΪ0����Ϊ���ܴ洢����(0,0)
	}
	for(i=0;i<15*15+1;i++)
	{
		white_occupied[i]=1;
		black_occupied[i]=1;
	}
	putimage(0,0,&chessboard);//�滭����
	setorigin(chess_origin_x,chess_origin_y);//��������ԭ�㵽��һ�����ӻ��Ƶ�λ��

}
bool CHESS::paint(short x,short y)
{
	x=x/distance*distance;
	y=y/distance*distance;//���ڱ���ͼ����,���Բ����ܻ滭����������ȷ�ĵط������Կ��Բ��ж��Ƿ�滭����"���"��
	int i;
	for(i=0;i<2*15*15;i+=2)//���ж��Ƿ��ڴ�λ�����������
	{
		if(occupied[i]!=1)
		{
			if(occupied[i]==x && occupied[i+1]==y)
			{
				return false;
			}
		}
	}
	for(i=0;i<2*15*15;i+=2)//�ȴ洢�ڹ�����������
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
		for(i=0;i<15*15+1;i+=2)//û�еĻ���Ҫ�洢�������λ��
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
		for(i=0;i<15*15+1;i+=2)//û�еĻ���Ҫ�洢�������λ��
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
	int i,n=1,num=1;//num��Ǽ�����������,n����ж���ĳ������ڼ����������Ƿ����
	int con=1;//����Ƿ��������

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
	//��������
	while(con)//��������
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
	con=1;//��������
	n=1;//Ϊ�����������ṩ������ȷ
	while(con)//����
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
	if(5<=num)//�ж��Ƿ�ʤ��
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
	//��������
	while(con)//��������
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
	con=1;//��������
	n=1;//Ϊ�����������ṩ������ȷ
	while(con)//��������
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
	if(5<=num)//�ж��Ƿ�ʤ��
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
	//���Ͻǵ����½�����
	while(con)//����������
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
	con=1;//��������
	n=1;//Ϊ�����������ṩ������ȷ
	while(con)//����������
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
	if(5<=num)//�ж��Ƿ�ʤ��
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
	//���½ǵ����Ͻ�����
	while(con)//����������
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
	con=1;//��������
	n=1;//Ϊ�����������ṩ������ȷ
	while(con)//����������
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
	if(5<=num)//�ж��Ƿ�ʤ��
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