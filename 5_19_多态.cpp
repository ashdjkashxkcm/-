#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//多态

class Animal
{	
public:
	//虚函数
	virtual void speak()
	{
		cout << " 动物 " << endl;
	}
};

class Cat:public Animal
{	
public:
	//子函数中virtual可写可不写
	void speak()
	{
		cout << " 小猫 " << endl;
	}
};

void Do(Animal& animal)
{
	animal.speak();
}

//地址早绑定 在编译阶段确定函数地址
//如果想让执行结果为小猫，这个函数的地址就不能提前绑定，需要在运行阶段进行绑定，也就是地址晚绑定
//在动物类中的speak函数前面加上virtual 即可实现
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
