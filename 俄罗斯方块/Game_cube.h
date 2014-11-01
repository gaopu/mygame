#ifndef GAME_CUBE_
#define GAME_CUBE_
//================================================================
const short cube_xy=1000;//���ɴ洢�ı�ռ������(x��y��ֵ),���ݳ��ش�С���任,��֤����ȫ���洢�¼���
//================================================================
//��Ϸ������
class Area
{
public:
	short area_x,area_y;//���ص����ұߵ�x��������±ߵ�y����
	short occupied[cube_xy];//��ռ�õ����������
	Area();
	void paint()const;//�滭������
	friend void Gameover(Area &t);
};
//================================================================
//��Ϸ������
class Cube
{
private:
	enum type_{o,o2,l1,l2,l3,l4,t1,t2,t3,t4,j1,j2,j3,j4,z1,z2,s1,s2,i1,i2};//���O��ֻ��һ�������ֳ��ִ���̫�٣�����Ū������ӦO��
	short cube[4][4];//�洢�������״
	enum Color{red,green,yellow,pink_intensity,cyan,red_intensity,green_intensity};//�洢��ɫ
	Color color;//��Ƿ�����ɫ
	type_ type;//����ķ�������
	short first_x,first_y;//ÿ�ַ���洢��4*4�ľ����У������Ǹ����ϽǷ��������
	short up_y,left_x,right_x,down_y;//������ķ����y�����Լ���������
	short last_xy[8];//��ס��һ�εķ���λ�ã����ڷ����½�ʱ������һ���ĺۼ�(�����������ֻ��paint()������)
	//---------------------------------------------------------------
	void paint();//�滭������
	void change_type(type_ t);//�ı�����
	void copy(type_ m);//����ȷ�ķ�����ת���Ƶ�cube[4][4]��
	void newoccupied(Area &t,short y=0);//ˢ��ռ�õ�����,���Ҫ���ĳ�У���Ҫ�ú���Ĳ����������е�y����
	void clear();//�����һ��λ�õķ���
	bool stop(Area &t);//�жϷ����½��Ƿ���Ӧ��ֹͣ��,������һ�����ض���
public:
	Cube();//�����������,��ʼ�����ֲ���(��Ҫ�ⲿ��srand()�ṩ����ֵ)
	void up(const Area &t);
	bool down(Area &t);//�����½��ͷ���true
	void left(const Area &t);
	void right(const Area &t);//�����ĸ����ĸ����Ĺ��ܽӿ�
	bool drop(Area &t);//������Զ�����
	short clear(Area &t);//�����������еķ��飬�����ǡ��ж��Ƿ������У����У����֮�����ҷ�������˼��С�
	void end(Area &t);//����ֱ�ӵ��������
	bool over(const Area &t);//�ж���Ϸ�Ƿ����
	void paint_next(const Area &t);//���Ƴ���һ������
};
//================================================================
#endif