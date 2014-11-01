#include<graphics.h>
#ifndef CHESS_H_
#define CHESS_H_

class CHESS
{
public:
	enum Condition{_black,_white};//该出什么颜色的棋子的标记(常量记号)
	CHESS();//初始化
	bool paint(short x,short y);//(x,y)绘画棋子,并且判断是否该一方胜出
private:
	IMAGE chessboard;
	IMAGE black_chess;
	IMAGE white_chess;
	IMAGE white_win;
	IMAGE black_win;
	Condition condition;//标记该出什么颜色的棋了的变量
	short occupied[2*15*15];//存储被占用了的坐标位置
	short white_occupied[15*15+1];//存储白色占用的坐标(与上面有重复，但感觉这样更好)
	short black_occupied[15*15+1];//存储黑色占用的坐标(x与y的值总数是偶数个)
	short *t_occupied;//判断胜负时需要把某个颜色的占用信息复制进来
	static const short chess_origin_x=3;
	static const short chess_origin_y=2;
	static const short distance=36;//设置棋盘两个棋点之间的像素点

	bool win(const Condition t,short x,short y);//判断(x,y)放置t棋是否胜利的具体实现
};

#endif