#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class BasePage
{
public:

	void Top()
	{
		cout << " ����ҳ�� " << endl;
	}
	void Middle()
	{
		cout << " �в�ҳ�� " << endl;
	}
	void Footer()
	{
		cout << " �ײ�ҳ�� " << endl;
	}
};

class Java : public BasePage
{
public:
	void cotent()
	{
		cout << "Java ��ѧ��Ƶ " << endl;
	}
};

void test01()
{
	Java j;
	j.Top();
	j.Middle();
	j.Footer();
	j.cotent();
}

int main()
{	
	test01();
	system("pause");
	return 0;
}
