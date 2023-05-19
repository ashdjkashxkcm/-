#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

class Animal
{

public:
	Animal()
	{
		cout << "Animal ���캯���ĵ���" << endl;
	}

	//�������������Խ�� ����ָ���ͷ��������ʱ���ɾ�������
	/*virtual ~Animal()
	{
		cout << "Animal �����������ĵ���" << endl;
	}*/
	//��������  ��Ҫ���� Ҳ��Ҫʵ��
	//���˴�����������֮�������Ҳ���ڳ����࣬�޷�ʵ��������
	virtual ~Animal() = 0;


	virtual void speak() = 0;
};

Animal::~Animal()
{
	cout << "Animal �������������ĵ���" << endl;
}

class Cat : public Animal
{	
public:

	Cat(string name)
	{
		cout << "Cat ���캯���ĵ���" << endl;
		m_Name = new string(name);
	}


	 void speak()
	{
		cout << *m_Name << "Сè��˵��" << endl;
	}
	 
	 ~Cat()
	 {
		 cout << "Cat ���������ĵ���" << endl;
		 if (m_Name != NULL)
		 {
			 delete m_Name;
			 m_Name = NULL;
		 }
	 }

	 string *m_Name;
};

void test01()
{
		Animal* animal = new Cat("Tom");
		animal->speak();
		delete animal;
}

int main()
{	
	test01();
	system("pause");
	return 0;
}
