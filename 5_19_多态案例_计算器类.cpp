#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

////利用多态实现计算器
////基类
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
////加法运算类
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
////减法运算类
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


//案例2 冲泡茶水

class AbstractDrinking
{
public:
	//煮水
	virtual void Boil() = 0;
	//冲泡
	virtual void Brew() = 0;
	//倒入杯中
	virtual void PourInCup() = 0;
	//加入佐料
	virtual void PutSomething() = 0;
	
	void MakeDrink()
	{

		Boil();
		Brew();
		PourInCup();
		PutSomething();

	}
};

//制作咖啡
class Coffe : public AbstractDrinking
{
	//煮水
	virtual void Boil()
	{
		cout << "煮矿泉水" << endl;
	}
	//冲泡
	virtual void Brew() 
	{
		cout << "冲泡咖啡" << endl;
	}
	//倒入杯中
	virtual void PourInCup()
	{
		cout << "倒入杯中" << endl;
	}
	//加入佐料
	virtual void PutSomething()
	{
		cout << "加入糖和牛奶" << endl;
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