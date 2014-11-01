#include<iostream>
#include<windows.h>
#include"Game_cube.h"
#include<cstdlib>
#include<ctime>
using std::cout;
using std::cin;
using std::endl;
//================================================================
//�����ⲿ����ķ�����״����
extern short o_[4][4];
extern short j_[4][4][4];
extern short t_[4][4][4];
extern short l_[4][4][4];
extern short z_[2][4][4];
extern short s_[2][4][4];
extern short i_[2][4][4];
//================================================================
void gotoxy(short x,short y);
//================================================================
//Area���ʵ��
Area::Area()
{
	short length=15,height=22;//��Ϸ����ʵ�ʵĴ�С,�ɵ���
	int i;
	for(i=0;i<cube_xy;i++)
	{
		occupied[i]=0;
	}//��ʼ������
	area_x = length * 2 + 2;
	area_y = height + 1;
}
void Area::paint()const
{
	int i;
	for(i=0;i<=area_x;i+=2)
	{
		gotoxy(i,0);cout<<"��";
		gotoxy(i,area_y);cout<<"��";
	}
	for(i=1;i<area_y;i++)
	{
		gotoxy(0,i);cout<<"��";
		gotoxy(area_x,i);cout<<"��";
	}
	for(i=area_x+2;i<=52;i+=2)
	{
		gotoxy(i,0);cout<<"��";
		gotoxy(i,6);cout<<"��";
		gotoxy(i,12);cout<<"��";
		gotoxy(i,13);cout<<"��";
		gotoxy(i,18);cout<<"��";
		gotoxy(i,19);cout<<"��";
		gotoxy(i,23);cout<<"��";
	}
	gotoxy(area_x+8,0);cout<<"��˵����";
	gotoxy(area_x+8,1);cout<<"�س���ͣ";
	gotoxy(area_x+6,2);cout<<"���������ƶ�";
	gotoxy(area_x+8,3);cout<<"������";
	gotoxy(area_x+7,4);cout<<"���任��״";
	gotoxy(area_x+3,5);cout<<"�ո��ƶ����鵽�ײ�";
	gotoxy(area_x+6,8);cout<<"����:";
	gotoxy(area_x+6,10);cout<<"�ȼ�:";
	gotoxy(area_x+6,13);cout<<"����һ��ͼ��";
	gotoxy(area_x+8,19);cout<<"�����ߡ�";
	gotoxy(area_x+6,21);cout<<"348538085Ⱥ��";
}
//================================================================
//Cube���ʵ��
Cube::Cube()
{
	type=(type_)(rand()%20);
	switch(type)
	{
	case o:
	case o2:	change_type(o);		color=red_intensity;	break;
	case l1:	change_type(l1);	color=green;			break;
	case l2:	change_type(l2);	color=green;			break;
	case l3:	change_type(l3);	color=green;			break;
	case l4:	change_type(l4);	color=green;			break;
	case t1:	change_type(t1);	color=yellow;			break;
	case t2:	change_type(t2);	color=yellow;			break;
	case t3:	change_type(t3);	color=yellow;			break;
	case t4:	change_type(t4);	color=yellow;			break;
	case j1:	change_type(j1);	color=green_intensity;	break;
	case j2:	change_type(j2);	color=green_intensity;	break;
	case j3:	change_type(j3);	color=green_intensity;	break;
	case j4:	change_type(j4);	color=green_intensity;	break;
	case z1:	change_type(z1);	color=red;				break;
	case z2:	change_type(z2);	color=red;				break;
	case s1:	change_type(s1);	color=pink_intensity;	break;
	case s2:	change_type(s2);	color=pink_intensity;	break;
	case i1:	change_type(i1);	color=cyan;				break;
	case i2:	change_type(i2);	color=cyan;				break;
	}
	first_x=12;//����ż��������ʹ�������
	first_y=1;
	paint();//������þ��������˶����������ʾ�������ҳ�ʼ����last_xy
}
void Cube::copy(type_ m)
{
	int i,j;
	switch(m)
	{
	case  o:for(i=0;i<4;i++)
			{
				for(j=0;j<4;j++)
					cube[i][j]=o_[i][j];
			}
		break;
	case l1:for(i=0;i<4;i++)
			{
				for(j=0;j<4;j++)
					cube[i][j]=l_[0][i][j];
			}	
		break;
	case l2:for(i=0;i<4;i++)
			{
				for(j=0;j<4;j++)
					cube[i][j]=l_[1][i][j];
			}	
		break;
	case l3:for(i=0;i<4;i++)
			{
				for(j=0;j<4;j++)
					cube[i][j]=l_[2][i][j];
			}	
		break;
	case l4:for(i=0;i<4;i++)
			{
				for(j=0;j<4;j++)
					cube[i][j]=l_[3][i][j];
			}	
		break;
	case t1:for(i=0;i<4;i++)
			{
				for(j=0;j<4;j++)
					cube[i][j]=t_[0][i][j];
			}	
		break;
	case t2:for(i=0;i<4;i++)
			{
				for(j=0;j<4;j++)
					cube[i][j]=t_[1][i][j];
			}	
		break;
	case t3:for(i=0;i<4;i++)
			{
				for(j=0;j<4;j++)
					cube[i][j]=t_[2][i][j];
			}	
		break;
	case t4:for(i=0;i<4;i++)
			{
				for(j=0;j<4;j++)
					cube[i][j]=t_[3][i][j];
			}	
		break;
	case j1:for(i=0;i<4;i++)
			{
				for(j=0;j<4;j++)
					cube[i][j]=j_[0][i][j];
			}	
		break;
	case j2:for(i=0;i<4;i++)
			{
				for(j=0;j<4;j++)
					cube[i][j]=j_[1][i][j];
			}	
		break;
	case j3:for(i=0;i<4;i++)
			{
				for(j=0;j<4;j++)
					cube[i][j]=j_[2][i][j];
			}	
		break;
	case j4:for(i=0;i<4;i++)
			{
				for(j=0;j<4;j++)
					cube[i][j]=j_[3][i][j];
			}	
		break;
	case z1:for(i=0;i<4;i++)
			{
				for(j=0;j<4;j++)
					cube[i][j]=z_[0][i][j];
			}	
		break;
	case z2:for(i=0;i<4;i++)
			{
				for(j=0;j<4;j++)
					cube[i][j]=z_[1][i][j];
			}	
		break;
	case s1:for(i=0;i<4;i++)
			{
				for(j=0;j<4;j++)
					cube[i][j]=s_[0][i][j];
			}	
		break;
	case s2:for(i=0;i<4;i++)
			{
				for(j=0;j<4;j++)
					cube[i][j]=s_[1][i][j];
			}	
		break;
	case i1:for(i=0;i<4;i++)
			{
				for(j=0;j<4;j++)
					cube[i][j]=i_[0][i][j];
			}	
		break;
	case i2:for(i=0;i<4;i++)
			{
				for(j=0;j<4;j++)
					cube[i][j]=i_[1][i][j];
			}	
		break;
	}
}
void Cube::paint()
{
	int i,j,k=0,m=0;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			if(cube[i][j])
			{
				m++;
				switch(color)
				{
					case green:				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN);										break;
					case red:				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED);										break;
					case yellow:			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN|FOREGROUND_RED);						break;
					case red_intensity:		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_INTENSITY);					break;
					case green_intensity:	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN|FOREGROUND_INTENSITY);					break;
					case cyan:				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN|FOREGROUND_BLUE);						break;
					case pink_intensity:	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);	break;
				}
				gotoxy(first_x+j*2,first_y+i);
				cout<<"��";
				last_xy[k++]=first_x+j*2;
				last_xy[k++]=first_y+i;
				if(1==m)
				{
					up_y=first_y+i;
					left_x=first_x+j*2;
					right_x=first_x+j*2;
				}
				if(4==m)
				{
					down_y=first_y+i;
				}
				left_x =left_x <= first_x+j*2 ? left_x : first_x+j*2;
				right_x=right_x >= first_x+j*2 ? right_x : first_x+j*2;
			}
		}
	}
}
bool Cube::drop(Area &t)//����ǰ�ж��Ƿ�������䣬���Ծͷ���true,��֮����false
{
	clear();
	if(stop(t))
	{
		paint();
		return false;
	}
	else
	{
		first_y++;//���½�һ��
		paint();
		return true;
	}
}
bool Cube::stop(Area &t)
{
	if(down_y==t.area_y-1)
	{
		newoccupied(t);//�������ֹͣ�˾�Ҫ�ѡ����λ�ñ�ռ������Ϣ�洢����
		return true;
	}//�ж��Ƿ��˳��صײ�
	int i,j;
	for(i=0;i<8;i+=2)
	{
		for(j=0;j<cube_xy;j+=2)
		{
			if(last_xy[i]==t.occupied[j] && last_xy[i+1]==t.occupied[j+1]-1)
			{
				newoccupied(t);
				return true;
			}
		}
	}//�ж��Ƿ������Ѿ����˷���
	return false;
}
void Cube::newoccupied(Area &t,short y)
{
	if(y)//����������Ҫ�����ĳһ�е�ռ��
	{
		short i;
		for(i=1;i<cube_xy;i+=2)
		{
			if(t.occupied[i]==y)//��ɾ����һ�еļ�¼
			{
				t.occupied[i]=t.occupied[i-1]=0;
			}
			if(t.occupied[i]<y && t.occupied[i])//�ٰ�����ķ�����ͳһ�����ƶ�һ��
			{
				t.occupied[i]++;
			}
		}
	}
	else//�������Ҫ�����µ�ռ����Ϣ	ע��:��Ҫ�ж���ǰ�Ƿ�洢��ͬ������Ϣ
	{
		short i,j;
		for(i=0;i<8;i+=2)
		{
			for(j=0;j<cube_xy;j+=2)
			{
				if(last_xy[i]==t.occupied[j] && last_xy[i+1]==t.occupied[j+1])//��ǰ�Ƿ�洢��ͬ������Ϣ
				{
					return;
				}
			}
		}
		short k=0;
		for(i=0;i<cube_xy;i+=2)
		{
			if(!t.occupied[i] && !t.occupied[i+1])
			{
				t.occupied[i]=last_xy[k++];
				t.occupied[i+1]=last_xy[k++];
			}
			if(k==8)
			{
				break;
			}
		}
	}
}
void Cube::up(const Area &t)
{
	type_ n;
	n=type;
	clear();
	switch(type)
	{
	case  o:						break;
	case l1:	change_type(l2);	break;
	case l2:	change_type(l3);	break;
	case l3:	change_type(l4);	break;
	case l4:	change_type(l1);	break;
	case t1:	change_type(t2);	break;
	case t2:	change_type(t3);	break;
	case t3:	change_type(t4);	break;
	case t4:	change_type(t1);	break;
	case j1:	change_type(j2);	break;
	case j2:	change_type(j3);	break;
	case j3:	change_type(j4);	break;
	case j4:	change_type(j1);	break;
	case z1:	change_type(z2);	break;
	case z2:	change_type(z1);	break;
	case s1:	change_type(s2);	break;
	case s2:	change_type(s1);	break;
	case i1:	change_type(i2);	break;
	case i2:	change_type(i1);	break;
	}
	short i,j,k=0,m=0;
	for(i=0;i<4;i++)//�任��״��ı䷽��ġ����ϡ��������ҡ����¡�����
	{
		for(j=0;j<4;j++)
		{
			if(cube[i][j])
			{
				m++;
				if(1==m)
				{
					up_y=first_y+i;
					left_x=first_x+j*2;
					right_x=first_x+j*2;
				}
				if(4==m)
				{
					down_y=first_y+i;
				}
				left_x =left_x <= first_x+j*2 ? left_x : first_x+j*2;
				right_x=right_x >= first_x+j*2 ? right_x : first_x+j*2;
			}
		}
	}
	if(up_y<1 || left_x<2 || right_x>=t.area_x || down_y>=t.area_y)
	{
		change_type(n);
		paint();
		return;
	}//�ж���ת���Ƿ���ǽ��ס
	for(i=0;i<8;i+=2)
	{
		for(j=0;j<cube_xy;j+=2)
		{
			if(last_xy[i]==t.occupied[j] && last_xy[i+1]==t.occupied[j+1])
			{
				change_type(n);
				paint();
				return;
			}
		}
	}//�ж���ת���Ƿ�����ǰ�ķ����ص�
	paint();
}
bool Cube::down(Area &t)
{
	if(!stop(t))
	{
		clear();
		first_y++;
		paint();
		return true;
	}
	return false;
}
void Cube::left(const Area &t)
{
	if(2==left_x)
	{
		return;
	}
	short i,j;
	for(i=0;i<8;i+=2)
	{
		for(j=0;j<cube_xy;j+=2)
		{
			if(last_xy[i]-2==t.occupied[j] && last_xy[i+1]==t.occupied[j+1])
			{
				return;
			}
		}
	}//�ж�����Ƿ���ռ��
	clear();
	first_x-=2;
	paint();
}
void Cube::right(const Area &t)
{
	if(right_x==t.area_x-2)
	{
		return;
	}
	short i,j;
	for(i=0;i<8;i+=2)
	{
		for(j=0;j<cube_xy;j+=2)
		{
			if(last_xy[i]+2==t.occupied[j] && last_xy[i+1]==t.occupied[j+1])
			{
				return;
			}
		}
	}//�ж��ұ��Ƿ���ռ��
	clear();
	first_x+=2;
	paint();
}
void Cube::clear()
{
	int i;
	for(i=0;i<8;i+=2)
	{
		gotoxy(last_xy[i],last_xy[i+1]);
		cout<<" ";
	}
}
short Cube::clear(Area &t)
{
	short i,j,sum=0,compare,lines=0;
	for(i=2;i<t.area_x;i+=2)
		sum+=i;//����ͬһ�е�����x������
	for(i=1;i<cube_xy;i+=2)
	{
		if(t.occupied[i])//y���겻��0��֤�������˷���λ�õ���Ϣ(�ж�xҲ����)
		{
			compare=0;
			short y=t.occupied[i];
			for(j=1;j<cube_xy;j+=2)
			{
				if(t.occupied[j]==y)
				{
					compare+=t.occupied[j-1];
				}
			}
			if(compare==sum)//��Ⱦ�˵����һ������
			{
				lines++;
				short k;
				for(k=1;k<cube_xy;k+=2)//ɾ����һ���Լ�����ķ���
				{
					if(t.occupied[k]<=y && t.occupied[k])
					{
						gotoxy(t.occupied[k-1],t.occupied[k]);
						cout<<" ";
					}
				}
				newoccupied(t,y);//����ռ��
				for(k=1;k<cube_xy;k+=2)//������ķ������»���
				{
					if(t.occupied[k]<=y && t.occupied[k])
					{
						gotoxy(t.occupied[k-1],t.occupied[k]);
						cout<<"��";
					}
				}
			}
		}
	}
	return lines;
}
void Cube::change_type(type_ t)
{
	//�ı���������������:�ı������͵ı���������Ӧ����״���ƽ�ȥ�������������ӵ�ÿ��С���������
	type=t;
	copy(t);
	short i,j,k=0;
	for(i=0;i<4;i++)//�����������ӵ�ÿ��С���������
	{
		for(j=0;j<4;j++)
		{
			if(cube[i][j])
			{
				last_xy[k++]=first_x+j*2;
				last_xy[k++]=first_y+i;
			}
		}
	}
}
void Cube::end(Area &t)
{
	clear();
	while(!stop(t))
	{
		first_y++;
		paint();
		clear();
	}
	paint();
}
bool Cube::over(const Area &t)
{
	short y;
	for(y=1;y<cube_xy;y+=2)
	{
		if(t.occupied[y]<=4 && t.occupied[y])
			return true;
	}
	return false;
}
void Cube::paint_next(const Area &t)
{
	first_x=t.area_x+8;
	first_y=14;
	short i,j;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			gotoxy(first_x+2*j,first_y+i);cout<<"  ";
		}
	}
	paint();
	first_x=12;
	first_y=1;//���ǵ������ʼ�㣬�������ȥ
	paint();
	clear();//������������Ϊpaint()���·����ÿ��λ�ã����Ծ�����д�ˡ��������ͺ��ҽ�����
	//����2�ŷ���ʱ�����������滭�����ˣ������������clear()���Ǹ������
}