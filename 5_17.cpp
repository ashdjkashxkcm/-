#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//class Person
//{	
//public:
//	Person()
//	{
//		cout << "Person���캯���ĵ���" << endl;
//	}
//
//	Person(int age,int hight)
//	{	
//		m_Age = age;
//		m_Hight = new int(hight);
//		cout << "Person �вι��캯���ĵ���" << endl;
//	}
//
//	Person(const Person& p)
//	{
//		cout << " Person ���������ĵ���" << endl;
//		m_Age = p.m_Age;
//		//m_Hight = p.m_Hight; //������Ĭ��ʵ��  ǳ���� ���ظ������ͷ�ʱ�ᵼ�³������
//		//���
//		m_Hight = new int(*p.m_Hight);
//		
//	}
//
//
//	~Person()
//	{
//		cout << "Person���������ĵ���" << endl;
//	}
//
//	int m_Age;
//	int *m_Hight;
//};
//
//void test01()
//{
//	Person p1(19,170);
//	cout << "p1������Ϊ:" << p1.m_Age << "\tp1�����Ϊ:" << *p1.m_Hight << endl;
//	
//	Person p2(p1);
//	cout << "p2������Ϊ:" << p2.m_Age << "\tp2�����Ϊ:" << *p2.m_Hight << endl;
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







////��̬��Ա����
////1.���ж�����ͬһ������
////2.�������׶η����ڴ�
////3.���������������ʼ������
//
//
//class Person
//{	
//public:
//	static int m_A;
//
////��̬����Ҳ�з���Ȩ��
//private:
//	static int m_B;
//};
//
//int Person::m_A = 100;
//int Person::m_B = 100;
//
////��̬��Ա����
////1.���ж�����ͬһ������
////2.��̬��Ա����ֻ�ܷ��ʾ�̬��Ա����
//
//class person
//{	
//public:
//	static void func()
//	{
//		cout << "��̬��Ա�����ĵ���" << endl;
//		
//		//��̬��Ա����ֻ�ܷ��ʾ�̬��Ա�����������Է��ʷǾ�̬��Ա������
//		m_C = 100;
//	}
//	static int m_C;
//};
//
//int person::m_C = 100;
//
////��̬��Ա�����ĵ���
//void test02()
//{	
//	//��̬����ͨ��������з���
//	Person p1;
//	cout << p1.m_A << endl;
//
//	Person p2;
//	p2.m_A = 200;
//	cout << p1.m_A << endl;
//
//	//ͨ������ֱ�ӷ���
//	cout << Person::m_A << endl;
//
//	// cout << Person::m_B << endl;
//}
//
////��̬��Ա�����ĵ���
//void test03()
//{
//	//1.ͨ���������
//	person p;
//	p.func();
//	
//
//
//	//2.ͨ����������
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


//thisָ��

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

	cout << "s2������Ϊ:" << s2.age << endl;
}



int main()
{
	test04();

	
	system("pause");
	return 0;
}