#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//��̬

class Animal
{	
public:
	//�麯��
	virtual void speak()
	{
		cout << " ���� " << endl;
	}
};

class Cat:public Animal
{	
public:
	//�Ӻ�����virtual��д�ɲ�д
	void speak()
	{
		cout << " Сè " << endl;
	}
};

void Do(Animal& animal)
{
	animal.speak();
}

//��ַ��� �ڱ���׶�ȷ��������ַ
//�������ִ�н��ΪСè����������ĵ�ַ�Ͳ�����ǰ�󶨣���Ҫ�����н׶ν��а󶨣�Ҳ���ǵ�ַ���
//�ڶ������е�speak����ǰ�����virtual ����ʵ��
void test01()
{
	Cat c;
	Do(c);
	Animal m1;
	Do(m1);
}

int main()
{	
	test01();


	system("pause");
	return 0;
}
