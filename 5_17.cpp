#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//class Person
//{	
//public:
//	Person()
//	{
//		cout << "Person构造函数的调用" << endl;
//	}
//
//	Person(int age,int hight)
//	{	
//		m_Age = age;
//		m_Hight = new int(hight);
//		cout << "Person 有参构造函数的调用" << endl;
//	}
//
//	Person(const Person& p)
//	{
//		cout << " Person 拷贝函数的调用" << endl;
//		m_Age = p.m_Age;
//		//m_Hight = p.m_Hight; //编译器默认实现  浅拷贝 当重复进行释放时会导致程序崩溃
//		//深拷贝
//		m_Hight = new int(*p.m_Hight);
//		
//	}
//
//
//	~Person()
//	{
//		cout << "Person析构函数的调用" << endl;
//	}
//
//	int m_Age;
//	int *m_Hight;
//};
//
//void test01()
//{
//	Person p1(19,170);
//	cout << "p1的年龄为:" << p1.m_Age << "\tp1的身高为:" << *p1.m_Hight << endl;
//	
//	Person p2(p1);
//	cout << "p2的年龄为:" << p2.m_Age << "\tp2的身高为:" << *p2.m_Hight << endl;
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







////静态成员变量
////1.所有对象共用同一份数据
////2.编译器阶段分配内存
////3.类内声明，类外初始化操作
//
//
//class Person
//{	
//public:
//	static int m_A;
//
////静态变量也有访问权限
//private:
//	static int m_B;
//};
//
//int Person::m_A = 100;
//int Person::m_B = 100;
//
////静态成员函数
////1.所有对象共享同一个函数
////2.静态成员函数只能访问静态成员变量
//
//class person
//{	
//public:
//	static void func()
//	{
//		cout << "静态成员函数的调用" << endl;
//		
//		//静态成员函数只能访问静态成员变量，不可以访问非静态成员变量。
//		m_C = 100;
//	}
//	static int m_C;
//};
//
//int person::m_C = 100;
//
////静态成员函数的调用
//void test02()
//{	
//	//静态对象通过对象进行访问
//	Person p1;
//	cout << p1.m_A << endl;
//
//	Person p2;
//	p2.m_A = 200;
//	cout << p1.m_A << endl;
//
//	//通过类名直接访问
//	cout << Person::m_A << endl;
//
//	// cout << Person::m_B << endl;
//}
//
////静态成员函数的调用
//void test03()
//{
//	//1.通过对象访问
//	person p;
//	p.func();
//	
//
//
//	//2.通过类名访问
//	person::func();
//}
//
//
//int main()
//{
//	//test02();
//	test03();
//
//	system("pause");
//	return 0;
//}
//
//


//this指针

class Student
{
public:
	Student(int age)
	{
		this->age = age;
	}

	Student& StudentAdd(Student& p)
	{
		this->age += p.age;

		return *this;
	}

	int age;
};

void test04()
{
	Student s1(10);

	Student s2(10);

	s2.StudentAdd(s1).StudentAdd(s1).StudentAdd(s1);

	cout << "s2的年龄为:" << s2.age << endl;
}



int main()
{
	test04();

	
	system("pause");
	return 0;
}