#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class BasePage
{
public:

	void Top()
	{
		cout << " 顶部页面 " << endl;
	}
	void Middle()
	{
		cout << " 中部页面 " << endl;
	}
	void Footer()
	{
		cout << " 底部页面 " << endl;
	}
};

class Java : public BasePage
{
public:
	void cotent()
	{
		cout << "Java 教学视频 " << endl;
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
