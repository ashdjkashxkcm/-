#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include"5_16_Point.h"
#include"5_16_Circle.h"

////��������Լ��������ݣ����ô�������ݣ����û�о���Ĭ��ֵ
//int test01(int a, int b = 20, int c = 30)
//{
//	return a + b + c;
//}
////ע������
////1.���ĳ��λ���Ѿ�����Ĭ�ϲ�������ô�����λ�����󣬴����Ҷ�����Ҫ��Ĭ��ֵ
////2.�����������������Ĭ�ϲ�����������ʵ�־Ͳ�����Ĭ�ϲ���    ������ʵ��ֻ����һ��Ĭ�ϲ���
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

//ѧ����
//class Student
//{
//	//����Ȩ��
//public:
//	//����
//	char name[10];
//	//ѧ��
//	char id[10];
//};


////ѧ����
//class Student
//{
//	//����Ȩ��
//public:
//	//����
//	string name;
//	//ѧ��
//	string id;
//
//	//����������ID
//	void Set_name_id(string Name, string Id)
//	{
//		name = Name;
//		id = Id;
//	}
//
//
//	//��ʾ������ѧ��
//	void Show()
//	{
//		cout << "����:" << name << endl;
//		cout << "ѧ��:" << id << endl;
//	}
//};
//
//int main()
//{	
//	Student s1;
//	/*strcpy(s1.name, "����");
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


////ѧ����
//class Student
//{
//public:
//	//��ȡ����
//	string getName()
//	{
//		m_Name = "zhangsan";
//		return m_Name;
//	}
//	//��д����
//	void getAge(int age)
//	{
//		m_age = age;
//	}
//
//	//��ȡ����
//	int ShowAge()
//	{
//		return m_age;
//	}
//
//	//��д����
//	void getLover(string lover)
//	{
//		Lover = lover;
//	}
//
//
//private:
//	// ����  ֻ��
//	string m_Name;
//	//����  �ɶ���д
//	int m_age;
//
//	//����  ֻд
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

////��������
//class Cube
//{
//public:
//	//���ó�������
//	void setLWH(int l,int w,int h)
//	{
//		m_L = l;
//		m_W = w;
//		m_H = h;
//	}
//	//��ȡ��
//	int getL()
//	{
//		return m_L;
//	}
//	//��ȡ��
//	int getW()
//	{
//		return m_W;
//	}
//	//��ȡ��
//	int getH()
//	{
//		return m_H;
//	}
//
//	//�ж������������Ƿ����
//	bool cube1(Cube& c)
//	{
//		if (m_L == c.m_L && m_W == c.m_W && m_H == c.m_H)
//		{
//			return true;
//		}
//		return false;
//	}
//
//	//��������������
//	int CubeS()
//	{
//		return 2 * m_L * m_W + 2 * m_L * m_H + 2 * m_W * m_H;
//	}
//	//��������������
//	int CubeV()
//	{
//		return m_L * m_H * m_W;
//	}
//
//private:
//	//���ó�
//	int m_L;
//	//���ÿ�
//	int m_W;
//	//���ø�
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
//	cout << "c1�����:" << c1.CubeS() << endl;
//	cout << "c1�����:" << c1.CubeV() << endl;
//
//	Cube c2;
//	c2.setLWH(10, 20, 10);
//	cout << "c2�����:" << c2.CubeS() << endl;
//	cout << "c2�����:" << c2.CubeV() << endl;
//
//	//�ж������������Ƿ����
//	//bool ret = Cube1(c1, c2);
//	bool ret = c1.cube1(c2);
//	if (ret)
//	{
//		cout << "c1��c2����ȵ�" << endl;
//	}
//	else
//	{
//		cout << "c1��c2�ǲ���ȵ�" << endl;
//	}
//
//	system("pause");
//	return 0;
//}

////������
//class Point
//{
//public:
//	//��������
//	void setXY(int x, int y)
//	{
//		m_X = x;
//		m_Y = y;
//	}
//	//��ȡ������
//	int getX()
//	{
//		return m_X;
//	}
//	//��ȡ������
//	int getY()
//	{
//		return m_Y;
//	}
//
//private:
//	//������
//	int m_X;
//	//������
//	int m_Y;
//};

////Բ��
//class Circle
//{	
//public:
//	//���ð뾶
//	void setR(int r)
//	{
//		m_R = r;
//	}
//	//��ȡ�뾶
//	int getR()
//	{
//		return m_R;
//	}
//	//����Բ��
//	void setCenter(Point c)
//	{
//		m_Center = c;
//	}
//	//��ȡԲ��
//	Point getCenter()
//	{
//		return m_Center;
//	}
//
//private:
//	//�뾶
//	int m_R;
//	//Բ��
//	Point m_Center;
//};

//�жȵ���Բ�Ĺ�ϵ
void isInCircle(Circle& c,Point p)
{
	//�㵽Բ�ľ����ƽ��
	int Rdistance = (c.getCenter().getX() - p.getX()) ^ 2 + (c.getCenter().getY() - p.getY() ^ 2);
	//�뾶��ƽ��
	int Cdistance = c.getR() * c.getR();

	//�ж�
	if (Rdistance == Cdistance)
	{
		cout << "����Բ��" << endl;
	}
	else if (Rdistance > Cdistance)
	{
		cout << "����Բ��" << endl;
	}
	else
	{
		cout << " ����Բ��" << endl;
	}
}

//int main()
//{	
//	Circle c1;
//	//���ð뾶
//	c1.setR(10);
//	//����Բ��
//	Point center;
//	center.setXY(10, 0);
//	c1.setCenter(center);
//
//	//��
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
	//���캯��
	//1.û�з���ֵ������дvoid
	//������ �� ������ͬ
	//���캯�������в���
	//���������ʱ�򣬹��캯�����Զ����ã�����ֻ��һ��
	Person()
	{
		cout << "���캯���ĵ���" << endl;
	}

	//�������� �����������
	//û�з���ֵ ����дvoid
	//��������������ͬ ������ǰ��~
	//���������������в����������Է�������
	//����������ǰ���Զ���������������ֻ����һ��
	~Person()
	{
		cout << "���������ĵ���" << endl;
	}
};


//������������Ǳ����е�ʵ�֣���������Լ����ṩ�����������ṩһ���չ���Ϳ�����
void test01()
{
	Person DD; //���󴴽���ջ����test01��ִ����Ϻ��ͷ��������
}

int main()
{	
	test01();

	Person P;

	system("pause");
	return 0;
}