#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

////���ö�̬ʵ�ּ�����
////����
//class Base
//{
//public:
//	
//	virtual int getResult()
//	{
//		return 0;
//	}
//
//	int m_A;
//	int m_B;
//};
//
////�ӷ�������
//class AddCalculate:public Base
//{
//public:
//	int getResult()
//	{
//		return m_A + m_B;
//	}
//
//};
//
////����������
//class SubCalculate :public Base
//{
//public:
//	int getResult()
//	{
//		return m_A - m_B;
//	}
//};
//
//void test01()
//{
//	Base *a = new AddCalculate;
//	a->m_A = 10;
//	a->m_B = 10;
//	
//	cout << a->m_A << " + " << a->m_B << " = " << a->getResult() << endl;
//	delete a;
//	
//	a = new SubCalculate;
//	a->m_A = 100;
//	a->m_B = 10;
//
//	cout << a->m_A << " - " << a->m_B << " = " << a->getResult() << endl;
//	delete a;
//}
//
//int main()
//{	
//	test01();
//
//	system("pause");
//	return 0;
//}


//����2 ���ݲ�ˮ

class AbstractDrinking
{
public:
	//��ˮ
	virtual void Boil() = 0;
	//����
	virtual void Brew() = 0;
	//���뱭��
	virtual void PourInCup() = 0;
	//��������
	virtual void PutSomething() = 0;
	
	void MakeDrink()
	{

		Boil();
		Brew();
		PourInCup();
		PutSomething();

	}
};

//��������
class Coffe : public AbstractDrinking
{
	//��ˮ
	virtual void Boil()
	{
		cout << "���Ȫˮ" << endl;
	}
	//����
	virtual void Brew() 
	{
		cout << "���ݿ���" << endl;
	}
	//���뱭��
	virtual void PourInCup()
	{
		cout << "���뱭��" << endl;
	}
	//��������
	virtual void PutSomething()
	{
		cout << "�����Ǻ�ţ��" << endl;
	}
};

void DoWork(AbstractDrinking* abc)
{
	abc->MakeDrink();
	delete abc;
}
void test01()
{
	DoWork(new Coffe);
}

int main()
{
	test01();
	system("pause");
	return 0;
}