#include<graphics.h>
#ifndef CHESS_H_
#define CHESS_H_

class CHESS
{
public:
	enum Condition{_black,_white};//�ó�ʲô��ɫ�����ӵı��(�����Ǻ�)
	CHESS();//��ʼ��
	bool paint(short x,short y);//(x,y)�滭����,�����ж��Ƿ��һ��ʤ��
private:
	IMAGE chessboard;
	IMAGE black_chess;
	IMAGE white_chess;
	IMAGE white_win;
	IMAGE black_win;
	Condition condition;//��Ǹó�ʲô��ɫ�����˵ı���
	short occupied[2*15*15];//�洢��ռ���˵�����λ��
	short white_occupied[15*15+1];//�洢��ɫռ�õ�����(���������ظ������о���������)
	short black_occupied[15*15+1];//�洢��ɫռ�õ�����(x��y��ֵ������ż����)
	short *t_occupied;//�ж�ʤ��ʱ��Ҫ��ĳ����ɫ��ռ����Ϣ���ƽ���
	static const short chess_origin_x=3;
	static const short chess_origin_y=2;
	static const short distance=36;//���������������֮������ص�

	bool win(const Condition t,short x,short y);//�ж�(x,y)����t���Ƿ�ʤ���ľ���ʵ��
};

#endif