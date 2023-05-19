#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;


//重载赋值运算符=

//class Person
//{
//public:
//
//	Person(int age)
//	{
//		m_Age = new int(age);
//	}
//
//	//重载赋值运算符=
//	Person& operator=(Person& p)
//	{
//		if (m_Age != NULL)
//		{
//			delete m_Age;
//			m_Age = NULL;
//		}
//		m_Age = new int(*p.m_Age);
//		return *this;
//	}
//
//	~Person()
//	{
//		if (m_Age != NULL)
//		{
//			delete m_Age;
//			m_Age = NULL;
//		}
//	}
//
//	int* m_Age;
//};
//
//
//void test01()
//{
//	Person p1(18);
//	
//	Person p2(20);
//
//	Person p3(30);
//
//	p2 = p1 = p3;
//
//	cout << "p1 的年龄: " << *p1.m_Age << endl;
//	cout << "p2 的年龄: " << *p2.m_Age << endl;
//}
//
//int main()
//{	
//
//	test01();
//
//	system("pause");
//	return 0;
//}




////重载关系运算符==
//class Person01
//{
//public:
//
//	Person01(string name, int age)
//	{
//		m_Name = name;
//		m_Age = age;
//	}
//
//	//重载运算符==
//	bool operator==(Person01& p)
//	{
//		if (m_Name == p.m_Name && m_Age == p.m_Age)
//		{
//			return true;
//		}
//		return false;
//	}
//
//	//重载运算符!=
//	bool operator!=(Person01& p)
//	{
//		if (m_Name == p.m_Name && m_Age == p.m_Age)
//		{
//			return false;
//		}
//		return true;
//	}
//
//	string m_Name;
//	int m_Age;
//};
//
//void test01()
//{
//	Person01 p1("Tom", 18);
//	Person01 p2("tom", 18);
//
//	if (p1 == p2)
//	{
//		cout << "p1 和 p2 是同一个人" << endl;
//	}
//	else
//	{
//		cout << "p1 和 p2 不是同一个人" << endl;
//	}
//}
//
//int main()
//{	
//	test01();
//
//
//	system("pause");
//	return 0;
//}



//重载 ()


class MyPrint
{
public:

	void operator()(string name)
	{
		cout << name << endl;
	}

};

class MyAdd
{
public:

	int operator()(int num1,int num2)
	{
		return num1 + num2;
	}

};

void test01()
{
	MyPrint m1;
	m1("hello world");

	MyAdd m2;
	
	cout << m2(10, 20) << endl;

	//匿名函数对象
	cout << MyAdd()(20, 30) << endl;
}

int main()
{	
	test01();

	system("pause");
	return 0;
}