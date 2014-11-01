#ifndef GAME_CUBE_
#define GAME_CUBE_
//================================================================
const short cube_xy=1000;//最多可存储的被占用坐标(x和y的值),根据场地大小灵活变换,保证可以全部存储下即可
//================================================================
//游戏场地类
class Area
{
public:
	short area_x,area_y;//场地的最右边的x坐标和最下边的y坐标
	short occupied[cube_xy];//被占用的区域的坐标
	Area();
	void paint()const;//绘画出场地
	friend void Gameover(Area &t);
};
//================================================================
//游戏方块类
class Cube
{
private:
	enum type_{o,o2,l1,l2,l3,l4,t1,t2,t3,t4,j1,j2,j3,j4,z1,z2,s1,s2,i1,i2};//如果O型只有一个，发现出现次数太少，所以弄两个对应O型
	short cube[4][4];//存储方块的形状
	enum Color{red,green,yellow,pink_intensity,cyan,red_intensity,green_intensity};//存储颜色
	Color color;//标记方块颜色
	type_ type;//具体的方块类型
	short first_x,first_y;//每种方块存储在4*4的矩形中，这是那个左上角方块的坐标
	short up_y,left_x,right_x,down_y;//最上面的方块的y坐标以及其他三个
	short last_xy[8];//记住上一次的方块位置，便于方块下降时擦除上一处的痕迹(更新这个数据只在paint()函数中)
	//---------------------------------------------------------------
	void paint();//绘画出方块
	void change_type(type_ t);//改变类型
	void copy(type_ m);//把正确的方块形转复制到cube[4][4]中
	void newoccupied(Area &t,short y=0);//刷新占用的坐标,如果要清除某行，就要用后面的参数，代表行的y坐标
	void clear();//清除上一个位置的方块
	bool stop(Area &t);//判断方块下降是否是应该停止了,参数是一个场地对象
public:
	Cube();//产生随机方块,初始化各种参数(需要外部用srand()提供种子值)
	void up(const Area &t);
	bool down(Area &t);//可以下降就返回true
	void left(const Area &t);
	void right(const Area &t);//以上四个是四个键的功能接口
	bool drop(Area &t);//方块会自动下落
	short clear(Area &t);//这个是清除满行的方块，功能是“判断是否有满行，若有，清除之，并且返回清除了几行”
	void end(Area &t);//方块直接掉到最底下
	bool over(const Area &t);//判断游戏是否结束
	void paint_next(const Area &t);//绘制出下一个方块
};
//================================================================
#endif