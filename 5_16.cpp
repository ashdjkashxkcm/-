#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include"5_16_Point.h"
#include"5_16_Circle.h"

////如果我们自己传入数据，就用传入的数据，如果没有就用默认值
//int test01(int a, int b = 20, int c = 30)
//{
//	return a + b + c;
//}
////注意事项
////1.如果某个位置已经有了默认参数，那么从这个位置往后，从左到右都必须要有默认值
////2.如果函数的声明有了默认参数，函数的实现就不能有默认参数    声明和实现只能有一个默认参数
//
//int main()
//{	
//	cout << test01(10, 30, 30) << endl;
//
//
//
//	system("pause");
//	return 0;
//}

//学生类
//class Student
//{
//	//访问权限
//public:
//	//姓名
//	char name[10];
//	//学号
//	char id[10];
//};


////学生类
//class Student
//{
//	//访问权限
//public:
//	//姓名
//	string name;
//	//学号
//	string id;
//
//	//设置姓名和ID
//	void Set_name_id(string Name, string Id)
//	{
//		name = Name;
//		id = Id;
//	}
//
//
//	//显示姓名和学号
//	void Show()
//	{
//		cout << "姓名:" << name << endl;
//		cout << "学号:" << id << endl;
//	}
//};
//
//int main()
//{	
//	Student s1;
//	/*strcpy(s1.name, "张三");
//	strcpy(s1.id, "007");*/
//
//	//s1.name = "zhangsan";
//	//s1.id = "007";
//	s1.Set_name_id("zhangsan", "001");
//
//	s1.Show();
//	
//	system("pause");
//	return 0;
//}


////学生类
//class Student
//{
//public:
//	//读取姓名
//	string getName()
//	{
//		m_Name = "zhangsan";
//		return m_Name;
//	}
//	//改写年龄
//	void getAge(int age)
//	{
//		m_age = age;
//	}
//
//	//读取年龄
//	int ShowAge()
//	{
//		return m_age;
//	}
//
//	//改写情人
//	void getLover(string lover)
//	{
//		Lover = lover;
//	}
//
//
//private:
//	// 姓名  只读
//	string m_Name;
//	//年龄  可读可写
//	int m_age;
//
//	//情人  只写
//	string Lover;
//};
//
//int main()
//{
//
//
//
//	system("pause");
//	return 0;
//}

////立方体类
//class Cube
//{
//public:
//	//设置长、宽、高
//	void setLWH(int l,int w,int h)
//	{
//		m_L = l;
//		m_W = w;
//		m_H = h;
//	}
//	//获取长
//	int getL()
//	{
//		return m_L;
//	}
//	//获取宽
//	int getW()
//	{
//		return m_W;
//	}
//	//获取高
//	int getH()
//	{
//		return m_H;
//	}
//
//	//判度两个立方体是否相等
//	bool cube1(Cube& c)
//	{
//		if (m_L == c.m_L && m_W == c.m_W && m_H == c.m_H)
//		{
//			return true;
//		}
//		return false;
//	}
//
//	//计算立方体的面积
//	int CubeS()
//	{
//		return 2 * m_L * m_W + 2 * m_L * m_H + 2 * m_W * m_H;
//	}
//	//计算立方体的体积
//	int CubeV()
//	{
//		return m_L * m_H * m_W;
//	}
//
//private:
//	//设置长
//	int m_L;
//	//设置宽
//	int m_W;
//	//设置高
//	int m_H;
//
//};
//
//bool Cube1(Cube& c1, Cube& c2)
//{
//	if (c1.getL() == c2.getL() && c1.getW() == c2.getW() && c1.getH() == c2.getH())
//	{
//		return true;
//	}
//	return false;
//}
//
//
//int main()
//{
//	Cube c1;
//	c1.setLWH(10, 10, 10);
//	cout << "c1的面积:" << c1.CubeS() << endl;
//	cout << "c1的体积:" << c1.CubeV() << endl;
//
//	Cube c2;
//	c2.setLWH(10, 20, 10);
//	cout << "c2的面积:" << c2.CubeS() << endl;
//	cout << "c2的体积:" << c2.CubeV() << endl;
//
//	//判度两个立方体是否相等
//	//bool ret = Cube1(c1, c2);
//	bool ret = c1.cube1(c2);
//	if (ret)
//	{
//		cout << "c1和c2是相等的" << endl;
//	}
//	else
//	{
//		cout << "c1和c2是不相等的" << endl;
//	}
//
//	system("pause");
//	return 0;
//}

////坐标类
//class Point
//{
//public:
//	//设置坐标
//	void setXY(int x, int y)
//	{
//		m_X = x;
//		m_Y = y;
//	}
//	//获取横坐标
//	int getX()
//	{
//		return m_X;
//	}
//	//获取纵坐标
//	int getY()
//	{
//		return m_Y;
//	}
//
//private:
//	//横坐标
//	int m_X;
//	//纵坐标
//	int m_Y;
//};

////圆类
//class Circle
//{	
//public:
//	//设置半径
//	void setR(int r)
//	{
//		m_R = r;
//	}
//	//获取半径
//	int getR()
//	{
//		return m_R;
//	}
//	//设置圆心
//	void setCenter(Point c)
//	{
//		m_Center = c;
//	}
//	//获取圆心
//	Point getCenter()
//	{
//		return m_Center;
//	}
//
//private:
//	//半径
//	int m_R;
//	//圆心
//	Point m_Center;
//};

//判度点与圆的关系
void isInCircle(Circle& c,Point p)
{
	//点到圆心距离的平方
	int Rdistance = (c.getCenter().getX() - p.getX()) ^ 2 + (c.getCenter().getY() - p.getY() ^ 2);
	//半径的平方
	int Cdistance = c.getR() * c.getR();

	//判度
	if (Rdistance == Cdistance)
	{
		cout << "点在圆上" << endl;
	}
	else if (Rdistance > Cdistance)
	{
		cout << "点在圆外" << endl;
	}
	else
	{
		cout << " 点在圆内" << endl;
	}
}

//int main()
//{	
//	Circle c1;
//	//设置半径
//	c1.setR(10);
//	//设置圆心
//	Point center;
//	center.setXY(10, 0);
//	c1.setCenter(center);
//
//	//点
//	Point P;
//	P.setXY(10, 10);
//
//	isInCircle(c1, P);
//	system("pause");
//	return 0;
//}

class Person
{	
public:
	//构造函数
	//1.没有返回值，不用写void
	//函数名 与 类名相同
	//构造函数可以有参数
	//创建对象的时候，构造函数会自动调用，而且只调一次
	Person()
	{
		cout << "构造函数的调用" << endl;
	}

	//析构函数 进行清理操作
	//没有返回值 不用写void
	//函数名与类名相同 在名称前加~
	//析构函数不可以有参数，不可以发生重载
	//对象在销毁前会自动调用析构函数且只调用一次
	~Person()
	{
		cout << "析构函数的调用" << endl;
	}
};


//构造和析构都是必须有的实现，如果我们自己不提供，编译器会提供一个空构造和空析构
void test01()
{
	Person DD; //对象创建在栈区，test01在执行完毕后，释放这个对象
}

int main()
{	
	test01();

	Person P;

	system("pause");
	return 0;
}